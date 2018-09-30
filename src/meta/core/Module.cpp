#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module toy.core;
#else
#include <meta/core/Module.h>
#endif

#ifndef MUD_MODULES
#include <meta/core/Convert.h>
#endif
#define TOY_CORE_REFLECTION_IMPL
#include <meta/core/Meta.h>

namespace toy
{
	toy_core::toy_core()
		: Module("toy::core")
	{
        // ensure dependencies are instantiated
        mud_type::m();
        mud_proto::m();
        mud_math::m();
        mud_geom::m();
        mud_lang::m();
        toy_util::m();

        // setup reflection meta data
		toy_core_meta(*this);
	}
}

#ifdef TOY_CORE_MODULE
extern "C"
Module& getModule()
{
	return toy_core::m();
}
#endif
