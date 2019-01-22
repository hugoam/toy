#pragma once

#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#include <refl/Module.h>
#endif

#include <platform/Forward.h>
#include <platform/Types.h>

#ifndef _PLATFORM_REFL_EXPORT
#define _PLATFORM_REFL_EXPORT MUD_IMPORT
#endif

export_ class _PLATFORM_REFL_EXPORT _platform : public Module
{
private:
	_platform();
	
public:
	static _platform& m() { static _platform instance; return instance; }
};

#ifdef _PLATFORM_MODULE
extern "C"
_PLATFORM_REFL_EXPORT Module& getModule();
#endif
