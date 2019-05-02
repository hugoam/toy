#include <infra/Cpp20.h>

#ifdef TWO_MODULES
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

using namespace two;

void two_ComponentHandle_Bullet__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) two::ComponentHandle<Bullet>(  ); }
void two_ComponentHandle_Bullet__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) two::ComponentHandle<Bullet>((*static_cast<two::ComponentHandle<Bullet>*>(other))); }
void two_ComponentHandle_Human__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) two::ComponentHandle<Human>(  ); }
void two_ComponentHandle_Human__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) two::ComponentHandle<Human>((*static_cast<two::ComponentHandle<Human>*>(other))); }
void two_ComponentHandle_Crate__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) two::ComponentHandle<Crate>(  ); }
void two_ComponentHandle_Crate__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) two::ComponentHandle<Crate>((*static_cast<two::ComponentHandle<Crate>*>(other))); }
void Human__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) Human(  ); }
void Human__construct_1(void* ref, span<void*> args) { new(stl::placeholder(), ref) Human( *static_cast<toy::HSpatial*>(args[0]), *static_cast<toy::HMovable*>(args[1]) ); }
void Crate__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) Crate(  ); }
void Crate__construct_1(void* ref, span<void*> args) { new(stl::placeholder(), ref) Crate( *static_cast<toy::HSpatial*>(args[0]), *static_cast<toy::HMovable*>(args[1]), *static_cast<two::vec3*>(args[2]) ); }

namespace two
{
	void _minimal_meta(Module& m)
	{
	UNUSED(m);
	
	// Base Types
	
	// Enums
	
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
		Type& t = type<two::ComponentHandle<Crate>>();
		static Alias alias = { &t, &namspc({}), "HCrate" };
		m.m_aliases.push_back(&alias);
	}
	
		m.m_types.push_back(&type<two::ComponentHandle<Bullet>>());
		m.m_types.push_back(&type<two::ComponentHandle<Human>>());
		m.m_types.push_back(&type<two::ComponentHandle<Crate>>());
		m.m_types.push_back(&type<HBullet>());
		m.m_types.push_back(&type<HHuman>());
		m.m_types.push_back(&type<HCrate>());
		m.m_types.push_back(&type<Bullet>());
		m.m_types.push_back(&type<Human>());
		m.m_types.push_back(&type<Crate>());
		m.m_types.push_back(&type<Player>());
	}
}

_minimal::_minimal()
	: Module("_minimal", { &two_infra::m(), &two_jobs::m(), &two_type::m(), &two_tree::m(), &two_pool::m(), &two_refl::m(), &two_ecs::m(), &two_srlz::m(), &two_math::m(), &two_geom::m(), &two_lang::m(), &two_ctx::m(), &two_ui::m(), &two_uio::m(), &two_bgfx::m(), &two_gfx::m(), &two_gfx_ui::m(), &two_frame::m(), &toy_util::m(), &toy_core::m(), &toy_visu::m(), &toy_edit::m(), &toy_block::m(), &toy_shell::m() })
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
