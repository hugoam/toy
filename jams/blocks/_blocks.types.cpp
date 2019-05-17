#include <infra/Cpp20.h>

#ifdef TWO_MODULES
module ._blocks;
#else
#include <blocks/Types.h>
#include <blocks/Api.h>
#include <type/Vector.h>
#endif

namespace two
{
    // Exported types
    
    
    template <> _BLOCKS_EXPORT Type& type<two::ComponentHandle<Camp>>() { static Type ty("ComponentHandle<Camp>", sizeof(two::ComponentHandle<Camp>)); return ty; }
    template <> _BLOCKS_EXPORT Type& type<two::ComponentHandle<Shield>>() { static Type ty("ComponentHandle<Shield>", sizeof(two::ComponentHandle<Shield>)); return ty; }
    template <> _BLOCKS_EXPORT Type& type<two::ComponentHandle<Slug>>() { static Type ty("ComponentHandle<Slug>", sizeof(two::ComponentHandle<Slug>)); return ty; }
    template <> _BLOCKS_EXPORT Type& type<two::ComponentHandle<Tank>>() { static Type ty("ComponentHandle<Tank>", sizeof(two::ComponentHandle<Tank>)); return ty; }
    template <> _BLOCKS_EXPORT Type& type<Faction>() { static Type ty("Faction", sizeof(Faction)); return ty; }
    template <> _BLOCKS_EXPORT Type& type<Camp>() { static Type ty("Camp", sizeof(Camp)); return ty; }
    template <> _BLOCKS_EXPORT Type& type<Shield>() { static Type ty("Shield", sizeof(Shield)); return ty; }
    template <> _BLOCKS_EXPORT Type& type<Slug>() { static Type ty("Slug", sizeof(Slug)); return ty; }
    template <> _BLOCKS_EXPORT Type& type<Tank>() { static Type ty("Tank", sizeof(Tank)); return ty; }
    template <> _BLOCKS_EXPORT Type& type<BlockWorld>() { static Type ty("BlockWorld", type<two::Complex>(), sizeof(BlockWorld)); return ty; }
    template <> _BLOCKS_EXPORT Type& type<Player>() { static Type ty("Player", sizeof(Player)); return ty; }
}
