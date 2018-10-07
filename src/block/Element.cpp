//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.


#include <block/Types.h>
#include <block/Element.h>

#include <core/Spatial/Spatial.h>
#include <core/WorldPage/WorldPage.h>

#include <block/Sector.h>
#include <block/Chunk.h>

using namespace mud; namespace toy
{
	bool GroundChunk::filter(Chunk& chunk)
	{
		return (chunk.m_element->m_state == MatterState::Gas
			 && chunk.neighbour(Side::Down)->m_element->m_state == MatterState::Solid);
	}

	Element::Element(cstring name, MatterState state, Colour colour)
		: m_name(name)
		, m_state(state)
		, m_colour(colour)
	{}

	Entity Heap::create(ECS& ecs, HSpatial parent, const vec3& position, Element& element, float radius)
	{
		Entity entity = { ecs.CreateEntity<Spatial, Heap>(), ecs.m_index };
		ecs.SetComponent(entity, Spatial(parent, position, ZeroQuat));
		ecs.SetComponent(entity, Heap(entity, element, radius));
		return entity;
	}

	Heap::Heap(HSpatial spatial, Element& element, float radius)
		: m_spatial(spatial)
		, m_element(&element)
		, m_radius(radius)
	{}
}
