
#include <blocks/Types.h>
#include <blocks/Generator.h>
#include <blocks/ex_blocks.h>

#include <toy/toy.h>

#include <set>

struct Edge
{
	vector<vec2> m_points;
};

Material& cliff_material(GfxSystem& gfx)
{
	Material& material = gfx.fetch_material("cliff", "pbr/pbr");
	material.m_pbr.m_albedo = Colour::DarkGrey;
	return material;
}

Material& ground_material(GfxSystem& gfx)
{
	Material& material = gfx.fetch_material("ground", "pbr/pbr");
	material.m_pbr.m_albedo = Colour(0.1f);//Colour::LightGrey;
	return material;
}

void flat_low(GfxSystem& gfx)
{
	static Material& material = ground_material(gfx);
	Model& model = gfx.models().create("flat_low");
	Quad quad = { 1.f, x3, z3 };
	quad.m_center = vec3(0.f);
	gen_model(ProcShape{ Symbol(), &quad, PLAIN }, model, true, &material);
}

void flat_high(GfxSystem& gfx)
{
	static Material& material = ground_material(gfx);
	Model& model = gfx.models().create("flat_high");
	Quad quad = { 1.f, x3, z3 };
	quad.m_center = y3;
	gen_model(ProcShape{ Symbol(), &quad, PLAIN }, model, true, &material);
}

Edge random_edge(float start, float end, float dv, size_t subdiv)
{
	Edge edge;
	edge.m_points.push_back({ start, 0.f });
	float vmin = 0.5f - dv;
	float vmax = 0.5f + dv;
	for(size_t i = 1; i < subdiv-1; ++i)
	{
		float t = float(i-1) * 1.f / float(subdiv-3);
		edge.m_points.push_back({ randf(vmin, vmax), t });
	}
	edge.m_points.push_back({ end, 1.f });
	return edge;
}

vector<size_t> range(size_t begin, size_t end)
{
	vector<size_t> result;
	for(size_t i = begin; i < end; ++i)
		result.push_back(i);
	return result;
}

Grid3 extrude(const vec3& offset, span<Edge> edges, span<size_t> points, const vec3& dir, const vec3& normal)
{
	Grid3 grid = { uvec2(uint(edges.size()), uint(points.size())) };
	span2d<vec3> vertices = { grid.m_points.data(), grid.m_size.x, grid.m_size.y };

	vec3 du = dir * 1.f / float(edges.size()-1);
	for(size_t i = 0; i < edges.size(); ++i)
		for(uint16_t h = 0; h < points.size(); h++)
		{
			size_t p = points[h];
			vertices.at(i, h) = offset + float(i) * du + edges[i].m_points[p].y * y3;
			vertices.at(i, h) += normal * edges[i].m_points[p].x;
		}

	return grid;
}

Grid3 revolve(const vec3& center, float radius, float start_angle, float end_angle, span<Edge> edges, span<size_t> points, bool reverse_edge)
{
	Grid3 grid = { uvec2(edges.size(), points.size()) };
	span2d<vec3> vertices = { grid.m_points.data(), grid.m_size.x, grid.m_size.y };

	float total_angle = end_angle - start_angle;
	float increment = total_angle / float(edges.size()-1);
	
	for(uint16_t r = 0; r < edges.size(); r++)
		for(uint16_t h = 0; h < points.size(); h++)
		{
			size_t p = points[h];
			float angle = start_angle + r * increment;
			vec3 point = { radius * cos(angle), 0.f, -radius * sin(angle) };

			vertices.at(r, h) = center + edges[r].m_points[p].y * y3;
			vertices.at(r, h) += normalize(point) * (reverse_edge ? (1.f - edges[r].m_points[p].x) : edges[r].m_points[p].x);
		}

	return grid;
}

struct Cliff
{
	static const size_t subdiv = 7;
	Edge edges[7];
};

Cliff random_cliff(Edge &edge0, Edge& edge1, size_t subdiv)
{
	Cliff cliff;
	for(size_t i = 0; i < subdiv; ++i)
		cliff.edges[i] = i == 0 ? edge0 
					   : (i == subdiv - 1 ? edge1
					   : random_edge(0.f, 1.f, 0.1f, subdiv));
	return cliff;
}

inline float sec(float a) { return 1.f / cos(a); }
inline float csc(float a) { return 1.f / sin(a); }

Cliff random_corner_cliff(Edge &edge0, Edge& edge1, size_t subdiv, bool inner)
{
	Cliff cliff = random_cliff(edge0, edge1, subdiv);

	for(uint16_t r = 0; r < Cliff::subdiv; r++)
	{
		float angle = c_pi2 * float(r) / float(Cliff::subdiv - 1);
		float length = min(abs(sec(angle)), abs(csc(angle)));
		if(inner)
		{
			cliff.edges[r].m_points.back().x = length;
			cliff.edges[r].m_points.front().x = 0.01f; // margin so we still end up with squares
		}
		else
			cliff.edges[r].m_points.front().x = 1.f - length;
	}

	return cliff;
}

void cliff_side(GfxSystem& gfx, const string& name, Edge& edge0, Edge& edge1)
{
	static Material& material_cliff = cliff_material(gfx);
	static Material& material_ground = ground_material(gfx);
	Model& model = gfx.models().create(name.c_str());

	Cliff cliff = random_cliff(edge0, edge1, Cliff::subdiv);

	auto extrusion = [&](span<size_t> points, Material& material)
	{
		vec3 offset = z3 * 0.5f - x3 * 0.5f;
		Grid3 grid = extrude(offset, { cliff.edges, Cliff::subdiv }, points, x3, -z3);
		gen_mesh(ProcShape{ Symbol(), &grid, PLAIN }, model, PLAIN, true, &material);
	};

	extrusion(range(0, 2), material_ground);
	extrusion({ 1, Cliff::subdiv - 2 }, material_cliff);
	//extrusion(range(1, Cliff::subdiv - 1), material_cliff);
	extrusion(range(Cliff::subdiv - 2, Cliff::subdiv), material_ground);

	model.prepare();
}

void cliff_corner(GfxSystem& gfx, const string& name, Edge& edge0, Edge& edge1, bool inner)
{
	static Material& material_cliff = cliff_material(gfx);
	static Material& material_ground = ground_material(gfx);
	Model& model = gfx.models().create(name.c_str());

	Cliff cliff = random_corner_cliff(edge0, edge1, Cliff::subdiv, inner);

	auto revolution = [&](span<size_t> points, Material& material)
	{
		Grid3 grid;
		if(inner)
		{
			vec3 offset = z3 - z3 * 0.5f - x3 * 0.5f;
			grid = revolve(offset, 0.5f, c_pi2, 0.f, { cliff.edges, Cliff::subdiv }, points, false);
		}
		else
		{
			vec3 offset = x3 - z3 * 0.5f - x3 * 0.5f;
			grid = revolve(offset, 0.5f, c_pi, c_pi * 3.f / 2.f, { cliff.edges, Cliff::subdiv }, points, true);
		}
		gen_mesh(ProcShape{ Symbol(), &grid, PLAIN }, model, PLAIN, true, &material);
	};
	
	revolution(range(0, 2), material_ground);
	revolution({ 1, Cliff::subdiv - 2 }, material_cliff);
	//revolution(range(1, Cliff::subdiv - 1), material_cliff);
	revolution(range(Cliff::subdiv - 2, Cliff::subdiv), material_ground);

	model.prepare();
}

WaveTileset& generator_tileset(GfxSystem& gfx)
{
	static WaveTileset tileset;

	vector<Edge> m_cliff_edges;

	for(size_t i = 0; i < 1; ++i)
		m_cliff_edges.push_back(random_edge(0.f, 1.f, 0.1f, Cliff::subdiv));

	tileset.m_name = "cliffs";
	tileset.m_tile_size = vec3(1.f) * 5.f;
	tileset.m_tile_scale = vec3(1.f);

	flat_low(gfx);
	flat_high(gfx);

	add_tile(tileset, "flat_low", 'X', 10.f);
	add_tile(tileset, "flat_high", 'X', 1.f);

	std::set<uvec2> cliffs;

	for(uint e0 = 0; e0 < uint(m_cliff_edges.size()); ++e0)
		for(uint e1 = 0; e1 < uint(m_cliff_edges.size()); ++e1)
		{
			uint lo = e0 <  e1 ? e0 : e1;
			uint hi = lo == e0 ? e1 : e0;
			cliffs.insert({ lo, hi });
		}

	auto suffix = [](uvec2 edges) { return "_" + to_string(edges.x) + "_" + to_string(edges.y); };

	for(uvec2 cliff : cliffs)
	{
		cliff_side(gfx, "cliff_side" + suffix(cliff), m_cliff_edges[cliff.x], m_cliff_edges[cliff.y]);
		cliff_corner(gfx, "cliff_corner_out" + suffix(cliff), m_cliff_edges[cliff.x], m_cliff_edges[cliff.y], false);
		cliff_corner(gfx, "cliff_corner_in" + suffix(cliff), m_cliff_edges[cliff.x], m_cliff_edges[cliff.y], true);

		add_tile(tileset, "cliff_side" + suffix(cliff), 'T', 1.f);
		add_tile(tileset, "cliff_corner_out" + suffix(cliff), 'L', 1.f);
		add_tile(tileset, "cliff_corner_in" + suffix(cliff), 'L', 1.f);
	}

	tileset.m_num_tiles = uint16_t(tileset.m_tiles_flip.size());

	tileset.initialize();

	auto connect = [](WaveTileset& tileset, const string& left, const string& right, uint8_t flip_left, uint8_t flip_right, bool horizontal = true)
	{
		int L = tileset.flip(tileset.tile(left)->m_index, flip_left);
		int R = tileset.flip(tileset.tile(right)->m_index, flip_right);
		tileset.connect(L, R, horizontal);
	};

	connect(tileset, "flat_low", "flat_low", 0, 0);
	//connect(tileset, "flat_high", "flat_high", 0, 0);

	//connect(tileset, "flat_low", "flat_high", 0, 0);

	for(uvec2 cliff : cliffs)
	{
		connect(tileset, "flat_high", "cliff_side" + suffix(cliff), 0, 1);
		connect(tileset, "flat_low", "cliff_side" + suffix(cliff), 0, 3);
		connect(tileset, "flat_low", "cliff_corner_out" + suffix(cliff), 0, 0);
		connect(tileset, "cliff_corner_in" + suffix(cliff), "flat_high", 0, 0);
	}

	for(uvec2 left : cliffs)
		for(uvec2 right : cliffs)
		{
			connect(tileset, "cliff_side" + suffix(left), "cliff_side" + suffix(right), 0, 0);
			connect(tileset, "cliff_corner_out" + suffix(left), "cliff_corner_in" + suffix(right), 0, 0);
			connect(tileset, "cliff_corner_out" + suffix(left), "cliff_corner_out" + suffix(right), 0, 1);
			connect(tileset, "cliff_corner_out" + suffix(left), "cliff_side" + suffix(right), 0, 0);
			connect(tileset, "cliff_corner_in" + suffix(right), "cliff_corner_in" + suffix(left), 1, 0);
			connect(tileset, "cliff_side" + suffix(right), "cliff_corner_in" + suffix(left), 0, 0);
		}

	tileset.finalize();

	return tileset;
}

#if 0
void block_generator(GameShell& shell, VisualScript& script)
{
	UNUSED(shell);

	using Var = Valve;

	script.lock();

	//Var& origin = script.input("origin");
	Var& world = script.input("world");

	// Create sectors
	Var& grid_subdiv = script.value(uvec3(4U, 1U, 4U)); // @BUG doesn't work with 1
	Var& block_subdiv = script.value(uvec3(20U));
	Var& cell_size = script.value(vec3(5.f));

	//Var* total_cells = script.function(multiply<vec3>, { &grid_subdiv, &block_subdiv });
	//Var* total_size = script.function(multiply<vec3>, { total_cells, &cell_size });

	Var& grid_subdiv_xz = script.value(uvec2(4U));
	Var& block_subdiv_xz = script.value(uvec2(20U));

	//script.function(block_grid, { &world, &grid_subdiv, &block_subdiv, &cell_size });
	Process& gen = script.node<ProcessFunction>(function(block_grid)).plug({ &world, &grid_subdiv, &block_subdiv, &cell_size });

	Var& sectors = script.get(&BlockWorld::m_sectors, { &world }, &gen);
	Var& blocks = script.get(&Sector::m_block, { &sectors }, &gen, { SM_GRAFT });

	// Create chunks
	Var& tabs = script.value(75U);
	Var& levels = script.value(2U);
	Var& precision = script.value(0.5f);

	// Height
	Var& fract = script.create<Fract>({ &tabs });
	Var& palette = script.create<Palette>({ &script.value(Spectrum::Value), &levels });
	Var& pattern = script.create<Pattern>({ &palette, &script.value(PatternSampling::X), &precision });

	{
		//Var* sample = script.method(&Fract::render_whole, { &fract, &pattern, chunk_size, chunk_size });
		//script.node<ProcessDisplay>().plug({ sample });
	}

	{
		Var* sample = script.method(&Fract::render_grid, { &fract, &grid_subdiv_xz, &pattern, &block_subdiv_xz });
		script.function(paint_block_height, { &blocks, sample, &script.reference((Element*) &Earth::me) });
	}

	script.method(&Block::commit, { &blocks });

	script.unlock();
}

VisualScript& block_generator(GameShell& shell)
{
	static Signature signature = { { { "world", Ref(type<World>()) }, { "origin", Ref(type<Origin>()) } } };
	static VisualScript generator = { "Generator", signature };
	block_generator(shell, generator);
	return generator;
}
#endif

void generate_camps(BlockWorld& world)
{
	float camp_radius = 50.f;
	ivec2 corners[4] = { { 0,   0   }, { 0,    1   }, {  1,    0   }, {  1,    1 } };
	vec2 margins[4] =  { { 1.f, 1.f }, { 1.f, -1.f }, { -1.f,  1.f }, { -1.f, -1.f } };

	vec3 offset = -world.m_world_size * 0.5f;

	for(size_t i = 0; i < 3; ++i)
	{
		Faction& faction = g_factions[i];

		vec3 camp_position = offset + to_xz(vec2(corners[i])) * world.m_world_size + to_xz(margins[i]) * camp_radius;
		Colour colour = Colour::hsl(randf(0.f, 1.f), 1.f, randf(0.5f, 0.7f));

		construct<Camp>(world.m_world.origin(), camp_position, faction);
		construct<Shield>(world.m_world.origin(), camp_position, faction, camp_radius);
		
		vector<vec3> tank_positions = distribute_poisson(vec2(camp_radius), 15.f);
		for(const vec3& tank_position : tank_positions)
		{
			construct<Tank>(world.m_world.origin(), camp_position + tank_position + y3 * 10.f, faction);
		}
	}
}
