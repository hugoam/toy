
#include <minimal/ex_minimal.h>
#include <toy/toy.h>

#include <minimal/Api.h>
#include <meta/minimal/Module.h>

Bullet::Bullet(Entity& parent, const vec3& source, const quat& rotation, float velocity)
	: Complex(0, type<Bullet>(), *this)
	, m_entity(0, *this, parent, source, rotation)
	, m_source(source)
	, m_velocity(rotate(rotation, -Z3) * velocity)
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
		m_impacted = true;
		m_impact = collision.m_hit_point;
	}

	if(distance(m_entity.m_position, m_source) > 100.f)
		m_destroy = true;

	m_entity.set_position(m_entity.m_position + m_velocity);
	//m_collider.update_transform();
}

const vec3 Human::muzzle_offset = { 0.f, 1.6f, -1.f };
float Human::headlight_angle = 40.f;

Human::Human(Id id, Entity& parent, const vec3& position)
	: Complex(id, type<Human>(), m_movable, *this)
	, m_entity(id, *this, parent, position, ZeroQuat)
	, m_movable(m_entity)
	, m_walk(false)
	, m_solid(m_entity, CollisionShape(Capsule(0.35f, 1.1f), Y3 * 0.9f), SolidMedium::me, CM_SOLID, false, 1.f)
{
	m_entity.m_world.add_task(this, short(Task::State)); // TASK_GAMEOBJECT
}

Human::~Human()
{
	m_entity.m_world.remove_task(this, short(Task::State));
}

void Human::next_frame(size_t tick, size_t delta)
{
	UNUSED(tick);
	m_solid->set_angular_factor(Zero3);

	for(auto& bullet : reverse_adapt(m_bullets))
	{
		bullet->update();
		if(bullet->m_destroy)
			vector_remove_pt(m_bullets, *bullet);
	}
}

quat Human::sight(bool aiming)
{
	return aiming ? rotate(m_entity.m_rotation, X3, m_angles.y) : m_entity.m_rotation;
}

Aim Human::aim()
{
	quat rotation = this->sight(m_aiming);
	vec3 source = m_entity.m_position + rotate(m_entity.m_rotation, Human::muzzle_offset);
	return { source, rotation };
}

void Human::shoot()
{
	Aim aim = this->aim();
	auto fuzz = [](const quat& rotation, const vec3& axis) { return rotate(rotation, axis, random_scalar(-0.05f, 0.05f)); };
	quat rotation = fuzz(fuzz(aim.rotation, X3), Y3);
	m_bullets.emplace_back(make_object<Bullet>(m_entity, aim.source, rotation, 2.f));
}

Crate::Crate(Id id, Entity& parent, const vec3& position, const vec3& extents)
	: Complex(id, type<Crate>(), m_movable, *this)
	, m_entity(id, *this, parent, position, ZeroQuat)
	, m_movable(m_entity)
	, m_extents(extents)
	, m_solid(m_entity, Cube(extents), SolidMedium::me, CM_SOLID, false, 10.f)
{}

Player::Player(World& world)
	: m_world(&world)
{
	m_human = &m_world->origin().construct<Human>(vec3(0.f));
	m_human->m_walk = false;
}

void paint_bullet(Gnode& parent, Bullet& bullet)
{
	static ParticleGenerator* flash = parent.m_scene->m_gfx_system.particles().file("flash");
	static ParticleGenerator* impact = parent.m_scene->m_gfx_system.particles().file("impact");

	Gnode& source = gfx::node(parent, {}, bullet.m_source, bullet.m_entity.m_rotation);
	gfx::particles(source, *flash);

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

void paint_human(Gnode& parent, Human& human)
{
	static Model& model = *parent.m_scene->m_gfx_system.models().file("human00");

	Gnode& self = gfx::node(parent, Ref(&human), human.m_entity.m_position, human.m_entity.m_rotation);
	
	Item& item = gfx::item(self, model);
	Animated& animated = gfx::animated(self, item);

	if(animated.m_playing.empty() || animated.playing() != human.m_state.name)
		animated.play(human.m_state.name.c_str(), human.m_state.loop, 0.f, human.m_walk ? 0.7f : 1.f);

	Bone* bone = animated.m_rig.m_skeleton.find_bone("RightHand");

	mat4 pose = bxrotation(human.m_entity.m_rotation) * fix_bone_pose(*bone);
	Gnode& arm = gfx::node(self, {}, human.m_entity.m_position + vec3(pose * vec4(Zero3, 1.f)), human.m_entity.m_rotation);
	gfx::model(arm, "rifle");
}

Material& plain_material(GfxSystem& gfx_system, cstring name, const Colour& colour)
{
	Material& material = gfx_system.fetch_material("crate", "pbr/pbr");
	material.m_pbr_block.m_enabled = true;
	material.m_pbr_block.m_albedo.m_value = colour;
	return material;
}

void paint_crate(Gnode& parent, Crate& crate)
{
	static Material& material = plain_material(parent.m_scene->m_gfx_system, "crate", Colour::White);
	gfx::shape(parent, Cube(crate.m_extents), Symbol(), 0U, &material);
}

void paint_scene(Gnode& parent)
{
	gfx::directional_light_node(parent);
	gfx::radiance(parent, "radiance/tiber_1_1k.hdr", BackgroundMode::None);
}

void ex_minimal_scene(GameShell& app, GameScene& scene)
{
	static OmniVision vision = { *scene.m_game.m_world };

	scene.painter("World", [&](size_t index, VisuScene& scene, Gnode& parent) {
		UNUSED(scene); paint_scene(parent.subi((void*)index));
	});
	
	scene.entity_painter<Human>("Humans", vision.m_store, paint_human);
	scene.entity_painter<Crate>("Crates", vision.m_store, paint_crate);
	scene.entity_painter<Bullet>("Bullets", vision.m_store, paint_bullet);
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
	struct KeyMove { Key key; vec3 force; };

	auto movement_key = [](Widget& widget, vec3& force, vec3& torque, const KeyMove& move, float speed)
	{
		if(widget.key_event(move.key, EventType::Pressed))
			force += move.force * speed;
		if(widget.key_event(move.key, EventType::Released))
			force -= move.force * speed;
	};

	bool shift = viewer.ui().m_keyboard.m_shift;

	const KeyMove moves[8] =
	{
		{ Key::Up,    -Z3 }, { Key::W, -Z3 },
		{ Key::Down,   Z3 }, { Key::S,  Z3 },
		{ Key::Left,	-X3 }, { Key::A, -X3 },
		{ Key::Right,  X3 }, { Key::D,  X3 },
	};

	const float speed = viewer.ui().m_keyboard.m_shift ? 4.f : 15.f;

	for(const KeyMove& key_move : moves)
		movement_key(viewer, controller.m_force, controller.m_torque, key_move, speed);

	if(viewer.key_event(Key::Space, EventType::Stroked))
		human.m_solid->impulse(Y3 * 16.f, Zero3);

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

void ex_minimal_game_hud(Viewer& viewer, GameScene& scene, Human& human)
{
	ui::OrbitMode mode = ui::OrbitMode::ThirdPerson;

	OrbitController& orbit = ui::hybrid_controller(viewer, ui::OrbitMode::ThirdPerson, human.m_entity, human.m_aiming, human.m_angles);

	static HumanController controller;

	human_velocity_controller(viewer, controller, human, orbit, mode != ui::OrbitMode::Isometric);

	if(mode == ui::OrbitMode::Isometric && controller.m_force != Zero3)
		human.m_entity.set_rotation(look_at(Zero3, rotate(quat(vec3(0.f, orbit.m_yaw, 0.f)), controller.m_force)));

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
		app.m_gfx_system->add_resource_path("examples/ex_minimal/");
		app.m_gfx_system->add_resource_path("examples/05_character/");

		global_pool<Human>();
		global_pool<Crate>();
	}

	virtual void start(GameShell& app, Game& game) final
	{
		DefaultWorld& world = global_pool<DefaultWorld>().construct("Arcadia");
		game.m_world = &world.m_world;

		static Player player = { *game.m_world };
		game.m_player = Ref(&player);
	}

	virtual void pump(GameShell& app, Game& game, Widget& ui) final
	{
		if(!game.m_world)
			this->start(app, game);

		auto pump = [&](Widget& parent, Dockbar* dockbar = nullptr)
		{
			static GameScene& scene = app.add_scene();
			Viewer& viewer = ui::viewer(parent, scene.m_scene);
			viewer.m_filters.m_glow.m_enabled = true;

			Player& player = val<Player>(game.m_player);
			ex_minimal_game_hud(viewer, scene, *player.m_human);
		};

		pump(ui);
	}
};

#ifdef _EX_MINIMAL_EXE
int main(int argc, char *argv[])
{
	GameShell app(carray<cstring, 1>{ TOY_RESOURCE_PATH }, argc, argv);
	
	ExMinimal module = { _minimal::m() };
	app.run_game(module);
}
#endif
