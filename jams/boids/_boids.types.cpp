#include <infra/Cpp20.h>

#ifdef TWO_MODULES
module ._boids;
#else
#include <boids/Types.h>
#include <boids/Api.h>
#include <type/Vector.h>
#endif

namespace two
{
    // Exported types
    
    
    template <> _BOIDS_EXPORT Type& type<boids::Position>() { static Type ty("Position", sizeof(boids::Position)); return ty; }
    template <> _BOIDS_EXPORT Type& type<boids::Heading>() { static Type ty("Heading", sizeof(boids::Heading)); return ty; }
    template <> _BOIDS_EXPORT Type& type<boids::Rotation>() { static Type ty("Rotation", sizeof(boids::Rotation)); return ty; }
    template <> _BOIDS_EXPORT Type& type<boids::MoveSpeed>() { static Type ty("MoveSpeed", sizeof(boids::MoveSpeed)); return ty; }
    template <> _BOIDS_EXPORT Type& type<boids::Transform4>() { static Type ty("Transform4", sizeof(boids::Transform4)); return ty; }
    template <> _BOIDS_EXPORT Type& type<boids::Boid>() { static Type ty("Boid", sizeof(boids::Boid)); return ty; }
    template <> _BOIDS_EXPORT Type& type<boids::BoidTarget>() { static Type ty("BoidTarget", sizeof(boids::BoidTarget)); return ty; }
    template <> _BOIDS_EXPORT Type& type<boids::BoidObstacle>() { static Type ty("BoidObstacle", sizeof(boids::BoidObstacle)); return ty; }
    template <> _BOIDS_EXPORT Type& type<boids::MoveForward>() { static Type ty("MoveForward", sizeof(boids::MoveForward)); return ty; }
    template <> _BOIDS_EXPORT Type& type<boids::Player>() { static Type ty("Player", sizeof(boids::Player)); return ty; }
}
