#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module ._blocks;
#else
#include <cstddef>
#include <stl/new.h>
#include <infra/ToString.h>
#include <infra/ToValue.h>
#include <type/Vector.h>
#include <refl/MetaDecl.h>
#include <refl/Module.h>
#include <meta/infra.meta.h>
#include <meta/jobs.meta.h>
#include <meta/type.meta.h>
#include <meta/tree.meta.h>
#include <meta/pool.meta.h>
#include <meta/refl.meta.h>
#include <meta/ecs.meta.h>
#include <meta/srlz.meta.h>
#include <meta/math.meta.h>
#include <meta/geom.meta.h>
#include <meta/lang.meta.h>
#include <meta/ctx.meta.h>
#include <meta/ui.meta.h>
#include <meta/uio.meta.h>
#include <meta/bgfx.meta.h>
#include <meta/gfx.meta.h>
#include <meta/gfx.ui.meta.h>
#include <meta/frame.meta.h>
#include <meta/util.meta.h>
#include <meta/core.meta.h>
#include <meta/visu.meta.h>
#include <meta/edit.meta.h>
#include <meta/block.meta.h>
#include <meta/shell.meta.h>
#include <meta/_blocks.meta.h>
#include <meta/_blocks.conv.h>
#endif

#include <blocks/Api.h>

using namespace mud;

void Camp__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) Camp(  ); }
void Camp__construct_1(void* ref, span<void*> args) { new(stl::placeholder(), ref) Camp( *static_cast<toy::HSpatial*>(args[0]), *static_cast<mud::vec3*>(args[1]), *static_cast<Faction*>(args[2]) ); }
void mud_ComponentHandle_Camp__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) mud::ComponentHandle<Camp>(  ); }
void mud_ComponentHandle_Camp__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) mud::ComponentHandle<Camp>((*static_cast<mud::ComponentHandle<Camp>*>(other))); }
void mud_ComponentHandle_Shield__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) mud::ComponentHandle<Shield>(  ); }
void mud_ComponentHandle_Shield__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) mud::ComponentHandle<Shield>((*static_cast<mud::ComponentHandle<Shield>*>(other))); }
void mud_ComponentHandle_Slug__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) mud::ComponentHandle<Slug>(  ); }
void mud_ComponentHandle_Slug__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) mud::ComponentHandle<Slug>((*static_cast<mud::ComponentHandle<Slug>*>(other))); }
void mud_ComponentHandle_Tank__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) mud::ComponentHandle<Tank>(  ); }
void mud_ComponentHandle_Tank__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) mud::ComponentHandle<Tank>((*static_cast<mud::ComponentHandle<Tank>*>(other))); }
void Faction__construct_0(void* ref, span<void*> args) { new(stl::placeholder(), ref) Faction( *static_cast<uint32_t*>(args[0]), *static_cast<mud::Colour*>(args[1]) ); }
void Shield__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) Shield(  ); }
void Shield__construct_1(void* ref, span<void*> args) { new(stl::placeholder(), ref) Shield( *static_cast<toy::HSpatial*>(args[0]), *static_cast<toy::HEmitter*>(args[1]), *static_cast<Faction*>(args[2]), *static_cast<float*>(args[3]) ); }
void Tank__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) Tank(  ); }
void Tank__construct_1(void* ref, span<void*> args) { new(stl::placeholder(), ref) Tank( *static_cast<toy::HSpatial*>(args[0]), *static_cast<toy::HMovable*>(args[1]), *static_cast<toy::HEmitter*>(args[2]), *static_cast<toy::HReceptor*>(args[3]), *static_cast<Faction*>(args[4]) ); }
void BlockWorld__construct_0(void* ref, span<void*> args) { new(stl::placeholder(), ref) BlockWorld( *static_cast<stl::string*>(args[0]), *static_cast<mud::JobSystem*>(args[1]) ); }

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
		Type& t = type<Camp>();
		static Meta meta = { t, &namspc({}), "Camp", sizeof(Camp), TypeClass::Object };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, Camp__construct_0, {} },
			{ t, Camp__construct_1, { { "spatial", type<toy::HSpatial>(),  }, { "position", type<mud::vec3>(),  }, { "faction", type<Faction>(),  } } }
		};
		// copy constructor
		// members
		static Member members[] = {
			{ t, offsetof(Camp, m_position), type<mud::vec3>(), "position", nullptr, Member::Value, nullptr },
			{ t, offsetof(Camp, m_faction), type<Faction>(), "faction", nullptr, Member::Flags(Member::Pointer|Member::Link), nullptr }
		};
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, {}, members, {}, {}, };
	}
	// mud::ComponentHandle<Camp>
	{
		Type& t = type<mud::ComponentHandle<Camp>>();
		static Meta meta = { t, &namspc({ "mud" }), "ComponentHandle<Camp>", sizeof(mud::ComponentHandle<Camp>), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, mud_ComponentHandle_Camp__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, mud_ComponentHandle_Camp__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
	}
	// mud::ComponentHandle<Shield>
	{
		Type& t = type<mud::ComponentHandle<Shield>>();
		static Meta meta = { t, &namspc({ "mud" }), "ComponentHandle<Shield>", sizeof(mud::ComponentHandle<Shield>), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, mud_ComponentHandle_Shield__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, mud_ComponentHandle_Shield__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
	}
	// mud::ComponentHandle<Slug>
	{
		Type& t = type<mud::ComponentHandle<Slug>>();
		static Meta meta = { t, &namspc({ "mud" }), "ComponentHandle<Slug>", sizeof(mud::ComponentHandle<Slug>), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, mud_ComponentHandle_Slug__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, mud_ComponentHandle_Slug__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
	}
	// mud::ComponentHandle<Tank>
	{
		Type& t = type<mud::ComponentHandle<Tank>>();
		static Meta meta = { t, &namspc({ "mud" }), "ComponentHandle<Tank>", sizeof(mud::ComponentHandle<Tank>), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, mud_ComponentHandle_Tank__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, mud_ComponentHandle_Tank__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
	}
	// Faction
	{
		Type& t = type<Faction>();
		static Meta meta = { t, &namspc({}), "Faction", sizeof(Faction), TypeClass::Object };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, Faction__construct_0, { { "id", type<uint32_t>(),  }, { "colour", type<mud::Colour>(),  } } }
		};
		// copy constructor
		// members
		static Member members[] = {
			{ t, offsetof(Faction, m_id), type<uint32_t>(), "id", nullptr, Member::Value, nullptr },
			{ t, offsetof(Faction, m_colour), type<mud::Colour>(), "colour", nullptr, Member::Value, nullptr }
		};
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, {}, members, {}, {}, };
	}
	// Player
	{
		Type& t = type<Player>();
		static Meta meta = { t, &namspc({}), "Player", sizeof(Player), TypeClass::Object };
		// bases
		// defaults
		// constructors
		// copy constructor
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, {}, {}, {}, {}, {}, };
	}
	// Shield
	{
		Type& t = type<Shield>();
		static Meta meta = { t, &namspc({}), "Shield", sizeof(Shield), TypeClass::Object };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, Shield__construct_0, {} },
			{ t, Shield__construct_1, { { "spatial", type<toy::HSpatial>(),  }, { "emitter", type<toy::HEmitter>(),  }, { "faction", type<Faction>(),  }, { "radius", type<float>(),  } } }
		};
		// copy constructor
		// members
		static Member members[] = {
			{ t, offsetof(Shield, m_faction), type<Faction>(), "faction", nullptr, Member::Flags(Member::Pointer|Member::Link), nullptr },
			{ t, offsetof(Shield, m_radius), type<float>(), "radius", nullptr, Member::Value, nullptr },
			{ t, offsetof(Shield, m_charge), type<float>(), "charge", nullptr, Member::Value, nullptr },
			{ t, offsetof(Shield, m_discharge), type<float>(), "discharge", nullptr, Member::Value, nullptr }
		};
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, {}, members, {}, {}, };
	}
	// Slug
	{
		Type& t = type<Slug>();
		static Meta meta = { t, &namspc({}), "Slug", sizeof(Slug), TypeClass::Object };
		// bases
		// defaults
		static float power_default = 1.f;
		// constructors
		// copy constructor
		// members
		static Member members[] = {
			{ t, offsetof(Slug, m_source), type<mud::vec3>(), "source", nullptr, Member::Value, nullptr },
			{ t, offsetof(Slug, m_velocity), type<mud::vec3>(), "velocity", nullptr, Member::Value, nullptr },
			{ t, offsetof(Slug, m_power), type<float>(), "power", &power_default, Member::Value, nullptr }
		};
		// methods
		// static members
		static Class cls = { t, {}, {}, {}, {}, members, {}, {}, };
	}
	// Tank
	{
		Type& t = type<Tank>();
		static Meta meta = { t, &namspc({}), "Tank", sizeof(Tank), TypeClass::Object };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, Tank__construct_0, {} },
			{ t, Tank__construct_1, { { "spatial", type<toy::HSpatial>(),  }, { "movable", type<toy::HMovable>(),  }, { "emitter", type<toy::HEmitter>(),  }, { "receptor", type<toy::HReceptor>(),  }, { "faction", type<Faction>(),  } } }
		};
		// copy constructor
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, {}, {}, {}, {}, };
	}
	// BlockWorld
	{
		Type& t = type<BlockWorld>();
		static Meta meta = { t, &namspc({}), "BlockWorld", sizeof(BlockWorld), TypeClass::Object };
		// bases
		static Type* bases[] = { &type<mud::Complex>() };
		static size_t bases_offsets[] = { base_offset<BlockWorld, mud::Complex>() };
		// defaults
		static mud::uvec3 block_subdiv_default = uvec3(20,4,20);
		// constructors
		static Constructor constructors[] = {
			{ t, BlockWorld__construct_0, { { "name", type<stl::string>(),  }, { "job_system", type<mud::JobSystem>(),  } } }
		};
		// copy constructor
		// members
		static Member members[] = {
			{ t, offsetof(BlockWorld, m_world), type<toy::World>(), "world", nullptr, Member::NonMutable, nullptr },
			{ t, offsetof(BlockWorld, m_bullet_world), type<toy::BulletWorld>(), "bullet_world", nullptr, Member::Flags(Member::NonMutable|Member::Component), nullptr },
			{ t, offsetof(BlockWorld, m_navmesh), type<toy::Navmesh>(), "navmesh", nullptr, Member::Flags(Member::NonMutable|Member::Component), nullptr },
			{ t, offsetof(BlockWorld, m_block_subdiv), type<mud::uvec3>(), "block_subdiv", &block_subdiv_default, Member::Value, nullptr },
			{ t, offsetof(BlockWorld, m_tile_scale), type<mud::vec3>(), "tile_scale", nullptr, Member::Value, nullptr },
			{ t, offsetof(BlockWorld, m_block_size), type<mud::vec3>(), "block_size", nullptr, Member::Value, nullptr },
			{ t, offsetof(BlockWorld, m_world_size), type<mud::vec3>(), "world_size", nullptr, Member::Value, nullptr }
		};
		// methods
		// static members
		static Class cls = { t, bases, bases_offsets, constructors, {}, members, {}, {}, };
	}
	
	{
		Type& t = type<mud::ComponentHandle<Camp>>();
		static Alias alias = { &t, &namspc({}), "HCamp" };
		m.m_aliases.push_back(&alias);
	}
	{
		Type& t = type<mud::ComponentHandle<Shield>>();
		static Alias alias = { &t, &namspc({}), "HShield" };
		m.m_aliases.push_back(&alias);
	}
	{
		Type& t = type<mud::ComponentHandle<Slug>>();
		static Alias alias = { &t, &namspc({}), "HSlug" };
		m.m_aliases.push_back(&alias);
	}
	{
		Type& t = type<mud::ComponentHandle<Tank>>();
		static Alias alias = { &t, &namspc({}), "HTank" };
		m.m_aliases.push_back(&alias);
	}
	
		m.m_types.push_back(&type<Camp>());
		m.m_types.push_back(&type<mud::ComponentHandle<Camp>>());
		m.m_types.push_back(&type<mud::ComponentHandle<Shield>>());
		m.m_types.push_back(&type<mud::ComponentHandle<Slug>>());
		m.m_types.push_back(&type<mud::ComponentHandle<Tank>>());
		m.m_types.push_back(&type<Faction>());
		m.m_types.push_back(&type<HCamp>());
		m.m_types.push_back(&type<HShield>());
		m.m_types.push_back(&type<HSlug>());
		m.m_types.push_back(&type<HTank>());
		m.m_types.push_back(&type<Player>());
		m.m_types.push_back(&type<Shield>());
		m.m_types.push_back(&type<Slug>());
		m.m_types.push_back(&type<Tank>());
		m.m_types.push_back(&type<BlockWorld>());
	}
}

_blocks::_blocks()
	: Module("_blocks", { &mud_infra::m(), &mud_jobs::m(), &mud_type::m(), &mud_tree::m(), &mud_pool::m(), &mud_refl::m(), &mud_ecs::m(), &mud_srlz::m(), &mud_math::m(), &mud_geom::m(), &mud_lang::m(), &mud_ctx::m(), &mud_ui::m(), &mud_uio::m(), &mud_bgfx::m(), &mud_gfx::m(), &mud_gfx_ui::m(), &mud_frame::m(), &toy_util::m(), &toy_core::m(), &toy_visu::m(), &toy_edit::m(), &toy_block::m(), &toy_shell::m() })
{
	// setup reflection meta data
	_blocks_meta(*this);
}

#ifdef _BLOCKS_MODULE
extern "C"
Module& getModule()
{
	return _blocks::m();
}
#endif
