#pragma once

#include <toy/util.h>
#include <two/refl.h>
#include <two/infra.h>


#if !defined TWO_MODULES || defined TWO_TYPE_LIB
#endif

//#include <util/Types.h>

#ifndef TOY_UTIL_REFL_EXPORT
#define TOY_UTIL_REFL_EXPORT TWO_IMPORT
#endif

namespace toy
{
	export_ class TOY_UTIL_REFL_EXPORT toy_util : public two::Module
	{
	private:
		toy_util();
		
	public:
		static toy_util& m() { static toy_util instance; return instance; }
	};
}

#ifdef TOY_UTIL_MODULE
extern "C"
TOY_UTIL_REFL_EXPORT Module& getModule();
#endif


#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#endif

namespace two
{
	
}
