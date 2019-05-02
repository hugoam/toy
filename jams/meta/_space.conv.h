#pragma once

#include <space/Types.h>

#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#include <refl/Meta.h>
#include <refl/Enum.h>
#include <infra/StringOps.h>
#endif

namespace two
{
	export_ template <> inline void to_value(const string& str, GameStage& val) { val = GameStage(enu<GameStage>().value(str.c_str())); };
	export_ template <> inline void to_string(const GameStage& val, string& str) { str = enu<GameStage>().name(uint32_t(val)); };
	
	export_ template <> inline void to_value(const string& str, Race& val) { val = Race(enu<Race>().value(str.c_str())); };
	export_ template <> inline void to_string(const Race& val, string& str) { str = enu<Race>().name(uint32_t(val)); };
	
	export_ template <> inline void to_value(const string& str, Regime& val) { val = Regime(enu<Regime>().value(str.c_str())); };
	export_ template <> inline void to_string(const Regime& val, string& str) { str = enu<Regime>().name(uint32_t(val)); };
	
	export_ template <> inline void to_value(const string& str, Politic& val) { val = Politic(enu<Politic>().value(str.c_str())); };
	export_ template <> inline void to_string(const Politic& val, string& str) { str = enu<Politic>().name(uint32_t(val)); };
	
	export_ template <> inline void to_value(const string& str, Taxation& val) { val = Taxation(enu<Taxation>().value(str.c_str())); };
	export_ template <> inline void to_string(const Taxation& val, string& str) { str = enu<Taxation>().name(uint32_t(val)); };
	
	export_ template <> inline void to_value(const string& str, Resource& val) { val = Resource(enu<Resource>().value(str.c_str())); };
	export_ template <> inline void to_string(const Resource& val, string& str) { str = enu<Resource>().name(uint32_t(val)); };
	
	export_ template <> inline void to_value(const string& str, FleetSize& val) { val = FleetSize(enu<FleetSize>().value(str.c_str())); };
	export_ template <> inline void to_string(const FleetSize& val, string& str) { str = enu<FleetSize>().name(uint32_t(val)); };
	
	export_ template <> inline void to_value(const string& str, Experience& val) { val = Experience(enu<Experience>().value(str.c_str())); };
	export_ template <> inline void to_string(const Experience& val, string& str) { str = enu<Experience>().name(uint32_t(val)); };
	
	export_ template <> inline void to_value(const string& str, FleetStance& val) { val = FleetStance(enu<FleetStance>().value(str.c_str())); };
	export_ template <> inline void to_string(const FleetStance& val, string& str) { str = enu<FleetStance>().name(uint32_t(val)); };
	
	export_ template <> inline void to_value(const string& str, WeaponType& val) { val = WeaponType(enu<WeaponType>().value(str.c_str())); };
	export_ template <> inline void to_string(const WeaponType& val, string& str) { str = enu<WeaponType>().name(uint32_t(val)); };
	
	export_ template <> inline void to_value(const string& str, Technology& val) { val = Technology(enu<Technology>().value(str.c_str())); };
	export_ template <> inline void to_string(const Technology& val, string& str) { str = enu<Technology>().name(uint32_t(val)); };
	
	export_ template <> inline void to_value(const string& str, CombatType& val) { val = CombatType(enu<CombatType>().value(str.c_str())); };
	export_ template <> inline void to_string(const CombatType& val, string& str) { str = enu<CombatType>().name(uint32_t(val)); };
	
	
}
