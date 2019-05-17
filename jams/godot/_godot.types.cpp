#include <infra/Cpp20.h>

#ifdef TWO_MODULES
module ._godot;
#else
#include <godot/Types.h>
#include <godot/Api.h>
#include <type/Vector.h>
#endif

namespace two
{
    // Exported types
    template <> _GODOT_EXPORT Type& type<Faction>() { static Type ty("Faction", sizeof(Faction)); return ty; }
    
    
    template <> _GODOT_EXPORT Type& type<two::ComponentHandle<Bullet>>() { static Type ty("ComponentHandle<Bullet>", sizeof(two::ComponentHandle<Bullet>)); return ty; }
    template <> _GODOT_EXPORT Type& type<two::ComponentHandle<Human>>() { static Type ty("ComponentHandle<Human>", sizeof(two::ComponentHandle<Human>)); return ty; }
    template <> _GODOT_EXPORT Type& type<two::ComponentHandle<Lamp>>() { static Type ty("ComponentHandle<Lamp>", sizeof(two::ComponentHandle<Lamp>)); return ty; }
    template <> _GODOT_EXPORT Type& type<two::ComponentHandle<Crate>>() { static Type ty("ComponentHandle<Crate>", sizeof(two::ComponentHandle<Crate>)); return ty; }
    template <> _GODOT_EXPORT Type& type<Bullet>() { static Type ty("Bullet", sizeof(Bullet)); return ty; }
    template <> _GODOT_EXPORT Type& type<Aim>() { static Type ty("Aim", sizeof(Aim)); return ty; }
    template <> _GODOT_EXPORT Type& type<Stance>() { static Type ty("Stance", sizeof(Stance)); return ty; }
    template <> _GODOT_EXPORT Type& type<Human>() { static Type ty("Human", sizeof(Human)); return ty; }
    template <> _GODOT_EXPORT Type& type<Lamp>() { static Type ty("Lamp", sizeof(Lamp)); return ty; }
    template <> _GODOT_EXPORT Type& type<Crate>() { static Type ty("Crate", sizeof(Crate)); return ty; }
    template <> _GODOT_EXPORT Type& type<WorldBlock>() { static Type ty("WorldBlock", sizeof(WorldBlock)); return ty; }
    template <> _GODOT_EXPORT Type& type<Player>() { static Type ty("Player", sizeof(Player)); return ty; }
}
