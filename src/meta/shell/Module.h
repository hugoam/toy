
#pragma once

#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#include <refl/Module.h>
#endif

#ifndef MUD_MODULES
#include <meta/core/Module.h>
#include <meta/visu/Module.h>
#include <meta/edit/Module.h>
#include <meta/block/Module.h>
#include <meta/ecs/Module.h>
#include <meta/tree/Module.h>
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
#include <meta/ctx-glfw/Module.h>
#include <meta/ui-vg/Module.h>
#include <meta/bgfx/Module.h>
#include <meta/gfx/Module.h>
#include <meta/gfx-pbr/Module.h>
#include <meta/gfx-obj/Module.h>
#include <meta/gfx-gltf/Module.h>
#include <meta/gfx-ui/Module.h>
#include <meta/tool/Module.h>
#include <meta/wfc-gfx/Module.h>
#endif
        
#include <shell/Forward.h>
#include <shell/Types.h>
#include <shell/Api.h>

#include <meta/shell/Convert.h>

#ifndef TOY_SHELL_REFL_EXPORT
#define TOY_SHELL_REFL_EXPORT MUD_IMPORT
#endif

namespace toy
{
	export_ class TOY_SHELL_REFL_EXPORT toy_shell : public Module
	{
	private:
		toy_shell();

	public:
		static toy_shell& m() { static toy_shell instance; return instance; }
	};
}

#ifdef TOY_SHELL_MODULE
extern "C"
TOY_SHELL_REFL_EXPORT Module& getModule();
#endif
