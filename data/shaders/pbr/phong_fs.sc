$input v_view, v_position, v_normal, v_tangent, v_color, v_uv0, v_uv1, v_binormal

#include <encode.sh>
#include <pbr/pbr.sh>
#include <pbr/light.sh>
#define BRDF_BLINN_PHONG
#include <pbr/light_brdf_three.sh>
#include <pbr/radiance.sh>

void main()
{
#include "fs_fragment.sh"

#include "fs_phong_material.sh"

#ifdef DEFERRED
    #include "fs_out_gbuffer.sh"
#else
    #include "fs_phong.sh"
    #include "fs_out_pbr.sh"
#endif
}
