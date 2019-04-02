    int material_index = int(u_state_material);
    LitMaterial lit = read_lit_material(material_index);
    PhongMaterial phong = read_phong_material(material_index);

#include "fs_depth.sh"

    vec2 uv = fragment.uv;
#include "fs_alpha.sh"
#include "fs_alphatest.sh"

    phong.diffuse = phong.diffuse * sample_material_texture(s_diffuse, fragment.uv).rgb;
    phong.specular = phong.specular * sample_material_texture(s_specular, fragment.uv).rgb;
    phong.shininess = phong.shininess * sample_material_texture(s_shininess, fragment.uv).r;

#ifdef VERTEX_COLOR
    phong.diffuse *= v_color.rgb;
    alpha *= v_color.a;
#endif

    PhongMaterial material = phong;

#include "fs_normal.sh"
#include "fs_emission.sh"
#include "fs_ao.sh"

    fragment.NoV = dot(fragment.normal, fragment.view);
    fragment.cNoV = max(dot(fragment.normal, fragment.view), 0.0);
