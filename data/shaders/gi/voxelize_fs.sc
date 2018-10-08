$input v_voxposition, v_normal, v_color, v_texcoord0

// #extension GL_ARB_shader_image_load_store : enable

#include <pbr/pbr.sh>
//#include <pbr/light.sh>

#include <gi/gi.sh>

#include <encode.sh>
#include <bgfx_compute.sh>

UIMAGE3D_RW(s_voxels, r32ui, 8);
UIMAGE3D_RW(s_voxels_normals, r32ui, 9);

void main()
{
    if (abs(v_voxposition.z) > VOXELGI_RESOLUTION_Z || abs(v_voxposition.x) > 1 || abs(v_voxposition.y) > 1) return;
    vec3 wposition = v_voxposition * u_voxelgi_extents;
    //wposition += u_eye_snap;

    Fragment fragment;
	fragment.position = wposition;
	fragment.normal = normalize(v_normal);
	fragment.uv = v_texcoord0.xy;
	fragment.color = v_color;
    
    Material material;
	material.albedo = u_albedo.rgb * sample_material_texture(s_albedo, fragment.uv).rgb;
    material.roughness = u_roughness * sample_material_texture(s_roughness, fragment.uv)[ int(u_roughness_channel) ];
	material.metallic = u_metallic * sample_material_texture(s_metallic, fragment.uv)[ int(u_metallic_channel) ];
    material.specular = u_specular;
	material.alpha = 1.0;

    fragment.color = vec4(material.albedo, 1.0);
    
    vec3 voxel = v_voxposition * 0.5 + 0.5;
    ivec3 coord = ivec3(u_voxelgi_resolution * voxel);
    
    uint color_enc = encodeRGBA8(fragment.color * 255.0);
#ifdef BGFX_SHADER_LANGUAGE_HLSL
    InterlockedMax(s_voxels.m_texture[coord], color_enc);
#else
    imageAtomicMax(s_voxels, coord, color_enc);
#endif

    uint normal_enc = encodeNormal(v_normal);
#ifdef BGFX_SHADER_LANGUAGE_HLSL
    InterlockedMax(s_voxels_normals.m_texture[coord], color_enc);
#else
    imageAtomicMax(s_voxels_normals, coord, normal_enc);
#endif
}
