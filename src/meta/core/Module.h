#pragma once

#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#include <refl/Module.h>
#endif

#include <core/Forward.h>
#include <core/Types.h>

#ifndef TOY_CORE_REFL_EXPORT
#define TOY_CORE_REFL_EXPORT MUD_IMPORT
#endif

namespace toy
{
	export_ class TOY_CORE_REFL_EXPORT toy_core : public Module
	{
	private:
		toy_core();
		
	public:
		static toy_core& m() { static toy_core instance; return instance; }
	};
}

#ifdef TOY_CORE_MODULE
extern "C"
TOY_CORE_REFL_EXPORT Module& getModule();
#endif
