#include <infra/Cpp20.h>

#ifdef TWO_MODULES
module ._platform;
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
#include <meta/_platform.meta.h>
#include <meta/_platform.conv.h>
#endif

#include <platform/Api.h>

using namespace two;

void Faction__to_string(void* val, string& str) { str = g_enu[type<Faction>().m_id]->name(uint32_t((*static_cast<Faction*>(val)))); }
void Faction__to_value(const string& str, void* val) { (*static_cast<Faction*>(val)) = Faction(g_enu[type<Faction>().m_id]->value(str.c_str())); }
void two_ComponentHandle_Bullet__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) two::ComponentHandle<Bullet>(  ); }
void two_ComponentHandle_Bullet__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) two::ComponentHandle<Bullet>((*static_cast<two::ComponentHandle<Bullet>*>(other))); }
void two_ComponentHandle_Human__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) two::ComponentHandle<Human>(  ); }
void two_ComponentHandle_Human__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) two::ComponentHandle<Human>((*static_cast<two::ComponentHandle<Human>*>(other))); }
void two_ComponentHandle_Lamp__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) two::ComponentHandle<Lamp>(  ); }
void two_ComponentHandle_Lamp__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) two::ComponentHandle<Lamp>((*static_cast<two::ComponentHandle<Lamp>*>(other))); }
void two_ComponentHandle_Crate__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) two::ComponentHandle<Crate>(  ); }
void two_ComponentHandle_Crate__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) two::ComponentHandle<Crate>((*static_cast<two::ComponentHandle<Crate>*>(other))); }
void TileWorld__construct_0(void* ref, span<void*> args) { new(stl::placeholder(), ref) TileWorld( *static_cast<stl::string*>(args[0]), *static_cast<two::JobSystem*>(args[1]) ); }
void Aim__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) Aim(  ); }
void Aim__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) Aim((*static_cast<Aim*>(other))); }
void Stance__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) Stance(  ); }
void Stance__construct_1(void* ref, span<void*> args) { new(stl::placeholder(), ref) Stance( *static_cast<stl::string*>(args[0]), *static_cast<bool*>(args[1]) ); }
void Stance__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) Stance((*static_cast<Stance*>(other))); }
void Human__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) Human(  ); }
void Human__construct_1(void* ref, span<void*> args) { new(stl::placeholder(), ref) Human( *static_cast<toy::HSpatial*>(args[0]), *static_cast<toy::HMovable*>(args[1]), *static_cast<toy::HEmitter*>(args[2]), *static_cast<toy::HReceptor*>(args[3]), *static_cast<toy::HEntityScript*>(args[4]), *static_cast<Faction*>(args[5]) ); }
void Human_sight(void* object, span<void*> args, void*& result) { (*static_cast<two::quat*>(result)) = (*static_cast<Human*>(object)).sight(*static_cast<bool*>(args[0])); }
void Human_aim(void* object, span<void*> args, void*& result) { UNUSED(args); (*static_cast<Aim*>(result)) = (*static_cast<Human*>(object)).aim(); }
void Human_shoot(void* object, span<void*> args, void*& result) { UNUSED(result); UNUSED(args); (*static_cast<Human*>(object)).shoot(); }
void Human_stop(void* object, span<void*> args, void*& result) { UNUSED(result); UNUSED(args); (*static_cast<Human*>(object)).stop(); }
void Lamp__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) Lamp(  ); }
void Lamp__construct_1(void* ref, span<void*> args) { new(stl::placeholder(), ref) Lamp( *static_cast<toy::HSpatial*>(args[0]), *static_cast<toy::HMovable*>(args[1]) ); }
void Crate__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) Crate(  ); }
void Crate__construct_1(void* ref, span<void*> args) { new(stl::placeholder(), ref) Crate( *static_cast<toy::HSpatial*>(args[0]), *static_cast<toy::HMovable*>(args[1]), *static_cast<two::vec3*>(args[2]) ); }

namespace two
{
	void _platform_meta(Module& m)
	{
	UNUSED(m);
	
	// Base Types
	
	// Enums
	{
		Type& t = type<Faction>();
		static Meta meta = { t, &namspc({}), "Faction", sizeof(Faction), TypeClass::Enum };
		static cstring ids[] = { "Ally", "Enemy" };
		static uint32_t values[] = { 0, 1 };
		static Faction vars[] = { Faction::Ally, Faction::Enemy};
		static void* refs[] = { &vars[0], &vars[1]};
		static Enum enu = { t, true, ids, values, refs };
		static Convert convert = { Faction__to_string,
		                           Faction__to_value };
		g_convert[t.m_id] = &convert;
	}
	
	// Sequences
	
	// two::ComponentHandle<Bullet>
	{
		Type& t = type<two::ComponentHandle<Bullet>>();
		static Meta meta = { t, &namspc({ "two" }), "ComponentHandle<Bullet>", sizeof(two::ComponentHandle<Bullet>), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, two_ComponentHandle_Bullet__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, two_ComponentHandle_Bullet__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
	}
	// two::ComponentHandle<Human>
	{
		Type& t = type<two::ComponentHandle<Human>>();
		static Meta meta = { t, &namspc({ "two" }), "ComponentHandle<Human>", sizeof(two::ComponentHandle<Human>), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, two_ComponentHandle_Human__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, two_ComponentHandle_Human__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
	}
	// two::ComponentHandle<Lamp>
	{
		Type& t = type<two::ComponentHandle<Lamp>>();
		static Meta meta = { t, &namspc({ "two" }), "ComponentHandle<Lamp>", sizeof(two::ComponentHandle<Lamp>), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, two_ComponentHandle_Lamp__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, two_ComponentHandle_Lamp__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
	}
	// two::ComponentHandle<Crate>
	{
		Type& t = type<two::ComponentHandle<Crate>>();
		static Meta meta = { t, &namspc({ "two" }), "ComponentHandle<Crate>", sizeof(two::ComponentHandle<Crate>), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, two_ComponentHandle_Crate__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, two_ComponentHandle_Crate__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
	}
	// TileWorld
	{
		Type& t = type<TileWorld>();
		static Meta meta = { t, &namspc({}), "TileWorld", sizeof(TileWorld), TypeClass::Object };
		// bases
		static Type* bases[] = { &type<two::Complex>() };
		static size_t bases_offsets[] = { base_offset<TileWorld, two::Complex>() };
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, TileWorld__construct_0, { { "name", type<stl::string>(),  }, { "job_system", type<two::JobSystem>(),  } } }
		};
		// copy constructor
		// members
		static Member members[] = {
			{ t, offsetof(TileWorld, m_world), type<toy::World>(), "world", nullptr, Member::NonMutable, nullptr },
			{ t, offsetof(TileWorld, m_bullet_world), type<toy::BulletWorld>(), "bullet_world", nullptr, Member::Flags(Member::NonMutable|Member::Component), nullptr },
			{ t, offsetof(TileWorld, m_navmesh), type<toy::Navmesh>(), "navmesh", nullptr, Member::Flags(Member::NonMutable|Member::Component), nullptr }
		};
		// methods
		// static members
		static Class cls = { t, bases, bases_offsets, constructors, {}, members, {}, {}, };
	}
	// Bullet
	{
		Type& t = type<Bullet>();
		static Meta meta = { t, &namspc({}), "Bullet", sizeof(Bullet), TypeClass::Object };
		// bases
		// defaults
		// constructors
		// copy constructor
		// members
		static Member members[] = {
			{ t, offsetof(Bullet, m_source), type<two::vec3>(), "source", nullptr, Member::Value, nullptr },
			{ t, offsetof(Bullet, m_velocity), type<two::vec3>(), "velocity", nullptr, Member::Value, nullptr }
		};
		// methods
		// static members
		static Class cls = { t, {}, {}, {}, {}, members, {}, {}, };
	}
	// Aim
	{
		Type& t = type<Aim>();
		static Meta meta = { t, &namspc({}), "Aim", sizeof(Aim), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, Aim__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, Aim__copy_construct }
		};
		// members
		static Member members[] = {
			{ t, offsetof(Aim, rotation), type<two::quat>(), "rotation", nullptr, Member::Value, nullptr },
			{ t, offsetof(Aim, start), type<two::vec3>(), "start", nullptr, Member::Value, nullptr },
			{ t, offsetof(Aim, end), type<two::vec3>(), "end", nullptr, Member::Value, nullptr },
			{ t, offsetof(Aim, hit), type<toy::Spatial>(), "hit", nullptr, Member::Flags(Member::Pointer|Member::Link), nullptr }
		};
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, members, {}, {}, };
	}
	// Stance
	{
		Type& t = type<Stance>();
		static Meta meta = { t, &namspc({}), "Stance", sizeof(Stance), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, Stance__construct_0, {} },
			{ t, Stance__construct_1, { { "name", type<stl::string>(),  }, { "loop", type<bool>(),  } } }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, Stance__copy_construct }
		};
		// members
		static Member members[] = {
			{ t, offsetof(Stance, name), type<stl::string>(), "name", nullptr, Member::Value, nullptr },
			{ t, offsetof(Stance, loop), type<bool>(), "loop", nullptr, Member::Value, nullptr }
		};
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, members, {}, {}, };
	}
	// Human
	{
		Type& t = type<Human>();
		static Meta meta = { t, &namspc({}), "Human", sizeof(Human), TypeClass::Object };
		// bases
		// defaults
		static float life_default = 1.f;
		static float energy_default = 1.f;
		static float discharge_default = 0.f;
		static bool headlight_default = true;
		static bool shield_default = false;
		static bool walk_default = true;
		static HHuman target_default = {};
		static float cooldown_default = 0.f;
		static Stance state_default = {"IdleAim",true};
		static bool sight_0_aiming_default = true;
		// constructors
		static Constructor constructors[] = {
			{ t, Human__construct_0, {} },
			{ t, Human__construct_1, { { "spatial", type<toy::HSpatial>(),  }, { "movable", type<toy::HMovable>(),  }, { "emitter", type<toy::HEmitter>(),  }, { "receptor", type<toy::HReceptor>(),  }, { "script", type<toy::HEntityScript>(),  }, { "faction", type<Faction>(),  } } }
		};
		// copy constructor
		// members
		static Member members[] = {
			{ t, offsetof(Human, m_faction), type<Faction>(), "faction", nullptr, Member::Value, nullptr },
			{ t, offsetof(Human, m_life), type<float>(), "life", &life_default, Member::Value, nullptr },
			{ t, offsetof(Human, m_energy), type<float>(), "energy", &energy_default, Member::Value, nullptr },
			{ t, offsetof(Human, m_discharge), type<float>(), "discharge", &discharge_default, Member::Value, nullptr },
			{ t, offsetof(Human, m_headlight), type<bool>(), "headlight", &headlight_default, Member::Value, nullptr },
			{ t, offsetof(Human, m_shield), type<bool>(), "shield", &shield_default, Member::Value, nullptr },
			{ t, offsetof(Human, m_walk), type<bool>(), "walk", &walk_default, Member::Value, nullptr },
			{ t, offsetof(Human, m_target), type<HHuman>(), "target", &target_default, Member::Value, nullptr },
			{ t, offsetof(Human, m_dest), type<two::vec3>(), "dest", nullptr, Member::Value, nullptr },
			{ t, offsetof(Human, m_cooldown), type<float>(), "cooldown", &cooldown_default, Member::Value, nullptr },
			{ t, offsetof(Human, m_state), type<Stance>(), "state", &state_default, Member::Value, nullptr }
		};
		// methods
		static Method methods[] = {
			{ t, "sight", Address(), Human_sight, { { "aiming", type<bool>(), Param::Default, &sight_0_aiming_default } }, { &type<two::quat>(), QualType::None } },
			{ t, "aim", Address(), Human_aim, {}, { &type<Aim>(), QualType::None } },
			{ t, "shoot", Address(), Human_shoot, {}, g_qvoid },
			{ t, "stop", Address(), Human_stop, {}, g_qvoid }
		};
		// static members
		static Class cls = { t, {}, {}, constructors, {}, members, methods, {}, };
	}
	// Lamp
	{
		Type& t = type<Lamp>();
		static Meta meta = { t, &namspc({}), "Lamp", sizeof(Lamp), TypeClass::Object };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, Lamp__construct_0, {} },
			{ t, Lamp__construct_1, { { "spatial", type<toy::HSpatial>(),  }, { "movable", type<toy::HMovable>(),  } } }
		};
		// copy constructor
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, {}, {}, {}, {}, };
	}
	// Crate
	{
		Type& t = type<Crate>();
		static Meta meta = { t, &namspc({}), "Crate", sizeof(Crate), TypeClass::Object };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, Crate__construct_0, {} },
			{ t, Crate__construct_1, { { "spatial", type<toy::HSpatial>(),  }, { "movable", type<toy::HMovable>(),  }, { "extents", type<two::vec3>(),  } } }
		};
		// copy constructor
		// members
		static Member members[] = {
			{ t, offsetof(Crate, m_extents), type<two::vec3>(), "extents", nullptr, Member::Value, nullptr }
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
	
	{
		Type& t = type<two::ComponentHandle<Bullet>>();
		static Alias alias = { &t, &namspc({}), "HBullet" };
		m.m_aliases.push_back(&alias);
	}
	{
		Type& t = type<two::ComponentHandle<Human>>();
		static Alias alias = { &t, &namspc({}), "HHuman" };
		m.m_aliases.push_back(&alias);
	}
	{
		Type& t = type<two::ComponentHandle<Lamp>>();
		static Alias alias = { &t, &namspc({}), "HLamp" };
		m.m_aliases.push_back(&alias);
	}
	{
		Type& t = type<two::ComponentHandle<Crate>>();
		static Alias alias = { &t, &namspc({}), "HCrate" };
		m.m_aliases.push_back(&alias);
	}
	
		m.m_types.push_back(&type<two::ComponentHandle<Bullet>>());
		m.m_types.push_back(&type<two::ComponentHandle<Human>>());
		m.m_types.push_back(&type<two::ComponentHandle<Lamp>>());
		m.m_types.push_back(&type<two::ComponentHandle<Crate>>());
		m.m_types.push_back(&type<HBullet>());
		m.m_types.push_back(&type<HHuman>());
		m.m_types.push_back(&type<HLamp>());
		m.m_types.push_back(&type<HCrate>());
		m.m_types.push_back(&type<TileWorld>());
		m.m_types.push_back(&type<Bullet>());
		m.m_types.push_back(&type<Faction>());
		m.m_types.push_back(&type<Aim>());
		m.m_types.push_back(&type<Stance>());
		m.m_types.push_back(&type<Human>());
		m.m_types.push_back(&type<Lamp>());
		m.m_types.push_back(&type<Crate>());
		m.m_types.push_back(&type<Player>());
	}
}

_platform::_platform()
	: Module("_platform", { &two_infra::m(), &two_jobs::m(), &two_type::m(), &two_tree::m(), &two_pool::m(), &two_refl::m(), &two_ecs::m(), &two_srlz::m(), &two_math::m(), &two_geom::m(), &two_lang::m(), &two_ctx::m(), &two_ui::m(), &two_uio::m(), &two_bgfx::m(), &two_gfx::m(), &two_gfx_ui::m(), &two_frame::m(), &toy_util::m(), &toy_core::m(), &toy_visu::m(), &toy_edit::m(), &toy_block::m(), &toy_shell::m() })
{
	// setup reflection meta data
	_platform_meta(*this);
}

#ifdef _PLATFORM_MODULE
extern "C"
Module& getModule()
{
	return _platform::m();
}
#endif
