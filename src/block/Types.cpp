

#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module toy.block;
#else
#include <block/Types.h>
#include <block/Api.h>
#include <type/Vector.h>
//#include <ecs/Proto.h>
#endif

namespace mud
{
    // Exported types
    template <> TOY_BLOCK_EXPORT Type& type<toy::MatterState>() { static Type ty("toy::MatterState"); return ty; }
    
    template <> TOY_BLOCK_EXPORT Type& type<toy::Element>() { static Type ty("Element"); return ty; }
    template <> TOY_BLOCK_EXPORT Type& type<mud::Grid<toy::Block*>>() { static Type ty("Grid<toy::Block*>"); return ty; }
    template <> TOY_BLOCK_EXPORT Type& type<toy::Block>() { static Type ty("Block"); return ty; }
    template <> TOY_BLOCK_EXPORT Type& type<toy::Chunk>() { static Type ty("Chunk"); return ty; }
    template <> TOY_BLOCK_EXPORT Type& type<toy::Heap>() { static Type ty("Heap"); return ty; }
    template <> TOY_BLOCK_EXPORT Type& type<toy::Sector>() { static Type ty("Sector"); return ty; }
    template <> TOY_BLOCK_EXPORT Type& type<toy::Tileblock>() { static Type ty("Tileblock"); return ty; }
    template <> TOY_BLOCK_EXPORT Type& type<toy::Earth>() { static Type ty("Earth", type<toy::Element>()); return ty; }
}
