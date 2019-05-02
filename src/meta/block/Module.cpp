#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module toy.block;
#else
#include <type/Vector.h>
#include <refl/MetaDecl.h>
#include <refl/Module.h>
#include <meta/type/Module.h>
#include <meta/math/Module.h>
#include <meta/wfc-gfx/Module.h>
#include <meta/core/Module.h>
#include <meta/visu/Module.h>
#include <meta/edit/Module.h>
#include <meta/block/Module.h>
#include <meta/block/Convert.h>
#endif

#include <block/Api.h>

using namespace two;

void toy_MatterState__to_string(void* val, string& str) { str = g_enu[type<toy::MatterState>().m_id]->name(uint32_t((*static_cast<toy::MatterState*>(val)))); }
void toy_MatterState__to_value(const string& str, void* val) { (*static_cast<toy::MatterState*>(val)) = toy::MatterState(g_enu[type<toy::MatterState>().m_id]->value(str.c_str())); }
size_t array_toy_Element____size(void* vec) { return (*static_cast<array<toy::Element*>*>(vec)).size(); }
void* array_toy_Element____at(void* vec, size_t i) { return &(*static_cast<array<toy::Element*>*>(vec))[i]; }
size_t vector_toy_Block____size(void* vec) { return (*static_cast<vector<toy::Block*>*>(vec)).size(); }
void* vector_toy_Block____at(void* vec, size_t i) { return &(*static_cast<vector<toy::Block*>*>(vec))[i]; }
void vector_toy_Block____add(void* vec, void* value) { (*static_cast<vector<toy::Block*>*>(vec)).push_back(static_cast<toy::Block*>(value)); }
void vector_toy_Block____remove(void* vec, void* value) { vector_remove_any((*static_cast<vector<toy::Block*>*>(vec)), static_cast<toy::Block*>(value)); }
size_t vector_toy_Sector____size(void* vec) { return (*static_cast<vector<toy::Sector*>*>(vec)).size(); }
void* vector_toy_Sector____at(void* vec, size_t i) { return &(*static_cast<vector<toy::Sector*>*>(vec))[i]; }
void vector_toy_Sector____add(void* vec, void* value) { (*static_cast<vector<toy::Sector*>*>(vec)).push_back(static_cast<toy::Sector*>(value)); }
void vector_toy_Sector____remove(void* vec, void* value) { vector_remove_any((*static_cast<vector<toy::Sector*>*>(vec)), static_cast<toy::Sector*>(value)); }
void toy_Block__construct_0(void* ref, array<void*> args) { UNUSED(args); new(stl::placeholder(), &(*static_cast<toy::Block*>(ref))) toy::Block(  ); }
void toy_Block__construct_1(void* ref, array<void*> args) { new(stl::placeholder(), &(*static_cast<toy::Block*>(ref))) toy::Block( *static_cast<toy::HSpatial*>(args[0]), *static_cast<toy::HWorldPage*>(args[1]), static_cast<toy::Block*>(args[2]), *static_cast<size_t*>(args[3]), *static_cast<two::vec3*>(args[4]) ); }
void toy_Block_subdivide(void* object, array<void*> args, void*& result) { UNUSED(result); UNUSED(args); (*static_cast<toy::Block*>(object)).subdivide(); }
void toy_Block_reset(void* object, array<void*> args, void*& result) { UNUSED(result); UNUSED(args); (*static_cast<toy::Block*>(object)).reset(); }
void toy_Block_chunk(void* object, array<void*> args, void*& result) { UNUSED(result); (*static_cast<toy::Block*>(object)).chunk(*static_cast<size_t*>(args[0]), *static_cast<size_t*>(args[1]), *static_cast<size_t*>(args[2]), *static_cast<toy::Element*>(args[3])); }
void toy_Block_commit(void* object, array<void*> args, void*& result) { UNUSED(result); UNUSED(args); (*static_cast<toy::Block*>(object)).commit(); }
void toy_Chunk__construct_0(void* ref, array<void*> args) { UNUSED(args); new(stl::placeholder(), &(*static_cast<toy::Chunk*>(ref))) toy::Chunk(  ); }
void toy_Chunk__construct_1(void* ref, array<void*> args) { new(stl::placeholder(), &(*static_cast<toy::Chunk*>(ref))) toy::Chunk( *static_cast<toy::HSpatial*>(args[0]), *static_cast<toy::Block*>(args[1]), *static_cast<size_t*>(args[2]), *static_cast<toy::Element*>(args[3]), *static_cast<float*>(args[4]) ); }
void toy_Element__construct_0(void* ref, array<void*> args) { new(stl::placeholder(), &(*static_cast<toy::Element*>(ref))) toy::Element( static_cast<const char*>(args[0]), *static_cast<toy::MatterState*>(args[1]), *static_cast<two::Colour*>(args[2]) ); }
void two_Grid_toy_Block____construct_0(void* ref, array<void*> args) { UNUSED(args); new(stl::placeholder(), &(*static_cast<two::Grid<toy::Block*>*>(ref))) two::Grid<toy::Block*>(  ); }
void two_Grid_toy_Block____copy_construct(void* ref, void* other) { new(stl::placeholder(), &(*static_cast<two::Grid<toy::Block*>*>(ref))) two::Grid<toy::Block*>((*static_cast<two::Grid<toy::Block*>*>(other))); }
void toy_Heap__construct_0(void* ref, array<void*> args) { UNUSED(args); new(stl::placeholder(), &(*static_cast<toy::Heap*>(ref))) toy::Heap(  ); }
void toy_Heap__construct_1(void* ref, array<void*> args) { new(stl::placeholder(), &(*static_cast<toy::Heap*>(ref))) toy::Heap( *static_cast<toy::HSpatial*>(args[0]), *static_cast<toy::Element*>(args[1]), *static_cast<float*>(args[2]) ); }
void toy_Sector__construct_0(void* ref, array<void*> args) { UNUSED(args); new(stl::placeholder(), &(*static_cast<toy::Sector*>(ref))) toy::Sector(  ); }
void toy_Sector__construct_1(void* ref, array<void*> args) { new(stl::placeholder(), &(*static_cast<toy::Sector*>(ref))) toy::Sector( *static_cast<toy::HSpatial*>(args[0]), *static_cast<toy::HWorldPage*>(args[1]), *static_cast<toy::HNavblock*>(args[2]), *static_cast<two::uvec3*>(args[3]), *static_cast<two::vec3*>(args[4]) ); }
void toy_Tileblock__construct_0(void* ref, array<void*> args) { UNUSED(args); new(stl::placeholder(), &(*static_cast<toy::Tileblock*>(ref))) toy::Tileblock(  ); }
void toy_Tileblock__construct_1(void* ref, array<void*> args) { new(stl::placeholder(), &(*static_cast<toy::Tileblock*>(ref))) toy::Tileblock( *static_cast<toy::HSpatial*>(args[0]), *static_cast<toy::HWorldPage*>(args[1]), *static_cast<toy::HNavblock*>(args[2]), *static_cast<two::uvec3*>(args[3]), *static_cast<two::vec3*>(args[4]), *static_cast<two::WaveTileset*>(args[5]) ); }
void two_ComponentHandle_toy_Block___construct_0(void* ref, array<void*> args) { UNUSED(args); new(stl::placeholder(), &(*static_cast<two::ComponentHandle<toy::Block>*>(ref))) two::ComponentHandle<toy::Block>(  ); }
void two_ComponentHandle_toy_Block___copy_construct(void* ref, void* other) { new(stl::placeholder(), &(*static_cast<two::ComponentHandle<toy::Block>*>(ref))) two::ComponentHandle<toy::Block>((*static_cast<two::ComponentHandle<toy::Block>*>(other))); }
void two_ComponentHandle_toy_Chunk___construct_0(void* ref, array<void*> args) { UNUSED(args); new(stl::placeholder(), &(*static_cast<two::ComponentHandle<toy::Chunk>*>(ref))) two::ComponentHandle<toy::Chunk>(  ); }
void two_ComponentHandle_toy_Chunk___copy_construct(void* ref, void* other) { new(stl::placeholder(), &(*static_cast<two::ComponentHandle<toy::Chunk>*>(ref))) two::ComponentHandle<toy::Chunk>((*static_cast<two::ComponentHandle<toy::Chunk>*>(other))); }
void two_ComponentHandle_toy_Heap___construct_0(void* ref, array<void*> args) { UNUSED(args); new(stl::placeholder(), &(*static_cast<two::ComponentHandle<toy::Heap>*>(ref))) two::ComponentHandle<toy::Heap>(  ); }
void two_ComponentHandle_toy_Heap___copy_construct(void* ref, void* other) { new(stl::placeholder(), &(*static_cast<two::ComponentHandle<toy::Heap>*>(ref))) two::ComponentHandle<toy::Heap>((*static_cast<two::ComponentHandle<toy::Heap>*>(other))); }
void two_ComponentHandle_toy_Sector___construct_0(void* ref, array<void*> args) { UNUSED(args); new(stl::placeholder(), &(*static_cast<two::ComponentHandle<toy::Sector>*>(ref))) two::ComponentHandle<toy::Sector>(  ); }
void two_ComponentHandle_toy_Sector___copy_construct(void* ref, void* other) { new(stl::placeholder(), &(*static_cast<two::ComponentHandle<toy::Sector>*>(ref))) two::ComponentHandle<toy::Sector>((*static_cast<two::ComponentHandle<toy::Sector>*>(other))); }
void two_ComponentHandle_toy_Tileblock___construct_0(void* ref, array<void*> args) { UNUSED(args); new(stl::placeholder(), &(*static_cast<two::ComponentHandle<toy::Tileblock>*>(ref))) two::ComponentHandle<toy::Tileblock>(  ); }
void two_ComponentHandle_toy_Tileblock___copy_construct(void* ref, void* other) { new(stl::placeholder(), &(*static_cast<two::ComponentHandle<toy::Tileblock>*>(ref))) two::ComponentHandle<toy::Tileblock>((*static_cast<two::ComponentHandle<toy::Tileblock>*>(other))); }
void toy_Earth__construct_0(void* ref, array<void*> args) { UNUSED(args); new(stl::placeholder(), &(*static_cast<toy::Earth*>(ref))) toy::Earth(  ); }
void toy_paint_block_height_0(array<void*> args, void*& result) { UNUSED(result);  toy::paint_block_height(*static_cast<toy::Block*>(args[0]), *static_cast<two::Image256*>(args[1]), *static_cast<toy::Element*>(args[2])); }
void toy_paint_block_elements_1(array<void*> args, void*& result) { UNUSED(result);  toy::paint_block_elements(*static_cast<toy::Block*>(args[0]), *static_cast<two::Image256*>(args[1]), *static_cast<array<toy::Element*>*>(args[2])); }
void toy_generate_block_2(array<void*> args, void*& result) { (*static_cast<toy::HTileblock*>(result)) = toy::generate_block(*static_cast<two::GfxSystem*>(args[0]), *static_cast<two::WaveTileset*>(args[1]), *static_cast<toy::HSpatial*>(args[2]), *static_cast<two::ivec2*>(args[3]), *static_cast<two::uvec3*>(args[4]), *static_cast<two::vec3*>(args[5]), *static_cast<bool*>(args[6])); }
void toy_build_block_geometry_3(array<void*> args, void*& result) { UNUSED(result);  toy::build_block_geometry(*static_cast<two::Scene*>(args[0]), *static_cast<toy::WorldPage*>(args[1]), *static_cast<toy::Tileblock*>(args[2])); }
void toy_index_blocks_4(array<void*> args, void*& result) { UNUSED(result);  toy::index_blocks(*static_cast<two::uvec3*>(args[0]), *static_cast<two::Grid<toy::Block*>*>(args[1]), *static_cast<vector<toy::Block*>*>(args[2]), *static_cast<vector<toy::Sector*>*>(args[3])); }

namespace two
{
	void toy_block_meta(Module& m)
	{
	UNUSED(m);
	
	// Base Types
	
	// Enums
	{
		Type& t = type<toy::MatterState>();
		static Meta meta = { t, &namspc({ "toy" }), "MatterState", sizeof(toy::MatterState), TypeClass::Enum };
		static cstring ids[] = { "Solid", "Liquid", "Gas", "Plasma" };
		static uint32_t values[] = { 0, 1, 2, 3 };
		static toy::MatterState vars[] = { toy::MatterState::Solid, toy::MatterState::Liquid, toy::MatterState::Gas, toy::MatterState::Plasma};
		static void* refs[] = { &vars[0], &vars[1], &vars[2], &vars[3]};
		static Enum enu = { t, true, ids, values, refs };
		static Convert convert = { toy_MatterState__to_string,
		                           toy_MatterState__to_value };
		g_convert[t.m_id] = &convert;
	}
	
	// Sequences
	{
		Type& t = type<array<toy::Element*>>();
		static Meta meta = { t, &namspc({}), "array<toy::Element*>", sizeof(array<toy::Element*>), TypeClass::Sequence };
		static Class cls = { t };
		static Iterable iterable = { &type<toy::Element>(),
		                             array_toy_Element____size,
		                             array_toy_Element____at};
		g_iterable[t.m_id] = &iterable;
	}
	{
		Type& t = type<vector<toy::Block*>>();
		static Meta meta = { t, &namspc({}), "vector<toy::Block*>", sizeof(vector<toy::Block*>), TypeClass::Sequence };
		static Class cls = { t };
		static Iterable iterable = { &type<toy::Block>(),
		                             vector_toy_Block____size,
		                             vector_toy_Block____at};
		g_iterable[t.m_id] = &iterable;
		static Sequence sequence = { vector_toy_Block____add,
		                             vector_toy_Block____remove };
		g_sequence[t.m_id] = &sequence;
	}
	{
		Type& t = type<vector<toy::Sector*>>();
		static Meta meta = { t, &namspc({}), "vector<toy::Sector*>", sizeof(vector<toy::Sector*>), TypeClass::Sequence };
		static Class cls = { t };
		static Iterable iterable = { &type<toy::Sector>(),
		                             vector_toy_Sector____size,
		                             vector_toy_Sector____at};
		g_iterable[t.m_id] = &iterable;
		static Sequence sequence = { vector_toy_Sector____add,
		                             vector_toy_Sector____remove };
		g_sequence[t.m_id] = &sequence;
	}
	
	// toy::Block
	{
		Type& t = type<toy::Block>();
		static Meta meta = { t, &namspc({ "toy" }), "Block", sizeof(toy::Block), TypeClass::Object };
		// bases
		// defaults
		static toy::Block* parentblock_default = nullptr;
		static size_t updated_default = 0;
		// constructors
		static Constructor constructors[] = {
			{ t, toy_Block__construct_0, {} },
			{ t, toy_Block__construct_1, { { "spatial", type<toy::HSpatial>(),  }, { "world_page", type<toy::HWorldPage>(),  }, { "parentblock", type<toy::Block>(), Param::Nullable }, { "index", type<size_t>(),  }, { "size", type<two::vec3>(),  } } }
		};
		// copy constructor
		// members
		static Member members[] = {
			{ t, offsetof(toy::Block, m_world_page), type<toy::HWorldPage>(), "world_page", nullptr, Member::Value, nullptr },
			{ t, offsetof(toy::Block, m_parentblock), type<toy::Block>(), "parentblock", parentblock_default, Member::Flags(Member::Pointer|Member::Link), nullptr },
			{ t, offsetof(toy::Block, m_index), type<size_t>(), "index", nullptr, Member::Value, nullptr },
			{ t, offsetof(toy::Block, m_size), type<two::vec3>(), "size", nullptr, Member::Value, nullptr },
			{ t, offsetof(toy::Block, m_updated), type<size_t>(), "updated", &updated_default, Member::Value, nullptr }
		};
		// methods
		static Method methods[] = {
			{ t, "subdivide", Address(), toy_Block_subdivide, {}, g_qvoid },
			{ t, "reset", Address(), toy_Block_reset, {}, g_qvoid },
			{ t, "chunk", Address(), toy_Block_chunk, { { "x", type<size_t>(),  }, { "y", type<size_t>(),  }, { "z", type<size_t>(),  }, { "element", type<toy::Element>(),  } }, g_qvoid },
			{ t, "commit", Address(), toy_Block_commit, {}, g_qvoid }
		};
		// static members
		static Class cls = { t, {}, {}, constructors, {}, members, methods, {}, };
	}
	// toy::Chunk
	{
		Type& t = type<toy::Chunk>();
		static Meta meta = { t, &namspc({ "toy" }), "Chunk", sizeof(toy::Chunk), TypeClass::Object };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, toy_Chunk__construct_0, {} },
			{ t, toy_Chunk__construct_1, { { "spatial", type<toy::HSpatial>(),  }, { "block", type<toy::Block>(),  }, { "index", type<size_t>(),  }, { "element", type<toy::Element>(),  }, { "size", type<float>(),  } } }
		};
		// copy constructor
		// members
		static Member members[] = {
			{ t, offsetof(toy::Chunk, m_index), type<size_t>(), "index", nullptr, Member::Value, nullptr },
			{ t, offsetof(toy::Chunk, m_block), type<toy::Block>(), "block", nullptr, Member::Flags(Member::Pointer|Member::Link), nullptr },
			{ t, offsetof(toy::Chunk, m_element), type<toy::Element>(), "element", nullptr, Member::Flags(Member::Pointer|Member::Link), nullptr },
			{ t, offsetof(toy::Chunk, m_size), type<float>(), "size", nullptr, Member::Value, nullptr }
		};
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, {}, members, {}, {}, };
	}
	// toy::Element
	{
		Type& t = type<toy::Element>();
		static Meta meta = { t, &namspc({ "toy" }), "Element", sizeof(toy::Element), TypeClass::Object };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, toy_Element__construct_0, { { "name", type<const char*>(), Param::Nullable }, { "state", type<toy::MatterState>(),  }, { "colour", type<two::Colour>(),  } } }
		};
		// copy constructor
		// members
		static Member members[] = {
			{ t, offsetof(toy::Element, m_id), type<uint32_t>(), "id", nullptr, Member::Value, nullptr },
			{ t, offsetof(toy::Element, m_name), type<string>(), "name", nullptr, Member::Value, nullptr },
			{ t, offsetof(toy::Element, m_state), type<toy::MatterState>(), "state", nullptr, Member::Value, nullptr },
			{ t, offsetof(toy::Element, m_colour), type<two::Colour>(), "colour", nullptr, Member::Value, nullptr }
		};
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, {}, members, {}, {}, };
	}
	// two::Grid<toy::Block*>
	{
		Type& t = type<two::Grid<toy::Block*>>();
		static Meta meta = { t, &namspc({ "two" }), "Grid<toy::Block*>", sizeof(two::Grid<toy::Block*>), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, two_Grid_toy_Block____construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, two_Grid_toy_Block____copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
	}
	// toy::Heap
	{
		Type& t = type<toy::Heap>();
		static Meta meta = { t, &namspc({ "toy" }), "Heap", sizeof(toy::Heap), TypeClass::Object };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, toy_Heap__construct_0, {} },
			{ t, toy_Heap__construct_1, { { "spatial", type<toy::HSpatial>(),  }, { "element", type<toy::Element>(),  }, { "radius", type<float>(),  } } }
		};
		// copy constructor
		// members
		static Member members[] = {
			{ t, offsetof(toy::Heap, m_element), type<toy::Element>(), "element", nullptr, Member::Flags(Member::Pointer|Member::Link), nullptr },
			{ t, offsetof(toy::Heap, m_radius), type<float>(), "radius", nullptr, Member::Value, nullptr }
		};
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, {}, members, {}, {}, };
	}
	// toy::Sector
	{
		Type& t = type<toy::Sector>();
		static Meta meta = { t, &namspc({ "toy" }), "Sector", sizeof(toy::Sector), TypeClass::Object };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, toy_Sector__construct_0, {} },
			{ t, toy_Sector__construct_1, { { "spatial", type<toy::HSpatial>(),  }, { "world_page", type<toy::HWorldPage>(),  }, { "navblock", type<toy::HNavblock>(),  }, { "coordinate", type<two::uvec3>(),  }, { "size", type<two::vec3>(),  } } }
		};
		// copy constructor
		// members
		static Member members[] = {
			{ t, offsetof(toy::Sector, m_coordinate), type<two::uvec3>(), "coordinate", nullptr, Member::Value, nullptr },
			{ t, offsetof(toy::Sector, m_size), type<two::vec3>(), "size", nullptr, Member::Value, nullptr },
			{ t, offsetof(toy::Sector, m_block), type<toy::Block>(), "block", nullptr, Member::Flags(Member::Pointer|Member::Link), nullptr }
		};
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, {}, members, {}, {}, };
	}
	// toy::Tileblock
	{
		Type& t = type<toy::Tileblock>();
		static Meta meta = { t, &namspc({ "toy" }), "Tileblock", sizeof(toy::Tileblock), TypeClass::Object };
		// bases
		// defaults
		static bool setup_default = false;
		static bool populated_default = false;
		// constructors
		static Constructor constructors[] = {
			{ t, toy_Tileblock__construct_0, {} },
			{ t, toy_Tileblock__construct_1, { { "spatial", type<toy::HSpatial>(),  }, { "world_page", type<toy::HWorldPage>(),  }, { "navblock", type<toy::HNavblock>(),  }, { "size", type<two::uvec3>(),  }, { "tile_scale", type<two::vec3>(),  }, { "tileset", type<two::WaveTileset>(),  } } }
		};
		// copy constructor
		// members
		static Member members[] = {
			{ t, offsetof(toy::Tileblock, m_wfc_block), type<two::WfcBlock>(), "wfc_block", nullptr, Member::NonMutable, nullptr },
			{ t, offsetof(toy::Tileblock, m_setup), type<bool>(), "setup", &setup_default, Member::Value, nullptr },
			{ t, offsetof(toy::Tileblock, m_populated), type<bool>(), "populated", &populated_default, Member::Value, nullptr }
		};
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, {}, members, {}, {}, };
	}
	// two::ComponentHandle<toy::Block>
	{
		Type& t = type<two::ComponentHandle<toy::Block>>();
		static Meta meta = { t, &namspc({ "two" }), "ComponentHandle<toy::Block>", sizeof(two::ComponentHandle<toy::Block>), TypeClass::Struct };
		// bases
		static Type* bases[] = { &type<two::Entity>() };
		static size_t bases_offsets[] = { base_offset<two::ComponentHandle<toy::Block>, two::Entity>() };
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, two_ComponentHandle_toy_Block___construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, two_ComponentHandle_toy_Block___copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, bases, bases_offsets, constructors, copy_constructor, {}, {}, {}, };
	}
	// two::ComponentHandle<toy::Chunk>
	{
		Type& t = type<two::ComponentHandle<toy::Chunk>>();
		static Meta meta = { t, &namspc({ "two" }), "ComponentHandle<toy::Chunk>", sizeof(two::ComponentHandle<toy::Chunk>), TypeClass::Struct };
		// bases
		static Type* bases[] = { &type<two::Entity>() };
		static size_t bases_offsets[] = { base_offset<two::ComponentHandle<toy::Chunk>, two::Entity>() };
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, two_ComponentHandle_toy_Chunk___construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, two_ComponentHandle_toy_Chunk___copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, bases, bases_offsets, constructors, copy_constructor, {}, {}, {}, };
	}
	// two::ComponentHandle<toy::Heap>
	{
		Type& t = type<two::ComponentHandle<toy::Heap>>();
		static Meta meta = { t, &namspc({ "two" }), "ComponentHandle<toy::Heap>", sizeof(two::ComponentHandle<toy::Heap>), TypeClass::Struct };
		// bases
		static Type* bases[] = { &type<two::Entity>() };
		static size_t bases_offsets[] = { base_offset<two::ComponentHandle<toy::Heap>, two::Entity>() };
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, two_ComponentHandle_toy_Heap___construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, two_ComponentHandle_toy_Heap___copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, bases, bases_offsets, constructors, copy_constructor, {}, {}, {}, };
	}
	// two::ComponentHandle<toy::Sector>
	{
		Type& t = type<two::ComponentHandle<toy::Sector>>();
		static Meta meta = { t, &namspc({ "two" }), "ComponentHandle<toy::Sector>", sizeof(two::ComponentHandle<toy::Sector>), TypeClass::Struct };
		// bases
		static Type* bases[] = { &type<two::Entity>() };
		static size_t bases_offsets[] = { base_offset<two::ComponentHandle<toy::Sector>, two::Entity>() };
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, two_ComponentHandle_toy_Sector___construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, two_ComponentHandle_toy_Sector___copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, bases, bases_offsets, constructors, copy_constructor, {}, {}, {}, };
	}
	// two::ComponentHandle<toy::Tileblock>
	{
		Type& t = type<two::ComponentHandle<toy::Tileblock>>();
		static Meta meta = { t, &namspc({ "two" }), "ComponentHandle<toy::Tileblock>", sizeof(two::ComponentHandle<toy::Tileblock>), TypeClass::Struct };
		// bases
		static Type* bases[] = { &type<two::Entity>() };
		static size_t bases_offsets[] = { base_offset<two::ComponentHandle<toy::Tileblock>, two::Entity>() };
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, two_ComponentHandle_toy_Tileblock___construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, two_ComponentHandle_toy_Tileblock___copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, bases, bases_offsets, constructors, copy_constructor, {}, {}, {}, };
	}
	// toy::Earth
	{
		Type& t = type<toy::Earth>();
		static Meta meta = { t, &namspc({ "toy" }), "Earth", sizeof(toy::Earth), TypeClass::Object };
		// bases
		static Type* bases[] = { &type<toy::Element>() };
		static size_t bases_offsets[] = { base_offset<toy::Earth, toy::Element>() };
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, toy_Earth__construct_0, {} }
		};
		// copy constructor
		// members
		// methods
		// static members
		static Static statics[] = {
			{ t, "me", Ref(&toy::Earth::me) }
		}
		static Class cls = { t, bases, bases_offsets, constructors, {}, {}, {}, statics, };
	}
		m.m_types.push_back(&type<toy::Block>());
		m.m_types.push_back(&type<toy::Chunk>());
		m.m_types.push_back(&type<toy::Element>());
		m.m_types.push_back(&type<two::Grid<toy::Block*>>());
		m.m_types.push_back(&type<toy::Heap>());
		m.m_types.push_back(&type<toy::MatterState>());
		m.m_types.push_back(&type<toy::Sector>());
		m.m_types.push_back(&type<toy::Tileblock>());
		m.m_types.push_back(&type<array<toy::Element*>>());
		m.m_types.push_back(&type<vector<toy::Block*>>());
		m.m_types.push_back(&type<vector<toy::Sector*>>());
		m.m_types.push_back(&type<two::ComponentHandle<toy::Block>>());
		m.m_types.push_back(&type<two::ComponentHandle<toy::Chunk>>());
		m.m_types.push_back(&type<two::ComponentHandle<toy::Heap>>());
		m.m_types.push_back(&type<two::ComponentHandle<toy::Sector>>());
		m.m_types.push_back(&type<two::ComponentHandle<toy::Tileblock>>());
		m.m_types.push_back(&type<toy::Earth>());
		{
			static Function f = { &namspc({ "toy" }), "paint_block_height", nullptr, toy_paint_block_height_0, { { "block", type<toy::Block>(),  }, { "image", type<two::Image256>(),  }, { "element", type<toy::Element>(),  } }, g_qvoid };
			m.m_functions.push_back(&f);
		}
		{
			static Function f = { &namspc({ "toy" }), "paint_block_elements", nullptr, toy_paint_block_elements_1, { { "block", type<toy::Block>(),  }, { "image", type<two::Image256>(),  }, { "elements", type<array<toy::Element*>>(),  } }, g_qvoid };
			m.m_functions.push_back(&f);
		}
		{
			static Function f = { &namspc({ "toy" }), "generate_block", nullptr, toy_generate_block_2, { { "gfx_system", type<two::GfxSystem>(),  }, { "tileset", type<two::WaveTileset>(),  }, { "origin", type<toy::HSpatial>(),  }, { "coord", type<two::ivec2>(),  }, { "block_subdiv", type<two::uvec3>(),  }, { "tile_scale", type<two::vec3>(),  }, { "from_file", type<bool>(), Param::Default } }, { &type<toy::HTileblock>(), QualType::None } };
			m.m_functions.push_back(&f);
		}
		{
			static Function f = { &namspc({ "toy" }), "build_block_geometry", nullptr, toy_build_block_geometry_3, { { "scene", type<two::Scene>(),  }, { "page", type<toy::WorldPage>(),  }, { "block", type<toy::Tileblock>(),  } }, g_qvoid };
			m.m_functions.push_back(&f);
		}
		{
			static Function f = { &namspc({ "toy" }), "index_blocks", nullptr, toy_index_blocks_4, { { "grid_size", type<two::uvec3>(),  }, { "grid", type<two::Grid<toy::Block*>>(),  }, { "blocks", type<vector<toy::Block*>>(),  }, { "sectors", type<vector<toy::Sector*>>(),  } }, g_qvoid };
			m.m_functions.push_back(&f);
		}
	}
}

namespace toy
{
	toy_block::toy_block()
		: Module("toy::block", { &two_type::m(), &two_math::m(), &two_wfc_gfx::m(), &toy_core::m(), &toy_visu::m(), &toy_edit::m() })
	{
		// setup reflection meta data
		toy_block_meta(*this);
	}
}

#ifdef TOY_BLOCK_MODULE
extern "C"
Module& getModule()
{
		return toy_block::m();
}
#endif
