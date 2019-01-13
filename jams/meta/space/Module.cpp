#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module ._space;
#else
#include <meta/space/Module.h>
#endif

#ifndef MUD_MODULES
#include <meta/space/Convert.h>
#endif
#define _SPACE_REFLECTION_IMPL
#include <meta/space/Meta.h>

_space::_space()
	: Module("_space", { &mud_infra::m(), &mud_jobs::m(), &mud_type::m(), &mud_tree::m(), &mud_pool::m(), &mud_refl::m(), &mud_ecs::m(), &mud_srlz::m(), &mud_math::m(), &mud_geom::m(), &mud_noise::m(), &mud_wfc::m(), &mud_fract::m(), &mud_lang::m(), &mud_ctx::m(), &mud_ui::m(), &mud_uio::m(), &mud_bgfx::m(), &mud_gfx::m(), &mud_gfx_pbr::m(), &mud_gfx_obj::m(), &mud_gltf::m(), &mud_gfx_gltf::m(), &mud_gfx_ui::m(), &mud_gfx_edit::m(), &mud_tool::m(), &mud_wfc_gfx::m(), &mud_frame::m(), &toy_util::m(), &toy_core::m(), &toy_visu::m(), &toy_edit::m(), &toy_block::m(), &toy_shell::m() })
{
	// setup reflection meta data
	_space_meta(*this);
}

#ifdef _SPACE_MODULE
extern "C"
Module& getModule()
{
		return _space::m();
}
#endif
