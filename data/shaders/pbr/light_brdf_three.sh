#include <pbr/light.sh>
#include <pbr/bsdf.sh>
#include <pbr/radiance.sh>

vec3 direct_energy(vec3 energy, vec3 l, Fragment fragment)
{
    float dotNL = saturate(dot(fragment.normal, l));
    vec3 irradiance = dotNL * energy;
#ifndef PHYSICALLY_CORRECT_LIGHTS
    irradiance *= M_PI; // punctual light
#endif
    return irradiance;
}

// taken from here: http://casual-effects.blogspot.ca/2011/08/plausible-environment-lighting-in-two.html
float getSpecularMIPLevel(float blinnShininessExponent, float highest) {

    float level = highest + 0.79248 - 0.5 * log2(pow2(blinnShininessExponent) + 1.0);

    // clamp to allowable LOD ranges.
    return clamp(level, 0.0, highest);
}

#ifdef BRDF_BLINN_PHONG
#define direct_brdf direct_blinn_phong
#define indirect_brdf indirect_blinn_phong
#endif

void direct_blinn_phong(vec3 energy, vec3 l, Fragment fragment, PhongMaterial material, inout vec3 diffuse, inout vec3 specular) {

#ifdef TOON
    vec3 irradiance = getGradientIrradiance(fragment.normal, l) * energy;
#else
    vec3 irradiance = direct_energy(energy, l, fragment);
#endif

    diffuse += irradiance * BRDF_Diffuse_Lambert(material.diffuse);
    specular += irradiance * BRDF_Specular_BlinnPhong(l, fragment, material.specular, material.shininess) * 1.0; //material.specularStrength;
}

void indirect_blinn_phong(Fragment fragment, PhongMaterial material, inout vec3 diffuse, inout vec3 specular) {

    diffuse *= BRDF_Diffuse_Lambert(material.diffuse);

}

float brdf_env_level(PhongMaterial material)
{
    return getSpecularMIPLevel(material.shininess, RADIANCE_MAX_LOD);
}

float brdf_env_specular(Fragment fragment, PhongMaterial material)
{
    return 1.0;
}

#ifdef BRDF_STANDARD

#define direct_brdf direct_standard
#define indirect_brdf indirect_standard

#define MAX_REFLECTANCE 0.16
#define DEFAULT_REFLECTANCE 0.04


PhysicalMaterial material;
material.albedo = albedo.rgb * (1.0 - metalness);
material.roughness = clamp(roughness, 0.04, 1.0);
#ifdef STANDARD
	material.f0 = mix(vec3(DEFAULT_REFLECTANCE), albedo.rgb, metalness);
#else
	material.f0 = mix(vec3(MAX_REFLECTANCE * pow2(reflectivity)), albedo.rgb, metalness);
	material.clearCoat = saturate(clearCoat); // Burley clearcoat model
	material.clearCoatRoughness = clamp(clearCoatRoughness, 0.04, 1.0);
#endif


// Clear coat directional hemishperical reflectance (this approximation should be improved)
float clearCoatDHRApprox(float roughness, float dotNL) {

    return MAX_REFLECTANCE + (1.0 - DEFAULT_REFLECTANCE) * (pow(1.0 - dotNL, 5.0) * pow(1.0 - roughness, 2.0));

}

#if NUM_RECT_AREA_LIGHTS > 0
struct RectAreaLight {
    vec3 color;
    vec3 position;
    vec3 halfWidth;
    vec3 halfHeight;
};

// Pre-computed values of LinearTransformedCosine approximation of BRDF
// BRDF approximation Texture is 64x64
uniform sampler2D ltc_1; // RGBA Float
uniform sampler2D ltc_2; // RGBA Float

uniform RectAreaLight rectAreaLights[ NUM_RECT_AREA_LIGHTS ];
#endif

void direct_rect_physical(RectAreaLight light, Fragment fragment, PhysicalMaterial material, inout vec3 diffuse, inout vec3 specular) {

    vec3 rectCoords[4];
    rectCoords[0] = light.position + light.halfWidth - light.halfHeight; // counterclockwise; light shines in local neg z direction
    rectCoords[1] = light.position - light.halfWidth - light.halfHeight;
    rectCoords[2] = light.position - light.halfWidth + light.halfHeight;
    rectCoords[3] = light.position + light.halfWidth + light.halfHeight;

    vec2 uv = LTC_Uv(fragment.normal, fragment.view, material.roughness);

    vec4 t1 = texture2D(ltc_1, uv);
    vec4 t2 = texture2D(ltc_2, uv);

    mat3 mInv = mat3(
        vec3(t1.x, 0, t1.y),
        vec3(  0, 1,    0),
        vec3(t1.z, 0, t1.w)
   );

    // LTC Fresnel Approximation by Stephen Hill
    // http://blog.selfshadow.com/publications/s2016-advances/s2016_ltc_fresnel.pdf
    vec3 fresnel = (material.f0 * t2.x + (vec3(1.0) - material.f0) * t2.y);

    specular += light.energy * fresnel * LTC_Evaluate(fragment.normal, fragment.view, fragment.position, mInv, rectCoords);

    diffuse += light.energy * material.albedo * LTC_Evaluate(fragment.normal, fragment.view, fragment.position, mat3(1.0), rectCoords);

}

void direct_standard(vec3 energy, vec3 l, Fragment fragment, Material material, inout vec3 diffuse, inout vec3 specular) {

    vec3 irradiance = direct_energy(energy, l, fragment);

    specular += irradiance * BRDF_Specular_GGX(l, fragment, material.f0, material.specularRoughness);

    diffuse += irradiance * BRDF_Diffuse_Lambert(material.albedo);
}

void direct_physical(vec3 energy, vec3 l, Fragment fragment, Material material, inout vec3 diffuse, inout vec3 specular) {

    vec3 irradiance = direct_energy(energy, l, fragment);
    
    float clearCoatDHR = material.clearcoat * clearCoatDHRApprox(material.clearCoatRoughness, dotNL);

    specular += (1.0 - clearCoatDHR) * irradiance * BRDF_Specular_GGX(l, fragment, material.f0, material.specularRoughness);

    diffuse += (1.0 - clearCoatDHR) * irradiance * BRDF_Diffuse_Lambert(material.albedo);

    specular += irradiance * material.clearcoat * BRDF_Specular_GGX(l, fragment, vec3(DEFAULT_SPECULAR_COEFFICIENT), material.clearCoatRoughness);
}

void indirect_standard(Fragment fragment, Material material, inout vec3 diffuse, inout vec3 specular) {

    diffuse *= BRDF_Diffuse_Lambert(material.albedo);
    specular *= BRDF_Specular_GGX_Environment(fragment, material.specularColor, material.specularRoughness);

}

void indirect_physical(vec3 irradiance, vec3 radiance, vec3 radiance_clearcoat, Fragment fragment, Material material, inout vec3 diffuse, inout vec3 specular) {

    float dotNV = saturate(dot(fragment.normal, fragment.view));
    float dotNL = dotNV;
    float clearCoatDHR = material.clearCoat * clearCoatDHRApprox(material.clearCoatRoughness, dotNL);

    diffuse += irradiance * BRDF_Diffuse_Lambert(material.albedo);
    specular += (1.0 - clearCoatDHR) * radiance * BRDF_Specular_GGX_Environment(fragment, material.specularColor, material.specularRoughness);
    specular += radiance_clearcoat * material.clearCoat * BRDF_Specular_GGX_Environment(fragment, vec3(DEFAULT_SPECULAR_COEFFICIENT), material.clearCoatRoughness);
}

#define BlinnShininessExponent(roughness)   GGXRoughnessToBlinnExponent(roughness)


// ref: https://seblagarde.files.wordpress.com/2015/07/course_notes_moving_frostbite_to_pbr_v32.pdf
float computeSpecularOcclusion(float dotNV, float ambientOcclusion, float roughness) {

    return saturate(pow(dotNV + ambientOcclusion, exp2(- 16.0 * roughness - 1.0)) - 1.0 + ambientOcclusion);

}
#endif
