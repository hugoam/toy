#include <toy/visu.h>
#include <toy/core.refl.h>
#include <mud/gfx.refl.h>
#include <toy/visu.refl.h>
#include <mud/type.refl.h>
#include <mud/refl.h>
#include <toy/util.refl.h>
#include <mud/infra.h>
#include <mud/type.h>

#ifdef MUD_MODULES
module toy.visu;
#else
#endif


using namespace mud;

void* toy_VisuScene__get_gfx_system(void* object) { return &(*static_cast<toy::VisuScene*>(object)).m_gfx_system; }
void toy_VisuScene_next_frame(void* object, array<void*> args, void*& result) { UNUSED(result); UNUSED(args); (*static_cast<toy::VisuScene*>(object)).next_frame(); }

namespace mud
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
			{ t, SIZE_MAX, type<mud::GfxSystem>(), "gfx_system", nullptr, Member::Flags(Member::NonMutable|Member::Link), toy_VisuScene__get_gfx_system },
			{ t, offsetof(toy::VisuScene, m_scene), type<mud::Scene>(), "scene", nullptr, Member::NonMutable, nullptr }
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
		: Module("toy::visu", { &mud_type::m(), &mud_gfx::m(), &toy_util::m(), &toy_core::m() })
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
