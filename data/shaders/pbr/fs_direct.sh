
float direct_shadows[4];
float point_shadows[MAX_LIGHTS];
float spot_shadows[MAX_LIGHTS];

#ifdef CSM_SHADOW
for(int i = 0; i < int(u_shadow_counts[LIGHT_DIRECT]); i++)
{
    CSMShadow shadow = read_csm_shadow(int(u_light_indices[i][LIGHT_DIRECT]));
    direct_shadows[i] = shadow_csm(shadow, fragment.position, fragment.depth);
}
#endif

for(int i = 0; i < int(u_shadow_counts[LIGHT_POINT]); i++)
{
    Shadow shadow = read_shadow(int(u_light_indices[i][LIGHT_POINT]));
    point_shadows[i] = shadow_point(shadow, fragment.position);
}

for(int i = 0; i < int(u_shadow_counts[LIGHT_SPOT]); i++)
{
    Shadow shadow = read_shadow(int(u_light_indices[i][LIGHT_SPOT]));
    spot_shadows[i] = shadow_spot(shadow, fragment.position);
}

#ifdef DIRECT_LIGHT
for(int i = 0; i < int(u_light_counts[LIGHT_DIRECT]); i++)
{
    Light direct = read_light(int(u_light_indices[i][LIGHT_DIRECT]));
    float factor = (i < int(u_shadow_counts[LIGHT_DIRECT]) ? direct_shadows[i] : 1.0);
    direct_brdf(direct.energy * factor, -direct.direction, fragment, material, diffuse, specular);
}
#endif

for(int j = 0; j < int(u_light_counts[LIGHT_POINT]); j++)
{
    Light light = read_light(int(u_light_indices[j][LIGHT_POINT]));
    vec3 l = light.position - fragment.position;
    float a = omni_attenuation(l, light) * (j < int(u_shadow_counts[LIGHT_POINT]) ? point_shadows[j] : 1.0);
    direct_brdf(light.energy * a, normalize(l), fragment, material, diffuse, specular);
}

for(int k = 0; k < int(u_light_counts[LIGHT_SPOT]); k++)
{
    Light light = read_light(int(u_light_indices[k][LIGHT_SPOT]));
    vec3 l = light.position - fragment.position;
    float a = spot_attenuation(l, light) * (k < int(u_shadow_counts[LIGHT_SPOT]) ? spot_shadows[k] : 1.0);
    direct_brdf(light.energy * a, normalize(l), fragment, material, diffuse, specular);
}
