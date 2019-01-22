#pragma once

#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#include <refl/Module.h>
#endif

#include <minimal/Forward.h>
#include <minimal/Types.h>

#ifndef _MINIMAL_REFL_EXPORT
#define _MINIMAL_REFL_EXPORT MUD_IMPORT
#endif

export_ class _MINIMAL_REFL_EXPORT _minimal : public Module
{
private:
	_minimal();
	
public:
	static _minimal& m() { static _minimal instance; return instance; }
};

#ifdef _MINIMAL_MODULE
extern "C"
_MINIMAL_REFL_EXPORT Module& getModule();
#endif
