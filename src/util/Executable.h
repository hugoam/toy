//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

//#include <atomic>
#include <stl/stddef.h>
#include <util/Forward.h>

namespace two
{
	class TWO_TYPE_EXPORT Executable
	{
	public:
		Executable() : m_done(false), m_done_flag(0) {}
		virtual ~Executable() {}

		virtual void begin() = 0;
		virtual void update(size_t tick, double step) { UNUSED(tick); UNUSED(step); }
		virtual void abort() {}
		
		void execute() { m_done = false; this->begin(); }
		void stop()	{ m_done = true; if(m_done_flag) *m_done_flag = true; this->abort(); }
		bool done() { return m_done; }

		//void flag(std::atomic<bool>* done) { *done = false; m_done_flag = done; }

	protected:
		bool m_done;
		//std::atomic<bool>* m_done_flag;
		bool* m_done_flag;
	};
}
