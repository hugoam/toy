//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/Event/Event.h>

#include <core/Entity/Entity.h>
#include <core/Event/EventRelay.h>

using namespace mud; namespace toy
{
	Event::Event(Type& eventType, EventRelay& source)
		: m_eventType(eventType)
		, m_source(source)
		, m_intensity()
		, m_attributes()
	{
		m_attributes["EventType"] = var(eventType);
	}

	EventSubscriber::EventSubscriber(Type& eventType, object_ptr<EventHandler> handler)
		: m_eventType(eventType)
		, m_handler(std::move(handler))
		, m_filters()
	{
		m_filters["EventType"] = var(eventType);
	}

	void EventSubscriber::call(Event& event)
	{
		m_handler->handleEvent(event);
	}
}
