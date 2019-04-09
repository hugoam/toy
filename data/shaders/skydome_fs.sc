$input v_world
#include <common.sh>
#define top_color    p0.xyz
#define bottom_color p1.xyz
#define offset       p2.x
#define exponent     p2.y
void main()
{
int material_index = int(u_state_material);
UserMaterial u = read_user_material(material_index);
float h = normalize(v_world + u.offset).y;
gl_FragColor = vec4(mix(u.bottom_color, u.top_color, max(pow(max(h, 0.0), u.exponent), 0.0)), 1.0);
gl_FragColor = vec4(pow(gl_FragColor.rgb, vec3_splat(2.0)), 1.0);
}
