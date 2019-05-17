#pragma once

#include <stdint.h>
#include <stl/string.h>
#include <stl/vector.h>
#include <shell/Forward.h>

#if !defined TWO_MODULES || defined TWO_TYPE_LIB
#include <type/Type.h>
#endif

#ifndef TWO_MODULES
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
#include <core/Types.h>
#include <visu/Types.h>
#include <edit/Types.h>
#include <block/Types.h>
#endif


namespace two
{
    // Exported types
    export_ template <> TOY_SHELL_EXPORT Type& type<toy::GameMode>();
    
    
    export_ template <> TOY_SHELL_EXPORT Type& type<toy::GameScene>();
    export_ template <> TOY_SHELL_EXPORT Type& type<toy::Game>();
    export_ template <> TOY_SHELL_EXPORT Type& type<toy::GameModule>();
    export_ template <> TOY_SHELL_EXPORT Type& type<toy::GameModuleBind>();
    export_ template <> TOY_SHELL_EXPORT Type& type<toy::GameWindow>();
    export_ template <> TOY_SHELL_EXPORT Type& type<toy::GameShell>();
}
