#pragma once

#include <toy/shell.h>
#include <mud/refl.h>
#include <mud/infra.h>


#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#endif

namespace mud
{
	export_ template <> inline void to_value(const string& str, toy::GameMode& val) { val = toy::GameMode(enu<toy::GameMode>().value(str.c_str())); };
	export_ template <> inline void to_string(const toy::GameMode& val, string& str) { str = enu<toy::GameMode>().name(uint32_t(val)); };
	
	
}

#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#endif


#ifndef TOY_SHELL_REFL_EXPORT
#define TOY_SHELL_REFL_EXPORT MUD_IMPORT
#endif

namespace toy
{
	export_ class TOY_SHELL_REFL_EXPORT toy_shell : public Module
	{
	private:
		toy_shell();
		
	public:
		static toy_shell& m() { static toy_shell instance; return instance; }
	};
}

#ifdef TOY_SHELL_MODULE
extern "C"
TOY_SHELL_REFL_EXPORT Module& getModule();
#endif

