#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module ._godot;
#else
#include <godot/Types.h>
#include <godot/Api.h>
#include <type/Vector.h>
#endif

namespace mud
{
    // Exported types
    template <> _GODOT_EXPORT Type& type<Faction>() { static Type ty("Faction", sizeof(Faction)); return ty; }
    
    
    template <> _GODOT_EXPORT Type& type<Aim>() { static Type ty("Aim", sizeof(Aim)); return ty; }
    template <> _GODOT_EXPORT Type& type<Bullet>() { static Type ty("Bullet", sizeof(Bullet)); return ty; }
    template <> _GODOT_EXPORT Type& type<mud::ComponentHandle<Bullet>>() { static Type ty("ComponentHandle<Bullet>", sizeof(mud::ComponentHandle<Bullet>)); return ty; }
    template <> _GODOT_EXPORT Type& type<mud::ComponentHandle<Crate>>() { static Type ty("ComponentHandle<Crate>", sizeof(mud::ComponentHandle<Crate>)); return ty; }
    template <> _GODOT_EXPORT Type& type<mud::ComponentHandle<Human>>() { static Type ty("ComponentHandle<Human>", sizeof(mud::ComponentHandle<Human>)); return ty; }
    template <> _GODOT_EXPORT Type& type<mud::ComponentHandle<Lamp>>() { static Type ty("ComponentHandle<Lamp>", sizeof(mud::ComponentHandle<Lamp>)); return ty; }
    template <> _GODOT_EXPORT Type& type<Crate>() { static Type ty("Crate", sizeof(Crate)); return ty; }
    template <> _GODOT_EXPORT Type& type<Human>() { static Type ty("Human", sizeof(Human)); return ty; }
    template <> _GODOT_EXPORT Type& type<Lamp>() { static Type ty("Lamp", sizeof(Lamp)); return ty; }
    template <> _GODOT_EXPORT Type& type<Player>() { static Type ty("Player", sizeof(Player)); return ty; }
    template <> _GODOT_EXPORT Type& type<Stance>() { static Type ty("Stance", sizeof(Stance)); return ty; }
    template <> _GODOT_EXPORT Type& type<WorldBlock>() { static Type ty("WorldBlock", sizeof(WorldBlock)); return ty; }
}
