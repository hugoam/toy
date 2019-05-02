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
#include <meta/two.gfx.meta.h>
#include <meta/toy.util.meta.h>
#include <meta/toy.core.meta.h>
#include <meta/toy.visu.meta.h>
#include <meta/toy.visu.conv.h>
#endif

#include <visu/Api.h>

using namespace two;


namespace two
{
	void toy_visu_meta(Module& m)
	{
	UNUSED(m);
	
	// Base Types
	
	// Enums
	
	// Sequences
	
	}
}

namespace toy
{
	
		: Module("visu", {  })
	{
		// setup reflection meta data
		toy_visu_meta(*this);
	}
}


extern "C"
Module& getModule()
{
		return toy_visu::m();
}
#endif
