#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module toy.edit;
#else
#include <meta/edit/Module.h>
#endif

#ifndef MUD_MODULES
#include <meta/edit/Convert.h>
#endif
#define TOY_EDIT_REFLECTION_IMPL
#include <meta/edit/Meta.h>

namespace toy
{
	toy_edit::toy_edit()
		: Module("toy::edit")
	{
        // ensure dependencies are instantiated
        mud_type::m();
        mud_ui::m();
        mud_tool::m();
        toy_util::m();
        toy_core::m();
        toy_visu::m();

        // setup reflection meta data
		toy_edit_meta(*this);
	}
}

#ifdef TOY_EDIT_MODULE
extern "C"
Module& getModule()
{
	return toy_edit::m();
}
#endif
