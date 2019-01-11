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
    template <> _GODOT_EXPORT Type& type<Crate>() { static Type ty("Crate", sizeof(Crate)); return ty; }
    template <> _GODOT_EXPORT Type& type<Human>() { static Type ty("Human", sizeof(Human)); return ty; }
    template <> _GODOT_EXPORT Type& type<Lamp>() { static Type ty("Lamp", sizeof(Lamp)); return ty; }
    template <> _GODOT_EXPORT Type& type<Player>() { static Type ty("Player", sizeof(Player)); return ty; }
    template <> _GODOT_EXPORT Type& type<Stance>() { static Type ty("Stance", sizeof(Stance)); return ty; }
    template <> _GODOT_EXPORT Type& type<WorldBlock>() { static Type ty("WorldBlock", sizeof(WorldBlock)); return ty; }
    template <> _GODOT_EXPORT Type& type<ComponentHandle<Bullet>>() { static Type ty("ComponentHandle<Bullet>", type<mud::Entity>(), sizeof(ComponentHandle<Bullet>)); return ty; }
    template <> _GODOT_EXPORT Type& type<ComponentHandle<Crate>>() { static Type ty("ComponentHandle<Crate>", type<mud::Entity>(), sizeof(ComponentHandle<Crate>)); return ty; }
    template <> _GODOT_EXPORT Type& type<ComponentHandle<Human>>() { static Type ty("ComponentHandle<Human>", type<mud::Entity>(), sizeof(ComponentHandle<Human>)); return ty; }
    template <> _GODOT_EXPORT Type& type<ComponentHandle<Lamp>>() { static Type ty("ComponentHandle<Lamp>", type<mud::Entity>(), sizeof(ComponentHandle<Lamp>)); return ty; }
}
