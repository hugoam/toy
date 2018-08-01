
#pragma once

#include <math/Vec.h>
#include <space/Forward.h>

#include <vector>

using namespace mud;
using namespace toy;

_SPACE_EXPORT func_ Star* generate_system(Entity& origin, const uvec3& coord, const vec3& position);
_SPACE_EXPORT func_ Fleet* generate_fleet(Entity& origin, const uvec3& coord, const vec3& position);
_SPACE_EXPORT func_ Commander* generate_commander(Entity& origin, Star& star);
_SPACE_EXPORT func_ Star* assign_system(Entity& origin, Star& star, std::vector<Commander*> commanders);

void space_generator(GameShell& shell, VisualScript& script);
VisualScript& space_generator(GameShell& shell);
