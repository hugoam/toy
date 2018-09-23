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

#include <obj/Indexer.h>
#include <core/Script/Script.h>

using namespace mud; namespace toy
{
	Core::Core()
	{
		s_registry.AddBuffer<Spatial>();
		s_registry.AddBuffer<Movable>();
		s_registry.AddBuffer<Camera>();
		s_registry.AddBuffer<Emitter>();
		s_registry.AddBuffer<Receptor>();
		s_registry.AddBuffer<EntityScript>();
		s_registry.AddBuffer<WorldPage>();
		s_registry.AddBuffer<Navblock>();

		add_loop<Spatial>(Task::Spatial);
		add_loop<Movable, Spatial>(Task::Spatial);
		add_loop<Camera, Spatial>(Task::Spatial);
		add_loop<EntityScript>(Task::Spatial);
		add_loop<WorldPage, Spatial>(Task::Spatial);
		add_loop<Navblock, Spatial, WorldPage>(Task::Spatial);
	}

	Core::~Core()
	{}

	void Core::next_frame()
	{
		s_registry.SortComponents();

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
	{
		m_world.destroy();
	}
}
