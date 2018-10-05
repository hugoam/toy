//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/Types.h>
#include <core/Core.h>

#include <core/Api.h>

#include <core/World/Section.h>
#include <math/Anim/Anim.h>

#define TOY_POOL_IMPLEMENTATION
#include <pool/Pool.h>
#include <pool/ObjectPool.h>

#include <refl/Injector.h>
#include <refl/System.h>

#include <type/Indexer.h>
#include <core/Script/Script.h>

using namespace mud; namespace toy
{
	Core::Core(JobSystem& job_system)
		: m_job_system(job_system)
	{
		//s_registry.AddBuffers<Spatial>();
		s_registry.AddBuffers<Spatial, Origin>("Origin");
		s_registry.AddBuffers<Spatial, Waypoint>("Waypoint");
		s_registry.AddBuffers<Spatial, Movable, Camera>("Camera");

		add_parallel_loop<Spatial>(Task::Spatial);
		add_parallel_loop<Movable, Spatial>(Task::Spatial);
		add_parallel_loop<Camera, Spatial>(Task::Spatial);
		add_parallel_loop<WorldPage, Spatial>(Task::Spatial);
		add_parallel_loop<Navblock, Spatial, WorldPage>(Task::Spatial);

		// not parallel because we don't know what the script might do
		add_loop<EntityScript>(Task::Spatial);
	}

	Core::~Core()
	{}

	void Core::next_frame()
	{
		Animator::me.next_frame(0, 0);

		m_pump.pump();
	}

	DefaultWorld::DefaultWorld(const string& name)
		: Complex(0, type<DefaultWorld>(), m_bullet_world, m_navmesh, *this)
		, m_world(0, *this, name)
		, m_bullet_world(m_world)
		, m_navmesh(m_world)
	{}

	DefaultWorld::~DefaultWorld()
	{}
}
