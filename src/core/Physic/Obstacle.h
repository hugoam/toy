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
	class refl_ TOY_CORE_EXPORT Obstacle : public Collider
	{
	public:
		constr_ Obstacle(HSpatial spatial, HMovable movable, Medium& medium, const CollisionShape& shape, float throughput);

		attr_ CollisionShape m_shape;
		attr_ float m_throughput;
	};
}
