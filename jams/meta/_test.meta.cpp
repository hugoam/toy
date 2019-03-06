#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module ._test;
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
#include <meta/_test.meta.h>
#endif

_test::_test()
	: Module("_test", { &mud_infra::m(), &mud_jobs::m(), &mud_type::m(), &mud_tree::m(), &mud_pool::m(), &mud_refl::m(), &mud_ecs::m(), &mud_srlz::m(), &mud_math::m(), &mud_geom::m(), &mud_lang::m(), &mud_ctx::m(), &mud_ui::m(), &mud_uio::m(), &mud_bgfx::m(), &mud_gfx::m(), &mud_gfx_ui::m(), &mud_frame::m(), &toy_util::m(), &toy_core::m(), &toy_visu::m(), &toy_edit::m(), &toy_block::m(), &toy_shell::m() })
{}

#ifdef _TEST_MODULE
extern "C"
Module& getModule()
{
	return _test::m();
}
#endif
