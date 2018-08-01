//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <math/Math.h>
#include <core/Forward.h>
#include <core/Agent/Agent.h>
#include <core/Entity/EntityObserver.h>

#ifndef MUD_CPP_20
#include <vector>
#endif

using namespace mud; namespace toy
{
	class refl_ TOY_CORE_EXPORT GroundMotion : public MotionStrategy, public HookObserver
	{
	public:
		GroundMotion(Entity& entity, Agent& agent);

		void hooked();
		void unhooked();
		void adjustHeight(vec3& position);
		void activate(vec3& position);
		void update(const vec3& oldPos, const vec3& pos, vec3& adjustedPos);
		bool validity(const vec3& position);
		void nearestValid(vec3& destination, float margin);

	private:
		Entity& m_entity;
		Agent& m_agent;
		WorldPage* m_world_page;
		size_t m_last_updated = 0;
		bool m_active = false;
	};
}
