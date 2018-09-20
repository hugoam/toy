//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/Area/Area.h>

#include <core/Entity/Entity.h>
#include <core/Physic/Collider.h>
#include <core/Physic/CollisionShape.h>
#include <core/Physic/Physic.h>

using namespace mud; namespace toy
{
	Area::Area(Entity& entity, const CollisionShape& shape)
		: m_collider(entity, shape, AreaMedium::me, CM_AREA)
	{
		m_collider.m_object = this;
	}

	Area::~Area()
	{}

	bool Area::checkInside(const vec3& position)
	{
		return m_collider.m_collision_shape.checkInside(position);
	}
}
