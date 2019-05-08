#include <infra/Cpp20.h>

#ifdef TWO_MODULES
module ._boids;
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
#include <meta/_boids.meta.h>
#include <meta/_boids.conv.h>
#endif

#include <boids/Api.h>

using namespace two;

void boids_Position__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) boids::Position(  ); }
void boids_Position__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) boids::Position((*static_cast<boids::Position*>(other))); }
void boids_Heading__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) boids::Heading(  ); }
void boids_Heading__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) boids::Heading((*static_cast<boids::Heading*>(other))); }
void boids_Rotation__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) boids::Rotation(  ); }
void boids_Rotation__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) boids::Rotation((*static_cast<boids::Rotation*>(other))); }
void boids_MoveSpeed__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) boids::MoveSpeed(  ); }
void boids_MoveSpeed__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) boids::MoveSpeed((*static_cast<boids::MoveSpeed*>(other))); }
void boids_Transform4__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) boids::Transform4(  ); }
void boids_Transform4__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) boids::Transform4((*static_cast<boids::Transform4*>(other))); }
void boids_Boid__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) boids::Boid(  ); }
void boids_Boid__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) boids::Boid((*static_cast<boids::Boid*>(other))); }
void boids_BoidTarget__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) boids::BoidTarget(  ); }
void boids_BoidTarget__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) boids::BoidTarget((*static_cast<boids::BoidTarget*>(other))); }
void boids_BoidObstacle__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) boids::BoidObstacle(  ); }
void boids_BoidObstacle__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) boids::BoidObstacle((*static_cast<boids::BoidObstacle*>(other))); }
void boids_MoveForward__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) boids::MoveForward(  ); }
void boids_MoveForward__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) boids::MoveForward((*static_cast<boids::MoveForward*>(other))); }

namespace two
{
	void _boids_meta(Module& m)
	{
	UNUSED(m);
	
	// Base Types
	
	// Enums
	
	// Sequences
	
	// boids::Position
	{
		Type& t = type<boids::Position>();
		static Meta meta = { t, &namspc({ "boids" }), "Position", sizeof(boids::Position), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, boids_Position__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, boids_Position__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
	}
	// boids::Heading
	{
		Type& t = type<boids::Heading>();
		static Meta meta = { t, &namspc({ "boids" }), "Heading", sizeof(boids::Heading), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, boids_Heading__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, boids_Heading__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
	}
	// boids::Rotation
	{
		Type& t = type<boids::Rotation>();
		static Meta meta = { t, &namspc({ "boids" }), "Rotation", sizeof(boids::Rotation), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, boids_Rotation__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, boids_Rotation__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
	}
	// boids::MoveSpeed
	{
		Type& t = type<boids::MoveSpeed>();
		static Meta meta = { t, &namspc({ "boids" }), "MoveSpeed", sizeof(boids::MoveSpeed), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, boids_MoveSpeed__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, boids_MoveSpeed__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
	}
	// boids::Transform4
	{
		Type& t = type<boids::Transform4>();
		static Meta meta = { t, &namspc({ "boids" }), "Transform4", sizeof(boids::Transform4), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, boids_Transform4__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, boids_Transform4__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
	}
	// boids::Boid
	{
		Type& t = type<boids::Boid>();
		static Meta meta = { t, &namspc({ "boids" }), "Boid", sizeof(boids::Boid), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, boids_Boid__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, boids_Boid__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
	}
	// boids::BoidTarget
	{
		Type& t = type<boids::BoidTarget>();
		static Meta meta = { t, &namspc({ "boids" }), "BoidTarget", sizeof(boids::BoidTarget), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, boids_BoidTarget__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, boids_BoidTarget__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
	}
	// boids::BoidObstacle
	{
		Type& t = type<boids::BoidObstacle>();
		static Meta meta = { t, &namspc({ "boids" }), "BoidObstacle", sizeof(boids::BoidObstacle), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, boids_BoidObstacle__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, boids_BoidObstacle__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
	}
	// boids::MoveForward
	{
		Type& t = type<boids::MoveForward>();
		static Meta meta = { t, &namspc({ "boids" }), "MoveForward", sizeof(boids::MoveForward), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, boids_MoveForward__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, boids_MoveForward__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
	}
	// boids::Player
	{
		Type& t = type<boids::Player>();
		static Meta meta = { t, &namspc({ "boids" }), "Player", sizeof(boids::Player), TypeClass::Object };
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
		Type& t = type<two::v4<float>>();
		static Alias alias = { &t, &namspc({ "boids" }), "vec3" };
		m.m_aliases.push_back(&alias);
	}
	
		m.m_types.push_back(&type<boids::Position>());
		m.m_types.push_back(&type<boids::Heading>());
		m.m_types.push_back(&type<boids::Rotation>());
		m.m_types.push_back(&type<boids::MoveSpeed>());
		m.m_types.push_back(&type<boids::Transform4>());
		m.m_types.push_back(&type<boids::Boid>());
		m.m_types.push_back(&type<boids::BoidTarget>());
		m.m_types.push_back(&type<boids::BoidObstacle>());
		m.m_types.push_back(&type<boids::MoveForward>());
		m.m_types.push_back(&type<boids::Player>());
	}
}

_boids::_boids()
	: Module("_boids", { &two_infra::m(), &two_jobs::m(), &two_type::m(), &two_tree::m(), &two_pool::m(), &two_refl::m(), &two_ecs::m(), &two_srlz::m(), &two_math::m(), &two_geom::m(), &two_lang::m(), &two_ctx::m(), &two_ui::m(), &two_uio::m(), &two_bgfx::m(), &two_gfx::m(), &two_gfx_ui::m(), &two_frame::m(), &toy_util::m(), &toy_core::m(), &toy_visu::m(), &toy_edit::m(), &toy_block::m(), &toy_shell::m() })
{
	// setup reflection meta data
	_boids_meta(*this);
}

#ifdef _BOIDS_MODULE
extern "C"
Module& getModule()
{
	return _boids::m();
}
#endif
