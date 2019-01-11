#include <edit/Api.h>
#include <emscripten/bind.h>

using namespace emscripten;

EMSCRIPTEN_BINDINGS(toy_edit)
{
    
    // Enums
    
    // Sequences
    
    // Arrays
    
    // Structs
    value_object<toy::ActionGroup>("ActionGroup")
        ;
    value_object<toy::GraphicsDebug>("GraphicsDebug")
        ;
    
    // Classes
    class_<toy::Clone>("Clone")
        ;
    class_<toy::Cut>("Cut")
        ;
    class_<toy::Edit>("Edit")
        ;
    class_<toy::Paste>("Paste")
        ;
    class_<toy::Toolbelt>("Toolbelt")
        ;
    class_<toy::Toolbox>("Toolbox")
        ;
    class_<toy::DynamicToolbox>("DynamicToolbox")
        ;
    class_<toy::Editor>("Editor")
        .property("run_tool", &toy::Editor::m_run_tool)
        .property("play_tool", &toy::Editor::m_play_tool)
        .property("frame_view_tool", &toy::Editor::m_frame_view_tool)
        .property("edited_world", &toy::Editor::m_edited_world)
        .property("run_game", &toy::Editor::m_run_game)
        .property("play_game", &toy::Editor::m_play_game)
        ;
    class_<toy::PlayTool>("PlayTool")
        ;
    class_<toy::RunTool>("RunTool")
        ;
    
    // Functions
    
}
