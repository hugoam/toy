//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/Event/EventRelay.h>

#include <core/World/World.h>
#include <core/Entity/Entity.h>
#include <core/Event/Event.h>
#include <core/Event/EventTube.h>

using namespace mud; namespace toy
{
	EventRelay::EventRelay(Entity& entity)
		: m_entity(entity)
		, m_abstractEventTube()
		, m_eventTubes()
	{}

	void EventRelay::subscribeEvent(EventSubscriber& subscriber)
	{
		for(EventTube* tube : m_eventTubes)
			tube->subscribe(subscriber);
	}

	void EventRelay::subscribeReceived(EventSubscriber& subscriber)
	{
		m_receivedSubscribers.insert(&subscriber);

		for(EventTubeEnd* tubeEnd : m_eventTubeEnds)
			tubeEnd->subscribe(subscriber);
	}

	void EventRelay::sendEvent(Event& event)
	{
		//mEventWorld->dispatch(event);
		m_abstractEventTube.dispatch(event);

		for(EventTube* tube : m_eventTubes)
			tube->dispatch(event);


		// @todo : collapse all same events that arrived through different tubes into one ?
	}

	void EventRelay::appendEventTube(EventTube& tube)
	{
		m_eventTubes.insert(&tube);
	}

	void EventRelay::removeEventTube(EventTube& tube)
	{
		m_eventTubes.erase(&tube);
	}

	void EventRelay::appendEventTubeEnd(EventTubeEnd& tube)
	{
		m_eventTubeEnds.insert(&tube);

		for(EventSubscriber* sub : m_receivedSubscribers)
			tube.subscribe(*sub);
	}

	void EventRelay::removeEventTubeEnd(EventTubeEnd& tube)
	{
		m_eventTubeEnds.erase(&tube);
	}
}
