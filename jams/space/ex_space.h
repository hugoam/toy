//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is provided 'as-is' under the zlib License, see the LICENSE.txt file.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <space/Forward.h>
#include <toy/toy.h>

#include <array>
#include <map>

using namespace mud;
using namespace toy;

extern "C"
{
	//_SPACE_EXPORT void ex_space_game(GameShell& app, Game& game);
}

namespace mud
{
	template <> struct TypedBuffer<Galaxy>	{ static size_t index() { return 20; } };
	template <> struct TypedBuffer<Star>	{ static size_t index() { return 21; } };
	template <> struct TypedBuffer<Fleet>	{ static size_t index() { return 22; } };
}

using HGalaxy = ComponentHandle<Galaxy>;
using HStar = ComponentHandle<Star>;
using HFleet = ComponentHandle<Fleet>;

struct Turn;
_SPACE_EXPORT void next_turn(Turn& turn);

_SPACE_EXPORT void turn_begin(Turn& turn);
_SPACE_EXPORT void turn_divisions(Turn& turn);
_SPACE_EXPORT void turn_jumps(Turn& turn);
_SPACE_EXPORT void turn_spatial_combats(Turn& turn);
_SPACE_EXPORT void turn_planetary_combats(Turn& turn);
_SPACE_EXPORT void turn_stars(Turn& turn);
_SPACE_EXPORT void turn_constructions(Turn& turn);
_SPACE_EXPORT void turn_fleets(Turn& turn);
_SPACE_EXPORT void turn_technology(Turn& turn);
_SPACE_EXPORT void turn_scans(Turn& turn);

void builtin_buildings(BuildingDatabase& database);
void builtin_ships(ShipDatabase& database);

inline bool intersects(const uvec2& coord, const uvec2& lo, const uvec2& hi)
{
	return coord.x >= lo.x && coord.x <= hi.x
		&& coord.y >= lo.y && coord.y <= hi.y;
}

enum class refl_ GameStage : uint32_t
{
	Empire = 0,
	Tactics = 1,
	TurnReport = 2
};

enum class refl_ Race : unsigned int
{
	Human,
	Bulvoid,
	Techtulon,
	Rakrarior,
	Seigneur,
	Meton,
	Tissinar,
	Zwiie
};

enum class refl_ Regime : unsigned int
{
	Empire,
	Dictature,
	Democracy,
	Theocracy,
	Technocracy,
	Piratery,
};

enum class refl_ Politic : unsigned int
{
	Taxes,			// +20% revenue from taxes
	Commerce,		// +1 each resource
	Construction,	// -1 construction time
	Defense,		// +20% combat potential
	Pacification,	// +4 stability & taxation must be <= light
};

enum class refl_ Taxation : unsigned int
{
	None,			// revenue x0, stability +6%/turn
	Light,			// revenue x1, stability +3%/turn
	Medium,			// revenue x1.5
	Heavy,			// revenue x2, stability -3%/turn, growth -1%
	Heaviest,		// revenue x2.5, stability -7%/turn, growth -3%
	Total,			// revenue x3, stability -12%/turn, growth -5%
};

enum class refl_ Resource : unsigned int
{
	None = 0,
	Minerals,
	Andrium,
	Alcool,
	Slaves,
	Narcotics,
	Food,
	Medicine,
	Computers,
	Plastic,
	Robot,
	Count,
};

enum class refl_ FleetSize : unsigned int
{
	Ridicule,
	Minuscule,
	Tiny,
	Small,
	Medium,
	Respectable,
	Grand,
	HighGrand,
	Colossal,
	Titanesque,
	Cyclopean,
	Divine,
	Count,
};

enum class refl_ Experience : unsigned int
{
	Inexperienced,
	LittleExperienced,
	Experienced,
	Superior,
	Elite
};

enum class refl_ FleetStance : unsigned int
{
	Movement,			// -15% combat, +2 movement
	SpatialAttack,		// 
	SpatialDefense,		// +10% combat for first combat
	PlanetaryAttack,	// -10% spatial combat
	PlanetaryDefense,	// 
	Pillage,			// -15% spatial combat
};

enum class refl_ WeaponType : unsigned int
{
	None = 0,
	Ion = 1,
	Laser = 2,
	Plasma = 3,
	Torpedo = 4,
	Bomb = 5
};

enum class refl_ Technology : unsigned int
{
	Engines,			// engine range +1/level
	EcoEnergy,			// ships upkeep -4%/level until level 10, then -2%/level
	Scanners,			// scanner range +1/level
	PlanetaryShields,	// planetary shield +2%/level
	SpatialShields,		// shields resistance +2%/level
	LaserPlasmaIons,	// laser/plasma/ions power +10%/level
	Torpedoes,			// torpedoes power +10%/level
	Bombs,				// bombs power +10%/level
	HullArmor,			// hull resistance +5%/level
	Mining,				// mining output +10%/level
	Terraforming,		// max star terraforming level
	Construction,		// max buildable ship level
	Piloting,			// spatial combat +5%/level
	Commerce,			// selling price +1.5%/level
	Personnel,			// buildings upkeep -3%/level
	Administration,		// income +2%/level
	CyberCommand,		// commandment +3pts/level
	CyberCommerce,		// commerce +3pts/level
	CyberDiplomacy,		// diplomacy +3pts/level
	Count,
};

inline float eco_energy(int level) { int under10 = min(level, 10); int above10 = max(level - 10, 0); return float(under10) * -4.f + float(above10) * -2.f; }

enum class refl_ CombatType : unsigned int
{
	Spatial,
	Planetary
};

static const WeaponType s_weapon_types[4] = { WeaponType::Ion, WeaponType::Laser, WeaponType::Plasma, WeaponType::Torpedo };

extern float g_hull_weight[8];

struct RacialFactors
{
	float m_growth;
	float m_research;
	float m_mining;
	float m_planetary_combat;
	float m_spatial_combat;
	int m_command;
	int m_commerce;
	int m_diplomacy;
};

const RacialFactors c_race_factors[8] =
{
//    growth	research	mining	planetary	spatial		cmd  dipl com
	{ 1.f,		1.f,		1.f,	1.f,		1.f,		  0, +10, +10 },
	{ 0.98f,	1.05f,		1.f,	1.f,		1.f,		  0,   0,   0 },
	{ 0.95f,	1.15f,		0.95f,	0.85f,		0.90f,		  0, +10, +10 },
	{ 1.05f,	0.75f,		0.95f,	1.20f,		1.05f,		+10, -10, -10 },
	{ 0.90f,	1.f,		1.f,	1.f,		1.f,		+10,   0, -10 },
	{ 1.10f,	1.f,		1.1f,	0.85f,		0.85f,		 -5,  +5,  +5 },
	{ 1.f,		0.95f,		0.95f,	0.95f,		1.f,		  0,   0,   0 },
	{ 1.5f,		0.8f,		0.8f,	1.20f,		1.f,		  0, -10, -10 },
};

inline FleetSize fleet_size(float power)
{
	if(power < 100.f)			return FleetSize::Ridicule;
	else if(power < 300.f)		return FleetSize::Minuscule;
	else if(power < 800.f)		return FleetSize::Tiny;
	else if(power < 1'600.f)	return FleetSize::Small;
	else if(power < 3'200.f)	return FleetSize::Medium;
	else if(power < 7'500.f)	return FleetSize::Respectable;
	else if(power < 15'000.f)	return FleetSize::Grand;
	else if(power < 30'000.f)	return FleetSize::HighGrand;
	else if(power < 60'000.f)	return FleetSize::Colossal;
	else if(power < 125'000.f)	return FleetSize::Titanesque;
	else if(power < 250'000.f)	return FleetSize::Cyclopean;
	else						return FleetSize::Divine;
}

inline Experience fleet_experience(float exp)
{
	if(exp < 5.f) return Experience::Inexperienced;
	else if(exp < 20.f) return Experience::LittleExperienced;
	else if(exp < 40.f) return Experience::Experienced;
	else if(exp < 70.f) return Experience::Superior;
	else return Experience::Elite;

}

inline int construction_time(int level)
{
	if(level < 3) return 1;
	else if(level < 5) return 2;
	else if(level < 6) return 3;
	else if(level < 7) return 4;
	else if(level < 8) return 5;
	else return 6;
}

inline float star_taxation_revenue(Taxation taxation)
{
	if(taxation == Taxation::None)			return 0.f;
	else if(taxation == Taxation::Light)	return 1.f;
	else if(taxation == Taxation::Medium)	return 1.5f;
	else if(taxation == Taxation::Heavy)	return 2.f;
	else if(taxation == Taxation::Heaviest) return 2.5f;
	else if(taxation == Taxation::Total)	return 3.f;
	return 0.f;
}

inline int star_taxation_stability(Taxation taxation)
{
	if(taxation == Taxation::None)			return +6;
	else if(taxation == Taxation::Light)	return +3;
	else if(taxation == Taxation::Medium)	return 0;
	else if(taxation == Taxation::Heavy)	return -3;
	else if(taxation == Taxation::Heaviest) return -7;
	else if(taxation == Taxation::Total)	return -12;
	return 0;
}

inline float star_taxation_growth(Taxation taxation)
{
	if(taxation <= Taxation::Medium)		return 0.f;
	else if(taxation == Taxation::Heavy)	return -1.f;
	else if(taxation == Taxation::Heaviest) return -3.f;
	else if(taxation == Taxation::Total)	return -5.f;
	return 0.f;
}

inline int star_distance_stability(int distance)
{
	if(distance == 0) return +2;
	else if(distance <= 2) return +1;
	else if(distance <= 5) return 0;
	else if(distance <= 8) return -1;
	else if(distance <= 11) return -3;
	else if(distance <= 13) return -7;
	else return -10;
}

inline float fleet_stance_modifier(FleetStance stance, CombatType combat, bool fought)
{
	if(stance == FleetStance::Movement) return -15.f;
	else if(stance == FleetStance::SpatialAttack) return 0.f;
	else if(stance == FleetStance::SpatialDefense) return fought ? 0.f : 10.f;
	else if(stance == FleetStance::PlanetaryAttack) return combat == CombatType::Spatial ? -10.f : 0.f;
	else if(stance == FleetStance::PlanetaryDefense) return 0.f;
	else if(stance == FleetStance::Pillage) return combat == CombatType::Spatial ? -15.f : 0.f;
	return 0.f;
}

inline int techno_level(int points)
{
	if(points >= 130'000) return 18;
	else if(points >= 115'000) return 17;
	else if(points >= 100'000) return 16;
	else if(points >= 85'000) return 15;
	else if(points >= 70'000) return 14;
	else if(points >= 60'000) return 13;
	else if(points >= 50'000) return 12;
	else if(points >= 40'000) return 11;
	else if(points >= 30'000) return 10;
	else if(points >= 20'000) return 9;
	else if(points >= 10'000) return 8;
	else if(points >= 6'000) return 7;
	else if(points >= 2'400) return 6;
	else if(points >= 1'200) return 5;
	else if(points >= 600) return 4;
	else if(points >= 400) return 3;
	else if(points >= 200) return 2;
	else if(points >= 100) return 1;
	else return 0;
}

const float c_fleet_visu_sizes[size_t(FleetSize::Count)] = { 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f, 1.f, 1.1f };

struct VisuPlanet
{
	VisuPlanet(vec2 ellipsis, quat rotation, float offset, float speed) : m_ellipsis(ellipsis), m_rotation(rotation), m_speed(speed), m_period(offset) {}
	vec2 m_ellipsis;
	quat m_rotation;
	float m_speed;
	float m_period = 0.f;
};

struct VisuStar
{
	Commander* m_commander = nullptr;
	std::vector<VisuPlanet> m_planets;
	float m_period = 0.f;
	size_t m_updated = 0;
};

struct WeaponRay
{
	vec3 m_start;
	vec3 m_end;
	vec3 m_dir;
	float m_length;
	quat m_angle;
	float m_d;
};

struct VisuShip
{
	float m_radius;
	vec3 m_spot;
	float m_depth;

	vec3 m_position;

	WeaponType m_weapon;
	float m_cooldown;
	WeaponRay m_ray;

	bool m_destroyed;
};

struct VisuFleet
{
	std::vector<VisuShip> m_ships[8];
	Points m_points;
	float m_angle = 0.f;
	float m_offset = 0.f;
	vec3 m_dilate = Unit3;
	size_t m_updated = 0;
};

enum class TurnStage : unsigned int
{
	None = 0,
	Divisions = 1,
	Movements = 2,
	SpatialCombats = 3,
	PlanetaryCombats = 4,
	Systems = 5,
	Constructions = 6,
	Fleets = 7,
	Technology = 8,
	Scans = 9,
	Count = 10
};

using TurnStep = void(*)(Turn&);
export_ extern _SPACE_EXPORT TurnStep g_turn_steps[size_t(TurnStage::Count)];

struct TurnEvents
{
	struct Item
	{
		std::string m_summary;
	};

	enum_array<TurnStage, std::vector<Item>> m_items;
};

struct refl_ _SPACE_EXPORT Turn
{
	Turn(Galaxy& galaxy);

	Galaxy* m_galaxy;
	std::vector<Commander*> m_commanders;

	TurnStage m_stage = TurnStage::None;

	void next_stage() { m_stage = TurnStage(uint(m_stage) + 1); g_turn_steps[size_t(m_stage)](*this);  }

	void add_item(TurnStage stage, Commander& commander, std::string summary)
	{
		m_events[&commander].m_items[size_t(stage)].push_back({ summary });
	}

	std::map<Commander*, TurnEvents> m_events;

	std::vector<Split*> m_divisions;
	std::vector<Jump*> m_jumps;
	std::vector<Jump*> m_tracks;
	std::vector<SpatialCombat> m_spatial_combats;
	std::vector<PlanetaryCombat> m_planetary_combats;

	size_t m_split = 0;
	size_t m_spatial_combat = 0;
	size_t m_planetary_combat = 0;
	size_t m_jump = 0;

	Split* split() { return m_split < m_divisions.size() ? m_divisions[m_split] : nullptr; }
	SpatialCombat* spatial_combat() { return m_spatial_combat < m_spatial_combats.size() ? &m_spatial_combats[m_spatial_combat] : nullptr; }
	PlanetaryCombat* planetary_combat() { return m_planetary_combat < m_planetary_combats.size() ? &m_planetary_combats[m_planetary_combat] : nullptr; }
	Jump* jump() { return m_jump < m_jumps.size() ? m_jumps[m_jump] : nullptr; }
	Jump* track() { return m_jump < m_tracks.size() ? m_tracks[m_jump] : nullptr; }
};

class refl_ _SPACE_EXPORT Player
{
public:
	Player(Galaxy* galaxy, Commander* commander);

	Galaxy* m_galaxy;
	Commander* m_commander;

	HCamera m_camera = {};

	GameStage m_mode = GameStage::Empire;
	
	Entity m_selected_item;
	Entity m_hovered_item;

	Turn m_last_turn;
	Turn m_turn_replay;
};

struct refl_ _SPACE_EXPORT SpatialPower
{
	SpatialPower() : m_values{ 0.f } {}
	SpatialPower(std::array<float, 8> values) : m_values(values) { this->update(); }
	
	std::array<float, 8> m_values;
	float m_average = 0.f;

	void update()
	{
		for(size_t i = 0; i < 8; ++i)
			m_average += m_values[i];
		m_average /= 8.f;
	}

	explicit operator float() const { return m_average; }

	float& operator[](size_t at) { return m_values[at]; }
	const float& operator[](size_t at) const { return m_values[at]; }

	SpatialPower& operator+=(const SpatialPower& rhs) { for(size_t i = 0; i < 8; ++i) m_values[i] += rhs.m_values[i]; this->update(); return *this; }
	SpatialPower& operator*=(float factor) { for(size_t i = 0; i < 8; ++i) m_values[i] *= factor; this->update(); return *this; }
	SpatialPower operator*(float factor) { SpatialPower result = *this; for(size_t i = 0; i < 8; ++i) result.m_values[i] *= factor; result.update(); return result; }
};

struct refl_ _SPACE_EXPORT Construction
{
	Schema* m_schema;
	int m_number;
	Fleet* m_destination;
	int m_turns;
};

class refl_ _SPACE_EXPORT Star
{
public:
	constr_ Star() {}
	constr_ Star(HSpatial spatial, Galaxy& galaxy, const uvec2& coord, const std::string& name);
	~Star();

	static Entity create(ECS& ecs, HSpatial parent, Galaxy& galaxy, const vec3& position, const uvec2& coord, const std::string& name);

	comp_ HSpatial m_spatial;

	attr_ Galaxy* m_galaxy;
	attr_ uvec2 m_coord;
	attr_ std::string m_name;
	
	enum_array<Resource, uint32_t> m_resources = {};
	enum_array<Resource, uint32_t> m_stocks = {};

	enum_array<Resource, uint32_t> m_extractors = {};

	std::map<BuildingSchema*, uint32_t> m_buildings;

	std::vector<Construction> m_constructions;

	attr_ int m_stability = 100;
	attr_ bool m_revolt = false;

	attr_ int m_environment = 10;
	attr_ int m_terraformation = 0;

	attr_ int m_base_population = 0;
	attr_ int m_max_population = 0;
	attr_ int m_population = 0;

	attr_ float m_militia = 0.1f;
	attr_ float m_defense = 0.f;
	attr_ float m_revenue = 0.f;

	attr_ Politic m_politic = Politic::Taxes;
	attr_ Taxation m_taxation = Taxation::Medium;

	attr_ Commander* m_commander = nullptr;

	attr_ int m_scan = 0;

	VisuStar m_visu;

	Galaxy& galaxy();

	void next_frame(Spatial& spatial, size_t tick, size_t delta);

	void add_construction(Schema& schema, int number, Fleet* destination = nullptr);

	void set_buildings(BuildingSchema& schema, uint32_t number);
	void set_buildings(const std::string& code, uint32_t number);

	void add_buildings(BuildingSchema& schema, int number);
	void add_buildings(const std::string& code, int number);
};

struct refl_ _SPACE_EXPORT Jump
{
	Jump() : m_state(None) {}
	Jump(Fleet& fleet, uvec2 start, uvec2 dest, FleetStance stance, size_t tick);

	enum State : unsigned int
	{
		None,
		Ordered,
		Start,
		Warp,
		End,
	};

	void update(Fleet& fleet, size_t tick);

	attr_ Fleet* m_fleet;
	attr_ uvec2 m_start;
	attr_ uvec2 m_dest;
	attr_ FleetStance m_stance;

	attr_ Fleet* m_track;

	vec3 m_start_pos;
	vec3 m_dest_pos;

	State m_state;
	size_t m_state_updated = 0;
};

struct refl_ _SPACE_EXPORT Split
{
	Split() : m_state(None) {}
	Split(Fleet& source, Fleet& dest, const std::string& code, FleetStance stance, std::map<ShipSchema*, uint32_t> ships, size_t tick)
		: m_source(&source), m_dest(&dest), m_code(code), m_stance(stance), m_ships(ships), m_state(Ordered), m_state_updated(tick)
	{}

	enum State : unsigned int
	{
		None,
		Ordered,
		Divide,
	};

	void update(Fleet& fleet, size_t tick);

	attr_ Fleet* m_source;
	attr_ Fleet* m_dest;

	attr_ std::string m_code;
	attr_ FleetStance m_stance;
	std::map<ShipSchema*, uint32_t> m_ships;

	State m_state;
	size_t m_state_updated = 0;
};

class refl_ _SPACE_EXPORT Fleet
{
public:
	constr_ Fleet() {}
	constr_ Fleet(HSpatial spatial, Galaxy& galaxy, Commander& commander, const uvec2& coord, const std::string& name);
	~Fleet();

	static Entity create(ECS& ecs, HSpatial parent, Galaxy& galaxy, const vec3& position, Commander& commander, const uvec2& coord, const std::string& name);

	comp_ HSpatial m_spatial;

	attr_ Galaxy* m_galaxy = nullptr;
	attr_ Commander* m_commander = nullptr;
	attr_ uvec2 m_coord;
	attr_ vec3 m_slot;
	attr_ std::string m_name;

	attr_ float m_experience = 0.f;
	attr_ SpatialPower m_spatial_power = {};
	attr_ float m_planetary_power = 0.f;
	attr_ uint8_t m_speed = 0;
	attr_ uint8_t m_scan = 0;
	attr_ float m_upkeep = 0.f;

	attr_ FleetStance m_stance = FleetStance::Movement;
	
	attr_ Jump m_jump;
	attr_ Split m_split;

	attr_ bool m_fought = false;
	
	FleetSize estimated_size() { return fleet_size(float(m_spatial_power) + m_planetary_power); }
	Experience estimated_experience() { return fleet_experience(m_experience); }

	attr_ size_t m_ships_updated = 0;

	/*attr_ mut_*/ std::map<ShipSchema*, uint32_t> m_ships;

	VisuFleet m_visu;

	Galaxy& galaxy();

	void add_ships(ShipSchema& schema, int number);
	void set_ships(ShipSchema& schema, uint32_t number);

	void add_ships(const std::string& code, int number);
	void set_ships(const std::string& code, uint32_t number);

	void update_ships();

	void jump();
	void split();

	void destroy();

	meth_ void order_jump(vec2 coord, FleetStance stance);
	/*meth_*/ void order_split(cstring name, FleetStance stance, std::map<ShipSchema*, uint32_t> ships);
	meth_ void order_attack(Star& star);

	void next_frame(Spatial& spatial, size_t tick, size_t delta);
};

struct refl_ _SPACE_EXPORT Schema
{
	Schema() {}
	Schema(std::string code, std::string name, std::string conceptor, uint8_t level, float cost, float minerals,
		   float andrium, float resistance = 0.f, uint8_t speed = 0, uint8_t scan = 0, float planetary = 0.f, std::array<float, 8> spatial = {})
		: m_code(code), m_name(name), m_conceptor(conceptor), m_level(level), m_cost(cost), m_minerals(minerals)
		, m_andrium(andrium), m_resistance(resistance), m_speed(speed), m_scan(scan), m_planetary(planetary), m_spatial(spatial)
	{}

	attr_ std::string m_code;
	attr_ std::string m_name;
	attr_ std::string m_conceptor;

	attr_ uint8_t m_level = 1;

	attr_ float m_cost = 0.f;
	attr_ float m_minerals = 0.f;
	attr_ float m_andrium = 0.f;

	attr_ float m_resistance = 0.f;
	attr_ uint8_t m_speed = 0;
	attr_ uint8_t m_scan = 0;

	attr_ float m_planetary = 0.f;
	attr_ SpatialPower m_spatial = {};

	attr_ float m_upkeep_factor = 1.f;
};

struct refl_ _SPACE_EXPORT ShipHull : public Schema
{
	using Schema::Schema;
};

struct refl_ _SPACE_EXPORT ShipEngine : public Schema
{
	using Schema::Schema;
};

struct refl_ _SPACE_EXPORT ShipComponent : public Schema
{
	using Schema::Schema;
};

struct refl_ _SPACE_EXPORT ShipSchema : public Schema
{
	ShipSchema() {}
	ShipSchema(uint8_t size, std::string code, std::string name, std::string conceptor, uint8_t level, float cost, float minerals,
			   float andrium, float resistance, uint8_t speed, uint8_t scan, float planetary, std::array<float, 8> spatial, std::array<uint, 6> weapon_count = {})
		: Schema(code, name, conceptor, level, cost, minerals, andrium, resistance, speed, scan, planetary, spatial)
		, m_size(size), m_class(size - 1), m_weapon_count(weapon_count)
	{
		uint max_weapon = 0;
		for(size_t i = 0; i < 4; ++i)
			if(m_weapon_count[i] > max_weapon)
			{
				max_weapon = m_weapon_count[i];
				m_main_weapon = WeaponType(i);
			}
	}

	attr_ uint8_t m_size;
	attr_ uint8_t m_class;

	std::array<uint, 6> m_weapon_count;

	attr_ WeaponType m_main_weapon = WeaponType::None;

	//ShipHull* m_hull;
	//ShipEngine* m_engine;
	//std::vector<ShipComponent*> m_components;
};

struct refl_  _SPACE_EXPORT BuildingSchema : public Schema
{
	using Schema::Schema;

	BuildingSchema(std::string code, std::string name, std::string conceptor, uint8_t level, float cost, float minerals, Resource extractor)
		: Schema(code, name, conceptor, level, cost, minerals, 0.f)
		, m_extractor(extractor)
	{}

	Resource m_extractor = Resource::None;
};

template <class T_Schema>
class _SPACE_EXPORT SchemaDatabase
{
public:
	SchemaDatabase() {}

	T_Schema& schema(const std::string& code)
	{
		for(T_Schema& schema : m_schemas)
			if(schema.m_code == code)
				return schema;
	}

	std::vector<T_Schema> m_schemas;
};

class _SPACE_EXPORT ShipDatabase : public SchemaDatabase<ShipSchema>
{
public:
	ShipDatabase();
	attr_ static ShipDatabase me;
};

class _SPACE_EXPORT BuildingDatabase : public SchemaDatabase<BuildingSchema>
{
public:
	BuildingDatabase();
	attr_ static BuildingDatabase me;
};

struct refl_ _SPACE_EXPORT Scans
{
	std::vector<HStar> m_stars;
	std::vector<HFleet> m_fleets;
	//attr_ std::vector<Star*> m_stars;
	//attr_ std::vector<Fleet*> m_fleets;
};

// float technology_upkeep(int points, )

struct refl_ _SPACE_EXPORT TechDomain
{
	int m_level = 0;
	int m_points = 0;
	float m_budget = 0.f;
};

class refl_ _SPACE_EXPORT Commander
{
public:
	constr_ Commander(Id id, const std::string& name, Race race, int command, int commerce, int diplomacy);
	~Commander();

	//attr_ Entity m_spatial;

	attr_ Id m_id;
	attr_ std::string m_name;
	attr_ Race m_race;
	attr_ int m_command;
	attr_ int m_commerce;
	attr_ int m_diplomacy;

	attr_ int m_reputation;
	attr_ int m_victory;

	Colour m_colour;
	Image256 m_avatar;

	attr_ std::vector<HStar> m_stars;
	attr_ std::vector<HFleet> m_fleets;

	attr_ Star* m_capital = nullptr;
	attr_ Regime m_regime = Regime::Empire;

	attr_ float m_power = 0.f;
	attr_ float m_centaures = 0.f;

	attr_ Scans m_scans;
	
	enum_array<Technology, TechDomain> m_technology = {};

	inline int level(Technology tech) { return m_technology[size_t(tech)].m_level; }

	void next_frame(size_t tick, size_t delta);

	void update_scans(Galaxy& galaxy);
	void update_power();

	void take_star(Star& star);
	void take_fleet(Fleet& fleet);

	bool allied(Commander& commander) { return &commander == this; }
};

#if 0
class refl_ _SPACE_EXPORT Quadrant
{
public:
	constr_ Quadrant(HSpatial spatial, const vec3& position, const uvec2& coord, float size);

	attr_ CSpatial m_spatial;

	attr_ uvec2 m_coord;
	attr_ float m_size;

	attr_ std::vector<Star*> m_stars;
};
#endif

struct GalaxyGrid
{
	GalaxyGrid();

	void add_fleet(Fleet& fleet, uvec2 coord);
	void move_fleet(Fleet& fleet, uvec2 start, uvec2 dest);

	void update_slots(uvec2 coord);

	std::map<uvec2, std::vector<Fleet*>> m_fleets;
	std::map<uvec2, Star*> m_stars;
};

using Buildings = std::map<BuildingSchema*, uint32_t>;
using Ships = std::map<ShipSchema*, uint32_t>;
using Flotilla = std::vector<Fleet*>;

struct refl_ _SPACE_EXPORT Combat
{
	enum State : unsigned int
	{
		DONE,
		APPROACH,
		ENGAGE,
	};

	Combat(State state, size_t tick = 0) : m_state(state), m_state_updated(tick) {}

	State m_state;
	size_t m_state_updated = 0;

	float m_t = 0.f;
	float m_t_damage = 0.f;
	float m_t_position = 0.f;
	float m_dt_intensity = 0.f;

	struct Force
	{
		float m_damage[8] = {};
		float m_power[8] = {};
		float m_metal[8] = {};
	};

	Force m_force_attack;
	Force m_force_defense;

};

struct refl_ _SPACE_EXPORT CombatFleet
{
	CombatFleet(Fleet& fleet) : m_fleet(&fleet) {}
	Fleet* m_fleet;
	float m_damage = 0.f;
	Ships m_losses = {};
	std::array<uint32_t, 8> m_hull_losses = {};
};

struct refl_ _SPACE_EXPORT CombatStar
{
	CombatStar() {}
	CombatStar(Star& star) : m_star(&star) {}
	Star* m_star = nullptr;
	float m_damage = 0.f;
	Buildings m_losses = {};
};

struct refl_ _SPACE_EXPORT PlanetaryCombat : public Combat
{
	PlanetaryCombat() : Combat(DONE) {}

	PlanetaryCombat(Star& star, uvec2 coord, size_t tick)
		: Combat(APPROACH, tick), m_coord(coord), m_defense(star)
	{}

	attr_ uvec2 m_coord;

	attr_ std::vector<CombatFleet> m_attack;
	attr_ CombatStar m_defense;

	void apply_losses();
};

struct refl_ _SPACE_EXPORT SpatialCombat : public Combat
{
	SpatialCombat() : Combat(DONE) {}

	SpatialCombat(uvec2 coord, size_t tick)
		: Combat(APPROACH, tick), m_coord(coord)
	{}

	attr_ uvec2 m_coord;

	attr_ std::vector<CombatFleet> m_attack;
	attr_ std::vector<CombatFleet> m_defense;

	void apply_losses();
};

class refl_ _SPACE_EXPORT Galaxy
{
public:
	constr_ Galaxy() {}
	constr_ Galaxy(HSpatial spatial, const uvec2& size);
	~Galaxy();

	static Entity create(ECS& ecs, HSpatial parent, const vec3& position, const uvec2& size);

	comp_ HSpatial m_spatial;

	//attr_ std::vector<HQuadrant> m_quadrants;
	attr_ std::vector<HStar> m_stars;
	attr_ std::vector<HFleet> m_fleets;
	attr_ std::vector<Commander*> m_commanders;
	attr_ uvec2 m_size;

	GalaxyGrid m_grid;

	uvec3 m_scale = uvec3(1);
	Plane m_plane = { Y3, 0.5f };

	uvec2 intersect_coord(Ray ray);
};

class refl_ _SPACE_EXPORT Universe : public Complex
{
public:
	constr_ Universe(const std::string& name, JobSystem& job_system);
	~Universe();

	attr_ World m_world;
	attr_ BulletWorld m_bullet_world;

	std::vector<HGalaxy> m_galaxies;

	static const TPool<Universe> s_pool;
};

class refl_ _SPACE_EXPORT CommanderBrush : public Brush
{
public:
	CommanderBrush(ToolContext& context);

	attr_ Commander* m_commander;
	attr_ float m_radius;

	virtual ToolState start();
	virtual void update(const vec3& position);
	virtual void paint(Gnode& parent);
};
