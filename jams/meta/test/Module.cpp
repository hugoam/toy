#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module ._test;
#else
#include <meta/test/Module.h>
#endif

#ifndef MUD_MODULES
#include <meta/test/Convert.h>
#endif
#define _TEST_REFLECTION_IMPL
#include <meta/test/Meta.h>

	_test::_test()
		: Module("_test")
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
		_test_meta(*this);
	}

#ifdef _TEST_MODULE
extern "C"
Module& getModule()
{
	return _test::m();
}
#endif
