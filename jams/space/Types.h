#pragma once

#include <space/Forward.h>

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
    export_ template <> _SPACE_EXPORT Type& type<CombatType>();
    export_ template <> _SPACE_EXPORT Type& type<Experience>();
    export_ template <> _SPACE_EXPORT Type& type<FleetSize>();
    export_ template <> _SPACE_EXPORT Type& type<FleetStance>();
    export_ template <> _SPACE_EXPORT Type& type<GameStage>();
    export_ template <> _SPACE_EXPORT Type& type<Politic>();
    export_ template <> _SPACE_EXPORT Type& type<Race>();
    export_ template <> _SPACE_EXPORT Type& type<Regime>();
    export_ template <> _SPACE_EXPORT Type& type<Resource>();
    export_ template <> _SPACE_EXPORT Type& type<Taxation>();
    export_ template <> _SPACE_EXPORT Type& type<Technology>();
    export_ template <> _SPACE_EXPORT Type& type<WeaponType>();
    
    export_ template <> _SPACE_EXPORT Type& type<Combat>();
    export_ template <> _SPACE_EXPORT Type& type<CombatFleet>();
    export_ template <> _SPACE_EXPORT Type& type<CombatStar>();
    export_ template <> _SPACE_EXPORT Type& type<Commander>();
    export_ template <> _SPACE_EXPORT Type& type<Construction>();
    export_ template <> _SPACE_EXPORT Type& type<Fleet>();
    export_ template <> _SPACE_EXPORT Type& type<Galaxy>();
    export_ template <> _SPACE_EXPORT Type& type<Jump>();
    export_ template <> _SPACE_EXPORT Type& type<Player>();
    export_ template <> _SPACE_EXPORT Type& type<Scans>();
    export_ template <> _SPACE_EXPORT Type& type<Schema>();
    export_ template <> _SPACE_EXPORT Type& type<SpatialPower>();
    export_ template <> _SPACE_EXPORT Type& type<Split>();
    export_ template <> _SPACE_EXPORT Type& type<Star>();
    export_ template <> _SPACE_EXPORT Type& type<TechDomain>();
    export_ template <> _SPACE_EXPORT Type& type<Turn>();
    export_ template <> _SPACE_EXPORT Type& type<BuildingSchema>();
    export_ template <> _SPACE_EXPORT Type& type<CommanderBrush>();
    export_ template <> _SPACE_EXPORT Type& type<mud::ComponentHandle<Fleet>>();
    export_ template <> _SPACE_EXPORT Type& type<mud::ComponentHandle<Galaxy>>();
    export_ template <> _SPACE_EXPORT Type& type<mud::ComponentHandle<Star>>();
    export_ template <> _SPACE_EXPORT Type& type<PlanetaryCombat>();
    export_ template <> _SPACE_EXPORT Type& type<ShipComponent>();
    export_ template <> _SPACE_EXPORT Type& type<ShipEngine>();
    export_ template <> _SPACE_EXPORT Type& type<ShipHull>();
    export_ template <> _SPACE_EXPORT Type& type<ShipSchema>();
    export_ template <> _SPACE_EXPORT Type& type<SpatialCombat>();
    export_ template <> _SPACE_EXPORT Type& type<Universe>();
    
    export_ template struct _SPACE_EXPORT Typed<vector<Combat*>>;
    export_ template struct _SPACE_EXPORT Typed<vector<CombatFleet*>>;
    export_ template struct _SPACE_EXPORT Typed<vector<CombatStar*>>;
    export_ template struct _SPACE_EXPORT Typed<vector<Commander*>>;
    export_ template struct _SPACE_EXPORT Typed<vector<Construction*>>;
    export_ template struct _SPACE_EXPORT Typed<vector<Fleet*>>;
    export_ template struct _SPACE_EXPORT Typed<vector<Galaxy*>>;
    export_ template struct _SPACE_EXPORT Typed<vector<Jump*>>;
    export_ template struct _SPACE_EXPORT Typed<vector<Player*>>;
    export_ template struct _SPACE_EXPORT Typed<vector<Scans*>>;
    export_ template struct _SPACE_EXPORT Typed<vector<Schema*>>;
    export_ template struct _SPACE_EXPORT Typed<vector<SpatialPower*>>;
    export_ template struct _SPACE_EXPORT Typed<vector<Split*>>;
    export_ template struct _SPACE_EXPORT Typed<vector<Star*>>;
    export_ template struct _SPACE_EXPORT Typed<vector<TechDomain*>>;
    export_ template struct _SPACE_EXPORT Typed<vector<Turn*>>;
    export_ template struct _SPACE_EXPORT Typed<vector<BuildingSchema*>>;
    export_ template struct _SPACE_EXPORT Typed<vector<CommanderBrush*>>;
    export_ template struct _SPACE_EXPORT Typed<vector<mud::ComponentHandle<Fleet>*>>;
    export_ template struct _SPACE_EXPORT Typed<vector<mud::ComponentHandle<Galaxy>*>>;
    export_ template struct _SPACE_EXPORT Typed<vector<mud::ComponentHandle<Star>*>>;
    export_ template struct _SPACE_EXPORT Typed<vector<PlanetaryCombat*>>;
    export_ template struct _SPACE_EXPORT Typed<vector<ShipComponent*>>;
    export_ template struct _SPACE_EXPORT Typed<vector<ShipEngine*>>;
    export_ template struct _SPACE_EXPORT Typed<vector<ShipHull*>>;
    export_ template struct _SPACE_EXPORT Typed<vector<ShipSchema*>>;
    export_ template struct _SPACE_EXPORT Typed<vector<SpatialCombat*>>;
    export_ template struct _SPACE_EXPORT Typed<vector<Universe*>>;
}
