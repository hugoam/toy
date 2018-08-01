

#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module ._platform;
#else
#include <platform/Types.h>
#include <platform/Api.h>
#include <obj/Vector.h>
//#include <proto/Proto.h>
#endif

namespace mud
{
    // Exported types
    template <> _PLATFORM_EXPORT Type& type<Faction>() { static Type ty("Faction"); return ty; }
    
    template <> _PLATFORM_EXPORT Type& type<Aim>() { static Type ty("Aim"); return ty; }
    template <> _PLATFORM_EXPORT Type& type<Player>() { static Type ty("Player"); return ty; }
    template <> _PLATFORM_EXPORT Type& type<Stance>() { static Type ty("Stance"); return ty; }
    template <> _PLATFORM_EXPORT Type& type<Lamp>() { static Type ty("Lamp", type<mud::Complex>()); return ty; }
    template <> _PLATFORM_EXPORT Type& type<TileWorld>() { static Type ty("TileWorld", type<mud::Complex>()); return ty; }
    template <> _PLATFORM_EXPORT Type& type<Bullet>() { static Type ty("Bullet", type<mud::Complex>()); return ty; }
    template <> _PLATFORM_EXPORT Type& type<Crate>() { static Type ty("Crate", type<mud::Complex>()); return ty; }
    template <> _PLATFORM_EXPORT Type& type<Human>() { static Type ty("Human", type<mud::Complex>()); return ty; }
}
