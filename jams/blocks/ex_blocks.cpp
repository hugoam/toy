#include <blocks/ex_blocks.h>
#include <toy/toy.h>

#include <blocks/Api.h>
#include <meta/blocks/Module.h>

#include <shell/Shell.h>

//#define _BLOCKS_TOOLS

using namespace mud;
using namespace toy;

Material& highlight_material(const std::string& name, const Colour& colour, int factor)
{
	Material& material = Material::ms_gfx_system->fetch_material(name.c_str(), "pbr/pbr");
	material.m_pbr_block.m_enabled = true;
	material.m_pbr_block.m_emissive.m_value = colour;
	material.m_pbr_block.m_emissive.m_value.m_a = float(factor);
	return material;
}

Faction::Faction(uint32_t id, const Colour& colour)
	: m_id(index(type<Faction>(), id, Ref(this)))
	, m_colour(colour)
{
	auto highlight_material = [=](int factor) -> Material&
	{
		return ::highlight_material("faction_" + to_string(m_id)  + "_highlight_" + to_string(factor), colour, factor);
	};

	m_highlight2 = &highlight_material(2);
	m_highlight11 = &highlight_material(11);
}

Faction::~Faction()
{
	unindex(type<Faction>(), m_id);
}

std::vector<Faction> g_factions;

Entity Well::create(ECS& ecs, HSpatial parent, const vec3& position)
{
	Entity entity = { ecs.CreateEntity<Spatial, Emitter, Well>(), ecs.m_index };
	ecs.SetComponent(entity, Spatial(parent, position, ZeroQuat));
	ecs.SetComponent(entity, Emitter(HSpatial(entity)));
	return entity;
}

Well::Well(HSpatial spatial, HEmitter emitter)
	: m_spatial(spatial)
	, m_emitter(emitter)
{}

void Well::next_frame(size_t tick, size_t delta)
{
	UNUSED(tick); UNUSED(delta);
}

Entity Camp::create(ECS& ecs, HSpatial parent, const vec3& position, Faction& faction)
{
	Entity entity = { ecs.CreateEntity<Spatial, Camp>(), ecs.m_index };
	ecs.SetComponent(entity, Spatial(parent, position, ZeroQuat));
	ecs.SetComponent(entity, Camp(HSpatial(entity), position, faction));
	return entity;
}

Camp::Camp(HSpatial spatial, const vec3& position, Faction& faction)
	: m_spatial(spatial)
	, m_faction(&faction)
	, m_position(position)
{}

Entity Shield::create(ECS& ecs, HSpatial parent, const vec3& position, Faction& faction, float radius)
{
	Entity entity = { ecs.CreateEntity<Spatial, Emitter, Shield>(), ecs.m_index };
	ecs.SetComponent(entity, Spatial(parent, position, ZeroQuat));
	ecs.SetComponent(entity, Emitter(HSpatial(entity)));
	ecs.SetComponent(entity, Shield(HSpatial(entity), HEmitter(entity), faction, radius));
	return entity;
}

Shield::Shield(HSpatial spatial, HEmitter emitter, Faction& faction, float radius)
	: m_spatial(spatial)
	, m_emitter(emitter)
	, m_faction(&faction)
	, m_radius(radius)
	, m_charge(1.f)
	, m_discharge(0.f)
	, m_collider(Collider::create(m_spatial, HMovable(), Sphere(radius), SolidMedium::me, CollisionGroup(CM_ENERGY)))
{}

void Shield::next_frame(size_t tick, size_t delta)
{
	UNUSED(tick); UNUSED(delta);
	if(m_discharge > 0.f)
	{
		m_charge = max(0.f, m_charge - m_discharge);
		m_discharge = max(0.f, m_discharge - min(0.1f, m_discharge));
	}

	m_charge = min(1.f, m_charge + 0.01f);
}

Entity Slug::create(ECS& ecs, HSpatial parent, const vec3& source, const quat& rotation, const vec3& velocity, float power)
{
	Entity entity = { ecs.CreateEntity<Spatial, Slug>(), ecs.m_index };
	ecs.SetComponent(entity, Spatial(parent, source, rotation));
	ecs.SetComponent(entity, Slug(HSpatial(entity), source, velocity, power));
	return entity;
}

Slug::Slug(HSpatial spatial, const vec3& source, const vec3& velocity, float power)
	: m_spatial(spatial)
	, m_source(source)
	, m_velocity(velocity)
	, m_power(power)
	//, m_solid(Solid::create(m_spatial, HMovable(), Sphere(0.1f), SolidMedium::me, CollisionGroup(CM_ENERGY), false, 1.f))
	, m_collider(Collider::create(m_spatial, HMovable(), Sphere(0.1f), SolidMedium::me, CollisionGroup(CM_ENERGY)))
{}

void Slug::update(Spatial& spatial)
{
	if(m_impacted)
		return;

	short int mask = CM_SOLID | CM_GROUND | CM_ENERGY;

	//Collision collision = (*m_solid)->raycast(m_spatial.m_position + m_velocity, mask);
	Collision collision = (*m_collider)->raycast(spatial.m_position + m_velocity, mask);
	HSpatial hit = collision.m_second ? collision.m_second->m_spatial : HSpatial();

	if(hit)
	{
		if(Tank* tank = try_asa<Tank>(hit))
		{
			m_impacted = true;
			m_impact = collision.m_hit_point;

			tank->m_shock += 1.f;
			tank->m_hitpoints -= 25.f;

			vec3 location = Zero3;//rotate(inverse(m_spatial.m_rotation), m_impact - m_spatial.m_position);

			Solid& solid = (*tank->m_solid);
			if(tank->m_hitpoints < 0.f)
				solid->impulse(Y3 * 100.f * m_power, location);
			else
				solid->impulse((m_velocity + Y3 * 10.f) * m_power, location);
		}

		if(Shield* shield = try_asa<Shield>(hit))
		{
			auto reflect = [](const vec3& I, const vec3& N) { return I - 2.f * dot(N, I) * N; };

			vec3 N = normalize(collision.m_hit_point - shield->m_spatial->m_position);
			m_velocity = reflect(m_velocity, N);

			shield->m_discharge += 1.0f;
		}
	}

	if(distance(spatial.m_position, Zero3) > 1000.f)
		m_destroy = true;

	spatial.set_position(spatial.m_position + m_velocity);
	//m_collider.update_transform();
}

Entity Tank::create(ECS& ecs, HSpatial parent, const vec3& position, Faction& faction)
{
	Entity entity = { ecs.CreateEntity<Spatial, Movable, Emitter, Receptor, Tank>(), ecs.m_index };
	ecs.SetComponent(entity, Spatial(parent, position, ZeroQuat));
	ecs.SetComponent(entity, Movable(HSpatial(entity)));
	ecs.SetComponent(entity, Emitter(HSpatial(entity)));
	ecs.SetComponent(entity, Receptor(HSpatial(entity)));
	ecs.SetComponent(entity, Tank(HSpatial(entity), HMovable(entity), HEmitter(entity), HReceptor(entity), faction));
	return entity;
}

Tank::Tank(HSpatial spatial, HMovable movable, HEmitter emitter, HReceptor receptor, Faction& faction)
	: m_spatial(spatial)
	, m_movable(movable)
	, m_emitter(emitter)
	, m_receptor(receptor)
	, m_faction(&faction)
	, m_solid(Solid::create(m_spatial, m_movable, CollisionShape(Cube(vec3(2.0f, 1.1f, 3.2f)), Y3 * 1.1f), false, 4.f))
{
	m_emitter->add_sphere(VisualMedium::me, 0.1f);
	m_receptor->add_sphere(VisualMedium::me, 100.f);
	
	m_shock = 1.f;
}

void Tank::next_frame(Spatial& spatial, Movable& movable, Receptor& receptor, size_t tick, size_t delta)
{
	UNUSED(tick);

	m_shock = max(0.f, m_shock - 0.01f * float(delta));
	bool control = m_shock == 0.f;

	m_energy = min(100.f, m_energy + delta * .1f);

	for(auto& slug : reverse_adapt(m_slugs))
	{
		slug->update(slug->m_spatial);
		//if(slug->m_destroy)
		//	vector_remove(m_slugs, *slug);
	}

	if(!m_ia)
		return;

	if(control && m_hitpoints > 0.f)
	{
		m_target = nullptr;

		ReceptorScope* vision = receptor.scope(VisualMedium::me);
		for(HSpatial seen : vision->m_scope)
			if(Tank* tank = try_asa<Tank>(seen))
				if(&tank->m_faction != &m_faction && !tank->m_stealth)
				{
					m_target = tank;
				}

		m_cooldown = max(0.f, m_cooldown - float(delta) * 0.01f);
		if(m_target)
		{
			m_turret_angle = look_at(spatial.m_position, m_target->m_spatial->m_position, -Z3);

			float d = distance(m_target->m_spatial->m_position, spatial.m_position);
			if(d > m_range)
			{
				m_dest = m_target->m_spatial->m_position;
			}
			else if(m_cooldown == 0.f)
			{
				this->shoot();
				m_dest = Zero3;
				m_cooldown = 1.f;
			}
		}

		HTank leader = m_faction->m_leader;
		if(leader && !m_target && distance(leader->m_spatial->m_position, spatial.m_position) > 50.f)
			m_dest = leader->m_spatial->m_position;
		
		if(m_dest != Zero3)
		{
			if(!steer_2d(spatial, movable, m_dest, 15.f, float(delta) * float(c_tick_interval), m_range))
				movable.set_linear_velocity(movable.m_linear_velocity - Y3 * 1.f);
			else
				m_dest = Zero3;
		}
	}
	else
	{
		//m_movable.set_linear_velocity(-Y3 * 1.f);
		m_dest = Zero3;
	}
}

void Tank::shoot(bool critical)
{
	static const vec3 tank_muzzle = { 0.f, 1.75f, -3.7f };

	if(m_energy < 10.f)
		return;

	m_energy -= 10.f;

	vec3 velocity = this->turret_direction() * 5.f;
	quat rotation = this->turret_rotation();

	Spatial& spatial = m_spatial;
	m_slugs.emplace_back(construct_owned<Slug>(m_spatial, spatial.m_position + rotate(rotation, tank_muzzle), rotation, velocity, critical ? 10.f : 1.f));
}

BlockWorld::BlockWorld(const std::string& name, JobSystem& job_system)
	: Complex(0, type<BlockWorld>(), m_bullet_world, m_navmesh, *this)
	, m_world(0, *this, name, job_system)
	, m_bullet_world(m_world)
	, m_navmesh(m_world)
	//, m_block_subdiv(64, 1, 64)
	, m_block_subdiv(32, 1, 32)
	, m_tile_scale(10.f, 4.f, 10.f)
	, m_block_size(vec3(m_block_subdiv) * m_tile_scale)
	, m_world_size(m_block_size)
{
	m_world.m_pump.add_step({ Task::PhysicsWorld,
		[&](size_t tick, size_t delta) { m_bullet_world.next_frame(tick, delta); }
	});
}

BlockWorld::~BlockWorld()
{}

void BlockWorld::generate_block(GfxSystem& gfx_system, const ivec2& coord)
{
	static WaveTileset& tileset = generator_tileset(gfx_system);

	Tileblock& block = ::generate_block(gfx_system, tileset, m_world.origin(), coord, m_block_subdiv, m_tile_scale, false);

	block.m_world_page->m_geometry_filter = { "flat_low", "flat_high", "cliff_side_0_0", "cliff_corner_in_0_0", "cliff_corner_out_0_0" };

	m_blocks[coord] = &block;
	if(m_center_block == nullptr)
		m_center_block = &block;

	block.m_wfc_block.m_auto_solve = true;
}

Player::Player(BlockWorld& world)
	: m_world(&world)
	, m_tank(Tank::create(world.m_world.m_ecs, world.m_world.origin(), Y3 * 20.f, g_factions[0]))
{
	m_tank->m_faction->m_leader = m_tank;
	m_tank->m_ia = false;
}

void paint_well(Gnode& parent, Well& well)
{
	UNUSED(parent); UNUSED(well);
}

Model& faction_fresnel_material(GfxSystem& gfx_system, Model& model)
{
	static Material& material = highlight_material("no_highlight", Colour::Black, 0);

	std::string name = model.m_name + "_dead";
	return model_variant(gfx_system, model, name.c_str(), carray<cstring, 2>{ "Highlight11", "Highlight2" }, 
														  carray<Material*, 2>{ &material, &material });
}

void paint_shield(Gnode& parent, Shield& shield)
{
	static Material* discharge = &parent.m_scene->m_gfx_system.fetch_material("shield_discharge", "fresnel");

	static std::vector<Material*> power = std::vector<Material*>(4);

	Faction& faction = *shield.m_faction;

	auto fresnel_material = [&](Material& material, const Colour& colour)
	{
		material.m_fresnel_block.m_enabled = true;
		material.m_fresnel_block.m_value.m_value = colour;
		material.m_fresnel_block.m_value.m_texture = parent.m_scene->m_gfx_system.textures().file("beehive.png");
	};

	if(power[faction.m_id] == nullptr)
	{
		Material* material = &parent.m_scene->m_gfx_system.fetch_material(("shield_faction_" + to_string(faction.m_id)).c_str(), "fresnel");
		fresnel_material(*material, faction.m_colour * 4.f);
		power[faction.m_id] = material;
	}

	static Clock clock;

	float period = remap_trig(sin(float(clock.read()) * 2.f), 0.f, 0.05f);

	auto paint = [&](Material& material, float bias, const Colour& colour)
	{
		fresnel_material(material, colour);
		material.m_fresnel_block.m_fresnel_bias = bias;
		gfx::shape(parent, Sphere(shield.m_radius), Symbol(colour), 0U, &material);
	};

	if(shield.m_discharge > 0.f)
	{
		paint(*discharge, shield.m_discharge, Colour::hsl(random_scalar(0.f, 1.f), 1.f, 0.5f) * shield.m_discharge * 10.f);
	}
	else
	{
		paint(*power[faction.m_id], period, faction.m_colour * 4.f * shield.m_charge);
	}

	if(shield.m_discharge > 0.f)
		toy::sound(parent, "bzwomb", false, 0.5f);
}

void paint_shell(Gnode& parent, Slug& shell)
{
	static ParticleGenerator* flash = parent.m_scene->m_gfx_system.particles().file("flash");
	static ParticleGenerator* trail = parent.m_scene->m_gfx_system.particles().file("trail");
	static ParticleGenerator* impact = parent.m_scene->m_gfx_system.particles().file("impact");

	Gnode& source = gfx::node(parent, Ref(&shell), shell.m_source, shell.m_spatial->m_rotation);
	gfx::particles(source, *flash);

	bool active = toy::sound(source, "bang", false, 0.5f);

	enum States { Fly = 1, Impact = 2 };
	if(!shell.m_impacted)
	{
		Gnode& projectile = gfx::node(parent.subx(Fly), Ref(&shell), shell.m_spatial->m_position, shell.m_spatial->m_rotation);
		gfx::shape(projectile, Cube(vec3(0.4f, 0.4f, 1.f)), Symbol(Colour(1.f, 2.f, 1.5f)));
		gfx::particles(projectile, *trail);
	}

	if(shell.m_impacted)
	{
		Gnode& hit = gfx::node(parent.subx(Impact), Ref(&shell), shell.m_impact, shell.m_spatial->m_rotation);
		active |= !gfx::particles(hit, *impact).m_ended;
		active |= toy::sound(hit, "impact", false, 0.2f);
		//active |= toy::sound(hit, "explode", false, 0.2f);
	}

	shell.m_destroy |= !active;
}

Model& faction_model_dead_variant(GfxSystem& gfx_system, Model& model)
{
	static Material& material = highlight_material("no_highlight", Colour::Black, 0);

	std::string name = model.m_name + "_dead";
	return model_variant(gfx_system, model, name.c_str(), carray<cstring, 2>{ "Highlight11", "Highlight2" }, 
														  carray<Material*, 2>{ &material, &material });
}

Model& faction_model_variant(GfxSystem& gfx_system, Faction& faction, Model& model)
{
	std::string name = model.m_name + "_faction" + to_string(faction.m_id);
	return model_variant(gfx_system, model, name.c_str(), carray<cstring, 2>{ "Highlight11", "Highlight2" }, 
														  carray<Material*, 2>{ faction.m_highlight11, faction.m_highlight2 });
}

void hud_bar(Gnode& parent, const vec3& position, const vec2& offset, float percentage, Colour colour)
{
	static const vec2 size = { 4.f, 0.2f };
	vec2 fill_offset = { size.x * -(1.f - percentage) / 2.f, 0.f };
	gfx::shape(parent, Quad(position, offset, vec2(4.f, 0.2f)), Symbol(Colour::White, Colour::None, true), ItemFlag::Render | ItemFlag::Billboard);
	gfx::shape(parent, Quad(position, offset + fill_offset, vec2(4.f * percentage, 0.2f)), Symbol(colour, true, true), ItemFlag::Render | ItemFlag::Billboard);
}

void paint_tank(Gnode& parent, Tank& tank)
{
	static Material* debug = &parent.m_scene->m_gfx_system.debug_material();
	static Material* stealth = &parent.m_scene->m_gfx_system.fetch_material("tank_stealth", "fresnel");
	{
		stealth->m_fresnel_block.m_enabled = true;
		stealth->m_fresnel_block.m_value.m_value = { 0.8f, 0.9f, 5.f };
		//stealth->m_fresnel_block.m_value.m_texture = parent.m_scene->m_gfx_system.textures().file("beehive.png");
	}

	GfxSystem& gfx_system = parent.m_scene->m_gfx_system;

	static std::vector<Model*> tank_base_models = std::vector<Model*>(size_t(Faction::s_max_factions));
	static std::vector<Model*> tank_turret_models = std::vector<Model*>(size_t(Faction::s_max_factions));

	static Model& tank_base_dead = faction_model_dead_variant(gfx_system, *gfx_system.models().file("scifi_tank_base"));
	static Model& tank_turret_dead = faction_model_dead_variant(gfx_system, *gfx_system.models().file("scifi_tank_turret"));

	Faction& faction = *tank.m_faction;

	if(tank_base_models[faction.m_id] == nullptr)
	{
		tank_base_models[faction.m_id] = &faction_model_variant(gfx_system, faction, *gfx_system.models().file("scifi_tank_base"));
		tank_turret_models[faction.m_id] = &faction_model_variant(gfx_system, faction, *gfx_system.models().file("scifi_tank_turret"));
	}

	Gnode& turret = gfx::node(parent, {}, parent.m_attach->position(), tank.turret_rotation());

	if(tank.m_hitpoints > 0.f)
	{
		if(tank.m_stealth)
		{
			gfx::item(parent, tank_base_dead, 0U, stealth);
			gfx::item(turret, tank_turret_dead, 0U, stealth);
		}
		else
		{
			gfx::item(parent, *tank_base_models[faction.m_id]);
			gfx::item(turret, *tank_turret_models[faction.m_id]);
		}
	}
	else
	{
		gfx::item(parent, tank_base_dead);
		gfx::item(turret, tank_turret_dead);
	}

	enum States { Alive = 2, Dead = 3 };

	if(tank.m_hitpoints > 0.f)
	{
		if(false)
		{
			Gnode& alive = parent.subx(Alive);
			Gnode& symbol = gfx::node(alive, {}, parent.m_attach->m_transform);
			gfx::shape(symbol, Torus(4.f, 0.1f), Symbol(faction.m_colour * 2.f));

			if(false)
			{
				static const Colour energy = { 0.f, 0.6f, 1.f };
				static const Colour life = { 0.f, 1.f, 0.2f };

				hud_bar(alive, Zero3, vec2(0.f), max(0.f, tank.m_hitpoints * 0.01f), life);
				hud_bar(alive, Zero3, vec2(0.f, -0.4f), max(0.f, tank.m_energy * 0.01f), energy);
			}
		}
	}
	else
	{
		Gnode& dead = parent.subx(Dead);
		static ParticleGenerator* explode = parent.m_scene->m_gfx_system.particles().file("explode");

		gfx::particles(dead, *explode);
		//toy::sound(dead, "explosion", false, 0.2f);
		toy::sound(dead, "explode", false, 0.2f);
	}
}

void paint_block_wire(Gnode& parent, Block& block)
{
	paint_block_wireframe(parent, block, Colour(1.f, 2.f, 1.5f));
}

void paint_block(Gnode& parent, Tileblock& block)
{
	if(block.m_wfc_block.m_wave.m_solved)
		paint_tiles(parent, ent_ref(block.m_spatial.m_handle), block.m_wfc_block);
}

void paint_scene(Gnode& parent, bool radiance)
{
	Light& light = gfx::direct_light_node(parent);
	light.m_shadow_range = 500.f;
	light.m_shadow_num_splits = 4;

	gfx::radiance(parent, "radiance/tiber_1_1k.hdr", radiance ? BackgroundMode::Radiance
															  : BackgroundMode::None);
}

void paint_viewer(Viewer& viewer)
{
	viewer.m_camera.m_far = 500.f;

	viewer.m_filters.m_glow.m_enabled = true;
	viewer.m_filters.m_glow.m_levels_1_4 = { 1.f, 1.f, 0.f, 0.f };
	viewer.m_filters.m_glow.m_intensity = 0.8f;
#ifndef MUD_PLATFORM_EMSCRIPTEN
	viewer.m_filters.m_glow.m_bicubic_filter = true;
#endif
}

struct KeyMove
{
	Key key;
	vec3 force;
	vec3 torque;
};

void tank_control_key(Widget& widget, vec3& force, vec3& torque, const KeyMove& move)
{
	if(widget.key_event(move.key, EventType::Pressed))
	{
		force += move.force;
		torque += move.torque * 2.f;
	}
	if(widget.key_event(move.key, EventType::Released))
	{
		force -= move.force;
		torque -= move.torque * 2.f;
	}
}

static void tank_velocity_controller(Widget& widget, Tank& tank)
{
	//bool shift = widget.ui().m_keyboard.m_shift;

	const KeyMove moves[8] =
	{
		{ Key::Up,    -Z3, Zero3 }, { Key::W,  -Z3, Zero3 },
		{ Key::Down,   Z3, Zero3 }, { Key::S,   Z3, Zero3 },
		{ Key::Left,  Zero3,  Y3 }, { Key::A,  Zero3,  Y3 },
		{ Key::Right, Zero3, -Y3 }, { Key::D,  Zero3, -Y3 },
	};

	for(const KeyMove& key_move : moves)
		tank_control_key(widget, tank.m_force, tank.m_torque, key_move);
}

Style& screen_style()
{
	static Style style = { "GameScreen", styles().wedge, [](Layout& l) { l.m_space = LAYOUT; l.m_padding = vec4(30.f); } };
	return style;
}

Style& right_panel_style(UiWindow& ui_window)
{
	//static ImageSkin skin = { *ui_window.find_image("graphic/red_on"), 46, 28, 38, 30 };
	
	static Style style = { "GamePanel", styles().wedge, [](Layout& l) { l.m_space = UNIT; l.m_align = { Right, CENTER }; l.m_padding = vec4(30.f); l.m_spacing = vec2(30.f); } };
													    //[](InkStyle& s) { s.m_empty = false; s.m_image_skin = skin; } };
	return style;
}

Style& center_panel_style(UiWindow& ui_window)
{
	//static ImageSkin skin = { *ui_window.find_image("graphic/red_on"), 46, 28, 38, 30 };
	
	static Style style = { "GamePanel", styles().wedge, [](Layout& l) { l.m_space = UNIT; l.m_align = { CENTER, CENTER }; l.m_padding = vec4(30.f); l.m_spacing = vec2(30.f); } };
													    //[](InkStyle& s) { s.m_empty = false; s.m_image_skin = skin; } };
	return style;
}

Style& left_panel_style(UiWindow& ui_window)
{
	//static ImageSkin skin = { *ui_window.find_image("graphic/red_on"), 46, 28, 38, 30 };
	
	static Style style = { "GamePanel", styles().wedge, [](Layout& l) { l.m_space = UNIT; l.m_align = { Left, CENTER }; l.m_padding = vec4(30.f); l.m_spacing = vec2(30.f); } };
													    //[](InkStyle& s) { s.m_empty = false; s.m_image_skin = skin; } };
	return style;
}

Style& menu_style()
{
	static Style style = { "GameMenu", styles().wedge, [](Layout& l) { l.m_space = UNIT; l.m_align = { Left, CENTER }; l.m_padding = vec4(120.f); l.m_padding.x = 240.f; l.m_spacing = vec2(30.f); } };
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

Style& label_style()
{
	static Style style = { "GameLabel", styles().button, [](Layout& l) { UNUSED(l); },
														 [](InkStyle& s) { s.m_empty = false; s.m_text_colour = Colour::White; s.m_text_size = 14.f;  } };
	return style;
}

void ex_blocks_game_ui(Widget& parent, GameScene& scene)
{
	Player& player = val<Player>(scene.m_player);

	Widget& self = ui::widget(parent, styles().board, &scene);

	Viewer& viewer = ui::viewer(self, scene.m_scene);
	//viewer.m_viewport.m_lighting = lighting(Lighting::VoxelGI);

	Tank& tank = player.m_tank;
	Spatial& spatial = tank.m_spatial;

	OrbitController& orbit = ui::orbit_controller(viewer, 0.f, -c_pi / 4.f, 200.f);
	orbit.set_target(spatial.m_position);

#ifdef TOY_SOUND
	scene.m_snd_manager.m_listener.setTransform(viewer.m_camera.m_eye, look_at(viewer.m_camera.m_eye, viewer.m_camera.m_target));
#endif

	Ray ray = viewer.mouse_ray();
	vec3 target = plane_segment_intersection(Plane(Y3, spatial.m_position.y), to_segment(ray));

	tank.m_turret_angle = look_at(spatial.m_position, target);

	tank_velocity_controller(viewer, player.m_tank);

	if(KeyEvent key_event = viewer.key_stroke(Key::LeftControl))
		tank.m_stealth = !tank.m_stealth;

	if(MouseEvent mouse_event = viewer.mouse_event(DeviceType::MouseLeft, EventType::Stroked, InputMod::Any))
	{
		viewer.take_focus();
		tank.shoot(viewer.ui().m_keyboard.m_shift);
	}

	static vec3 destination = Zero3;

	if(MouseEvent mouse_event = viewer.mouse_event(DeviceType::MouseRight, EventType::Stroked))
	{
		viewer.take_focus();

		Ray pick_ray = viewer.m_viewport.ray(mouse_event.m_relative);
		destination = player.m_world->m_bullet_world.ground_point(pick_ray);
	}

	if(destination != Zero3)
	{
		static Clock clock;
		if(steer_2d(spatial, tank.m_movable, destination, 15.f, float(clock.step()), 0.1f))
			destination = Zero3;
	}

	paint_viewer(viewer);

	static Style& style_screen = screen_style();
	static Style& style_right_panel = right_panel_style(parent.ui_window());
	static Style& style_center_panel = center_panel_style(parent.ui_window());
	static Style& style_left_panel = left_panel_style(parent.ui_window());
	static Style& style_label = label_style();

	Widget& screen = ui::widget(viewer, style_screen);
	Widget& board = ui::board(screen); UNUSED(board);
	Widget& row = ui::row(screen);
	Widget& left_panel = ui::widget(row, style_left_panel);
	Widget& center_panel = ui::widget(row, style_center_panel);

	ui::item(left_panel, style_label, "Destroy All Enemy Shields");

	ui::icon(center_panel, "(World)");
}

Viewer& ex_blocks_menu_viewport(Widget& parent, GameShell& app)
{
	Viewer& viewer = ui::scene_viewer(parent);
	Gnode& scene = viewer.m_scene->begin();

#ifdef TOY_SOUND
	scene.m_sound_manager = app.m_sound_system.get();
#endif

	paint_viewer(viewer);
	paint_scene(scene, false);

	static Clock clock;

	viewer.m_camera.m_target = vec3(5.f, 0.f, -2.5f);
	viewer.m_camera.m_eye = viewer.m_camera.m_target + vec3(-1.5f, 1.0f, -0.5f) * (10.f + sinf(float(clock.read()) * 0.1f));

	static DefaultWorld world = { "", *app.m_job_system };
	static EntityHandle<Origin> root = { Origin::create(world.m_world.m_ecs, world.m_world), 0 };

	static EntityHandle<Tank> tank0 = construct_owned<Tank>(root->m_spatial, Zero3, g_factions[0]);
	static EntityHandle<Tank> tank1 = construct_owned<Tank>(root->m_spatial, X3 * 10.f, g_factions[1]);
	static EntityHandle<Tank> tank2 = construct_owned<Tank>(root->m_spatial, Z3 * 10.f, g_factions[2]);

	static bool once = false;
	if(!once)
	{
		tank0->m_spatial->rotate(Y3, c_pi * 0.25f);
		tank1->m_spatial->rotate(Y3, c_pi * 0.25f);
		tank2->m_spatial->rotate(Y3, c_pi * 0.25f);
		once = true;
	}

	auto paint = [&](Tank& tank) { Gnode& node = gfx::node(scene, {}, tank.m_spatial->m_position, tank.m_spatial->m_rotation); paint_tank(node, tank); };
	paint(tank0);
	paint(tank1);
	paint(tank2);

	return viewer;
}

void ex_blocks_menu(Widget& parent, Game& game)
{
	static Style& style_button = button_style(parent.ui_window());
	static Style& style_menu = menu_style();

	Widget& self = ui::board(parent);

	Viewer& viewer = ex_blocks_menu_viewport(self, *game.m_shell);
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

void ex_blocks_pump_game(GameShell& app, Game& game, Widget& parent)
{
	UNUSED(game);
	static GameScene& scene = app.add_scene();
	ex_blocks_game_ui(parent, scene);
}

class ExBlocksModule : public GameModule
{
public:
	ExBlocksModule(Module& module) : GameModule(module) {}

	virtual void init(GameShell& app, Game& game) final
	{
		UNUSED(game);
		app.m_gfx_system->add_resource_path("examples/ex_blocks/");

		g_factions.emplace_back(0, Colour::Red);
		g_factions.emplace_back(0, Colour::Pink);
		g_factions.emplace_back(0, Colour::Cyan);
	}

	virtual void start(GameShell& app, Game& game) final
	{
		SolidMedium::me.m_masks[CollisionGroup(CM_ENERGY)] = CM_SOLID | CM_GROUND | CM_ENERGY;

		BlockWorld& block_world = global_pool<BlockWorld>().construct("Arcadia", *app.m_job_system);
		World& world = block_world.m_world;
		game.m_world = &world;

		world.m_ecs.AddBuffers<Spatial, WorldPage, Navblock, Sector>("Sector");
		world.m_ecs.AddBuffers<Spatial, WorldPage, Navblock, Tileblock>("Tileblock");

		world.m_ecs.AddBuffers<Spatial, Emitter, Well>("Well");
		world.m_ecs.AddBuffers<Spatial, Camp>("Camp");
		world.m_ecs.AddBuffers<Spatial, Emitter, Shield>("Shield");
		world.m_ecs.AddBuffers<Spatial, Slug>("Slug");
		world.m_ecs.AddBuffers<Spatial, Movable, Emitter, Receptor, Tank>("Tank");

		world.add_loop<Tileblock, WorldPage>(Task::Spatial);
		world.add_loop<Shield>(Task::GameObject);
		world.add_loop<Tank, Spatial, Movable, Receptor>(Task::GameObject);

		static Player player = { block_world };
		game.m_player = Ref(&player);

		block_world.generate_block(*app.m_gfx_system, ivec2(0));
		generate_camps(block_world);
	}

	virtual void scene(GameShell& app, GameScene& scene) final
	{
		UNUSED(app);
		scene.painter("World", [&](size_t index, VisuScene& scene, Gnode& parent) {
			UNUSED(scene); paint_scene(parent.subi((void*)index), true);
		});

		World& world = *scene.m_game.m_world;
		scene.entity_painter<Shield>("Shields", world, paint_shield);
		scene.entity_painter<Well>("Well", world, paint_well);
		scene.entity_painter<Tank>("Tanks", world, paint_tank);
		scene.entity_painter<Slug>("Slugs", world, paint_shell);
		scene.entity_painter<Tileblock>("Tileblocks", world, paint_block);
		scene_painters(scene, world);

		static PhysicDebugDraw physic_draw = { *scene.m_scene.m_immediate };

		scene.painter("PhysicsDebug", [&](size_t index, VisuScene& visu_scene, Gnode& parent) {
			UNUSED(index); UNUSED(visu_scene); UNUSED(parent);
			//physic_draw.draw_physics(parent, *scene.m_game.m_world, SolidMedium::me);
		});
	}

	virtual void pump(GameShell& app, Game& game, Widget& ui) final
	{
		auto pump = [&](Widget& parent, Dockbar* dockbar = nullptr)
		{
			UNUSED(dockbar);
			if(!game.m_player)
				ex_blocks_menu(parent, game);
			else
				ex_blocks_pump_game(app, game, parent);
		};

#ifdef _BLOCKS_TOOLS
		edit_context(ui, app.m_editor, true);
		pump(*app.m_editor.m_screen, app.m_editor.m_dockbar);
#else
		pump(ui);
#endif
	}
};

#ifdef _EX_BLOCKS_EXE
int main(int argc, char *argv[])
{
	cstring example_path = TOY_RESOURCE_PATH "examples/ex_blocks/";
	GameShell app(carray<cstring, 2>{ TOY_RESOURCE_PATH, example_path }, argc, argv);
	
	ExBlocksModule module = { _blocks::m() };
	app.run_game(module);
}
#endif
