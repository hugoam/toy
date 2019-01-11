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
    template <> _BLOCKS_EXPORT Type& type<BlockWorld>() { static Type ty("BlockWorld", type<mud::Complex>(), sizeof(BlockWorld)); return ty; }
    template <> _BLOCKS_EXPORT Type& type<mud::ComponentHandle<Camp>>() { static Type ty("ComponentHandle<Camp>", type<mud::Entity>(), sizeof(mud::ComponentHandle<Camp>)); return ty; }
    template <> _BLOCKS_EXPORT Type& type<mud::ComponentHandle<Shield>>() { static Type ty("ComponentHandle<Shield>", type<mud::Entity>(), sizeof(mud::ComponentHandle<Shield>)); return ty; }
    template <> _BLOCKS_EXPORT Type& type<mud::ComponentHandle<Slug>>() { static Type ty("ComponentHandle<Slug>", type<mud::Entity>(), sizeof(mud::ComponentHandle<Slug>)); return ty; }
    template <> _BLOCKS_EXPORT Type& type<mud::ComponentHandle<Tank>>() { static Type ty("ComponentHandle<Tank>", type<mud::Entity>(), sizeof(mud::ComponentHandle<Tank>)); return ty; }
}
