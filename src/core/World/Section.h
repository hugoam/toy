//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <core/Forward.h>
#include <math/Timer.h>

#ifndef MUD_CPP_20
#include <vector>
#include <functional>
#endif

using namespace mud; namespace toy
{
	enum class Task : unsigned int
	{
		World = 0,
		Spatial = 1,
		State = 2,
		Physics = 3,
		PhysicsWorld = 4,
		GameObject = 5,
		Ui = 6,
		Graphics = 7,
		Core = 8,
		Cleanup = 9,
		Loader = 10,
		Count = 11,
		Background = 12,
	};

	class TOY_CORE_EXPORT JobPump
	{
	public:
		JobPump();

		void pump();
		
		struct Entry
		{
			Task m_task;
			std::function<void(size_t tick, size_t delta)> m_handler;
		};

		void add_step(Entry entry);

		std::vector<Entry> m_steps;
		Clock m_clock;
	};
}
