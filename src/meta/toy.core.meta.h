#pragma once

#if !defined TWO_MODULES || defined TWO_TYPE_LIB
#include <refl/Module.h>
#endif

#include <core/Forward.h>
#include <core/Types.h>

#ifndef _REFL_EXPORT
#define _REFL_EXPORT TWO_IMPORT
#endif

namespace toy
{
	export_ class _REFL_EXPORT toy_core : public Module
	{
	private:
		toy_core();
		
	public:
		static toy_core& m() { static toy_core instance; return instance; }
	};
}


extern "C"
_REFL_EXPORT Module& getModule();
#endif
