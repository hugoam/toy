#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module ._minimal;
#else
#include <minimal/Types.h>
#include <minimal/Api.h>
#include <type/Vector.h>
#endif

namespace mud
{
    // Exported types
    
    
    template <> _MINIMAL_EXPORT Type& type<Bullet>() { static Type ty("Bullet", sizeof(Bullet)); return ty; }
    template <> _MINIMAL_EXPORT Type& type<mud::ComponentHandle<Bullet>>() { static Type ty("ComponentHandle<Bullet>", sizeof(mud::ComponentHandle<Bullet>)); return ty; }
    template <> _MINIMAL_EXPORT Type& type<mud::ComponentHandle<Crate>>() { static Type ty("ComponentHandle<Crate>", sizeof(mud::ComponentHandle<Crate>)); return ty; }
    template <> _MINIMAL_EXPORT Type& type<mud::ComponentHandle<Human>>() { static Type ty("ComponentHandle<Human>", sizeof(mud::ComponentHandle<Human>)); return ty; }
    template <> _MINIMAL_EXPORT Type& type<Crate>() { static Type ty("Crate", sizeof(Crate)); return ty; }
    template <> _MINIMAL_EXPORT Type& type<Human>() { static Type ty("Human", sizeof(Human)); return ty; }
    template <> _MINIMAL_EXPORT Type& type<Player>() { static Type ty("Player", sizeof(Player)); return ty; }
}
