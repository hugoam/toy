#pragma once

#include <stdint.h>
#include <stl/string.h>
#include <stl/vector.h>
#include <boids/Forward.h>

#if !defined TWO_MODULES || defined TWO_TYPE_LIB
#include <type/Type.h>
#endif

#ifndef TWO_MODULES
#include <infra/Types.h>
#include <jobs/Types.h>
#include <type/Types.h>
#include <tree/Types.h>
#include <pool/Types.h>
#include <refl/Types.h>
#include <ecs/Types.h>
#include <srlz/Types.h>
#include <math/Types.h>
#include <geom/Types.h>
#include <lang/Types.h>
#include <ctx/Types.h>
#include <ui/Types.h>
#include <uio/Types.h>
#include <bgfx/Types.h>
#include <gfx/Types.h>
#include <gfx-ui/Types.h>
#include <frame/Types.h>
#include <util/Types.h>
#include <core/Types.h>
#include <visu/Types.h>
#include <edit/Types.h>
#include <block/Types.h>
#include <shell/Types.h>
#endif


namespace two
{
    // Exported types
    
    
    export_ template <> _BOIDS_EXPORT Type& type<boids::Position>();
    export_ template <> _BOIDS_EXPORT Type& type<boids::Heading>();
    export_ template <> _BOIDS_EXPORT Type& type<boids::Rotation>();
    export_ template <> _BOIDS_EXPORT Type& type<boids::MoveSpeed>();
    export_ template <> _BOIDS_EXPORT Type& type<boids::Transform4>();
    export_ template <> _BOIDS_EXPORT Type& type<boids::Boid>();
    export_ template <> _BOIDS_EXPORT Type& type<boids::BoidTarget>();
    export_ template <> _BOIDS_EXPORT Type& type<boids::BoidObstacle>();
    export_ template <> _BOIDS_EXPORT Type& type<boids::MoveForward>();
    export_ template <> _BOIDS_EXPORT Type& type<boids::Player>();
}
