#include <two/jobs.refl.h>
#include <two/tree.refl.h>
#include <two/lang.refl.h>
#include <two/srlz.refl.h>
#include <two/uio.refl.h>
#include <toy/core.refl.h>
#include <toy/shell.h>
#include <two/pool.refl.h>
#include <two/geom.refl.h>
#include <two/ui.refl.h>
#include <toy/shell.refl.h>
#include <two/gfx.refl.h>
#include <toy/visu.refl.h>
#include <two/infra.refl.h>
#include <two/type.refl.h>
#include <two/refl.refl.h>
#include <two/ctx.refl.h>
#include <two/gfx.ui.refl.h>
#include <toy/block.refl.h>
#include <two/refl.h>
#include <two/math.refl.h>
#include <toy/edit.refl.h>
#include <two/infra.h>
#include <two/type.h>
#include <two/ecs.refl.h>
#include <two/bgfx.refl.h>
#include <two/frame.refl.h>


#ifdef TWO_MODULES
module toy.shell;
#else
#include <cstddef>
#include <stl/new.h>
#endif


using namespace two;

void toy_GameMode__to_string(void* val, string& str) { str = g_enu[type<toy::GameMode>().m_id]->name(uint32_t((*static_cast<toy::GameMode*>(val)))); }
void toy_GameMode__to_value(const string& str, void* val) { (*static_cast<toy::GameMode*>(val)) = toy::GameMode(g_enu[type<toy::GameMode>().m_id]->value(str.c_str())); }
void toy_GameModule_init(void* object, span<void*> args, void*& result) { UNUSED(result); (*static_cast<toy::GameModule*>(object)).init(*static_cast<toy::GameShell*>(args[0]), *static_cast<toy::Game*>(args[1])); }
void toy_GameModule_start(void* object, span<void*> args, void*& result) { UNUSED(result); (*static_cast<toy::GameModule*>(object)).start(*static_cast<toy::GameShell*>(args[0]), *static_cast<toy::Game*>(args[1])); }
void toy_GameModule_pump(void* object, span<void*> args, void*& result) { UNUSED(result); (*static_cast<toy::GameModule*>(object)).pump(*static_cast<toy::GameShell*>(args[0]), *static_cast<toy::Game*>(args[1]), *static_cast<two::Widget*>(args[2])); }
void toy_GameModule_scene(void* object, span<void*> args, void*& result) { UNUSED(result); (*static_cast<toy::GameModule*>(object)).scene(*static_cast<toy::GameShell*>(args[0]), *static_cast<toy::GameScene*>(args[1])); }
void toy_GameModule_paint(void* object, span<void*> args, void*& result) { UNUSED(result); (*static_cast<toy::GameModule*>(object)).paint(*static_cast<toy::GameShell*>(args[0]), *static_cast<toy::GameScene*>(args[1]), *static_cast<two::Gnode*>(args[2])); }
void toy_GameShell__construct_0(void* ref, span<void*> args) { new(stl::placeholder(), ref) toy::GameShell( *static_cast<stl::string*>(args[0]), static_cast<const char*>(args[1]) ); }
void* toy_GameShell__get_core(void* object) { return &(*static_cast<toy::GameShell*>(object)).core(); }
void* toy_GameShell__get_lua(void* object) { return &(*static_cast<toy::GameShell*>(object)).lua(); }
void* toy_GameShell__get_wren(void* object) { return &(*static_cast<toy::GameShell*>(object)).wren(); }
void* toy_GameShell__get_gfx(void* object) { return &(*static_cast<toy::GameShell*>(object)).gfx(); }
void toy_GameShell_init(void* object, span<void*> args, void*& result) { UNUSED(result); (*static_cast<toy::GameShell*>(object)).init(*static_cast<bool*>(args[0])); }
void toy_GameShell_window(void* object, span<void*> args, void*& result) { result = &(*static_cast<toy::GameShell*>(object)).window(*static_cast<stl::string*>(args[0]), *static_cast<two::uvec2*>(args[1]), *static_cast<bool*>(args[2])); }
void toy_GameShell_load(void* object, span<void*> args, void*& result) { UNUSED(result); (*static_cast<toy::GameShell*>(object)).load(*static_cast<toy::GameModule*>(args[0])); }
void toy_GameShell_load_path(void* object, span<void*> args, void*& result) { UNUSED(result); (*static_cast<toy::GameShell*>(object)).load_path(*static_cast<stl::string*>(args[0])); }
void toy_GameShell_run(void* object, span<void*> args, void*& result) { UNUSED(result); (*static_cast<toy::GameShell*>(object)).run(*static_cast<size_t*>(args[0])); }
void toy_GameShell_run_game(void* object, span<void*> args, void*& result) { UNUSED(result); (*static_cast<toy::GameShell*>(object)).run_game(*static_cast<toy::GameModule*>(args[0]), *static_cast<size_t*>(args[1])); }
void toy_GameShell_run_editor(void* object, span<void*> args, void*& result) { UNUSED(result); (*static_cast<toy::GameShell*>(object)).run_editor(*static_cast<toy::GameModule*>(args[0]), *static_cast<size_t*>(args[1])); }
void toy_GameShell_run_game_path(void* object, span<void*> args, void*& result) { UNUSED(result); (*static_cast<toy::GameShell*>(object)).run_game_path(*static_cast<stl::string*>(args[0]), *static_cast<size_t*>(args[1])); }
void toy_GameShell_run_editor_path(void* object, span<void*> args, void*& result) { UNUSED(result); (*static_cast<toy::GameShell*>(object)).run_editor_path(*static_cast<stl::string*>(args[0]), *static_cast<size_t*>(args[1])); }
void toy_GameShell_launch(void* object, span<void*> args, void*& result) { UNUSED(result); UNUSED(args); (*static_cast<toy::GameShell*>(object)).launch(); }
void toy_GameShell_save(void* object, span<void*> args, void*& result) { UNUSED(result); UNUSED(args); (*static_cast<toy::GameShell*>(object)).save(); }
void toy_GameShell_reload(void* object, span<void*> args, void*& result) { UNUSED(result); UNUSED(args); (*static_cast<toy::GameShell*>(object)).reload(); }
void toy_GameShell_pump(void* object, span<void*> args, void*& result) { UNUSED(args); (*static_cast<bool*>(result)) = (*static_cast<toy::GameShell*>(object)).pump(); }
void toy_GameShell_cleanup(void* object, span<void*> args, void*& result) { UNUSED(result); UNUSED(args); (*static_cast<toy::GameShell*>(object)).cleanup(); }
void toy_GameShell_main_window(void* object, span<void*> args, void*& result) { UNUSED(args); result = &(*static_cast<toy::GameShell*>(object)).main_window(); }
void toy_GameShell_add_scene(void* object, span<void*> args, void*& result) { UNUSED(args); result = &(*static_cast<toy::GameShell*>(object)).add_scene(); }
void toy_GameShell_remove_scene(void* object, span<void*> args, void*& result) { UNUSED(result); (*static_cast<toy::GameShell*>(object)).remove_scene(*static_cast<toy::GameScene*>(args[0])); }
void toy_GameShell_clear_scenes(void* object, span<void*> args, void*& result) { UNUSED(result); UNUSED(args); (*static_cast<toy::GameShell*>(object)).clear_scenes(); }
void toy_paint_physics_0(span<void*> args, void*& result) { UNUSED(result);  toy::paint_physics(*static_cast<two::Gnode*>(args[0]), *static_cast<toy::World*>(args[1])); }
void toy_physic_painter_1(span<void*> args, void*& result) { UNUSED(result);  toy::physic_painter(*static_cast<toy::GameScene*>(args[0])); }

namespace two
{
	void toy_shell_meta(Module& m)
	{
	UNUSED(m);
	
	// Base Types
	
	// Enums
	{
		Type& t = type<toy::GameMode>();
		static Meta meta = { t, &namspc({ "toy" }), "GameMode", sizeof(toy::GameMode), TypeClass::Enum };
		static cstring ids[] = { "Play", "PlayEditor", "Pause" };
		static uint32_t values[] = { 0, 1, 2 };
		static toy::GameMode vars[] = { toy::GameMode::Play, toy::GameMode::PlayEditor, toy::GameMode::Pause};
		static void* refs[] = { &vars[0], &vars[1], &vars[2]};
		static Enum enu = { t, true, ids, values, refs };
		static Convert convert = { toy_GameMode__to_string,
		                           toy_GameMode__to_value };
		g_convert[t.m_id] = &convert;
	}
	
	// Sequences
	
	// toy::GameScene
	{
		Type& t = type<toy::GameScene>();
		static Meta meta = { t, &namspc({ "toy" }), "GameScene", sizeof(toy::GameScene), TypeClass::Object };
		// bases
		static Type* bases[] = { &type<toy::VisuScene>() };
		static size_t bases_offsets[] = { base_offset<toy::GameScene, toy::VisuScene>() };
		// defaults
		// constructors
		// copy constructor
		// members
		// methods
		// static members
		static Class cls = { t, bases, bases_offsets, {}, {}, {}, {}, {}, };
	}
	// toy::Game
	{
		Type& t = type<toy::Game>();
		static Meta meta = { t, &namspc({ "toy" }), "Game", sizeof(toy::Game), TypeClass::Object };
		// bases
		// defaults
		static toy::User* user_default = nullptr;
		static toy::GameMode mode_default = toy::GameMode::Play;
		static toy::GameShell* shell_default = nullptr;
		static toy::GameModule* module_default = nullptr;
		static two::Ref player_default = {};
		static toy::World* world_default = nullptr;
		static two::Widget* screen_default = nullptr;
		// constructors
		// copy constructor
		// members
		static Member members[] = {
			{ t, offsetof(toy::Game, m_user), type<toy::User>(), "user", user_default, Member::Flags(Member::Pointer|Member::Link), nullptr },
			{ t, offsetof(toy::Game, m_mode), type<toy::GameMode>(), "mode", &mode_default, Member::Value, nullptr },
			{ t, offsetof(toy::Game, m_shell), type<toy::GameShell>(), "shell", shell_default, Member::Flags(Member::Pointer|Member::Link), nullptr },
			{ t, offsetof(toy::Game, m_module), type<toy::GameModule>(), "module", module_default, Member::Flags(Member::Pointer|Member::Link), nullptr },
			{ t, offsetof(toy::Game, m_player), type<two::Ref>(), "player", &player_default, Member::Value, nullptr },
			{ t, offsetof(toy::Game, m_world), type<toy::World>(), "world", world_default, Member::Flags(Member::Pointer|Member::Link), nullptr },
			{ t, offsetof(toy::Game, m_screen), type<two::Widget>(), "screen", screen_default, Member::Flags(Member::Pointer|Member::Link), nullptr }
		};
		// methods
		// static members
		static Class cls = { t, {}, {}, {}, {}, members, {}, {}, };
	}
	// toy::GameModule
	{
		Type& t = type<toy::GameModule>();
		static Meta meta = { t, &namspc({ "toy" }), "GameModule", sizeof(toy::GameModule), TypeClass::Object };
		// bases
		// defaults
		// constructors
		// copy constructor
		// members
		// methods
		static Method methods[] = {
			{ t, "init", Address(), toy_GameModule_init, { { "shell", type<toy::GameShell>(),  }, { "game", type<toy::Game>(),  } }, g_qvoid },
			{ t, "start", Address(), toy_GameModule_start, { { "shell", type<toy::GameShell>(),  }, { "game", type<toy::Game>(),  } }, g_qvoid },
			{ t, "pump", Address(), toy_GameModule_pump, { { "shell", type<toy::GameShell>(),  }, { "game", type<toy::Game>(),  }, { "ui", type<two::Widget>(),  } }, g_qvoid },
			{ t, "scene", Address(), toy_GameModule_scene, { { "shell", type<toy::GameShell>(),  }, { "scene", type<toy::GameScene>(),  } }, g_qvoid },
			{ t, "paint", Address(), toy_GameModule_paint, { { "shell", type<toy::GameShell>(),  }, { "scene", type<toy::GameScene>(),  }, { "graph", type<two::Gnode>(),  } }, g_qvoid }
		};
		// static members
		static Class cls = { t, {}, {}, {}, {}, {}, methods, {}, };
	}
	// toy::GameModuleBind
	{
		Type& t = type<toy::GameModuleBind>();
		static Meta meta = { t, &namspc({ "toy" }), "GameModuleBind", sizeof(toy::GameModuleBind), TypeClass::Object };
		// bases
		static Type* bases[] = { &type<toy::GameModule>() };
		static size_t bases_offsets[] = { base_offset<toy::GameModuleBind, toy::GameModule>() };
		// defaults
		// constructors
		// copy constructor
		// members
		// methods
		// static members
		static Class cls = { t, bases, bases_offsets, {}, {}, {}, {}, {}, };
	}
	// toy::GameWindow
	{
		Type& t = type<toy::GameWindow>();
		static Meta meta = { t, &namspc({ "toy" }), "GameWindow", sizeof(toy::GameWindow), TypeClass::Object };
		// bases
		static Type* bases[] = { &type<two::GfxWindow>() };
		static size_t bases_offsets[] = { base_offset<toy::GameWindow, two::GfxWindow>() };
		// defaults
		static uint32_t index_default = 0;
		static two::Ui* ui_default = nullptr;
		// constructors
		// copy constructor
		// members
		static Member members[] = {
			{ t, offsetof(toy::GameWindow, m_index), type<uint32_t>(), "index", &index_default, Member::Value, nullptr },
			{ t, offsetof(toy::GameWindow, m_ui_window), type<two::UiWindow>(), "ui_window", nullptr, Member::NonMutable, nullptr },
			{ t, offsetof(toy::GameWindow, m_ui), type<two::Ui>(), "ui", ui_default, Member::Flags(Member::Pointer|Member::Link), nullptr }
		};
		// methods
		// static members
		static Class cls = { t, bases, bases_offsets, {}, {}, members, {}, {}, };
	}
	// toy::GameShell
	{
		Type& t = type<toy::GameShell>();
		static Meta meta = { t, &namspc({ "toy" }), "GameShell", sizeof(toy::GameShell), TypeClass::Object };
		// bases
		// defaults
		static const char* construct_0_exec_path_default = nullptr;
		static bool window_0_fullscreen_default = false;
		static size_t run_0_iterations_default = 0U;
		static size_t run_game_0_iterations_default = 0U;
		static size_t run_editor_0_iterations_default = 0U;
		static size_t run_game_path_0_iterations_default = 0U;
		static size_t run_editor_path_0_iterations_default = 0U;
		// constructors
		static Constructor constructors[] = {
			{ t, toy_GameShell__construct_0, { { "resource_path", type<stl::string>(),  }, { "exec_path", type<const char*>(), Param::Flags(Param::Nullable|Param::Default), &construct_0_exec_path_default } } }
		};
		// copy constructor
		// members
		static Member members[] = {
			{ t, SIZE_MAX, type<toy::Core>(), "core", nullptr, Member::Flags(Member::NonMutable|Member::Link), toy_GameShell__get_core },
			{ t, SIZE_MAX, type<two::LuaInterpreter>(), "lua", nullptr, Member::Flags(Member::NonMutable|Member::Link), toy_GameShell__get_lua },
			{ t, SIZE_MAX, type<two::WrenInterpreter>(), "wren", nullptr, Member::Flags(Member::NonMutable|Member::Link), toy_GameShell__get_wren },
			{ t, SIZE_MAX, type<two::GfxSystem>(), "gfx", nullptr, Member::Flags(Member::NonMutable|Member::Link), toy_GameShell__get_gfx },
			{ t, offsetof(toy::GameShell, m_editor), type<toy::Editor>(), "editor", nullptr, Member::NonMutable, nullptr }
		};
		// methods
		static Method methods[] = {
			{ t, "init", Address(), toy_GameShell_init, { { "window", type<bool>(),  } }, g_qvoid },
			{ t, "window", Address(), toy_GameShell_window, { { "name", type<stl::string>(),  }, { "size", type<two::uvec2>(),  }, { "fullscreen", type<bool>(), Param::Default, &window_0_fullscreen_default } }, { &type<toy::GameWindow>(), QualType::None } },
			{ t, "load", Address(), toy_GameShell_load, { { "module", type<toy::GameModule>(),  } }, g_qvoid },
			{ t, "load_path", Address(), toy_GameShell_load_path, { { "module_path", type<stl::string>(),  } }, g_qvoid },
			{ t, "run", Address(), toy_GameShell_run, { { "iterations", type<size_t>(), Param::Default, &run_0_iterations_default } }, g_qvoid },
			{ t, "run_game", Address(), toy_GameShell_run_game, { { "module", type<toy::GameModule>(),  }, { "iterations", type<size_t>(), Param::Default, &run_game_0_iterations_default } }, g_qvoid },
			{ t, "run_editor", Address(), toy_GameShell_run_editor, { { "module", type<toy::GameModule>(),  }, { "iterations", type<size_t>(), Param::Default, &run_editor_0_iterations_default } }, g_qvoid },
			{ t, "run_game_path", Address(), toy_GameShell_run_game_path, { { "module_path", type<stl::string>(),  }, { "iterations", type<size_t>(), Param::Default, &run_game_path_0_iterations_default } }, g_qvoid },
			{ t, "run_editor_path", Address(), toy_GameShell_run_editor_path, { { "module_path", type<stl::string>(),  }, { "iterations", type<size_t>(), Param::Default, &run_editor_path_0_iterations_default } }, g_qvoid },
			{ t, "launch", Address(), toy_GameShell_launch, {}, g_qvoid },
			{ t, "save", Address(), toy_GameShell_save, {}, g_qvoid },
			{ t, "reload", Address(), toy_GameShell_reload, {}, g_qvoid },
			{ t, "pump", Address(), toy_GameShell_pump, {}, { &type<bool>(), QualType::None } },
			{ t, "cleanup", Address(), toy_GameShell_cleanup, {}, g_qvoid },
			{ t, "main_window", Address(), toy_GameShell_main_window, {}, { &type<toy::GameWindow>(), QualType::None } },
			{ t, "add_scene", Address(), toy_GameShell_add_scene, {}, { &type<toy::GameScene>(), QualType::None } },
			{ t, "remove_scene", Address(), toy_GameShell_remove_scene, { { "scene", type<toy::GameScene>(),  } }, g_qvoid },
			{ t, "clear_scenes", Address(), toy_GameShell_clear_scenes, {}, g_qvoid }
		};
		// static members
		static Class cls = { t, {}, {}, constructors, {}, members, methods, {}, };
	}
	
	
		m.m_types.push_back(&type<toy::GameScene>());
		m.m_types.push_back(&type<toy::GameMode>());
		m.m_types.push_back(&type<toy::Game>());
		m.m_types.push_back(&type<toy::GameModule>());
		m.m_types.push_back(&type<toy::GameModuleBind>());
		m.m_types.push_back(&type<toy::GameWindow>());
		m.m_types.push_back(&type<toy::GameShell>());
		{
			static Function f = { &namspc({ "toy" }), "paint_physics", funcptr<void(*)(two::Gnode&, toy::World&)>(toy::paint_physics), toy_paint_physics_0, { { "parent", type<two::Gnode>(),  }, { "world", type<toy::World>(),  } }, g_qvoid };
			m.m_functions.push_back(&f);
		}
		{
			static Function f = { &namspc({ "toy" }), "physic_painter", funcptr<void(*)(toy::GameScene&)>(toy::physic_painter), toy_physic_painter_1, { { "scene", type<toy::GameScene>(),  } }, g_qvoid };
			m.m_functions.push_back(&f);
		}
	}
}

namespace toy
{
	toy_shell::toy_shell()
		: Module("toy::shell", { &two_infra::m(), &two_jobs::m(), &two_type::m(), &two_tree::m(), &two_pool::m(), &two_refl::m(), &two_ecs::m(), &two_srlz::m(), &two_math::m(), &two_geom::m(), &two_lang::m(), &two_ctx::m(), &two_ui::m(), &two_uio::m(), &two_bgfx::m(), &two_gfx::m(), &two_gfx_ui::m(), &two_frame::m(), &toy_core::m(), &toy_visu::m(), &toy_edit::m(), &toy_block::m() })
	{
		// setup reflection meta data
		toy_shell_meta(*this);
	}
}

#ifdef TOY_SHELL_MODULE
extern "C"
Module& getModule()
{
	return toy_shell::m();
}
#endif
