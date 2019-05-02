#include <infra/Cpp20.h>

#ifdef TWO_MODULES
module ._space;
#else
#include <space/Types.h>
#include <space/Api.h>
#include <type/Vector.h>
#endif

namespace two
{
    // Exported types
    template <> _SPACE_EXPORT Type& type<GameStage>() { static Type ty("GameStage", sizeof(GameStage)); return ty; }
    template <> _SPACE_EXPORT Type& type<Race>() { static Type ty("Race", sizeof(Race)); return ty; }
    template <> _SPACE_EXPORT Type& type<Regime>() { static Type ty("Regime", sizeof(Regime)); return ty; }
    template <> _SPACE_EXPORT Type& type<Politic>() { static Type ty("Politic", sizeof(Politic)); return ty; }
    template <> _SPACE_EXPORT Type& type<Taxation>() { static Type ty("Taxation", sizeof(Taxation)); return ty; }
    template <> _SPACE_EXPORT Type& type<Resource>() { static Type ty("Resource", sizeof(Resource)); return ty; }
    template <> _SPACE_EXPORT Type& type<FleetSize>() { static Type ty("FleetSize", sizeof(FleetSize)); return ty; }
    template <> _SPACE_EXPORT Type& type<Experience>() { static Type ty("Experience", sizeof(Experience)); return ty; }
    template <> _SPACE_EXPORT Type& type<FleetStance>() { static Type ty("FleetStance", sizeof(FleetStance)); return ty; }
    template <> _SPACE_EXPORT Type& type<WeaponType>() { static Type ty("WeaponType", sizeof(WeaponType)); return ty; }
    template <> _SPACE_EXPORT Type& type<Technology>() { static Type ty("Technology", sizeof(Technology)); return ty; }
    template <> _SPACE_EXPORT Type& type<CombatType>() { static Type ty("CombatType", sizeof(CombatType)); return ty; }
    
    template <> _SPACE_EXPORT Type& type<stl::vector<HStar>>() { static Type ty("stl::vector<HStar>", sizeof(stl::vector<HStar>)); return ty; }
    template <> _SPACE_EXPORT Type& type<stl::vector<HFleet>>() { static Type ty("stl::vector<HFleet>", sizeof(stl::vector<HFleet>)); return ty; }
    template <> _SPACE_EXPORT Type& type<stl::vector<Commander*>>() { static Type ty("stl::vector<Commander*>", sizeof(stl::vector<Commander*>)); return ty; }
    template <> _SPACE_EXPORT Type& type<stl::vector<CombatFleet>>() { static Type ty("stl::vector<CombatFleet>", sizeof(stl::vector<CombatFleet>)); return ty; }
    
    template <> _SPACE_EXPORT Type& type<two::ComponentHandle<Galaxy>>() { static Type ty("ComponentHandle<Galaxy>", sizeof(two::ComponentHandle<Galaxy>)); return ty; }
    template <> _SPACE_EXPORT Type& type<two::ComponentHandle<Star>>() { static Type ty("ComponentHandle<Star>", sizeof(two::ComponentHandle<Star>)); return ty; }
    template <> _SPACE_EXPORT Type& type<two::ComponentHandle<Fleet>>() { static Type ty("ComponentHandle<Fleet>", sizeof(two::ComponentHandle<Fleet>)); return ty; }
    template <> _SPACE_EXPORT Type& type<Turn>() { static Type ty("Turn", sizeof(Turn)); return ty; }
    template <> _SPACE_EXPORT Type& type<Player>() { static Type ty("Player", sizeof(Player)); return ty; }
    template <> _SPACE_EXPORT Type& type<SpatialPower>() { static Type ty("SpatialPower", sizeof(SpatialPower)); return ty; }
    template <> _SPACE_EXPORT Type& type<Construction>() { static Type ty("Construction", sizeof(Construction)); return ty; }
    template <> _SPACE_EXPORT Type& type<Star>() { static Type ty("Star", sizeof(Star)); return ty; }
    template <> _SPACE_EXPORT Type& type<Jump>() { static Type ty("Jump", sizeof(Jump)); return ty; }
    template <> _SPACE_EXPORT Type& type<Split>() { static Type ty("Split", sizeof(Split)); return ty; }
    template <> _SPACE_EXPORT Type& type<Fleet>() { static Type ty("Fleet", sizeof(Fleet)); return ty; }
    template <> _SPACE_EXPORT Type& type<Schema>() { static Type ty("Schema", sizeof(Schema)); return ty; }
    template <> _SPACE_EXPORT Type& type<ShipHull>() { static Type ty("ShipHull", type<Schema>(), sizeof(ShipHull)); return ty; }
    template <> _SPACE_EXPORT Type& type<ShipEngine>() { static Type ty("ShipEngine", type<Schema>(), sizeof(ShipEngine)); return ty; }
    template <> _SPACE_EXPORT Type& type<ShipComponent>() { static Type ty("ShipComponent", type<Schema>(), sizeof(ShipComponent)); return ty; }
    template <> _SPACE_EXPORT Type& type<ShipSchema>() { static Type ty("ShipSchema", type<Schema>(), sizeof(ShipSchema)); return ty; }
    template <> _SPACE_EXPORT Type& type<BuildingSchema>() { static Type ty("BuildingSchema", type<Schema>(), sizeof(BuildingSchema)); return ty; }
    template <> _SPACE_EXPORT Type& type<Scans>() { static Type ty("Scans", sizeof(Scans)); return ty; }
    template <> _SPACE_EXPORT Type& type<TechDomain>() { static Type ty("TechDomain", sizeof(TechDomain)); return ty; }
    template <> _SPACE_EXPORT Type& type<Commander>() { static Type ty("Commander", sizeof(Commander)); return ty; }
    template <> _SPACE_EXPORT Type& type<Combat>() { static Type ty("Combat", sizeof(Combat)); return ty; }
    template <> _SPACE_EXPORT Type& type<CombatFleet>() { static Type ty("CombatFleet", sizeof(CombatFleet)); return ty; }
    template <> _SPACE_EXPORT Type& type<CombatStar>() { static Type ty("CombatStar", sizeof(CombatStar)); return ty; }
    template <> _SPACE_EXPORT Type& type<PlanetaryCombat>() { static Type ty("PlanetaryCombat", type<Combat>(), sizeof(PlanetaryCombat)); return ty; }
    template <> _SPACE_EXPORT Type& type<SpatialCombat>() { static Type ty("SpatialCombat", type<Combat>(), sizeof(SpatialCombat)); return ty; }
    template <> _SPACE_EXPORT Type& type<Galaxy>() { static Type ty("Galaxy", sizeof(Galaxy)); return ty; }
    template <> _SPACE_EXPORT Type& type<Universe>() { static Type ty("Universe", type<two::Complex>(), sizeof(Universe)); return ty; }
    template <> _SPACE_EXPORT Type& type<CommanderBrush>() { static Type ty("CommanderBrush", type<two::Brush>(), sizeof(CommanderBrush)); return ty; }
}
