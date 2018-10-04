//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <ecs/Entity.h>
#include <core/Forward.h>
#include <core/World/Origin.h>
#include <core/World/Section.h>

#ifndef MUD_CPP_20
#include <vector>
#include <string>
#endif

using namespace mud; namespace toy
{
	using string = std::string;

	class refl_ TOY_CORE_EXPORT World
    {
    public:
		constr_ World(Id id, Complex& complex, const string& name);
        ~World();

		attr_ Id m_id;
		attr_ Complex& m_complex;
		attr_ string m_name;
		attr_ graph_ HSpatial origin() { return m_origin->m_spatial; }
		attr_ graph_ HSpatial unworld() { return m_unworld->m_spatial; }

		WorldClock& clock() { return *m_clock; }

		void next_frame();

	public:
		std::vector<unique_ptr<HandlePool>> m_pools;

		template <class T>
		inline SparsePool<T>& pool()
		{
			if(!m_pools[type<T>().m_id])
				m_pools[type<T>().m_id] = make_unique<SparsePool<T>>();
			return as<SparsePool<T>>(*m_pools[type<T>().m_id].get());
		}

    private:
		object_ptr<WorldClock> m_clock;
		EntityHandle<Origin> m_origin;
		EntityHandle<Origin> m_unworld;

	public:
		JobPump m_pump;
    };
}
