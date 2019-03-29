#ifndef MUD_SHADER_RADIANCE
#define MUD_SHADER_RADIANCE

#include <spherical.sh>
#include <gpu/zone.sh>

//uniform vec4 u_pbr_globals;
//#define u_roughness_levels u_pbr_globals.x

#define RADIANCE_MAX_LOD 7.0

#ifdef RADIANCE_ENVMAP

#ifdef RADIANCE_CUBE
SAMPLERCUBE(s_radiance, 10);
#else
SAMPLER2D(s_radiance, 10);
#endif

vec3 radiance_refraction(Zone zone, vec3 view, vec3 normal, float refraction, float level)
{
	vec3 dir = refract(-view, normal, refraction);
	dir = normalize(mul(u_invView, vec4(dir, 0.0)).xyz);
#ifdef RADIANCE_CUBE
	vec3 rad = textureCubeLod(s_radiance, vec3(-dir.x, dir.y, dir.z), level).rgb;
#else
	vec3 rad = textureSpherical2D(s_radiance, dir, level).rgb;
#endif
    return rad;
}

vec3 radiance_reflection(Zone zone, vec3 view, vec3 normal, float level)
{
	vec3 dir = reflect(-view, normal);
	dir = normalize(mul(u_invView, vec4(dir, 0.0)).xyz);
#ifdef RADIANCE_CUBE
	vec3 rad = textureCubeLod(s_radiance, vec3(-dir.x, dir.y, dir.z), level).rgb;
#else
	vec3 rad = textureSpherical2D(s_radiance, dir, level).rgb;
#endif
    return rad * zone.radiance_color * zone.radiance_energy;
}

vec3 radiance_ambient(Zone zone, vec3 normal)
{
	vec3 dir = normalize(mul(u_invView, vec4(normal, 0.0)).xyz);
#ifdef RADIANCE_CUBE
	vec3 amb = textureCubeLod(s_radiance, vec3(-dir.x, dir.y, dir.z), RADIANCE_MAX_LOD).rgb;
#else
	vec3 amb = textureSpherical2D(s_radiance, dir, RADIANCE_MAX_LOD).rgb;
#endif
	return amb * zone.radiance_color * zone.ambient;
}
#endif

#endif
