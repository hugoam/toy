

#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module toy.shell;
#else
#include <shell/Types.h>
#include <shell/Api.h>
#include <obj/Vector.h>
//#include <proto/Proto.h>
#endif

namespace mud
{
    // Exported types
    template <> TOY_SHELL_EXPORT Type& type<toy::GameMode>() { static Type ty("toy::GameMode"); return ty; }
    
    template <> TOY_SHELL_EXPORT Type& type<toy::GameShell>() { static Type ty("GameShell"); return ty; }
}
