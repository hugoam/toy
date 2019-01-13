#include <infra/Api.h>
#include <jobs/Api.h>
#include <type/Api.h>
#include <tree/Api.h>
#include <pool/Api.h>
#include <refl/Api.h>
#include <ecs/Api.h>
#include <srlz/Api.h>
#include <math/Api.h>
#include <geom/Api.h>
#include <noise/Api.h>
#include <wfc/Api.h>
#include <fract/Api.h>
#include <lang/Api.h>
#include <ctx/Api.h>
#include <ui/Api.h>
#include <uio/Api.h>
#include <bgfx/Api.h>
#include <gfx/Api.h>
#include <gfx-pbr/Api.h>
#include <gfx-obj/Api.h>
#include <gltf/Api.h>
#include <gfx-gltf/Api.h>
#include <gfx-ui/Api.h>
#include <gfx-edit/Api.h>
#include <tool/Api.h>
#include <wfc-gfx/Api.h>
#include <util/Api.h>
#include <core/Api.h>
#include <visu/Api.h>
#include <edit/Api.h>
#include <block/Api.h>
#include <shell/Api.h>
#include <space/Api.h>
#include <emscripten.h>


extern "C" {
	
	// Not using size_t for array indices as the values used by the javascript code are signed.
	void array_bounds_check(const int array_size, const int array_idx) {
		  if (array_idx < 0 || array_idx >= array_size) {
			    EM_ASM({
				      throw 'Array index ' + $0 + ' out of bounds: [0,' + $1 + ')';
				    }, array_idx, array_size);
			  }
	}
	// Combat
	Combat* EMSCRIPTEN_KEEPALIVE Combat_Combat_0() {
		return new Combat();
	}
	void EMSCRIPTEN_KEEPALIVE Combat___destroy__(Combat* self) {
		delete self;
	}
	// CombatFleet
	CombatFleet* EMSCRIPTEN_KEEPALIVE CombatFleet_CombatFleet_0() {
		return new CombatFleet();
	}
	void EMSCRIPTEN_KEEPALIVE CombatFleet___destroy__(CombatFleet* self) {
		delete self;
	}
	// CombatStar
	CombatStar* EMSCRIPTEN_KEEPALIVE CombatStar_CombatStar_0() {
		return new CombatStar();
	}
	void EMSCRIPTEN_KEEPALIVE CombatStar___destroy__(CombatStar* self) {
		delete self;
	}
	// Commander
	Commander* EMSCRIPTEN_KEEPALIVE Commander_Commander_6(mud::Id id, const std::string name, Race race, int command, int commerce, int diplomacy) {
		return new Commander(id, *name, race, command, commerce, diplomacy);
	}
	mud::Id EMSCRIPTEN_KEEPALIVE Commander_get_id(Commander* self) {
		return self->m_id;
	}
	std::string EMSCRIPTEN_KEEPALIVE Commander_get_name(Commander* self) {
		return self->m_name;
	}
	Race EMSCRIPTEN_KEEPALIVE Commander_get_race(Commander* self) {
		return self->m_race;
	}
	int EMSCRIPTEN_KEEPALIVE Commander_get_command(Commander* self) {
		return self->m_command;
	}
	int EMSCRIPTEN_KEEPALIVE Commander_get_commerce(Commander* self) {
		return self->m_commerce;
	}
	int EMSCRIPTEN_KEEPALIVE Commander_get_diplomacy(Commander* self) {
		return self->m_diplomacy;
	}
	int EMSCRIPTEN_KEEPALIVE Commander_get_reputation(Commander* self) {
		return self->m_reputation;
	}
	int EMSCRIPTEN_KEEPALIVE Commander_get_victory(Commander* self) {
		return self->m_victory;
	}
	std::vector<HStar> EMSCRIPTEN_KEEPALIVE Commander_get_stars(Commander* self) {
		return self->m_stars;
	}
	std::vector<HFleet> EMSCRIPTEN_KEEPALIVE Commander_get_fleets(Commander* self) {
		return self->m_fleets;
	}
	Star EMSCRIPTEN_KEEPALIVE Commander_get_capital(Commander* self) {
		return self->m_capital;
	}
	Regime EMSCRIPTEN_KEEPALIVE Commander_get_regime(Commander* self) {
		return self->m_regime;
	}
	float EMSCRIPTEN_KEEPALIVE Commander_get_power(Commander* self) {
		return self->m_power;
	}
	float EMSCRIPTEN_KEEPALIVE Commander_get_centaures(Commander* self) {
		return self->m_centaures;
	}
	Scans EMSCRIPTEN_KEEPALIVE Commander_get_scans(Commander* self) {
		return self->m_scans;
	}
	void EMSCRIPTEN_KEEPALIVE Commander___destroy__(Commander* self) {
		delete self;
	}
	// Construction
	Construction* EMSCRIPTEN_KEEPALIVE Construction_Construction_0() {
		return new Construction();
	}
	void EMSCRIPTEN_KEEPALIVE Construction___destroy__(Construction* self) {
		delete self;
	}
	// Fleet
	Fleet* EMSCRIPTEN_KEEPALIVE Fleet_Fleet_0() {
		return new Fleet();
	}
	Fleet* EMSCRIPTEN_KEEPALIVE Fleet_Fleet_5(toy::HSpatial spatial, Galaxy galaxy, Commander commander, const uvec2 coord, const std::string name) {
		return new Fleet(spatial, *galaxy, *commander, *coord, *name);
	}
	void EMSCRIPTEN_KEEPALIVE Fleet_order_jump_2(Fleet* self, vec2 coord, FleetStance stance) {
		self->order_jump(coord, stance);
	}
	void EMSCRIPTEN_KEEPALIVE Fleet_order_attack_1(Fleet* self, Star star) {
		self->order_attack(*star);
	}
	Galaxy EMSCRIPTEN_KEEPALIVE Fleet_get_galaxy(Fleet* self) {
		return self->m_galaxy;
	}
	Commander EMSCRIPTEN_KEEPALIVE Fleet_get_commander(Fleet* self) {
		return self->m_commander;
	}
	uvec2 EMSCRIPTEN_KEEPALIVE Fleet_get_coord(Fleet* self) {
		return self->m_coord;
	}
	vec3 EMSCRIPTEN_KEEPALIVE Fleet_get_slot(Fleet* self) {
		return self->m_slot;
	}
	std::string EMSCRIPTEN_KEEPALIVE Fleet_get_name(Fleet* self) {
		return self->m_name;
	}
	float EMSCRIPTEN_KEEPALIVE Fleet_get_experience(Fleet* self) {
		return self->m_experience;
	}
	SpatialPower EMSCRIPTEN_KEEPALIVE Fleet_get_spatial_power(Fleet* self) {
		return self->m_spatial_power;
	}
	float EMSCRIPTEN_KEEPALIVE Fleet_get_planetary_power(Fleet* self) {
		return self->m_planetary_power;
	}
	uint8_t EMSCRIPTEN_KEEPALIVE Fleet_get_speed(Fleet* self) {
		return self->m_speed;
	}
	uint8_t EMSCRIPTEN_KEEPALIVE Fleet_get_scan(Fleet* self) {
		return self->m_scan;
	}
	float EMSCRIPTEN_KEEPALIVE Fleet_get_upkeep(Fleet* self) {
		return self->m_upkeep;
	}
	FleetStance EMSCRIPTEN_KEEPALIVE Fleet_get_stance(Fleet* self) {
		return self->m_stance;
	}
	Jump EMSCRIPTEN_KEEPALIVE Fleet_get_jump(Fleet* self) {
		return self->m_jump;
	}
	Split EMSCRIPTEN_KEEPALIVE Fleet_get_split(Fleet* self) {
		return self->m_split;
	}
	bool EMSCRIPTEN_KEEPALIVE Fleet_get_fought(Fleet* self) {
		return self->m_fought;
	}
	size_t EMSCRIPTEN_KEEPALIVE Fleet_get_ships_updated(Fleet* self) {
		return self->m_ships_updated;
	}
	void EMSCRIPTEN_KEEPALIVE Fleet___destroy__(Fleet* self) {
		delete self;
	}
	// Galaxy
	Galaxy* EMSCRIPTEN_KEEPALIVE Galaxy_Galaxy_0() {
		return new Galaxy();
	}
	Galaxy* EMSCRIPTEN_KEEPALIVE Galaxy_Galaxy_2(toy::HSpatial spatial, const uvec2 size) {
		return new Galaxy(spatial, *size);
	}
	std::vector<HStar> EMSCRIPTEN_KEEPALIVE Galaxy_get_stars(Galaxy* self) {
		return self->m_stars;
	}
	std::vector<HFleet> EMSCRIPTEN_KEEPALIVE Galaxy_get_fleets(Galaxy* self) {
		return self->m_fleets;
	}
	std::vector<Commander*> EMSCRIPTEN_KEEPALIVE Galaxy_get_commanders(Galaxy* self) {
		return self->m_commanders;
	}
	uvec2 EMSCRIPTEN_KEEPALIVE Galaxy_get_size(Galaxy* self) {
		return self->m_size;
	}
	void EMSCRIPTEN_KEEPALIVE Galaxy___destroy__(Galaxy* self) {
		delete self;
	}
	// Jump
	Jump* EMSCRIPTEN_KEEPALIVE Jump_Jump_0() {
		return new Jump();
	}
	Fleet EMSCRIPTEN_KEEPALIVE Jump_get_fleet(Jump* self) {
		return self->m_fleet;
	}
	uvec2 EMSCRIPTEN_KEEPALIVE Jump_get_start(Jump* self) {
		return self->m_start;
	}
	uvec2 EMSCRIPTEN_KEEPALIVE Jump_get_dest(Jump* self) {
		return self->m_dest;
	}
	FleetStance EMSCRIPTEN_KEEPALIVE Jump_get_stance(Jump* self) {
		return self->m_stance;
	}
	Fleet EMSCRIPTEN_KEEPALIVE Jump_get_track(Jump* self) {
		return self->m_track;
	}
	void EMSCRIPTEN_KEEPALIVE Jump___destroy__(Jump* self) {
		delete self;
	}
	// Player
	void EMSCRIPTEN_KEEPALIVE Player___destroy__(Player* self) {
		delete self;
	}
	// Scans
	Scans* EMSCRIPTEN_KEEPALIVE Scans_Scans_0() {
		return new Scans();
	}
	void EMSCRIPTEN_KEEPALIVE Scans___destroy__(Scans* self) {
		delete self;
	}
	// Schema
	Schema* EMSCRIPTEN_KEEPALIVE Schema_Schema_0() {
		return new Schema();
	}
	std::string EMSCRIPTEN_KEEPALIVE Schema_get_code(Schema* self) {
		return self->m_code;
	}
	std::string EMSCRIPTEN_KEEPALIVE Schema_get_name(Schema* self) {
		return self->m_name;
	}
	std::string EMSCRIPTEN_KEEPALIVE Schema_get_conceptor(Schema* self) {
		return self->m_conceptor;
	}
	uint8_t EMSCRIPTEN_KEEPALIVE Schema_get_level(Schema* self) {
		return self->m_level;
	}
	float EMSCRIPTEN_KEEPALIVE Schema_get_cost(Schema* self) {
		return self->m_cost;
	}
	float EMSCRIPTEN_KEEPALIVE Schema_get_minerals(Schema* self) {
		return self->m_minerals;
	}
	float EMSCRIPTEN_KEEPALIVE Schema_get_andrium(Schema* self) {
		return self->m_andrium;
	}
	float EMSCRIPTEN_KEEPALIVE Schema_get_resistance(Schema* self) {
		return self->m_resistance;
	}
	uint8_t EMSCRIPTEN_KEEPALIVE Schema_get_speed(Schema* self) {
		return self->m_speed;
	}
	uint8_t EMSCRIPTEN_KEEPALIVE Schema_get_scan(Schema* self) {
		return self->m_scan;
	}
	float EMSCRIPTEN_KEEPALIVE Schema_get_planetary(Schema* self) {
		return self->m_planetary;
	}
	SpatialPower EMSCRIPTEN_KEEPALIVE Schema_get_spatial(Schema* self) {
		return self->m_spatial;
	}
	float EMSCRIPTEN_KEEPALIVE Schema_get_upkeep_factor(Schema* self) {
		return self->m_upkeep_factor;
	}
	void EMSCRIPTEN_KEEPALIVE Schema___destroy__(Schema* self) {
		delete self;
	}
	// SpatialPower
	SpatialPower* EMSCRIPTEN_KEEPALIVE SpatialPower_SpatialPower_0() {
		return new SpatialPower();
	}
	void EMSCRIPTEN_KEEPALIVE SpatialPower___destroy__(SpatialPower* self) {
		delete self;
	}
	// Split
	Split* EMSCRIPTEN_KEEPALIVE Split_Split_0() {
		return new Split();
	}
	Fleet EMSCRIPTEN_KEEPALIVE Split_get_source(Split* self) {
		return self->m_source;
	}
	Fleet EMSCRIPTEN_KEEPALIVE Split_get_dest(Split* self) {
		return self->m_dest;
	}
	std::string EMSCRIPTEN_KEEPALIVE Split_get_code(Split* self) {
		return self->m_code;
	}
	FleetStance EMSCRIPTEN_KEEPALIVE Split_get_stance(Split* self) {
		return self->m_stance;
	}
	void EMSCRIPTEN_KEEPALIVE Split___destroy__(Split* self) {
		delete self;
	}
	// Star
	Star* EMSCRIPTEN_KEEPALIVE Star_Star_0() {
		return new Star();
	}
	Star* EMSCRIPTEN_KEEPALIVE Star_Star_4(toy::HSpatial spatial, Galaxy galaxy, const uvec2 coord, const std::string name) {
		return new Star(spatial, *galaxy, *coord, *name);
	}
	Galaxy EMSCRIPTEN_KEEPALIVE Star_get_galaxy(Star* self) {
		return self->m_galaxy;
	}
	uvec2 EMSCRIPTEN_KEEPALIVE Star_get_coord(Star* self) {
		return self->m_coord;
	}
	std::string EMSCRIPTEN_KEEPALIVE Star_get_name(Star* self) {
		return self->m_name;
	}
	int EMSCRIPTEN_KEEPALIVE Star_get_stability(Star* self) {
		return self->m_stability;
	}
	bool EMSCRIPTEN_KEEPALIVE Star_get_revolt(Star* self) {
		return self->m_revolt;
	}
	int EMSCRIPTEN_KEEPALIVE Star_get_environment(Star* self) {
		return self->m_environment;
	}
	int EMSCRIPTEN_KEEPALIVE Star_get_terraformation(Star* self) {
		return self->m_terraformation;
	}
	int EMSCRIPTEN_KEEPALIVE Star_get_base_population(Star* self) {
		return self->m_base_population;
	}
	int EMSCRIPTEN_KEEPALIVE Star_get_max_population(Star* self) {
		return self->m_max_population;
	}
	int EMSCRIPTEN_KEEPALIVE Star_get_population(Star* self) {
		return self->m_population;
	}
	float EMSCRIPTEN_KEEPALIVE Star_get_militia(Star* self) {
		return self->m_militia;
	}
	float EMSCRIPTEN_KEEPALIVE Star_get_defense(Star* self) {
		return self->m_defense;
	}
	float EMSCRIPTEN_KEEPALIVE Star_get_revenue(Star* self) {
		return self->m_revenue;
	}
	Politic EMSCRIPTEN_KEEPALIVE Star_get_politic(Star* self) {
		return self->m_politic;
	}
	Taxation EMSCRIPTEN_KEEPALIVE Star_get_taxation(Star* self) {
		return self->m_taxation;
	}
	Commander EMSCRIPTEN_KEEPALIVE Star_get_commander(Star* self) {
		return self->m_commander;
	}
	int EMSCRIPTEN_KEEPALIVE Star_get_scan(Star* self) {
		return self->m_scan;
	}
	void EMSCRIPTEN_KEEPALIVE Star___destroy__(Star* self) {
		delete self;
	}
	// TechDomain
	TechDomain* EMSCRIPTEN_KEEPALIVE TechDomain_TechDomain_0() {
		return new TechDomain();
	}
	void EMSCRIPTEN_KEEPALIVE TechDomain___destroy__(TechDomain* self) {
		delete self;
	}
	// Turn
	Turn* EMSCRIPTEN_KEEPALIVE Turn_Turn_0() {
		return new Turn();
	}
	void EMSCRIPTEN_KEEPALIVE Turn___destroy__(Turn* self) {
		delete self;
	}
	// BuildingSchema
	BuildingSchema* EMSCRIPTEN_KEEPALIVE BuildingSchema_BuildingSchema_0() {
		return new BuildingSchema();
	}
	void EMSCRIPTEN_KEEPALIVE BuildingSchema___destroy__(BuildingSchema* self) {
		delete self;
	}
	// CommanderBrush
	Commander EMSCRIPTEN_KEEPALIVE CommanderBrush_get_commander(CommanderBrush* self) {
		return self->m_commander;
	}
	float EMSCRIPTEN_KEEPALIVE CommanderBrush_get_radius(CommanderBrush* self) {
		return self->m_radius;
	}
	void EMSCRIPTEN_KEEPALIVE CommanderBrush___destroy__(CommanderBrush* self) {
		delete self;
	}
	// PlanetaryCombat
	PlanetaryCombat* EMSCRIPTEN_KEEPALIVE PlanetaryCombat_PlanetaryCombat_0() {
		return new PlanetaryCombat();
	}
	uvec2 EMSCRIPTEN_KEEPALIVE PlanetaryCombat_get_coord(PlanetaryCombat* self) {
		return self->m_coord;
	}
	std::vector<CombatFleet> EMSCRIPTEN_KEEPALIVE PlanetaryCombat_get_attack(PlanetaryCombat* self) {
		return self->m_attack;
	}
	CombatStar EMSCRIPTEN_KEEPALIVE PlanetaryCombat_get_defense(PlanetaryCombat* self) {
		return self->m_defense;
	}
	void EMSCRIPTEN_KEEPALIVE PlanetaryCombat___destroy__(PlanetaryCombat* self) {
		delete self;
	}
	// ShipComponent
	ShipComponent* EMSCRIPTEN_KEEPALIVE ShipComponent_ShipComponent_0() {
		return new ShipComponent();
	}
	void EMSCRIPTEN_KEEPALIVE ShipComponent___destroy__(ShipComponent* self) {
		delete self;
	}
	// ShipEngine
	ShipEngine* EMSCRIPTEN_KEEPALIVE ShipEngine_ShipEngine_0() {
		return new ShipEngine();
	}
	void EMSCRIPTEN_KEEPALIVE ShipEngine___destroy__(ShipEngine* self) {
		delete self;
	}
	// ShipHull
	ShipHull* EMSCRIPTEN_KEEPALIVE ShipHull_ShipHull_0() {
		return new ShipHull();
	}
	void EMSCRIPTEN_KEEPALIVE ShipHull___destroy__(ShipHull* self) {
		delete self;
	}
	// ShipSchema
	ShipSchema* EMSCRIPTEN_KEEPALIVE ShipSchema_ShipSchema_0() {
		return new ShipSchema();
	}
	uint8_t EMSCRIPTEN_KEEPALIVE ShipSchema_get_size(ShipSchema* self) {
		return self->m_size;
	}
	uint8_t EMSCRIPTEN_KEEPALIVE ShipSchema_get_class(ShipSchema* self) {
		return self->m_class;
	}
	WeaponType EMSCRIPTEN_KEEPALIVE ShipSchema_get_main_weapon(ShipSchema* self) {
		return self->m_main_weapon;
	}
	void EMSCRIPTEN_KEEPALIVE ShipSchema___destroy__(ShipSchema* self) {
		delete self;
	}
	// SpatialCombat
	SpatialCombat* EMSCRIPTEN_KEEPALIVE SpatialCombat_SpatialCombat_0() {
		return new SpatialCombat();
	}
	uvec2 EMSCRIPTEN_KEEPALIVE SpatialCombat_get_coord(SpatialCombat* self) {
		return self->m_coord;
	}
	std::vector<CombatFleet> EMSCRIPTEN_KEEPALIVE SpatialCombat_get_attack(SpatialCombat* self) {
		return self->m_attack;
	}
	std::vector<CombatFleet> EMSCRIPTEN_KEEPALIVE SpatialCombat_get_defense(SpatialCombat* self) {
		return self->m_defense;
	}
	void EMSCRIPTEN_KEEPALIVE SpatialCombat___destroy__(SpatialCombat* self) {
		delete self;
	}
	// Universe
	Universe* EMSCRIPTEN_KEEPALIVE Universe_Universe_2(const std::string name, JobSystem job_system) {
		return new Universe(*name, *job_system);
	}
	World EMSCRIPTEN_KEEPALIVE Universe_get_world(Universe* self) {
		return self->m_world;
	}
	BulletWorld EMSCRIPTEN_KEEPALIVE Universe_get_bullet_world(Universe* self) {
		return self->m_bullet_world;
	}
	void EMSCRIPTEN_KEEPALIVE Universe___destroy__(Universe* self) {
		delete self;
	}
	// CombatType
	CombatType EMSCRIPTEN_KEEPALIVE emscripten_enum_CombatType_Spatial() {
		return CombatType::Spatial;
	}
	CombatType EMSCRIPTEN_KEEPALIVE emscripten_enum_CombatType_Planetary() {
		return CombatType::Planetary;
	}
	// Experience
	Experience EMSCRIPTEN_KEEPALIVE emscripten_enum_Experience_Inexperienced() {
		return Experience::Inexperienced;
	}
	Experience EMSCRIPTEN_KEEPALIVE emscripten_enum_Experience_LittleExperienced() {
		return Experience::LittleExperienced;
	}
	Experience EMSCRIPTEN_KEEPALIVE emscripten_enum_Experience_Experienced() {
		return Experience::Experienced;
	}
	Experience EMSCRIPTEN_KEEPALIVE emscripten_enum_Experience_Superior() {
		return Experience::Superior;
	}
	Experience EMSCRIPTEN_KEEPALIVE emscripten_enum_Experience_Elite() {
		return Experience::Elite;
	}
	// FleetSize
	FleetSize EMSCRIPTEN_KEEPALIVE emscripten_enum_FleetSize_Ridicule() {
		return FleetSize::Ridicule;
	}
	FleetSize EMSCRIPTEN_KEEPALIVE emscripten_enum_FleetSize_Minuscule() {
		return FleetSize::Minuscule;
	}
	FleetSize EMSCRIPTEN_KEEPALIVE emscripten_enum_FleetSize_Tiny() {
		return FleetSize::Tiny;
	}
	FleetSize EMSCRIPTEN_KEEPALIVE emscripten_enum_FleetSize_Small() {
		return FleetSize::Small;
	}
	FleetSize EMSCRIPTEN_KEEPALIVE emscripten_enum_FleetSize_Medium() {
		return FleetSize::Medium;
	}
	FleetSize EMSCRIPTEN_KEEPALIVE emscripten_enum_FleetSize_Respectable() {
		return FleetSize::Respectable;
	}
	FleetSize EMSCRIPTEN_KEEPALIVE emscripten_enum_FleetSize_Grand() {
		return FleetSize::Grand;
	}
	FleetSize EMSCRIPTEN_KEEPALIVE emscripten_enum_FleetSize_HighGrand() {
		return FleetSize::HighGrand;
	}
	FleetSize EMSCRIPTEN_KEEPALIVE emscripten_enum_FleetSize_Colossal() {
		return FleetSize::Colossal;
	}
	FleetSize EMSCRIPTEN_KEEPALIVE emscripten_enum_FleetSize_Titanesque() {
		return FleetSize::Titanesque;
	}
	FleetSize EMSCRIPTEN_KEEPALIVE emscripten_enum_FleetSize_Cyclopean() {
		return FleetSize::Cyclopean;
	}
	FleetSize EMSCRIPTEN_KEEPALIVE emscripten_enum_FleetSize_Divine() {
		return FleetSize::Divine;
	}
	FleetSize EMSCRIPTEN_KEEPALIVE emscripten_enum_FleetSize_Count() {
		return FleetSize::Count;
	}
	// FleetStance
	FleetStance EMSCRIPTEN_KEEPALIVE emscripten_enum_FleetStance_Movement() {
		return FleetStance::Movement;
	}
	FleetStance EMSCRIPTEN_KEEPALIVE emscripten_enum_FleetStance_SpatialAttack() {
		return FleetStance::SpatialAttack;
	}
	FleetStance EMSCRIPTEN_KEEPALIVE emscripten_enum_FleetStance_SpatialDefense() {
		return FleetStance::SpatialDefense;
	}
	FleetStance EMSCRIPTEN_KEEPALIVE emscripten_enum_FleetStance_PlanetaryAttack() {
		return FleetStance::PlanetaryAttack;
	}
	FleetStance EMSCRIPTEN_KEEPALIVE emscripten_enum_FleetStance_PlanetaryDefense() {
		return FleetStance::PlanetaryDefense;
	}
	FleetStance EMSCRIPTEN_KEEPALIVE emscripten_enum_FleetStance_Pillage() {
		return FleetStance::Pillage;
	}
	// GameStage
	GameStage EMSCRIPTEN_KEEPALIVE emscripten_enum_GameStage_Empire() {
		return GameStage::Empire;
	}
	GameStage EMSCRIPTEN_KEEPALIVE emscripten_enum_GameStage_Tactics() {
		return GameStage::Tactics;
	}
	GameStage EMSCRIPTEN_KEEPALIVE emscripten_enum_GameStage_TurnReport() {
		return GameStage::TurnReport;
	}
	// Politic
	Politic EMSCRIPTEN_KEEPALIVE emscripten_enum_Politic_Taxes() {
		return Politic::Taxes;
	}
	Politic EMSCRIPTEN_KEEPALIVE emscripten_enum_Politic_Commerce() {
		return Politic::Commerce;
	}
	Politic EMSCRIPTEN_KEEPALIVE emscripten_enum_Politic_Construction() {
		return Politic::Construction;
	}
	Politic EMSCRIPTEN_KEEPALIVE emscripten_enum_Politic_Defense() {
		return Politic::Defense;
	}
	Politic EMSCRIPTEN_KEEPALIVE emscripten_enum_Politic_Pacification() {
		return Politic::Pacification;
	}
	// Race
	Race EMSCRIPTEN_KEEPALIVE emscripten_enum_Race_Human() {
		return Race::Human;
	}
	Race EMSCRIPTEN_KEEPALIVE emscripten_enum_Race_Bulvoid() {
		return Race::Bulvoid;
	}
	Race EMSCRIPTEN_KEEPALIVE emscripten_enum_Race_Techtulon() {
		return Race::Techtulon;
	}
	Race EMSCRIPTEN_KEEPALIVE emscripten_enum_Race_Rakrarior() {
		return Race::Rakrarior;
	}
	Race EMSCRIPTEN_KEEPALIVE emscripten_enum_Race_Seigneur() {
		return Race::Seigneur;
	}
	Race EMSCRIPTEN_KEEPALIVE emscripten_enum_Race_Meton() {
		return Race::Meton;
	}
	Race EMSCRIPTEN_KEEPALIVE emscripten_enum_Race_Tissinar() {
		return Race::Tissinar;
	}
	Race EMSCRIPTEN_KEEPALIVE emscripten_enum_Race_Zwiie() {
		return Race::Zwiie;
	}
	// Regime
	Regime EMSCRIPTEN_KEEPALIVE emscripten_enum_Regime_Empire() {
		return Regime::Empire;
	}
	Regime EMSCRIPTEN_KEEPALIVE emscripten_enum_Regime_Dictature() {
		return Regime::Dictature;
	}
	Regime EMSCRIPTEN_KEEPALIVE emscripten_enum_Regime_Democracy() {
		return Regime::Democracy;
	}
	Regime EMSCRIPTEN_KEEPALIVE emscripten_enum_Regime_Theocracy() {
		return Regime::Theocracy;
	}
	Regime EMSCRIPTEN_KEEPALIVE emscripten_enum_Regime_Technocracy() {
		return Regime::Technocracy;
	}
	Regime EMSCRIPTEN_KEEPALIVE emscripten_enum_Regime_Piratery() {
		return Regime::Piratery;
	}
	// Resource
	Resource EMSCRIPTEN_KEEPALIVE emscripten_enum_Resource_None() {
		return Resource::None;
	}
	Resource EMSCRIPTEN_KEEPALIVE emscripten_enum_Resource_Minerals() {
		return Resource::Minerals;
	}
	Resource EMSCRIPTEN_KEEPALIVE emscripten_enum_Resource_Andrium() {
		return Resource::Andrium;
	}
	Resource EMSCRIPTEN_KEEPALIVE emscripten_enum_Resource_Alcool() {
		return Resource::Alcool;
	}
	Resource EMSCRIPTEN_KEEPALIVE emscripten_enum_Resource_Slaves() {
		return Resource::Slaves;
	}
	Resource EMSCRIPTEN_KEEPALIVE emscripten_enum_Resource_Narcotics() {
		return Resource::Narcotics;
	}
	Resource EMSCRIPTEN_KEEPALIVE emscripten_enum_Resource_Food() {
		return Resource::Food;
	}
	Resource EMSCRIPTEN_KEEPALIVE emscripten_enum_Resource_Medicine() {
		return Resource::Medicine;
	}
	Resource EMSCRIPTEN_KEEPALIVE emscripten_enum_Resource_Computers() {
		return Resource::Computers;
	}
	Resource EMSCRIPTEN_KEEPALIVE emscripten_enum_Resource_Plastic() {
		return Resource::Plastic;
	}
	Resource EMSCRIPTEN_KEEPALIVE emscripten_enum_Resource_Robot() {
		return Resource::Robot;
	}
	Resource EMSCRIPTEN_KEEPALIVE emscripten_enum_Resource_Count() {
		return Resource::Count;
	}
	// Taxation
	Taxation EMSCRIPTEN_KEEPALIVE emscripten_enum_Taxation_None() {
		return Taxation::None;
	}
	Taxation EMSCRIPTEN_KEEPALIVE emscripten_enum_Taxation_Light() {
		return Taxation::Light;
	}
	Taxation EMSCRIPTEN_KEEPALIVE emscripten_enum_Taxation_Medium() {
		return Taxation::Medium;
	}
	Taxation EMSCRIPTEN_KEEPALIVE emscripten_enum_Taxation_Heavy() {
		return Taxation::Heavy;
	}
	Taxation EMSCRIPTEN_KEEPALIVE emscripten_enum_Taxation_Heaviest() {
		return Taxation::Heaviest;
	}
	Taxation EMSCRIPTEN_KEEPALIVE emscripten_enum_Taxation_Total() {
		return Taxation::Total;
	}
	// Technology
	Technology EMSCRIPTEN_KEEPALIVE emscripten_enum_Technology_Engines() {
		return Technology::Engines;
	}
	Technology EMSCRIPTEN_KEEPALIVE emscripten_enum_Technology_EcoEnergy() {
		return Technology::EcoEnergy;
	}
	Technology EMSCRIPTEN_KEEPALIVE emscripten_enum_Technology_Scanners() {
		return Technology::Scanners;
	}
	Technology EMSCRIPTEN_KEEPALIVE emscripten_enum_Technology_PlanetaryShields() {
		return Technology::PlanetaryShields;
	}
	Technology EMSCRIPTEN_KEEPALIVE emscripten_enum_Technology_SpatialShields() {
		return Technology::SpatialShields;
	}
	Technology EMSCRIPTEN_KEEPALIVE emscripten_enum_Technology_LaserPlasmaIons() {
		return Technology::LaserPlasmaIons;
	}
	Technology EMSCRIPTEN_KEEPALIVE emscripten_enum_Technology_Torpedoes() {
		return Technology::Torpedoes;
	}
	Technology EMSCRIPTEN_KEEPALIVE emscripten_enum_Technology_Bombs() {
		return Technology::Bombs;
	}
	Technology EMSCRIPTEN_KEEPALIVE emscripten_enum_Technology_HullArmor() {
		return Technology::HullArmor;
	}
	Technology EMSCRIPTEN_KEEPALIVE emscripten_enum_Technology_Mining() {
		return Technology::Mining;
	}
	Technology EMSCRIPTEN_KEEPALIVE emscripten_enum_Technology_Terraforming() {
		return Technology::Terraforming;
	}
	Technology EMSCRIPTEN_KEEPALIVE emscripten_enum_Technology_Construction() {
		return Technology::Construction;
	}
	Technology EMSCRIPTEN_KEEPALIVE emscripten_enum_Technology_Piloting() {
		return Technology::Piloting;
	}
	Technology EMSCRIPTEN_KEEPALIVE emscripten_enum_Technology_Commerce() {
		return Technology::Commerce;
	}
	Technology EMSCRIPTEN_KEEPALIVE emscripten_enum_Technology_Personnel() {
		return Technology::Personnel;
	}
	Technology EMSCRIPTEN_KEEPALIVE emscripten_enum_Technology_Administration() {
		return Technology::Administration;
	}
	Technology EMSCRIPTEN_KEEPALIVE emscripten_enum_Technology_CyberCommand() {
		return Technology::CyberCommand;
	}
	Technology EMSCRIPTEN_KEEPALIVE emscripten_enum_Technology_CyberCommerce() {
		return Technology::CyberCommerce;
	}
	Technology EMSCRIPTEN_KEEPALIVE emscripten_enum_Technology_CyberDiplomacy() {
		return Technology::CyberDiplomacy;
	}
	Technology EMSCRIPTEN_KEEPALIVE emscripten_enum_Technology_Count() {
		return Technology::Count;
	}
	// WeaponType
	WeaponType EMSCRIPTEN_KEEPALIVE emscripten_enum_WeaponType_None() {
		return WeaponType::None;
	}
	WeaponType EMSCRIPTEN_KEEPALIVE emscripten_enum_WeaponType_Ion() {
		return WeaponType::Ion;
	}
	WeaponType EMSCRIPTEN_KEEPALIVE emscripten_enum_WeaponType_Laser() {
		return WeaponType::Laser;
	}
	WeaponType EMSCRIPTEN_KEEPALIVE emscripten_enum_WeaponType_Plasma() {
		return WeaponType::Plasma;
	}
	WeaponType EMSCRIPTEN_KEEPALIVE emscripten_enum_WeaponType_Torpedo() {
		return WeaponType::Torpedo;
	}
	WeaponType EMSCRIPTEN_KEEPALIVE emscripten_enum_WeaponType_Bomb() {
		return WeaponType::Bomb;
	}
	
}


