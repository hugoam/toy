
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

		User* m_user = nullptr;
		GameMode m_mode = GameMode::Play;
		GameShell* m_shell = nullptr;
		GameModule* m_module = nullptr;
		Ref m_player = {};
		World* m_world = nullptr;
		Widget* m_screen = nullptr;

		EditContext m_editor;

		std::vector<unique_ptr<GameScene>> m_scenes;
	};

	using GameCallback = void(*)(GameModule& module, GameShell& shell, Game& game);
	using SceneCallback = void(*)(GameModule& module, GameShell& shell, GameScene& scene);

	class refl_ TOY_SHELL_EXPORT GameModule
	{
	public:
		GameModule(Module& module)
			: m_module(&module)
		{}

		string m_module_path = "";
		Module* m_module = nullptr;

		meth_ virtual void init(GameShell& shell, Game& game) = 0;
		meth_ virtual void start(GameShell& shell, Game& game) = 0;
		meth_ virtual void pump(GameShell& shell, Game& game) = 0;
		meth_ virtual void scene(GameShell& shell, GameScene& scene) { UNUSED(shell); UNUSED(scene); }
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
		virtual void pump(GameShell& app, Game& game) { Var params[2] = { Ref(&app), Ref(&game) }; m_call(method(&GameModule::pump), Ref(this), { params, 2 }); }
		virtual void scene(GameShell& app, GameScene& scene) { Var params[2] = { Ref(&app), Ref(&scene) }; m_call(method(&GameModule::scene), Ref(this), { params, 2 }); }

		VirtualMethod m_call;
	};

	TOY_SHELL_EXPORT Viewer& game_viewport(Widget& parent, GameScene& scene, Camera& camera);

	class refl_ TOY_SHELL_EXPORT GameShell : public NonCopy
	{
	public:
		GameShell(array<cstring> resource_paths, int argc, char *argv[]);
		~GameShell();

		meth_ void init();
		meth_ void load(GameModule& module);
		meth_ void load(const string& module_path);
		meth_ void run(size_t iterations = 0U);
		meth_ void run_game(GameModule& module, size_t iterations = 0U);
		meth_ void run_editor(GameModule& module, size_t iterations = 0U);
		meth_ void run_game(const string& module_path, size_t iterations = 0U);
		meth_ void run_editor(const string& module_path, size_t iterations = 0U);
		meth_ void launch();
		meth_ void save();
		meth_ void reload();
		meth_ bool pump();
		meth_ void cleanup();

		void start_game();
		void pump_game();
		void pump_editor();

		GameScene& add_scene();

		World& load_world(Id id);
		void destroy_world();

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

		Editor m_editor;

		unique_ptr<Context> m_context;
		unique_ptr<Vg> m_vg;
		unique_ptr<UiWindow> m_ui_window;
		Widget* m_ui = nullptr;

		unique_ptr<GameModule> m_game_module_alloc;

		GameModule* m_game_module = nullptr;
		Game m_game;

		std::function<void()> m_pump;
	};
}
