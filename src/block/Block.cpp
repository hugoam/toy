//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.


#include <block/Types.h>
#include <block/Block.h>

#include <geom/Shapes.h>
#include <math/Image256.h>

#include <core/Entity/Entity.h>

#include <core/Physic/Scope.h>
#include <core/Physic/CollisionShape.h>

#include <core/WorldPage/WorldPage.h>

#include <block/Sector.h>

#define BLOCK_SUBDIV 20U

using namespace mud; namespace toy
{
	void index_blocks(const ivec3& grid_size, Grid<Block*>& grid, const std::vector<Block*>& blocks, const std::vector<Sector*>& sectors)
	{
		grid.reset(grid_size.x, grid_size.y, grid_size.z);

		for(size_t i = 0; i < blocks.size(); ++i)
		{
			ivec3 coord = sectors[i]->m_coordinate;
			grid.at(coord.x, coord.y, coord.z) = blocks[i];
		}

		for(size_t i = 0; i < blocks.size(); ++i)
		{
			ivec3 coord = sectors[i]->m_coordinate;
			size_t index = grid.index_at(coord.x, coord.y, coord.z);
			for(Side side : c_sides)
				blocks[i]->m_neighbours[size_t(side)] = grid.border(index, side) ? nullptr : grid.neighbour_item(index, side);
		}
	}
	
	void paint_block_height(Block& block, Image256& image, Element& element)
	{
		block.reset();

		size_t subdiv = block.subdiv();
		for(size_t y = 0; y < subdiv; ++y)
			for(size_t x = 0; x < subdiv; ++x)
			{
				size_t height = image.at(x, y);
				for(size_t z = 0; z <= height; ++z)
					block.chunk(x, z, y, element);
			}
	}

	void paint_block_elements(Block& block, Image256& image, array<Element*> elements)
	{
		size_t subdiv = block.subdiv();
		for(size_t y = 0; y < subdiv; ++y)
			for(size_t x = 0; x < subdiv; ++x)
				for(size_t z = 0; z < subdiv; ++z)
				{
					size_t colour = image.at(x, y);
					Element* element = block.m_chunks.at(x, z, y);

					if(element->m_state == MatterState::Solid)
						block.chunk(x, z, y, *elements[colour]);
				}
	}

	Block::Block(Id id, Entity& parent, const vec3& position, Block* parentblock, size_t index, const vec3& size)
		: Complex(id, type<Block>(), m_emitter, *this)
		, m_entity(id, *this, parent, position, ZeroQuat)
		, m_emitter(m_entity)
		, m_parentblock(parentblock)
		, m_index(index)
		, m_size(size)
		, m_chunks(BLOCK_SUBDIV)
		, m_subblocks(2)
		, m_scope(m_emitter.add_scope(WorldMedium::me, Cube(m_size), CM_SOURCE))
	{}

	size_t Block::depth()
	{
		return m_parentblock ? m_parentblock->depth() + 1 : 0;
	}

	vec3 Block::min()
	{
		vec3 half_size = m_size / 2.f;
		return m_entity.absolute_position() - half_size;
	}

	vec3 Block::max()
	{
		vec3 half_size = m_size / 2.f;
		return m_entity.absolute_position() + half_size;
	}

	vec3 Block::coordinates()
	{
		return m_parentblock ? m_parentblock->block_coord(*this) : vec3(0, 0, 0);
	}

	size_t Block::subdiv()
	{
		return BLOCK_SUBDIV;
	}

	vec3 Block::chunk_size()
	{
		return m_size / float(this->subdiv());
	}

	void Block::reset()
	{
		for(Element*& chunk : m_chunks)
			chunk = nullptr;
	}

	void Block::chunk(size_t x, size_t y, size_t z, Element& element)
	{
		m_chunks.at(x, y, z) = &element;
	}

	void Block::commit()
	{
		m_updated++;
		this->sector().m_world_page.m_updated++; // = m_entity.m_last_tick;
	}

	vec3 Block::local_block_coord(Block& child)
	{
		size_t index = child.m_index;
		return this->local_block_coord(index);
	}

	vec3 Block::local_block_coord(size_t index)
	{
		return vec3(m_subblocks.x(index), m_subblocks.y(index), m_subblocks.z(index));
	}

	vec3 Block::block_coord(Block& subblock)
	{
		vec3 coordinates = this->local_block_coord(subblock);

		if(m_parentblock)
			coordinates += m_parentblock->block_coord(*this) * 2.f;

		return coordinates;
	}

	vec3 Block::local_chunk_coord(size_t index)
	{
		return vec3(m_chunks.x(index), m_chunks.y(index), m_chunks.z(index));
	}

	vec3 Block::chunk_coord(size_t index)
	{
		vec3 coordinates = this->local_chunk_coord(index);

		if(m_parentblock)
			coordinates += m_parentblock->block_coord(*this) * float(this->subdiv());

		return coordinates;
	}

	vec3 Block::chunk_position(size_t index)
	{
		vec3 coordinates = this->local_chunk_coord(index) * this->chunk_size() + this->chunk_size() / 2.f - m_size / 2.f;
		return coordinates;
	}

	Hunk Block::hunk_at(size_t index)
	{
		return Hunk(*this, index, m_chunks[index]);
	}

	void Block::subdivide()
	{
		for(size_t index = 0; index < 8; ++index)
		{
			vec3 half_size = m_size / 2.f;
			vec3 half_subdiv_size = half_size / 2.f;
			vec3 position = this->local_block_coord(index) * half_size - half_size + half_subdiv_size;

			Block& block = m_entity.construct<Block>(position, this, index, m_size / 2.f);

			m_subblocks.push_back(&block);
		}

		m_subdived = true;
		// "update" trick
		m_entity.set_position(m_entity.m_position);
	}

	void Block::subdivide_to(size_t depth)
	{
		this->subdivide();

		if(depth - 1 > 0)
		{
			for(Block* block : m_subblocks)
				block->subdivide_to(depth - 1);
		}
	}

	Hunk Block::neighbour(size_t index, Side side)
	{
		if(m_chunks.border(index, side))
		{
			if(!m_neighbours[size_t(side)])
				return Hunk();

			size_t neighbour = m_neighbours[size_t(side)]->m_chunks.neighbour_mod(index, side);
			return m_neighbours[size_t(side)]->hunk_at(neighbour);
		}
		else
		{
			size_t neighbour = m_chunks.neighbour(index, side);
			return this->hunk_at(neighbour);
		}
	}

	Hunk Block::neighbour(Hunk& hunk, Side side)
	{
		return this->neighbour(hunk.index, side);
	}

	Sector& Block::sector()
	{
		Entity* parent = m_entity.m_parent;
		for(size_t depth = 1; !parent->isa<Sector>(); parent = parent->m_parent)
			++depth;

		return parent->as<Sector>();
	}
}
