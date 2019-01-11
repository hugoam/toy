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
        .property("position", &Camp::position)
        .property("faction", &Camp::faction)
        ;
    class_<Faction>("Faction")
        .constructor<uint32_t, const mud::Colour&>()
        .property("id", &Faction::id)
        .property("colour", &Faction::colour)
        ;
    class_<Player>("Player")
        ;
    class_<Shield>("Shield")
        .constructor<>()
        .constructor<toy::HSpatial, toy::HEmitter, Faction&, float>()
        .property("faction", &Shield::faction)
        .property("radius", &Shield::radius)
        .property("charge", &Shield::charge)
        .property("discharge", &Shield::discharge)
        ;
    class_<Slug>("Slug")
        .property("source", &Slug::source)
        .property("velocity", &Slug::velocity)
        .property("power", &Slug::power)
        ;
    class_<Tank>("Tank")
        .constructor<>()
        .constructor<toy::HSpatial, toy::HMovable, toy::HEmitter, toy::HReceptor, Faction&>()
        ;
    class_<BlockWorld>("BlockWorld")
        .constructor<const std::string&, mud::JobSystem&>()
        .property("world", &BlockWorld::world)
        .property("bullet_world", &BlockWorld::bullet_world)
        .property("navmesh", &BlockWorld::navmesh)
        .property("block_subdiv", &BlockWorld::block_subdiv)
        .property("tile_scale", &BlockWorld::tile_scale)
        .property("block_size", &BlockWorld::block_size)
        .property("world_size", &BlockWorld::world_size)
        ;
    
    // Functions
    
}
