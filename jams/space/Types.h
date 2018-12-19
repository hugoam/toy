#pragma once

#include <space/Forward.h>

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
    export_ template <> _SPACE_EXPORT Type& type<TurnStage>();
    export_ template <> _SPACE_EXPORT Type& type<WeaponType>();
    
    export_ template <> _SPACE_EXPORT Type& type<Combat>();
    export_ template <> _SPACE_EXPORT Type& type<CombatFleet>();
    export_ template <> _SPACE_EXPORT Type& type<CombatStar>();
    export_ template <> _SPACE_EXPORT Type& type<Commander>();
    export_ template <> _SPACE_EXPORT Type& type<Construction>();
    export_ template <> _SPACE_EXPORT Type& type<Jump>();
    export_ template <> _SPACE_EXPORT Type& type<Player>();
    export_ template <> _SPACE_EXPORT Type& type<Scans>();
    export_ template <> _SPACE_EXPORT Type& type<Schema>();
    export_ template <> _SPACE_EXPORT Type& type<SpatialPower>();
    export_ template <> _SPACE_EXPORT Type& type<Split>();
    export_ template <> _SPACE_EXPORT Type& type<TechDomain>();
    export_ template <> _SPACE_EXPORT Type& type<Turn>();
    export_ template <> _SPACE_EXPORT Type& type<Fleet>();
    export_ template <> _SPACE_EXPORT Type& type<Galaxy>();
    export_ template <> _SPACE_EXPORT Type& type<Quadrant>();
    export_ template <> _SPACE_EXPORT Type& type<Star>();
    export_ template <> _SPACE_EXPORT Type& type<Universe>();
    export_ template <> _SPACE_EXPORT Type& type<CommanderBrush>();
    export_ template <> _SPACE_EXPORT Type& type<BuildingSchema>();
    export_ template <> _SPACE_EXPORT Type& type<ShipComponent>();
    export_ template <> _SPACE_EXPORT Type& type<ShipEngine>();
    export_ template <> _SPACE_EXPORT Type& type<ShipHull>();
    export_ template <> _SPACE_EXPORT Type& type<ShipSchema>();
    export_ template <> _SPACE_EXPORT Type& type<PlanetaryCombat>();
    export_ template <> _SPACE_EXPORT Type& type<SpatialCombat>();
    
	export_ template struct _SPACE_EXPORT Typed<std::vector<Combat*>>;
	export_ template struct _SPACE_EXPORT Typed<std::vector<CombatFleet*>>;
	export_ template struct _SPACE_EXPORT Typed<std::vector<CombatStar*>>;
	export_ template struct _SPACE_EXPORT Typed<std::vector<Commander*>>;
	export_ template struct _SPACE_EXPORT Typed<std::vector<Construction*>>;
	export_ template struct _SPACE_EXPORT Typed<std::vector<Jump*>>;
	export_ template struct _SPACE_EXPORT Typed<std::vector<Player*>>;
	export_ template struct _SPACE_EXPORT Typed<std::vector<Scans*>>;
	export_ template struct _SPACE_EXPORT Typed<std::vector<Schema*>>;
	export_ template struct _SPACE_EXPORT Typed<std::vector<SpatialPower*>>;
	export_ template struct _SPACE_EXPORT Typed<std::vector<Split*>>;
	export_ template struct _SPACE_EXPORT Typed<std::vector<TechDomain*>>;
	export_ template struct _SPACE_EXPORT Typed<std::vector<Turn*>>;
	export_ template struct _SPACE_EXPORT Typed<std::vector<Fleet*>>;
	export_ template struct _SPACE_EXPORT Typed<std::vector<Galaxy*>>;
	export_ template struct _SPACE_EXPORT Typed<std::vector<Quadrant*>>;
	export_ template struct _SPACE_EXPORT Typed<std::vector<Star*>>;
	export_ template struct _SPACE_EXPORT Typed<std::vector<Universe*>>;
	export_ template struct _SPACE_EXPORT Typed<std::vector<CommanderBrush*>>;
	export_ template struct _SPACE_EXPORT Typed<std::vector<BuildingSchema*>>;
	export_ template struct _SPACE_EXPORT Typed<std::vector<ShipComponent*>>;
	export_ template struct _SPACE_EXPORT Typed<std::vector<ShipEngine*>>;
	export_ template struct _SPACE_EXPORT Typed<std::vector<ShipHull*>>;
	export_ template struct _SPACE_EXPORT Typed<std::vector<ShipSchema*>>;
	export_ template struct _SPACE_EXPORT Typed<std::vector<PlanetaryCombat*>>;
	export_ template struct _SPACE_EXPORT Typed<std::vector<SpatialCombat*>>;
}
