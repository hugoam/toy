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
#include <meta/two.jobs.meta.h>
#include <meta/two.ecs.meta.h>
#include <meta/two.math.meta.h>
#include <meta/two.geom.meta.h>
#include <meta/two.lang.meta.h>
#include <meta/toy.util.meta.h>
#include <meta/toy.core.meta.h>
#include <meta/toy.core.conv.h>
#endif

#include <core/Api.h>

using namespace two;


namespace two
{
	void toy_core_meta(Module& m)
	{
	UNUSED(m);
	
	// Base Types
	
	// Enums
	
	// Sequences
	
	}
}

namespace toy
{
	
		: Module("core", { , , , , , ,  })
	{
		// setup reflection meta data
		toy_core_meta(*this);
	}
}


extern "C"
Module& getModule()
{
		return toy_core::m();
}
#endif
