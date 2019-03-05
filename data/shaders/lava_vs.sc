$input a_position, a_texcoord0
$output v_texcoord0

#include <common.sh>

uniform vec4 u_lava_params;
#define u_lava_uv_scale u_lava_params.xy

void main()
{
	v_texcoord0 = vec4(u_lava_uv_scale * a_texcoord0.xy, 0.0, 0.0);
	vec3 view = mul(u_modelView, vec4(a_position, 1.0)).xyz;
	gl_Position = mul(u_proj, vec4(view, 1.0));
}
