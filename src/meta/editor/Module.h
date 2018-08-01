
#pragma once

#if !defined MUD_MODULES || defined MUD_OBJ_LIB
#include <refl/Module.h>
#endif

#ifndef MUD_MODULES
#include <meta/obj/Module.h>
#include <meta/ui/Module.h>
#include <meta/util/Module.h>
#include <meta/core/Module.h>
#include <meta/visu/Module.h>
#endif
        
#include <editor/Forward.h>
#include <editor/Types.h>
#include <editor/Api.h>

#include <meta/editor/Convert.h>

#ifndef TOY_EDITOR_REFL_EXPORT
#define TOY_EDITOR_REFL_EXPORT MUD_IMPORT
#endif

namespace toy
{
	export_ class TOY_EDITOR_REFL_EXPORT toy_editor : public Module
	{
	private:
		toy_editor();

	public:
		static toy_editor& m() { static toy_editor instance; return instance; }
	};
}

#ifdef TOY_EDITOR_MODULE
extern "C"
TOY_EDITOR_REFL_EXPORT Module& getModule();
#endif
