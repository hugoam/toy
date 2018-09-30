//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <util/Forward.h>

#ifndef MUD_CPP_20
#include <atomic>
#include <cstddef>
#endif

namespace mud
{
	class MUD_TYPE_EXPORT Executable
	{
	public:
		Executable() : m_done(false), m_doneFlag(0) {}
		virtual ~Executable() {}

		virtual void begin() = 0;
		virtual void update(size_t tick, double step) { UNUSED(tick); UNUSED(step); }
		virtual void abort() {}
		
		void execute() { m_done = false; this->begin(); }
		void stop()	{ m_done = true; if(m_doneFlag) *m_doneFlag = true; this->abort(); }
		bool done() { return m_done; }

		void flag(std::atomic<bool>* done) { *done = false; m_doneFlag = done; }

	protected:
		bool m_done;
		std::atomic<bool>* m_doneFlag;
	};
}
