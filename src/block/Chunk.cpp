//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.


#include <block/Types.h>
#include <block/Chunk.h>

#include <block/Block.h>
#include <block/Sector.h>

#include <core/Entity/Entity.h>
#include <core/WorldPage/WorldPage.h>

using namespace mud; namespace toy
{
	Chunk::Chunk(Id id, Entity& parent, const vec3& position, size_t index, Element& element, float size)
		: Complex(id, type<Chunk>(), *this)
		, m_entity(id, *this, parent, position, ZeroQuat)
		, m_index(index)
		, m_block(*sector().m_block)
		, m_element(element)
		, m_size(size)
	{}

	Sector& Chunk::sector()
	{
		Entity* parent = m_entity.m_parent;
		for(size_t depth = 1; !parent->isa<WorldPage>(); parent = parent->m_parent)
			++depth;

		return parent->as<Sector>();
	}

	Chunk* Chunk::neighbour(Side side)
	{
		UNUSED(side);
		return nullptr;
		//return m_block.neighbour(m_index, side);
	}

	bool Chunk::boundary(Side side)
	{
		Chunk* neighbour = this->neighbour(side);
		return (!neighbour || neighbour->m_element.m_state != this->m_element.m_state);
	}
}
