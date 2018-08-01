//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/Camera/Camera.h>

#include <refl/Class.h>
#include <math/Anim/Anim.h>
#include <math/Random.h>

#include <core/Entity/Entity.h>
#include <core/World/World.h>
#include <core/WorldPage/WorldPage.h>

#include <core/World/Section.h>

using namespace mud; namespace toy
{
    Camera::Camera(Entity& entity, float lens_distance, float near, float far)
        : m_entity(entity)
		, m_lens_distance(lens_distance)
		, m_near(near)
        , m_far(far)
    {
		entity.m_world.add_task(this, short(Task::Entity));
		calc_lens_position();
	}

	Camera::~Camera()
	{
		m_entity.m_world.remove_task(this, short(Task::Entity));
	}
	
	void Camera::set_lens_distance(float distance)
	{
		m_lens_distance = distance;
		m_lens_updated = true;
	}

	void Camera::zoom(float amount)
	{
		m_lens_distance *= 1.f/amount;
		m_lens_updated = true;
	}

	void Camera::set_lens_angle(float angle)
	{
		m_lens_angle = angle;
		m_lens_updated = true;
	}

	void Camera::pitch_lens(float amount)
	{
		m_lens_angle += amount;
		m_lens_updated = true;
	}

	vec3 Camera::lens_direction()
	{
		return rotate(m_entity.front(), -m_lens_angle, m_entity.right());
	}

	void Camera::calc_lens_position()
	{
		m_lens_position = -this->lens_direction() * m_lens_distance;
		m_lens_position += m_entity.absolute_position();
	}

	void Camera::calc_lens_rotation()
	{
		m_lens_rotation = m_entity.absolute_rotation() * angleAxis(-m_lens_angle, to_vec3(Side::Right));
	}

	void Camera::next_frame(size_t tick, size_t delta)
	{
		UNUSED(delta);

		//if(m_entity.m_last_updated > m_last_updated || m_lensUpdated)
		{
			calc_lens_position();
			calc_lens_rotation();
		}
		m_last_updated = tick;
		m_lens_updated = false;
	}

	OCamera::OCamera(Id id, Entity& parent, const vec3& position, float lensDistance, float nearClipDistance, float farClipDistance)
		: Complex(id, type<OCamera>(), m_movable, m_receptor, m_camera)
		, m_entity(id, *this, parent, position, ZeroQuat)
		, m_movable(m_entity)
		, m_receptor(m_entity)
		, m_camera(m_entity, lensDistance, nearClipDistance, farClipDistance)
	{
		m_receptor.add_sphere(WorldMedium::me, 0.1f, CM_RECEPTOR);
	}

	void jump_camera_to(Camera& camera, const vec3& target, float distance, float rotation)
	{
		animate(Ref(&camera), member(&Camera::m_lens_distance), var(distance), 1.f);
		animate(Ref(&as<Transform>(camera.m_entity)), member(&Transform::m_position), var(target), 1.f);
		animate(Ref(&as<Transform>(camera.m_entity)), member(&Transform::m_rotation), var(rotate(camera.m_entity.m_rotation, rotation, Y3)), 1.f);
	}

	void move_camera_to(Camera& camera, const vec3& target)
	{
		animate(Ref(&as<Transform>(camera.m_entity)), member(&Transform::m_position), var(target), 1.f);
	}
}
