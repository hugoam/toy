
#pragma once

#include <tree/Node.h>
#include <refl/System.h>
#include <refl/Class.h>
#include <shell/Forward.h>
#include <core/Player/Player.h>

#include <edit/Editor/Editor.h>
#include <lang/Lua.h>
#include <lang/Wren.h>

#include <visu/VisuScene.h>

#include <uio/Edit/Script.h>

namespace mud
{
	class Shell;
}

using namespace mud; namespace toy
{
	class SqliteDatabase;
	
	using Selection = std::vector<Ref>;

	class refl_ TOY_SHELL_EXPORT GameScene : public VisuScene
	{
	public:
		GameScene(User& user, GfxSystem& gfx_system, SoundManager* sound_system, Game& game, Ref player = {});
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

	class refl_ TOY_SHELL_EXPORT Game : public NonCopy
	{
	public:
		Game(User& user, GfxSystem& gfx_system);
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

		std::vector<unique_ptr<GameScene>> m_scenes;
	};

	using GameCallback = void(*)(GameModule& module, GameShell& shell, Game& game);
	using SceneCallback = void(*)(GameModule& module, GameShell& shell, GameScene& scene);

	class refl_ TOY_SHELL_EXPORT GameModule : public NonCopy
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
		constr_ GameModuleBind(Module& module, const VirtualMethod& call)
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

	TOY_SHELL_EXPORT Viewer& game_viewport(Widget& parent, GameScene& scene, Camera& camera);
	TOY_SHELL_EXPORT func_ void paint_physics(Gnode& parent, World& world);
	TOY_SHELL_EXPORT func_ void physic_painter(GameScene& scene);

	class refl_ TOY_SHELL_EXPORT GameShell : public NonCopy
	{
	public:
		GameShell(array<cstring> resource_paths, int argc, char *argv[]);
		~GameShell();

		meth_ void init();
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

		World& load_world(Id id);
		void destroy_world();

		void time_entries(Widget& parent);

		attr_ Core& core() { return *m_core; }
		attr_ LuaInterpreter& lua() { return *m_lua; }
		attr_ WrenInterpreter& wren() { return *m_wren; }
		attr_ GfxSystem& gfx() { return *m_gfx_system; }
#ifdef TOY_SOUND
		attr_ SoundManager& sound() { return *m_sound_system; }
#endif

		attr_ Context& context() { return *m_context; }
		attr_ Vg& vg() { return *m_vg; }
		attr_ UiWindow& ui_window() { return *m_ui_window; }

	public:
		string m_exec_path;
		string m_resource_path;

		User m_user;

		object_ptr<Core> m_core;
		object_ptr<LuaInterpreter> m_lua;
		object_ptr<WrenInterpreter> m_wren;
		object_ptr<GfxSystem> m_gfx_system;
#ifdef TOY_SOUND
		object_ptr<SoundManager> m_sound_system;
#endif

		attr_ Editor m_editor;
		bool m_mini_editor = false;

		unique_ptr<Context> m_context;
		unique_ptr<Vg> m_vg;
		unique_ptr<UiWindow> m_ui_window;

		attr_ Ui* m_ui = nullptr;

		unique_ptr<GameModule> m_game_module_alloc;

		GameModule* m_game_module = nullptr;
		Game m_game;

		std::function<void()> m_pump;

		enum class Step : unsigned int { Input = 0, Core, World, Game, Scene, UiRender, GfxRender, Count };
		float m_times[size_t(Step::Count)] = {};
	};

#if MUD_PLATFORM_EMSCRIPTEN
	static GameShell* g_app = nullptr;
#endif
}

#if MUD_PLATFORM_EMSCRIPTEN
extern "C"
{
	void copy(const char* text);
	void paste(const char* text);
}
#endif