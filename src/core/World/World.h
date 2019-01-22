//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <stl/vector.h>
#include <stl/string.h>
#include <ecs/ECS.h>
#include <ecs/Loop.h>
#include <core/Forward.h>
#include <core/World/Origin.h>
#include <core/World/Section.h>

using namespace mud; namespace toy
{
	class refl_ TOY_CORE_EXPORT World
    {
    public:
		constr_ World(Id id, Complex& complex, const string& name, JobSystem& job_system);
        ~World();

		attr_ Id m_id;
		attr_ Complex& m_complex;
		attr_ string m_name;
		attr_ graph_ HSpatial origin() { return m_origin->m_spatial; }
		attr_ graph_ HSpatial unworld() { return m_unworld->m_spatial; }

		WorldClock& clock() { return *m_clock; }

		void next_frame();

		template <class T_Component, class... T_Args>
		void add_loop(Task task)
		{
			auto loop = [&](size_t tick, size_t delta)
			{
				m_ecs.Loop<T_Component, T_Args...>([tick, delta](T_Component& component, T_Args&... args)
				{
					component.next_frame(args..., tick, delta);
				});
			};

			m_pump.add_step({ task, loop });
		}

		template <class T_Component, class... T_Args>
		void add_parallel_loop(Task task)
		{
			auto loop = [&](size_t tick, size_t delta)
			{
				auto process = [tick, delta](T_Component& component, T_Args&... args)
				{
					component.next_frame(args..., tick, delta);
				};

				Job* job = for_components<T_Component, T_Args...>(m_job_system, nullptr, m_ecs, process);
				m_job_system.complete(job);
			};

			m_pump.add_step({ task, loop });
		}

	public:
		vector<unique<HandlePool>> m_pools;

		template <class T>
		inline SparsePool<T>& pool()
		{
			if(!m_pools[type<T>().m_id])
				m_pools[type<T>().m_id] = make_unique<SparsePool<T>>();
			return as<SparsePool<T>>(*m_pools[type<T>().m_id].get());
		}

    private:
		object<WorldClock> m_clock;
		EntityHandle<Origin> m_origin;
		EntityHandle<Origin> m_unworld;

	public:
		JobSystem& m_job_system;
		ECS m_ecs;
		JobPump m_pump;
    };

	template <class T, class... Types>
	inline ComponentHandle<T> construct(HSpatial parent, Types&&... args)
	{
		ECS& ecs = parent->m_world->m_ecs;
		ComponentHandle<T> object = T::create(ecs, parent, static_cast<Types&&>(args)...);
		parent->m_contents.push_back(object->m_spatial);
		return object;
	}

	template <class T, class... Types>
	inline EntityHandle<T> construct_owned(HSpatial parent, Types&&... args)
	{
		ECS& ecs = parent->m_world->m_ecs;
		ComponentHandle<T> object = T::create(ecs, parent, static_cast<Types&&>(args)...);
		parent->m_contents.push_back(object->m_spatial);
		return { object.m_handle, object.m_ecs };
	}
}
