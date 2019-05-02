#include <infra/Cpp20.h>

#ifdef TWO_MODULES
module toy.visu;
#else
#include <visu/Types.h>
#include <visu/Api.h>
#include <type/Vector.h>
#endif

namespace two
{
    // Exported types
    
    
    template <> TOY_VISU_EXPORT Type& type<toy::PhysicDebugDraw>() { static Type ty("PhysicDebugDraw", sizeof(toy::PhysicDebugDraw)); return ty; }
    template <> TOY_VISU_EXPORT Type& type<toy::VisuScene>() { static Type ty("VisuScene", sizeof(toy::VisuScene)); return ty; }
}
