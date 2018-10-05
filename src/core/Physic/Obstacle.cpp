//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/Physic/Obstacle.h>

#include <core/Spatial/Spatial.h>

#include <core/Physic/CollisionShape.h>
#include <core/Physic/Collider.h>
#include <core/Physic/Medium.h>

using namespace mud; namespace toy
{
	Obstacle::Obstacle(HSpatial spatial, HMovable movable, Medium& medium, const CollisionShape& shape, float throughput)
		: Collider(spatial, movable, shape, medium, CM_OBSTACLE)
		, m_shape(shape)
		, m_throughput(throughput)
	{}
}
