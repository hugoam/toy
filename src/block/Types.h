#pragma once

#include <block/Forward.h>

#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#include <type/Type.h>
#include <type/Vector.h>
#endif

#ifndef MUD_MODULES
#include <type/Types.h>
#include <math/Types.h>
#include <wfc-gfx/Types.h>
#include <core/Types.h>
#include <visu/Types.h>
#include <edit/Types.h>
#endif

#ifndef MUD_CPP_20
#include <string>
#include <cstdint>
#include <vector>
#endif


namespace mud
{
    // Exported types
    export_ template <> TOY_BLOCK_EXPORT Type& type<toy::MatterState>();
    
    export_ template <> TOY_BLOCK_EXPORT Type& type<toy::Element>();
    export_ template <> TOY_BLOCK_EXPORT Type& type<mud::Grid<toy::Block*>>();
    export_ template <> TOY_BLOCK_EXPORT Type& type<toy::Block>();
    export_ template <> TOY_BLOCK_EXPORT Type& type<toy::Chunk>();
    export_ template <> TOY_BLOCK_EXPORT Type& type<toy::Heap>();
    export_ template <> TOY_BLOCK_EXPORT Type& type<toy::Sector>();
    export_ template <> TOY_BLOCK_EXPORT Type& type<toy::Tileblock>();
    export_ template <> TOY_BLOCK_EXPORT Type& type<toy::Earth>();
    
	export_ template struct TOY_BLOCK_EXPORT Typed<std::vector<toy::Element*>>;
	export_ template struct TOY_BLOCK_EXPORT Typed<std::vector<mud::Grid<toy::Block*>*>>;
	export_ template struct TOY_BLOCK_EXPORT Typed<std::vector<toy::Block*>>;
	export_ template struct TOY_BLOCK_EXPORT Typed<std::vector<toy::Chunk*>>;
	export_ template struct TOY_BLOCK_EXPORT Typed<std::vector<toy::Heap*>>;
	export_ template struct TOY_BLOCK_EXPORT Typed<std::vector<toy::Sector*>>;
	export_ template struct TOY_BLOCK_EXPORT Typed<std::vector<toy::Tileblock*>>;
	export_ template struct TOY_BLOCK_EXPORT Typed<std::vector<toy::Earth*>>;
}
