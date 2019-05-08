#pragma once

#include <two/gfx.h>
#include <toy/visu.h>
#include <toy/core.h>
#include <two/ecs.h>
#include <two/math.h>
#include <toy/edit.h>
#include <two/wfc.gfx.h>
#include <two/type.h>
#include <two/infra.h>



#include <stl/vector.h>
#include <stl/memory.h>





#ifndef TOY_BLOCK_EXPORT
#define TOY_BLOCK_EXPORT TWO_IMPORT
#endif

namespace toy
{
    enum class MatterState : unsigned int;
    
    
    struct Hunk;
    class Block;
    class Chunk;
    class Element;
    class Heap;
    class ChunkFilter;
    class GroundChunk;
    class Earth;
    class Stone;
    class Sand;
    class Air;
    class Gas;
    class Minerals;
    class Fungus;
    class Water;
    class Sector;
    class Tileblock;
    struct BlockState;
}

#ifdef TWO_META_GENERATOR
#include <stl/span.h>
#include <stl/vector.h>
namespace stl
{
	export_ extern template struct refl_ seque_ span<toy::Element*>;
	export_ extern template struct refl_ seque_ vector<toy::Block*>;
	export_ extern template struct refl_ seque_ vector<toy::Sector*>;
}
namespace two
{
	export_ extern template struct refl_ ComponentHandle<toy::Block>;
	export_ extern template struct refl_ ComponentHandle<toy::Chunk>;
	export_ extern template struct refl_ ComponentHandle<toy::Heap>;
	export_ extern template struct refl_ ComponentHandle<toy::Sector>;
	export_ extern template struct refl_ ComponentHandle<toy::Tileblock>;
}
#endif

namespace toy
{
	using HBlock = ComponentHandle<Block>;
	using HChunk = ComponentHandle<Chunk>;
	using HHeap = ComponentHandle<Heap>;
	using HSector = ComponentHandle<Sector>;
	using HTileblock = ComponentHandle<Tileblock>;
}



namespace two
{
	template <> struct TypedBuffer<toy::Sector>		{ static uint32_t index() { return 12; } };
	template <> struct TypedBuffer<toy::Tileblock>	{ static uint32_t index() { return 13; } };
	template <> struct TypedBuffer<toy::Block>		{ static uint32_t index() { return 14; } };
	template <> struct TypedBuffer<toy::Chunk>		{ static uint32_t index() { return 15; } };
	template <> struct TypedBuffer<toy::Heap>		{ static uint32_t index() { return 16; } };
}

#ifdef TWO_META_GENERATOR
namespace two
{
	extern template class refl_ vector2d<toy::Block*>;
}
#endif

namespace toy
{
	struct Hunk
	{
		Block* block = nullptr;
		size_t index = SIZE_MAX;
		Element* element = nullptr;

		operator bool() { return block != nullptr; }

		Hunk(Block& b, size_t i, Element* e) : block(&b), index(i), element(e) {}
		Hunk() {}
	};

	TOY_BLOCK_EXPORT func_ void paint_block_height(Block& block, Image256& image, Element& element);
	TOY_BLOCK_EXPORT func_ void paint_block_elements(Block& block, Image256& image, span<Element*> elements);

	class refl_ TOY_BLOCK_EXPORT Block
	{
	public:
		constr_ Block();
		constr_ Block(HSpatial spatial, HWorldPage world_page, Block* parentblock, size_t index, const vec3& size);

		static Entity create(ECS& ecs, HSpatial parent, HWorldPage world_page, const vec3& position, Block* parentblock, size_t index, const vec3& size);

		comp_ HSpatial m_spatial;
		//comp_ HEmitter m_emitter;

		attr_ HWorldPage m_world_page;
		attr_ link_ Block* m_parentblock = nullptr;
		attr_ size_t m_index;
		attr_ vec3 m_size;
		attr_ size_t m_updated = 0;

		uint16_t m_depth = 0;

		bool m_subdived = false;

		vector2d<Element*> m_chunks;
		vector2d<HBlock> m_subblocks;

		table<Side, Block*> m_neighbours = {};

		meth_ void subdivide();

		meth_ void reset();
		meth_ void chunk(size_t x, size_t y, size_t z, Element& element);
		meth_ void commit();

		void subdivide_to(uint16_t depth);

		uint16_t depth();

		vec3 min(Spatial& self);
		vec3 max(Spatial& self);
		uvec3 coordinates();

		uint16_t subdiv();
		vec3 chunk_size();

		uvec3 local_block_coord(size_t index);
		uvec3 local_block_coord(Block& child);
		uvec3 block_coord(Block& child);
		
		uvec3 local_chunk_coord(size_t index);
		uvec3 chunk_coord(size_t index);

		vec3 chunk_position(size_t index);

		Hunk hunk_at(size_t index);

		Hunk neighbour(size_t index, Side side);
		Hunk neighbour(Hunk& hunk, Side side);

	protected:
		//EmitterScope& m_scope;
	};
}



namespace toy
{
	class refl_ TOY_BLOCK_EXPORT Chunk
	{
	public:
		constr_ Chunk() {}
		constr_ Chunk(Block& block, size_t index, Element& element, float size);

		static Entity create(ECS& ecs, HSpatial parent, Block& block, const vec3& position, size_t index, Element& element, float size);

		attr_ size_t m_index;
		attr_ Block* m_block;
		attr_ Element* m_element;
		attr_ float m_size;

		Chunk* neighbour(Side side);
		bool boundary(Side side);
	};
}


#include <stl/vector.h>
#include <stl/string.h>

namespace toy
{
	enum class refl_ MatterState : unsigned int
	{
		Solid,
		Liquid,
		Gas,
		Plasma
	};

	class refl_ TOY_BLOCK_EXPORT Element
	{
	public:
		constr_ Element(cstring name, MatterState state, Colour colour);

		attr_ uint32_t m_id;
		attr_ string m_name;
		attr_ MatterState m_state;
		attr_ Colour m_colour;
	};

	class refl_ TOY_BLOCK_EXPORT Heap
	{
	public:
		constr_ Heap() {}
		constr_ Heap(Element& element, float radius);

		static Entity create(ECS& ecs, HSpatial parent, const vec3& position, Element& element, float radius);

		attr_ link_ Element* m_element;
		attr_ float m_radius;
	};

	class TOY_BLOCK_EXPORT ChunkFilter
	{
	public:
		virtual bool filter(Chunk& chunk) = 0;
	};

	class TOY_BLOCK_EXPORT GroundChunk : public LazyGlobal<GroundChunk>, public ChunkFilter
	{
	public:
		bool filter(Chunk& cell);
	};
}



namespace toy
{
	class refl_ TOY_BLOCK_EXPORT Earth : public Element
	{
	public:
		constr_ Earth() : Element("earth", MatterState::Solid, Colour(0.4f, 0.3f, 0.3f)) {}
		attr_ static Earth me;
	};

	class TOY_BLOCK_EXPORT Stone : public Element
	{
	public:
		constr_ Stone() : Element("stone", MatterState::Solid, Colour(0.6f, 0.6f, 0.65f)) {}
		attr_ static Stone me;
	};

	class TOY_BLOCK_EXPORT Sand : public Element
	{
	public:
		Sand() : Element("sand", MatterState::Solid, Colour(0.55f, 0.5f, 0.2f)) {}
		attr_ static Sand me;
	};

	class TOY_BLOCK_EXPORT Air : public Element
	{
	public:
		Air() : Element("air", MatterState::Gas, Colour(1.f, 1.f, 1.f)) {}
		attr_ static Air me;
	};

	class TOY_BLOCK_EXPORT Gas : public Element
	{
	public:
		Gas() : Element("gas", MatterState::Gas, Colour(1.f, 0.1f, 0.f)) {}
		attr_ static Gas me;
	};

	class TOY_BLOCK_EXPORT Minerals : public Element
	{
	public:
		Minerals() : Element("minerals", MatterState::Solid, Colour(0.1f, 0.2f, 1.f)) {}
		attr_ static Minerals me;
	};

	class TOY_BLOCK_EXPORT Fungus : public Element
	{
	public:
		Fungus() : Element("mushrooms", MatterState::Solid, Colour(0.f, 1.f, 0.1f)) {}
		attr_ static Fungus me;
	};

	class TOY_BLOCK_EXPORT Water : public Element
	{
	public:
		Water() : Element("water", MatterState::Liquid, Colour(0.f, 0.3f, 1.f)) {}
		attr_ static Water me;
	};
}


#include <stl/vector.h>
#include <stl/function.h>
//#include <core/WorldPage/BufferPage.h>



namespace toy
{
	typedef vector<Chunk*> ChunkVector;

	class refl_ TOY_BLOCK_EXPORT Sector
	{
	public:
		constr_ Sector() {}
		constr_ Sector(HSpatial spatial, HWorldPage world_page, HNavblock navblock, const uvec3& coordinate, const vec3& size);

		static Entity create(ECS& ecs, HSpatial parent, const vec3& position, const uvec3& coordinate, const vec3& size);

		comp_ HSpatial m_spatial;
		comp_ HWorldPage m_world_page;
		comp_ HNavblock m_navblock;

		attr_ uvec3 m_coordinate;
		attr_ vec3 m_size;

		attr_ Block* m_block;

		vector<Heap*> m_heaps;
	};

	class refl_ TOY_BLOCK_EXPORT Tileblock
	{
	public:
		constr_ Tileblock() {}
		constr_ Tileblock(HSpatial spatial, HWorldPage world_page, HNavblock navblock, const uvec3& size, const vec3& tile_scale, WaveTileset& tileset);
		~Tileblock();

		static Entity create(ECS& ecs, HSpatial parent, const vec3& position, const uvec3& size, const vec3& tile_scale, WaveTileset& tileset);

		comp_ HSpatial m_spatial;
		comp_ HWorldPage m_world_page;
		comp_ HNavblock m_navblock;

		attr_ WfcBlock m_wfc_block;
		attr_ bool m_setup = false;
		attr_ bool m_populated = false;

		function<void(Tileblock&)> m_on_setup;

		void next_frame(WorldPage& world_page, size_t frame, size_t delta);

		bool contains(const vec3& position);
	};

	TOY_BLOCK_EXPORT func_ HTileblock generate_block(GfxSystem& gfx, WaveTileset& tileset, HSpatial origin, const ivec2& coord, const uvec3& block_subdiv, const vec3& tile_scale, bool from_file = true);

	TOY_BLOCK_EXPORT func_ void build_block_geometry(Scene& scene, WorldPage& page, Tileblock& block);

	TOY_BLOCK_EXPORT func_ void index_blocks(const uvec3& grid_size, vector2d<Block*>& grid, span<Block*> blocks, span<Sector*> sectors);
}

#include <stdint.h>
#include <stl/string.h>
#include <stl/vector.h>

#if !defined TWO_MODULES || defined TWO_TYPE_LIB
#endif

#ifndef TWO_MODULES
#endif


namespace two
{
    // Exported types
    export_ template <> TOY_BLOCK_EXPORT Type& type<toy::MatterState>();
    
    export_ template <> TOY_BLOCK_EXPORT Type& type<stl::span<toy::Element*>>();
    export_ template <> TOY_BLOCK_EXPORT Type& type<stl::vector<toy::Block*>>();
    export_ template <> TOY_BLOCK_EXPORT Type& type<stl::vector<toy::Sector*>>();
    
    export_ template <> TOY_BLOCK_EXPORT Type& type<two::ComponentHandle<toy::Block>>();
    export_ template <> TOY_BLOCK_EXPORT Type& type<two::ComponentHandle<toy::Chunk>>();
    export_ template <> TOY_BLOCK_EXPORT Type& type<two::ComponentHandle<toy::Heap>>();
    export_ template <> TOY_BLOCK_EXPORT Type& type<two::ComponentHandle<toy::Sector>>();
    export_ template <> TOY_BLOCK_EXPORT Type& type<two::ComponentHandle<toy::Tileblock>>();
    export_ template <> TOY_BLOCK_EXPORT Type& type<two::vector2d<toy::Block*>>();
    export_ template <> TOY_BLOCK_EXPORT Type& type<toy::Block>();
    export_ template <> TOY_BLOCK_EXPORT Type& type<toy::Chunk>();
    export_ template <> TOY_BLOCK_EXPORT Type& type<toy::Element>();
    export_ template <> TOY_BLOCK_EXPORT Type& type<toy::Heap>();
    export_ template <> TOY_BLOCK_EXPORT Type& type<toy::Earth>();
    export_ template <> TOY_BLOCK_EXPORT Type& type<toy::Sector>();
    export_ template <> TOY_BLOCK_EXPORT Type& type<toy::Tileblock>();
}


#include <stl/map.h>


namespace toy
{
	export_ TOY_BLOCK_EXPORT void paint_heap(Gnode& parent, Heap& heap);
	export_ TOY_BLOCK_EXPORT void paint_block(Gnode& parent, Block& block, Material* material);
	export_ TOY_BLOCK_EXPORT void paint_block(Gnode& parent, Block& block);
	export_ TOY_BLOCK_EXPORT void paint_block_wireframe(Gnode& parent, Block& block, const Colour& colour);

	struct BlockState : public NodeState
	{
		size_t m_updated = 0;
		map<Element*, object<Model>> m_models;
	};

	export_ TOY_BLOCK_EXPORT void update_block_geometry(GfxSystem& gfx, Block& block, BlockState& state);
}

