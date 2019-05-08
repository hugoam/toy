//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#ifdef TWO_MODULES
module toy.core;
#else
#include <stl/algorithm.h>
#include <type/Proto.h>
#include <type/Indexer.h>
#include <math/Timer.h>
#include <math/Math.h>
#include <refl/Meta.h>
#include <core/Spatial/Spatial.h>
#include <core/World/World.h>
#include <core/World/Section.h>
#endif

#include <cstdio>
#include <cassert>

namespace toy
{
	Spatial::Spatial(World& world, HSpatial parent, const vec3& position, const quat& rotation)
		: Transform{ position, rotation, vec3(1.f) }
		, m_world(&world)
		, m_parent(parent)
		, m_hooked(true)
	{}

	Spatial::Spatial(HSpatial parent, const vec3& position, const quat& rotation)
		: Spatial(*parent->m_world, parent, position, rotation)
	{}

    Spatial::~Spatial()
    {}

	Spatial& Spatial::origin()
	{
		return m_world->origin();
	}

	void Spatial::debug_contents(size_t depth)
	{
		if(m_contents.size() > 1)
		{
			for(size_t o = 0; o < depth; ++o)
				printf("    ");

			printf("Spatial %u : %zu leafs\n", 0U, m_contents.size());
		}

		for(HSpatial child : m_contents)
			child->debug_contents(depth + 1);
	}

	vec3 Spatial::absolute_position() const
	{
		if(m_parent)
			return m_position + m_parent->absolute_position();
		else
			return m_position;
	}

	quat Spatial::absolute_rotation() const
	{
		if(m_parent)
			assert(&(*m_parent) != this);
		if(m_parent)
			return m_rotation * m_parent->absolute_rotation();
		else
			return m_rotation;
	}

	void Spatial::translate(const vec3& vec)
	{
		set_position(two::rotate(m_rotation, vec) + m_position);
	}

	void Spatial::rotate(const vec3& axis, float angle)
	{
		quat rot = angle_axis(angle, two::rotate(m_rotation, axis));
		set_rotation(rot * m_rotation);
		normalize(m_rotation);
	}

	void Spatial::yaw(float value)
	{
		vec3 axis(two::rotate(m_rotation, y3));			
		rotate(axis, value);
	}

	void Spatial::yaw_fixed(float value)
	{			
		rotate(y3, value);
	}

	void Spatial::pitch(float value)
	{
		vec3 axis(two::rotate(m_rotation, x3));
		rotate(axis, value);
	}

	void Spatial::roll(float value)
	{
		vec3 axis(two::rotate(m_rotation, z3));
		rotate(axis, value);
	}

    void Spatial::next_frame(size_t tick, size_t delta)
    {
		UNUSED(delta);

		m_moved = false;
		m_last_tick = tick;
	}

	void Spatial::hook()
	{
		m_hooked = true;
	}

	void Spatial::unhook()
	{
		m_hooked = false;
	}

	bool Spatial::is_child_of(HSpatial spatial)
	{
		if(m_parent == spatial)
			return true;
		else if(m_parent)
			return m_parent->is_child_of(spatial);
		else
			return false;
	}

	Spatial* Spatial::spatial_root()
	{
		if(m_parent)
			return m_parent->spatial_root();
		else
			return this;
	}

	void Spatial::detach(Spatial& child)
	{
		child.m_parent = {};
		//remove(m_contents, child);
	}

	void detach_to(HSpatial self, HSpatial target)
	{
		Spatial& spatial = self;
		Spatial& movefrom = spatial.m_parent;
		spatial.m_parent = target;
		remove(movefrom.m_contents, self);
		target->m_contents.push_back(self);
		spatial.set_dirty(false);
	}

	void set_parent(HSpatial self, HSpatial target)
	{
		detach_to(self, target);
	}
}
