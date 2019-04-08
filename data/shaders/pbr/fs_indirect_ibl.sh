#ifdef RADIANCE_ENVMAP
    diffuse += env_brdf_diffuse(fragment, material, ibl_diffuse(fragment.normal) * zone.ambient);
#ifdef REFRACTION
    vec3 envspec = ibl_refract(fragment.view, fragment.normal, material.refraction, env_brdf_miplevel(material));
#else
    vec3 envspec = ibl_reflect(fragment.view, fragment.normal, env_brdf_miplevel(material));
#endif
    specular += env_brdf_specular(fragment, material, envspec * zone.radiance * zone.energy);
#else
    diffuse += zone.ambient * PI;
#endif

