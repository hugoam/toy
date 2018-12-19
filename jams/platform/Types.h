#pragma once

#include <platform/Forward.h>

#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#include <type/Type.h>
#include <type/Vector.h>
#endif

#ifndef MUD_MODULES
#include <infra/Types.h>
#include <type/Types.h>
#include <pool/Types.h>
#include <refl/Types.h>
#include <ecs/Types.h>
#include <tree/Types.h>
#include <srlz/Types.h>
#include <math/Types.h>
#include <geom/Types.h>
#include <noise/Types.h>
#include <wfc/Types.h>
#include <fract/Types.h>
#include <lang/Types.h>
#include <ctx/Types.h>
#include <ui/Types.h>
#include <uio/Types.h>
#include <snd/Types.h>
#include <ctx-glfw/Types.h>
#include <ui-vg/Types.h>
#include <bgfx/Types.h>
#include <gfx/Types.h>
#include <gfx-pbr/Types.h>
#include <gfx-obj/Types.h>
#include <gfx-gltf/Types.h>
#include <gfx-ui/Types.h>
#include <tool/Types.h>
#include <wfc-gfx/Types.h>
#include <util/Types.h>
#include <core/Types.h>
#include <visu/Types.h>
#include <edit/Types.h>
#include <block/Types.h>
#include <shell/Types.h>
#endif

#ifndef MUD_CPP_20
#include <string>
#include <cstdint>
#include <vector>
#endif


namespace mud
{
    // Exported types
    export_ template <> _PLATFORM_EXPORT Type& type<Faction>();
    
    export_ template <> _PLATFORM_EXPORT Type& type<Aim>();
    export_ template <> _PLATFORM_EXPORT Type& type<Player>();
    export_ template <> _PLATFORM_EXPORT Type& type<Stance>();
    export_ template <> _PLATFORM_EXPORT Type& type<Lamp>();
    export_ template <> _PLATFORM_EXPORT Type& type<TileWorld>();
    export_ template <> _PLATFORM_EXPORT Type& type<Bullet>();
    export_ template <> _PLATFORM_EXPORT Type& type<Crate>();
    export_ template <> _PLATFORM_EXPORT Type& type<Human>();
    
	export_ template struct _PLATFORM_EXPORT Typed<std::vector<Aim*>>;
	export_ template struct _PLATFORM_EXPORT Typed<std::vector<Player*>>;
	export_ template struct _PLATFORM_EXPORT Typed<std::vector<Stance*>>;
	export_ template struct _PLATFORM_EXPORT Typed<std::vector<Lamp*>>;
	export_ template struct _PLATFORM_EXPORT Typed<std::vector<TileWorld*>>;
	export_ template struct _PLATFORM_EXPORT Typed<std::vector<Bullet*>>;
	export_ template struct _PLATFORM_EXPORT Typed<std::vector<Crate*>>;
	export_ template struct _PLATFORM_EXPORT Typed<std::vector<Human*>>;
}
