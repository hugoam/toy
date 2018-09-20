#include <toy/toy.h>
#include <05_character/05_character.h>
#include <meta/05_character/Module.h>

Human::Human(HSpatial parent, const vec3& position, float radius, float height, const std::string& first_name, const std::string& last_name)
	: m_spatial(*this, *this, parent, position, ZeroQuat)
	, m_agent(*this, m_spatial, radius, height)
	, m_first_name(first_name)
	, m_last_name(last_name)
	, m_next_change(5.f)
	//, m_solid(make_unique<Solid>(m_spatial, *this, CollisionShape(Cylinder(0.35f, 2.f), Y3 * 1.f), SolidMedium::me, CM_SOLID, false, 1.f))
{
	//m_spatial.as<Active>().addState("idle", 1, 0.5f);

	m_states.push_back({ "Idle", 1.f });
}

Human::~Human()
{}

inline const std::vector<Ref>& indexed_objects(Type& type) { return indexer(type).m_objects; }

void Human::pumpSecond()
{}

void Human::next_frame(size_t tick, size_t delta)
{
	UNUSED(delta);
	//m_solid->m_impl->setForce(Zero3);
	//m_solid->m_impl->setTorque(Zero3);

	if((tick - m_last_tick) * c_tick_interval > 1.0f)
	{
		pumpSecond();
		m_last_tick = tick;
	}
}

bool Walk::checkAgent(const Entity& agent) { UNUSED(agent); return true; }
bool Walk::checkTarget(const Entity& target) { return target.m_hooked; }

Walk::Walk(toy::User* user, Entity& agent, Entity& target)
	: TypedAction(user, agent, target)
	, m_agent2(agent.as<Agent>())
	, m_range(0.02f)
{
	m_agent2.computePath(m_target.absolute_position());
}

void Walk::begin()
{
	//m_agent.as<Active>().addState("walk", 1, 0.5f);

	float dist = distance2(m_agent.m_position, m_target.m_position);
	if(dist < m_range)
		this->stop();
	else
		this->nextWaypoint();
}

void Walk::nextWaypoint()
{
	if(!m_agent2.popWaypoint())
		this->stop();
}

void Walk::update(size_t tick, double time_step)
{
	UNUSED(tick);
	vec3 target = m_agent2.m_waypoint;
	//bool done = steer_2d(m_agent, target, 1.f, float(time_step));
	bool done = steer_2d(m_agent.as<Movable>(), target, 1.f, float(time_step));
	if(done)
		this->nextWaypoint();
}

void Walk::abort()
{
	//m_agent.as<Active>().removeState("walk");
}

void paint_human(Gnode& parent, Human& human)
{
	Gnode& self = gfx::node(parent, Ref(&human), human.m_spatial.m_position, human.m_spatial.m_rotation);
	gfx::shape(self, Circle(0.35f), Symbol(), ITEM_SELECTABLE);
	Item* item = gfx::model(self, "human00", ITEM_SELECTABLE);
	Animated& animated = gfx::animated(self, *item);

	Human::State& state = human.m_states.back();
	if(animated.m_playing.empty() || animated.playing() != state.m_action)
		animated.play(state.m_action.c_str(), true, 0.f, state.m_action_speed);
}

Material& milky_white(GfxSystem& gfx_system, cstring name = "milky_white")
{
	Material& mat = gfx_system.fetch_material(name, "pbr/pbr");
	mat.m_pbr_block.m_enabled = true;
	mat.m_pbr_block.m_albedo.m_value = Colour::White;
	mat.m_pbr_block.m_metallic.m_value = 0.4f;
	mat.m_pbr_block.m_roughness.m_value = 0.35f;
	return mat;
}

struct KeyMove
{
	Key key;
	vec3 velocity;
	std::string action;
	float action_speed;
};

void human_control_key(Widget& widget, Human& human, vec3& speed, const KeyMove& move)
{
	if(widget.key_event(move.key, EventType::Pressed))
	{
		human.m_states.push_back({ move.action, move.action_speed });
		speed += move.velocity;
	}
	if(widget.key_event(move.key, EventType::Released))
	{
		vector_remove_if(human.m_states, [&](Human::State& state) { return state.m_action == move.action && state.m_action_speed == move.action_speed; });
		speed -= move.velocity;
	}
}

static void human_velocity_controller(Widget& widget, Human& human)
{
	bool shift = widget.ui().m_keyboard.m_shift;

	const KeyMove moves[4] =
	{
		{ Key::Up,   -Z3 * 2.f, "Walk",  1.f }, { Key::W,  -Z3 * 2.f, "Walk",  1.f },
		{ Key::Down,  Z3 * 2.f, "Walk", -1.f }, { Key::S,   Z3 * 2.f, "Walk", -1.f },
	};

	const KeyMove shift_moves[4] =
	{
		{ Key::Up,  -Z3 * 12.f, "Run",  1.f }, { Key::W, -Z3 * 12.f, "Run",  1.f },
		{ Key::Down, Z3 * 12.f, "Run", -1.f }, { Key::S,  Z3 * 12.f, "Run", -1.f },
	};

	for(const KeyMove& key_move : (shift ? shift_moves : moves))
		human_control_key(widget, human, human.m_movable.m_linear_velocity, key_move);

	const KeyMove rotations[4] =
	{
		{ Key::Right, -Y3 * 4.f, "Step",  1.f }, { Key::D, -Y3 * 4.f, "Step",  1.f },
		{ Key::Left,   Y3 * 4.f, "Step", -1.f }, { Key::A,  Y3 * 4.f, "Step", -1.f },
	};

	for(const KeyMove& key_rotation: rotations)
		human_control_key(widget, human, human.m_movable.m_angular_velocity, key_rotation);
}

void human_controller_3rdperson(Viewer& viewer, Human& human)
{
	human_velocity_controller(viewer, human);
}

class Ex05Character : public GameModule
{
public:
	Ex05Character(Module& module) : GameModule(module) {}

	virtual void init(GameShell& shell, Game& game) final
	{
		UNUSED(shell); UNUSED(game);
	}

	virtual void start(GameShell& shell, Game& game) final
	{
		UNUSED(shell);
		game.m_world = &global_pool<DefaultWorld>().construct("Arcadia").m_world;
	}

	virtual void pump(GameShell& app, Game& game, Widget& ui) final
	{
		if(!game.m_world)
			this->start(app, game);

		auto pump = [&](Widget& parent, Dockbar* dockbar = nullptr)
		{
			UNUSED(parent); UNUSED(dockbar);
			Widget& uroot = app.m_ui->begin();
			Widget& umain = ui::board(uroot);

			SceneViewer& viewer = ui::scene_viewer(umain);
			ui::orbit_controller(viewer);

			Gnode& groot = viewer.m_scene->begin();

			Material& material = milky_white(viewer.m_gfx_system);

			gfx::shape(groot, Rect(vec2{ -50.f, -50.f }, vec2{ 100.f }), Symbol(), 0U, &material);

			gfx::directional_light_node(groot);
			gfx::radiance(groot, "radiance/tiber_1_1k.hdr", BackgroundMode::None);

			static Human& character = construct<Human>(game.m_world->origin(), Zero3, 0.35f, 2.f, "Robert", "Citrus");
			paint_human(groot, character);

			human_controller_3rdperson(viewer, character);
			//orbit.set_target(character.m_spatial.m_position);
		};
		//edit_context(app.m_ui->begin(), app.m_editor, true);
		pump(ui, app.m_editor.m_dockbar);
	}

};

#ifdef __05_CHARACTER_EXE
int main(int argc, char *argv[])
{
	cstring example_path = TOY_RESOURCE_PATH "examples/ex_blocks/";
	cstring character_path = TOY_RESOURCE_PATH "examples/05_character/";
	GameShell app(carray<cstring, 3>{ TOY_RESOURCE_PATH, example_path, character_path }, argc, argv);
	
	system().load_module(_05_character::m());

	Ex05Character module = { _05_character::m() };
	app.run_game(module);
}
#endif
