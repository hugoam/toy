
#pragma once

#include <tree/Node.h>
#include <refl/System.h>
#include <shell/Forward.h>
#include <core/Player/Player.h>

#include <edit/Editor/Editor.h>
#include <lang/Lua.h>

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

	struct TOY_SHELL_EXPORT GameScene : public VisuScene
	{
		Selection& m_selection;
		Game& m_game;

		GameScene(User& user, GfxSystem& gfx_system, SoundManager* sound_system, Game& game, Ref player = {});
		~GameScene();
	};

	enum class refl_ GameMode
	{
		Play,
		PlayEditor,
		Pause,
	};

	struct TOY_SHELL_EXPORT Game : public NonCopy
	{
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

	using GameCallback = void(*)(GameShell& shell, Game& game);
	using SceneCallback = void(*)(GameShell& shell, GameScene& scene);

	class TOY_SHELL_EXPORT GameModule
	{
	public:
		GameModule(Module& module)
			: m_module(&module)
		{}

		string m_module_path = "";
		Module* m_module = nullptr;

		virtual void init(GameShell& shell, Game& game) = 0;
		virtual void start(GameShell& shell, Game& game) = 0;
		virtual void pump(GameShell& shell, Game& game) = 0;
		virtual void scene(GameShell& shell, GameScene& scene) { UNUSED(shell); UNUSED(scene); }
	};

	TOY_SHELL_EXPORT Viewer& game_viewport(Widget& parent, GameScene& scene, Camera& camera);

	class refl_ TOY_SHELL_EXPORT GameShell : public NonCopy
	{
	public:
		GameShell(array<cstring> resource_paths, int argc, char *argv[]);
		~GameShell();

		void init();
		void load(GameModule& module);
		void load(const string& module_path);
		void run(size_t iterations = 0U);
		void run_game(GameModule& module, size_t iterations = 0U);
		void run_editor(GameModule& module, size_t iterations = 0U);
		void run_game(const string& module_path, size_t iterations = 0U);
		void run_editor(const string& module_path, size_t iterations = 0U);
		void launch();
		void save();
		void reload();
		bool pump();
		void cleanup();

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
		object_ptr<LuaInterpreter> m_interpreter;
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
