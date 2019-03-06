//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <ecs/Entity.h>
#include <block/Forward.h>
#include <block/Handles.h>
#include <core/Spatial/Spatial.h>
#include <ecs/ECS.h>

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
