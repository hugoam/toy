

#pragma once

#ifndef MUD_MODULES
#include <meta/shell/Module.h>

#include <type/Any.h>
#include <type/Vector.h>
#include <refl/MetaDecl.h>
#include <refl/Module.h>
#endif

namespace mud
{
    void toy_shell_meta(Module& m)
    {   
    // Base Types
    
    // Enums
    {
        static Meta meta = { type<toy::GameMode>(), &namspc({ "toy" }), "GameMode", sizeof(toy::GameMode), TypeClass::Enum };
        static Enum enu = { type<toy::GameMode>(),
            true,
            { "Play", "PlayEditor", "Pause" },
            { 0, 1, 2 },
            { var(toy::GameMode::Play), var(toy::GameMode::PlayEditor), var(toy::GameMode::Pause) }
        };
        meta_enum<toy::GameMode>();
    }
    
    
    // Sequences
    
    
    
        
    // toy::Game
    {
        static Meta meta = { type<toy::Game>(), &namspc({ "toy" }), "Game", sizeof(toy::Game), TypeClass::Object };
        static Class cls = { type<toy::Game>(),
            // bases
            {  },
            {  },
            // constructors
            {
            },
            // copy constructor
            {
            },
            // members
            {
                { type<toy::Game>(), member_address(&toy::Game::m_user), type<toy::User>(), "user", Ref(type<toy::User>()), Member::Flags(Member::Pointer|Member::Link), nullptr },
                { type<toy::Game>(), member_address(&toy::Game::m_mode), type<toy::GameMode>(), "mode", var(toy::GameMode()), Member::Value, nullptr },
                { type<toy::Game>(), member_address(&toy::Game::m_shell), type<toy::GameShell>(), "shell", Ref(type<toy::GameShell>()), Member::Flags(Member::Pointer|Member::Link), nullptr },
                { type<toy::Game>(), member_address(&toy::Game::m_module), type<toy::GameModule>(), "module", Ref(type<toy::GameModule>()), Member::Flags(Member::Pointer|Member::Link), nullptr },
                { type<toy::Game>(), member_address(&toy::Game::m_player), type<mud::Ref>(), "player", Ref(type<mud::Ref>()), Member::None, nullptr },
                { type<toy::Game>(), member_address(&toy::Game::m_world), type<toy::World>(), "world", Ref(type<toy::World>()), Member::Flags(Member::Pointer|Member::Link), nullptr },
                { type<toy::Game>(), member_address(&toy::Game::m_screen), type<mud::Widget>(), "screen", Ref(type<mud::Widget>()), Member::Flags(Member::Pointer|Member::Link), nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        
        
        meta_class<toy::Game>();
    }
    
    
        
    // toy::GameModule
    {
        static Meta meta = { type<toy::GameModule>(), &namspc({ "toy" }), "GameModule", sizeof(toy::GameModule), TypeClass::Object };
        static Class cls = { type<toy::GameModule>(),
            // bases
            {  },
            {  },
            // constructors
            {
            },
            // copy constructor
            {
            },
            // members
            {
            },
            // methods
            {
                { type<toy::GameModule>(), "init", member_address(&toy::GameModule::init), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::GameModule>(object).init(val<toy::GameShell>(args[0]), val<toy::Game>(args[1])); }, { { "shell", Ref(type<toy::GameShell>()) }, { "game", Ref(type<toy::Game>()) } }, Var() },
                { type<toy::GameModule>(), "start", member_address(&toy::GameModule::start), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::GameModule>(object).start(val<toy::GameShell>(args[0]), val<toy::Game>(args[1])); }, { { "shell", Ref(type<toy::GameShell>()) }, { "game", Ref(type<toy::Game>()) } }, Var() },
                { type<toy::GameModule>(), "pump", member_address(&toy::GameModule::pump), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::GameModule>(object).pump(val<toy::GameShell>(args[0]), val<toy::Game>(args[1]), val<mud::Widget>(args[3])); }, { { "shell", Ref(type<toy::GameShell>()) }, { "game", Ref(type<toy::Game>()) }, { "ui", Ref(type<mud::Widget>()) } }, Var() },
                { type<toy::GameModule>(), "scene", member_address(&toy::GameModule::scene), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::GameModule>(object).scene(val<toy::GameShell>(args[0]), val<toy::GameScene>(args[1])); }, { { "shell", Ref(type<toy::GameShell>()) }, { "scene", Ref(type<toy::GameScene>()) } }, Var() },
				{ type<toy::GameModule>(), "paint", member_address(&toy::GameModule::paint), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::GameModule>(object).paint(val<toy::GameShell>(args[0]), val<toy::GameScene>(args[1]), val<mud::Gnode>(args[2])); }, { { "shell", Ref(type<toy::GameShell>()) }, { "scene", Ref(type<toy::GameScene>()) }, { "graph", Ref(type<mud::Gnode>()) } }, Var() }
            },
            // static members
            {
            }
        };
        
        
        
        
        meta_class<toy::GameModule>();
    }
    
    
        
    // toy::GameShell
    {
        static Meta meta = { type<toy::GameShell>(), &namspc({ "toy" }), "GameShell", sizeof(toy::GameShell), TypeClass::Object };
        static Class cls = { type<toy::GameShell>(),
            // bases
            {  },
            {  },
            // constructors
            {
            },
            // copy constructor
            {
            },
            // members
            {
                { type<toy::GameShell>(), member_address(&toy::GameShell::core), type<toy::Core>(), "core", Ref(type<toy::Core>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::GameShell>(object).core()); } },
                //{ type<toy::GameShell>(), member_address(&toy::GameShell::lua), type<mud::LuaInterpreter>(), "lua", Ref(type<mud::LuaInterpreter>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::GameShell>(object).lua()); } },
                //{ type<toy::GameShell>(), member_address(&toy::GameShell::wren), type<mud::WrenInterpreter>(), "wren", Ref(type<mud::WrenInterpreter>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::GameShell>(object).wren()); } },
                { type<toy::GameShell>(), member_address(&toy::GameShell::gfx), type<mud::GfxSystem>(), "gfx", Ref(type<mud::GfxSystem>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::GameShell>(object).gfx()); } },
                { type<toy::GameShell>(), member_address(&toy::GameShell::context), type<mud::Context>(), "context", Ref(type<mud::Context>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::GameShell>(object).context()); } },
                //{ type<toy::GameShell>(), member_address(&toy::GameShell::vg), type<mud::Vg>(), "vg", Ref(type<mud::Vg>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::GameShell>(object).vg()); } },
                { type<toy::GameShell>(), member_address(&toy::GameShell::ui_window), type<mud::UiWindow>(), "ui_window", Ref(type<mud::UiWindow>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::GameShell>(object).ui_window()); } },
                { type<toy::GameShell>(), member_address(&toy::GameShell::m_editor), type<toy::Editor>(), "editor", Ref(type<toy::Editor>()), Member::None, nullptr },
                { type<toy::GameShell>(), member_address(&toy::GameShell::m_ui), type<mud::Ui>(), "ui", Ref(type<mud::Ui>()), Member::Flags(Member::Pointer|Member::Link), nullptr }
            },
            // methods
            {
                { type<toy::GameShell>(), "init", member_address(&toy::GameShell::init), [](Ref object, array<Var> args, Var& result) { UNUSED(result); UNUSED(args);val<toy::GameShell>(object).init(); }, {}, Var() },
                { type<toy::GameShell>(), "load", member_address(&toy::GameShell::load), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::GameShell>(object).load(val<toy::GameModule>(args[0])); }, { { "module", Ref(type<toy::GameModule>()) } }, Var() },
                { type<toy::GameShell>(), "load_path", member_address(&toy::GameShell::load_path), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::GameShell>(object).load_path(val<std::string>(args[0])); }, { { "module_path", var(std::string()) } }, Var() },
                { type<toy::GameShell>(), "run", member_address(&toy::GameShell::run), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::GameShell>(object).run(val<size_t>(args[0])); }, { { "iterations", var(size_t(0U)), Param::Default } }, Var() },
                { type<toy::GameShell>(), "run_game", member_address(&toy::GameShell::run_game), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::GameShell>(object).run_game(val<toy::GameModule>(args[0]), val<size_t>(args[1])); }, { { "module", Ref(type<toy::GameModule>()) }, { "iterations", var(size_t(0U)), Param::Default } }, Var() },
                { type<toy::GameShell>(), "run_editor", member_address(&toy::GameShell::run_editor), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::GameShell>(object).run_editor(val<toy::GameModule>(args[0]), val<size_t>(args[1])); }, { { "module", Ref(type<toy::GameModule>()) }, { "iterations", var(size_t(0U)), Param::Default } }, Var() },
                { type<toy::GameShell>(), "run_game_path", member_address(&toy::GameShell::run_game_path), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::GameShell>(object).run_game_path(val<std::string>(args[0]), val<size_t>(args[1])); }, { { "module_path", var(std::string()) }, { "iterations", var(size_t(0U)), Param::Default } }, Var() },
                { type<toy::GameShell>(), "run_editor_path", member_address(&toy::GameShell::run_editor_path), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::GameShell>(object).run_editor_path(val<std::string>(args[0]), val<size_t>(args[1])); }, { { "module_path", var(std::string()) }, { "iterations", var(size_t(0U)), Param::Default } }, Var() },
                { type<toy::GameShell>(), "launch", member_address(&toy::GameShell::launch), [](Ref object, array<Var> args, Var& result) { UNUSED(result); UNUSED(args);val<toy::GameShell>(object).launch(); }, {}, Var() },
                { type<toy::GameShell>(), "save", member_address(&toy::GameShell::save), [](Ref object, array<Var> args, Var& result) { UNUSED(result); UNUSED(args);val<toy::GameShell>(object).save(); }, {}, Var() },
                { type<toy::GameShell>(), "reload", member_address(&toy::GameShell::reload), [](Ref object, array<Var> args, Var& result) { UNUSED(result); UNUSED(args);val<toy::GameShell>(object).reload(); }, {}, Var() },
                { type<toy::GameShell>(), "pump", member_address(&toy::GameShell::pump), [](Ref object, array<Var> args, Var& result) { UNUSED(args);val<bool>(result) = val<toy::GameShell>(object).pump(); }, {}, var(bool()) },
                { type<toy::GameShell>(), "cleanup", member_address(&toy::GameShell::cleanup), [](Ref object, array<Var> args, Var& result) { UNUSED(result); UNUSED(args);val<toy::GameShell>(object).cleanup(); }, {}, Var() },
				{ type<toy::GameShell>(), "add_scene", member_address(&toy::GameShell::add_scene), [](Ref object, array<Var> args, Var& result) { UNUSED(args); result = Ref(&val<toy::GameShell>(object).add_scene()); },{}, Ref(type<toy::GameScene>()) },
            },
            // static members
            {
            }
        };
        
        
        
        
        meta_class<toy::GameShell>();
    }
    
    
    
    
    
    
    
        
    // toy::GameModuleBind
    {
        static Meta meta = { type<toy::GameModuleBind>(), &namspc({ "toy" }), "GameModuleBind", sizeof(toy::GameModuleBind), TypeClass::Object };
        static Class cls = { type<toy::GameModuleBind>(),
            // bases
            { &type<toy::GameModule>() },
            { base_offset<toy::GameModuleBind, toy::GameModule>() },
            // constructors
            {
                { type<toy::GameModuleBind>(), [](Ref ref, array<Var> args) { new(&val<toy::GameModuleBind>(ref)) toy::GameModuleBind( val<mud::Module>(args[0]), val<mud::VirtualMethod>(args[1]) ); }, { { "module", Ref(type<mud::Module>()) }, { "call", var(mud::VirtualMethod()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        init_pool<toy::GameModuleBind>(); 
        
        meta_class<toy::GameModuleBind>();
    }
    
    
        
    // toy::GameScene
    {
        static Meta meta = { type<toy::GameScene>(), &namspc({ "toy" }), "GameScene", sizeof(toy::GameScene), TypeClass::Object };
        static Class cls = { type<toy::GameScene>(),
            // bases
            { &type<toy::VisuScene>() },
            { base_offset<toy::GameScene, toy::VisuScene>() },
            // constructors
            {
            },
            // copy constructor
            {
            },
            // members
            {
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        
        
        meta_class<toy::GameScene>();
    }
    

	{
		auto func = [](array<Var> args, Var& result) {  UNUSED(result); toy::paint_physics(val<mud::Gnode>(args[0]), val<toy::World>(args[1])); };
		std::vector<Param> params = { { "parent", Ref(type<mud::Gnode>()) }, { "world", Ref(type<toy::World>()) } };
		static Function f = { &namspc({ "toy" }), "paint_physics", function_id<void(*)(mud::Gnode&, toy::World&)>(&toy::paint_physics), func, params, Var() };
		m.m_functions.push_back(&f);
	}

	{
		auto func = [](array<Var> args, Var& result) {  UNUSED(result); toy::physic_painter(val<toy::GameScene>(args[0])); };
		std::vector<Param> params = { { "scene", Ref(type<toy::GameScene>()) } };
		static Function f = { &namspc({ "toy" }), "physic_painter", function_id<void(*)(toy::GameScene&)>(&toy::physic_painter), func, params, Var() };
		m.m_functions.push_back(&f);
	}
    
        m.m_types.push_back(&type<toy::Game>());
        m.m_types.push_back(&type<toy::GameMode>());
        m.m_types.push_back(&type<toy::GameModule>());
        m.m_types.push_back(&type<toy::GameShell>());
        m.m_types.push_back(&type<mud::VirtualMethod>());
        m.m_types.push_back(&type<toy::GameModuleBind>());
        m.m_types.push_back(&type<toy::GameScene>());
    
    }
}
