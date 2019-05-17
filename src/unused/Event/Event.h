//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <obj/Var.h>
#include <obj/Unique.h>
#include <core/Forward.h>
#include <core/Event/EventHandler.h>

#ifndef MUD_CPP_20
#include <stl/map>
#endif

using namespace two; namespace toy
{
	using string = string;
	using VarDict = map<string, Var>;

	class TOY_CORE_EXPORT Event
	{
	public:
		Event(Type& eventType, EventRelay& source);

	public:
		const Type& m_eventType;
		const EventRelay& m_source;

		typedef map<Medium*, float> IntensityMap;
		IntensityMap m_intensity;

		VarDict m_attributes;

		// @ todo : to allow for more than just discrete instance mask checking (area, space, receptor, etc...), use an EventMask interface subclassed with type map dispatching based on subclass
		// map<string, EventMask*>
	};

	class TOY_CORE_EXPORT EventSubscriber
	{
	public:
		EventSubscriber(Type& eventType, object_ptr<EventHandler> handler);

		void call(Event& event);

	public:
		Type& m_eventType;
		object_ptr<EventHandler> m_handler;

		VarDict m_filters;
	};
}
