#include <shell/Api.h>
#include <emscripten/bind.h>

using namespace emscripten;

EMSCRIPTEN_BINDINGS(toy_shell)
{
    
    // Enums
    enum_<toy::GameMode>("toy::GameMode")
        .value("Play", toy::GameMode::Play)
        .value("PlayEditor", toy::GameMode::PlayEditor)
        .value("Pause", toy::GameMode::Pause)
        ;
    
    // Sequences
    
    // Arrays
    
    // Structs
    
    // Classes
    class_<toy::Game>("Game")
        .property("user", &toy::Game::m_user)
        .property("mode", &toy::Game::m_mode)
        .property("shell", &toy::Game::m_shell)
        .property("module", &toy::Game::m_module)
        .property("player", &toy::Game::m_player)
        .property("world", &toy::Game::m_world)
        .property("screen", &toy::Game::m_screen)
        ;
    class_<toy::GameModule>("GameModule")
        .function("init", &toy::GameModule::init)
        .function("start", &toy::GameModule::start)
        .function("pump", &toy::GameModule::pump)
        .function("scene", &toy::GameModule::scene)
        .function("paint", &toy::GameModule::paint)
        ;
    class_<toy::GameShell>("GameShell")
        .property("core", &toy::GameShell::core, &toy::GameShell::setCore)
        .property("lua", &toy::GameShell::lua, &toy::GameShell::setLua)
        .property("wren", &toy::GameShell::wren, &toy::GameShell::setWren)
        .property("gfx", &toy::GameShell::gfx, &toy::GameShell::setGfx)
        .property("context", &toy::GameShell::context, &toy::GameShell::setContext)
        .property("vg", &toy::GameShell::vg, &toy::GameShell::setVg)
        .property("ui_window", &toy::GameShell::ui_window, &toy::GameShell::setUi_window)
        .property("editor", &toy::GameShell::m_editor)
        .property("ui", &toy::GameShell::m_ui)
        .function("init", &toy::GameShell::init)
        .function("load", &toy::GameShell::load)
        .function("load_path", &toy::GameShell::load_path)
        .function("run", &toy::GameShell::run)
        .function("run_game", &toy::GameShell::run_game)
        .function("run_editor", &toy::GameShell::run_editor)
        .function("run_game_path", &toy::GameShell::run_game_path)
        .function("run_editor_path", &toy::GameShell::run_editor_path)
        .function("launch", &toy::GameShell::launch)
        .function("save", &toy::GameShell::save)
        .function("reload", &toy::GameShell::reload)
        .function("pump", &toy::GameShell::pump)
        .function("cleanup", &toy::GameShell::cleanup)
        .function("add_scene", &toy::GameShell::add_scene)
        .function("remove_scene", &toy::GameShell::remove_scene)
        .function("clear_scenes", &toy::GameShell::clear_scenes)
        ;
    class_<toy::GameModuleBind>("GameModuleBind")
        .constructor<mud::Module&, const mud::VirtualMethod&>()
        ;
    class_<toy::GameScene>("GameScene")
        ;
    
    // Functions
    function("paint_physics", &toy::paint_physics);
    function("physic_painter", &toy::physic_painter);
    
}
