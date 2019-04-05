$input v_world, v_mirrored
#include <common.sh>
#define s_mirror s_user0
#define s_normal s_user1
#define u_alpha u_user_p0.x
#define u_size u_user_p0.y
#define u_distortion u_user_p0.z
#define u_sun_color u_user_p1.xyz
#define u_sun_dir u_user_p2.xyz
#define u_eye u_user_p3.xyz
#define u_water_color u_user_p4.xyz
vec4 getNoise(vec2 uv) {
	vec2 uv0 = (uv / 103.0) + vec2(u_time / 17.0, u_time / 29.0);
	vec2 uv1 = uv / 107.0 - vec2(u_time / -19.0, u_time / 31.0);
	vec2 uv2 = uv / vec2(8907.0, 9803.0) + vec2(u_time / 101.0, u_time / 97.0);
	vec2 uv3 = uv / vec2(1091.0, 1027.0) - vec2(u_time / 109.0, u_time / -113.0);
	vec4 noise = texture2D(s_normal, uv0) +
		texture2D(s_normal, uv1) +
		texture2D(s_normal, uv2) +
		texture2D(s_normal, uv3);
	return noise * 0.5 - 1.0;
}
void sunLight(vec3 normal, vec3 view, float shiny, float fspec, float fdiff, inout vec3 diffuse, inout vec3 specular) {
	vec3 reflection = normalize(reflect(-u_sun_dir, normal));
	float direction = max(0.0, dot(view, reflection));
	specular += pow(direction, shiny) * u_sun_color * fspec;
	diffuse += max(dot(u_sun_dir, normal), 0.0) * u_sun_color * fdiff;
}
void main() {
	vec4 noise = getNoise(v_world.xz * u_size);
	vec3 normal = normalize(noise.xzy * vec3(1.5, 1.0, 1.5));
	vec3 diffuse = vec3_splat(0.0);
	vec3 specular = vec3_splat(0.0);
	vec3 ray = u_eye - v_world.xyz;
	float distance = length(ray);
	vec3 dir = normalize(ray);
	sunLight(normal, dir, 100.0, 2.0, 0.5, diffuse, specular);
	vec2 distortion = normal.xz * (0.001 + 1.0 / distance) * u_distortion;
	vec3 reflection = texture2D(s_mirror, v_mirrored.xy / v_mirrored.w + distortion).rgb;
	float theta = max(dot(dir, normal), 0.0);
	float rf0 = 0.3;
	float reflectance = rf0 + (1.0 - rf0) * pow((1.0 - theta), 5.0);
	vec3 scatter = max(0.0, dot(normal, dir)) * u_water_color;
	diffuse = (u_sun_color * diffuse * 0.3 + scatter);
	specular = (vec3_splat(0.1) + reflection * 0.9 + reflection * specular);
	vec3 albedo = mix(diffuse, specular, reflectance);
	vec3 light = albedo;
	gl_FragColor = vec4(light, u_alpha);
}
