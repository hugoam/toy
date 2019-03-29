    int material_index = int(u_state_material);
    LitMaterial lit = read_lit_material(material_index);
    PbrMaterial pbr = read_pbr_material(material_index);

#include "fs_depth.sh"

    vec2 uv = fragment.uv;
#include "fs_alpha.sh"
#include "fs_alphatest.sh"

    Material material;
    material.albedo = pbr.albedo.rgb * sample_material_texture(s_albedo, fragment.uv).rgb;
    material.roughness = pbr.roughness * sample_material_texture(s_roughness, fragment.uv)[ int(pbr.roughness_channel) ];
    material.metallic = pbr.metallic * sample_material_texture(s_metallic, fragment.uv)[ int(pbr.metallic_channel) ];
    material.specular = pbr.specular;
    material.refraction = pbr.refraction;

#ifdef VERTEX_COLOR
    material.albedo *= v_color.rgb;
    alpha *= v_color.a;
#endif

#include "fs_normal.sh"
#include "fs_emission.sh"
#include "fs_anisotropy.sh"
#include "fs_ao.sh"
