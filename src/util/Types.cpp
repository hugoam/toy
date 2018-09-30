

#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module toy.util;
#else
#include <util/Types.h>
#include <util/Api.h>
#include <type/Vector.h>
//#include <ecs/Proto.h>
#endif

namespace mud
{
    // Exported types
    
    template <> TOY_UTIL_EXPORT Type& type<toy::Procedure>() { static Type ty("Procedure"); return ty; }
    template <> TOY_UTIL_EXPORT Type& type<toy::ProcedureType>() { static Type ty("ProcedureType"); return ty; }
}
