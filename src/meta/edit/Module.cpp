#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module toy.edit;
#else
#include <meta/type/Module.h>
#include <meta/ui/Module.h>
#include <meta/tool/Module.h>
#include <meta/util/Module.h>
#include <meta/core/Module.h>
#include <meta/visu/Module.h>
#include <meta/edit/Module.h>
#include <meta/edit/Convert.h>
#endif

#include <edit/Api.h>
#define TOY_EDIT_REFLECTION_IMPL
#include <meta/edit/Meta.h>

namespace toy
{
	toy_edit::toy_edit()
		: Module("toy::edit", { &mud_type::m(), &mud_ui::m(), &mud_tool::m(), &toy_util::m(), &toy_core::m(), &toy_visu::m() })
	{
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
