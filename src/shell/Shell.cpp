
#include <shell/Shell.h>

#include <toy/toy.h>
#include <toy/Modules.h>

#include <ui-vg/VgVg.h>

#include <edit/Edit/Viewport.h>

#if MUD_PLATFORM_EMSCRIPTEN
#include <emscripten/emscripten.h>
#endif

using namespace mud; namespace toy
{
#if MUD_PLATFORM_EMSCRIPTEN
	static GameShell* g_app = nullptr;
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

	Viewer& editor_viewport(Widget& parent, GameScene& scene)
	{
		Viewer& self = ui::viewer(parent, scene.m_scene);
		ui::free_orbit_controller(self);
		return self;
	}

	GameShell::GameShell(array<cstring> resource_paths, int argc, char *argv[])
		: m_exec_path(exec_path(argc, argv))
		, m_resource_path(resource_paths[0])
		, m_core(make_object<Core>())
		, m_interpreter()
		, m_gfx_system(make_object<GfxSystem>(resource_paths))
#ifdef TOY_SOUND
		, m_sound_system(make_object<SoundManager>(resource_paths[0]))
#endif
		, m_editor(*m_gfx_system)
		, m_game(m_user, *m_gfx_system)
	{
		System::instance().load_modules({ &mud_obj::m(), &mud_math::m(), &mud_geom::m(), &mud_procgen::m(), &mud_lang::m() });
		System::instance().load_modules({ &mud_ui::m(), &mud_gfx::m(), &mud_gfx_pbr::m(), &mud_gfx_obj::m(), &mud_gfx_gltf::m(), &mud_gfx_ui::m(), &mud_tool::m() });

		System::instance().load_modules({ &toy_util::m(), &toy_core::m(), &toy_visu::m(), &toy_block::m() });

		// @todo this should be automatically done by math module
		register_math_conversions();

		m_interpreter = make_object<LuaInterpreter>();
		m_editor.m_script_editor.m_interpreter = m_interpreter.get();

		m_game.m_shell = this;
		m_game.m_editor.m_script_editor.m_interpreter = m_interpreter.get();

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

	void GameShell::load(GameModule& game_module)
	{
		m_game.m_module = &game_module;
		m_game_module = &game_module;
		m_game_module->init(*this, m_game);

		System::instance().load_module(*game_module.m_module);

		m_interpreter->declare_types();
	}

	void GameShell::load(const string& module_name)
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
#endif
	}

	void GameShell::run_game(GameModule& module, size_t iterations)
	{
		this->load(module);
		//this->start_game();
		m_pump = [&]() { this->pump_game(); };
		this->run(iterations);
	}

	void GameShell::run_editor(GameModule& module, size_t iterations)
	{
		this->load(module);
		this->start_game();
		m_pump = [&]() { this->pump_editor(); };
		this->run(iterations);
	}

	void GameShell::run_game(const string& module_name, size_t iterations)
	{
		this->load(module_name);
		//this->start_game();
		m_pump = [&]() { this->pump_game(); };
		this->run(iterations);
	}

	void GameShell::run_editor(const string& module_path, size_t iterations)
	{
		this->load(module_path);
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
		bool pursue = m_ui_window->input_frame();
		m_core->next_frame();
		m_pump();
		m_ui_window->render_frame();
		pursue &= m_gfx_system->next_frame();
		return pursue;
	}

	void GameShell::start_game()
	{
		m_game_module->start(*this, m_game);
		m_game_module->pump(*this, m_game);
	}

	void GameShell::pump_game()
	{
		if(m_game.m_world)
			m_game.m_world->next_frame();
		m_game_module->pump(*this, m_game);
	}

	void GameShell::pump_editor()
	{
		Widget& ui = m_ui->begin();
		toy::editor(ui, m_editor);

		m_game.m_screen = m_editor.m_screen;
		m_editor.m_edited_world = m_game.m_world;

		if(m_editor.m_run_game)
		{
			if(m_game.m_world)
				m_game.m_world->next_frame();
			m_game_module->pump(*this, m_game);
			m_editor.m_viewer = nullptr;
		}
		else if(m_game.m_scenes.size() > 0 && m_game.m_screen)
		{
			m_game.m_scenes[0]->next_frame();
			m_editor.m_viewer = &editor_viewport(*m_game.m_screen, *m_game.m_scenes[0]);
		}

		if(m_editor.m_viewer)
		{
			paint_selection(m_editor.m_viewer->m_scene->m_graph, m_editor.m_selection);
			toy::editor_viewer_overlay(*m_editor.m_viewer, m_editor);
		}
	}

	GameScene& GameShell::add_scene()
	{
		GameScene& scene = m_game.add_scene();
		m_editor.m_scenes.push_back(&scene.m_scene);
		m_game_module->scene(*this, scene);
		return scene;
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
}
