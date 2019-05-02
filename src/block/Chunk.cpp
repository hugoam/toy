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
#include <block/Chunk.h>
#include <block/Block.h>
#include <block/Sector.h>
#endif

namespace toy
{
	Entity Chunk::create(ECS& ecs, HSpatial parent, Block& block, const vec3& position, size_t index, Element& element, float size)
	{
		Entity entity = ecs.create<Spatial, Chunk>();
		ecs.set(entity, Spatial(parent, position, ZeroQuat));
		ecs.set(entity, Chunk(block, index, element, size));
		return entity;
	}

	Chunk::Chunk(Block& block, size_t index, Element& element, float size)
		: m_index(index)
		, m_block(&block)
		, m_element(&element)
		, m_size(size)
	{}

	Chunk* Chunk::neighbour(Side side)
	{
		UNUSED(side);
		return nullptr;
		//return m_block.neighbour(m_index, side);
	}

	bool Chunk::boundary(Side side)
	{
		Chunk* neighbour = this->neighbour(side);
		return (!neighbour || neighbour->m_element->m_state != this->m_element->m_state);
	}
}
