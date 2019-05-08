#pragma once

#include <two/refl.h>
#include <toy/block.h>
#include <two/infra.h>


#if !defined TWO_MODULES || defined TWO_TYPE_LIB
#endif

//#include <block/Types.h>

#ifndef TOY_BLOCK_REFL_EXPORT
#define TOY_BLOCK_REFL_EXPORT TWO_IMPORT
#endif

namespace toy
{
	export_ class TOY_BLOCK_REFL_EXPORT toy_block : public two::Module
	{
	private:
		toy_block();
		
	public:
		static toy_block& m() { static toy_block instance; return instance; }
	};
}

#ifdef TOY_BLOCK_MODULE
extern "C"
TOY_BLOCK_REFL_EXPORT Module& getModule();
#endif


#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#endif

namespace two
{
	export_ template <> inline void to_value(const string& str, toy::MatterState& val) { val = toy::MatterState(enu<toy::MatterState>().value(str.c_str())); };
	export_ template <> inline void to_string(const toy::MatterState& val, string& str) { str = enu<toy::MatterState>().name(uint32_t(val)); };
	
	
}
