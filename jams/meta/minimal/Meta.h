

#pragma once

#ifndef MUD_MODULES
#include <meta/minimal/Module.h>

#include <obj/Any.h>
#include <obj/Vector.h>
#include <refl/MetaDecl.h>
#include <refl/Module.h>
#endif

namespace mud
{
    void _minimal_meta(Module& m)
    {   
    // Base Types
    
    // Enums
    
    // Sequences
    
    
    
    
    
        
    // Player
    {
        static Meta meta = { type<Player>(), &namspc({}), "Player", sizeof(Player), TypeClass::Object };
        static Class cls = { type<Player>(),
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
        
        
        
        
        meta_class<Player>();
    }
    
    
    
    
    
    
    
        
    // Bullet
    {
        static Meta meta = { type<Bullet>(), &namspc({}), "Bullet", sizeof(Bullet), TypeClass::Complex };
        static Class cls = { type<Bullet>(),
            // bases
            { &type<mud::Complex>(), &type<toy::ColliderObject>() },
            { base_offset<Bullet, mud::Complex>(), base_offset<Bullet, toy::ColliderObject>() },
            // constructors
            {
            },
            // copy constructor
            {
            },
            // members
            {
                { type<Bullet>(), member_address(&Bullet::m_entity), type<toy::Entity>(), "entity", Ref(type<toy::Entity>()), Member::Component, nullptr },
                { type<Bullet>(), member_address(&Bullet::m_source), type<mud::vec3>(), "source", var(mud::vec3()), Member::Value, nullptr },
                { type<Bullet>(), member_address(&Bullet::m_velocity), type<mud::vec3>(), "velocity", var(mud::vec3()), Member::Value, nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        
        
        meta_class<Bullet>();
    }
    
    
        
    // Crate
    {
        static Meta meta = { type<Crate>(), &namspc({}), "Crate", sizeof(Crate), TypeClass::Complex };
        static Class cls = { type<Crate>(),
            // bases
            { &type<mud::Complex>(), &type<toy::ColliderObject>() },
            { base_offset<Crate, mud::Complex>(), base_offset<Crate, toy::ColliderObject>() },
            // constructors
            {
                { type<Crate>(), [](Ref ref, array<Var> args) { new(&val<Crate>(ref)) Crate( val<mud::Id>(args[0]), val<toy::Entity>(args[1]), val<mud::vec3>(args[2]), val<mud::vec3>(args[3]) ); }, { { "id", var(mud::Id()) }, { "parent", Ref(type<toy::Entity>()) }, { "position", var(mud::vec3()) }, { "extents", var(mud::vec3()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<Crate>(), member_address(&Crate::m_entity), type<toy::Entity>(), "entity", Ref(type<toy::Entity>()), Member::Component, nullptr },
                { type<Crate>(), member_address(&Crate::m_movable), type<toy::Movable>(), "movable", Ref(type<toy::Movable>()), Member::Component, nullptr },
                { type<Crate>(), member_address(&Crate::m_extents), type<mud::vec3>(), "extents", var(mud::vec3()), Member::Value, nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        init_pool<Crate>(); 
        
        meta_class<Crate>();
    }
    
    
        
    // Human
    {
        static Meta meta = { type<Human>(), &namspc({}), "Human", sizeof(Human), TypeClass::Complex };
        static Class cls = { type<Human>(),
            // bases
            { &type<mud::Complex>(), &type<toy::ColliderObject>() },
            { base_offset<Human, mud::Complex>(), base_offset<Human, toy::ColliderObject>() },
            // constructors
            {
                { type<Human>(), [](Ref ref, array<Var> args) { new(&val<Human>(ref)) Human( val<mud::Id>(args[0]), val<toy::Entity>(args[1]), val<mud::vec3>(args[2]) ); }, { { "id", var(mud::Id()) }, { "parent", Ref(type<toy::Entity>()) }, { "position", var(mud::vec3()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<Human>(), member_address(&Human::m_entity), type<toy::Entity>(), "entity", Ref(type<toy::Entity>()), Member::Component, nullptr },
                { type<Human>(), member_address(&Human::m_movable), type<toy::Movable>(), "movable", Ref(type<toy::Movable>()), Member::Component, nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        init_pool<Human>(); 
        
        meta_class<Human>();
    }
    

    
        m.m_types.push_back(&type<Player>());
        m.m_types.push_back(&type<Bullet>());
        m.m_types.push_back(&type<Crate>());
        m.m_types.push_back(&type<Human>());
    
    }
}
