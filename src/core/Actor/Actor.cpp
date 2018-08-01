//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/Actor/Actor.h>

#include <math/Timer.h>
#include <infra/Reverse.h>

#include <core/Action.h>
#include <core/Entity/Entity.h>
#include <core/World/World.h>

#include <core/World/Section.h>

#include <algorithm>

using namespace mud; namespace toy
{
	Actor::Actor(Entity& entity)
		: m_entity(entity)
		, m_actions()
		, m_queued()
		, m_execution()
	{
		entity.m_world.add_task(this, short(Task::State));
	}

	Actor::~Actor()
	{
		m_entity.m_world.remove_task(this, short(Task::State));

		m_execution.clear();
	}

	void Actor::halt()
	{
		for(auto& action : m_execution)
			action->stop();

		m_execution.clear();
	}

	Procedure& Actor::execute(object_ptr<Procedure> action)
	{
		action->execute();
		m_execution.push_back(std::move(action));
		return *m_execution.back();
	}

	Procedure& Actor::queue(object_ptr<Procedure> action)
	{
		m_queued.push_back(std::move(action));
		return *m_queued.back();
	}

	Procedure& Actor::execute(User* user, ProcedureType& type, Entity& target)
	{
		this->halt();
		return execute(type.instance(user, Ref(&m_entity), { Ref(&target) }));
	}

	Procedure& Actor::queue(User* user, ProcedureType& type, Entity& target)
	{
		return queue(type.instance(user, Ref(&m_entity), { Ref(&target) }));
	}

	void Actor::next_frame(size_t tick, size_t delta)
	{
		if(m_execution.empty() && !m_queued.empty())
		{
			this->execute(vector_pop(m_queued));
		}

		for(int i = m_execution.size() - 1; i >= 0; --i)
		{
			m_execution[i]->update(tick, (delta * c_tick_interval));
			if(m_execution[i]->done())
				m_execution.erase(m_execution.begin() + i);
		}
	}
}
