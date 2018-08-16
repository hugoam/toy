#include <blocks/ex_blocks.h>
#include <05_character/05_character.h>
#include <toy/toy.h>

#include <blocks/Api.h>
#include <meta/blocks/Module.h>
#include <meta/05_character/Module.h>

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

Well::Well(Id id, Entity& parent, const vec3& position)
	: Complex(id, type<Tank>(), m_emitter, *this)
	, m_entity(id, *this, parent, position, ZeroQuat)
	, m_emitter(m_entity)
{
	m_entity.m_world.add_task(this, short(Task::State)); // TASK_GAMEOBJECT
}

Well::~Well()
{
	m_entity.m_world.remove_task(this, short(Task::State));
}

void Well::next_frame(size_t tick, size_t delta)
{
	UNUSED(tick); UNUSED(delta);
}

Camp::Camp(Id id, Entity& parent, const vec3& position, Faction& faction)
	: Complex(id, type<Camp>(), *this)
	, m_entity(id, *this, parent, position, ZeroQuat)
	, m_faction(faction)
	, m_position(position)
{}

Shield::Shield(Id id, Entity& parent, const vec3& position, Faction& faction, float radius)
	: Complex(id, type<Shield>(), m_emitter, *this)
	, m_entity(id, *this, parent, position, ZeroQuat)
	, m_emitter(m_entity)
	, m_faction(faction)
	, m_radius(radius)
	, m_charge(1.f)
	, m_discharge(0.f)
	, m_solid(m_entity, Sphere(radius), SolidMedium::me, CollisionGroup(CM_ENERGY), false, 0.f)
{
	m_entity.m_world.add_task(this, short(Task::State)); // TASK_GAMEOBJECT
}

Shield::~Shield()
{
	m_entity.m_world.remove_task(this, short(Task::State));
}

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

Slug::Slug(Entity& parent, const vec3& source, const quat& rotation, const vec3& velocity, float power)
	: Complex(0, type<Slug>(), *this)
	, m_entity(0, *this, parent, source, rotation)
	, m_source(source)
	, m_velocity(velocity)
	, m_power(power)
	//, m_solid(m_entity, *this, Sphere(0.1f), SolidMedium::me, CollisionGroup(CM_ENERGY), false, 1.f)
	, m_collider(m_entity, Sphere(0.1f), SolidMedium::me, CollisionGroup(CM_ENERGY))
{}

Slug::~Slug()
{}

void Slug::update()
{
	if(m_impacted)
		return;

	short int mask = CM_SOLID | CM_GROUND | CM_ENERGY;

	//Collision collision = m_solid.m_impl->raycast(m_entity.m_position + m_velocity, mask);
	Collision collision = m_collider.m_impl->raycast(m_entity.m_position + m_velocity, mask);
	Entity* hit = collision.m_second ? &collision.m_second->m_entity : nullptr;

	if(hit != nullptr)
	{
		if(hit->isa<Tank>())
		{
			m_impacted = true;
			m_impact = collision.m_hit_point;

			hit->as<Tank>().m_shock += 1.f;
			hit->as<Tank>().m_hitpoints -= 25.f;

			vec3 location = Zero3;//rotate(inverse(m_entity.m_rotation), m_impact - m_entity.m_position);

			if(hit->as<Tank>().m_hitpoints < 0.f)
				hit->as<Tank>().m_solid.m_impl->impulse(Y3 * 100.f * m_power, location);
			else
				hit->as<Tank>().m_solid.m_impl->impulse((m_velocity + Y3 * 10.f) * m_power, location);
		}

		if(hit->isa<Shield>())
		{
			auto reflect = [](const vec3& I, const vec3& N) { return I - 2.f * dot(N, I) * N; };

			vec3 N = normalize(collision.m_hit_point - hit->as<Shield>().m_entity.m_position);
			m_velocity = reflect(m_velocity, N);

			hit->as<Shield>().m_discharge += 1.0f;
		}
	}

	if(distance(m_entity.m_position, Zero3) > 1000.f)
		m_destroy = true;

	m_entity.set_position(m_entity.m_position + m_velocity);
	//m_collider.update_transform();
}

Tank::Tank(Id id, Entity& parent, const vec3& position, Faction& faction)
	: Complex(id, type<Tank>(), m_movable, m_emitter, *this)
	, m_entity(id, *this, parent, position, ZeroQuat)
	, m_movable(m_entity)
	, m_emitter(m_entity)
	, m_receptor(m_entity)
	, m_faction(faction)
	, m_solid(m_entity, CollisionShape(Cube(vec3(2.0f, 1.1f, 3.2f)), Y3 * 1.1f), false, 4.f)
{
	m_entity.m_world.add_task(this, short(Task::State)); // TASK_GAMEOBJECT

	m_emitter.add_sphere(VisualMedium::me, 0.1f);
	m_receptor.add_sphere(VisualMedium::me, 100.f);
	
	m_shock = 1.f;
}

Tank::~Tank()
{
	m_entity.m_world.remove_task(this, short(Task::State));
}

void Tank::next_frame(size_t tick, size_t delta)
{
	UNUSED(tick);

	m_shock = max(0.f, m_shock - 0.01f * float(delta));
	bool control = m_shock == 0.f;

	m_energy = min(100.f, m_energy + delta * .1f);

	for(auto& slug : reverse_adapt(m_slugs))
	{
		slug->update();
		if(slug->m_destroy)
			vector_remove_pt(m_slugs, *slug);
	}

	if(!m_ia)
		return;

	if(control && m_hitpoints > 0.f)
	{
		m_target = nullptr;

		ReceptorScope* vision = m_receptor.scope(VisualMedium::me);
		for(Entity* entity : vision->m_scope.store())
			if(Tank* tank = entity->try_as<Tank>())
				if(&tank->m_faction != &m_faction && !tank->m_stealth)
				{
					m_target = tank;
				}

		m_cooldown = max(0.f, m_cooldown - float(delta) * 0.01f);
		if(m_target)
		{
			m_turret_angle = look_at(m_entity.m_position, m_target->m_entity.m_position, -Z3);

			float d = distance(m_target->m_entity.m_position, m_entity.m_position);
			if(d > m_range)
			{
				m_dest = m_target->m_entity.m_position;
			}
			else if(m_cooldown == 0.f)
			{
				this->shoot();
				m_dest = Zero3;
				m_cooldown = 1.f;
			}
		}

		Tank* leader = m_faction.m_leader;
		if(leader && !m_target && distance(leader->m_entity.m_position, m_entity.m_position) > 50.f)
			m_dest = leader->m_entity.m_position;
		
		if(m_dest != Zero3)
		{
			if(!steer_2d(m_movable, m_dest, 15.f, float(delta) * float(c_tick_interval), m_range))
				m_movable.set_linear_velocity(m_movable.m_linear_velocity - Y3 * 1.f);
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

	m_slugs.emplace_back(make_object<Slug>(m_entity, m_entity.m_position + rotate(rotation, tank_muzzle), rotation, velocity, critical ? 10.f : 1.f));
}

BlockWorld::BlockWorld(const std::string& name)
	: Complex(0, type<BlockWorld>(), m_bullet_world, m_navmesh, *this)
	, m_world(0, *this, name)
	, m_bullet_world(m_world)
	, m_navmesh(m_world)
	//, m_block_subdiv(64, 1, 64)
	, m_block_subdiv(32, 1, 32)
	, m_tile_scale(10.f, 4.f, 10.f)
	, m_block_size(vec3(m_block_subdiv) * m_tile_scale)
	, m_world_size(m_block_size)
{}

BlockWorld::~BlockWorld()
{
	m_world.destroy();
}

void BlockWorld::generate_block(GfxSystem& gfx_system, const ivec2& coord)
{
	static WaveTileset& tileset = generator_tileset(gfx_system);

	TileBlock& block = ::generate_block(gfx_system, tileset, m_world.origin(), coord, m_block_subdiv, m_tile_scale, false);

	block.m_world_page.m_geometry_filter = { "flat_low", "flat_high", "cliff_side_0_0", "cliff_corner_in_0_0", "cliff_corner_out_0_0" };

	m_blocks[coord] = &block;
	if(m_center_block == nullptr)
		m_center_block = &block;

	block.m_wfc_block.m_auto_solve = true;
}

Player::Player(BlockWorld& world)
	: m_world(&world)
	, m_tank(0, world.m_world.origin(), Y3 * 20.f, g_factions[0])
{
	m_tank.m_faction.m_leader = &m_tank;
	m_tank.m_ia = false;
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

	auto fresnel_material = [&](Material& material, const Colour& colour)
	{
		material.m_fresnel_block.m_enabled = true;
		material.m_fresnel_block.m_value.m_value = colour;
		material.m_fresnel_block.m_value.m_texture = parent.m_scene->m_gfx_system.textures().file("beehive.png");
	};

	if(power[shield.m_faction.m_id] == nullptr)
	{
		Material* material = &parent.m_scene->m_gfx_system.fetch_material(("shield_faction_" + to_string(shield.m_faction.m_id)).c_str(), "fresnel");
		fresnel_material(*material, shield.m_faction.m_colour * 4.f);
		power[shield.m_faction.m_id] = material;
	}

	static Clock clock;

	float period = remap_trig(sin(clock.read() * 2.f), 0.f, 0.05f);

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
		paint(*power[shield.m_faction.m_id], period, shield.m_faction.m_colour * 4.f * shield.m_charge);
	}

	if(shield.m_discharge > 0.f)
		toy::sound(parent, "bzwomb", false, 0.5f);
}

void paint_shell(Gnode& parent, Slug& shell)
{
	static ParticleGenerator* flash = parent.m_scene->m_gfx_system.particles().file("flash");
	static ParticleGenerator* trail = parent.m_scene->m_gfx_system.particles().file("trail");
	static ParticleGenerator* impact = parent.m_scene->m_gfx_system.particles().file("impact");

	Gnode& source = gfx::node(parent, Ref(&shell), shell.m_source, shell.m_entity.m_rotation);
	gfx::particles(source, *flash);

	bool active = toy::sound(source, "bang", false, 0.5f);

	enum States { Fly = 1, Impact = 2 };
	if(!shell.m_impacted)
	{
		Gnode& projectile = gfx::node(parent.subx(Fly), Ref(&shell), shell.m_entity.m_position, shell.m_entity.m_rotation);
		gfx::shape(projectile, Cube(vec3(0.4f, 0.4f, 1.f)), Symbol(Colour(1.f, 2.f, 1.5f)));
		gfx::particles(projectile, *trail);
	}

	if(shell.m_impacted)
	{
		Gnode& hit = gfx::node(parent.subx(Impact), Ref(&shell), shell.m_impact, shell.m_entity.m_rotation);
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
	gfx::shape(parent, Quad(position, offset, vec2(4.f, 0.2f)), Symbol(Colour::White, Colour::None, true), ITEM_BILLBOARD);
	gfx::shape(parent, Quad(position, offset + fill_offset, vec2(4.f * percentage, 0.2f)), Symbol(colour, true, true), ITEM_BILLBOARD);
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

	if(tank_base_models[tank.m_faction.m_id] == nullptr)
	{
		tank_base_models[tank.m_faction.m_id] = &faction_model_variant(gfx_system, tank.m_faction, *gfx_system.models().file("scifi_tank_base"));
		tank_turret_models[tank.m_faction.m_id] = &faction_model_variant(gfx_system, tank.m_faction, *gfx_system.models().file("scifi_tank_turret"));
	}

	Gnode& turret = gfx::node(parent, {}, parent.m_attach->m_position, tank.turret_rotation());

	if(tank.m_hitpoints > 0.f)
	{
		if(tank.m_stealth)
		{
			gfx::item(parent, tank_base_dead, 0U, stealth);
			gfx::item(turret, tank_turret_dead, 0U, stealth);
		}
		else
		{
			gfx::item(parent, *tank_base_models[tank.m_faction.m_id]);
			gfx::item(turret, *tank_turret_models[tank.m_faction.m_id]);
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
			Gnode& symbol = gfx::node(alive, {}, parent.m_attach->m_position, parent.m_attach->m_rotation);
			gfx::shape(alive, Torus(4.f, 0.1f), Symbol(tank.m_faction.m_colour * 2.f));

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

void paint_block(Gnode& parent, TileBlock& block)
{
	if(block.m_wfc_block.m_wave.m_solved)
		paint_tiles(parent, Ref(&block.m_entity), block.m_wfc_block);
}

void paint_scene(Gnode& parent, bool radiance)
{
	Light& light = gfx::directional_light_node(parent);
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
	static ImageSkin skin = { *ui_window.find_image("graphic/red_on"), 46, 28, 38, 30 };
	
	static Style style = { "GamePanel", styles().wedge, [](Layout& l) { l.m_space = UNIT; l.m_align = { Right, CENTER }; l.m_padding = vec4(30.f); l.m_spacing = vec2(30.f); },
													   [](InkStyle& s) { s.m_empty = false; s.m_image_skin = skin; } };
	return style;
}

Style& center_panel_style(UiWindow& ui_window)
{
	static ImageSkin skin = { *ui_window.find_image("graphic/red_on"), 46, 28, 38, 30 };
	
	static Style style = { "GamePanel", styles().wedge, [](Layout& l) { l.m_space = UNIT; l.m_align = { CENTER, CENTER }; l.m_padding = vec4(30.f); l.m_spacing = vec2(30.f); },
													   [](InkStyle& s) { s.m_empty = false; s.m_image_skin = skin; } };
	return style;
}

Style& left_panel_style(UiWindow& ui_window)
{
	static ImageSkin skin = { *ui_window.find_image("graphic/red_on"), 46, 28, 38, 30 };
	
	static Style style = { "GamePanel", styles().wedge, [](Layout& l) { l.m_space = UNIT; l.m_align = { Left, CENTER }; l.m_padding = vec4(30.f); l.m_spacing = vec2(30.f); },
													   [](InkStyle& s) { s.m_empty = false; s.m_image_skin = skin; } };
	return style;
}

Style& menu_style()
{
	static Style style = { "GameMenu", styles().wedge, [](Layout& l) { l.m_space = UNIT; l.m_align = { Left, CENTER }; l.m_padding = vec4(120.f); l.m_padding.x = 240.f; l.m_spacing = vec2(30.f); } };
	return style;
}

#if 1
Style& button_style(UiWindow& ui_window)
{
	static Style style = { "GameButton", styles().button, [](Layout& l) {},
														  [](InkStyle& s) { s.m_empty = false; s.m_text_colour = Colour::AlphaWhite; s.m_text_size = 24.f; },
														  [](Style& s) { s.decline_skin(HOVERED).m_text_colour = Colour::White; } };
	return style;
}
#else
Style& button_style(UiWindow& ui_window)
{
	static ImageSkin skin = { *ui_window.find_image("graphic/red_off"), 46, 28, 38, 30 };
	static ImageSkin skin_focused = { *ui_window.find_image("graphic/red_on"), 46, 28, 38, 30 };

	static Style style = { "GameButton", styles().button, [](Layout& l) { l.m_size = { 400.f, 80.f }; },
														  [](InkStyle& s) { s.m_empty = false; s.m_text_colour = Colour::White; s.m_text_font = "veramono"; s.m_text_size = 24.f; s.m_padding = vec4(40.f, 20.f, 40.f, 20.f); s.m_image_skin = skin; },
														  [](Style& s) { s.decline_skin(HOVERED).m_text_colour = Colour::White; s.decline_skin(HOVERED).m_image_skin = skin_focused; } };
	return style;
}
#endif

Style& label_style()
{
	static Style style = { "GameLabel", styles().button, [](Layout& l) {},
														 [](InkStyle& s) { s.m_empty = false; s.m_text_colour = Colour::White; s.m_text_font = "veramono"; s.m_text_size = 14.f;  } };
	return style;
}

void ex_blocks_game_ui(Widget& parent, GameScene& scene)
{
	Player& player = val<Player>(scene.m_player);

	Widget& self = ui::widget(parent, styles().board, &scene);

	Viewer& viewer = ui::viewer(self, scene.m_scene);

	OrbitController& orbit = ui::orbit_controller(viewer, 0.f, -c_pi / 4.f, 200.f);
	orbit.set_target(player.m_tank.m_entity.m_position);

#ifdef TOY_SOUND
	scene.m_snd_manager.m_listener.setTransform(viewer.m_camera.m_eye, look_at(viewer.m_camera.m_eye, viewer.m_camera.m_target));
#endif

	Ray ray = viewer.mouse_ray();
	vec3 target = plane_segment_intersection(Plane(Y3, player.m_tank.m_entity.m_position.y), to_segment(ray));

	player.m_tank.m_turret_angle = look_at(player.m_tank.m_entity.m_position, target);

	tank_velocity_controller(viewer, player.m_tank);

	if(KeyEvent key_event = viewer.key_stroke(Key::LeftControl))
		player.m_tank.m_stealth = !player.m_tank.m_stealth;

	if(MouseEvent mouse_event = viewer.mouse_event(DeviceType::MouseLeft, EventType::Stroked, InputMod::Any))
	{
		viewer.take_focus();
		player.m_tank.shoot(viewer.ui().m_keyboard.m_shift);
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
		if(steer_2d(player.m_tank.m_movable, destination, 15.f, float(clock.step()), 0.1f))
			destination = Zero3;
	}

	paint_viewer(viewer);

	static Style& style_screen = screen_style();
	static Style& style_right_panel = right_panel_style(parent.ui_window());
	static Style& style_center_panel = center_panel_style(parent.ui_window());
	static Style& style_left_panel = left_panel_style(parent.ui_window());
	static Style& style_label = label_style();

	Widget& screen = ui::widget(viewer, style_screen);
	Widget& board = ui::board(screen);
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

	static DefaultWorld world = { "" };
	static Origin root = { 0, world.m_world };

	static Tank tank0 = { 0, root.m_entity, Zero3, g_factions[0] };
	static Tank tank1 = { 0, root.m_entity, X3 * 10.f, g_factions[1] };
	static Tank tank2 = { 0, root.m_entity, Z3 * 10.f, g_factions[2] };

	static bool once = false;
	if(!once)
	{
		tank0.m_entity.rotate(Y3, c_pi * 0.25f);
		tank1.m_entity.rotate(Y3, c_pi * 0.25f);
		tank2.m_entity.rotate(Y3, c_pi * 0.25f);
		once = true;
	}

	auto paint = [&](Tank& tank) { Gnode& node = gfx::node(scene, {}, tank.m_entity.m_position, tank.m_entity.m_rotation); paint_tank(node, tank); };
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
		global_pool<BlockWorld>();
		global_pool<Well>();
		global_pool<Camp>();
		global_pool<Shield>();
		global_pool<Tank>();
		global_pool<Fract>();
		global_pool<Sector>();
		global_pool<Block>();
		global_pool<OCamera>();

		SolidMedium::me.m_masks[CollisionGroup(CM_ENERGY)] = CM_SOLID | CM_GROUND | CM_ENERGY;

		BlockWorld& world = global_pool<BlockWorld>().construct("Arcadia");
		game.m_world = &world.m_world;

		//app.m_core->section(0).add_task(game.m_world);

		static Player player = { world };
		game.m_player = Ref(&player);

		world.generate_block(*app.m_gfx_system, ivec2(0));
		generate_camps(world);
	}

	virtual void scene(GameShell& app, GameScene& scene) final
	{
		static OmniVision vision = { *scene.m_game.m_world };

		scene_painters(scene, vision.m_store);

		scene.painter("World", [&](size_t index, VisuScene& scene, Gnode& parent) {
			UNUSED(scene); paint_scene(parent.subi((void*)index), true);
		});
		scene.entity_painter<Shield>("Shields", vision.m_store, paint_shield);
		scene.entity_painter<Well>("Well", vision.m_store, paint_well);
		scene.entity_painter<Tank>("Tanks", vision.m_store, paint_tank);
		scene.entity_painter<Slug>("Slugs", vision.m_store, paint_shell);

		scene.entity_painter<TileBlock>("Tileblocks", vision.m_store, paint_block);

		static PhysicDebugDraw physic_draw = { *scene.m_scene.m_immediate };

		scene.painter("PhysicsDebug", [&](size_t index, VisuScene& visu_scene, Gnode& parent) {
			//physic_draw.draw_physics(parent, *scene.m_game.m_world, SolidMedium::me);
		});
	}

	virtual void pump(GameShell& app, Game& game, Widget& ui) final
	{
		auto pump = [&](Widget& parent, Dockbar* dockbar = nullptr)
		{
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
