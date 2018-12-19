#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module ._minimal;
#else
#include <meta/minimal/Module.h>
#endif

#ifndef MUD_MODULES
#include <meta/minimal/Convert.h>
#endif
#define _MINIMAL_REFLECTION_IMPL
#include <meta/minimal/Meta.h>

	_minimal::_minimal()
		: Module("_minimal")
	{
        // ensure dependencies are instantiated
        mud_infra::m();
        mud_type::m();
        mud_pool::m();
        mud_refl::m();
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
        //mud_snd::m();
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
        toy_util::m();
        toy_core::m();
        toy_visu::m();
        toy_edit::m();
        toy_block::m();
        toy_shell::m();

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
