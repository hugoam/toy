

#pragma once

#ifndef MUD_MODULES
#include <meta/shell/Module.h>

#include <obj/Any.h>
#include <obj/Vector.h>
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
                { type<toy::GameModule>(), "pump", member_address(&toy::GameModule::pump), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::GameModule>(object).pump(val<toy::GameShell>(args[0]), val<toy::Game>(args[1])); }, { { "shell", Ref(type<toy::GameShell>()) }, { "game", Ref(type<toy::Game>()) } }, Var() },
                { type<toy::GameModule>(), "scene", member_address(&toy::GameModule::scene), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::GameModule>(object).scene(val<toy::GameShell>(args[0]), val<toy::GameScene>(args[1])); }, { { "shell", Ref(type<toy::GameShell>()) }, { "scene", Ref(type<toy::GameScene>()) } }, Var() }
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
            },
            // methods
            {
                { type<toy::GameShell>(), "init", member_address(&toy::GameShell::init), [](Ref object, array<Var> args, Var& result) { UNUSED(result); UNUSED(args);val<toy::GameShell>(object).init(); }, {}, Var() },
                { type<toy::GameShell>(), "load", member_address(&toy::GameShell::load), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::GameShell>(object).load(val<toy::GameModule>(args[0])); }, { { "module", Ref(type<toy::GameModule>()) } }, Var() },
                { type<toy::GameShell>(), "load", member_address(&toy::GameShell::load), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::GameShell>(object).load(val<std::string>(args[0])); }, { { "module_path", var(std::string()) } }, Var() },
                { type<toy::GameShell>(), "run", member_address(&toy::GameShell::run), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::GameShell>(object).run(val<size_t>(args[0])); }, { { "iterations", var(size_t(0U)), Param::Default } }, Var() },
                { type<toy::GameShell>(), "run_game", member_address(&toy::GameShell::run_game), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::GameShell>(object).run_game(val<toy::GameModule>(args[0]), val<size_t>(args[1])); }, { { "module", Ref(type<toy::GameModule>()) }, { "iterations", var(size_t(0U)), Param::Default } }, Var() },
                { type<toy::GameShell>(), "run_editor", member_address(&toy::GameShell::run_editor), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::GameShell>(object).run_editor(val<toy::GameModule>(args[0]), val<size_t>(args[1])); }, { { "module", Ref(type<toy::GameModule>()) }, { "iterations", var(size_t(0U)), Param::Default } }, Var() },
                { type<toy::GameShell>(), "run_game", member_address(&toy::GameShell::run_game), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::GameShell>(object).run_game(val<std::string>(args[0]), val<size_t>(args[1])); }, { { "module_path", var(std::string()) }, { "iterations", var(size_t(0U)), Param::Default } }, Var() },
                { type<toy::GameShell>(), "run_editor", member_address(&toy::GameShell::run_editor), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::GameShell>(object).run_editor(val<std::string>(args[0]), val<size_t>(args[1])); }, { { "module_path", var(std::string()) }, { "iterations", var(size_t(0U)), Param::Default } }, Var() },
                { type<toy::GameShell>(), "launch", member_address(&toy::GameShell::launch), [](Ref object, array<Var> args, Var& result) { UNUSED(result); UNUSED(args);val<toy::GameShell>(object).launch(); }, {}, Var() },
                { type<toy::GameShell>(), "save", member_address(&toy::GameShell::save), [](Ref object, array<Var> args, Var& result) { UNUSED(result); UNUSED(args);val<toy::GameShell>(object).save(); }, {}, Var() },
                { type<toy::GameShell>(), "reload", member_address(&toy::GameShell::reload), [](Ref object, array<Var> args, Var& result) { UNUSED(result); UNUSED(args);val<toy::GameShell>(object).reload(); }, {}, Var() },
                { type<toy::GameShell>(), "pump", member_address(&toy::GameShell::pump), [](Ref object, array<Var> args, Var& result) { UNUSED(args);val<bool>(result) = val<toy::GameShell>(object).pump(); }, {}, var(bool()) },
                { type<toy::GameShell>(), "cleanup", member_address(&toy::GameShell::cleanup), [](Ref object, array<Var> args, Var& result) { UNUSED(result); UNUSED(args);val<toy::GameShell>(object).cleanup(); }, {}, Var() }
            },
            // static members
            {
            }
        };
        
        
        
        
        meta_class<toy::GameShell>();
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
    
    
        
    // toy::GameModuleBind
    {
        static Meta meta = { type<toy::GameModuleBind>(), &namspc({ "toy" }), "GameModuleBind", sizeof(toy::GameModuleBind), TypeClass::Object };
        static Class cls = { type<toy::GameModuleBind>(),
            // bases
            { &type<toy::GameModule>() },
            { base_offset<toy::GameModuleBind, toy::GameModule>() },
            // constructors
            {
                { type<toy::GameModuleBind>(), [](Ref ref, array<Var> args) { new(&val<toy::GameModuleBind>(ref)) toy::GameModuleBind( val<mud::Module>(args[0]), val<toy::GameModuleBind::mud::VirtualMethod>(args[1]) ); }, { { "module", Ref(type<mud::Module>()) }, { "call", var(toy::GameModuleBind::mud::VirtualMethod()) } } }
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
    

    
        m.m_types.push_back(&type<toy::Game>());
        m.m_types.push_back(&type<toy::GameMode>());
        m.m_types.push_back(&type<toy::GameModule>());
        m.m_types.push_back(&type<toy::GameShell>());
        m.m_types.push_back(&type<toy::GameModuleBind::mud::VirtualMethod>());
        m.m_types.push_back(&type<toy::GameScene>());
        m.m_types.push_back(&type<toy::GameModuleBind>());
    
    }
}
