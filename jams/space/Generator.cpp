
#include <space/Types.h>
#include <space/Generator.h>
#include <space/ex_space.h>
#include <toy/toy.h>

#include <cctype>

uvec2 to_coord(uvec3 coord)
{
	return{ coord.x, coord.z };
}

static const string consonnants = "bcdfghjklmnpqrstvwxz";
static const string vowels = "aeiouy";

string generate_name()
{
	string name = "";

	size_t length = randi(3U, 8U);
	bool vowel = false;
	for(size_t i = 0; i < length; ++i)
	{
		vowel = randf(0.f, 1.f) > (vowel ? 0.8f : 0.2f);
		const string& chars = vowel ? consonnants : vowels;
		size_t c = randi(size_t(0U), chars.size() - size_t(1U));
		name += string(1, char(toupper(chars[c])));
	}

	return name;
}

void generate_avatar(Colour& colour, Image256& avatar)
{
	constexpr uint32_t side = 6;
	avatar.resize(uvec2(side));

	colour = Colour::hsl(randf(0.f, 1.f), 1.f, randf(0.5f, 0.6f));

	Palette palette = { { Colour::None, colour } };
	avatar.m_palette = palette;

	uint16_t halfside = side / 2;
	for(uint16_t x = 0; x < halfside; ++x)
		for(uint16_t y = 0; y < side; ++y)
		{
			bool full = randf(0.f, 1.f) >= 0.5f;
			avatar.at(uvec2(x, y)) = (full ? 1 : 0);
			avatar.at(uvec2(side - 1 - x, y)) = (full ? 1 : 0);
		}
}

HStar generate_system(Galaxy& galaxy, const uvec3& coord, const vec3& position)
{
	int roll = randi(0, 100);
	if(roll < 85)
		return {};

	HStar hstar = construct<Star>(galaxy.m_spatial, galaxy, position, to_coord(coord), generate_name());
	Star& star = hstar;
	star.m_base_population = randi(1, 1000);
	star.m_population = randi(1, star.m_base_population);
	star.m_max_population = star.m_base_population;
	star.m_env = randi(1, 20);
	star.m_resources[Resource::Minerals] = randi(1, 20);
	for(Resource resource = Resource(0); resource != Resource::Count; resource = Resource(size_t(resource) + 1))
		if(randi(1, 100) > 98)
			star.m_resources[resource] = randi(1, 20);
	return hstar;
}

HFleet generate_fleet(Galaxy& galaxy, const uvec3& coord, const vec3& position)
{
	UNUSED(galaxy); UNUSED(coord); UNUSED(position);
	return {};
}

Commander* generate_commander(Galaxy& galaxy, Star& star)
{
	int roll = randi(0, 100);
	if(roll < 85)
		return nullptr;

	/*
	static bool once = true;
	if(once)
		once = false;
	else
		return nullptr;
	*/

	Race race = Race(randi<uint>(uint(Race::Human), uint(Race::Zwiie)));
	int command = randi(0, 100);
	int commerce = randi(0, 100);
	int diplomacy = randi(0, 100);

	vec3 traits = { float(command), float(commerce), float(diplomacy) };
	traits = normalize(traits);

	command = int(traits.x * 90.f);
	commerce = int(traits.y * 90.f);
	diplomacy = int(traits.z * 90.f);

	Commander& commander = global_pool<Commander>().construct(0, generate_name(), race, command, commerce, diplomacy);
	commander.take_star(star);
	commander.m_capital = &star;
	commander.m_centaures = 10'000.f;

	star.m_stocks[Resource::Minerals] = 200;

	star.set_buildings("MINE", 3);
	star.set_buildings("CHANTIER", 1);
	star.set_buildings("POSTE", 1);
	//BLASER1 : 50
	//BPLASMA1 : 20

	galaxy.m_commanders.push_back(&commander);

	generate_avatar(commander.m_colour, commander.m_avatar);

	Fleet& fleet = construct<Fleet>(galaxy.m_spatial, galaxy, star.m_spatial->m_position + 1.0f * y3, commander, star.m_coord, generate_name());

	float size = randf(1.f, 3.f);
	fleet.set_ships("SONDE", size_t(1 * size));
	fleet.set_ships("CHA", size_t(20 * size));
	fleet.set_ships("CHABOM", size_t(10 * size));
	fleet.set_ships("BOM", size_t(10 * size));
	fleet.set_ships("COR", size_t(5 * size));

	return &commander;
}

void assign_system(Galaxy& galaxy, Star& star, vector<Commander*> commanders)
{
	UNUSED(galaxy); UNUSED(star); UNUSED(commanders);
}

void space_generate(HSpatial origin)
{
	uint galaxy_size = 40;

	HGalaxy galaxy = construct<Galaxy>(origin, vec3(0.f), uvec2(galaxy_size));

	as<Universe>(origin->m_world->m_complex).m_galaxies.push_back(galaxy);

	vector<uvec3> coords;
	grid(uvec3(galaxy_size, 1, galaxy_size), coords);

	vector<vec3> positions;
	for(uvec3& coord : coords)
		positions.push_back(grid_center(coord, vec3(1.f)));

	vector<HStar> systems;
	for(size_t i = 0; i < coords.size(); ++i)
		if(HStar star = generate_system(galaxy, coords[i], positions[i]))
		{
			systems.push_back(star);
		}

	for(HStar star : systems)
		generate_commander(galaxy, *star);
}

void space_generator(GameShell& shell, VisualScript& script)
{
	UNUSED(shell);
	script.lock();

	// Sectors
	Valve& parsecs_per_sector = script.value(uvec3(20U));
	Valve& sectors_per_galaxy = script.value(2);
	Valve& parsecs_per_galaxy = script.value(20 * 2);
	UNUSED(parsecs_per_sector);
	
	Valve& galaxy_sectors = script.create<uvec3>({ &sectors_per_galaxy, &script.value(1), &sectors_per_galaxy });
	Valve& galaxy_size = script.create<uvec3>({ &parsecs_per_galaxy, &script.value(1), &parsecs_per_galaxy });
	Valve& galaxy_size2 = script.create<uvec2>({ &parsecs_per_galaxy, &parsecs_per_galaxy });
	UNUSED(galaxy_sectors);

	//Valve* sector_coords = script.function(grid, { &galaxy_sectors });
	//Valve* sector_positions = script.function(grid_center, { sector_coords, &parsecs_per_sector });

	Valve& origin = script.input("origin");

	Valve& galaxy = script.create<Galaxy>({ &script.value(0U), &origin, &script.value(vec3(0.f)), &galaxy_size2 });

	//Valve& sectors = script.create<Quadrant>().pipe({ &script.value(0U), &galaxy, &sectorPositions, &sectorCoords, &sectorParsecs });

	Valve* coords = script.function(grid, { &galaxy_size });
	Valve* positions = script.function(grid_center, { coords, &script.value(vec3(1.f)) });

	Valve* systems = script.function(generate_system, { &galaxy, coords, positions });

	Valve* commanders = script.function(generate_commander, { &galaxy, systems });
	UNUSED(commanders);

	//Valve& assigned_systems = script.function(assignSystem).pipe({ &galaxy, &systems, &commanders });

	//Valve& fleets = script.function(generateFleet).pipe({ &galaxy, &coords, &positions });

	// Create sectors

	script.unlock();
}

VisualScript& space_generator(GameShell& shell)
{
	static Signature signature = { { { "world", type<World>() }, { "origin", type<Origin>() } } };
	static VisualScript generator = { "Generator", signature };
	space_generator(shell, generator);
	return generator;
}
