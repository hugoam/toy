//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <math/Math.h>
#include <core/Entity/Entity.h>
#include <core/Movable/Movable.h>

using namespace mud; namespace toy
{
	class TOY_CORE_EXPORT MotionSource
	{
	public:
		virtual void update_transform(const vec3& position, const quat& rotation) = 0;
		virtual void update_motion(const vec3& linear_velocity, const vec3& angular_velocity) = 0;
	};

    class TOY_CORE_EXPORT MotionState
    {
    public:
		MotionState(Entity& entity, const vec3& offset)
			: m_entity(entity), m_movable(entity.isa<Movable>() ? &entity.as<Movable>() : nullptr)
			, m_offset(offset), m_last_updated(0)
		{
			if(m_movable)
				m_movable->m_motion_state = this;
		}

		Entity& m_entity;
		Movable* m_movable;
		MotionSource* m_source;
		vec3 m_offset;
		size_t m_last_updated;

		struct Transform { vec3 m_position; quat m_rotation; };

		Transform transform()
		{
			quat rotation = m_entity.absolute_rotation();
			vec3 position = m_entity.absolute_position() + rotate(rotation, m_offset);
			return { position, rotation };
		}

		void sync_transform(const vec3& position, const quat& rotation)
		{
			quat inv_rotation = inverse(m_entity.m_parent->absolute_rotation());
			m_entity.set_position(position - m_entity.m_parent->absolute_position() - rotate(inv_rotation, m_offset));
			m_entity.set_rotation(rotation * inv_rotation);
		}

		void update(size_t tick)
		{
			quat rotation = m_entity.absolute_rotation();
			if(m_entity.m_last_modified > m_last_updated)
			{
				vec3 position = m_entity.absolute_position() + rotate(rotation, m_offset);
				m_source->update_transform(position, rotation);
			}
			if(m_movable && m_movable->m_updated > m_last_updated)
			{
				vec3 linear_velocity = rotate(rotation, m_movable->m_linear_velocity);
				vec3 angular_velocity = rotate(rotation, m_movable->m_angular_velocity);
				m_source->update_motion(linear_velocity, angular_velocity);
			}
			m_last_updated = tick;
		}
    };
}
