//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <math/Math.h>
#include <math/Vec.h>
#include <proto/Complex.h>
#include <core/Forward.h>
#include <core/Disq/Disq.h>
#include <infra/Updatable.h>

#ifndef MUD_CPP_20
#include <stl/vector>
#include <memory>
#endif

using namespace two; namespace toy
{
	class TOY_CORE_EXPORT MotionStrategy
	{
	public:
		virtual ~MotionStrategy() {}

		virtual void activate(vec3& position) = 0;
		virtual void adjustHeight(vec3& position) = 0;
		virtual void update(const vec3& oldPos, const vec3& pos, vec3& adjustedPos) = 0;
		virtual bool validity(const vec3& pos) = 0;
		virtual void nearestValid(vec3& destination, float margin) = 0;
	};
	typedef vector<Movable*> MovableVector;

	class refl_ TOY_CORE_EXPORT Agent : public NonCopy
	{
	public:
		constr_ Agent(Entity& entity, float radius /*= 0.3f*/, float height /*= 2.f*/);
		~Agent();

	public:
		attr_ Entity& m_entity;
		//Movable& m_movable;

		unique_ptr<Pathfinder> m_pathfinder;

#ifdef TOY_DISQS
		Disq m_disq;
		Disq m_avoidDisq;
#endif

		attr_ float m_radius;
		attr_ float m_height;

		void setMotionStrategy(object_ptr<MotionStrategy> strategy);

		void next_frame(size_t tick, size_t delta);

		void set_position(const vec3& pos);

		void steer();

	public:
		void destination(vec3& destination);
		void adjustHeight(vec3& position);

		void computePath(const vec3& destination);
		void updatePath();

		vec3 detour(Agent& agent, Atoll* atoll);
		void avoid(const vec3& spot);

		bool forecast(const vec3& spot);
		bool forecastNavmesh(const vec3& spot);

		object_ptr<DetourPath> m_path;
		vec3 m_waypoint;

		bool popWaypoint();

	protected:
		Entity* m_avoiding = nullptr;

		object_ptr<MotionStrategy> m_motionStrategy;
	};
}
