
#pragma once

#include <space/Types.h>

#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#include <refl/Meta.h>
#include <refl/Enum.h>
#include <infra/StringConvert.h>
#endif

namespace mud
{
    export_ template <> inline void from_string(const string& str, CombatType& val) { val = static_cast<CombatType>(enu<CombatType>().value(str.c_str())); };
    export_ template <> inline void to_string(const CombatType& val, string& str) { str = enu<CombatType>().m_map[size_t(val)]; };
    
    export_ template <> inline void from_string(const string& str, Experience& val) { val = static_cast<Experience>(enu<Experience>().value(str.c_str())); };
    export_ template <> inline void to_string(const Experience& val, string& str) { str = enu<Experience>().m_map[size_t(val)]; };
    
    export_ template <> inline void from_string(const string& str, FleetSize& val) { val = static_cast<FleetSize>(enu<FleetSize>().value(str.c_str())); };
    export_ template <> inline void to_string(const FleetSize& val, string& str) { str = enu<FleetSize>().m_map[size_t(val)]; };
    
    export_ template <> inline void from_string(const string& str, FleetStance& val) { val = static_cast<FleetStance>(enu<FleetStance>().value(str.c_str())); };
    export_ template <> inline void to_string(const FleetStance& val, string& str) { str = enu<FleetStance>().m_map[size_t(val)]; };
    
    export_ template <> inline void from_string(const string& str, GameStage& val) { val = static_cast<GameStage>(enu<GameStage>().value(str.c_str())); };
    export_ template <> inline void to_string(const GameStage& val, string& str) { str = enu<GameStage>().m_map[size_t(val)]; };
    
    export_ template <> inline void from_string(const string& str, Politic& val) { val = static_cast<Politic>(enu<Politic>().value(str.c_str())); };
    export_ template <> inline void to_string(const Politic& val, string& str) { str = enu<Politic>().m_map[size_t(val)]; };
    
    export_ template <> inline void from_string(const string& str, Race& val) { val = static_cast<Race>(enu<Race>().value(str.c_str())); };
    export_ template <> inline void to_string(const Race& val, string& str) { str = enu<Race>().m_map[size_t(val)]; };
    
    export_ template <> inline void from_string(const string& str, Regime& val) { val = static_cast<Regime>(enu<Regime>().value(str.c_str())); };
    export_ template <> inline void to_string(const Regime& val, string& str) { str = enu<Regime>().m_map[size_t(val)]; };
    
    export_ template <> inline void from_string(const string& str, Resource& val) { val = static_cast<Resource>(enu<Resource>().value(str.c_str())); };
    export_ template <> inline void to_string(const Resource& val, string& str) { str = enu<Resource>().m_map[size_t(val)]; };
    
    export_ template <> inline void from_string(const string& str, Taxation& val) { val = static_cast<Taxation>(enu<Taxation>().value(str.c_str())); };
    export_ template <> inline void to_string(const Taxation& val, string& str) { str = enu<Taxation>().m_map[size_t(val)]; };
    
    export_ template <> inline void from_string(const string& str, Technology& val) { val = static_cast<Technology>(enu<Technology>().value(str.c_str())); };
    export_ template <> inline void to_string(const Technology& val, string& str) { str = enu<Technology>().m_map[size_t(val)]; };
    
    export_ template <> inline void from_string(const string& str, WeaponType& val) { val = static_cast<WeaponType>(enu<WeaponType>().value(str.c_str())); };
    export_ template <> inline void to_string(const WeaponType& val, string& str) { str = enu<WeaponType>().m_map[size_t(val)]; };
    
    
}
