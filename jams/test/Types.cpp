

#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module ._test;
#else
#include <test/Types.h>
#include <test/Api.h>
#include <type/Vector.h>
//#include <ecs/Proto.h>
#endif

namespace mud
{
    // Exported types
    
    template <> _TEST_EXPORT Type& type<Player>() { static Type ty("Player"); return ty; }
    template <> _TEST_EXPORT Type& type<Bullet>() { static Type ty("Bullet"); return ty; }
    template <> _TEST_EXPORT Type& type<Crate>() { static Type ty("Crate"); return ty; }
    template <> _TEST_EXPORT Type& type<Human>() { static Type ty("Human"); return ty; }
}
