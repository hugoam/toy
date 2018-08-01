//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <proto/Complex.h>
#include <core/Forward.h>
#include <core/World/Origin.h>

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
		attr_ graph_ Entity& origin() { return m_origin->m_entity; }
		attr_ graph_ Entity& unworld() { return m_unworld->m_entity; }

		void destroy();

		WorldClock& clock() { return *m_clock; }

		TaskSection* section(short int section);

    public:
		void next_frame();

		void add_task(Updatable* task, short int section);
		void remove_task(Updatable* task, short int section);
		void updateTasks(short int section);

	public:
		template <class T>
		inline bool isa() { return m_complex.isa<T>(); }

		template <class T>
		inline T& as() { return m_complex.as<T>(); }

    private:
		std::vector<object_ptr<TaskSection>> m_sections;
		object_ptr<WorldClock> m_clock;
		object_ptr<Origin> m_origin;
		object_ptr<Origin> m_unworld;
    };
}
