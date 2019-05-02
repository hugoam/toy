//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <stl/vector.h>
#include <stl/memory.h>
#include <type/Proto.h>
#include <math/Vec.h>
#include <math/Grid.h>
#include <core/Spatial/Spatial.h>
#include <core/Physic/Scope.h>
#include <block/Forward.h>
#include <block/Handles.h>

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
