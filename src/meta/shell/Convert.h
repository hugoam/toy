
#pragma once

#include <shell/Types.h>

#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#include <refl/Meta.h>
#include <refl/Enum.h>
#include <infra/StringConvert.h>
#endif

namespace mud
{
    export_ template <> inline void from_string(const string& str, toy::GameMode& val) { val = static_cast<toy::GameMode>(enu<toy::GameMode>().value(str.c_str())); };
    export_ template <> inline void to_string(const toy::GameMode& val, string& str) { str = enu<toy::GameMode>().m_map[size_t(val)]; };
    
    
}
