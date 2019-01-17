#pragma once

#include <shell/Forward.h>

#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#include <type/Type.h>
#include <type/Vector.h>
#endif

#ifndef MUD_MODULES
#include <core/Types.h>
#include <visu/Types.h>
#include <edit/Types.h>
#include <block/Types.h>
#include <pool/Types.h>
#include <refl/Types.h>
#include <ecs/Types.h>
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
#include <bgfx/Types.h>
#include <gfx/Types.h>
#include <gfx-pbr/Types.h>
#include <gfx-obj/Types.h>
#include <gltf/Types.h>
#include <gfx-gltf/Types.h>
#include <gfx-ui/Types.h>
#include <gfx-edit/Types.h>
#include <tool/Types.h>
#include <wfc-gfx/Types.h>
#include <frame/Types.h>
#endif

#ifndef MUD_CPP_20
#include <stl/string.h>
#include <cstdint>
#include <stl/vector.h>
#endif


namespace mud
{
    // Exported types
    export_ template <> TOY_SHELL_EXPORT Type& type<toy::GameMode>();
    
    export_ template <> TOY_SHELL_EXPORT Type& type<toy::Game>();
    export_ template <> TOY_SHELL_EXPORT Type& type<toy::GameModule>();
    export_ template <> TOY_SHELL_EXPORT Type& type<toy::GameShell>();
    export_ template <> TOY_SHELL_EXPORT Type& type<toy::GameModuleBind>();
    export_ template <> TOY_SHELL_EXPORT Type& type<toy::GameScene>();
    
    export_ template struct TOY_SHELL_EXPORT Typed<vector<toy::Game*>>;
    export_ template struct TOY_SHELL_EXPORT Typed<vector<toy::GameModule*>>;
    export_ template struct TOY_SHELL_EXPORT Typed<vector<toy::GameShell*>>;
    export_ template struct TOY_SHELL_EXPORT Typed<vector<toy::GameModuleBind*>>;
    export_ template struct TOY_SHELL_EXPORT Typed<vector<toy::GameScene*>>;
}
