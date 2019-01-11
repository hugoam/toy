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
        .property("source", &Bullet::m_source)
        .property("velocity", &Bullet::m_velocity)
        ;
    class_<Crate>("Crate")
        .constructor<>()
        .constructor<toy::HSpatial, toy::HMovable, const mud::vec3&>()
        .property("extents", &Crate::m_extents)
        ;
    class_<Human>("Human")
        .constructor<>()
        .constructor<toy::HSpatial, toy::HMovable, toy::HEmitter, toy::HReceptor, toy::HEntityScript, Faction>()
        .property("faction", &Human::m_faction)
        .property("life", &Human::m_life)
        .property("energy", &Human::m_energy)
        .property("discharge", &Human::m_discharge)
        .property("headlight", &Human::m_headlight)
        .property("shield", &Human::m_shield)
        .property("walk", &Human::m_walk)
        .property("target", &Human::m_target)
        .property("dest", &Human::m_dest)
        .property("cooldown", &Human::m_cooldown)
        .property("state", &Human::m_state)
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
        .property("world", &TileWorld::m_world)
        .property("bullet_world", &TileWorld::m_bullet_world)
        .property("navmesh", &TileWorld::m_navmesh)
        ;
    
    // Functions
    
}
