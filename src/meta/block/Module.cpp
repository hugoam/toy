#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module toy.block;
#else
#include <meta/block/Module.h>
#endif

#ifndef MUD_MODULES
#include <meta/block/Convert.h>
#endif
#define TOY_BLOCK_REFLECTION_IMPL
#include <meta/block/Meta.h>

namespace toy
{
	toy_block::toy_block()
		: Module("toy::block")
	{
        // ensure dependencies are instantiated
        mud_type::m();
        mud_math::m();
        mud_wfc_gfx::m();
        toy_core::m();
        toy_visu::m();
        toy_edit::m();

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
