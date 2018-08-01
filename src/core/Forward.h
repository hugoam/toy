

#pragma once

#include <infra/Config.h>

#include <obj/Forward.h>
#include <proto/Forward.h>
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

namespace mud {
namespace gfx {

    
    
}
}

namespace json11 {

    
    
}

namespace mud {

    
    
}

namespace mud {
namespace detail {

    
    
}
}

namespace bgfx {

    
    
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
    class Entity;
    class Action;
    class TaskSection;
    class QueueSection;
    class MonoSection;
    class ParallelSection;
    class Origin;
    class World;
    class PhysicMedium;
    class PhysicWorld;
    class SubBulletWorld;
    class BulletWorld;
    struct ConvexVolume;
    class NavGeom;
    class rcTileMesh;
    class Navmesh;
    class Navblock;
    class NavmeshShape;
    class Core;
    class DefaultWorld;
    class EffectCallback;
    class Effect;
    class State;
    class Active;
    class Actor;
    class CollisionShape;
    class Movable;
    class MotionSource;
    class MotionState;
    struct Collision;
    class ColliderImpl;
    class ColliderObject;
    class Collider;
    class Solid;
    class Atoll;
    struct Contact;
    class Belt;
    class Disq;
    class MotionStrategy;
    class Agent;
    class GroundMotion;
    class Area;
    class BulletShape;
    class DispatchBulletShape;
    class BulletCollider;
    class BulletSolid;
    class Signal;
    class PhysicScope;
    class EmitterScope;
    class ReceptorScope;
    class EmitterSphere;
    class ReceptorSphere;
    class Emitter;
    class Receptor;
    class Camera;
    class OCamera;
    class EventHandler_;
    class Event;
    class EventSubscriber;
    class EventFilter;
    class EventTube;
    class EventTubeEnd;
    class EventRelay;
    class EventEmitter;
    class EventReceptor;
    class LightReflector;
    class LightSource;
    class OLight;
    class Medium;
    class SoundMedium;
    class VisualMedium;
    class MotionStateObserver;
    struct rcChunkyTriMeshNode;
    struct rcChunkyTriMesh;
    class OWaypoint;
    class DetourPath;
    class Pathfinder;
    class ObstacleBody;
    class Obstacle;
    class AreaMedium;
    class Physic;
    class SolidMedium;
    class User;
    class Behavior;
    class Reactive;
    class ComponentPool;
    class EntityScript;
    class TargetDispatcher;
    class Selector;
    class Symbolic;
    class RecursiveStore;
    class View;
    class StoreView;
    class ReceptorView;
    class Vision;
    class OmniVision;
    class WorldClock;
    class BufferPage;
    class WorldMedium;
    class WorldPage;
}

namespace bx {

    
    
}

