

#pragma once

#include <infra/Config.h>

#include <type/Forward.h>
#include <ecs/Forward.h>
#include <math/Forward.h>
#include <geom/Forward.h>
#include <lang/Forward.h>
#include <util/Forward.h>

#ifndef TOY_CORE_EXPORT
#define TOY_CORE_EXPORT MUD_IMPORT
#endif


    
    

namespace std {

    
    
}

namespace mud {
namespace ui {

    
    
}
}

namespace glm {

    
    
}

namespace bx {

    
    
}

namespace json11 {

    
    
}

namespace mud {

    
    
}

namespace mud {
namespace detail {

    
    
}
}

namespace mud {
namespace gfx {

    
    
}
}

namespace bimg {

    
    
}

namespace toy {

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

namespace bgfx {

    
    
}

