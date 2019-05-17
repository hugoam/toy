#pragma once

#include <toy/edit.h>
#include <two/refl.h>
#include <two/infra.h>


#if !defined TWO_MODULES || defined TWO_TYPE_LIB
#endif

//#include <edit/Types.h>

#ifndef TOY_EDIT_REFL_EXPORT
#define TOY_EDIT_REFL_EXPORT TWO_IMPORT
#endif

namespace toy
{
	export_ class TOY_EDIT_REFL_EXPORT toy_edit : public two::Module
	{
	private:
		toy_edit();
		
	public:
		static toy_edit& m() { static toy_edit instance; return instance; }
	};
}

#ifdef TOY_EDIT_MODULE
extern "C"
TOY_EDIT_REFL_EXPORT Module& getModule();
#endif


#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#endif

namespace two
{
	
}
