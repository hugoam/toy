
#pragma once

#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#include <refl/Module.h>
#endif

#ifndef MUD_MODULES
#include <meta/type/Module.h>
#include <meta/gfx/Module.h>
#include <meta/util/Module.h>
#include <meta/core/Module.h>
#endif
        
#include <visu/Forward.h>
#include <visu/Types.h>
#include <visu/Api.h>

#include <meta/visu/Convert.h>

#ifndef TOY_VISU_REFL_EXPORT
#define TOY_VISU_REFL_EXPORT MUD_IMPORT
#endif

namespace toy
{
	export_ class TOY_VISU_REFL_EXPORT toy_visu : public Module
	{
	private:
		toy_visu();

	public:
		static toy_visu& m() { static toy_visu instance; return instance; }
	};
}

#ifdef TOY_VISU_MODULE
extern "C"
TOY_VISU_REFL_EXPORT Module& getModule();
#endif
