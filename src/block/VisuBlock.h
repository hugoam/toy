//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <stl/map.h>
#include <visu/VisuScene.h>
#include <block/Forward.h>
#include <block/Block.h>

#include <gfx/Node3.h>
#include <gfx/Light.h>

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
