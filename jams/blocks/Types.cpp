#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module ._blocks;
#else
#include <blocks/Types.h>
#include <blocks/Api.h>
#include <type/Vector.h>
#endif

namespace mud
{
    // Exported types
    
    template <> _BLOCKS_EXPORT Type& type<Camp>() { static Type ty("Camp", sizeof(Camp)); return ty; }
    template <> _BLOCKS_EXPORT Type& type<Faction>() { static Type ty("Faction", sizeof(Faction)); return ty; }
    template <> _BLOCKS_EXPORT Type& type<Player>() { static Type ty("Player", sizeof(Player)); return ty; }
    template <> _BLOCKS_EXPORT Type& type<Shield>() { static Type ty("Shield", sizeof(Shield)); return ty; }
    template <> _BLOCKS_EXPORT Type& type<Slug>() { static Type ty("Slug", sizeof(Slug)); return ty; }
    template <> _BLOCKS_EXPORT Type& type<Tank>() { static Type ty("Tank", sizeof(Tank)); return ty; }
    template <> _BLOCKS_EXPORT Type& type<Well>() { static Type ty("Well", sizeof(Well)); return ty; }
    template <> _BLOCKS_EXPORT Type& type<BlockWorld>() { static Type ty("BlockWorld", type<mud::Complex>(), sizeof(BlockWorld)); return ty; }
}
