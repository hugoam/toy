//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/Movable/Movable.h>

#include <math/Vec.hpp>
#include <math/Timer.h>

#include <core/Bullet/Bullet.h.inl>

#include <core/World/World.h>
#include <core/Spatial/Spatial.h>
#include <core/Movable/MotionState.h>

#include <core/World/Section.h>

namespace toy
{
	vec3 to_2d(const vec3& vec) { return { vec.x, 0.f, vec.z }; }

	float angle_flat(const vec3& v1, const vec3& v2)
	{
		vec3 vec1 = normalize(vec3(v1.x, 0.f, v1.z));
		vec3 vec2 = normalize(vec3(v2.x, 0.f, v2.z));

		return oriented_angle(vec1, vec2, y3);
	}

	bool spin_2d(Spatial& spatial, const vec3& axis, const vec3& target, float velocity, float time_step, float margin)
	{
		UNUSED(time_step); UNUSED(margin);
		vec3 direction = normalize(target - spatial.m_position);
		float total_angle = angle_flat(spatial.front(), direction);
		float angle = min(sign(total_angle) * velocity, total_angle);
		quat rotation = rotate(spatial.m_rotation, angle, axis);
		spatial.set_rotation(rotation);
		return angle == total_angle;
	}

	bool lookat_2d(Spatial& spatial, const vec3& axis, const vec3& target, float velocity, float time_step, float margin)
	{
		UNUSED(axis); UNUSED(velocity); UNUSED(time_step); UNUSED(margin);
		vec3 direction = normalize(target - spatial.m_position);
		float targetAngle = angle_flat(-z3, direction);
		quat rotation = angle_axis(targetAngle, y3);
		spatial.set_rotation(rotation);
		return true;
	}

	vec3 project_move_2d(Spatial& spatial, const vec3& target, float velocity, float time_step, float margin)
	{
		UNUSED(margin);
		vec3 direction = normalize(target - spatial.m_position);
		direction.y = 0.f;

		vec3 movement = direction * velocity * time_step;
		vec3 distance = target - spatial.m_position;
		distance.y = 0.f;

		if(length2(movement) >= length2(distance))
			return target;
		else
			return spatial.m_position + movement;
	}

	bool move_2d(Spatial& spatial, const vec3& target, float velocity, float time_step, float margin)
	{
		if(target == spatial.m_position)
			return true;

		vec3 position = project_move_2d(spatial, target, velocity, time_step, margin);
		spatial.set_position(position);
		return position == target;
	}

	bool move_2d(Spatial& spatial, Movable& movable, const vec3& target, float velocity, float time_step, float margin)
	{
		UNUSED(time_step); UNUSED(margin);
		if(target == spatial.m_position)
			return true;
		movable.set_linear_velocity(normalize(target - spatial.m_position) * velocity);
		return false;
	}

	vec3 clamp(const vec3& vec, float l)
	{
		return length(vec) > l ? normalize(vec) * l : vec;
	}

	bool steer_2d(Spatial& spatial, Movable& movable, const vec3& target, float velocity, float time_step, float margin)
	{
		UNUSED(time_step);
		vec3 segment = to_2d(target - spatial.absolute_position());
		float distance = length(segment);
		
		if(distance < margin)
			return true;

		const float seek_force = 0.5f;
		const float approach_radius = 0.35f;
		UNUSED(approach_radius);

		vec3 desired = segment / distance * velocity;
		vec3 steer = desired - movable.m_direction;
		steer = clamp(steer, seek_force);

		movable.m_direction += steer;
		movable.m_direction = clamp(movable.m_direction, velocity);
		if(distance < velocity / 10.f)
			movable.m_direction = clamp(movable.m_direction, distance + 0.01f);

		float angle = oriented_angle(normalize(movable.m_direction), -z3, y3);
		spatial.set_rotation(rotate(ZeroQuat, -angle, y3));
		movable.set_linear_velocity(rotate(movable.m_direction, angle, y3));

		return false;
	}

	bool steer_2d(Spatial& spatial, const vec3& target, float velocity, float time_step, float margin)
	{
		bool done = spin_2d(spatial, y3, target, 1.f, time_step, margin);
		if(true) // m_agent.forecast(project_move_2d(spatial, target, velocity, time_step))
			done &= move_2d(spatial, target, velocity, time_step, margin);
		return done;
	}

	bool stick_2d(Spatial& spatial, const vec3& target, float velocity, float time_step, float margin)
	{
		//if(m_target.moving())
		//	m_target.stick(m_source);

		spin_2d(spatial, y3, target, 1.f, time_step, margin);
		move_2d(spatial, target, velocity, time_step, margin);
		return false;
	}

	bool track_2d(Spatial& spatial, const vec3& target, float velocity, float time_step, float margin)
	{
		/*if(m_targetMovable && m_targetMovable->m_moving)
		{
			if(m_targetManoeuv)
				m_sticky.set_position(m_targetManoeuv->m_disq.closest(m_agent.m_disq));
			else
				m_sticky.set_position(m_agent.m_disq.attract(spatial.m_position, target.m_position, m_distance));
		}*/

		return steer_2d(spatial, target, velocity, time_step, margin);
	}

	Movable::Movable(const vec3& position)
		: m_previous_position(position)
	{}

	Movable::~Movable()
	{}

	void Movable::set_acceleration(const vec3& acceleration, const vec3& maxLinVel)
	{
		m_acceleration = acceleration;
		m_max_linear_velocity = maxLinVel;
		m_acceleration_updated = m_last_tick+1;
	}

	void Movable::modify_acceleration(const vec3& acceleration)
	{
		m_acceleration += acceleration;
		m_acceleration_updated = m_last_tick+1;
	}

    void Movable::set_linear_velocity(const vec3& linVel)
	{
		m_linear_velocity = linVel;
		m_updated = m_last_tick+1;
	}

	void Movable::modify_linear_velocity(const vec3& linVel)
	{
		m_linear_velocity += linVel;
		m_updated = m_last_tick+1;
	}

    void Movable::set_angular_velocity(const vec3& angVel)
	{
		m_angular_velocity = angVel;
		m_updated = m_last_tick+1;
	}

	void Movable::modify_angular_velocity(const vec3& angVel)
	{
		m_angular_velocity += angVel;
		m_updated = m_last_tick+1;
	}

    void Movable::next_frame(Spatial& spatial, size_t tick, size_t delta)
	{
		if(m_acceleration != vec3(0.f))
		{
			//m_linear_velocity += m_acceleration * (delta * float(TICK_INTERVAL));
			//if(m_linear_velocity > m_maxLinearVelocity)
			//	m_linear_velocity = m_maxLinearVelocity;
		}

		//if(m_linear_velocity != vec3(0.f) || m_angular_velocity != vec3(0.f))
		if((m_linear_velocity != vec3(0.f) || m_angular_velocity != vec3(0.f)) && m_motion_state == nullptr)
        {
			m_previous_position = spatial.m_position;

			btVector3 linear_vel = to_btvec3(rotate(spatial.m_rotation, m_linear_velocity));
			btVector3 angular_vel = to_btvec3(rotate(spatial.m_rotation, m_angular_velocity));

			btTransform current(to_btquat(spatial.m_rotation), to_btvec3(spatial.m_position));
            btTransform updated;
            btTransformUtil::integrateTransform(current, linear_vel, angular_vel, float(delta * c_tick_interval), updated);

			if(!linear_vel.isZero())
				spatial.set_position(to_vec3(updated.getOrigin()));
			if(!angular_vel.isZero())
				spatial.set_rotation(to_quat(updated.getRotation()));

#if 0
			printf("move spatial from (%.2f, %.2f, %.2f) to (%.2f, %.2f, %.2f)\n", m_previous_position.x, m_previous_position.y, m_previous_position.z,
																				  spatial.m_position.x, spatial.m_position.y, spatial.m_position.z);
#endif

			m_moving = true;
        }
		else
		{
			m_moving = false;
		}

		m_last_tick = tick;
    }
}
