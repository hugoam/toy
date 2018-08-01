

#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module ._minimal;
#else
#include <minimal/Types.h>
#include <minimal/Api.h>
#include <obj/Vector.h>
//#include <proto/Proto.h>
#endif

namespace mud
{
    // Exported types
    
    template <> _MINIMAL_EXPORT Type& type<Player>() { static Type ty("Player"); return ty; }
    template <> _MINIMAL_EXPORT Type& type<Bullet>() { static Type ty("Bullet", type<mud::Complex>()); return ty; }
    template <> _MINIMAL_EXPORT Type& type<Crate>() { static Type ty("Crate", type<mud::Complex>()); return ty; }
    template <> _MINIMAL_EXPORT Type& type<Human>() { static Type ty("Human", type<mud::Complex>()); return ty; }
}
