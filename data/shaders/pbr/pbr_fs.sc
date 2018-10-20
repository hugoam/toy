$input v_view, v_position, v_normal, v_tangent, v_color, v_texcoord0/*, v_texcoord1*/, v_binormal

#include <pbr/pbr.sh>
#include <pbr/light.sh>
#include <pbr/radiance.sh>

#ifdef FOG
#include <pbr/fog.sh>
#endif

#ifdef GI_CONETRACE
#include <gi/conetrace.sh>
#endif

void main()
{
    Fragment fragment;
    fragment.coord = gl_FragCoord;
	fragment.position = v_view.xyz;
	fragment.view = normalize(-v_view.xyz);
	fragment.normal = normalize(v_normal);
	fragment.binormal = normalize(v_binormal);
	fragment.tangent = normalize(v_tangent);
	fragment.uv = v_texcoord0.xy;
	//fragment.uv2 = v_texcoord1.xy;
	fragment.color = v_color;
    
#if BGFX_SHADER_LANGUAGE_HLSL
    fragment.coord.z = (fragment.coord.z + 1.0) / 2.0;
    fragment.depth = gl_FragCoord.w;
#else
    fragment.depth = -fragment.position.z;
#endif

    //fragment.coord.z = fragment.depth;

#include "fs_depth.sh"
#include "fs_normal.sh"

    Material material;
	material.albedo = u_albedo.rgb * sample_material_texture(s_albedo, fragment.uv).rgb;
    material.roughness = u_roughness * sample_material_texture(s_roughness, fragment.uv)[ int(u_roughness_channel) ];
	material.metallic = u_metallic * sample_material_texture(s_metallic, fragment.uv)[ int(u_metallic_channel) ];
    material.specular = u_specular;
	material.alpha = 1.0;

#include "fs_emission.sh"
#include "fs_anisotropy.sh"
#include "fs_ao.sh"

#ifdef DEFERRED
    float emissive = float(u_emissive_energy > 0.0);
    vec3 colour = material.albedo * (1.0 - emissive) + emission.rgb * emissive;
	gl_FragData[0] = vec4(fragment.position, fragment.coord.z);
	gl_FragData[1] = vec4(fragment.normal, 1.0);
	gl_FragData[2] = vec4(colour, emissive);
	gl_FragData[3] = vec4(material.roughness, material.metallic, material.specular, 1.0);
#else
    // metallic energy conservation
	vec3 dielectric = vec3_splat(0.034) * material.specular * 2.0;
	material.f0 = mix(dielectric, material.albedo, material.metallic);
    material.albedo = mix(material.albedo, vec3_splat(0.0), material.metallic);

	fragment.NoV = saturate(dot(fragment.normal, fragment.view));
    
    // Radiance radiance;
	vec3 specular = vec3_splat(0.0);
	vec3 diffuse = vec3_splat(0.0);
	vec3 ambient = vec3_splat(0.0);

#ifdef RADIANCE_ENVMAP
    ambient += radiance_ambient(fragment.normal);
    specular += radiance_reflection(fragment.view, fragment.normal, material.roughness);
#else
	ambient += u_radiance_color * u_ambient;
#endif
    
#ifdef AMBIENT_OCCLUSION
	ambient *= material.ao;
#endif

#ifdef GI_CONETRACE
#if 0
	vec3 probe_pos = mul(u_gi_probe_transform, vec4(fragment.position, 1.0)).xyz;
    vec3 probe_coord = probe_pos * u_gi_probe_inv_extents * 0.5 + 0.5; // [-1,1] to [0,1]
    if(!( any(greaterThan(probe_coord, vec3_splat(1.0))) 
       || any(lessThan(probe_coord, vec3_splat(0.0))) ))
    {
        //vec4 probe_color = texture3DLod(s_gi_probe, probe_coord, 2.0);
        vec4 probe_color = texture3DLod(s_gi_probe, probe_coord, 0.0);
        //gl_FragColor = vec4(probe_coord, 1.0);
        gl_FragColor = vec4(probe_color.rgb, 1.0);
    }
    return;
#else
    gi_probe_compute(fragment.position, fragment.normal, fragment.binormal, fragment.tangent, material.roughness, ambient,  specular);
#endif
#endif

#ifdef DIRECT_LIGHT
	direct_light(fragment, material, fragment.depth, diffuse, specular);
#endif

    //apply_reflections(specular, ambient);
    
#ifdef CLUSTERED
    apply_cluster_lights(fragment, material, diffuse, specular);
#else
	apply_lights(fragment, material, diffuse, specular);
#endif
    
	ambient *= material.albedo;
    
#ifdef DIFFUSE_TOON
	specular *= material.specular * material.metallic * material.albedo * 2.0;
#else
    specular *= brdf_specular_term(fragment, material);
#endif

#ifdef FOG
    //apply_fog(fragment, emission, ambient, diffuse, specular);
    apply_fog_0(fragment, emission.rgb);
#endif

#ifdef MRT
	gl_FragData[0] = vec4(emission.rgb + diffuse + ambient, material.alpha);
	gl_FragData[1] = vec4(specular, material.metallic);
	gl_FragData[2] = vec4(normalize(fragment.normal) * 0.5 + 0.5, material.roughness);
#ifdef SUBSURFACE
	gl_FragData[3] = subsurface;
#endif

#else
	gl_FragColor = vec4(emission.rgb + ambient + diffuse + specular, material.alpha);
	//gl_FragColor = vec4(normalize(fragment.normal) * 0.5 + 0.5, 1.0);
	//gl_FragColor = vec4(v_color.rgb, 1.0);
#endif

#endif

}
