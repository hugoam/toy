#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module ._minimal;
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
#include <meta/_minimal.meta.h>
#include <meta/_minimal.conv.h>
#endif

#include <minimal/Api.h>

using namespace mud;

void mud_ComponentHandle_Bullet__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) mud::ComponentHandle<Bullet>(  ); }
void mud_ComponentHandle_Bullet__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) mud::ComponentHandle<Bullet>((*static_cast<mud::ComponentHandle<Bullet>*>(other))); }
void mud_ComponentHandle_Crate__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) mud::ComponentHandle<Crate>(  ); }
void mud_ComponentHandle_Crate__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) mud::ComponentHandle<Crate>((*static_cast<mud::ComponentHandle<Crate>*>(other))); }
void mud_ComponentHandle_Human__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) mud::ComponentHandle<Human>(  ); }
void mud_ComponentHandle_Human__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) mud::ComponentHandle<Human>((*static_cast<mud::ComponentHandle<Human>*>(other))); }
void Crate__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) Crate(  ); }
void Crate__construct_1(void* ref, span<void*> args) { new(stl::placeholder(), ref) Crate( *static_cast<toy::HSpatial*>(args[0]), *static_cast<toy::HMovable*>(args[1]), *static_cast<mud::vec3*>(args[2]) ); }
void Human__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) Human(  ); }
void Human__construct_1(void* ref, span<void*> args) { new(stl::placeholder(), ref) Human( *static_cast<toy::HSpatial*>(args[0]), *static_cast<toy::HMovable*>(args[1]) ); }

namespace mud
{
	void _minimal_meta(Module& m)
	{
	UNUSED(m);
	
	// Base Types
	
	// Enums
	
	// Sequences
	
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
		// constructors
		static Constructor constructors[] = {
			{ t, Human__construct_0, {} },
			{ t, Human__construct_1, { { "spatial", type<toy::HSpatial>(),  }, { "movable", type<toy::HMovable>(),  } } }
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
		Type& t = type<mud::ComponentHandle<Crate>>();
		static Alias alias = { &t, &namspc({}), "HCrate" };
		m.m_aliases.push_back(&alias);
	}
	
		m.m_types.push_back(&type<Bullet>());
		m.m_types.push_back(&type<mud::ComponentHandle<Bullet>>());
		m.m_types.push_back(&type<mud::ComponentHandle<Crate>>());
		m.m_types.push_back(&type<mud::ComponentHandle<Human>>());
		m.m_types.push_back(&type<Crate>());
		m.m_types.push_back(&type<HBullet>());
		m.m_types.push_back(&type<HCrate>());
		m.m_types.push_back(&type<HHuman>());
		m.m_types.push_back(&type<Human>());
		m.m_types.push_back(&type<Player>());
	}
}

_minimal::_minimal()
	: Module("_minimal", { &mud_infra::m(), &mud_jobs::m(), &mud_type::m(), &mud_tree::m(), &mud_pool::m(), &mud_refl::m(), &mud_ecs::m(), &mud_srlz::m(), &mud_math::m(), &mud_geom::m(), &mud_lang::m(), &mud_ctx::m(), &mud_ui::m(), &mud_uio::m(), &mud_bgfx::m(), &mud_gfx::m(), &mud_gfx_ui::m(), &mud_frame::m(), &toy_util::m(), &toy_core::m(), &toy_visu::m(), &toy_edit::m(), &toy_block::m(), &toy_shell::m() })
{
	// setup reflection meta data
	_minimal_meta(*this);
}

#ifdef _MINIMAL_MODULE
extern "C"
Module& getModule()
{
	return _minimal::m();
}
#endif
