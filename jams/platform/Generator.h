
#pragma once

#include <platform/Forward.h>

using namespace mud;
using namespace toy;

WaveTileset& generator_tileset(GfxSystem& gfx_system);
void generate_crates(Tileblock& block);
void generate_npcs(Tileblock& block);
void generate_lamps(Tileblock& block);

void platform_generator(GameShell& shell, VisualScript& script);
VisualScript& platform_generator(GameShell& shell);
