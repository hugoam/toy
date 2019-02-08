#pragma once

#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#include <refl/Module.h>
#endif

#include <block/Forward.h>
#include <block/Types.h>

#ifndef _REFL_EXPORT
#define _REFL_EXPORT MUD_IMPORT
#endif

namespace toy
{
	export_ class _REFL_EXPORT toy_block : public Module
	{
	private:
		toy_block();
		
	public:
		static toy_block& m() { static toy_block instance; return instance; }
	};
}


extern "C"
_REFL_EXPORT Module& getModule();
#endif
