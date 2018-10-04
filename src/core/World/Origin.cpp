//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/World/Origin.h>


using namespace mud; namespace toy
{
	uint32_t Origin::create(World& world)
	{
		uint32_t entity = s_registry.CreateEntity<Spatial, Origin>();
		s_registry.SetComponent(entity, Spatial(world, HSpatial(), Zero3, ZeroQuat));
		s_registry.SetComponent(entity, Origin(HSpatial(entity)));
		return entity;
	}

	Origin::Origin(HSpatial spatial)
		: m_spatial(spatial)
	{}
}
