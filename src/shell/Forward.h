#pragma once

#include <infra/Config.h>

#include <core/Forward.h>
#include <visu/Forward.h>
#include <edit/Forward.h>
#include <block/Forward.h>
#include <ecs/Forward.h>
#include <tree/Forward.h>
#include <srlz/Forward.h>
#include <math/Forward.h>
#include <geom/Forward.h>
#include <lang/Forward.h>
#include <ctx/Forward.h>
#include <ui/Forward.h>
#include <uio/Forward.h>
#include <ctx-glfw/Forward.h>
#include <ui-vg/Forward.h>
#include <bgfx/Forward.h>
#include <gfx/Forward.h>
#include <gfx-pbr/Forward.h>
#include <gfx-obj/Forward.h>
#include <gfx-gltf/Forward.h>
#include <gfx-ui/Forward.h>
#include <tool/Forward.h>
#include <wfc-gfx/Forward.h>

#ifndef TOY_SHELL_EXPORT
#define TOY_SHELL_EXPORT TWO_IMPORT
#endif

namespace toy
{
    enum class GameMode : int;
    
    
    class GameScene;
    class Game;
    class GameModule;
    class GameModuleBind;
    class GameShell;
	class GameWindow;
}
