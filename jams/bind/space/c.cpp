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
#include <frame/Api.h>
#include <util/Api.h>
#include <core/Api.h>
#include <visu/Api.h>
#include <edit/Api.h>
#include <block/Api.h>
#include <shell/Api.h>
#include <space/Api.h>

#ifdef MUD_PLATFORM_EMSCRIPTEN
#include <emscripten.h>
#define DECL EMSCRIPTEN_KEEPALIVE
#else
#define DECL
#endif


extern "C" {
	
	// Combat
	two::Type* DECL Combat__type() {
		return &two::type<Combat>();
	}
	Combat* DECL Combat_Combat_0() {
		return new Combat();
	}
	void DECL Combat__destroy(Combat* self) {
		delete self;
	}
	// CombatFleet
	two::Type* DECL CombatFleet__type() {
		return &two::type<CombatFleet>();
	}
	CombatFleet* DECL CombatFleet_CombatFleet_0() {
		return new CombatFleet();
	}
	void DECL CombatFleet__destroy(CombatFleet* self) {
		delete self;
	}
	// CombatStar
	two::Type* DECL CombatStar__type() {
		return &two::type<CombatStar>();
	}
	CombatStar* DECL CombatStar_CombatStar_0() {
		return new CombatStar();
	}
	void DECL CombatStar__destroy(CombatStar* self) {
		delete self;
	}
	// Commander
	two::Type* DECL Commander__type() {
		return &two::type<Commander>();
	}
	Commander* DECL Commander_Commander_6(uint32_t id, const char* name, Race race, int command, int commerce, int diplomacy) {
		return new Commander(id, name, race, command, commerce, diplomacy);
	}
	uint32_t DECL Commander__get_id(Commander* self) {
		return self->m_id;
	}
	void DECL Commander__set_id(Commander* self, uint32_t value) {
		self->m_id = value;
	}
	const char* DECL Commander__get_name(Commander* self) {
		return self->m_name.c_str();
	}
	void DECL Commander__set_name(Commander* self, const char* value) {
		self->m_name = value;
	}
	Race DECL Commander__get_race(Commander* self) {
		return self->m_race;
	}
	void DECL Commander__set_race(Commander* self, Race value) {
		self->m_race = value;
	}
	int DECL Commander__get_command(Commander* self) {
		return self->m_command;
	}
	void DECL Commander__set_command(Commander* self, int value) {
		self->m_command = value;
	}
	int DECL Commander__get_commerce(Commander* self) {
		return self->m_commerce;
	}
	void DECL Commander__set_commerce(Commander* self, int value) {
		self->m_commerce = value;
	}
	int DECL Commander__get_diplomacy(Commander* self) {
		return self->m_diplomacy;
	}
	void DECL Commander__set_diplomacy(Commander* self, int value) {
		self->m_diplomacy = value;
	}
	int DECL Commander__get_reputation(Commander* self) {
		return self->m_reputation;
	}
	void DECL Commander__set_reputation(Commander* self, int value) {
		self->m_reputation = value;
	}
	int DECL Commander__get_victory(Commander* self) {
		return self->m_victory;
	}
	void DECL Commander__set_victory(Commander* self, int value) {
		self->m_victory = value;
	}
	Star* DECL Commander__get_capital(Commander* self) {
		return self->m_capital;
	}
	void DECL Commander__set_capital(Commander* self, Star* value) {
		self->m_capital = value;
	}
	Regime DECL Commander__get_regime(Commander* self) {
		return self->m_regime;
	}
	void DECL Commander__set_regime(Commander* self, Regime value) {
		self->m_regime = value;
	}
	float DECL Commander__get_power(Commander* self) {
		return self->m_power;
	}
	void DECL Commander__set_power(Commander* self, float value) {
		self->m_power = value;
	}
	float DECL Commander__get_centaures(Commander* self) {
		return self->m_centaures;
	}
	void DECL Commander__set_centaures(Commander* self, float value) {
		self->m_centaures = value;
	}
	Scans* DECL Commander__get_scans(Commander* self) {
		static Scans temp;
		return (temp = self->m_scans, &temp);
	}
	void DECL Commander__set_scans(Commander* self, Scans* value) {
		self->m_scans = *value;
	}
	void DECL Commander__destroy(Commander* self) {
		delete self;
	}
	// Construction
	two::Type* DECL Construction__type() {
		return &two::type<Construction>();
	}
	Construction* DECL Construction_Construction_0() {
		return new Construction();
	}
	void DECL Construction__destroy(Construction* self) {
		delete self;
	}
	// Fleet
	two::Type* DECL Fleet__type() {
		return &two::type<Fleet>();
	}
	Fleet* DECL Fleet_Fleet_0() {
		return new Fleet();
	}
	Fleet* DECL Fleet_Fleet_5(toy::HSpatial spatial, Galaxy* galaxy, Commander* commander, const two::uvec2* coord, const char* name) {
		return new Fleet(spatial, *galaxy, *commander, *coord, name);
	}
	void DECL Fleet_order_jump_2(Fleet* self, two::uvec2* coord, FleetStance stance) {
		self->order_jump(*coord, stance);
	}
	void DECL Fleet_order_attack_1(Fleet* self, Star* star) {
		self->order_attack(*star);
	}
	Galaxy* DECL Fleet__get_galaxy(Fleet* self) {
		return self->m_galaxy;
	}
	void DECL Fleet__set_galaxy(Fleet* self, Galaxy* value) {
		self->m_galaxy = value;
	}
	Commander* DECL Fleet__get_commander(Fleet* self) {
		return self->m_commander;
	}
	void DECL Fleet__set_commander(Fleet* self, Commander* value) {
		self->m_commander = value;
	}
	two::uvec2* DECL Fleet__get_coord(Fleet* self) {
		static two::uvec2 temp;
		return (temp = self->m_coord, &temp);
	}
	void DECL Fleet__set_coord(Fleet* self, two::uvec2* value) {
		self->m_coord = *value;
	}
	two::vec3* DECL Fleet__get_slot(Fleet* self) {
		static two::vec3 temp;
		return (temp = self->m_slot, &temp);
	}
	void DECL Fleet__set_slot(Fleet* self, two::vec3* value) {
		self->m_slot = *value;
	}
	const char* DECL Fleet__get_name(Fleet* self) {
		return self->m_name.c_str();
	}
	void DECL Fleet__set_name(Fleet* self, const char* value) {
		self->m_name = value;
	}
	float DECL Fleet__get_experience(Fleet* self) {
		return self->m_experience;
	}
	void DECL Fleet__set_experience(Fleet* self, float value) {
		self->m_experience = value;
	}
	SpatialPower* DECL Fleet__get_spatial_power(Fleet* self) {
		static SpatialPower temp;
		return (temp = self->m_spatial_power, &temp);
	}
	void DECL Fleet__set_spatial_power(Fleet* self, SpatialPower* value) {
		self->m_spatial_power = *value;
	}
	float DECL Fleet__get_planetary_power(Fleet* self) {
		return self->m_planetary_power;
	}
	void DECL Fleet__set_planetary_power(Fleet* self, float value) {
		self->m_planetary_power = value;
	}
	uint8_t DECL Fleet__get_speed(Fleet* self) {
		return self->m_speed;
	}
	void DECL Fleet__set_speed(Fleet* self, uint8_t value) {
		self->m_speed = value;
	}
	uint8_t DECL Fleet__get_scan(Fleet* self) {
		return self->m_scan;
	}
	void DECL Fleet__set_scan(Fleet* self, uint8_t value) {
		self->m_scan = value;
	}
	float DECL Fleet__get_upkeep(Fleet* self) {
		return self->m_upkeep;
	}
	void DECL Fleet__set_upkeep(Fleet* self, float value) {
		self->m_upkeep = value;
	}
	FleetStance DECL Fleet__get_stance(Fleet* self) {
		return self->m_stance;
	}
	void DECL Fleet__set_stance(Fleet* self, FleetStance value) {
		self->m_stance = value;
	}
	Jump* DECL Fleet__get_jump(Fleet* self) {
		static Jump temp;
		return (temp = self->m_jump, &temp);
	}
	void DECL Fleet__set_jump(Fleet* self, Jump* value) {
		self->m_jump = *value;
	}
	Split* DECL Fleet__get_split(Fleet* self) {
		static Split temp;
		return (temp = self->m_split, &temp);
	}
	void DECL Fleet__set_split(Fleet* self, Split* value) {
		self->m_split = *value;
	}
	bool DECL Fleet__get_fought(Fleet* self) {
		return self->m_fought;
	}
	void DECL Fleet__set_fought(Fleet* self, bool value) {
		self->m_fought = value;
	}
	size_t DECL Fleet__get_ships_updated(Fleet* self) {
		return self->m_ships_updated;
	}
	void DECL Fleet__set_ships_updated(Fleet* self, size_t value) {
		self->m_ships_updated = value;
	}
	void DECL Fleet__destroy(Fleet* self) {
		delete self;
	}
	// Galaxy
	two::Type* DECL Galaxy__type() {
		return &two::type<Galaxy>();
	}
	Galaxy* DECL Galaxy_Galaxy_0() {
		return new Galaxy();
	}
	Galaxy* DECL Galaxy_Galaxy_2(toy::HSpatial spatial, const two::uvec2* size) {
		return new Galaxy(spatial, *size);
	}
	two::uvec2* DECL Galaxy__get_size(Galaxy* self) {
		static two::uvec2 temp;
		return (temp = self->m_size, &temp);
	}
	void DECL Galaxy__set_size(Galaxy* self, two::uvec2* value) {
		self->m_size = *value;
	}
	void DECL Galaxy__destroy(Galaxy* self) {
		delete self;
	}
	// Jump
	two::Type* DECL Jump__type() {
		return &two::type<Jump>();
	}
	Jump* DECL Jump_Jump_0() {
		return new Jump();
	}
	Fleet* DECL Jump__get_fleet(Jump* self) {
		return self->m_fleet;
	}
	void DECL Jump__set_fleet(Jump* self, Fleet* value) {
		self->m_fleet = value;
	}
	two::uvec2* DECL Jump__get_start(Jump* self) {
		static two::uvec2 temp;
		return (temp = self->m_start, &temp);
	}
	void DECL Jump__set_start(Jump* self, two::uvec2* value) {
		self->m_start = *value;
	}
	two::uvec2* DECL Jump__get_dest(Jump* self) {
		static two::uvec2 temp;
		return (temp = self->m_dest, &temp);
	}
	void DECL Jump__set_dest(Jump* self, two::uvec2* value) {
		self->m_dest = *value;
	}
	FleetStance DECL Jump__get_stance(Jump* self) {
		return self->m_stance;
	}
	void DECL Jump__set_stance(Jump* self, FleetStance value) {
		self->m_stance = value;
	}
	Fleet* DECL Jump__get_track(Jump* self) {
		return self->m_track;
	}
	void DECL Jump__set_track(Jump* self, Fleet* value) {
		self->m_track = value;
	}
	void DECL Jump__destroy(Jump* self) {
		delete self;
	}
	// Player
	two::Type* DECL Player__type() {
		return &two::type<Player>();
	}
	void DECL Player__destroy(Player* self) {
		delete self;
	}
	// Scans
	two::Type* DECL Scans__type() {
		return &two::type<Scans>();
	}
	Scans* DECL Scans_Scans_0() {
		return new Scans();
	}
	void DECL Scans__destroy(Scans* self) {
		delete self;
	}
	// Schema
	two::Type* DECL Schema__type() {
		return &two::type<Schema>();
	}
	Schema* DECL Schema_Schema_0() {
		return new Schema();
	}
	const char* DECL Schema__get_code(Schema* self) {
		return self->m_code.c_str();
	}
	void DECL Schema__set_code(Schema* self, const char* value) {
		self->m_code = value;
	}
	const char* DECL Schema__get_name(Schema* self) {
		return self->m_name.c_str();
	}
	void DECL Schema__set_name(Schema* self, const char* value) {
		self->m_name = value;
	}
	const char* DECL Schema__get_conceptor(Schema* self) {
		return self->m_conceptor.c_str();
	}
	void DECL Schema__set_conceptor(Schema* self, const char* value) {
		self->m_conceptor = value;
	}
	uint8_t DECL Schema__get_level(Schema* self) {
		return self->m_level;
	}
	void DECL Schema__set_level(Schema* self, uint8_t value) {
		self->m_level = value;
	}
	float DECL Schema__get_cost(Schema* self) {
		return self->m_cost;
	}
	void DECL Schema__set_cost(Schema* self, float value) {
		self->m_cost = value;
	}
	float DECL Schema__get_minerals(Schema* self) {
		return self->m_minerals;
	}
	void DECL Schema__set_minerals(Schema* self, float value) {
		self->m_minerals = value;
	}
	float DECL Schema__get_andrium(Schema* self) {
		return self->m_andrium;
	}
	void DECL Schema__set_andrium(Schema* self, float value) {
		self->m_andrium = value;
	}
	float DECL Schema__get_resistance(Schema* self) {
		return self->m_resistance;
	}
	void DECL Schema__set_resistance(Schema* self, float value) {
		self->m_resistance = value;
	}
	uint8_t DECL Schema__get_speed(Schema* self) {
		return self->m_speed;
	}
	void DECL Schema__set_speed(Schema* self, uint8_t value) {
		self->m_speed = value;
	}
	uint8_t DECL Schema__get_scan(Schema* self) {
		return self->m_scan;
	}
	void DECL Schema__set_scan(Schema* self, uint8_t value) {
		self->m_scan = value;
	}
	float DECL Schema__get_planetary(Schema* self) {
		return self->m_planetary;
	}
	void DECL Schema__set_planetary(Schema* self, float value) {
		self->m_planetary = value;
	}
	SpatialPower* DECL Schema__get_spatial(Schema* self) {
		static SpatialPower temp;
		return (temp = self->m_spatial, &temp);
	}
	void DECL Schema__set_spatial(Schema* self, SpatialPower* value) {
		self->m_spatial = *value;
	}
	float DECL Schema__get_upkeep_factor(Schema* self) {
		return self->m_upkeep_factor;
	}
	void DECL Schema__set_upkeep_factor(Schema* self, float value) {
		self->m_upkeep_factor = value;
	}
	void DECL Schema__destroy(Schema* self) {
		delete self;
	}
	// SpatialPower
	two::Type* DECL SpatialPower__type() {
		return &two::type<SpatialPower>();
	}
	SpatialPower* DECL SpatialPower_SpatialPower_0() {
		return new SpatialPower();
	}
	void DECL SpatialPower__destroy(SpatialPower* self) {
		delete self;
	}
	// Split
	two::Type* DECL Split__type() {
		return &two::type<Split>();
	}
	Split* DECL Split_Split_0() {
		return new Split();
	}
	Fleet* DECL Split__get_source(Split* self) {
		return self->m_source;
	}
	void DECL Split__set_source(Split* self, Fleet* value) {
		self->m_source = value;
	}
	Fleet* DECL Split__get_dest(Split* self) {
		return self->m_dest;
	}
	void DECL Split__set_dest(Split* self, Fleet* value) {
		self->m_dest = value;
	}
	const char* DECL Split__get_code(Split* self) {
		return self->m_code.c_str();
	}
	void DECL Split__set_code(Split* self, const char* value) {
		self->m_code = value;
	}
	FleetStance DECL Split__get_stance(Split* self) {
		return self->m_stance;
	}
	void DECL Split__set_stance(Split* self, FleetStance value) {
		self->m_stance = value;
	}
	void DECL Split__destroy(Split* self) {
		delete self;
	}
	// Star
	two::Type* DECL Star__type() {
		return &two::type<Star>();
	}
	Star* DECL Star_Star_0() {
		return new Star();
	}
	Star* DECL Star_Star_4(toy::HSpatial spatial, Galaxy* galaxy, const two::uvec2* coord, const char* name) {
		return new Star(spatial, *galaxy, *coord, name);
	}
	Galaxy* DECL Star__get_galaxy(Star* self) {
		return self->m_galaxy;
	}
	void DECL Star__set_galaxy(Star* self, Galaxy* value) {
		self->m_galaxy = value;
	}
	two::uvec2* DECL Star__get_coord(Star* self) {
		static two::uvec2 temp;
		return (temp = self->m_coord, &temp);
	}
	void DECL Star__set_coord(Star* self, two::uvec2* value) {
		self->m_coord = *value;
	}
	const char* DECL Star__get_name(Star* self) {
		return self->m_name.c_str();
	}
	void DECL Star__set_name(Star* self, const char* value) {
		self->m_name = value;
	}
	int DECL Star__get_stability(Star* self) {
		return self->m_stability;
	}
	void DECL Star__set_stability(Star* self, int value) {
		self->m_stability = value;
	}
	bool DECL Star__get_revolt(Star* self) {
		return self->m_revolt;
	}
	void DECL Star__set_revolt(Star* self, bool value) {
		self->m_revolt = value;
	}
	int DECL Star__get_environment(Star* self) {
		return self->m_environment;
	}
	void DECL Star__set_environment(Star* self, int value) {
		self->m_environment = value;
	}
	int DECL Star__get_terraformation(Star* self) {
		return self->m_terraformation;
	}
	void DECL Star__set_terraformation(Star* self, int value) {
		self->m_terraformation = value;
	}
	int DECL Star__get_base_population(Star* self) {
		return self->m_base_population;
	}
	void DECL Star__set_base_population(Star* self, int value) {
		self->m_base_population = value;
	}
	int DECL Star__get_max_population(Star* self) {
		return self->m_max_population;
	}
	void DECL Star__set_max_population(Star* self, int value) {
		self->m_max_population = value;
	}
	int DECL Star__get_population(Star* self) {
		return self->m_population;
	}
	void DECL Star__set_population(Star* self, int value) {
		self->m_population = value;
	}
	float DECL Star__get_militia(Star* self) {
		return self->m_militia;
	}
	void DECL Star__set_militia(Star* self, float value) {
		self->m_militia = value;
	}
	float DECL Star__get_defense(Star* self) {
		return self->m_defense;
	}
	void DECL Star__set_defense(Star* self, float value) {
		self->m_defense = value;
	}
	float DECL Star__get_revenue(Star* self) {
		return self->m_revenue;
	}
	void DECL Star__set_revenue(Star* self, float value) {
		self->m_revenue = value;
	}
	Politic DECL Star__get_politic(Star* self) {
		return self->m_politic;
	}
	void DECL Star__set_politic(Star* self, Politic value) {
		self->m_politic = value;
	}
	Taxation DECL Star__get_taxation(Star* self) {
		return self->m_taxation;
	}
	void DECL Star__set_taxation(Star* self, Taxation value) {
		self->m_taxation = value;
	}
	Commander* DECL Star__get_commander(Star* self) {
		return self->m_commander;
	}
	void DECL Star__set_commander(Star* self, Commander* value) {
		self->m_commander = value;
	}
	int DECL Star__get_scan(Star* self) {
		return self->m_scan;
	}
	void DECL Star__set_scan(Star* self, int value) {
		self->m_scan = value;
	}
	void DECL Star__destroy(Star* self) {
		delete self;
	}
	// TechDomain
	two::Type* DECL TechDomain__type() {
		return &two::type<TechDomain>();
	}
	TechDomain* DECL TechDomain_TechDomain_0() {
		return new TechDomain();
	}
	void DECL TechDomain__destroy(TechDomain* self) {
		delete self;
	}
	// Turn
	two::Type* DECL Turn__type() {
		return &two::type<Turn>();
	}
	Turn* DECL Turn_Turn_0() {
		return new Turn();
	}
	void DECL Turn__destroy(Turn* self) {
		delete self;
	}
	// BuildingSchema
	two::Type* DECL BuildingSchema__type() {
		return &two::type<BuildingSchema>();
	}
	BuildingSchema* DECL BuildingSchema_BuildingSchema_0() {
		return new BuildingSchema();
	}
	void DECL BuildingSchema__destroy(BuildingSchema* self) {
		delete self;
	}
	// CommanderBrush
	two::Type* DECL CommanderBrush__type() {
		return &two::type<CommanderBrush>();
	}
	Commander* DECL CommanderBrush__get_commander(CommanderBrush* self) {
		return self->m_commander;
	}
	void DECL CommanderBrush__set_commander(CommanderBrush* self, Commander* value) {
		self->m_commander = value;
	}
	float DECL CommanderBrush__get_radius(CommanderBrush* self) {
		return self->m_radius;
	}
	void DECL CommanderBrush__set_radius(CommanderBrush* self, float value) {
		self->m_radius = value;
	}
	void DECL CommanderBrush__destroy(CommanderBrush* self) {
		delete self;
	}
	// PlanetaryCombat
	two::Type* DECL PlanetaryCombat__type() {
		return &two::type<PlanetaryCombat>();
	}
	PlanetaryCombat* DECL PlanetaryCombat_PlanetaryCombat_0() {
		return new PlanetaryCombat();
	}
	two::uvec2* DECL PlanetaryCombat__get_coord(PlanetaryCombat* self) {
		static two::uvec2 temp;
		return (temp = self->m_coord, &temp);
	}
	void DECL PlanetaryCombat__set_coord(PlanetaryCombat* self, two::uvec2* value) {
		self->m_coord = *value;
	}
	CombatStar* DECL PlanetaryCombat__get_defense(PlanetaryCombat* self) {
		static CombatStar temp;
		return (temp = self->m_defense, &temp);
	}
	void DECL PlanetaryCombat__set_defense(PlanetaryCombat* self, CombatStar* value) {
		self->m_defense = *value;
	}
	void DECL PlanetaryCombat__destroy(PlanetaryCombat* self) {
		delete self;
	}
	// ShipComponent
	two::Type* DECL ShipComponent__type() {
		return &two::type<ShipComponent>();
	}
	ShipComponent* DECL ShipComponent_ShipComponent_0() {
		return new ShipComponent();
	}
	void DECL ShipComponent__destroy(ShipComponent* self) {
		delete self;
	}
	// ShipEngine
	two::Type* DECL ShipEngine__type() {
		return &two::type<ShipEngine>();
	}
	ShipEngine* DECL ShipEngine_ShipEngine_0() {
		return new ShipEngine();
	}
	void DECL ShipEngine__destroy(ShipEngine* self) {
		delete self;
	}
	// ShipHull
	two::Type* DECL ShipHull__type() {
		return &two::type<ShipHull>();
	}
	ShipHull* DECL ShipHull_ShipHull_0() {
		return new ShipHull();
	}
	void DECL ShipHull__destroy(ShipHull* self) {
		delete self;
	}
	// ShipSchema
	two::Type* DECL ShipSchema__type() {
		return &two::type<ShipSchema>();
	}
	ShipSchema* DECL ShipSchema_ShipSchema_0() {
		return new ShipSchema();
	}
	uint8_t DECL ShipSchema__get_size(ShipSchema* self) {
		return self->m_size;
	}
	void DECL ShipSchema__set_size(ShipSchema* self, uint8_t value) {
		self->m_size = value;
	}
	uint8_t DECL ShipSchema__get_class(ShipSchema* self) {
		return self->m_class;
	}
	void DECL ShipSchema__set_class(ShipSchema* self, uint8_t value) {
		self->m_class = value;
	}
	WeaponType DECL ShipSchema__get_main_weapon(ShipSchema* self) {
		return self->m_main_weapon;
	}
	void DECL ShipSchema__set_main_weapon(ShipSchema* self, WeaponType value) {
		self->m_main_weapon = value;
	}
	void DECL ShipSchema__destroy(ShipSchema* self) {
		delete self;
	}
	// SpatialCombat
	two::Type* DECL SpatialCombat__type() {
		return &two::type<SpatialCombat>();
	}
	SpatialCombat* DECL SpatialCombat_SpatialCombat_0() {
		return new SpatialCombat();
	}
	two::uvec2* DECL SpatialCombat__get_coord(SpatialCombat* self) {
		static two::uvec2 temp;
		return (temp = self->m_coord, &temp);
	}
	void DECL SpatialCombat__set_coord(SpatialCombat* self, two::uvec2* value) {
		self->m_coord = *value;
	}
	void DECL SpatialCombat__destroy(SpatialCombat* self) {
		delete self;
	}
	// Universe
	two::Type* DECL Universe__type() {
		return &two::type<Universe>();
	}
	Universe* DECL Universe_Universe_2(const char* name, two::JobSystem* job_system) {
		return new Universe(name, *job_system);
	}
	toy::World* DECL Universe__get_world(Universe* self) {
		return &self->m_world;
	}
	toy::BulletWorld* DECL Universe__get_bullet_world(Universe* self) {
		return &self->m_bullet_world;
	}
	void DECL Universe__destroy(Universe* self) {
		delete self;
	}
	HStar DECL _generate_system_3(Galaxy* galaxy, const two::uvec3* coord, const two::vec3* position) {
		return generate_system(*galaxy, *coord, *position);
	}
	HFleet DECL _generate_fleet_3(Galaxy* galaxy, const two::uvec3* coord, const two::vec3* position) {
		return generate_fleet(*galaxy, *coord, *position);
	}
	Commander* DECL _generate_commander_2(Galaxy* galaxy, Star* star) {
		return generate_commander(*galaxy, *star);
	}
	// CombatType
	CombatType DECL CombatType_Spatial() {
		return CombatType::Spatial;
	}
	CombatType DECL CombatType_Planetary() {
		return CombatType::Planetary;
	}
	// Experience
	Experience DECL Experience_Inexperienced() {
		return Experience::Inexperienced;
	}
	Experience DECL Experience_LittleExperienced() {
		return Experience::LittleExperienced;
	}
	Experience DECL Experience_Experienced() {
		return Experience::Experienced;
	}
	Experience DECL Experience_Superior() {
		return Experience::Superior;
	}
	Experience DECL Experience_Elite() {
		return Experience::Elite;
	}
	// FleetSize
	FleetSize DECL FleetSize_Ridicule() {
		return FleetSize::Ridicule;
	}
	FleetSize DECL FleetSize_Minuscule() {
		return FleetSize::Minuscule;
	}
	FleetSize DECL FleetSize_Tiny() {
		return FleetSize::Tiny;
	}
	FleetSize DECL FleetSize_Small() {
		return FleetSize::Small;
	}
	FleetSize DECL FleetSize_Medium() {
		return FleetSize::Medium;
	}
	FleetSize DECL FleetSize_Respectable() {
		return FleetSize::Respectable;
	}
	FleetSize DECL FleetSize_Grand() {
		return FleetSize::Grand;
	}
	FleetSize DECL FleetSize_HighGrand() {
		return FleetSize::HighGrand;
	}
	FleetSize DECL FleetSize_Colossal() {
		return FleetSize::Colossal;
	}
	FleetSize DECL FleetSize_Titanesque() {
		return FleetSize::Titanesque;
	}
	FleetSize DECL FleetSize_Cyclopean() {
		return FleetSize::Cyclopean;
	}
	FleetSize DECL FleetSize_Divine() {
		return FleetSize::Divine;
	}
	FleetSize DECL FleetSize_Count() {
		return FleetSize::Count;
	}
	// FleetStance
	FleetStance DECL FleetStance_Movement() {
		return FleetStance::Movement;
	}
	FleetStance DECL FleetStance_SpatialAttack() {
		return FleetStance::SpatialAttack;
	}
	FleetStance DECL FleetStance_SpatialDefense() {
		return FleetStance::SpatialDefense;
	}
	FleetStance DECL FleetStance_PlanetaryAttack() {
		return FleetStance::PlanetaryAttack;
	}
	FleetStance DECL FleetStance_PlanetaryDefense() {
		return FleetStance::PlanetaryDefense;
	}
	FleetStance DECL FleetStance_Pillage() {
		return FleetStance::Pillage;
	}
	// GameStage
	GameStage DECL GameStage_Empire() {
		return GameStage::Empire;
	}
	GameStage DECL GameStage_Tactics() {
		return GameStage::Tactics;
	}
	GameStage DECL GameStage_TurnReport() {
		return GameStage::TurnReport;
	}
	// Politic
	Politic DECL Politic_Taxes() {
		return Politic::Taxes;
	}
	Politic DECL Politic_Commerce() {
		return Politic::Commerce;
	}
	Politic DECL Politic_Construction() {
		return Politic::Construction;
	}
	Politic DECL Politic_Defense() {
		return Politic::Defense;
	}
	Politic DECL Politic_Pacification() {
		return Politic::Pacification;
	}
	// Race
	Race DECL Race_Human() {
		return Race::Human;
	}
	Race DECL Race_Bulvoid() {
		return Race::Bulvoid;
	}
	Race DECL Race_Techtulon() {
		return Race::Techtulon;
	}
	Race DECL Race_Rakrarior() {
		return Race::Rakrarior;
	}
	Race DECL Race_Seigneur() {
		return Race::Seigneur;
	}
	Race DECL Race_Meton() {
		return Race::Meton;
	}
	Race DECL Race_Tissinar() {
		return Race::Tissinar;
	}
	Race DECL Race_Zwiie() {
		return Race::Zwiie;
	}
	// Regime
	Regime DECL Regime_Empire() {
		return Regime::Empire;
	}
	Regime DECL Regime_Dictature() {
		return Regime::Dictature;
	}
	Regime DECL Regime_Democracy() {
		return Regime::Democracy;
	}
	Regime DECL Regime_Theocracy() {
		return Regime::Theocracy;
	}
	Regime DECL Regime_Technocracy() {
		return Regime::Technocracy;
	}
	Regime DECL Regime_Piratery() {
		return Regime::Piratery;
	}
	// Resource
	Resource DECL Resource_None() {
		return Resource::None;
	}
	Resource DECL Resource_Minerals() {
		return Resource::Minerals;
	}
	Resource DECL Resource_Andrium() {
		return Resource::Andrium;
	}
	Resource DECL Resource_Alcool() {
		return Resource::Alcool;
	}
	Resource DECL Resource_Slaves() {
		return Resource::Slaves;
	}
	Resource DECL Resource_Narcotics() {
		return Resource::Narcotics;
	}
	Resource DECL Resource_Food() {
		return Resource::Food;
	}
	Resource DECL Resource_Medicine() {
		return Resource::Medicine;
	}
	Resource DECL Resource_Computers() {
		return Resource::Computers;
	}
	Resource DECL Resource_Plastic() {
		return Resource::Plastic;
	}
	Resource DECL Resource_Robot() {
		return Resource::Robot;
	}
	Resource DECL Resource_Count() {
		return Resource::Count;
	}
	// Taxation
	Taxation DECL Taxation_None() {
		return Taxation::None;
	}
	Taxation DECL Taxation_Light() {
		return Taxation::Light;
	}
	Taxation DECL Taxation_Medium() {
		return Taxation::Medium;
	}
	Taxation DECL Taxation_Heavy() {
		return Taxation::Heavy;
	}
	Taxation DECL Taxation_Heaviest() {
		return Taxation::Heaviest;
	}
	Taxation DECL Taxation_Total() {
		return Taxation::Total;
	}
	// Technology
	Technology DECL Technology_Engines() {
		return Technology::Engines;
	}
	Technology DECL Technology_EcoEnergy() {
		return Technology::EcoEnergy;
	}
	Technology DECL Technology_Scanners() {
		return Technology::Scanners;
	}
	Technology DECL Technology_PlanetaryShields() {
		return Technology::PlanetaryShields;
	}
	Technology DECL Technology_SpatialShields() {
		return Technology::SpatialShields;
	}
	Technology DECL Technology_LaserPlasmaIons() {
		return Technology::LaserPlasmaIons;
	}
	Technology DECL Technology_Torpedoes() {
		return Technology::Torpedoes;
	}
	Technology DECL Technology_Bombs() {
		return Technology::Bombs;
	}
	Technology DECL Technology_HullArmor() {
		return Technology::HullArmor;
	}
	Technology DECL Technology_Mining() {
		return Technology::Mining;
	}
	Technology DECL Technology_Terraforming() {
		return Technology::Terraforming;
	}
	Technology DECL Technology_Construction() {
		return Technology::Construction;
	}
	Technology DECL Technology_Piloting() {
		return Technology::Piloting;
	}
	Technology DECL Technology_Commerce() {
		return Technology::Commerce;
	}
	Technology DECL Technology_Personnel() {
		return Technology::Personnel;
	}
	Technology DECL Technology_Administration() {
		return Technology::Administration;
	}
	Technology DECL Technology_CyberCommand() {
		return Technology::CyberCommand;
	}
	Technology DECL Technology_CyberCommerce() {
		return Technology::CyberCommerce;
	}
	Technology DECL Technology_CyberDiplomacy() {
		return Technology::CyberDiplomacy;
	}
	Technology DECL Technology_Count() {
		return Technology::Count;
	}
	// WeaponType
	WeaponType DECL WeaponType_None() {
		return WeaponType::None;
	}
	WeaponType DECL WeaponType_Ion() {
		return WeaponType::Ion;
	}
	WeaponType DECL WeaponType_Laser() {
		return WeaponType::Laser;
	}
	WeaponType DECL WeaponType_Plasma() {
		return WeaponType::Plasma;
	}
	WeaponType DECL WeaponType_Torpedo() {
		return WeaponType::Torpedo;
	}
	WeaponType DECL WeaponType_Bomb() {
		return WeaponType::Bomb;
	}
	
}


