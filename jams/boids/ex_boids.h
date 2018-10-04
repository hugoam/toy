//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is provided 'as-is' under the zlib License, see the LICENSE.txt file.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <boids/Forward.h>
#include <toy/toy.h>

#ifdef BOIDS_SIMD
#include <immintrin.h>
#endif

using namespace mud;
using namespace toy;

extern "C"
{
	//_BOIDS_EXPORT void ex_boids_game(GameShell& app, Game& game);
}

namespace boids
{
#ifdef BOIDS_SIMD
	inline float dot_simd(const __m128& first, const __m128& second)
	{
		__m128 vd2 = _mm_dp_ps(first, second, 0x71); // src 0111 dest 0001
		return _mm_cvtss_f32(vd2);
	}

	inline __m128 cross_simd(__m128 a, __m128 b)
	{
		__m128 v0 = _mm_mul_ps(b, _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 0, 2, 1)));
		__m128 v1 = _mm_mul_ps(a, _mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 0, 2, 1)));
		__m128 result = _mm_sub_ps(v0, v1);
		return _mm_shuffle_ps(result, result, _MM_SHUFFLE(3, 0, 2, 1));
	}

	inline __m128 normalize_safe_simd(const __m128& vec)
	{
		__m128 l2 = _mm_dp_ps(vec, vec, 0x7F); // src 0111 dest 1111
		__m128 l = _mm_rsqrt_ps(l2);
		__m128 normalized = _mm_mul_ps(vec, l);
		__m128 mask = _mm_cmpeq_ps(vec, _mm_set_ps1(0.f));
		return _mm_blendv_ps(normalized, vec, mask);
	}

	inline __m128 normalize_simd(const __m128& vec)
	{
		__m128 l2 = _mm_dp_ps(vec, vec, 0x7F); // src 0111 dest 1111
		__m128 l = _mm_rsqrt_ps(l2);
		return _mm_mul_ps(vec, l);
	}

	struct float3
	{
		float m_f[4];
		float operator[](size_t i) const { return m_f[i]; }
	};

	struct vec3
	{
		vec3() {}
		vec3(__m128 v) : value(v) {}
		vec3(float v) : value(_mm_set_ps1(v)) {}
		vec3(float* v) : value(_mm_load_ps(v)) {}
		//vec3(float x, float y, float z, float w = 0.f) : vec3(std::array<float, 4>{ x, y, z, w }.data()) {}
		//vec3(float x, float y, float z, float w = 0.f) : value(_mm_set_ps(x, y, z, w)) {}
		vec3(float x, float y, float z, float w = 0.f) : value(_mm_setr_ps(x, y, z, w)) {}
		operator float3() const { float3 result; _mm_store_ps(result.m_f, value); return result; }
		operator mud::vec3() const { float3 result; _mm_store_ps(result.m_f, value); return { result[0], result[1], result[2] }; }
		__m128 value;
	};

	inline vec3 operator+(const vec3& first, const vec3& second) { return vec3(_mm_add_ps(first.value, second.value)); }
	inline vec3 operator-(const vec3& first, const vec3& second) { return vec3(_mm_sub_ps(first.value, second.value)); }
	inline vec3 operator*(const vec3& first, const vec3& second) { return vec3(_mm_mul_ps(first.value, second.value)); }
	inline vec3 operator/(const vec3& first, const vec3& second) { return vec3(_mm_div_ps(first.value, second.value)); }

	inline vec3 floor(const vec3& v) { return vec3(_mm_floor_ps(v.value)); }
	inline float length2(const vec3& v) { return dot_simd(v.value, v.value); }

	inline vec3 normalize_safe(const vec3& vec) { return vec3(normalize_safe_simd(vec.value)); }
	inline vec3 normalize(const vec3& vec) { return vec3(normalize_simd(vec.value)); }

	inline float dot(const vec3& a, const vec3& b) { return dot_simd(a.value, b.value); }
	inline vec3 cross(const vec3& a, const vec3& b) { return vec3(cross_simd(a.value, b.value)); }
#else
	using vec3 = glm::vec4;
#endif

	template <class T>
	struct Wrapper
	{
		Wrapper(T value) : m_value(value) {}
		operator const T&() const { return m_value; }
		operator T&() { return m_value; }
		T m_value;
	};

	struct Position
	{
		Position() {}
		Position(vec3 value) : m_value(value) {}
		operator const vec3&() const { return m_value; }
		operator vec3&() { return m_value; }
		vec3 m_value = vec3(0.f);
	};

	struct Heading
	{
		Heading() {}
		Heading(vec3 value) : m_value(value) {}
		operator const vec3&() const { return m_value; }
		operator vec3&() { return m_value; }
		vec3 m_value = { 0.f, 0.f, -1.f, 0.f };
	};

	struct Rotation
	{
		Rotation() {}
		Rotation(quat value) : m_value(value) {}
		operator const quat&() const { return m_value; }
		operator quat&() { return m_value; }
		quat m_value = ZeroQuat;
	};

	struct MoveSpeed
	{
		MoveSpeed() {}
		MoveSpeed(float value) : m_value(value) {}
		operator const float&() const { return m_value; }
		operator float&() { return m_value; }
		float m_value = 1.f;
	};

	struct Transform4
	{
		Transform4() : m_value(bxidentity()) {}
		Transform4(mat4 value) : m_value(value) {}
		operator const mat4&() const { return m_value; }
		operator mat4&() { return m_value; }
		mat4 m_value;
	};

	struct Boid
	{};

	struct BoidTarget
	{};

	struct BoidObstacle
	{};

	struct MoveForward
	{};

	class refl_ _BOIDS_EXPORT Player
	{
	public:
		Player(World& world);

		World* m_world;
	};
}

namespace mud
{
	template <> struct TypedBuffer<boids::Position> { static size_t index() { return 12; } };
	template <> struct TypedBuffer<boids::Heading> { static size_t index() { return 13; } };
	template <> struct TypedBuffer<boids::Rotation> { static size_t index() { return 14; } };
	template <> struct TypedBuffer<boids::MoveForward> { static size_t index() { return 15; } };
	template <> struct TypedBuffer<boids::MoveSpeed> { static size_t index() { return 16; } };
	template <> struct TypedBuffer<boids::Boid> { static size_t index() { return 17; } };
	template <> struct TypedBuffer<boids::BoidObstacle> { static size_t index() { return 18; } };
	template <> struct TypedBuffer<boids::BoidTarget> { static size_t index() { return 19; } };
	template <> struct TypedBuffer<boids::Transform4> { static size_t index() { return 20; } };
}
