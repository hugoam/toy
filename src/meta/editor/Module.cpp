#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module toy.editor;
#else
#include <meta/editor/Module.h>
#endif

#ifndef MUD_MODULES
#include <meta/editor/Convert.h>
#endif
#define TOY_EDITOR_REFLECTION_IMPL
#include <meta/editor/Meta.h>

namespace toy
{
	toy_editor::toy_editor()
		: Module("toy::editor")
	{
        // ensure dependencies are instantiated
        two_obj::m();
        two_ui::m();
        toy_util::m();
        toy_core::m();
        toy_visu::m();

        // setup reflection meta data
		toy_editor_meta(*this);
	}
}

#ifdef TOY_EDITOR_MODULE
extern "C"
Module& getModule()
{
	return toy_editor::m();
}
#endif
