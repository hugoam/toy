//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/Types.h>
#include <core/Camera/Camera.h>

#include <refl/Class.h>
#include <math/Random.h>

#include <core/Spatial/Spatial.h>
#include <core/World/World.h>
#include <core/Anim/Anim.h>

#include <core/World/Section.h>

using namespace mud; namespace toy
{
	Entity Camera::create(ECS& ecs, HSpatial parent, const vec3& position, float lens_distance, float near, float far)
	{
		Entity entity = { ecs.CreateEntity<Spatial, Movable, toy::Camera>(), ecs.m_index };
		ecs.SetComponent(entity, Spatial(parent, position, ZeroQuat));
		ecs.SetComponent(entity, Movable(HSpatial(entity)));
		ecs.SetComponent(entity, toy::Camera(HSpatial(entity), lens_distance, near, far));
		return entity;
	}

    Camera::Camera(HSpatial spatial, float lens_distance, float near, float far)
        : m_spatial(spatial)
		, m_lens_distance(lens_distance)
		, m_near(near)
        , m_far(far)
    {
		calc_lens_position(spatial);
	}

	Camera::~Camera()
	{}
	
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

	vec3 Camera::lens_direction(const Spatial& spatial)
	{
		return rotate(spatial.front(), -m_lens_angle, spatial.right());
	}

	void Camera::calc_lens_position(const Spatial& spatial)
	{
		m_lens_position = -this->lens_direction(spatial) * m_lens_distance;
		m_lens_position += spatial.absolute_position();
	}

	void Camera::calc_lens_rotation(const Spatial& spatial)
	{
		m_lens_rotation = spatial.absolute_rotation() * angleAxis(-m_lens_angle, to_vec3(Side::Right));
	}

	void Camera::next_frame(const Spatial& spatial, size_t tick, size_t delta)
	{
		UNUSED(delta);

		//if(m_spatial.m_last_updated > m_last_updated || m_lensUpdated)
		{
			calc_lens_position(spatial);
			calc_lens_rotation(spatial);
		}
		m_last_updated = tick;
		m_lens_updated = false;
	}

	void jump_camera_to(Spatial& spatial, Camera& camera, const vec3& target, float distance, float rotation)
	{
		animate(Ref(&camera), member(&Camera::m_lens_distance), var(distance), 1.f);
		animate(Ref(&as<Transform>(spatial)), member(&Transform::m_position), var(target), 1.f);
		animate(Ref(&as<Transform>(spatial)), member(&Transform::m_rotation), var(rotate(spatial.m_rotation, rotation, Y3)), 1.f);
	}

	void move_camera_to(Spatial& spatial, Camera& camera, const vec3& target)
	{
		UNUSED(camera);
		animate(Ref(&as<Transform>(spatial)), member(&Transform::m_position), var(target), 1.f);
	}
}
