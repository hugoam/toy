//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/Physic/Obstacle.h>

#include <core/Entity/Entity.h>

#include <core/Physic/CollisionShape.h>
#include <core/Physic/Collider.h>
#include <core/Physic/Medium.h>

using namespace mud; namespace toy
{
	ObstacleBody::ObstacleBody(Entity& entity, Medium& medium, const CollisionShape& shape, float throughput)
		: Collider(entity, *this, shape, medium, CM_OBSTACLE)
		, m_throughput(throughput)
	{}

	Obstacle::Obstacle(Entity& entity, const CollisionShape& shape)
		: m_entity(entity)
		, m_shape(shape)
	{}

	Obstacle::~Obstacle()
	{}

	void Obstacle::addBody(Medium& medium, const CollisionShape& shape, float throughput)
	{
		m_bodies.push_back(make_object<ObstacleBody>(m_entity, medium, shape, throughput));
	}
}
