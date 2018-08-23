
#include <shell/Shell.h>

#include <toy/toy.h>
#include <toy/Modules.h>

#include <ui-vg/VgVg.h>

#include <edit/Edit/Viewport.h>

#if MUD_PLATFORM_EMSCRIPTEN
#include <emscripten/emscripten.h>
#endif

#include <lang/Wren.h>

#include <numeric>
#include <deque>

class WrenVM;

using namespace mud; namespace toy
{
#if MUD_PLATFORM_EMSCRIPTEN
	static void iterate()
	{
		g_app->pump();
	}
#endif

	string exec_path(int argc, char *argv[])
	{
#ifdef _WIN32
		UNUSED(argc);
		string exec_path = argv[0];
		string exec_dir(exec_path.begin(), exec_path.begin() + exec_path.rfind('\\'));
#else
		UNUSED(argc); UNUSED(argv);
		string exec_dir = "./";
#endif
		return exec_dir;
	}

	struct SmoothTimer : public TimerBx
	{
		SmoothTimer(size_t num_frames) : m_num_frames(num_frames) {}

		size_t m_num_frames;
		std::deque<float> m_times;

		float read()
		{
			if(m_times.size() == m_num_frames)
				m_times.pop_front();
			m_times.push_back(this->end());
			return std::accumulate(m_times.begin(), m_times.end(), 0.f) / m_times.size();
		}
	};

	template <class T_Func>
	auto time(float* times, GameShell::Step step, cstring name, T_Func f)
	{
		UNUSED(name); static SmoothTimer timer = { 10 }; timer.begin(); f(); times[size_t(step)] = timer.read();
	}

	Game::Game(User& user, GfxSystem& gfx_system)
		: m_user(&user)
		, m_editor(gfx_system)
	{}

	Game::~Game()
	{}

	GameScene& Game::add_scene()
	{
#ifdef TOY_SOUND
		m_scenes.emplace_back(make_unique<GameScene>(*m_user, *m_shell->m_gfx_system, m_shell->m_sound_system.get(), *this, m_player));
#else
		m_scenes.emplace_back(make_unique<GameScene>(*m_user, *m_shell->m_gfx_system, nullptr, *this, m_player));
#endif
		return *m_scenes.back();
	}

	GameScene::GameScene(User& user, GfxSystem& gfx_system, SoundManager* sound_system, Game& game, Ref player)
		: VisuScene(gfx_system, sound_system)
		, m_selection(user.m_selection)
		, m_game(game)
	{
		m_player = player;
		m_scene.m_user = player;
	}

	GameScene::~GameScene()
	{}

	Viewer& game_viewport(Widget& parent, GameScene& scene, Camera& camera)
	{
		return scene_viewport(parent, scene, camera, scene.m_selection);
	}

	void paint_physics(Gnode& parent, World& world)
	{
		static PhysicDebugDraw physic_draw = { *parent.m_scene->m_immediate };
		physic_draw.draw_physics(parent, world, SolidMedium::me);
		//physic_draw.draw_physics(parent, world, VisualMedium::me);
	}

	void physic_painter(GameScene& scene)
	{
		scene.painter("PhysicsDebug", [&](size_t index, VisuScene& visu_scene, Gnode& parent) {
			UNUSED(index); UNUSED(visu_scene); paint_physics(parent, *scene.m_game.m_world);
		});
	}

	GameShell::GameShell(array<cstring> resource_paths, int argc, char *argv[])
		: m_exec_path(exec_path(argc, argv))
		, m_resource_path(resource_paths[0])
		, m_core(make_object<toy::Core>())
		, m_gfx_system(make_object<GfxSystem>(resource_paths))
#ifdef TOY_SOUND
		, m_sound_system(make_object<SoundManager>(resource_paths[0]))
#endif
		, m_editor(*m_gfx_system)
		, m_game(m_user, *m_gfx_system)
	{
		System::instance().load_modules({ &mud_infra::m(), &mud_obj::m(), &mud_pool::m(), &mud_refl::m(), &mud_proto::m(), &mud_tree::m() });
		System::instance().load_modules({ &mud_srlz::m(), &mud_math::m(), &mud_geom::m(), &mud_procgen::m(), &mud_lang::m() });
		System::instance().load_modules({ &mud_ctx::m(), &mud_ui::m(), &mud_gfx::m(), &mud_gfx_pbr::m(), &mud_gfx_obj::m(), &mud_gfx_gltf::m(), &mud_gfx_ui::m(), &mud_tool::m() });

		static Meta m = { type<VirtualMethod>(), &namspc({}), "VirtualMethod", sizeof(VirtualMethod), TypeClass::Object };
		static Class c = { type<VirtualMethod>(), {}, {}, {}, {}, {}, {}, {} };
		meta_class<VirtualMethod>();

		System::instance().load_modules({ &toy_util::m(), &toy_core::m(), &toy_visu::m(), &toy_block::m(), &toy_edit::m(), &toy_shell::m() });

		// @todo this should be automatically done by math module
		register_math_conversions();

		reset_interpreters(false);

		m_game.m_shell = this;

		this->init();
	}

	GameShell::~GameShell()
    {}

	void GameShell::init()
	{
#ifdef TOY_SOUND
		if(!m_sound_system->init())
		{
			printf("ERROR: Sound - failed to init\n");
		}
#endif
		//m_context = m_gfx_system->create_context("mud EditorCore", 1920, 1080, false);
		m_context = m_gfx_system->create_context("mud EditorCore", 1600, 900, false);
		//m_context = m_gfx_system.create_context("mud EditorCore", 1280, 720, false);
		GfxContext& context = as<GfxContext>(*m_context);

#if defined MUD_VG_VG
		m_vg = make_object<VgVg>(m_resource_path.c_str(), &m_gfx_system->m_allocator);
#elif defined MUD_VG_NANOVG
		m_vg = make_object<VgNanoBgfx>(m_resource_path.c_str());
#endif
		context.m_reset_vg = [&] { return m_vg->load_texture(context.m_target->m_diffuse.idx); };

		m_ui_window = make_unique<UiWindow>(*m_context, *m_vg);

		pipeline_pbr(*m_gfx_system, *m_gfx_system->m_pipeline);
		m_gfx_system->init_pipeline();

		static ImporterOBJ obj_importer(*m_gfx_system);
		static ImporterGltf gltf_importer(*m_gfx_system);

		string stylesheet = "minimal.yml";
		//string stylesheet = "vector.yml";
		//string stylesheet = "blendish_dark.yml";
		set_style_sheet(*m_ui_window->m_styler, (string(m_ui_window->m_resource_path) + "interface/styles/" + stylesheet).c_str());

		declare_gfx_edit();

		m_ui = m_ui_window->m_root_sheet.get();
	}

	void GameShell::reset_interpreters(bool reflect)
	{
		m_lua = make_object<LuaInterpreter>(false);
		m_wren = make_object<WrenInterpreter>(false);

		m_editor.m_script_editor.reset_interpreters(*m_lua, *m_wren);
		m_game.m_editor.m_script_editor.reset_interpreters(*m_lua, *m_wren);

		if(reflect)
		{
			m_lua->declare_types();
			m_wren->declare_types();
		}
	}

	void GameShell::load(GameModule& game_module)
	{
		m_game.m_module = &game_module;
		m_game_module = &game_module;
		m_game_module->init(*this, m_game);

		System::instance().load_module(*game_module.m_module);
	}

	void GameShell::load_path(const string& module_name)
	{
		Module* module = system().open_module((m_exec_path + "/" + module_name).c_str());
		if(module == nullptr)
		{
			printf("ERROR: could not locate/load module %s\n", module_name.c_str());
			return;
		}

		//GameCallback init  = (GameCallback)module_function(*module, (module_name + "_init").c_str());
		//GameCallback start = (GameCallback)module_function(*module, (module_name + "_start").c_str());
		//GameCallback pump  = (GameCallback)module_function(*module, (module_name + "_pump").c_str());
		//SceneCallback scene = (SceneCallback)module_function(*module, (module_name + "_scene").c_str());

		//m_game_module_alloc = make_unique<GameModule>(*module);

		//this->load(*m_game_module_alloc);
	}

	void GameShell::run(size_t iterations)
	{
#ifdef MUD_PLATFORM_EMSCRIPTEN
		g_app = this;
		//g_iterations = iterations;
		emscripten_set_main_loop(iterate, 0, 1);
#else
		size_t frame = 0;
		while(pump() && (iterations == 0 || frame++ < iterations));
			//std::this_thread::sleep_for(std::chrono::milliseconds(10));
#endif
	}

	void GameShell::run_game(GameModule& module, size_t iterations)
	{
		this->load(module);
		//this->start_game();
		m_pump = [&]() { this->pump_game(); };
		this->run(iterations);
	}

	void GameShell::run_script(Module& module, const string& file, bool run)
	{
		string path = "scripts/" + file;
		LocatedFile location = m_gfx_system->locate_file(path.c_str());

		if(location.m_name == nullptr)
			return;

		Signature signature = { { Param{ "app", Ref(type<GameShell>()) }, Param{ "module", Ref(type<Module>()) } } };

		TextScript& script = m_editor.m_script_editor.create_script(file.c_str(), Language::Wren, signature);
		script.m_script = read_text_file(std::string(location.m_location) + location.m_name);
		script.m_dirty = true;

		m_pump = [&]()
		{
			if(script.m_dirty)
			{
				this->reset_interpreters(true);
				this->clear_scenes();
				m_game.m_world = nullptr;

				if(m_editor.m_viewer)
					m_editor.m_viewer->m_viewport.m_active = false;

				Var args[2] = { Ref(this), Ref(&module) };
				script({ args, 2 });

				GameModuleBind* game_module = m_wren->tget<GameModuleBind>("game");
				if(game_module)
					this->load(*game_module);
				else
					m_game_module = nullptr;

				script.m_dirty = false;
			}

			//printf("\nframe\n\n");
			this->pump_editor();
			//this->pump_game();

			if(m_editor.m_viewer)
				m_editor.m_viewer->m_viewport.m_active = true;
		};

		//m_editor.m_run_game = run;
		m_editor.m_play_game = run;
		m_mini_editor = true;

		this->run(0);
	}

	void GameShell::run_editor(GameModule& module, size_t iterations)
	{
		this->load(module);
		this->start_game();
		m_pump = [&]() { this->pump_editor(); };
		this->run(iterations);
	}

	void GameShell::run_game_path(const string& module_name, size_t iterations)
	{
		this->load_path(module_name);
		//this->start_game();
		m_pump = [&]() { this->pump_game(); };
		this->run(iterations);
	}

	void GameShell::run_editor_path(const string& module_path, size_t iterations)
	{
		this->load_path(module_path);
		this->start_game();
		m_pump = [&]() { this->pump_editor(); };
		this->run(iterations);
	}

	void GameShell::launch()
	{
		string shell_path = m_exec_path + "/" + "shell";
		system().launch_process(shell_path.c_str(), m_game_module->m_module_path.c_str());
	}

	bool GameShell::pump()
	{
		static SmoothTimer timer = { 10 };
		timer.begin();

		bool pursue = true;
		for(float& time : m_times)
			time = 0.f;
		time(m_times, Step::Input,		"ui input",		[&] { pursue &= m_ui_window->input_frame(); });
		time(m_times, Step::Core,		"core",			[&] { m_core->next_frame(); });
		m_pump();
		time(m_times, Step::UiRender,	"ui render",	[&] { m_ui_window->render_frame(); });
		time(m_times, Step::GfxRender,	"gfx",			[&] { pursue &= m_gfx_system->next_frame(); });

		timer.end();

		return pursue;
	}

	void GameShell::start_game()
	{
		m_game_module->start(*this, m_game);
		this->pump_game();
	}

	void GameShell::frame_world()
	{
		if(m_game.m_world)
			m_game.m_world->next_frame();
	}

	void GameShell::frame_game()
	{
		if(m_game_module)
			m_game_module->pump(*this, m_game, m_game.m_screen ? *m_game.m_screen : m_ui->begin());
	}

	void GameShell::frame_scenes()
	{
		for(auto& scene : m_game.m_scenes)
			scene->next_frame();
	}

	void GameShell::pump_game()
	{
		time(m_times, Step::World, "world", [&] { this->frame_world(); });
		time(m_times, Step::Game, "game", [&] { this->frame_game(); });
		time(m_times, Step::Scene, "scenes", [&] { this->frame_scenes(); });
	}

	void GameShell::pump_editor()
	{
		m_editor.m_edited_world = m_game.m_world;

		//Widget& ui = m_ui->begin();
		Widget& ui = *m_ui;

		if(m_mini_editor)
			toy::mini_editor(ui, m_editor, m_game.m_screen);
		else
			toy::editor(ui, m_editor, m_game.m_screen);

		if(m_editor.m_run_game || m_editor.m_play_game)
			time(m_times, Step::World, "world", [&] { this->frame_world(); });
		if(m_editor.m_play_game)
			time(m_times, Step::Game, "game", [&] { this->frame_game(); });

		time(m_times, Step::Scene, "scenes", [&] { this->frame_scenes(); });

		m_ui->begin(); // well maybe we should call it end() then
	}

	GameScene& GameShell::add_scene()
	{
		GameScene& scene = m_game.add_scene();
		m_editor.m_scenes.push_back(&scene.m_scene);
		m_game_module->scene(*this, scene);
		scene.painter("Game", [&](size_t index, VisuScene& visu_scene, Gnode& parent) {
			UNUSED(index); UNUSED(visu_scene); UNUSED(parent); m_game_module->paint(*this, scene, parent);
		});
		return scene;
	}

	void GameShell::remove_scene(GameScene& scene)
	{}

	void GameShell::clear_scenes()
	{
		m_game.m_scenes.clear();
		m_editor.m_scenes.clear();
	}

	void GameShell::save()
	{
		pack_json_file(Ref(m_game.m_world), "");
	}

	World& GameShell::load_world(Id id)
	{
		Ref world;
		unpack_json_file(world, "");
		m_game.m_world = &val<World>(world);
		return val<World>(world);
	}

	void GameShell::destroy_world()
	{
		Complex& complex = m_game.m_world->m_complex;
		g_pools[complex.m_prototype.m_type.m_id]->destroy(Ref(&complex));
		m_game.m_world = nullptr;
	}

	void GameShell::reload()
	{
		Id id = m_game.m_world->m_id;
		this->save();
		this->destroy_world();

		m_game_module->m_module = &System::instance().reload_module(*m_game_module->m_module);

		m_game.m_world = &this->load_world(id);
	}

	void GameShell::cleanup()
	{
	}

	void GameShell::time_entries(Widget& parent)
	{
		auto entry = [](Widget& parent, cstring name, int value)
		{
			Widget& row = ui::row(parent);
			ui::label(row, name);
			ui::label(row, truncate_number(to_string(value)).c_str());
		};

		entry(parent, "ui input",	int(1000.f * m_times[size_t(Step::Input)]));
		entry(parent, "core",		int(1000.f * m_times[size_t(Step::Core)]));
		entry(parent, "world",		int(1000.f * m_times[size_t(Step::World)]));
		entry(parent, "game",		int(1000.f * m_times[size_t(Step::Game)]));
		entry(parent, "scenes",		int(1000.f * m_times[size_t(Step::Scene)]));
		entry(parent, "ui render",	int(1000.f * m_times[size_t(Step::UiRender)]));
		entry(parent, "gfx",		int(1000.f * m_times[size_t(Step::GfxRender)]));
	}

	void GameShell::copy(const string& text)
	{
		m_ui_window->m_clipboard = { text, false };
	}

	void GameShell::paste(const string& text)
	{
		m_ui_window->m_clipboard.m_pasted.push_back(text);
	}
}

#if MUD_PLATFORM_EMSCRIPTEN
extern "C"
{
	void copy(const char* text)
	{
		toy::g_app->copy(text);
	}

	void paste(const char* text)
	{
		toy::g_app->paste(text);
	}
}
#endif