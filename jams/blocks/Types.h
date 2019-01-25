#pragma once

#include <blocks/Forward.h>

#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#include <type/Type.h>
#include <type/Vector.h>
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
#include <util/Types.h>
#include <core/Types.h>
#include <visu/Types.h>
#include <edit/Types.h>
#include <block/Types.h>
#include <shell/Types.h>
#endif

#ifndef MUD_CPP_20
#include <stl/string.h>
#include <stl/vector.h>
#include <cstdint>
#endif


namespace mud
{
    // Exported types
    
    export_ template <> _BLOCKS_EXPORT Type& type<Camp>();
    export_ template <> _BLOCKS_EXPORT Type& type<Faction>();
    export_ template <> _BLOCKS_EXPORT Type& type<Player>();
    export_ template <> _BLOCKS_EXPORT Type& type<Shield>();
    export_ template <> _BLOCKS_EXPORT Type& type<Slug>();
    export_ template <> _BLOCKS_EXPORT Type& type<Tank>();
    export_ template <> _BLOCKS_EXPORT Type& type<BlockWorld>();
    export_ template <> _BLOCKS_EXPORT Type& type<mud::ComponentHandle<Camp>>();
    export_ template <> _BLOCKS_EXPORT Type& type<mud::ComponentHandle<Shield>>();
    export_ template <> _BLOCKS_EXPORT Type& type<mud::ComponentHandle<Slug>>();
    export_ template <> _BLOCKS_EXPORT Type& type<mud::ComponentHandle<Tank>>();
    
    export_ template struct _BLOCKS_EXPORT Typed<vector<Camp*>>;
    export_ template struct _BLOCKS_EXPORT Typed<vector<Faction*>>;
    export_ template struct _BLOCKS_EXPORT Typed<vector<Player*>>;
    export_ template struct _BLOCKS_EXPORT Typed<vector<Shield*>>;
    export_ template struct _BLOCKS_EXPORT Typed<vector<Slug*>>;
    export_ template struct _BLOCKS_EXPORT Typed<vector<Tank*>>;
    export_ template struct _BLOCKS_EXPORT Typed<vector<BlockWorld*>>;
    export_ template struct _BLOCKS_EXPORT Typed<vector<mud::ComponentHandle<Camp>*>>;
    export_ template struct _BLOCKS_EXPORT Typed<vector<mud::ComponentHandle<Shield>*>>;
    export_ template struct _BLOCKS_EXPORT Typed<vector<mud::ComponentHandle<Slug>*>>;
    export_ template struct _BLOCKS_EXPORT Typed<vector<mud::ComponentHandle<Tank>*>>;
}
