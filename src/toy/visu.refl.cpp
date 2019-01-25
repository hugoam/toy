#pragma once

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
		static Meta meta = { type<toy::PhysicDebugDraw>(), &namspc({ "toy" }), "PhysicDebugDraw", sizeof(toy::PhysicDebugDraw), TypeClass::Object };
		static Class cls = { type<toy::PhysicDebugDraw>(),
			// bases
			{  },
			{  },
			// constructors
			{
			},
			// copy constructor
			{
			},
			// members
			{
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		meta_class<toy::PhysicDebugDraw>();
	}
	// toy::VisuScene
	{
		static Meta meta = { type<toy::VisuScene>(), &namspc({ "toy" }), "VisuScene", sizeof(toy::VisuScene), TypeClass::Object };
		static Class cls = { type<toy::VisuScene>(),
			// bases
			{  },
			{  },
			// constructors
			{
			},
			// copy constructor
			{
			},
			// members
			{
				{ type<toy::VisuScene>(), Address(), type<mud::GfxSystem>(), "gfx_system", Ref(type<mud::GfxSystem>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::VisuScene>(object).m_gfx_system); } },
				{ type<toy::VisuScene>(), member_address(&toy::VisuScene::m_scene), type<mud::Scene>(), "scene", Ref(type<mud::Scene>()), Member::NonMutable, nullptr }
			},
			// methods
			{
				{ type<toy::VisuScene>(), "next_frame", member_address<void(toy::VisuScene::*)()>(&toy::VisuScene::next_frame), [](Ref object, array<Var> args, Var& result) { UNUSED(result); UNUSED(args); val<toy::VisuScene>(object).next_frame(); }, {}, Var() }
			},
			// static members
			{
			}
		};
		meta_class<toy::VisuScene>();
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
