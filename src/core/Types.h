#pragma once

#include <core/Forward.h>

#if !defined MUD_MODULES || defined MUD_OBJ_LIB
#include <obj/Type.h>
#include <obj/Vector.h>
#endif

#ifndef MUD_MODULES
#include <obj/Types.h>
#include <proto/Types.h>
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
    
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Active>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Actor>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Agent>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Array<toy::Action>>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Array<toy::Entity>>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Behavior>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::BufferPage>();
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
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Effect>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Emitter>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::EntityScript>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::EventFilter>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::EventRelay>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::GroundMotion>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::LightReflector>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::LightSource>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Medium>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Movable>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Navblock>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Navmesh>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Obstacle>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Pathfinder>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::PhysicWorld>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Reactive>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Receptor>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Selector>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::State>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::SubBulletWorld>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Symbolic>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::TaskSection>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::User>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::View>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Vision>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::World>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::WorldClock>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Entity>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::DefaultWorld>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::OCamera>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::OLight>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::OWaypoint>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Origin>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::NavmeshShape>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Action>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::BulletCollider>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Solid>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::ObstacleBody>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::PhysicScope>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::Area>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::WorldPage>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::BulletSolid>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::EmitterScope>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::ReceptorScope>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::EmitterSphere>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::ReceptorSphere>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::EventEmitter>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::EventReceptor>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::MonoSection>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::ParallelSection>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::QueueSection>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::BulletWorld>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::SolidMedium>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::SoundMedium>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::VisualMedium>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::WorldMedium>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::ReceptorView>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::StoreView>();
    export_ template <> TOY_CORE_EXPORT Type& type<toy::OmniVision>();
    
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::Active*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::Actor*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::Agent*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::Array<toy::Action>*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::Array<toy::Entity>*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::Behavior*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::BufferPage*>>;
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
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::Effect*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::Emitter*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::EntityScript*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::EventFilter*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::EventRelay*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::GroundMotion*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::LightReflector*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::LightSource*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::Medium*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::Movable*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::Navblock*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::Navmesh*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::Obstacle*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::Pathfinder*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::PhysicWorld*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::Reactive*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::Receptor*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::Selector*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::State*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::SubBulletWorld*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::Symbolic*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::TaskSection*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::User*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::View*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::Vision*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::World*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::WorldClock*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::Entity*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::DefaultWorld*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::OCamera*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::OLight*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::OWaypoint*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::Origin*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::NavmeshShape*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::Action*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::BulletCollider*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::Solid*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::ObstacleBody*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::PhysicScope*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::Area*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::WorldPage*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::BulletSolid*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::EmitterScope*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::ReceptorScope*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::EmitterSphere*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::ReceptorSphere*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::EventEmitter*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::EventReceptor*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::MonoSection*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::ParallelSection*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::QueueSection*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::BulletWorld*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::SolidMedium*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::SoundMedium*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::VisualMedium*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::WorldMedium*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::ReceptorView*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::StoreView*>>;
	export_ template struct TOY_CORE_EXPORT Typed<std::vector<toy::OmniVision*>>;
}
