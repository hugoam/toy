
#include <minimal/ex_minimal.h>
#include <toy/toy.h>

#include <minimal/Api.h>
#include <meta/_minimal.meta.h>

Entity Bullet::create(ECS& ecs, HSpatial parent, const vec3& source, const quat& rotation, float velocity)
{
	Entity entity = ecs.create<Spatial, Bullet>();
	asa<Spatial>(entity) = Spatial(parent, source, rotation);
	asa<Bullet>(entity) = Bullet(HSpatial(entity), source, rotation, velocity);
	return entity;
}

Bullet::Bullet(HSpatial spatial, const vec3& source, const quat& rotation, float velocity)
	: m_spatial(spatial)
	, m_source(source)
	, m_velocity(rotate(rotation, -z3) * velocity)
	, m_collider(Collider::create(m_spatial, HMovable(), Sphere(0.1f), SolidMedium::me, CM_SOLID))
{}

void Bullet::update()
{
	if(m_impacted)
		return;

	Collision collision = (*m_collider)->raycast(m_spatial->m_position + m_velocity, CM_SOLID | CM_GROUND);
	HSpatial hit = collision.m_second ? collision.m_second->m_spatial : HSpatial();

	if(Human* shot = try_asa<Human>(hit))
	{
		m_impacted = true;
		m_impact = collision.m_hit_point;
	}

	if(distance(m_spatial->m_position, m_source) > 100.f)
		m_destroy = true;

	m_spatial->set_position(m_spatial->m_position + m_velocity);
	//m_collider.update_transform();
}

const vec3 Human::muzzle_offset = { 0.f, 1.6f, -1.f };
float Human::headlight_angle = 40.f;

Entity Human::create(ECS& ecs, HSpatial parent, const vec3& position)
{
	Entity entity = ecs.create<Spatial, Movable, Human>();
	ecs.set(entity, Spatial(parent, position, ZeroQuat));
	ecs.set(entity, Movable(position));
	ecs.set(entity, Human(entity, entity));
	return entity;
}

Human::Human(HSpatial spatial, HMovable movable)
	: m_spatial(spatial)
	, m_movable(movable)
	, m_walk(false)
	, m_solid(Solid::create(m_spatial, m_movable, CollisionShape(Capsule(0.35f, 1.1f), y3 * 0.9f), SolidMedium::me, CM_SOLID, false, 1.f))
{}

void Human::next_frame(Spatial& spatial, size_t tick, size_t delta)
{
	UNUSED(spatial); UNUSED(tick); UNUSED(delta);
	(*m_solid)->set_angular_factor(vec3(0.f));

	for(llong i = m_bullets.size() - 1; i >= 0; --i)
	{
		m_bullets[i]->update();
		if(m_bullets[i]->m_destroy)
			m_bullets.erase(m_bullets.begin() + i);
	}
}

quat Human::sight(bool aiming)
{
	Spatial& spatial = m_spatial;
	return aiming ? rotate(spatial.m_rotation, x3, m_angles.y) : spatial.m_rotation;
}

Aim Human::aim()
{
	Spatial& spatial = m_spatial;
	quat rotation = this->sight(m_aiming);
	vec3 source = spatial.m_position + rotate(spatial.m_rotation, Human::muzzle_offset);
	return { source, rotation };
}

void Human::shoot()
{
	Aim aim = this->aim();
	auto fuzz = [](const quat& rotation, const vec3& axis) { return rotate(rotation, axis, randf(-0.05f, 0.05f)); };
	quat rotation = fuzz(fuzz(aim.rotation, x3), y3);
	m_bullets.push_back(construct_owned<Bullet>(m_spatial, aim.source, rotation, 2.f));
}

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

Player::Player(World& world)
	: m_world(&world)
{
	m_human = construct<Human>(m_world->origin(), vec3(0.f));
	m_human->m_walk = false;
}

void paint_bullet(Gnode& parent, Bullet& bullet)
{
	Spatial& spatial = bullet.m_spatial;

	static Flow* flash = parent.m_scene->m_gfx.flows().file("flash");
	static Flow* impact = parent.m_scene->m_gfx.flows().file("impact");

	Gnode& source = gfx::node(parent, bullet.m_source, spatial.m_rotation);
	gfx::flows(source, *flash);

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

void paint_human(Gnode& parent, Human& human)
{
	static Model& model = *parent.m_scene->m_gfx.models().file("human00");

	Spatial& spatial = human.m_spatial;

	Gnode& self = gfx::node(parent, spatial.m_position, spatial.m_rotation);
	self.m_node->m_object = human.m_spatial;

	Item& item = gfx::item(self, model);
	Mime& animated = gfx::animated(self, item);

	if(animated.m_playing.empty() || animated.playing() != human.m_state.name)
		animated.start(human.m_state.name.c_str(), human.m_state.loop, 0.f, human.m_walk ? 0.7f : 1.f);

	Node3* bone = animated.m_rig.m_skeleton.find_bone("RightHand");

	mat4 pose = bxrotation(spatial.m_rotation) * fix_bone_pose(*bone);
	Gnode& arm = gfx::node(self, spatial.m_position + vec3(pose * vec4(vec3(0.f), 1.f)), spatial.m_rotation);
	gfx::model(arm, "rifle");
}

void paint_crate(Gnode& parent, Crate& crate)
{
	static Material& material = gfx::pbr_material(parent.m_scene->m_gfx, "crate", Colour::White);
	gfx::shape(parent, Cube(crate.m_extents), Symbol(), 0U, &material);
}

void paint_scene(Gnode& parent)
{
	gfx::direct_light_node(parent);
	gfx::radiance(parent, "radiance/tiber_1_1k.hdr", BackgroundMode::None);
}

void ex_minimal_scene(GameShell& app, GameScene& scene)
{
	UNUSED(app);
	scene.painter("World", [&](size_t index, VisuScene& scene, Gnode& parent) {
		UNUSED(scene); paint_scene(parent.subi((void*)index));
	});

	World& world = *scene.m_game.m_world;
	scene.entity_painter<Human>("Humans", world, paint_human);
	scene.entity_painter<Crate>("Crates", world, paint_crate);
	scene.entity_painter<Bullet>("Bullets", world, paint_bullet);
}

void human_controller(HumanController& controller, Human& human, OrbitController& orbit, bool relative = true)
{
	Solid& solid = human.m_solid;
	vec3 velocity = solid->linear_velocity();
	vec3 force = relative ? rotate(human.m_spatial->m_rotation, controller.m_force)
						  : rotate(quat(vec3(orbit.m_pitch, orbit.m_yaw, 0.f)), controller.m_force);

	solid->set_linear_velocity({ force.x, velocity.y - 1.f, force.z });
	solid->set_angular_velocity(controller.m_torque);
}

static void human_velocity_controller(Viewer& viewer, HumanController& controller, Human& human, OrbitController& orbit, bool relative = true)
{
	struct KeyMove { Key key; vec3 force; };

	auto movement_key = [](Widget& widget, vec3& force, vec3& torque, const KeyMove& move, float speed)
	{
		UNUSED(torque);
		if(widget.key_event(move.key, EventType::Pressed))
			force += move.force * speed;
		if(widget.key_event(move.key, EventType::Released))
			force -= move.force * speed;
	};

	const KeyMove moves[8] =
	{
		{ Key::Up,    -z3 }, { Key::W, -z3 },
		{ Key::Down,   z3 }, { Key::S,  z3 },
		{ Key::Left,  -x3 }, { Key::A, -x3 },
		{ Key::Right,  x3 }, { Key::D,  x3 },
	};

	const float speed = viewer.ui().m_keyboard.m_shift ? 4.f : 15.f;

	for(const KeyMove& key_move : moves)
		movement_key(viewer, controller.m_force, controller.m_torque, key_move, speed);

	if(viewer.key_event(Key::Space, EventType::Stroked))
		(*human.m_solid)->impulse(y3 * 16.f, vec3(0.f));

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

void ex_minimal_game_hud(Viewer& viewer, GameScene& scene, Human& human)
{
	UNUSED(scene);
	ui::OrbitMode mode = ui::OrbitMode::ThirdPerson;

	OrbitController& orbit = ui::hybrid_controller(viewer, ui::OrbitMode::ThirdPerson, human.m_spatial, human.m_aiming, human.m_angles);

	static HumanController controller;

	human_velocity_controller(viewer, controller, human, orbit, mode != ui::OrbitMode::Isometric);

	if(mode == ui::OrbitMode::Isometric && controller.m_force != vec3(0.f))
		human.m_spatial->set_rotation(look_at(vec3(0.f), rotate(quat(vec3(0.f, orbit.m_yaw, 0.f)), controller.m_force)));

	if(viewer.mouse_event(DeviceType::MouseLeft, EventType::Stroked))
	{
		viewer.take_modal();
		human.shoot();
	}
}

class ExMinimal : public GameModule
{
public:
	ExMinimal(Module& module) : GameModule(module) {}

	virtual void init(GameShell& app, Game& game) final
	{
		UNUSED(game);
		app.m_gfx->add_resource_path("examples/ex_minimal");
		app.m_gfx->add_resource_path("examples/05_character");
	}

	virtual void start(GameShell& app, Game& game) final
	{
		UNUSED(app);
		DefaultWorld& default_world = global_pool<DefaultWorld>().construct("Arcadia", *app.m_job_system);
		World& world = default_world.m_world;
		game.m_world = &world;

		static Player player = { *game.m_world };
		game.m_player = Ref(&player);
	}

	virtual void pump(GameShell& app, Game& game, Widget& ui) final
	{
		if(!game.m_world)
			this->start(app, game);

		auto pump = [&](Widget& parent, Dockbar* dockbar = nullptr)
		{
			UNUSED(dockbar);
			static GameScene& scene = app.add_scene();
			Viewer& viewer = ui::viewer(parent, scene.m_scene);
			viewer.m_viewport.comp<Glow>().m_enabled = true;

			Player& player = val<Player>(game.m_player);
			ex_minimal_game_hud(viewer, scene, *player.m_human);
		};

		pump(ui);
	}
};

#ifdef _EX_MINIMAL_EXE
int main(int argc, char *argv[])
{
	GameShell app(TOY_RESOURCE_PATH, exec_path(argc, argv).c_str());
	
	ExMinimal module = { _minimal::m() };
	app.run_game(module);
}
#endif
