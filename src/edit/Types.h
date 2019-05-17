#pragma once

#include <stdint.h>
#include <stl/string.h>
#include <stl/vector.h>
#include <edit/Forward.h>

#if !defined TWO_MODULES || defined TWO_TYPE_LIB
#include <type/Type.h>
#endif

#ifndef TWO_MODULES
#include <type/Types.h>
#include <ui/Types.h>
#include <tool/Types.h>
#include <util/Types.h>
#include <core/Types.h>
#include <visu/Types.h>
#endif


namespace two
{
    // Exported types
    
    
    export_ template <> TOY_EDIT_EXPORT Type& type<toy::Edit>();
    export_ template <> TOY_EDIT_EXPORT Type& type<toy::Clone>();
    export_ template <> TOY_EDIT_EXPORT Type& type<toy::Cut>();
    export_ template <> TOY_EDIT_EXPORT Type& type<toy::Paste>();
    export_ template <> TOY_EDIT_EXPORT Type& type<toy::Toolbox>();
    export_ template <> TOY_EDIT_EXPORT Type& type<toy::DynamicToolbox>();
    export_ template <> TOY_EDIT_EXPORT Type& type<toy::Toolbelt>();
    export_ template <> TOY_EDIT_EXPORT Type& type<toy::PlayTool>();
    export_ template <> TOY_EDIT_EXPORT Type& type<toy::RunTool>();
    export_ template <> TOY_EDIT_EXPORT Type& type<toy::ActionGroup>();
    export_ template <> TOY_EDIT_EXPORT Type& type<toy::GraphicsDebug>();
    export_ template <> TOY_EDIT_EXPORT Type& type<toy::Editor>();
}
