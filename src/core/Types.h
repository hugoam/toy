#pragma once

#include <core/Forward.h>

#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#include <type/Type.h>
#include <type/Vector.h>
#endif

#ifndef MUD_MODULES
#include <type/Types.h>
#include <ecs/Types.h>
#include <math/Types.h>
#include <geom/Types.h>
#include <lang/Types.h>
#include <util/Types.h>
#endif

#ifndef MUD_CPP_20
#include <string>
#include <cstdint>
#include <vector>
#endif

#include <core/Structs.h>

namespace mud
{
    // Exported types
    export_ template <> TOY_CORE_EXPORT Type& type<toy::CollisionGroup>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::SamplePolyAreas>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::SamplePolyFlags>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Task>();

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
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Pathfinder>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::PhysicWorld>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Receptor>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::BulletMedium>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::User>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::World>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::WorldClock>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Spatial>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::NavmeshShape>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::DefaultWorld>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Waypoint>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Origin>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::BulletCollider>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::WorldPage>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Solid>();
	export_ template <> TOY_CORE_EXPORT Type& type<toy::SolidImpl>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Obstacle>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::PhysicScope>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::BulletWorld>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::BulletSolid>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::EmitterScope>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::ReceptorScope>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::SolidMedium>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::SoundMedium>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::VisualMedium>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::WorldMedium>();

	export_ template <> TOY_CORE_EXPORT Type& type<toy::HSpatial>();
	export_ template <> TOY_CORE_EXPORT Type& type<toy::HMovable>();
	export_ template <> TOY_CORE_EXPORT Type& type<toy::HCamera>();
	export_ template <> TOY_CORE_EXPORT Type& type<toy::HEmitter>();
	export_ template <> TOY_CORE_EXPORT Type& type<toy::HReceptor>();
	export_ template <> TOY_CORE_EXPORT Type& type<toy::HEntityScript>();
	export_ template <> TOY_CORE_EXPORT Type& type<toy::HWorldPage>();
	export_ template <> TOY_CORE_EXPORT Type& type<toy::HNavblock>();

	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::BulletShape*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::Camera*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::Collider*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::ColliderImpl*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::ColliderObject*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::Collision*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::CollisionShape*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::ComponentPool*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::Core*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::DetourPath*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::Emitter*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::EntityScript*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::Medium*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::Movable*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::Navblock*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::Navmesh*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::Pathfinder*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::PhysicWorld*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::Receptor*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::BulletMedium*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::User*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::World*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::WorldClock*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::Spatial*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::NavmeshShape*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::DefaultWorld*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::Waypoint*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::Origin*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::BulletCollider*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::WorldPage*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::Solid*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::Obstacle*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::PhysicScope*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::BulletWorld*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::BulletSolid*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::EmitterScope*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::ReceptorScope*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::SolidMedium*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::SoundMedium*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::VisualMedium*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::WorldMedium*>>;
}
