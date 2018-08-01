

#pragma once

#ifndef MUD_MODULES
#include <meta/core/Module.h>

#include <obj/Any.h>
#include <obj/Vector.h>
#include <refl/MetaDecl.h>
#include <refl/Module.h>
#endif

namespace mud
{
    void toy_core_meta(Module& m)
    {   
    // Base Types
    
    // Enums
    
    // Sequences
    {
        static Meta meta = { type<std::vector<mud::Symbol>>(), &namspc({}), "std::vector<mud::Symbol>", sizeof(std::vector<mud::Symbol>), TypeClass::Sequence };
        static Class cls = { type<std::vector<mud::Symbol>>() };
        cls.m_content = &type<mud::Symbol>();
        meta_sequence<std::vector<mud::Symbol>, mud::Symbol>();
    }
    
    {
        static Meta meta = { type<std::vector<toy::Entity*>>(), &namspc({}), "std::vector<toy::Entity*>", sizeof(std::vector<toy::Entity*>), TypeClass::Sequence };
        static Class cls = { type<std::vector<toy::Entity*>>() };
        cls.m_content = &type<toy::Entity>();
        meta_sequence<std::vector<toy::Entity*>, toy::Entity*>();
    }
    
    
    
    
        
    // toy::Active
    {
        static Meta meta = { type<toy::Active>(), &namspc({ "toy" }), "Active", sizeof(toy::Active), TypeClass::Object };
        static Class cls = { type<toy::Active>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<toy::Active>(), [](Ref ref, array<Var> args) { new(&val<toy::Active>(ref)) toy::Active( val<toy::Entity>(args[0]) ); }, { { "entity", Ref(type<toy::Entity>()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<toy::Active>(), Address(), type<toy::Entity>(), "entity", Ref(type<toy::Entity>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::Active>(object).m_entity); } }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        init_pool<toy::Active>(); 
        
        meta_class<toy::Active>();
    }
    
    
        
    // toy::Actor
    {
        static Meta meta = { type<toy::Actor>(), &namspc({ "toy" }), "Actor", sizeof(toy::Actor), TypeClass::Object };
        static Class cls = { type<toy::Actor>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<toy::Actor>(), [](Ref ref, array<Var> args) { new(&val<toy::Actor>(ref)) toy::Actor( val<toy::Entity>(args[0]) ); }, { { "entity", Ref(type<toy::Entity>()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<toy::Actor>(), Address(), type<toy::Entity>(), "entity", Ref(type<toy::Entity>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::Actor>(object).m_entity); } }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        init_pool<toy::Actor>(); 
        
        meta_class<toy::Actor>();
    }
    
    
        
    // toy::Agent
    {
        static Meta meta = { type<toy::Agent>(), &namspc({ "toy" }), "Agent", sizeof(toy::Agent), TypeClass::Object };
        static Class cls = { type<toy::Agent>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<toy::Agent>(), [](Ref ref, array<Var> args) { new(&val<toy::Agent>(ref)) toy::Agent( val<toy::Entity>(args[0]), val<float>(args[1]), val<float>(args[2]) ); }, { { "entity", Ref(type<toy::Entity>()) }, { "radius", var(float()) }, { "height", var(float()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<toy::Agent>(), Address(), type<toy::Entity>(), "entity", Ref(type<toy::Entity>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::Agent>(object).m_entity); } },
                { type<toy::Agent>(), member_address(&toy::Agent::m_radius), type<float>(), "radius", var(float()), Member::Value, nullptr },
                { type<toy::Agent>(), member_address(&toy::Agent::m_height), type<float>(), "height", var(float()), Member::Value, nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        init_pool<toy::Agent>(); 
        
        meta_class<toy::Agent>();
    }
    
    
        
    // toy::Array<toy::Action>
    {
        static Meta meta = { type<toy::Array<toy::Action>>(), &namspc({ "toy" }), "Array<toy::Action>", sizeof(toy::Array<toy::Action>), TypeClass::Object };
        static Class cls = { type<toy::Array<toy::Action>>(),
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
        
        
        
        
        meta_class<toy::Array<toy::Action>>();
    }
    
    
        
    // toy::Array<toy::Entity>
    {
        static Meta meta = { type<toy::Array<toy::Entity>>(), &namspc({ "toy" }), "Array<toy::Entity>", sizeof(toy::Array<toy::Entity>), TypeClass::Object };
        static Class cls = { type<toy::Array<toy::Entity>>(),
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
        
        
        
        
        meta_class<toy::Array<toy::Entity>>();
    }
    
    
    
        
    // toy::Behavior
    {
        static Meta meta = { type<toy::Behavior>(), &namspc({ "toy" }), "Behavior", sizeof(toy::Behavior), TypeClass::Object };
        static Class cls = { type<toy::Behavior>(),
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
                { type<toy::Behavior>(), Address(), type<mud::Type>(), "type", Ref(type<mud::Type>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::Behavior>(object).m_type); } }
            },
            // methods
            {
                { type<toy::Behavior>(), "sleep", member_address(&toy::Behavior::sleep), [](Ref object, array<Var> args, Var& result) { UNUSED(result); UNUSED(args);val<toy::Behavior>(object).sleep(); }, {}, Var() },
                { type<toy::Behavior>(), "wake", member_address(&toy::Behavior::wake), [](Ref object, array<Var> args, Var& result) { UNUSED(result); UNUSED(args);val<toy::Behavior>(object).wake(); }, {}, Var() }
            },
            // static members
            {
            }
        };
        
        
        
        
        meta_class<toy::Behavior>();
    }
    
    
    
        
    // toy::BufferPage
    {
        static Meta meta = { type<toy::BufferPage>(), &namspc({ "toy" }), "BufferPage", sizeof(toy::BufferPage), TypeClass::Object };
        static Class cls = { type<toy::BufferPage>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<toy::BufferPage>(), [](Ref ref, array<Var> args) { new(&val<toy::BufferPage>(ref)) toy::BufferPage( val<toy::Entity>(args[0]), val<toy::WorldPage>(args[1]), val<bool>(args[2]) ); }, { { "entity", Ref(type<toy::Entity>()) }, { "world_page", Ref(type<toy::WorldPage>()) }, { "loaded", var(bool(false)), Param::Default } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<toy::BufferPage>(), Address(), type<toy::Entity>(), "entity", Ref(type<toy::Entity>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::BufferPage>(object).m_entity); } },
                { type<toy::BufferPage>(), Address(), type<toy::WorldPage>(), "world_page", Ref(type<toy::WorldPage>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::BufferPage>(object).m_world_page); } },
                { type<toy::BufferPage>(), member_address(&toy::BufferPage::m_loaded), type<bool>(), "loaded", var(bool()), Member::Value, nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        init_pool<toy::BufferPage>(); 
        
        meta_class<toy::BufferPage>();
    }
    
    
        
    // toy::BulletShape
    {
        static Meta meta = { type<toy::BulletShape>(), &namspc({ "toy" }), "BulletShape", sizeof(toy::BulletShape), TypeClass::Object };
        static Class cls = { type<toy::BulletShape>(),
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
        
        
        
        
        meta_class<toy::BulletShape>();
    }
    
    
        
    // toy::Camera
    {
        static Meta meta = { type<toy::Camera>(), &namspc({ "toy" }), "Camera", sizeof(toy::Camera), TypeClass::Object };
        static Class cls = { type<toy::Camera>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<toy::Camera>(), [](Ref ref, array<Var> args) { new(&val<toy::Camera>(ref)) toy::Camera( val<toy::Entity>(args[0]), val<float>(args[1]), val<float>(args[2]), val<float>(args[3]) ); }, { { "entity", Ref(type<toy::Entity>()) }, { "lensDistance", var(float(1.f)), Param::Default }, { "near", var(float(0.001f)), Param::Default }, { "far", var(float(1000.f)), Param::Default } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<toy::Camera>(), Address(), type<toy::Entity>(), "entity", Ref(type<toy::Entity>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::Camera>(object).m_entity); } },
                { type<toy::Camera>(), member_address(&toy::Camera::m_lens_distance), type<float>(), "lens_distance", var(float(1.f)), Member::Value, nullptr },
                { type<toy::Camera>(), member_address(&toy::Camera::m_lens_angle), type<float>(), "lens_angle", var(float(0.f)), Member::Value, nullptr },
                { type<toy::Camera>(), member_address(&toy::Camera::m_near), type<float>(), "near", var(float(0.001f)), Member::Value, nullptr },
                { type<toy::Camera>(), member_address(&toy::Camera::m_far), type<float>(), "far", var(float(1000.f)), Member::Value, nullptr },
                { type<toy::Camera>(), member_address(&toy::Camera::m_aspect), type<float>(), "aspect", var(float()), Member::Value, nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        init_pool<toy::Camera>(); 
        
        meta_class<toy::Camera>();
    }
    
    
        
    // toy::Collider
    {
        static Meta meta = { type<toy::Collider>(), &namspc({ "toy" }), "Collider", sizeof(toy::Collider), TypeClass::Object };
        static Class cls = { type<toy::Collider>(),
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
                { type<toy::Collider>(), Address(), type<toy::Entity>(), "entity", Ref(type<toy::Entity>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::Collider>(object).m_entity); } },
                { type<toy::Collider>(), Address(), type<toy::Medium>(), "medium", Ref(type<toy::Medium>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::Collider>(object).m_medium); } }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        
        
        meta_class<toy::Collider>();
    }
    
    
        
    // toy::ColliderImpl
    {
        static Meta meta = { type<toy::ColliderImpl>(), &namspc({ "toy" }), "ColliderImpl", sizeof(toy::ColliderImpl), TypeClass::Object };
        static Class cls = { type<toy::ColliderImpl>(),
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
        
        
        
        
        meta_class<toy::ColliderImpl>();
    }
    
    
        
    // toy::ColliderObject
    {
        static Meta meta = { type<toy::ColliderObject>(), &namspc({ "toy" }), "ColliderObject", sizeof(toy::ColliderObject), TypeClass::Object };
        static Class cls = { type<toy::ColliderObject>(),
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
        
        
        
        
        meta_class<toy::ColliderObject>();
    }
    
    
        
    // toy::Collision
    {
        static Meta meta = { type<toy::Collision>(), &namspc({ "toy" }), "Collision", sizeof(toy::Collision), TypeClass::Struct };
        static Class cls = { type<toy::Collision>(),
            // bases
            {  },
            {  },
            // constructors
            {
            },
            // copy constructor
            {
                { type<toy::Collision>(), [](Ref ref, Ref other) { new(&val<toy::Collision>(ref)) toy::Collision(val<toy::Collision>(other)); } }
            },
            // members
            {
                { type<toy::Collision>(), member_address(&toy::Collision::m_first), type<toy::Collider>(), "first", Ref(type<toy::Collider>()), Member::Flags(Member::Pointer|Member::Link), nullptr },
                { type<toy::Collision>(), member_address(&toy::Collision::m_second), type<toy::Collider>(), "second", Ref(type<toy::Collider>()), Member::Flags(Member::Pointer|Member::Link), nullptr },
                { type<toy::Collision>(), member_address(&toy::Collision::m_hit_point), type<mud::vec3>(), "hit_point", var(mud::vec3()), Member::Value, nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        
        
        meta_class<toy::Collision>();
    }
    
    
        
    // toy::CollisionShape
    {
        static Meta meta = { type<toy::CollisionShape>(), &namspc({ "toy" }), "CollisionShape", sizeof(toy::CollisionShape), TypeClass::Object };
        static Class cls = { type<toy::CollisionShape>(),
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
        
        
        
        
        meta_class<toy::CollisionShape>();
    }
    
    
        
    // toy::ComponentPool
    {
        static Meta meta = { type<toy::ComponentPool>(), &namspc({ "toy" }), "ComponentPool", sizeof(toy::ComponentPool), TypeClass::Object };
        static Class cls = { type<toy::ComponentPool>(),
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
        
        
        
        
        meta_class<toy::ComponentPool>();
    }
    
    
    
    
    
        
    // toy::Core
    {
        static Meta meta = { type<toy::Core>(), &namspc({ "toy" }), "Core", sizeof(toy::Core), TypeClass::Object };
        static Class cls = { type<toy::Core>(),
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
        
        
        
        
        meta_class<toy::Core>();
    }
    
    
        
    // toy::DetourPath
    {
        static Meta meta = { type<toy::DetourPath>(), &namspc({ "toy" }), "DetourPath", sizeof(toy::DetourPath), TypeClass::Object };
        static Class cls = { type<toy::DetourPath>(),
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
        
        
        
        
        meta_class<toy::DetourPath>();
    }
    
    
    
        
    // toy::Effect
    {
        static Meta meta = { type<toy::Effect>(), &namspc({ "toy" }), "Effect", sizeof(toy::Effect), TypeClass::Object };
        static Class cls = { type<toy::Effect>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<toy::Effect>(), [](Ref ref, array<Var> args) { new(&val<toy::Effect>(ref)) toy::Effect( val<toy::Active>(args[0]), val<std::string>(args[1]), val<float>(args[2]), val<bool>(args[3]) ); }, { { "active", Ref(type<toy::Active>()) }, { "name", var(std::string()) }, { "duration", var(float(0.f)), Param::Default }, { "loop", var(bool(true)), Param::Default } } }
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
        
        
        init_pool<toy::Effect>(); 
        
        meta_class<toy::Effect>();
    }
    
    
    
        
    // toy::Emitter
    {
        static Meta meta = { type<toy::Emitter>(), &namspc({ "toy" }), "Emitter", sizeof(toy::Emitter), TypeClass::Object };
        static Class cls = { type<toy::Emitter>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<toy::Emitter>(), [](Ref ref, array<Var> args) { new(&val<toy::Emitter>(ref)) toy::Emitter( val<toy::Entity>(args[0]) ); }, { { "entity", Ref(type<toy::Entity>()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<toy::Emitter>(), Address(), type<toy::Entity>(), "entity", Ref(type<toy::Entity>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::Emitter>(object).m_entity); } }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        init_pool<toy::Emitter>(); 
        
        meta_class<toy::Emitter>();
    }
    
    
        
    // toy::EntityScript
    {
        static Meta meta = { type<toy::EntityScript>(), &namspc({ "toy" }), "EntityScript", sizeof(toy::EntityScript), TypeClass::Object };
        static Class cls = { type<toy::EntityScript>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<toy::EntityScript>(), [](Ref ref, array<Var> args) { new(&val<toy::EntityScript>(ref)) toy::EntityScript( val<toy::Entity>(args[0]) ); }, { { "entity", Ref(type<toy::Entity>()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<toy::EntityScript>(), Address(), type<toy::Entity>(), "entity", Ref(type<toy::Entity>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::EntityScript>(object).m_entity); } },
                { type<toy::EntityScript>(), member_address(&toy::EntityScript::m_logic_script), type<mud::Script>(), "logic_script", Ref(type<mud::Script>()), Member::Flags(Member::Pointer|Member::Link), nullptr },
                { type<toy::EntityScript>(), member_address(&toy::EntityScript::m_render_script), type<mud::Script>(), "render_script", Ref(type<mud::Script>()), Member::Flags(Member::Pointer|Member::Link), nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        init_pool<toy::EntityScript>(); 
        
        meta_class<toy::EntityScript>();
    }
    
    
    
        
    // toy::EventFilter
    {
        static Meta meta = { type<toy::EventFilter>(), &namspc({ "toy" }), "EventFilter", sizeof(toy::EventFilter), TypeClass::Object };
        static Class cls = { type<toy::EventFilter>(),
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
        
        
        
        
        meta_class<toy::EventFilter>();
    }
    
    
    
        
    // toy::EventRelay
    {
        static Meta meta = { type<toy::EventRelay>(), &namspc({ "toy" }), "EventRelay", sizeof(toy::EventRelay), TypeClass::Object };
        static Class cls = { type<toy::EventRelay>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<toy::EventRelay>(), [](Ref ref, array<Var> args) { new(&val<toy::EventRelay>(ref)) toy::EventRelay( val<toy::Entity>(args[0]) ); }, { { "entity", Ref(type<toy::Entity>()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<toy::EventRelay>(), Address(), type<toy::Entity>(), "entity", Ref(type<toy::Entity>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::EventRelay>(object).m_entity); } }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        init_pool<toy::EventRelay>(); 
        
        meta_class<toy::EventRelay>();
    }
    
    
    
    
    
    
    
        
    // toy::GroundMotion
    {
        static Meta meta = { type<toy::GroundMotion>(), &namspc({ "toy" }), "GroundMotion", sizeof(toy::GroundMotion), TypeClass::Object };
        static Class cls = { type<toy::GroundMotion>(),
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
        
        
        
        
        meta_class<toy::GroundMotion>();
    }
    
    
    
        
    // toy::LightReflector
    {
        static Meta meta = { type<toy::LightReflector>(), &namspc({ "toy" }), "LightReflector", sizeof(toy::LightReflector), TypeClass::Object };
        static Class cls = { type<toy::LightReflector>(),
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
                { type<toy::LightReflector>(), Address(), type<toy::Entity>(), "entity", Ref(type<toy::Entity>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::LightReflector>(object).m_entity); } },
                { type<toy::LightReflector>(), member_address(&toy::LightReflector::m_brightness), type<mud::Ratio>(), "brightness", var(mud::Ratio()), Member::Value, nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        
        
        meta_class<toy::LightReflector>();
    }
    
    
        
    // toy::LightSource
    {
        static Meta meta = { type<toy::LightSource>(), &namspc({ "toy" }), "LightSource", sizeof(toy::LightSource), TypeClass::Object };
        static Class cls = { type<toy::LightSource>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<toy::LightSource>(), [](Ref ref, array<Var> args) { new(&val<toy::LightSource>(ref)) toy::LightSource( val<toy::Entity>(args[0]), val<toy::Emitter>(args[1]), val<float>(args[2]), val<float>(args[3]), val<mud::Colour>(args[4]), val<bool>(args[5]) ); }, { { "entity", Ref(type<toy::Entity>()) }, { "emitter", Ref(type<toy::Emitter>()) }, { "range", var(float()) }, { "intensity", var(float()) }, { "colour", var(mud::Colour()) }, { "shadows", var(bool()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<toy::LightSource>(), Address(), type<toy::Entity>(), "entity", Ref(type<toy::Entity>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::LightSource>(object).m_entity); } },
                { type<toy::LightSource>(), Address(), type<toy::Emitter>(), "emitter", Ref(type<toy::Emitter>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::LightSource>(object).m_emitter); } },
                { type<toy::LightSource>(), member_address(&toy::LightSource::m_range), type<float>(), "range", var(float()), Member::Value, nullptr },
                { type<toy::LightSource>(), member_address(&toy::LightSource::m_intensity), type<float>(), "intensity", var(float()), Member::Value, nullptr },
                { type<toy::LightSource>(), member_address(&toy::LightSource::m_colour), type<mud::Colour>(), "colour", var(mud::Colour()), Member::Value, nullptr },
                { type<toy::LightSource>(), member_address(&toy::LightSource::m_shadows), type<bool>(), "shadows", var(bool()), Member::Value, nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        init_pool<toy::LightSource>(); 
        
        meta_class<toy::LightSource>();
    }
    
    
        
    // toy::Medium
    {
        static Meta meta = { type<toy::Medium>(), &namspc({ "toy" }), "Medium", sizeof(toy::Medium), TypeClass::Object };
        static Class cls = { type<toy::Medium>(),
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
                { type<toy::Medium>(), member_address(&toy::Medium::m_name), type<std::string>(), "name", var(std::string()), Member::Value, nullptr },
                { type<toy::Medium>(), member_address(&toy::Medium::m_occlusions), type<bool>(), "occlusions", var(bool()), Member::Value, nullptr },
                { type<toy::Medium>(), member_address(&toy::Medium::m_solid), type<bool>(), "solid", var(bool()), Member::Value, nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        
        
        meta_class<toy::Medium>();
    }
    
    
    
    
    
    
        
    // toy::Movable
    {
        static Meta meta = { type<toy::Movable>(), &namspc({ "toy" }), "Movable", sizeof(toy::Movable), TypeClass::Object };
        static Class cls = { type<toy::Movable>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<toy::Movable>(), [](Ref ref, array<Var> args) { new(&val<toy::Movable>(ref)) toy::Movable( val<toy::Entity>(args[0]) ); }, { { "entity", Ref(type<toy::Entity>()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<toy::Movable>(), Address(), type<toy::Entity>(), "entity", Ref(type<toy::Entity>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::Movable>(object).m_entity); } },
                { type<toy::Movable>(), member_address(&toy::Movable::m_linear_velocity), type<mud::vec3>(), "linear_velocity", var(mud::vec3()), Member::Value, nullptr },
                { type<toy::Movable>(), member_address(&toy::Movable::m_angular_velocity), type<mud::vec3>(), "angular_velocity", var(mud::vec3()), Member::Value, nullptr },
                { type<toy::Movable>(), member_address(&toy::Movable::m_moving), type<bool>(), "moving", var(bool(false)), Member::Value, nullptr },
                { type<toy::Movable>(), member_address(&toy::Movable::m_previous_position), type<mud::vec3>(), "previous_position", var(mud::vec3()), Member::Value, nullptr }
            },
            // methods
            {
                { type<toy::Movable>(), "set_linear_velocity", member_address(&toy::Movable::set_linear_velocity), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::Movable>(object).set_linear_velocity(val<mud::vec3>(args[0])); }, { { "velocity", var(mud::vec3()) } }, Var() },
                { type<toy::Movable>(), "modify_linear_velocity", member_address(&toy::Movable::modify_linear_velocity), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::Movable>(object).modify_linear_velocity(val<mud::vec3>(args[0])); }, { { "velocity", var(mud::vec3()) } }, Var() },
                { type<toy::Movable>(), "set_angular_velocity", member_address(&toy::Movable::set_angular_velocity), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::Movable>(object).set_angular_velocity(val<mud::vec3>(args[0])); }, { { "velocity", var(mud::vec3()) } }, Var() },
                { type<toy::Movable>(), "modify_angular_velocity", member_address(&toy::Movable::modify_angular_velocity), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::Movable>(object).modify_angular_velocity(val<mud::vec3>(args[0])); }, { { "velocity", var(mud::vec3()) } }, Var() }
            },
            // static members
            {
            }
        };
        
        
        init_pool<toy::Movable>(); 
        
        meta_class<toy::Movable>();
    }
    
    
    
        
    // toy::Navblock
    {
        static Meta meta = { type<toy::Navblock>(), &namspc({ "toy" }), "Navblock", sizeof(toy::Navblock), TypeClass::Object };
        static Class cls = { type<toy::Navblock>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<toy::Navblock>(), [](Ref ref, array<Var> args) { new(&val<toy::Navblock>(ref)) toy::Navblock( val<toy::Navmesh>(args[0]), val<toy::Entity>(args[1]), val<toy::WorldPage>(args[2]) ); }, { { "navmesh", Ref(type<toy::Navmesh>()) }, { "entity", Ref(type<toy::Entity>()) }, { "world_page", Ref(type<toy::WorldPage>()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<toy::Navblock>(), Address(), type<toy::Entity>(), "entity", Ref(type<toy::Entity>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::Navblock>(object).m_entity); } },
                { type<toy::Navblock>(), Address(), type<toy::WorldPage>(), "world_page", Ref(type<toy::WorldPage>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::Navblock>(object).m_world_page); } },
                { type<toy::Navblock>(), Address(), type<toy::Navmesh>(), "navmesh", Ref(type<toy::Navmesh>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::Navblock>(object).m_navmesh); } },
                { type<toy::Navblock>(), member_address(&toy::Navblock::m_auto_update), type<bool>(), "auto_update", var(bool(false)), Member::Value, nullptr },
                { type<toy::Navblock>(), member_address(&toy::Navblock::m_updated), type<size_t>(), "updated", var(size_t()), Member::Value, nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        init_pool<toy::Navblock>(); 
        
        meta_class<toy::Navblock>();
    }
    
    
        
    // toy::Navmesh
    {
        static Meta meta = { type<toy::Navmesh>(), &namspc({ "toy" }), "Navmesh", sizeof(toy::Navmesh), TypeClass::Object };
        static Class cls = { type<toy::Navmesh>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<toy::Navmesh>(), [](Ref ref, array<Var> args) { new(&val<toy::Navmesh>(ref)) toy::Navmesh( val<toy::World>(args[0]) ); }, { { "world", Ref(type<toy::World>()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<toy::Navmesh>(), Address(), type<toy::World>(), "world", Ref(type<toy::World>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::Navmesh>(object).m_world); } },
                { type<toy::Navmesh>(), member_address(&toy::Navmesh::m_updated), type<size_t>(), "updated", var(size_t()), Member::Value, nullptr },
                { type<toy::Navmesh>(), member_address(&toy::Navmesh::m_dirty), type<bool>(), "dirty", var(bool(false)), Member::Value, nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        init_pool<toy::Navmesh>(); 
        
        meta_class<toy::Navmesh>();
    }
    
    
    
        
    // toy::Obstacle
    {
        static Meta meta = { type<toy::Obstacle>(), &namspc({ "toy" }), "Obstacle", sizeof(toy::Obstacle), TypeClass::Object };
        static Class cls = { type<toy::Obstacle>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<toy::Obstacle>(), [](Ref ref, array<Var> args) { new(&val<toy::Obstacle>(ref)) toy::Obstacle( val<toy::Entity>(args[0]), val<toy::CollisionShape>(args[1]) ); }, { { "entity", Ref(type<toy::Entity>()) }, { "shape", Ref(type<toy::CollisionShape>()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<toy::Obstacle>(), Address(), type<toy::Entity>(), "entity", Ref(type<toy::Entity>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::Obstacle>(object).m_entity); } },
                { type<toy::Obstacle>(), member_address(&toy::Obstacle::m_shape), type<toy::CollisionShape>(), "shape", Ref(type<toy::CollisionShape>()), Member::None, nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        init_pool<toy::Obstacle>(); 
        
        meta_class<toy::Obstacle>();
    }
    
    
        
    // toy::Pathfinder
    {
        static Meta meta = { type<toy::Pathfinder>(), &namspc({ "toy" }), "Pathfinder", sizeof(toy::Pathfinder), TypeClass::Object };
        static Class cls = { type<toy::Pathfinder>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<toy::Pathfinder>(), [](Ref ref, array<Var> args) { new(&val<toy::Pathfinder>(ref)) toy::Pathfinder( val<toy::Navmesh>(args[0]) ); }, { { "navmesh", Ref(type<toy::Navmesh>()) } } }
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
        
        
        init_pool<toy::Pathfinder>(); 
        
        meta_class<toy::Pathfinder>();
    }
    
    
    
    
        
    // toy::PhysicWorld
    {
        static Meta meta = { type<toy::PhysicWorld>(), &namspc({ "toy" }), "PhysicWorld", sizeof(toy::PhysicWorld), TypeClass::Object };
        static Class cls = { type<toy::PhysicWorld>(),
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
                { type<toy::PhysicWorld>(), Address(), type<toy::World>(), "world", Ref(type<toy::World>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::PhysicWorld>(object).m_world); } }
            },
            // methods
            {
                { type<toy::PhysicWorld>(), "ground_point", member_address(&toy::PhysicWorld::ground_point), [](Ref object, array<Var> args, Var& result) { val<mud::vec3>(result) = val<toy::PhysicWorld>(object).ground_point(val<mud::Ray>(args[0])); }, { { "ray", var(mud::Ray()) } }, var(mud::vec3()) },
                { type<toy::PhysicWorld>(), "raycast", member_address(&toy::PhysicWorld::raycast), [](Ref object, array<Var> args, Var& result) { val<toy::Collision>(result) = val<toy::PhysicWorld>(object).raycast(val<mud::Ray>(args[0]), val<short>(args[1])); }, { { "ray", var(mud::Ray()) }, { "mask", var(short()) } }, var(toy::Collision()) }
            },
            // static members
            {
            }
        };
        
        
        
        
        meta_class<toy::PhysicWorld>();
    }
    
    
        
    // toy::Reactive
    {
        static Meta meta = { type<toy::Reactive>(), &namspc({ "toy" }), "Reactive", sizeof(toy::Reactive), TypeClass::Object };
        static Class cls = { type<toy::Reactive>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<toy::Reactive>(), [](Ref ref, array<Var> args) { new(&val<toy::Reactive>(ref)) toy::Reactive( val<toy::Entity>(args[0]) ); }, { { "entity", Ref(type<toy::Entity>()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<toy::Reactive>(), Address(), type<toy::Entity>(), "entity", Ref(type<toy::Entity>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::Reactive>(object).m_entity); } },
                { type<toy::Reactive>(), member_address(&toy::Reactive::m_controller), type<toy::Behavior>(), "controller", Ref(type<toy::Behavior>()), Member::Flags(Member::Pointer|Member::Link), nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        init_pool<toy::Reactive>(); 
        
        meta_class<toy::Reactive>();
    }
    
    
        
    // toy::Receptor
    {
        static Meta meta = { type<toy::Receptor>(), &namspc({ "toy" }), "Receptor", sizeof(toy::Receptor), TypeClass::Object };
        static Class cls = { type<toy::Receptor>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<toy::Receptor>(), [](Ref ref, array<Var> args) { new(&val<toy::Receptor>(ref)) toy::Receptor( val<toy::Entity>(args[0]) ); }, { { "entity", Ref(type<toy::Entity>()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<toy::Receptor>(), Address(), type<toy::Entity>(), "entity", Ref(type<toy::Entity>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::Receptor>(object).m_entity); } }
            },
            // methods
            {
                { type<toy::Receptor>(), "scope", member_address(&toy::Receptor::scope), [](Ref object, array<Var> args, Var& result) { result = Ref(val<toy::Receptor>(object).scope(val<toy::Medium>(args[0]))); }, { { "medium", Ref(type<toy::Medium>()) } }, Ref(type<toy::ReceptorScope>()) }
            },
            // static members
            {
            }
        };
        
        
        init_pool<toy::Receptor>(); 
        
        meta_class<toy::Receptor>();
    }
    
    
        
    // toy::Selector
    {
        static Meta meta = { type<toy::Selector>(), &namspc({ "toy" }), "Selector", sizeof(toy::Selector), TypeClass::Object };
        static Class cls = { type<toy::Selector>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<toy::Selector>(), [](Ref ref, array<Var> args) { new(&val<toy::Selector>(ref)) toy::Selector( val<toy::User>(args[0]) ); }, { { "user", Ref(type<toy::User>()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<toy::Selector>(), Address(), type<toy::User>(), "user", Ref(type<toy::User>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::Selector>(object).m_user); } }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        init_pool<toy::Selector>(); 
        
        meta_class<toy::Selector>();
    }
    
    
    
        
    // toy::State
    {
        static Meta meta = { type<toy::State>(), &namspc({ "toy" }), "State", sizeof(toy::State), TypeClass::Object };
        static Class cls = { type<toy::State>(),
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
        
        
        
        
        meta_class<toy::State>();
    }
    
    
    
    
        
    // toy::SubBulletWorld
    {
        static Meta meta = { type<toy::SubBulletWorld>(), &namspc({ "toy" }), "SubBulletWorld", sizeof(toy::SubBulletWorld), TypeClass::Object };
        static Class cls = { type<toy::SubBulletWorld>(),
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
        
        
        
        
        meta_class<toy::SubBulletWorld>();
    }
    
    
        
    // toy::Symbolic
    {
        static Meta meta = { type<toy::Symbolic>(), &namspc({ "toy" }), "Symbolic", sizeof(toy::Symbolic), TypeClass::Object };
        static Class cls = { type<toy::Symbolic>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<toy::Symbolic>(), [](Ref ref, array<Var> args) { new(&val<toy::Symbolic>(ref)) toy::Symbolic( val<toy::Entity>(args[0]), val<std::vector<mud::Symbol>>(args[1]) ); }, { { "entity", Ref(type<toy::Entity>()) }, { "shapes", var(std::vector<mud::Symbol>()), Param::Default } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<toy::Symbolic>(), Address(), type<toy::Entity>(), "entity", Ref(type<toy::Entity>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::Symbolic>(object).m_entity); } },
                { type<toy::Symbolic>(), member_address(&toy::Symbolic::m_symbols), type<std::vector<mud::Symbol>>(), "symbols", var(std::vector<mud::Symbol>()), Member::Value, nullptr },
                { type<toy::Symbolic>(), member_address(&toy::Symbolic::m_updated), type<size_t>(), "updated", var(size_t()), Member::Value, nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        init_pool<toy::Symbolic>(); 
        
        meta_class<toy::Symbolic>();
    }
    
    
    
        
    // toy::TaskSection
    {
        static Meta meta = { type<toy::TaskSection>(), &namspc({ "toy" }), "TaskSection", sizeof(toy::TaskSection), TypeClass::Object };
        static Class cls = { type<toy::TaskSection>(),
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
        
        
        
        
        meta_class<toy::TaskSection>();
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
        
    // toy::User
    {
        static Meta meta = { type<toy::User>(), &namspc({ "toy" }), "User", sizeof(toy::User), TypeClass::Object };
        static Class cls = { type<toy::User>(),
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
        
        
        
        
        meta_class<toy::User>();
    }
    
    
        
    // toy::View
    {
        static Meta meta = { type<toy::View>(), &namspc({ "toy" }), "View", sizeof(toy::View), TypeClass::Object };
        static Class cls = { type<toy::View>(),
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
                { type<toy::View>(), Address(), type<mud::Type>(), "type", Ref(type<mud::Type>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::View>(object).m_type); } }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        
        
        meta_class<toy::View>();
    }
    
    
        
    // toy::Vision
    {
        static Meta meta = { type<toy::Vision>(), &namspc({ "toy" }), "Vision", sizeof(toy::Vision), TypeClass::Object };
        static Class cls = { type<toy::Vision>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<toy::Vision>(), [](Ref ref, array<Var> args) { new(&val<toy::Vision>(ref)) toy::Vision( val<toy::World>(args[0]) ); }, { { "world", Ref(type<toy::World>()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<toy::Vision>(), Address(), type<toy::World>(), "world", Ref(type<toy::World>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::Vision>(object).m_world); } },
                { type<toy::Vision>(), member_address(&toy::Vision::m_player), type<mud::Ref>(), "player", Ref(type<mud::Ref>()), Member::None, nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        init_pool<toy::Vision>(); 
        
        meta_class<toy::Vision>();
    }
    
    
        
    // toy::World
    {
        static Meta meta = { type<toy::World>(), &namspc({ "toy" }), "World", sizeof(toy::World), TypeClass::Object };
        static Class cls = { type<toy::World>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<toy::World>(), [](Ref ref, array<Var> args) { new(&val<toy::World>(ref)) toy::World( val<mud::Id>(args[0]), val<mud::Complex>(args[1]), val<std::string>(args[2]) ); }, { { "id", var(mud::Id()) }, { "complex", Ref(type<mud::Complex>()) }, { "name", var(std::string()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<toy::World>(), member_address(&toy::World::m_id), type<mud::Id>(), "id", var(mud::Id()), Member::Value, nullptr },
                { type<toy::World>(), Address(), type<mud::Complex>(), "complex", Ref(type<mud::Complex>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::World>(object).m_complex); } },
                { type<toy::World>(), member_address(&toy::World::m_name), type<std::string>(), "name", var(std::string()), Member::Value, nullptr },
                { type<toy::World>(), member_address(&toy::World::origin), type<toy::Entity>(), "origin", Ref(type<toy::Entity>()), Member::Flags(Member::NonMutable|Member::Structure|Member::Link), [](Ref object) { return Ref(&val<toy::World>(object).origin()); } },
                { type<toy::World>(), member_address(&toy::World::unworld), type<toy::Entity>(), "unworld", Ref(type<toy::Entity>()), Member::Flags(Member::NonMutable|Member::Structure|Member::Link), [](Ref object) { return Ref(&val<toy::World>(object).unworld()); } }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        init_pool<toy::World>(); 
        
        meta_class<toy::World>();
    }
    
    
        
    // toy::WorldClock
    {
        static Meta meta = { type<toy::WorldClock>(), &namspc({ "toy" }), "WorldClock", sizeof(toy::WorldClock), TypeClass::Object };
        static Class cls = { type<toy::WorldClock>(),
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
        
        
        
        
        meta_class<toy::WorldClock>();
    }
    
    
    
    
    
    
        
    // toy::Entity
    {
        static Meta meta = { type<toy::Entity>(), &namspc({ "toy" }), "Entity", sizeof(toy::Entity), TypeClass::Object };
        static Class cls = { type<toy::Entity>(),
            // bases
            { &type<mud::Transform>() },
            { base_offset<toy::Entity, mud::Transform>() },
            // constructors
            {
                { type<toy::Entity>(), [](Ref ref, array<Var> args) { new(&val<toy::Entity>(ref)) toy::Entity( val<mud::Id>(args[0]), val<mud::Complex>(args[1]), val<toy::Entity>(args[2]), val<mud::vec3>(args[3]), val<mud::quat>(args[4]) ); }, { { "id", var(mud::Id()) }, { "complex", Ref(type<mud::Complex>()) }, { "parent", Ref(type<toy::Entity>()) }, { "position", var(mud::vec3()) }, { "rotation", var(mud::quat()) } } },
                { type<toy::Entity>(), [](Ref ref, array<Var> args) { new(&val<toy::Entity>(ref)) toy::Entity( val<mud::Id>(args[0]), val<mud::Complex>(args[1]), val<toy::World>(args[2]), &val<toy::Entity>(args[3]), val<mud::vec3>(args[4]), val<mud::quat>(args[5]) ); }, { { "id", var(mud::Id()) }, { "complex", Ref(type<mud::Complex>()) }, { "world", Ref(type<toy::World>()) }, { "parent", Ref(type<toy::Entity>()), Param::Nullable }, { "position", var(mud::vec3()) }, { "rotation", var(mud::quat()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<toy::Entity>(), member_address(&toy::Entity::m_id), type<mud::Id>(), "id", var(mud::Id()), Member::Value, nullptr },
                { type<toy::Entity>(), Address(), type<mud::Complex>(), "complex", Ref(type<mud::Complex>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::Entity>(object).m_complex); } },
                { type<toy::Entity>(), Address(), type<toy::World>(), "world", Ref(type<toy::World>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::Entity>(object).m_world); } },
                { type<toy::Entity>(), member_address(&toy::Entity::m_parent), type<toy::Entity>(), "parent", Ref(type<toy::Entity>()), Member::Flags(Member::Pointer|Member::Link), nullptr },
                { type<toy::Entity>(), member_address(&toy::Entity::m_contents), type<toy::Array<toy::Entity>>(), "contents", Ref(type<toy::Array<toy::Entity>>()), Member::Structure, nullptr }
            },
            // methods
            {
                { type<toy::Entity>(), "set_position", member_address(&toy::Entity::set_position), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::Entity>(object).set_position(val<mud::vec3>(args[0])); }, { { "position", var(mud::vec3()) } }, Var() },
                { type<toy::Entity>(), "set_rotation", member_address(&toy::Entity::set_rotation), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::Entity>(object).set_rotation(val<mud::quat>(args[0])); }, { { "rotation", var(mud::quat()) } }, Var() }
            },
            // static members
            {
            }
        };
        
        
        init_pool<toy::Entity>(); 
        
        meta_class<toy::Entity>();
    }
    
    
        
    // toy::DefaultWorld
    {
        static Meta meta = { type<toy::DefaultWorld>(), &namspc({ "toy" }), "DefaultWorld", sizeof(toy::DefaultWorld), TypeClass::Complex };
        static Class cls = { type<toy::DefaultWorld>(),
            // bases
            { &type<mud::Complex>() },
            { base_offset<toy::DefaultWorld, mud::Complex>() },
            // constructors
            {
                { type<toy::DefaultWorld>(), [](Ref ref, array<Var> args) { new(&val<toy::DefaultWorld>(ref)) toy::DefaultWorld( val<std::string>(args[0]) ); }, { { "name", var(std::string()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<toy::DefaultWorld>(), member_address(&toy::DefaultWorld::m_world), type<toy::World>(), "world", Ref(type<toy::World>()), Member::Component, nullptr },
                { type<toy::DefaultWorld>(), member_address(&toy::DefaultWorld::m_bullet_world), type<toy::BulletWorld>(), "bullet_world", Ref(type<toy::BulletWorld>()), Member::Component, nullptr },
                { type<toy::DefaultWorld>(), member_address(&toy::DefaultWorld::m_navmesh), type<toy::Navmesh>(), "navmesh", Ref(type<toy::Navmesh>()), Member::Component, nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        init_pool<toy::DefaultWorld>(); 
        
        meta_class<toy::DefaultWorld>();
    }
    
    
        
    // toy::OCamera
    {
        static Meta meta = { type<toy::OCamera>(), &namspc({ "toy" }), "OCamera", sizeof(toy::OCamera), TypeClass::Complex };
        static Class cls = { type<toy::OCamera>(),
            // bases
            { &type<mud::Complex>() },
            { base_offset<toy::OCamera, mud::Complex>() },
            // constructors
            {
                { type<toy::OCamera>(), [](Ref ref, array<Var> args) { new(&val<toy::OCamera>(ref)) toy::OCamera( val<mud::Id>(args[0]), val<toy::Entity>(args[1]), val<mud::vec3>(args[2]), val<float>(args[3]), val<float>(args[4]), val<float>(args[5]) ); }, { { "id", var(mud::Id()) }, { "parent", Ref(type<toy::Entity>()) }, { "position", var(mud::vec3()) }, { "lensDistance", var(float()) }, { "nearClipDistance", var(float(0.001f)), Param::Default }, { "farClipDistance", var(float(1000.f)), Param::Default } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<toy::OCamera>(), member_address(&toy::OCamera::m_entity), type<toy::Entity>(), "entity", Ref(type<toy::Entity>()), Member::Component, nullptr },
                { type<toy::OCamera>(), member_address(&toy::OCamera::m_movable), type<toy::Movable>(), "movable", Ref(type<toy::Movable>()), Member::Component, nullptr },
                { type<toy::OCamera>(), member_address(&toy::OCamera::m_receptor), type<toy::Receptor>(), "receptor", Ref(type<toy::Receptor>()), Member::Component, nullptr },
                { type<toy::OCamera>(), member_address(&toy::OCamera::m_camera), type<toy::Camera>(), "camera", Ref(type<toy::Camera>()), Member::Component, nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        init_pool<toy::OCamera>(); 
        
        meta_class<toy::OCamera>();
    }
    
    
        
    // toy::OLight
    {
        static Meta meta = { type<toy::OLight>(), &namspc({ "toy" }), "OLight", sizeof(toy::OLight), TypeClass::Complex };
        static Class cls = { type<toy::OLight>(),
            // bases
            { &type<mud::Complex>() },
            { base_offset<toy::OLight, mud::Complex>() },
            // constructors
            {
                { type<toy::OLight>(), [](Ref ref, array<Var> args) { new(&val<toy::OLight>(ref)) toy::OLight( val<mud::Id>(args[0]), val<toy::Entity>(args[1]), val<mud::vec3>(args[2]), val<float>(args[3]), val<float>(args[4]), val<mud::Colour>(args[5]), val<bool>(args[6]) ); }, { { "id", var(mud::Id()) }, { "parent", Ref(type<toy::Entity>()) }, { "position", var(mud::vec3()) }, { "range", var(float(10.f)), Param::Default }, { "intensity", var(float(1.f)), Param::Default }, { "colour", var(mud::Colour()), Param::Default }, { "shadows", var(bool(false)), Param::Default } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<toy::OLight>(), member_address(&toy::OLight::m_entity), type<toy::Entity>(), "entity", Ref(type<toy::Entity>()), Member::Component, nullptr },
                { type<toy::OLight>(), member_address(&toy::OLight::m_emitter), type<toy::Emitter>(), "emitter", Ref(type<toy::Emitter>()), Member::Component, nullptr },
                { type<toy::OLight>(), member_address(&toy::OLight::m_light), type<toy::LightSource>(), "light", Ref(type<toy::LightSource>()), Member::Component, nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        init_pool<toy::OLight>(); 
        
        meta_class<toy::OLight>();
    }
    
    
        
    // toy::OWaypoint
    {
        static Meta meta = { type<toy::OWaypoint>(), &namspc({ "toy" }), "OWaypoint", sizeof(toy::OWaypoint), TypeClass::Complex };
        static Class cls = { type<toy::OWaypoint>(),
            // bases
            { &type<mud::Complex>() },
            { base_offset<toy::OWaypoint, mud::Complex>() },
            // constructors
            {
                { type<toy::OWaypoint>(), [](Ref ref, array<Var> args) { new(&val<toy::OWaypoint>(ref)) toy::OWaypoint( val<mud::Id>(args[0]), val<toy::Entity>(args[1]), val<mud::vec3>(args[2]) ); }, { { "id", var(mud::Id()) }, { "parent", Ref(type<toy::Entity>()) }, { "position", var(mud::vec3()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<toy::OWaypoint>(), member_address(&toy::OWaypoint::m_entity), type<toy::Entity>(), "entity", Ref(type<toy::Entity>()), Member::Component, nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        init_pool<toy::OWaypoint>(); 
        
        meta_class<toy::OWaypoint>();
    }
    
    
        
    // toy::Origin
    {
        static Meta meta = { type<toy::Origin>(), &namspc({ "toy" }), "Origin", sizeof(toy::Origin), TypeClass::Complex };
        static Class cls = { type<toy::Origin>(),
            // bases
            { &type<mud::Complex>() },
            { base_offset<toy::Origin, mud::Complex>() },
            // constructors
            {
                { type<toy::Origin>(), [](Ref ref, array<Var> args) { new(&val<toy::Origin>(ref)) toy::Origin( val<mud::Id>(args[0]), val<toy::World>(args[1]) ); }, { { "id", var(mud::Id()) }, { "world", Ref(type<toy::World>()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<toy::Origin>(), member_address(&toy::Origin::m_entity), type<toy::Entity>(), "entity", Ref(type<toy::Entity>()), Member::Component, nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        init_pool<toy::Origin>(); 
        
        meta_class<toy::Origin>();
    }
    
    
        
    // toy::NavmeshShape
    {
        static Meta meta = { type<toy::NavmeshShape>(), &namspc({ "toy" }), "NavmeshShape", sizeof(toy::NavmeshShape), TypeClass::Object };
        static Class cls = { type<toy::NavmeshShape>(),
            // bases
            { &type<mud::Shape>() },
            { base_offset<toy::NavmeshShape, mud::Shape>() },
            // constructors
            {
                { type<toy::NavmeshShape>(), [](Ref ref, array<Var> args) { new(&val<toy::NavmeshShape>(ref)) toy::NavmeshShape( val<toy::Navmesh>(args[0]) ); }, { { "navmesh", Ref(type<toy::Navmesh>()) } } }
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
        
        
        init_pool<toy::NavmeshShape>(); 
        
        meta_class<toy::NavmeshShape>();
    }
    
    
        
    // toy::Action
    {
        static Meta meta = { type<toy::Action>(), &namspc({ "toy" }), "Action", sizeof(toy::Action), TypeClass::Object };
        static Class cls = { type<toy::Action>(),
            // bases
            { &type<toy::Procedure>() },
            { base_offset<toy::Action, toy::Procedure>() },
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
        
        
        
        
        meta_class<toy::Action>();
    }
    
    
        
    // toy::BulletCollider
    {
        static Meta meta = { type<toy::BulletCollider>(), &namspc({ "toy" }), "BulletCollider", sizeof(toy::BulletCollider), TypeClass::Object };
        static Class cls = { type<toy::BulletCollider>(),
            // bases
            { &type<toy::ColliderImpl>() },
            { base_offset<toy::BulletCollider, toy::ColliderImpl>() },
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
        
        
        
        
        meta_class<toy::BulletCollider>();
    }
    
    
        
    // toy::Solid
    {
        static Meta meta = { type<toy::Solid>(), &namspc({ "toy" }), "Solid", sizeof(toy::Solid), TypeClass::Object };
        static Class cls = { type<toy::Solid>(),
            // bases
            { &type<toy::Collider>() },
            { base_offset<toy::Solid, toy::Collider>() },
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
        
        
        
        
        meta_class<toy::Solid>();
    }
    
    
    
        
    // toy::ObstacleBody
    {
        static Meta meta = { type<toy::ObstacleBody>(), &namspc({ "toy" }), "ObstacleBody", sizeof(toy::ObstacleBody), TypeClass::Object };
        static Class cls = { type<toy::ObstacleBody>(),
            // bases
            { &type<toy::Collider>(), &type<toy::ColliderObject>() },
            { base_offset<toy::ObstacleBody, toy::Collider>(), base_offset<toy::ObstacleBody, toy::ColliderObject>() },
            // constructors
            {
            },
            // copy constructor
            {
            },
            // members
            {
                { type<toy::ObstacleBody>(), member_address(&toy::ObstacleBody::collision_shape), type<toy::CollisionShape>(), "collision_shape", Ref(type<toy::CollisionShape>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::ObstacleBody>(object).collision_shape()); } },
                { type<toy::ObstacleBody>(), member_address(&toy::ObstacleBody::m_throughput), type<float>(), "throughput", var(float()), Member::Value, nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        
        
        meta_class<toy::ObstacleBody>();
    }
    
    
        
    // toy::PhysicScope
    {
        static Meta meta = { type<toy::PhysicScope>(), &namspc({ "toy" }), "PhysicScope", sizeof(toy::PhysicScope), TypeClass::Object };
        static Class cls = { type<toy::PhysicScope>(),
            // bases
            { &type<toy::Collider>(), &type<toy::ColliderObject>() },
            { base_offset<toy::PhysicScope, toy::Collider>(), base_offset<toy::PhysicScope, toy::ColliderObject>() },
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
                { type<toy::PhysicScope>(), "scope", member_address(&toy::PhysicScope::scope), [](Ref object, array<Var> args, Var& result) { UNUSED(args);val<std::vector<toy::Entity*>>(result) = val<toy::PhysicScope>(object).scope(); }, {}, var(std::vector<toy::Entity*>()) }
            },
            // static members
            {
            }
        };
        
        
        
        
        meta_class<toy::PhysicScope>();
    }
    
    
        
    // toy::Area
    {
        static Meta meta = { type<toy::Area>(), &namspc({ "toy" }), "Area", sizeof(toy::Area), TypeClass::Object };
        static Class cls = { type<toy::Area>(),
            // bases
            { &type<toy::ColliderObject>() },
            { base_offset<toy::Area, toy::ColliderObject>() },
            // constructors
            {
                { type<toy::Area>(), [](Ref ref, array<Var> args) { new(&val<toy::Area>(ref)) toy::Area( val<toy::Entity>(args[0]), val<toy::CollisionShape>(args[1]) ); }, { { "entity", Ref(type<toy::Entity>()) }, { "shape", Ref(type<toy::CollisionShape>()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<toy::Area>(), member_address(&toy::Area::entity), type<toy::Entity>(), "entity", Ref(type<toy::Entity>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::Area>(object).entity()); } },
                { type<toy::Area>(), member_address(&toy::Area::shape), type<toy::CollisionShape>(), "shape", Ref(type<toy::CollisionShape>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::Area>(object).shape()); } }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        init_pool<toy::Area>(); 
        
        meta_class<toy::Area>();
    }
    
    
        
    // toy::WorldPage
    {
        static Meta meta = { type<toy::WorldPage>(), &namspc({ "toy" }), "WorldPage", sizeof(toy::WorldPage), TypeClass::Object };
        static Class cls = { type<toy::WorldPage>(),
            // bases
            { &type<toy::ColliderObject>() },
            { base_offset<toy::WorldPage, toy::ColliderObject>() },
            // constructors
            {
                { type<toy::WorldPage>(), [](Ref ref, array<Var> args) { new(&val<toy::WorldPage>(ref)) toy::WorldPage( val<toy::Entity>(args[0]), val<toy::Emitter>(args[1]), val<bool>(args[2]), val<mud::vec3>(args[3]) ); }, { { "entity", Ref(type<toy::Entity>()) }, { "emitter", Ref(type<toy::Emitter>()) }, { "open", var(bool()) }, { "extents", var(mud::vec3()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<toy::WorldPage>(), Address(), type<toy::Entity>(), "entity", Ref(type<toy::Entity>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::WorldPage>(object).m_entity); } },
                { type<toy::WorldPage>(), Address(), type<toy::Emitter>(), "emitter", Ref(type<toy::Emitter>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::WorldPage>(object).m_emitter); } },
                { type<toy::WorldPage>(), member_address(&toy::WorldPage::m_open), type<bool>(), "open", var(bool()), Member::Value, nullptr },
                { type<toy::WorldPage>(), member_address(&toy::WorldPage::m_extents), type<mud::vec3>(), "extents", var(mud::vec3()), Member::Value, nullptr },
                { type<toy::WorldPage>(), Address(), type<toy::World>(), "world", Ref(type<toy::World>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::WorldPage>(object).m_world); } },
                { type<toy::WorldPage>(), member_address(&toy::WorldPage::m_last_rebuilt), type<size_t>(), "last_rebuilt", var(size_t()), Member::Value, nullptr }
            },
            // methods
            {
                { type<toy::WorldPage>(), "build_geometry", member_address(&toy::WorldPage::build_geometry), [](Ref object, array<Var> args, Var& result) { UNUSED(result); UNUSED(args);val<toy::WorldPage>(object).build_geometry(); }, {}, Var() },
                { type<toy::WorldPage>(), "update_geometry", member_address(&toy::WorldPage::update_geometry), [](Ref object, array<Var> args, Var& result) { UNUSED(result); UNUSED(args);val<toy::WorldPage>(object).update_geometry(); }, {}, Var() },
                { type<toy::WorldPage>(), "ground_point", member_address(&toy::WorldPage::ground_point), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::WorldPage>(object).ground_point(val<mud::vec3>(args[0]), val<bool>(args[1]), val<mud::vec3>(args[2])); }, { { "position", var(mud::vec3()) }, { "relative", var(bool()) }, { "outputPoint", var(mud::vec3()), Param::Output } }, Var() },
                { type<toy::WorldPage>(), "raycast_ground", member_address(&toy::WorldPage::raycast_ground), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::WorldPage>(object).raycast_ground(val<mud::vec3>(args[0]), val<mud::vec3>(args[1]), val<mud::vec3>(args[2])); }, { { "from", var(mud::vec3()) }, { "to", var(mud::vec3()) }, { "ground_point", var(mud::vec3()) } }, Var() }
            },
            // static members
            {
            }
        };
        
        
        init_pool<toy::WorldPage>(); 
        
        meta_class<toy::WorldPage>();
    }
    
    
        
    // toy::BulletSolid
    {
        static Meta meta = { type<toy::BulletSolid>(), &namspc({ "toy" }), "BulletSolid", sizeof(toy::BulletSolid), TypeClass::Object };
        static Class cls = { type<toy::BulletSolid>(),
            // bases
            { &type<toy::BulletCollider>() },
            { base_offset<toy::BulletSolid, toy::BulletCollider>() },
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
        
        
        
        
        meta_class<toy::BulletSolid>();
    }
    
    
        
    // toy::EmitterScope
    {
        static Meta meta = { type<toy::EmitterScope>(), &namspc({ "toy" }), "EmitterScope", sizeof(toy::EmitterScope), TypeClass::Object };
        static Class cls = { type<toy::EmitterScope>(),
            // bases
            { &type<toy::PhysicScope>() },
            { base_offset<toy::EmitterScope, toy::PhysicScope>() },
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
        
        
        
        
        meta_class<toy::EmitterScope>();
    }
    
    
        
    // toy::ReceptorScope
    {
        static Meta meta = { type<toy::ReceptorScope>(), &namspc({ "toy" }), "ReceptorScope", sizeof(toy::ReceptorScope), TypeClass::Object };
        static Class cls = { type<toy::ReceptorScope>(),
            // bases
            { &type<toy::PhysicScope>() },
            { base_offset<toy::ReceptorScope, toy::PhysicScope>() },
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
        
        
        
        
        meta_class<toy::ReceptorScope>();
    }
    
    
        
    // toy::EmitterSphere
    {
        static Meta meta = { type<toy::EmitterSphere>(), &namspc({ "toy" }), "EmitterSphere", sizeof(toy::EmitterSphere), TypeClass::Object };
        static Class cls = { type<toy::EmitterSphere>(),
            // bases
            { &type<toy::EmitterScope>() },
            { base_offset<toy::EmitterSphere, toy::EmitterScope>() },
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
        
        
        
        
        meta_class<toy::EmitterSphere>();
    }
    
    
        
    // toy::ReceptorSphere
    {
        static Meta meta = { type<toy::ReceptorSphere>(), &namspc({ "toy" }), "ReceptorSphere", sizeof(toy::ReceptorSphere), TypeClass::Object };
        static Class cls = { type<toy::ReceptorSphere>(),
            // bases
            { &type<toy::ReceptorScope>() },
            { base_offset<toy::ReceptorSphere, toy::ReceptorScope>() },
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
        
        
        
        
        meta_class<toy::ReceptorSphere>();
    }
    
    
        
    // toy::EventEmitter
    {
        static Meta meta = { type<toy::EventEmitter>(), &namspc({ "toy" }), "EventEmitter", sizeof(toy::EventEmitter), TypeClass::Object };
        static Class cls = { type<toy::EventEmitter>(),
            // bases
            { &type<toy::Emitter>() },
            { base_offset<toy::EventEmitter, toy::Emitter>() },
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
        
        
        
        
        meta_class<toy::EventEmitter>();
    }
    
    
        
    // toy::EventReceptor
    {
        static Meta meta = { type<toy::EventReceptor>(), &namspc({ "toy" }), "EventReceptor", sizeof(toy::EventReceptor), TypeClass::Object };
        static Class cls = { type<toy::EventReceptor>(),
            // bases
            { &type<toy::Receptor>() },
            { base_offset<toy::EventReceptor, toy::Receptor>() },
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
        
        
        
        
        meta_class<toy::EventReceptor>();
    }
    
    
        
    // toy::MonoSection
    {
        static Meta meta = { type<toy::MonoSection>(), &namspc({ "toy" }), "MonoSection", sizeof(toy::MonoSection), TypeClass::Object };
        static Class cls = { type<toy::MonoSection>(),
            // bases
            { &type<toy::TaskSection>() },
            { base_offset<toy::MonoSection, toy::TaskSection>() },
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
        
        
        
        
        meta_class<toy::MonoSection>();
    }
    
    
        
    // toy::ParallelSection
    {
        static Meta meta = { type<toy::ParallelSection>(), &namspc({ "toy" }), "ParallelSection", sizeof(toy::ParallelSection), TypeClass::Object };
        static Class cls = { type<toy::ParallelSection>(),
            // bases
            { &type<toy::TaskSection>() },
            { base_offset<toy::ParallelSection, toy::TaskSection>() },
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
        
        
        
        
        meta_class<toy::ParallelSection>();
    }
    
    
        
    // toy::QueueSection
    {
        static Meta meta = { type<toy::QueueSection>(), &namspc({ "toy" }), "QueueSection", sizeof(toy::QueueSection), TypeClass::Object };
        static Class cls = { type<toy::QueueSection>(),
            // bases
            { &type<toy::TaskSection>() },
            { base_offset<toy::QueueSection, toy::TaskSection>() },
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
        
        
        
        
        meta_class<toy::QueueSection>();
    }
    
    
    
        
    // toy::BulletWorld
    {
        static Meta meta = { type<toy::BulletWorld>(), &namspc({ "toy" }), "BulletWorld", sizeof(toy::BulletWorld), TypeClass::Object };
        static Class cls = { type<toy::BulletWorld>(),
            // bases
            { &type<toy::PhysicWorld>() },
            { base_offset<toy::BulletWorld, toy::PhysicWorld>() },
            // constructors
            {
                { type<toy::BulletWorld>(), [](Ref ref, array<Var> args) { new(&val<toy::BulletWorld>(ref)) toy::BulletWorld( val<toy::World>(args[0]) ); }, { { "world", Ref(type<toy::World>()) } } }
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
        
        
        init_pool<toy::BulletWorld>(); 
        
        meta_class<toy::BulletWorld>();
    }
    
    
    
        
    // toy::SolidMedium
    {
        static Meta meta = { type<toy::SolidMedium>(), &namspc({ "toy" }), "SolidMedium", sizeof(toy::SolidMedium), TypeClass::Object };
        static Class cls = { type<toy::SolidMedium>(),
            // bases
            { &type<toy::Medium>() },
            { base_offset<toy::SolidMedium, toy::Medium>() },
            // constructors
            {
                { type<toy::SolidMedium>(), [](Ref ref, array<Var> args) { UNUSED(args);new(&val<toy::SolidMedium>(ref)) toy::SolidMedium(  ); }, {} }
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
                { type<toy::SolidMedium>(), "me", Ref(&toy::SolidMedium::me) }
            }
        };
        
        
        init_pool<toy::SolidMedium>(); 
        
        meta_class<toy::SolidMedium>();
    }
    
    
        
    // toy::SoundMedium
    {
        static Meta meta = { type<toy::SoundMedium>(), &namspc({ "toy" }), "SoundMedium", sizeof(toy::SoundMedium), TypeClass::Object };
        static Class cls = { type<toy::SoundMedium>(),
            // bases
            { &type<toy::Medium>() },
            { base_offset<toy::SoundMedium, toy::Medium>() },
            // constructors
            {
                { type<toy::SoundMedium>(), [](Ref ref, array<Var> args) { UNUSED(args);new(&val<toy::SoundMedium>(ref)) toy::SoundMedium(  ); }, {} }
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
                { type<toy::SoundMedium>(), "me", Ref(&toy::SoundMedium::me) }
            }
        };
        
        
        init_pool<toy::SoundMedium>(); 
        
        meta_class<toy::SoundMedium>();
    }
    
    
        
    // toy::VisualMedium
    {
        static Meta meta = { type<toy::VisualMedium>(), &namspc({ "toy" }), "VisualMedium", sizeof(toy::VisualMedium), TypeClass::Object };
        static Class cls = { type<toy::VisualMedium>(),
            // bases
            { &type<toy::Medium>() },
            { base_offset<toy::VisualMedium, toy::Medium>() },
            // constructors
            {
                { type<toy::VisualMedium>(), [](Ref ref, array<Var> args) { UNUSED(args);new(&val<toy::VisualMedium>(ref)) toy::VisualMedium(  ); }, {} }
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
                { type<toy::VisualMedium>(), "me", Ref(&toy::VisualMedium::me) }
            }
        };
        
        
        init_pool<toy::VisualMedium>(); 
        
        meta_class<toy::VisualMedium>();
    }
    
    
        
    // toy::WorldMedium
    {
        static Meta meta = { type<toy::WorldMedium>(), &namspc({ "toy" }), "WorldMedium", sizeof(toy::WorldMedium), TypeClass::Object };
        static Class cls = { type<toy::WorldMedium>(),
            // bases
            { &type<toy::Medium>() },
            { base_offset<toy::WorldMedium, toy::Medium>() },
            // constructors
            {
                { type<toy::WorldMedium>(), [](Ref ref, array<Var> args) { UNUSED(args);new(&val<toy::WorldMedium>(ref)) toy::WorldMedium(  ); }, {} }
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
                { type<toy::WorldMedium>(), "me", Ref(&toy::WorldMedium::me) }
            }
        };
        
        
        init_pool<toy::WorldMedium>(); 
        
        meta_class<toy::WorldMedium>();
    }
    
    
        
    // toy::ReceptorView
    {
        static Meta meta = { type<toy::ReceptorView>(), &namspc({ "toy" }), "ReceptorView", sizeof(toy::ReceptorView), TypeClass::Object };
        static Class cls = { type<toy::ReceptorView>(),
            // bases
            { &type<toy::View>() },
            { base_offset<toy::ReceptorView, toy::View>() },
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
        
        
        
        
        meta_class<toy::ReceptorView>();
    }
    
    
        
    // toy::StoreView
    {
        static Meta meta = { type<toy::StoreView>(), &namspc({ "toy" }), "StoreView", sizeof(toy::StoreView), TypeClass::Object };
        static Class cls = { type<toy::StoreView>(),
            // bases
            { &type<toy::View>() },
            { base_offset<toy::StoreView, toy::View>() },
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
        
        
        
        
        meta_class<toy::StoreView>();
    }
    
    
        
    // toy::OmniVision
    {
        static Meta meta = { type<toy::OmniVision>(), &namspc({ "toy" }), "OmniVision", sizeof(toy::OmniVision), TypeClass::Object };
        static Class cls = { type<toy::OmniVision>(),
            // bases
            { &type<toy::Vision>() },
            { base_offset<toy::OmniVision, toy::Vision>() },
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
        
        
        
        
        meta_class<toy::OmniVision>();
    }
    

    
        m.m_types.push_back(&type<toy::Active>());
        m.m_types.push_back(&type<toy::Actor>());
        m.m_types.push_back(&type<toy::Agent>());
        m.m_types.push_back(&type<toy::Array<toy::Action>>());
        m.m_types.push_back(&type<toy::Array<toy::Entity>>());
        m.m_types.push_back(&type<toy::Behavior>());
        m.m_types.push_back(&type<toy::BufferPage>());
        m.m_types.push_back(&type<toy::BulletShape>());
        m.m_types.push_back(&type<toy::Camera>());
        m.m_types.push_back(&type<toy::Collider>());
        m.m_types.push_back(&type<toy::ColliderImpl>());
        m.m_types.push_back(&type<toy::ColliderObject>());
        m.m_types.push_back(&type<toy::Collision>());
        m.m_types.push_back(&type<toy::CollisionShape>());
        m.m_types.push_back(&type<toy::ComponentPool>());
        m.m_types.push_back(&type<toy::Core>());
        m.m_types.push_back(&type<toy::DetourPath>());
        m.m_types.push_back(&type<toy::Effect>());
        m.m_types.push_back(&type<toy::Emitter>());
        m.m_types.push_back(&type<toy::EntityScript>());
        m.m_types.push_back(&type<toy::EventFilter>());
        m.m_types.push_back(&type<toy::EventRelay>());
        m.m_types.push_back(&type<toy::GroundMotion>());
        m.m_types.push_back(&type<toy::LightReflector>());
        m.m_types.push_back(&type<toy::LightSource>());
        m.m_types.push_back(&type<toy::Medium>());
        m.m_types.push_back(&type<toy::Movable>());
        m.m_types.push_back(&type<toy::Navblock>());
        m.m_types.push_back(&type<toy::Navmesh>());
        m.m_types.push_back(&type<toy::Obstacle>());
        m.m_types.push_back(&type<toy::Pathfinder>());
        m.m_types.push_back(&type<toy::PhysicWorld>());
        m.m_types.push_back(&type<toy::Reactive>());
        m.m_types.push_back(&type<toy::Receptor>());
        m.m_types.push_back(&type<toy::Selector>());
        m.m_types.push_back(&type<toy::State>());
        m.m_types.push_back(&type<toy::SubBulletWorld>());
        m.m_types.push_back(&type<toy::Symbolic>());
        m.m_types.push_back(&type<toy::TaskSection>());
        m.m_types.push_back(&type<toy::User>());
        m.m_types.push_back(&type<toy::View>());
        m.m_types.push_back(&type<toy::Vision>());
        m.m_types.push_back(&type<toy::World>());
        m.m_types.push_back(&type<toy::WorldClock>());
        m.m_types.push_back(&type<std::vector<mud::Symbol>>());
        m.m_types.push_back(&type<std::vector<toy::Entity*>>());
        m.m_types.push_back(&type<toy::Entity>());
        m.m_types.push_back(&type<toy::DefaultWorld>());
        m.m_types.push_back(&type<toy::OCamera>());
        m.m_types.push_back(&type<toy::OLight>());
        m.m_types.push_back(&type<toy::OWaypoint>());
        m.m_types.push_back(&type<toy::Origin>());
        m.m_types.push_back(&type<toy::NavmeshShape>());
        m.m_types.push_back(&type<toy::Action>());
        m.m_types.push_back(&type<toy::BulletCollider>());
        m.m_types.push_back(&type<toy::Solid>());
        m.m_types.push_back(&type<toy::ObstacleBody>());
        m.m_types.push_back(&type<toy::PhysicScope>());
        m.m_types.push_back(&type<toy::Area>());
        m.m_types.push_back(&type<toy::WorldPage>());
        m.m_types.push_back(&type<toy::BulletSolid>());
        m.m_types.push_back(&type<toy::EmitterScope>());
        m.m_types.push_back(&type<toy::ReceptorScope>());
        m.m_types.push_back(&type<toy::EmitterSphere>());
        m.m_types.push_back(&type<toy::ReceptorSphere>());
        m.m_types.push_back(&type<toy::EventEmitter>());
        m.m_types.push_back(&type<toy::EventReceptor>());
        m.m_types.push_back(&type<toy::MonoSection>());
        m.m_types.push_back(&type<toy::ParallelSection>());
        m.m_types.push_back(&type<toy::QueueSection>());
        m.m_types.push_back(&type<toy::BulletWorld>());
        m.m_types.push_back(&type<toy::SolidMedium>());
        m.m_types.push_back(&type<toy::SoundMedium>());
        m.m_types.push_back(&type<toy::VisualMedium>());
        m.m_types.push_back(&type<toy::WorldMedium>());
        m.m_types.push_back(&type<toy::ReceptorView>());
        m.m_types.push_back(&type<toy::StoreView>());
        m.m_types.push_back(&type<toy::OmniVision>());
    
        {
            auto func = [](array<Var> args, Var& result) {  val<bool>(result) = toy::move_2d(val<toy::Movable>(args[0]), val<mud::vec3>(args[1]), val<float>(args[2]), val<float>(args[3]), val<float>(args[4])); };
            std::vector<Param> params = { { "movable", Ref(type<toy::Movable>()) }, { "target", var(mud::vec3()) }, { "velocity", var(float()) }, { "time_step", var(float()) }, { "margin", var(float(0.1f)), Param::Default } };
            static Function f = { &namspc({ "toy" }), "move_2d", function_id<bool(*)(toy::Movable&, const mud::vec3&, float, float, float)>(&toy::move_2d), func, params, var(bool()) };
            m.m_functions.push_back(&f);
        }
        {
            auto func = [](array<Var> args, Var& result) {  val<bool>(result) = toy::steer_2d(val<toy::Movable>(args[0]), val<mud::vec3>(args[1]), val<float>(args[2]), val<float>(args[3]), val<float>(args[4])); };
            std::vector<Param> params = { { "movable", Ref(type<toy::Movable>()) }, { "target", var(mud::vec3()) }, { "velocity", var(float()) }, { "time_step", var(float()) }, { "margin", var(float(0.1f)), Param::Default } };
            static Function f = { &namspc({ "toy" }), "steer_2d", function_id<bool(*)(toy::Movable&, const mud::vec3&, float, float, float)>(&toy::steer_2d), func, params, var(bool()) };
            m.m_functions.push_back(&f);
        }
    }
}
