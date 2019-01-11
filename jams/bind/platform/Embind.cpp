#include <platform/Api.h>
#include <emscripten/bind.h>

using namespace emscripten;

EMSCRIPTEN_BINDINGS(_platform)
{
    
    // Enums
    enum_<Faction>("Faction")
        .value("Ally", Faction::Ally)
        .value("Enemy", Faction::Enemy)
        ;
    
    // Sequences
    
    // Arrays
    
    // Structs
    value_object<Aim>("Aim")
        .field("rotation", &Aim::rotation)
        .field("start", &Aim::start)
        .field("end", &Aim::end)
        .field("hit", &Aim::hit)
        ;
    value_object<Stance>("Stance")
        .field("name", &Stance::name)
        .field("loop", &Stance::loop)
        ;
    value_object<mud::ComponentHandle<Bullet>>("ComponentHandle<Bullet>")
        ;
    value_object<mud::ComponentHandle<Crate>>("ComponentHandle<Crate>")
        ;
    value_object<mud::ComponentHandle<Human>>("ComponentHandle<Human>")
        ;
    value_object<mud::ComponentHandle<Lamp>>("ComponentHandle<Lamp>")
        ;
    
    // Classes
    class_<Bullet>("Bullet")
        .property("source", &Bullet::source)
        .property("velocity", &Bullet::velocity)
        ;
    class_<Crate>("Crate")
        .constructor<>()
        .constructor<toy::HSpatial, toy::HMovable, const mud::vec3&>()
        .property("extents", &Crate::extents)
        ;
    class_<Human>("Human")
        .constructor<>()
        .constructor<toy::HSpatial, toy::HMovable, toy::HEmitter, toy::HReceptor, toy::HEntityScript, Faction>()
        .property("faction", &Human::faction)
        .property("life", &Human::life)
        .property("energy", &Human::energy)
        .property("discharge", &Human::discharge)
        .property("headlight", &Human::headlight)
        .property("shield", &Human::shield)
        .property("walk", &Human::walk)
        .property("target", &Human::target)
        .property("dest", &Human::dest)
        .property("cooldown", &Human::cooldown)
        .property("state", &Human::state)
        .function("sight", &Human::sight)
        .function("aim", &Human::aim)
        .function("shoot", &Human::shoot)
        .function("stop", &Human::stop)
        ;
    class_<Lamp>("Lamp")
        .constructor<>()
        .constructor<toy::HSpatial, toy::HMovable>()
        ;
    class_<Player>("Player")
        ;
    class_<TileWorld>("TileWorld")
        .constructor<const std::string&, mud::JobSystem&>()
        .property("world", &TileWorld::world)
        .property("bullet_world", &TileWorld::bullet_world)
        .property("navmesh", &TileWorld::navmesh)
        ;
    
    // Functions
    
}
