
#include <platform/ex_platform.h>
#include <toy/toy.h>

#include <platform/Api.h>
#include <meta/platform/Module.h>

//#define _PLATFORM_TOOLS
//#define SCRIPTED_IA

float omni_attenuation(vec3 ray, float range, float attenuation_factor, float lower_bound)
{
	float normalized_distance = length(ray) / range;
	return pow(max(1.f - normalized_distance, lower_bound), attenuation_factor);
}

float spot_attenuation(vec3 ray, vec3 light, float range, float attenuation_factor, float spot_attenuation, float spot_cutoff)
{
	float attenuation = omni_attenuation(ray, range, attenuation_factor, 0.001f);
	float scos = max(dot(normalize(ray), -light), spot_cutoff);
	float spot_rim = (1.f - scos) / (1.f - spot_cutoff);
	return attenuation * (1.f - pow(max(spot_rim, 0.001f), spot_attenuation));
}

void populate_block(TileBlock& block)
{
	generate_crates(block);
	generate_npcs(block);

	for(size_t x = 0; x < block.m_wfc_block.m_tiles.m_x; ++x)
		for(size_t y = 0; y < block.m_wfc_block.m_tiles.m_y; ++y)
			for(size_t z = 0; z < block.m_wfc_block.m_tiles.m_z; ++z)
			{
				Tile& tile = block.m_wfc_block.m_tileset.m_tiles_flip[block.m_wfc_block.m_tiles.at(x, y, z)];
				if(tile.m_name == "cube_covered_side")
				{
					if(random_integer(0, 9) > 8)
						block.m_entity.m_world.origin().construct<Lamp>(block.m_wfc_block.to_position(uvec3(x, y, z)) + Y3 * 1.5f * block.m_wfc_block.m_scale);
				}
			}
}

TileWorld::TileWorld(const std::string& name)
	: Complex(0, type<TileWorld>(), m_bullet_world, m_navmesh, *this)
	, m_world(0, *this, name)
	, m_bullet_world(m_world)
	, m_navmesh(m_world)
	, m_block_size(vec3(m_block_subdiv) * m_tile_scale)
{}

TileWorld::~TileWorld()
{
	m_world.destroy();
}

void TileWorld::next_frame()
{
	for(auto& coord_block : m_blocks)
		if(coord_block.second && coord_block.second->m_setup && !coord_block.second->m_populated)
		{
			populate_block(*coord_block.second);
			coord_block.second->m_populated = true;
		}
}

void TileWorld::generate_block(GfxSystem& gfx_system, const ivec2& coord)
{
	static WaveTileset& tileset = generator_tileset(gfx_system);

	TileBlock& block = ::generate_block(gfx_system, tileset, m_world.origin(), coord, m_block_subdiv, m_tile_scale);

	block.m_world_page.m_geometry_filter = { "platform/cube_covered", "platform/cube_covered_side", "platform/cube_covered_angle", "platform/corner_covered", "platform/empty_covered" };

	m_blocks[coord] = &block;

	// @todo why u clang no accept this ?
	// for(size_t x : { 0U, block.m_wfc_block.m_tiles.m_x - 1 })
	std::vector<size_t> xs = { 0U, block.m_wfc_block.m_tiles.m_x - 1 };
	for(size_t x : xs)
	for(size_t y = 0; y < block.m_wfc_block.m_tiles.m_y; ++y)
	for(size_t z = 0; z < block.m_wfc_block.m_tiles.m_z; ++z)
	{
		uint16_t empty = 0;
		block.m_wfc_block.m_wave.set_tile({ uint(x), uint(y), uint(z) }, empty);
	}

	if(m_center_block == nullptr)
	{
		m_center_block = &block;
		block.m_wfc_block.m_auto_solve = true;
		return;
	}

	bool positive = m_blocks[coord + ivec2(0, 1)] == nullptr;
	TileBlock& neighbour = positive ? *m_blocks[coord + ivec2(0, -1)] : *m_blocks[coord + ivec2(0, 1)];

	for(size_t x = 0; x < block.m_wfc_block.m_tiles.m_x; ++x)
	for(size_t y = 0; y < block.m_wfc_block.m_tiles.m_y; ++y)
	{
		size_t z = positive ? 0U : block.m_wfc_block.m_tiles.m_z - 1;
		size_t adjacent_z = positive ? block.m_wfc_block.m_tiles.m_z - 1 : 0U;
		uint16_t tile = neighbour.m_wfc_block.m_tiles.at(x, y, adjacent_z);
		block.m_wfc_block.m_wave.set_tile({ uint(x), uint(y), uint(z) }, tile);
	}

	block.m_wfc_block.m_wave.propagate();

	block.m_wfc_block.m_auto_solve = true;
}

void TileWorld::open_blocks(GfxSystem& gfx_system, const vec3& position, const ivec2& radius)
{
	ivec2 coord = ivec2(to_xz(position / m_block_size));

	for(int x = coord.x - radius.x; x < coord.x + radius.x + 1; ++x)
	for(int y = coord.y - radius.y; y < coord.y + radius.y + 1; ++y)
	{
		ivec2 neighbour = { x, y };
		if(!m_blocks[neighbour])
			this->generate_block(gfx_system, neighbour);
	}
}


Bullet::Bullet(Entity& parent, const vec3& source, const quat& rotation, float velocity)
	: Complex(0, type<Bullet>(), *this)
	, m_entity(0, *this, parent, source, rotation)
	, m_source(source)
	, m_velocity(rotate(rotation, -Z3) * velocity)
	//, m_solid(m_entity, *this, Sphere(0.1f), SolidMedium::me, CollisionGroup(energy), false, 1.f)
	, m_collider(m_entity, Sphere(0.1f), SolidMedium::me, CM_SOLID)
{}

Bullet::~Bullet()
{}

void Bullet::update()
{
	if(m_impacted)
		return;

	Collision collision = m_collider.m_impl->raycast(m_entity.m_position + m_velocity, CM_SOLID | CM_GROUND);
	Entity* hit = collision.m_second ? &collision.m_second->m_entity : nullptr;

	if(hit != nullptr && hit->isa<Human>())
	{
		Human& shot = hit->as<Human>();
		if(shot.m_shield && shot.m_energy > 0.f)
		{
			auto reflect = [](const vec3& I, const vec3& N) { return I - 2.f * dot(N, I) * N; };
			vec3 N = normalize(collision.m_hit_point - shot.m_entity.m_position + Y3);
			m_velocity = reflect(m_velocity, N);
			m_entity.m_rotation = look_at(Zero3, m_velocity);

			shot.m_energy -= 0.5f;
			shot.m_discharge += 0.5f;
		}
		else
		{
			m_impacted = true;
			m_impact = collision.m_hit_point;

			shot.damage(1.f);
		}
	}

	if(distance(m_entity.m_position, m_source) > 100.f)
		m_destroy = true;

	m_entity.set_position(m_entity.m_position + m_velocity);
	//m_collider.update_transform();
}

const vec3 Human::muzzle_offset = { 0.f, 1.6f, -1.f };
float Human::headlight_angle = 40.f;
//float Human::headlight_angle = 30.f;
//float Human::headlight_angle = 20.f;

Human::Human(Id id, Entity& parent, const vec3& position, Faction faction)
	: Complex(id, type<Human>(), m_movable, m_emitter, m_receptor, m_script, *this)
	, m_entity(id, *this, parent, position, ZeroQuat)
	, m_movable(m_entity)
	, m_emitter(m_entity)
	, m_receptor(m_entity)
	, m_script(m_entity)
	, m_faction(faction)
	, m_walk(false)
	, m_solid(m_entity, CollisionShape(Capsule(0.35f, 1.1f), Y3 * 0.9f), false, 1.f)
{
	m_entity.m_world.add_task(this, short(Task::State)); // TASK_GAMEOBJECT

	m_emitter.add_sphere(VisualMedium::me, 0.1f);
	m_receptor.add_sphere(VisualMedium::me, 30.f);
}

Human::~Human()
{
	m_entity.m_world.remove_task(this, short(Task::State));
}

void Human::next_frame(size_t tick, size_t delta)
{
	UNUSED(tick);
	m_solid->set_angular_factor(Zero3);

	m_visor = this->aim();

	for(auto& bullet : reverse_adapt(m_bullets))
	{
		bullet->update();
		if(bullet->m_destroy)
			vector_remove_pt(m_bullets, *bullet);
	}

	m_energy = min(1.f, m_energy + delta * 0.01f);
	m_discharge = max(0.f, m_discharge - delta * 0.05f);
	
	// @kludge in case that weird bug where we go through the scene geometry happens... put us back up
	if(m_entity.m_position.y < -10.f)
		m_entity.m_position.y = 10.f;

	bool ia = m_faction == Faction::Enemy;
	//ia = false;
	if(ia)
	{
		if(m_life <= 0.f)
		{
			m_state = { "Die", false };
			return;
		}

		if(m_target)
		{
			Aim aim = this->aim();
			bool disable = distance(m_target->m_entity.m_position, m_entity.m_position) > 50.f;
			disable |= aim.hit && aim.hit != &m_target->m_entity;
			disable |= m_target->m_life <= 0.f;
			if(disable)
				m_target = nullptr;
		}

		if(m_target == nullptr)
		{
			ReceptorScope* vision = m_receptor.scope(VisualMedium::me);
			for(Entity* entity : vision->m_scope.store())
				if(Human* human = entity->try_as<Human>())
				{
					if(human->m_faction != m_faction)
					{
						vec3 direction = entity->m_position - m_entity.m_position;
						float light = spot_attenuation(-direction, m_entity.front(), 30.f, 0.5f, 0.9f, cos(to_radians(headlight_angle)));
						float visibility = light * (human->m_headlight ? 4.f : 0.5f);
						if(human->m_life > 0.f && (visibility > 0.2f || length(direction) < 4.f))
						{
							m_target = human;
							m_cooldown = 2.f;
						}
					}
				}
		}

		m_cooldown = max(0.f, m_cooldown - float(delta) * 0.05f);
		if(m_target)
		{
			this->stop();

			auto x0z = [](const vec3& v) -> vec3 { return{ v.x, 0.f, v.z }; };
			m_entity.set_rotation(look_at(x0z(m_entity.m_position), x0z(m_target->m_entity.m_position)));

			if(m_cooldown == 0.f)
			{
				this->shoot();
				m_cooldown = 1.f;
			}
		}
		else
		{
			auto is_walkable = [&](const vec3& pos) { return m_entity.m_world.as<PhysicWorld>().ground_point(to_ray(pos, -Y3)) != Zero3; };

			if(m_dest == Zero3)
			{
				float amplitude = 10.f;
				m_dest = m_entity.m_position + vec3(random_scalar(-amplitude, amplitude), 0.f, random_scalar(-amplitude, amplitude));
				if(!is_walkable(m_dest))
					m_dest = Zero3;
			}

			if(m_dest != Zero3)
			{
				if(steer_2d(m_movable, m_dest, 3.f, float(delta) * float(c_tick_interval), 1.f))
				{
					this->stop();
				}
				else
				{
					m_state = { m_walk ? "Walk" : "RunAim", true };
					m_movable.set_linear_velocity(m_movable.m_linear_velocity - Y3 * 1.f);
				}
			}
		}
	}
}

quat Human::sight(bool aiming)
{
	return aiming ? rotate(m_entity.m_rotation, X3, m_angles.y) : m_entity.m_rotation;
}

void Human::stop()
{
	m_state = { "IdleAim", true };
	m_movable.m_linear_velocity = Zero3;
	m_dest = Zero3;
}

Aim Human::aim()
{
	quat rotation = this->sight(m_aiming);
	vec3 muzzle = m_entity.m_position + rotate(m_entity.m_rotation, Human::muzzle_offset);
	vec3 end = muzzle + rotate(rotation, -Z3) * 1000.f;

	Collision hit = m_entity.m_world.as<PhysicWorld>().raycast({ muzzle, end }, CM_GROUND | CM_SOLID);
	return { rotation, muzzle, hit.m_second ? hit.m_hit_point : end, hit.m_second ? &hit.m_second->m_entity : nullptr };
}

void Human::shoot()
{
	Aim aim = this->aim();
	auto fuzz = [](const quat& rotation, const vec3& axis) { return rotate(rotation, axis, random_scalar(-0.05f, 0.05f)); };
	quat rotation = fuzz(fuzz(aim.rotation, X3), Y3);
	m_bullets.emplace_back(make_object<Bullet>(m_entity, aim.start, rotation, 2.f));
	//m_solid->impulse(rotate(m_entity.m_rotation, Z3 * 4.f), Zero3);
}

void Human::damage(float amount)
{
	m_life -= amount;
	if(m_life <= 0.f)
	{
		m_headlight = false;
		m_movable.m_linear_velocity = Zero3;
	}
}

Lamp::Lamp(Id id, Entity& parent, const vec3& position)
	: Complex(id, type<Lamp>(), m_movable, *this)
	, m_entity(id, *this, parent, position, ZeroQuat)
	, m_movable(m_entity)
{}

Crate::Crate(Id id, Entity& parent, const vec3& position, const vec3& extents)
	: Complex(id, type<Crate>(), m_movable, *this)
	, m_entity(id, *this, parent, position, ZeroQuat)
	, m_movable(m_entity)
	, m_extents(extents)
	, m_solid(m_entity, Cube(extents), SolidMedium::me, CM_SOLID, false, 10.f)
{}

Player::Player(TileWorld& world)
	: m_world(&world)
{}

void Player::spawn(const vec3& start_position)
{
	vec3 position = start_position + Y3 * 2.f * m_world->m_center_block->m_wfc_block.m_scale.y;
	m_human = &m_world->m_world.origin().construct<Human>(position, Faction::Ally);
	//m_human->m_headlight = false;
	m_human->m_stealth = true;
	m_human->m_walk = false;
	m_human->m_life = 5.f;
}

void paint_bullet(Gnode& parent, Bullet& bullet)
{
	static ParticleGenerator* flash = parent.m_scene->m_gfx_system.particles().file("flash");
	static ParticleGenerator* impact = parent.m_scene->m_gfx_system.particles().file("impact");

	Gnode& source = gfx::node(parent, {}, bullet.m_source, bullet.m_entity.m_rotation);
	gfx::particles(source, *flash);

	//toy::sound(source, "rifle", false, 0.4f);
	toy::sound(source, "rifle2", false, 0.4f);

	if(!bullet.m_impacted)
	{
		Gnode& projectile = gfx::node(parent, {}, bullet.m_entity.m_position, bullet.m_entity.m_rotation);
		gfx::shape(projectile, Cube(vec3(0.02f, 0.02f, 0.4f)), Symbol(Colour(2.f, 0.3f, 0.3f) * 4.f));
	}

	if(bullet.m_impacted)
	{
		Gnode& hit = gfx::node(parent, {}, bullet.m_impact, bullet.m_entity.m_rotation);
		toy::sound(source, "impact2", false, 0.4f);
		if(gfx::particles(hit, *impact).m_ended)
			bullet.m_destroy = true;
	}
}

void paint_lamp(Gnode& parent, Lamp& lamp)
{
	gfx::shape(parent, Sphere(0.1f), Symbol(Colour::Red), ITEM_SELECTABLE);
	gfx::light(parent, LightType::Point, false, Colour(1.f, 0.3f, 0.2f), 10.f);
}

Material& highlight_material(const std::string& name, const Colour& colour, int factor)
{
	Material& material = Material::ms_gfx_system->fetch_material(name.c_str(), "pbr/pbr");
	material.m_pbr_block.m_enabled = true;
	material.m_pbr_block.m_albedo.m_value = Colour::Black;
	material.m_pbr_block.m_emissive.m_value = colour;
	material.m_pbr_block.m_emissive.m_value.m_a = float(factor);
	return material;
}

Model& human_model_glow(GfxSystem& gfx_system)
{
	//Material& glow_material = highlight_material("JointsGlow", Colour(0.2f, 0.8f, 2.4f), 2);
	static Material& glow_material = highlight_material("JointsGlow", Colour::Red, 4);
	static Model& human = *gfx_system.models().file("human00");
	static Model& model = model_variant(gfx_system, human, "human_glow", carray<cstring, 1>{ "Joints" },
																		 carray<Material*, 1>{ &glow_material });
	return model;
}

Model& human_model_stealth(GfxSystem& gfx_system)
{
	static Material& stealth_material = highlight_material("JointsStealth", Colour(0.2f, 0.2f, 0.2f), 2);
	static Model& human = *gfx_system.models().file("human00");
	static Model& model = model_variant(gfx_system, human, "human_stealth", carray<cstring, 1>{ "Joints" },
																		    carray<Material*, 1>{ &stealth_material });
	return model;
}

void paint_human(Gnode& parent, Human& human)
{
	static Model& model_normal = *parent.m_scene->m_gfx_system.models().file("human00");
	static Model& model_stealth = human_model_stealth(parent.m_scene->m_gfx_system);
	static Model& model_glow = human_model_glow(parent.m_scene->m_gfx_system);

	Model& model = human.m_stealth ? model_stealth : model_glow;
	
	Gnode& self = gfx::node(parent, Ref(&human), human.m_entity.m_position, human.m_entity.m_rotation);
	
	Item& item = gfx::item(self, model, ITEM_SELECTABLE);
	Animated& animated = gfx::animated(self, item);

	if(animated.m_playing.empty() || animated.playing() != human.m_state.name)
		animated.play(human.m_state.name.c_str(), human.m_state.loop, 0.f, human.m_walk ? 0.7f : 1.f);

	Bone* bone = animated.m_rig.m_skeleton.find_bone("RightHand");

	mat4 pose = bxrotation(human.m_entity.m_rotation) * fix_bone_pose(*bone);
	Gnode& arm = gfx::node(self, {}, human.m_entity.m_position + vec3(pose * vec4(Zero3, 1.f)), human.m_entity.m_rotation);
	gfx::model(arm, "rifle");

	enum States { Seek = 3, Dead = 4, Shield = 5, Headlight = 6, Visor = 7 };

	if(human.m_target)
	{
		Gnode& seek = gfx::node(parent.subx(Seek), Ref(&human), human.m_entity.m_position, human.m_entity.m_rotation);
		toy::sound(seek, "destroy", false, 0.5f);
	}

	if(human.m_life <= 0.f)
	{
		Gnode& dead = gfx::node(parent.subx(Dead), Ref(&human), human.m_entity.m_position, human.m_entity.m_rotation);
		//toy::sound(dead, "robotdeath", false, 0.1f);
		toy::sound(dead, "sparks", false, 0.1f);
	}

	if(human.m_shield)
	{
		auto shield_material = [&](Colour colour, float bias) -> Material&
		{
			Material& material = parent.m_scene->m_gfx_system.fetch_material("shield", "fresnel");
			material.m_fresnel_block.m_enabled = true;
			material.m_fresnel_block.m_value.m_value = colour;
			material.m_fresnel_block.m_fresnel_bias = bias;
			//material.m_fresnel_block.m_value.m_texture = parent.m_scene->m_gfx_system.textures().file("beehive.png");
			return material;
		};

		Colour shield_colour = Colour(0.2f, 0.8f, 2.4f) * 4.f;
		static Material& shield = shield_material(shield_colour, 0.04f);

		static Clock clock;
		float shield_intensity = remap_trig(sin(clock.read() * 2.f), 0.3f, 1.4f) * (human.m_energy + human.m_discharge * 10.f);
		float light_intensity = remap_trig(sin(clock.read() * 2.f), 0.8f, 1.4f) * (human.m_energy + human.m_discharge * 5.f);
		
		shield.m_fresnel_block.m_value.m_value = shield_colour * shield_intensity;

		Gnode& center = gfx::node(parent.subx(Shield), Ref(&human), human.m_entity.m_position + rotate(human.m_entity.m_rotation, Y3), human.m_entity.m_rotation);
		gfx::shape(center, Sphere(1.f), Symbol(shield_colour), 0U, &shield);
		gfx::light(center, LightType::Point, false, Colour(0.3f, 0.4f, 1.f) * light_intensity, 10.f);
	
		toy::sound(center, "electricfield", false, 0.3f);

		if(human.m_discharge > 0.f)
		{
			toy::sound(center, "bzwomb");
			toy::sound(center, "grzzt");
		}
	}

	if(human.m_headlight)
	{
		Gnode& headlight = gfx::node(parent.subx(Headlight), Ref(&human), human.m_entity.m_position + rotate(human.m_entity.m_rotation, Human::muzzle_offset), human.sight());
		Light& light = gfx::light(headlight, LightType::Spot, false, Colour::White, 30.f);
		light.m_spot_angle = Human::headlight_angle;
		light.m_spot_attenuation = 0.9f;
	}

	if(human.m_faction == Faction::Ally)
	{
		Gnode& visor = gfx::node(parent.subx(Visor), Ref(&human), human.m_entity.m_position + rotate(human.m_entity.m_rotation, Human::muzzle_offset), human.sight(human.m_aiming));
		//gfx::shape(visor, Line(-Z3 * 4.f, -Z3 * 8.f), Symbol(Colour(0.2f, 0.8f, 2.4f) * 4.f, Colour::None, true));
		gfx::shape(visor, Circle(-Z3 * 8.f, 0.2f, Axis::Z), Symbol(Colour::None, Colour(0.2f, 0.8f, 2.4f) * 4.f, true));
	}
}

void paint_world_block(Gnode& parent, TileBlock& block, const uvec3* exclude = nullptr)
{
	if(!block.m_wfc_block.m_wave.m_solved) return;
	paint_tiles(parent, Ref(&block.m_entity), block.m_wfc_block, uvec3(UINT_MAX), exclude);
	if(!block.m_world_page.m_build_geometry)
		block.m_world_page.m_build_geometry = [&](WorldPage& page) { build_block_geometry(*parent.m_scene, page, block); };
}

Material& plain_material(GfxSystem& gfx_system, cstring name, const Colour& colour)
{
	Material& material = gfx_system.fetch_material(name, "pbr/pbr");
	material.m_pbr_block.m_enabled = true;
	material.m_pbr_block.m_albedo.m_value = colour;
	return material;
}

void paint_crate(Gnode& parent, Crate& crate)
{
	static Material& material = plain_material(parent.m_scene->m_gfx_system, "crate", Colour::White);
	gfx::shape(parent, Cube(crate.m_extents), Symbol(), ITEM_SELECTABLE, &material);
}

void paint_scene(Gnode& parent)
{
	parent.m_scene->m_environment.m_radiance.m_energy = 0.2f;
	parent.m_scene->m_environment.m_radiance.m_ambient = 0.04f;

	gfx::radiance(parent, "radiance/tiber_1_1k.hdr", BackgroundMode::None);

	toy::sound(parent, "complexambient", true, 0.1f);
}

void paint_viewer(Viewer& viewer)
{
	viewer.m_filters.m_glow.m_enabled = true;
#ifndef MUD_PLATFORM_EMSCRIPTEN
	viewer.m_filters.m_glow.m_bicubic_filter = true;
#endif
}

vec3 find_fitting_player_location(WfcBlock& tileblock)
{
	vec3 center = vec3(tileblock.m_size) * 0.5f;
	vec3 start_coord = {};
	for(size_t i = 0; i < tileblock.m_tiles.size(); ++i)
		if(tileblock.m_tileset.m_tiles_flip[tileblock.m_tiles[i]].m_name == "empty_covered")
		{
			vec3 coord = { tileblock.m_tiles.x(i), tileblock.m_tiles.y(i), tileblock.m_tiles.z(i) };
			if(distance2(coord, center) < distance2(start_coord, center))
				start_coord = coord;
		}
	return tileblock.to_position(start_coord);
}

Style& menu_style()
{
	static Style style = { "GameMenu", styles().wedge, [](Layout& l) { l.m_space = UNIT; l.m_align = { Left, CENTER }; l.m_padding = vec4(120.f); l.m_padding.x = 300.f; l.m_spacing = vec2(30.f); } };
	return style;
}

Style& button_style()
{
	static Style style = { "GameButton", styles().button, [](Layout& l) {},
														  [](InkStyle& s) { s.m_empty = false; s.m_text_colour = Colour::AlphaWhite; s.m_text_size = 24.f; },
														  [](Style& s) { s.decline_skin(HOVERED).m_text_colour = Colour::White; } };
	return style;
}

Style& health_bar_style()
{
	static Style style = { "HealthBar", styles().filler, [](Layout& l) { l.m_space = { READING, WRAP, FIXED }; l.m_size = { 0.f, 10.f }; },
														 [](InkStyle& s) { s.m_empty = false; s.m_background_colour = Colour::Red; } };
	return style;
}

Style& energy_bar_style()
{
	static Style style = { "EnergyBar", styles().filler, [](Layout& l) { l.m_space = { READING, WRAP, FIXED }; l.m_size = { 0.f, 10.f }; },
														 [](InkStyle& s) { s.m_empty = false; s.m_background_colour = Colour::Blue; } };
	return style;
}

Style& row_bar_style()
{
	static Style style = { "RowBar", styles().row, [](Layout& l) { l.m_spacing = vec2(20.f); } };
	return style;
}

Style& screen_style()
{
	static Style style = { "GameScreen", styles().wedge, [](Layout& l) { l.m_space = LAYOUT; l.m_padding = vec4(30.f); } };
	return style;
}

Style& left_panel_style(UiWindow& ui_window)
{
	//static ImageSkin skin = { *ui_window.find_image("graphic/blue_on"), 46, 28, 38, 30 };
	
	static Style style = { "LeftPanel", styles().wedge, [](Layout& l) { l.m_space = { PARAGRAPH, WRAP, FIXED }; l.m_size = { 450.f, 0.f }; l.m_align = { Left, CENTER }; l.m_padding = vec4(30.f); l.m_spacing = vec2(30.f); } };
													   //[](InkStyle& s) { s.m_empty = false; s.m_image_skin = skin; } };
	return style;
}

void human_controller(HumanController& controller, Human& human, OrbitController& orbit, bool relative = true)
{
	vec3 velocity = human.m_solid->linear_velocity();
	vec3 force = relative ? rotate(human.m_entity.m_rotation, controller.m_force)
						  : rotate(quat(vec3(orbit.m_pitch, orbit.m_yaw, 0.f)), controller.m_force);

	human.m_solid->set_linear_velocity({ force.x, velocity.y - 1.f, force.z });
	human.m_solid->set_angular_velocity(controller.m_torque);
}

static void human_velocity_controller(Viewer& viewer, HumanController& controller, Human& human, OrbitController& orbit, bool relative = true)
{
	const float speed = viewer.ui().m_keyboard.m_shift ? 4.f : 15.f;
	ui::velocity_controller(viewer, controller.m_force, controller.m_torque, speed);

	if(viewer.key_event(Key::Space, EventType::Stroked))
		human.m_solid->impulse(Y3 * 20.f, Zero3);

	if(controller.m_force != Zero3 || controller.m_torque != Zero3)
	{
		human.m_state = { human.m_walk ? "Walk" : "RunAim", true };
	}
	else
	{
		human.m_state = { "IdleAim", true };
	}

	human_controller(controller, human, orbit, relative);
}

void ex_platform_game_hud(Viewer& viewer, GameScene& scene, Human& human)
{
	static Style& style_screen = screen_style();
	static Style& style_left_panel = left_panel_style(viewer.ui_window());

	//Widget& screen = ui::screen(viewer);
	Widget& screen = ui::widget(viewer, style_screen);

	ui::OrbitMode mode = val<Player>(scene.m_player).m_mode;
	OrbitController& orbit = ui::hybrid_controller(viewer, mode, human.m_entity, human.m_aiming, human.m_angles, scene.m_game.m_mode == GameMode::Play);

	Widget& board = ui::board(screen);
	Widget& row = ui::row(screen);
	Widget& left_panel = ui::widget(row, style_left_panel);

	static HumanController controller;

	if(human.m_life <= 0.f)
	{
		controller.m_force = Zero3;
		controller.m_torque = Zero3;
		human.m_state = { "Die", false };
	}

	if(human.m_life > 0.f)
	{
		human_velocity_controller(viewer, controller, human, orbit, mode != ui::OrbitMode::Isometric);

		if(mode == ui::OrbitMode::Isometric && controller.m_force != Zero3)
			human.m_entity.set_rotation(look_at(Zero3, rotate(quat(vec3(0.f, orbit.m_yaw, 0.f)), controller.m_force)));

		if(viewer.mouse_event(DeviceType::MouseLeft, EventType::Stroked))
		{
			//viewer.take_focus();
			human.shoot();
		}

		if(viewer.key_event(Key::LeftShift, EventType::Pressed))
			human.m_headlight = !human.m_headlight;

		if(viewer.key_event(Key::LeftControl, EventType::Pressed))
			human.m_shield = !human.m_shield;

		auto bar = [](Widget& parent, Style& style, cstring icon, float ratio)
		{
			Widget& row = ui::widget(parent, row_bar_style());// row(parent);
			ui::icon(row, icon);
			ui::widget(row, style);
			//ui::fill_bar(row, ratio);
		};

		//ui::label(left_panel, "Press ARROWS to move, CTRL to activate shield, SHIFT to switch headlight, Space to jump, and Left CLICK to fire");
		if(false)
		{
			bar(left_panel, health_bar_style(), "(health64)", human.m_life);
			bar(left_panel, energy_bar_style(), "(energy64)", human.m_energy);
		}
	}

	if(human.m_life <= 0.f)
	{
		Widget& modal = ui::popup(screen, styles().modal, ui::PopupFlags::None);
		ui::title(modal, "You are DEAD");
		ui::label(modal, "Press ENTER to try again");

		if(viewer.key_event(Key::Return, EventType::Stroked))
		{
			human.m_life = 5.f;
		}
	}
}

void ex_platform_game_ui(Widget& parent, Game& game, GameScene& scene)
{
	Widget& self = ui::widget(parent, styles().board, &scene);//ui::board(parent);

	Viewer& viewer = ui::viewer(self, scene.m_scene);

	paint_viewer(viewer);
	
	Player& player = val<Player>(game.m_player);
	if(player.m_human)
		ex_platform_game_hud(viewer, scene, *player.m_human);
}

Viewer& ex_platform_menu_viewport(Widget& parent, GameShell& app)
{
	Viewer& viewer = ui::scene_viewer(parent);
	Gnode& scene = viewer.m_scene->begin();

#ifdef TOY_SOUND
	scene.m_sound_manager = app.m_sound_system.get();
#endif

	paint_viewer(viewer);
	paint_scene(scene);
	
	static Model& human = human_model_glow(viewer.m_scene->m_gfx_system);
	static Clock clock;

	viewer.m_camera.m_eye = Z3 * 2.f;

	Gnode& node = gfx::node(scene, {}, -Y3 * 0.5f + X3 * 0.6f, angle_axis(fmod(clock.read(), 2.f * c_pi), Y3), Unit3 * 0.5f);
	Item& item = gfx::item(node, human);
	Animated& animated = gfx::animated(node, item);
	 
	if(animated.m_playing.empty())
		animated.play("IdleAim", true, 0.f);

	return viewer;
}

void ex_platform_menu(Widget& parent, Game& game)
{
	Widget& self = ui::board(parent);

	Viewer& viewer = ex_platform_menu_viewport(self, *game.m_shell);
	Widget& overlay = ui::screen(viewer);

	Widget& menu = ui::widget(overlay, menu_style());

	ui::icon(menu, "(toy)");

	if(ui::button(menu, button_style(), "Start (3rd Person)").activated())
	{
		game.m_module->start(*game.m_shell, game);
		val<Player>(game.m_player).m_mode = ui::OrbitMode::ThirdPerson;
	}

	if(ui::button(menu, button_style(), "Start (Isometric)").activated())
	{
		game.m_module->start(*game.m_shell, game);
		val<Player>(game.m_player).m_mode = ui::OrbitMode::Isometric;
	}

	if(ui::button(menu, button_style(), "Start (Pseudo Isometric)").activated())
	{
		game.m_module->start(*game.m_shell, game);
		val<Player>(game.m_player).m_mode = ui::OrbitMode::PseudoIsometric;
	}

	ui::button(menu, button_style(), "Continue game");
	ui::button(menu, button_style(), "Quit");
}

void ex_platform_pump_game(GameShell& app, Game& game, Widget& parent)
{
	Player& player = val<Player>(game.m_player);
	TileWorld& world = as<TileWorld>(game.m_world->m_complex);
	TileBlock& block = *world.m_center_block;

	world.next_frame();

	Widget& self = ui::widget(parent, styles().board, &game);

	if(player.m_human == nullptr)
	{
		Viewer& viewer = ex_platform_menu_viewport(self, *game.m_shell);
		Widget& overlay = ui::screen(viewer);

		Widget& dialog = ui::widget(overlay, menu_style());
		ui::item(dialog, button_style(), "Loading");

		if(block.m_wfc_block.m_wave_solved > 0)
		{
			vec3 start_position = find_fitting_player_location(block.m_wfc_block);
			player.spawn(start_position);
		}
	}
	else
	{
		static GameScene& scene = app.add_scene();
		ex_platform_game_ui(self, game, scene);

		vec3 position = player.m_human->m_entity.m_position;
		world.open_blocks(*app.m_gfx_system, position, { 0, 1 });
	}
}

template <class T, class T_Store, class T_PaintFunc>
inline void range_entity_painter(VisuScene& scene, Entity& reference, float range, cstring name, T_Store& entities, T_PaintFunc paint_func)
{
	auto paint = [&scene, &reference, range, &entities, paint_func](size_t index, VisuScene&, Gnode& parent)
	{
		float range2 = range*range;
		for(Entity* entity : entities.store())
		{
			float dist2 = distance2(entity->m_position, reference.m_position);
			if(dist2 < range2 && entity->isa<T>())
				paint_func(scene.entity_node(parent, *entity, index), entity->as<T>());
		}
	};
	scene.m_painters.emplace_back(make_unique<VisuPainter>(name, scene.m_painters.size(), paint));
}

class PlatformModule : public GameModule
{
public:
	PlatformModule(Module& module) : GameModule(module) {}

	virtual void init(GameShell& app, Game& game) final
	{
		UNUSED(game);
		app.m_gfx_system->add_resource_path("examples/ex_platform/");
		app.m_gfx_system->add_resource_path("examples/05_character/");
		app.m_gfx_system->add_resource_path("examples/17_wfc/");

#ifdef SCRIPTED_IA
		LocatedFile location = app.m_gfx_system->locate_file("scripts/enemy_ai.lua");

		if(location.m_name != nullptr)
		{
			TextScript& script = app.m_editor.m_script_editor.create_script("enemy_ai", Language::Lua);
			script.m_script = read_text_file(std::string(location.m_location) + location.m_name);
		}
#endif
	}

	virtual void start(GameShell& app, Game& game) final
	{
		global_pool<TileBlock>();
		global_pool<TileWorld>();
		global_pool<Human>();
		global_pool<Crate>();
		global_pool<OCamera>();

		TileWorld& tileworld = global_pool<TileWorld>().construct("Arcadia");
		game.m_world = &tileworld.m_world;

		static Player player = { tileworld };
		game.m_player = Ref(&player);

		tileworld.generate_block(*app.m_gfx_system, ivec2(0));
	}

	virtual void scene(GameShell& app, GameScene& scene) final
	{
		static OmniVision vision = { *scene.m_game.m_world };
		//scene.m_camera.m_entity.set_position(Zero3);

		//scene_painters(scene, vision.m_store);
		scene.painter("World", [&](size_t index, VisuScene& scene, Gnode& parent) {
			UNUSED(scene); paint_scene(parent.subi((void*)index));
		});

		Player& player = val<Player>(scene.m_player);
		Entity& reference = player.m_human->m_entity;

		auto paint_hole_block = [&](Gnode& parent, TileBlock& block)
		{
#if 0 //ndef MUD_PLATFORM_EMSCRIPTEN
			if(block.contains(player.m_human->m_entity.m_position))
			{
				// cut a hole of 6x6 tiles above the character
				uvec3 coord = block.m_wfc_block.to_coord(player.m_human->m_entity.m_position);
				uvec3 y = uvec3(0, 1, 0);
				uvec3 lohi[2] = { { coord + y - min(uvec3(6, 0, 6), coord) },
								  { coord + y + uvec3(6, 0, 6)} };
				paint_world_block(parent, block, lohi);
			}
			else
#endif
			{
				paint_world_block(parent, block);
			}
		};

		range_entity_painter<Lamp>(scene, reference, 100.f, "Lamps", vision.m_store, paint_lamp);
		range_entity_painter<Human>(scene, reference, 100.f, "Humans", vision.m_store, paint_human);
		range_entity_painter<Crate>(scene, reference, 100.f, "Crates", vision.m_store, paint_crate);
		range_entity_painter<TileBlock>(scene, reference, 200.f, "Tileblocks", vision.m_store, paint_hole_block);
		range_entity_painter<Bullet>(scene, reference, 100.f, "Bullets", vision.m_store, paint_bullet);

		//physic_painter(scene);
	}

	virtual void pump(GameShell& app, Game& game, Widget& ui) final
	{
		auto pump = [&](Widget& parent, Dockbar* dockbar = nullptr)
		{
			if(!game.m_player)
				ex_platform_menu(parent, game);
			else
				ex_platform_pump_game(app, game, parent);
		};

#ifdef _PLATFORM_TOOLS
		edit_context(ui, app.m_editor, true);
		pump(*app.m_editor.m_screen, app.m_editor.m_dockbar);
#else
		pump(ui);
#endif
	}
};

#ifdef _EX_PLATFORM_EXE
int main(int argc, char *argv[])
{
	GameShell app(carray<cstring, 1>{ TOY_RESOURCE_PATH }, argc, argv);
	
	PlatformModule module = { _platform::m() };
	//app.run_game(module);
	app.run_editor(module);
}
#endif
