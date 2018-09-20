//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/Event/EventFilter.h>

#include <obj/Var.h>

#include <core/Event/Event.h>

using namespace mud; namespace toy
{
	EventFilter::EventFilter(Type& type, const string& filterName)
		: m_type(type)
		, m_filterName(filterName)
		, m_filteredNone()
		, m_filtered()
	{}

	void EventFilter::subscribe(EventSubscriber& subscriber)
	{
		UNUSED(subscriber);
		//void* mask = &val<void*>(subscriber.m_filters[m_filterName]);
		//printf("Subscribing to filter type = " << m_type << " and name = " << m_filterName << std::endl;
		//printf("Mask of address %p\n", mask);
		//subscribe(mask, subscriber);
	}

	void EventFilter::subscribe(void* mask, EventSubscriber& subscriber)
	{
		if(mask)
		{
			m_filteredNone.insert(&subscriber);
			m_filtered[mask].insert(&subscriber);
		}
	}

	void EventFilter::unsubscribe(EventSubscriber& subscriber)
	{
		UNUSED(subscriber);
		//void* mask = &val<void*>(subscriber.m_filters[m_filterName]);
		//unsubscribe(mask, subscriber);
	}

	void EventFilter::unsubscribe(void* mask, EventSubscriber& subscriber)
	{
		if(mask)
		{
			m_filteredNone.erase(&subscriber);
			m_filtered[mask].erase(&subscriber);
		}
	}

	void EventFilter::filterGroup(const MaskList& masks, SubscriberSet& subscribers)
	{
		UNUSED(masks); UNUSED(subscribers);
		//SubscriberSet out(m_filteredNone.begin(), m_filteredNone.end());

		//for(auto mask : masks)
		//	inplace_set_difference(out, m_filtered[mask]);

		//inplace_set_difference(subscribers, out);
	}

	void EventFilter::filter(Event& event, SubscriberSet& subscribers)
	{
		UNUSED(event); UNUSED(subscribers);
		//printf("Filtering type = " << m_type << " and name = " << m_filterName << std::endl);
		//filter(&val<void*>(event.m_attributes[m_filterName]), subscribers);
	}

	void EventFilter::filter(void* mask, SubscriberSet& subscribers)
	{
		UNUSED(mask); UNUSED(subscribers);
		//printf("Object of address " << mask << std::endl;
		//SubscriberSet out(m_filteredNone.begin(), m_filteredNone.end());
		//inplace_set_difference(out, m_filtered[mask]);
		//inplace_set_difference(subscribers, out);
	}

	/*void EventFilter::fill(Event& event, SubscriberSet& subscribers)
	{
		filter(event->m_attributes.get(m_type, m_filterName), subscribers);
	}

	void EventFilter::fill(void* mask, SubscriberSet& subscribers)
	{
		printf("Object of address " << mask << std::endl;
		
		subscribers.insert(m_filteredNone.begin(), m_filteredNone.end());
		subscribers.insert(m_filtered[mask].begin(), m_filtered[mask].end());
	}*/
}
