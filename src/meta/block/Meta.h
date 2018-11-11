

#pragma once

#ifndef MUD_MODULES
#include <meta/block/Module.h>

#include <type/Any.h>
#include <type/Vector.h>
#include <refl/MetaDecl.h>
#include <refl/Module.h>
#endif

namespace mud
{
    void toy_block_meta(Module& m)
    {   
    // Base Types
    
    // Enums
    {
        static Meta meta = { type<toy::MatterState>(), &namspc({ "toy" }), "MatterState", sizeof(toy::MatterState), TypeClass::Enum };
        static Enum enu = { type<toy::MatterState>(),
            true,
            { "Solid", "Liquid", "Gas", "Plasma" },
            { 0, 1, 2, 3 },
            { var(toy::MatterState::Solid), var(toy::MatterState::Liquid), var(toy::MatterState::Gas), var(toy::MatterState::Plasma) }
        };
        meta_enum<toy::MatterState>();
    }
    
    
    // Sequences
    {
        static Meta meta = { type<array<toy::Element*>>(), &namspc({}), "array<toy::Element*>", sizeof(array<toy::Element*>), TypeClass::Sequence };
        static Class cls = { type<array<toy::Element*>>() };
        cls.m_content = &type<toy::Element>();
        meta_sequence<array<toy::Element*>, toy::Element*>();
    }
    
    {
        static Meta meta = { type<std::vector<toy::Block*>>(), &namspc({}), "std::vector<toy::Block*>", sizeof(std::vector<toy::Block*>), TypeClass::Sequence };
        static Class cls = { type<std::vector<toy::Block*>>() };
        cls.m_content = &type<toy::Block>();
        meta_sequence<std::vector<toy::Block*>, toy::Block*>();
    }
    
    {
        static Meta meta = { type<std::vector<toy::Sector*>>(), &namspc({}), "std::vector<toy::Sector*>", sizeof(std::vector<toy::Sector*>), TypeClass::Sequence };
        static Class cls = { type<std::vector<toy::Sector*>>() };
        cls.m_content = &type<toy::Sector>();
        meta_sequence<std::vector<toy::Sector*>, toy::Sector*>();
    }
    
    
    
    
    
    
        
    // toy::Element
    {
        static Meta meta = { type<toy::Element>(), &namspc({ "toy" }), "Element", sizeof(toy::Element), TypeClass::Object };
        static Class cls = { type<toy::Element>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<toy::Element>(), [](Ref ref, array<Var> args) { new(&val<toy::Element>(ref)) toy::Element( val<cstring>(args[0]), val<toy::MatterState>(args[1]), val<mud::Colour>(args[2]) ); }, { { "name", var(cstring()) }, { "state", var(toy::MatterState()) }, { "colour", var(mud::Colour()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<toy::Element>(), member_address(&toy::Element::m_id), type<mud::Id>(), "id", var(mud::Id()), Member::Value, nullptr },
                { type<toy::Element>(), member_address(&toy::Element::m_name), type<std::string>(), "name", var(std::string()), Member::Value, nullptr },
                { type<toy::Element>(), member_address(&toy::Element::m_state), type<toy::MatterState>(), "state", var(toy::MatterState()), Member::Value, nullptr },
                { type<toy::Element>(), member_address(&toy::Element::m_colour), type<mud::Colour>(), "colour", var(mud::Colour()), Member::Value, nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        init_pool<toy::Element>(); 
        
        meta_class<toy::Element>();
    }
    
    
        
    // mud::Grid<toy::Block*>
    {
        static Meta meta = { type<mud::Grid<toy::Block*>>(), &namspc({ "mud" }), "Grid<toy::Block*>", sizeof(mud::Grid<toy::Block*>), TypeClass::Struct };
        static Class cls = { type<mud::Grid<toy::Block*>>(),
            // bases
            {  },
            {  },
            // constructors
            {
            },
            // copy constructor
            {
                { type<mud::Grid<toy::Block*>>(), [](Ref ref, Ref other) { new(&val<mud::Grid<toy::Block*>>(ref)) mud::Grid<toy::Block*>(val<mud::Grid<toy::Block*>>(other)); } }
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
        
        
        
        
        meta_class<mud::Grid<toy::Block*>>();
    }
    
    
    
    
    
    
    
    
    
    
    
        
    // toy::Block
    {
        static Meta meta = { type<toy::Block>(), &namspc({ "toy" }), "Block", sizeof(toy::Block), TypeClass::Object };
        static Class cls = { type<toy::Block>(),
            // bases
            { },
			{ },
            // constructors
            {
                //{ type<toy::Block>(), [](Ref ref, array<Var> args) { new(&val<toy::Block>(ref)) toy::Block( val<toy::HSpatial>(args[1]), val<mud::vec3>(args[2]), &val<toy::Block>(args[3]), val<size_t>(args[4]), val<mud::vec3>(args[5]) ); }, { { "id", var(mud::Id()) }, { "parent", Ref(type<toy::Spatial>()) }, { "position", var(mud::vec3()) }, { "parentblock", Ref(type<toy::Block>()), Param::Nullable }, { "index", var(size_t()) }, { "size", var(mud::vec3()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                //{ type<toy::Block>(), member_address(&toy::Block::m_spatial), type<toy::Spatial>(), "entity", Ref(type<toy::HSpatial>()), Member::Component, nullptr },
                //{ type<toy::Block>(), member_address(&toy::Block::m_emitter), type<toy::Emitter>(), "emitter", Ref(type<toy::Emitter>()), Member::Component, nullptr },
                { type<toy::Block>(), member_address(&toy::Block::m_parentblock), type<toy::Block>(), "parentblock", Ref(type<toy::Block>()), Member::Flags(Member::Pointer|Member::Link), nullptr },
                { type<toy::Block>(), member_address(&toy::Block::m_index), type<size_t>(), "index", var(size_t()), Member::Value, nullptr },
                { type<toy::Block>(), member_address(&toy::Block::m_size), type<mud::vec3>(), "size", var(mud::vec3()), Member::Value, nullptr },
                { type<toy::Block>(), member_address(&toy::Block::m_updated), type<size_t>(), "updated", var(size_t()), Member::Value, nullptr }
            },
            // methods
            {
                //{ type<toy::Block>(), "subdivide", member_address(&toy::Block::subdivide), [](Ref object, array<Var> args, Var& result) { UNUSED(result); UNUSED(args);val<toy::Block>(object).subdivide(); }, {}, Var() },
                { type<toy::Block>(), "reset", member_address(&toy::Block::reset), [](Ref object, array<Var> args, Var& result) { UNUSED(result); UNUSED(args);val<toy::Block>(object).reset(); }, {}, Var() },
                { type<toy::Block>(), "chunk", member_address(&toy::Block::chunk), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::Block>(object).chunk(val<size_t>(args[0]), val<size_t>(args[1]), val<size_t>(args[2]), val<toy::Element>(args[3])); }, { { "x", var(size_t()) }, { "y", var(size_t()) }, { "z", var(size_t()) }, { "element", Ref(type<toy::Element>()) } }, Var() },
                { type<toy::Block>(), "commit", member_address(&toy::Block::commit), [](Ref object, array<Var> args, Var& result) { UNUSED(result); UNUSED(args);val<toy::Block>(object).commit(); }, {}, Var() }
            },
            // static members
            {
            }
        };
        
        
        init_pool<toy::Block>(); 
        
        meta_class<toy::Block>();
    }
    
    
        
    // toy::Chunk
    {
        static Meta meta = { type<toy::Chunk>(), &namspc({ "toy" }), "Chunk", sizeof(toy::Chunk), TypeClass::Object };
        static Class cls = { type<toy::Chunk>(),
            // bases
            { },
			{ },
            // constructors
            {
                //{ type<toy::Chunk>(), [](Ref ref, array<Var> args) { new(&val<toy::Chunk>(ref)) toy::Chunk( val<toy::HSpatial>(args[1]), val<toy::Block>(args[1]), val<mud::vec3>(args[2]), val<size_t>(args[3]), val<toy::Element>(args[4]), val<float>(args[5]) ); }, { { "id", var(mud::Id()) }, { "parent", Ref(type<toy::Spatial>()) }, { "position", var(mud::vec3()) }, { "index", var(size_t()) }, { "element", Ref(type<toy::Element>()) }, { "size", var(float()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                //{ type<toy::Chunk>(), member_address(&toy::Chunk::m_spatial), type<toy::Spatial>(), "entity", Ref(type<toy::HSpatial>()), Member::Component, nullptr },
                { type<toy::Chunk>(), member_address(&toy::Chunk::m_index), type<size_t>(), "index", var(size_t()), Member::Value, nullptr },
                //{ type<toy::Chunk>(), Address(), type<toy::Block>(), "block", Ref(type<toy::Block>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::Chunk>(object).m_block); } },
                //{ type<toy::Chunk>(), Address(), type<toy::Element>(), "element", Ref(type<toy::Element>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::Chunk>(object).m_element); } },
                { type<toy::Chunk>(), member_address(&toy::Chunk::m_size), type<float>(), "size", var(float()), Member::Value, nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        init_pool<toy::Chunk>(); 
        
        meta_class<toy::Chunk>();
    }
    
    
        
    // toy::Heap
    {
        static Meta meta = { type<toy::Heap>(), &namspc({ "toy" }), "Heap", sizeof(toy::Heap), TypeClass::Object };
        static Class cls = { type<toy::Heap>(),
            // bases
            { },
			{ },
            // constructors
            {
                //{ type<toy::Heap>(), [](Ref ref, array<Var> args) { new(&val<toy::Heap>(ref)) toy::Heap( val<toy::HSpatial>(args[1]), val<mud::vec3>(args[2]), val<toy::Element>(args[3]), val<float>(args[4]) ); }, { { "id", var(mud::Id()) }, { "parent", Ref(type<toy::Spatial>()) }, { "position", var(mud::vec3()) }, { "element", Ref(type<toy::Element>()) }, { "radius", var(float()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                //{ type<toy::Heap>(), member_address(&toy::Heap::m_spatial), type<toy::Spatial>(), "entity", Ref(type<toy::HSpatial>()), Member::Component, nullptr },
                //{ type<toy::Heap>(), Address(), type<toy::Element>(), "element", Ref(type<toy::Element>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::Heap>(object).m_element); } },
                { type<toy::Heap>(), member_address(&toy::Heap::m_radius), type<float>(), "radius", var(float()), Member::Value, nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        init_pool<toy::Heap>(); 
        
        meta_class<toy::Heap>();
    }
    
    
        
    // toy::Sector
    {
        static Meta meta = { type<toy::Sector>(), &namspc({ "toy" }), "Sector", sizeof(toy::Sector), TypeClass::Object };
        static Class cls = { type<toy::Sector>(),
            // bases
            { },
			{ },
            // constructors
            {
                //{ type<toy::Sector>(), [](Ref ref, array<Var> args) { new(&val<toy::Sector>(ref)) toy::Sector( val<toy::HSpatial>(args[1]), val<mud::vec3>(args[2]), val<mud::uvec3>(args[3]), val<mud::vec3>(args[4]) ); }, { { "id", var(mud::Id()) }, { "parent", Ref(type<toy::Spatial>()) }, { "position", var(mud::vec3()) }, { "coordinate", var(mud::uvec3()) }, { "size", var(mud::vec3()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                //{ type<toy::Sector>(), member_address(&toy::Sector::m_spatial), type<toy::Spatial>(), "entity", Ref(type<toy::HSpatial>()), Member::Component, nullptr },
                //{ type<toy::Sector>(), member_address(&toy::Sector::m_emitter), type<toy::Emitter>(), "emitter", Ref(type<toy::Emitter>()), Member::Component, nullptr },
                //{ type<toy::Sector>(), member_address(&toy::Sector::m_world_page), type<toy::WorldPage>(), "world_page", Ref(type<toy::WorldPage>()), Member::Component, nullptr },
                //{ type<toy::Sector>(), member_address(&toy::Sector::m_buffer_page), type<toy::BufferPage>(), "bufferPage", Ref(type<toy::BufferPage>()), Member::Component, nullptr },
                //{ type<toy::Sector>(), member_address(&toy::Sector::m_navblock), type<toy::Navblock>(), "navblock", Ref(type<toy::Navblock>()), Member::Component, nullptr },
                { type<toy::Sector>(), member_address(&toy::Sector::m_coordinate), type<mud::uvec3>(), "coordinate", var(mud::uvec3()), Member::Value, nullptr },
                { type<toy::Sector>(), member_address(&toy::Sector::m_size), type<mud::vec3>(), "size", var(mud::vec3()), Member::Value, nullptr },
                { type<toy::Sector>(), member_address(&toy::Sector::m_block), type<toy::Block>(), "block", Ref(type<toy::Block>()), Member::Flags(Member::Pointer|Member::Link), nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        init_pool<toy::Sector>(); 
        
        meta_class<toy::Sector>();
    }
    
    
        
    // toy::Tileblock
    {
        static Meta meta = { type<toy::Tileblock>(), &namspc({ "toy" }), "Tileblock", sizeof(toy::Tileblock), TypeClass::Object };
        static Class cls = { type<toy::Tileblock>(),
            // bases
            { },
			{ },
            // constructors
            {
                //{ type<toy::Tileblock>(), [](Ref ref, array<Var> args) { new(&val<toy::Tileblock>(ref)) toy::Tileblock( val<toy::HSpatial>(args[1]), val<mud::vec3>(args[2]), val<mud::uvec3>(args[3]), val<mud::vec3>(args[4]), val<mud::WaveTileset>(args[5]) ); }, { { "id", var(mud::Id()) }, { "parent", Ref(type<toy::Spatial>()) }, { "position", var(mud::vec3()) }, { "size", var(mud::uvec3()) }, { "tile_scale", var(mud::vec3()) }, { "tileset", var(mud::WaveTileset()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                //{ type<toy::Tileblock>(), member_address(&toy::Tileblock::m_spatial), type<toy::Spatial>(), "entity", Ref(type<toy::HSpatial>()), Member::Component, nullptr },
                //{ type<toy::Tileblock>(), member_address(&toy::Tileblock::m_emitter), type<toy::Emitter>(), "emitter", Ref(type<toy::Emitter>()), Member::Component, nullptr },
                //{ type<toy::Tileblock>(), member_address(&toy::Tileblock::m_world_page), type<toy::WorldPage>(), "world_page", Ref(type<toy::WorldPage>()), Member::Component, nullptr },
                //{ type<toy::Tileblock>(), member_address(&toy::Tileblock::m_navblock), type<toy::Navblock>(), "navblock", Ref(type<toy::Navblock>()), Member::Component, nullptr },
                { type<toy::Tileblock>(), member_address(&toy::Tileblock::m_wfc_block), type<mud::WfcBlock>(), "wfc_block", Ref(type<mud::WfcBlock>()), Member::None, nullptr },
                { type<toy::Tileblock>(), member_address(&toy::Tileblock::m_setup), type<bool>(), "setup", var(bool(false)), Member::Value, nullptr },
                { type<toy::Tileblock>(), member_address(&toy::Tileblock::m_populated), type<bool>(), "populated", var(bool(false)), Member::Value, nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        init_pool<toy::Tileblock>(); 
        
        meta_class<toy::Tileblock>();
    }
    
    
    
        
    // toy::Earth
    {
        static Meta meta = { type<toy::Earth>(), &namspc({ "toy" }), "Earth", sizeof(toy::Earth), TypeClass::Object };
        static Class cls = { type<toy::Earth>(),
            // bases
            { &type<toy::Element>() },
            { base_offset<toy::Earth, toy::Element>() },
            // constructors
            {
                { type<toy::Earth>(), [](Ref ref, array<Var> args) { UNUSED(args);new(&val<toy::Earth>(ref)) toy::Earth(  ); }, {} }
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
                { type<toy::Earth>(), "me", Ref(&toy::Earth::me) }
            }
        };
        
        
        init_pool<toy::Earth>(); 
        
        meta_class<toy::Earth>();
    }
    
    
    
    
    
    
    

    
        m.m_types.push_back(&type<toy::Element>());
        m.m_types.push_back(&type<mud::Grid<toy::Block*>>());
        m.m_types.push_back(&type<toy::MatterState>());
        m.m_types.push_back(&type<array<toy::Element*>>());
        m.m_types.push_back(&type<std::vector<toy::Block*>>());
        m.m_types.push_back(&type<std::vector<toy::Sector*>>());
        m.m_types.push_back(&type<toy::Block>());
        m.m_types.push_back(&type<toy::Chunk>());
        m.m_types.push_back(&type<toy::Heap>());
        m.m_types.push_back(&type<toy::Sector>());
        m.m_types.push_back(&type<toy::Tileblock>());
        m.m_types.push_back(&type<toy::Earth>());
    
        {
            auto func = [](array<Var> args, Var& result) { UNUSED(result);  toy::paint_block_height(val<toy::Block>(args[0]), val<mud::Image256>(args[1]), val<toy::Element>(args[2])); };
            std::vector<Param> params = { { "block", Ref(type<toy::Block>()) }, { "image", var(mud::Image256()) }, { "element", Ref(type<toy::Element>()) } };
            static Function f = { &namspc({ "toy" }), "paint_block_height", function_id<void(*)(toy::Block&, mud::Image256&, toy::Element&)>(&toy::paint_block_height), func, params, Var() };
            m.m_functions.push_back(&f);
        }
        {
            auto func = [](array<Var> args, Var& result) { UNUSED(result);  toy::paint_block_elements(val<toy::Block>(args[0]), val<mud::Image256>(args[1]), val<array<toy::Element*>>(args[2])); };
            std::vector<Param> params = { { "block", Ref(type<toy::Block>()) }, { "image", var(mud::Image256()) }, { "elements", var(array<toy::Element*>()) } };
            static Function f = { &namspc({ "toy" }), "paint_block_elements", function_id<void(*)(toy::Block&, mud::Image256&, array<toy::Element*>)>(&toy::paint_block_elements), func, params, Var() };
            m.m_functions.push_back(&f);
        }
        //{
        //    auto func = [](array<Var> args, Var& result) {  result = Ref(&toy::generate_block(val<mud::GfxSystem>(args[0]), val<mud::WaveTileset>(args[1]), val<toy::HSpatial>(args[2]), val<mud::ivec2>(args[3]), val<mud::uvec3>(args[4]), val<mud::vec3>(args[5]), val<bool>(args[6]))); };
        //    std::vector<Param> params = { { "gfx_system", Ref(type<mud::GfxSystem>()) }, { "tileset", var(mud::WaveTileset()) }, { "origin", Ref(type<toy::Spatial>()) }, { "coord", var(mud::ivec2()) }, { "block_subdiv", var(mud::uvec3()) }, { "tile_scale", var(mud::vec3()) }, { "from_file", var(bool(true)), Param::Default } };
        //    static Function f = { &namspc({ "toy" }), "generate_block", function_id<toy::HTileblock(*)(mud::GfxSystem&, mud::WaveTileset&, toy::HSpatial, const mud::ivec2&, const mud::uvec3&, const mud::vec3&, bool)>(&toy::generate_block), func, params, Ref(type<toy::Tileblock>()) };
        //    m.m_functions.push_back(&f);
        //}
        {
            auto func = [](array<Var> args, Var& result) { UNUSED(result);  toy::build_block_geometry(val<mud::Scene>(args[0]), val<toy::WorldPage>(args[1]), val<toy::Tileblock>(args[2])); };
            std::vector<Param> params = { { "scene", Ref(type<mud::Scene>()) }, { "page", Ref(type<toy::WorldPage>()) }, { "block", Ref(type<toy::Tileblock>()) } };
            static Function f = { &namspc({ "toy" }), "build_block_geometry", function_id<void(*)(mud::Scene&, toy::WorldPage&, toy::Tileblock&)>(&toy::build_block_geometry), func, params, Var() };
            m.m_functions.push_back(&f);
        }
        {
            auto func = [](array<Var> args, Var& result) { UNUSED(result);  toy::index_blocks(val<mud::ivec3>(args[0]), val<mud::Grid<toy::Block*>>(args[1]), val<std::vector<toy::Block*>>(args[2]), val<std::vector<toy::Sector*>>(args[3])); };
            std::vector<Param> params = { { "grid_size", var(mud::ivec3()) }, { "grid", var(mud::Grid<toy::Block*>()) }, { "blocks", var(std::vector<toy::Block*>()) }, { "sectors", var(std::vector<toy::Sector*>()) } };
            static Function f = { &namspc({ "toy" }), "index_blocks", function_id<void(*)(const mud::ivec3&, mud::Grid<toy::Block*>&, const std::vector<toy::Block*>&, const std::vector<toy::Sector*>&)>(&toy::index_blocks), func, params, Var() };
            m.m_functions.push_back(&f);
        }
    }
}
