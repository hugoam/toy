#pragma once

#if !defined TWO_MODULES || defined TWO_TYPE_LIB
#include <refl/Module.h>
#endif

#include <visu/Forward.h>
//#include <visu/Types.h>

#ifndef TOY_VISU_REFL_EXPORT
#define TOY_VISU_REFL_EXPORT TWO_IMPORT
#endif

namespace toy
{
	export_ class TOY_VISU_REFL_EXPORT toy_visu : public two::Module
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
