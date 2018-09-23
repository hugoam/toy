//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <proto/Proto.h>
#include <procgen-gfx/Wfc/Tileblock.h>
#include <core/WorldPage/WorldPage.h>
//#include <core/WorldPage/BufferPage.h>
#include <core/Navmesh/Navmesh.h>
#include <block/Forward.h>
#include <block/Element.h>

#ifndef MUD_CPP_20
#include <vector>
#endif

#ifdef TOY_ECS
namespace mud
{
	template <> struct TypedBuffer<toy::Sector> { using type = ComponentBuffer<toy::Sector*>; static size_t index() { return 10; } };
	template <> struct TypedBuffer<toy::TileBlock> { using type = ComponentBuffer<toy::TileBlock*>; static size_t index() { return 11; } };
}
#endif

using namespace mud; namespace toy
{
	typedef std::vector<Chunk*> ChunkVector;

	class refl_ TOY_BLOCK_EXPORT Sector : public Entity
	{
	public:
		constr_ Sector(HSpatial parent, const vec3& position, const uvec3& coordinate, const vec3& size);

		comp_ attr_ CSpatial m_spatial;
		//comp_ attr_ CEmitter m_emitter;
		comp_ attr_ CWorldPage m_world_page;
		//comp_ attr_ CBufferPage m_buffer_page;
		comp_ attr_ CNavblock m_navblock;

		attr_ uvec3 m_coordinate;
		attr_ vec3 m_size;

		attr_ Block* m_block;

		std::vector<Heap*> m_heaps;
	};

	class refl_ TOY_BLOCK_EXPORT TileBlock : public Entity
	{
	public:
		constr_ TileBlock(HSpatial parent, const vec3& position, const uvec3& size, const vec3& tile_scale, WaveTileset& tileset);
		~TileBlock();

		comp_ attr_ CSpatial m_spatial;
		//comp_ attr_ CEmitter m_emitter;
		comp_ attr_ CWorldPage m_world_page;
		comp_ attr_ CNavblock m_navblock;

		attr_ WfcBlock m_wfc_block;
		attr_ bool m_setup = false;
		attr_ bool m_populated = false;

		std::function<void(TileBlock&)> m_on_setup;

		void next_frame(WorldPage& world_page, size_t frame, size_t delta);

		bool contains(const vec3& position);
	};

	TOY_BLOCK_EXPORT func_ TileBlock& generate_block(GfxSystem& gfx_system, WaveTileset& tileset, HSpatial origin, const ivec2& coord, const uvec3& block_subdiv, const vec3& tile_scale, bool from_file = true);

	TOY_BLOCK_EXPORT func_ void build_block_geometry(Scene& scene, WorldPage& page, TileBlock& block);

	TOY_BLOCK_EXPORT func_ void index_blocks(const ivec3& grid_size, Grid<Block*>& grid, const std::vector<Block*>& blocks, const std::vector<Sector*>& sectors);
}
