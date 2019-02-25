#pragma once

#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#include <refl/Module.h>
#endif

#include <godot/Forward.h>
//#include <godot/Types.h>

#ifndef _GODOT_REFL_EXPORT
#define _GODOT_REFL_EXPORT MUD_IMPORT
#endif

export_ class _GODOT_REFL_EXPORT _godot : public mud::Module
{
private:
	_godot();
	
public:
	static _godot& m() { static _godot instance; return instance; }
};

#ifdef _GODOT_MODULE
extern "C"
_GODOT_REFL_EXPORT Module& getModule();
#endif
