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
        .field("fleet", &Jump::fleet)
        .field("start", &Jump::start)
        .field("dest", &Jump::dest)
        .field("stance", &Jump::stance)
        .field("track", &Jump::track)
        ;
    value_object<Scans>("Scans")
        ;
    value_object<Schema>("Schema")
        .field("code", &Schema::code)
        .field("name", &Schema::name)
        .field("conceptor", &Schema::conceptor)
        .field("level", &Schema::level)
        .field("cost", &Schema::cost)
        .field("minerals", &Schema::minerals)
        .field("andrium", &Schema::andrium)
        .field("resistance", &Schema::resistance)
        .field("speed", &Schema::speed)
        .field("scan", &Schema::scan)
        .field("planetary", &Schema::planetary)
        .field("spatial", &Schema::spatial)
        .field("upkeep_factor", &Schema::upkeep_factor)
        ;
    value_object<SpatialPower>("SpatialPower")
        ;
    value_object<Split>("Split")
        .field("source", &Split::source)
        .field("dest", &Split::dest)
        .field("code", &Split::code)
        .field("stance", &Split::stance)
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
        .field("coord", &PlanetaryCombat::coord)
        .field("attack", &PlanetaryCombat::attack)
        .field("defense", &PlanetaryCombat::defense)
        ;
    value_object<ShipComponent>("ShipComponent")
        ;
    value_object<ShipEngine>("ShipEngine")
        ;
    value_object<ShipHull>("ShipHull")
        ;
    value_object<ShipSchema>("ShipSchema")
        .field("size", &ShipSchema::size)
        .field("class", &ShipSchema::class)
        .field("main_weapon", &ShipSchema::main_weapon)
        ;
    value_object<SpatialCombat>("SpatialCombat")
        .field("coord", &SpatialCombat::coord)
        .field("attack", &SpatialCombat::attack)
        .field("defense", &SpatialCombat::defense)
        ;
    
    // Classes
    class_<Commander>("Commander")
        .constructor<mud::Id, const std::string&, Race, int, int, int>()
        .property("id", &Commander::id)
        .property("name", &Commander::name)
        .property("race", &Commander::race)
        .property("command", &Commander::command)
        .property("commerce", &Commander::commerce)
        .property("diplomacy", &Commander::diplomacy)
        .property("reputation", &Commander::reputation)
        .property("victory", &Commander::victory)
        .property("stars", &Commander::stars)
        .property("fleets", &Commander::fleets)
        .property("capital", &Commander::capital)
        .property("regime", &Commander::regime)
        .property("power", &Commander::power)
        .property("centaures", &Commander::centaures)
        .property("scans", &Commander::scans)
        ;
    class_<Fleet>("Fleet")
        .constructor<>()
        .constructor<toy::HSpatial, Galaxy&, Commander&, const mud::uvec2&, const std::string&>()
        .property("galaxy", &Fleet::galaxy)
        .property("commander", &Fleet::commander)
        .property("coord", &Fleet::coord)
        .property("slot", &Fleet::slot)
        .property("name", &Fleet::name)
        .property("experience", &Fleet::experience)
        .property("spatial_power", &Fleet::spatial_power)
        .property("planetary_power", &Fleet::planetary_power)
        .property("speed", &Fleet::speed)
        .property("scan", &Fleet::scan)
        .property("upkeep", &Fleet::upkeep)
        .property("stance", &Fleet::stance)
        .property("jump", &Fleet::jump)
        .property("split", &Fleet::split)
        .property("fought", &Fleet::fought)
        .property("ships_updated", &Fleet::ships_updated)
        .function("order_jump", &Fleet::order_jump)
        .function("order_attack", &Fleet::order_attack)
        ;
    class_<Galaxy>("Galaxy")
        .constructor<>()
        .constructor<toy::HSpatial, const mud::uvec2&>()
        .property("stars", &Galaxy::stars)
        .property("fleets", &Galaxy::fleets)
        .property("commanders", &Galaxy::commanders)
        .property("size", &Galaxy::size)
        ;
    class_<Player>("Player")
        ;
    class_<Star>("Star")
        .constructor<>()
        .constructor<toy::HSpatial, Galaxy&, const mud::uvec2&, const std::string&>()
        .property("galaxy", &Star::galaxy)
        .property("coord", &Star::coord)
        .property("name", &Star::name)
        .property("stability", &Star::stability)
        .property("revolt", &Star::revolt)
        .property("environment", &Star::environment)
        .property("terraformation", &Star::terraformation)
        .property("base_population", &Star::base_population)
        .property("max_population", &Star::max_population)
        .property("population", &Star::population)
        .property("militia", &Star::militia)
        .property("defense", &Star::defense)
        .property("revenue", &Star::revenue)
        .property("politic", &Star::politic)
        .property("taxation", &Star::taxation)
        .property("commander", &Star::commander)
        .property("scan", &Star::scan)
        ;
    class_<CommanderBrush>("CommanderBrush")
        .property("commander", &CommanderBrush::commander)
        .property("radius", &CommanderBrush::radius)
        ;
    class_<Universe>("Universe")
        .constructor<const std::string&, mud::JobSystem&>()
        .property("world", &Universe::world)
        .property("bullet_world", &Universe::bullet_world)
        ;
    
    // Functions
    function("generate_system", &generate_system);
    function("generate_fleet", &generate_fleet);
    function("generate_commander", &generate_commander);
    function("assign_system", &assign_system);
    
}
