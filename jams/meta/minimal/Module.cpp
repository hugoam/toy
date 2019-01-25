#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module ._minimal;
#else
#include <type/Vector.h>
#include <type/Any.h>
#include <refl/MetaDecl.h>
#include <refl/Module.h>
#include <meta/infra/Module.h>
#include <meta/jobs/Module.h>
#include <meta/type/Module.h>
#include <meta/tree/Module.h>
#include <meta/pool/Module.h>
#include <meta/refl/Module.h>
#include <meta/ecs/Module.h>
#include <meta/srlz/Module.h>
#include <meta/math/Module.h>
#include <meta/geom/Module.h>
#include <meta/noise/Module.h>
#include <meta/wfc/Module.h>
#include <meta/fract/Module.h>
#include <meta/lang/Module.h>
#include <meta/ctx/Module.h>
#include <meta/ui/Module.h>
#include <meta/uio/Module.h>
#include <meta/bgfx/Module.h>
#include <meta/gfx/Module.h>
#include <meta/gfx-pbr/Module.h>
#include <meta/gfx-obj/Module.h>
#include <meta/gltf/Module.h>
#include <meta/gfx-gltf/Module.h>
#include <meta/gfx-ui/Module.h>
#include <meta/gfx-edit/Module.h>
#include <meta/tool/Module.h>
#include <meta/wfc-gfx/Module.h>
#include <meta/frame/Module.h>
#include <meta/util/Module.h>
#include <meta/core/Module.h>
#include <meta/visu/Module.h>
#include <meta/edit/Module.h>
#include <meta/block/Module.h>
#include <meta/shell/Module.h>
#include <meta/minimal/Module.h>
#include <meta/minimal/Convert.h>
#endif

#include <minimal/Api.h>

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
		static Meta meta = { type<Bullet>(), &namspc({}), "Bullet", sizeof(Bullet), TypeClass::Object };
		static Class cls = { type<Bullet>(),
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
				{ type<Bullet>(), member_address(&Bullet::m_source), type<mud::vec3>(), "source", var(mud::vec3()), Member::Value, nullptr },
				{ type<Bullet>(), member_address(&Bullet::m_velocity), type<mud::vec3>(), "velocity", var(mud::vec3()), Member::Value, nullptr }
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		meta_class<Bullet>();
	}
	// Crate
	{
		static Meta meta = { type<Crate>(), &namspc({}), "Crate", sizeof(Crate), TypeClass::Object };
		static Class cls = { type<Crate>(),
			// bases
			{  },
			{  },
			// constructors
			{
				{ type<Crate>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<Crate>(ref)) Crate(  ); }, {} },
				{ type<Crate>(), [](Ref ref, array<Var> args) { new(&val<Crate>(ref)) Crate( val<toy::HSpatial>(args[0]), val<toy::HMovable>(args[1]), val<mud::vec3>(args[2]) ); }, { { "spatial", var(toy::HSpatial()) }, { "movable", var(toy::HMovable()) }, { "extents", var(mud::vec3()) } } }
			},
			// copy constructor
			{
			},
			// members
			{
				{ type<Crate>(), member_address(&Crate::m_extents), type<mud::vec3>(), "extents", var(mud::vec3()), Member::Value, nullptr }
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		init_pool<Crate>();
		meta_class<Crate>();
	}
	// Human
	{
		static Meta meta = { type<Human>(), &namspc({}), "Human", sizeof(Human), TypeClass::Object };
		static Class cls = { type<Human>(),
			// bases
			{  },
			{  },
			// constructors
			{
				{ type<Human>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<Human>(ref)) Human(  ); }, {} },
				{ type<Human>(), [](Ref ref, array<Var> args) { new(&val<Human>(ref)) Human( val<toy::HSpatial>(args[0]), val<toy::HMovable>(args[1]) ); }, { { "spatial", var(toy::HSpatial()) }, { "movable", var(toy::HMovable()) } } }
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
		init_pool<Human>();
		meta_class<Human>();
	}
	// Player
	{
		static Meta meta = { type<Player>(), &namspc({}), "Player", sizeof(Player), TypeClass::Object };
		static Class cls = { type<Player>(),
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
		meta_class<Player>();
	}
	// mud::ComponentHandle<Bullet>
	{
		static Meta meta = { type<mud::ComponentHandle<Bullet>>(), &namspc({ "mud" }), "ComponentHandle<Bullet>", sizeof(mud::ComponentHandle<Bullet>), TypeClass::Struct };
		static Class cls = { type<mud::ComponentHandle<Bullet>>(),
			// bases
			{ &type<mud::Entity>() },
			{ base_offset<mud::ComponentHandle<Bullet>, mud::Entity>() },
			// constructors
			{
				{ type<mud::ComponentHandle<Bullet>>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<mud::ComponentHandle<Bullet>>(ref)) mud::ComponentHandle<Bullet>(  ); }, {} }
			},
			// copy constructor
			{
				{ type<mud::ComponentHandle<Bullet>>(), [](Ref ref, Ref other) { new(&val<mud::ComponentHandle<Bullet>>(ref)) mud::ComponentHandle<Bullet>(val<mud::ComponentHandle<Bullet>>(other)); } }
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
		meta_class<mud::ComponentHandle<Bullet>>();
	}
	// mud::ComponentHandle<Crate>
	{
		static Meta meta = { type<mud::ComponentHandle<Crate>>(), &namspc({ "mud" }), "ComponentHandle<Crate>", sizeof(mud::ComponentHandle<Crate>), TypeClass::Struct };
		static Class cls = { type<mud::ComponentHandle<Crate>>(),
			// bases
			{ &type<mud::Entity>() },
			{ base_offset<mud::ComponentHandle<Crate>, mud::Entity>() },
			// constructors
			{
				{ type<mud::ComponentHandle<Crate>>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<mud::ComponentHandle<Crate>>(ref)) mud::ComponentHandle<Crate>(  ); }, {} }
			},
			// copy constructor
			{
				{ type<mud::ComponentHandle<Crate>>(), [](Ref ref, Ref other) { new(&val<mud::ComponentHandle<Crate>>(ref)) mud::ComponentHandle<Crate>(val<mud::ComponentHandle<Crate>>(other)); } }
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
		meta_class<mud::ComponentHandle<Crate>>();
	}
	// mud::ComponentHandle<Human>
	{
		static Meta meta = { type<mud::ComponentHandle<Human>>(), &namspc({ "mud" }), "ComponentHandle<Human>", sizeof(mud::ComponentHandle<Human>), TypeClass::Struct };
		static Class cls = { type<mud::ComponentHandle<Human>>(),
			// bases
			{ &type<mud::Entity>() },
			{ base_offset<mud::ComponentHandle<Human>, mud::Entity>() },
			// constructors
			{
				{ type<mud::ComponentHandle<Human>>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<mud::ComponentHandle<Human>>(ref)) mud::ComponentHandle<Human>(  ); }, {} }
			},
			// copy constructor
			{
				{ type<mud::ComponentHandle<Human>>(), [](Ref ref, Ref other) { new(&val<mud::ComponentHandle<Human>>(ref)) mud::ComponentHandle<Human>(val<mud::ComponentHandle<Human>>(other)); } }
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
		meta_class<mud::ComponentHandle<Human>>();
	}
		m.m_types.push_back(&type<Bullet>());
		m.m_types.push_back(&type<Crate>());
		m.m_types.push_back(&type<Human>());
		m.m_types.push_back(&type<Player>());
		m.m_types.push_back(&type<mud::ComponentHandle<Bullet>>());
		m.m_types.push_back(&type<mud::ComponentHandle<Crate>>());
		m.m_types.push_back(&type<mud::ComponentHandle<Human>>());
	}
}

_minimal::_minimal()
	: Module("_minimal", { &mud_infra::m(), &mud_jobs::m(), &mud_type::m(), &mud_tree::m(), &mud_pool::m(), &mud_refl::m(), &mud_ecs::m(), &mud_srlz::m(), &mud_math::m(), &mud_geom::m(), &mud_noise::m(), &mud_wfc::m(), &mud_fract::m(), &mud_lang::m(), &mud_ctx::m(), &mud_ui::m(), &mud_uio::m(), &mud_bgfx::m(), &mud_gfx::m(), &mud_gfx_pbr::m(), &mud_gfx_obj::m(), &mud_gltf::m(), &mud_gfx_gltf::m(), &mud_gfx_ui::m(), &mud_gfx_edit::m(), &mud_tool::m(), &mud_wfc_gfx::m(), &mud_frame::m(), &toy_util::m(), &toy_core::m(), &toy_visu::m(), &toy_edit::m(), &toy_block::m(), &toy_shell::m() })
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
