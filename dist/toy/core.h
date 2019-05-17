#pragma once

#include <two/geom.h>
#include <two/pool.h>
#include <two/jobs.h>
#include <two/lang.h>
#include <two/ecs.h>
#include <two/math.h>
#include <toy/util.h>
#include <two/type.h>
#include <two/infra.h>



#ifndef TWO_MODULES
#endif





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

namespace two
{
	export_ struct TOY_CORE_EXPORT Anim
	{
		Ref m_object;
		Member* m_member;
		Var m_source_value;
		Var m_target_value;
		float m_duration;
		float m_cursor;
		// Interpolation m_interpolation = LINEAR;
		// Easing m_easing;
	};

	export_ class TOY_CORE_EXPORT Animator
	{
	public:
		Animator();

		void next_frame(size_t tick, size_t delta);
		void animate(Ref object, Member& member, const Var& value, float duration);

		Clock m_clock;
		vector<Anim> m_animations;

		static Animator me;
	};

	inline void animate(Ref object, Member& member, const Var& value, float duration)
	{
		Animator::me.animate(object, member, value, duration);
	}
}




#include <stl/vector.h>
#include <stl/function.h>

namespace toy
{
	enum class Task : unsigned int
	{
		World = 0,
		Spatial = 1,
		State = 2,
		Physics = 3,
		PhysicsWorld = 4,
		GameObject = 5,
		Ui = 6,
		Graphics = 7,
		Core = 8,
		Cleanup = 9,
		Loader = 10,
		Count = 11,
		Background = 12,
	};

	class TOY_CORE_EXPORT JobPump
	{
	public:
		JobPump();

		void pump();
		
		struct Entry
		{
			Task m_task;
			function<void(size_t tick, size_t delta)> m_handler;
		};

		void add_step(Entry entry);

		vector<Entry> m_steps;
		Clock m_clock;
	};
}


#include <stl/vector.h>
#include <stl/string.h>




#include <stl/memory.h>
#include <stl/vector.h>



struct rcHeightfield;
struct rcCompactHeightfield;
struct rcContourSet;
struct rcPolyMesh;
struct rcPolyMeshDetail;
struct rcConfig;

class rcContext;

typedef unsigned int dtStatus;
typedef unsigned int dtPolyRef;
typedef unsigned int dtTileRef;

class dtNavMeshQuery;
class dtQueryFilter;
class dtNavMesh;

class btCollisionWorld;
class btDynamicsWorld;
class btDiscreteDynamicsWorld;
class btBroadphaseInterface;
class btConstraintSolver;

class btCollisionShape;
class btStridingMeshInterface;
class btCollisionObject;
class btRigidBody;
class btPersistentManifold;

class btCollisionConfiguration;
class btCollisionDispatcher;




namespace two
{
	template <> struct TypedBuffer<toy::Spatial>		{ static uint32_t index() { return 0; } };
	template <> struct TypedBuffer<toy::Movable>		{ static uint32_t index() { return 1; } };
	template <> struct TypedBuffer<toy::Camera>			{ static uint32_t index() { return 2; } };
	template <> struct TypedBuffer<toy::Emitter>		{ static uint32_t index() { return 3; } };
	template <> struct TypedBuffer<toy::Receptor>		{ static uint32_t index() { return 4; } };
	template <> struct TypedBuffer<toy::EntityScript>	{ static uint32_t index() { return 5; } };
	template <> struct TypedBuffer<toy::WorldPage>		{ static uint32_t index() { return 6; } };
	template <> struct TypedBuffer<toy::Navblock>		{ static uint32_t index() { return 7; } };
	//template <> struct TypedBuffer<toy::Collider>		{ static uint32_t index() { return 8; } };
	//template <> struct TypedBuffer<toy::Solid>			{ static uint32_t index() { return 9; } };

	template <> struct TypedBuffer<toy::Origin>			{ static uint32_t index() { return 10; } };
	template <> struct TypedBuffer<toy::Waypoint>		{ static uint32_t index() { return 11; } };
}

namespace toy
{
	class refl_ TOY_CORE_EXPORT Spatial : public Transform
    {
	public:
		constr_ Spatial() {}
		constr_ Spatial(HSpatial parent, const vec3& position, const quat& rotation);
		constr_ Spatial(World& world, HSpatial parent, const vec3& position, const quat& rotation);
        ~Spatial();

		attr_ World* m_world = nullptr;
		attr_ link_ HSpatial m_parent;

		attr_ graph_ vector<HSpatial> m_contents;

		size_t m_last_tick = 0;
		size_t m_last_updated = 0;
		size_t m_last_modified = 0;

		bool m_moved = false;
		bool m_hooked = true;

		Spatial& origin();
		bool is_child_of(HSpatial spatial);

		vec3 absolute_position() const;
		quat absolute_rotation() const;

		inline void set_dirty(bool moved) { m_last_updated = m_last_tick + 1; m_last_modified = m_last_tick + 1; m_moved = moved; }
		inline void set_sync_dirty(bool moved) { m_last_updated = m_last_tick + 1; m_moved = moved; }

		meth_ inline void set_position(const vec3& position) { m_position = position; this->set_dirty(true); }
		meth_ inline void set_rotation(const quat& rotation) { m_rotation = rotation; this->set_dirty(false); }

		inline void sync_position(const vec3& position) { m_position = position; this->set_sync_dirty(true); }
		inline void sync_rotation(const quat& rotation) { m_rotation = rotation; this->set_sync_dirty(false); }

		inline vec3 front() const { return two::rotate(m_rotation, to_vec3(Side::Front)); }
		inline vec3 right() const { return two::rotate(m_rotation, to_vec3(Side::Right)); }
		inline vec3 up()    const { return two::rotate(m_rotation, to_vec3(Side::Up)); }
		inline vec3 down()  const { return two::rotate(m_rotation, to_vec3(Side::Down)); }

		void translate(const vec3& vec);
		void rotate(const vec3& axis, float angle);

		void yaw(float value);
		void yaw_fixed(float value);
		void pitch(float value);
		void roll(float value);

		void next_frame(size_t tick, size_t delta);
		
		Spatial* spatial_root();

		void detach(Spatial& child);

		void hook();
		void unhook();

		template <class Visitor>
		void visit(const Visitor& visitor)
		{
			if(!visitor(*this))
				return;
			for(HSpatial spatial : m_contents)
				spatial->visit(visitor);
		}

		void debug_contents(size_t depth = 0);
	};

	void detach_to(HSpatial spatial, HSpatial target);
	void set_parent(HSpatial spatial, HSpatial target);
}

namespace toy
{
	class refl_ TOY_CORE_EXPORT Origin
	{
	public:
		constr_ Origin() {}

		static Entity create(ECS& ecs, World& world);
	};
}



namespace toy
{
    class refl_ TOY_CORE_EXPORT WorldClock
    {
    public:
        WorldClock();

		double step();
        double step(double step);

		double read();
		double symbolic();

    private:
		Clock m_clock;

		float m_speed = 1.f;
		double m_time = 0.f;
		double m_symbolic_time = 0.f;
    };
}

namespace toy
{
	class refl_ TOY_CORE_EXPORT World
    {
    public:
		constr_ World(uint32_t id, Complex& complex, const string& name, JobSystem& job_system);
        ~World();

		attr_ uint32_t m_id;
		attr_ Complex& m_complex;
		attr_ string m_name;

		ECS m_ecs;
		JobSystem& m_job_system;
		JobPump m_pump;
		WorldClock m_clock;

		attr_ graph_ HSpatial origin() { return m_origin; }
		attr_ graph_ HSpatial unworld() { return m_unworld; }

		void next_frame();

		template <class T_Component, class... Args>
		void add_loop(Task task);

		template <class T_Component, class... Args>
		void add_parallel_loop(Task task);

	public:
		vector<unique<HandlePool>> m_pools;

		template <class T>
		inline SparsePool<T>& pool();

    private:
		EntityHandle<Origin> m_origin;
		EntityHandle<Origin> m_unworld;
    };

	template <class T, class... Types>
	inline ComponentHandle<T> construct(HSpatial parent, Types&&... args);

	template <class T, class... Types>
	inline EntityHandle<T> construct_owned(HSpatial parent, Types&&... args);
}




#include <stl/memory.h>


#include <stl/vector.h>
#include <stl/string.h>
#include <stl/map.h>


namespace toy
{
	enum refl_ CollisionGroup : short int
	{
		CM_NOMASK   = 0,
		CM_OBJECT   = 1 << 0,
		CM_SOLID    = 1 << 1,
		CM_GROUND   = 1 << 2,
		CM_AREA     = 1 << 3,
		CM_BUFFER   = 1 << 4,
		CM_LIGHT    = 1 << 5,
		CM_LIGHTREFLECTOR = 1 << 6,
		CM_SOURCE   = 1 << 7,
		CM_RECEPTOR = 1 << 8,
		CM_OBSTACLE = 1 << 9
	};
}

namespace toy
{
	//@todo : cleanup, remove references to emitters and receptors since it's not supposed to be specific
	//			make_unique masks stored in a map based on the group
    class refl_ TOY_CORE_EXPORT Medium
	{
	public:
		Medium(const string& name, bool occlusions = false);

		attr_ string m_name;
		attr_ bool m_occlusions;
		attr_ bool m_solid;

		map<CollisionGroup, short int> m_masks;

		short int mask(CollisionGroup group);

		virtual float throughput(EmitterScope& emitter, ReceptorScope& receptor, vector<Obstacle*>& occluding);
	};
}


#include <stl/memory.h>



namespace toy
{
	class refl_ TOY_CORE_EXPORT CollisionShape
	{
	public:
		constr_ CollisionShape();
		constr_ CollisionShape(const Shape& shape, const vec3& center = vec3(0.f), float margin = 0.f);
		~CollisionShape();

		CollisionShape(CollisionShape&& other) = default;
		CollisionShape& operator=(CollisionShape&& other) = default;

		CollisionShape(const CollisionShape& shape);
		CollisionShape& operator=(const CollisionShape& shape);

		object<Shape> m_shape;
		vec3 m_center = vec3(0.f);
		float m_margin = 0.f;

		bool checkInside(const vec3& position) { UNUSED(position); return true; }
	};
}





namespace toy
{
	TOY_CORE_EXPORT func_ bool move_2d(Spatial& spatial, Movable& movable, const vec3& target, float velocity, float time_step, float margin = 0.1f);
	TOY_CORE_EXPORT func_ bool steer_2d(Spatial& spatial, Movable& movable, const vec3& target, float velocity, float time_step, float margin = 0.1f);

	TOY_CORE_EXPORT bool spin_2d(Spatial& spatial, const vec3& axis, const vec3& target, float velocity, float time_step, float margin = 0.1f);
	TOY_CORE_EXPORT bool lookat_2d(Spatial& spatial, const vec3& axis, const vec3& target, float velocity, float time_step, float margin = 0.1f);
	TOY_CORE_EXPORT bool move_2d(Spatial& spatial, const vec3& target, float velocity, float time_step, float margin = 0.1f);
	TOY_CORE_EXPORT bool steer_2d(Spatial& spatial, const vec3& target, float velocity, float time_step, float margin = 0.1f);
	TOY_CORE_EXPORT bool stick_2d(Spatial& spatial, const vec3& target, float velocity, float time_step, float margin = 0.1f);
	TOY_CORE_EXPORT bool track_2d(Spatial& spatial, const vec3& target, float velocity, float time_step, float margin = 0.1f);

	class refl_ TOY_CORE_EXPORT Movable
	{
	public:
		constr_ Movable() {}
		constr_ Movable(const vec3& position);
		~Movable();

		MotionState* m_motion_state = nullptr;

		attr_ vec3 m_linear_velocity = vec3(0.f);
		attr_ vec3 m_angular_velocity = vec3(0.f);

		vec3 m_direction = -Z3;
		vec3 m_acceleration = vec3(0.f);

		attr_ bool m_moving = false;
		attr_ vec3 m_previous_position;

		vec3 m_max_linear_velocity = vec3(0.f);

		size_t m_updated = 0;
		size_t m_acceleration_updated = 0;
		size_t m_last_tick = 0;

        meth_ void set_linear_velocity(const vec3& velocity);
		meth_ void modify_linear_velocity(const vec3& velocity);

        meth_ void set_angular_velocity(const vec3& velocity);
		meth_ void modify_angular_velocity(const vec3& velocity);

		void set_acceleration(const vec3& acceleration, const vec3& maxLinVel);
		void modify_acceleration(const vec3& acceleration); 

		void next_frame(Spatial& spatial, size_t tick, size_t delta);
	};
}

namespace toy
{
	class TOY_CORE_EXPORT TransformSource
	{
	public:
		virtual void update_transform(const vec3& position, const quat& rotation) = 0;
	};

	class TOY_CORE_EXPORT MotionSource
	{
	public:
		virtual void update_motion(const vec3& linear_velocity, const vec3& angular_velocity) = 0;
	};

    class TOY_CORE_EXPORT MotionState
    {
    public:
		MotionState(const vec3& offset = vec3(0.f))
			: m_offset(offset)
		{
			//if(m_movable)
			//	m_movable->m_motion_state = this;
		}

		TransformSource* m_transform_source = nullptr;
		MotionSource* m_motion_source = nullptr;
		vec3 m_offset = vec3(0.f);
		size_t m_last_updated = 0;

		struct Transform { vec3 m_position; quat m_rotation; };

		Transform transform(const Spatial& spatial) const
		{
			quat rotation = spatial.absolute_rotation();
			vec3 position = spatial.absolute_position() + rotate(rotation, m_offset);
			return { position, rotation };
		}

		void sync_transform(Spatial& spatial, const vec3& position, const quat& rotation)
		{
			quat inv_rotation = inverse(spatial.m_parent->absolute_rotation());
			spatial.set_position(position - spatial.m_parent->absolute_position() - rotate(inv_rotation, m_offset));
			spatial.set_rotation(rotation * inv_rotation);
		}

		void update_transform(Spatial& spatial)
		{
			quat rotation = spatial.absolute_rotation();
			vec3 position = spatial.absolute_position() + rotate(rotation, m_offset);
			m_transform_source->update_transform(position, rotation);
		}

		void update(Spatial& spatial, const quat& rotation)
		{
			if(spatial.m_last_modified > m_last_updated)
			{
				vec3 position = spatial.absolute_position() + rotate(rotation, m_offset);
				m_transform_source->update_transform(position, rotation);
			}
		}

		void update(Spatial& spatial, size_t tick)
		{
			quat rotation = spatial.absolute_rotation();
			this->update(spatial, rotation);
			m_last_updated = tick;
		}

		void update(Spatial& spatial, Movable& movable, size_t tick)
		{
			quat rotation = spatial.absolute_rotation();
			this->update(spatial, rotation);
			if(movable.m_updated > m_last_updated)
			{
				vec3 linear_velocity = rotate(rotation, movable.m_linear_velocity);
				vec3 angular_velocity = rotate(rotation, movable.m_angular_velocity);
				m_motion_source->update_motion(linear_velocity, angular_velocity);
			}
			m_last_updated = tick;
		}
    };
}

namespace toy
{
	struct refl_ TOY_CORE_EXPORT Collision
	{
		Collision() {}
		Collision(HCollider first, HCollider second, const vec3& hit_point) : m_first(first), m_second(second), m_hit_point(hit_point) {}
		attr_ HCollider m_first = {};
		attr_ HCollider m_second = {};
		attr_ vec3 m_hit_point = vec3(0.f);
	};

	class refl_ TOY_CORE_EXPORT ColliderImpl : public TransformSource
	{
	public:
		virtual ~ColliderImpl() {}

		virtual void update_transform(const vec3& position, const quat& rotation) = 0;
		virtual void update_transform() = 0;

		virtual void project(const vec3& position, vector<Collision>& collisions, short int mask) = 0;
		virtual void raycast(const vec3& position, vector<Collision>& collisions, short int mask) = 0;
		virtual Collision raycast(const vec3& position, short int mask) = 0;
	};

	class refl_ TOY_CORE_EXPORT ColliderObject
	{
	public:
		virtual ~ColliderObject() {}
		virtual void add_contact(Collider& collider, ColliderObject& object) { UNUSED(collider); UNUSED(object); }
		virtual void remove_contact(Collider& collider, ColliderObject& object) { UNUSED(collider); UNUSED(object); }
	};

    class refl_ TOY_CORE_EXPORT Collider
    {
	public:
		constr_ Collider() {}
		constr_ Collider(HSpatial spatial, HMovable movable, const CollisionShape& collision_shape, Medium& medium, CollisionGroup group);
        virtual ~Collider();

		Collider(Collider&& other) = default;
		Collider& operator=(Collider&& other) = default;

		attr_ HSpatial m_spatial;
		attr_ HMovable m_movable;
		attr_ CollisionShape m_collision_shape;
		attr_ Medium* m_medium = nullptr;
		attr_ CollisionGroup m_group;

		attr_ ColliderObject* m_object = nullptr;

		PhysicMedium* m_world;
		object<ColliderImpl> m_impl;

		attr_ ColliderImpl& impl() { return *m_impl; }

		MotionState m_motion_state;

		void init(object<ColliderImpl> impl);

		void next_frame(size_t tick, size_t delta);
		void next_frame(Spatial& spatial, size_t tick, size_t delta);
		void next_frame(Spatial& spatial, Movable& movable, size_t tick, size_t delta);

		ColliderImpl* operator->() { return m_impl.get(); }
		const ColliderImpl* operator->() const { return m_impl.get(); }

		static OCollider create(HSpatial spatial, HMovable movable, const CollisionShape& collision_shape, Medium& medium, CollisionGroup group);
		static void destroy(HCollider solid);
    };

	class refl_ TOY_CORE_EXPORT SolidImpl : public TransformSource, public MotionSource
	{
	public:
		virtual ~SolidImpl() {}

		virtual void update_transform(const vec3& position, const quat& rotation) = 0;
		virtual void update_motion(const vec3& linear_velocity, const vec3& angular_velocity) = 0;

		meth_ virtual vec3 linear_velocity() = 0;
		meth_ virtual vec3 angular_velocity() = 0;

		meth_ virtual void set_linear_velocity(const vec3& force) = 0;
		meth_ virtual void set_angular_velocity(const vec3& torque) = 0;
		meth_ virtual void set_angular_factor(const vec3& factor) = 0;

		virtual void set_force(const vec3& force) = 0;
		virtual void set_torque(const vec3& torque) = 0;

		meth_ virtual void impulse(const vec3& force, const vec3& point) = 0;

		virtual void impulse_force(const vec3& force) = 0;
		virtual void impulse_torque(const vec3& torque) = 0;
	};

	class refl_ TOY_CORE_EXPORT Solid
	{
	public:
		Solid() {}
		Solid(HSpatial spatial, HMovable movable, OCollider collider, bool isstatic, float mass = 0.f);
		virtual ~Solid();

		Solid(Solid&& other) = default;
		Solid& operator=(Solid&& other) = default;

		attr_ HSpatial m_spatial;
		//attr_ nomut_ OCollider m_collider;
		OCollider m_collider;
		attr_ bool m_static = false;
		attr_ float m_mass = 0.f;

		void init(object<SolidImpl> impl);

		object<SolidImpl> m_impl;

		SolidImpl* operator->() { return m_impl.get(); }
		const SolidImpl* operator->() const { return m_impl.get(); }

		static OSolid create(HSpatial spatial, HMovable movable, const CollisionShape& collision_shape, Medium& medium, CollisionGroup group, bool isstatic, float mass = 0.f);
		static OSolid create(HSpatial spatial, HMovable movable, const CollisionShape& collision_shape, bool isstatic, float mass = 0.f);
		static void destroy(HSolid solid);
	};
}

namespace two
{
	template <>
	struct DestroyHandle<toy::Collider>
	{
		static void destroy(const SparseHandle<toy::Collider>& handle) { toy::Collider::destroy(handle); }
	};

	template <>
	struct DestroyHandle<toy::Solid>
	{
		static void destroy(const SparseHandle<toy::Solid>& handle) { toy::Solid::destroy(handle); }
	};
}

namespace toy
{
	class refl_ TOY_CORE_EXPORT WorldMedium final : public Medium
	{
	public:
		constr_ WorldMedium();
		attr_ static WorldMedium me;
	};

	/* A WorldPage has : 
		- contents (entities)
		- static geometry (static entities)
		- nested worldpages (worldpages)
		- adjacent worldpages
	*/

	class refl_ TOY_CORE_EXPORT WorldPage// : public Movabl
    {
	public:
		constr_ WorldPage() {}
		constr_ WorldPage(HSpatial spatial, bool open, const vec3& extents);
        ~WorldPage();

		WorldPage(WorldPage&& other) = default;
		WorldPage& operator=(WorldPage&& other) = default;

		comp_ HSpatial m_spatial;

		attr_ bool m_open = true;
		attr_ vec3 m_extents = vec3(0.f);
		attr_ World* m_world = nullptr;
		attr_ size_t m_last_rebuilt = 0;

		size_t m_updated = 0;
		//std::atomic<size_t> m_updated = 0;

		vector<string> m_geometry_filter;

		//EmitterScope& m_scope;

		vector<Geometry> m_chunks;
		vector<OSolid> m_solids;

		void next_frame(const Spatial& spatial, size_t tick, size_t delta);

		meth_ void update_geometry(size_t tick);

		meth_ void ground_point(const vec3& position, bool relative, vec3& outputPoint);
		meth_ void raycast_ground(const vec3& from, const vec3& to, vec3& ground_point);
    };
}
// Copyright (c) 2009-2010 Mikko Mononen memon@inside.org
//
// This software is provided 'as-is', without any express or implied
// warranty.  In no event will the authors be held liable for any damages
// arising from the use of this software.
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would be
//    appreciated but is not required.
// 2. Altered source versions must be plainly marked as such, and must not be
//    misrepresented as being the original software.
// 3. This notice may not be removed or altered from any source distribution.
//

#ifndef RECASTSAMPLETILEMESH_H
#define RECASTSAMPLETILEMESH_H



#include <stl/string.h>

class rcContext;

namespace toy
{
	using cstring = const char*;

	static const int MAX_CONVEXVOL_PTS = 12;
	struct ConvexVolume
	{
		float verts[MAX_CONVEXVOL_PTS*3];
		float hmin, hmax;
		int nverts;
		int area;
	};

	class TOY_CORE_EXPORT NavGeom
	{
	public:
		NavGeom(Geometry& geom, cstring name);
		~NavGeom();

		Geometry& m_geometry;
		string m_name;
		unique<rcChunkyTriMesh> m_chunkyMesh;

		bool build();

	public:
		bool raycastMesh(const vec3& src, const vec3& dst, float& tmin);

		// Off-Mesh connections.
		void addOffMeshConnection(const float* spos, const float* epos, const float rad, unsigned char bidir, unsigned char area, unsigned short flags);
		void deleteOffMeshConnection(int i);

		// Box Volumes.
		int getConvexVolumeCount() const { return m_volumeCount; }
		const ConvexVolume* getConvexVolumes() const { return m_volumes; }
		void addConvexVolume(const float* verts, const int nverts, const float minh, const float maxh, unsigned char area);
		void deleteConvexVolume(int i);

	protected:
		unique<rcContext> m_ctx;

	public:
		// Off-Mesh connections.
		static const int MAX_OFFMESH_CONNECTIONS = 256;

		float m_offMeshConVerts[MAX_OFFMESH_CONNECTIONS*3*2];
		float m_offMeshConRads[MAX_OFFMESH_CONNECTIONS];
		unsigned char m_offMeshConDirs[MAX_OFFMESH_CONNECTIONS];
		unsigned char m_offMeshConAreas[MAX_OFFMESH_CONNECTIONS];
		unsigned short m_offMeshConFlags[MAX_OFFMESH_CONNECTIONS];
		unsigned int m_offMeshConId[MAX_OFFMESH_CONNECTIONS];
		int m_offMeshConCount = 0;

		// Convex Volumes.
		static const int MAX_VOLUMES = 256;

		ConvexVolume m_volumes[MAX_VOLUMES];
		int m_volumeCount = 0;
	};
}

struct rcHeightfield;
struct rcCompactHeightfield;
struct rcContourSet;
struct rcPolyMesh;
struct rcPolyMeshDetail;
struct rcConfig;

class rcContext;

typedef unsigned int dtStatus;
typedef unsigned int dtPolyRef;
typedef unsigned int dtTileRef;

class dtNavMeshQuery;
class dtQueryFilter;
class dtNavMesh;

namespace toy
{
	enum SamplePolyAreas : unsigned int
	{
		SAMPLE_POLYAREA_GROUND,
		SAMPLE_POLYAREA_WATER,
		SAMPLE_POLYAREA_ROAD,
		SAMPLE_POLYAREA_DOOR,
		SAMPLE_POLYAREA_GRASS,
		SAMPLE_POLYAREA_JUMP,
	};

	enum SamplePolyFlags : unsigned int
	{
		SAMPLE_POLYFLAGS_WALK = 0x01,		// Ability to walk (ground, grass, road)
		SAMPLE_POLYFLAGS_SWIM = 0x02,		// Ability to swim (water).
		SAMPLE_POLYFLAGS_DOOR = 0x04,		// Ability to move through doors.
		SAMPLE_POLYFLAGS_JUMP = 0x08,		// Ability to jump.
		SAMPLE_POLYFLAGS_ALL = 0xffff		// All abilities.
	};

	class TOY_CORE_EXPORT rcTileMesh
	{
	public:
		float m_cellSize = 0.3f;
		float m_cellHeight = 0.2f;
		float m_agentHeight = 2.0f;
		float m_agentRadius = 0.35f;
		float m_agentMaxClimb = 0.9f;
		float m_agentMaxSlope = 45.0f;
		int m_regionMinSize = 8;
		int m_regionMergeSize = 20;
		bool m_monotonePartitioning = false;
		float m_edgeMaxLen = 12.0f;
		float m_edgeMaxError = 1.3f;
		int m_vertsPerPoly = 6;
		float m_detailSampleDist = 6.0f;
		float m_detailSampleMaxError = 1.0f;

		unique<rcContext> m_ctx;

	public:
		bool m_keepInterResults = false;
		bool m_buildAll = true;
		float m_totalBuildTimeMs = 0.f;

		Geometry m_geometry;
		dtNavMesh* m_navmesh = nullptr;
		unique<NavGeom> m_navgeom;
		unsigned char* m_triareas = nullptr;
		rcHeightfield* m_solid = nullptr;
		rcCompactHeightfield* m_chf = nullptr;
		rcContourSet* m_cset = nullptr;
		rcPolyMesh* m_pmesh = nullptr;
		rcPolyMeshDetail* m_dmesh = nullptr;
		unique<rcConfig> m_cfg;	

		int m_maxTiles = 0;
		int m_maxPolysPerTile = 0;
		float m_tileSize = 32.f;
	
		float m_tileBmin[3];
		float m_tileBmax[3];
		float m_tileBuildTime = 0.f;
		float m_tileMemUsage = 0.f;
		int m_tileTriCount = 0;

		unsigned char* buildTileMesh(const int tx, const int ty, const float* bmin, const float* bmax, int& dataSize);
	
		void cleanup();
	
	public:
		rcTileMesh();
		virtual ~rcTileMesh();
	
		void setupSettings();

		virtual void handleMeshChanged(Geometry& geom);
		virtual bool handleBuild();
	
		void getTilePos(const float* pos, int& tx, int& ty);
	
		void buildTile(const float* pos);
		void removeTile(const float* pos);
		void buildAllTiles();
		void removeAllTiles();

		dtStatus getPolyHeight(dtPolyRef ref, const float* pos, float* height) const;
	};
}


#endif // RECASTSAMPLETILEMESH_H

namespace toy
{
	TOY_CORE_EXPORT uint32_t navmesh_num_vertices(const Navmesh& navmesh);
	
	TOY_CORE_EXPORT ShapeSize size_shape_lines(const ProcShape& shape, const NavmeshShape& navmesh);
	TOY_CORE_EXPORT void draw_shape_lines(const ProcShape& shape, const NavmeshShape& navmesh, MeshAdapter& writer);

	TOY_CORE_EXPORT ShapeSize size_shape_triangles(const ProcShape& shape, const NavmeshShape& navmesh);
	TOY_CORE_EXPORT void draw_shape_triangles(const ProcShape& shape, const NavmeshShape& navmesh, MeshAdapter& writer);

	class refl_ TOY_CORE_EXPORT Navmesh : public rcTileMesh
    {
    public:
		constr_ Navmesh(World& world);
		~Navmesh();

		attr_ World& m_world;
		attr_ size_t m_updated = 0;
		attr_ bool m_dirty = false;

		void update_block(Navblock& navblock);

		void next_frame(size_t tick, size_t delta);

		void load();
		void build();

		void save(const char* path);
		void load(const char* path);

	private:
		dtNavMesh* _load(const char* path);
		void _save(const char* path, const dtNavMesh* mesh);
    };

	class refl_ TOY_CORE_EXPORT Navblock
	{
	public:
		constr_ Navblock() {}
		constr_ Navblock(HSpatial spatial, HWorldPage world_page, Navmesh& navmesh);
		~Navblock();

		comp_ HSpatial m_spatial;
		comp_ HWorldPage m_world_page;

		attr_ Navmesh* m_navmesh = nullptr;

		attr_ bool m_auto_update = false;
		attr_ size_t m_updated = 0;

		void next_frame(const Spatial& spatial, const WorldPage& world_page, size_t tick, size_t delta);
	};

	class refl_ TOY_CORE_EXPORT NavmeshShape : public Shape
	{
	public:
		constr_ NavmeshShape(Navmesh& navmesh);

		Navmesh& m_navmesh;

		virtual object<Shape> clone() const;
	};
}


#include <stl/unordered_map.h>


#include <stl/map.h>

namespace toy
{
	class TOY_CORE_EXPORT PhysicMedium
	{
	public:
		PhysicMedium(World& world, Medium& medium);
		virtual ~PhysicMedium() {}

		World& m_world;
		Medium& m_medium;

		virtual void update_contacts() = 0;
		virtual void next_frame(size_t tick, size_t delta) = 0;

		virtual object<ColliderImpl> make_collider(HCollider collider) = 0;
		virtual object<SolidImpl> make_solid(HSolid solid) = 0;

		virtual void add_solid(HCollider collider, HSolid solid) = 0;
		virtual void remove_solid(HCollider collider, HSolid solid) = 0;

		virtual void add_collider(HCollider collider) = 0;
		virtual void remove_collider(HCollider collider) = 0;

		virtual void project(HCollider collider, const vec3& position, const quat& rotation, vector<Collision>& collisions, short int mask) = 0;
		virtual void raycast(HCollider collider, const vec3& start, const vec3& end, vector<Collision>& collisions, short int mask) = 0;
		virtual Collision raycast(HCollider collider, const vec3& target, const vec3& end, short int mask) = 0;
	};

	class refl_ TOY_CORE_EXPORT PhysicWorld
    {
	public:
        PhysicWorld(World& world);
		virtual ~PhysicWorld();

		attr_ World& m_world;

		void next_frame(size_t tick, size_t delta);

		PhysicMedium& sub_world(Medium& medium);

	public:
		virtual object<PhysicMedium> create_sub_world(Medium& medium) = 0;
		meth_ virtual vec3 ground_point(const Ray& ray) = 0;
		meth_ virtual Collision raycast(const Ray& ray, short int mask) = 0;

	protected:
		map<Medium*, object<PhysicMedium>> m_subworlds;
    };
}

class btCollisionWorld;
class btDynamicsWorld;
class btDiscreteDynamicsWorld;
class btBroadphaseInterface;
class btConstraintSolver;

class btCollisionShape;
class btStridingMeshInterface;
class btCollisionObject;
class btRigidBody;
class btPersistentManifold;

class btCollisionConfiguration;
class btCollisionDispatcher;

namespace toy
{
#ifdef TRIGGER_COLLISIONS
	static void collisionStarted(btPersistentManifold* manifold);
	static void collisionEnded(btPersistentManifold* manifold);
#endif

	class refl_ TOY_CORE_EXPORT BulletMedium : public PhysicMedium
	{
	public:
        BulletMedium(World& world, BulletWorld& bullet_world, Medium& medium);
        ~BulletMedium();

		virtual void update_contacts() override final;

        virtual void next_frame(size_t tick, size_t delta) override final;

		virtual object<ColliderImpl> make_collider(HCollider collider) override final;
		virtual object<SolidImpl> make_solid(HSolid solid) override final;

		virtual void add_solid(HCollider collider, HSolid solid) override final;
		virtual void remove_solid(HCollider collider, HSolid solid) override final;

		virtual void add_collider(HCollider collider) override final;
		virtual void remove_collider(HCollider collider) override final;

		virtual void project(HCollider collider, const vec3& position, const quat& rotation, vector<Collision>& collisions, short int mask) override final;
		virtual void raycast(HCollider collider, const vec3& start, const vec3& end, vector<Collision>& collisions, short int mask) override final;
		virtual Collision raycast(HCollider collider, const vec3& start, const vec3& end, short int mask) override final;

		void remove_contacts(uint32_t collider);

    public:
		BulletWorld& m_bullet_world;

		size_t m_last_tick;
        unique<btCollisionDispatcher> m_collision_dispatcher;
        unique<btBroadphaseInterface> m_broadphase_interface;

		unique<btCollisionWorld> m_collision_world;
        unique<btConstraintSolver> m_constraint_solver;

		btDynamicsWorld* m_dynamics_world = nullptr;

#ifndef TRIGGER_COLLISIONS
		uint64_t hash(uint32_t a, uint32_t b) { return uint64_t(a) | (uint64_t(b) << 32); }
		uint64_t pair_hash(uint32_t a, uint32_t b) { return a < b ? hash(a, b) : hash(b, a); }

		struct Contact
		{
			Contact() : m_tick(0) {}

			uint32_t m_col0;
			uint32_t m_col1;
			size_t m_tick;
			size_t m_index;
		};

		unordered_map<uint64_t, Contact> m_hash_contacts;
		vector<Contact*> m_contacts;

		void remove_contact(Contact& contact, size_t index);

		void remove_contact(uint32_t col0, uint32_t col1);
		Contact& find_contact(uint32_t col0, uint32_t col1);
#endif
	};

	class refl_ TOY_CORE_EXPORT BulletWorld : public PhysicWorld
	{
	public:
		constr_ BulletWorld(World& world);
        ~BulletWorld();

		object<PhysicMedium> create_sub_world(Medium& medium);

		vec3 ground_point(const Ray& ray);
		Collision raycast(const Ray& ray, short int mask);
    };
}

namespace toy
{
	class refl_ TOY_CORE_EXPORT Core
	{
	public:
		Core(JobSystem& job_system);
		~Core();

		void next_frame();
		
		JobSystem& m_job_system;
		JobPump m_pump;
	};

	class refl_ TOY_CORE_EXPORT DefaultWorld : public Complex
	{
	public:
		constr_ DefaultWorld(const string& name, JobSystem& job_system);
		~DefaultWorld();

		attr_ World m_world;
		attr_ comp_ BulletWorld m_bullet_world;
		attr_ comp_ Navmesh m_navmesh;
	};
}

#include <stdint.h>
#include <stl/string.h>
#include <stl/vector.h>

#if !defined TWO_MODULES || defined TWO_TYPE_LIB
#endif

#ifndef TWO_MODULES
#endif


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


#include <stl/vector.h>

namespace toy
{
	class refl_ TOY_CORE_EXPORT User
	{
	public:
		vector<Ref> m_selection;
	};
}




namespace toy
{
	class refl_ TOY_CORE_EXPORT BulletShape
	{
	public:
		BulletShape(unique<btCollisionShape> shape);
		BulletShape(unique<btCollisionShape> shape, unique<btStridingMeshInterface> mesh);
		~BulletShape();

		BulletShape(BulletShape&& other);
		BulletShape& operator=(BulletShape&& other);

		BulletShape(const BulletShape& other) = delete;
		BulletShape& operator=(const BulletShape& other) = delete;

		unique<btCollisionShape> shape;
		unique<btStridingMeshInterface> mesh;
	};

	class TOY_CORE_EXPORT DispatchBulletShape : public Dispatch<BulletShape>, public LazyGlobal<DispatchBulletShape>
	{
	public:
		DispatchBulletShape();
		BulletShape dispatch(CollisionShape& collision_shape);
	};

    class refl_ TOY_CORE_EXPORT BulletCollider : public ColliderImpl
    {
	public:
        BulletCollider(BulletMedium& bulletWorld, HSpatial spatial, HCollider collider, CollisionShape& collision_shape, bool create = true);
        ~BulletCollider();

		void setup(Spatial& spatial, btCollisionObject& collisionObject);

		virtual void update_transform(const vec3& position, const quat& rotation) override;
		virtual void update_transform() override;

		virtual void project(const vec3& position, vector<Collision>& collisions, short int mask) override;
		virtual void raycast(const vec3& position, vector<Collision>& collisions, short int mask) override;
		virtual Collision raycast(const vec3& position, short int mask) override;

	public:
		BulletMedium& m_bullet_world;
		HSpatial m_spatial;
		HCollider m_collider;
		BulletShape m_collision_shape;
		unique<btCollisionObject> m_collision_object;
    };
}



namespace toy
{
	class BulletMotionState;

	class refl_ TOY_CORE_EXPORT BulletSolid : public SolidImpl
    {
    public:
		BulletSolid(BulletMedium& bullet_world, BulletCollider& bullet_collider, HSpatial spatial, HCollider collider, HSolid solid);
        ~BulletSolid();

		void setup(BulletCollider& collider, Spatial& spatial, Solid& solid);

		btRigidBody* m_rigid_body;

		virtual void update_transform(const vec3& position, const quat& rotation) override;
		virtual void update_motion(const vec3& linear_velocity, const vec3& angular_velocity) override;

		virtual vec3 linear_velocity() override;
		virtual vec3 angular_velocity() override;

		virtual void set_linear_velocity(const vec3& force) override;
		virtual void set_angular_velocity(const vec3& torque) override;
		virtual void set_angular_factor(const vec3& factor) override;

		virtual void set_force(const vec3& force) override;
		virtual void set_torque(const vec3& torque) override;

		virtual void impulse(const vec3& force, const vec3& point) override;

		virtual void impulse_force(const vec3& force) override;
		virtual void impulse_torque(const vec3& torque) override;

    public:
		unique<BulletMotionState> m_motion_state;
    };
}


#include <stl/function.h>





#include <stl/vector.h>

namespace toy
{
	class TOY_CORE_EXPORT Signal
	{
	public:
		Signal() {}
		Signal(EmitterScope& emitter, ReceptorScope& receptor);
		~Signal();

		EmitterScope* m_emitter = nullptr;
		ReceptorScope* m_receptor = nullptr;
		float m_strength = 0.f;
		bool m_on = false;

		void update();
		void on();
		void off();

	private:
		vector<Obstacle*> m_occluding;
	};
}

namespace toy
{
	class refl_ TOY_CORE_EXPORT PhysicScope : public ColliderObject
    {
    public:
		PhysicScope() {}
        PhysicScope(HSpatial spatial, Medium& medium, const CollisionShape& collision_shape, CollisionGroup group);

		void add_scope(HSpatial object);
		void remove_scope(HSpatial object);

		HSpatial m_spatial;
		OCollider m_collider;
		vector<HSpatial> m_scope;
		vector<Observer*> m_observers;
	};

	class refl_ TOY_CORE_EXPORT EmitterScope : public PhysicScope
	{
	public:
		EmitterScope() {}
		EmitterScope(HSpatial spatial, Medium& medium, const CollisionShape& collision_shape, CollisionGroup group /*= CM_SOURCE*/);

		virtual void add_contact(Collider& collider, ColliderObject& object);
		virtual void remove_contact(Collider& collider, ColliderObject& object);

		virtual void handle_moved();

	protected:
		vector<Signal> m_signals;
	};

	class refl_ TOY_CORE_EXPORT ReceptorScope : public PhysicScope
	{
	public:
		ReceptorScope() {}
		ReceptorScope(HSpatial spatial, Medium& medium, const CollisionShape& collision_shape, CollisionGroup group /*= CM_RECEPTOR*/);
	};

#if 0
	using OEmitterScope = OwnedHandle<EmitterScope>;
	using OReceptorScope = OwnedHandle<ReceptorScope>;

	using HEmitterScope = SparseHandle<EmitterScope>;
	using HReceptorScope = SparseHandle<ReceptorScope>;
#else
	using OEmitterScope = object<EmitterScope>;
	using OReceptorScope = object<ReceptorScope>;

	using HEmitterScope = EmitterScope&;
	using HReceptorScope = ReceptorScope&;
#endif

	class refl_ TOY_CORE_EXPORT Emitter// : public Movabl
	{
	public:
		constr_ Emitter() {}
		constr_ Emitter(HSpatial spatial);
		~Emitter();

		Emitter(Emitter&& other) = default;
		Emitter& operator=(Emitter&& other) = default;

		comp_ HSpatial m_spatial;

		HEmitterScope add_scope(Medium& medium, const CollisionShape& collision_shape, CollisionGroup group);
		HEmitterScope add_sphere(Medium& medium, float radius, CollisionGroup group = CM_SOURCE);

	protected:
		vector<OEmitterScope> m_emitters;
	};

	class refl_ TOY_CORE_EXPORT Receptor// : public Movabl
	{
	public:
		constr_ Receptor() {}
		constr_ Receptor(HSpatial spatial);
		~Receptor();

		Receptor(Receptor&& other) = default;
		Receptor& operator=(Receptor&& other) = default;

		comp_ HSpatial m_spatial;

		HReceptorScope add_scope(Medium& medium, const CollisionShape& collision_shape, CollisionGroup group);
		HReceptorScope add_sphere(Medium& medium, float radius, CollisionGroup group = CM_RECEPTOR);

		meth_ ReceptorScope* scope(Medium& medium);

	protected:
		vector<OReceptorScope> m_receptors;
	};
}

namespace toy
{
	class refl_ TOY_CORE_EXPORT Camera
	{
	public:
		constr_ Camera() {}
		constr_ Camera(float distance, float near = 0.001f, float far = 1000.f);
		~Camera();

		static Entity create(ECS& ecs, HSpatial parent, const vec3& position, float lens_distance, float near = 0.001f, float far = 1000.f);

		attr_ float m_lens_distance = 1.f;
		attr_ float m_lens_angle = 0.f;

		attr_ float m_near = 0.001f;
		attr_ float m_far = 1000.f;

		attr_ float m_aspect;

		bool m_lens_updated = true;

		vec3 m_lens_position = vec3(0.f);
		quat m_lens_rotation = ZeroQuat;

		size_t m_last_updated = 0;

		void next_frame(const Spatial& spatial, size_t tick, size_t delta);

		void calc_lens_position(const Spatial& spatial);
		void calc_lens_rotation(const Spatial& spatial);

		void set_lens_distance(float distance);
		void zoom(float amount);

		void set_lens_angle(float angle);
		void pitch_lens(float amount);

		//void viewportRay(float tx, float ty, vec3& from, vec3& to);
		//void planarRay(float tx, float ty, vec3& from, vec3& to);

		vec3 lens_direction(const Spatial& spatial);

	//private:
		//bool m_planar;
		//float m_vertical_angle;
		//float m_plane_distance;

#ifdef TOY_THREADED
		TransfomReceiver m_receiver;
#endif
	};

	export_ TOY_CORE_EXPORT void jump_camera_to(Spatial& spatial, Camera& camera, const vec3& target, const quat& rotation, float distance, float angle, float duration = 1.f);
	export_ TOY_CORE_EXPORT void jump_camera_to(Spatial& spatial, Camera& camera, const vec3& position, float distance = 1.f, float rotation = 0.f);
	export_ TOY_CORE_EXPORT void move_camera_to(Spatial& spatial, Camera& camera, const vec3& position);

	export_ TOY_CORE_EXPORT void jump_camera_to(Entity camera, const vec3& target, const quat& rotation, float distance, float angle, float duration = 1.f);
	export_ TOY_CORE_EXPORT void jump_camera_to(Entity camera, const vec3& position, float distance = 1.f, float rotation = 0.f);
	export_ TOY_CORE_EXPORT void move_camera_to(Entity camera, const vec3& position);
}



namespace toy
{
	class refl_ TOY_CORE_EXPORT SoundMedium final : public Medium
	{
	public:
		constr_ SoundMedium();
		attr_ static SoundMedium me;
	};
}



namespace toy
{
	class refl_ TOY_CORE_EXPORT VisualMedium final : public Medium
	{
	public:
		constr_ VisualMedium();
		attr_ static VisualMedium me;

		float m_ambient_intensity;
	};
}



namespace toy
{
	class MotionStateObserver { public:	virtual void update(MotionState* motionState) = 0; };
}
//
// Copyright (c) 2009-2010 Mikko Mononen memon@inside.org
//
// This software is provided 'as-is', without any express or implied
// warranty.  In no event will the authors be held liable for any damages
// arising from the use of this software.
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would be
//    appreciated but is not required.
// 2. Altered source versions must be plainly marked as such, and must not be
//    misrepresented as being the original software.
// 3. This notice may not be removed or altered from any source distribution.
//

#ifndef CHUNKYTRIMESH_H
#define CHUNKYTRIMESH_H


#include <stdint.h>

namespace toy
{
	struct rcChunkyTriMeshNode
	{
		vec2 bmin, bmax;
		int i, n;
	};

	struct rcChunkyTriMesh
	{
		inline rcChunkyTriMesh() : nodes(0), tris(0) {};
		inline ~rcChunkyTriMesh() { delete[] nodes; delete[] tris; }

		rcChunkyTriMeshNode* nodes;
		int nnodes;
		int* tris;
		int ntris;
		int maxTrisPerChunk;
	};

	// Creates partitioned triangle mesh (AABB tree),
	// where each node contains at max trisPerChunk triangles.
	bool rcCreateChunkyTriMesh(const float* verts, const uint32_t* tris, int ntris, int trisPerChunk, rcChunkyTriMesh* cm);

	// Returns the chunk indices which overlap the input rectable.
	int rcGetChunksOverlappingRect(const rcChunkyTriMesh* cm, const vec2& bmin, const vec2& bmax, int* ids, const int maxIds);

	// Returns the chunk indices which overlap the input segment.
	int rcGetChunksOverlappingSegment(const rcChunkyTriMesh* cm, const vec2& p, const vec2& q, int* ids, const int maxIds);
}


#endif // CHUNKYTRIMESH_H


#include <stl/vector.h>
#include <stl/memory.h>

namespace toy
{
	typedef unsigned int dtPolyRef;

	class refl_ TOY_CORE_EXPORT Waypoint
	{
	public:
		constr_ Waypoint() {}

		static Entity create(ECS& ecs, HSpatial parent, const vec3& position);
	};

    class refl_ TOY_CORE_EXPORT DetourPath
    {
	public:
		DetourPath(Pathfinder& pathfinder, const vec3& origin, const vec3& destination);

		Pathfinder& m_pathfinder;

		vec3 m_origin;
		vec3 m_destination;

		vector<vec3> m_path;
		vector<vec3> m_waypoints;
		vector<dtPolyRef> m_poly_path;

		void clear();
		bool compute();

	private:
		dtPolyRef m_currentPoly;
    };
}


#include <stl/vector.h>

class dtNavMesh;
class dtNavMeshQuery;
class dtQueryFilter;

namespace toy
{
	class refl_ TOY_CORE_EXPORT Pathfinder
    {
	public:
		constr_ Pathfinder(Navmesh& navmesh);
		~Pathfinder();

		dtNavMesh& m_navmesh;

		unique<dtNavMeshQuery> m_query;
		unique<dtQueryFilter> m_filter;

		size_t m_max_polys = 20;
		size_t m_max_waypoints = 50;

		bool validity(const vec3& pos);
		void nearestValid(vec3& destination, float margin);
    };
}



namespace toy
{
	class refl_ TOY_CORE_EXPORT Obstacle : public Collider
	{
	public:
		constr_ Obstacle(HSpatial spatial, HMovable movable, Medium& medium, const CollisionShape& shape, float throughput);

		attr_ CollisionShape m_shape;
		attr_ float m_throughput;
	};
}



namespace toy
{
	class TOY_CORE_EXPORT AreaMedium final : public Medium
	{
	public:
		constr_ AreaMedium();
		attr_ static AreaMedium me;
	};

	class TOY_CORE_EXPORT Physic
	{
	public:
		Physic(Spatial& spatial);
	};
}



namespace toy
{
	class refl_ TOY_CORE_EXPORT SolidMedium final : public Medium
	{
	public:
		constr_ SolidMedium();
		attr_ static SolidMedium me;
	};
}


#include <stl/string.h>

namespace toy
{
	class refl_ TOY_CORE_EXPORT ComponentPool
	{

	};

	class refl_ TOY_CORE_EXPORT EntityScript
	{
	public:
		constr_ EntityScript() {}
		constr_ EntityScript(HSpatial spatial);
		
		comp_ HSpatial m_spatial;
		attr_ Script* m_logic_script = nullptr;
		attr_ Script* m_render_script = nullptr;

		void next_frame(size_t tick, size_t delta);

		void run_logic();
		void run_render(); // Gnode& parent
	};
}



#include <stl/vector.h>

namespace toy
{
	using namespace two;

}



using namespace two; namespace toy
{
	template <class T_Component, class... Args>
	void World::add_loop(Task task)
	{
		auto loop = [&](size_t tick, size_t delta)
		{
			m_ecs.loop<T_Component, Args...>([tick, delta](T_Component& component, Args&... args)
			{
				component.next_frame(args..., tick, delta);
			});
		};

		m_pump.add_step({ task, loop });
	}

	template <class T_Component, class... Args>
	void World::add_parallel_loop(Task task)
	{
		auto loop = [&](size_t tick, size_t delta)
		{
			auto process = [tick, delta](T_Component& component, Args&... args)
			{
				component.next_frame(args..., tick, delta);
			};

			Job* job = for_components<T_Component, Args...>(m_job_system, nullptr, m_ecs, process);
			m_job_system.complete(job);
		};

		m_pump.add_step({ task, loop });
	}

	template <class T>
	inline SparsePool<T>& World::pool()
	{
		if(!m_pools[type<T>().m_id])
			m_pools[type<T>().m_id] = make_unique<SparsePool<T>>();
		return as<SparsePool<T>>(*m_pools[type<T>().m_id].get());
	}

	template <class T, class... Types>
	inline ComponentHandle<T> construct(HSpatial parent, Types&&... args)
	{
		ECS& ecs = parent->m_world->m_ecs;
		ComponentHandle<T> object = T::create(ecs, parent, static_cast<Types&&>(args)...);
		parent->m_contents.push_back(HSpatial(object));
		return object;
	}

	template <class T, class... Types>
	inline EntityHandle<T> construct_owned(HSpatial parent, Types&&... args)
	{
		ECS& ecs = parent->m_world->m_ecs;
		ComponentHandle<T> object = T::create(ecs, parent, static_cast<Types&&>(args)...);
		parent->m_contents.push_back(object->m_spatial);
		return object;
	}
}
