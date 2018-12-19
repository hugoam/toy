#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module toy.shell;
#else
#include <meta/shell/Module.h>
#endif

#ifndef MUD_MODULES
#include <meta/shell/Convert.h>
#endif
#define TOY_SHELL_REFLECTION_IMPL
#include <meta/shell/Meta.h>

namespace toy
{
	toy_shell::toy_shell()
		: Module("toy::shell")
	{
        // ensure dependencies are instantiated
        toy_core::m();
        toy_visu::m();
        toy_edit::m();
        toy_block::m();
        mud_proto::m();
        mud_tree::m();
        mud_srlz::m();
        mud_math::m();
        mud_geom::m();
		mud_noise::m();
		mud_wfc::m();
		mud_fract::m();
        mud_lang::m();
        mud_ctx::m();
        mud_ui::m();
        mud_uio::m();
        //mud_ctx_glfw::m();
        mud_ui_vg::m();
        mud_bgfx::m();
        mud_gfx::m();
        mud_gfx_pbr::m();
        mud_gfx_obj::m();
        mud_gfx_gltf::m();
        mud_gfx_ui::m();
        mud_tool::m();
        mud_wfc_gfx::m();

        // setup reflection meta data
		toy_shell_meta(*this);
	}
}

#ifdef TOY_SHELL_MODULE
extern "C"
Module& getModule()
{
	return toy_shell::m();
}
#endif
