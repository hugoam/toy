#pragma once

#include <godot/Types.h>

#if !defined TWO_MODULES || defined TWO_TYPE_LIB
#include <refl/Meta.h>
#include <refl/Enum.h>
#include <infra/StringOps.h>
#endif

namespace two
{
	export_ template <> inline void to_value(const string& str, Faction& val) { val = Faction(enu<Faction>().value(str.c_str())); };
	export_ template <> inline void to_string(const Faction& val, string& str) { str = enu<Faction>().name(uint32_t(val)); };
	
	
}
