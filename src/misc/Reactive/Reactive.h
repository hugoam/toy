//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <proto/Complex.h>
#include <infra/NonCopy.h>
#include <core/Store/Array.h>
#include <core/Forward.h>
#include <infra/Updatable.h>

using namespace two; namespace toy
{
	class refl_ TOY_CORE_EXPORT Behavior : public Updatable
	{
	public:
		enum Priority
		{
			BP_NONE,
			BP_LOW,
			BP_MEDIUM,
			BP_HIGH,
			BP_CRITICAL
		};

		Behavior(Type& type, Reactive& reactive);
		virtual ~Behavior();

		attr_ Type& m_type;
		Reactive& m_reactive;
		bool m_control;
		bool m_asleep;
		Priority m_priority;
		int m_priorityValue;

		void take() { m_control = true; }
		void yield() { m_control = false; }
		
		virtual void dotake() {}
		virtual void doyield() {}

		virtual cstring name() { return ""; }

		meth_ void sleep();
		meth_ void wake();

		bool bypasses(Behavior* other) { return m_priority >= other->m_priority && m_priorityValue > other->m_priorityValue; }
	};

	class refl_ TOY_CORE_EXPORT Reactive : public NonCopy, public Updatable
	{
	public:
		constr_ Reactive(Entity& entity);
        ~Reactive();

		attr_ Entity& m_entity;
		attr_ Behavior* m_controller;

		vector<object_ptr<Behavior>> m_behaviors;

		void add(object_ptr<Behavior> behavior);

		void next_frame(size_t tick, size_t delta);

		void needControl();

		void overtake(Behavior* behavior);
		void take(Behavior* behavior);
		void wake(Behavior* behavior);
		void sleep(Behavior* behavior);

	private:
		void check(Behavior* behavior);

	private:
		vector<Behavior*> m_actives;
	};
}
