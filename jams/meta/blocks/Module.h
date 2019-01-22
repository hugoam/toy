#pragma once

#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#include <refl/Module.h>
#endif

#include <blocks/Forward.h>
#include <blocks/Types.h>

#ifndef _BLOCKS_REFL_EXPORT
#define _BLOCKS_REFL_EXPORT MUD_IMPORT
#endif

export_ class _BLOCKS_REFL_EXPORT _blocks : public Module
{
private:
	_blocks();
	
public:
	static _blocks& m() { static _blocks instance; return instance; }
};

#ifdef _BLOCKS_MODULE
extern "C"
_BLOCKS_REFL_EXPORT Module& getModule();
#endif
