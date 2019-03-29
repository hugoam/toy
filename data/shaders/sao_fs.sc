$input v_uv0

#include <filter.sh>

uniform vec4 u_sao_p0;
#define u_scale;
#define u_intensity;
#define u_bias;

uniform vec4 u_sao_p1;
#define u_kernelRadius;
#define u_minResolution;
#define u_size;

// RGBA depth

#include <packing>

vec4 getDefaultColor(vec2 screenPosition) {
	#if DIFFUSE_TEXTURE == 1
	return texture2D(s_diffuse, v_uv0);
	#else
	return vec4(1.0);
	#endif
}
float getDepth(vec2 screenPosition) {
	return texture2D(tDepth, screenPosition).x;
}
float getViewZ(float depth) {
	#if PERSPECTIVE_CAMERA == 1
	return perspectiveDepthToViewZ(depth);
	#else
	return orthographicDepthToViewZ(depth);
	#endif
}
vec3 getViewPosition(vec2 screenPosition, float depth, float viewZ) {
	float clipW = cameraProjectionMatrix[2][3] * viewZ + cameraProjectionMatrix[3][3];
	vec4 clipPosition = vec4((vec3(screenPosition, depth) - 0.5) * 2.0, 1.0);
	clipPosition *= clipW; // unprojection.
	return (cameraInverseProjectionMatrix * clipPosition).xyz;
}
vec3 getViewNormal(vec3 viewPosition, vec2 screenPosition) {
	return unpackRGBToNormal(texture2D(tNormal, screenPosition).xyz);
}
float scaleDividedByCameraFar;
float minResolutionMultipliedByCameraFar;
float getOcclusion(vec3 centerViewPosition, vec3 centerViewNormal, vec3 sampleViewPosition) {
	vec3 viewDelta = sampleViewPosition - centerViewPosition;
	float viewDistance = length(viewDelta);
	float scaledScreenDistance = scaleDividedByCameraFar * viewDistance;
	return max(0.0, (dot(centerViewNormal, viewDelta) - minResolutionMultipliedByCameraFar) / scaledScreenDistance - bias) / (1.0 + pow2(scaledScreenDistance));
}
// moving costly divides into consts
const float ANGLE_STEP = PI2 * float(NUM_RINGS) / float(NUM_SAMPLES);
const float INV_NUM_SAMPLES = 1.0 / float(NUM_SAMPLES);
float getAmbientOcclusion(vec3 centerViewPosition) {
	// precompute some variables require in getOcclusion.
	scaleDividedByCameraFar = u_scale / u_z_far;
	minResolutionMultipliedByCameraFar = u_minResolution * u_z_far;
	vec3 centerViewNormal = getViewNormal(centerViewPosition, v_uv0);
	// jsfiddle that shows sample pattern: https://jsfiddle.net/a16ff1p7/
	float angle = rand(v_uv0 + randomSeed) * PI2;
	vec2 radius = vec2(kernelRadius * INV_NUM_SAMPLES) / size;
	vec2 radiusStep = radius;
	float occlusionSum = 0.0;
	float weightSum = 0.0;
	for(int i = 0; i < NUM_SAMPLES; i ++) {
		vec2 sampleUv = v_uv0 + vec2(cos(angle), sin(angle)) * radius;
		radius += radiusStep;
		angle += ANGLE_STEP;
		float sampleDepth = getDepth(sampleUv);
		if(sampleDepth >= (1.0 - EPSILON)) {
			continue;
		}
		float sampleViewZ = getViewZ(sampleDepth);
		vec3 sampleViewPosition = getViewPosition(sampleUv, sampleDepth, sampleViewZ);
		occlusionSum += getOcclusion(centerViewPosition, centerViewNormal, sampleViewPosition);
		weightSum += 1.0;
	}
	if(weightSum == 0.0) discard;
	return occlusionSum * (intensity / weightSum);
}
void main() {
	float centerDepth = getDepth(v_uv0);
	if(centerDepth >= (1.0 - EPSILON)) {
		discard;
	}
	float centerViewZ = getViewZ(centerDepth);
	vec3 viewPosition = getViewPosition(v_uv0, centerDepth, centerViewZ);
	float ambientOcclusion = getAmbientOcclusion(viewPosition);
	gl_FragColor = getDefaultColor(v_uv0);
	gl_FragColor.xyz *=  1.0 - ambientOcclusion;
}