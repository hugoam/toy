

#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module ._blocks;
#else
#include <blocks/Types.h>
#include <blocks/Api.h>
#include <obj/Vector.h>
//#include <proto/Proto.h>
#endif

namespace mud
{
    // Exported types
    template <> _BLOCKS_EXPORT Type& type<CustomCollisionGroup>() { static Type ty("CustomCollisionGroup"); return ty; }
    
    template <> _BLOCKS_EXPORT Type& type<Faction>() { static Type ty("Faction"); return ty; }
    template <> _BLOCKS_EXPORT Type& type<Player>() { static Type ty("Player"); return ty; }
    template <> _BLOCKS_EXPORT Type& type<BlockWorld>() { static Type ty("BlockWorld", type<mud::Complex>()); return ty; }
    template <> _BLOCKS_EXPORT Type& type<Camp>() { static Type ty("Camp", type<mud::Complex>()); return ty; }
    template <> _BLOCKS_EXPORT Type& type<Shield>() { static Type ty("Shield", type<mud::Complex>()); return ty; }
    template <> _BLOCKS_EXPORT Type& type<Slug>() { static Type ty("Slug", type<mud::Complex>()); return ty; }
    template <> _BLOCKS_EXPORT Type& type<Tank>() { static Type ty("Tank", type<mud::Complex>()); return ty; }
    template <> _BLOCKS_EXPORT Type& type<Well>() { static Type ty("Well", type<mud::Complex>()); return ty; }
}
