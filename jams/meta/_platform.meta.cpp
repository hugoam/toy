#include <infra/Cpp20.h>

#ifdef MUD_MODULES
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

using namespace mud;

void Faction__to_string(void* val, string& str) { str = g_enu[type<Faction>().m_id]->name(uint32_t((*static_cast<Faction*>(val)))); }
void Faction__to_value(const string& str, void* val) { (*static_cast<Faction*>(val)) = Faction(g_enu[type<Faction>().m_id]->value(str.c_str())); }
void Aim__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) Aim(  ); }
void Aim__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) Aim((*static_cast<Aim*>(other))); }
void mud_ComponentHandle_Bullet__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) mud::ComponentHandle<Bullet>(  ); }
void mud_ComponentHandle_Bullet__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) mud::ComponentHandle<Bullet>((*static_cast<mud::ComponentHandle<Bullet>*>(other))); }
void mud_ComponentHandle_Crate__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) mud::ComponentHandle<Crate>(  ); }
void mud_ComponentHandle_Crate__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) mud::ComponentHandle<Crate>((*static_cast<mud::ComponentHandle<Crate>*>(other))); }
void mud_ComponentHandle_Human__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) mud::ComponentHandle<Human>(  ); }
void mud_ComponentHandle_Human__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) mud::ComponentHandle<Human>((*static_cast<mud::ComponentHandle<Human>*>(other))); }
void mud_ComponentHandle_Lamp__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) mud::ComponentHandle<Lamp>(  ); }
void mud_ComponentHandle_Lamp__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) mud::ComponentHandle<Lamp>((*static_cast<mud::ComponentHandle<Lamp>*>(other))); }
void Crate__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) Crate(  ); }
void Crate__construct_1(void* ref, span<void*> args) { new(stl::placeholder(), ref) Crate( *static_cast<toy::HSpatial*>(args[0]), *static_cast<toy::HMovable*>(args[1]), *static_cast<mud::vec3*>(args[2]) ); }
void Human__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) Human(  ); }
void Human__construct_1(void* ref, span<void*> args) { new(stl::placeholder(), ref) Human( *static_cast<toy::HSpatial*>(args[0]), *static_cast<toy::HMovable*>(args[1]), *static_cast<toy::HEmitter*>(args[2]), *static_cast<toy::HReceptor*>(args[3]), *static_cast<toy::HEntityScript*>(args[4]), *static_cast<Faction*>(args[5]) ); }
void Human_sight(void* object, span<void*> args, void*& result) { (*static_cast<mud::quat*>(result)) = (*static_cast<Human*>(object)).sight(*static_cast<bool*>(args[0])); }
void Human_aim(void* object, span<void*> args, void*& result) { UNUSED(args); (*static_cast<Aim*>(result)) = (*static_cast<Human*>(object)).aim(); }
void Human_shoot(void* object, span<void*> args, void*& result) { UNUSED(result); UNUSED(args); (*static_cast<Human*>(object)).shoot(); }
void Human_stop(void* object, span<void*> args, void*& result) { UNUSED(result); UNUSED(args); (*static_cast<Human*>(object)).stop(); }
void Lamp__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) Lamp(  ); }
void Lamp__construct_1(void* ref, span<void*> args) { new(stl::placeholder(), ref) Lamp( *static_cast<toy::HSpatial*>(args[0]), *static_cast<toy::HMovable*>(args[1]) ); }
void Stance__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) Stance(  ); }
void Stance__construct_1(void* ref, span<void*> args) { new(stl::placeholder(), ref) Stance( *static_cast<stl::string*>(args[0]), *static_cast<bool*>(args[1]) ); }
void Stance__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) Stance((*static_cast<Stance*>(other))); }
void TileWorld__construct_0(void* ref, span<void*> args) { new(stl::placeholder(), ref) TileWorld( *static_cast<stl::string*>(args[0]), *static_cast<mud::JobSystem*>(args[1]) ); }

namespace mud
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
			{ t, offsetof(Aim, rotation), type<mud::quat>(), "rotation", nullptr, Member::Value, nullptr },
			{ t, offsetof(Aim, start), type<mud::vec3>(), "start", nullptr, Member::Value, nullptr },
			{ t, offsetof(Aim, end), type<mud::vec3>(), "end", nullptr, Member::Value, nullptr },
			{ t, offsetof(Aim, hit), type<toy::Spatial>(), "hit", nullptr, Member::Flags(Member::Pointer|Member::Link), nullptr }
		};
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, members, {}, {}, };
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
			{ t, offsetof(Bullet, m_source), type<mud::vec3>(), "source", nullptr, Member::Value, nullptr },
			{ t, offsetof(Bullet, m_velocity), type<mud::vec3>(), "velocity", nullptr, Member::Value, nullptr }
		};
		// methods
		// static members
		static Class cls = { t, {}, {}, {}, {}, members, {}, {}, };
	}
	// mud::ComponentHandle<Bullet>
	{
		Type& t = type<mud::ComponentHandle<Bullet>>();
		static Meta meta = { t, &namspc({ "mud" }), "ComponentHandle<Bullet>", sizeof(mud::ComponentHandle<Bullet>), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, mud_ComponentHandle_Bullet__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, mud_ComponentHandle_Bullet__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
	}
	// mud::ComponentHandle<Crate>
	{
		Type& t = type<mud::ComponentHandle<Crate>>();
		static Meta meta = { t, &namspc({ "mud" }), "ComponentHandle<Crate>", sizeof(mud::ComponentHandle<Crate>), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, mud_ComponentHandle_Crate__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, mud_ComponentHandle_Crate__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
	}
	// mud::ComponentHandle<Human>
	{
		Type& t = type<mud::ComponentHandle<Human>>();
		static Meta meta = { t, &namspc({ "mud" }), "ComponentHandle<Human>", sizeof(mud::ComponentHandle<Human>), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, mud_ComponentHandle_Human__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, mud_ComponentHandle_Human__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
	}
	// mud::ComponentHandle<Lamp>
	{
		Type& t = type<mud::ComponentHandle<Lamp>>();
		static Meta meta = { t, &namspc({ "mud" }), "ComponentHandle<Lamp>", sizeof(mud::ComponentHandle<Lamp>), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, mud_ComponentHandle_Lamp__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, mud_ComponentHandle_Lamp__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
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
			{ t, Crate__construct_1, { { "spatial", type<toy::HSpatial>(),  }, { "movable", type<toy::HMovable>(),  }, { "extents", type<mud::vec3>(),  } } }
		};
		// copy constructor
		// members
		static Member members[] = {
			{ t, offsetof(Crate, m_extents), type<mud::vec3>(), "extents", nullptr, Member::Value, nullptr }
		};
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, {}, members, {}, {}, };
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
			{ t, offsetof(Human, m_dest), type<mud::vec3>(), "dest", nullptr, Member::Value, nullptr },
			{ t, offsetof(Human, m_cooldown), type<float>(), "cooldown", &cooldown_default, Member::Value, nullptr },
			{ t, offsetof(Human, m_state), type<Stance>(), "state", &state_default, Member::Value, nullptr }
		};
		// methods
		static Method methods[] = {
			{ t, "sight", Address(), Human_sight, { { "aiming", type<bool>(), Param::Default, &sight_0_aiming_default } }, { &type<mud::quat>(), QualType::None } },
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
	// TileWorld
	{
		Type& t = type<TileWorld>();
		static Meta meta = { t, &namspc({}), "TileWorld", sizeof(TileWorld), TypeClass::Object };
		// bases
		static Type* bases[] = { &type<mud::Complex>() };
		static size_t bases_offsets[] = { base_offset<TileWorld, mud::Complex>() };
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, TileWorld__construct_0, { { "name", type<stl::string>(),  }, { "job_system", type<mud::JobSystem>(),  } } }
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
	
	{
		Type& t = type<mud::ComponentHandle<Bullet>>();
		static Alias alias = { &t, &namspc({}), "HBullet" };
		m.m_aliases.push_back(&alias);
	}
	{
		Type& t = type<mud::ComponentHandle<Human>>();
		static Alias alias = { &t, &namspc({}), "HHuman" };
		m.m_aliases.push_back(&alias);
	}
	{
		Type& t = type<mud::ComponentHandle<Lamp>>();
		static Alias alias = { &t, &namspc({}), "HLamp" };
		m.m_aliases.push_back(&alias);
	}
	{
		Type& t = type<mud::ComponentHandle<Crate>>();
		static Alias alias = { &t, &namspc({}), "HCrate" };
		m.m_aliases.push_back(&alias);
	}
	
		m.m_types.push_back(&type<Aim>());
		m.m_types.push_back(&type<Bullet>());
		m.m_types.push_back(&type<mud::ComponentHandle<Bullet>>());
		m.m_types.push_back(&type<mud::ComponentHandle<Crate>>());
		m.m_types.push_back(&type<mud::ComponentHandle<Human>>());
		m.m_types.push_back(&type<mud::ComponentHandle<Lamp>>());
		m.m_types.push_back(&type<Crate>());
		m.m_types.push_back(&type<Faction>());
		m.m_types.push_back(&type<HBullet>());
		m.m_types.push_back(&type<HCrate>());
		m.m_types.push_back(&type<HHuman>());
		m.m_types.push_back(&type<HLamp>());
		m.m_types.push_back(&type<Human>());
		m.m_types.push_back(&type<Lamp>());
		m.m_types.push_back(&type<Player>());
		m.m_types.push_back(&type<Stance>());
		m.m_types.push_back(&type<TileWorld>());
	}
}

_platform::_platform()
	: Module("_platform", { &mud_infra::m(), &mud_jobs::m(), &mud_type::m(), &mud_tree::m(), &mud_pool::m(), &mud_refl::m(), &mud_ecs::m(), &mud_srlz::m(), &mud_math::m(), &mud_geom::m(), &mud_lang::m(), &mud_ctx::m(), &mud_ui::m(), &mud_uio::m(), &mud_bgfx::m(), &mud_gfx::m(), &mud_gfx_ui::m(), &mud_frame::m(), &toy_util::m(), &toy_core::m(), &toy_visu::m(), &toy_edit::m(), &toy_block::m(), &toy_shell::m() })
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
