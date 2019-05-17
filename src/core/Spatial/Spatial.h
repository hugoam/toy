//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <stl/memory.h>
#include <stl/vector.h>
#include <pool/ObjectPool.h>
#include <math/Vec.hpp>
#include <math/Axes.h>
#include <core/Forward.h>
#include <core/Structs.h>

namespace toy
{
	class refl_ TOY_CORE_EXPORT Spatial : public Transform
    {
	public:
		constr_ Spatial() {}
		constr_ Spatial(HSpatial parent, const vec3& position, const quat& rotation);
		constr_ Spatial(World& world, HSpatial parent, const vec3& position, const quat& rotation);
        ~Spatial();

		attr_ World* m_world = nullptr;
		attr_ link_ HSpatial m_parent;

		attr_ graph_ vector<HSpatial> m_contents;

		size_t m_last_tick = 0;
		size_t m_last_updated = 0;
		size_t m_last_modified = 0;

		bool m_moved = false;
		bool m_hooked = true;

		Spatial& origin();
		bool is_child_of(HSpatial spatial);

		vec3 absolute_position() const;
		quat absolute_rotation() const;

		inline void set_dirty(bool moved) { m_last_updated = m_last_tick + 1; m_last_modified = m_last_tick + 1; m_moved = moved; }
		inline void set_sync_dirty(bool moved) { m_last_updated = m_last_tick + 1; m_moved = moved; }

		meth_ inline void set_position(const vec3& position) { m_position = position; this->set_dirty(true); }
		meth_ inline void set_rotation(const quat& rotation) { m_rotation = rotation; this->set_dirty(false); }

		inline void sync_position(const vec3& position) { m_position = position; this->set_sync_dirty(true); }
		inline void sync_rotation(const quat& rotation) { m_rotation = rotation; this->set_sync_dirty(false); }

		inline vec3 front() const { return two::rotate(m_rotation, to_vec3(Side::Front)); }
		inline vec3 right() const { return two::rotate(m_rotation, to_vec3(Side::Right)); }
		inline vec3 up()    const { return two::rotate(m_rotation, to_vec3(Side::Up)); }
		inline vec3 down()  const { return two::rotate(m_rotation, to_vec3(Side::Down)); }

		void translate(const vec3& vec);
		void rotate(const vec3& axis, float angle);

		void yaw(float value);
		void yaw_fixed(float value);
		void pitch(float value);
		void roll(float value);

		void next_frame(size_t tick, size_t delta);
		
		Spatial* spatial_root();

		void detach(Spatial& child);

		void hook();
		void unhook();

		template <class Visitor>
		void visit(const Visitor& visitor)
		{
			if(!visitor(*this))
				return;
			for(HSpatial spatial : m_contents)
				spatial->visit(visitor);
		}

		void debug_contents(size_t depth = 0);
	};

	void detach_to(HSpatial spatial, HSpatial target);
	void set_parent(HSpatial spatial, HSpatial target);
}
