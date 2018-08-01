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
    
    export_ template <> TOY_UTIL_EXPORT Type& type<toy::Loader>();
    export_ template <> TOY_UTIL_EXPORT Type& type<toy::Procedure>();
    export_ template <> TOY_UTIL_EXPORT Type& type<toy::ProcedureType>();
    export_ template <> TOY_UTIL_EXPORT Type& type<toy::LinkedLoader>();
    export_ template <> TOY_UTIL_EXPORT Type& type<toy::SequenceLoader>();
    export_ template <> TOY_UTIL_EXPORT Type& type<toy::StructureLoader>();
    export_ template <> TOY_UTIL_EXPORT Type& type<toy::TypeLoader>();
    export_ template <> TOY_UTIL_EXPORT Type& type<toy::MemberLoader>();
    export_ template <> TOY_UTIL_EXPORT Type& type<toy::ObjectLoader>();
    export_ template <> TOY_UTIL_EXPORT Type& type<toy::OwnedLoader>();
    export_ template <> TOY_UTIL_EXPORT Type& type<toy::PartLoader>();
    
	export_ template struct TOY_UTIL_EXPORT Typed<std::vector<toy::Loader*>>;
	export_ template struct TOY_UTIL_EXPORT Typed<std::vector<toy::Procedure*>>;
	export_ template struct TOY_UTIL_EXPORT Typed<std::vector<toy::ProcedureType*>>;
	export_ template struct TOY_UTIL_EXPORT Typed<std::vector<toy::LinkedLoader*>>;
	export_ template struct TOY_UTIL_EXPORT Typed<std::vector<toy::SequenceLoader*>>;
	export_ template struct TOY_UTIL_EXPORT Typed<std::vector<toy::StructureLoader*>>;
	export_ template struct TOY_UTIL_EXPORT Typed<std::vector<toy::TypeLoader*>>;
	export_ template struct TOY_UTIL_EXPORT Typed<std::vector<toy::MemberLoader*>>;
	export_ template struct TOY_UTIL_EXPORT Typed<std::vector<toy::ObjectLoader*>>;
	export_ template struct TOY_UTIL_EXPORT Typed<std::vector<toy::OwnedLoader*>>;
	export_ template struct TOY_UTIL_EXPORT Typed<std::vector<toy::PartLoader*>>;
}
