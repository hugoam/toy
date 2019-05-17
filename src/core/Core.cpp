//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/Types.h>
#include <core/Core.h>

#include <core/Handles.h>
#include <core/World/Section.h>
#include <core/Anim/Anim.h>

#define TOY_POOL_IMPLEMENTATION
#include <pool/Pool.h>
#include <pool/ObjectPool.h>

#include <refl/Injector.h>
#include <refl/System.h>

#include <type/Indexer.h>
#include <core/Script/Script.h>

namespace toy
{
	Core::Core(JobSystem& job_system)
		: m_job_system(job_system)
	{
		static Prototype default_world = { type<DefaultWorld>(), { &type<World>(), &type<BulletWorld>() } };
	}

	Core::~Core()
	{}

	void Core::next_frame()
	{
		Animator::me.next_frame(0, 0);

		m_pump.pump();
	}

	DefaultWorld::DefaultWorld(const string& name, JobSystem& job_system)
		: Complex(0, type<DefaultWorld>(), m_bullet_world, m_navmesh, *this)
		, m_world(0, *this, name, job_system)
		, m_bullet_world(m_world)
		, m_navmesh(m_world)
	{
		m_world.m_pump.add_step({ Task::PhysicsWorld,
			[&](size_t tick, size_t delta) { m_bullet_world.next_frame(tick, delta); }
		});
	}

	DefaultWorld::~DefaultWorld()
	{}
}
