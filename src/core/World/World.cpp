//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/World/World.h>

#include <core/World/Origin.h>

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
		, m_sections(size_t(Task::Background) + 1)
		, m_clock(make_object<WorldClock>(*this))
    {
		for(Task task = Task(0); task < Task::Count; task = Task(uint(task) + 1))
			m_sections[size_t(task)] = make_object<MonoSection>(short(task));

		m_sections[size_t(Task::Background)] = make_object<MonoSection>(short(Task::Background), true);

		//indexer(type<Entity>()).alloc();
		//indexer(type<Entity>()).alloc();
		m_origin = make_object<Origin>(1, *this);
		m_unworld = make_object<Origin>(2, *this);
	}

    World::~World()
    {}

	void World::destroy()
	{
		m_origin = nullptr;
		m_unworld = nullptr;
	}

    void World::next_frame()
    {
#ifndef TOY_THREADED
		m_clock->stepClock();
		for(Task task = Task(0); task < Task::Count; task = Task(uint(task) + 1))
			m_sections[size_t(task)]->update();
#endif

#ifdef MUD_PLATFORM_EMSCRIPTEN
		m_sections[size_t(Task::Background)]->update();
#endif
    }

    void World::add_task(Updatable* task, short int section)
    {
		m_sections[section]->add_task(task);
    }

	void World::remove_task(Updatable* task, short int section)
	{
		m_sections[section]->remove_task(task);
	}

	void World::updateTasks(short int section)
	{
		m_sections[section]->update();
	}

	TaskSection* World::section(short int section)
	{
		return m_sections[section].get();
	}
}
