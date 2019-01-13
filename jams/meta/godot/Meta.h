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
                { type<Aim>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<Aim>(ref)) Aim(  ); }, {} }
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
    // Bullet
    {
        static Meta meta = { type<Bullet>(), &namspc({}), "Bullet", sizeof(Bullet), TypeClass::Object };
        static Class cls = { type<Bullet>(),
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
            {  },
            {  },
            // constructors
            {
                { type<Crate>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<Crate>(ref)) Crate(  ); }, {} },
                { type<Crate>(), [](Ref ref, array<Var> args) { new(&val<Crate>(ref)) Crate( val<toy::HSpatial>(args[0]), val<toy::HMovable>(args[1]), val<mud::vec3>(args[2]) ); }, { { "spatial", var(toy::HSpatial()) }, { "movable", var(toy::HMovable()) }, { "extents", var(mud::vec3()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
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
            {  },
            {  },
            // constructors
            {
                { type<Human>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<Human>(ref)) Human(  ); }, {} },
                { type<Human>(), [](Ref ref, array<Var> args) { new(&val<Human>(ref)) Human( val<toy::HSpatial>(args[0]), val<toy::HMovable>(args[1]), val<toy::HEmitter>(args[2]), val<toy::HReceptor>(args[3]), val<toy::HEntityScript>(args[4]), val<Faction>(args[5]) ); }, { { "spatial", var(toy::HSpatial()) }, { "movable", var(toy::HMovable()) }, { "emitter", var(toy::HEmitter()) }, { "receptor", var(toy::HReceptor()) }, { "script", var(toy::HEntityScript()) }, { "faction", var(Faction()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<Human>(), member_address(&Human::m_faction), type<Faction>(), "faction", var(Faction()), Member::Value, nullptr },
                { type<Human>(), member_address(&Human::m_life), type<float>(), "life", var(float(1.f)), Member::Value, nullptr },
                { type<Human>(), member_address(&Human::m_energy), type<float>(), "energy", var(float(1.f)), Member::Value, nullptr },
                { type<Human>(), member_address(&Human::m_discharge), type<float>(), "discharge", var(float(0.f)), Member::Value, nullptr },
                { type<Human>(), member_address(&Human::m_headlight), type<bool>(), "headlight", var(bool(true)), Member::Value, nullptr },
                { type<Human>(), member_address(&Human::m_shield), type<bool>(), "shield", var(bool(false)), Member::Value, nullptr },
                { type<Human>(), member_address(&Human::m_walk), type<bool>(), "walk", var(bool(true)), Member::Value, nullptr },
                { type<Human>(), member_address(&Human::m_target), type<HHuman>(), "target", var(HHuman{}), Member::Value, nullptr },
                { type<Human>(), member_address(&Human::m_dest), type<mud::vec3>(), "dest", var(mud::vec3(Zero3)), Member::Value, nullptr },
                { type<Human>(), member_address(&Human::m_cooldown), type<float>(), "cooldown", var(float(0.f)), Member::Value, nullptr },
                { type<Human>(), member_address(&Human::m_state), type<Stance>(), "state", var(Stance{"IdleAim",true}), Member::Value, nullptr }
            },
            // methods
            {
                { type<Human>(), "sight", member_address<mud::quat(Human::*)(bool)>(&Human::sight), [](Ref object, array<Var> args, Var& result) { val<mud::quat>(result) = val<Human>(object).sight(val<bool>(args[0])); }, { { "aiming", var(bool(true)), Param::Default } }, var(mud::quat()) },
                { type<Human>(), "aim", member_address<Aim(Human::*)()>(&Human::aim), [](Ref object, array<Var> args, Var& result) { UNUSED(args); val<Aim>(result) = val<Human>(object).aim(); }, {}, var(Aim()) },
                { type<Human>(), "shoot", member_address<void(Human::*)()>(&Human::shoot), [](Ref object, array<Var> args, Var& result) { UNUSED(result); UNUSED(args); val<Human>(object).shoot(); }, {}, Var() },
                { type<Human>(), "stop", member_address<void(Human::*)()>(&Human::stop), [](Ref object, array<Var> args, Var& result) { UNUSED(result); UNUSED(args); val<Human>(object).stop(); }, {}, Var() }
            },
            // static members
            {
            }
        };
        init_pool<Human>();
        meta_class<Human>();
    }
    // Lamp
    {
        static Meta meta = { type<Lamp>(), &namspc({}), "Lamp", sizeof(Lamp), TypeClass::Object };
        static Class cls = { type<Lamp>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<Lamp>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<Lamp>(ref)) Lamp(  ); }, {} },
                { type<Lamp>(), [](Ref ref, array<Var> args) { new(&val<Lamp>(ref)) Lamp( val<toy::HSpatial>(args[0]), val<toy::HMovable>(args[1]) ); }, { { "spatial", var(toy::HSpatial()) }, { "movable", var(toy::HMovable()) } } }
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
        init_pool<Lamp>();
        meta_class<Lamp>();
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
                { type<Stance>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<Stance>(ref)) Stance(  ); }, {} },
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
    // WorldBlock
    {
        static Meta meta = { type<WorldBlock>(), &namspc({}), "WorldBlock", sizeof(WorldBlock), TypeClass::Object };
        static Class cls = { type<WorldBlock>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<WorldBlock>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<WorldBlock>(ref)) WorldBlock(  ); }, {} },
                { type<WorldBlock>(), [](Ref ref, array<Var> args) { new(&val<WorldBlock>(ref)) WorldBlock( val<toy::HSpatial>(args[0]), val<toy::HWorldPage>(args[1]), val<toy::HNavblock>(args[2]), val<mud::vec3>(args[3]) ); }, { { "spatial", var(toy::HSpatial()) }, { "world_page", var(toy::HWorldPage()) }, { "navblock", var(toy::HNavblock()) }, { "extents", var(mud::vec3()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<WorldBlock>(), member_address(&WorldBlock::m_extents), type<mud::vec3>(), "extents", var(mud::vec3()), Member::Value, nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        init_pool<WorldBlock>();
        meta_class<WorldBlock>();
    }
    // mud::ComponentHandle<Bullet>
    {
        static Meta meta = { type<mud::ComponentHandle<Bullet>>(), &namspc({ "mud" }), "ComponentHandle<Bullet>", sizeof(mud::ComponentHandle<Bullet>), TypeClass::Struct };
        static Class cls = { type<mud::ComponentHandle<Bullet>>(),
            // bases
            { &type<mud::Entity>() },
            { base_offset<mud::ComponentHandle<Bullet>, mud::Entity>() },
            // constructors
            {
                { type<mud::ComponentHandle<Bullet>>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<mud::ComponentHandle<Bullet>>(ref)) mud::ComponentHandle<Bullet>(  ); }, {} }
            },
            // copy constructor
            {
                { type<mud::ComponentHandle<Bullet>>(), [](Ref ref, Ref other) { new(&val<mud::ComponentHandle<Bullet>>(ref)) mud::ComponentHandle<Bullet>(val<mud::ComponentHandle<Bullet>>(other)); } }
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
        meta_class<mud::ComponentHandle<Bullet>>();
    }
    // mud::ComponentHandle<Crate>
    {
        static Meta meta = { type<mud::ComponentHandle<Crate>>(), &namspc({ "mud" }), "ComponentHandle<Crate>", sizeof(mud::ComponentHandle<Crate>), TypeClass::Struct };
        static Class cls = { type<mud::ComponentHandle<Crate>>(),
            // bases
            { &type<mud::Entity>() },
            { base_offset<mud::ComponentHandle<Crate>, mud::Entity>() },
            // constructors
            {
                { type<mud::ComponentHandle<Crate>>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<mud::ComponentHandle<Crate>>(ref)) mud::ComponentHandle<Crate>(  ); }, {} }
            },
            // copy constructor
            {
                { type<mud::ComponentHandle<Crate>>(), [](Ref ref, Ref other) { new(&val<mud::ComponentHandle<Crate>>(ref)) mud::ComponentHandle<Crate>(val<mud::ComponentHandle<Crate>>(other)); } }
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
        meta_class<mud::ComponentHandle<Crate>>();
    }
    // mud::ComponentHandle<Human>
    {
        static Meta meta = { type<mud::ComponentHandle<Human>>(), &namspc({ "mud" }), "ComponentHandle<Human>", sizeof(mud::ComponentHandle<Human>), TypeClass::Struct };
        static Class cls = { type<mud::ComponentHandle<Human>>(),
            // bases
            { &type<mud::Entity>() },
            { base_offset<mud::ComponentHandle<Human>, mud::Entity>() },
            // constructors
            {
                { type<mud::ComponentHandle<Human>>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<mud::ComponentHandle<Human>>(ref)) mud::ComponentHandle<Human>(  ); }, {} }
            },
            // copy constructor
            {
                { type<mud::ComponentHandle<Human>>(), [](Ref ref, Ref other) { new(&val<mud::ComponentHandle<Human>>(ref)) mud::ComponentHandle<Human>(val<mud::ComponentHandle<Human>>(other)); } }
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
        meta_class<mud::ComponentHandle<Human>>();
    }
    // mud::ComponentHandle<Lamp>
    {
        static Meta meta = { type<mud::ComponentHandle<Lamp>>(), &namspc({ "mud" }), "ComponentHandle<Lamp>", sizeof(mud::ComponentHandle<Lamp>), TypeClass::Struct };
        static Class cls = { type<mud::ComponentHandle<Lamp>>(),
            // bases
            { &type<mud::Entity>() },
            { base_offset<mud::ComponentHandle<Lamp>, mud::Entity>() },
            // constructors
            {
                { type<mud::ComponentHandle<Lamp>>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<mud::ComponentHandle<Lamp>>(ref)) mud::ComponentHandle<Lamp>(  ); }, {} }
            },
            // copy constructor
            {
                { type<mud::ComponentHandle<Lamp>>(), [](Ref ref, Ref other) { new(&val<mud::ComponentHandle<Lamp>>(ref)) mud::ComponentHandle<Lamp>(val<mud::ComponentHandle<Lamp>>(other)); } }
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
        meta_class<mud::ComponentHandle<Lamp>>();
    }
        m.m_types.push_back(&type<Aim>());
        m.m_types.push_back(&type<Bullet>());
        m.m_types.push_back(&type<Crate>());
        m.m_types.push_back(&type<Faction>());
        m.m_types.push_back(&type<Human>());
        m.m_types.push_back(&type<Lamp>());
        m.m_types.push_back(&type<Player>());
        m.m_types.push_back(&type<Stance>());
        m.m_types.push_back(&type<WorldBlock>());
        m.m_types.push_back(&type<mud::ComponentHandle<Bullet>>());
        m.m_types.push_back(&type<mud::ComponentHandle<Crate>>());
        m.m_types.push_back(&type<mud::ComponentHandle<Human>>());
        m.m_types.push_back(&type<mud::ComponentHandle<Lamp>>());
    }
}
