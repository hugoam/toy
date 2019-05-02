#include <infra/Cpp20.h>

#ifdef TWO_MODULES
module ._minimal;
#else
#include <minimal/Types.h>
#include <minimal/Api.h>
#include <type/Vector.h>
#endif

namespace two
{
    // Exported types
    
    
    template <> _MINIMAL_EXPORT Type& type<two::ComponentHandle<Bullet>>() { static Type ty("ComponentHandle<Bullet>", sizeof(two::ComponentHandle<Bullet>)); return ty; }
    template <> _MINIMAL_EXPORT Type& type<two::ComponentHandle<Human>>() { static Type ty("ComponentHandle<Human>", sizeof(two::ComponentHandle<Human>)); return ty; }
    template <> _MINIMAL_EXPORT Type& type<two::ComponentHandle<Crate>>() { static Type ty("ComponentHandle<Crate>", sizeof(two::ComponentHandle<Crate>)); return ty; }
    template <> _MINIMAL_EXPORT Type& type<Bullet>() { static Type ty("Bullet", sizeof(Bullet)); return ty; }
    template <> _MINIMAL_EXPORT Type& type<Human>() { static Type ty("Human", sizeof(Human)); return ty; }
    template <> _MINIMAL_EXPORT Type& type<Crate>() { static Type ty("Crate", sizeof(Crate)); return ty; }
    template <> _MINIMAL_EXPORT Type& type<Player>() { static Type ty("Player", sizeof(Player)); return ty; }
}
