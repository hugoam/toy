

#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module ._05_character;
#else
#include <05_character/Types.h>
#include <05_character/Api.h>
#include <obj/Vector.h>
//#include <proto/Proto.h>
#endif

namespace mud
{
    // Exported types
    
    template <> _05_CHARACTER_EXPORT Type& type<Walk>() { static Type ty("Walk"); return ty; }
    template <> _05_CHARACTER_EXPORT Type& type<Human>() { static Type ty("Human", type<mud::Entity>()); return ty; }
}
