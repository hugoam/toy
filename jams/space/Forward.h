

#pragma once

#include <infra/Config.h>

#include <infra/Forward.h>
#include <type/Forward.h>
#include <pool/Forward.h>
#include <refl/Forward.h>
#include <ecs/Forward.h>
#include <tree/Forward.h>
#include <srlz/Forward.h>
#include <math/Forward.h>
#include <geom/Forward.h>
#include <noise/Forward.h>
#include <wfc/Forward.h>
#include <fract/Forward.h>
#include <lang/Forward.h>
#include <ctx/Forward.h>
#include <ui/Forward.h>
#include <uio/Forward.h>
#include <snd/Forward.h>
#include <ctx-glfw/Forward.h>
#include <ui-vg/Forward.h>
#include <bgfx/Forward.h>
#include <gfx/Forward.h>
#include <gfx-pbr/Forward.h>
#include <gfx-obj/Forward.h>
#include <gfx-gltf/Forward.h>
#include <gfx-ui/Forward.h>
#include <tool/Forward.h>
#include <wfc-gfx/Forward.h>
#include <util/Forward.h>
#include <core/Forward.h>
#include <visu/Forward.h>
#include <edit/Forward.h>
#include <block/Forward.h>
#include <shell/Forward.h>

#ifndef _SPACE_EXPORT
#define _SPACE_EXPORT MUD_IMPORT
#endif

#include <cstdint>

    enum class GameStage : uint32_t;
    enum class Race : unsigned int;
    enum class Regime : unsigned int;
    enum class Politic : unsigned int;
    enum class Taxation : unsigned int;
    enum class Resource : unsigned int;
    enum class FleetSize : unsigned int;
    enum class Experience : unsigned int;
    enum class FleetStance : unsigned int;
    enum class WeaponType : unsigned int;
    enum class Technology : unsigned int;
    enum class CombatType : unsigned int;
    enum class TurnStage : unsigned int;
    
    
    struct RacialFactors;
    struct VisuPlanet;
    struct VisuStar;
    struct WeaponRay;
    struct VisuShip;
    struct VisuFleet;
    struct TurnEvents;
    struct Turn;
    class Player;
    struct SpatialPower;
    struct Construction;
    class Star;
    struct Jump;
    struct Split;
    class Fleet;
    struct Schema;
    struct ShipHull;
    struct ShipEngine;
    struct ShipComponent;
    struct ShipSchema;
    struct BuildingSchema;
    class ShipDatabase;
    class BuildingDatabase;
    struct Scans;
    struct TechDomain;
    class Commander;
    class Quadrant;
    struct GalaxyGrid;
    struct Combat;
    struct CombatFleet;
    struct CombatStar;
    struct PlanetaryCombat;
    struct SpatialCombat;
    class Galaxy;
    class Universe;
    class CommanderBrush;

namespace std {

    
    
}

namespace mud {
namespace ui {

    
    
}
}

namespace glm {

    
    
}

namespace mud {
namespace gfx {

    
    
}
}

namespace json11 {

    
    
}

namespace mud {

    
    
}

namespace mud {
namespace detail {

    
    
}
}

namespace bgfx {

    
    
}

namespace bimg {

    
    
}

namespace toy {

    
    
}

namespace bx {

    
    
}

