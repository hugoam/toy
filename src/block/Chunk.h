//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <proto/Entity.h>
#include <math/Math.h>
#include <block/Forward.h>
#include <core/Entity/Entity.h>

using namespace mud; namespace toy
{
	class refl_ TOY_BLOCK_EXPORT Chunk : public Entity
	{
	public:
		constr_ Chunk(HSpatial parent, Block& block, const vec3& position, size_t index, Element& element, float size);

		comp_ attr_ CSpatial m_spatial;

		attr_ size_t m_index;
		attr_ Block& m_block;
		attr_ Element& m_element;
		attr_ float m_size;

		Chunk* neighbour(Side side);
		bool boundary(Side side);
	};
}
