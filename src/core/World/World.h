//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <stl/vector.h>
#include <stl/string.h>
#include <ecs/ECS.h>
#include <core/Forward.h>
#include <core/World/Origin.h>
#include <core/World/Section.h>
#include <core/World/WorldClock.h>

namespace toy
{
	class refl_ TOY_CORE_EXPORT World
    {
    public:
		constr_ World(uint32_t id, Complex& complex, const string& name, JobSystem& job_system);
        ~World();

		attr_ uint32_t m_id;
		attr_ Complex& m_complex;
		attr_ string m_name;

		ECS m_ecs;
		JobSystem& m_job_system;
		JobPump m_pump;
		WorldClock m_clock;

		attr_ graph_ HSpatial origin() { return m_origin; }
		attr_ graph_ HSpatial unworld() { return m_unworld; }

		void next_frame();

		template <class T_Component, class... Args>
		void add_loop(Task task);

		template <class T_Component, class... Args>
		void add_parallel_loop(Task task);

	public:
		vector<unique<HandlePool>> m_pools;

		template <class T>
		inline SparsePool<T>& pool();

    private:
		EntityHandle<Origin> m_origin;
		EntityHandle<Origin> m_unworld;
    };

	template <class T, class... Types>
	inline ComponentHandle<T> construct(HSpatial parent, Types&&... args);

	template <class T, class... Types>
	inline EntityHandle<T> construct_owned(HSpatial parent, Types&&... args);
}
