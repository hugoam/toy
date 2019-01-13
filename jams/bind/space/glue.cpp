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
	Commander* EMSCRIPTEN_KEEPALIVE Commander_Commander_6(mud::Id id, const char* name, Race race, int command, int commerce, int diplomacy) {
		return new Commander(id, name, race, command, commerce, diplomacy);
	}
	mud::Id EMSCRIPTEN_KEEPALIVE Commander_get_id(Commander* self) {
		return self->m_id;
	}
	void EMSCRIPTEN_KEEPALIVE Commander_set_id(Commander* self, mud::Id id) {
		self->m_id = id;
	}
	const char* EMSCRIPTEN_KEEPALIVE Commander_get_name(Commander* self) {
		return self->m_name.c_str();
	}
	void EMSCRIPTEN_KEEPALIVE Commander_set_name(Commander* self, const char* name) {
		self->m_name = name;
	}
	Race EMSCRIPTEN_KEEPALIVE Commander_get_race(Commander* self) {
		return self->m_race;
	}
	void EMSCRIPTEN_KEEPALIVE Commander_set_race(Commander* self, Race race) {
		self->m_race = race;
	}
	int EMSCRIPTEN_KEEPALIVE Commander_get_command(Commander* self) {
		return self->m_command;
	}
	void EMSCRIPTEN_KEEPALIVE Commander_set_command(Commander* self, int command) {
		self->m_command = command;
	}
	int EMSCRIPTEN_KEEPALIVE Commander_get_commerce(Commander* self) {
		return self->m_commerce;
	}
	void EMSCRIPTEN_KEEPALIVE Commander_set_commerce(Commander* self, int commerce) {
		self->m_commerce = commerce;
	}
	int EMSCRIPTEN_KEEPALIVE Commander_get_diplomacy(Commander* self) {
		return self->m_diplomacy;
	}
	void EMSCRIPTEN_KEEPALIVE Commander_set_diplomacy(Commander* self, int diplomacy) {
		self->m_diplomacy = diplomacy;
	}
	int EMSCRIPTEN_KEEPALIVE Commander_get_reputation(Commander* self) {
		return self->m_reputation;
	}
	void EMSCRIPTEN_KEEPALIVE Commander_set_reputation(Commander* self, int reputation) {
		self->m_reputation = reputation;
	}
	int EMSCRIPTEN_KEEPALIVE Commander_get_victory(Commander* self) {
		return self->m_victory;
	}
	void EMSCRIPTEN_KEEPALIVE Commander_set_victory(Commander* self, int victory) {
		self->m_victory = victory;
	}
	Star* EMSCRIPTEN_KEEPALIVE Commander_get_capital(Commander* self) {
		return self->m_capital;
	}
	void EMSCRIPTEN_KEEPALIVE Commander_set_capital(Commander* self, Star* capital) {
		self->m_capital = capital;
	}
	Regime EMSCRIPTEN_KEEPALIVE Commander_get_regime(Commander* self) {
		return self->m_regime;
	}
	void EMSCRIPTEN_KEEPALIVE Commander_set_regime(Commander* self, Regime regime) {
		self->m_regime = regime;
	}
	float EMSCRIPTEN_KEEPALIVE Commander_get_power(Commander* self) {
		return self->m_power;
	}
	void EMSCRIPTEN_KEEPALIVE Commander_set_power(Commander* self, float power) {
		self->m_power = power;
	}
	float EMSCRIPTEN_KEEPALIVE Commander_get_centaures(Commander* self) {
		return self->m_centaures;
	}
	void EMSCRIPTEN_KEEPALIVE Commander_set_centaures(Commander* self, float centaures) {
		self->m_centaures = centaures;
	}
	Scans* EMSCRIPTEN_KEEPALIVE Commander_get_scans(Commander* self) {
		static Scans temp;
		return (temp = self->m_scans, &temp);
	}
	void EMSCRIPTEN_KEEPALIVE Commander_set_scans(Commander* self, Scans* scans) {
		self->m_scans = *scans;
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
	Fleet* EMSCRIPTEN_KEEPALIVE Fleet_Fleet_5(toy::HSpatial spatial, Galaxy* galaxy, Commander* commander, const mud::uvec2* coord, const char* name) {
		return new Fleet(spatial, *galaxy, *commander, *coord, name);
	}
	void EMSCRIPTEN_KEEPALIVE Fleet_order_attack_1(Fleet* self, Star* star) {
		self->order_attack(*star);
	}
	void EMSCRIPTEN_KEEPALIVE Fleet_order_jump_2(Fleet* self, mud::vec2* coord, FleetStance stance) {
		self->order_jump(*coord, stance);
	}
	Galaxy* EMSCRIPTEN_KEEPALIVE Fleet_get_galaxy(Fleet* self) {
		return self->m_galaxy;
	}
	void EMSCRIPTEN_KEEPALIVE Fleet_set_galaxy(Fleet* self, Galaxy* galaxy) {
		self->m_galaxy = galaxy;
	}
	Commander* EMSCRIPTEN_KEEPALIVE Fleet_get_commander(Fleet* self) {
		return self->m_commander;
	}
	void EMSCRIPTEN_KEEPALIVE Fleet_set_commander(Fleet* self, Commander* commander) {
		self->m_commander = commander;
	}
	mud::uvec2* EMSCRIPTEN_KEEPALIVE Fleet_get_coord(Fleet* self) {
		static mud::uvec2 temp;
		return (temp = self->m_coord, &temp);
	}
	void EMSCRIPTEN_KEEPALIVE Fleet_set_coord(Fleet* self, mud::uvec2* coord) {
		self->m_coord = *coord;
	}
	mud::vec3* EMSCRIPTEN_KEEPALIVE Fleet_get_slot(Fleet* self) {
		static mud::vec3 temp;
		return (temp = self->m_slot, &temp);
	}
	void EMSCRIPTEN_KEEPALIVE Fleet_set_slot(Fleet* self, mud::vec3* slot) {
		self->m_slot = *slot;
	}
	const char* EMSCRIPTEN_KEEPALIVE Fleet_get_name(Fleet* self) {
		return self->m_name.c_str();
	}
	void EMSCRIPTEN_KEEPALIVE Fleet_set_name(Fleet* self, const char* name) {
		self->m_name = name;
	}
	float EMSCRIPTEN_KEEPALIVE Fleet_get_experience(Fleet* self) {
		return self->m_experience;
	}
	void EMSCRIPTEN_KEEPALIVE Fleet_set_experience(Fleet* self, float experience) {
		self->m_experience = experience;
	}
	SpatialPower* EMSCRIPTEN_KEEPALIVE Fleet_get_spatial_power(Fleet* self) {
		static SpatialPower temp;
		return (temp = self->m_spatial_power, &temp);
	}
	void EMSCRIPTEN_KEEPALIVE Fleet_set_spatial_power(Fleet* self, SpatialPower* spatial_power) {
		self->m_spatial_power = *spatial_power;
	}
	float EMSCRIPTEN_KEEPALIVE Fleet_get_planetary_power(Fleet* self) {
		return self->m_planetary_power;
	}
	void EMSCRIPTEN_KEEPALIVE Fleet_set_planetary_power(Fleet* self, float planetary_power) {
		self->m_planetary_power = planetary_power;
	}
	uint8_t EMSCRIPTEN_KEEPALIVE Fleet_get_speed(Fleet* self) {
		return self->m_speed;
	}
	void EMSCRIPTEN_KEEPALIVE Fleet_set_speed(Fleet* self, uint8_t speed) {
		self->m_speed = speed;
	}
	uint8_t EMSCRIPTEN_KEEPALIVE Fleet_get_scan(Fleet* self) {
		return self->m_scan;
	}
	void EMSCRIPTEN_KEEPALIVE Fleet_set_scan(Fleet* self, uint8_t scan) {
		self->m_scan = scan;
	}
	float EMSCRIPTEN_KEEPALIVE Fleet_get_upkeep(Fleet* self) {
		return self->m_upkeep;
	}
	void EMSCRIPTEN_KEEPALIVE Fleet_set_upkeep(Fleet* self, float upkeep) {
		self->m_upkeep = upkeep;
	}
	FleetStance EMSCRIPTEN_KEEPALIVE Fleet_get_stance(Fleet* self) {
		return self->m_stance;
	}
	void EMSCRIPTEN_KEEPALIVE Fleet_set_stance(Fleet* self, FleetStance stance) {
		self->m_stance = stance;
	}
	Jump* EMSCRIPTEN_KEEPALIVE Fleet_get_jump(Fleet* self) {
		static Jump temp;
		return (temp = self->m_jump, &temp);
	}
	void EMSCRIPTEN_KEEPALIVE Fleet_set_jump(Fleet* self, Jump* jump) {
		self->m_jump = *jump;
	}
	Split* EMSCRIPTEN_KEEPALIVE Fleet_get_split(Fleet* self) {
		static Split temp;
		return (temp = self->m_split, &temp);
	}
	void EMSCRIPTEN_KEEPALIVE Fleet_set_split(Fleet* self, Split* split) {
		self->m_split = *split;
	}
	bool EMSCRIPTEN_KEEPALIVE Fleet_get_fought(Fleet* self) {
		return self->m_fought;
	}
	void EMSCRIPTEN_KEEPALIVE Fleet_set_fought(Fleet* self, bool fought) {
		self->m_fought = fought;
	}
	size_t EMSCRIPTEN_KEEPALIVE Fleet_get_ships_updated(Fleet* self) {
		return self->m_ships_updated;
	}
	void EMSCRIPTEN_KEEPALIVE Fleet_set_ships_updated(Fleet* self, size_t ships_updated) {
		self->m_ships_updated = ships_updated;
	}
	void EMSCRIPTEN_KEEPALIVE Fleet___destroy__(Fleet* self) {
		delete self;
	}
	// Galaxy
	Galaxy* EMSCRIPTEN_KEEPALIVE Galaxy_Galaxy_0() {
		return new Galaxy();
	}
	Galaxy* EMSCRIPTEN_KEEPALIVE Galaxy_Galaxy_2(toy::HSpatial spatial, const mud::uvec2* size) {
		return new Galaxy(spatial, *size);
	}
	mud::uvec2* EMSCRIPTEN_KEEPALIVE Galaxy_get_size(Galaxy* self) {
		static mud::uvec2 temp;
		return (temp = self->m_size, &temp);
	}
	void EMSCRIPTEN_KEEPALIVE Galaxy_set_size(Galaxy* self, mud::uvec2* size) {
		self->m_size = *size;
	}
	void EMSCRIPTEN_KEEPALIVE Galaxy___destroy__(Galaxy* self) {
		delete self;
	}
	// Jump
	Jump* EMSCRIPTEN_KEEPALIVE Jump_Jump_0() {
		return new Jump();
	}
	Fleet* EMSCRIPTEN_KEEPALIVE Jump_get_fleet(Jump* self) {
		return self->m_fleet;
	}
	void EMSCRIPTEN_KEEPALIVE Jump_set_fleet(Jump* self, Fleet* fleet) {
		self->m_fleet = fleet;
	}
	mud::uvec2* EMSCRIPTEN_KEEPALIVE Jump_get_start(Jump* self) {
		static mud::uvec2 temp;
		return (temp = self->m_start, &temp);
	}
	void EMSCRIPTEN_KEEPALIVE Jump_set_start(Jump* self, mud::uvec2* start) {
		self->m_start = *start;
	}
	mud::uvec2* EMSCRIPTEN_KEEPALIVE Jump_get_dest(Jump* self) {
		static mud::uvec2 temp;
		return (temp = self->m_dest, &temp);
	}
	void EMSCRIPTEN_KEEPALIVE Jump_set_dest(Jump* self, mud::uvec2* dest) {
		self->m_dest = *dest;
	}
	FleetStance EMSCRIPTEN_KEEPALIVE Jump_get_stance(Jump* self) {
		return self->m_stance;
	}
	void EMSCRIPTEN_KEEPALIVE Jump_set_stance(Jump* self, FleetStance stance) {
		self->m_stance = stance;
	}
	Fleet* EMSCRIPTEN_KEEPALIVE Jump_get_track(Jump* self) {
		return self->m_track;
	}
	void EMSCRIPTEN_KEEPALIVE Jump_set_track(Jump* self, Fleet* track) {
		self->m_track = track;
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
	const char* EMSCRIPTEN_KEEPALIVE Schema_get_code(Schema* self) {
		return self->m_code.c_str();
	}
	void EMSCRIPTEN_KEEPALIVE Schema_set_code(Schema* self, const char* code) {
		self->m_code = code;
	}
	const char* EMSCRIPTEN_KEEPALIVE Schema_get_name(Schema* self) {
		return self->m_name.c_str();
	}
	void EMSCRIPTEN_KEEPALIVE Schema_set_name(Schema* self, const char* name) {
		self->m_name = name;
	}
	const char* EMSCRIPTEN_KEEPALIVE Schema_get_conceptor(Schema* self) {
		return self->m_conceptor.c_str();
	}
	void EMSCRIPTEN_KEEPALIVE Schema_set_conceptor(Schema* self, const char* conceptor) {
		self->m_conceptor = conceptor;
	}
	uint8_t EMSCRIPTEN_KEEPALIVE Schema_get_level(Schema* self) {
		return self->m_level;
	}
	void EMSCRIPTEN_KEEPALIVE Schema_set_level(Schema* self, uint8_t level) {
		self->m_level = level;
	}
	float EMSCRIPTEN_KEEPALIVE Schema_get_cost(Schema* self) {
		return self->m_cost;
	}
	void EMSCRIPTEN_KEEPALIVE Schema_set_cost(Schema* self, float cost) {
		self->m_cost = cost;
	}
	float EMSCRIPTEN_KEEPALIVE Schema_get_minerals(Schema* self) {
		return self->m_minerals;
	}
	void EMSCRIPTEN_KEEPALIVE Schema_set_minerals(Schema* self, float minerals) {
		self->m_minerals = minerals;
	}
	float EMSCRIPTEN_KEEPALIVE Schema_get_andrium(Schema* self) {
		return self->m_andrium;
	}
	void EMSCRIPTEN_KEEPALIVE Schema_set_andrium(Schema* self, float andrium) {
		self->m_andrium = andrium;
	}
	float EMSCRIPTEN_KEEPALIVE Schema_get_resistance(Schema* self) {
		return self->m_resistance;
	}
	void EMSCRIPTEN_KEEPALIVE Schema_set_resistance(Schema* self, float resistance) {
		self->m_resistance = resistance;
	}
	uint8_t EMSCRIPTEN_KEEPALIVE Schema_get_speed(Schema* self) {
		return self->m_speed;
	}
	void EMSCRIPTEN_KEEPALIVE Schema_set_speed(Schema* self, uint8_t speed) {
		self->m_speed = speed;
	}
	uint8_t EMSCRIPTEN_KEEPALIVE Schema_get_scan(Schema* self) {
		return self->m_scan;
	}
	void EMSCRIPTEN_KEEPALIVE Schema_set_scan(Schema* self, uint8_t scan) {
		self->m_scan = scan;
	}
	float EMSCRIPTEN_KEEPALIVE Schema_get_planetary(Schema* self) {
		return self->m_planetary;
	}
	void EMSCRIPTEN_KEEPALIVE Schema_set_planetary(Schema* self, float planetary) {
		self->m_planetary = planetary;
	}
	SpatialPower* EMSCRIPTEN_KEEPALIVE Schema_get_spatial(Schema* self) {
		static SpatialPower temp;
		return (temp = self->m_spatial, &temp);
	}
	void EMSCRIPTEN_KEEPALIVE Schema_set_spatial(Schema* self, SpatialPower* spatial) {
		self->m_spatial = *spatial;
	}
	float EMSCRIPTEN_KEEPALIVE Schema_get_upkeep_factor(Schema* self) {
		return self->m_upkeep_factor;
	}
	void EMSCRIPTEN_KEEPALIVE Schema_set_upkeep_factor(Schema* self, float upkeep_factor) {
		self->m_upkeep_factor = upkeep_factor;
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
	Fleet* EMSCRIPTEN_KEEPALIVE Split_get_source(Split* self) {
		return self->m_source;
	}
	void EMSCRIPTEN_KEEPALIVE Split_set_source(Split* self, Fleet* source) {
		self->m_source = source;
	}
	Fleet* EMSCRIPTEN_KEEPALIVE Split_get_dest(Split* self) {
		return self->m_dest;
	}
	void EMSCRIPTEN_KEEPALIVE Split_set_dest(Split* self, Fleet* dest) {
		self->m_dest = dest;
	}
	const char* EMSCRIPTEN_KEEPALIVE Split_get_code(Split* self) {
		return self->m_code.c_str();
	}
	void EMSCRIPTEN_KEEPALIVE Split_set_code(Split* self, const char* code) {
		self->m_code = code;
	}
	FleetStance EMSCRIPTEN_KEEPALIVE Split_get_stance(Split* self) {
		return self->m_stance;
	}
	void EMSCRIPTEN_KEEPALIVE Split_set_stance(Split* self, FleetStance stance) {
		self->m_stance = stance;
	}
	void EMSCRIPTEN_KEEPALIVE Split___destroy__(Split* self) {
		delete self;
	}
	// Star
	Star* EMSCRIPTEN_KEEPALIVE Star_Star_0() {
		return new Star();
	}
	Star* EMSCRIPTEN_KEEPALIVE Star_Star_4(toy::HSpatial spatial, Galaxy* galaxy, const mud::uvec2* coord, const char* name) {
		return new Star(spatial, *galaxy, *coord, name);
	}
	Galaxy* EMSCRIPTEN_KEEPALIVE Star_get_galaxy(Star* self) {
		return self->m_galaxy;
	}
	void EMSCRIPTEN_KEEPALIVE Star_set_galaxy(Star* self, Galaxy* galaxy) {
		self->m_galaxy = galaxy;
	}
	mud::uvec2* EMSCRIPTEN_KEEPALIVE Star_get_coord(Star* self) {
		static mud::uvec2 temp;
		return (temp = self->m_coord, &temp);
	}
	void EMSCRIPTEN_KEEPALIVE Star_set_coord(Star* self, mud::uvec2* coord) {
		self->m_coord = *coord;
	}
	const char* EMSCRIPTEN_KEEPALIVE Star_get_name(Star* self) {
		return self->m_name.c_str();
	}
	void EMSCRIPTEN_KEEPALIVE Star_set_name(Star* self, const char* name) {
		self->m_name = name;
	}
	int EMSCRIPTEN_KEEPALIVE Star_get_stability(Star* self) {
		return self->m_stability;
	}
	void EMSCRIPTEN_KEEPALIVE Star_set_stability(Star* self, int stability) {
		self->m_stability = stability;
	}
	bool EMSCRIPTEN_KEEPALIVE Star_get_revolt(Star* self) {
		return self->m_revolt;
	}
	void EMSCRIPTEN_KEEPALIVE Star_set_revolt(Star* self, bool revolt) {
		self->m_revolt = revolt;
	}
	int EMSCRIPTEN_KEEPALIVE Star_get_environment(Star* self) {
		return self->m_environment;
	}
	void EMSCRIPTEN_KEEPALIVE Star_set_environment(Star* self, int environment) {
		self->m_environment = environment;
	}
	int EMSCRIPTEN_KEEPALIVE Star_get_terraformation(Star* self) {
		return self->m_terraformation;
	}
	void EMSCRIPTEN_KEEPALIVE Star_set_terraformation(Star* self, int terraformation) {
		self->m_terraformation = terraformation;
	}
	int EMSCRIPTEN_KEEPALIVE Star_get_base_population(Star* self) {
		return self->m_base_population;
	}
	void EMSCRIPTEN_KEEPALIVE Star_set_base_population(Star* self, int base_population) {
		self->m_base_population = base_population;
	}
	int EMSCRIPTEN_KEEPALIVE Star_get_max_population(Star* self) {
		return self->m_max_population;
	}
	void EMSCRIPTEN_KEEPALIVE Star_set_max_population(Star* self, int max_population) {
		self->m_max_population = max_population;
	}
	int EMSCRIPTEN_KEEPALIVE Star_get_population(Star* self) {
		return self->m_population;
	}
	void EMSCRIPTEN_KEEPALIVE Star_set_population(Star* self, int population) {
		self->m_population = population;
	}
	float EMSCRIPTEN_KEEPALIVE Star_get_militia(Star* self) {
		return self->m_militia;
	}
	void EMSCRIPTEN_KEEPALIVE Star_set_militia(Star* self, float militia) {
		self->m_militia = militia;
	}
	float EMSCRIPTEN_KEEPALIVE Star_get_defense(Star* self) {
		return self->m_defense;
	}
	void EMSCRIPTEN_KEEPALIVE Star_set_defense(Star* self, float defense) {
		self->m_defense = defense;
	}
	float EMSCRIPTEN_KEEPALIVE Star_get_revenue(Star* self) {
		return self->m_revenue;
	}
	void EMSCRIPTEN_KEEPALIVE Star_set_revenue(Star* self, float revenue) {
		self->m_revenue = revenue;
	}
	Politic EMSCRIPTEN_KEEPALIVE Star_get_politic(Star* self) {
		return self->m_politic;
	}
	void EMSCRIPTEN_KEEPALIVE Star_set_politic(Star* self, Politic politic) {
		self->m_politic = politic;
	}
	Taxation EMSCRIPTEN_KEEPALIVE Star_get_taxation(Star* self) {
		return self->m_taxation;
	}
	void EMSCRIPTEN_KEEPALIVE Star_set_taxation(Star* self, Taxation taxation) {
		self->m_taxation = taxation;
	}
	Commander* EMSCRIPTEN_KEEPALIVE Star_get_commander(Star* self) {
		return self->m_commander;
	}
	void EMSCRIPTEN_KEEPALIVE Star_set_commander(Star* self, Commander* commander) {
		self->m_commander = commander;
	}
	int EMSCRIPTEN_KEEPALIVE Star_get_scan(Star* self) {
		return self->m_scan;
	}
	void EMSCRIPTEN_KEEPALIVE Star_set_scan(Star* self, int scan) {
		self->m_scan = scan;
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
	Commander* EMSCRIPTEN_KEEPALIVE CommanderBrush_get_commander(CommanderBrush* self) {
		return self->m_commander;
	}
	void EMSCRIPTEN_KEEPALIVE CommanderBrush_set_commander(CommanderBrush* self, Commander* commander) {
		self->m_commander = commander;
	}
	float EMSCRIPTEN_KEEPALIVE CommanderBrush_get_radius(CommanderBrush* self) {
		return self->m_radius;
	}
	void EMSCRIPTEN_KEEPALIVE CommanderBrush_set_radius(CommanderBrush* self, float radius) {
		self->m_radius = radius;
	}
	void EMSCRIPTEN_KEEPALIVE CommanderBrush___destroy__(CommanderBrush* self) {
		delete self;
	}
	// PlanetaryCombat
	PlanetaryCombat* EMSCRIPTEN_KEEPALIVE PlanetaryCombat_PlanetaryCombat_0() {
		return new PlanetaryCombat();
	}
	mud::uvec2* EMSCRIPTEN_KEEPALIVE PlanetaryCombat_get_coord(PlanetaryCombat* self) {
		static mud::uvec2 temp;
		return (temp = self->m_coord, &temp);
	}
	void EMSCRIPTEN_KEEPALIVE PlanetaryCombat_set_coord(PlanetaryCombat* self, mud::uvec2* coord) {
		self->m_coord = *coord;
	}
	CombatStar* EMSCRIPTEN_KEEPALIVE PlanetaryCombat_get_defense(PlanetaryCombat* self) {
		static CombatStar temp;
		return (temp = self->m_defense, &temp);
	}
	void EMSCRIPTEN_KEEPALIVE PlanetaryCombat_set_defense(PlanetaryCombat* self, CombatStar* defense) {
		self->m_defense = *defense;
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
	void EMSCRIPTEN_KEEPALIVE ShipSchema_set_size(ShipSchema* self, uint8_t size) {
		self->m_size = size;
	}
	uint8_t EMSCRIPTEN_KEEPALIVE ShipSchema_get_class(ShipSchema* self) {
		return self->m_class;
	}
	void EMSCRIPTEN_KEEPALIVE ShipSchema_set_class(ShipSchema* self, uint8_t class) {
		self->m_class = class;
	}
	WeaponType EMSCRIPTEN_KEEPALIVE ShipSchema_get_main_weapon(ShipSchema* self) {
		return self->m_main_weapon;
	}
	void EMSCRIPTEN_KEEPALIVE ShipSchema_set_main_weapon(ShipSchema* self, WeaponType main_weapon) {
		self->m_main_weapon = main_weapon;
	}
	void EMSCRIPTEN_KEEPALIVE ShipSchema___destroy__(ShipSchema* self) {
		delete self;
	}
	// SpatialCombat
	SpatialCombat* EMSCRIPTEN_KEEPALIVE SpatialCombat_SpatialCombat_0() {
		return new SpatialCombat();
	}
	mud::uvec2* EMSCRIPTEN_KEEPALIVE SpatialCombat_get_coord(SpatialCombat* self) {
		static mud::uvec2 temp;
		return (temp = self->m_coord, &temp);
	}
	void EMSCRIPTEN_KEEPALIVE SpatialCombat_set_coord(SpatialCombat* self, mud::uvec2* coord) {
		self->m_coord = *coord;
	}
	void EMSCRIPTEN_KEEPALIVE SpatialCombat___destroy__(SpatialCombat* self) {
		delete self;
	}
	// Universe
	Universe* EMSCRIPTEN_KEEPALIVE Universe_Universe_2(const char* name, mud::JobSystem* job_system) {
		return new Universe(name, *job_system);
	}
	toy::World* EMSCRIPTEN_KEEPALIVE Universe_get_world(Universe* self) {
		return &self->m_world;
	}
	toy::BulletWorld* EMSCRIPTEN_KEEPALIVE Universe_get_bullet_world(Universe* self) {
		return &self->m_bullet_world;
	}
	void EMSCRIPTEN_KEEPALIVE Universe___destroy__(Universe* self) {
		delete self;
	}
	// CombatType
	CombatType EMSCRIPTEN_KEEPALIVE CombatType_Spatial() {
		return CombatType::Spatial;
	}
	CombatType EMSCRIPTEN_KEEPALIVE CombatType_Planetary() {
		return CombatType::Planetary;
	}
	// Experience
	Experience EMSCRIPTEN_KEEPALIVE Experience_Inexperienced() {
		return Experience::Inexperienced;
	}
	Experience EMSCRIPTEN_KEEPALIVE Experience_LittleExperienced() {
		return Experience::LittleExperienced;
	}
	Experience EMSCRIPTEN_KEEPALIVE Experience_Experienced() {
		return Experience::Experienced;
	}
	Experience EMSCRIPTEN_KEEPALIVE Experience_Superior() {
		return Experience::Superior;
	}
	Experience EMSCRIPTEN_KEEPALIVE Experience_Elite() {
		return Experience::Elite;
	}
	// FleetSize
	FleetSize EMSCRIPTEN_KEEPALIVE FleetSize_Ridicule() {
		return FleetSize::Ridicule;
	}
	FleetSize EMSCRIPTEN_KEEPALIVE FleetSize_Minuscule() {
		return FleetSize::Minuscule;
	}
	FleetSize EMSCRIPTEN_KEEPALIVE FleetSize_Tiny() {
		return FleetSize::Tiny;
	}
	FleetSize EMSCRIPTEN_KEEPALIVE FleetSize_Small() {
		return FleetSize::Small;
	}
	FleetSize EMSCRIPTEN_KEEPALIVE FleetSize_Medium() {
		return FleetSize::Medium;
	}
	FleetSize EMSCRIPTEN_KEEPALIVE FleetSize_Respectable() {
		return FleetSize::Respectable;
	}
	FleetSize EMSCRIPTEN_KEEPALIVE FleetSize_Grand() {
		return FleetSize::Grand;
	}
	FleetSize EMSCRIPTEN_KEEPALIVE FleetSize_HighGrand() {
		return FleetSize::HighGrand;
	}
	FleetSize EMSCRIPTEN_KEEPALIVE FleetSize_Colossal() {
		return FleetSize::Colossal;
	}
	FleetSize EMSCRIPTEN_KEEPALIVE FleetSize_Titanesque() {
		return FleetSize::Titanesque;
	}
	FleetSize EMSCRIPTEN_KEEPALIVE FleetSize_Cyclopean() {
		return FleetSize::Cyclopean;
	}
	FleetSize EMSCRIPTEN_KEEPALIVE FleetSize_Divine() {
		return FleetSize::Divine;
	}
	FleetSize EMSCRIPTEN_KEEPALIVE FleetSize_Count() {
		return FleetSize::Count;
	}
	// FleetStance
	FleetStance EMSCRIPTEN_KEEPALIVE FleetStance_Movement() {
		return FleetStance::Movement;
	}
	FleetStance EMSCRIPTEN_KEEPALIVE FleetStance_SpatialAttack() {
		return FleetStance::SpatialAttack;
	}
	FleetStance EMSCRIPTEN_KEEPALIVE FleetStance_SpatialDefense() {
		return FleetStance::SpatialDefense;
	}
	FleetStance EMSCRIPTEN_KEEPALIVE FleetStance_PlanetaryAttack() {
		return FleetStance::PlanetaryAttack;
	}
	FleetStance EMSCRIPTEN_KEEPALIVE FleetStance_PlanetaryDefense() {
		return FleetStance::PlanetaryDefense;
	}
	FleetStance EMSCRIPTEN_KEEPALIVE FleetStance_Pillage() {
		return FleetStance::Pillage;
	}
	// GameStage
	GameStage EMSCRIPTEN_KEEPALIVE GameStage_Empire() {
		return GameStage::Empire;
	}
	GameStage EMSCRIPTEN_KEEPALIVE GameStage_Tactics() {
		return GameStage::Tactics;
	}
	GameStage EMSCRIPTEN_KEEPALIVE GameStage_TurnReport() {
		return GameStage::TurnReport;
	}
	// Politic
	Politic EMSCRIPTEN_KEEPALIVE Politic_Taxes() {
		return Politic::Taxes;
	}
	Politic EMSCRIPTEN_KEEPALIVE Politic_Commerce() {
		return Politic::Commerce;
	}
	Politic EMSCRIPTEN_KEEPALIVE Politic_Construction() {
		return Politic::Construction;
	}
	Politic EMSCRIPTEN_KEEPALIVE Politic_Defense() {
		return Politic::Defense;
	}
	Politic EMSCRIPTEN_KEEPALIVE Politic_Pacification() {
		return Politic::Pacification;
	}
	// Race
	Race EMSCRIPTEN_KEEPALIVE Race_Human() {
		return Race::Human;
	}
	Race EMSCRIPTEN_KEEPALIVE Race_Bulvoid() {
		return Race::Bulvoid;
	}
	Race EMSCRIPTEN_KEEPALIVE Race_Techtulon() {
		return Race::Techtulon;
	}
	Race EMSCRIPTEN_KEEPALIVE Race_Rakrarior() {
		return Race::Rakrarior;
	}
	Race EMSCRIPTEN_KEEPALIVE Race_Seigneur() {
		return Race::Seigneur;
	}
	Race EMSCRIPTEN_KEEPALIVE Race_Meton() {
		return Race::Meton;
	}
	Race EMSCRIPTEN_KEEPALIVE Race_Tissinar() {
		return Race::Tissinar;
	}
	Race EMSCRIPTEN_KEEPALIVE Race_Zwiie() {
		return Race::Zwiie;
	}
	// Regime
	Regime EMSCRIPTEN_KEEPALIVE Regime_Empire() {
		return Regime::Empire;
	}
	Regime EMSCRIPTEN_KEEPALIVE Regime_Dictature() {
		return Regime::Dictature;
	}
	Regime EMSCRIPTEN_KEEPALIVE Regime_Democracy() {
		return Regime::Democracy;
	}
	Regime EMSCRIPTEN_KEEPALIVE Regime_Theocracy() {
		return Regime::Theocracy;
	}
	Regime EMSCRIPTEN_KEEPALIVE Regime_Technocracy() {
		return Regime::Technocracy;
	}
	Regime EMSCRIPTEN_KEEPALIVE Regime_Piratery() {
		return Regime::Piratery;
	}
	// Resource
	Resource EMSCRIPTEN_KEEPALIVE Resource_None() {
		return Resource::None;
	}
	Resource EMSCRIPTEN_KEEPALIVE Resource_Minerals() {
		return Resource::Minerals;
	}
	Resource EMSCRIPTEN_KEEPALIVE Resource_Andrium() {
		return Resource::Andrium;
	}
	Resource EMSCRIPTEN_KEEPALIVE Resource_Alcool() {
		return Resource::Alcool;
	}
	Resource EMSCRIPTEN_KEEPALIVE Resource_Slaves() {
		return Resource::Slaves;
	}
	Resource EMSCRIPTEN_KEEPALIVE Resource_Narcotics() {
		return Resource::Narcotics;
	}
	Resource EMSCRIPTEN_KEEPALIVE Resource_Food() {
		return Resource::Food;
	}
	Resource EMSCRIPTEN_KEEPALIVE Resource_Medicine() {
		return Resource::Medicine;
	}
	Resource EMSCRIPTEN_KEEPALIVE Resource_Computers() {
		return Resource::Computers;
	}
	Resource EMSCRIPTEN_KEEPALIVE Resource_Plastic() {
		return Resource::Plastic;
	}
	Resource EMSCRIPTEN_KEEPALIVE Resource_Robot() {
		return Resource::Robot;
	}
	Resource EMSCRIPTEN_KEEPALIVE Resource_Count() {
		return Resource::Count;
	}
	// Taxation
	Taxation EMSCRIPTEN_KEEPALIVE Taxation_None() {
		return Taxation::None;
	}
	Taxation EMSCRIPTEN_KEEPALIVE Taxation_Light() {
		return Taxation::Light;
	}
	Taxation EMSCRIPTEN_KEEPALIVE Taxation_Medium() {
		return Taxation::Medium;
	}
	Taxation EMSCRIPTEN_KEEPALIVE Taxation_Heavy() {
		return Taxation::Heavy;
	}
	Taxation EMSCRIPTEN_KEEPALIVE Taxation_Heaviest() {
		return Taxation::Heaviest;
	}
	Taxation EMSCRIPTEN_KEEPALIVE Taxation_Total() {
		return Taxation::Total;
	}
	// Technology
	Technology EMSCRIPTEN_KEEPALIVE Technology_Engines() {
		return Technology::Engines;
	}
	Technology EMSCRIPTEN_KEEPALIVE Technology_EcoEnergy() {
		return Technology::EcoEnergy;
	}
	Technology EMSCRIPTEN_KEEPALIVE Technology_Scanners() {
		return Technology::Scanners;
	}
	Technology EMSCRIPTEN_KEEPALIVE Technology_PlanetaryShields() {
		return Technology::PlanetaryShields;
	}
	Technology EMSCRIPTEN_KEEPALIVE Technology_SpatialShields() {
		return Technology::SpatialShields;
	}
	Technology EMSCRIPTEN_KEEPALIVE Technology_LaserPlasmaIons() {
		return Technology::LaserPlasmaIons;
	}
	Technology EMSCRIPTEN_KEEPALIVE Technology_Torpedoes() {
		return Technology::Torpedoes;
	}
	Technology EMSCRIPTEN_KEEPALIVE Technology_Bombs() {
		return Technology::Bombs;
	}
	Technology EMSCRIPTEN_KEEPALIVE Technology_HullArmor() {
		return Technology::HullArmor;
	}
	Technology EMSCRIPTEN_KEEPALIVE Technology_Mining() {
		return Technology::Mining;
	}
	Technology EMSCRIPTEN_KEEPALIVE Technology_Terraforming() {
		return Technology::Terraforming;
	}
	Technology EMSCRIPTEN_KEEPALIVE Technology_Construction() {
		return Technology::Construction;
	}
	Technology EMSCRIPTEN_KEEPALIVE Technology_Piloting() {
		return Technology::Piloting;
	}
	Technology EMSCRIPTEN_KEEPALIVE Technology_Commerce() {
		return Technology::Commerce;
	}
	Technology EMSCRIPTEN_KEEPALIVE Technology_Personnel() {
		return Technology::Personnel;
	}
	Technology EMSCRIPTEN_KEEPALIVE Technology_Administration() {
		return Technology::Administration;
	}
	Technology EMSCRIPTEN_KEEPALIVE Technology_CyberCommand() {
		return Technology::CyberCommand;
	}
	Technology EMSCRIPTEN_KEEPALIVE Technology_CyberCommerce() {
		return Technology::CyberCommerce;
	}
	Technology EMSCRIPTEN_KEEPALIVE Technology_CyberDiplomacy() {
		return Technology::CyberDiplomacy;
	}
	Technology EMSCRIPTEN_KEEPALIVE Technology_Count() {
		return Technology::Count;
	}
	// WeaponType
	WeaponType EMSCRIPTEN_KEEPALIVE WeaponType_None() {
		return WeaponType::None;
	}
	WeaponType EMSCRIPTEN_KEEPALIVE WeaponType_Ion() {
		return WeaponType::Ion;
	}
	WeaponType EMSCRIPTEN_KEEPALIVE WeaponType_Laser() {
		return WeaponType::Laser;
	}
	WeaponType EMSCRIPTEN_KEEPALIVE WeaponType_Plasma() {
		return WeaponType::Plasma;
	}
	WeaponType EMSCRIPTEN_KEEPALIVE WeaponType_Torpedo() {
		return WeaponType::Torpedo;
	}
	WeaponType EMSCRIPTEN_KEEPALIVE WeaponType_Bomb() {
		return WeaponType::Bomb;
	}
	
}


