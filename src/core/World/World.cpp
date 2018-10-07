//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/Types.h>
#include <core/World/World.h>

#include <core/World/Origin.h>
#include <core/Physic/Collider.h>

#include <core/Api.h>

#include <type/Indexer.h>
#include <math/Timer.h>
#include <ecs/Proto.h>
#include <math/Vec.h>
#include <core/Spatial/Spatial.h>
#include <core/World/WorldClock.h>
#include <core/World/Section.h>

using namespace mud; namespace toy
{
	World::World(Id id, Complex& complex, const string& name, JobSystem& job_system)
        : m_id(complex.m_id)
		, m_complex(complex)
		, m_name(name)
		, m_clock(make_object<WorldClock>(*this))
		, m_pools(c_max_types)
		, m_job_system(job_system)
    {
		UNUSED(id);
		s_ecs[0] = &m_ecs;

		//m_ecs.AddBuffers<Spatial>();
		m_ecs.AddBuffers<Spatial, Origin>("Origin");
		m_ecs.AddBuffers<Spatial, Waypoint>("Waypoint");
		m_ecs.AddBuffers<Spatial, Movable, Camera>("Camera");

		m_origin = { Origin::create(m_ecs, *this), 0 };
		m_unworld = { Origin::create(m_ecs, *this), 0 };

		auto update_colliders = [&](size_t tick, size_t delta)
		{
			for(Collider& collider : this->pool<Collider>().m_objects)
				collider.next_frame(tick, delta);
		};

		m_pump.add_step({ Task::Physics, update_colliders });

		add_parallel_loop<Spatial>(Task::Spatial);
		add_parallel_loop<Movable, Spatial>(Task::Spatial);
		add_parallel_loop<Camera, Spatial>(Task::Spatial);
		add_parallel_loop<WorldPage, Spatial>(Task::Spatial);
		add_parallel_loop<Navblock, Spatial, WorldPage>(Task::Spatial);

		// not parallel because we don't know what the script might do
		add_loop<EntityScript>(Task::Spatial);
	}

    World::~World()
    {}

    void World::next_frame()
    {
		m_pump.pump();
    }
}
