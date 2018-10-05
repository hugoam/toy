

#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module ._boids;
#else
#include <boids/Types.h>
#include <boids/Api.h>
#include <type/Vector.h>
//#include <ecs/Proto.h>
#endif

namespace mud
{
    // Exported types
    
    template <> _BOIDS_EXPORT Type& type<boids::Player>() { static Type ty("Player"); return ty; }

	template <> _BOIDS_EXPORT Type& type<boids::Position>() { static Type ty("Position"); return ty; }
	template <> _BOIDS_EXPORT Type& type<boids::Heading>() { static Type ty("Heading"); return ty; }
	template <> _BOIDS_EXPORT Type& type<boids::Rotation>() { static Type ty("Rotation"); return ty; }
	template <> _BOIDS_EXPORT Type& type<boids::MoveSpeed>() { static Type ty("MoveSpeed"); return ty; }
	template <> _BOIDS_EXPORT Type& type<boids::MoveForward>() { static Type ty("MoveForward"); return ty; }
	template <> _BOIDS_EXPORT Type& type<boids::Transform4>() { static Type ty("Transform4"); return ty; }
	template <> _BOIDS_EXPORT Type& type<boids::Boid>() { static Type ty("Boid"); return ty; }
	template <> _BOIDS_EXPORT Type& type<boids::BoidTarget>() { static Type ty("BoidTarget"); return ty; }
	template <> _BOIDS_EXPORT Type& type<boids::BoidObstacle>() { static Type ty("BoidObstacle"); return ty; }
}
