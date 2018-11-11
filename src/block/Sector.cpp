//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.


#include <block/Types.h>
#include <block/Sector.h>

#include <core/Spatial/Spatial.h>
#include <core/World/World.h>

#include <block/Element.h>
#include <block/Block.h>

#include <core/World/Section.h>

using namespace mud; namespace toy
{
	Entity Sector::create(ECS& ecs, HSpatial parent, const vec3& position, const uvec3& coordinate, const vec3& size)
	{
		Entity entity = { ecs.CreateEntity<Spatial, WorldPage, Navblock, Sector>(), ecs.m_index };
		ecs.SetComponent(entity, Spatial(parent, position, ZeroQuat));
		ecs.SetComponent(entity, WorldPage(HSpatial(entity), true, size));
		ecs.SetComponent(entity, Navblock(HSpatial(entity), HWorldPage(entity), as<Navmesh>(parent->m_world->m_complex)));
		ecs.SetComponent(entity, Sector(HSpatial(entity), HWorldPage(entity), HNavblock(entity), coordinate, size));
		return entity;
	}

	Sector::Sector(HSpatial spatial, HWorldPage world_page, HNavblock navblock, const uvec3& coordinate, const vec3& size)
		: m_spatial(spatial)
		, m_world_page(world_page)
		, m_navblock(navblock)
		, m_coordinate(coordinate)
		, m_size(size)
		, m_block(nullptr)
		, m_heaps()
	{}

	struct BlockGrid
	{
		BlockGrid(const uvec3& grid_subdiv, const uvec3& block_subdiv, const vec3& cell_size)
			: m_subdiv(grid_subdiv), m_block_subdiv(block_subdiv), m_cell_size(cell_size)
		{}

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

			Sector& sector = construct<Sector>(world.origin(), position, coord, grid.m_sector_size);
			Block& block = construct<Block>(sector.m_spatial, sector.m_world_page, Zero3, nullptr, 0, grid.m_sector_size);

			grid.m_sectors.push_back(&sector);
			blocks.push_back(&block);
			sector.m_block = &block;
		}

		index_blocks(grid_subdiv, grid.m_blocks, blocks, grid.m_sectors);
	}

	Entity Tileblock::create(ECS& ecs, HSpatial parent, const vec3& position, const uvec3& size, const vec3& tile_scale, WaveTileset& tileset)
	{
		Entity entity = { ecs.CreateEntity<Spatial, WorldPage, Navblock, Tileblock>(), ecs.m_index };
		ecs.SetComponent(entity, Spatial(parent, position, ZeroQuat));
		ecs.SetComponent(entity, WorldPage(HSpatial(entity), true, size));
		ecs.SetComponent(entity, Navblock(HSpatial(entity), HWorldPage(entity), as<Navmesh>(parent->m_world->m_complex)));
		ecs.SetComponent(entity, Tileblock(HSpatial(entity), HWorldPage(entity), HNavblock(entity), size, tile_scale, tileset));
		return entity;
	}

	Tileblock::Tileblock(HSpatial spatial, HWorldPage world_page, HNavblock navblock, const uvec3& size, const vec3& period, WaveTileset& tileset)
		: m_spatial(spatial)
		, m_world_page(world_page)
		, m_navblock(navblock)
		, m_wfc_block(spatial->m_position, size, period, tileset)
	{
		//m_spatial.m_world.add_task(this, short(Task::Background));
	}

	Tileblock::~Tileblock()
	{
		//m_spatial.m_world.remove_task(this, short(Task::Background));
	}

	void Tileblock::next_frame(WorldPage& world_page, size_t frame, size_t delta)
	{
		m_wfc_block.next_frame(frame, delta);

		world_page.m_updated = m_wfc_block.m_wave_solved;

		if(m_wfc_block.m_wave.m_solved && !m_setup)
			m_setup = true;
	}

	bool Tileblock::contains(const vec3& position)
	{
		bool outside = any(less(position, m_wfc_block.m_aabb.bmin())) && any(less(position, m_wfc_block.m_aabb.bmax()));
		return !outside;
	}

	HTileblock generate_block(GfxSystem& gfx_system, WaveTileset& tileset, HSpatial origin, const ivec2& coord, const uvec3& block_subdiv, const vec3& tile_scale, bool from_file)
	{
		vec3 position = vec3(to_xz(coord)) * vec3(block_subdiv) * tile_scale;
		HTileblock block = construct<Tileblock>(origin, position, block_subdiv, tile_scale, tileset);

		if(block->m_wfc_block.m_tile_models.empty())
			block->m_wfc_block.load_models(gfx_system, from_file);

		return block;
	}

	void build_block_geometry(Scene& scene, WorldPage& page, Tileblock& block)
	{
		UNUSED(scene);

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
		Geometry& geometry = page.m_chunks.back();

		ShapeSize size;
		for(const ProcShape& shape : shapes)
			size.vec += symbol_triangle_size(shape).vec;

		geometry.allocate(size.vertex_count, size.index_count);

		array<Vertex> vertices = geometry.vertices();
		array<uint32_t> indices = geometry.indices();
		MeshAdapter data(Vertex::vertex_format, vertices.data(), vertices.size(), indices.data(), indices.size(), true);

		for(const ProcShape& shape : shapes)
		{
			symbol_draw_triangles(shape, data);
			data.next();
		}
	}
}
