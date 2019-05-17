#include <two/gfx.h>
#include <two/geom.h>
#include <toy/core.h>
#include <two/tree.h>
#include <two/ecs.h>
#include <two/math.h>
#include <toy/block.h>
#include <two/math.refl.h>
#include <two/infra.h>
#include <two/type.h>


#ifdef TWO_MODULES
module toy.block
#else
#endif

#define BLOCK_SUBDIV 20U

namespace toy
{
	void index_blocks(const uvec3& grid_size, vector2d<Block*>& grid, span<Block*> blocks, span<Sector*> sectors)
	{
		grid.reset(grid_size.x, grid_size.y, grid_size.z);

		for(size_t i = 0; i < blocks.size(); ++i)
		{
			uvec3 coord = sectors[i]->m_coordinate;
			grid.at(coord.x, coord.y, coord.z) = blocks[i];
		}

		for(size_t i = 0; i < blocks.size(); ++i)
		{
			uvec3 coord = sectors[i]->m_coordinate;
			size_t index = grid.index_at(coord.x, coord.y, coord.z);
			for(Side side : c_sides)
				blocks[i]->m_neighbours[side] = grid.border(index, side) ? nullptr : grid.neighbour_item(index, side);
		}
	}
	
	void paint_block_height(Block& block, Image256& image, Element& element)
	{
		block.reset();

		uint16_t subdiv = block.subdiv();
		for(uint16_t y = 0; y < subdiv; ++y)
			for(uint16_t x = 0; x < subdiv; ++x)
			{
				uint32_t height = image.at(uvec2(x, y));
				for(uint32_t z = 0; z <= height; ++z)
					block.chunk(x, z, y, element);
			}
	}

	void paint_block_elements(Block& block, Image256& image, span<Element*> elements)
	{
		uint16_t subdiv = block.subdiv();
		for(uint16_t y = 0; y < subdiv; ++y)
			for(uint16_t x = 0; x < subdiv; ++x)
				for(uint16_t z = 0; z < subdiv; ++z)
				{
					size_t colour = image.at(uvec2(x, y));
					Element* element = block.m_chunks.at(x, z, y);

					if(element->m_state == MatterState::Solid)
						block.chunk(x, z, y, *elements[colour]);
				}
	}

	Entity Block::create(ECS& ecs, HSpatial parent, HWorldPage world_page, const vec3& position, Block* parentblock, size_t index, const vec3& size)
	{
		Entity entity = ecs.create<Spatial, Block>();
		asa<Spatial>(entity) = Spatial(parent, position, ZeroQuat);
		asa<Block>(entity) = Block(HSpatial(entity), world_page, parentblock, index, size);
		//, m_emitter(*this, m_spatial, m_movable)
		return entity;
	}

	Block::Block() {}
	Block::Block(HSpatial spatial, HWorldPage world_page, Block* parentblock, size_t index, const vec3& size)
		: m_spatial(spatial)
		, m_world_page(world_page)
		, m_parentblock(parentblock)
		, m_index(index)
		, m_size(size)
		, m_chunks(BLOCK_SUBDIV)
		, m_subblocks(2)
		//, m_scope(m_emitter.add_scope(WorldMedium::me, Cube(m_size), CM_SOURCE))
	{}

	uint16_t Block::depth()
	{
		return m_parentblock ? m_parentblock->depth() + 1 : 0;
	}

	vec3 Block::min(Spatial& self)
	{
		vec3 half_size = m_size / 2.f;
		return self.absolute_position() - half_size;
	}

	vec3 Block::max(Spatial& self)
	{
		vec3 half_size = m_size / 2.f;
		return self.absolute_position() + half_size;
	}

	uvec3 Block::coordinates()
	{
		return m_parentblock ? m_parentblock->block_coord(*this) : uvec3(0U);
	}

	uint16_t Block::subdiv()
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
		WorldPage& page = m_world_page;
		page.m_updated++;
	}

	uvec3 Block::local_block_coord(Block& child)
	{
		size_t index = child.m_index;
		return this->local_block_coord(index);
	}

	uvec3 Block::local_block_coord(size_t index)
	{
		return uvec3(uint(m_subblocks.x(index)), uint(m_subblocks.y(index)), uint(m_subblocks.z(index)));
	}

	uvec3 Block::block_coord(Block& subblock)
	{
		uvec3 coordinates = this->local_block_coord(subblock);

		if(m_parentblock)
			coordinates += m_parentblock->block_coord(*this) * 2U;

		return coordinates;
	}

	uvec3 Block::local_chunk_coord(size_t index)
	{
		return uvec3(uint(m_chunks.x(index)), uint(m_chunks.y(index)), uint(m_chunks.z(index)));
	}

	uvec3 Block::chunk_coord(size_t index)
	{
		uvec3 coordinates = this->local_chunk_coord(index);

		if(m_parentblock)
			coordinates += m_parentblock->block_coord(*this) * uint(this->subdiv());

		return coordinates;
	}

	vec3 Block::chunk_position(size_t index)
	{
		vec3 coordinates = vec3(this->local_chunk_coord(index)) * this->chunk_size() + this->chunk_size() / 2.f - m_size / 2.f;
		return coordinates;
	}

	Hunk Block::hunk_at(size_t index)
	{
		return Hunk(*this, index, m_chunks[index]);
	}

	void Block::subdivide()
	{
		Spatial& spatial = m_spatial;

		for(size_t index = 0; index < 8; ++index)
		{
			vec3 half_size = m_size / 2.f;
			vec3 half_subdiv_size = half_size / 2.f;
			vec3 position = vec3(this->local_block_coord(index)) * half_size - half_size + half_subdiv_size;

			HBlock block = construct<Block>(m_spatial, m_world_page, position, this, index, m_size / 2.f);

			m_subblocks.push_back(block);
		}

		m_subdived = true;
		// "update" trick
		spatial.set_position(spatial.m_position);
	}

	void Block::subdivide_to(uint16_t depth)
	{
		this->subdivide();

		if(depth - 1 > 0)
		{
			for(HBlock& block : m_subblocks)
				block->subdivide_to(depth - 1);
		}
	}

	Hunk Block::neighbour(size_t index, Side side)
	{
		if(m_chunks.border(index, side))
		{
			if(!m_neighbours[side])
				return Hunk();

			size_t neighbour = m_neighbours[side]->m_chunks.neighbour_mod(index, side);
			return m_neighbours[side]->hunk_at(neighbour);
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
}
#ifndef USE_STL
#ifdef TWO_MODULES
module toy.block;
#else
#include <stl/vector.hpp>
#include <stl/unordered_map.hpp>
#endif

namespace two
{
	template class TOY_BLOCK_EXPORT vector2d<toy::Block*>;
}

namespace stl
{
	using namespace toy;
	template class TOY_BLOCK_EXPORT vector<Quad>;
	template class TOY_BLOCK_EXPORT vector<Cube>;
	template class TOY_BLOCK_EXPORT vector<Chunk>;
	template class TOY_BLOCK_EXPORT vector<Heap>;
	template class TOY_BLOCK_EXPORT vector<Block>;
	template class TOY_BLOCK_EXPORT vector<Sector>;
	template class TOY_BLOCK_EXPORT vector<Tileblock>;
	template class TOY_BLOCK_EXPORT vector<HBlock>;
	template class TOY_BLOCK_EXPORT vector<Element*>;
	template class TOY_BLOCK_EXPORT vector<Heap*>;
	template class TOY_BLOCK_EXPORT vector<Block*>;
	template class TOY_BLOCK_EXPORT vector<Sector*>;
	template class TOY_BLOCK_EXPORT unordered_map<Element*, vector<ProcShape>>;
	template class TOY_BLOCK_EXPORT unordered_map<Element*, unique<Model>>;
}
#endif

#ifdef TWO_MODULES
module toy.block;
#else
#endif

namespace two
{
    // Exported types
    template <> TOY_BLOCK_EXPORT Type& type<toy::MatterState>() { static Type ty("MatterState", sizeof(toy::MatterState)); return ty; }
    
    template <> TOY_BLOCK_EXPORT Type& type<stl::span<toy::Element*>>() { static Type ty("span<toy::Element*>", sizeof(stl::span<toy::Element*>)); return ty; }
    template <> TOY_BLOCK_EXPORT Type& type<stl::vector<toy::Block*>>() { static Type ty("vector<toy::Block*>", sizeof(stl::vector<toy::Block*>)); return ty; }
    template <> TOY_BLOCK_EXPORT Type& type<stl::vector<toy::Sector*>>() { static Type ty("vector<toy::Sector*>", sizeof(stl::vector<toy::Sector*>)); return ty; }
    
    template <> TOY_BLOCK_EXPORT Type& type<two::ComponentHandle<toy::Block>>() { static Type ty("ComponentHandle<toy::Block>", sizeof(two::ComponentHandle<toy::Block>)); return ty; }
    template <> TOY_BLOCK_EXPORT Type& type<two::ComponentHandle<toy::Chunk>>() { static Type ty("ComponentHandle<toy::Chunk>", sizeof(two::ComponentHandle<toy::Chunk>)); return ty; }
    template <> TOY_BLOCK_EXPORT Type& type<two::ComponentHandle<toy::Heap>>() { static Type ty("ComponentHandle<toy::Heap>", sizeof(two::ComponentHandle<toy::Heap>)); return ty; }
    template <> TOY_BLOCK_EXPORT Type& type<two::ComponentHandle<toy::Sector>>() { static Type ty("ComponentHandle<toy::Sector>", sizeof(two::ComponentHandle<toy::Sector>)); return ty; }
    template <> TOY_BLOCK_EXPORT Type& type<two::ComponentHandle<toy::Tileblock>>() { static Type ty("ComponentHandle<toy::Tileblock>", sizeof(two::ComponentHandle<toy::Tileblock>)); return ty; }
    template <> TOY_BLOCK_EXPORT Type& type<two::vector2d<toy::Block*>>() { static Type ty("vector2d<toy::Block*>", sizeof(two::vector2d<toy::Block*>)); return ty; }
    template <> TOY_BLOCK_EXPORT Type& type<toy::Block>() { static Type ty("Block", sizeof(toy::Block)); return ty; }
    template <> TOY_BLOCK_EXPORT Type& type<toy::Chunk>() { static Type ty("Chunk", sizeof(toy::Chunk)); return ty; }
    template <> TOY_BLOCK_EXPORT Type& type<toy::Element>() { static Type ty("Element", sizeof(toy::Element)); return ty; }
    template <> TOY_BLOCK_EXPORT Type& type<toy::Heap>() { static Type ty("Heap", sizeof(toy::Heap)); return ty; }
    template <> TOY_BLOCK_EXPORT Type& type<toy::Earth>() { static Type ty("Earth", type<toy::Element>(), sizeof(toy::Earth)); return ty; }
    template <> TOY_BLOCK_EXPORT Type& type<toy::Sector>() { static Type ty("Sector", sizeof(toy::Sector)); return ty; }
    template <> TOY_BLOCK_EXPORT Type& type<toy::Tileblock>() { static Type ty("Tileblock", sizeof(toy::Tileblock)); return ty; }
}

#ifdef TWO_MODULES
module toy.core
#else
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

#ifdef TWO_MODULES
module toy.core
#else
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


namespace toy
{
	Earth Earth::me;
	Stone Stone::me;
	Sand Sand::me;
	Air Air::me;
	Gas Gas::me;
	Minerals Minerals::me;
	Fungus Fungus::me;
	Water Water::me;
}


namespace two
{
	template struct ComponentHandle<toy::Block>;
	template struct ComponentHandle<toy::Chunk>;
	template struct ComponentHandle<toy::Heap>;
	template struct ComponentHandle<toy::Sector>;
	template struct ComponentHandle<toy::Tileblock>;
}

#ifdef TWO_MODULES
module toy.block
#else
#endif

namespace toy
{
	Entity Sector::create(ECS& ecs, HSpatial parent, const vec3& position, const uvec3& coordinate, const vec3& size)
	{
		Entity entity = ecs.create<Spatial, WorldPage, Navblock, Sector>();
		ecs.set(entity, Spatial(parent, position, ZeroQuat));
		ecs.set(entity, WorldPage(HSpatial(entity), true, size));
		ecs.set(entity, Navblock(HSpatial(entity), HWorldPage(entity), as<Navmesh>(parent->m_world->m_complex)));
		ecs.set(entity, Sector(HSpatial(entity), HWorldPage(entity), HNavblock(entity), coordinate, size));
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

		attr_ vector<Element*> m_elements;

		attr_ vector<Sector*> m_sectors;
		attr_ vector2d<Block*> m_blocks;

	};

	void block_grid(World& world, BlockGrid& grid, const uvec3& grid_subdiv, const uvec3& block_subdiv, const vec3& cell_size)
	{
		grid.m_sector_size = vec3(block_subdiv) * cell_size;
		grid.m_world_size = grid.m_sector_size * vec3(grid_subdiv);
		grid.m_center_offset = grid.m_world_size * 0.5f;
		grid.m_center_offset.y = 0.f;

		vector<uvec3> coords;
		two::grid(grid_subdiv, coords);

		vector<Block*> blocks;

		for(uvec3 coord : coords)
		{
			vec3 position = grid_center(coord, grid.m_sector_size) - grid.m_center_offset;

			Sector& sector = construct<Sector>(world.origin(), position, coord, grid.m_sector_size);
			Block& block = construct<Block>(sector.m_spatial, sector.m_world_page, vec3(0.f), nullptr, 0, grid.m_sector_size);

			grid.m_sectors.push_back(&sector);
			blocks.push_back(&block);
			sector.m_block = &block;
		}

		index_blocks(grid_subdiv, grid.m_blocks, blocks, grid.m_sectors);
	}

	Entity Tileblock::create(ECS& ecs, HSpatial parent, const vec3& position, const uvec3& size, const vec3& tile_scale, WaveTileset& tileset)
	{
		Entity entity = ecs.create<Spatial, WorldPage, Navblock, Tileblock>();
		ecs.set(entity, Spatial(parent, position, ZeroQuat));
		ecs.set(entity, WorldPage(HSpatial(entity), true, vec3(size)));
		ecs.set(entity, Navblock(HSpatial(entity), HWorldPage(entity), as<Navmesh>(parent->m_world->m_complex)));
		ecs.set(entity, Tileblock(HSpatial(entity), HWorldPage(entity), HNavblock(entity), size, tile_scale, tileset));
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

	HTileblock generate_block(GfxSystem& gfx, WaveTileset& tileset, HSpatial origin, const ivec2& coord, const uvec3& block_subdiv, const vec3& tile_scale, bool from_file)
	{
		vec3 position = vec3(to_xz(coord)) * vec3(block_subdiv) * tile_scale;
		HTileblock block = construct<Tileblock>(origin, position, block_subdiv, tile_scale, tileset);

		if(block->m_wfc_block.m_tile_models.empty())
			block->m_wfc_block.load_models(gfx, from_file);

		return block;
	}

	void build_block_geometry(Scene& scene, WorldPage& page, Tileblock& block)
	{
		UNUSED(scene);

		WfcBlock& tileblock = block.m_wfc_block;

		vector<Cube> cubes;
		vector<ProcShape> shapes;
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

		span<Vertex> vertices = geometry.vertices();
		span<uint32_t> indices = geometry.indices();
		MeshAdapter data(Vertex::vertex_format, { vertices.data(), vertices.size() }, { indices.data(), indices.size() }, true);

		for(const ProcShape& shape : shapes)
		{
			symbol_draw_triangles(shape, data);
			data.next();
		}
	}
}

#ifdef TWO_MODULES
module toy.block
#else
#include <stl/hash_base.hpp>
#endif

#include <cstdio>

#define DEBUG_BLOCK 0
#define BLOCK_WIREFRAME 1

namespace toy
{
	void paint_heap(Gnode& parent, Heap& heap)
	{
		gfx::light(parent, LightType::Point, false, heap.m_element->m_colour, heap.m_radius * 2.f);
		//gfx::shape(parent, Circle(heap.m_radius), Symbol(heap.m_element.m_colour));
		//gfx::shape(parent, Spheroid(heap.radius(), Symbol(heap.m_element.m_colour));
	}

	void paint_block(Gnode& parent, Block& block, Material* material)
	{
#if DEBUG_BLOCK
		float size = block.m_size / 2.f;
		gfx::shape(parent, Cube(size), Symbol(Colour(1.f, 1.f, 1.f, 0.2f)));
#endif
		BlockState& state = parent.state<BlockState>();
		if(state.m_updated < block.m_updated)
		{
			state.m_updated = block.m_updated;
			update_block_geometry(parent.m_scene->m_gfx, block, state);
		}

		for(auto& element_model : state.m_models)
			gfx::item(parent, *element_model.second, ItemFlag::Default | ItemFlag::Static | ItemFlag::Selectable, material);
	}

	Material& plain_material(GfxSystem& gfx, cstring name)
	{
		Material& material = gfx.fetch_material(name, "pbr/pbr");
		material.m_base.m_geometry_filter = 1 << uint(PrimitiveType::Triangles);
		return material;
	}

	Material& wireframe_material(GfxSystem& gfx, cstring name, const Colour& colour)
	{
		string variant_name = string(name) + "_" + to_string(to_rgba(colour));
		Material& material = gfx.fetch_material(variant_name.c_str(), "solid");
		material.m_base.m_geometry_filter = 1 << uint(PrimitiveType::Lines);
		material.m_solid.m_colour.m_value = colour;
		return material;
	}

	void paint_block(Gnode& parent, Block& block)
	{
		static Material& material = plain_material(parent.m_scene->m_gfx, "block");
		paint_block(parent, block, &material);
	}

	void paint_block_wireframe(Gnode& parent, Block& block, const Colour& colour)
	{
		static Material& material = wireframe_material(parent.m_scene->m_gfx, "block_wireframe", colour);
		paint_block(parent, block, &material);
	}

	void voxel_side(Block& block, size_t chunk, Element* element, Side side, vector<Quad>& quads, vector<ProcShape>& shapes)
	{
		SignedAxis axis = SignedAxis(side);
		Quad quad = { to_xz(block.chunk_size()), c_dirs_tangents[axis], c_dirs_normals[axis] };
		quad.m_center = block.chunk_position(chunk) + to_vec3(side) * block.chunk_size() / 2.f;

		quads.push_back(quad);
		shapes.push_back({ Symbol(), &quads.back(), OUTLINE });
		shapes.push_back({ Symbol(element->m_colour), &quads.back(), PLAIN });
	}

	void update_block_geometry(GfxSystem& gfx, Block& block, BlockState& state)
	{
		UNUSED(gfx);

		//Spatial& spatial = block.m_spatial;
		WorldPage& world_page = block.m_world_page;

		if(block.m_subdived)
			return;

		vector<Quad> quads;
		//quads.reserve(block.m_chunks.size() * 6 / 2);
		quads.reserve(block.m_chunks.size() * 6 / 2 * 16);

		state.m_models.clear();

		map<Element*, vector<ProcShape>> bodies;

		vector<Element*> elements = { &Earth::me, &Stone::me, &Sand::me, &Air::me, &Gas::me, &Minerals::me, &Fungus::me, &Water::me };

		size_t index = 0;
		for(Element* element : block.m_chunks)
		{
			if(element == nullptr /*|| element->matterState() != STATE_SOLID*/)
			{
				++index;
				continue;
			}

			for(Side side : c_sides)
			{
				Hunk neighbour = block.neighbour(index, side);

				if(!neighbour || neighbour.element == element)
					continue;

				voxel_side(block, index, element, side, quads, bodies[element]);
			}

			++index;
		}

		for(Element* element : elements)
			if(!bodies[element].empty())
			{
				string identifier = "sector_" + to_string(block.m_index) + "_" + element->m_name;

				printf("[info] Creating geometry for Block %s, %zu quads\n", identifier.c_str(), bodies[element].size());

				state.m_models[element] = gen_model(identifier.c_str(), bodies[element], true);

				/*
				Material& plain = gfx.fetch_material(element->m_name.c_str(), "pbr/pbr");
				plain.m_base.m_geometry_filter = 1 << uint(PrimitiveType::Triangles);
				plain.m_pbr.m_enabled = true;

				state.m_models[element]->m_meshes[0]->m_material = &wireframe;
				state.m_models[element]->m_meshes[1]->m_material = &wireframe;
				*/

				world_page.m_geometry_filter.push_back(identifier); // @kludge : find out a more intelligent way to filter world geometry
			}

		//as<WorldPage>(block.sector()).update_geometry();
	}
}
