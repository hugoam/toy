

#pragma once

#ifndef MUD_MODULES
#include <meta/godot/Module.h>

#include <type/Any.h>
#include <type/Vector.h>
#include <refl/MetaDecl.h>
#include <refl/Module.h>
#endif

namespace mud
{
    void _godot_meta(Module& m)
    {   
    // Base Types
    
    // Enums
    {
        static Meta meta = { type<Faction>(), &namspc({}), "Faction", sizeof(Faction), TypeClass::Enum };
        static Enum enu = { type<Faction>(),
            true,
            { "Ally", "Enemy" },
            { 0, 1 },
            { var(Faction::Ally), var(Faction::Enemy) }
        };
        meta_enum<Faction>();
    }
    
    
    // Sequences
    
    
    
        
    // Aim
    {
        static Meta meta = { type<Aim>(), &namspc({}), "Aim", sizeof(Aim), TypeClass::Struct };
        static Class cls = { type<Aim>(),
            // bases
            {  },
            {  },
            // constructors
            {
            },
            // copy constructor
            {
                { type<Aim>(), [](Ref ref, Ref other) { new(&val<Aim>(ref)) Aim(val<Aim>(other)); } }
            },
            // members
            {
                { type<Aim>(), member_address(&Aim::rotation), type<mud::quat>(), "rotation", var(mud::quat()), Member::Value, nullptr },
                { type<Aim>(), member_address(&Aim::start), type<mud::vec3>(), "start", var(mud::vec3()), Member::Value, nullptr },
                { type<Aim>(), member_address(&Aim::end), type<mud::vec3>(), "end", var(mud::vec3()), Member::Value, nullptr },
                { type<Aim>(), member_address(&Aim::hit), type<toy::Spatial>(), "hit", Ref(type<toy::Spatial>()), Member::Flags(Member::Pointer|Member::Link), nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        
        
        meta_class<Aim>();
    }
    
    
    
        
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
    
    
        
    // Stance
    {
        static Meta meta = { type<Stance>(), &namspc({}), "Stance", sizeof(Stance), TypeClass::Struct };
        static Class cls = { type<Stance>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<Stance>(), [](Ref ref, array<Var> args) { UNUSED(args);new(&val<Stance>(ref)) Stance(  ); }, {} },
                { type<Stance>(), [](Ref ref, array<Var> args) { new(&val<Stance>(ref)) Stance( val<std::string>(args[0]), val<bool>(args[1]) ); }, { { "name", var(std::string()) }, { "loop", var(bool()) } } }
            },
            // copy constructor
            {
                { type<Stance>(), [](Ref ref, Ref other) { new(&val<Stance>(ref)) Stance(val<Stance>(other)); } }
            },
            // members
            {
                { type<Stance>(), member_address(&Stance::name), type<std::string>(), "name", var(std::string()), Member::Value, nullptr },
                { type<Stance>(), member_address(&Stance::loop), type<bool>(), "loop", var(bool()), Member::Value, nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        
        
        meta_class<Stance>();
    }
    
    
    
    
    
    
    
    
    
    
        
    // Lamp
    {
        static Meta meta = { type<Lamp>(), &namspc({}), "Lamp", sizeof(Lamp), TypeClass::Object };
        static Class cls = { type<Lamp>(),
            // bases
            { },
			{ },
            // constructors
            {
                //{ type<Lamp>(), [](Ref ref, array<Var> args) { new(&val<Lamp>(ref)) Lamp( val<toy::HSpatial>(args[1]), val<mud::vec3>(args[2]) ); }, { { "id", var(mud::Id()) }, { "parent", Ref(type<toy::Spatial>()) }, { "position", var(mud::vec3()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                //{ type<Lamp>(), member_address(&Lamp::m_spatial), type<toy::Spatial>(), "entity", Ref(type<toy::Spatial>()), Member::Component, nullptr },
                //{ type<Lamp>(), member_address(&Lamp::m_movable), type<toy::Movable>(), "movable", Ref(type<toy::Movable>()), Member::Component, nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        init_pool<Lamp>(); 
        
        meta_class<Lamp>();
    }
    
    
        
        
    // Bullet
    {
        static Meta meta = { type<Bullet>(), &namspc({}), "Bullet", sizeof(Bullet), TypeClass::Object };
        static Class cls = { type<Bullet>(),
            // bases
            { },
			{ },
            // constructors
            {
            },
            // copy constructor
            {
            },
            // members
            {
                //{ type<Bullet>(), member_address(&Bullet::m_spatial), type<toy::Spatial>(), "entity", Ref(type<toy::Spatial>()), Member::Component, nullptr },
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
        static Meta meta = { type<Crate>(), &namspc({}), "Crate", sizeof(Crate), TypeClass::Object };
        static Class cls = { type<Crate>(),
            // bases
            { },
			{ },
            // constructors
            {
                //{ type<Crate>(), [](Ref ref, array<Var> args) { new(&val<Crate>(ref)) Crate( val<toy::HSpatial>(args[1]), val<mud::vec3>(args[2]), val<mud::vec3>(args[3]) ); }, { { "id", var(mud::Id()) }, { "parent", Ref(type<toy::Spatial>()) }, { "position", var(mud::vec3()) }, { "extents", var(mud::vec3()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                //{ type<Crate>(), member_address(&Crate::m_spatial), type<toy::Spatial>(), "entity", Ref(type<toy::Spatial>()), Member::Component, nullptr },
                //{ type<Crate>(), member_address(&Crate::m_movable), type<toy::Movable>(), "movable", Ref(type<toy::Movable>()), Member::Component, nullptr },
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
        static Meta meta = { type<Human>(), &namspc({}), "Human", sizeof(Human), TypeClass::Object };
        static Class cls = { type<Human>(),
            // bases
            { },
			{ },
            // constructors
            {
                //{ type<Human>(), [](Ref ref, array<Var> args) { new(&val<Human>(ref)) Human( val<toy::HSpatial>(args[1]), val<mud::vec3>(args[2]), val<Faction>(args[3]) ); }, { { "id", var(mud::Id()) }, { "parent", Ref(type<toy::Spatial>()) }, { "position", var(mud::vec3()) }, { "faction", var(Faction()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                //{ type<Human>(), member_address(&Human::m_spatial), type<toy::Spatial>(), "entity", Ref(type<toy::Spatial>()), Member::Component, nullptr },
                //{ type<Human>(), member_address(&Human::m_movable), type<toy::Movable>(), "movable", Ref(type<toy::Movable>()), Member::Component, nullptr },
                //{ type<Human>(), member_address(&Human::m_emitter), type<toy::Emitter>(), "emitter", Ref(type<toy::Emitter>()), Member::Component, nullptr },
                //{ type<Human>(), member_address(&Human::m_receptor), type<toy::Receptor>(), "receptor", Ref(type<toy::Receptor>()), Member::Component, nullptr },
                //{ type<Human>(), member_address(&Human::m_script), type<toy::EntityScript>(), "script", Ref(type<toy::EntityScript>()), Member::Component, nullptr },
                { type<Human>(), member_address(&Human::m_faction), type<Faction>(), "faction", var(Faction()), Member::Value, nullptr },
                { type<Human>(), member_address(&Human::m_life), type<float>(), "life", var(float(1.f)), Member::Value, nullptr },
                { type<Human>(), member_address(&Human::m_energy), type<float>(), "energy", var(float(1.f)), Member::Value, nullptr },
                { type<Human>(), member_address(&Human::m_discharge), type<float>(), "discharge", var(float(0.f)), Member::Value, nullptr },
                { type<Human>(), member_address(&Human::m_headlight), type<bool>(), "headlight", var(bool(true)), Member::Value, nullptr },
                { type<Human>(), member_address(&Human::m_shield), type<bool>(), "shield", var(bool(false)), Member::Value, nullptr },
                { type<Human>(), member_address(&Human::m_walk), type<bool>(), "walk", var(bool(true)), Member::Value, nullptr },
                { type<Human>(), member_address(&Human::m_target), type<Human>(), "target", Ref(type<Human>()), Member::Flags(Member::Pointer|Member::Link), nullptr },
                { type<Human>(), member_address(&Human::m_dest), type<mud::vec3>(), "dest", var(mud::vec3()), Member::Value, nullptr },
                { type<Human>(), member_address(&Human::m_cooldown), type<float>(), "cooldown", var(float(0.f)), Member::Value, nullptr },
                { type<Human>(), member_address(&Human::m_state), type<Stance>(), "state", var(Stance()), Member::Value, nullptr }
            },
            // methods
            {
                { type<Human>(), "sight", member_address(&Human::sight), [](Ref object, array<Var> args, Var& result) { val<mud::quat>(result) = val<Human>(object).sight(val<bool>(args[0])); }, { { "aiming", var(bool(true)), Param::Default } }, var(mud::quat()) },
                { type<Human>(), "aim", member_address(&Human::aim), [](Ref object, array<Var> args, Var& result) { UNUSED(args);val<Aim>(result) = val<Human>(object).aim(); }, {}, var(Aim()) },
                { type<Human>(), "shoot", member_address(&Human::shoot), [](Ref object, array<Var> args, Var& result) { UNUSED(result); UNUSED(args);val<Human>(object).shoot(); }, {}, Var() },
                { type<Human>(), "stop", member_address(&Human::stop), [](Ref object, array<Var> args, Var& result) { UNUSED(result); UNUSED(args);val<Human>(object).stop(); }, {}, Var() }
            },
            // static members
            {
            }
        };
        
        
        init_pool<Human>(); 
        
        meta_class<Human>();
    }
    

    
        m.m_types.push_back(&type<Aim>());
        m.m_types.push_back(&type<Faction>());
        m.m_types.push_back(&type<Player>());
        m.m_types.push_back(&type<Stance>());
        m.m_types.push_back(&type<Lamp>());
        m.m_types.push_back(&type<Bullet>());
        m.m_types.push_back(&type<Crate>());
        m.m_types.push_back(&type<Human>());
    
    }
}
