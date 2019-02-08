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
#include <meta/mud.type.meta.h>
#include <meta/mud.jobs.meta.h>
#include <meta/mud.ecs.meta.h>
#include <meta/mud.math.meta.h>
#include <meta/mud.geom.meta.h>
#include <meta/mud.lang.meta.h>
#include <meta/toy.util.meta.h>
#include <meta/toy.core.meta.h>
#include <meta/toy.core.conv.h>
#endif

#include <core/Api.h>

using namespace mud;


namespace mud
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
