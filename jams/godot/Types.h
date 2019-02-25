#pragma once

#include <stdint.h>
#include <stl/string.h>
#include <stl/vector.h>
#include <godot/Forward.h>

#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#include <type/Type.h>
#endif

#ifndef MUD_MODULES
#include <infra/Types.h>
#include <jobs/Types.h>
#include <type/Types.h>
#include <tree/Types.h>
#include <pool/Types.h>
#include <refl/Types.h>
#include <ecs/Types.h>
#include <srlz/Types.h>
#include <math/Types.h>
#include <geom/Types.h>
#include <lang/Types.h>
#include <ctx/Types.h>
#include <ui/Types.h>
#include <uio/Types.h>
#include <bgfx/Types.h>
#include <gfx/Types.h>
#include <gfx-ui/Types.h>
#include <frame/Types.h>
#include <util/Types.h>
#include <core/Types.h>
#include <visu/Types.h>
#include <edit/Types.h>
#include <block/Types.h>
#include <shell/Types.h>
#endif


namespace mud
{
    // Exported types
    export_ template <> _GODOT_EXPORT Type& type<Faction>();
    
    
    export_ template <> _GODOT_EXPORT Type& type<Aim>();
    export_ template <> _GODOT_EXPORT Type& type<Bullet>();
    export_ template <> _GODOT_EXPORT Type& type<mud::ComponentHandle<Bullet>>();
    export_ template <> _GODOT_EXPORT Type& type<mud::ComponentHandle<Crate>>();
    export_ template <> _GODOT_EXPORT Type& type<mud::ComponentHandle<Human>>();
    export_ template <> _GODOT_EXPORT Type& type<mud::ComponentHandle<Lamp>>();
    export_ template <> _GODOT_EXPORT Type& type<Crate>();
    export_ template <> _GODOT_EXPORT Type& type<Human>();
    export_ template <> _GODOT_EXPORT Type& type<Lamp>();
    export_ template <> _GODOT_EXPORT Type& type<Player>();
    export_ template <> _GODOT_EXPORT Type& type<Stance>();
    export_ template <> _GODOT_EXPORT Type& type<WorldBlock>();
}
