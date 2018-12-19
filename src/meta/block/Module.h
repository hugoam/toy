
#pragma once

#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#include <refl/Module.h>
#endif

#ifndef MUD_MODULES
#include <meta/type/Module.h>
#include <meta/math/Module.h>
#include <meta/wfc-gfx/Module.h>
#include <meta/core/Module.h>
#include <meta/visu/Module.h>
#include <meta/edit/Module.h>
#endif
        
#include <block/Forward.h>
#include <block/Types.h>
#include <block/Api.h>

#include <meta/block/Convert.h>

#ifndef TOY_BLOCK_REFL_EXPORT
#define TOY_BLOCK_REFL_EXPORT MUD_IMPORT
#endif

namespace toy
{
	export_ class TOY_BLOCK_REFL_EXPORT toy_block : public Module
	{
	private:
		toy_block();

	public:
		static toy_block& m() { static toy_block instance; return instance; }
	};
}

#ifdef TOY_BLOCK_MODULE
extern "C"
TOY_BLOCK_REFL_EXPORT Module& getModule();
#endif
