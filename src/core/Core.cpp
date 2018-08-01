//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/Types.h>
#include <core/Core.h>

#include <core/Player/Player.h>
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
		size_t size = size_t(Task::Background) + 1;
		m_sections.resize(size);

		for(Task task = Task(0); task < Task::Count; task = Task(uint(task) + 1))
			m_sections[size_t(task)] = make_object<MonoSection>(short(task));

		//m_sections[size_t(Task::Background)] = make_object<MonoSection>(short(Task::Background), true);
	}

	Core::~Core()
	{}

	void Core::next_frame()
	{
		Animator::me.next_frame(0, 0);

		for(Task task = Task(0); task < Task::Count; task = Task(uint(task) + 1))
			m_sections[size_t(task)]->update();

		Indexer& scripts = indexer(type<EntityScript>());
		for(Ref object : scripts.m_objects)
			if(object)
				val<EntityScript>(object).run_logic();
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
