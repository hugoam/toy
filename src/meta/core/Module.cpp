#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module toy.core;
#else
#include <meta/type/Module.h>
#include <meta/jobs/Module.h>
#include <meta/ecs/Module.h>
#include <meta/math/Module.h>
#include <meta/geom/Module.h>
#include <meta/lang/Module.h>
#include <meta/util/Module.h>
#include <meta/core/Module.h>
#include <meta/core/Convert.h>
#endif

#include <core/Api.h>
#define TOY_CORE_REFLECTION_IMPL
#include <meta/core/Meta.h>

namespace toy
{
	toy_core::toy_core()
		: Module("toy::core", { &mud_type::m(), &mud_jobs::m(), &mud_ecs::m(), &mud_math::m(), &mud_geom::m(), &mud_lang::m(), &toy_util::m() })
	{
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
