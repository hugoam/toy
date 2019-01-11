#include <minimal/Api.h>
#include <emscripten/bind.h>

using namespace emscripten;

EMSCRIPTEN_BINDINGS(_minimal)
{
    
    // Enums
    
    // Sequences
    
    // Arrays
    
    // Structs
    value_object<mud::ComponentHandle<Bullet>>("ComponentHandle<Bullet>")
        ;
    value_object<mud::ComponentHandle<Crate>>("ComponentHandle<Crate>")
        ;
    value_object<mud::ComponentHandle<Human>>("ComponentHandle<Human>")
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
        .constructor<toy::HSpatial, toy::HMovable>()
        ;
    class_<Player>("Player")
        ;
    
    // Functions
    
}
