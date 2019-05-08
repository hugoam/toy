#pragma once

#include <two/gfx.h>
#include <toy/visu.h>
#include <two/ui.h>
#include <two/geom.h>
#include <two/gfx.obj.h>
#include <two/gfx.gltf.h>
#include <two/pool.h>
#include <toy/core.h>
#include <two/srlz.h>
#include <two/uio.h>
#include <two/ctx.glfw.h>
#include <two/ui.vg.h>
#include <two/gfx.pbr.h>
#include <two/tree.h>
#include <two/lang.h>
#include <two/jobs.h>
#include <two/ecs.h>
#include <two/bgfx.h>
#include <two/frame.h>
#include <toy/edit.h>
#include <two/math.h>
#include <two/tool.h>
#include <two/refl.h>
#include <toy/block.h>
#include <two/ctx.h>
#include <two/gfx.ui.h>
#include <two/wfc.gfx.h>
#include <two/infra.h>
#include <two/type.h>




#ifndef TOY_SHELL_EXPORT
#define TOY_SHELL_EXPORT TWO_IMPORT
#endif

namespace toy
{
    enum class GameMode : int;
    
    
    class GameScene;
    class Game;
    class GameModule;
    class GameModuleBind;
    class GameShell;
	class GameWindow;
}






namespace two
{
	class Shell;
}

namespace toy
{
	class SqliteDatabase;
	
	class refl_ TOY_SHELL_EXPORT GameScene : public VisuScene
	{
	public:
		GameScene(User& user, GfxSystem& gfx, SoundManager* sound_system, Game& game, Ref player = {});
		~GameScene();

		Selection& m_selection;
		Game& m_game;
	};

	enum class refl_ GameMode
	{
		Play,
		PlayEditor,
		Pause,
	};

	class refl_ TOY_SHELL_EXPORT Game
	{
	public:
		Game(User& user, GfxSystem& gfx);
		~Game();

		GameScene& add_scene();

		attr_ User* m_user = nullptr;
		attr_ GameMode m_mode = GameMode::Play;
		attr_ GameShell* m_shell = nullptr;
		attr_ GameModule* m_module = nullptr;
		attr_ Ref m_player = {};
		attr_ World* m_world = nullptr;
		attr_ Widget* m_screen = nullptr;

		EditContext m_editor;

		vector<unique<GameScene>> m_scenes;
	};

	using GameCallback = void(*)(GameModule& module, GameShell& shell, Game& game);
	using SceneCallback = void(*)(GameModule& module, GameShell& shell, GameScene& scene);

	class refl_ TOY_SHELL_EXPORT GameModule
	{
	public:
		GameModule(Module& module) : m_module(&module) {}
		virtual ~GameModule() {}

		string m_module_path = "";
		Module* m_module = nullptr;

		meth_ virtual void init(GameShell& shell, Game& game) = 0;
		meth_ virtual void start(GameShell& shell, Game& game) = 0;
		meth_ virtual void pump(GameShell& shell, Game& game, Widget& ui) = 0;
		meth_ virtual void scene(GameShell& shell, GameScene& scene) { UNUSED(shell); UNUSED(scene); }
		meth_ virtual void paint(GameShell& shell, GameScene& scene, Gnode& graph) { UNUSED(shell); UNUSED(scene); UNUSED(graph); }
	};

	class refl_ TOY_SHELL_EXPORT GameModuleBind : public GameModule
	{
	public:
		/*constr_*/ GameModuleBind(Module& module, const VirtualMethod& call)
			: GameModule(module)
			, m_call(call)
		{}

		virtual void init(GameShell& app, Game& game) { Var params[2] = { Ref(&app), Ref(&game) }; m_call(method(&GameModule::init), Ref(this), { params, 2 }); }
		virtual void start(GameShell& app, Game& game) { Var params[2] = { Ref(&app), Ref(&game) }; m_call(method(&GameModule::start), Ref(this), { params, 2 }); }
		virtual void pump(GameShell& app, Game& game, Widget& ui) { Var params[3] = { Ref(&app), Ref(&game), Ref(&ui) }; m_call(method(&GameModule::pump), Ref(this), { params, 3 }); }
		virtual void scene(GameShell& app, GameScene& scene) { Var params[2] = { Ref(&app), Ref(&scene) }; m_call(method(&GameModule::scene), Ref(this), { params, 2 }); }
		virtual void paint(GameShell& app, GameScene& scene, Gnode& graph) { Var params[3] = { Ref(&app), Ref(&scene), Ref(&graph) }; m_call(method(&GameModule::paint), Ref(this), { params, 3 }); }

		VirtualMethod m_call;
	};

	TOY_SHELL_EXPORT Viewer& game_viewport(Widget& parent, GameScene& scene, HCamera camera, HMovable movable);
	TOY_SHELL_EXPORT func_ void paint_physics(Gnode& parent, World& world);
	TOY_SHELL_EXPORT func_ void physic_painter(GameScene& scene);

	class refl_ TOY_SHELL_EXPORT GameWindow : public GfxWindow
	{
	public:
		GameWindow(GfxSystem& gfx, uint32_t index, const string& name, const uvec2& size, bool fullscreen = false);

#if !GLOBAL_VG
		unique<Vg> m_vg = nullptr;
#endif

		attr_ uint32_t m_index = 0;
		attr_ UiWindow m_ui_window;
		attr_ Ui* m_ui = nullptr;

		//attr_ Context& context() { return *m_context; }
		//attr_ Vg& vg() { return *m_vg; }

		virtual bool begin_frame() override;
		virtual void render_frame() override;
		//virtual void end_frame() override;
	};

	class refl_ TOY_SHELL_EXPORT GameShell
	{
	public:
		constr_ GameShell(const string& resource_path, cstring exec_path = nullptr);
		~GameShell();

		meth_ void init(bool window);
		meth_ GameWindow& window(const string& name, const uvec2& size, bool fullscreen = false);

		meth_ void load(GameModule& module);
		meth_ void load_path(const string& module_path);
		meth_ void run(size_t iterations = 0U);
		meth_ void run_game(GameModule& module, size_t iterations = 0U);
		meth_ void run_editor(GameModule& module, size_t iterations = 0U);
		meth_ void run_game_path(const string& module_path, size_t iterations = 0U);
		meth_ void run_editor_path(const string& module_path, size_t iterations = 0U);
		meth_ void launch();
		meth_ void save();
		meth_ void reload();
		meth_ bool pump();
		meth_ void cleanup();

		meth_ GameWindow& main_window();

		void run_script(Module& module, const string& file, bool run = false);

		void reset_interpreters(bool reflect);

		void start_game();
		void frame_world();
		void frame_game();
		void frame_scenes();

		void pump_editor();
		void pump_game();

		void copy(const string& text);
		void paste(const string& text);

		meth_ GameScene& add_scene();
		meth_ void remove_scene(GameScene& scene);
		meth_ void clear_scenes();

		World& load_world(uint32_t id);
		void destroy_world();

		void time_entries(Widget& parent);

		attr_ Core& core() { return *m_core; }
		attr_ LuaInterpreter& lua() { return *m_lua; }
		attr_ WrenInterpreter& wren() { return *m_wren; }
		attr_ GfxSystem& gfx() { return *m_gfx; }
#ifdef TOY_SOUND
		attr_ SoundManager& sound() { return *m_sound_system; }
#endif

	public:
		string m_exec_path;
		string m_resource_path;

		User m_user;

		object<JobSystem> m_job_system;
		object<Core> m_core;
		object<LuaInterpreter> m_lua;
		object<WrenInterpreter> m_wren;
		object<GfxSystem> m_gfx;
#ifdef TOY_SOUND
		object<SoundManager> m_sound_system;
#endif

		vector<unique<GameWindow>> m_windows;

		attr_ Editor m_editor;
		bool m_mini_editor = false;

		unique<GameModule> m_game_module_alloc;

		GameModule* m_game_module = nullptr;
		Game m_game;

		function<void()> m_pump;

		enum class Step : unsigned int { Input = 0, Core, World, Game, Scene, UiRender, GfxRender, Count };
		table<Step, float> m_times = {};
	};

#ifdef TWO_PLATFORM_EMSCRIPTEN
	static GameShell* g_app = nullptr;
#endif
}

#ifdef TWO_PLATFORM_EMSCRIPTEN
extern "C"
{
	void copy(const char* text);
	void paste(const char* text);
}
#endif

#include <stdint.h>
#include <stl/string.h>
#include <stl/vector.h>

#if !defined TWO_MODULES || defined TWO_TYPE_LIB
#endif

#ifndef TWO_MODULES
#endif


namespace two
{
    // Exported types
    export_ template <> TOY_SHELL_EXPORT Type& type<toy::GameMode>();
    
    
    export_ template <> TOY_SHELL_EXPORT Type& type<toy::GameScene>();
    export_ template <> TOY_SHELL_EXPORT Type& type<toy::Game>();
    export_ template <> TOY_SHELL_EXPORT Type& type<toy::GameModule>();
    export_ template <> TOY_SHELL_EXPORT Type& type<toy::GameModuleBind>();
    export_ template <> TOY_SHELL_EXPORT Type& type<toy::GameWindow>();
    export_ template <> TOY_SHELL_EXPORT Type& type<toy::GameShell>();
}

