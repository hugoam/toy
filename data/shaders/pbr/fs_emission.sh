#ifdef EMISSIVE
    vec3 emission_tex = sample_material_texture(s_emissive, fragment.uv).rgb;
    vec4 emission = vec4((lit.emissive + emission_tex) * lit.energy, lit.energy);
#else
    vec4 emission = vec4_splat(0.0);
#endif
