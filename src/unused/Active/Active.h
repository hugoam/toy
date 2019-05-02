//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <infra/NonCopy.h>
#include <infra/Updatable.h>
#include <core/Forward.h>
#include <core/Active/Effect.h>

#include <stl/vector>

using namespace two; namespace toy
{
	class refl_ TOY_CORE_EXPORT State
	{
	public:
		State(Active& active, const string& name, int priority, float weight);

		Active* m_active;
		string m_name;
		int m_priority;
		float m_weight;
	};

	class refl_ TOY_CORE_EXPORT Active : public NonCopy, public Updatable//, public EffectCallback
    {
	public:
		constr_ Active(Entity& entity);
		~Active();

		attr_ Entity& m_entity;

		vector<Effect> m_effects;
		vector<State> m_states;

		void addEffect(const string& name, float duration = 0.f, bool loop = true);
		void removeEffect(const string& name);

		void addState(const string& name, int priority, float weight);
		void removeState(const string& name);

		void next_frame(size_t tick, size_t delta);
    };
}
