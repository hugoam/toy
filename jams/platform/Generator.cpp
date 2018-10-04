
#include <platform/Types.h>
#include <platform/Generator.h>
#include <platform/ex_platform.h>

#include <toy/toy.h>

WaveTileset& generator_tileset(GfxSystem& gfx_system)
{
	LocatedFile location = gfx_system.locate_file("models/platform/platform.tls");
	std::string filepath = std::string(location.m_location) + "models/platform/platform.tls";

	static WaveTileset tileset;
	parse_json_wave_tileset(filepath, "", tileset);
	return tileset;
}

void generate_crates(Tileblock& block)
{
	HSpatial origin = block.m_spatial->m_world->origin();

	float crate_radius = 10.f;
	std::vector<vec3> positions = distribute_poisson(to_xz(block.m_wfc_block.m_aabb.m_extents), crate_radius);
	for(const vec3& position : positions)
	{
		construct<Crate>(origin, block.m_spatial->m_position + position + Y3 * 10.f, vec3(0.75f));
	}
}

void generate_npcs(Tileblock& block)
{
	HSpatial origin = block.m_spatial->m_world->origin();

	float npc_radius = 10.f;
	std::vector<vec3> positions = distribute_poisson(to_xz(block.m_wfc_block.m_aabb.m_extents), npc_radius);
	for(const vec3& position : positions)
	{
		construct<Human>(origin, block.m_spatial->m_position + position + Y3 * 10.f, Faction::Enemy);
	}
}

void generate_lamps(Tileblock& block)
{
	HSpatial origin = block.m_spatial->m_world->origin();

	for(size_t x = 0; x < block.m_wfc_block.m_tiles.m_x; ++x)
		for(size_t y = 0; y < block.m_wfc_block.m_tiles.m_y; ++y)
			for(size_t z = 0; z < block.m_wfc_block.m_tiles.m_z; ++z)
			{
				Tile& tile = block.m_wfc_block.m_tileset->m_tiles_flip[block.m_wfc_block.m_tiles.at(x, y, z)];
				if(tile.m_name == "cube_covered_side")
					if(random_integer(0, 9) > 8)
					{
						construct<Lamp>(origin, block.m_wfc_block.to_position(uvec3(x, y, z)) + Y3 * 1.5f * block.m_wfc_block.m_scale);
					}
			}
}

void platform_generator(GameShell& shell, VisualScript& script)
{
	script.lock();

	Valve& height = script.value(4);
	Valve& tiles = script.value(20);
	Valve& gridSize = script.create<uvec3>({ &tiles, &height, &tiles });

	Valve* coords = script.function(grid, { &gridSize });

	LocatedFile location = shell.m_gfx_system->locate_file("models/platform/platform.tls");
	std::string filepath = std::string(location.m_location) + "models/platform/platform.tls";
	Valve* tileset = script.function(parse_json_wave_tileset, { &script.value(filepath), &script.value(std::string("")) });

	//Valve& empty_wave = script.create<TileWave>({ &tileset, &tiles, &height, &tiles, &script.value(false) });
	//Valve& solve_steps = script.value(0);
	//Process& solve = script.method(&Wave::solve).plug({ &empty_wave, &solve_steps });
	//Valve& solve_result = *solve.m_outputs[0];
	//Valve& wave = *solve.m_outputs[1];
	//Valve& wave = empty_wave;

	Valve& scale = script.value(vec3(4.f));
	Valve& empty_world = script.create<Tileblock>({ &script.value(0U), &script.input("origin"), &script.value(Zero3), &gridSize, &scale, tileset });
	//Valve& world = script.method(&Tileblock::update, { &empty_world, &wave });

#if 0
	// Create crates
	if(0)
	{
		Var& radius = script.value(15.f);
		Var* positions = script.function(distribute_poisson, { &script.value(vec2{ 50.f }), &radius }); // .flow(sectors

		Var& extents = script.value(vec3(0.75f, 0.5f, 0.4f));
		Var& crates = script.create<Crate>({ &script.value(0), &sectors, positions, &extents });
	}

	// Create characters
	if(0)
	{
		Var& radius = script.value(20.f);
		//Var& positions = script.function(distribute_poisson{ &sectorSize2, &radius });
		Var* positions = script.function(distribute_poisson, { &script.value(vec2{ 50.f }), &radius }); // .flow(sectors

		Var& crates = script.create<Human>({ &script.value(0), &sectors, positions, &script.value(0.35f), &script.value(2.f),
											 &script.value(std::string("Human")), &script.value(std::string("X")) });
	}
#endif

	script.unlock();
}

VisualScript& platform_generator(GameShell& shell)
{
	static Signature signature = { { { "world", Ref(type<World>()) }, { "origin", Ref(type<Origin>()) } } };
	static VisualScript generator = { "Generator", signature };
	platform_generator(shell, generator);
	return generator;
}
