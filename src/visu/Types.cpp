

#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module toy.visu;
#else
#include <visu/Types.h>
#include <visu/Api.h>
#include <obj/Vector.h>
//#include <proto/Proto.h>
#endif

namespace mud
{
    // Exported types
    
    template <> TOY_VISU_EXPORT Type& type<toy::PhysicDebugDraw>() { static Type ty("PhysicDebugDraw"); return ty; }
    template <> TOY_VISU_EXPORT Type& type<toy::SoundSource>() { static Type ty("SoundSource"); return ty; }
    template <> TOY_VISU_EXPORT Type& type<toy::VisuScene>() { static Type ty("VisuScene"); return ty; }
}
