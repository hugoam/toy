//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <core/Forward.h>

#ifndef MUD_CPP_20
#include <functional>
#endif

using namespace two; namespace toy
{
	class EventHandler
	{
	public:
		virtual void handleEvent(Event& event) = 0;
	};

	template <class T_Event>
	class TEventHandler : public EventHandler
	{
	public:
		typedef std::function<void (T_Event&)> Handler;

	public:
		TEventHandler(const Handler& handler) : m_handler(handler) {}

		void handleEvent(Event& event) { m_handler(static_cast<T_Event&>(event)); }

	private:
		Handler m_handler;
	};
}
