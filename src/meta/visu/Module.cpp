#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module toy.visu;
#else
#include <type/Vector.h>
#include <refl/MetaDecl.h>
#include <refl/Module.h>
#include <meta/type/Module.h>
#include <meta/gfx/Module.h>
#include <meta/util/Module.h>
#include <meta/core/Module.h>
#include <meta/visu/Module.h>
#include <meta/visu/Convert.h>
#endif

#include <visu/Api.h>

using namespace two;

void* toy_VisuScene__get_gfx_system(void* object) { return &(*static_cast<toy::VisuScene*>(object)).m_gfx_system; }
void toy_VisuScene_next_frame(void* object, array<void*> args, void*& result) { UNUSED(result); UNUSED(args); (*static_cast<toy::VisuScene*>(object)).next_frame(); }

namespace two
{
	void toy_visu_meta(Module& m)
	{
	UNUSED(m);
	
	// Base Types
	
	// Enums
	
	// Sequences
	
	// toy::PhysicDebugDraw
	{
		Type& t = type<toy::PhysicDebugDraw>();
		static Meta meta = { t, &namspc({ "toy" }), "PhysicDebugDraw", sizeof(toy::PhysicDebugDraw), TypeClass::Object };
		// bases
		// defaults
		// constructors
		// copy constructor
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, {}, {}, {}, {}, {}, };
	}
	// toy::VisuScene
	{
		Type& t = type<toy::VisuScene>();
		static Meta meta = { t, &namspc({ "toy" }), "VisuScene", sizeof(toy::VisuScene), TypeClass::Object };
		// bases
		// defaults
		// constructors
		// copy constructor
		// members
		static Member members[] = {
			{ t, SIZE_MAX, type<two::GfxSystem>(), "gfx_system", nullptr, Member::Flags(Member::NonMutable|Member::Link), toy_VisuScene__get_gfx_system },
			{ t, offsetof(toy::VisuScene, m_scene), type<two::Scene>(), "scene", nullptr, Member::NonMutable, nullptr }
		};
		// methods
		static Method methods[] = {
			{ t, "next_frame", Address(), toy_VisuScene_next_frame, {}, g_qvoid }
		};
		// static members
		static Class cls = { t, {}, {}, {}, {}, members, methods, {}, };
	}
		m.m_types.push_back(&type<toy::PhysicDebugDraw>());
		m.m_types.push_back(&type<toy::VisuScene>());
	}
}

namespace toy
{
	toy_visu::toy_visu()
		: Module("toy::visu", { &two_type::m(), &two_gfx::m(), &toy_util::m(), &toy_core::m() })
	{
		// setup reflection meta data
		toy_visu_meta(*this);
	}
}

#ifdef TOY_VISU_MODULE
extern "C"
Module& getModule()
{
		return toy_visu::m();
}
#endif
