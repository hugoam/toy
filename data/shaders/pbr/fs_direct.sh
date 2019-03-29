#ifdef DIRECT_LIGHT
Light direct = read_light(0);

float factor = 1.0;
#ifdef CSM_SHADOW
factor = shadow_csm(direct, direct.shadow, fragment.position, fragment.depth);
#endif

direct_brdf(direct.energy * factor, -direct.direction, fragment, material, diffuse, specular);
#endif

//float shadows[64] = { 0.0 };

for(int i = 0; i < int(u_light_counts[LIGHT_POINT]); i++)
{
    Light light = read_light(int(u_light_indices[i][LIGHT_POINT]));
    vec3 l = light.position - fragment.position;
    float a = omni_attenuation(l, light);
    //a *= light.shadows ? shadow_point(light, light.shadow, fragment.position) : 1.0;
    direct_brdf(light.energy * a, normalize(l), fragment, material, diffuse, specular);
}

for(int j = 0; j < int(u_light_counts[LIGHT_SPOT]); j++)
{
    Light light = read_light(int(u_light_indices[j][LIGHT_SPOT]));
    vec3 l = light.position - fragment.position;
    float a = spot_attenuation(l, light);
    //a *= light.shadows ? shadow_spot(light, light.shadow, fragment.position) : 1.0;
    direct_brdf(light.energy * a, normalize(l), fragment, material, diffuse, specular);
}
