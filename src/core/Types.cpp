

#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module toy.core;
#else
#include <core/Types.h>
#include <core/Api.h>
#include <type/Vector.h>
//#include <ecs/Proto.h>
#endif

namespace mud
{
    // Exported types
    template <> TOY_CORE_EXPORT Type& type<toy::CollisionGroup>() { static Type ty("toy::CollisionGroup"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::SamplePolyAreas>() { static Type ty("toy::SamplePolyAreas"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::SamplePolyFlags>() { static Type ty("toy::SamplePolyFlags"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Task>() { static Type ty("toy::Task"); return ty; }
    
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
    template <> TOY_CORE_EXPORT Type& type<toy::Emitter>() { static Type ty("Emitter"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::EntityScript>() { static Type ty("EntityScript"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Medium>() { static Type ty("Medium"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Movable>() { static Type ty("Movable"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Navblock>() { static Type ty("Navblock"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Navmesh>() { static Type ty("Navmesh"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Pathfinder>() { static Type ty("Pathfinder"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::PhysicWorld>() { static Type ty("PhysicWorld"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Receptor>() { static Type ty("Receptor"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::BulletMedium>() { static Type ty("BulletMedium"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::User>() { static Type ty("User"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::World>() { static Type ty("World"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::WorldClock>() { static Type ty("WorldClock"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Spatial>() { static Type ty("Spatial", type<mud::Transform>()); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::NavmeshShape>() { static Type ty("NavmeshShape", type<mud::Shape>()); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::DefaultWorld>() { static Type ty("DefaultWorld"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Waypoint>() { static Type ty("Waypoint"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Origin>() { static Type ty("Origin"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::BulletCollider>() { static Type ty("BulletCollider", type<toy::ColliderImpl>()); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::WorldPage>() { static Type ty("WorldPage", type<toy::ColliderObject>()); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Solid>() { static Type ty("Solid"); return ty; }
	template <> TOY_CORE_EXPORT Type& type<toy::SolidImpl>() { static Type ty("SolidImpl"); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Obstacle>() { static Type ty("Obstacle", type<toy::Collider>()); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::PhysicScope>() { static Type ty("PhysicScope", type<toy::Collider>()); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::BulletWorld>() { static Type ty("BulletWorld", type<toy::PhysicWorld>()); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::BulletSolid>() { static Type ty("BulletSolid", type<toy::BulletCollider>()); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::EmitterScope>() { static Type ty("EmitterScope", type<toy::PhysicScope>()); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::ReceptorScope>() { static Type ty("ReceptorScope", type<toy::PhysicScope>()); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::SolidMedium>() { static Type ty("SolidMedium", type<toy::Medium>()); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::SoundMedium>() { static Type ty("SoundMedium", type<toy::Medium>()); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::VisualMedium>() { static Type ty("VisualMedium", type<toy::Medium>()); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::WorldMedium>() { static Type ty("WorldMedium", type<toy::Medium>()); return ty; }

	template <> TOY_CORE_EXPORT Type& type<toy::HSpatial>() { static Type ty("HSpatial"); return ty; }
	template <> TOY_CORE_EXPORT Type& type<toy::HMovable>() { static Type ty("HMovable"); return ty; }
	template <> TOY_CORE_EXPORT Type& type<toy::HCamera>() { static Type ty("HCamera"); return ty; }
	template <> TOY_CORE_EXPORT Type& type<toy::HEmitter>() { static Type ty("HEmitter"); return ty; }
	template <> TOY_CORE_EXPORT Type& type<toy::HReceptor>() { static Type ty("HReceptor"); return ty; }
	template <> TOY_CORE_EXPORT Type& type<toy::HEntityScript>() { static Type ty("HEntityScript"); return ty; }
	template <> TOY_CORE_EXPORT Type& type<toy::HWorldPage>() { static Type ty("HWorldPage"); return ty; }
	template <> TOY_CORE_EXPORT Type& type<toy::HNavblock>() { static Type ty("HNavblock"); return ty; }
}
