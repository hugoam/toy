#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module toy.util;
#else
#include <meta/util/Module.h>
#endif

#ifndef MUD_MODULES
#include <meta/util/Convert.h>
#endif
#define TOY_UTIL_REFLECTION_IMPL
#include <meta/util/Meta.h>

namespace toy
{
	toy_util::toy_util()
		: Module("toy::util")
	{
        // ensure dependencies are instantiated
        mud_type::m();
        mud_math::m();

        // setup reflection meta data
		toy_util_meta(*this);
	}
}

#ifdef TOY_UTIL_MODULE
extern "C"
Module& getModule()
{
	return toy_util::m();
}
#endif
