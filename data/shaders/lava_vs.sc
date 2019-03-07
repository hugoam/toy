$input a_position, a_texcoord0
$output v_position, v_texcoord0

#include <common.sh>

void main()
{
   int material_index = int(u_state_material);
   BaseMaterial basic = read_base_material(material_index);
   
   v_texcoord0 = vec4((a_texcoord0.xy * basic.uv0_scale) + basic.uv0_offset, 0.0, 0.0);
	vec4 view = mul(u_modelView, vec4(a_position, 1.0));
	v_position = mul(u_proj, view);
	gl_Position = v_position;
}
