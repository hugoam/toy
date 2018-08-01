//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <proto/Proto.h>
#include <math/Math.h>
#include <math/Vec.h>
#include <infra/Updatable.h>
#include <core/Forward.h>
#include <core/Entity/Entity.h>
#include <core/Movable/Movable.h>
#include <core/Physic/Scope.h>
#include <core/Entity/EntityObserver.h>

#ifndef MUD_CPP_20
#include <functional>
#include <array>
#endif

using namespace mud; namespace toy
{
	class refl_ TOY_CORE_EXPORT Camera : public Updatable
	{
	public:
		constr_ Camera(Entity& entity, float lensDistance = 1.f, float near = 0.001f, float far = 1000.f);
		~Camera();

		attr_ Entity& m_entity;

		attr_ float m_lens_distance = 1.f;
		attr_ float m_lens_angle = 0.f;

		attr_ float m_near = 0.001f;
		attr_ float m_far = 1000.f;

		attr_ float m_aspect;

		bool m_lens_updated = true;

		vec3 m_lens_position = Zero3;
		quat m_lens_rotation = ZeroQuat;

		size_t m_last_updated = 0;

		void next_frame(size_t tick, size_t delta);

		void calc_lens_position();
		void calc_lens_rotation();

		void set_lens_distance(float distance);
		void zoom(float amount);

		void set_lens_angle(float angle);
		void pitch_lens(float amount);

		//void viewportRay(float tx, float ty, vec3& from, vec3& to);
		//void planarRay(float tx, float ty, vec3& from, vec3& to);

		vec3 lens_direction();

	private:
		bool m_planar;
		float m_vertical_angle;
		float m_plane_distance;

#ifdef TOY_THREADED
		TransfomReceiver m_receiver;
#endif
	};

	class refl_ TOY_CORE_EXPORT OCamera : public Complex
	{
	public:
		constr_ OCamera(Id id, Entity& parent, const vec3& position, float lensDistance, float nearClipDistance = 0.001f, float farClipDistance = 1000.f);
		
		comp_ attr_ Entity m_entity;
		comp_ attr_ Movable m_movable;
		comp_ attr_ Receptor m_receptor;
		comp_ attr_ Camera m_camera;
	};

	export_ TOY_CORE_EXPORT void jump_camera_to(Camera& camera, const vec3& position, float distance = 1.f, float rotation = 0.f);
	export_ TOY_CORE_EXPORT void move_camera_to(Camera& camera, const vec3& position);
}
