
#include <godot/Types.h>
#include <godot/Generator.h>
#include <godot/ex_godot.h>

#include <toy/toy.h>

void generate_crates(World& world, const vec3& extents)
{
	HSpatial origin = world.origin();

	float crate_radius = 10.f;
	std::vector<vec3> positions = distribute_poisson(to_xz(extents), crate_radius);
	for(const vec3& position : positions)
	{
		construct<Crate>(origin, position + Y3 * 10.f, vec3(0.75f));
	}
}

void generate_npcs(World& world, const vec3& extents)
{
	HSpatial origin = world.origin();

	float npc_radius = 10.f;
	std::vector<vec3> positions = distribute_poisson(to_xz(extents), npc_radius);
	for(const vec3& position : positions)
	{
		construct<Human>(origin, position + Y3 * 10.f, Faction::Enemy);
	}
}

void generate_lamps(World& world, const vec3& extents)
{
	HSpatial origin = world.origin();

	float lamp_radius = 10.f;
	std::vector<vec3> positions = distribute_poisson(to_xz(extents), lamp_radius);
	for(const vec3& position : positions)
	{
		construct<Lamp>(origin, position + Y3 * 10.f);
	}
}
