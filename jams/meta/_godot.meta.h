#pragma once

#if !defined TWO_MODULES || defined TWO_TYPE_LIB
#include <refl/Module.h>
#endif

#include <godot/Forward.h>
//#include <godot/Types.h>

#ifndef _GODOT_REFL_EXPORT
#define _GODOT_REFL_EXPORT TWO_IMPORT
#endif

export_ class _GODOT_REFL_EXPORT _godot : public two::Module
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
