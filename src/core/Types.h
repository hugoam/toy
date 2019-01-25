#pragma once

#include <core/Forward.h>

#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#include <type/Type.h>
#include <type/Vector.h>
#endif

#ifndef MUD_MODULES
#include <type/Types.h>
#include <jobs/Types.h>
#include <ecs/Types.h>
#include <math/Types.h>
#include <geom/Types.h>
#include <lang/Types.h>
#include <util/Types.h>
#endif

#ifndef MUD_CPP_20
#include <stl/string.h>
#include <stl/vector.h>
#include <cstdint>
#endif

#include <core/Structs.h>

namespace mud
{
    // Exported types
    export_ template <> TOY_CORE_EXPORT Type& type<toy::CollisionGroup>();
    
    export_ template <> TOY_CORE_EXPORT Type& type<toy::BulletMedium>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::BulletShape>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Camera>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Collider>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::ColliderImpl>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::ColliderObject>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Collision>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::CollisionShape>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::ComponentPool>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Core>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::DetourPath>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Emitter>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::EntityScript>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Medium>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Movable>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Navblock>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Navmesh>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Origin>();
    export_ template <> TOY_CORE_EXPORT Type& type<mud::OwnedHandle<toy::Collider>>();
    export_ template <> TOY_CORE_EXPORT Type& type<mud::OwnedHandle<toy::Solid>>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Pathfinder>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::PhysicWorld>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Receptor>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Solid>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::SolidImpl>();
    export_ template <> TOY_CORE_EXPORT Type& type<mud::SparseHandle<toy::Collider>>();
    export_ template <> TOY_CORE_EXPORT Type& type<mud::SparseHandle<toy::Solid>>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::User>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Waypoint>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::World>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::WorldClock>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::WorldPage>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::BulletCollider>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::BulletSolid>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::BulletWorld>();
    export_ template <> TOY_CORE_EXPORT Type& type<mud::ComponentHandle<toy::Camera>>();
    export_ template <> TOY_CORE_EXPORT Type& type<mud::ComponentHandle<toy::Emitter>>();
    export_ template <> TOY_CORE_EXPORT Type& type<mud::ComponentHandle<toy::EntityScript>>();
    export_ template <> TOY_CORE_EXPORT Type& type<mud::ComponentHandle<toy::Movable>>();
    export_ template <> TOY_CORE_EXPORT Type& type<mud::ComponentHandle<toy::Navblock>>();
    export_ template <> TOY_CORE_EXPORT Type& type<mud::ComponentHandle<toy::Origin>>();
    export_ template <> TOY_CORE_EXPORT Type& type<mud::ComponentHandle<toy::Receptor>>();
    export_ template <> TOY_CORE_EXPORT Type& type<mud::ComponentHandle<toy::Spatial>>();
    export_ template <> TOY_CORE_EXPORT Type& type<mud::ComponentHandle<toy::Waypoint>>();
    export_ template <> TOY_CORE_EXPORT Type& type<mud::ComponentHandle<toy::WorldPage>>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::DefaultWorld>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::EmitterScope>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::NavmeshShape>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Obstacle>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::PhysicScope>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::ReceptorScope>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::SolidMedium>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::SoundMedium>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Spatial>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::VisualMedium>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::WorldMedium>();
    
    export_ template struct TOY_CORE_EXPORT Typed<vector<toy::BulletMedium*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<toy::BulletShape*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<toy::Camera*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<toy::Collider*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<toy::ColliderImpl*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<toy::ColliderObject*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<toy::Collision*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<toy::CollisionShape*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<toy::ComponentPool*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<toy::Core*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<toy::DetourPath*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<toy::Emitter*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<toy::EntityScript*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<toy::Medium*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<toy::Movable*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<toy::Navblock*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<toy::Navmesh*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<toy::Origin*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<mud::OwnedHandle<toy::Collider>*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<mud::OwnedHandle<toy::Solid>*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<toy::Pathfinder*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<toy::PhysicWorld*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<toy::Receptor*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<toy::Solid*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<toy::SolidImpl*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<mud::SparseHandle<toy::Collider>*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<mud::SparseHandle<toy::Solid>*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<toy::User*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<toy::Waypoint*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<toy::World*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<toy::WorldClock*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<toy::WorldPage*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<toy::BulletCollider*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<toy::BulletSolid*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<toy::BulletWorld*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<mud::ComponentHandle<toy::Camera>*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<mud::ComponentHandle<toy::Emitter>*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<mud::ComponentHandle<toy::EntityScript>*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<mud::ComponentHandle<toy::Movable>*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<mud::ComponentHandle<toy::Navblock>*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<mud::ComponentHandle<toy::Origin>*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<mud::ComponentHandle<toy::Receptor>*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<mud::ComponentHandle<toy::Spatial>*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<mud::ComponentHandle<toy::Waypoint>*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<mud::ComponentHandle<toy::WorldPage>*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<toy::DefaultWorld*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<toy::EmitterScope*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<toy::NavmeshShape*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<toy::Obstacle*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<toy::PhysicScope*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<toy::ReceptorScope*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<toy::SolidMedium*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<toy::SoundMedium*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<toy::Spatial*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<toy::VisualMedium*>>;
    export_ template struct TOY_CORE_EXPORT Typed<vector<toy::WorldMedium*>>;
}
