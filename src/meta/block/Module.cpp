#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module toy.block;
#else
#include <meta/type/Module.h>
#include <meta/math/Module.h>
#include <meta/wfc-gfx/Module.h>
#include <meta/core/Module.h>
#include <meta/visu/Module.h>
#include <meta/edit/Module.h>
#include <meta/block/Module.h>
#include <meta/block/Convert.h>
#endif

#include <block/Api.h>
#define TOY_BLOCK_REFLECTION_IMPL
#include <meta/block/Meta.h>

namespace toy
{
	toy_block::toy_block()
		: Module("toy::block", { &mud_type::m(), &mud_math::m(), &mud_wfc_gfx::m(), &toy_core::m(), &toy_visu::m(), &toy_edit::m() })
	{
		// setup reflection meta data
		toy_block_meta(*this);
	}
}

#ifdef TOY_BLOCK_MODULE
extern "C"
Module& getModule()
{
		return toy_block::m();
}
#endif
