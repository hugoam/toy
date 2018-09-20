//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/World/Section.h>

#include <math/Timer.h>

#include <algorithm>

using namespace mud; namespace toy
{
	JobPump::JobPump()
	{}

	void JobPump::pump()
	{
		size_t tick = m_clock.readTick();
		size_t delta = m_clock.stepTick();

		for(auto& step : m_steps)
			step.m_handler(tick, delta);
	}

	void JobPump::add_step(Entry entry)
	{
		m_steps.push_back(entry);
		std::sort(m_steps.begin(), m_steps.end(), [&](const Entry& a, const Entry& b) { return a.m_task < b.m_task; });
	}
}
