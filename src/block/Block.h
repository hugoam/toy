//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <proto/Proto.h>
#include <math/Vec.h>
#include <math/Grid.h>
#include <core/Entity/Entity.h>
#include <core/Physic/Scope.h>
#include <block/Forward.h>

#ifndef MUD_CPP_20
#include <vector>
#include <memory>
#endif

namespace mud
{
	template struct refl_ struct_ TOY_BLOCK_EXPORT Grid<toy::Block*>;
}

using namespace mud; namespace toy
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
	TOY_BLOCK_EXPORT func_ void paint_block_elements(Block& block, Image256& image, array<Element*> elements);

	class refl_ TOY_BLOCK_EXPORT Block : public Complex
	{
	public:
		constr_ Block(Id id, Entity& parent, const vec3& position, Block* parentblock, size_t index, const vec3& size);

		comp_ attr_ Entity m_entity;
		comp_ attr_ Emitter m_emitter;

		attr_ link_ Block* m_parentblock;
		attr_ size_t m_index;
		attr_ vec3 m_size;
		attr_ size_t m_updated = 0;

		size_t m_depth = 0;

		bool m_subdived = false;

		Grid<Element*> m_chunks;
		Grid<Block*> m_subblocks;

		Block* m_neighbours[6] = { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr };

		meth_ void subdivide();

		meth_ void reset();
		meth_ void chunk(size_t x, size_t y, size_t z, Element& element);
		meth_ void commit();

		void subdivide_to(size_t depth);

		size_t depth();

		vec3 min();
		vec3 max();
		vec3 coordinates();

		size_t subdiv();
		vec3 chunk_size();

		Sector& sector();

		vec3 local_block_coord(size_t index);
		vec3 local_block_coord(Block& child);
		vec3 block_coord(Block& child);

		vec3 local_chunk_coord(size_t index);
		vec3 chunk_coord(size_t index);

		vec3 chunk_position(size_t index);

		Hunk hunk_at(size_t index);

		Hunk neighbour(size_t index, Side side);
		Hunk neighbour(Hunk& hunk, Side side);

	protected:
		EmitterScope& m_scope;
	};
}
