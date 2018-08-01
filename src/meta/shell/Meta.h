

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
    
    
    

    
        m.m_types.push_back(&type<toy::GameMode>());
        m.m_types.push_back(&type<toy::GameShell>());
    
    }
}
