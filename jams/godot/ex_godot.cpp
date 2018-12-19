
#include <godot/ex_godot.h>
#include <toy/toy.h>

#include <godot/Api.h>
#include <meta/godot/Module.h>

//#define _GODOT_TOOLS
#ifndef MUD_PLATFORM_EMSCRIPTEN
//#define GI_PROBE
#define CLUSTERED
#endif
#define LIGHTMAPS
//#define REPACK
#define PHYSICS

static const vec3 c_start_pos = vec3(15.88f, -12.42f, 13.60f);
//static const vec3 c_start_pos = vec3(-87.15f, -1.15f, -46.15f);
//static const vec3 c_start_pos = vec3(-64.f,   -1.15f, -78.50f);

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

Entity Bullet::create(ECS& ecs, HSpatial parent, const vec3& source, const quat& rotation, float velocity)
{
	Entity entity = { ecs.CreateEntity<Spatial, Bullet>(), ecs.m_index };
	ecs.SetComponent(entity, Spatial(parent, source, rotation));
	ecs.SetComponent(entity, Bullet(HSpatial(entity), source, rotation, velocity));
	return entity;
}

Bullet::Bullet(HSpatial spatial, const vec3& source, const quat& rotation, float velocity)
	: m_spatial(spatial)
	, m_source(source)
	, m_velocity(rotate(rotation, -Z3) * velocity)
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
				vec3 N = normalize(collision.m_hit_point - shot_spatial.m_position + Y3);
				m_velocity = reflect(m_velocity, N);
				spatial.m_rotation = look_at(Zero3, m_velocity);

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
	Entity entity = { ecs.CreateEntity<Spatial, Movable, Emitter, Receptor, EntityScript, Human>(), ecs.m_index };
	ecs.SetComponent(entity, Spatial(parent, position, ZeroQuat));
	ecs.SetComponent(entity, Movable(HSpatial(entity)));
	ecs.SetComponent(entity, Emitter(HSpatial(entity)));
	ecs.SetComponent(entity, Receptor(HSpatial(entity)));
	ecs.SetComponent(entity, EntityScript(entity));
	ecs.SetComponent(entity, Human(entity, entity, entity, entity, entity, faction));
	return entity;
}

Human::Human(HSpatial spatial, HMovable movable, HEmitter emitter, HReceptor receptor, HEntityScript script, Faction faction)
	: m_spatial(spatial)
	, m_movable(movable)
	, m_emitter(emitter)
	, m_receptor(receptor)
	, m_script(script)
	, m_faction(faction)
	, m_solid(Solid::create(m_spatial, m_movable, CollisionShape(Capsule(0.35f, 1.1f), Y3 * 0.9f), false, 1.f))
	, m_walk(false)
{
	emitter->add_sphere(VisualMedium::me, 0.1f);
	receptor->add_sphere(VisualMedium::me, 30.f);
}

void Human::next_frame(Spatial& spatial, Movable& movable, Receptor& receptor, size_t tick, size_t delta)
{
	UNUSED(tick);
	(*m_solid)->set_angular_factor(Zero3);

	vec3 velocity = (*m_solid)->linear_velocity();

	m_visor = this->aim();

	for(int i = m_bullets.size() - 1; i >= 0; --i)
	{
		m_bullets[i]->update();
		if(m_bullets[i]->m_destroy)
			m_bullets.erase(m_bullets.begin() + i);
	}

	m_energy = min(1.f, m_energy + delta * 0.01f);
	m_discharge = max(0.f, m_discharge - delta * 0.05f);
	
	// @kludge in case that weird bug where we go through the scene geometry happens... put us back up
	if(spatial.m_position.y < -64.f)
		spatial.m_position = c_start_pos;

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
			bool disable = distance(m_target->m_spatial->m_position, spatial.m_position) > 50.f;
			disable |= aim.hit && aim.hit != &(*m_target->m_spatial);
			disable |= m_target->m_life <= 0.f;
			if(disable)
				m_target = nullptr;
		}

		if(m_target == nullptr)
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
			spatial.set_rotation(look_at(x0z(spatial.m_position), x0z(m_target->m_spatial->m_position)));

			if(m_cooldown == 0.f)
			{
				this->shoot();
				m_cooldown = 1.f;
			}
		}
		else
		{
			auto is_walkable = [&](const vec3& pos) { return as<PhysicWorld>(spatial.m_world->m_complex).ground_point(to_ray(pos, -Y3)) != Zero3; };

			if(m_dest == Zero3)
			{
				float amplitude = 10.f;
				m_dest = spatial.m_position + vec3(random_scalar(-amplitude, amplitude), 0.f, random_scalar(-amplitude, amplitude));
				if(!is_walkable(m_dest))
					m_dest = Zero3;
			}

			//(*m_solid)->set_linear_velocity(Zero3);
			//return;

			if(m_dest != Zero3)
			{
				if(steer_2d(spatial, movable, m_dest, 3.f, float(delta) * float(c_tick_interval), 1.f))
				{
					this->stop();
				}
				else
				{
					m_state = { m_walk ? "Walk" : "RunAim", true };
					movable.set_linear_velocity(movable.m_linear_velocity - Y3 * 1.f);
				}
			}
		}
	}
}

quat Human::sight(bool aiming)
{
	Spatial& spatial = m_spatial;
	return aiming ? rotate(spatial.m_rotation, X3, m_angles.y) : spatial.m_rotation;
}

void Human::stop()
{
	Movable& movable = m_movable;
	m_state = { "IdleAim", true };
	movable.m_linear_velocity = Zero3;
	m_dest = Zero3;
}

Aim Human::aim()
{
	Spatial& spatial = m_spatial;
	quat rotation = this->sight(m_aiming);
	vec3 muzzle = spatial.m_position + rotate(spatial.m_rotation, Human::muzzle_offset);
	vec3 end = muzzle + rotate(rotation, -Z3) * 1000.f;

	Collision hit = as<PhysicWorld>(spatial.m_world->m_complex).raycast({ muzzle, end }, CM_GROUND | CM_SOLID);
	Spatial* target = nullptr;//hit.m_second ? &((Spatial&)hit.m_second->m_spatial) : nullptr;
	return { rotation, muzzle, hit.m_second ? hit.m_hit_point : end, target };
}

void Human::shoot()
{
	Aim aim = this->aim();
	auto fuzz = [](const quat& rotation, const vec3& axis) { return rotate(rotation, axis, random_scalar(-0.05f, 0.05f)); };
	quat rotation = fuzz(fuzz(aim.rotation, X3), Y3);
	m_bullets.emplace_back(construct_owned<Bullet>(m_spatial, aim.start, rotation, 2.f));
	//m_solid->impulse(rotate(m_spatial.m_rotation, Z3 * 4.f), Zero3);
}

void Human::damage(float amount)
{
	Movable& movable = m_movable;
	m_life -= amount;
	if(m_life <= 0.f)
	{
		m_headlight = false;
		movable.m_linear_velocity = Zero3;
	}
}

Entity Lamp::create(ECS& ecs, HSpatial parent, const vec3& position)
{
	Entity entity = { ecs.CreateEntity<Spatial, Movable, Lamp>(), ecs.m_index };
	ecs.SetComponent(entity, Spatial(parent, position, ZeroQuat));
	ecs.SetComponent(entity, Movable(HSpatial(entity)));
	ecs.SetComponent(entity, Lamp(HSpatial(entity), HMovable(entity)));
	return entity;
}

Lamp::Lamp(HSpatial spatial, HMovable movable)
	: m_spatial(spatial)
	, m_movable(movable)
{}

Entity Crate::create(ECS& ecs, HSpatial parent, const vec3& position, const vec3& extents)
{
	Entity entity = { ecs.CreateEntity<Spatial, Movable, Crate>(), ecs.m_index };
	ecs.SetComponent(entity, Spatial(parent, position, ZeroQuat));
	ecs.SetComponent(entity, Movable(HSpatial(entity)));
	ecs.SetComponent(entity, Crate(HSpatial(entity), HMovable(entity), extents));
	return entity;
}

Crate::Crate(HSpatial spatial, HMovable movable, const vec3& extents)
	: m_spatial(spatial)
	, m_movable(movable)
	, m_extents(extents)
	, m_solid(Solid::create(m_spatial, m_movable, Cube(extents), SolidMedium::me, CM_SOLID, false, 10.f))
{}

Entity WorldBlock::create(ECS& ecs, HSpatial parent, const vec3& position, const vec3& extents)
{
	Entity entity = { ecs.CreateEntity<Spatial, WorldPage, Navblock, WorldBlock>(), ecs.m_index };
	ecs.SetComponent(entity, Spatial(parent, position, ZeroQuat));
	ecs.SetComponent(entity, WorldPage(HSpatial(entity), true, extents));
	ecs.SetComponent(entity, Navblock(HSpatial(entity), HWorldPage(entity), as<Navmesh>(parent->m_world->m_complex)));
	ecs.SetComponent(entity, WorldBlock(HSpatial(entity), HWorldPage(entity), HNavblock(entity), extents));
	return entity;
}

WorldBlock::WorldBlock(HSpatial spatial, HWorldPage world_page, HNavblock navblock, const vec3& extents)
	: m_spatial(spatial)
	, m_world_page(world_page)
	, m_navblock(navblock)
	, m_extents(extents)
{}

Player::Player(DefaultWorld& world)
	: m_world(&world)
{}

void Player::spawn(const vec3& start_position)
{
	HSpatial origin = m_world->m_world.origin();
	m_human = construct<Human>(origin, start_position, Faction::Ally);
	//m_human->m_headlight = false;
	m_human->m_stealth = true;
	m_human->m_walk = false;
	m_human->m_life = 5.f;
}

void paint_bullet(Gnode& parent, Bullet& bullet)
{
	Spatial& spatial = bullet.m_spatial;

	static ParticleGenerator* flash = parent.m_scene->m_gfx_system.particles().file("flash");
	static ParticleGenerator* impact = parent.m_scene->m_gfx_system.particles().file("impact");

	Gnode& source = gfx::node(parent, {}, bullet.m_source, spatial.m_rotation);
	gfx::particles(source, *flash);

	//toy::sound(source, "rifle", false, 0.4f);
	toy::sound(source, "rifle2", false, 0.4f);

	if(!bullet.m_impacted)
	{
		Gnode& projectile = gfx::node(parent, {}, spatial.m_position, spatial.m_rotation);
		gfx::shape(projectile, Cube(vec3(0.02f, 0.02f, 0.4f)), Symbol(Colour(2.f, 0.3f, 0.3f) * 4.f));
	}

	if(bullet.m_impacted)
	{
		Gnode& hit = gfx::node(parent, {}, bullet.m_impact, spatial.m_rotation);
		toy::sound(source, "impact2", false, 0.4f);
		if(gfx::particles(hit, *impact).m_ended)
			bullet.m_destroy = true;
	}
}

void paint_lamp(Gnode& parent, Lamp& lamp)
{
	UNUSED(lamp);
	gfx::shape(parent, Sphere(0.1f), Symbol(Colour::Red), ItemFlag::Default | ItemFlag::Selectable);
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
	Spatial& spatial = human.m_spatial;

	//static Model& model_normal = *parent.m_scene->m_gfx_system.models().file("human00");
	static Model& model_stealth = human_model_stealth(parent.m_scene->m_gfx_system);
	static Model& model_glow = human_model_glow(parent.m_scene->m_gfx_system);

	Model& model = human.m_stealth ? model_stealth : model_glow;
	
	Gnode& self = gfx::node(parent, Ref(&human), spatial.m_position, spatial.m_rotation);
	
	Item& item = gfx::item(self, model, ItemFlag::Default | ItemFlag::Selectable);
	Animated& animated = gfx::animated(self, item);

	if(animated.m_playing.empty() || animated.playing() != human.m_state.name)
		animated.play(human.m_state.name.c_str(), human.m_state.loop, 0.f, human.m_walk ? 0.7f : 1.f);

	Bone* bone = animated.m_rig.m_skeleton.find_bone("RightHand");

	mat4 pose = bxrotation(spatial.m_rotation) * fix_bone_pose(*bone);
	Gnode& arm = gfx::node(self, {}, spatial.m_position + vec3(pose * vec4(Zero3, 1.f)), spatial.m_rotation);
	gfx::model(arm, "rifle");

	enum States { Seek = 3, Dead = 4, Shield = 5, Headlight = 6, Visor = 7 };

	if(human.m_target)
	{
		Gnode& seek = gfx::node(parent.subx(Seek), Ref(&human), spatial.m_position, spatial.m_rotation);
		toy::sound(seek, "destroy", false, 0.5f);
	}

	if(human.m_life <= 0.f)
	{
		Gnode& dead = gfx::node(parent.subx(Dead), Ref(&human), spatial.m_position, spatial.m_rotation);
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
		float shield_intensity = remap_trig(sin(float(clock.read()) * 2.f), 0.3f, 1.4f) * (human.m_energy + human.m_discharge * 10.f);
		float light_intensity = remap_trig(sin(float(clock.read()) * 2.f), 0.8f, 1.4f) * (human.m_energy + human.m_discharge * 5.f);
		
		shield.m_fresnel_block.m_value.m_value = shield_colour * shield_intensity;

		Gnode& center = gfx::node(parent.subx(Shield), Ref(&human), spatial.m_position + rotate(spatial.m_rotation, Y3), spatial.m_rotation);
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
		Gnode& headlight = gfx::node(parent.subx(Headlight), Ref(&human), spatial.m_position + rotate(spatial.m_rotation, Human::muzzle_offset), human.sight());
		Light& light = gfx::light(headlight, LightType::Spot, false, Colour::White, 30.f);
		light.m_spot_angle = Human::headlight_angle;
		light.m_spot_attenuation = 0.9f;
	}

	if(human.m_faction == Faction::Ally)
	{
		Gnode& visor = gfx::node(parent.subx(Visor), Ref(&human), spatial.m_position + rotate(spatial.m_rotation, Human::muzzle_offset), human.sight(human.m_aiming));
		//gfx::shape(visor, Line(-Z3 * 4.f, -Z3 * 8.f), Symbol(Colour(0.2f, 0.8f, 2.4f) * 4.f, Colour::None, true));
		gfx::shape(visor, Circle(-Z3 * 8.f, 0.2f, Axis::Z), Symbol(Colour::None, Colour(0.2f, 0.8f, 2.4f) * 4.f, true));
	}
}

void paint_crate(Gnode& parent, Crate& crate)
{
	static Material& material = gfx::pbr_material(parent.m_scene->m_gfx_system, "crate", Colour::White);
	gfx::shape(parent, Cube(crate.m_extents), Symbol(), ItemFlag::Default | ItemFlag::Selectable, &material);
}

void paint_scene(Gnode& parent)
{
	parent.m_scene->m_environment.m_radiance.m_energy = 0.2f;
	parent.m_scene->m_environment.m_radiance.m_ambient = 0.04f;

	gfx::radiance(parent, "radiance/tiber_1_1k.hdr", BackgroundMode::None);

	//toy::sound(parent, "complexambient", true, 0.1f);
}

void paint_level(Gnode& parent)
{
#ifdef REPACK
	ImportConfig config;
	config.m_optimize_geometry = true;
	config.m_cache_geometry = true;
	config.m_flags = ItemFlag::Static;
	static Prefab& reactor = import_prefab(parent.m_scene->m_gfx_system, ModelFormat::gltf, "reactor", config);
#else
	ImportConfig config;
	config.m_flags = ItemFlag::Static;
	static Prefab& reactor = import_prefab(parent.m_scene->m_gfx_system, ModelFormat::gltf, "reactor.repack", config);
#endif
	gfx::prefab(parent, reactor, false, ItemFlag::NoUpdate);

#ifdef GI_PROBE
		GIProbe& probe = gfx::gi_probe(parent, 512U, vec3(128.f, 64.f, 128.f));
		//GIProbe& probe = gfx::gi_probe(parent, 512U, vec3(64.f, 32.f, 64.f));
		//probe.m_bounces = 1;
		probe.m_diffuse = 1.f;
		probe.m_mode = GIProbeMode::Voxelize;
		//probe.m_mode = GIProbeMode::LoadVoxels;
#endif

#ifdef LIGHTMAPS
#ifdef MUD_PLATFORM_EMSCRIPTEN
		string path = parent.m_scene->m_gfx_system.m_resource_path + "lightmaps/";
#else
		string path = parent.m_scene->m_gfx_system.m_resource_path + "examples/ex_godot/lightmaps/";
#endif

		LightmapAtlas& lightmap = gfx::lightmap(parent, 4096U, 4.f, path);
		lightmap.m_capture_transform = bxidentity();
		lightmap.m_capture_extents = vec3(128.f, 64.f, 128.f);
		//gfx::lightmap(parent, 4096U, 8.f, path);
#endif
}

void paint_viewer(Viewer& viewer)
{
#ifdef CLUSTERED
	if(rect_size(viewer.m_viewport.m_rect) != vec2(0.f) && !viewer.m_camera.m_clusters)
	{
		viewer.m_camera.m_clustered = true;
		viewer.m_camera.m_clusters = make_unique<Froxelizer>(viewer.m_scene->m_gfx_system);
		viewer.m_camera.m_clusters->prepare(viewer.m_viewport, viewer.m_camera.m_projection, viewer.m_camera.m_near, viewer.m_camera.m_far);
	}
#endif

	//viewer.m_filters.m_tonemap.m_mode = TonemapMode::ACES;

	viewer.m_filters.m_glow.m_enabled = true;
#ifndef MUD_GODOT_EMSCRIPTEN
	viewer.m_filters.m_glow.m_bicubic_filter = true;
#endif
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
		(*human.m_solid)->impulse(Y3 * 20.f, Zero3);

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

void ex_godot_game_hud(Viewer& viewer, GameScene& scene, Human& human)
{
	Spatial& spatial = human.m_spatial;

	//Widget& screen = ui::screen(viewer);
	Widget& screen = ui::board(viewer);

	ui::OrbitMode mode = val<Player>(scene.m_player).m_mode;
	//OrbitController& orbit = ui::orbit_controller(viewer);
	OrbitController& orbit = ui::hybrid_controller(viewer, mode, human.m_spatial, human.m_aiming, human.m_angles, scene.m_game.m_mode == GameMode::Play);

	if(scene.m_gfx_system.m_frame == 1)
	{
		orbit.m_pitch = -c_pi / 16.f;
		orbit.m_distance = 4.f;
	}

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
			spatial.set_rotation(look_at(Zero3, rotate(quat(vec3(0.f, orbit.m_yaw, 0.f)), controller.m_force)));

		if(viewer.mouse_event(DeviceType::MouseLeft, EventType::Stroked))
		{
			viewer.take_focus();
			human.shoot();
		}

		if(viewer.key_event(Key::LeftShift, EventType::Pressed))
			human.m_headlight = !human.m_headlight;

		if(viewer.key_event(Key::LeftControl, EventType::Pressed))
			human.m_shield = !human.m_shield;
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

void viewport_item_picker(Viewer& viewer, Widget& widget, std::vector<Item*>& selection)
{
	if(MouseEvent mouse_event = widget.mouse_event(DeviceType::Mouse, EventType::Moved, InputMod::None, false))
	{
		auto callback = [&](Item* item) { viewer.m_hovered = item; };
		viewer.picker(0).pick_point(viewer.m_viewport, mouse_event.m_relative, callback, ItemFlag::Static);
	}

	if(MouseEvent mouse_event = widget.mouse_event(DeviceType::MouseLeft, EventType::Stroked))
	{
		if(viewer.m_hovered)
		{
			bool shift = widget.ui().m_keyboard.m_shift;
			if(!shift)
				vector_select(selection, viewer.m_hovered);
			else
				vector_swap(selection, viewer.m_hovered);
		}
	}
}

void ex_godot_edit_ui(Viewer& viewer, GameScene& scene)
{
	ui::free_orbit_controller(viewer);
	return;

	static std::vector<Item*> selection;
	viewport_item_picker(viewer, viewer, selection);

	mat4 identity = bxidentity();
	for(Item* item : selection)
	{
		static const Colour colour = Colour::AlphaGrey;
		Gnode& n = gfx::node(scene.m_scene.m_graph, {}, item->m_node->m_transform);
		gfx::draw(n, item->m_model->m_aabb, Symbol::wire(colour, true));
		gfx::draw(scene.m_scene.m_graph, item->m_aabb, Symbol::wire(colour, true));
		//scene.m_scene.m_immediate->draw(identity, { Symbol::wire(colour, true), &item->m_aabb, OUTLINE });
	}
}

void ex_godot_game_ui(Widget& parent, Game& game, GameScene& scene)
{
	Viewer& viewer = ui::viewer(parent, scene.m_scene);
	paint_viewer(viewer);
	viewer.m_viewport.m_lighting = Lighting::VoxelGI;

	//Viewer& debug_viewer = ui::viewer(self, scene.m_scene);
	//ui::orbit_controller(debug_viewer);

	Player& player = val<Player>(game.m_player);
	player.m_viewer = &viewer;

	//ex_godot_edit_ui(viewer, scene);
	ex_godot_game_hud(viewer, scene, *player.m_human);
}

void ex_godot_pump_game(GameShell& app, Game& game, Widget& parent)
{
	Widget& self = ui::widget(parent, styles().board, &game);

	static GameScene& scene = app.add_scene();
	ex_godot_game_ui(self, game, scene);
}

class GodotModule : public GameModule
{
public:
	GodotModule(Module& module) : GameModule(module) {}

	virtual void init(GameShell& app, Game& game) final
	{
		UNUSED(game);
		//app.m_gfx_system->add_resource_path("examples/ex_godot_hd/");
		app.m_gfx_system->add_resource_path("examples/ex_godot/");
		app.m_gfx_system->add_resource_path("examples/05_character/");
		app.m_gfx_system->add_resource_path("examples/17_wfc/");

		this->start(app, game);
	}

	virtual void start(GameShell& app, Game& game) final
	{
		DefaultWorld& default_world = global_pool<DefaultWorld>().construct("Arcadia", *app.m_job_system);
		World& world = default_world.m_world;
		game.m_world = &world;

#ifdef PHYSICS
		WorldBlock& block = construct<WorldBlock>(world.origin(), Zero3, vec3(128.f, 64.f, 128.f));

		ImportConfig config;
		config.m_cache_geometry = true;
		Prefab& collision_world = import_prefab(*app.m_gfx_system, ModelFormat::gltf, "reactor.collision", config);

		std::vector<Item*> items;
		for(Item& item : collision_world.m_items)
			items.push_back(&item);

		build_world_page_geometry(block.m_world_page, items);
		block.m_world_page->update_geometry();

		destroy_prefab(*app.m_gfx_system, collision_world);
#endif

		world.m_ecs.AddBuffers<Spatial, WorldPage, Navblock, Sector>("Sector");

		world.m_ecs.AddBuffers<Spatial, Bullet>("Bullet");
		world.m_ecs.AddBuffers<Spatial, Movable, Emitter, Receptor, EntityScript, Human>("Human");
		world.m_ecs.AddBuffers<Spatial, Movable, Crate>("Crate");
		world.m_ecs.AddBuffers<Spatial, Movable, Lamp>("Lamp");

		world.add_loop<Human, Spatial, Movable, Receptor>(Task::GameObject);

		static Player player = { default_world };
		game.m_player = Ref(&player);

		player.spawn(c_start_pos);

		vec3 ennemies[] = {
			{ -12.50f, -12.41f, -15.06f },
			{ -64.31f,  -6.33f, -19.29f },
			{ -77.81f,  -6.37f, -43.68f },
			{ -25.99f,  -6.34f, -86.29f },
			{ -62.10f,  -1.15f, -75.88f },
		};

		HSpatial origin = world.origin();
		for(vec3 position : ennemies)
		{
			construct<Human>(origin, position, Faction::Enemy);
		}
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
			paint_level(self);
			//debug_draw_light_clusters(self, player.m_viewer->m_camera);
		});

		World& world = *scene.m_game.m_world;
		scene.range_entity_painter<Lamp>(reference, 100.f, "Lamps", world, paint_lamp);
		scene.range_entity_painter<Human>(reference, 100.f, "Humans", world, paint_human);
		scene.range_entity_painter<Crate>(reference, 100.f, "Crates", world, paint_crate);
		scene.range_entity_painter<Bullet>(reference, 100.f, "Bullets", world, paint_bullet);

		physic_painter(scene);
	}

	virtual void pump(GameShell& app, Game& game, Widget& ui) final
	{
#ifdef REPACK
		static bool repacked = false;
		if(app.m_gfx_system->m_frame > 100 && !repacked)
		{
			LocatedFile location = app.m_gfx_system->locate_file("models/reactor", carray<cstring, 1>{ ".gltf" });
			Importer& importer = *app.m_gfx_system->importer(ModelFormat::gltf);
			importer.repack((string(location.m_location) + location.m_name).c_str(), ImportConfig());
			repacked = true;
		}
#endif

		auto pump = [&](Widget& parent, Dockbar* dockbar = nullptr)
		{
			UNUSED(dockbar);
			ex_godot_pump_game(app, game, parent);
		};

#ifdef _GODOT_TOOLS
		edit_context(ui, app.m_editor, true);
		pump(*app.m_editor.m_screen, app.m_editor.m_dockbar);
#else
		pump(ui);
#endif
	}
};

#ifdef _EX_GODOT_EXE
int main(int argc, char *argv[])
{
	GameShell app(carray<cstring, 1>{ TOY_RESOURCE_PATH }, argc, argv);
	
	GodotModule module = { _godot::m() };
	app.run_game(module);
	//app.run_editor(module);
}
#endif
