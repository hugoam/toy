

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
        static Meta meta = { type<toy::Game>(), &namspc({ "toy" }), "Game", sizeof(toy::Game), TypeClass::Struct };
        static Class cls = { type<toy::Game>(),
            // bases
            {  },
            {  },
            // constructors
            {
            },
            // copy constructor
            {
                { type<toy::Game>(), [](Ref ref, Ref other) { new(&val<toy::Game>(ref)) toy::Game(val<toy::Game>(other)); } }
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
                { type<toy::GameModule>(), [](Ref ref, array<Var> args) { new(&val<toy::GameModule>(ref)) toy::GameModule( val<mud::Module>(args[0]) ); }, { { "module", Ref(type<mud::Module>()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
            },
            // methods
            {
                { type<toy::GameModule>(), "init", member_address(&toy::GameModule::init), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::GameModule>(object).init(val<toy::GameShell>(args[0]), val<toy::Game>(args[1])); }, { { "shell", Ref(type<toy::GameShell>()) }, { "game", var(toy::Game()) } }, Var() },
                { type<toy::GameModule>(), "start", member_address(&toy::GameModule::start), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::GameModule>(object).start(val<toy::GameShell>(args[0]), val<toy::Game>(args[1])); }, { { "shell", Ref(type<toy::GameShell>()) }, { "game", var(toy::Game()) } }, Var() },
                { type<toy::GameModule>(), "pump", member_address(&toy::GameModule::pump), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::GameModule>(object).pump(val<toy::GameShell>(args[0]), val<toy::Game>(args[1])); }, { { "shell", Ref(type<toy::GameShell>()) }, { "game", var(toy::Game()) } }, Var() },
                { type<toy::GameModule>(), "scene", member_address(&toy::GameModule::scene), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::GameModule>(object).scene(val<toy::GameShell>(args[0]), val<toy::GameScene>(args[1])); }, { { "shell", Ref(type<toy::GameShell>()) }, { "scene", var(toy::GameScene()) } }, Var() }
            },
            // static members
            {
            }
        };
        
        
        init_pool<toy::GameModule>(); 
        
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
            },
            // static members
            {
            }
        };
        
        
        
        
        meta_class<toy::GameShell>();
    }
    
    
    
        
    // toy::GameScene
    {
        static Meta meta = { type<toy::GameScene>(), &namspc({ "toy" }), "GameScene", sizeof(toy::GameScene), TypeClass::Struct };
        static Class cls = { type<toy::GameScene>(),
            // bases
            { &type<toy::VisuScene>() },
            { base_offset<toy::GameScene, toy::VisuScene>() },
            // constructors
            {
            },
            // copy constructor
            {
                { type<toy::GameScene>(), [](Ref ref, Ref other) { new(&val<toy::GameScene>(ref)) toy::GameScene(val<toy::GameScene>(other)); } }
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
