
#pragma once

#include <core/Types.h>

#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#include <refl/Meta.h>
#include <refl/Enum.h>
#include <infra/StringConvert.h>
#endif

namespace mud
{
    export_ template <> inline void from_string(const string& str, toy::CollisionGroup& val) { val = static_cast<toy::CollisionGroup>(enu<toy::CollisionGroup>().value(str.c_str())); };
    export_ template <> inline void to_string(const toy::CollisionGroup& val, string& str) { str = enu<toy::CollisionGroup>().m_map[size_t(val)]; };
    
    
}
