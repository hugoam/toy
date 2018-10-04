

#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module ._minimal;
#else
#include <minimal/Types.h>
#include <minimal/Api.h>
#include <type/Vector.h>
//#include <ecs/Proto.h>
#endif

namespace mud
{
    // Exported types
    
    template <> _MINIMAL_EXPORT Type& type<Player>() { static Type ty("Player"); return ty; }
    template <> _MINIMAL_EXPORT Type& type<Bullet>() { static Type ty("Bullet"); return ty; }
    template <> _MINIMAL_EXPORT Type& type<Crate>() { static Type ty("Crate"); return ty; }
    template <> _MINIMAL_EXPORT Type& type<Human>() { static Type ty("Human"); return ty; }
}
