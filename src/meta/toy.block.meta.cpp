#include <infra/Cpp20.h>

#ifdef MUD_MODULES

#else
#include <cstddef>
#include <stl/new.h>
#include <infra/ToString.h>
#include <infra/ToValue.h>
#include <type/Vector.h>
#include <refl/MetaDecl.h>
#include <refl/Module.h>
#include <meta/two.type.meta.h>
#include <meta/two.math.meta.h>
#include <meta/two.wfc.gfx.meta.h>
#include <meta/toy.core.meta.h>
#include <meta/toy.visu.meta.h>
#include <meta/toy.edit.meta.h>
#include <meta/toy.block.meta.h>
#include <meta/toy.block.conv.h>
#endif

#include <block/Api.h>

using namespace two;


namespace two
{
	void toy_block_meta(Module& m)
	{
	UNUSED(m);
	
	// Base Types
	
	// Enums
	
	// Sequences
	
	}
}

namespace toy
{
	toy_block::toy_block()
		: Module("block", { , , &two_wfc_gfx::m(), , ,  })
	{
		// setup reflection meta data
		toy_block_meta(*this);
	}
}


extern "C"
Module& getModule()
{
		return toy_block::m();
}
#endif
