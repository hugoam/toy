#pragma once

#include <core/Types.h>

#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#include <refl/Meta.h>
#include <refl/Enum.h>
#include <infra/StringOps.h>
#endif

namespace two
{
	export_ template <> inline void to_value(const string& str, toy::CollisionGroup& val) { val = toy::CollisionGroup(enu<toy::CollisionGroup>().value(str.c_str())); };
	export_ template <> inline void to_string(const toy::CollisionGroup& val, string& str) { str = enu<toy::CollisionGroup>().name(uint32_t(val)); };
	
	
}
