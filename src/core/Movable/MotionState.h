//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <math/Math.h>
#include <core/Spatial/Spatial.h>
#include <core/Movable/Movable.h>

using namespace mud; namespace toy
{
	class TOY_CORE_EXPORT TransformSource
	{
	public:
		virtual void update_transform(const vec3& position, const quat& rotation) = 0;
	};

	class TOY_CORE_EXPORT MotionSource
	{
	public:
		virtual void update_motion(const vec3& linear_velocity, const vec3& angular_velocity) = 0;
	};

    class TOY_CORE_EXPORT MotionState
    {
    public:
		MotionState(const vec3& offset = Zero3)
			: m_offset(offset)
		{
			//if(m_movable)
			//	m_movable->m_motion_state = this;
		}

		TransformSource* m_transform_source = nullptr;
		MotionSource* m_motion_source = nullptr;
		vec3 m_offset = Zero3;
		size_t m_last_updated = 0;

		struct Transform { vec3 m_position; quat m_rotation; };

		Transform transform(const Spatial& spatial) const
		{
			quat rotation = spatial.absolute_rotation();
			vec3 position = spatial.absolute_position() + rotate(rotation, m_offset);
			return { position, rotation };
		}

		void sync_transform(Spatial& spatial, const vec3& position, const quat& rotation)
		{
			quat inv_rotation = inverse(spatial.m_parent->absolute_rotation());
			spatial.set_position(position - spatial.m_parent->absolute_position() - rotate(inv_rotation, m_offset));
			spatial.set_rotation(rotation * inv_rotation);
		}

		void update_transform(Spatial& spatial)
		{
			quat rotation = spatial.absolute_rotation();
			vec3 position = spatial.absolute_position() + rotate(rotation, m_offset);
			m_transform_source->update_transform(position, rotation);
		}

		void update(Spatial& spatial, const quat& rotation)
		{
			if(spatial.m_last_modified > m_last_updated)
			{
				vec3 position = spatial.absolute_position() + rotate(rotation, m_offset);
				m_transform_source->update_transform(position, rotation);
			}
		}

		void update(Spatial& spatial, size_t tick)
		{
			quat rotation = spatial.absolute_rotation();
			this->update(spatial, rotation);
			m_last_updated = tick;
		}

		void update(Spatial& spatial, Movable& movable, size_t tick)
		{
			quat rotation = spatial.absolute_rotation();
			this->update(spatial, rotation);
			if(movable.m_updated > m_last_updated)
			{
				vec3 linear_velocity = rotate(rotation, movable.m_linear_velocity);
				vec3 angular_velocity = rotate(rotation, movable.m_angular_velocity);
				m_motion_source->update_motion(linear_velocity, angular_velocity);
			}
			m_last_updated = tick;
		}
    };
}
