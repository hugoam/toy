

#pragma once

#ifndef MUD_MODULES
#include <meta/visu/Module.h>

#include <type/Any.h>
#include <type/Vector.h>
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
				{ type<toy::VisuScene>(), "next_frame", member_address(&toy::VisuScene::next_frame), [](Ref object, array<Var> args, Var& result) { UNUSED(result); UNUSED(args); val<toy::VisuScene>(object).next_frame(); }, {}, Var() },
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
