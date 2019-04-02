$input v_world
#include <common.sh>
#define u_top_color u_user_p0.xyz
#define u_bottom_color u_user_p1.xyz
#define u_offset u_user_p2.x
#define u_exponent u_user_p2.y
void main()
{
	float h = normalize(v_world + u_offset).y;
	gl_FragColor = vec4(mix(u_bottom_color, u_top_color, max(pow(max(h, 0.0), u_exponent), 0.0)), 1.0);
}
