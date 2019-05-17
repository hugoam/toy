

#pragma once

#include <infra/Config.h>

#include <type/Forward.h>
#include <math/Forward.h>
#include <wfc-gfx/Forward.h>
#include <core/Forward.h>
#include <visu/Forward.h>
#include <edit/Forward.h>

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
