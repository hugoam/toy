#include <two/pool.h>
#include <two/geom.h>
#include <toy/core.h>
#include <two/lang.h>
#include <two/ecs.h>
#include <two/math.h>
#include <two/refl.h>
#include <two/type.h>
#include <two/infra.h>




#define TOY_POOL_IMPLEMENTATION



namespace toy
{
	Core::Core(JobSystem& job_system)
		: m_job_system(job_system)
	{
		static Prototype default_world = { type<DefaultWorld>(), { &type<World>(), &type<BulletWorld>() } };
	}

	Core::~Core()
	{}

	void Core::next_frame()
	{
		Animator::me.next_frame(0, 0);

		m_pump.pump();
	}

	DefaultWorld::DefaultWorld(const string& name, JobSystem& job_system)
		: Complex(0, type<DefaultWorld>(), m_bullet_world, m_navmesh, *this)
		, m_world(0, *this, name, job_system)
		, m_bullet_world(m_world)
		, m_navmesh(m_world)
	{
		m_world.m_pump.add_step({ Task::PhysicsWorld,
			[&](size_t tick, size_t delta) { m_bullet_world.next_frame(tick, delta); }
		});
	}

	DefaultWorld::~DefaultWorld()
	{}
}
#ifndef USE_STL
#ifdef TWO_MODULES
module toy.core;
#else
#include <stl/vector.hpp>
#include <stl/unordered_map.hpp>
#endif

namespace stl
{
	using namespace toy;
	template class TOY_CORE_EXPORT vector<JobPump::Entry>;
	template class TOY_CORE_EXPORT vector<Spatial>;
	template class TOY_CORE_EXPORT vector<Movable>;
	template class TOY_CORE_EXPORT vector<Camera>;
	template class TOY_CORE_EXPORT vector<WorldPage>;
	template class TOY_CORE_EXPORT vector<Navblock>;
	template class TOY_CORE_EXPORT vector<Origin>;
	template class TOY_CORE_EXPORT vector<HSpatial>;
	template class TOY_CORE_EXPORT vector<OSolid>;
	template class TOY_CORE_EXPORT vector<Signal>;
	template class TOY_CORE_EXPORT vector<Collider>;
	template class TOY_CORE_EXPORT vector<Solid>;
	template class TOY_CORE_EXPORT vector<Obstacle*>;
	template class TOY_CORE_EXPORT vector<unique<EmitterScope>>;
	template class TOY_CORE_EXPORT vector<unique<ReceptorScope>>;
	template class TOY_CORE_EXPORT vector<unique<HandlePool>>;
	template class TOY_CORE_EXPORT vector<Waypoint>;
	template class TOY_CORE_EXPORT vector<Anim>;
	template class TOY_CORE_EXPORT vector<Observer*>;
	template class TOY_CORE_EXPORT vector<Collision>;
	template class TOY_CORE_EXPORT vector<BulletMedium::Contact*>;
	//template class TOY_CORE_EXPORT vector<ContactCheck::Contact>;
	template class TOY_CORE_EXPORT unordered_map<CollisionGroup, short>;
	template class TOY_CORE_EXPORT unordered_map<Medium*, unique<PhysicMedium>>;
	template class TOY_CORE_EXPORT unordered_map<uint64_t, BulletMedium::Contact>;
}
#endif

#ifdef TWO_MODULES
module toy.core;
#else
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



namespace two
{
	template struct OwnedHandle<toy::Collider>;
	template struct OwnedHandle<toy::Solid>;
	template struct SparseHandle<toy::Collider>;
	template struct SparseHandle<toy::Solid>;

	template struct ComponentHandle<toy::Spatial>;
	template struct ComponentHandle<toy::Movable>;
	template struct ComponentHandle<toy::Camera>;
	template struct ComponentHandle<toy::Emitter>;
	template struct ComponentHandle<toy::Receptor>;
	template struct ComponentHandle<toy::EntityScript>;
	template struct ComponentHandle<toy::WorldPage>;
	template struct ComponentHandle<toy::Navblock>;
	//emplate struct ComponentHandle<toy::Collider>;
	//emplate struct ComponentHandle<toy::Solid>;

	template struct ComponentHandle<toy::Origin>;
	template struct ComponentHandle<toy::Waypoint>;
}


namespace toy
{
}


#ifdef TWO_MODULES
module two.math;
#else
#include <stl/algorithm.h>
#endif

namespace two
{
	Animator Animator::me;

	Animator::Animator()
	{}

	void Animator::next_frame(size_t tick, size_t delta)
	{
		UNUSED(tick); UNUSED(delta);

		float elapsed = float(m_clock.step());
		for(Anim& anim : m_animations)
		{
			anim.m_cursor = min(anim.m_cursor + elapsed, anim.m_duration);
			float ratio = anim.m_cursor / anim.m_duration;
			Var value = anim.m_member->get(anim.m_object);
			interpolate(value, anim.m_source_value, anim.m_target_value, ratio);
			anim.m_member->set(anim.m_object, value);
		}

		prune(m_animations, [](Anim& anim) { return anim.m_cursor >= anim.m_duration; });
	}

	void Animator::animate(Ref object, Member& member, const Var& value, float duration)
	{
		//m_animations.push_back({ object, &member, member.get_value(object), value, duration, 0.f });
	}
}





#ifdef _MSC_VER
#	pragma warning (push)
#	pragma warning (disable : 4127)
#	pragma warning (disable : 4100)
#	pragma warning (disable : 4305)
#	pragma warning (disable : 5033) // @todo deal with this ?
#endif




#include <LinearMath/btScalar.h>
#include <LinearMath/btVector3.h>
#include <LinearMath/btQuaternion.h>
#include <LinearMath/btTransform.h>
#include <LinearMath/btTransformUtil.h>

namespace toy
{
	using namespace two;

	inline vec3 to_vec3(const btVector3& vec) { return { vec.x(), vec.y(), vec.z() }; }
	inline btVector3 to_btvec3(const vec3& vec) { return { vec.x, vec.y, vec.z }; }
	
	inline quat to_quat(const btQuaternion& q) { return { q.x(), q.y(), q.z(), q.w() }; }
	inline btQuaternion to_btquat(const quat& q) { return { q.x, q.y, q.z, q.w }; }

	inline Colour to_colour(const btVector3& col) { return { col.x(), col.y(), col.z() }; }
}

#include <BulletCollision/CollisionDispatch/btGhostObject.h>
#include <BulletCollision/CollisionShapes/btConvexHullShape.h>
#include <BulletCollision/CollisionShapes/btSphereShape.h>
#include <BulletCollision/CollisionShapes/btStaticPlaneShape.h>
#include <btBulletCollisionCommon.h>

#ifdef _MSC_VER
#	pragma warning (pop)
#endif

namespace toy
{
	BulletShape::BulletShape(unique<btCollisionShape> shape)
		: shape(move(shape))
	{}

	BulletShape::BulletShape(unique<btCollisionShape> shape, unique<btStridingMeshInterface> mesh)
		: shape(move(shape))
		, mesh(move(mesh))
	{}

	BulletShape::BulletShape(BulletShape&& other)
		: shape(move(other.shape))
		, mesh(move(other.mesh))
	{}

	BulletShape& BulletShape::operator=(BulletShape&& other)
	{
		this->shape = move(other.shape);
		this->mesh = move(other.mesh);
		return *this;
	}

	BulletShape::~BulletShape()
	{}

	BulletShape createGeometryShape(Geometry& geometry)
	{
		unique<btTriangleMesh> trimesh = make_unique<btTriangleMesh>();

		btVector3 vertex[3];
		for(const Tri& triangle : geometry.m_triangles)
		{
			for(int i = 0; i < 3; ++i)
			{
				uint32_t index = (&triangle.a)[i];
				assert(index <= geometry.m_vertices.size());
				vertex[i] = to_btvec3(geometry.m_vertices[index].m_position);
			}

			trimesh->addTriangle(vertex[0], vertex[1], vertex[2]);
		}

		const bool useQuantizedAABB = true;
		unique<btCollisionShape> meshShape(make_unique<btBvhTriangleMeshShape>(trimesh.get(), useQuantizedAABB));

		return BulletShape(move(meshShape), move(trimesh));
	}

	BulletShape createConvexHullShape(ConvexHull& hull)
	{
		unique<btConvexHullShape> convexHull = make_unique<btConvexHullShape>();
		for(const vec3& point : hull.m_vertices)
			convexHull->addPoint(to_btvec3(point));
		return BulletShape(move(convexHull));
	}

	DispatchBulletShape::DispatchBulletShape()
	{
		dispatch_branch<Plane>	    (*this, +[](Plane& plane) -> BulletShape { return{ make_unique<btStaticPlaneShape>(to_btvec3(plane.m_normal), plane.m_distance) }; });
		dispatch_branch<Quad>	    (*this, +[](Quad& quad) -> BulletShape { Plane plane = { quad.m_vertices[0], quad.m_vertices[1], quad.m_vertices[2] }; return{ make_unique<btStaticPlaneShape>(to_btvec3(plane.m_normal), plane.m_distance) }; });
		dispatch_branch<Sphere>     (*this, +[](Sphere& sphere) -> BulletShape { return{ make_unique<btSphereShape>(sphere.m_radius) }; });
		dispatch_branch<Capsule>    (*this, +[](Capsule& capsule) -> BulletShape { return{ make_unique<btCapsuleShape>(capsule.m_radius, capsule.m_height) }; });
		dispatch_branch<Cylinder>   (*this, +[](Cylinder& cylinder) -> BulletShape { return{ make_unique<btCylinderShape>(btVector3(cylinder.m_radius, cylinder.m_height / 2.f, cylinder.m_radius)) }; });
		dispatch_branch<Cube>       (*this, +[](Cube& box) -> BulletShape { return{ make_unique<btBoxShape>(to_btvec3(box.m_extents)) }; });
		dispatch_branch<ConvexHull> (*this, createConvexHullShape);
		dispatch_branch<Geometry>   (*this, createGeometryShape);
	};

	BulletShape DispatchBulletShape::dispatch(CollisionShape& collision_shape)
	{
		Ref shape = Ref(collision_shape.m_shape.get());
		return Dispatch::dispatch(shape); 
	}

	BulletCollider::BulletCollider(BulletMedium& bullet_world, HSpatial spatial, HCollider collider, CollisionShape& collision_shape, bool create)
		: m_bullet_world(bullet_world)
		, m_spatial(spatial)
		, m_collider(collider)
		, m_collision_shape(DispatchBulletShape::me().dispatch(collision_shape))
	{
		collider->m_motion_state.m_transform_source = this;

		if(create)
		{
			m_collision_object = make_unique<btCollisionObject>();
			this->setup(spatial, *m_collision_object);
		}

		collision_shape.m_shape = {};
	}

	BulletCollider::~BulletCollider()
	{}

	void BulletCollider::setup(Spatial& spatial, btCollisionObject& collision_object)
	{
		collision_object.setUserPointer((void*) m_collider.m_handle);
		collision_object.setCollisionFlags(0);
		collision_object.setCollisionShape(m_collision_shape.shape.get());
		//collision_object->setContactProcessingThreshold(0.1f);

		m_collider->m_motion_state.update_transform(spatial);
	}

	void BulletCollider::update_transform(const vec3& position, const quat& rotation)
	{
		//printf("bullet set transform rotation %.2f, %.2f, %.2f, %.2f\n", rotation.x, rotation.y, rotation.y, rotation.z);
		m_collision_object->setWorldTransform(btTransform(to_btquat(rotation), to_btvec3(position)));
	}

	void BulletCollider::update_transform()
	{
		Spatial& spatial = m_spatial;
		this->update_transform(spatial.absolute_position(), spatial.absolute_rotation());
	}

	void BulletCollider::project(const vec3& position, vector<Collision>& collisions, short int mask)
	{
		Spatial& spatial = m_spatial;
		m_bullet_world.project(m_collider, position, spatial.m_rotation, collisions, mask);
	}

	void BulletCollider::raycast(const vec3& target, vector<Collision>& collisions, short int mask)
	{
		Spatial& spatial = m_spatial;
		Collision coll = m_bullet_world.raycast(m_collider, spatial.m_position, target, mask);
		collisions.push_back(coll);
	}

	Collision BulletCollider::raycast(const vec3& target, short int mask)
	{
		Spatial& spatial = m_spatial;
		return m_bullet_world.raycast(m_collider, spatial.m_position, target, mask);
	}
}




class TOY_CORE_EXPORT btMotionState;
#include <LinearMath/btMotionState.h>

namespace toy
{
    class TOY_CORE_EXPORT BulletMotionState : public btMotionState
    {
    public:
        BulletMotionState(HSpatial spatial, HCollider collider);

		HSpatial m_spatial;
		HCollider m_collider;

		virtual void getWorldTransform(btTransform& worldTransform) const;
		virtual void setWorldTransform(const btTransform& worldTransform);
    };
}


namespace toy
{
    BulletMotionState::BulletMotionState(HSpatial spatial, HCollider collider)
        : btMotionState()
		, m_spatial(spatial)
		, m_collider(collider)
    {}

	void BulletMotionState::getWorldTransform(btTransform& transform) const
	{
		MotionState::Transform t = m_collider->m_motion_state.transform(m_spatial);
		transform.setOrigin(to_btvec3(t.m_position));
		transform.setRotation(to_btquat(t.m_rotation));
	}

    void BulletMotionState::setWorldTransform(const btTransform& transform)
    {
		m_collider->m_motion_state.sync_transform(m_spatial, to_vec3(transform.getOrigin()), to_quat(transform.getRotation()));
    }
}




#ifdef _MSC_VER
#	pragma warning (push)
#	pragma warning (disable : 4127)
#	pragma warning (disable : 4100)
#	pragma warning (disable : 4305)
#	pragma warning (disable : 5033) // @todo deal with this ?
#endif


#include <LinearMath/btMotionState.h>
#include <btBulletDynamicsCommon.h>

#ifdef _MSC_VER
#	pragma warning (pop)
#endif

namespace toy
{
    BulletSolid::BulletSolid(BulletMedium& bullet_world, BulletCollider& bullet_collider, HSpatial spatial, HCollider collider, HSolid solid)
		: m_rigid_body(nullptr)
		, m_motion_state(make_unique<BulletMotionState>(spatial, collider))
    {
		UNUSED(bullet_world);
		collider->m_motion_state.m_transform_source = this;
		collider->m_motion_state.m_motion_source = this;

		this->setup(bullet_collider, spatial, solid);
    }

	BulletSolid::~BulletSolid()
    {}

	void BulletSolid::setup(BulletCollider& collider, Spatial& spatial, Solid& solid)
	{
		btVector3 inertia;
		if(!solid.m_static)
			collider.m_collision_shape.shape->calculateLocalInertia(solid.m_mass, inertia);

		collider.m_collision_object = make_unique<btRigidBody>(solid.m_mass, m_motion_state.get(), collider.m_collision_shape.shape.get(), inertia);
		m_rigid_body = &static_cast<btRigidBody&>(*collider.m_collision_object);

		collider.setup(spatial, *collider.m_collision_object);

		//m_rigid_body->setFriction(0.6f);
		//m_rigid_body->setCollisionFlags(btCollisionObject::CF_KINEMATIC_OBJECT);

		if(solid.m_static)
		{
			m_rigid_body->setContactProcessingThreshold(0.02f);
			m_rigid_body->setCollisionFlags(btCollisionObject::CF_STATIC_OBJECT);
		}
	}

	vec3 BulletSolid::linear_velocity()
	{
		return to_vec3(m_rigid_body->getLinearVelocity());
	}

	vec3 BulletSolid::angular_velocity()
	{
		return to_vec3(m_rigid_body->getAngularVelocity());
	}

	void BulletSolid::set_linear_velocity(const vec3& force)
	{
		m_rigid_body->activate(true);
		m_rigid_body->setLinearVelocity(to_btvec3(force));
	}

	void BulletSolid::set_angular_velocity(const vec3& torque)
	{
		m_rigid_body->setAngularVelocity(to_btvec3(torque));
	}

	void BulletSolid::set_angular_factor(const vec3& factor)
	{
		m_rigid_body->setAngularFactor(to_btvec3(factor));
	}

	void BulletSolid::set_force(const vec3& force)
	{
		m_rigid_body->activate(true);
		//m_rigid_body->set_linear_velocity(to_btvec3(force));
		//m_rigid_body->applyCentralForce(to_btvec3(force));
		m_rigid_body->applyCentralImpulse(to_btvec3(force));
	}

	void BulletSolid::set_torque(const vec3& torque)
	{
		m_rigid_body->activate(true);
		//m_rigid_body->setAngularVelocity(to_btvec3(torque));
		m_rigid_body->applyTorqueImpulse(to_btvec3(torque));
	}

	void BulletSolid::impulse_force(const vec3& force)
	{
		m_rigid_body->activate(true);
		m_rigid_body->applyCentralImpulse(to_btvec3(force));
	}

	void BulletSolid::impulse(const vec3& force, const vec3& point)
	{
		m_rigid_body->activate(true);
		m_rigid_body->applyImpulse(to_btvec3(force), to_btvec3(point));
	}

	void BulletSolid::impulse_torque(const vec3& torque)
	{
		m_rigid_body->activate(true);
		m_rigid_body->applyTorqueImpulse(to_btvec3(torque));
	}

	void BulletSolid::update_transform(const vec3& position, const quat& rotation)
	{
		m_rigid_body->activate();
		m_rigid_body->setWorldTransform(btTransform(to_btquat(rotation), to_btvec3(position)));
	}

	void BulletSolid::update_motion(const vec3& linear_velocity, const vec3& angular_velocity)
	{
		m_rigid_body->activate();
		m_rigid_body->setLinearVelocity(to_btvec3(linear_velocity));
		m_rigid_body->setAngularVelocity(to_btvec3(angular_velocity));
	}
}

#ifndef USE_STL
#include <stl/vector.hpp>
#endif

#ifdef _MSC_VER
#	pragma warning (push)
#	pragma warning (disable : 4127) // members are private, so there's no risk them being accessed by the user
#	pragma warning (disable : 4100)
#	pragma warning (disable : 4305)
#	pragma warning (disable : 5033) // @todo deal with this ?
#endif


#include <BulletDynamics/ConstraintSolver/btSequentialImpulseConstraintSolver.h>
#include <BulletDynamics/Dynamics/btDiscreteDynamicsWorld.h>

#include <BulletCollision/CollisionDispatch/btGhostObject.h>
#include <btBulletCollisionCommon.h>

#ifdef _MSC_VER
#	pragma warning (pop)
#endif

#ifdef TRIGGER_COLLISIONS
extern CollisionStartedCallback gCollisionStartedCallback;
extern CollisionEndedCallback gCollisionEndedCallback;
#endif

namespace toy
{
#ifdef TRIGGER_COLLISIONS
	static void collisionStarted(btPersistentManifold* manifold)
	{
	}

	static void collisionEnded(btPersistentManifold* manifold)
	{
		Collider* col0 = (Collider*)((btCollisionObject*)manifold->getBody0())->getUserPointer();
		Collider* col1 = (Collider*)((btCollisionObject*)manifold->getBody1())->getUserPointer();

		if(&col0->m_spatial == &col1->m_spatial)
			return;

		if(col0->m_object && col1->m_object)
		{
			// printf << "Remove contact " << col0->m_spatial.m_id << " : " << col1->m_spatial.m_id << endl;
			col0->m_object->remove_contact(*col1);
			col1->m_object->remove_contact(*col0); // @todo : replace this with buffered action (set a flag on bullet object ?) to not loop infinitely from bullet code
		}
	}
#endif

	HCollider object_collider(BulletWorld& bullet_world, const btCollisionObject& object)
	{
		SparsePool<Collider>& pool = bullet_world.m_world.pool<Collider>();
		uint32_t handle = uint32_t((uintptr_t)object.getUserPointer());
		return { pool, handle };
	}

#define BULLET_WORLD_SCALE 10000.f

    BulletMedium::BulletMedium(World& world, BulletWorld& bullet_world, Medium& medium)
        : PhysicMedium(world, medium)
		, m_bullet_world(bullet_world)
	{
		static btDefaultCollisionConfiguration configuration;

		m_collision_dispatcher = make_unique<btCollisionDispatcher>(&configuration);
		m_broadphase_interface = make_unique<btAxisSweep3>(btVector3(-1.f, -1.f, -1.f) * BULLET_WORLD_SCALE, btVector3(1.f, 1.f, 1.f) * BULLET_WORLD_SCALE, uint16_t(32000)); // @crash btAssert(m_firstFreeHandle) is limited by this setting
		//, m_broadphaseInterface(make_unique<btDbvtBroadphase>()) // @crash btAssert(m_firstFreeHandle) is limited by this setting

		if(medium.m_solid)
		{
			m_constraint_solver = make_unique<btSequentialImpulseConstraintSolver>();
			m_collision_world = make_unique<btDiscreteDynamicsWorld>(m_collision_dispatcher.get(), m_broadphase_interface.get(), m_constraint_solver.get(), &configuration);
			m_dynamics_world = static_cast<btDiscreteDynamicsWorld*>(m_collision_world.get());
		}
		else
		{
			m_collision_world = make_unique<btCollisionWorld>(m_collision_dispatcher.get(), m_broadphase_interface.get(), &configuration);
		}
	}

    BulletMedium::~BulletMedium()
    {}

	object<ColliderImpl> BulletMedium::make_collider(HCollider collider)
	{
		return oconstruct<BulletCollider>(*this, collider->m_spatial, collider, collider->m_collision_shape);
	}

	object<SolidImpl> BulletMedium::make_solid(HSolid solid)
	{
		return oconstruct<BulletSolid>(*this, as<BulletCollider>(*solid->m_collider->m_impl), solid->m_spatial, solid->m_collider, solid);
	}

	void BulletMedium::add_solid(HCollider collider, HSolid solid)
	{
		collider->m_impl = this->make_collider(collider);
		solid->m_impl = this->make_solid(solid);
		m_dynamics_world->addRigidBody(as<BulletSolid>(*solid->m_impl).m_rigid_body, collider->m_group, m_medium.mask(collider->m_group));
	}

	void BulletMedium::remove_solid(HCollider collider, HSolid solid)
	{
		m_dynamics_world->removeRigidBody(as<BulletSolid>(*solid->m_impl).m_rigid_body);
		this->remove_contacts(collider.m_handle);
		solid->m_impl = nullptr;
		collider->m_impl = nullptr;
	}

	void BulletMedium::add_collider(HCollider collider)
	{
		collider->m_impl = this->make_collider(collider);
		m_collision_world->addCollisionObject(as<BulletCollider>(*collider->m_impl).m_collision_object.get(), collider->m_group, m_medium.mask(collider->m_group));
	}

	void BulletMedium::remove_collider(HCollider collider)
	{
		m_collision_world->removeCollisionObject(as<BulletCollider>(*collider->m_impl).m_collision_object.get());
		this->remove_contacts(collider.m_handle);
		collider->m_impl = nullptr;
	}

	class ContactCheck : public btCollisionWorld::ContactResultCallback
	{
	public:
		struct Contact { const btCollisionObject* first; const btCollisionObject* second; btVector3 position; };

		ContactCheck(float margin = 0.f)
			: m_margin(margin)
		{}

		ContactCheck& operator=(const ContactCheck&) = delete;

		btScalar addSingleResult(btManifoldPoint &cp, const btCollisionObjectWrapper *colObj0, int partId0, int index0, const btCollisionObjectWrapper *colObj1, int partId1, int index1)
		{
			UNUSED(index0); UNUSED(index1); UNUSED(partId0); UNUSED(partId1);
			if(cp.getDistance() < m_margin)
				m_contacts.push_back({ colObj0->m_collisionObject, colObj1->m_collisionObject, btVector3(0.f, 0.f, 0.f) });

			return 0.f;
		}

		vector<Contact> m_contacts;
		float m_margin;
	};

	void project_test(btCollisionWorld& collision_world, btCollisionObject& collision_object, ContactCheck& callback, const vec3& position, const quat& rotation, short int mask)
	{
		btTransform transform = collision_object.getWorldTransform();
		collision_object.setWorldTransform(btTransform(to_btquat(rotation), to_btvec3(position)));

		callback.m_collisionFilterGroup = mask;
		callback.m_collisionFilterMask = mask;

		collision_world.updateSingleAabb(&collision_object);
		collision_world.contactTest(&collision_object, callback);

		collision_object.setWorldTransform(transform);
	}

	void ray_test(btCollisionWorld& collision_world, btCollisionWorld::RayResultCallback& callback, const vec3& start, const vec3& end, short int mask)
	{
		callback.m_collisionFilterMask = mask;
		callback.m_collisionFilterGroup = btBroadphaseProxy::AllFilter;
		collision_world.rayTest(to_btvec3(start), to_btvec3(end), callback);
	}

	void BulletMedium::project(HCollider collider, const vec3& position, const quat& rotation, vector<Collision>& collisions, short int mask)
	{
		ContactCheck callback;
		BulletCollider& bullet_collider = as<BulletCollider>(*collider->m_impl);
		project_test(*m_collision_world, *bullet_collider.m_collision_object, callback, position, rotation, mask);

		SparsePool<Collider>& pool = m_bullet_world.m_world.pool<Collider>();

		for(ContactCheck::Contact& contact : callback.m_contacts)
		{
			HCollider first = { pool, uint32_t((uintptr_t)contact.first->getUserPointer()) };
			HCollider second = { pool, uint32_t((uintptr_t)contact.second->getUserPointer()) };
			collisions.push_back({ collider, second.m_handle == collider.m_handle ? first : second, to_vec3(contact.position) });
		}
	}
	
	void BulletMedium::raycast(HCollider collider, const vec3& start, const vec3& end, vector<Collision>& collisions, short int mask)
	{
		btCollisionWorld::AllHitsRayResultCallback callback(to_btvec3(start), to_btvec3(end));
		ray_test(*m_collision_world, callback, start, end, mask);

		SparsePool<Collider>& pool = m_bullet_world.m_world.pool<Collider>();

		for(int i = 0; i < callback.m_collisionObjects.size(); ++i)
		{
			HCollider collision = { pool, uint32_t((uintptr_t)callback.m_collisionObjects[i]->getUserPointer()) };
			collisions.push_back({ collider, collision, to_vec3(callback.m_hitPointWorld[i]) });
		}
	}

	Collision BulletMedium::raycast(HCollider collider, const vec3& start, const vec3& end, short int mask)
	{
		btCollisionWorld::ClosestRayResultCallback callback(to_btvec3(start), to_btvec3(end));
		ray_test(*m_collision_world, callback, start, end, mask);

		if(callback.m_collisionObject)
			return { collider, object_collider(m_bullet_world, *callback.m_collisionObject), to_vec3(callback.m_hitPointWorld) };
		return {};
	}

	void BulletMedium::remove_contacts(uint32_t collider)
	{
		for(int i = int(m_contacts.size()) - 1; i >= 0; --i)
		{
			Contact& contact = *m_contacts[i];
			if(contact.m_col0 == collider || contact.m_col1 == collider)
				this->remove_contact(contact, i);
		}
	}

	void BulletMedium::remove_contact(Contact& contact, size_t index)
	{
		SparsePool<Collider>& pool = m_bullet_world.m_world.pool<Collider>();

		Collider& first = pool.get(contact.m_col0);
		Collider& second = pool.get(contact.m_col1);

		if(first.m_object && second.m_object)
		{
			first.m_object->remove_contact(second, *second.m_object);
			second.m_object->remove_contact(first, *first.m_object);
		}

		m_contacts.back()->m_index = index;
		swap(m_contacts[index], m_contacts.back());
		m_contacts.pop_back();

		remove_contact(contact.m_col0, contact.m_col1);
	}

	void BulletMedium::update_contacts()
	{
#ifndef TRIGGER_COLLISIONS
		btManifoldArray manifoldArray;

		SparsePool<Collider>& pool = m_bullet_world.m_world.pool<Collider>();

		int numManifolds = m_collision_world->getDispatcher()->getNumManifolds();
		for(int i = 0; i<numManifolds; i++)
		{
			btPersistentManifold* manifold = m_collision_world->getDispatcher()->getManifoldByIndexInternal(i);

			uint32_t col0 = uint32_t((uintptr_t)((btCollisionObject*)manifold->getBody0())->getUserPointer());
			uint32_t col1 = uint32_t((uintptr_t)((btCollisionObject*)manifold->getBody1())->getUserPointer());

			Collider& first = pool.get(col0);
			Collider& second = pool.get(col1);

			if(col0 == col1 || first.m_object == second.m_object)
				continue;

			int numContacts = manifold->getNumContacts();
			for(int j = 0; j<numContacts; j++)
			{
				btManifoldPoint& pt = manifold->getContactPoint(j);

				if(pt.getDistance() < 0.f)
				{
					Contact& contact = this->find_contact(col0, col1);

					if(contact.m_tick == 0)
					{
						if(first.m_object && second.m_object)
						{
							first.m_object->add_contact(second, *second.m_object);
							second.m_object->add_contact(first, *first.m_object);
						}

						contact.m_col0 = col0;
						contact.m_col1 = col1;
						contact.m_index = m_contacts.size();
						m_contacts.push_back(&contact);
					}

					contact.m_tick = m_last_tick;
				}
			}
		}

		for(int i = int(m_contacts.size()) - 1; i >= 0; --i)
		{
			Contact& contact = *m_contacts[i];
			if(contact.m_tick < m_last_tick)
				this->remove_contact(contact, i);
		}
#endif
	}

	void BulletMedium::remove_contact(uint32_t col0, uint32_t col1)
	{
		m_hash_contacts.erase(pair_hash(col0, col1));
	}

	BulletMedium::Contact& BulletMedium::find_contact(uint32_t col0, uint32_t col1)
	{
		return m_hash_contacts[pair_hash(col0, col1)];
	}

    // @note : this assume that we cap the framerate at 120fps, and that it shouldn't go lower than 12fps
    void BulletMedium::next_frame(size_t tick, size_t delta)
    {
		m_last_tick = tick;

		if(m_dynamics_world)
#ifdef TWO_PLATFORM_EMSCRIPTEN
			m_dynamics_world->stepSimulation(float(delta * c_tick_interval), 3, 0.032f);
#else
			m_dynamics_world->stepSimulation(float(delta * c_tick_interval), 3);
#endif
		else
			m_collision_world->performDiscreteCollisionDetection();

		this->update_contacts();
    }

	BulletWorld::BulletWorld(World& world)
		: PhysicWorld(world)
    {
#ifdef TRIGGER_COLLISIONS
		gCollisionStartedCallback = collisionStarted;
		gCollisionEndedCallback = collisionEnded;
#endif
	}

	BulletWorld::~BulletWorld()
    {}

	object<PhysicMedium> BulletWorld::create_sub_world(Medium& medium)
	{
		return oconstruct<BulletMedium>(m_world, *this, medium);
	}

	vec3 BulletWorld::ground_point(const Ray& ray)
	{
		Collision collision = this->raycast(ray, CM_GROUND);
		return collision.m_hit_point;
	}

	Collision BulletWorld::raycast(const Ray& ray, short int mask)
	{
		BulletMedium& bullet_medium = as<BulletMedium>(this->sub_world(SolidMedium::me));
		return bullet_medium.raycast(HCollider(), ray.m_start, ray.m_end, mask);
	}
}

#ifdef TWO_MODULES
module toy.core
#else
#endif

namespace toy
{
	Entity Camera::create(ECS& ecs, HSpatial parent, const vec3& position, float lens_distance, float near, float far)
	{
		Entity entity = ecs.create<Spatial, Movable, toy::Camera>();
		ecs.set(entity, Spatial(parent, position, ZeroQuat));
		ecs.set(entity, Movable(position));
		ecs.set(entity, Camera(lens_distance, near, far));
		return entity;
	}

    Camera::Camera(float distance, float near, float far)
        : m_lens_distance(distance)
		, m_near(near)
        , m_far(far)
    {
		//calc_lens_position(spatial);
	}

	Camera::~Camera()
	{}
	
	void Camera::set_lens_distance(float distance)
	{
		m_lens_distance = distance;
		m_lens_updated = true;
	}

	void Camera::zoom(float amount)
	{
		m_lens_distance *= 1.f/amount;
		m_lens_updated = true;
	}

	void Camera::set_lens_angle(float angle)
	{
		m_lens_angle = angle;
		m_lens_updated = true;
	}

	void Camera::pitch_lens(float amount)
	{
		m_lens_angle += amount;
		m_lens_updated = true;
	}

	vec3 Camera::lens_direction(const Spatial& spatial)
	{
		return rotate(spatial.front(), -m_lens_angle, spatial.right());
	}

	void Camera::calc_lens_position(const Spatial& spatial)
	{
		m_lens_position = -this->lens_direction(spatial) * m_lens_distance;
		m_lens_position += spatial.absolute_position();
	}

	void Camera::calc_lens_rotation(const Spatial& spatial)
	{
		m_lens_rotation = spatial.absolute_rotation() * angle_axis(-m_lens_angle, to_vec3(Side::Right));
	}

	void Camera::next_frame(const Spatial& spatial, size_t tick, size_t delta)
	{
		UNUSED(delta);

		//if(m_spatial.m_last_updated > m_last_updated || m_lensUpdated)
		{
			calc_lens_position(spatial);
			calc_lens_rotation(spatial);
		}
		m_last_updated = tick;
		m_lens_updated = false;
	}

	void jump_camera_to(Spatial& spatial, Camera& camera, const vec3& target, float distance, float rotation)
	{
		animate(Ref(&camera), member(&Camera::m_lens_distance), var(distance), 1.f);
		animate(Ref(&as<Transform>(spatial)), member(&Transform::m_position), var(target), 1.f);
		animate(Ref(&as<Transform>(spatial)), member(&Transform::m_rotation), var(rotate(spatial.m_rotation, rotation, Y3)), 1.f);
	}

	void jump_camera_to(Spatial& spatial, toy::Camera& camera, const vec3& target, const quat& rotation, float distance, float angle, float duration)
	{
		animate(Ref(&camera), member(&toy::Camera::m_lens_distance), var(distance), duration);
		animate(Ref(&camera), member(&toy::Camera::m_lens_angle), var(angle), duration);
		animate(Ref(&as<Transform>(spatial)), member(&Transform::m_position), var(target), duration);
		animate(Ref(&as<Transform>(spatial)), member(&Transform::m_rotation), var(rotation), duration);
	}

	void move_camera_to(Spatial& spatial, Camera& camera, const vec3& target)
	{
		UNUSED(camera);
		animate(Ref(&as<Transform>(spatial)), member(&Transform::m_position), var(target), 1.f);
	}

	void jump_camera_to(Entity camera, const vec3& target, float distance, float rotation)
	{
		jump_camera_to(asa<Spatial>(camera), asa<Camera>(camera), target, distance, rotation);
	}

	void jump_camera_to(Entity camera, const vec3& target, const quat& rotation, float distance, float angle, float duration)
	{
		jump_camera_to(asa<Spatial>(camera), asa<Camera>(camera), target, rotation, distance, angle, duration);
	}

	void move_camera_to(Entity camera, const vec3& target)
	{
		move_camera_to(asa<Spatial>(camera), asa<Camera>(camera), target);
	}
}



namespace toy
{
	SoundMedium SoundMedium::me;

	SoundMedium::SoundMedium()
		: Medium("SoundMedium")
	{
		m_masks[CM_OBSTACLE] = CM_NOMASK;
		m_masks[CM_SOURCE] = CM_RECEPTOR;
		m_masks[CM_RECEPTOR] = CM_SOURCE;
	}
}



namespace toy
{
	VisualMedium VisualMedium::me;

	VisualMedium::VisualMedium()
		: Medium("VisualMedium")
	{	
		m_masks[CM_LIGHT] = CM_LIGHTREFLECTOR;
		m_masks[CM_LIGHTREFLECTOR] = CM_LIGHT;
	}
}






namespace toy
{
	vec3 to_2d(const vec3& vec) { return { vec.x, 0.f, vec.z }; }

	float angle_flat(const vec3& v1, const vec3& v2)
	{
		vec3 vec1 = normalize(vec3(v1.x, 0.f, v1.z));
		vec3 vec2 = normalize(vec3(v2.x, 0.f, v2.z));

		return oriented_angle(vec1, vec2, Y3);
	}

	bool spin_2d(Spatial& spatial, const vec3& axis, const vec3& target, float velocity, float time_step, float margin)
	{
		UNUSED(time_step); UNUSED(margin);
		vec3 direction = normalize(target - spatial.m_position);
		float total_angle = angle_flat(spatial.front(), direction);
		float angle = min(sign(total_angle) * velocity, total_angle);
		quat rotation = rotate(spatial.m_rotation, angle, axis);
		spatial.set_rotation(rotation);
		return angle == total_angle;
	}

	bool lookat_2d(Spatial& spatial, const vec3& axis, const vec3& target, float velocity, float time_step, float margin)
	{
		UNUSED(axis); UNUSED(velocity); UNUSED(time_step); UNUSED(margin);
		vec3 direction = normalize(target - spatial.m_position);
		float targetAngle = angle_flat(-Z3, direction);
		quat rotation = angle_axis(targetAngle, Y3);
		spatial.set_rotation(rotation);
		return true;
	}

	vec3 project_move_2d(Spatial& spatial, const vec3& target, float velocity, float time_step, float margin)
	{
		UNUSED(margin);
		vec3 direction = normalize(target - spatial.m_position);
		direction.y = 0.f;

		vec3 movement = direction * velocity * time_step;
		vec3 distance = target - spatial.m_position;
		distance.y = 0.f;

		if(length2(movement) >= length2(distance))
			return target;
		else
			return spatial.m_position + movement;
	}

	bool move_2d(Spatial& spatial, const vec3& target, float velocity, float time_step, float margin)
	{
		if(target == spatial.m_position)
			return true;

		vec3 position = project_move_2d(spatial, target, velocity, time_step, margin);
		spatial.set_position(position);
		return position == target;
	}

	bool move_2d(Spatial& spatial, Movable& movable, const vec3& target, float velocity, float time_step, float margin)
	{
		UNUSED(time_step); UNUSED(margin);
		if(target == spatial.m_position)
			return true;
		movable.set_linear_velocity(normalize(target - spatial.m_position) * velocity);
		return false;
	}

	vec3 clamp(const vec3& vec, float l)
	{
		return length(vec) > l ? normalize(vec) * l : vec;
	}

	bool steer_2d(Spatial& spatial, Movable& movable, const vec3& target, float velocity, float time_step, float margin)
	{
		UNUSED(time_step);
		vec3 segment = to_2d(target - spatial.absolute_position());
		float distance = length(segment);
		
		if(distance < margin)
			return true;

		const float seek_force = 0.5f;
		const float approach_radius = 0.35f;
		UNUSED(approach_radius);

		vec3 desired = segment / distance * velocity;
		vec3 steer = desired - movable.m_direction;
		steer = clamp(steer, seek_force);

		movable.m_direction += steer;
		movable.m_direction = clamp(movable.m_direction, velocity);
		if(distance < velocity / 10.f)
			movable.m_direction = clamp(movable.m_direction, distance + 0.01f);

		float angle = oriented_angle(normalize(movable.m_direction), -Z3, Y3);
		spatial.set_rotation(rotate(ZeroQuat, -angle, Y3));
		movable.set_linear_velocity(rotate(movable.m_direction, angle, Y3));

		return false;
	}

	bool steer_2d(Spatial& spatial, const vec3& target, float velocity, float time_step, float margin)
	{
		bool done = spin_2d(spatial, Y3, target, 1.f, time_step, margin);
		if(true) // m_agent.forecast(project_move_2d(spatial, target, velocity, time_step))
			done &= move_2d(spatial, target, velocity, time_step, margin);
		return done;
	}

	bool stick_2d(Spatial& spatial, const vec3& target, float velocity, float time_step, float margin)
	{
		//if(m_target.moving())
		//	m_target.stick(m_source);

		spin_2d(spatial, Y3, target, 1.f, time_step, margin);
		move_2d(spatial, target, velocity, time_step, margin);
		return false;
	}

	bool track_2d(Spatial& spatial, const vec3& target, float velocity, float time_step, float margin)
	{
		/*if(m_targetMovable && m_targetMovable->m_moving)
		{
			if(m_targetManoeuv)
				m_sticky.set_position(m_targetManoeuv->m_disq.closest(m_agent.m_disq));
			else
				m_sticky.set_position(m_agent.m_disq.attract(spatial.m_position, target.m_position, m_distance));
		}*/

		return steer_2d(spatial, target, velocity, time_step, margin);
	}

	Movable::Movable(const vec3& position)
		: m_previous_position(position)
	{}

	Movable::~Movable()
	{}

	void Movable::set_acceleration(const vec3& acceleration, const vec3& maxLinVel)
	{
		m_acceleration = acceleration;
		m_max_linear_velocity = maxLinVel;
		m_acceleration_updated = m_last_tick+1;
	}

	void Movable::modify_acceleration(const vec3& acceleration)
	{
		m_acceleration += acceleration;
		m_acceleration_updated = m_last_tick+1;
	}

    void Movable::set_linear_velocity(const vec3& linVel)
	{
		m_linear_velocity = linVel;
		m_updated = m_last_tick+1;
	}

	void Movable::modify_linear_velocity(const vec3& linVel)
	{
		m_linear_velocity += linVel;
		m_updated = m_last_tick+1;
	}

    void Movable::set_angular_velocity(const vec3& angVel)
	{
		m_angular_velocity = angVel;
		m_updated = m_last_tick+1;
	}

	void Movable::modify_angular_velocity(const vec3& angVel)
	{
		m_angular_velocity += angVel;
		m_updated = m_last_tick+1;
	}

    void Movable::next_frame(Spatial& spatial, size_t tick, size_t delta)
	{
		if(m_acceleration != vec3(0.f))
		{
			//m_linear_velocity += m_acceleration * (delta * float(TICK_INTERVAL));
			//if(m_linear_velocity > m_maxLinearVelocity)
			//	m_linear_velocity = m_maxLinearVelocity;
		}

		//if(m_linear_velocity != vec3(0.f) || m_angular_velocity != vec3(0.f))
		if((m_linear_velocity != vec3(0.f) || m_angular_velocity != vec3(0.f)) && m_motion_state == nullptr)
        {
			m_previous_position = spatial.m_position;

			btVector3 linear_vel = to_btvec3(rotate(spatial.m_rotation, m_linear_velocity));
			btVector3 angular_vel = to_btvec3(rotate(spatial.m_rotation, m_angular_velocity));

			btTransform current(to_btquat(spatial.m_rotation), to_btvec3(spatial.m_position));
            btTransform updated;
            btTransformUtil::integrateTransform(current, linear_vel, angular_vel, float(delta * c_tick_interval), updated);

			if(!linear_vel.isZero())
				spatial.set_position(to_vec3(updated.getOrigin()));
			if(!angular_vel.isZero())
				spatial.set_rotation(to_quat(updated.getRotation()));

#if 0
			printf("move spatial from (%.2f, %.2f, %.2f) to (%.2f, %.2f, %.2f)\n", m_previous_position.x, m_previous_position.y, m_previous_position.z,
																				  spatial.m_position.x, spatial.m_position.y, spatial.m_position.z);
#endif

			m_moving = true;
        }
		else
		{
			m_moving = false;
		}

		m_last_tick = tick;
    }
}


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

namespace toy
{
	struct BoundsItem
	{
		vec2 bmin;
		vec2 bmax;
		int i;
	};

	static int compareItemX(const void* va, const void* vb)
	{
		const BoundsItem* a = (const BoundsItem*)va;
		const BoundsItem* b = (const BoundsItem*)vb;
		if(a->bmin[0] < b->bmin[0])
			return -1;
		if(a->bmin[0] > b->bmin[0])
			return 1;
		return 0;
	}

	static int compareItemY(const void* va, const void* vb)
	{
		const BoundsItem* a = (const BoundsItem*)va;
		const BoundsItem* b = (const BoundsItem*)vb;
		if(a->bmin[1] < b->bmin[1])
			return -1;
		if(a->bmin[1] > b->bmin[1])
			return 1;
		return 0;
	}

	static void calcExtends(const BoundsItem* items, const int /*nitems*/, const int imin, const int imax, vec2& bmin, vec2& bmax)
	{
		bmin = items[imin].bmin;
		bmax = items[imin].bmax;

		for(int i = imin + 1; i < imax; ++i)
		{
			bmin = min(items[i].bmin, bmin);
			bmax = max(items[i].bmax, bmax);
		}
	}

	inline int longestAxis(float x, float y)
	{
		return y > x ? 1 : 0;
	}

	static void subdivide(BoundsItem* items, int nitems, int imin, int imax, int trisPerChunk,int& curNode, rcChunkyTriMeshNode* nodes, const int maxNodes,
						  int& curTri, int* outTris, const uint32_t* inTris)
	{
		int inum = imax - imin;
		int icur = curNode;

		if(curNode > maxNodes)
			return;

		rcChunkyTriMeshNode& node = nodes[curNode++];

		if(inum <= trisPerChunk)
		{
			// Leaf
			calcExtends(items, nitems, imin, imax, node.bmin, node.bmax);

			// Copy triangles.
			node.i = curTri;
			node.n = inum;

			for(int i = imin; i < imax; ++i)
			{
				const uint32_t* src = &inTris[items[i].i * 3];
				int* dst = &outTris[curTri * 3];
				curTri++;
				dst[0] = static_cast<int>(src[0]);
				dst[1] = static_cast<int>(src[1]);
				dst[2] = static_cast<int>(src[2]);
			}
		}
		else
		{
			// Split
			calcExtends(items, nitems, imin, imax, node.bmin, node.bmax);

			int	axis = longestAxis(node.bmax[0] - node.bmin[0],
				node.bmax[1] - node.bmin[1]);

			if(axis == 0)
			{
				// Sort along x-axis
				qsort(items + imin, inum, sizeof(BoundsItem), compareItemX);
			}
			else if(axis == 1)
			{
				// Sort along y-axis
				qsort(items + imin, inum, sizeof(BoundsItem), compareItemY);
			}

			int isplit = imin + inum / 2;

			// Left
			subdivide(items, nitems, imin, isplit, trisPerChunk, curNode, nodes, maxNodes, curTri, outTris, inTris);
			// Right
			subdivide(items, nitems, isplit, imax, trisPerChunk, curNode, nodes, maxNodes, curTri, outTris, inTris);

			int iescape = curNode - icur;
			// Negative index means escape.
			node.i = -iescape;
		}
	}

	bool rcCreateChunkyTriMesh(const float* verts, const uint32_t* tris, int ntris, int trisPerChunk, rcChunkyTriMesh* cm)
	{
		int nchunks = (ntris + trisPerChunk - 1) / trisPerChunk;

		cm->nodes = new/*memory*/rcChunkyTriMeshNode[nchunks * 4];
		if(!cm->nodes)
			return false;

		cm->tris = new/*memory*/int[ntris * 3];
		if(!cm->tris)
			return false;

		cm->ntris = ntris;

		// Build tree
		BoundsItem* items = new/*memory*/BoundsItem[ntris];
		if(!items)
			return false;

		for(int i = 0; i < ntris; i++)
		{
			const uint32_t* t = &tris[i * 3];
			BoundsItem& it = items[i];
			it.i = i;
			// Calc triangle XZ bounds.
			it.bmin[0] = it.bmax[0] = verts[t[0] * 3 + 0];
			it.bmin[1] = it.bmax[1] = verts[t[0] * 3 + 2];
			for(int j = 1; j < 3; ++j)
			{
				const float* v = &verts[t[j] * 3];
				if(v[0] < it.bmin[0]) it.bmin[0] = v[0];
				if(v[2] < it.bmin[1]) it.bmin[1] = v[2];

				if(v[0] > it.bmax[0]) it.bmax[0] = v[0];
				if(v[2] > it.bmax[1]) it.bmax[1] = v[2];
			}
		}

		int curTri = 0;
		int curNode = 0;
		subdivide(items, ntris, 0, ntris, trisPerChunk, curNode, cm->nodes, nchunks * 4, curTri, cm->tris, tris);

		delete[] items;

		cm->nnodes = curNode;

		// Calc max tris per node.
		cm->maxTrisPerChunk = 0;
		for(int i = 0; i < cm->nnodes; ++i)
		{
			rcChunkyTriMeshNode& node = cm->nodes[i];
			const bool isLeaf = node.i >= 0;
			if(!isLeaf) continue;
			if(node.n > cm->maxTrisPerChunk)
				cm->maxTrisPerChunk = node.n;
		}

		return true;
	}

	inline bool checkOverlapRect(const vec2& amin, const vec2& amax, const vec2& bmin, const vec2& bmax)
	{
		bool overlap = true;
		overlap = (amin[0] > bmax[0] || amax[0] < bmin[0]) ? false : overlap;
		overlap = (amin[1] > bmax[1] || amax[1] < bmin[1]) ? false : overlap;
		return overlap;
	}

	int rcGetChunksOverlappingRect(const rcChunkyTriMesh* cm, const vec2& bmin, const vec2& bmax, int* ids, const int maxIds)
	{
		// Traverse tree
		int i = 0;
		int n = 0;
		while(i < cm->nnodes)
		{
			const rcChunkyTriMeshNode* node = &cm->nodes[i];
			const bool overlap = checkOverlapRect(bmin, bmax, node->bmin, node->bmax);
			const bool isLeafNode = node->i >= 0;

			if(isLeafNode && overlap)
			{
				if(n < maxIds)
				{
					ids[n] = i;
					n++;
				}
			}

			if(overlap || isLeafNode)
				i++;
			else
			{
				const int escapeIndex = -node->i;
				i += escapeIndex;
			}
		}

		return n;
	}

	int rcGetChunksOverlappingSegment(const rcChunkyTriMesh* cm, const vec2& p, const vec2& q, int* ids, const int maxIds)
	{
		// Traverse tree
		int i = 0;
		int n = 0;
		while(i < cm->nnodes)
		{
			const rcChunkyTriMeshNode* node = &cm->nodes[i];
			const bool overlap = segment_aabb_intersection_2d(p, q, node->bmin, node->bmax);
			const bool isLeafNode = node->i >= 0;

			if(isLeafNode && overlap)
			{
				if(n < maxIds)
				{
					ids[n] = i;
					n++;
				}
			}

			if(overlap || isLeafNode)
				i++;
			else
			{
				const int escapeIndex = -node->i;
				i += escapeIndex;
			}
		}

		return n;
	}
}



#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <string.h>

#include <Recast.h>
#include <DetourNavMesh.h>
#include <DetourNavMeshBuilder.h>

namespace toy
{
	NavGeom::NavGeom(Geometry& geometry, cstring name)
		: m_geometry(geometry)
		, m_name(name)
		, m_ctx(make_unique<rcContext>())
	{}

	NavGeom::~NavGeom()
	{}

	bool NavGeom::build()
	{
		const float* verts = &m_geometry.m_vertices[0].m_position.x;
		const uint32_t* tris = &m_geometry.m_triangles[0].a;

		const int num_verts = int(m_geometry.m_vertices.size());
		const int num_tris = int(m_geometry.m_triangles.size());

		rcCalcBounds(verts, num_verts, value_ptr(m_geometry.m_bounds_min), value_ptr(m_geometry.m_bounds_max));

		m_chunkyMesh = make_unique<rcChunkyTriMesh>();
		if(!rcCreateChunkyTriMesh(verts, tris, num_tris, 256, m_chunkyMesh.get()))
		{
			m_ctx->log(RC_LOG_ERROR, "buildTiledNavigation: Failed to build chunky mesh.");
			return false;
		}

		return true;
	}

	bool NavGeom::raycastMesh(const vec3& src, const vec3& dst, float& tmin)
	{
		//vec3 dir = dst - src;

		// Prune hit ray.
		float btmin, btmax;
		if(!segment_aabb_intersection(src, dst, m_geometry.m_bounds_min, m_geometry.m_bounds_max, btmin, btmax))
			return false;
		vec2 p, q;
		p[0] = src[0] + (dst[0]-src[0])*btmin;
		p[1] = src[2] + (dst[2]-src[2])*btmin;
		q[0] = src[0] + (dst[0]-src[0])*btmax;
		q[1] = src[2] + (dst[2]-src[2])*btmax;
	
		int cid[512];
		const int ncid = rcGetChunksOverlappingSegment(m_chunkyMesh.get(), p, q, cid, 512);
		if(!ncid)
			return false;
	
		tmin = 1.0f;
		bool hit = false;
		//const float* verts = value_ptr(m_geometry.m_vertices[0].m_position);
	
		for(int i = 0; i < ncid; ++i)
		{
			const rcChunkyTriMeshNode& node = m_chunkyMesh->nodes[cid[i]];
			const int* tris = &m_chunkyMesh->tris[node.i*3];
			const int ntris = node.n;

			for(int j = 0; j < ntris*3; j += 3)
			{
				float t = 1;
				if(segment_triangle_intersection(src, dst, m_geometry.m_vertices[tris[j]].m_position,
															m_geometry.m_vertices[tris[j+1]].m_position,
															m_geometry.m_vertices[tris[j+2]].m_position, t))
				{
					if(t < tmin)
						tmin = t;
					hit = true;
				}
			}
		}
	
		return hit;
	}

	void NavGeom::addOffMeshConnection(const float* spos, const float* epos, const float rad,
										 unsigned char bidir, unsigned char area, unsigned short flags)
	{
		if(m_offMeshConCount >= MAX_OFFMESH_CONNECTIONS) return;
		float* v = &m_offMeshConVerts[m_offMeshConCount*3*2];
		m_offMeshConRads[m_offMeshConCount] = rad;
		m_offMeshConDirs[m_offMeshConCount] = bidir;
		m_offMeshConAreas[m_offMeshConCount] = area;
		m_offMeshConFlags[m_offMeshConCount] = flags;
		m_offMeshConId[m_offMeshConCount] = 1000 + m_offMeshConCount;
		rcVcopy(&v[0], spos);
		rcVcopy(&v[3], epos);
		m_offMeshConCount++;
	}

	void NavGeom::deleteOffMeshConnection(int i)
	{
		m_offMeshConCount--;
		float* src = &m_offMeshConVerts[m_offMeshConCount*3*2];
		float* dst = &m_offMeshConVerts[i*3*2];
		rcVcopy(&dst[0], &src[0]);
		rcVcopy(&dst[3], &src[3]);
		m_offMeshConRads[i] = m_offMeshConRads[m_offMeshConCount];
		m_offMeshConDirs[i] = m_offMeshConDirs[m_offMeshConCount];
		m_offMeshConAreas[i] = m_offMeshConAreas[m_offMeshConCount];
		m_offMeshConFlags[i] = m_offMeshConFlags[m_offMeshConCount];
	}

	void NavGeom::addConvexVolume(const float* verts, const int nverts,
									const float minh, const float maxh, unsigned char area)
	{
		if(m_volumeCount >= MAX_VOLUMES) return;
		ConvexVolume* vol = &m_volumes[m_volumeCount++];
		memset(vol, 0, sizeof(ConvexVolume));
		memcpy(vol->verts, verts, sizeof(float)*3*nverts);
		vol->hmin = minh;
		vol->hmax = maxh;
		vol->nverts = nverts;
		vol->area = area;
	}

	void NavGeom::deleteConvexVolume(int i)
	{
		m_volumeCount--;
		m_volumes[i] = m_volumes[m_volumeCount];
	}

}




#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <string.h>

#include <Recast.h>
#include <DetourNavMesh.h>
#include <DetourNavMeshBuilder.h>

namespace toy
{
	uint32_t navmesh_num_vertices(const Navmesh& navmesh)
	{
		const dtNavMesh& dt_navmesh = *navmesh.m_navmesh;

		uint32_t count = 0;
		for(int i = 0; i < dt_navmesh.getMaxTiles(); ++i)
		{
			const dtMeshTile* tile = dt_navmesh.getTile(i);
			if(tile->header)
				count += tile->header->polyCount * navmesh.m_vertsPerPoly;
		}
		return count;
	}

	ShapeSize size_shape_lines(const ProcShape& shape, const NavmeshShape& navmesh)
	{
		UNUSED(shape);
		uint16_t num_verts = uint16_t(navmesh_num_vertices(navmesh.m_navmesh));
		return { num_verts, uint16_t(num_verts * 2U) };
	}

	void draw_shape_lines(const ProcShape& shape, const NavmeshShape& navmesh_shape, MeshAdapter& writer)
	{
		UNUSED(shape);
		Navmesh& navmesh = navmesh_shape.m_navmesh;
		const dtNavMesh& dt_navmesh = *navmesh.m_navmesh;

		uint16_t index = 0;

		for(int t = 0; t < dt_navmesh.getMaxTiles(); ++t)
		{
			const dtMeshTile* tile = dt_navmesh.getTile(t);

			if(!tile->header)
				continue;

			for(int p = 0; p < tile->header->polyCount; ++p)
			{
				float r = randf(0.f, 1.f);
				float g = randf(0.f, 1.f);
				float b = randf(0.f, 1.f);

				Colour colour = { r, g, b, 1.f };

				for(int v = 0; v < tile->polys[p].vertCount; ++v)
				{
					size_t vertex_offset = tile->polys[p].verts[v] * 3;
					vec3 vertex = { tile->verts[vertex_offset], tile->verts[vertex_offset + 1], tile->verts[vertex_offset + 2] };

					writer.position(vertex)
						  .colour(colour);

				}

				for(uint16_t i = 0; i < tile->polys[p].vertCount; i++)
				{
					uint16_t i0 = index + i;
					uint16_t i1 = i + 1 < tile->polys[p].vertCount ? index + i + 1 : index;
					writer.line(i0, i1);
				}

				index += tile->polys[p].vertCount;
			}
		}
	}

	ShapeSize size_shape_triangles(const ProcShape& shape, const NavmeshShape& navmesh)
	{
		UNUSED(shape);
		uint16_t num_verts = uint16_t(navmesh_num_vertices(navmesh.m_navmesh));
		return { num_verts, uint16_t(num_verts * 3U) };
	}

	void draw_shape_triangles(const ProcShape& shape, const NavmeshShape& navmesh_shape, MeshAdapter& writer)
	{
		UNUSED(shape);
		Navmesh& navmesh = navmesh_shape.m_navmesh;
		const dtNavMesh& dt_navmesh = *navmesh.m_navmesh;

		uint16_t index = 0;

		for(int t = 0; t < dt_navmesh.getMaxTiles(); ++t)
		{
			const dtMeshTile* tile = dt_navmesh.getTile(t);

			if(!tile->header)
				continue;

			for(int p = 0; p < tile->header->polyCount; ++p)
			{
				float r = randf(0.f, 1.f);
				float g = randf(0.f, 1.f);
				float b = randf(0.f, 1.f);

				Colour colour = { r, g, b, 0.6f };

				vec3 center = vec3(0.f);

				for(int v = 0; v < tile->polys[p].vertCount; ++v)
				{

					size_t vertex_offset = tile->polys[p].verts[v] * 3;
					vec3 vertex = { tile->verts[vertex_offset], tile->verts[vertex_offset + 1], tile->verts[vertex_offset + 2] };

					center += vertex;

					writer.position(vertex)
						  .colour(colour);
				}

				center /= float(tile->polys[p].vertCount);
				
				writer.position(center)
					  .colour(colour);

				uint16_t center_index = index + tile->polys[p].vertCount;

				for(uint16_t i = 0; i < tile->polys[p].vertCount; i++)
				{
					uint16_t i0 = index + i;
					uint16_t i1 = i + 1 < tile->polys[p].vertCount ? index + i + 1 : index;
					writer.tri(i0, i1, center_index);
				}

				index += tile->polys[p].vertCount + 1;
			}
		}
	}

	struct NavmeshShapeDeclaration
	{
		NavmeshShapeDeclaration()
		{
			decl_shape<NavmeshShape>(DispatchDrawProcShape::me);
		}
	};

	Navblock::Navblock(HSpatial spatial, HWorldPage world_page, Navmesh& navmesh)
		: m_spatial(spatial)
		, m_world_page(world_page)
		, m_navmesh(&navmesh)
	{}

	Navblock::~Navblock()
	{}

	void Navblock::next_frame(const Spatial& spatial, const WorldPage& world_page, size_t tick, size_t delta)
	{
		UNUSED(tick); UNUSED(delta);
		
		if(m_auto_update && m_updated < world_page.m_last_rebuilt)
		{
			m_navmesh->update_block(*this);
			m_updated = spatial.m_last_tick;
		}
	}

	Navmesh::Navmesh(World& world)
		: rcTileMesh()
		, m_world(world)
	{
		static NavmeshShapeDeclaration decl;

		m_navgeom = make_unique<NavGeom>(m_geometry, m_world.m_name.c_str());
	}

	Navmesh::~Navmesh()
	{}

	void Navmesh::update_block(Navblock& navblock)
	{
		// @todo we are just appending here, should clear and update

		const Spatial& spatial = navblock.m_spatial;
		const WorldPage& world_page = navblock.m_world_page;

		for(const Geometry& geom : world_page.m_chunks)
		{
			if(geom.m_vertices.empty())
				return;

			printf("[info] Updating Navmesh geometry block with %zu vertices\n", geom.m_vertices.size());

			ShapeIndex offset = ShapeIndex(m_geometry.m_vertices.size());

			for(const Vertex& vertex : geom.m_vertices)
				m_geometry.m_vertices.push_back({ spatial.m_position + vertex.m_position });

			for(const Tri& tri : geom.m_triangles)
				m_geometry.m_triangles.push_back({ ShapeIndex(offset + tri.a), ShapeIndex(offset + tri.b), ShapeIndex(offset + tri.c) });

			m_dirty = true;
		}

	}

	void Navmesh::next_frame(size_t tick, size_t delta)
	{
		UNUSED(tick); UNUSED(delta);
		if(m_dirty)
		{
			this->build();
			m_dirty = false;
		}
	}

	void Navmesh::build()
	{
		m_navgeom->build();

		this->setupSettings();
		this->handleBuild();

		string name = m_world.m_name + ".nav";
		this->save(name.c_str());
	}

	void Navmesh::load()
	{
		this->setupSettings();

		string name = m_world.m_name + ".nav";
		this->load(name.c_str());
	}

	static const int NAVMESHSET_MAGIC = 'M'<<24 | 'S'<<16 | 'E'<<8 | 'T'; //'MSET';
	static const int NAVMESHSET_VERSION = 1;

	struct NavmeshSetHeader
	{
		int magic;
		int version;
		int numTiles;
		dtNavMeshParams params;
	};

	struct NavmeshTileHeader
	{
		dtTileRef tileRef;
		int dataSize;
	};

	void Navmesh::load(const char* path)
	{
		m_navmesh = this->_load(path);
	}

	void Navmesh::save(const char* path)
	{
		this->_save(path, m_navmesh);
	}

	void Navmesh::_save(const char* path, const dtNavMesh* mesh)
	{
		if(!mesh) return;
	
		FILE* fp = fopen(path, "wb");
		if(!fp)
			return;
	
		// Array header.
		NavmeshSetHeader header;
		header.magic = NAVMESHSET_MAGIC;
		header.version = NAVMESHSET_VERSION;
		header.numTiles = 0;
		for(int i = 0; i < mesh->getMaxTiles(); ++i)
		{
			const dtMeshTile* tile = mesh->getTile(i);
			if(!tile || !tile->header || !tile->dataSize) continue;
			header.numTiles++;
		}
		memcpy(&header.params, mesh->getParams(), sizeof(dtNavMeshParams));
		fwrite(&header, sizeof(NavmeshSetHeader), 1, fp);

		// Array tiles.
		for(int i = 0; i < mesh->getMaxTiles(); ++i)
		{
			const dtMeshTile* tile = mesh->getTile(i);
			if(!tile || !tile->header || !tile->dataSize) continue;

			NavmeshTileHeader tileHeader;
			tileHeader.tileRef = mesh->getTileRef(tile);
			tileHeader.dataSize = tile->dataSize;
			fwrite(&tileHeader, sizeof(tileHeader), 1, fp);

			fwrite(tile->data, tile->dataSize, 1, fp);
		}

		fclose(fp);
	}

	dtNavMesh* Navmesh::_load(const char* path)
	{
		FILE* fp = fopen(path, "rb");
		if(!fp) return 0;
	
		// Read header.
		NavmeshSetHeader header;
		fread(&header, sizeof(NavmeshSetHeader), 1, fp);
		if(header.magic != NAVMESHSET_MAGIC)
		{
			fclose(fp);
			return 0;
		}
		if(header.version != NAVMESHSET_VERSION)
		{
			fclose(fp);
			return 0;
		}
	
		dtNavMesh* mesh = dtAllocNavMesh();
		if(!mesh)
		{
			fclose(fp);
			return 0;
		}
		dtStatus status = mesh->init(&header.params);
		if(dtStatusFailed(status))
		{
			fclose(fp);
			return 0;
		}
		
		// Read tiles.
		for(int i = 0; i < header.numTiles; ++i)
		{
			NavmeshTileHeader tileHeader;
			fread(&tileHeader, sizeof(tileHeader), 1, fp);
			if(!tileHeader.tileRef || !tileHeader.dataSize)
				break;

			unsigned char* data = (unsigned char*)dtAlloc(tileHeader.dataSize, DT_ALLOC_PERM);
			if(!data) break;
			memset(data, 0, tileHeader.dataSize);
			fread(data, tileHeader.dataSize, 1, fp);
		
			mesh->addTile(data, tileHeader.dataSize, DT_TILE_FREE_DATA, tileHeader.tileRef, 0);
		}
	
		fclose(fp);
	
		return mesh;
	}

	NavmeshShape::NavmeshShape(Navmesh& navmesh)
		: Shape(type<NavmeshShape>())
		, m_navmesh(navmesh)
	{}

	object<Shape> NavmeshShape::clone() const { return oconstruct<NavmeshShape>(m_navmesh); }
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

#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <string.h>



#include <Recast.h>
#include <DetourNavMesh.h>
#include <DetourNavMeshBuilder.h>
#include <DetourCommon.h>
#include <DetourAlloc.h>
#include <DetourAssert.h>

#ifdef WIN32
#	define snprintf _snprintf
#endif

namespace toy
{
	class MyContext : public rcContext
	{
	public:
		virtual void doLog(const rcLogCategory category, const char* msg, const int len) { UNUSED(category); UNUSED(len); printf("%s\n", msg); }
	};

	inline unsigned int nextPow2(unsigned int v)
	{
		v--;
		v |= v >> 1;
		v |= v >> 2;
		v |= v >> 4;
		v |= v >> 8;
		v |= v >> 16;
		v++;
		return v;
	}

	inline unsigned int ilog2(unsigned int v)
	{
		unsigned int r;
		unsigned int shift;
		r = (v > 0xffff) << 4; v >>= r;
		shift = (v > 0xff) << 3; v >>= shift; r |= shift;
		shift = (v > 0xf) << 2; v >>= shift; r |= shift;
		shift = (v > 0x3) << 1; v >>= shift; r |= shift;
		r |= (v >> 1);
		return r;
	}


	rcTileMesh::rcTileMesh() :
		m_ctx(make_unique<rcContext>()),
		m_cfg(make_unique<rcConfig>())
	{
		memset(m_tileBmin, 0, sizeof(m_tileBmin));
		memset(m_tileBmax, 0, sizeof(m_tileBmax));
	}

	void rcTileMesh::setupSettings()
	{
		m_keepInterResults = true;

		const float* bmin = value_ptr(m_geometry.m_bounds_min);
		const float* bmax = value_ptr(m_geometry.m_bounds_max);
		//char text[64];
		int gw = 0, gh = 0;
		rcCalcGridSize(bmin, bmax, m_cellSize, &gw, &gh);
		const int ts = (int)m_tileSize;
		const int tw = (gw + ts-1) / ts;
		const int th = (gh + ts-1) / ts;

		// Max tiles and max polys affect how the tile IDs are caculated.
		// There are 22 bits available for identifying a tile and a polygon.
		int tileBits = rcMin((int)ilog2(nextPow2(tw*th)), 14);
		if(tileBits > 14) tileBits = 14;
		int polyBits = 22 - tileBits;

		m_maxTiles = 1 << tileBits;
		m_maxPolysPerTile = 1 << polyBits;
	}

	rcTileMesh::~rcTileMesh()
	{
		cleanup();
		dtFreeNavMesh(m_navmesh);
		m_navmesh = 0;
	}

	void rcTileMesh::cleanup()
	{
		delete [] m_triareas;
		m_triareas = 0;
		rcFreeHeightField(m_solid);
		m_solid = 0;
		rcFreeCompactHeightfield(m_chf);
		m_chf = 0;
		rcFreeContourSet(m_cset);
		m_cset = 0;
		rcFreePolyMesh(m_pmesh);
		m_pmesh = 0;
		rcFreePolyMeshDetail(m_dmesh);
		m_dmesh = 0;
	}

	void rcTileMesh::handleMeshChanged(Geometry& geom)
	{
		UNUSED(geom);
		//m_geom = &geom;

		cleanup();

		dtFreeNavMesh(m_navmesh);
		m_navmesh = 0;
	}

	bool rcTileMesh::handleBuild()
	{
		if(m_geometry.m_triangles.empty())
		{
			m_ctx->log(RC_LOG_ERROR, "buildTiledNavigation: No vertices and triangles.");
			return false;
		}

		dtFreeNavMesh(m_navmesh);

		m_navmesh = dtAllocNavMesh();
		if(!m_navmesh)
		{
			m_ctx->log(RC_LOG_ERROR, "buildTiledNavigation: Could not allocate navmesh.");
			return false;
		}

		dtNavMeshParams params;
		rcVcopy(params.orig, value_ptr(m_geometry.m_bounds_min));
		params.tileWidth = m_tileSize*m_cellSize;
		params.tileHeight = m_tileSize*m_cellSize;
		params.maxTiles = m_maxTiles;
		params.maxPolys = m_maxPolysPerTile;
	
		dtStatus status;
	
		status = m_navmesh->init(&params);
		if(dtStatusFailed(status))
		{
			m_ctx->log(RC_LOG_ERROR, "buildTiledNavigation: Could not init navmesh.");
			return false;
		}
	
		if(m_buildAll)
			buildAllTiles();

		return true;
	}

	void rcTileMesh::buildTile(const float* pos)
	{
		if(m_geometry.m_triangles.empty()) return;
		if(!m_navmesh) return;
		
		const float* bmin = value_ptr(m_geometry.m_bounds_min);
		const float* bmax = value_ptr(m_geometry.m_bounds_max);
	
		const float ts = m_tileSize*m_cellSize;
		const int tx = (int)((pos[0] - bmin[0]) / ts);
		const int ty = (int)((pos[2] - bmin[2]) / ts);
	
		m_tileBmin[0] = bmin[0] + tx*ts;
		m_tileBmin[1] = bmin[1];
		m_tileBmin[2] = bmin[2] + ty*ts;
	
		m_tileBmax[0] = bmin[0] + (tx+1)*ts;
		m_tileBmax[1] = bmax[1];
		m_tileBmax[2] = bmin[2] + (ty+1)*ts;
	
		m_ctx->resetLog();
	
		int dataSize = 0;
		unsigned char* data = buildTileMesh(tx, ty, m_tileBmin, m_tileBmax, dataSize);
	
		if(data)
		{
			// Remove any previous data (navmesh owns and deletes the data).
			m_navmesh->removeTile(m_navmesh->getTileRefAt(tx,ty,0),0,0);
		
			// Let the navmesh own the data.
			dtStatus status = m_navmesh->addTile(data,dataSize,DT_TILE_FREE_DATA,0,0);
			if(dtStatusFailed(status))
				dtFree(data);
		}
	
		m_ctx->log(RC_LOG_PROGRESS, "Build Tile (%d,%d):", tx,ty);
	}

	void rcTileMesh::getTilePos(const float* pos, int& tx, int& ty)
	{
		if(m_geometry.m_triangles.empty()) return;
	
		const float* bmin = value_ptr(m_geometry.m_bounds_min);
	
		const float ts = m_tileSize*m_cellSize;
		tx = (int)((pos[0] - bmin[0]) / ts);
		ty = (int)((pos[2] - bmin[2]) / ts);
	}

	void rcTileMesh::removeTile(const float* pos)
	{
		if(m_geometry.m_triangles.empty()) return;
		if(!m_navmesh) return;
	
		const float* bmin = value_ptr(m_geometry.m_bounds_min);
		const float* bmax = value_ptr(m_geometry.m_bounds_max);

		const float ts = m_tileSize*m_cellSize;
		const int tx = (int)((pos[0] - bmin[0]) / ts);
		const int ty = (int)((pos[2] - bmin[2]) / ts);
	
		m_tileBmin[0] = bmin[0] + tx*ts;
		m_tileBmin[1] = bmin[1];
		m_tileBmin[2] = bmin[2] + ty*ts;
	
		m_tileBmax[0] = bmin[0] + (tx+1)*ts;
		m_tileBmax[1] = bmax[1];
		m_tileBmax[2] = bmin[2] + (ty+1)*ts;
	
		m_navmesh->removeTile(m_navmesh->getTileRefAt(tx,ty,0),0,0);
	}

	void rcTileMesh::buildAllTiles()
	{
		if(m_geometry.m_triangles.empty()) return;
		if(!m_navmesh) return;
	
		const float* bmin = value_ptr(m_geometry.m_bounds_min);
		const float* bmax = value_ptr(m_geometry.m_bounds_max);
		int gw = 0, gh = 0;
		rcCalcGridSize(bmin, bmax, m_cellSize, &gw, &gh);
		const int ts = (int)m_tileSize;
		const int tw = (gw + ts-1) / ts;
		const int th = (gh + ts-1) / ts;
		const float tcs = m_tileSize*m_cellSize;


		// Start the build process.
		m_ctx->startTimer(RC_TIMER_TEMP);

		for(int y = 0; y < th; ++y)
		{
			for(int x = 0; x < tw; ++x)
			{
				m_tileBmin[0] = bmin[0] + x*tcs;
				m_tileBmin[1] = bmin[1];
				m_tileBmin[2] = bmin[2] + y*tcs;
			
				m_tileBmax[0] = bmin[0] + (x+1)*tcs;
				m_tileBmax[1] = bmax[1];
				m_tileBmax[2] = bmin[2] + (y+1)*tcs;
			
				int dataSize = 0;
				unsigned char* data = buildTileMesh(x, y, m_tileBmin, m_tileBmax, dataSize);
				if(data)
				{
					// Remove any previous data (navmesh owns and deletes the data).
					m_navmesh->removeTile(m_navmesh->getTileRefAt(x,y,0),0,0);
					// Let the navmesh own the data.
					dtStatus status = m_navmesh->addTile(data,dataSize,DT_TILE_FREE_DATA,0,0);
					if(dtStatusFailed(status))
						dtFree(data);
				}
			}
		}
	
		// Start the build process.	
		m_ctx->stopTimer(RC_TIMER_TEMP);

		m_totalBuildTimeMs = m_ctx->getAccumulatedTime(RC_TIMER_TEMP)/1000.0f;
	
	}

	void rcTileMesh::removeAllTiles()
	{
		const float* bmin = value_ptr(m_geometry.m_bounds_min);
		const float* bmax = value_ptr(m_geometry.m_bounds_max);
		int gw = 0, gh = 0;
		rcCalcGridSize(bmin, bmax, m_cellSize, &gw, &gh);
		const int ts = (int)m_tileSize;
		const int tw = (gw + ts-1) / ts;
		const int th = (gh + ts-1) / ts;
	
		for(int y = 0; y < th; ++y)
			for(int x = 0; x < tw; ++x)
				m_navmesh->removeTile(m_navmesh->getTileRefAt(x,y,0),0,0);
	}


	unsigned char* rcTileMesh::buildTileMesh(const int tx, const int ty, const float* bmin, const float* bmax, int& dataSize)
	{
		if(m_geometry.m_triangles.empty())
		{
			m_ctx->log(RC_LOG_ERROR, "buildNavigation: Input mesh is not specified.");
			return 0;
		}
	

		m_tileMemUsage = 0;
		m_tileBuildTime = 0;
	
		cleanup();
	
		const float* verts = &m_geometry.m_vertices[0].m_position.x;
		const int nverts = int(m_geometry.m_vertices.size());
		const int ntris = int(m_geometry.m_triangles.size());
		const rcChunkyTriMesh* chunkyMesh = m_navgeom->m_chunkyMesh.get();
		
		// Init build configuration from GUI
		//memset(&m_cfg, 0, sizeof(m_cfg));
		m_cfg->cs = m_cellSize;
		m_cfg->ch = m_cellHeight;
		m_cfg->walkableSlopeAngle = m_agentMaxSlope;
		m_cfg->walkableHeight = (int)ceilf(m_agentHeight / m_cfg->ch);
		m_cfg->walkableClimb = (int)floorf(m_agentMaxClimb / m_cfg->ch);
		m_cfg->walkableRadius = (int)ceilf(m_agentRadius / m_cfg->cs);
		m_cfg->maxEdgeLen = (int)(m_edgeMaxLen / m_cellSize);
		m_cfg->maxSimplificationError = m_edgeMaxError;
		m_cfg->minRegionArea = (int)rcSqr(m_regionMinSize);		// Note: area = size*size
		m_cfg->mergeRegionArea = (int)rcSqr(m_regionMergeSize);	// Note: area = size*size
		m_cfg->maxVertsPerPoly = (int)m_vertsPerPoly;
		m_cfg->tileSize = (int)m_tileSize;
		m_cfg->borderSize = m_cfg->walkableRadius + 3; // Reserve enough padding.
		m_cfg->width = m_cfg->tileSize + m_cfg->borderSize * 2;
		m_cfg->height = m_cfg->tileSize + m_cfg->borderSize * 2;
		m_cfg->detailSampleDist = m_detailSampleDist < 0.9f ? 0 : m_cellSize * m_detailSampleDist;
		m_cfg->detailSampleMaxError = m_cellHeight * m_detailSampleMaxError;
	
		rcVcopy(m_cfg->bmin, bmin);
		rcVcopy(m_cfg->bmax, bmax);
		m_cfg->bmin[0] -= m_cfg->borderSize*m_cfg->cs;
		m_cfg->bmin[2] -= m_cfg->borderSize*m_cfg->cs;
		m_cfg->bmax[0] += m_cfg->borderSize*m_cfg->cs;
		m_cfg->bmax[2] += m_cfg->borderSize*m_cfg->cs;
	
		// Reset build times gathering.
		m_ctx->resetTimers();
	
		// Start the build process.
		m_ctx->startTimer(RC_TIMER_TOTAL);
	
		m_ctx->log(RC_LOG_PROGRESS, "Building navigation:");
		m_ctx->log(RC_LOG_PROGRESS, " - %d x %d cells", m_cfg->width, m_cfg->height);
		m_ctx->log(RC_LOG_PROGRESS, " - %.1fK verts, %.1fK tris", nverts/1000.0f, ntris/1000.0f);

		// Allocate voxel heightfield where we rasterize our input data to.
		m_solid = rcAllocHeightfield();
		if(!m_solid)
		{
			m_ctx->log(RC_LOG_ERROR, "buildNavigation: Out of memory 'solid'.");
			return 0;
		}
		if(!rcCreateHeightfield(m_ctx.get(), *m_solid, m_cfg->width, m_cfg->height, m_cfg->bmin, m_cfg->bmax, m_cfg->cs, m_cfg->ch))
		{
			m_ctx->log(RC_LOG_ERROR, "buildNavigation: Could not create solid heightfield.");
			return 0;
		}
	
		// Allocate span that can hold triangle flags.
		// If you have multiple meshes you need to process, allocate
		// and span which can hold the max number of triangles you need to process.
		m_triareas = new/*memory*/unsigned char[chunkyMesh->maxTrisPerChunk];
		if(!m_triareas)
		{
			m_ctx->log(RC_LOG_ERROR, "buildNavigation: Out of memory 'm_triareas' (%d).", chunkyMesh->maxTrisPerChunk);
			return 0;
		}
	
		vec2 tbmin, tbmax;
		tbmin[0] = m_cfg->bmin[0];
		tbmin[1] = m_cfg->bmin[2];
		tbmax[0] = m_cfg->bmax[0];
		tbmax[1] = m_cfg->bmax[2];
		int cid[512];// TODO: Make grow when returning too many items.
		const int ncid = rcGetChunksOverlappingRect(chunkyMesh, tbmin, tbmax, cid, 512);
		if(!ncid)
			return 0;
	
		m_tileTriCount = 0;
	
		for(int i = 0; i < ncid; ++i)
		{
			const rcChunkyTriMeshNode& node = chunkyMesh->nodes[cid[i]];
			const int* tris = &chunkyMesh->tris[node.i*3];
			const int ntris = node.n;
		
			m_tileTriCount += ntris;
		
			memset(m_triareas, 0, ntris*sizeof(unsigned char));
			rcMarkWalkableTriangles(m_ctx.get(), m_cfg->walkableSlopeAngle,
									verts, nverts, tris, ntris, m_triareas);
		
			rcRasterizeTriangles(m_ctx.get(), verts, nverts, tris, m_triareas, ntris, *m_solid, m_cfg->walkableClimb);
		}
	
		if(!m_keepInterResults)
		{
			delete [] m_triareas;
			m_triareas = 0;
		}
	
		// Once all geometry is rasterized, we do initial pass of filtering to
		// remove unwanted overhangs caused by the conservative rasterization
		// as well as filter spans where the character cannot possibly stand.
		rcFilterLowHangingWalkableObstacles(m_ctx.get(), m_cfg->walkableClimb, *m_solid);
		rcFilterLedgeSpans(m_ctx.get(), m_cfg->walkableHeight, m_cfg->walkableClimb, *m_solid);
		rcFilterWalkableLowHeightSpans(m_ctx.get(), m_cfg->walkableHeight, *m_solid);
	
		// Compact the heightfield so that it is faster to type from now on.
		// This will result more cache coherent data as well as the neighbours
		// between walkable cells will be calculated.
		m_chf = rcAllocCompactHeightfield();
		if(!m_chf)
		{
			m_ctx->log(RC_LOG_ERROR, "buildNavigation: Out of memory 'chf'.");
			return 0;
		}
		if(!rcBuildCompactHeightfield(m_ctx.get(), m_cfg->walkableHeight, m_cfg->walkableClimb, *m_solid, *m_chf))
		{
			m_ctx->log(RC_LOG_ERROR, "buildNavigation: Could not build compact data.");
			return 0;
		}
	
		if(!m_keepInterResults)
		{
			rcFreeHeightField(m_solid);
			m_solid = 0;
		}

		// Erode the walkable area by agent radius.
		if(!rcErodeWalkableArea(m_ctx.get(), m_cfg->walkableRadius, *m_chf))
		{
			m_ctx->log(RC_LOG_ERROR, "buildNavigation: Could not erode.");
			return 0;
		}

		// (Optional) Mark areas.
		const ConvexVolume* vols = m_navgeom->getConvexVolumes();
		for(int i  = 0; i < m_navgeom->getConvexVolumeCount(); ++i)
			rcMarkConvexPolyArea(m_ctx.get(), vols[i].verts, vols[i].nverts, vols[i].hmin, vols[i].hmax, (unsigned char)vols[i].area, *m_chf);
	
		if(m_monotonePartitioning)
		{
			// Partition the walkable surface into simple regions without holes.
			if(!rcBuildRegionsMonotone(m_ctx.get(), *m_chf, m_cfg->borderSize, m_cfg->minRegionArea, m_cfg->mergeRegionArea))
			{
				m_ctx->log(RC_LOG_ERROR, "buildNavigation: Could not build regions.");
				return 0;
			}
		}
		else
		{
			// Prepare for region partitioning, by calculating distance field along the walkable surface.
			if(!rcBuildDistanceField(m_ctx.get(), *m_chf))
			{
				m_ctx->log(RC_LOG_ERROR, "buildNavigation: Could not build distance field.");
				return 0;
			}
		
			// Partition the walkable surface into simple regions without holes.
			if(!rcBuildRegions(m_ctx.get(), *m_chf, m_cfg->borderSize, m_cfg->minRegionArea, m_cfg->mergeRegionArea))
			{
				m_ctx->log(RC_LOG_ERROR, "buildNavigation: Could not build regions.");
				return 0;
			}
		}
 	
		// Create contours.
		m_cset = rcAllocContourSet();
		if(!m_cset)
		{
			m_ctx->log(RC_LOG_ERROR, "buildNavigation: Out of memory 'cset'.");
			return 0;
		}
		if(!rcBuildContours(m_ctx.get(), *m_chf, m_cfg->maxSimplificationError, m_cfg->maxEdgeLen, *m_cset))
		{
			m_ctx->log(RC_LOG_ERROR, "buildNavigation: Could not create contours.");
			return 0;
		}
	
		if(m_cset->nconts == 0)
		{
			return 0;
		}
	
		// Build polygon navmesh from the contours.
		m_pmesh = rcAllocPolyMesh();
		if(!m_pmesh)
		{
			m_ctx->log(RC_LOG_ERROR, "buildNavigation: Out of memory 'pmesh'.");
			return 0;
		}
		if(!rcBuildPolyMesh(m_ctx.get(), *m_cset, m_cfg->maxVertsPerPoly, *m_pmesh))
		{
			m_ctx->log(RC_LOG_ERROR, "buildNavigation: Could not triangulate contours.");
			return 0;
		}
	
		// Build detail mesh.
		m_dmesh = rcAllocPolyMeshDetail();
		if(!m_dmesh)
		{
			m_ctx->log(RC_LOG_ERROR, "buildNavigation: Out of memory 'dmesh'.");
			return 0;
		}
	
		if(!rcBuildPolyMeshDetail(m_ctx.get(), *m_pmesh, *m_chf,
								   m_cfg->detailSampleDist, m_cfg->detailSampleMaxError,
								   *m_dmesh))
		{
			m_ctx->log(RC_LOG_ERROR, "buildNavigation: Could build polymesh detail.");
			return 0;
		}
	
		if(!m_keepInterResults)
		{
			rcFreeCompactHeightfield(m_chf);
			m_chf = 0;
			rcFreeContourSet(m_cset);
			m_cset = 0;
		}
	
		unsigned char* navData = 0;
		int navDataSize = 0;
		if(m_cfg->maxVertsPerPoly <= DT_VERTS_PER_POLYGON)
		{
			if(m_pmesh->nverts >= 0xffff)
			{
				// The vertex indices are ushorts, and cannot point to more than 0xffff vertices.
				m_ctx->log(RC_LOG_ERROR, "Too many vertices per tile %d (max: %d).", m_pmesh->nverts, 0xffff);
				return 0;
			}
		
			// Update poly flags from areas.
			for(int i = 0; i < m_pmesh->npolys; ++i)
			{
				if(m_pmesh->areas[i] == RC_WALKABLE_AREA)
					m_pmesh->areas[i] = SAMPLE_POLYAREA_GROUND;
			
				if(m_pmesh->areas[i] == SAMPLE_POLYAREA_GROUND ||
					m_pmesh->areas[i] == SAMPLE_POLYAREA_GRASS ||
					m_pmesh->areas[i] == SAMPLE_POLYAREA_ROAD)
				{
					m_pmesh->flags[i] = SAMPLE_POLYFLAGS_WALK;
				}
				else if(m_pmesh->areas[i] == SAMPLE_POLYAREA_WATER)
				{
					m_pmesh->flags[i] = SAMPLE_POLYFLAGS_SWIM;
				}
				else if(m_pmesh->areas[i] == SAMPLE_POLYAREA_DOOR)
				{
					m_pmesh->flags[i] = SAMPLE_POLYFLAGS_WALK | SAMPLE_POLYFLAGS_DOOR;
				}
			}
		
			dtNavMeshCreateParams params;
			memset(&params, 0, sizeof(params));
			params.verts = m_pmesh->verts;
			params.vertCount = m_pmesh->nverts;
			params.polys = m_pmesh->polys;
			params.polyAreas = m_pmesh->areas;
			params.polyFlags = m_pmesh->flags;
			params.polyCount = m_pmesh->npolys;
			params.nvp = m_pmesh->nvp;
			params.detailMeshes = m_dmesh->meshes;
			params.detailVerts = m_dmesh->verts;
			params.detailVertsCount = m_dmesh->nverts;
			params.detailTris = m_dmesh->tris;
			params.detailTriCount = m_dmesh->ntris;
			params.offMeshConVerts = m_navgeom->m_offMeshConVerts;
			params.offMeshConRad = m_navgeom->m_offMeshConRads;
			params.offMeshConDir = m_navgeom->m_offMeshConDirs;
			params.offMeshConAreas = m_navgeom->m_offMeshConAreas;
			params.offMeshConFlags = m_navgeom->m_offMeshConFlags;
			params.offMeshConUserID = m_navgeom->m_offMeshConId;
			params.offMeshConCount = m_navgeom->m_offMeshConCount;
			params.walkableHeight = m_agentHeight;
			params.walkableRadius = m_agentRadius;
			params.walkableClimb = m_agentMaxClimb;
			params.tileX = tx;
			params.tileY = ty;
			params.tileLayer = 0;
			rcVcopy(params.bmin, m_pmesh->bmin);
			rcVcopy(params.bmax, m_pmesh->bmax);
			params.cs = m_cfg->cs;
			params.ch = m_cfg->ch;
			params.buildBvTree = true;
		
			if(!dtCreateNavMeshData(&params, &navData, &navDataSize))
			{
				m_ctx->log(RC_LOG_ERROR, "Could not build Detour navmesh.");
				return 0;
			}		
		}
		m_tileMemUsage = navDataSize/1024.0f;
	
		m_ctx->stopTimer(RC_TIMER_TOTAL);
	
		// Show performance stats.
		//duLogBuildTimes(*m_ctx, m_ctx->getAccumulatedTime(RC_TIMER_TOTAL));
		m_ctx->log(RC_LOG_PROGRESS, ">> Polymesh: %d vertices  %d polygons", m_pmesh->nverts, m_pmesh->npolys);
	
		m_tileBuildTime = m_ctx->getAccumulatedTime(RC_TIMER_TOTAL)/1000.0f;

		dataSize = navDataSize;
		return navData;
	}

	dtStatus rcTileMesh::getPolyHeight(dtPolyRef ref, const float* pos, float* height) const
	{
		dtAssert(m_navmesh);

		const dtMeshTile* tile = 0;
		const dtPoly* poly = 0;
		if(dtStatusFailed(m_navmesh->getTileAndPolyByRef(ref, &tile, &poly)))
			return DT_FAILURE | DT_INVALID_PARAM;
	
		if(poly->getType() == DT_POLYTYPE_OFFMESH_CONNECTION)
		{
			const float* v0 = &tile->verts[poly->verts[0]*3];
			const float* v1 = &tile->verts[poly->verts[1]*3];
			const float d0 = dtVdist(pos, v0);
			const float d1 = dtVdist(pos, v1);
			const float u = d0 / (d0+d1);
			if(height)
				*height = v0[1] + (v1[1] - v0[1]) * u;
			return DT_SUCCESS;
		}
		else
		{
			const unsigned int ip = (unsigned int)(poly - tile->polys);
			const dtPolyDetail* pd = &tile->detailMeshes[ip];
			for(int j = 0; j < pd->triCount; ++j)
			{
				const unsigned char* t = &tile->detailTris[(pd->triBase+j)*4];
				const float* v[3];
				for(int k = 0; k < 3; ++k)
				{
					if(t[k] < poly->vertCount)
						v[k] = &tile->verts[poly->verts[t[k]]*3];
					else
						v[k] = &tile->detailVerts[(pd->vertBase+(t[k]-poly->vertCount))*3];
				}
				float h;
				if(dtClosestHeightPointTriangle(pos, v[0], v[1], v[2], h))
				{
					if(height)
						*height = h;
					return DT_SUCCESS;
				}
			}
		}
	
		return DT_FAILURE | DT_INVALID_PARAM;
	}
}

#ifdef TWO_MODULES
module toy.core
#else
#endif

#include <DetourNavMeshQuery.h>

namespace toy
{
	Entity Waypoint::create(ECS& ecs, HSpatial parent, const vec3& position)
	{
		Entity entity = ecs.create<Spatial, Waypoint>();
		ecs.set(entity, Spatial(parent, position, ZeroQuat));
		ecs.set(entity, Waypoint());
		return entity;
	}

	DetourPath::DetourPath(Pathfinder& pathfinder, const vec3& origin, const vec3& destination)
		: m_pathfinder(pathfinder)
		, m_origin(origin)
		, m_destination(destination)
	{}
	
	void DetourPath::clear()
	{
		m_currentPoly = 0;
		m_waypoints.clear();
		m_poly_path.clear();
	}

	bool DetourPath::compute()
	{
		dtNavMeshQuery& query = *m_pathfinder.m_query;
		dtQueryFilter& filter = *m_pathfinder.m_filter;

		this->clear();

		vec3 extents = { 0.0f, 2.0f, 0.0f };
		dtPolyRef start_poly;
		dtPolyRef end_poly;
		vec3 start_pos;
		vec3 end_pos;

		if(!query.findNearestPoly(&m_origin[0], &extents[0], &filter, &start_poly, &start_pos[0]))
			return false;

		if(!query.findNearestPoly(&m_destination[0], &extents[0], &filter, &end_poly, &end_pos[0]))
			return false;

		vector<dtPolyRef> poly_path(m_pathfinder.m_max_polys);
		int polyCount = 0;

		if(!query.findPath(start_poly, end_poly, &start_pos[0], &end_pos[0], &filter, poly_path.data(), &polyCount, int(m_pathfinder.m_max_polys)))
			return false;

		vector<vec3> point_path(m_pathfinder.m_max_waypoints);
		vector<dtPolyRef> poly_refs(m_pathfinder.m_max_waypoints);

		int count;

		if(!query.findStraightPath(&start_pos[0], &end_pos[0], poly_path.data(), polyCount, value_ptr(point_path[0]), 0, poly_refs.data(), &count, int(m_pathfinder.m_max_waypoints)))
			return false;

		for(int i = count - 1; i >= 0; i--)
			m_path.push_back(point_path[i]);

		for(int i = count - 1; i > 0; i--)
			m_waypoints.push_back(point_path[i]);

		for(int i = count - 1; i > 0; i--)
			m_poly_path.push_back(poly_refs[i]);

		return true;
	}
}



#include <DetourNavMeshQuery.h>



namespace toy
{
	Pathfinder::Pathfinder(Navmesh& navmesh)
		: m_navmesh(*navmesh.m_navmesh)
		, m_query(make_unique<dtNavMeshQuery>())
		, m_filter(make_unique<dtQueryFilter>())
	{
		m_filter->setIncludeFlags(0xFFFF);
		m_filter->setExcludeFlags(0);
		m_filter->setAreaCost(0, 1.0f);
		m_query->init(&m_navmesh, 65535);
	}

	Pathfinder::~Pathfinder()
	{}

	void Pathfinder::nearestValid(vec3& destination, float margin)
	{
		//m_world_page.ground_point(destination, true, destination);

		float extents[3] = { 0.f, margin, 0.f };
		dtPolyRef polyLref;
		m_query->findNearestPoly(&destination[0], extents, m_filter.get(), &polyLref, &destination[0]);
		//printf("navdestination : " << destination[0] << " , " << destination[1] << " , " << destination[2] << endl;

		//m_world_page.ground_point(destination, true, destination);

		//printf("destination : " << destination[0] << " , " << destination[1] << " , " << destination[2] << endl;
	}

	bool Pathfinder::validity(const vec3& pos)
	{
		float extents[3] = { 0.f, 2.f, 0.f };
		float result[3];
		dtPolyRef poly;
		m_query->findNearestPoly(value_ptr(pos), extents, m_filter.get(), &poly, &result[0]);

		return (poly != 0);
	}

}

#ifdef TWO_MODULES
module toy.core
#else
#endif

namespace toy
{
	OCollider Collider::create(HSpatial spatial, HMovable movable, const CollisionShape& collision_shape, Medium& medium, CollisionGroup group)
	{
		SparsePool<Collider>& pool = spatial->m_world->pool<Collider>();

		OCollider collider = pool.create(spatial, movable, collision_shape, medium, group);
		collider->m_world->add_collider(collider);
		return collider;
	}

	void Collider::destroy(HCollider collider)
	{
		collider->m_world->remove_collider(collider);
	}

    Collider::Collider(HSpatial spatial, HMovable movable, const CollisionShape& collision_shape, Medium& medium, CollisionGroup group)
        : m_spatial(spatial)
		, m_movable(movable)
		, m_collision_shape(collision_shape)
		, m_medium(&medium)
		, m_group(group)
		, m_world(&as<PhysicWorld>(spatial->m_world->m_complex).sub_world(*m_medium))
		, m_impl()
		, m_motion_state(collision_shape.m_center)
    {}

    Collider::~Collider()
    {}

	void Collider::init(object<ColliderImpl> impl)
	{
		m_impl = move(impl);
	}

	void Collider::next_frame(size_t tick, size_t delta)
	{
		if(m_movable)
			this->next_frame(m_spatial, m_movable, tick, delta);
		else
			this->next_frame(m_spatial, tick, delta);
	}

	void Collider::next_frame(Spatial& spatial, size_t tick, size_t delta)
	{
		UNUSED(delta);
		m_motion_state.update(spatial, tick);
	}

	void Collider::next_frame(Spatial& spatial, Movable& movable, size_t tick, size_t delta)
	{
		UNUSED(delta);
		m_motion_state.update(spatial, movable, tick);
	}

	OSolid Solid::create(HSpatial spatial, HMovable movable, const CollisionShape& collision_shape, Medium& medium, CollisionGroup group, bool isstatic, float mass)
	{
		SparsePool<Collider>& colliders = spatial->m_world->pool<Collider>();
		SparsePool<Solid>& solids = spatial->m_world->pool<Solid>();

		OCollider collider = colliders.create(spatial, movable, collision_shape, medium, group);
		OSolid solid = solids.create(spatial, movable, move(collider), isstatic, mass);

		HCollider hcollider = solid->m_collider;
		hcollider->m_world->add_solid(hcollider, solid);

		return solid;
	}

	OSolid Solid::create(HSpatial spatial, HMovable movable, const CollisionShape& collision_shape, bool isstatic, float mass)
	{
		return create(spatial, movable, collision_shape, SolidMedium::me, CM_SOLID, isstatic, mass);
	}

	void Solid::destroy(HSolid solid)
	{
		solid->m_collider->m_world->remove_solid(solid->m_collider, solid);
	}

	Solid::Solid(HSpatial spatial, HMovable movable, OCollider collider, bool isstatic, float mass)
		: m_spatial(spatial)
		, m_collider(move(collider))
		, m_static(isstatic)
		, m_mass(mass)
	{
		UNUSED(movable);
	}

	Solid::~Solid()
	{}

	void Solid::init(object<SolidImpl> impl)
	{
		m_impl = move(impl);
	}
}




namespace toy
{
	CollisionShape::CollisionShape()
	{}

	CollisionShape::CollisionShape(const Shape& shape, const vec3& center, float margin)
		: m_shape(shape.clone())
		, m_center(center)
		, m_margin(margin)
	{}

	CollisionShape::~CollisionShape()
	{}

	CollisionShape::CollisionShape(const CollisionShape& other)
		: m_shape(other.m_shape ? other.m_shape->clone() : nullptr)
		, m_center(other.m_center)
		, m_margin(other.m_margin)
	{}

	CollisionShape& CollisionShape::operator=(const CollisionShape& other)
	{
		if(other.m_shape)
			m_shape = other.m_shape->clone();
		m_center = other.m_center;
		m_margin = other.m_margin;
		return *this;
	}
}



namespace toy
{
	Medium::Medium(const string& name, bool occlusions)
		: m_name(name)
		, m_occlusions(occlusions)
		, m_solid(false)
	{
		m_masks[CM_SOURCE] = CM_RECEPTOR;
		m_masks[CM_RECEPTOR] = CM_SOURCE;
		m_masks[CM_OBSTACLE] = CM_OBSTACLE;
	}

	short int Medium::mask(CollisionGroup group)
	{
		return m_masks[group];
	}

	float Medium::throughput(EmitterScope& emitter, ReceptorScope& receptor, vector<Obstacle*>& occluding)
	{
		UNUSED(emitter); UNUSED(receptor);

		float throughput = 1.f;

		for(Obstacle* obstacle : occluding)
		{
			if(obstacle->m_throughput <= 0.f)
				return 0.f;
			
			throughput *= obstacle->m_throughput;
		}

		//float distance2 = source->m_position.distance2(receptor->m_position);
		
		//if(distance2 > 1.f)
		//	throughput *= 1/distance2;

		return throughput;
	}
}




namespace toy
{
	Obstacle::Obstacle(HSpatial spatial, HMovable movable, Medium& medium, const CollisionShape& shape, float throughput)
		: Collider(spatial, movable, shape, medium, CM_OBSTACLE)
		, m_shape(shape)
		, m_throughput(throughput)
	{}
}



namespace toy
{
	AreaMedium AreaMedium::me;

	AreaMedium::AreaMedium()
		: Medium("AreaMedium", false)
	{
		m_masks[CM_OBJECT] = CM_BUFFER | CM_AREA;
		m_masks[CM_BUFFER] = CM_OBJECT;
		m_masks[CM_AREA] = CM_OBJECT;
	}

	Physic::Physic(Spatial& spatial)
		//: m_areaStore()
	{
		UNUSED(spatial);
		//as<Emitter>(spatial).addEmitter(AreaMedium::me, oconstruct<SphereShape>(0.1f), CM_OBJECT);
	}

    /*void Physic::handle_add(Collider& object)
    {
		m_areaStore.add(as<Area>(object->m_spatial));
	}

    void Physic::handle_remove(Collider& object)
    {
		m_areaStore.add(as<Area>(object->m_spatial));
    }*/
}

#ifdef TWO_MODULES
module toy.core
#else
#include <stl/hash_base.hpp>
#endif

namespace toy
{
	PhysicMedium::PhysicMedium(World& world, Medium& medium)
		: m_world(world)
		, m_medium(medium)
	{}

    PhysicWorld::PhysicWorld(World& world)
		: m_world(world)
	{}

    PhysicWorld::~PhysicWorld()
	{}

	void PhysicWorld::next_frame(size_t tick, size_t delta)
	{
		for(auto& kv : m_subworlds)
			kv.second->next_frame(tick, delta);
	}

	PhysicMedium& PhysicWorld::sub_world(Medium& medium)
	{
		if(m_subworlds.find(&medium) == m_subworlds.end())
			m_subworlds[&medium] = this->create_sub_world(medium);
		return *m_subworlds[&medium].get();
	}
}

#include <stl/algorithm.h>



namespace toy
{
	PhysicScope::PhysicScope(HSpatial spatial, Medium& medium, const CollisionShape& collision_shape, CollisionGroup group)
		: m_spatial(spatial)
		, m_collider(Collider::create(spatial, HMovable(), collision_shape, medium, group))
	{
		m_collider->m_object = this;
	}

	void PhysicScope::add_scope(HSpatial object)
	{
		m_scope.push_back(object);
	}

	void PhysicScope::remove_scope(HSpatial object)
	{
		remove(m_scope, object);
	}

	EmitterScope::EmitterScope(HSpatial spatial, Medium& medium, const CollisionShape& collision_shape, CollisionGroup group)
		: PhysicScope(spatial, medium, collision_shape, group)
		, m_signals()
	{}

    void EmitterScope::add_contact(Collider& collider, ColliderObject& object)
	{
		if(collider.m_spatial == m_spatial) return;
		ReceptorScope& receptor = static_cast<ReceptorScope&>(object);
		m_signals.push_back({ *this, receptor });
	}

    void EmitterScope::remove_contact(Collider& collider, ColliderObject& object)
    {
		if(collider.m_spatial == m_spatial) return;
		ReceptorScope& receptor = static_cast<ReceptorScope&>(object);
		remove_if(m_signals, [&] (const Signal& s) { return s.m_receptor == &receptor; });
    }

	void EmitterScope::handle_moved()
	{
		Spatial& spatial = m_spatial;
		if(!spatial.m_moved) // @Hack performance kludge : scopes are usually spheres
			return;

		for(Signal& signal : m_signals)
			signal.update();
	}

	ReceptorScope::ReceptorScope(HSpatial spatial, Medium& medium, const CollisionShape& collision_shape, CollisionGroup group)
		: PhysicScope(spatial, medium, collision_shape, group)
	{}

	Emitter::Emitter(HSpatial spatial)
		: m_spatial(spatial)
	{}

	Emitter::~Emitter()
	{}

	HEmitterScope Emitter::add_scope(Medium& medium, const CollisionShape& collision_shape, CollisionGroup group)
	{
		//SparsePool<EmitterScope>& pool = m_spatial->m_world->pool<EmitterScope>();
		//m_emitters.push_back(pool.construct(m_spatial, medium, collision_shape, group));
		m_emitters.push_back(make_unique<EmitterScope>(m_spatial, medium, collision_shape, group));
		return *m_emitters.back();
	}

	HEmitterScope Emitter::add_sphere(Medium& medium, float radius, CollisionGroup group)
	{
		return this->add_scope(medium, Sphere(radius), group);
	}

	Receptor::Receptor(HSpatial spatial)
		: m_spatial(spatial)
	{}

	Receptor::~Receptor()
	{}

	HReceptorScope Receptor::add_scope(Medium& medium, const CollisionShape& collision_shape, CollisionGroup group)
	{
		//SparsePool<ReceptorScope>& pool = m_spatial->m_world->pool<ReceptorScope>();
		//m_receptors.push_back(pool.construct(m_spatial, medium, collision_shape, group));
		m_receptors.push_back(make_unique<ReceptorScope>(m_spatial, medium, collision_shape, group));
		return *m_receptors.back();
	}

	HReceptorScope Receptor::add_sphere(Medium& medium, float radius, CollisionGroup group)
	{
		return this->add_scope(medium, Sphere(radius), group);
	}

	ReceptorScope* Receptor::scope(Medium& medium)
	{
		for(auto& scope : m_receptors)
			if(scope->m_collider->m_medium == &medium)
				return &(*scope);
		return nullptr;
	}

}




namespace toy
{
	Signal::Signal(EmitterScope& emitter, ReceptorScope& receptor)
		: m_emitter(&emitter)
		, m_receptor(&receptor)
	{
		if(!m_emitter->m_collider->m_medium->m_occlusions)
			this->on();

		update();
	}

	Signal::~Signal()
	{
		if(m_on)
			this->off();
	}

	void Signal::update()
	{
		if(m_emitter->m_collider->m_medium->m_occlusions)
		{
			vector<Collision> occluding;

			Spatial& receptor = m_receptor->m_spatial;
			m_emitter->m_collider->m_impl->raycast(receptor.m_position, occluding, CM_OBSTACLE);

			m_occluding.clear();
			//for(const Collision& coll : occluding)
			//	m_occluding.push_back(static_cast<Obstacle*>(coll.m_second));

			m_strength = m_emitter->m_collider->m_medium->throughput(*m_emitter, *m_receptor, m_occluding);

			if(m_strength > 0.f && !m_on)
				this->on();
			else if(m_strength == 0.f && m_on)
				this->off();
		}
	}

	void Signal::on()
	{
		m_on = true;
		m_receptor->add_scope(m_emitter->m_spatial);
		m_emitter->add_scope(m_receptor->m_spatial);
	}

	void Signal::off()
	{
		m_on = false;
		m_receptor->remove_scope(m_emitter->m_spatial);
		m_emitter->remove_scope(m_receptor->m_spatial);
	}
}


namespace toy
{
	SolidMedium SolidMedium::me;

	SolidMedium::SolidMedium()
		: Medium("SolidMedium")
	{
		m_solid = true;
		m_masks[CM_SOLID] = CM_SOLID | CM_GROUND;
		m_masks[CM_GROUND] = CM_GROUND | CM_SOLID;
	}
}




#include <stl/vector.h>
#include <sstream>

namespace toy
{
	EntityScript::EntityScript(HSpatial spatial)
		: m_spatial(spatial)
	{}

	void EntityScript::next_frame(size_t tick, size_t delta)
	{
		UNUSED(tick); UNUSED(delta);
		this->run_logic();
	}

	void EntityScript::run_logic()
	{
		if(m_logic_script)
		{
			//Spatial& spatial = m_spatial;
			// @hack @kludge add proper way to define a script signature
			if(m_logic_script->m_signature.m_params.empty())
			{
				//m_logic_script->m_signature.m_params.push_back({ "self", Ref(spatial.m_entity->m_type) });
				//m_logic_script->m_signature.m_params.push_back({ "self", Ref(type<Entity>()) });
				//m_logic_script->m_signature.m_params.push_back({ "entity", Ref(type<Spatial>()) });
			}

			//vector<Var> args = { Ref(spatial.m_handle), Ref(&spatial) };
			//(*m_logic_script)(args);
		}
	}

	void EntityScript::run_render()
	{
		if(m_render_script)
		{
			Spatial& spatial = m_spatial;
			//vector<Var> args = { Ref(&spatial) };
			//(*m_render_script)(args);
		}
	}
}



namespace toy
{
}

#ifdef TWO_MODULES
module toy.core;
#else
#include <stl/algorithm.h>
#endif

#include <cstdio>
#include <cassert>

namespace toy
{
	Spatial::Spatial(World& world, HSpatial parent, const vec3& position, const quat& rotation)
		: Transform{ position, rotation, vec3(1.f) }
		, m_world(&world)
		, m_parent(parent)
		, m_hooked(true)
	{}

	Spatial::Spatial(HSpatial parent, const vec3& position, const quat& rotation)
		: Spatial(*parent->m_world, parent, position, rotation)
	{}

    Spatial::~Spatial()
    {}

	Spatial& Spatial::origin()
	{
		return m_world->origin();
	}

	void Spatial::debug_contents(size_t depth)
	{
		if(m_contents.size() > 1)
		{
			for(size_t o = 0; o < depth; ++o)
				printf("    ");

			printf("Spatial %u : %zu leafs\n", 0U, m_contents.size());
		}

		for(HSpatial child : m_contents)
			child->debug_contents(depth + 1);
	}

	vec3 Spatial::absolute_position() const
	{
		if(m_parent)
			return m_position + m_parent->absolute_position();
		else
			return m_position;
	}

	quat Spatial::absolute_rotation() const
	{
		if(m_parent)
			assert(&(*m_parent) != this);
		if(m_parent)
			return m_rotation * m_parent->absolute_rotation();
		else
			return m_rotation;
	}

	void Spatial::translate(const vec3& vec)
	{
		set_position(two::rotate(m_rotation, vec) + m_position);
	}

	void Spatial::rotate(const vec3& axis, float angle)
	{
		quat rot = angle_axis(angle, two::rotate(m_rotation, axis));
		set_rotation(rot * m_rotation);
		normalize(m_rotation);
	}

	void Spatial::yaw(float value)
	{
		vec3 axis(two::rotate(m_rotation, Y3));			
		rotate(axis, value);
	}

	void Spatial::yaw_fixed(float value)
	{			
		rotate(Y3, value);
	}

	void Spatial::pitch(float value)
	{
		vec3 axis(two::rotate(m_rotation, X3));
		rotate(axis, value);
	}

	void Spatial::roll(float value)
	{
		vec3 axis(two::rotate(m_rotation, Z3));
		rotate(axis, value);
	}

    void Spatial::next_frame(size_t tick, size_t delta)
    {
		UNUSED(delta);

		m_moved = false;
		m_last_tick = tick;
	}

	void Spatial::hook()
	{
		m_hooked = true;
	}

	void Spatial::unhook()
	{
		m_hooked = false;
	}

	bool Spatial::is_child_of(HSpatial spatial)
	{
		if(m_parent == spatial)
			return true;
		else if(m_parent)
			return m_parent->is_child_of(spatial);
		else
			return false;
	}

	Spatial* Spatial::spatial_root()
	{
		if(m_parent)
			return m_parent->spatial_root();
		else
			return this;
	}

	void Spatial::detach(Spatial& child)
	{
		child.m_parent = {};
		//remove(m_contents, child);
	}

	void detach_to(HSpatial self, HSpatial target)
	{
		Spatial& spatial = self;
		Spatial& movefrom = spatial.m_parent;
		spatial.m_parent = target;
		remove(movefrom.m_contents, self);
		target->m_contents.push_back(self);
		spatial.set_dirty(false);
	}

	void set_parent(HSpatial self, HSpatial target)
	{
		detach_to(self, target);
	}
}

#ifdef TWO_MODULES
module toy.core
#else
#endif

namespace toy
{
	Entity Origin::create(ECS& ecs, World& world)
	{
		Entity entity = ecs.create<Spatial, Origin>();
		ecs.set(entity, Spatial(world, HSpatial(), vec3(0.f), ZeroQuat));
		return entity;
	}
}



#include <algorithm>

namespace toy
{
	JobPump::JobPump()
	{}

	void JobPump::pump()
	{
		size_t tick = m_clock.readTick();
		size_t delta = m_clock.stepTick();

		for(auto& step : m_steps)
			step.m_handler(tick, delta);
	}

	void JobPump::add_step(Entry entry)
	{
		m_steps.push_back(entry);
		std::sort(m_steps.begin(), m_steps.end(), [&](const Entry& a, const Entry& b) { return a.m_task < b.m_task; });
	}
}





namespace toy
{
	World::World(uint32_t id, Complex& complex, const string& name, JobSystem& job_system)
        : m_id(complex.m_id)
		, m_complex(complex)
		, m_name(name)
		, m_job_system(job_system)
		, m_pools(c_max_types)
    {
		UNUSED(id);
		s_ecs[0] = &m_ecs;

		m_origin = Origin::create(m_ecs, *this);
		m_unworld = Origin::create(m_ecs, *this);

		auto update_colliders = [&](size_t tick, size_t delta)
		{
			for(Collider& collider : this->pool<Collider>().m_objects)
				collider.next_frame(tick, delta);
		};

		m_pump.add_step({ Task::Physics, update_colliders });

		add_parallel_loop<Spatial>(Task::Spatial);
		add_parallel_loop<Movable, Spatial>(Task::Spatial);
		add_parallel_loop<Camera, Spatial>(Task::Spatial);
		add_parallel_loop<WorldPage, Spatial>(Task::Spatial);
		add_parallel_loop<Navblock, Spatial, WorldPage>(Task::Spatial);

		// not parallel because we don't know what the script might do
		add_loop<EntityScript>(Task::Spatial);
	}

    World::~World()
    {}

    void World::next_frame()
    {
		m_pump.pump();
    }
}



namespace toy
{
    WorldClock::WorldClock()
	{}

	double WorldClock::step()
	{
        double timeStep = m_clock.read();
        m_clock.update();
		return this->step(timeStep);
	}

    double WorldClock::step(double step)
	{
		m_symbolic_time += step * m_speed;
		m_time += step;
		return step * m_speed;
	}

	double WorldClock::read()
	{
		return m_time;
	}

	double WorldClock::symbolic()
	{
		return m_symbolic_time;
	}
}






#include <cstdio>

namespace toy
{
	WorldMedium WorldMedium::me;

	WorldMedium::WorldMedium()
		: Medium("World", false)
	{}

	WorldPage::WorldPage(HSpatial spatial, bool open, const vec3& extents)
        : m_spatial(spatial)
		, m_open(open)
		, m_extents(extents)
		, m_world(spatial->m_world)
		//, m_scope(emitter.add_scope(WorldMedium::me, Cube(m_extents / 2.f), CM_SOURCE))
    {
		//m_spatial.m_contents.observe(*this);
	}

    WorldPage::~WorldPage()
    {
		//m_spatial.m_contents.unobserve(*this);
	}

	void WorldPage::next_frame(const Spatial& spatial, size_t tick, size_t delta)
	{
		UNUSED(spatial); UNUSED(tick); UNUSED(delta);
	}

	void WorldPage::update_geometry(size_t tick)
	{
		printf("[info] Updating WorldPage world geometry\n");
		m_solids.clear();
		for(Geometry& geom : m_chunks)
		{
			if(geom.m_vertices.empty() || geom.m_triangles.empty())
				continue;
			printf("[info] WorldPage geometry chunk, %zu vertices\n", geom.m_vertices.size());
			m_solids.push_back(Solid::create(m_spatial, HMovable(), geom, SolidMedium::me, CM_GROUND, true));
		}

		m_chunks.clear();
		m_last_rebuilt = tick;
	}

	/*
	void WorldPage::handle_add(Spatial& spatial)
	{
		UNUSED(spatial);
		//if(!is<Movable>(entity))
		//	m_updated = m_spatial.m_last_tick;
	}

	void WorldPage::handle_remove(Spatial& spatial)
	{
		UNUSED(spatial);
		//if(!is<Movable>(entity))
		//	m_updated = m_spatial.m_last_tick;
	}
	*/
	void WorldPage::ground_point(const vec3& position, bool relative, vec3& ground_point)
	{
		Spatial& spatial = m_spatial;

		// to absolute
		vec3 start(position.x, -m_extents.y / 2, position.z);
		vec3 end(position.x, +m_extents.y / 2, position.z);

		if(relative)
		{
			start += spatial.m_position;
			end += spatial.m_position;
		}

		Ray ray = { start, end, normalize(end - start), normalize(start - end) };
		ground_point = as<PhysicWorld>(m_world->m_complex).ground_point(ray) - spatial.m_position;

		if(any(isnan(ground_point)) || any(isinf(ground_point)))
			printf("[ERROR] raycast ground point failed, position result invalid\n");
	}

	void WorldPage::raycast_ground(const vec3& start, const vec3& end, vec3& ground_point)
	{
		Ray ray = { start, end, normalize(end - start), normalize(start - end) };
		ground_point = as<PhysicWorld>(m_world->m_complex).ground_point(ray);
	}
}
