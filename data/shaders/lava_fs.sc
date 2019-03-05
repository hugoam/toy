$input v_texcoord0

#include <common.sh>

SAMPLER2D(s_texture_1, 0);
SAMPLER2D(s_texture_2, 1);

void main()
{
   vec2 uv = v_texcoord0.xy;	vec2 position = - 1.0 + 2.0 * uv;

	vec4 noise = texture2D(s_texture_1, uv);
	vec2 T1 = uv + vec2(1.5, - 1.5) * u_time * 0.02;
	vec2 T2 = uv + vec2(- 0.5, 2.0) * u_time * 0.01;

	T1.x += noise.x * 2.0;
	T1.y += noise.y * 2.0;
	T2.x -= noise.y * 0.2;
	T2.y += noise.z * 0.2;

	float p = texture2D(s_texture_1, T1 * 2.0).a;

	vec4 color = texture2D(s_texture_2, T2 * 2.0);
	vec4 temp = color * (vec4(p, p, p, p) * 2.0) + (color * color - 0.1);

	if(temp.r > 1.0) { temp.bg += clamp(temp.r - 2.0, 0.0, 100.0); }
	if(temp.g > 1.0) { temp.rb += temp.g - 1.0; }
	if(temp.b > 1.0) { temp.rg += temp.b - 1.0; }

	gl_FragColor = temp;

}
