#pragma once

#include <stdint.h>
#include <stl/string.h>
#include <stl/vector.h>
#include <util/Forward.h>

#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#include <type/Type.h>
#endif

#ifndef MUD_MODULES
#include <type/Types.h>
#include <math/Types.h>
#endif


namespace mud
{
    // Exported types
    
    
    export_ template <> TOY_UTIL_EXPORT Type& type<toy::Procedure>();
    export_ template <> TOY_UTIL_EXPORT Type& type<toy::ProcedureType>();
}
