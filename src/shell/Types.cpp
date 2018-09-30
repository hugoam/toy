

#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module toy.shell;
#else
#include <shell/Types.h>
#include <shell/Api.h>
#include <type/Vector.h>
//#include <ecs/Proto.h>
#endif

namespace mud
{
    // Exported types
    template <> TOY_SHELL_EXPORT Type& type<toy::GameMode>() { static Type ty("toy::GameMode"); return ty; }
    
    template <> TOY_SHELL_EXPORT Type& type<toy::Game>() { static Type ty("Game"); return ty; }
    template <> TOY_SHELL_EXPORT Type& type<toy::GameModule>() { static Type ty("GameModule"); return ty; }
    template <> TOY_SHELL_EXPORT Type& type<toy::GameShell>() { static Type ty("GameShell"); return ty; }
    template <> TOY_SHELL_EXPORT Type& type<toy::GameScene>() { static Type ty("GameScene", type<toy::VisuScene>()); return ty; }
    template <> TOY_SHELL_EXPORT Type& type<toy::GameModuleBind>() { static Type ty("GameModuleBind", type<toy::GameModule>()); return ty; }
}
