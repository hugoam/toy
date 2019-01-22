#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module toy.util;
#else
#include <meta/type/Module.h>
#include <meta/math/Module.h>
#include <meta/util/Module.h>
#include <meta/util/Convert.h>
#endif

#include <util/Api.h>
#define TOY_UTIL_REFLECTION_IMPL
#include <meta/util/Meta.h>

namespace toy
{
	toy_util::toy_util()
		: Module("toy::util", { &mud_type::m(), &mud_math::m() })
	{
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
