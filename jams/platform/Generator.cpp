
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

void generate_crates(TileBlock& block)
{
	float crate_radius = 10.f;
	std::vector<vec3> positions = distribute_poisson(to_xz(block.m_wfc_block.m_aabb.m_extents), crate_radius);

	for(const vec3& position : positions)
	{
		block.m_entity.m_world.origin().construct<Crate>(block.m_entity.m_position + position + Y3 * 10.f, vec3(0.75f));
	}
}

void generate_npcs(TileBlock& block)
{
	float npc_radius = 10.f;
	std::vector<vec3> positions = distribute_poisson(to_xz(block.m_wfc_block.m_aabb.m_extents), npc_radius);

	for(const vec3& position : positions)
	{
		block.m_entity.m_world.origin().construct<Human>(block.m_entity.m_position + position + Y3 * 10.f, Faction::Enemy);
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
	Valve& empty_world = script.create<TileBlock>({ &script.value(0U), &script.input("origin"), &script.value(Zero3), &gridSize, &scale, tileset });
	//Valve& world = script.method(&TileBlock::update, { &empty_world, &wave });

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
