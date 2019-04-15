#pragma once

#include <toy/visu.h>
#include <mud/refl.h>
#include <mud/infra.h>


#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#endif

//#include <visu/Types.h>

#ifndef TOY_VISU_REFL_EXPORT
#define TOY_VISU_REFL_EXPORT MUD_IMPORT
#endif

namespace toy
{
	export_ class TOY_VISU_REFL_EXPORT toy_visu : public mud::Module
	{
	private:
		toy_visu();
		
	public:
		static toy_visu& m() { static toy_visu instance; return instance; }
	};
}

#ifdef TOY_VISU_MODULE
extern "C"
TOY_VISU_REFL_EXPORT Module& getModule();
#endif


#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#endif

namespace mud
{
	
}
