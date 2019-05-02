#pragma once

#if !defined TWO_MODULES || defined TWO_TYPE_LIB
#include <refl/Module.h>
#endif

#include <test/Forward.h>
//#include <test/Types.h>

#ifndef _TEST_REFL_EXPORT
#define _TEST_REFL_EXPORT TWO_IMPORT
#endif

export_ class _TEST_REFL_EXPORT _test : public two::Module
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
