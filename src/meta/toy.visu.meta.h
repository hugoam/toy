#pragma once

#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#include <refl/Module.h>
#endif

#include <visu/Forward.h>
#include <visu/Types.h>

#ifndef _REFL_EXPORT
#define _REFL_EXPORT MUD_IMPORT
#endif

namespace toy
{
	export_ class _REFL_EXPORT toy_visu : public Module
	{
	private:
		toy_visu();
		
	public:
		static toy_visu& m() { static toy_visu instance; return instance; }
	};
}


extern "C"
_REFL_EXPORT Module& getModule();
#endif
