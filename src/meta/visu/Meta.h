

#pragma once

#ifndef MUD_MODULES
#include <meta/visu/Module.h>

#include <obj/Any.h>
#include <obj/Vector.h>
#include <refl/MetaDecl.h>
#include <refl/Module.h>
#endif

namespace mud
{
    void toy_visu_meta(Module& m)
    {   
    // Base Types
    
    // Enums
    
    // Sequences
    
    
    
        
    // toy::PhysicDebugDraw
    {
        static Meta meta = { type<toy::PhysicDebugDraw>(), &namspc({ "toy" }), "PhysicDebugDraw", sizeof(toy::PhysicDebugDraw), TypeClass::Object };
        static Class cls = { type<toy::PhysicDebugDraw>(),
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
        
        
        
        
        meta_class<toy::PhysicDebugDraw>();
    }
    
    
        
    // toy::SoundSource
    {
        static Meta meta = { type<toy::SoundSource>(), &namspc({ "toy" }), "SoundSource", sizeof(toy::SoundSource), TypeClass::Object };
        static Class cls = { type<toy::SoundSource>(),
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
                { type<toy::SoundSource>(), Address(), type<toy::Entity>(), "entity", Ref(type<toy::Entity>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::SoundSource>(object).m_entity); } }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        
        
        meta_class<toy::SoundSource>();
    }
    
    
    
    
    
    
        
    // toy::VisuScene
    {
        static Meta meta = { type<toy::VisuScene>(), &namspc({ "toy" }), "VisuScene", sizeof(toy::VisuScene), TypeClass::Object };
        static Class cls = { type<toy::VisuScene>(),
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
                { type<toy::VisuScene>(), Address(), type<mud::GfxSystem>(), "gfx_system", Ref(type<mud::GfxSystem>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::VisuScene>(object).m_gfx_system); } },
                { type<toy::VisuScene>(), member_address(&toy::VisuScene::m_scene), type<mud::Scene>(), "scene", Ref(type<mud::Scene>()), Member::None, nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        
        
        meta_class<toy::VisuScene>();
    }
    
    

    
        m.m_types.push_back(&type<toy::PhysicDebugDraw>());
        m.m_types.push_back(&type<toy::SoundSource>());
        m.m_types.push_back(&type<toy::VisuScene>());
    
    }
}
