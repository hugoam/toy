//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <stl/vector.h>
#include <stl/string.h>
#include <infra/Global.h>
#include <type/Proto.h>
#include <math/Colour.h>
#include <math/Grid.h>
#include <core/Spatial/Spatial.h>
#include <core/Physic/Scope.h>
#include <block/Forward.h>

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
