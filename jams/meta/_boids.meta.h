#pragma once

#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#include <refl/Module.h>
#endif

#include <boids/Forward.h>
//#include <boids/Types.h>

#ifndef _BOIDS_REFL_EXPORT
#define _BOIDS_REFL_EXPORT MUD_IMPORT
#endif

export_ class _BOIDS_REFL_EXPORT _boids : public mud::Module
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
