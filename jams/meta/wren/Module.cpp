#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module ._wren;
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
#include <meta/wren/Module.h>
#include <meta/wren/Convert.h>
#endif

#include <wren/Api.h>

namespace mud
{
	void _wren_meta(Module& m)
	{
	UNUSED(m);
	
	// Base Types
	
	// Enums
	
	// Sequences
	
	}
}

_wren::_wren()
	: Module("_wren", { &mud_infra::m(), &mud_jobs::m(), &mud_type::m(), &mud_tree::m(), &mud_pool::m(), &mud_refl::m(), &mud_ecs::m(), &mud_srlz::m(), &mud_math::m(), &mud_geom::m(), &mud_noise::m(), &mud_wfc::m(), &mud_fract::m(), &mud_lang::m(), &mud_ctx::m(), &mud_ui::m(), &mud_uio::m(), &mud_bgfx::m(), &mud_gfx::m(), &mud_gfx_pbr::m(), &mud_gfx_obj::m(), &mud_gltf::m(), &mud_gfx_gltf::m(), &mud_gfx_ui::m(), &mud_gfx_edit::m(), &mud_tool::m(), &mud_wfc_gfx::m(), &mud_frame::m(), &toy_util::m(), &toy_core::m(), &toy_visu::m(), &toy_edit::m(), &toy_block::m(), &toy_shell::m() })
{
	// setup reflection meta data
	_wren_meta(*this);
}

#ifdef _WREN_MODULE
extern "C"
Module& getModule()
{
		return _wren::m();
}
#endif
