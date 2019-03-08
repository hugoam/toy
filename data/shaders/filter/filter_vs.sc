$input a_position, a_texcoord0
$output v_uv0

#include <filter/filter.sh>

void main()
{
	v_uv0 = a_texcoord0;
	v_uv0 = u_source_0_crop.xy + v_uv0 * u_source_0_crop.zw;

    gl_Position = mul(u_modelViewProj, vec4(a_position.xyz, 1.0));
}
