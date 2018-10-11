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

//IMAGE3D_RO(s_voxels_albedo, rgba8, 0);
UIMAGE3D_RO(s_voxels_albedo, r32ui, 0);
UIMAGE3D_RO(s_voxels_normals, r32ui, 1);
UIMAGE3D_RW(s_voxels_light, r32ui, 2);

#ifdef SHADOWS
SAMPLER2D(s_shadowmap, 3);
SAMPLERCUBE(s_shadowmap_cube, 4);
#endif

float attenuate(const float dist)
{
	return 1.0 / (dist * dist);
}

#if 0
float attenuate(float dist, float constant, float linear, float quadratic)
{
    return 1.0 / (constant * 1.0)
         + 1.0 / (linear * dist)
         + 1.0 / (quadratic * dist * dist);
}
#endif

vec3 accumulate_light(vec3 voxel_position, vec3 voxel_color, vec3 voxel_normal, int light_index, int light_type)
{
    Light light = preread_light(light_index, light_type);
    
    vec3 lp = light.position - voxel_position;
    
    float visibility;
    vec3 l;
    if (light.type == LIGHT_DIRECT) { l = light.direction; visibility = 1.0; }
    else { l = normalize(lp); visibility = attenuate(length(lp)); }

    float dotNL = max(dot(voxel_normal, l), 0.0);
    if (dotNL == 0.0) return vec3_splat(0.0);

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

    return voxel_color * visibility * light.energy * dotNL;
}

NUM_THREADS(64, 1, 1)
void main()
{
    ivec3 coord = ivec3(gl_GlobalInvocationID.xyz);
    //vec4 voxel_color = imageLoad(s_voxels_albedo, coord);
    vec4 voxel_color = decodeRGBA8(imageLoad(s_voxels_albedo, coord).x);
    if (voxel_color.a == 0.0) return;

    uint unor = imageLoad(s_voxels_normals, coord).r;
    vec3 voxel_normal = normalize(decodeNormal(unor));

    const vec3 hres = u_voxelgi_resolution / 2;
    vec3 voxel_position = ((gl_GlobalInvocationID.xyz - hres) / hres) * u_voxelgi_extents;
    voxel_position -= voxel_normal * 0.01; // Offset

    vec3 diffuse = vec3_splat(0.0);
    
#ifdef DIRECTIONAL_LIGHT
    diffuse += accumulate_light(voxel_position, voxel_color.rgb, voxel_normal, 0, LIGHT_DIRECT);
#endif

    for(int i = 0; i < int(u_light_counts[LIGHT_OMNI]); i++)
    {
        diffuse += accumulate_light(voxel_position, voxel_color.rgb, voxel_normal, int(u_light_indices[i][LIGHT_OMNI]), LIGHT_OMNI);
    }
    
    for(int i = 0; i < int(u_light_counts[LIGHT_SPOT]); i++)
    {
        diffuse += accumulate_light(voxel_position, voxel_color.rgb, voxel_normal, int(u_light_indices[i][LIGHT_SPOT]), LIGHT_SPOT);
    }
    
    diffuse = clamp(diffuse, vec3_splat(0.0), vec3_splat(1.0));
    //diffuse = voxel_color.rgb * vec3_splat(1.0);
    
    // imageStore(s_voxels_light, coord, diffuse);
    
    //uint color_enc = encodeRGBA8(vec4(diffuse, voxel_color.a) * 255);
    uint color_enc = encodeRGBA8(vec4(diffuse, 1.0) * 255);
    //color_enc = 0xFFFFFFFFu;
#if BGFX_SHADER_LANGUAGE_HLSL
    //InterlockedAdd(s_voxels_light.m_texture[coord], color_enc);
    s_voxels_light.m_texture[coord] = color_enc;
#else
    imageAtomicAdd(s_voxels_light, coord, color_enc);
#endif
}
