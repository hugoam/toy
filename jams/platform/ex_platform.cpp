
#include <platform/ex_platform.h>
#include <toy/toy.h>

#include <platform/Api.h>
#include <meta/_platform.meta.h>

//#define _PLATFORM_TOOLS
#define CLUSTERED 1
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

void populate_block(Tileblock& block)
{
	generate_crates(block);
	generate_npcs(block);
	generate_lamps(block);
}

Prototype tile_world = { type<TileWorld>(), { &type<World>(), &type<BulletWorld>(), &type<Navmesh>() } };

TileWorld::TileWorld(const string& name, JobSystem& job_system)
	: Complex(0, type<TileWorld>(), m_bullet_world, m_navmesh, *this)
	, m_world(0, *this, name, job_system)
	, m_bullet_world(m_world)
	, m_navmesh(m_world)
	, m_block_size(vec3(m_block_subdiv) * m_tile_scale)
{
	m_world.m_pump.add_step({ Task::PhysicsWorld,
		[&](size_t tick, size_t delta) { m_bullet_world.next_frame(tick, delta); }
	});
}

TileWorld::~TileWorld()
{}

void TileWorld::next_frame()
{
	for(auto& coord_block : m_blocks)
		if(coord_block.second && coord_block.second->m_setup && !coord_block.second->m_populated)
		{
			populate_block(*coord_block.second);
			coord_block.second->m_populated = true;
		}
}

void TileWorld::generate_block(GfxSystem& gfx, const ivec2& coord)
{
	static WaveTileset& tileset = generator_tileset(gfx);

	HTileblock block = ::generate_block(gfx, tileset, m_world.origin(), coord, m_block_subdiv, m_tile_scale);
	WfcBlock& wfc = block->m_wfc_block;
	WorldPage& world_page = block->m_world_page;

	world_page.m_geometry_filter = {
		"platform/cube_covered", "platform/cube_covered_side", "platform/cube_covered_angle", "platform/corner_covered", "platform/empty_covered"
	};

	m_blocks[coord] = block;

	// @todo why u clang no accept this ?
	// for(size_t x : { 0U, block.m_wfc_block.m_tiles.m_x - 1 })
	vector<size_t> xs = { 0U, wfc.m_tiles.m_x - 1 };
	for(size_t x : xs)
	for(size_t y = 0; y < wfc.m_tiles.m_y; ++y)
	for(size_t z = 0; z < wfc.m_tiles.m_z; ++z)
	{
		uint16_t empty = 0;
		wfc.m_wave.set_tile({ uint(x), uint(y), uint(z) }, empty);
	}

	if(!m_center_block)
	{
		m_center_block = block;
		wfc.m_auto_solve = true;
		return;
	}

	bool positive = (bool)m_blocks[coord + ivec2(0, -1)];
	Tileblock& neighbour = positive ? *m_blocks[coord + ivec2(0, -1)] : *m_blocks[coord + ivec2(0, 1)];

	for(size_t x = 0; x < wfc.m_tiles.m_x; ++x)
	for(size_t y = 0; y < wfc.m_tiles.m_y; ++y)
	{
		size_t z = positive ? 0U : wfc.m_tiles.m_z - 1;
		size_t adjacent_z = positive ? wfc.m_tiles.m_z - 1 : 0U;
		uint16_t tile = neighbour.m_wfc_block.m_tiles.at(x, y, adjacent_z);
		wfc.m_wave.set_tile({ uint(x), uint(y), uint(z) }, tile);
	}

	wfc.m_wave.propagate();

	wfc.m_auto_solve = true;
}

void TileWorld::open_blocks(GfxSystem& gfx, const vec3& position, const ivec2& radius)
{
	ivec2 coord = ivec2(to_xz(position / m_block_size));

	for(int x = coord.x - radius.x; x < coord.x + radius.x + 1; ++x)
	for(int y = coord.y - radius.y; y < coord.y + radius.y + 1; ++y)
	{
		ivec2 neighbour = { x, y };
		if(!m_blocks[neighbour])
			this->generate_block(gfx, neighbour);
	}
}

Entity Bullet::create(ECS& ecs, HSpatial parent, const vec3& source, const quat& rotation, float velocity)
{
	Entity entity = ecs.create<Spatial, Bullet>();
	ecs.set(entity, Spatial(parent, source, rotation));
	ecs.set(entity, Bullet(HSpatial(entity), source, rotation, velocity));
	return entity;
}

Bullet::Bullet(HSpatial spatial, const vec3& source, const quat& rotation, float velocity)
	: m_spatial(spatial)
	, m_source(source)
	, m_velocity(rotate(rotation, -z3) * velocity)
	//, m_solid(Solid::create(m_spatial, *this, Sphere(0.1f), SolidMedium::me, CollisionGroup(energy), false, 1.f))
	, m_collider(Collider::create(m_spatial, HMovable(), Sphere(0.1f), SolidMedium::me, CM_SOLID))
{}

void Bullet::update()
{
	if(m_impacted)
		return;

	Spatial& spatial = m_spatial;
	Collider& collider = *m_collider;

	Collision collision = collider->raycast(spatial.m_position + m_velocity, CM_SOLID | CM_GROUND);
	HSpatial hit = collision.m_second ? collision.m_second->m_spatial : HSpatial();

	if(hit)
	{
		if(Human* shot = try_asa<Human>(hit))
		{
			Spatial& shot_spatial = shot->m_spatial;
			if(shot->m_shield && shot->m_energy > 0.f)
			{
				auto reflect = [](const vec3& I, const vec3& N) { return I - 2.f * dot(N, I) * N; };
				vec3 N = normalize(collision.m_hit_point - shot_spatial.m_position + y3);
				m_velocity = reflect(m_velocity, N);
				spatial.m_rotation = look_at(vec3(0.f), m_velocity);

				shot->m_energy -= 0.5f;
				shot->m_discharge += 0.5f;
			}
			else
			{
				m_impacted = true;
				m_impact = collision.m_hit_point;

				shot->damage(1.f);
			}
		}
	}

	if(distance(spatial.m_position, m_source) > 100.f)
		m_destroy = true;

	spatial.set_position(spatial.m_position + m_velocity);
	//m_collider.update_transform();
}

const vec3 Human::muzzle_offset = { 0.f, 1.6f, -1.f };
float Human::headlight_angle = 40.f;
//float Human::headlight_angle = 30.f;
//float Human::headlight_angle = 20.f;

Entity Human::create(ECS& ecs, HSpatial parent, const vec3& position, Faction faction)
{
	Entity entity = ecs.create<Spatial, Movable, Emitter, Receptor, EntityScript, Human>();
	ecs.set(entity, Spatial(parent, position, ZeroQuat));
	ecs.set(entity, Movable(position));
	ecs.set(entity, Emitter(HSpatial(entity)));
	ecs.set(entity, Receptor(HSpatial(entity)));
	ecs.set(entity, EntityScript(entity));
	ecs.set(entity, Human(entity, entity, entity, entity, entity, faction));
	return entity;
}

Human::Human(HSpatial spatial, HMovable movable, HEmitter emitter, HReceptor receptor, HEntityScript script, Faction faction)
	: m_spatial(spatial)
	, m_movable(movable)
	, m_emitter(emitter)
	, m_receptor(receptor)
	, m_script(script)
	, m_faction(faction)
	, m_walk(false)
	, m_solid(Solid::create(m_spatial, m_movable, CollisionShape(Capsule(0.35f, 1.1f), y3 * 0.9f), false, 1.f))
{
	emitter->add_sphere(VisualMedium::me, 0.1f);
	receptor->add_sphere(VisualMedium::me, 30.f);
}

void Human::next_frame(Spatial& spatial, Movable& movable, Receptor& receptor, size_t tick, size_t delta)
{
	UNUSED(tick);
	(*m_solid)->set_angular_factor(vec3(0.f));

	m_visor = this->aim();

	for(llong i = m_bullets.size() - 1; i >= 0; --i)
	{
		m_bullets[i]->update();
		if(m_bullets[i]->m_destroy)
			m_bullets.erase(m_bullets.begin() + i);
	}

	m_energy = min(1.f, m_energy + delta * 0.01f);
	m_discharge = max(0.f, m_discharge - delta * 0.05f);
	
	// @kludge in case that weird bug where we go through the scene geometry happens... put us back up
	if(spatial.m_position.y < -10.f)
		spatial.m_position.y = 10.f;

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
			bool disable = distance(((Spatial&)m_target->m_spatial).m_position, spatial.m_position) > 50.f;
			disable |= aim.hit && aim.hit != &(*m_target->m_spatial);
			disable |= m_target->m_life <= 0.f;
			if(disable)
				m_target = {};
		}

		if(!m_target)
		{
			ReceptorScope* vision = receptor.scope(VisualMedium::me);
			for(HSpatial seen : vision->m_scope)
				if(Human* human = try_asa<Human>(seen))
				{
					if(human->m_faction != m_faction)
					{
						vec3 direction = seen->m_position - spatial.m_position;
						float light = spot_attenuation(-direction, spatial.front(), 30.f, 0.5f, 0.9f, cos(to_radians(headlight_angle)));
						float visibility = light * (human->m_headlight ? 4.f : 0.5f);
						if(human->m_life > 0.f && (visibility > 0.2f || length(direction) < 4.f))
						{
							m_target = seen;
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
			spatial.set_rotation(look_at(x0z(spatial.m_position), x0z(m_target->m_spatial->m_position)));

			if(m_cooldown == 0.f)
			{
				this->shoot();
				m_cooldown = 1.f;
			}
		}
		else
		{
			auto is_walkable = [&](const vec3& pos) { return as<PhysicWorld>(spatial.m_world->m_complex).ground_point(to_ray(pos, -y3)) != vec3(0.f); };

			if(m_dest == vec3(0.f))
			{
				float amplitude = 10.f;
				m_dest = spatial.m_position + vec3(randf(-amplitude, amplitude), 0.f, randf(-amplitude, amplitude));
				if(!is_walkable(m_dest))
					m_dest = vec3(0.f);
			}

			if(m_dest != vec3(0.f))
			{
				if(steer_2d(spatial, movable, m_dest, 3.f, float(delta) * float(c_tick_interval), 1.f))
				{
					this->stop();
				}
				else
				{
					m_state = { m_walk ? "Walk" : "RunAim", true };
					movable.set_linear_velocity(movable.m_linear_velocity - y3 * 1.f);
				}
			}
		}
	}
}

quat Human::sight(bool aiming)
{
	Spatial& spatial = m_spatial;
	return aiming ? rotate(spatial.m_rotation, x3, m_angles.y) : spatial.m_rotation;
}

void Human::stop()
{
	Movable& movable = m_movable;
	m_state = { "IdleAim", true };
	movable.m_linear_velocity = vec3(0.f);
	m_dest = vec3(0.f);
}

Aim Human::aim()
{
	Spatial& spatial = m_spatial;
	quat rotation = this->sight(m_aiming);
	vec3 muzzle = spatial.m_position + rotate(spatial.m_rotation, Human::muzzle_offset);
	vec3 end = muzzle + rotate(rotation, -z3) * 1000.f;

	Collision hit = as<PhysicWorld>(spatial.m_world->m_complex).raycast({ muzzle, end }, CM_GROUND | CM_SOLID);
	Spatial* target = nullptr;//hit.m_second ? &((Spatial&)hit.m_second->m_spatial) : nullptr;
	return { rotation, muzzle, hit.m_second ? hit.m_hit_point : end, target };
}

void Human::shoot()
{
	Aim aim = this->aim();
	auto fuzz = [](const quat& rotation, const vec3& axis) { return rotate(rotation, axis, randf(-0.05f, 0.05f)); };
	quat rotation = fuzz(fuzz(aim.rotation, x3), y3);
	m_bullets.push_back(construct_owned<Bullet>(m_spatial, aim.start, rotation, 2.f));
	//m_solid->impulse(rotate(m_spatial.m_rotation, z3 * 4.f), vec3(0.f));
}

void Human::damage(float amount)
{
	Movable& movable = m_movable;
	m_life -= amount;
	if(m_life <= 0.f)
	{
		m_headlight = false;
		movable.m_linear_velocity = vec3(0.f);
	}
}

Entity Lamp::create(ECS& ecs, HSpatial parent, const vec3& position)
{
	Entity entity = ecs.create<Spatial, Movable, Lamp>();
	ecs.set(entity, Spatial(parent, position, ZeroQuat));
	ecs.set(entity, Movable(position));
	ecs.set(entity, Lamp(HSpatial(entity), HMovable(entity)));
	return entity;
}

Lamp::Lamp(HSpatial spatial, HMovable movable)
	: m_spatial(spatial)
	, m_movable(movable)
{}

Entity Crate::create(ECS& ecs, HSpatial parent, const vec3& position, const vec3& extents)
{
	Entity entity = ecs.create<Spatial, Movable, Crate>();
	ecs.set(entity, Spatial(parent, position, ZeroQuat));
	ecs.set(entity, Movable(position));
	ecs.set(entity, Crate(HSpatial(entity), HMovable(entity), extents));
	return entity;
}

Crate::Crate(HSpatial spatial, HMovable movable, const vec3& extents)
	: m_spatial(spatial)
	, m_movable(movable)
	, m_extents(extents)
	, m_solid(Solid::create(m_spatial, m_movable, Cube(extents), SolidMedium::me, CM_SOLID, false, 10.f))
{}

Player::Player(TileWorld& world)
	: m_world(&world)
{}

void Player::spawn(const vec3& start_position)
{
	HSpatial origin = m_world->m_world.origin();
	vec3 position = start_position + y3 * 2.f * m_world->m_center_block->m_wfc_block.m_scale.y;
	m_human = construct<Human>(origin, position, Faction::Ally);
	//m_human->m_headlight = false;
	m_human->m_stealth = true;
	m_human->m_walk = false;
	m_human->m_life = 5.f;
}

void paint_bullet(Gnode& parent, Bullet& bullet)
{
	Spatial& spatial = bullet.m_spatial;

	static Flow* flash = parent.m_scene->m_gfx.flows().file("flash");
	static Flow* impact = parent.m_scene->m_gfx.flows().file("impact");

	Gnode& source = gfx::node(parent, bullet.m_source, spatial.m_rotation);
	gfx::flows(source, *flash);

	//toy::sound(source, "rifle", false, 0.4f);
	toy::sound(source, "rifle2", false, 0.4f);

	if(!bullet.m_impacted)
	{
		Gnode& projectile = gfx::node(parent, spatial.m_position, spatial.m_rotation);
		gfx::shape(projectile, Cube(vec3(0.02f, 0.02f, 0.4f)), Symbol(Colour(2.f, 0.3f, 0.3f) * 4.f));
	}

	if(bullet.m_impacted)
	{
		Gnode& hit = gfx::node(parent, bullet.m_impact, spatial.m_rotation);
		toy::sound(source, "impact2", false, 0.4f);
		if(gfx::flows(hit, *impact).m_ended)
			bullet.m_destroy = true;
	}
}

void paint_lamp(Gnode& parent, Lamp& lamp)
{
	UNUSED(lamp);
	gfx::shape(parent, Sphere(0.1f), Symbol(Colour::Red), ItemFlag::Default | ItemFlag::Selectable);
	gfx::light(parent, LightType::Point, false, Colour(1.f, 0.3f, 0.2f), 10.f);
}

Material& highlight_material(const string& name, const Colour& colour, int factor)
{
	Material& material = Material::ms_gfx->fetch_material(name.c_str(), "pbr/pbr");
	material.m_pbr.m_albedo.m_value = Colour::Black;
	material.m_lit.m_emissive.m_value = colour;
	material.m_lit.m_emissive.m_value.a = float(factor);
	return material;
}

Model& human_model_glow(GfxSystem& gfx)
{
	//Material& glow_material = highlight_material("JointsGlow", Colour(0.2f, 0.8f, 2.4f), 2);
	static Material& glow_material = highlight_material("JointsGlow", Colour::Red, 4);
	static Model& human = *gfx.models().file("human00");
	static Model& model = model_variant(gfx, human, "human_glow", { "Joints" }, { &glow_material });
	return model;
}

Model& human_model_stealth(GfxSystem& gfx)
{
	static Material& stealth_material = highlight_material("JointsStealth", Colour(0.2f, 0.2f, 0.2f), 2);
	static Model& human = *gfx.models().file("human00");
	static Model& model = model_variant(gfx, human, "human_stealth", { "Joints" }, { &stealth_material });
	return model;
}

void paint_human(Gnode& parent, Human& human)
{
	const Spatial& spatial = human.m_spatial;

	static Model& model_normal = *parent.m_scene->m_gfx.models().file("human00");
	static Model& model_stealth = human_model_stealth(parent.m_scene->m_gfx);
	static Model& model_glow = human_model_glow(parent.m_scene->m_gfx);

	Model& model = human.m_stealth ? model_stealth : model_glow;
	
	Gnode& self = gfx::node(parent, spatial.m_position, spatial.m_rotation);
	self.m_node->m_object = human.m_spatial;

	Item& item = gfx::item(self, model, ItemFlag::Default | ItemFlag::Selectable);
	Mime& animated = gfx::animated(self, item);

	if(animated.m_playing.empty() || animated.playing() != human.m_state.name)
		animated.start(human.m_state.name.c_str(), human.m_state.loop, 0.f, human.m_walk ? 0.7f : 1.f);

	Node3* bone = animated.m_rig.m_skeleton.find_bone("RightHand");

	const mat4 pose = bxrotation(spatial.m_rotation) * fix_bone_pose(*bone);
	Gnode& arm = gfx::node(self, spatial.m_position + vec3(pose * vec4(vec3(0.f), 1.f)), spatial.m_rotation);
	gfx::model(arm, "rifle");

	enum States { Seek = 3, Dead = 4, Shield = 5, Headlight = 6, Visor = 7 };

	if(human.m_target)
	{
		Gnode& seek = gfx::node(parent.subx(Seek), spatial.m_position, spatial.m_rotation);
		toy::sound(seek, "destroy", false, 0.5f);
	}

	if(human.m_life <= 0.f)
	{
		Gnode& dead = gfx::node(parent.subx(Dead), spatial.m_position, spatial.m_rotation);
		//toy::sound(dead, "robotdeath", false, 0.1f);
		toy::sound(dead, "sparks", false, 0.1f);
	}

	if(human.m_shield)
	{
		auto shield_material = [&](Colour colour, float bias) -> Material&
		{
			Material& material = parent.m_scene->m_gfx.fetch_material("shield", "fresnel");
			material.m_fresnel.m_value.m_value = colour;
			material.m_fresnel.m_fresnel_bias = bias;
			//material.m_fresnel_block.m_value = parent.m_scene->m_gfx.textures().file("beehive.png");
			return material;
		};

		const Colour shield_colour = Colour(0.2f, 0.8f, 2.4f) * 4.f;
		static Material& shield = shield_material(shield_colour, 0.04f);

		static Clock clock;
		const float shield_intensity = remap_trig(sin(float(clock.read()) * 2.f), 0.3f, 1.4f) * (human.m_energy + human.m_discharge * 10.f);
		const float light_intensity = remap_trig(sin(float(clock.read()) * 2.f), 0.8f, 1.4f) * (human.m_energy + human.m_discharge * 5.f);
		
		shield.m_fresnel.m_value.m_value = shield_colour * shield_intensity;

		Gnode& center = gfx::node(parent.subx(Shield), spatial.m_position + rotate(spatial.m_rotation, y3), spatial.m_rotation);
		center.m_node->m_object = human.m_spatial;

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
		Gnode& headlight = gfx::node(parent.subx(Headlight), spatial.m_position + rotate(spatial.m_rotation, Human::muzzle_offset), human.sight());
		Light& light = gfx::light(headlight, LightType::Spot, false, Colour::White, 30.f);
		light.m_spot_angle = Human::headlight_angle;
		light.m_spot_attenuation = 0.9f;
	}

	if(human.m_faction == Faction::Ally)
	{
		Gnode& visor = gfx::node(parent.subx(Visor), spatial.m_position + rotate(spatial.m_rotation, Human::muzzle_offset), human.sight(human.m_aiming));
		//gfx::shape(visor, Line(-z3 * 4.f, -z3 * 8.f), Symbol(Colour(0.2f, 0.8f, 2.4f) * 4.f, Colour::None, true));
		gfx::shape(visor, Circle(-z3 * 8.f, 0.2f, Axis::Z), Symbol(Colour::None, Colour(0.2f, 0.8f, 2.4f) * 4.f, true));
	}
}

void paint_world_block(Gnode& parent, Tileblock& block, const uvec3* exclude = nullptr)
{
	if(!block.m_wfc_block.m_wave.m_solved) return;
	paint_tiles(parent, block.m_spatial, block.m_wfc_block, uvec3(UINT_MAX), exclude);
	WorldPage& world_page = block.m_world_page;
	if(world_page.m_updated > world_page.m_last_rebuilt)
	{
		build_block_geometry(*parent.m_scene, world_page, block);
		world_page.update_geometry(world_page.m_spatial->m_last_tick);
	}
}

void paint_crate(Gnode& parent, Crate& crate)
{
	static Material& material = gfx::pbr_material(parent.m_scene->m_gfx, "crate", Colour::White);
	gfx::shape(parent, Cube(crate.m_extents), Symbol(), ItemFlag::Default | ItemFlag::Selectable, &material);
}

void paint_scene(Gnode& parent)
{
	parent.m_scene->m_env.m_radiance.m_energy = 0.2f;
	parent.m_scene->m_env.m_radiance.m_ambient = Colour(0.04f);

	//gfx::radiance(parent, "radiance/tiber_1_1k.hdr", BackgroundMode::None);

	toy::sound(parent, "complexambient", true, 0.1f);
}

void paint_viewer(Viewer& viewer)
{
#if CLUSTERED
	viewer.m_viewport.set_clustered(viewer.m_scene->m_gfx);
#endif

	viewer.m_viewport.m_to_gamma = true;

	Tonemap& tonemap = viewer.m_viewport.comp<Tonemap>();
	tonemap.m_enabled = true;

	Glow& glow = viewer.m_viewport.comp<Glow>();
	glow.m_enabled = true;
#ifndef TWO_PLATFORM_EMSCRIPTEN
	glow.m_bicubic_filter = true;
#endif
}

vec3 find_fitting_player_location(WfcBlock& tileblock)
{
	vec3 center = vec3(tileblock.m_size) * 0.5f;
	vec3 start_coord = {};
	for(size_t i = 0; i < tileblock.m_tiles.size(); ++i)
		if(tileblock.m_tileset->m_tiles_flip[tileblock.m_tiles[i]].m_name == "empty_covered")
		{
			vec3 coord = vec3(uvec3(tileblock.m_tiles.x(i), tileblock.m_tiles.y(i), tileblock.m_tiles.z(i)));
			if(distance2(coord, center) < distance2(start_coord, center))
				start_coord = coord;
		}
	return tileblock.to_position(uvec3(start_coord));
}

Style& menu_style()
{
	static Style style = { "GameMenu", styles().wedge, [](Layout& l) { l.m_space = Preset::Unit; l.m_align = { Align::Left, Align::Center }; l.m_padding = vec4(120.f); l.m_padding.x = 300.f; l.m_spacing = vec2(30.f); } };
	return style;
}

Style& button_style()
{
	static Style style = { "GameButton", styles().button, [](Layout& l) { UNUSED(l); },
														  [](InkStyle& s) { s.m_empty = false; s.m_text_colour = Colour::AlphaWhite; s.m_text_size = 24.f; },
														  [](Style& s) { s.decline_skin(HOVERED).m_text_colour = Colour::White; } };
	return style;
}

Style& health_bar_style()
{
	static Style style = { "HealthBar", styles().filler, [](Layout& l) { l.m_space = { FlowAxis::Reading, Sizing::Wrap, Sizing::Fixed }; l.m_size = { 0.f, 10.f }; },
														 [](InkStyle& s) { s.m_empty = false; s.m_background_colour = Colour::Red; } };
	return style;
}

Style& energy_bar_style()
{
	static Style style = { "EnergyBar", styles().filler, [](Layout& l) { l.m_space = { FlowAxis::Reading, Sizing::Wrap, Sizing::Fixed }; l.m_size = { 0.f, 10.f }; },
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
	static Style style = { "GameScreen", styles().wedge, [](Layout& l) { l.m_space = Preset::Layout; l.m_padding = vec4(30.f); } };
	return style;
}

Style& left_panel_style(UiWindow& ui_window)
{
	UNUSED(ui_window);
	//static ImageSkin skin = { *ui_window.find_image("graphic/blue_on"), 46, 28, 38, 30 };
	
	static Style style = { "LeftPanel", styles().wedge, [](Layout& l) { l.m_space = { FlowAxis::Paragraph, Sizing::Wrap, Sizing::Fixed }; l.m_size = { 450.f, 0.f }; l.m_align = { Align::Left, Align::Center }; l.m_padding = vec4(30.f); l.m_spacing = vec2(30.f); } };
													   //[](InkStyle& s) { s.m_empty = false; s.m_image_skin = skin; } };
	return style;
}

void human_controller(HumanController& controller, Human& human, OrbitController& orbit, bool relative = true)
{
	Spatial& spatial = human.m_spatial;
	Solid& solid = human.m_solid;

	vec3 velocity = solid->linear_velocity();
	vec3 force = relative ? rotate(spatial.m_rotation, controller.m_force)
						  : rotate(quat(vec3(orbit.m_pitch, orbit.m_yaw, 0.f)), controller.m_force);

	solid->set_linear_velocity({ force.x, velocity.y - 1.f, force.z });
	solid->set_angular_velocity(controller.m_torque);
}

static void human_velocity_controller(Viewer& viewer, HumanController& controller, Human& human, OrbitController& orbit, bool relative = true)
{
	const float speed = viewer.ui().m_keyboard.m_shift ? 4.f : 15.f;
	ui::velocity_controller(viewer, controller.m_force, controller.m_torque, speed);

	if(viewer.key_event(Key::Space, EventType::Stroked))
		(*human.m_solid)->impulse(y3 * 20.f, vec3(0.f));

	if(controller.m_force != vec3(0.f) || controller.m_torque != vec3(0.f))
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
	Spatial& spatial = human.m_spatial;

	static Style& style_screen = screen_style();
	static Style& style_left_panel = left_panel_style(viewer.ui_window());

	//Widget& screen = ui::screen(viewer);
	Widget& screen = ui::widget(viewer, style_screen);

	ui::OrbitMode mode = val<Player>(scene.m_player).m_mode;
	//OrbitController& orbit = ui::orbit_controller(viewer);
	OrbitController& orbit = ui::hybrid_controller(viewer, mode, human.m_spatial, human.m_aiming, human.m_angles, scene.m_game.m_mode == GameMode::Play);

	Widget& board = ui::board(screen); UNUSED(board);
	Widget& row = ui::row(screen);
	Widget& left_panel = ui::widget(row, style_left_panel);

	static HumanController controller;

	if(human.m_life <= 0.f)
	{
		controller.m_force = vec3(0.f);
		controller.m_torque = vec3(0.f);
		human.m_state = { "Die", false };
	}

	if(human.m_life > 0.f)
	{
		human_velocity_controller(viewer, controller, human, orbit, mode != ui::OrbitMode::Isometric);

		if(mode == ui::OrbitMode::Isometric && controller.m_force != vec3(0.f))
			spatial.set_rotation(look_at(vec3(0.f), rotate(quat(vec3(0.f, orbit.m_yaw, 0.f)), controller.m_force)));

		if(viewer.mouse_event(DeviceType::MouseLeft, EventType::Stroked))
		{
			viewer.take_focus();
			human.shoot();
		}

		if(viewer.key_event(Key::LeftShift, EventType::Pressed))
			human.m_headlight = !human.m_headlight;

		if(viewer.key_event(Key::LeftControl, EventType::Pressed))
			human.m_shield = !human.m_shield;

		auto bar = [](Widget& parent, Style& style, cstring icon, float ratio)
		{
			UNUSED(ratio);
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

	//Viewer& debug_viewer = ui::viewer(self, scene.m_scene);
	//ui::orbit_controller(debug_viewer);

	Player& player = val<Player>(game.m_player);
	player.m_viewer = &viewer;
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
	
	static Model& human = human_model_glow(viewer.m_scene->m_gfx);
	static Clock clock;

	viewer.m_camera.m_eye = z3 * 2.f;

	Gnode& node = gfx::node(scene, -y3 * 0.5f + x3 * 0.6f, angle_axis(fmod(float(clock.read()), c_2pi), y3), vec3(1.f) * 0.5f);
	Item& item = gfx::item(node, human);
	Mime& animated = gfx::animated(node, item);
	 
	if(animated.m_playing.empty())
		animated.start("IdleAim", true, 0.f);

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
	Tileblock& block = *world.m_center_block;

	world.next_frame();

	Widget& self = ui::widget(parent, styles().board, &game);

	if(!player.m_human)
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

		Spatial& spatial = player.m_human->m_spatial;
		vec3 position = spatial.m_position;
		world.open_blocks(*app.m_gfx, position, { 0, 1 });
	}
}

class PlatformModule : public GameModule
{
public:
	PlatformModule(Module& module) : GameModule(module) {}

	virtual void init(GameShell& app, Game& game) final
	{
		UNUSED(game);
		app.m_gfx->add_resource_path("examples/ex_platform");
		app.m_gfx->add_resource_path("examples/05_character");
		app.m_gfx->add_resource_path("examples/17_wfc");

#ifdef SCRIPTED_IA
		LocatedFile location = app.m_gfx->locate_file("scripts/enemy_ai.lua");

		if(location)
		{
			TextScript& script = app.m_editor.m_script_editor.create_script("enemy_ai", Language::Lua);
			script.m_script = read_text_file(location.path(false));
		}
#endif
	}

	virtual void start(GameShell& app, Game& game) final
	{
		TileWorld& tileworld = global_pool<TileWorld>().construct("Arcadia", *app.m_job_system);
		World& world = tileworld.m_world;
		game.m_world = &world;

		world.add_loop<Tileblock, WorldPage>(Task::Spatial);
		world.add_loop<Human, Spatial, Movable, Receptor>(Task::GameObject);

		static Player player = { tileworld };
		game.m_player = Ref(&player);

		tileworld.generate_block(*app.m_gfx, ivec2(0));
	}

	virtual void scene(GameShell& app, GameScene& scene) final
	{
		UNUSED(app);
		//scene_painters(scene, vision.m_store);
		Player& player = val<Player>(scene.m_player);
		HSpatial reference = player.m_human->m_spatial;

		scene.painter("World", [&](size_t index, VisuScene& visu_scene, Gnode& parent) {
			UNUSED(visu_scene);
			Gnode& self = parent.subi((void*)index);
			paint_scene(self);
			//debug_draw_light_clusters(self, player.m_viewer->m_camera);
		});

		auto paint_hole_block = [&](Gnode& parent, Tileblock& block)
		{
#if 0 //ndef TWO_PLATFORM_EMSCRIPTEN
			if(block.contains(player.m_human->m_spatial.m_position))
			{
				// cut a hole of 6x6 tiles above the character
				uvec3 coord = block.m_wfc_block.to_coord(player.m_human->m_spatial.m_position);
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

		World& world = *scene.m_game.m_world;
		scene.range_entity_painter<Lamp>(reference, 100.f, "Lamps", world, paint_lamp);
		scene.range_entity_painter<Human>(reference, 100.f, "Humans", world, paint_human);
		scene.range_entity_painter<Crate>(reference, 100.f, "Crates", world, paint_crate);
		scene.range_entity_painter<Tileblock>(reference, 200.f, "Tileblocks", world, paint_hole_block);
		scene.range_entity_painter<Bullet>(reference, 100.f, "Bullets", world, paint_bullet);

		//physic_painter(scene);
	}

	virtual void pump(GameShell& app, Game& game, Widget& ui) final
	{
		auto pump = [&](Widget& parent, Dockbar* dockbar = nullptr)
		{
			UNUSED(dockbar);
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
	GameShell app(TOY_RESOURCE_PATH, exec_path(argc, argv).c_str());
	
	PlatformModule module = { _platform::m() };
	//app.run_game(module);
	app.run_editor(module);
}
#endif
