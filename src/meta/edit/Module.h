
#pragma once

#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#include <refl/Module.h>
#endif

#ifndef MUD_MODULES
#include <meta/type/Module.h>
#include <meta/ui/Module.h>
#include <meta/tool/Module.h>
#include <meta/util/Module.h>
#include <meta/core/Module.h>
#include <meta/visu/Module.h>
#endif
        
#include <edit/Forward.h>
#include <edit/Types.h>
#include <edit/Api.h>

#include <meta/edit/Convert.h>

#ifndef TOY_EDIT_REFL_EXPORT
#define TOY_EDIT_REFL_EXPORT MUD_IMPORT
#endif

namespace toy
{
	export_ class TOY_EDIT_REFL_EXPORT toy_edit : public Module
	{
	private:
		toy_edit();

	public:
		static toy_edit& m() { static toy_edit instance; return instance; }
	};
}

#ifdef TOY_EDIT_MODULE
extern "C"
TOY_EDIT_REFL_EXPORT Module& getModule();
#endif
