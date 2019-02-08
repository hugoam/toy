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
#include <meta/mud.pool.meta.h>
#include <meta/mud.refl.meta.h>
#include <meta/mud.ecs.meta.h>
#include <meta/mud.srlz.meta.h>
#include <meta/mud.math.meta.h>
#include <meta/mud.geom.meta.h>
#include <meta/mud.noise.meta.h>
#include <meta/mud.wfc.meta.h>
#include <meta/mud.fract.meta.h>
#include <meta/mud.lang.meta.h>
#include <meta/mud.ctx.meta.h>
#include <meta/mud.ui.meta.h>
#include <meta/mud.uio.meta.h>
#include <meta/mud.bgfx.meta.h>
#include <meta/mud.gfx.meta.h>
#include <meta/mud.gfx.pbr.meta.h>
#include <meta/mud.gfx.obj.meta.h>
#include <meta/mud.gltf.meta.h>
#include <meta/mud.gfx.gltf.meta.h>
#include <meta/mud.gfx.ui.meta.h>
#include <meta/mud.gfx.edit.meta.h>
#include <meta/mud.tool.meta.h>
#include <meta/mud.wfc.gfx.meta.h>
#include <meta/mud.frame.meta.h>
#include <meta/toy.shell.meta.h>
#include <meta/toy.shell.conv.h>
#endif

#include <shell/Api.h>

using namespace mud;


namespace mud
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
		: Module("shell", { , , , , , , , , , , , , , , , , , , , &mud_gfx_pbr::m(), &mud_gfx_obj::m(), , &mud_gfx_gltf::m(), &mud_gfx_ui::m(), &mud_gfx_edit::m(), , &mud_wfc_gfx::m(),  })
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
