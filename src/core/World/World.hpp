//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <ecs/ECS.hpp>
#include <ecs/Loop.hpp>
#include <core/Forward.h>
#include <core/World/World.h>

using namespace two; namespace toy
{
	template <class T_Component, class... Args>
	void World::add_loop(Task task)
	{
		auto loop = [&](size_t tick, size_t delta)
		{
			m_ecs.loop<T_Component, Args...>([tick, delta](T_Component& component, Args&... args)
			{
				component.next_frame(args..., tick, delta);
			});
		};

		m_pump.add_step({ task, loop });
	}

	template <class T_Component, class... Args>
	void World::add_parallel_loop(Task task)
	{
		auto loop = [&](size_t tick, size_t delta)
		{
			auto process = [tick, delta](T_Component& component, Args&... args)
			{
				component.next_frame(args..., tick, delta);
			};

			Job* job = for_components<T_Component, Args...>(m_job_system, nullptr, m_ecs, process);
			m_job_system.complete(job);
		};

		m_pump.add_step({ task, loop });
	}

	template <class T>
	inline SparsePool<T>& World::pool()
	{
		if(!m_pools[type<T>().m_id])
			m_pools[type<T>().m_id] = make_unique<SparsePool<T>>();
		return as<SparsePool<T>>(*m_pools[type<T>().m_id].get());
	}

	template <class T, class... Types>
	inline ComponentHandle<T> construct(HSpatial parent, Types&&... args)
	{
		ECS& ecs = parent->m_world->m_ecs;
		ComponentHandle<T> object = T::create(ecs, parent, static_cast<Types&&>(args)...);
		parent->m_contents.push_back(HSpatial(object));
		return object;
	}

	template <class T, class... Types>
	inline EntityHandle<T> construct_owned(HSpatial parent, Types&&... args)
	{
		ECS& ecs = parent->m_world->m_ecs;
		ComponentHandle<T> object = T::create(ecs, parent, static_cast<Types&&>(args)...);
		parent->m_contents.push_back(object->m_spatial);
		return object;
	}
}
