#pragma once

#include <stdint.h>
#include <stl/string.h>
#include <stl/vector.h>
#include <visu/Forward.h>

#if !defined TWO_MODULES || defined TWO_TYPE_LIB
#include <type/Type.h>
#endif

#ifndef TWO_MODULES
#include <type/Types.h>
#include <gfx/Types.h>
#include <util/Types.h>
#include <core/Types.h>
#endif


namespace two
{
    // Exported types
    
    
    export_ template <> TOY_VISU_EXPORT Type& type<toy::PhysicDebugDraw>();
    export_ template <> TOY_VISU_EXPORT Type& type<toy::VisuScene>();
}
