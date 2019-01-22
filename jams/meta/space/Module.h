#pragma once

#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#include <refl/Module.h>
#endif

#include <space/Forward.h>
#include <space/Types.h>

#ifndef _SPACE_REFL_EXPORT
#define _SPACE_REFL_EXPORT MUD_IMPORT
#endif

export_ class _SPACE_REFL_EXPORT _space : public Module
{
private:
	_space();
	
public:
	static _space& m() { static _space instance; return instance; }
};

#ifdef _SPACE_MODULE
extern "C"
_SPACE_REFL_EXPORT Module& getModule();
#endif
