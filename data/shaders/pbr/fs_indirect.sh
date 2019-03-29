#ifdef RADIANCE_ENVMAP
    diffuse += radiance_ambient(zone, fragment.normal);
#ifdef REFRACTION
    specular += radiance_refraction(zone, fragment.view, fragment.normal, material.refraction, brdf_env_level(material))
              * brdf_env_specular(fragment, material);
#else
    specular += radiance_reflection(zone, fragment.view, fragment.normal, brdf_env_level(material))
              * brdf_env_specular(fragment, material);
#endif
#else
    diffuse += zone.radiance_color * zone.ambient;
#endif

#if (NUM_HEMI_LIGHTS > 0)
    for (int i = 0; i < NUM_HEMI_LIGHTS; i ++) {
        diffuse += getHemisphereLightIrradiance(hemisphereLights[ i ], geometry);
    }
#endif

#if defined LIGHTMAP
    vec4 lightmap = sample_material_texture(s_lightmap, fragment.uv2);
    //diffuse += lightmap.rgb;
    diffuse += decodeHDR(lightmap);
    //specular = trace_specular(s_gi_probe, cone.pos, cone.refl, material.roughness * material.roughness, u_gi_probe_bias) * u_gi_probe_specular;
#elif defined GI_CONETRACE
    ConeStart cone = cone_start(fragment.position, fragment.normal);
    trace_gi_probe(cone, material.roughness, diffuse, specular);
    //gl_FragColor = vec4(gi_probe_debug(fragment.position, 0.0), 1.0);
    //gl_FragColor = vec4(debug_trace_diffuse(s_gi_probe, mul(u_gi_probe_transform, vec4(fragment.normal, 0.0)).xyz), 1.0);
    //return;
#endif

#ifdef AMBIENT_OCCLUSION
    diffuse *= lit.ao;
#endif

    //apply_reflections(specular, ambient);
