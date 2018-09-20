
#pragma once

#include <math/Vec.h>
#include <space/Forward.h>

#include <vector>

using namespace mud;
using namespace toy;

_SPACE_EXPORT func_ Star* generate_system(HSpatial galaxy, const uvec3& coord, const vec3& position);
_SPACE_EXPORT func_ Fleet* generate_fleet(HSpatial galaxy, const uvec3& coord, const vec3& position);
_SPACE_EXPORT func_ Commander* generate_commander(HSpatial galaxy, Star& star);
_SPACE_EXPORT func_ Star* assign_system(HSpatial galaxy, Star& star, std::vector<Commander*> commanders);

void space_generate(HSpatial origin);
void space_generator(GameShell& shell, VisualScript& script);
VisualScript& space_generator(GameShell& shell);
