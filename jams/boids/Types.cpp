

#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module ._boids;
#else
#include <boids/Types.h>
#include <boids/Api.h>
#include <obj/Vector.h>
//#include <proto/Proto.h>
#endif

namespace mud
{
    // Exported types
    
    template <> _BOIDS_EXPORT Type& type<boids::Player>() { static Type ty("Player"); return ty; }
}
