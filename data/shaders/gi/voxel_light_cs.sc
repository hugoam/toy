#version 450

// layout (local_size_x = 4, local_size_y = 4, local_size_z = 4) in;
layout (local_size_x = 64, local_size_y = 1, local_size_z = 1) in;

#include <pbr/pbr.sh>
#include <pbr/light.sh>

#include <gi/gi.sh>

#include <encode.sh>
#include <bgfx_compute.sh>

#ifdef SHADOWS
//uniform int u_light_shadow;
//uniform vec2 u_light_proj;
//uniform float u_shadow_bias;
//uniform mat4 u_LVP;
#endif

IMAGE3D_R(s_voxels_albedo, rgba8, 0);
UIMAGE3D_R(s_voxels_normals, r32ui, 1);
UIMAGE3D_RW(s_voxels_light, r32ui, 2);

#ifdef SHADOWS
SAMPLER2D(s_shadowmap, 3);
SAMPLERCUBE(s_shadowmap_cube, 4);
#endif

void main()
{
    vec4 col = imageLoad(s_voxels_albedo, ivec3(gl_GlobalInvocationID.xyz));
    if (col.a == 0.0) return;

    const vec3 hres = u_voxelgi_resolution / 2;
    vec3 voxel_position = ((gl_GlobalInvocationID.xyz - hres) / hres) * u_voxelgi_extents;

    uint unor = imageLoad(s_voxels_normals, ivec3(gl_GlobalInvocationID.xyz)).r;
    vec3 wnormal = normalize(decodeNormal(unor));

    voxel_position -= wnormal * 0.01; // Offset

	for(int i = 0; i < int(u_light_counts[LIGHT_OMNI]); i++)
	{
        Light light = preread_light(int(u_light_indices[i][LIGHT_OMNI]));
        light.type = LIGHT_OMNI;
        
        vec3 lp = light.position - voxel_position;
        
        float visibility;
        vec3 l;
        if (light.type == LIGHT_DIRECT) { l = light.direction; visibility = 1.0; }
        else { l = normalize(lp); visibility = attenuate(length(lp)); }

        float dotNL = max(dot(wnormal, l), 0.0);
        if (dotNL == 0.0) return;

#ifdef SHADOWS
        //if (light.shadow == 1)
        //{
        //    vec4 light_position = u_LVP * vec4(voxel_position, 1.0);
        //    vec3 lPos = light_position.xyz / light_position.w;
        //    // if (light_position.w > 0.0)
        //    if (texture(s_shadowmap, lPos.xy).r < lPos.z - u_shadow_bias) visibility = 0.0;
        //    // visibility = shadowTest(shadowMap, lPos, u_shadow_bias, shadowmapSize);
        //}
        //else if (light.shadow == 2)
        //{
        //    visibility *= float(texture(u_shadowmap_cube, -l).r + u_shadow_bias > lpToDepth(lp, u_light_proj));
        //}
#endif

        if (light.type == LIGHT_SPOT)
        {
            float spot_effect = dot(light.direction, l);
            if (spot_effect < light.spot_cutoff)
            {
                visibility *= smoothstep(light.spot_cutoff, light.spot_inner, spot_effect);
            }
        }

        col.rgb *= visibility * light.energy * dotNL;
        col = clamp(col, vec4(0.0), vec4(1.0));
        
        // imageStore(s_voxels_light, ivec3(gl_GlobalInvocationID.xyz), col);
        imageAtomicAdd(s_voxels_light, ivec3(gl_GlobalInvocationID.xyz), encodeRGBA8(col * 255));
    }
}
