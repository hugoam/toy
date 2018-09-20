//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/Types.h>
#include <core/Event/EventTube.h>

#include <obj/Var.h>
#include <core/Event/Event.h>
#include <core/Event/EventFilter.h>

using namespace mud; namespace toy
{
	EventTube::EventTube()
		: m_subscribers()
		, m_filters()
	{}
	
	EventTube::~EventTube()
	{}

	void EventTube::subscribe(EventSubscriber& subscriber)
	{
		m_subscribers.insert(&subscriber);

		for(auto& kv : subscriber.m_filters)
		{
			EventFilter* filter = 0;

			auto up = m_filters.find(kv.first);

			if(up == m_filters.end())
			{
				//printf("Creating filter for type = " << (*it).second << " and name = " << (*it).first << std::endl;
				m_filters[kv.first] = make_object<EventFilter>(type(kv.second), kv.first);
				filter = m_filters[kv.first].get();
			}
			else
			{
				filter = (*up).second.get();
			}

			filter->subscribe(subscriber);
		}
	}

	void EventTube::unsubscribe(EventSubscriber& subscriber)
	{
		m_subscribers.erase(&subscriber);

		for(auto& kv : m_filters)
			kv.second->unsubscribe(subscriber);
	}

	void EventTube::dispatch(Event& event)
	{
		std::set<EventSubscriber*> subscribers(m_subscribers.begin(), m_subscribers.end());

		for(auto& kv : m_filters)
			kv.second->filter(event, subscribers);

		// Dispatch event
		for(EventSubscriber* sub : subscribers)
			sub->call(event);
	}

	EventTubeEnd::EventTubeEnd()
		: m_subscribers()
	{}

	void EventTubeEnd::subscribe(EventSubscriber& subscriber)
	{
		//printf("Subscribing to EventTubeEnd" << std::endl;
		m_subscribers.insert(&subscriber);
	}

	void EventTubeEnd::unsubscribe(EventSubscriber& subscriber)
	{
		UNUSED(subscriber);
		//mSubscribers.insert(subscriber);
	}

	void EventTubeEnd::bind(EventTube& eventTube)
	{
		for(EventSubscriber* sub : m_subscribers)
			eventTube.subscribe(*sub);
	}

	void EventTubeEnd::unbind(EventTube& eventTube)
	{
		for(EventSubscriber* sub : m_subscribers)
			eventTube.unsubscribe(*sub);
	}
}
