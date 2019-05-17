#pragma once

#include <infra/Config.h>

#include <type/Forward.h>
#include <gfx/Forward.h>
#include <tool/Forward.h>
#include <util/Forward.h>
#include <core/Forward.h>

#ifndef TOY_VISU_EXPORT
#define TOY_VISU_EXPORT TWO_IMPORT
#endif

namespace toy
{
    struct VisuPainter;
    class PhysicDebugDraw;
    class VisuScene;
    class SoundSource;
}
