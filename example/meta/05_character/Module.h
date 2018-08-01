
#pragma once

#if !defined MUD_MODULES || defined MUD_OBJ_LIB
#include <refl/Module.h>
#endif

#ifndef MUD_MODULES
#include <meta/util/Module.h>
#include <meta/core/Module.h>
#include <meta/visu/Module.h>
#include <meta/edit/Module.h>
#include <meta/block/Module.h>
#include <meta/shell/Module.h>
#endif
        
#include <05_character/Forward.h>
#include <05_character/Types.h>
#include <05_character/Api.h>

#include <meta/05_character/Convert.h>

#ifndef _05_CHARACTER_REFL_EXPORT
#define _05_CHARACTER_REFL_EXPORT MUD_IMPORT
#endif

	export_ class _05_CHARACTER_REFL_EXPORT _05_character : public Module
	{
	private:
		_05_character();

	public:
		static _05_character& m() { static _05_character instance; return instance; }
	};

#ifdef _05_CHARACTER_MODULE
extern "C"
_05_CHARACTER_REFL_EXPORT Module& getModule();
#endif
