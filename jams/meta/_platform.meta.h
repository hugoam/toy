#pragma once

#if !defined TWO_MODULES || defined TWO_TYPE_LIB
#include <refl/Module.h>
#endif

#include <platform/Forward.h>
//#include <platform/Types.h>

#ifndef _PLATFORM_REFL_EXPORT
#define _PLATFORM_REFL_EXPORT TWO_IMPORT
#endif

export_ class _PLATFORM_REFL_EXPORT _platform : public two::Module
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
