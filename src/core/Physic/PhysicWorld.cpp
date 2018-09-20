//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/Physic/PhysicWorld.h>

#include <core/World/Section.h>
#include <core/World/World.h>

using namespace mud; namespace toy
{
	PhysicMedium::PhysicMedium(World& world, Medium& medium)
		: m_world(world)
		, m_medium(medium)
	{}

    PhysicWorld::PhysicWorld(World& world)
		: m_world(world)
	{}

    PhysicWorld::~PhysicWorld()
	{}

	void PhysicWorld::next_frame(size_t tick, size_t delta)
	{
		for(auto& kv : m_subworlds)
			kv.second->next_frame(tick, delta);
	}

	PhysicMedium& PhysicWorld::sub_world(Medium& medium)
	{
		if(m_subworlds.find(&medium) == m_subworlds.end())
			m_subworlds[&medium] = this->create_sub_world(medium);
		return *m_subworlds[&medium].get();
	}
}
