//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/Agent/GroundMotion.h>

#include <core/World/World.h>
#include <core/Entity/Entity.h>
#include <core/WorldPage/WorldPage.h>
#include <core/Physic/PhysicWorld.h>

#include <core/Path/Pathfinder.h>
#include <core/Navmesh/Navmesh.h>

using namespace mud; namespace toy
{
	GroundMotion::GroundMotion(Entity& entity, Agent& agent)
		: m_entity(entity)
		, m_agent(agent)
	{
		entity.observe_hook(*this);
	}

	void GroundMotion::hooked()
	{
		//m_pathfinder = &m_entity.m_parent->plug<Pathfinder>();
		m_world_page = &m_entity.m_parent->as<WorldPage>();

		m_active = true;
	}

	void GroundMotion::unhooked()
	{
		m_active = false;
	}

	bool GroundMotion::validity(const vec3& pos)
	{
		return m_agent.m_pathfinder->validity(pos);
	}

	void GroundMotion::nearestValid(vec3& destination, float margin)
	{
		return m_agent.m_pathfinder->nearestValid(destination, margin);
	}

	void GroundMotion::adjustHeight(vec3& position)
	{
		m_world_page->ground_point(position, true, position);
		if(any(isnan(position)) || any(isinf(position)))
			printf("CORRUPTING POSITION\n");
	}

	void GroundMotion::activate(vec3& position)
	{
		if(!m_active)
			return;

		m_world_page->ground_point(position, true, position);

		if(any(isnan(position)) || any(isinf(position)))
			printf("CORRUPTING POSITION\n");
	}

	void GroundMotion::update(const vec3& oldPos, const vec3& novPos, vec3& adjustedPos)
	{
		UNUSED(oldPos);

		// If in terrestrial moving strategy, we move ourselves sliding on ground surfaces
		// When the strategy is activated, we get the nearest navpoly and bind ourselves to it
		// On update, we query the navmesh about a move to determine when changing polys, and get the correct height each frame

		// Move along navmesh and update position.

		if(m_last_updated >= m_entity.m_last_updated)
			return;

		if(!m_active)
			return;

		m_world_page->ground_point(novPos, true, adjustedPos);
		m_last_updated = m_entity.m_last_updated;

		if(any(isnan(adjustedPos)) || any(isinf(adjustedPos)))
			printf("CORRUPTING POSITION\n");
	}
}
