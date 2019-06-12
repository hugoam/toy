//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/Reactive/Reactive.h>

#include <core/Entity/Entity.h>
#include <core/World/World.h>
#include <core/World/Section.h>

using namespace two; namespace toy
{
	Behavior::Behavior(Type& type, Reactive& reactive)
		: m_type(type)
		, m_reactive(reactive)
		, m_control(false)
		, m_asleep(false)
		, m_priority(BP_LOW)
		, m_priorityValue(0)
	{}

	Behavior::~Behavior()
	{}

	void Behavior::sleep()
	{
		m_asleep = true;
		m_reactive.sleep(this);
	}

	void Behavior::wake()
	{
		m_asleep = false;
		m_reactive.wake(this);
	}

	Reactive::Reactive(Entity& entity)
		: m_entity(entity)
		, m_controller(nullptr)
	{
		entity.m_world.add_task(this, short(Task::State));
	}

	Reactive::~Reactive()
	{
		m_entity.m_world.remove_task(this, short(Task::State));
	}

	void Reactive::add(object_ptr<Behavior> behavior)
	{
		if(m_controller)
			this->overtake(behavior.get());
		else
			this->take(behavior.get());

		m_actives.push_back(behavior.get());
		m_behaviors.push_back(std::move(behavior));
	}

	void Reactive::next_frame(size_t tick, size_t delta)
	{
		//printf("Reactive::next_frame" << std::endl;
		for(Behavior* behavior : m_actives)
		{
			this->overtake(behavior);
			behavior->next_frame(tick, delta);
		}
	}

	void Reactive::needControl()
	{
		for(Behavior* behavior : m_actives)
			this->overtake(behavior);
	}
		
	void Reactive::overtake(Behavior* behavior)
	{
		if(!behavior->bypasses(m_controller))
			return;

		m_controller->yield();
		this->take(behavior);
	}

	void Reactive::take(Behavior* behavior)
	{
		printf("Behavior activated : %s\n", behavior->name());
		behavior->take();
		m_controller = behavior;
	}

	void Reactive::wake(Behavior* behavior)
	{
		m_actives.push_back(behavior);
	}

	void Reactive::sleep(Behavior* behavior)
	{
		if(behavior->m_control)
			needControl();

		vector_remove(m_actives, behavior);
	}
}
