//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/Types.h>
#include <core/World/World.h>

#include <core/World/Origin.h>
#include <core/Physic/Collider.h>

#include <obj/Indexer.h>
#include <math/Timer.h>
#include <proto/Proto.h>
#include <math/Vec.h>
#include <core/Entity/Entity.h>
#include <core/World/WorldClock.h>
#include <core/World/Section.h>

using namespace mud; namespace toy
{
	World::World(Id id, Complex& complex, const string& name)
        : m_id(complex.m_id)
		, m_complex(complex)
		, m_name(name)
		, m_clock(make_object<WorldClock>(*this))
		, m_pools(c_max_types)
    {
		m_origin = make_object<Origin>(*this);
		m_unworld = make_object<Origin>(*this);

		auto update_colliders = [&](size_t tick, size_t delta)
		{
			for(Collider& collider : this->pool<Collider>().m_objects)
				collider.next_frame(tick, delta);
		};

		m_pump.add_step({ Task::Physics, update_colliders });
	}

    World::~World()
    {
		this->destroy();
	}

	void World::destroy()
	{
		m_origin = nullptr;
		m_unworld = nullptr;
	}

    void World::next_frame()
    {
		m_pump.pump();
    }
}
