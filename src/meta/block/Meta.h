#pragma once

#ifndef MUD_MODULES
#include <meta/block/Module.h>

#include <type/Any.h>
#include <type/Vector.h>
#include <refl/MetaDecl.h>
#include <refl/Module.h>
#endif

#include <math/Api.h>

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
        //meta_sequence<array<toy::Element*>, toy::Element*>();
    }
    {
        static Meta meta = { type<vector<toy::Block*>>(), &namspc({}), "vector<toy::Block*>", sizeof(vector<toy::Block*>), TypeClass::Sequence };
        static Class cls = { type<vector<toy::Block*>>() };
        cls.m_content = &type<toy::Block>();
        meta_sequence<vector<toy::Block*>, toy::Block*>();
    }
    {
        static Meta meta = { type<vector<toy::Sector*>>(), &namspc({}), "vector<toy::Sector*>", sizeof(vector<toy::Sector*>), TypeClass::Sequence };
        static Class cls = { type<vector<toy::Sector*>>() };
        cls.m_content = &type<toy::Sector>();
        meta_sequence<vector<toy::Sector*>, toy::Sector*>();
    }
    
    // toy::Block
    {
        static Meta meta = { type<toy::Block>(), &namspc({ "toy" }), "Block", sizeof(toy::Block), TypeClass::Object };
        static Class cls = { type<toy::Block>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<toy::Block>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<toy::Block>(ref)) toy::Block(  ); }, {} },
                { type<toy::Block>(), [](Ref ref, array<Var> args) { new(&val<toy::Block>(ref)) toy::Block( val<toy::HSpatial>(args[0]), val<toy::HWorldPage>(args[1]), &val<toy::Block>(args[2]), val<size_t>(args[3]), val<mud::vec3>(args[4]) ); }, { { "spatial", var(toy::HSpatial()) }, { "world_page", var(toy::HWorldPage()) }, { "parentblock", Ref(type<toy::Block>()), Param::Nullable }, { "index", var(size_t()) }, { "size", var(mud::vec3()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<toy::Block>(), member_address(&toy::Block::m_world_page), type<toy::HWorldPage>(), "world_page", var(toy::HWorldPage()), Member::Value, nullptr },
                { type<toy::Block>(), member_address(&toy::Block::m_parentblock), type<toy::Block>(), "parentblock", Ref(type<toy::Block>()), Member::Flags(Member::Pointer|Member::Link), nullptr },
                { type<toy::Block>(), member_address(&toy::Block::m_index), type<size_t>(), "index", var(size_t()), Member::Value, nullptr },
                { type<toy::Block>(), member_address(&toy::Block::m_size), type<mud::vec3>(), "size", var(mud::vec3()), Member::Value, nullptr },
                { type<toy::Block>(), member_address(&toy::Block::m_updated), type<size_t>(), "updated", var(size_t(0)), Member::Value, nullptr }
            },
            // methods
            {
                { type<toy::Block>(), "subdivide", member_address<void(toy::Block::*)()>(&toy::Block::subdivide), [](Ref object, array<Var> args, Var& result) { UNUSED(result); UNUSED(args); val<toy::Block>(object).subdivide(); }, {}, Var() },
                { type<toy::Block>(), "reset", member_address<void(toy::Block::*)()>(&toy::Block::reset), [](Ref object, array<Var> args, Var& result) { UNUSED(result); UNUSED(args); val<toy::Block>(object).reset(); }, {}, Var() },
                { type<toy::Block>(), "chunk", member_address<void(toy::Block::*)(size_t, size_t, size_t, toy::Element&)>(&toy::Block::chunk), [](Ref object, array<Var> args, Var& result) { UNUSED(result); val<toy::Block>(object).chunk(val<size_t>(args[0]), val<size_t>(args[1]), val<size_t>(args[2]), val<toy::Element>(args[3])); }, { { "x", var(size_t()) }, { "y", var(size_t()) }, { "z", var(size_t()) }, { "element", Ref(type<toy::Element>()) } }, Var() },
                { type<toy::Block>(), "commit", member_address<void(toy::Block::*)()>(&toy::Block::commit), [](Ref object, array<Var> args, Var& result) { UNUSED(result); UNUSED(args); val<toy::Block>(object).commit(); }, {}, Var() }
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
            {  },
            {  },
            // constructors
            {
                { type<toy::Chunk>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<toy::Chunk>(ref)) toy::Chunk(  ); }, {} },
                { type<toy::Chunk>(), [](Ref ref, array<Var> args) { new(&val<toy::Chunk>(ref)) toy::Chunk( val<toy::HSpatial>(args[0]), val<toy::Block>(args[1]), val<size_t>(args[2]), val<toy::Element>(args[3]), val<float>(args[4]) ); }, { { "spatial", var(toy::HSpatial()) }, { "block", Ref(type<toy::Block>()) }, { "index", var(size_t()) }, { "element", Ref(type<toy::Element>()) }, { "size", var(float()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<toy::Chunk>(), member_address(&toy::Chunk::m_index), type<size_t>(), "index", var(size_t()), Member::Value, nullptr },
                { type<toy::Chunk>(), member_address(&toy::Chunk::m_block), type<toy::Block>(), "block", Ref(type<toy::Block>()), Member::Flags(Member::Pointer|Member::Link), nullptr },
                { type<toy::Chunk>(), member_address(&toy::Chunk::m_element), type<toy::Element>(), "element", Ref(type<toy::Element>()), Member::Flags(Member::Pointer|Member::Link), nullptr },
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
    // toy::Element
    {
        static Meta meta = { type<toy::Element>(), &namspc({ "toy" }), "Element", sizeof(toy::Element), TypeClass::Object };
        static Class cls = { type<toy::Element>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<toy::Element>(), [](Ref ref, array<Var> args) { new(&val<toy::Element>(ref)) toy::Element( val<const char*>(args[0]), val<toy::MatterState>(args[1]), val<mud::Colour>(args[2]) ); }, { { "name", Ref(type<const char*>()), Param::Nullable }, { "state", var(toy::MatterState()) }, { "colour", var(mud::Colour()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<toy::Element>(), member_address(&toy::Element::m_id), type<mud::Id>(), "id", var(mud::Id()), Member::Value, nullptr },
                { type<toy::Element>(), member_address(&toy::Element::m_name), type<string>(), "name", var(string()), Member::Value, nullptr },
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
                { type<mud::Grid<toy::Block*>>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<mud::Grid<toy::Block*>>(ref)) mud::Grid<toy::Block*>(  ); }, {} }
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
    // toy::Heap
    {
        static Meta meta = { type<toy::Heap>(), &namspc({ "toy" }), "Heap", sizeof(toy::Heap), TypeClass::Object };
        static Class cls = { type<toy::Heap>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<toy::Heap>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<toy::Heap>(ref)) toy::Heap(  ); }, {} },
                { type<toy::Heap>(), [](Ref ref, array<Var> args) { new(&val<toy::Heap>(ref)) toy::Heap( val<toy::HSpatial>(args[0]), val<toy::Element>(args[1]), val<float>(args[2]) ); }, { { "spatial", var(toy::HSpatial()) }, { "element", Ref(type<toy::Element>()) }, { "radius", var(float()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<toy::Heap>(), member_address(&toy::Heap::m_element), type<toy::Element>(), "element", Ref(type<toy::Element>()), Member::Flags(Member::Pointer|Member::Link), nullptr },
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
            {  },
            {  },
            // constructors
            {
                { type<toy::Sector>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<toy::Sector>(ref)) toy::Sector(  ); }, {} },
                { type<toy::Sector>(), [](Ref ref, array<Var> args) { new(&val<toy::Sector>(ref)) toy::Sector( val<toy::HSpatial>(args[0]), val<toy::HWorldPage>(args[1]), val<toy::HNavblock>(args[2]), val<mud::uvec3>(args[3]), val<mud::vec3>(args[4]) ); }, { { "spatial", var(toy::HSpatial()) }, { "world_page", var(toy::HWorldPage()) }, { "navblock", var(toy::HNavblock()) }, { "coordinate", var(mud::uvec3()) }, { "size", var(mud::vec3()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
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
            {  },
            {  },
            // constructors
            {
                { type<toy::Tileblock>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<toy::Tileblock>(ref)) toy::Tileblock(  ); }, {} },
                { type<toy::Tileblock>(), [](Ref ref, array<Var> args) { new(&val<toy::Tileblock>(ref)) toy::Tileblock( val<toy::HSpatial>(args[0]), val<toy::HWorldPage>(args[1]), val<toy::HNavblock>(args[2]), val<mud::uvec3>(args[3]), val<mud::vec3>(args[4]), val<mud::WaveTileset>(args[5]) ); }, { { "spatial", var(toy::HSpatial()) }, { "world_page", var(toy::HWorldPage()) }, { "navblock", var(toy::HNavblock()) }, { "size", var(mud::uvec3()) }, { "tile_scale", var(mud::vec3()) }, { "tileset", var(mud::WaveTileset()) } } }
            },
            // copy constructor
            {
            },
            // members
            {
                { type<toy::Tileblock>(), member_address(&toy::Tileblock::m_wfc_block), type<mud::WfcBlock>(), "wfc_block", Ref(type<mud::WfcBlock>()), Member::NonMutable, nullptr },
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
    // mud::ComponentHandle<toy::Block>
    {
        static Meta meta = { type<mud::ComponentHandle<toy::Block>>(), &namspc({ "mud" }), "ComponentHandle<toy::Block>", sizeof(mud::ComponentHandle<toy::Block>), TypeClass::Struct };
        static Class cls = { type<mud::ComponentHandle<toy::Block>>(),
            // bases
            { &type<mud::Entity>() },
            { base_offset<mud::ComponentHandle<toy::Block>, mud::Entity>() },
            // constructors
            {
                { type<mud::ComponentHandle<toy::Block>>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<mud::ComponentHandle<toy::Block>>(ref)) mud::ComponentHandle<toy::Block>(  ); }, {} }
            },
            // copy constructor
            {
                { type<mud::ComponentHandle<toy::Block>>(), [](Ref ref, Ref other) { new(&val<mud::ComponentHandle<toy::Block>>(ref)) mud::ComponentHandle<toy::Block>(val<mud::ComponentHandle<toy::Block>>(other)); } }
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
        meta_class<mud::ComponentHandle<toy::Block>>();
    }
    // mud::ComponentHandle<toy::Chunk>
    {
        static Meta meta = { type<mud::ComponentHandle<toy::Chunk>>(), &namspc({ "mud" }), "ComponentHandle<toy::Chunk>", sizeof(mud::ComponentHandle<toy::Chunk>), TypeClass::Struct };
        static Class cls = { type<mud::ComponentHandle<toy::Chunk>>(),
            // bases
            { &type<mud::Entity>() },
            { base_offset<mud::ComponentHandle<toy::Chunk>, mud::Entity>() },
            // constructors
            {
                { type<mud::ComponentHandle<toy::Chunk>>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<mud::ComponentHandle<toy::Chunk>>(ref)) mud::ComponentHandle<toy::Chunk>(  ); }, {} }
            },
            // copy constructor
            {
                { type<mud::ComponentHandle<toy::Chunk>>(), [](Ref ref, Ref other) { new(&val<mud::ComponentHandle<toy::Chunk>>(ref)) mud::ComponentHandle<toy::Chunk>(val<mud::ComponentHandle<toy::Chunk>>(other)); } }
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
        meta_class<mud::ComponentHandle<toy::Chunk>>();
    }
    // mud::ComponentHandle<toy::Heap>
    {
        static Meta meta = { type<mud::ComponentHandle<toy::Heap>>(), &namspc({ "mud" }), "ComponentHandle<toy::Heap>", sizeof(mud::ComponentHandle<toy::Heap>), TypeClass::Struct };
        static Class cls = { type<mud::ComponentHandle<toy::Heap>>(),
            // bases
            { &type<mud::Entity>() },
            { base_offset<mud::ComponentHandle<toy::Heap>, mud::Entity>() },
            // constructors
            {
                { type<mud::ComponentHandle<toy::Heap>>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<mud::ComponentHandle<toy::Heap>>(ref)) mud::ComponentHandle<toy::Heap>(  ); }, {} }
            },
            // copy constructor
            {
                { type<mud::ComponentHandle<toy::Heap>>(), [](Ref ref, Ref other) { new(&val<mud::ComponentHandle<toy::Heap>>(ref)) mud::ComponentHandle<toy::Heap>(val<mud::ComponentHandle<toy::Heap>>(other)); } }
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
        meta_class<mud::ComponentHandle<toy::Heap>>();
    }
    // mud::ComponentHandle<toy::Sector>
    {
        static Meta meta = { type<mud::ComponentHandle<toy::Sector>>(), &namspc({ "mud" }), "ComponentHandle<toy::Sector>", sizeof(mud::ComponentHandle<toy::Sector>), TypeClass::Struct };
        static Class cls = { type<mud::ComponentHandle<toy::Sector>>(),
            // bases
            { &type<mud::Entity>() },
            { base_offset<mud::ComponentHandle<toy::Sector>, mud::Entity>() },
            // constructors
            {
                { type<mud::ComponentHandle<toy::Sector>>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<mud::ComponentHandle<toy::Sector>>(ref)) mud::ComponentHandle<toy::Sector>(  ); }, {} }
            },
            // copy constructor
            {
                { type<mud::ComponentHandle<toy::Sector>>(), [](Ref ref, Ref other) { new(&val<mud::ComponentHandle<toy::Sector>>(ref)) mud::ComponentHandle<toy::Sector>(val<mud::ComponentHandle<toy::Sector>>(other)); } }
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
        meta_class<mud::ComponentHandle<toy::Sector>>();
    }
    // mud::ComponentHandle<toy::Tileblock>
    {
        static Meta meta = { type<mud::ComponentHandle<toy::Tileblock>>(), &namspc({ "mud" }), "ComponentHandle<toy::Tileblock>", sizeof(mud::ComponentHandle<toy::Tileblock>), TypeClass::Struct };
        static Class cls = { type<mud::ComponentHandle<toy::Tileblock>>(),
            // bases
            { &type<mud::Entity>() },
            { base_offset<mud::ComponentHandle<toy::Tileblock>, mud::Entity>() },
            // constructors
            {
                { type<mud::ComponentHandle<toy::Tileblock>>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<mud::ComponentHandle<toy::Tileblock>>(ref)) mud::ComponentHandle<toy::Tileblock>(  ); }, {} }
            },
            // copy constructor
            {
                { type<mud::ComponentHandle<toy::Tileblock>>(), [](Ref ref, Ref other) { new(&val<mud::ComponentHandle<toy::Tileblock>>(ref)) mud::ComponentHandle<toy::Tileblock>(val<mud::ComponentHandle<toy::Tileblock>>(other)); } }
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
        meta_class<mud::ComponentHandle<toy::Tileblock>>();
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
                { type<toy::Earth>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<toy::Earth>(ref)) toy::Earth(  ); }, {} }
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
        m.m_types.push_back(&type<toy::Block>());
        m.m_types.push_back(&type<toy::Chunk>());
        m.m_types.push_back(&type<toy::Element>());
        m.m_types.push_back(&type<mud::Grid<toy::Block*>>());
        m.m_types.push_back(&type<toy::Heap>());
        m.m_types.push_back(&type<toy::MatterState>());
        m.m_types.push_back(&type<toy::Sector>());
        m.m_types.push_back(&type<toy::Tileblock>());
        m.m_types.push_back(&type<array<toy::Element*>>());
        m.m_types.push_back(&type<vector<toy::Block*>>());
        m.m_types.push_back(&type<vector<toy::Sector*>>());
        m.m_types.push_back(&type<mud::ComponentHandle<toy::Block>>());
        m.m_types.push_back(&type<mud::ComponentHandle<toy::Chunk>>());
        m.m_types.push_back(&type<mud::ComponentHandle<toy::Heap>>());
        m.m_types.push_back(&type<mud::ComponentHandle<toy::Sector>>());
        m.m_types.push_back(&type<mud::ComponentHandle<toy::Tileblock>>());
        m.m_types.push_back(&type<toy::Earth>());
        {
            auto func = [](array<Var> args, Var& result) { UNUSED(result);  toy::paint_block_height(val<toy::Block>(args[0]), val<mud::Image256>(args[1]), val<toy::Element>(args[2])); };
            vector<Param> params = { { "block", Ref(type<toy::Block>()) }, { "image", var(mud::Image256()) }, { "element", Ref(type<toy::Element>()) } };
            static Function f = { &namspc({ "toy" }), "paint_block_height", funcptr<void(*)(toy::Block&, mud::Image256&, toy::Element&)>(&toy::paint_block_height), func, params, Var() };
            m.m_functions.push_back(&f);
        }
        {
            auto func = [](array<Var> args, Var& result) { UNUSED(result);  toy::paint_block_elements(val<toy::Block>(args[0]), val<mud::Image256>(args[1]), val<array<toy::Element*>>(args[2])); };
            vector<Param> params = { { "block", Ref(type<toy::Block>()) }, { "image", var(mud::Image256()) }, { "elements", var(array<toy::Element*>()) } };
            static Function f = { &namspc({ "toy" }), "paint_block_elements", funcptr<void(*)(toy::Block&, mud::Image256&, array<toy::Element*>)>(&toy::paint_block_elements), func, params, Var() };
            m.m_functions.push_back(&f);
        }
        {
            auto func = [](array<Var> args, Var& result) {  val<toy::HTileblock>(result) = toy::generate_block(val<mud::GfxSystem>(args[0]), val<mud::WaveTileset>(args[1]), val<toy::HSpatial>(args[2]), val<mud::ivec2>(args[3]), val<mud::uvec3>(args[4]), val<mud::vec3>(args[5]), val<bool>(args[6])); };
            vector<Param> params = { { "gfx_system", Ref(type<mud::GfxSystem>()) }, { "tileset", var(mud::WaveTileset()) }, { "origin", var(toy::HSpatial()) }, { "coord", var(mud::ivec2()) }, { "block_subdiv", var(mud::uvec3()) }, { "tile_scale", var(mud::vec3()) }, { "from_file", var(bool(true)), Param::Default } };
            static Function f = { &namspc({ "toy" }), "generate_block", funcptr<toy::HTileblock(*)(mud::GfxSystem&, mud::WaveTileset&, toy::HSpatial, const mud::ivec2&, const mud::uvec3&, const mud::vec3&, bool)>(&toy::generate_block), func, params, var(toy::HTileblock()) };
            m.m_functions.push_back(&f);
        }
        {
            auto func = [](array<Var> args, Var& result) { UNUSED(result);  toy::build_block_geometry(val<mud::Scene>(args[0]), val<toy::WorldPage>(args[1]), val<toy::Tileblock>(args[2])); };
            vector<Param> params = { { "scene", Ref(type<mud::Scene>()) }, { "page", Ref(type<toy::WorldPage>()) }, { "block", Ref(type<toy::Tileblock>()) } };
            static Function f = { &namspc({ "toy" }), "build_block_geometry", funcptr<void(*)(mud::Scene&, toy::WorldPage&, toy::Tileblock&)>(&toy::build_block_geometry), func, params, Var() };
            m.m_functions.push_back(&f);
        }
        //{
        //    auto func = [](array<Var> args, Var& result) { UNUSED(result);  toy::index_blocks(val<mud::ivec3>(args[0]), val<mud::Grid<toy::Block*>>(args[1]), val<vector<toy::Block*>>(args[2]), val<vector<toy::Sector*>>(args[3])); };
        //    vector<Param> params = { { "grid_size", var(mud::ivec3()) }, { "grid", var(mud::Grid<toy::Block*>()) }, { "blocks", var(vector<toy::Block*>()) }, { "sectors", var(vector<toy::Sector*>()) } };
        //    static Function f = { &namspc({ "toy" }), "index_blocks", funcptr<void(*)(const mud::ivec3&, mud::Grid<toy::Block*>&, const vector<toy::Block*>&, const vector<toy::Sector*>&)>(&toy::index_blocks), func, params, Var() };
        //    m.m_functions.push_back(&f);
        //}
    }
}
