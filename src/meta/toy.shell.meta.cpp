#include <infra/Cpp20.h>

#ifdef MUD_MODULES

#else
#include <cstddef>
#include <stl/new.h>
#include <infra/ToString.h>
#include <infra/ToValue.h>
#include <type/Vector.h>
#include <refl/MetaDecl.h>
#include <refl/Module.h>
#include <meta/toy.core.meta.h>
#include <meta/toy.visu.meta.h>
#include <meta/toy.edit.meta.h>
#include <meta/toy.block.meta.h>
#include <meta/two.pool.meta.h>
#include <meta/two.refl.meta.h>
#include <meta/two.ecs.meta.h>
#include <meta/two.srlz.meta.h>
#include <meta/two.math.meta.h>
#include <meta/two.geom.meta.h>
#include <meta/two.noise.meta.h>
#include <meta/two.wfc.meta.h>
#include <meta/two.fract.meta.h>
#include <meta/two.lang.meta.h>
#include <meta/two.ctx.meta.h>
#include <meta/two.ui.meta.h>
#include <meta/two.uio.meta.h>
#include <meta/two.bgfx.meta.h>
#include <meta/two.gfx.meta.h>
#include <meta/two.gfx.pbr.meta.h>
#include <meta/two.gfx.obj.meta.h>
#include <meta/two.gltf.meta.h>
#include <meta/two.gfx.gltf.meta.h>
#include <meta/two.gfx.ui.meta.h>
#include <meta/two.gfx.edit.meta.h>
#include <meta/two.tool.meta.h>
#include <meta/two.wfc.gfx.meta.h>
#include <meta/two.frame.meta.h>
#include <meta/toy.shell.meta.h>
#include <meta/toy.shell.conv.h>
#endif

#include <shell/Api.h>

using namespace two;


namespace two
{
	void toy_shell_meta(Module& m)
	{
	UNUSED(m);
	
	// Base Types
	
	// Enums
	
	// Sequences
	
	}
}

namespace toy
{
	toy_shell::toy_shell()
		: Module("shell", { , , , , , , , , , , , , , , , , , , , &two_gfx_pbr::m(), &two_gfx_obj::m(), , &two_gfx_gltf::m(), &two_gfx_ui::m(), &two_gfx_edit::m(), , &two_wfc_gfx::m(),  })
	{
		// setup reflection meta data
		toy_shell_meta(*this);
	}
}


extern "C"
Module& getModule()
{
		return toy_shell::m();
}
#endif
