//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#ifdef TWO_MODULES
module toy.core
#else
#include <ecs/ECS.hpp>
#include <core/Spatial/Spatial.h>
#include <core/WorldPage/WorldPage.h>
#include <block/Types.h>
#include <block/Element.h>
#include <block/Sector.h>
#include <block/Chunk.h>
#endif

namespace toy
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
		Entity entity = ecs.create<Spatial, Heap>();
		ecs.set(entity, Spatial(parent, position, ZeroQuat));
		ecs.set(entity, Heap(element, radius));
		return entity;
	}

	Heap::Heap(Element& element, float radius)
		: m_element(&element)
		, m_radius(radius)
	{}
}
