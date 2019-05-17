//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.
//  Copyright (c) 2015 Hugo Amiard hugo.amiard@laposte.net
//  This software is provided 'as-is' under the zlib License, see the LICENSE.txt file.
//  This notice and the license may not be removed or altered from any source distribution.


#include <util/Threading/Scheduler.h>

namespace toy
{
	Scheduler::Scheduler(size_t queueSize)
		: m_actions(queueSize)
	{}

	Scheduler::~Scheduler() 
	{}

	bool Scheduler::scheduleAction(const ProcedureType& action)
	{
		return m_actions.push(action);
	}

	void Scheduler::processActions()
	{
		int i = 0;
		ProcedureType action;

		if(!m_actions.empty())
		{
			while(((++i) < 5) && m_actions.pop(action))
			{
				action();
			}
		}
	}
}
