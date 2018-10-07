

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
    // Base Types
    
    // Enums
    
    // Sequences
    
    
    
        
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
    
    
    
    
    
    
    
    
    
    
        
    // BlockWorld
    {
        static Meta meta = { type<BlockWorld>(), &namspc({}), "BlockWorld", sizeof(BlockWorld), TypeClass::Object };
        static Class cls = { type<BlockWorld>(),
            // bases
            { &type<mud::Complex>() },
            { base_offset<BlockWorld, mud::Complex>() },
            // constructors
            {
                //{ type<BlockWorld>(), [](Ref ref, array<Var> args) { new(&val<BlockWorld>(ref)) BlockWorld( val<std::string>(args[0]) ); }, { { "name", var(std::string()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<BlockWorld>(), member_address(&BlockWorld::m_world), type<toy::World>(), "world", Ref(type<toy::World>()), Member::Component, nullptr },
                { type<BlockWorld>(), member_address(&BlockWorld::m_bullet_world), type<toy::BulletWorld>(), "bullet_world", Ref(type<toy::BulletWorld>()), Member::Component, nullptr },
                { type<BlockWorld>(), member_address(&BlockWorld::m_navmesh), type<toy::Navmesh>(), "navmesh", Ref(type<toy::Navmesh>()), Member::Component, nullptr },
                { type<BlockWorld>(), member_address(&BlockWorld::m_block_subdiv), type<mud::uvec3>(), "block_subdiv", var(mud::uvec3()), Member::Value, nullptr },
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
    
    
        
    // Camp
    {
        static Meta meta = { type<Camp>(), &namspc({}), "Camp", sizeof(Camp), TypeClass::Object };
        static Class cls = { type<Camp>(),
            // bases
            { },
			{ },
            // constructors
            {
                { type<Camp>(), [](Ref ref, array<Var> args) { new(&val<Camp>(ref)) Camp( val<toy::HSpatial>(args[1]), val<mud::vec3>(args[2]), val<Faction>(args[3]) ); }, { { "id", var(mud::Id()) }, { "parent", Ref(type<toy::Spatial>()) }, { "position", var(mud::vec3()) }, { "faction", Ref(type<Faction>()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                //{ type<Camp>(), member_address(&Camp::m_spatial), type<toy::Spatial>(), "entity", Ref(type<toy::Spatial>()), Member::Component, nullptr },
                { type<Camp>(), member_address(&Camp::m_position), type<mud::vec3>(), "position", var(mud::vec3()), Member::Value, nullptr },
                //{ type<Camp>(), Address(), type<Faction>(), "faction", Ref(type<Faction>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<Camp>(object).m_faction); } }
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
    
    
        
    // Shield
    {
        static Meta meta = { type<Shield>(), &namspc({}), "Shield", sizeof(Shield), TypeClass::Object };
        static Class cls = { type<Shield>(),
            // bases
            { },
			{ },
            // constructors
            {
                //{ type<Shield>(), [](Ref ref, array<Var> args) { new(&val<Shield>(ref)) Shield( val<toy::HSpatial>(args[1]), val<mud::vec3>(args[2]), val<Faction>(args[3]), val<float>(args[4]) ); }, { { "id", var(mud::Id()) }, { "parent", Ref(type<toy::Spatial>()) }, { "position", var(mud::vec3()) }, { "faction", Ref(type<Faction>()) }, { "radius", var(float()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                //{ type<Shield>(), member_address(&Shield::m_spatial), type<toy::Spatial>(), "entity", Ref(type<toy::Spatial>()), Member::Component, nullptr },
                //{ type<Shield>(), member_address(&Shield::m_emitter), type<toy::Emitter>(), "emitter", Ref(type<toy::Emitter>()), Member::Component, nullptr },
                //{ type<Shield>(), Address(), type<Faction>(), "faction", Ref(type<Faction>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<Shield>(object).m_faction); } },
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
                //{ type<Slug>(), member_address(&Slug::m_spatial), type<toy::Spatial>(), "entity", Ref(type<toy::Spatial>()), Member::Component, nullptr },
                { type<Slug>(), member_address(&Slug::m_source), type<mud::vec3>(), "source", var(mud::vec3()), Member::Value, nullptr },
                { type<Slug>(), member_address(&Slug::m_velocity), type<mud::vec3>(), "velocity", var(mud::vec3()), Member::Value, nullptr }
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
            { },
			{ },
            // constructors
            {
                //{ type<Tank>(), [](Ref ref, array<Var> args) { new(&val<Tank>(ref)) Tank( val<toy::HSpatial>(args[1]), val<mud::vec3>(args[2]), val<Faction>(args[3]) ); }, { { "id", var(mud::Id()) }, { "parent", Ref(type<toy::Spatial>()) }, { "position", var(mud::vec3()) }, { "faction", Ref(type<Faction>()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                //{ type<Tank>(), member_address(&Tank::m_spatial), type<toy::Spatial>(), "entity", Ref(type<toy::Spatial>()), Member::Component, nullptr },
                //{ type<Tank>(), member_address(&Tank::m_movable), type<toy::Movable>(), "movable", Ref(type<toy::Movable>()), Member::Component, nullptr },
                //{ type<Tank>(), member_address(&Tank::m_emitter), type<toy::Emitter>(), "emitter", Ref(type<toy::Emitter>()), Member::Component, nullptr },
                //{ type<Tank>(), member_address(&Tank::m_receptor), type<toy::Receptor>(), "receptor", Ref(type<toy::Receptor>()), Member::Component, nullptr }
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
    
    
        
    // Well
    {
        static Meta meta = { type<Well>(), &namspc({}), "Well", sizeof(Well), TypeClass::Object };
        static Class cls = { type<Well>(),
            // bases
            { },
			{ },
            // constructors
            {
                //{ type<Well>(), [](Ref ref, array<Var> args) { new(&val<Well>(ref)) Well( val<toy::HSpatial>(args[1]), val<mud::vec3>(args[2]) ); }, { { "id", var(mud::Id()) }, { "parent", Ref(type<toy::Spatial>()) }, { "position", var(mud::vec3()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                //{ type<Well>(), member_address(&Well::m_spatial), type<toy::Spatial>(), "entity", Ref(type<toy::Spatial>()), Member::Component, nullptr },
                //{ type<Well>(), member_address(&Well::m_emitter), type<toy::Emitter>(), "emitter", Ref(type<toy::Emitter>()), Member::Component, nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        init_pool<Well>(); 
        
        meta_class<Well>();
    }
    

    
        m.m_types.push_back(&type<Faction>());
        m.m_types.push_back(&type<Player>());
        m.m_types.push_back(&type<BlockWorld>());
        m.m_types.push_back(&type<Camp>());
        m.m_types.push_back(&type<Shield>());
        m.m_types.push_back(&type<Slug>());
        m.m_types.push_back(&type<Tank>());
        m.m_types.push_back(&type<Well>());
    
    }
}
