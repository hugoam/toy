

#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module toy.core;
#else
#include <core/Types.h>
#include <core/Api.h>
#include <obj/Vector.h>
//#include <proto/Proto.h>
#endif

namespace mud
{
    // Exported types
    template <> TOY_CORE_EXPORT Type& type<toy::CollisionGroup>() { static Type ty("toy::CollisionGroup"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Behavior::Priority>() { static Type ty("toy::Behavior::Priority"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::SamplePolyAreas>() { static Type ty("toy::SamplePolyAreas"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::SamplePolyFlags>() { static Type ty("toy::SamplePolyFlags"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Task>() { static Type ty("toy::Task"); return ty; }
    
    template <> TOY_CORE_EXPORT Type& type<toy::Active>() { static Type ty("Active"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Actor>() { static Type ty("Actor"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Agent>() { static Type ty("Agent"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Array<toy::Action>>() { static Type ty("Array<toy::Action>"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Array<toy::Entity>>() { static Type ty("Array<toy::Entity>"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Behavior>() { static Type ty("Behavior"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::BufferPage>() { static Type ty("BufferPage"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::BulletShape>() { static Type ty("BulletShape"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Camera>() { static Type ty("Camera"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Collider>() { static Type ty("Collider"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::ColliderImpl>() { static Type ty("ColliderImpl"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::ColliderObject>() { static Type ty("ColliderObject"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Collision>() { static Type ty("Collision"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::CollisionShape>() { static Type ty("CollisionShape"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::ComponentPool>() { static Type ty("ComponentPool"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Core>() { static Type ty("Core"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::DetourPath>() { static Type ty("DetourPath"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Effect>() { static Type ty("Effect"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Emitter>() { static Type ty("Emitter"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::EntityScript>() { static Type ty("EntityScript"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::EventFilter>() { static Type ty("EventFilter"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::EventRelay>() { static Type ty("EventRelay"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::GroundMotion>() { static Type ty("GroundMotion"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::LightReflector>() { static Type ty("LightReflector"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::LightSource>() { static Type ty("LightSource"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Medium>() { static Type ty("Medium"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Movable>() { static Type ty("Movable"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Navblock>() { static Type ty("Navblock"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Navmesh>() { static Type ty("Navmesh"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Obstacle>() { static Type ty("Obstacle"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Pathfinder>() { static Type ty("Pathfinder"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::PhysicWorld>() { static Type ty("PhysicWorld"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Reactive>() { static Type ty("Reactive"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Receptor>() { static Type ty("Receptor"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Selector>() { static Type ty("Selector"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::State>() { static Type ty("State"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::SubBulletWorld>() { static Type ty("SubBulletWorld"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Symbolic>() { static Type ty("Symbolic"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::TaskSection>() { static Type ty("TaskSection"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::User>() { static Type ty("User"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::View>() { static Type ty("View"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Vision>() { static Type ty("Vision"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::World>() { static Type ty("World"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::WorldClock>() { static Type ty("WorldClock"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Entity>() { static Type ty("Entity", type<mud::Transform>()); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::DefaultWorld>() { static Type ty("DefaultWorld", type<mud::Complex>()); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::OCamera>() { static Type ty("OCamera", type<mud::Complex>()); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::OLight>() { static Type ty("OLight", type<mud::Complex>()); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::OWaypoint>() { static Type ty("OWaypoint", type<mud::Complex>()); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Origin>() { static Type ty("Origin", type<mud::Complex>()); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::NavmeshShape>() { static Type ty("NavmeshShape", type<mud::Shape>()); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Action>() { static Type ty("Action", type<toy::Procedure>()); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::BulletCollider>() { static Type ty("BulletCollider", type<toy::ColliderImpl>()); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Solid>() { static Type ty("Solid", type<toy::Collider>()); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::ObstacleBody>() { static Type ty("ObstacleBody", type<toy::Collider>()); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::PhysicScope>() { static Type ty("PhysicScope", type<toy::Collider>()); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Area>() { static Type ty("Area", type<toy::ColliderObject>()); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::WorldPage>() { static Type ty("WorldPage", type<toy::ColliderObject>()); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::BulletSolid>() { static Type ty("BulletSolid", type<toy::BulletCollider>()); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::EmitterScope>() { static Type ty("EmitterScope", type<toy::PhysicScope>()); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::ReceptorScope>() { static Type ty("ReceptorScope", type<toy::PhysicScope>()); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::EmitterSphere>() { static Type ty("EmitterSphere", type<toy::EmitterScope>()); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::ReceptorSphere>() { static Type ty("ReceptorSphere", type<toy::ReceptorScope>()); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::EventEmitter>() { static Type ty("EventEmitter", type<toy::Emitter>()); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::EventReceptor>() { static Type ty("EventReceptor", type<toy::Receptor>()); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::MonoSection>() { static Type ty("MonoSection", type<toy::TaskSection>()); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::ParallelSection>() { static Type ty("ParallelSection", type<toy::TaskSection>()); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::QueueSection>() { static Type ty("QueueSection", type<toy::TaskSection>()); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::BulletWorld>() { static Type ty("BulletWorld", type<toy::PhysicWorld>()); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::SolidMedium>() { static Type ty("SolidMedium", type<toy::Medium>()); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::SoundMedium>() { static Type ty("SoundMedium", type<toy::Medium>()); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::VisualMedium>() { static Type ty("VisualMedium", type<toy::Medium>()); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::WorldMedium>() { static Type ty("WorldMedium", type<toy::Medium>()); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::ReceptorView>() { static Type ty("ReceptorView", type<toy::View>()); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::StoreView>() { static Type ty("StoreView", type<toy::View>()); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::OmniVision>() { static Type ty("OmniVision", type<toy::Vision>()); return ty; }
}
