$input v_view, v_position, v_normal, v_tangent, v_color, v_uv0, v_uv1, v_binormal
#include <encode.sh>
#include <pbr/pbr.sh>
#include <pbr/light.sh>
#include <pbr/light_brdf_three.sh>
#include <pbr/radiance.sh>
#define s_thickness s_user0
#define u_scatter_p0 u_user_p0
#define u_scatter_p1 u_user_p1
#define u_thicknessPower u_scatter_p0.x
#define u_thicknessScale u_scatter_p0.y
#define u_thicknessDistortion u_scatter_p0.z
#define u_thicknessAmbient u_scatter_p0.w
#define u_thicknessAttenuation u_scatter_p1.x
#define u_thicknessColor u_scatter_p1.yzw
void direct_scatter(vec3 energy, vec3 l, Fragment fragment, PhongMaterial material, inout vec3 diffuse, inout vec3 specular)
{
   direct_blinn_phong(energy, l, fragment, material, diffuse, specular);
	vec3 thickness = u_thicknessColor * texture2D(s_thickness, fragment.uv).r;
	vec3 scatteringHalf = normalize(l + (fragment.normal * u_thicknessDistortion));
	float scatteringDot = pow(saturate(dot(fragment.view, -scatteringHalf)), u_thicknessPower) * u_thicknessScale;
	vec3 scatteringIllu = (scatteringDot + u_thicknessAmbient) * thickness;
	diffuse += scatteringIllu * u_thicknessAttenuation * energy;
}
#define direct_brdf direct_scatter
void main()
{
#include <pbr/fs_fragment.sh>
#include <pbr/fs_phong_material.sh>
#include <pbr/fs_phong.sh>
#include <pbr/fs_out_pbr.sh>
}
