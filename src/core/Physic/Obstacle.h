//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <infra/NonCopy.h>
#include <core/Forward.h>
#include <core/Physic/CollisionGroup.h>
#include <core/Physic/Collider.h>

using namespace mud; namespace toy
{
	class refl_ TOY_CORE_EXPORT ObstacleBody : public Collider, public ColliderObject
	{
	public:
		ObstacleBody(Entity& entity, Medium& medium, const CollisionShape& shape, float throughput);

		attr_ inline CollisionShape& collision_shape() { return m_collision_shape; }
		attr_ float m_throughput;
	};

	class refl_ TOY_CORE_EXPORT Obstacle : public NonCopy
	{
	public:
		constr_ Obstacle(Entity& entity, const CollisionShape& shape);
		~Obstacle();

		attr_ Entity& m_entity;
		attr_ CollisionShape m_shape;

		void addBody(Medium& medium, float throughput);
		void addBody(Medium& medium, const CollisionShape& shape, float throughput);

	protected:
		std::vector<object_ptr<ObstacleBody>> m_bodies;
	};
}
