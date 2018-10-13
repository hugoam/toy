#ifndef MUD_SHADER_GI
#define MUD_SHADER_GI

#include <common.sh>
 
SAMPLER3D(s_gi_probe, 10);
uniform highp mat4 u_gi_probe_transform;
uniform highp vec4 u_gi_probe_bounds;
uniform highp vec4 u_gi_probe_cell_size;
uniform highp vec4 u_gi_probe_params;
#define u_gi_probe_multiplier       u_gi_probe_params.x
#define u_gi_probe_bias             u_gi_probe_params.y
#define u_gi_probe_normal_bias      u_gi_probe_params.z
#define u_gi_probe_blend_ambient    u_gi_probe_params.w


vec3 voxel_cone_trace(sampler3D probe, vec3 cell_size, vec3 pos, vec3 ambient, bool blend_ambient, vec3 direction, float tan_half_angle, float max_distance, float bias)
{
	float dist = bias; //1.0; //dot(direction, mix(vec3_splat(-1.0), vec3_splat(1.0), greaterThan(direction, vec3_splat(0.0)))) * 2.0;
	float alpha = 0.0;
	vec3 color = vec3_splat(0.0);

	while(dist < max_distance && alpha < 0.95) {
		float diameter = max(1.0, 2.0 * tan_half_angle * dist);
		vec4 scolor = texture3DLod(probe, (pos + dist * direction) * cell_size, log2(diameter));
		float a = (1.0 - alpha);
		color += scolor.rgb * a;
		alpha += a * scolor.a;
		dist += diameter * 0.5;
	}

	if (blend_ambient) {
		color.rgb = mix(ambient,color.rgb,min(1.0,alpha/0.95));
	}

	return color;
}

void gi_probe_compute(sampler3D probe, mat4 probe_transform, vec3 bounds, vec3 cell_size, vec3 pos, vec3 ambient, vec3 environment, bool blend_ambient,
                      float multiplier, mat3 normal_mtx, vec3 ref_vec, float roughness, float p_bias, float normal_bias, inout vec4 out_spec, inout vec4 out_diff)
{

	vec3 probe_pos = mul(probe_transform, vec4(pos, 1.0)).xyz;
	vec3 ref_pos = mul(probe_transform, vec4(pos + ref_vec, 1.0)).xyz;
	ref_vec = normalize(ref_pos - probe_pos);

	probe_pos += mul(probe_transform, vec4(normal_mtx[2], 0.0)).xyz * normal_bias;

/*	out_diff.rgb = voxel_cone_trace(probe,cell_size,probe_pos,normalize(mul(probe_transform, vec4(ref_vec,0.0)).xyz),0.0 ,100.0);
	out_diff.a = 1.0;
	return;*/
	//out_diff = vec4(textureLod(probe,probe_pos*cell_size,3.0).rgb,1.0);
	//return;

	//this causes corrupted pixels, i have no idea why..
	if (any(bvec2(any(lessThan(probe_pos, vec3_splat(0.0))), any(greaterThan(probe_pos, bounds))))) {
		return;
	}

	//vec3 blendv = probe_pos/bounds * 2.0 - 1.0;
	//float blend = 1.001-max(blendv.x,max(blendv.y,blendv.z));
	float blend = 1.0;

	float max_distance = length(bounds);

	//radiance
#ifdef VCT_QUALITY_HIGH

#define MAX_CONE_DIRS 6
    
    CONST(ARRAY_BEGIN(vec3, cone_dirs, MAX_CONE_DIRS))
		vec3(0, 0, 1),
		vec3(0.866025, 0, 0.5),
		vec3(0.267617, 0.823639, 0.5),
		vec3(-0.700629, 0.509037, 0.5),
		vec3(-0.700629, -0.509037, 0.5),
		vec3(0.267617, -0.823639, 0.5)
    ARRAY_END();

	ARRAY_BEGIN(float, cone_weights, MAX_CONE_DIRS) 0.25, 0.15, 0.15, 0.15, 0.15, 0.15 ARRAY_END();
	float cone_angle_tan = 0.577;
	float min_ref_tan = 0.0;
#else

#define MAX_CONE_DIRS 4

    CONST(ARRAY_BEGIN(vec3, cone_dirs, MAX_CONE_DIRS))
        vec3(0.707107, 0, 0.707107),
        vec3(0, 0.707107, 0.707107),
        vec3(-0.707107, 0, 0.707107),
        vec3(0, -0.707107, 0.707107)
    ARRAY_END();

	ARRAY_BEGIN(float, cone_weights, MAX_CONE_DIRS) 0.25, 0.25, 0.25, 0.25 ARRAY_END();
	float cone_angle_tan = 0.98269;
	max_distance *= 0.5;
	float min_ref_tan = 0.2;

#endif
	vec3 light = vec3_splat(0.0);
	for(int i = 0; i < MAX_CONE_DIRS; i++) {

		vec3 dir = normalize(mul(probe_transform, vec4(pos + mul(normal_mtx, cone_dirs[i]), 1.0)).xyz - probe_pos);
		light += cone_weights[i] * voxel_cone_trace(probe, cell_size, probe_pos, ambient, blend_ambient, dir, cone_angle_tan, max_distance, p_bias);

	}

	light *= multiplier;

	out_diff += vec4(light * blend, blend);

	//irradiance

	vec3 irr_light = voxel_cone_trace(probe, cell_size, probe_pos, environment, blend_ambient, ref_vec, max(min_ref_tan, tan(roughness * 0.5 * M_PI)), max_distance, p_bias);

	irr_light *= multiplier;
	//irr_light = vec3_splat(0.0);

	out_spec += vec4(irr_light * blend, blend);

}


void gi_probes_compute(vec3 pos, vec3 normal, float roughness, inout vec3 out_specular, inout vec3 out_ambient)
{
	roughness = roughness * roughness;

	vec3 ref_vec = normalize(reflect(normalize(pos), normal));

	//find arbitrary tangent and bitangent, then build a matrix
	vec3 v0 = abs(normal.z) < 0.999 ? vec3(0, 0, 1) : vec3(0, 1, 0);
	vec3 tangent = normalize(cross(v0, normal));
	vec3 bitangent = normalize(cross(tangent, normal));
	mat3 normal_mat = mat3(tangent,bitangent,normal);

	vec4 diff_accum = vec4_splat(0.0);
	vec4 spec_accum = vec4_splat(0.0);

	vec3 ambient = out_ambient;
	out_ambient = vec3_splat(0.0);

	vec3 environment = out_specular;
	out_specular = vec3_splat(0.0);

	gi_probe_compute(s_gi_probe, u_gi_probe_transform, u_gi_probe_bounds.xyz, u_gi_probe_cell_size.xyz, pos, ambient, environment, bool(u_gi_probe_blend_ambient),
                     u_gi_probe_multiplier, normal_mat, ref_vec, roughness, u_gi_probe_bias, u_gi_probe_normal_bias, spec_accum, diff_accum);

#if 0
	if (gi_probe2_enabled) {

		gi_probe_compute(s_gi_probe, u_gi_probe_transform, u_gi_probe_bounds.xyz, u_gi_probe_cell_size.xyz, pos, ambient, environment, bool(u_gi_probe_blend_ambient),
                         u_gi_probe_multiplier, normal_mat, ref_vec, roughness, u_gi_probe_bias, u_gi_probe_normal_bias, spec_accum, diff_accum);
	}
#endif

	if (diff_accum.a > 0.0) {
		diff_accum.rgb /= diff_accum.a;
	}

	if (spec_accum.a > 0.0) {
		spec_accum.rgb /= spec_accum.a;
	}

	out_specular += spec_accum.rgb;
	out_ambient += diff_accum.rgb;
}

#endif
