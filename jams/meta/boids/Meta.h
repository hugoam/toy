

#pragma once

#ifndef MUD_MODULES
#include <meta/boids/Module.h>

#include <type/Any.h>
#include <type/Vector.h>
#include <refl/MetaDecl.h>
#include <refl/Module.h>
#endif

namespace mud
{
    void _boids_meta(Module& m)
    {   
    // Base Types
    
    // Enums
    
    // Sequences
    
    
    
    
    
        
    // Player
    {
        static Meta meta = { type<boids::Player>(), &namspc({}), "Player", sizeof(boids::Player), TypeClass::Object };
        static Class cls = { type<boids::Player>(),
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
        
        
        
        
        meta_class<boids::Player>();
    }
    
    
    
    
    
    
    

    
        m.m_types.push_back(&type<boids::Player>());
    
    }
}
