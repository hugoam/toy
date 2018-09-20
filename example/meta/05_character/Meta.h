

#pragma once

#ifndef MUD_MODULES
#include <meta/05_character/Module.h>

#include <obj/Any.h>
#include <obj/Vector.h>
#include <refl/MetaDecl.h>
#include <refl/Module.h>
#endif

namespace mud
{
    void _05_character_meta(Module& m)
    {   
    // Base Types
    
    // Enums
    
    // Sequences
    
    
    
    
    
    
        
    // Walk
    {
        static Meta meta = { type<Walk>(), &namspc({}), "Walk", sizeof(Walk), TypeClass::Object };
        static Class cls = { type<Walk>(),
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
        
        
        
        
        meta_class<Walk>();
    }
    
    
        
    // Human
    {
        static Meta meta = { type<Human>(), &namspc({}), "Human", sizeof(Human), TypeClass::Entity };
        static Class cls = { type<Human>(),
            // bases
            { &type<mud::Entity>() },
            { base_offset<Human, mud::Entity>() },
            // constructors
            {
                { type<Human>(), [](Ref ref, array<Var> args) { new(&val<Human>(ref)) Human( val<toy::HSpatial>(args[1]), val<mud::vec3>(args[2]), val<float>(args[3]), val<float>(args[4]), val<std::string>(args[5]), val<std::string>(args[6]) ); }, { { "id", var(mud::Id()) }, { "parent", Ref(type<toy::Spatial>()) }, { "position", var(mud::vec3()) }, { "radius", var(float()) }, { "height", var(float()) }, { "first_name", var(std::string()) }, { "last_name", var(std::string()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<Human>(), member_address(&Human::m_spatial), type<toy::Spatial>(), "entity", Ref(type<toy::Spatial>()), Member::Component, nullptr },
                { type<Human>(), member_address(&Human::m_movable), type<toy::Movable>(), "movable", Ref(type<toy::Movable>()), Member::Component, nullptr },
                { type<Human>(), member_address(&Human::m_agent), type<toy::Agent>(), "agent", Ref(type<toy::Agent>()), Member::Component, nullptr },
                { type<Human>(), member_address(&Human::m_emitter), type<toy::Emitter>(), "emitter", Ref(type<toy::Emitter>()), Member::Component, nullptr },
                { type<Human>(), member_address(&Human::m_receptor), type<toy::Receptor>(), "receptor", Ref(type<toy::Receptor>()), Member::Component, nullptr },
                { type<Human>(), member_address(&Human::m_actor), type<toy::Actor>(), "actor", Ref(type<toy::Actor>()), Member::Component, nullptr },
                { type<Human>(), member_address(&Human::m_reactive), type<toy::Reactive>(), "reactive", Ref(type<toy::Reactive>()), Member::Component, nullptr },
                { type<Human>(), member_address(&Human::m_first_name), type<std::string>(), "first_name", var(std::string()), Member::Value, nullptr },
                { type<Human>(), member_address(&Human::m_last_name), type<std::string>(), "last_name", var(std::string()), Member::Value, nullptr },
                { type<Human>(), member_address(&Human::m_counter), type<float>(), "counter", var(float(0.f)), Member::Value, nullptr },
                { type<Human>(), member_address(&Human::m_next_change), type<float>(), "next_change", var(float()), Member::Value, nullptr }
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
    

    
        m.m_types.push_back(&type<Walk>());
        m.m_types.push_back(&type<Human>());
    
    }
}
