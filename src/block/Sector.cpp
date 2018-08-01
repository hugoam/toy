//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.


#include <block/Types.h>
#include <block/Sector.h>

#include <core/Entity/Entity.h>
#include <core/World/World.h>

#include <block/Element.h>
#include <block/Block.h>

#include <core/World/Section.h>

using namespace mud; namespace toy
{
	Sector::Sector(Id id, Entity& parent, const vec3& position, const uvec3& coordinate, const vec3& size)
		: Complex(id, type<Sector>(), m_emitter, m_world_page, m_bufferPage, m_navblock, *this)
		, m_entity(id, *this, parent, position, ZeroQuat)
		, m_emitter(m_entity)
		, m_world_page(m_entity, m_emitter, true, size)
		, m_bufferPage(m_entity, m_world_page, true)
		, m_navblock(m_entity.m_world.as<Navmesh>(), m_entity, m_world_page)
		, m_coordinate(coordinate)
		, m_size(size)
		, m_block(nullptr)
		, m_heaps()
	{}

	struct BlockGrid
	{
		BlockGrid(const uvec3& grid_subdiv, const uvec3& block_subdiv, const vec3& cell_size) {}

		attr_ uvec3 m_subdiv;
		attr_ uvec3 m_block_subdiv;
		attr_ vec3 m_cell_size;

		attr_ vec3 m_sector_size;
		attr_ vec3 m_world_size;
		attr_ vec3 m_center_offset;

		attr_ std::vector<Element*> m_elements;

		attr_ std::vector<Sector*> m_sectors;
		attr_ Grid<Block*> m_blocks;

	};

	void block_grid(World& world, BlockGrid& grid, const uvec3& grid_subdiv, const uvec3& block_subdiv, const vec3& cell_size)
	{
		grid.m_sector_size = vec3(block_subdiv) * cell_size;
		grid.m_world_size = grid.m_sector_size * vec3(grid_subdiv);
		grid.m_center_offset = grid.m_world_size * 0.5f;
		grid.m_center_offset.y = 0.f;

		std::vector<uvec3> coords;
		mud::grid(grid_subdiv, coords);

		std::vector<Block*> blocks;

		for(uvec3 coord : coords)
		{
			vec3 position = grid_center(coord, grid.m_sector_size) - grid.m_center_offset;

			Sector& sector = world.origin().construct<Sector>(position, coord, grid.m_sector_size);
			Block& block = sector.m_entity.construct<Block>(Zero3, nullptr, 0, grid.m_sector_size);

			grid.m_sectors.push_back(&sector);
			blocks.push_back(&block);
			sector.m_block = &block;
		}

		index_blocks(grid_subdiv, grid.m_blocks, blocks, grid.m_sectors);
	}

	TileBlock::TileBlock(Id id, Entity& parent, const vec3& position, const uvec3& size, const vec3& period, WaveTileset& tileset)
		: Complex(id, type<TileBlock>(), *this, m_emitter, m_world_page, m_navblock)
		, m_entity(id, *this, parent, position, ZeroQuat)
		, m_emitter(m_entity)
		, m_world_page(m_entity, m_emitter, true, vec3(size) * 0.5f)
		, m_navblock(m_entity.m_world.as<Navmesh>(), m_entity, m_world_page)
		, m_wfc_block(position, size, period, tileset)
	{
		m_entity.m_world.add_task(this, short(Task::Background));
	}

	TileBlock::~TileBlock()
	{
		m_entity.m_world.remove_task(this, short(Task::Background));
	}

	void TileBlock::next_frame(size_t frame, size_t delta)
	{
		m_wfc_block.next_frame(frame, delta);

		m_world_page.m_updated = m_wfc_block.m_wave_solved;

		if(m_wfc_block.m_wave.m_solved && !m_setup)
			m_setup = true;
	}

	bool TileBlock::contains(const vec3& position)
	{
		bool outside = any(less(position, m_wfc_block.m_aabb.bmin())) && any(less(position, m_wfc_block.m_aabb.bmax()));
		return !outside;
	}

	TileBlock& generate_block(GfxSystem& gfx_system, WaveTileset& tileset, Entity& origin, const ivec2& coord, const uvec3& block_subdiv, const vec3& tile_scale, bool from_file)
	{
		vec3 position = vec3(to_xz(coord)) * vec3(block_subdiv) * tile_scale;
		TileBlock& block = global_pool<TileBlock>().construct(0U, origin, position, block_subdiv, tile_scale, tileset);

		if(block.m_wfc_block.m_tile_models.empty())
			block.m_wfc_block.load_models(gfx_system, from_file);

		return block;
	}

	void build_block_geometry(Scene& scene, WorldPage& page, TileBlock& block)
	{
		WfcBlock& tileblock = block.m_wfc_block;

		std::vector<Cube> cubes;
		std::vector<ProcShape> shapes;
		cubes.reserve(tileblock.m_tiles.size());

		for(size_t x = 0; x < tileblock.m_tiles.m_x; ++x) for(size_t y = 0; y < tileblock.m_tiles.m_y; ++y) for(size_t z = 0; z < tileblock.m_tiles.m_z; ++z)
		{
			uint16_t index = tileblock.m_tiles.at(x, y, z);

			if(index != UINT16_MAX)
			{
				TileModel& tile = tileblock.m_tile_models[index];
				if(tile.m_model)
				{
					vec3 position = tileblock.to_position({ uint(x), uint(y), uint(z) }) - tileblock.m_position + Y3 * 0.5f * tileblock.m_scale;
					cubes.push_back({ position, tileblock.m_scale / 2.f });
					shapes.push_back({ Symbol(), &cubes.back(), PLAIN });
				}
			}
		}

		page.m_chunks.emplace_back();
		Geometry& geom = page.m_chunks.back();

		ShapeSize size;
		for(const ProcShape& shape : shapes)
			size.vec += symbol_triangle_size(shape).vec;

		geom.allocate(size.vertex_count, size.index_count);

		MeshData data(geom.vertices(), geom.indices());

		for(const ProcShape& shape : shapes)
		{
			symbol_draw_triangles(shape, data);
			data.next();
		}
	}
}
