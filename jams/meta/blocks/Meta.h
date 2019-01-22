#pragma once

#ifndef MUD_MODULES
#include <meta/blocks/Module.h>

#include <type/Any.h>
#include <type/Vector.h>
#include <refl/MetaDecl.h>
#include <refl/Module.h>
#endif

namespace mud
{
    void _blocks_meta(Module& m)
    {
    UNUSED(m);
    
    // Base Types
    
    // Enums
    
    // Sequences
    
    // Camp
    {
        static Meta meta = { type<Camp>(), &namspc({}), "Camp", sizeof(Camp), TypeClass::Object };
        static Class cls = { type<Camp>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<Camp>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<Camp>(ref)) Camp(  ); }, {} },
                { type<Camp>(), [](Ref ref, array<Var> args) { new(&val<Camp>(ref)) Camp( val<toy::HSpatial>(args[0]), val<mud::vec3>(args[1]), val<Faction>(args[2]) ); }, { { "spatial", var(toy::HSpatial()) }, { "position", var(mud::vec3()) }, { "faction", Ref(type<Faction>()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<Camp>(), member_address(&Camp::m_position), type<mud::vec3>(), "position", var(mud::vec3()), Member::Value, nullptr },
                { type<Camp>(), member_address(&Camp::m_faction), type<Faction>(), "faction", Ref(type<Faction>()), Member::Flags(Member::Pointer|Member::Link), nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        init_pool<Camp>();
        meta_class<Camp>();
    }
    // Faction
    {
        static Meta meta = { type<Faction>(), &namspc({}), "Faction", sizeof(Faction), TypeClass::Object };
        static Class cls = { type<Faction>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<Faction>(), [](Ref ref, array<Var> args) { new(&val<Faction>(ref)) Faction( val<uint32_t>(args[0]), val<mud::Colour>(args[1]) ); }, { { "id", var(uint32_t()) }, { "colour", var(mud::Colour()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<Faction>(), member_address(&Faction::m_id), type<uint32_t>(), "id", var(uint32_t()), Member::Value, nullptr },
                { type<Faction>(), member_address(&Faction::m_colour), type<mud::Colour>(), "colour", var(mud::Colour()), Member::Value, nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        init_pool<Faction>();
        meta_class<Faction>();
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
    // Shield
    {
        static Meta meta = { type<Shield>(), &namspc({}), "Shield", sizeof(Shield), TypeClass::Object };
        static Class cls = { type<Shield>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<Shield>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<Shield>(ref)) Shield(  ); }, {} },
                { type<Shield>(), [](Ref ref, array<Var> args) { new(&val<Shield>(ref)) Shield( val<toy::HSpatial>(args[0]), val<toy::HEmitter>(args[1]), val<Faction>(args[2]), val<float>(args[3]) ); }, { { "spatial", var(toy::HSpatial()) }, { "emitter", var(toy::HEmitter()) }, { "faction", Ref(type<Faction>()) }, { "radius", var(float()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<Shield>(), member_address(&Shield::m_faction), type<Faction>(), "faction", Ref(type<Faction>()), Member::Flags(Member::Pointer|Member::Link), nullptr },
                { type<Shield>(), member_address(&Shield::m_radius), type<float>(), "radius", var(float()), Member::Value, nullptr },
                { type<Shield>(), member_address(&Shield::m_charge), type<float>(), "charge", var(float()), Member::Value, nullptr },
                { type<Shield>(), member_address(&Shield::m_discharge), type<float>(), "discharge", var(float()), Member::Value, nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        init_pool<Shield>();
        meta_class<Shield>();
    }
    // Slug
    {
        static Meta meta = { type<Slug>(), &namspc({}), "Slug", sizeof(Slug), TypeClass::Object };
        static Class cls = { type<Slug>(),
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
                { type<Slug>(), member_address(&Slug::m_source), type<mud::vec3>(), "source", var(mud::vec3()), Member::Value, nullptr },
                { type<Slug>(), member_address(&Slug::m_velocity), type<mud::vec3>(), "velocity", var(mud::vec3()), Member::Value, nullptr },
                { type<Slug>(), member_address(&Slug::m_power), type<float>(), "power", var(float(1.f)), Member::Value, nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        meta_class<Slug>();
    }
    // Tank
    {
        static Meta meta = { type<Tank>(), &namspc({}), "Tank", sizeof(Tank), TypeClass::Object };
        static Class cls = { type<Tank>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<Tank>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<Tank>(ref)) Tank(  ); }, {} },
                { type<Tank>(), [](Ref ref, array<Var> args) { new(&val<Tank>(ref)) Tank( val<toy::HSpatial>(args[0]), val<toy::HMovable>(args[1]), val<toy::HEmitter>(args[2]), val<toy::HReceptor>(args[3]), val<Faction>(args[4]) ); }, { { "spatial", var(toy::HSpatial()) }, { "movable", var(toy::HMovable()) }, { "emitter", var(toy::HEmitter()) }, { "receptor", var(toy::HReceptor()) }, { "faction", Ref(type<Faction>()) } } }
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
        init_pool<Tank>();
        meta_class<Tank>();
    }
    // BlockWorld
    {
        static Meta meta = { type<BlockWorld>(), &namspc({}), "BlockWorld", sizeof(BlockWorld), TypeClass::Object };
        static Class cls = { type<BlockWorld>(),
            // bases
            { &type<mud::Complex>() },
            { base_offset<BlockWorld, mud::Complex>() },
            // constructors
            {
                { type<BlockWorld>(), [](Ref ref, array<Var> args) { new(&val<BlockWorld>(ref)) BlockWorld( val<string>(args[0]), val<mud::JobSystem>(args[1]) ); }, { { "name", var(string()) }, { "job_system", Ref(type<mud::JobSystem>()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<BlockWorld>(), member_address(&BlockWorld::m_world), type<toy::World>(), "world", Ref(type<toy::World>()), Member::NonMutable, nullptr },
                { type<BlockWorld>(), member_address(&BlockWorld::m_bullet_world), type<toy::BulletWorld>(), "bullet_world", Ref(type<toy::BulletWorld>()), Member::Flags(Member::NonMutable|Member::Component), nullptr },
                { type<BlockWorld>(), member_address(&BlockWorld::m_navmesh), type<toy::Navmesh>(), "navmesh", Ref(type<toy::Navmesh>()), Member::Flags(Member::NonMutable|Member::Component), nullptr },
                { type<BlockWorld>(), member_address(&BlockWorld::m_block_subdiv), type<mud::uvec3>(), "block_subdiv", var(mud::uvec3(20,4,20)), Member::Value, nullptr },
                { type<BlockWorld>(), member_address(&BlockWorld::m_tile_scale), type<mud::vec3>(), "tile_scale", var(mud::vec3()), Member::Value, nullptr },
                { type<BlockWorld>(), member_address(&BlockWorld::m_block_size), type<mud::vec3>(), "block_size", var(mud::vec3()), Member::Value, nullptr },
                { type<BlockWorld>(), member_address(&BlockWorld::m_world_size), type<mud::vec3>(), "world_size", var(mud::vec3()), Member::Value, nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        init_pool<BlockWorld>();
        meta_class<BlockWorld>();
    }
    // mud::ComponentHandle<Camp>
    {
        static Meta meta = { type<mud::ComponentHandle<Camp>>(), &namspc({ "mud" }), "ComponentHandle<Camp>", sizeof(mud::ComponentHandle<Camp>), TypeClass::Struct };
        static Class cls = { type<mud::ComponentHandle<Camp>>(),
            // bases
            { &type<mud::Entity>() },
            { base_offset<mud::ComponentHandle<Camp>, mud::Entity>() },
            // constructors
            {
                { type<mud::ComponentHandle<Camp>>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<mud::ComponentHandle<Camp>>(ref)) mud::ComponentHandle<Camp>(  ); }, {} }
            },
            // copy constructor
            {
                { type<mud::ComponentHandle<Camp>>(), [](Ref ref, Ref other) { new(&val<mud::ComponentHandle<Camp>>(ref)) mud::ComponentHandle<Camp>(val<mud::ComponentHandle<Camp>>(other)); } }
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
        meta_class<mud::ComponentHandle<Camp>>();
    }
    // mud::ComponentHandle<Shield>
    {
        static Meta meta = { type<mud::ComponentHandle<Shield>>(), &namspc({ "mud" }), "ComponentHandle<Shield>", sizeof(mud::ComponentHandle<Shield>), TypeClass::Struct };
        static Class cls = { type<mud::ComponentHandle<Shield>>(),
            // bases
            { &type<mud::Entity>() },
            { base_offset<mud::ComponentHandle<Shield>, mud::Entity>() },
            // constructors
            {
                { type<mud::ComponentHandle<Shield>>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<mud::ComponentHandle<Shield>>(ref)) mud::ComponentHandle<Shield>(  ); }, {} }
            },
            // copy constructor
            {
                { type<mud::ComponentHandle<Shield>>(), [](Ref ref, Ref other) { new(&val<mud::ComponentHandle<Shield>>(ref)) mud::ComponentHandle<Shield>(val<mud::ComponentHandle<Shield>>(other)); } }
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
        meta_class<mud::ComponentHandle<Shield>>();
    }
    // mud::ComponentHandle<Slug>
    {
        static Meta meta = { type<mud::ComponentHandle<Slug>>(), &namspc({ "mud" }), "ComponentHandle<Slug>", sizeof(mud::ComponentHandle<Slug>), TypeClass::Struct };
        static Class cls = { type<mud::ComponentHandle<Slug>>(),
            // bases
            { &type<mud::Entity>() },
            { base_offset<mud::ComponentHandle<Slug>, mud::Entity>() },
            // constructors
            {
                { type<mud::ComponentHandle<Slug>>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<mud::ComponentHandle<Slug>>(ref)) mud::ComponentHandle<Slug>(  ); }, {} }
            },
            // copy constructor
            {
                { type<mud::ComponentHandle<Slug>>(), [](Ref ref, Ref other) { new(&val<mud::ComponentHandle<Slug>>(ref)) mud::ComponentHandle<Slug>(val<mud::ComponentHandle<Slug>>(other)); } }
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
        meta_class<mud::ComponentHandle<Slug>>();
    }
    // mud::ComponentHandle<Tank>
    {
        static Meta meta = { type<mud::ComponentHandle<Tank>>(), &namspc({ "mud" }), "ComponentHandle<Tank>", sizeof(mud::ComponentHandle<Tank>), TypeClass::Struct };
        static Class cls = { type<mud::ComponentHandle<Tank>>(),
            // bases
            { &type<mud::Entity>() },
            { base_offset<mud::ComponentHandle<Tank>, mud::Entity>() },
            // constructors
            {
                { type<mud::ComponentHandle<Tank>>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<mud::ComponentHandle<Tank>>(ref)) mud::ComponentHandle<Tank>(  ); }, {} }
            },
            // copy constructor
            {
                { type<mud::ComponentHandle<Tank>>(), [](Ref ref, Ref other) { new(&val<mud::ComponentHandle<Tank>>(ref)) mud::ComponentHandle<Tank>(val<mud::ComponentHandle<Tank>>(other)); } }
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
        meta_class<mud::ComponentHandle<Tank>>();
    }
        m.m_types.push_back(&type<Camp>());
        m.m_types.push_back(&type<Faction>());
        m.m_types.push_back(&type<Player>());
        m.m_types.push_back(&type<Shield>());
        m.m_types.push_back(&type<Slug>());
        m.m_types.push_back(&type<Tank>());
        m.m_types.push_back(&type<BlockWorld>());
        m.m_types.push_back(&type<mud::ComponentHandle<Camp>>());
        m.m_types.push_back(&type<mud::ComponentHandle<Shield>>());
        m.m_types.push_back(&type<mud::ComponentHandle<Slug>>());
        m.m_types.push_back(&type<mud::ComponentHandle<Tank>>());
    }
}
