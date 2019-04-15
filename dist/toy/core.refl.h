#pragma once

#include <toy/core.h>
#include <mud/refl.h>
#include <mud/infra.h>


#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#endif

//#include <core/Types.h>

#ifndef TOY_CORE_REFL_EXPORT
#define TOY_CORE_REFL_EXPORT MUD_IMPORT
#endif

namespace toy
{
	export_ class TOY_CORE_REFL_EXPORT toy_core : public mud::Module
	{
	private:
		toy_core();
		
	public:
		static toy_core& m() { static toy_core instance; return instance; }
	};
}

#ifdef TOY_CORE_MODULE
extern "C"
TOY_CORE_REFL_EXPORT Module& getModule();
#endif


#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#endif

namespace mud
{
	export_ template <> inline void to_value(const string& str, toy::CollisionGroup& val) { val = toy::CollisionGroup(enu<toy::CollisionGroup>().value(str.c_str())); };
	export_ template <> inline void to_string(const toy::CollisionGroup& val, string& str) { str = enu<toy::CollisionGroup>().name(uint32_t(val)); };
	
	
}
