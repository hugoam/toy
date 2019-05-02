
#pragma once

#include <blocks/Forward.h>

using namespace two;
using namespace toy;

void block_grid(BlockWorld& world, const uvec3& grid_subdiv, const uvec3& block_subdiv, const vec3& cell_size);

WaveTileset& generator_tileset(GfxSystem& gfx);

void block_generator(GameShell& shell, VisualScript& script);
VisualScript& block_generator(GameShell& shell);

void generate_camps(BlockWorld& world);
