$input a_position, a_texcoord0
$output v_texcoord0

#include <common.sh>

void main()
{
	int material_index = int(u_state_material);
	BaseMaterial basic = read_base_material(material_index);
	
   v_texcoord0 = vec4((a_texcoord0.xy * basic.uv0_scale) + basic.uv0_offset, 0.0, 0.0);
	gl_Position = mul(u_modelViewProj, vec4(a_position.xyz, 1.0));
}
