#include <infra/Cpp20.h>

#ifdef TWO_MODULES
module ._wren;
#else
#include <refl/Module.h>
#include <meta/infra.meta.h>
#include <meta/jobs.meta.h>
#include <meta/type.meta.h>
#include <meta/tree.meta.h>
#include <meta/pool.meta.h>
#include <meta/refl.meta.h>
#include <meta/ecs.meta.h>
#include <meta/srlz.meta.h>
#include <meta/math.meta.h>
#include <meta/geom.meta.h>
#include <meta/lang.meta.h>
#include <meta/ctx.meta.h>
#include <meta/ui.meta.h>
#include <meta/uio.meta.h>
#include <meta/bgfx.meta.h>
#include <meta/gfx.meta.h>
#include <meta/gfx.ui.meta.h>
#include <meta/frame.meta.h>
#include <meta/util.meta.h>
#include <meta/core.meta.h>
#include <meta/visu.meta.h>
#include <meta/edit.meta.h>
#include <meta/block.meta.h>
#include <meta/shell.meta.h>
#include <meta/_wren.meta.h>
#endif

using namespace two;
using namespace toy;

_wren::_wren()
	: Module("_wren", { &two_infra::m(), &two_jobs::m(), &two_type::m(), &two_tree::m(), &two_pool::m(), &two_refl::m(), &two_ecs::m(), &two_srlz::m(), &two_math::m(), &two_geom::m(), &two_lang::m(), &two_ctx::m(), &two_ui::m(), &two_uio::m(), &two_bgfx::m(), &two_gfx::m(), &two_gfx_ui::m(), &two_frame::m(), &toy_util::m(), &toy_core::m(), &toy_visu::m(), &toy_edit::m(), &toy_block::m(), &toy_shell::m() })
{}

#ifdef _WREN_MODULE
extern "C"
Module& getModule()
{
	return _wren::m();
}
#endif
