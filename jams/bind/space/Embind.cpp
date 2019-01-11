#include <space/Api.h>
#include <emscripten/bind.h>

using namespace emscripten;

EMSCRIPTEN_BINDINGS(_space)
{
    
    // Enums
    enum_<CombatType>("CombatType")
        .value("Spatial", CombatType::Spatial)
        .value("Planetary", CombatType::Planetary)
        ;
    enum_<Experience>("Experience")
        .value("Inexperienced", Experience::Inexperienced)
        .value("LittleExperienced", Experience::LittleExperienced)
        .value("Experienced", Experience::Experienced)
        .value("Superior", Experience::Superior)
        .value("Elite", Experience::Elite)
        ;
    enum_<FleetSize>("FleetSize")
        .value("Ridicule", FleetSize::Ridicule)
        .value("Minuscule", FleetSize::Minuscule)
        .value("Tiny", FleetSize::Tiny)
        .value("Small", FleetSize::Small)
        .value("Medium", FleetSize::Medium)
        .value("Respectable", FleetSize::Respectable)
        .value("Grand", FleetSize::Grand)
        .value("HighGrand", FleetSize::HighGrand)
        .value("Colossal", FleetSize::Colossal)
        .value("Titanesque", FleetSize::Titanesque)
        .value("Cyclopean", FleetSize::Cyclopean)
        .value("Divine", FleetSize::Divine)
        .value("Count", FleetSize::Count)
        ;
    enum_<FleetStance>("FleetStance")
        .value("Movement", FleetStance::Movement)
        .value("SpatialAttack", FleetStance::SpatialAttack)
        .value("SpatialDefense", FleetStance::SpatialDefense)
        .value("PlanetaryAttack", FleetStance::PlanetaryAttack)
        .value("PlanetaryDefense", FleetStance::PlanetaryDefense)
        .value("Pillage", FleetStance::Pillage)
        ;
    enum_<GameStage>("GameStage")
        .value("Empire", GameStage::Empire)
        .value("Tactics", GameStage::Tactics)
        .value("TurnReport", GameStage::TurnReport)
        ;
    enum_<Politic>("Politic")
        .value("Taxes", Politic::Taxes)
        .value("Commerce", Politic::Commerce)
        .value("Construction", Politic::Construction)
        .value("Defense", Politic::Defense)
        .value("Pacification", Politic::Pacification)
        ;
    enum_<Race>("Race")
        .value("Human", Race::Human)
        .value("Bulvoid", Race::Bulvoid)
        .value("Techtulon", Race::Techtulon)
        .value("Rakrarior", Race::Rakrarior)
        .value("Seigneur", Race::Seigneur)
        .value("Meton", Race::Meton)
        .value("Tissinar", Race::Tissinar)
        .value("Zwiie", Race::Zwiie)
        ;
    enum_<Regime>("Regime")
        .value("Empire", Regime::Empire)
        .value("Dictature", Regime::Dictature)
        .value("Democracy", Regime::Democracy)
        .value("Theocracy", Regime::Theocracy)
        .value("Technocracy", Regime::Technocracy)
        .value("Piratery", Regime::Piratery)
        ;
    enum_<Resource>("Resource")
        .value("None", Resource::None)
        .value("Minerals", Resource::Minerals)
        .value("Andrium", Resource::Andrium)
        .value("Alcool", Resource::Alcool)
        .value("Slaves", Resource::Slaves)
        .value("Narcotics", Resource::Narcotics)
        .value("Food", Resource::Food)
        .value("Medicine", Resource::Medicine)
        .value("Computers", Resource::Computers)
        .value("Plastic", Resource::Plastic)
        .value("Robot", Resource::Robot)
        .value("Count", Resource::Count)
        ;
    enum_<Taxation>("Taxation")
        .value("None", Taxation::None)
        .value("Light", Taxation::Light)
        .value("Medium", Taxation::Medium)
        .value("Heavy", Taxation::Heavy)
        .value("Heaviest", Taxation::Heaviest)
        .value("Total", Taxation::Total)
        ;
    enum_<Technology>("Technology")
        .value("Engines", Technology::Engines)
        .value("EcoEnergy", Technology::EcoEnergy)
        .value("Scanners", Technology::Scanners)
        .value("PlanetaryShields", Technology::PlanetaryShields)
        .value("SpatialShields", Technology::SpatialShields)
        .value("LaserPlasmaIons", Technology::LaserPlasmaIons)
        .value("Torpedoes", Technology::Torpedoes)
        .value("Bombs", Technology::Bombs)
        .value("HullArmor", Technology::HullArmor)
        .value("Mining", Technology::Mining)
        .value("Terraforming", Technology::Terraforming)
        .value("Construction", Technology::Construction)
        .value("Piloting", Technology::Piloting)
        .value("Commerce", Technology::Commerce)
        .value("Personnel", Technology::Personnel)
        .value("Administration", Technology::Administration)
        .value("CyberCommand", Technology::CyberCommand)
        .value("CyberCommerce", Technology::CyberCommerce)
        .value("CyberDiplomacy", Technology::CyberDiplomacy)
        .value("Count", Technology::Count)
        ;
    enum_<WeaponType>("WeaponType")
        .value("None", WeaponType::None)
        .value("Ion", WeaponType::Ion)
        .value("Laser", WeaponType::Laser)
        .value("Plasma", WeaponType::Plasma)
        .value("Torpedo", WeaponType::Torpedo)
        .value("Bomb", WeaponType::Bomb)
        ;
    
    // Sequences
    
    // Arrays
    
    // Structs
    value_object<Combat>("Combat")
        ;
    value_object<CombatFleet>("CombatFleet")
        ;
    value_object<CombatStar>("CombatStar")
        ;
    value_object<Construction>("Construction")
        ;
    value_object<Jump>("Jump")
        .field("fleet", &Jump::m_fleet)
        .field("start", &Jump::m_start)
        .field("dest", &Jump::m_dest)
        .field("stance", &Jump::m_stance)
        .field("track", &Jump::m_track)
        ;
    value_object<Scans>("Scans")
        ;
    value_object<Schema>("Schema")
        .field("code", &Schema::m_code)
        .field("name", &Schema::m_name)
        .field("conceptor", &Schema::m_conceptor)
        .field("level", &Schema::m_level)
        .field("cost", &Schema::m_cost)
        .field("minerals", &Schema::m_minerals)
        .field("andrium", &Schema::m_andrium)
        .field("resistance", &Schema::m_resistance)
        .field("speed", &Schema::m_speed)
        .field("scan", &Schema::m_scan)
        .field("planetary", &Schema::m_planetary)
        .field("spatial", &Schema::m_spatial)
        .field("upkeep_factor", &Schema::m_upkeep_factor)
        ;
    value_object<SpatialPower>("SpatialPower")
        ;
    value_object<Split>("Split")
        .field("source", &Split::m_source)
        .field("dest", &Split::m_dest)
        .field("code", &Split::m_code)
        .field("stance", &Split::m_stance)
        ;
    value_object<TechDomain>("TechDomain")
        ;
    value_object<Turn>("Turn")
        ;
    value_object<BuildingSchema>("BuildingSchema")
        ;
    value_object<mud::ComponentHandle<Fleet>>("ComponentHandle<Fleet>")
        ;
    value_object<mud::ComponentHandle<Galaxy>>("ComponentHandle<Galaxy>")
        ;
    value_object<mud::ComponentHandle<Star>>("ComponentHandle<Star>")
        ;
    value_object<PlanetaryCombat>("PlanetaryCombat")
        .field("coord", &PlanetaryCombat::m_coord)
        .field("attack", &PlanetaryCombat::m_attack)
        .field("defense", &PlanetaryCombat::m_defense)
        ;
    value_object<ShipComponent>("ShipComponent")
        ;
    value_object<ShipEngine>("ShipEngine")
        ;
    value_object<ShipHull>("ShipHull")
        ;
    value_object<ShipSchema>("ShipSchema")
        .field("size", &ShipSchema::m_size)
        .field("class", &ShipSchema::m_class)
        .field("main_weapon", &ShipSchema::m_main_weapon)
        ;
    value_object<SpatialCombat>("SpatialCombat")
        .field("coord", &SpatialCombat::m_coord)
        .field("attack", &SpatialCombat::m_attack)
        .field("defense", &SpatialCombat::m_defense)
        ;
    
    // Classes
    class_<Commander>("Commander")
        .constructor<mud::Id, const std::string&, Race, int, int, int>()
        .property("id", &Commander::m_id)
        .property("name", &Commander::m_name)
        .property("race", &Commander::m_race)
        .property("command", &Commander::m_command)
        .property("commerce", &Commander::m_commerce)
        .property("diplomacy", &Commander::m_diplomacy)
        .property("reputation", &Commander::m_reputation)
        .property("victory", &Commander::m_victory)
        .property("stars", &Commander::m_stars)
        .property("fleets", &Commander::m_fleets)
        .property("capital", &Commander::m_capital)
        .property("regime", &Commander::m_regime)
        .property("power", &Commander::m_power)
        .property("centaures", &Commander::m_centaures)
        .property("scans", &Commander::m_scans)
        ;
    class_<Fleet>("Fleet")
        .constructor<>()
        .constructor<toy::HSpatial, Galaxy&, Commander&, const mud::uvec2&, const std::string&>()
        .property("galaxy", &Fleet::m_galaxy)
        .property("commander", &Fleet::m_commander)
        .property("coord", &Fleet::m_coord)
        .property("slot", &Fleet::m_slot)
        .property("name", &Fleet::m_name)
        .property("experience", &Fleet::m_experience)
        .property("spatial_power", &Fleet::m_spatial_power)
        .property("planetary_power", &Fleet::m_planetary_power)
        .property("speed", &Fleet::m_speed)
        .property("scan", &Fleet::m_scan)
        .property("upkeep", &Fleet::m_upkeep)
        .property("stance", &Fleet::m_stance)
        .property("jump", &Fleet::m_jump)
        .property("split", &Fleet::m_split)
        .property("fought", &Fleet::m_fought)
        .property("ships_updated", &Fleet::m_ships_updated)
        .function("order_jump", &Fleet::order_jump)
        .function("order_attack", &Fleet::order_attack)
        ;
    class_<Galaxy>("Galaxy")
        .constructor<>()
        .constructor<toy::HSpatial, const mud::uvec2&>()
        .property("stars", &Galaxy::m_stars)
        .property("fleets", &Galaxy::m_fleets)
        .property("commanders", &Galaxy::m_commanders)
        .property("size", &Galaxy::m_size)
        ;
    class_<Player>("Player")
        ;
    class_<Star>("Star")
        .constructor<>()
        .constructor<toy::HSpatial, Galaxy&, const mud::uvec2&, const std::string&>()
        .property("galaxy", &Star::m_galaxy)
        .property("coord", &Star::m_coord)
        .property("name", &Star::m_name)
        .property("stability", &Star::m_stability)
        .property("revolt", &Star::m_revolt)
        .property("environment", &Star::m_environment)
        .property("terraformation", &Star::m_terraformation)
        .property("base_population", &Star::m_base_population)
        .property("max_population", &Star::m_max_population)
        .property("population", &Star::m_population)
        .property("militia", &Star::m_militia)
        .property("defense", &Star::m_defense)
        .property("revenue", &Star::m_revenue)
        .property("politic", &Star::m_politic)
        .property("taxation", &Star::m_taxation)
        .property("commander", &Star::m_commander)
        .property("scan", &Star::m_scan)
        ;
    class_<CommanderBrush>("CommanderBrush")
        .property("commander", &CommanderBrush::m_commander)
        .property("radius", &CommanderBrush::m_radius)
        ;
    class_<Universe>("Universe")
        .constructor<const std::string&, mud::JobSystem&>()
        .property("world", &Universe::m_world)
        .property("bullet_world", &Universe::m_bullet_world)
        ;
    
    // Functions
    function("generate_system", &generate_system);
    function("generate_fleet", &generate_fleet);
    function("generate_commander", &generate_commander);
    function("assign_system", &assign_system);
    
}
