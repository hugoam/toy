#ifndef MUD_SHADER_GI
#define MUD_SHADER_GI

#include <common.sh>
#include <encode.sh>

SAMPLER3D(s_gi_probe, 10);

uniform highp mat4 u_gi_probe_transform;
uniform highp vec4 u_gi_probe_bounds;
uniform highp vec4 u_gi_probe_cell_size;
uniform highp vec4 u_gi_probe_params;
#define u_gi_probe_multiplier       u_gi_probe_params.x
#define u_gi_probe_bias             u_gi_probe_params.y
#define u_gi_probe_normal_bias      u_gi_probe_params.z
#define u_gi_probe_blend_ambient    u_gi_probe_params.w

#ifdef VCT_QUALITY_HIGH
#define NUM_CONES 6
    CONST(ARRAY_BEGIN(vec3, cone_dirs, NUM_CONES))
		vec3(0, 0, 1),
		vec3(0.866025, 0, 0.5),
		vec3(0.267617, 0.823639, 0.5),
		vec3(-0.700629, 0.509037, 0.5),
		vec3(-0.700629, -0.509037, 0.5),
		vec3(0.267617, -0.823639, 0.5)
    ARRAY_END();

	ARRAY_BEGIN(float, cone_weights, NUM_CONES) 0.25, 0.15, 0.15, 0.15, 0.15, 0.15 ARRAY_END();
	CONST(float) cone_angle_tan = 0.577;
    CONST(float) cone_distance_factor = 1.0;
	CONST(float) min_ref_tan = 0.0;
#else
#define NUM_CONES 4
    CONST(ARRAY_BEGIN(vec3, cone_dirs, NUM_CONES))
        vec3(0.707107, 0, 0.707107),
        vec3(0, 0.707107, 0.707107),
        vec3(-0.707107, 0, 0.707107),
        vec3(0, -0.707107, 0.707107)
    ARRAY_END();

	ARRAY_BEGIN(float, cone_weights, NUM_CONES) 0.25, 0.25, 0.25, 0.25 ARRAY_END();
	CONST(float) cone_angle_tan = 0.98269;
    CONST(float) cone_distance_factor = 0.5;
	CONST(float) min_ref_tan = 0.2;
#endif

vec4 voxel_cone_trace(sampler3D probe, vec3 cell_size, vec3 pos, vec3 direction, float tan_half_angle, float max_distance, float bias)
{
    float dist = bias;
    float alpha = 0.0;
    vec3 color = vec3_splat(0.0);

    while(dist < max_distance && alpha < 0.95) {
        float diameter = max(1.0, 2.0 * tan_half_angle * dist);
        vec3 coord = (pos + dist * direction) * cell_size * 0.5 + 0.5;
        vec4 scolor = texture3DLod(probe, coord, log2(diameter));
        float a = (1.0 - alpha);
        color += a * scolor.rgb;
        alpha += a * scolor.a;
        dist += diameter * 0.5;
        //color = coord;
        //alpha = 1.0;
    }

	return vec4(color, alpha);
}

vec3 voxel_cone_trace_blend(sampler3D probe, vec3 cell_size, vec3 pos, vec3 ambient, bool blend_ambient, vec3 direction, float tan_half_angle, float max_distance, float bias)
{
	vec4 color = voxel_cone_trace(probe, cell_size, pos, direction, tan_half_angle, max_distance, bias);
    
	if (blend_ambient) {
		color.rgb = mix(ambient, color.rgb, min(1.0, color.a / 0.95));
	}

	return color.rgb;
}

void gi_probe_compute(sampler3D probe, mat4 probe_transform, vec3 bounds, vec3 cell_size, vec3 pos, vec3 ambient, vec3 environment, bool blend_ambient,
                      float multiplier, mat3 normal_mtx, vec3 ref_vec, float roughness, float bias, float normal_bias, inout vec4 out_spec, inout vec4 out_diff)
{
	vec3 probe_pos = mul(probe_transform, vec4(pos, 1.0)).xyz;// - bounds / 2.f;
	vec3 ref_pos = mul(probe_transform, vec4(pos + ref_vec, 1.0)).xyz;
	ref_vec = normalize(ref_pos - probe_pos);

	probe_pos += mul(probe_transform, vec4(normal_mtx[2], 0.0)).xyz * normal_bias;

	//this causes corrupted pixels, i have no idea why..
	//if (any(bvec2(any(lessThan(probe_pos, vec3_splat(0.0))), any(greaterThan(probe_pos, bounds))))) {
	//	return;
	//}

	//vec3 blendv = probe_pos/bounds * 2.0 - 1.0;
	//float blend = 1.001-max(blendv.x,max(blendv.y,blendv.z));
	float blend = 1.0;

	float max_distance = length(bounds);

	//radiance
	max_distance *= cone_distance_factor;
    
	vec3 light = vec3_splat(0.0);
	for(int i = 0; i < NUM_CONES; i++) {

		vec3 dir = normalize(mul(probe_transform, vec4(pos + mul(normal_mtx, cone_dirs[i]), 1.0)).xyz - probe_pos);
		light += cone_weights[i] * voxel_cone_trace_blend(probe, cell_size, probe_pos, ambient, blend_ambient, dir, cone_angle_tan, max_distance, bias);

	}

	light *= multiplier;

	out_diff += vec4(light * blend, blend);

	//irradiance

	vec3 irr_light = voxel_cone_trace_blend(probe, cell_size, probe_pos, environment, blend_ambient, ref_vec, max(min_ref_tan, tan(roughness * 0.5 * M_PI)), max_distance, bias);

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
