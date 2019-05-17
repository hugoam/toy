
#include <space/Types.h>
#include <space/Scene.h>
#include <space/ex_space.h>

#include <toy/toy.h>

void fill_star(VisuStar& visu, Star& star)
{
	UNUSED(star);
	size_t num_planets = randi(3, 12);
	for(size_t i = 0; i < num_planets; ++i)
	{
		float distance = randf(0.f, 1.f);
		float speed = 1.f / (c_2pi * distance) * 10.f;
		float offset = randf(0.f, 2.f * float(c_pi));
		float aniso = randf(0.8f, 1.2f);
		float pitch = randf(0.8f * float(c_pi), 1.2f * float(c_pi));
		float roll = randf(0.8f * float(c_pi), 1.2f * float(c_pi));
		visu.m_planets.push_back({ vec2(distance, distance * aniso) *0.4f, quat({ pitch, 0.f, roll }), offset, speed });
	}
}

mat4 planet_transform(VisuPlanet& planet, const mat4& transform)
{
	vec2 coord = vec2(cos(planet.m_period), sin(planet.m_period)) * planet.m_ellipsis;
	mat4 planet_mat = bxSRT(vec3(1.f), vec3(0.f), rotate(planet.m_rotation, vec3(coord.x, 0.f, coord.y)));
	return bxmul(planet_mat, transform);
}

void paint_planet_ellipsis(Gnode& parent, VisuPlanet& planet)
{
	gfx::node(parent, rotate(planet.m_rotation, parent.m_attach->position()), planet.m_rotation);
	gfx::shape(parent, Ellipsis(planet.m_ellipsis), Symbol::wire(Colour::AlphaGrey), ItemFlag::Default | ItemFlag::Selectable);
}

void paint_star_ellipses(Gnode& parent, VisuStar& visu)
{
	for(size_t i = 0; i < visu.m_planets.size(); ++i)
		paint_planet_ellipsis(parent, visu.m_planets[i]);
}

void paint_star_planets(Gnode& parent, Star& star)
{
	VisuStar& visu = star.m_visu;

	if(visu.m_updated == 0)
	{
		fill_star(visu, star);
		visu.m_updated = 1;
	}

	Item& item = gfx::shape(parent, Sphere(0.005f), Symbol(), 0, nullptr);
	Batch& batch = gfx::batch(parent, item, sizeof(mat4));
	mat4 transform = parent.m_attach->m_transform;

	batch.m_cache.clear();

	for(size_t i = 0; i < visu.m_planets.size(); ++i)
	{
		batch.transform(planet_transform(visu.m_planets[i], transform));
	}

	//paint_star_ellipses(parent, star);
}

void paint_star(Gnode& parent, Star& star)
{
	paint_star_planets(parent, star);
}

inline vec3 to_xz3(const vec3& vec) { return { vec.x, 0.f, vec.z }; }

void paint_range_grid(Gnode& parent, const Colour& colour, int range)
{
	float side = float(range * 2 + 1);
	Gnode& projected = gfx::node(parent, to_xz3(parent.m_attach->position()) + y3 * 0.5f);
	gfx::shape(projected, Grid2(vec2(side), vec2(2.5f)), Symbol::wire(colour));
}

void paint_range(Gnode& parent, const Colour& colour, int range)
{
	if(range == 0) return;
	float side = float(range * 2 + 1);
	Gnode& projected = gfx::node(parent, to_xz3(parent.m_attach->position()) + y3 * 0.5f);
	gfx::shape(projected, Quad(side, x3, z3), Symbol::wire(colour));
}

inline float sec(float a) { return 1.f / cos(a); }
inline float csc(float a) { return 1.f / sin(a); }

void paint_range_sonar(Gnode& parent, const Colour& colour, int range)
{
	static Clock clock;

	float angle = fmod(float(clock.read()), c_2pi);
	float length = min(abs(sec(angle)), abs(csc(angle))) * range;
	vec3 end = rotate(x3 * length, angle, y3);

	Gnode& projected = gfx::node(parent, to_xz3(parent.m_attach->position()) + y3 * 0.5f);
	gfx::draw(projected, Line(vec3(0.f), end), Symbol::wire(colour));
}

void paint_scan_star(Gnode& parent, Star& star, Player& player)
{
	gfx::shape(parent, Circle(0.4f, Axis::Y), Symbol(Colour::Invisible), ItemFlag::Default | ItemFlag::Selectable);
	gfx::shape(parent, Sphere(0.01f), Symbol(Colour::White * 4.f), ItemFlag::Default | ItemFlag::Selectable);

	bool hovered = player.m_hovered_item == star.m_spatial;
	bool selected = player.m_selected_item == star.m_spatial;

	Colour colour = star.m_commander ? star.m_commander->m_colour * 3.f : Colour{ 0.3f, 0.3f, 0.3f, 0.1f };
	if(player.m_mode == GameStage::Empire && star.m_commander != player.m_commander)
		colour = saturation(colour, 0.7f);
	if(hovered)
		colour = colour * 1.5f;

	gfx::shape(parent, Circle(0.4f, Axis::Y), Symbol::wire(colour));
	//gfx::shape(parent, Circle(0.4f, Axis::Z), Symbol(colour), ItemFlag::Render | ItemFlag::Billboard);

	//if(star.m_commander)
	//	gfx::sprite(parent, star.m_commander->m_avatar, vec2(0.4f), ItemFlag::Render | ItemFlag::Billboard | ItemFlag::Selectable);

	if(star.m_commander == player.m_commander)
	{
		if(star.m_commander->m_capital == &star)
			gfx::shape(parent, Circle(0.5f, Axis::Y), Symbol::wire(colour));

		if(!star.m_constructions.empty())
			gfx::shape(parent, Quad(0.5f, x3, z3), Symbol::wire(colour));

		if(star.m_revolt)
			gfx::shape(parent, Circle(0.3f, Axis::Y), Symbol::wire(Colour::Red));
	}

	if((selected || hovered) && star.m_commander == player.m_commander)
	{
		if(star.m_scan > 0)
			paint_range(parent, colour, star.m_scan);
	}
}

void paint_scan_star(Gnode& parent, Star& star)
{
	Player& player = val<Player>(parent.root().m_scene->m_user);
	paint_scan_star(parent, star, player);
}

static float spaceship_sizes[8] = { 0.01f, 0.02f, 0.03f, 0.04f, 0.05f, 0.06f, 0.08f, 0.1f };

void fill_fleet(VisuFleet& visu, const Ships& ships)
{
	for(size_t i = 0; i < 8; ++i)
		visu.m_ships[i].clear();

	visu.m_points.m_points.clear();
	
	for(auto& kv : ships)
	{
		ShipSchema& schema = *kv.first;
		for(size_t i = 0; i < kv.second; ++i)
		{
			visu.m_ships[schema.m_class].push_back({ spaceship_sizes[schema.m_class] });
			visu.m_ships[schema.m_class].back().m_weapon = schema.m_main_weapon;
			visu.m_ships[schema.m_class].back().m_destroyed = false;
		}
	}

	for(size_t size = 0; size < 8; ++size)
	{
		Poisson distribution = { vec2(1.f), spaceship_sizes[size] };
		distribution.m_start_from_center = true;

		visu.m_points.m_points.resize(visu.m_points.m_points.size() + visu.m_ships[size].size());

		for(VisuShip& ship : visu.m_ships[size])
		{
			distribution.addPoint(ship.m_radius, ship.m_spot);
			ship.m_depth = randf(0.f, 1.f);
			ship.m_spot.z = ship.m_depth;
			ship.m_spot = ship.m_spot * 2.f - 1.f;
			ship.m_cooldown = randf(0.f, 1.f);
		}
	}
}

vec3 ship_position(VisuFleet& fleet, VisuShip& ship, float radius)
{
	quat rot = angle_axis(fleet.m_angle, z3);
	return rotate(rot, fleet.m_dilate * ship.m_spot * radius);
}

void update_fleet_positions(VisuFleet& visu, float radius)
{
	size_t index = 0;
	for(size_t size = 0; size < 8; ++size)
		for(size_t i = 0; i < visu.m_ships[size].size(); ++i)
		{
			visu.m_ships[size][i].m_position = ship_position(visu, visu.m_ships[size][i], radius);
			visu.m_points.m_points[index++] = visu.m_ships[size][i].m_position;
		}
}

mat4 ship_transform(VisuShip& ship, const mat4& transform, const vec3& position, float ship_scale)
{
	vec3 scale = ship.m_destroyed ? vec3(0.f) : vec3(ship.m_radius  * ship_scale);
	mat4 ship_mat = bxSRT(scale, vec3(0.f), position);
	return bxmul(ship_mat, transform);
}

void paint_fleet_ships(Gnode& parent, VisuFleet& visu, float radius, float ship_scale)
{
	update_fleet_positions(visu, radius);

	Model& model = *parent.m_scene->m_gfx.models().file("spaceship");

	size_t index = 0;
	for(size_t size = 0; size < 8; ++size)
		if(!visu.m_ships[size].empty())
		{
			Item& item = gfx::item(parent, model, ItemFlag::Render | ItemFlag::Lod0);
			Batch& batch = gfx::batch(parent, item, sizeof(mat4));

			const mat4 transform = parent.m_attach->m_transform;

			batch.m_cache.clear();
			for(size_t i = 0; i < visu.m_ships[size].size(); ++i)
				batch.transform(ship_transform(visu.m_ships[size][i], transform, visu.m_points.m_points[index++], ship_scale));
		}
}

void paint_fleet_orders(Gnode& parent, Fleet& fleet, const Colour& colour)
{
	if(fleet.m_jump.m_state == Jump::Ordered)
	{
		vec3 start = fleet.m_jump.m_start_pos;
		vec3 end = to_xz(vec2(fleet.m_jump.m_dest)) + 0.5f + y3;
		vec3 middle = (end + start) / 2.f + y3 * 0.2f * length(end - start);
		gfx::shape(parent, ArcLine(-start, start, middle, end), Symbol::wire(colour));
	}
}

void paint_fleet_jumping(Gnode& parent, Fleet& fleet, const Colour& colour)
{
	float size = c_fleet_visu_sizes[fleet.estimated_size()];
	gfx::shape(parent, Circle(0.4f * size, Axis::Z), Symbol::wire(colour), ItemFlag::Render | ItemFlag::Billboard);
}

void paint_fleet_warp(Gnode& parent, VisuFleet& visu)
{
	UNUSED(parent); UNUSED(visu);
}

void paint_fleet_stationary(Gnode& parent, Fleet& fleet, VisuFleet& visu, const Colour& colour)
{
	float size = c_fleet_visu_sizes[fleet.estimated_size()];
	vec2 triangle = { 0.4f * size, 0.6f * size };
	gfx::shape(parent, Triangle(triangle), Symbol::wire(colour), ItemFlag::Render | ItemFlag::Billboard);
	gfx::shape(parent, Triangle(triangle * 1.2f), Symbol(Colour::Invisible), ItemFlag::Render | ItemFlag::Billboard | ItemFlag::Selectable);
	paint_fleet_ships(parent, visu, 0.4f * size * 2.f, 0.01f);
}

void paint_scan_fleet(Gnode& parent, Fleet& fleet, Player& player)
{
	enum States {  Fleet = 0, Warp = 1, Jump = 2, Orders = 3, ScanRange = 4, JumpRange = 5, Thrusters = 6 };

	VisuFleet& visu = fleet.m_visu;

	if(fleet.m_ships_updated > visu.m_updated)
	{
		fill_fleet(visu, fleet.m_ships);
		visu.m_updated = fleet.m_ships_updated;
	}

	bool hovered = player.m_hovered_item == fleet.m_spatial;
	bool selected = player.m_selected_item == fleet.m_spatial;

	Colour colour = fleet.m_commander->m_colour * 2.5f;
	if(player.m_mode == GameStage::Empire && fleet.m_commander != player.m_commander)
		colour = saturation(colour, 0.7f);
	if(hovered)
		colour = colour * 1.5f;

	//if(fleet.m_jump.m_state != Jump::Warp)
		paint_fleet_stationary(parent.subx(Fleet), fleet, visu, colour);
	if(fleet.m_jump.m_state >= Jump::Start)
		toy::sound(parent.subx(Warp), "warp", false, 0.5f);
	if(fleet.m_jump.m_state == Jump::Start || fleet.m_jump.m_state == Jump::End)
		paint_fleet_jumping(parent.subx(Jump), fleet, colour);
	//if(fleet.m_jump.m_state == Jump::Jump || fleet.m_jump.m_state == Jump::End)
	//	paint_fleet_warp(parent, visu);

	if(fleet.m_commander == player.m_commander)
		paint_fleet_orders(parent.subx(Orders), fleet, colour);

	if(player.m_mode == GameStage::Empire && fleet.m_commander == player.m_commander)
	{
		paint_range(parent.subx(ScanRange), colour, fleet.m_scan);
	}

	if((selected || hovered) && fleet.m_commander == player.m_commander)
	{
		paint_range(parent.subx(JumpRange), colour, fleet.m_speed);
		//if(fleet.m_scan > 0)
			//paint_range(parent, fleet.m_commander->m_colour * 2.f, fleet.m_scan);
		toy::sound(parent.subx(Thrusters), "thrusters", true, 0.2f);
	}
}

void paint_scan_fleet(Gnode& parent, Fleet& fleet)
{
	Player& player = val<Player>(parent.root().m_scene->m_user);
	paint_scan_fleet(parent, fleet, player);
}

static table<WeaponType, float> s_weapon_rate  = { 0.f, 2.f,   1.2f,  1.f,    0.7f,  1.f };
static table<WeaponType, float> s_weapon_speed = { 0.f, 2.f,   1.2f,  1.f,    0.7f,  1.f };
static table<WeaponType, float> s_weapon_scale = { 0.f, 0.01f, 0.01f, 0.03f,  0.05f, 0.05f };

static table<WeaponType, float> s_weapon_hue   = { 0.f, 0.55f, 1.f,   0.305f, 0.f,   0.f };
static table<WeaponType, float> s_weapon_sat   = { 0.f, 1.f,   1.f,   1.f,    0.f,   0.f };
static table<WeaponType, float> s_weapon_value = { 0.f, 0.7f,  0.6f,  0.6f,   0.8f,  0.8f };

static table<WeaponType, Colour> s_weapon_colour =
{
	Colour(),
	Colour::hsl(0.55f, 1.f, 0.7f),
	Colour::hsl(1.f, 1.f, 0.6f),
	Colour::hsl(0.305f, 1.f, 0.6f),
	Colour::hsl(0.f, 0.f, 0.8f),
	Colour::hsl(0.f, 0.f, 0.8f)
};

static table<WeaponType, Cube> s_weapon_shape =
{
	Cube(),
	Cube(vec3(vec2(0.001f), 0.004f)),
	Cube(vec3(vec2(0.001f), 0.004f)),
	Cube(vec3(vec2(0.001f), 0.004f)),
	Cube(vec3(vec2(0.001f), 0.004f)),
	Cube(vec3(vec2(0.001f), 0.004f))
};

void scale_down(Flow& particles, float factor)
{
	particles.m_scale.m_value *= factor;
	particles.m_volume.m_value *= factor;
	particles.m_speed.m_value *= factor;
}

unique<Flow> weapon_particles(Gnode& parent, cstring name, WeaponType weapon)
{
	Flow& original = *parent.m_scene->m_gfx.flows().file(name);
	unique<Flow> particles = make_unique<Flow>(original);
	particles->m_colour.m_value = s_weapon_colour[weapon];
	//particles->m_scale.m_value = s_weapon_scale[weapon];
	scale_down(*particles, 0.005f);
	return move(particles);
}

bool paint_weapon_ray(Gnode& parent, const WeaponRay& ray, WeaponType weapon)
{
	static table<WeaponType, unique<Flow>> weapon_flash = {};
	static table<WeaponType, unique<Flow>> weapon_trail = {};
	static table<WeaponType, unique<Flow>> weapon_impact = {};

	if(weapon_flash[weapon] == nullptr)
	{
		weapon_flash[weapon] = weapon_particles(parent, "flash", weapon);
		weapon_trail[weapon] = weapon_particles(parent, "impact", weapon);
		weapon_impact[weapon] = weapon_particles(parent, "impact", weapon);
	}

	Colour colour = s_weapon_colour[weapon] * 3.f;

	vec3 current = ray.m_start + ray.m_dir * ray.m_d;

	//Gnode& source = gfx::node(parent, ray.m_start, ray.m_angle);
	Gnode& projectile = gfx::node(parent, current, ray.m_angle);
	//Gnode& hit = gfx::node(parent, ray.m_end, ray.m_angle);

	//gfx::flows(out, flash);

	if(ray.m_d < ray.m_length)
	{
		gfx::shape(projectile, s_weapon_shape[weapon], Symbol::wire(colour));
		//gfx::flows(projectile, trail);
		return false;
	}
	else
	{
		//return gfx::flows(hit, *weapon_impact[weapon]).m_ended;
		return true;
	}
}

namespace two
{
	template <> Type& type<VisuShip>() { static Type ty; return ty; }
}

template <class T>
T random_element(span<T> vec)
{
	return vec[randi<size_t>(0, vec.size() - 1)];
}

void paint_combat_fleet(Gnode& parent, span<CombatFleet> flotilla, span<CombatFleet> enemies, float delta, float intensity)
{
	for(const CombatFleet& combat_fleet : flotilla)
	{
		Fleet* fleet = combat_fleet.m_fleet;
		Fleet* target_fleet = random_element(enemies).m_fleet;

		for(uint8_t i = 0; i < 8; ++i)
			for(VisuShip& ship : fleet->m_visu.m_ships[i])
			{
				Gnode& node = gfx::node(parent, fleet->m_spatial->m_position + ship.m_position);
				//node.m_node->m_object = Ref(&ship);

				if(ship.m_destroyed)
				{
					static Flow& explode = *parent.m_scene->m_gfx.flows().file("explode");
					static bool once = false;
					if(!once)
					{
						scale_down(explode, 0.1f);
						once = true;
					}
					gfx::flows(node, explode);
				}

				if(ship.m_destroyed || ship.m_weapon == WeaponType::None)
					continue;

				ship.m_cooldown -= intensity * 100.f;
				if(ship.m_cooldown < 0.f)
				{
					if(ship.m_ray.m_end == vec3(0.f))
					{
						const vec3 source = fleet->m_spatial->m_position + ship.m_position;
						const vec3 target = target_fleet->m_spatial->m_position + random_element(span<vec3>(target_fleet->m_visu.m_points.m_points));
						const quat angle = look_at(source, target);
						ship.m_ray = { source, target, normalize(target - source), length(target - source), angle, 0.f };
					}

					ship.m_ray.m_d += delta * s_weapon_speed[ship.m_weapon];

					if(paint_weapon_ray(node, ship.m_ray, ship.m_weapon))
					{
						ship.m_ray = {};
						ship.m_cooldown = 2.f / s_weapon_rate[ship.m_weapon];
					}
				}
			}
	}
}

void paint_combat(Gnode& parent, SpatialCombat& combat)
{
	toy::sound(parent, "hornwar", false, 0.3f);

	if(combat.m_state == SpatialCombat::APPROACH)
	{
		//for(CombatFleet& combat_fleet : combat.m_attack)
		//	combat_fleet.m_fleet->m_spatial.m_position = combat_fleet.m_fleet->base_position() - offset;
		//for(CombatFleet& combat_fleet : combat.m_defense)
		//	combat_fleet.m_fleet->m_spatial.m_position = combat_fleet.m_fleet->base_position() + offset;

		combat.m_state = SpatialCombat::ENGAGE;
	}

	static Clock clock;
	float delta = float(clock.step());

	const float length = 20.f;

	float dt = delta / length;

	combat.m_t += dt;
	combat.m_t = min(1.f, combat.m_t);

	float s = sin(combat.m_t * c_pi);
	combat.m_t_position = s;

	combat.m_dt_intensity = s * 2.f * dt;
	combat.m_t_damage += combat.m_dt_intensity;
	combat.m_t_damage = min(1.f, combat.m_t_damage);

	auto destroy_ships = [&](Fleet& fleet, uint32_t* hull_losses)
	{
		for(uint8_t t = 0; t < 8; ++t)
		{
			size_t last = uint32_t(float(hull_losses[t]) * combat.m_t_damage);
			for(size_t i = 0; i < last; ++i)
				fleet.m_visu.m_ships[t][i].m_destroyed = true;
		}
	};

	vec3 center = to_xz(vec2(combat.m_coord)) + 0.5f + y3;;

	for(CombatFleet& fleet : combat.m_attack)
		destroy_ships(*fleet.m_fleet, fleet.m_hull_losses);
	for(CombatFleet& fleet : combat.m_defense)
		destroy_ships(*fleet.m_fleet, fleet.m_hull_losses);

	for(CombatFleet& fleet : combat.m_attack)
		fleet.m_fleet->m_spatial->m_position = lerp(fleet.m_fleet->m_slot, center, combat.m_t_position);
	for(CombatFleet& fleet : combat.m_defense)
		fleet.m_fleet->m_spatial->m_position = lerp(fleet.m_fleet->m_slot, center, combat.m_t_position);

	paint_combat_fleet(parent, combat.m_attack, combat.m_defense, delta, combat.m_dt_intensity);
	paint_combat_fleet(parent, combat.m_defense, combat.m_attack, delta, combat.m_dt_intensity);
}

void galaxy_grid(Gnode& parent, Galaxy& galaxy)
{
	Colour colour = Colour::White * 3.f;
	Gnode& self = gfx::node(parent, y3 * 0.5f);
	gfx::shape(self, Grid2(vec2(galaxy.m_size)), Symbol::wire(colour));
}

void highlighted_sector(Gnode& parent, const vec2& coord)
{
	Gnode& self = gfx::node(parent, vec3(coord.x, 0.f, coord.y) + 0.5f);
	gfx::shape(self, Quad(1.f, x3, z3), Symbol::wire(Colour::White));
}

void paint_galaxy(Gnode& parent, Galaxy& galaxy)
{
	UNUSED(parent); UNUSED(galaxy);
}

void paint_scene(Gnode& parent)
{
	Light& light = gfx::direct_light_node(parent);
	light.m_shadows = false;

	gfx::radiance(parent, "equirectangular_space_sampler.jpg", BackgroundMode::None);
	//gfx::custom_sky(parent, "start_nest");

	toy::sound(parent, "deep", true, 0.4f);

	static float crackle = 170.f;
	static float grtgrtttt = 55.f;
	static float grzzt = 0.f;

	static Clock clock;
	float step = float(clock.step());

	auto update_sound = [&](float& counter, cstring name, float period, float volume)
	{
		counter += step;
		if(counter > period)
		{
			toy::sound(parent, name, false, volume);
			counter = 0.f;
		}
	};

	//update_sound(crackle, "crackle", 180.f, 0.3f);
	//update_sound(grtgrtttt, "grtgrtttt", 60.f, 0.1f);
	update_sound(grzzt, "grzzt", 10.f, 0.02f);
}

void paint_viewer(Viewer& viewer)
{
	viewer.m_camera.m_near = 0.0001f;

	viewer.m_viewport.comp<Glow>().m_enabled = true;
	viewer.m_viewport.comp<Glow>().m_levels_1_4 = { 1.f, 1.f, 0.f, 0.f };
#ifndef TWO_PLATFORM_EMSCRIPTEN
	viewer.m_viewport.comp<Glow>().m_bicubic_filter = true;
#endif
}