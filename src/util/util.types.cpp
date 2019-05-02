#include <infra/Cpp20.h>

#ifdef TWO_MODULES
module toy.util;
#else
#include <util/Types.h>
#include <util/Api.h>
#include <type/Vector.h>
#endif

namespace two
{
    // Exported types
    
    
    template <> TOY_UTIL_EXPORT Type& type<toy::ProcedureType>() { static Type ty("ProcedureType", sizeof(toy::ProcedureType)); return ty; }
    template <> TOY_UTIL_EXPORT Type& type<toy::Procedure>() { static Type ty("Procedure", sizeof(toy::Procedure)); return ty; }
}
