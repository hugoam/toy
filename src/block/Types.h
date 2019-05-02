#pragma once

#include <stdint.h>
#include <stl/string.h>
#include <stl/vector.h>
#include <block/Forward.h>

#if !defined TWO_MODULES || defined TWO_TYPE_LIB
#include <type/Type.h>
#endif

#ifndef TWO_MODULES
#include <type/Types.h>
#include <math/Types.h>
#include <wfc-gfx/Types.h>
#include <core/Types.h>
#include <visu/Types.h>
#include <edit/Types.h>
#endif

#include <block/Structs.h>

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
