#pragma once

#include <block/Types.h>

#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#include <refl/Meta.h>
#include <refl/Enum.h>
#include <infra/StringOps.h>
#endif

namespace two
{
	export_ template <> inline void to_value(const string& str, toy::MatterState& val) { val = toy::MatterState(enu<toy::MatterState>().value(str.c_str())); };
	export_ template <> inline void to_string(const toy::MatterState& val, string& str) { str = enu<toy::MatterState>().name(uint32_t(val)); };
	
	
}
