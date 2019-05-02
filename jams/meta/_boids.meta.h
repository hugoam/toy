#pragma once

#if !defined TWO_MODULES || defined TWO_TYPE_LIB
#include <refl/Module.h>
#endif

#include <boids/Forward.h>
//#include <boids/Types.h>

#ifndef _BOIDS_REFL_EXPORT
#define _BOIDS_REFL_EXPORT TWO_IMPORT
#endif

export_ class _BOIDS_REFL_EXPORT _boids : public two::Module
{
private:
	_boids();
	
public:
	static _boids& m() { static _boids instance; return instance; }
};

#ifdef _BOIDS_MODULE
extern "C"
_BOIDS_REFL_EXPORT Module& getModule();
#endif
