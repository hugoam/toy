//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.


#include <core/Types.h>
#include <core/Agent/Agent.h>

#include <geom/Intersect.h>

#include <core/World/World.h>
#include <core/Entity/Entity.h>
#include <core/Entity/Entity.h>
#include <core/Movable/Movable.h>
#include <core/Physic/Collider.h>
#include <core/Physic/CollisionShape.h>
#include <core/Physic/Solid.h>
#include <core/WorldPage/WorldPage.h>

#include <core/Agent/GroundMotion.h>
#include <core/Path/DetourPath.h>
#include <core/Path/Pathfinder.h>

#include <core/World/Section.h>

#include <algorithm>

#define CONTACT_THRESHOLD 0.1f

using namespace two; namespace toy
{
	Agent::Agent(Entity& entity, float radius, float height)
		: m_entity(entity)
		//, m_movable(entity.as<Movable>())
#ifdef TOY_DISQS
		, m_disq(entity, radius, height, SolidMedium::me, CM_SOLID)
		, m_avoidDisq(entity, radius * 3.f, height, SolidMedium::me, CM_SOLID)
#endif
		, m_radius(radius)
		, m_height(height)
		, m_motionStrategy(make_object<GroundMotion>(m_entity, *this))
	{
		//m_motionStrategy->activate(m_entity.m_position);

#ifdef TOY_DISQS
		m_disq.imbed();
#endif
	}

	Agent::~Agent()
	{
#ifdef TOY_DISQS
		m_disq.unhooked();
#endif
	}

	void Agent::destination(vec3& destination)
	{
		m_motionStrategy->nearestValid(destination, 2.f);
	}

	void Agent::set_position(const vec3& position)
	{
		m_entity.set_position(position);
		this->adjustHeight(m_entity.m_position);
	}

	void Agent::adjustHeight(vec3& position)
	{
		m_motionStrategy->adjustHeight(position);
	}

	void Agent::computePath(const vec3& destination)
	{
		Navmesh& navmesh = m_entity.m_world.as<Navmesh>();
		if(!m_pathfinder)
			m_pathfinder = make_unique<Pathfinder>(navmesh);

		m_path = make_object<DetourPath>(m_entity, *m_pathfinder, m_entity.absolute_position(), destination);
		m_path->compute();
	}

	void Agent::updatePath()
	{
		m_path->compute();
	}

	bool Agent::popWaypoint()
	{
		if(m_path->m_waypoints.empty())
		{
			m_path = nullptr;
			return false;
		}

		m_waypoint = vector_pop(m_path->m_waypoints);
		//this->adjustHeight(m_waypoint);

		return true;
	}

	bool Agent::forecast(const vec3& spot)
	{
		if(!forecastNavmesh(spot))
			return false;
#ifdef TOY_DISQS
		if(m_disq.collisions(spot))
			return false;
#endif

		return true;
	}
	
	bool Agent::forecastNavmesh(const vec3& pos)
	{
		return m_motionStrategy->validity(pos);
	}

	vec3 Agent::detour(Agent& target, Atoll* island)
	{
		vec3 invdirection = m_entity.m_position - island->m_center;
		vec3 direction = island->m_center - m_entity.m_position;
		
		
		// We take three points, two tangents and one straight from the island radius
		float tangent = sqrt(length2(direction) - (island->totalRadius() * island->totalRadius()));
		vec3 p1;
		vec3 p2 = island->m_center + (normalize(invdirection) * (island->m_farthestDist + island->m_highRadius));
		vec3 p3;
		circle_circle_intersection(m_entity.m_position, tangent, island->m_center, island->totalRadius(), p1, p3);

		float d1 = distance2(p1, target.m_entity.m_position);
		float d2 = distance2(p2, target.m_entity.m_position);
		float d3 = distance2(p3, target.m_entity.m_position);

		if(d1 < d2 && d1 < d3)
			return p1;
		else if(d2 < d3)
			return p2;
		else
			return p3;
	}

	/*void Agent::stick(Agent* sticker)
	{
		sticker->m_entity.set_position(this->spot(sticker));
	}*/

	void Agent::setMotionStrategy(object_ptr<MotionStrategy> strategy)
	{
		m_motionStrategy = std::move(strategy);
	}

	void Agent::next_frame(size_t tick, size_t delta)
	{
		UNUSED(tick); UNUSED(delta);
#ifdef TOY_DISQS
		m_disq.next_frame(tick, delta);
#endif

		this->steer();

		//if(m_motionStrategy)
		//	m_motionStrategy->update(m_movable.m_oldPosition, m_entity.m_position, m_entity.m_position);
	}

	void Agent::steer()
	{
		/*for(Contact& contact : m_avoidDisq.contacts())
		{
			if(!m_avoiding)
			{
			}

			if(&contact.disq->m_entity != m_avoiding)
			{ }
			// If the contact is
		}*/
	}

	/*void Agent::addedToWorld(World* world)
	{
		m_motionStrategy.resetGroundMotion(m_entity);
		m_motionStrategy->activate(*m_entity.m_position);
		
		m_entity.set_position(this->closestFreeSpot(m_entity.m_position));
	}

	void Agent::removedFromWorld(World* world)
	{
		m_motionStrategy.reset();
	}*/
}
