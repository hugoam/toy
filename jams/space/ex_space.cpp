
#include <space/ex_space.h>
#include <toy/toy.h>

#include <meta/_space.conv.h>
#include <meta/_space.meta.h>
#include <space/Api.h>
#include <shell/Shell.h>

#include <space/Generator.h>
#include <space/Scene.h>
#include <space/Ui.h>

using namespace two;
using namespace toy;

float g_hull_weight[8] = { 2.f, 6.f, 20.f, 50.f, 100.f, 150.f, 200.f, 250.f };

table<TurnStage, TurnStep> g_turn_steps = { turn_begin, turn_divisions, turn_jumps, turn_spatial_combats, turn_planetary_combats, turn_stars, turn_constructions, turn_fleets, turn_technology, turn_scans };

void star_power(Star& star, Combat::Force& force)
{
	float race_modifier = star.m_commander ? 100.f - c_race_factors[star.m_commander->m_race].m_planetary_combat * 100.f
										   : 0.f;
	float defense_modifier = star.m_politic == Politic::Defense ? 20.f : 0.f;

	float modifier = 100.f + (star.m_commander ? star.m_commander->m_command : 0.f)
		+ defense_modifier
		+ race_modifier;
	modifier /= 100.f;

	for(size_t i = 0; i < 8; ++i)
		force.m_damage[i] += star.m_militia * float(star.m_population) * 2.5f * modifier;

	for(auto& kv : star.m_buildings)
	{
		BuildingSchema& building = *kv.first;
		int number = kv.second;

		for(size_t i = 0; i < 8; ++i)
			force.m_damage[i] += building.m_spatial[i] * modifier * float(number);

		force.m_power[0] += float(building.m_spatial) * modifier * float(number);
		force.m_metal[0] += float(number);
	}
}

void fleet_power_planetary(span<CombatFleet> flotilla, Combat::Force& force)
{
	for(const CombatFleet& combat_fleet : flotilla)
	{
		Fleet& fleet = *combat_fleet.m_fleet;

		float race_modifier = 100.f - c_race_factors[fleet.m_commander->m_race].m_spatial_combat * 100.f;
		float stance_modifier = fleet_stance_modifier(fleet.m_stance, CombatType::Planetary, fleet.m_fought);

		float modifier = 100.f + fleet.m_commander->m_command
			+ race_modifier
			+ stance_modifier
			+ fleet.m_experience;
		modifier /= 100.f;

		for(auto& kv : fleet.m_ships)
		{
			ShipSchema& ship = *kv.first;
			size_t number = kv.second;

			force.m_damage[0] += ship.m_planetary * modifier * float(number);

			for(size_t i = 0; i < 8; ++i)
			{
				force.m_power[i] += ship.m_planetary * modifier * float(number);
				force.m_metal[i] += g_hull_weight[ship.m_class] * float(number);
			}
		}
	}
}

void fleet_power_spatial(span<CombatFleet> flotilla, Combat::Force& force)
{
	for(const CombatFleet& combat_fleet : flotilla)
	{
		Fleet& fleet = *combat_fleet.m_fleet;

		float race_modifier = 100.f - c_race_factors[fleet.m_commander->m_race].m_spatial_combat * 100.f;
		float stance_modifier = fleet_stance_modifier(fleet.m_stance, CombatType::Spatial, fleet.m_fought);

		float modifier = 100.f + fleet.m_commander->m_command
			+ race_modifier
			+ stance_modifier
			+ fleet.m_commander->level(Technology::Piloting) * 5.f
			+ fleet.m_experience;
		modifier /= 100.f;

		for(auto& kv : fleet.m_ships)
		{
			ShipSchema& ship = *kv.first;
			uint32_t number = kv.second;

			for(size_t i = 0; i < 8; ++i)
				force.m_damage[i] += ship.m_spatial[i] * modifier * float(number);

			force.m_power[ship.m_class] += float(ship.m_spatial) * modifier * float(number);
			force.m_metal[ship.m_class] += g_hull_weight[ship.m_class] * float(number);
		}
	}
}

void star_losses(CombatStar& star, float ratio)
{
	for(auto& kv : star.m_star->m_buildings)
	{
		BuildingSchema& building = *kv.first;

		float damage = max(0.f, ratio - building.m_resistance * 0.01f);
		uint32_t losses = uint32_t(star.m_star->m_buildings[&building] * damage);

		star.m_losses[&building] = losses;
	}
}

void fleet_losses(span<CombatFleet> flotilla, float ratio)
{
	for(CombatFleet& combat_fleet : flotilla)
	{
		combat_fleet.m_damage = ratio;

		for(auto& kv : combat_fleet.m_fleet->m_ships)
		{
			ShipSchema& ship = *kv.first;

			float damage = max(0.f, ratio - ship.m_resistance * 0.01f);
			uint32_t losses = uint32_t(combat_fleet.m_fleet->m_ships[&ship] * damage);

			combat_fleet.m_losses[&ship] = losses;
			combat_fleet.m_hull_losses[ship.m_class] += losses;
		}
	}
}

void resolve_combat(PlanetaryCombat& combat)
{
	fleet_power_planetary(combat.m_attack, combat.m_force_attack);
	star_power(*combat.m_defense.m_star, combat.m_force_defense);

	float allies = combat.m_force_attack.m_damage[0] / combat.m_force_defense.m_metal[0];
	float enemies = 0.f;

	for(size_t i = 0; i < 8; ++i)
	{
		enemies += combat.m_force_defense.m_damage[i] / combat.m_force_attack.m_metal[i];
	}

	float total = allies + enemies;

	fleet_losses(combat.m_attack, enemies / total);
	star_losses(combat.m_defense, allies / total);
}

void resolve_combat(SpatialCombat& combat)
{
	fleet_power_spatial(combat.m_attack, combat.m_force_attack);
	fleet_power_spatial(combat.m_defense, combat.m_force_defense);

	float allies = 0.f;
	float enemies = 0.f;

	for(size_t i = 0; i < 8; ++i)
	{
		allies += combat.m_force_attack.m_damage[i] * combat.m_force_defense.m_metal[i];
		enemies += combat.m_force_defense.m_damage[i] * combat.m_force_attack.m_metal[i];
	}

	float total = allies + enemies;

	fleet_losses(combat.m_attack, enemies / total);
	fleet_losses(combat.m_defense, allies / total);
}

void SpatialCombat::apply_losses()
{
	auto apply = [](CombatFleet& combat_fleet)
	{
		for(auto& kv : combat_fleet.m_fleet->m_ships)
		{
			ShipSchema& ship = *kv.first;
			combat_fleet.m_fleet->add_ships(ship, -int(combat_fleet.m_losses[&ship]));
		}
	};

	for(CombatFleet& combat_fleet : m_attack)
		apply(combat_fleet);
	for(CombatFleet& combat_fleet : m_defense)
		apply(combat_fleet);
}

void PlanetaryCombat::apply_losses()
{
	auto apply = [](CombatFleet& combat_fleet)
	{
		for(auto& kv : combat_fleet.m_fleet->m_ships)
		{
			ShipSchema& ship = *kv.first;
			combat_fleet.m_fleet->add_ships(ship, -int(combat_fleet.m_losses[&ship]));
		}
	};

	for(CombatFleet& combat_fleet : m_attack)
		apply(combat_fleet);
	//for(CombatFleet& combat_fleet : m_defense)
	//	apply(combat_fleet);

	if(true)
		m_attack[0].m_fleet->m_commander->take_star(*m_defense.m_star);
}

void gather_allies(Fleet& fleet, CombatType combat_type, vector<CombatFleet>& attack)
{
	UNUSED(combat_type);
	for(Fleet* other : fleet.galaxy().m_grid.m_fleets[fleet.m_coord])
	{
		if(other->m_commander->allied(*fleet.m_commander))
			attack.push_back({ *other });
	}
}

void gather_allies(Fleet& fleet, CombatType combat_type, vector<CombatFleet>& attack, vector<CombatFleet>& defense)
{
	UNUSED(combat_type);
	for(Fleet* other : fleet.galaxy().m_grid.m_fleets[fleet.m_coord])
	{
		if(other->m_commander->allied(*fleet.m_commander))
			attack.push_back({ *other });
		else
			defense.push_back({ *other });
	}
}

void spatial_combat(Turn& turn, Fleet& fleet)
{
	SpatialCombat combat = { fleet.m_coord, fleet.m_spatial->m_last_tick };

	gather_allies(fleet, CombatType::Spatial, combat.m_attack, combat.m_defense);

	if(!combat.m_defense.empty())
	{
		resolve_combat(combat);
		turn.m_spatial_combats.push_back(combat);
	}
}

void planetary_combat(Turn& turn, Fleet& fleet)
{
	Star* star = turn.m_galaxy->m_grid.m_stars[fleet.m_coord];
	if(!star) return;

	PlanetaryCombat combat = { *star, fleet.m_coord, fleet.m_spatial->m_last_tick };
	
	gather_allies(fleet, CombatType::Spatial, combat.m_attack);

	resolve_combat(combat);
	turn.m_planetary_combats.push_back(combat);
}

void extract_resources(Turn& turn, Commander& commander, Star& star)
{
	auto mining_factor = [&](Commander& commander)
	{
		return 1.f + commander.level(Technology::Mining) * 0.10f + (1.f - c_race_factors[commander.m_race].m_mining);
	};

	for(Resource resource = Resource(0); resource != Resource::Count; resource = Resource(size_t(resource) + 1))
	{
		bool is_mining = (resource == Resource::Minerals || resource == Resource::Andrium);
		int extracted = star.m_resources[resource] * star.m_extractors[resource];
		extracted = int(extracted * (is_mining ? mining_factor(commander) : 1.f));
		if(extracted > 0)
		{
			star.m_stocks[resource] += extracted;
			turn.add_item(TurnStage::Systems, commander, "System " + star.m_name + " extracted " + to_string(extracted) + " " + to_string(resource));
		}
	}
}

void commit_construction(Turn& turn, Commander& commander, Star& star, Construction& construction)
{
	int number = construction.m_number; // @todo clamp number depending on actual resources

	star.m_stocks[Resource::Minerals] -= int(construction.m_schema->m_minerals * number);
	star.m_stocks[Resource::Andrium] -= int(construction.m_schema->m_andrium * number);
	commander.m_centaures -= construction.m_schema->m_cost * number;

	if(construction.m_destination)
	{
		construction.m_destination->add_ships(*static_cast<ShipSchema*>(construction.m_schema), number);
		turn.add_item(TurnStage::Constructions, commander, "Construction of " + to_string(number) + " " + construction.m_schema->m_code + " for fleet " + construction.m_destination->m_name);
	}
	else
	{
		star.add_buildings(*static_cast<BuildingSchema*>(construction.m_schema), number);
		turn.add_item(TurnStage::Constructions, commander, "Construction of " + to_string(number) + " " + construction.m_schema->m_code + " on system " + star.m_name);
	}
}

void advance_constructions(Turn& turn, Commander& commander, Star& star)
{
	for(Construction& construction : star.m_constructions)
	{
		construction.m_turns -= 1;
		if(construction.m_turns == 0)
			commit_construction(turn, commander, star, construction);
	}
	remove_if(star.m_constructions, [](Construction& construction) { return construction.m_turns == 0; });
}

void grow_population(Turn& turn, Commander& commander, Star& star)
{
	int growth = int(star.m_population * star.m_env / 100.f * c_race_factors[commander.m_race].m_growth);
	growth = min(growth, star.m_max_population - star.m_population);
	if(growth > 0)
	{
		star.m_population += growth;
		turn.add_item(TurnStage::Systems, commander, "Population of " + star.m_name + " grew by " + to_string(growth) + " units");
	}
}

void collect_taxes(Turn& turn, Commander& commander, Star& star)
{
	int population = star.m_population - int(star.m_militia * float(star.m_population));
	star.m_revenue = population * (star_taxation_revenue(star.m_taxation) + commander.level(Technology::Administration) * 0.02f + (star.m_politic == Politic::Taxes ? 0.2f : 0.f));
	commander.m_centaures += star.m_revenue;
	turn.add_item(TurnStage::Systems, commander, "System " + star.m_name + " collected " + truncate_number(to_string(star.m_revenue)) + "C in taxes");
}

void sustain_system(Turn& turn, Commander& commander, Star& star)
{
	float upkeep = star.m_militia * float(star.m_population) * 0.5f;
	commander.m_centaures -= upkeep;
	turn.add_item(TurnStage::Systems, commander, "Star " + star.m_name + " militia cost " + truncate_number(to_string(upkeep)) + "C");
}

void update_stability(Turn& turn, Commander& commander, Star& star)
{
	UNUSED(turn);
	ivec2 distance2 = abs(ivec2(star.m_coord) - ivec2(commander.m_capital->m_coord));
	int distance = distance2.x > distance2.y ? distance2.x : distance2.y;
	int modifier = star_distance_stability(distance) + star_taxation_stability(star.m_taxation) + (star.m_politic == Politic::Pacification ? 4 : 0);
	star.m_stability = clamp(star.m_stability + modifier, 0, 100);
}

void sustain_fleet(Turn& turn, Commander& commander, Fleet& fleet)
{
	float upkeep_factor = (100.f + eco_energy(commander.level(Technology::EcoEnergy))) / 100.f;
	float upkeep = fleet.m_upkeep * upkeep_factor;
	commander.m_centaures -= upkeep;
	turn.add_item(TurnStage::Fleets, commander, "Fleet " + fleet.m_name + " sustenance cost " + truncate_number(to_string(upkeep)) + "C");
}

void advance_technology(Turn& turn, Commander& commander, Technology tech, TechDomain& domain)
{
	commander.m_centaures -= domain.m_budget;
	domain.m_points += int(domain.m_budget * c_race_factors[commander.m_race].m_research);
	int level = techno_level(domain.m_points);
	if(level != domain.m_level)
	{
		domain.m_level = level;
		turn.add_item(TurnStage::Technology, commander, "Technology " + to_string(tech) + " has reached level " + to_string(level));
	}
}

void turn_begin(Turn& turn)
{
	UNUSED(turn);
}

void turn_divisions(Turn& turn)
{
	for(Commander* commander : turn.m_commanders)
		for(HFleet fleet : commander->m_fleets)
			if(fleet->m_split.m_state == Split::Ordered)
			{
				turn.m_divisions.push_back(&fleet->m_split);
			}
}

void turn_jumps(Turn& turn)
{
	for(Commander* commander : turn.m_commanders)
		for(HFleet fleet : commander->m_fleets)
			if(fleet->m_jump.m_state == Jump::Ordered)
			{
				turn.m_jumps.push_back(&fleet->m_jump);
			}
}

void turn_spatial_combats(Turn& turn)
{
	for(Commander* commander : turn.m_commanders)
		for(HFleet fleet : commander->m_fleets)
		{
			if(fleet->m_stance == FleetStance::SpatialAttack)
				spatial_combat(turn, *fleet);
		}
}

void turn_planetary_combats(Turn& turn)
{
	for(Commander* commander : turn.m_commanders)
		for(HFleet fleet : commander->m_fleets)
		{
			if(fleet->m_stance == FleetStance::PlanetaryAttack)
			{
				//spatial_combat(turn, *fleet); @todo planetary defense
				planetary_combat(turn, *fleet);
			}
		}
}

void turn_stars(Turn& turn)
{
	for(Commander* commander : turn.m_commanders)
	{
		for(HStar star : commander->m_stars)
		{
			if(star->m_revolt)
				continue;

			grow_population(turn, *commander, *star);
			collect_taxes(turn, *commander, *star);
			extract_resources(turn, *commander, *star);
			sustain_system(turn, *commander, *star);
			update_stability(turn, *commander, *star);

			// @todo remove (debug)
			advance_constructions(turn, *commander, *star);
		}
	}
}

void turn_constructions(Turn& turn)
{
	for(Commander* commander : turn.m_commanders)
	{
		for(HStar star : commander->m_stars)
		{
			if(star->m_revolt)
				continue;

			advance_constructions(turn, *commander, *star);
		}
	}
}
void turn_fleets(Turn& turn)
{
	for(Commander* commander : turn.m_commanders)
	{
		commander->m_power = 0.f;

		for(HFleet fleet : commander->m_fleets)
		{
			sustain_fleet(turn, *commander, *fleet);
			commander->m_power += float(fleet->m_spatial_power);
			commander->m_power += fleet->m_planetary_power;
		}
	}
}

void turn_technology(Turn& turn)
{
	for(Commander* commander : turn.m_commanders)
	{
		for(Technology tech = Technology(0); tech != Technology::Count; tech = Technology(size_t(tech) + 1))
			advance_technology(turn, *commander, tech, commander->m_technology[tech]);
	}
}

void turn_scans(Turn& turn)
{
	for(Commander* commander : turn.m_commanders)
	{
		commander->update_scans(*turn.m_galaxy);
	}
}

void next_turn(Turn& turn)
{
	turn_divisions(turn);
	turn_jumps(turn);
	turn_spatial_combats(turn);
	turn_planetary_combats(turn);
	turn_stars(turn);
	turn_constructions(turn);
	turn_fleets(turn);
	turn_technology(turn);
	turn_scans(turn);
}

BuildingDatabase BuildingDatabase::me;

BuildingDatabase::BuildingDatabase()
	: SchemaDatabase<BuildingSchema>()
{
	builtin_buildings(*this);
}

ShipDatabase ShipDatabase::me;

ShipDatabase::ShipDatabase()
	: SchemaDatabase<ShipSchema>()
{
	builtin_ships(*this);
}

Prototype universe = { type<Universe>(), { &type<World>(), &type<BulletWorld>() } };

Universe::Universe(const string& name, JobSystem& job_system)
	: Complex(0, type<Universe>(), m_bullet_world, *this)
	, m_world(0, *this, name, job_system)
	, m_bullet_world(m_world)
{}

Universe::~Universe()
{}

GalaxyGrid::GalaxyGrid()
{}

void GalaxyGrid::update_slots(uvec2 coord)
{
	vec3 center = to_xz(vec2(coord)) + 0.5f + y3;

	map<Commander*, vector<Fleet*>> fleets;
	for(Fleet* fleet : m_fleets[coord])
	{
		fleets[fleet->m_commander].push_back(fleet);
	}

	float theta = c_2pi / float(fleets.size());
	float angle = 0.f;
	for(auto& commander_fleets : fleets)
	{
		vec3 slot = fleets.size() == 1 ? center : center + rotate(-z3 * 0.2f, angle, x3);
		for(Fleet* fleet : commander_fleets.second)
		{
			float size = c_fleet_visu_sizes[fleet->estimated_size()];
			fleet->m_slot = slot;
			//fleet->m_spatial.set_position(slot);
			//animate(Ref(&as<Transform>(fleet->m_spatial)), member(&Spatial::m_position), var(slot), 0.25f);
			slot += y3 * -size;
		}
		angle += theta;
	}
}

void GalaxyGrid::add_fleet(Fleet& fleet, uvec2 coord)
{
	m_fleets[coord].push_back(&fleet);
	update_slots(coord);
}

void GalaxyGrid::move_fleet(Fleet& fleet, uvec2 start, uvec2 dest)
{
	remove(m_fleets[start], &fleet);
	m_fleets[dest].push_back(&fleet);
	fleet.m_coord = dest;
	update_slots(dest);
}

Entity Galaxy::create(ECS& ecs, HSpatial parent, const vec3& position, const uvec2& size)
{
	Entity entity = ecs.create<Spatial, Galaxy>();
	ecs.set(entity, Spatial(parent, position, ZeroQuat));
	ecs.set(entity, Galaxy(HSpatial(entity), size));
	return entity;
}

Galaxy::Galaxy(HSpatial spatial, const uvec2& size)
	: m_spatial(spatial)
	, m_size(size)
{}

Galaxy::~Galaxy()
{}

uvec2 Galaxy::intersect_coord(Ray ray)
{
	vec3 intersect = plane_segment_intersection(m_plane, { ray.m_start, ray.m_end });
	ivec3 icoord = ivec3(floor(intersect));
	uvec3 coord = uvec3(icoord); // / m_period;
	return { coord.x, coord.z };
}

#if 0
Quadrant::Quadrant(HSpatial spatial, const vec3& position, const uvec2& coord, float size)
	: Entity(Tags<Spatial, Quadrant*>{})
	, m_spatial(*this, *this, parent, position, ZeroQuat)
	, m_coord(coord)
	, m_size(size)
{
	ecs.set<Quadrant*>(m_handle, this);

	galaxy.m_quadrants.push_back(this);
}
#endif

static size_t star_count = 0;

Entity Star::create(ECS& ecs, HSpatial parent, Galaxy& galaxy, const vec3& position, const uvec2& coord, const string& name)
{
	Entity entity = ecs.create<Spatial, Star>();
	ecs.set(entity, Spatial(parent, position, ZeroQuat));
	ecs.set(entity, Star(HSpatial(entity), galaxy, coord, name));
	return entity;
}

Star::Star(HSpatial spatial, Galaxy& galaxy, const uvec2& coord, const string& name)
	: m_spatial(spatial)
	, m_galaxy(&galaxy)
	, m_coord(coord)
	, m_name(name)
	, m_resources{}
{
	galaxy.m_stars.push_back(spatial);
	galaxy.m_grid.m_stars[coord] = this;
}

Star::~Star()
{}

Galaxy& Star::galaxy() { return *m_galaxy; }

void Star::next_frame(Spatial& spatial, size_t tick, size_t delta)
{
	UNUSED(spatial); UNUSED(tick); UNUSED(delta);
	float speed = 0.001f;
	m_visu.m_period = fmod(m_visu.m_period + delta * speed, c_2pi);

	for(VisuPlanet& planet : m_visu.m_planets)
	{
		planet.m_period = fmod(planet.m_period + delta * speed * planet.m_speed, c_2pi);
	}
}

void Star::add_construction(Schema& schema, int number, Fleet* destination)
{
	m_constructions.push_back({ &schema, number, destination, construction_time(schema.m_level) });
}

void Star::set_buildings(BuildingSchema& schema, uint32_t number)
{
	if(number == 0)
		m_buildings.erase(&schema);
	else
		m_buildings[&schema] = number;

	if(schema.m_extractor != Resource::None)
		m_extractors[schema.m_extractor] = m_buildings[&schema];
}

void Star::set_buildings(const string& code, uint32_t number)
{
	this->set_buildings(BuildingDatabase::me.schema(code), number);
}

void Star::add_buildings(BuildingSchema& schema, int number)
{
	this->set_buildings(schema, m_buildings[&schema] + number);
}

void Star::add_buildings(const string& code, int number)
{
	this->add_buildings(BuildingDatabase::me.schema(code), number);
}

static size_t fleet_count = 0;

Entity Fleet::create(ECS& ecs, HSpatial parent, Galaxy& galaxy, const vec3& position, Commander& commander, const uvec2& coord, const string& name)
{
	Entity entity = ecs.create<Spatial, Fleet>();
	ecs.set(entity, Spatial(parent, position, ZeroQuat));
	ecs.set(entity, Fleet(HSpatial(entity), galaxy, commander, coord, name));
	return entity;
}

Fleet::Fleet(HSpatial spatial, Galaxy& galaxy, Commander& commander, const uvec2& coord, const string& name)
	: m_spatial(spatial)
	, m_galaxy(&galaxy)
	, m_commander(&commander)
	, m_coord(coord)
	, m_name(name)
{
	commander.m_fleets.push_back(spatial);

	galaxy.m_fleets.push_back(spatial);
	galaxy.m_grid.add_fleet(*this, coord);
}

Fleet::~Fleet()
{}

Galaxy& Fleet::galaxy() { return *m_galaxy; }

void update_visu_fleet(VisuFleet& visu, size_t tick, size_t delta)
{
	float speed = 0.001f;
	visu.m_angle = fmod(visu.m_angle + delta * speed, c_2pi);
	visu.m_offset = sin(tick * speed);
	visu.m_dilate.z = remap_trig(visu.m_offset, 0.7f, 1.f);
}

void Fleet::next_frame(Spatial& spatial, size_t tick, size_t delta)
{
	UNUSED(spatial);
	update_visu_fleet(m_visu, tick, delta);
}

void Fleet::set_ships(ShipSchema& schema, uint32_t number)
{
	if(number == 0)
		m_ships.erase(&schema);
	else
		m_ships[&schema] = number;

	this->update_ships();
}

void Fleet::add_ships(ShipSchema& schema, int number)
{
	if(number < 0 && size_t(abs(number)) > m_ships[&schema])
	{
		printf("[warning] removing more ships than the fleet contains");
		number = -int(m_ships[&schema]);
	}
	this->set_ships(schema, m_ships[&schema] + number);
}

void Fleet::set_ships(const string& code, uint32_t number)
{
	this->set_ships(ShipDatabase::me.schema(code), number);
}

void Fleet::add_ships(const string& code, int number)
{
	this->add_ships(ShipDatabase::me.schema(code), number);
}

void Fleet::update_ships()
{
	m_ships_updated = m_spatial->m_last_tick + 1;

	m_spatial_power = {};
	m_planetary_power = 0.f;
	m_speed = UINT8_MAX;
	m_scan = 0U;
	m_upkeep = 0.f;

	for(auto& ship_number : m_ships)
	{
		ShipSchema& ship = *ship_number.first;
		size_t number = ship_number.second;

		m_spatial_power += ship.m_spatial * float(number);
		m_planetary_power += ship.m_planetary * float(number);
		m_speed = min(m_speed, ship.m_speed);
		m_scan = max(m_scan, ship.m_scan);
		m_upkeep += ship.m_cost * ship.m_upkeep_factor * 0.1f;
	}
}

static inline Jump::State jump_none(Fleet& fleet, float elapsed) { UNUSED(fleet); UNUSED(elapsed); return Jump::None; }
static inline Jump::State jump_ordered(Fleet& fleet, float elapsed) { UNUSED(fleet); UNUSED(elapsed); return Jump::Start; }
static inline Jump::State jump_start(Fleet& fleet, float elapsed) { if(elapsed > 3.0f) { fleet.jump(); return Jump::Warp; } else return Jump::Start; }
static inline Jump::State jump_warp(Fleet& fleet, float elapsed) { UNUSED(fleet); if(elapsed > 0.25f) return Jump::End; else return Jump::Warp; }
static inline Jump::State jump_end(Fleet& fleet, float elapsed) { UNUSED(fleet); if(elapsed > 0.5f) return Jump::None; else return Jump::End; }

using StateFunc = Jump::State(*)(Fleet&, float);
static constexpr StateFunc s_fleet_states[5] = { jump_none, jump_ordered, jump_start, jump_warp, jump_end };

Jump::Jump(Fleet& fleet, uvec2 start, uvec2 dest, FleetStance stance, size_t tick)
	: m_fleet(&fleet), m_start(start), m_dest(dest), m_stance(stance), m_state(Ordered), m_state_updated(tick)
	, m_start_pos(fleet.m_spatial->m_position)
	, m_dest_pos(to_xz(vec2(dest)) + 0.5f + y3)
{}

void Jump::update(Fleet& fleet, size_t tick)
{
	float elapsed = float((tick - m_state_updated) * c_tick_interval);
	State old_state = m_state;
	m_state = s_fleet_states[static_cast<size_t>(m_state)](fleet, elapsed);
	m_state_updated = old_state == m_state ? m_state_updated : tick;
}

void Fleet::order_jump(uvec2 coord, FleetStance stance)
{
	printf("Fleet %s from commander %s : jump to [%i,%i] in directive %s\n", m_name.c_str(), m_commander->m_name.c_str(), int(coord.x), int(coord.y), to_string(stance).c_str());
	m_jump = { *this, m_coord, coord, stance, m_spatial->m_last_tick };
}

void Split::update(Fleet& fleet, size_t tick)
{
	UNUSED(tick);
	fleet.split();
	m_state = Split::None;
}

void Fleet::order_split(const string& code, FleetStance stance, Ships ships)
{
	printf("Fleet %s from commander %s : split fleet %s in directive %s\n", m_name.c_str(), m_commander->m_name.c_str(), code.c_str(), to_string(stance).c_str());
	Fleet& divided = construct<Fleet>(m_galaxy->m_spatial, *m_galaxy, m_spatial->m_position, *m_commander, m_coord, code);
	m_split = { *this, divided, code, stance, ships, m_spatial->m_last_tick };

	// precalculate speed so that we can give jump orders during the same turn
	divided.m_speed = UINT8_MAX;
	for(auto& ship_number : ships)
		divided.m_speed = min(divided.m_speed, ship_number.first->m_speed);
}

void Fleet::order_attack(Star& star)
{
	printf("Fleet %s from commander %s : attack star %s\n", m_name.c_str(), m_commander->m_name.c_str(), star.m_name.c_str());
}

void Fleet::jump()
{
	this->galaxy().m_grid.move_fleet(*this, m_coord, m_jump.m_dest);
	m_stance = m_jump.m_stance;
}

void Fleet::split()
{
	for(auto& ship_number : m_split.m_ships)
	{
		this->add_ships(*ship_number.first, -int(ship_number.second));
		m_split.m_dest->add_ships(*ship_number.first, int(ship_number.second));
	}
}

void Fleet::destroy()
{
	if(m_commander)
		remove(m_commander->m_fleets, HFleet(m_spatial));
}

Commander::Commander(uint32_t id, const string& name, Race race, int command, int commerce, int diplomacy)
	: m_id(index(type<Commander>(), id, Ref(this)))
	, m_name(name)
	, m_race(race)
	, m_command(command + c_race_factors[race].m_command)
	, m_commerce(commerce + c_race_factors[race].m_commerce)
	, m_diplomacy(diplomacy + c_race_factors[race].m_diplomacy)
{}

Commander::~Commander()
{
	unindex(type<Commander>(), m_id);
}

void Commander::next_frame(size_t tick, size_t delta)
{
	UNUSED(tick); UNUSED(delta);
}

void Commander::update_scans(Galaxy& galaxy)
{
	m_scans.m_fleets.clear();
	m_scans.m_stars.clear();

	auto scan = [](Galaxy& galaxy, uvec2 coord, uint scan, vector<HFleet>& fleets, vector<HStar>& stars)
	{
		uvec2 lo = coord - min(uvec2(scan), coord);
		uvec2 hi = coord + scan;

		for(HFleet fleet : galaxy.m_fleets)
			if(intersects(fleet->m_coord, lo, hi))
				fleets.push_back(fleet);

		for(HStar star : galaxy.m_stars)
			if(intersects(star->m_coord, lo, hi))
				stars.push_back(star);
	};

	for(HFleet fleet : m_fleets)
		scan(galaxy, fleet->m_coord, fleet->m_scan, m_scans.m_fleets, m_scans.m_stars);
	for(HStar star : m_stars)
		scan(galaxy, star->m_coord, star->m_scan, m_scans.m_fleets, m_scans.m_stars);
}

void Commander::take_star(Star& star)
{
	HStar hstar = star.m_spatial;
	if(star.m_commander)
		remove(star.m_commander->m_stars, hstar);
	m_stars.push_back(hstar);
	star.m_commander = this;
}

void Commander::take_fleet(Fleet& fleet)
{
	HFleet hfleet = fleet.m_spatial;
	if(fleet.m_commander)
		remove(fleet.m_commander->m_fleets, hfleet);
	m_fleets.push_back(hfleet);
	fleet.m_commander = this;
}

CommanderBrush::CommanderBrush(ToolContext& context)
	: Brush(context, "Commander", type<CommanderBrush>())
	, m_commander(nullptr)
	, m_radius(3.f)
{}

Colour rgb_to_rgba(const Colour& colour, float a)
{
	return{ colour.r, colour.g, colour.b, a };
}

void CommanderBrush::paint(Gnode& parent)
{
	if(!m_commander) return;

	gfx::node(parent, m_position);
	gfx::shape(parent, Circle(m_radius, Axis::Y), Symbol(Colour::White, rgb_to_rgba(m_commander->m_colour, 0.3f)));
}

ToolState CommanderBrush::start()
{
	return ToolState();
	//return SpatialTool::start();
}

void CommanderBrush::update(const vec3& position)
{
	if(!m_commander) return;

	Galaxy& galaxy = m_commander->m_stars[0]->galaxy();
	for(HStar star : galaxy.m_stars)
		if(distance(star->m_spatial->m_position, position) <= m_radius)
			m_commander->take_star(*star);
}

Turn::Turn(Galaxy& galaxy)
	: m_galaxy(&galaxy), m_commanders(galaxy.m_commanders)
{}

Player::Player(Galaxy* galaxy, Commander* commander)
	: m_galaxy(galaxy), m_commander(commander), m_last_turn(*galaxy), m_turn_replay(*galaxy)
{
	m_camera = construct<toy::Camera>(galaxy->m_spatial->m_world->origin(), vec3(10.f, 0.f, 10.f), 25.f, 0.1f, 300.f);
	m_camera->set_lens_angle(c_pi4);
}

void ex_space_lua_check(GameShell& shell, Galaxy& galaxy)
{
	LuaInterpreter& lua = *shell.m_lua;

	lua.set("col", Ref(&Colour::Pink));
	lua.call("print('col.r = ' .. col.r)");
	lua.call("print('col.g = ' .. col.g)");
	lua.call("Colour.Pink.g = 5.93");
	lua.call("print('col.g = ' .. col.g)");
	lua.call("print('Colour.Green.g = ' .. Colour.Green.g)");

	lua.set("galaxy", Ref(&galaxy));
	lua.call("star = galaxy.stars[1]");
	lua.call("fleet = galaxy.fleets[1]");
	lua.call("fleet:order_attack(star)");
	lua.set("coord", var(vec2(45.f, 12.f)));
	lua.call("coord = vec2(45, 12)");
	lua.set("stance", var(FleetStance::PlanetaryAttack));
	//float x = lua.getx<float>({ "coord", "x" });
	//printf("cpp -> coord.x = %f\n", x);
	lua.call("print('coord = ' .. coord.x .. ', ' .. coord.y)");
	lua.call("print('stance = ' .. tostring(stance))");
	lua.call("fleet:order_jump(coord, stance)");

	//lua.call("objects = Index.me.indexer().objects");
}

Style& menu_style()
{
	static Style style = { "GameMenu", styles().wedge, [](Layout& l) { l.m_space = Preset::Unit; l.m_align = { Align::Left, Align::Center }; l.m_padding = vec4(120.f); l.m_padding.x = 240.f; l.m_spacing = vec2(30.f); } };
	return style;
}

Style& button_style(UiWindow& ui_window)
{
	UNUSED(ui_window);
	static Style style = { "GameButton", styles().button, [](Layout& l) { UNUSED(l); },
														  [](InkStyle& s) { s.m_empty = false; s.m_text_colour = Colour::AlphaWhite; s.m_text_size = 24.f; },
														  [](Style& s) { s.decline_skin(HOVERED).m_text_colour = Colour::White; } };
	return style;
}

Viewer& ex_space_menu_viewport(Widget& parent, GameShell& app)
{
	Viewer& viewer = ui::scene_viewer(parent);
	Gnode& scene = viewer.m_scene->begin();

#ifdef TOY_SOUND
	scene.m_sound_manager = app.m_sound_system.get();
#endif

	paint_viewer(viewer);
	paint_scene(scene);

	viewer.m_camera.m_eye = z3;

	static Ships ships;
	static VisuFleet fleet;
	if(fleet.m_updated == 0)
	{
		auto set_ships = [&](const string& code, uint32_t number) { ships[&ShipDatabase::me.schema(code)] = number; };
		set_ships("CHA", 80);
		set_ships("COR", 10);

		fill_fleet(fleet, ships);
		fleet.m_updated = 1;
	}

	static Clock clock;
	
	size_t tick = clock.readTick();
	size_t delta = clock.stepTick();

	update_visu_fleet(fleet, tick, delta);

	float angle = fmod(float(clock.read()) / 50.f, c_2pi);
	Gnode& node = gfx::node(scene, vec3(0.f), angle_axis(angle, y3), vec3(1.f));
	paint_fleet_ships(node, fleet, 1.f, 0.1f);
	
	//toy::sound(node, "complexambient", true);

	return viewer;
}

void ex_space_menu(Widget& parent, Game& game)
{
	static Style& style_button = button_style(parent.ui_window());
	static Style& style_menu = menu_style();

	Widget& self = ui::board(parent);

	Viewer& viewer = ex_space_menu_viewport(self, *game.m_shell);
	Widget& overlay = ui::screen(viewer);

	Widget& menu = ui::widget(overlay, style_menu);

	ui::icon(menu, "(toy)");

	if(ui::button(menu, style_button, "Start game").activated())
	{
		game.m_module->start(*game.m_shell, game);
	}

	ui::button(menu, style_button, "Continue game");
	ui::button(menu, style_button, "Quit");
}

class ExSpaceModule : public GameModule
{
public:
	ExSpaceModule(Module& module) : GameModule(module) {}

	virtual void scene(GameShell& app, GameScene& scene) final
	{
		UNUSED(app);
		Player& player = val<Player>(scene.m_player);

		scene.painter("Galaxy", [&](size_t, VisuScene&, Gnode& parent) {
			paint_galaxy(parent, *player.m_galaxy);
			paint_scene(parent);
		});
		scene.object_painter<Star>("Stars", player.m_galaxy->m_stars, paint_star);
		scene.object_painter<Star>("Stars", player.m_commander->m_stars, paint_scan_star);
		scene.object_painter<Star>("Stars", player.m_commander->m_scans.m_stars, paint_scan_star);
		scene.object_painter<Fleet>("Fleets", player.m_commander->m_fleets, paint_scan_fleet);
		scene.object_painter<Fleet>("Fleets", player.m_commander->m_scans.m_fleets, paint_scan_fleet);

		scene.painter("Combat", [&](size_t, VisuScene&, Gnode& parent) {
			if(player.m_turn_replay.spatial_combat())
				paint_combat(parent, *player.m_turn_replay.spatial_combat());
			//if(player.m_turn_replay.planetary_combat())
			//	paint_combat(parent, *player.m_turn_replay.planetary_combat());
		});

		Spatial& spatial = asa<Spatial>(player.m_camera);
		spatial.m_position = player.m_commander->m_capital->m_spatial->m_position;
	}

	virtual void init(GameShell& app, Game& game) final
	{
		app.m_gfx->add_resource_path("examples/ex_space");

		game.m_editor.m_custom_brushes.push_back(construct<CommanderBrush>(game.m_editor.m_tool_context));
	}

	virtual void start(GameShell& app, Game& game) final
	{
		Universe& universe = global_pool<Universe>().construct("Arcadia", *app.m_job_system);
		World& world = universe.m_world;
		game.m_world = &world;

		world.add_loop<Star, Spatial>(Task::GameObject);
		world.add_loop<Fleet, Spatial>(Task::GameObject);

		//VisualScript& generator = space_generator(app);
		//generator({ Ref(game.m_world), Ref(&game.m_world->origin()) });

		space_generate(game.m_world->origin());

		Galaxy& galaxy = *universe.m_galaxies[0];

		static Player player = { &galaxy, galaxy.m_commanders[0] };
		game.m_player = Ref(&player);

		for(Commander* commander : galaxy.m_commanders)
			commander->update_scans(galaxy);
	}

	virtual void pump(GameShell& app, Game& game, Widget& ui) final
	{
		auto pump = [&](Widget& parent, Dockbar* dockbar = nullptr)
		{
			UNUSED(dockbar);
			if(!game.m_player)
			{
				ex_space_menu(parent, game);
			}
			else
			{
				static GameScene& scene = app.add_scene();
				ex_space_ui(parent, scene);
			}
		};

#ifdef _SPACE_TOOLS
		edit_context(ui, app.m_editor, true);
		pump(*app.m_editor.m_screen, app.m_editor.m_dockbar);
#else
		pump(ui);
#endif
	}
};

#ifdef _EX_SPACE_EXE
int main(int argc, char *argv[])
{
	GameShell app(TOY_RESOURCE_PATH, exec_path(argc, argv).c_str());

	ExSpaceModule module = { _space::m() };
	app.run_game(module);
}
#endif
