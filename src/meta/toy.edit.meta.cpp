#include <infra/Cpp20.h>

#ifdef MUD_MODULES

#else
#include <cstddef>
#include <stl/new.h>
#include <infra/ToString.h>
#include <infra/ToValue.h>
#include <type/Vector.h>
#include <refl/MetaDecl.h>
#include <refl/Module.h>
#include <meta/two.type.meta.h>
#include <meta/two.ui.meta.h>
#include <meta/two.tool.meta.h>
#include <meta/toy.util.meta.h>
#include <meta/toy.core.meta.h>
#include <meta/toy.visu.meta.h>
#include <meta/toy.edit.meta.h>
#include <meta/toy.edit.conv.h>
#endif

#include <edit/Api.h>

using namespace two;


namespace two
{
	void toy_edit_meta(Module& m)
	{
	UNUSED(m);
	
	// Base Types
	
	// Enums
	
	// Sequences
	
	}
}

namespace toy
{
	
		: Module("edit", {  })
	{
		// setup reflection meta data
		toy_edit_meta(*this);
	}
}


extern "C"
Module& getModule()
{
		return toy_edit::m();
}
#endif
