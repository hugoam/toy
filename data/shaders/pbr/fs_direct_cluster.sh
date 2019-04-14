
uint cluster_index = fragment_cluster_index(fragment.coord.xyz);
LightCluster cluster = get_light_cluster(cluster_index);

uint index = cluster.record_offset;

int i  = 0;

#ifdef SHADOWS
float direct_shadows[4];
float point_shadows[MAX_LIGHTS];
float spot_shadows[MAX_LIGHTS];

for(i = 0; i < int(u_shadow_counts[LIGHT_DIRECT]); i++)
{
    CSMShadow shadow = read_csm_shadow(int(u_light_indices[i][LIGHT_DIRECT]));
    direct_shadows[i] = shadow_csm(shadow, fragment.position, fragment.depth);
}

for(i = 0; i < int(u_shadow_counts[LIGHT_POINT]); i++)
{
    Shadow shadow = read_shadow(int(u_light_indices[i][LIGHT_POINT]));
    point_shadows[i] = shadow_point(shadow, fragment.position);
}

for(i = 0; i < int(u_shadow_counts[LIGHT_SPOT]); i++)
{
    Shadow shadow = read_shadow(int(u_light_indices[i][LIGHT_SPOT]));
    spot_shadows[i] = shadow_spot(shadow, fragment.position);
}
#endif

index = cluster.record_offset;

for(i = 0; i < int(u_light_counts[LIGHT_DIRECT]); i++)
{
    Light direct = read_light(int(u_light_indices[i][LIGHT_DIRECT]));
    float factor = 1.0;
#ifdef SHADOWS
    factor *= direct_shadows[i];
#endif
    direct_brdf(direct.energy * factor, -direct.direction, fragment, material, diffuse, specular);
}

for(uint last_point = index + cluster.point_count; index < last_point; index++)
{
    Light light = read_cluster_light(index);
    vec3 l = light.position - fragment.position;
    float a = omni_attenuation(l, light);
#ifdef SHADOWS
    a *= (j < int(u_shadow_counts[LIGHT_POINT]) ? point_shadows[j] : 1.0);
#endif
    direct_brdf(light.energy * a, normalize(l), fragment, material, diffuse, specular);
}

for(uint last_spot = index + cluster.spot_count; index < last_spot; index++)
{
    Light light = read_cluster_light(index);
    vec3 l = light.position - fragment.position;
    float a = spot_attenuation(l, light);
#ifdef SHADOWS
    a *= (k < int(u_shadow_counts[LIGHT_SPOT]) ? spot_shadows[k] : 1.0);
#endif
    direct_brdf(light.energy * a, normalize(l), fragment, material, diffuse, specular);
}
