#include <blocks/Api.h>
#include <emscripten/bind.h>

using namespace emscripten;

EMSCRIPTEN_BINDINGS(_blocks)
{
    
    // Enums
    
    // Sequences
    
    // Arrays
    
    // Structs
    value_object<mud::ComponentHandle<Camp>>("ComponentHandle<Camp>")
        ;
    value_object<mud::ComponentHandle<Shield>>("ComponentHandle<Shield>")
        ;
    value_object<mud::ComponentHandle<Slug>>("ComponentHandle<Slug>")
        ;
    value_object<mud::ComponentHandle<Tank>>("ComponentHandle<Tank>")
        ;
    
    // Classes
    class_<Camp>("Camp")
        .constructor<>()
        .constructor<toy::HSpatial, const mud::vec3&, Faction&>()
        .property("position", &Camp::m_position)
        .property("faction", &Camp::m_faction)
        ;
    class_<Faction>("Faction")
        .constructor<uint32_t, const mud::Colour&>()
        .property("id", &Faction::m_id)
        .property("colour", &Faction::m_colour)
        ;
    class_<Player>("Player")
        ;
    class_<Shield>("Shield")
        .constructor<>()
        .constructor<toy::HSpatial, toy::HEmitter, Faction&, float>()
        .property("faction", &Shield::m_faction)
        .property("radius", &Shield::m_radius)
        .property("charge", &Shield::m_charge)
        .property("discharge", &Shield::m_discharge)
        ;
    class_<Slug>("Slug")
        .property("source", &Slug::m_source)
        .property("velocity", &Slug::m_velocity)
        .property("power", &Slug::m_power)
        ;
    class_<Tank>("Tank")
        .constructor<>()
        .constructor<toy::HSpatial, toy::HMovable, toy::HEmitter, toy::HReceptor, Faction&>()
        ;
    class_<BlockWorld>("BlockWorld")
        .constructor<const std::string&, mud::JobSystem&>()
        .property("world", &BlockWorld::m_world)
        .property("bullet_world", &BlockWorld::m_bullet_world)
        .property("navmesh", &BlockWorld::m_navmesh)
        .property("block_subdiv", &BlockWorld::m_block_subdiv)
        .property("tile_scale", &BlockWorld::m_tile_scale)
        .property("block_size", &BlockWorld::m_block_size)
        .property("world_size", &BlockWorld::m_world_size)
        ;
    
    // Functions
    
}
