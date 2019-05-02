

#pragma once

#include <infra/Config.h>

#include <jobs/Forward.h>
#include <type/Forward.h>
#include <ecs/Forward.h>
#include <math/Forward.h>
#include <geom/Forward.h>
#include <lang/Forward.h>
#include <util/Forward.h>

#ifndef TOY_CORE_EXPORT
#define TOY_CORE_EXPORT TWO_IMPORT
#endif

namespace toy
{
	using namespace two;

    enum class Task : unsigned int;
    enum SamplePolyAreas : unsigned int;
    enum SamplePolyFlags : unsigned int;
    enum CollisionGroup : short;
    
    template <class T> class Array;

    class Observer;
    class GenStoreObserver;
    class GenStore;
    class HookObserver;
    class Spatial;
    class Origin;
    class World;
    class PhysicMedium;
    class PhysicWorld;
    class BulletMedium;
    class BulletWorld;
    struct ConvexVolume;
    class NavGeom;
    class rcTileMesh;
    class Navmesh;
    class Navblock;
    class NavmeshShape;
    class Core;
    class DefaultWorld;
    class CollisionShape;
    class Movable;
    class MotionSource;
    class MotionState;
    struct Collision;
    class ColliderImpl;
    class ColliderObject;
    class Collider;
	class SolidImpl;
    class Solid;
    struct Contact;
    class BulletShape;
    class DispatchBulletShape;
    class BulletCollider;
    class BulletSolid;
    class Signal;
    class PhysicScope;
    class EmitterScope;
    class ReceptorScope;
    class Emitter;
    class Receptor;
    class Camera;
    class Medium;
    class SoundMedium;
    class VisualMedium;
    class MotionStateObserver;
    struct rcChunkyTriMeshNode;
    struct rcChunkyTriMesh;
    class Waypoint;
    class DetourPath;
    class Pathfinder;
    class Obstacle;
    class Obstacle;
    class AreaMedium;
    class Physic;
    class SolidMedium;
    class User;
    class ComponentPool;
    class EntityScript;
    class TargetDispatcher;
    class WorldClock;
    class WorldMedium;
    class WorldPage;
}

#ifdef TWO_META_GENERATOR
#include <pool/SparsePool.h>
#include <ecs/ECS.h>
namespace two
{
	extern template struct refl_ nocopy_ OwnedHandle<toy::Collider>;
	extern template struct refl_ nocopy_ OwnedHandle<toy::Solid>;
	extern template struct refl_ SparseHandle<toy::Collider>;
	extern template struct refl_ SparseHandle<toy::Solid>;

	extern template struct refl_ ComponentHandle<toy::Spatial>;
	extern template struct refl_ ComponentHandle<toy::Movable>;
	extern template struct refl_ ComponentHandle<toy::Camera>;
	extern template struct refl_ ComponentHandle<toy::Emitter>;
	extern template struct refl_ ComponentHandle<toy::Receptor>;
	extern template struct refl_ ComponentHandle<toy::EntityScript>;
	extern template struct refl_ ComponentHandle<toy::WorldPage>;
	extern template struct refl_ ComponentHandle<toy::Navblock>;
	//extern template struct refl_ ComponentHandle<toy::Collider>;
	//extern template struct refl_ ComponentHandle<toy::Solid>;

	extern template struct refl_ ComponentHandle<toy::Origin>;
	extern template struct refl_ ComponentHandle<toy::Waypoint>;
}
#endif

namespace toy
{
	using HCollider = SparseHandle<Collider>;
	using OCollider = OwnedHandle<Collider>;
	using HSolid = SparseHandle<Solid>;
	using OSolid = OwnedHandle<Solid>;

	using HSpatial = ComponentHandle<Spatial>;
	using HMovable = ComponentHandle<Movable>;
	using HCamera = ComponentHandle<Camera>;
	using HEmitter = ComponentHandle<Emitter>;
	using HReceptor = ComponentHandle<Receptor>;
	using HEntityScript = ComponentHandle<EntityScript>;
	using HWorldPage = ComponentHandle<WorldPage>;
	using HNavblock = ComponentHandle<Navblock>;

	using HOrigin = ComponentHandle<Origin>;
	using HWaypoint = ComponentHandle<Waypoint>;
}

#ifdef TWO_META_GENERATOR
#include <stl/vector.h>
namespace stl
{
	export_ extern template class refl_ seque_ vector<toy::HSpatial>;
}
#endif
