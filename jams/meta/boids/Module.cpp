#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module ._boids;
#else
#include <type/Any.h>
#include <type/Vector.h>
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
#include <meta/boids/Module.h>
#include <meta/boids/Convert.h>
#endif

#include <boids/Api.h>

namespace mud
{
	void _boids_meta(Module& m)
	{
	UNUSED(m);
	
	// Base Types
	
	// Enums
	
	// Sequences
	
	// boids::Boid
	{
		static Meta meta = { type<boids::Boid>(), &namspc({ "boids" }), "Boid", sizeof(boids::Boid), TypeClass::Struct };
		static Class cls = { type<boids::Boid>(),
			// bases
			{  },
			{  },
			// constructors
			{
				{ type<boids::Boid>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<boids::Boid>(ref)) boids::Boid(  ); }, {} }
			},
			// copy constructor
			{
				{ type<boids::Boid>(), [](Ref ref, Ref other) { new(&val<boids::Boid>(ref)) boids::Boid(val<boids::Boid>(other)); } }
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
		meta_class<boids::Boid>();
	}
	// boids::BoidObstacle
	{
		static Meta meta = { type<boids::BoidObstacle>(), &namspc({ "boids" }), "BoidObstacle", sizeof(boids::BoidObstacle), TypeClass::Struct };
		static Class cls = { type<boids::BoidObstacle>(),
			// bases
			{  },
			{  },
			// constructors
			{
				{ type<boids::BoidObstacle>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<boids::BoidObstacle>(ref)) boids::BoidObstacle(  ); }, {} }
			},
			// copy constructor
			{
				{ type<boids::BoidObstacle>(), [](Ref ref, Ref other) { new(&val<boids::BoidObstacle>(ref)) boids::BoidObstacle(val<boids::BoidObstacle>(other)); } }
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
		meta_class<boids::BoidObstacle>();
	}
	// boids::BoidTarget
	{
		static Meta meta = { type<boids::BoidTarget>(), &namspc({ "boids" }), "BoidTarget", sizeof(boids::BoidTarget), TypeClass::Struct };
		static Class cls = { type<boids::BoidTarget>(),
			// bases
			{  },
			{  },
			// constructors
			{
				{ type<boids::BoidTarget>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<boids::BoidTarget>(ref)) boids::BoidTarget(  ); }, {} }
			},
			// copy constructor
			{
				{ type<boids::BoidTarget>(), [](Ref ref, Ref other) { new(&val<boids::BoidTarget>(ref)) boids::BoidTarget(val<boids::BoidTarget>(other)); } }
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
		meta_class<boids::BoidTarget>();
	}
	// boids::Heading
	{
		static Meta meta = { type<boids::Heading>(), &namspc({ "boids" }), "Heading", sizeof(boids::Heading), TypeClass::Struct };
		static Class cls = { type<boids::Heading>(),
			// bases
			{  },
			{  },
			// constructors
			{
				{ type<boids::Heading>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<boids::Heading>(ref)) boids::Heading(  ); }, {} }
			},
			// copy constructor
			{
				{ type<boids::Heading>(), [](Ref ref, Ref other) { new(&val<boids::Heading>(ref)) boids::Heading(val<boids::Heading>(other)); } }
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
		meta_class<boids::Heading>();
	}
	// boids::MoveForward
	{
		static Meta meta = { type<boids::MoveForward>(), &namspc({ "boids" }), "MoveForward", sizeof(boids::MoveForward), TypeClass::Struct };
		static Class cls = { type<boids::MoveForward>(),
			// bases
			{  },
			{  },
			// constructors
			{
				{ type<boids::MoveForward>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<boids::MoveForward>(ref)) boids::MoveForward(  ); }, {} }
			},
			// copy constructor
			{
				{ type<boids::MoveForward>(), [](Ref ref, Ref other) { new(&val<boids::MoveForward>(ref)) boids::MoveForward(val<boids::MoveForward>(other)); } }
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
		meta_class<boids::MoveForward>();
	}
	// boids::MoveSpeed
	{
		static Meta meta = { type<boids::MoveSpeed>(), &namspc({ "boids" }), "MoveSpeed", sizeof(boids::MoveSpeed), TypeClass::Struct };
		static Class cls = { type<boids::MoveSpeed>(),
			// bases
			{  },
			{  },
			// constructors
			{
				{ type<boids::MoveSpeed>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<boids::MoveSpeed>(ref)) boids::MoveSpeed(  ); }, {} }
			},
			// copy constructor
			{
				{ type<boids::MoveSpeed>(), [](Ref ref, Ref other) { new(&val<boids::MoveSpeed>(ref)) boids::MoveSpeed(val<boids::MoveSpeed>(other)); } }
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
		meta_class<boids::MoveSpeed>();
	}
	// boids::Player
	{
		static Meta meta = { type<boids::Player>(), &namspc({ "boids" }), "Player", sizeof(boids::Player), TypeClass::Object };
		static Class cls = { type<boids::Player>(),
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
		meta_class<boids::Player>();
	}
	// boids::Position
	{
		static Meta meta = { type<boids::Position>(), &namspc({ "boids" }), "Position", sizeof(boids::Position), TypeClass::Struct };
		static Class cls = { type<boids::Position>(),
			// bases
			{  },
			{  },
			// constructors
			{
				{ type<boids::Position>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<boids::Position>(ref)) boids::Position(  ); }, {} }
			},
			// copy constructor
			{
				{ type<boids::Position>(), [](Ref ref, Ref other) { new(&val<boids::Position>(ref)) boids::Position(val<boids::Position>(other)); } }
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
		meta_class<boids::Position>();
	}
	// boids::Rotation
	{
		static Meta meta = { type<boids::Rotation>(), &namspc({ "boids" }), "Rotation", sizeof(boids::Rotation), TypeClass::Struct };
		static Class cls = { type<boids::Rotation>(),
			// bases
			{  },
			{  },
			// constructors
			{
				{ type<boids::Rotation>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<boids::Rotation>(ref)) boids::Rotation(  ); }, {} }
			},
			// copy constructor
			{
				{ type<boids::Rotation>(), [](Ref ref, Ref other) { new(&val<boids::Rotation>(ref)) boids::Rotation(val<boids::Rotation>(other)); } }
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
		meta_class<boids::Rotation>();
	}
	// boids::Transform4
	{
		static Meta meta = { type<boids::Transform4>(), &namspc({ "boids" }), "Transform4", sizeof(boids::Transform4), TypeClass::Struct };
		static Class cls = { type<boids::Transform4>(),
			// bases
			{  },
			{  },
			// constructors
			{
				{ type<boids::Transform4>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<boids::Transform4>(ref)) boids::Transform4(  ); }, {} }
			},
			// copy constructor
			{
				{ type<boids::Transform4>(), [](Ref ref, Ref other) { new(&val<boids::Transform4>(ref)) boids::Transform4(val<boids::Transform4>(other)); } }
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
		meta_class<boids::Transform4>();
	}
		m.m_types.push_back(&type<boids::Boid>());
		m.m_types.push_back(&type<boids::BoidObstacle>());
		m.m_types.push_back(&type<boids::BoidTarget>());
		m.m_types.push_back(&type<boids::Heading>());
		m.m_types.push_back(&type<boids::MoveForward>());
		m.m_types.push_back(&type<boids::MoveSpeed>());
		m.m_types.push_back(&type<boids::Player>());
		m.m_types.push_back(&type<boids::Position>());
		m.m_types.push_back(&type<boids::Rotation>());
		m.m_types.push_back(&type<boids::Transform4>());
	}
}

_boids::_boids()
	: Module("_boids", { &mud_infra::m(), &mud_jobs::m(), &mud_type::m(), &mud_tree::m(), &mud_pool::m(), &mud_refl::m(), &mud_ecs::m(), &mud_srlz::m(), &mud_math::m(), &mud_geom::m(), &mud_noise::m(), &mud_wfc::m(), &mud_fract::m(), &mud_lang::m(), &mud_ctx::m(), &mud_ui::m(), &mud_uio::m(), &mud_bgfx::m(), &mud_gfx::m(), &mud_gfx_pbr::m(), &mud_gfx_obj::m(), &mud_gltf::m(), &mud_gfx_gltf::m(), &mud_gfx_ui::m(), &mud_gfx_edit::m(), &mud_tool::m(), &mud_wfc_gfx::m(), &mud_frame::m(), &toy_util::m(), &toy_core::m(), &toy_visu::m(), &toy_edit::m(), &toy_block::m(), &toy_shell::m() })
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
