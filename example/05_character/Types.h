#pragma once

#include <05_character/Forward.h>

#if !defined TWO_MODULES || defined TWO_OBJ_LIB
#include <obj/Type.h>
#include <obj/Vector.h>
#endif

#ifndef TWO_MODULES
#include <util/Types.h>
#include <core/Types.h>
#include <visu/Types.h>
#include <edit/Types.h>
#include <block/Types.h>
#include <shell/Types.h>
#endif

#ifndef TWO_CPP_20
#include <string>
#include <cstdint>
#include <vector>
#endif


namespace mud
{
    // Exported types
    
    export_ template <> _05_CHARACTER_EXPORT Type& type<Walk>();
    export_ template <> _05_CHARACTER_EXPORT Type& type<Human>();
    
	export_ template struct _05_CHARACTER_EXPORT Typed<std::vector<Walk*>>;
	export_ template struct _05_CHARACTER_EXPORT Typed<std::vector<Human*>>;
}
