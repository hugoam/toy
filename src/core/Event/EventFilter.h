//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <core/Forward.h>

#ifndef MUD_CPP_20
#include <list>
#include <set>
#include <map>
#include <string>
#endif

using namespace mud; namespace toy
{
	using string = std::string;

	// The default EventFilter filters a value stored in the event against the value of the mask specified by the subscriber
	// the value must be equal in order for the event to reach the subscriber

	// ThresholdEventFilter filters a value stored in the event against the value of the mask specified by the subscriber
	// the value must be superior in order for the event to reach the subscriber

	class refl_ EventFilter
	{
	public:
		typedef std::set<EventSubscriber*> SubscriberSet;
		typedef std::map<void*, SubscriberSet> SubscriberMap;
		typedef std::list<void*> MaskList;

	public:
		EventFilter(Type& type, const string& filterName);

		void subscribe(EventSubscriber& subscriber);
		void subscribe(void* mask, EventSubscriber& subscriber);

		void unsubscribe(EventSubscriber& subscriber);
		void unsubscribe(void* mask, EventSubscriber& subscriber);

		void filter(Event& event, SubscriberSet& subscribers);
		void filter(void* mask, SubscriberSet& subscribers);

		void fill(Event& event, SubscriberSet& subscribers);
		void fill(void* mask, SubscriberSet& subscribers);

		void filterGroup(const MaskList& masks, SubscriberSet& subscribers);

		Type& m_type;
		string m_filterName;

		SubscriberSet m_filteredNone;
		SubscriberMap m_filtered;
	};

	/*class EventFiller : public EventFilter
	{
	public:
		EventFiller(Type* type, const string& filterName);

		void subscribe(Object* mask, EventSubscriber* subscriber);
		void unsubscribe(Object* mask, EventSubscriber* subscriber);
		void filter(Object* mask, SubscriberSet& subscribers);
		void filterGroup(const MaskList& masks, SubscriberSet& subscribers);

	protected:
		SubscriberSet m_unfiltered;
	};*/
}
