
#pragma once

#include <block/Types.h>

#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#include <refl/Meta.h>
#include <refl/Enum.h>
#include <infra/StringConvert.h>
#endif

namespace mud
{
    export_ template <> inline void from_string(const string& str, toy::MatterState& val) { val = static_cast<toy::MatterState>(enu<toy::MatterState>().value(str.c_str())); };
    export_ template <> inline void to_string(const toy::MatterState& val, string& str) { str = enu<toy::MatterState>().m_map[size_t(val)]; };
    
    
}
