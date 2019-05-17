//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <stl/function.h>
#include <util/Forward.h>
#include <type/Util/LocklessQueue.h>

namespace toy
{
	class TOY_UTIL_EXPORT Scheduler
	{
	public:
		typedef function<void()> ProcedureType;

	public:
		Scheduler(size_t queueSize);
		~Scheduler();

		bool scheduleAction(const ProcedureType& action);
		void processActions();

	private:
		LocklessQueue<ProcedureType> m_actions;
	};
}
