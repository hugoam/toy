#pragma once

#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#include <refl/Module.h>
#endif

#include <shell/Forward.h>
#include <shell/Types.h>

#ifndef _REFL_EXPORT
#define _REFL_EXPORT MUD_IMPORT
#endif

namespace toy
{
	export_ class _REFL_EXPORT toy_shell : public Module
	{
	private:
		toy_shell();
		
	public:
		static toy_shell& m() { static toy_shell instance; return instance; }
	};
}


extern "C"
_REFL_EXPORT Module& getModule();
#endif
