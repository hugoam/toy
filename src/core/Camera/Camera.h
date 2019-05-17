//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <stl/function.h>
#include <math/Vec.h>
#include <core/Forward.h>
#include <core/Spatial/Spatial.h>
#include <core/Movable/Movable.h>
#include <core/Physic/Scope.h>

namespace toy
{
	class refl_ TOY_CORE_EXPORT Camera
	{
	public:
		constr_ Camera() {}
		constr_ Camera(float distance, float near = 0.001f, float far = 1000.f);
		~Camera();

		static Entity create(ECS& ecs, HSpatial parent, const vec3& position, float lens_distance, float near = 0.001f, float far = 1000.f);

		attr_ float m_lens_distance = 1.f;
		attr_ float m_lens_angle = 0.f;

		attr_ float m_near = 0.001f;
		attr_ float m_far = 1000.f;

		attr_ float m_aspect;

		bool m_lens_updated = true;

		vec3 m_lens_position = vec3(0.f);
		quat m_lens_rotation = ZeroQuat;

		size_t m_last_updated = 0;

		void next_frame(const Spatial& spatial, size_t tick, size_t delta);

		void calc_lens_position(const Spatial& spatial);
		void calc_lens_rotation(const Spatial& spatial);

		void set_lens_distance(float distance);
		void zoom(float amount);

		void set_lens_angle(float angle);
		void pitch_lens(float amount);

		//void viewportRay(float tx, float ty, vec3& from, vec3& to);
		//void planarRay(float tx, float ty, vec3& from, vec3& to);

		vec3 lens_direction(const Spatial& spatial);

	//private:
		//bool m_planar;
		//float m_vertical_angle;
		//float m_plane_distance;

#ifdef TOY_THREADED
		TransfomReceiver m_receiver;
#endif
	};

	export_ TOY_CORE_EXPORT void jump_camera_to(Spatial& spatial, Camera& camera, const vec3& target, const quat& rotation, float distance, float angle, float duration = 1.f);
	export_ TOY_CORE_EXPORT void jump_camera_to(Spatial& spatial, Camera& camera, const vec3& position, float distance = 1.f, float rotation = 0.f);
	export_ TOY_CORE_EXPORT void move_camera_to(Spatial& spatial, Camera& camera, const vec3& position);

	export_ TOY_CORE_EXPORT void jump_camera_to(Entity camera, const vec3& target, const quat& rotation, float distance, float angle, float duration = 1.f);
	export_ TOY_CORE_EXPORT void jump_camera_to(Entity camera, const vec3& position, float distance = 1.f, float rotation = 0.f);
	export_ TOY_CORE_EXPORT void move_camera_to(Entity camera, const vec3& position);
}
