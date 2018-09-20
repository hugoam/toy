#pragma once

#include <util/Forward.h>

#if !defined MUD_MODULES || defined MUD_OBJ_LIB
#include <obj/Type.h>
#include <obj/Vector.h>
#endif

#ifndef MUD_MODULES
#include <obj/Types.h>
#include <math/Types.h>
#endif

#ifndef MUD_CPP_20
#include <string>
#include <cstdint>
#include <vector>
#endif


namespace mud
{
    // Exported types
    
    export_ template <> TOY_UTIL_EXPORT Type& type<toy::Procedure>();
    export_ template <> TOY_UTIL_EXPORT Type& type<toy::ProcedureType>();
    
	export_ template struct TOY_UTIL_EXPORT Typed<std::vector<toy::Procedure*>>;
	export_ template struct TOY_UTIL_EXPORT Typed<std::vector<toy::ProcedureType*>>;
}
