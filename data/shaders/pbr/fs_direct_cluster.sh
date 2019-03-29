#ifdef DIRECT_LIGHT
Light direct = read_light(0);

float factor = 1.0;
#ifdef CSM_SHADOW
factor = shadow_csm(direct, direct.shadow, fragment.position, fragment.depth);
#endif

direct_brdf(direct.energy * factor, -direct.direction, fragment, material, diffuse, specular);
#endif

uint cluster_index = fragment_cluster_index(fragment.coord.xyz);
LightCluster cluster = get_light_cluster(cluster_index);

uint index = cluster.record_offset;

for(uint last_point = index + cluster.point_count; index < last_point; index++)
{
    Light light = read_cluster_light(index);
    vec3 l = light.position - fragment.position;
    float a = omni_attenuation(l, light);
    //a *= light.shadows ? shadow_point(light, light.shadow, fragment.position) : 1.0;
    direct_brdf(light.energy * a, normalize(l), fragment, material, diffuse, specular);
}

for(uint last_spot = index + cluster.spot_count; index < last_spot; index++)
{
    Light light = read_cluster_light(index);
    vec3 l = light.position - fragment.position;
    float a = spot_attenuation(l, light);
    //a *= light.shadows ? shadow_spot(light, light.shadow, fragment.position) : 1.0;
    direct_brdf(light.energy * a, normalize(l), fragment, material, diffuse, specular);
}
