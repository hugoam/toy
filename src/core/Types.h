#pragma once

#include <stdint.h>
#include <stl/string.h>
#include <stl/vector.h>
#include <core/Forward.h>

#if !defined TWO_MODULES || defined TWO_TYPE_LIB
#include <type/Type.h>
#endif

#ifndef TWO_MODULES
#include <type/Types.h>
#include <jobs/Types.h>
#include <ecs/Types.h>
#include <math/Types.h>
#include <geom/Types.h>
#include <lang/Types.h>
#include <util/Types.h>
#endif

#include <core/Structs.h>

namespace two
{
    // Exported types
    export_ template <> TOY_CORE_EXPORT Type& type<toy::CollisionGroup>();
    
    export_ template <> TOY_CORE_EXPORT Type& type<stl::vector<toy::HSpatial>>();
    
    export_ template <> TOY_CORE_EXPORT Type& type<two::OwnedHandle<toy::Collider>>();
    export_ template <> TOY_CORE_EXPORT Type& type<two::OwnedHandle<toy::Solid>>();
    export_ template <> TOY_CORE_EXPORT Type& type<two::SparseHandle<toy::Collider>>();
    export_ template <> TOY_CORE_EXPORT Type& type<two::SparseHandle<toy::Solid>>();
    export_ template <> TOY_CORE_EXPORT Type& type<two::ComponentHandle<toy::Spatial>>();
    export_ template <> TOY_CORE_EXPORT Type& type<two::ComponentHandle<toy::Movable>>();
    export_ template <> TOY_CORE_EXPORT Type& type<two::ComponentHandle<toy::Camera>>();
    export_ template <> TOY_CORE_EXPORT Type& type<two::ComponentHandle<toy::Emitter>>();
    export_ template <> TOY_CORE_EXPORT Type& type<two::ComponentHandle<toy::Receptor>>();
    export_ template <> TOY_CORE_EXPORT Type& type<two::ComponentHandle<toy::EntityScript>>();
    export_ template <> TOY_CORE_EXPORT Type& type<two::ComponentHandle<toy::WorldPage>>();
    export_ template <> TOY_CORE_EXPORT Type& type<two::ComponentHandle<toy::Navblock>>();
    export_ template <> TOY_CORE_EXPORT Type& type<two::ComponentHandle<toy::Origin>>();
    export_ template <> TOY_CORE_EXPORT Type& type<two::ComponentHandle<toy::Waypoint>>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Spatial>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Origin>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::WorldClock>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::World>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Medium>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::CollisionShape>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Movable>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Collision>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::ColliderImpl>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::ColliderObject>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Collider>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::SolidImpl>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Solid>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::WorldMedium>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::WorldPage>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Navmesh>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Navblock>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::NavmeshShape>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::PhysicWorld>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::BulletMedium>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::BulletWorld>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Core>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::DefaultWorld>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::User>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::BulletShape>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::BulletCollider>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::BulletSolid>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::PhysicScope>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::EmitterScope>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::ReceptorScope>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Emitter>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Receptor>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Camera>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::SoundMedium>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::VisualMedium>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Waypoint>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::DetourPath>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Pathfinder>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Obstacle>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::SolidMedium>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::ComponentPool>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::EntityScript>();
}
