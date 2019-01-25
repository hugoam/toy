#pragma once

#include <edit/Forward.h>

#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#include <type/Type.h>
#include <type/Vector.h>
#endif

#ifndef MUD_MODULES
#include <type/Types.h>
#include <ui/Types.h>
#include <tool/Types.h>
#include <util/Types.h>
#include <core/Types.h>
#include <visu/Types.h>
#endif

#ifndef MUD_CPP_20
#include <stl/string.h>
#include <stl/vector.h>
#include <cstdint>
#endif


namespace mud
{
    // Exported types
    
    export_ template <> TOY_EDIT_EXPORT Type& type<toy::ActionGroup>();
    export_ template <> TOY_EDIT_EXPORT Type& type<toy::Clone>();
    export_ template <> TOY_EDIT_EXPORT Type& type<toy::Cut>();
    export_ template <> TOY_EDIT_EXPORT Type& type<toy::Edit>();
    export_ template <> TOY_EDIT_EXPORT Type& type<toy::GraphicsDebug>();
    export_ template <> TOY_EDIT_EXPORT Type& type<toy::Paste>();
    export_ template <> TOY_EDIT_EXPORT Type& type<toy::Toolbelt>();
    export_ template <> TOY_EDIT_EXPORT Type& type<toy::Toolbox>();
    export_ template <> TOY_EDIT_EXPORT Type& type<toy::DynamicToolbox>();
    export_ template <> TOY_EDIT_EXPORT Type& type<toy::Editor>();
    export_ template <> TOY_EDIT_EXPORT Type& type<toy::PlayTool>();
    export_ template <> TOY_EDIT_EXPORT Type& type<toy::RunTool>();
    
    export_ template struct TOY_EDIT_EXPORT Typed<vector<toy::ActionGroup*>>;
    export_ template struct TOY_EDIT_EXPORT Typed<vector<toy::Clone*>>;
    export_ template struct TOY_EDIT_EXPORT Typed<vector<toy::Cut*>>;
    export_ template struct TOY_EDIT_EXPORT Typed<vector<toy::Edit*>>;
    export_ template struct TOY_EDIT_EXPORT Typed<vector<toy::GraphicsDebug*>>;
    export_ template struct TOY_EDIT_EXPORT Typed<vector<toy::Paste*>>;
    export_ template struct TOY_EDIT_EXPORT Typed<vector<toy::Toolbelt*>>;
    export_ template struct TOY_EDIT_EXPORT Typed<vector<toy::Toolbox*>>;
    export_ template struct TOY_EDIT_EXPORT Typed<vector<toy::DynamicToolbox*>>;
    export_ template struct TOY_EDIT_EXPORT Typed<vector<toy::Editor*>>;
    export_ template struct TOY_EDIT_EXPORT Typed<vector<toy::PlayTool*>>;
    export_ template struct TOY_EDIT_EXPORT Typed<vector<toy::RunTool*>>;
}
