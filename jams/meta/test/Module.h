#pragma once

#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#include <refl/Module.h>
#endif

#include <test/Forward.h>
#include <test/Types.h>

#ifndef _TEST_REFL_EXPORT
#define _TEST_REFL_EXPORT MUD_IMPORT
#endif

export_ class _TEST_REFL_EXPORT _test : public Module
{
private:
	_test();
	
public:
	static _test& m() { static _test instance; return instance; }
};

#ifdef _TEST_MODULE
extern "C"
_TEST_REFL_EXPORT Module& getModule();
#endif
