#include <boids/Api.h>
#include <emscripten/bind.h>

using namespace emscripten;

EMSCRIPTEN_BINDINGS(_boids)
{
    
    // Enums
    
    // Sequences
    
    // Arrays
    
    // Structs
    value_object<boids::Boid>("Boid")
        ;
    value_object<boids::BoidObstacle>("BoidObstacle")
        ;
    value_object<boids::BoidTarget>("BoidTarget")
        ;
    value_object<boids::Heading>("Heading")
        ;
    value_object<boids::MoveForward>("MoveForward")
        ;
    value_object<boids::MoveSpeed>("MoveSpeed")
        ;
    value_object<boids::Position>("Position")
        ;
    value_object<boids::Rotation>("Rotation")
        ;
    value_object<boids::Transform4>("Transform4")
        ;
    
    // Classes
    class_<boids::Player>("Player")
        ;
    
    // Functions
    
}
