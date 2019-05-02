#pragma once

#include <shell/Types.h>

#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#include <refl/Meta.h>
#include <refl/Enum.h>
#include <infra/StringOps.h>
#endif

namespace two
{
	export_ template <> inline void to_value(const string& str, toy::GameMode& val) { val = toy::GameMode(enu<toy::GameMode>().value(str.c_str())); };
	export_ template <> inline void to_string(const toy::GameMode& val, string& str) { str = enu<toy::GameMode>().name(uint32_t(val)); };
	
	
}
