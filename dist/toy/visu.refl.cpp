#include <toy/visu.h>
#include <toy/core.refl.h>
#include <two/gfx.refl.h>
#include <toy/visu.refl.h>
#include <two/type.refl.h>
#include <two/refl.h>
#include <toy/util.refl.h>
#include <two/infra.h>
#include <two/type.h>


#ifdef TWO_MODULES
module toy.visu;
#else
#include <cstddef>
#include <stl/new.h>
#endif


using namespace two;

void* toy_VisuScene__get_gfx(void* object) { return &(*static_cast<toy::VisuScene*>(object)).m_gfx; }
void toy_VisuScene_next_frame(void* object, span<void*> args, void*& result) { UNUSED(result); UNUSED(args); (*static_cast<toy::VisuScene*>(object)).next_frame(); }

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
			{ t, SIZE_MAX, type<two::GfxSystem>(), "gfx", nullptr, Member::Flags(Member::NonMutable|Member::Link), toy_VisuScene__get_gfx },
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
