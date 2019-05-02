#pragma once

#include <stdint.h>
#include <stl/string.h>
#include <stl/vector.h>
#include <space/Forward.h>

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
#include <util/Types.h>
#include <core/Types.h>
#include <visu/Types.h>
#include <edit/Types.h>
#include <block/Types.h>
#include <shell/Types.h>
#endif


namespace two
{
    // Exported types
    export_ template <> _SPACE_EXPORT Type& type<GameStage>();
    export_ template <> _SPACE_EXPORT Type& type<Race>();
    export_ template <> _SPACE_EXPORT Type& type<Regime>();
    export_ template <> _SPACE_EXPORT Type& type<Politic>();
    export_ template <> _SPACE_EXPORT Type& type<Taxation>();
    export_ template <> _SPACE_EXPORT Type& type<Resource>();
    export_ template <> _SPACE_EXPORT Type& type<FleetSize>();
    export_ template <> _SPACE_EXPORT Type& type<Experience>();
    export_ template <> _SPACE_EXPORT Type& type<FleetStance>();
    export_ template <> _SPACE_EXPORT Type& type<WeaponType>();
    export_ template <> _SPACE_EXPORT Type& type<Technology>();
    export_ template <> _SPACE_EXPORT Type& type<CombatType>();
    
    export_ template <> _SPACE_EXPORT Type& type<stl::vector<HStar>>();
    export_ template <> _SPACE_EXPORT Type& type<stl::vector<HFleet>>();
    export_ template <> _SPACE_EXPORT Type& type<stl::vector<Commander*>>();
    export_ template <> _SPACE_EXPORT Type& type<stl::vector<CombatFleet>>();
    
    export_ template <> _SPACE_EXPORT Type& type<two::ComponentHandle<Galaxy>>();
    export_ template <> _SPACE_EXPORT Type& type<two::ComponentHandle<Star>>();
    export_ template <> _SPACE_EXPORT Type& type<two::ComponentHandle<Fleet>>();
    export_ template <> _SPACE_EXPORT Type& type<Turn>();
    export_ template <> _SPACE_EXPORT Type& type<Player>();
    export_ template <> _SPACE_EXPORT Type& type<SpatialPower>();
    export_ template <> _SPACE_EXPORT Type& type<Construction>();
    export_ template <> _SPACE_EXPORT Type& type<Star>();
    export_ template <> _SPACE_EXPORT Type& type<Jump>();
    export_ template <> _SPACE_EXPORT Type& type<Split>();
    export_ template <> _SPACE_EXPORT Type& type<Fleet>();
    export_ template <> _SPACE_EXPORT Type& type<Schema>();
    export_ template <> _SPACE_EXPORT Type& type<ShipHull>();
    export_ template <> _SPACE_EXPORT Type& type<ShipEngine>();
    export_ template <> _SPACE_EXPORT Type& type<ShipComponent>();
    export_ template <> _SPACE_EXPORT Type& type<ShipSchema>();
    export_ template <> _SPACE_EXPORT Type& type<BuildingSchema>();
    export_ template <> _SPACE_EXPORT Type& type<Scans>();
    export_ template <> _SPACE_EXPORT Type& type<TechDomain>();
    export_ template <> _SPACE_EXPORT Type& type<Commander>();
    export_ template <> _SPACE_EXPORT Type& type<Combat>();
    export_ template <> _SPACE_EXPORT Type& type<CombatFleet>();
    export_ template <> _SPACE_EXPORT Type& type<CombatStar>();
    export_ template <> _SPACE_EXPORT Type& type<PlanetaryCombat>();
    export_ template <> _SPACE_EXPORT Type& type<SpatialCombat>();
    export_ template <> _SPACE_EXPORT Type& type<Galaxy>();
    export_ template <> _SPACE_EXPORT Type& type<Universe>();
    export_ template <> _SPACE_EXPORT Type& type<CommanderBrush>();
}
