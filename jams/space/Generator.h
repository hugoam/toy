
#pragma once

#include <math/Vec.h>
#include <space/Forward.h>
#include <space/ex_space.h>

#include <vector>

using namespace mud;
using namespace toy;

_SPACE_EXPORT func_ HStar generate_system(Galaxy& galaxy, const uvec3& coord, const vec3& position);
_SPACE_EXPORT func_ HFleet generate_fleet(Galaxy& galaxy, const uvec3& coord, const vec3& position);
_SPACE_EXPORT func_ Commander* generate_commander(Galaxy& galaxy, Star& star);
_SPACE_EXPORT func_ void assign_system(Galaxy& galaxy, Star& star, std::vector<Commander*> commanders);

void space_generate(HSpatial origin);
void space_generator(GameShell& shell, VisualScript& script);
VisualScript& space_generator(GameShell& shell);
