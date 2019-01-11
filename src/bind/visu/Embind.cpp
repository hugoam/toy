#include <visu/Api.h>
#include <emscripten/bind.h>

using namespace emscripten;

EMSCRIPTEN_BINDINGS(toy_visu)
{
    
    // Enums
    
    // Sequences
    
    // Arrays
    
    // Structs
    
    // Classes
    class_<toy::PhysicDebugDraw>("PhysicDebugDraw")
        ;
    class_<toy::VisuScene>("VisuScene")
        .property("gfx_system", &toy::VisuScene::m_gfx_system)
        .property("scene", &toy::VisuScene::m_scene)
        .function("next_frame", &toy::VisuScene::next_frame)
        ;
    
    // Functions
    
}
