#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module ._05_character;
#else
#include <meta/05_character/Module.h>
#endif

#ifndef MUD_MODULES
#include <meta/05_character/Convert.h>
#endif
#define _05_CHARACTER_REFLECTION_IMPL
#include <meta/05_character/Meta.h>

	_05_character::_05_character()
		: Module("_05_character")
	{
        // ensure dependencies are instantiated
        toy_util::m();
        toy_core::m();
        toy_visu::m();
        toy_edit::m();
        toy_block::m();
        toy_shell::m();

        // setup reflection meta data
		_05_character_meta(*this);
	}

#ifdef _05_CHARACTER_MODULE
extern "C"
Module& getModule()
{
	return _05_character::m();
}
#endif
