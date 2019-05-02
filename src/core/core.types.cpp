#include <infra/Cpp20.h>

#ifdef TWO_MODULES
module toy.core;
#else
#include <core/Types.h>
#include <core/Api.h>
#include <type/Vector.h>
#endif

namespace two
{
    // Exported types
    template <> TOY_CORE_EXPORT Type& type<toy::CollisionGroup>() { static Type ty("CollisionGroup", sizeof(toy::CollisionGroup)); return ty; }
    
    template <> TOY_CORE_EXPORT Type& type<stl::vector<toy::HSpatial>>() { static Type ty("vector<toy::HSpatial>", sizeof(stl::vector<toy::HSpatial>)); return ty; }
    
    template <> TOY_CORE_EXPORT Type& type<two::OwnedHandle<toy::Collider>>() { static Type ty("OwnedHandle<toy::Collider>", sizeof(two::OwnedHandle<toy::Collider>)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<two::OwnedHandle<toy::Solid>>() { static Type ty("OwnedHandle<toy::Solid>", sizeof(two::OwnedHandle<toy::Solid>)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<two::SparseHandle<toy::Collider>>() { static Type ty("SparseHandle<toy::Collider>", sizeof(two::SparseHandle<toy::Collider>)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<two::SparseHandle<toy::Solid>>() { static Type ty("SparseHandle<toy::Solid>", sizeof(two::SparseHandle<toy::Solid>)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<two::ComponentHandle<toy::Spatial>>() { static Type ty("ComponentHandle<toy::Spatial>", sizeof(two::ComponentHandle<toy::Spatial>)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<two::ComponentHandle<toy::Movable>>() { static Type ty("ComponentHandle<toy::Movable>", sizeof(two::ComponentHandle<toy::Movable>)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<two::ComponentHandle<toy::Camera>>() { static Type ty("ComponentHandle<toy::Camera>", sizeof(two::ComponentHandle<toy::Camera>)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<two::ComponentHandle<toy::Emitter>>() { static Type ty("ComponentHandle<toy::Emitter>", sizeof(two::ComponentHandle<toy::Emitter>)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<two::ComponentHandle<toy::Receptor>>() { static Type ty("ComponentHandle<toy::Receptor>", sizeof(two::ComponentHandle<toy::Receptor>)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<two::ComponentHandle<toy::EntityScript>>() { static Type ty("ComponentHandle<toy::EntityScript>", sizeof(two::ComponentHandle<toy::EntityScript>)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<two::ComponentHandle<toy::WorldPage>>() { static Type ty("ComponentHandle<toy::WorldPage>", sizeof(two::ComponentHandle<toy::WorldPage>)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<two::ComponentHandle<toy::Navblock>>() { static Type ty("ComponentHandle<toy::Navblock>", sizeof(two::ComponentHandle<toy::Navblock>)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<two::ComponentHandle<toy::Origin>>() { static Type ty("ComponentHandle<toy::Origin>", sizeof(two::ComponentHandle<toy::Origin>)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<two::ComponentHandle<toy::Waypoint>>() { static Type ty("ComponentHandle<toy::Waypoint>", sizeof(two::ComponentHandle<toy::Waypoint>)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Spatial>() { static Type ty("Spatial", type<two::Transform>(), sizeof(toy::Spatial)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Origin>() { static Type ty("Origin", sizeof(toy::Origin)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::WorldClock>() { static Type ty("WorldClock", sizeof(toy::WorldClock)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::World>() { static Type ty("World", sizeof(toy::World)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Medium>() { static Type ty("Medium", sizeof(toy::Medium)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::CollisionShape>() { static Type ty("CollisionShape", sizeof(toy::CollisionShape)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Movable>() { static Type ty("Movable", sizeof(toy::Movable)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Collision>() { static Type ty("Collision", sizeof(toy::Collision)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::ColliderImpl>() { static Type ty("ColliderImpl", sizeof(toy::ColliderImpl)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::ColliderObject>() { static Type ty("ColliderObject", sizeof(toy::ColliderObject)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Collider>() { static Type ty("Collider", sizeof(toy::Collider)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::SolidImpl>() { static Type ty("SolidImpl", sizeof(toy::SolidImpl)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Solid>() { static Type ty("Solid", sizeof(toy::Solid)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::WorldMedium>() { static Type ty("WorldMedium", type<toy::Medium>(), sizeof(toy::WorldMedium)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::WorldPage>() { static Type ty("WorldPage", sizeof(toy::WorldPage)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Navmesh>() { static Type ty("Navmesh", sizeof(toy::Navmesh)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Navblock>() { static Type ty("Navblock", sizeof(toy::Navblock)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::NavmeshShape>() { static Type ty("NavmeshShape", type<two::Shape>(), sizeof(toy::NavmeshShape)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::PhysicWorld>() { static Type ty("PhysicWorld", sizeof(toy::PhysicWorld)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::BulletMedium>() { static Type ty("BulletMedium", sizeof(toy::BulletMedium)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::BulletWorld>() { static Type ty("BulletWorld", type<toy::PhysicWorld>(), sizeof(toy::BulletWorld)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Core>() { static Type ty("Core", sizeof(toy::Core)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::DefaultWorld>() { static Type ty("DefaultWorld", type<two::Complex>(), sizeof(toy::DefaultWorld)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::User>() { static Type ty("User", sizeof(toy::User)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::BulletShape>() { static Type ty("BulletShape", sizeof(toy::BulletShape)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::BulletCollider>() { static Type ty("BulletCollider", type<toy::ColliderImpl>(), sizeof(toy::BulletCollider)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::BulletSolid>() { static Type ty("BulletSolid", type<toy::SolidImpl>(), sizeof(toy::BulletSolid)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::PhysicScope>() { static Type ty("PhysicScope", type<toy::ColliderObject>(), sizeof(toy::PhysicScope)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::EmitterScope>() { static Type ty("EmitterScope", type<toy::PhysicScope>(), sizeof(toy::EmitterScope)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::ReceptorScope>() { static Type ty("ReceptorScope", type<toy::PhysicScope>(), sizeof(toy::ReceptorScope)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Emitter>() { static Type ty("Emitter", sizeof(toy::Emitter)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Receptor>() { static Type ty("Receptor", sizeof(toy::Receptor)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Camera>() { static Type ty("Camera", sizeof(toy::Camera)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::SoundMedium>() { static Type ty("SoundMedium", type<toy::Medium>(), sizeof(toy::SoundMedium)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::VisualMedium>() { static Type ty("VisualMedium", type<toy::Medium>(), sizeof(toy::VisualMedium)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Waypoint>() { static Type ty("Waypoint", sizeof(toy::Waypoint)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::DetourPath>() { static Type ty("DetourPath", sizeof(toy::DetourPath)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Pathfinder>() { static Type ty("Pathfinder", sizeof(toy::Pathfinder)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::Obstacle>() { static Type ty("Obstacle", type<toy::Collider>(), sizeof(toy::Obstacle)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::SolidMedium>() { static Type ty("SolidMedium", type<toy::Medium>(), sizeof(toy::SolidMedium)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::ComponentPool>() { static Type ty("ComponentPool", sizeof(toy::ComponentPool)); return ty; }
    template <> TOY_CORE_EXPORT Type& type<toy::EntityScript>() { static Type ty("EntityScript", sizeof(toy::EntityScript)); return ty; }
}
