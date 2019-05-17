//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <infra/NonCopy.h>
#include <obj/Unique.h>
#include <core/Forward.h>

#ifndef MUD_CPP_20
#include <set>
#include <stl/map>
#include <stl/string>
#endif

using namespace two; namespace toy
{		
	using string = string;

	// @ add a Filler discriminating between event types
	class TOY_CORE_EXPORT EventTube : public NonCopy
	{
	public:
		EventTube();
		~EventTube();

		void subscribe(EventSubscriber& subscriber);
		void unsubscribe(EventSubscriber& subscriber);
		void dispatch(Event& event);

	protected:
		std::set<EventSubscriber*> m_subscribers;
		map<string, object_ptr<EventFilter>> m_filters;
	};

	class TOY_CORE_EXPORT EventTubeEnd
	{
	public:
		EventTubeEnd();

		void subscribe(EventSubscriber& subscriber);
		void unsubscribe(EventSubscriber& subscriber);
		void bind(EventTube& eventTube);
		void unbind(EventTube& eventTube);

	protected:
		std::set<EventSubscriber*> m_subscribers;
	};

}
