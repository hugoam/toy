//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/Bullet/BulletCollider.h>

#include <obj/DispatchDecl.h>

#include <geom/Shapes.h>
#include <geom/ShapesComplex.h>
#include <geom/Mesh.h>
#include <geom/Primitive.h>
#define TOY_PRIVATE
#include <core/Bullet.h>

#include <core/World/World.h>
#include <core/Entity/Entity.h>
#include <core/Bullet/BulletWorld.h>
#include <core/Physic/PhysicWorld.h>
#include <core/Physic/Medium.h>

/* bullet */

#if _MSC_VER
#	pragma warning (push)
#	pragma warning (disable : 4127)
#	pragma warning (disable : 4100)
#endif

#include <BulletCollision/CollisionDispatch/btGhostObject.h>
#include <BulletCollision/CollisionShapes/btConvexHullShape.h>
#include <BulletCollision/CollisionShapes/btSphereShape.h>
#include <BulletCollision/CollisionShapes/btBoxShape.h>
#include <btBulletCollisionCommon.h>

#if _MSC_VER
#	pragma warning (pop)
#endif

using namespace mud; namespace toy
{
	BulletShape::BulletShape(unique_ptr<btCollisionShape> shape)
		: shape(std::move(shape))
	{}

	BulletShape::BulletShape(unique_ptr<btCollisionShape> shape, unique_ptr<btStridingMeshInterface> mesh)
		: shape(std::move(shape))
		, mesh(std::move(mesh))
	{}

	BulletShape::BulletShape(BulletShape&& other)
		: shape(std::move(other.shape))
		, mesh(std::move(other.mesh))
	{}

	BulletShape& BulletShape::operator=(BulletShape&& other)
	{
		this->shape = std::move(other.shape);
		this->mesh = std::move(other.mesh);
		return *this;
	}

	BulletShape::~BulletShape()
	{}

	BulletShape createGeometryShape(Geometry& geometry)
	{
		unique_ptr<btTriangleMesh> trimesh = make_unique<btTriangleMesh>();

		btVector3 vertex[3];
		for(const Tri& triangle : geometry.m_triangles)
		{
			for(int i = 0; i < 3; ++i)
			{
				uint32_t index = (&triangle.a)[i];
				vertex[i] = to_btvec3(geometry.m_vertices[index].m_position);
			}

			trimesh->addTriangle(vertex[0], vertex[1], vertex[2]);
		}

		const bool useQuantizedAABB = true;
		unique_ptr<btCollisionShape> meshShape(make_unique<btBvhTriangleMeshShape>(trimesh.get(), useQuantizedAABB));

		return BulletShape(std::move(meshShape), std::move(trimesh));
	}

	BulletShape createConvexHullShape(ConvexHull& hull)
	{
		unique_ptr<btConvexHullShape> convexHull = make_unique<btConvexHullShape>();
		for(const vec3& point : hull.m_vertices)
			convexHull->addPoint(to_btvec3(point));
		return BulletShape(std::move(convexHull));
	}

	DispatchBulletShape::DispatchBulletShape()
	{
		dispatch_branch<Sphere>(*this, [](Sphere& sphere) -> BulletShape { return{ make_unique<btSphereShape>(sphere.m_radius) }; });
		dispatch_branch<Capsule>(*this, [](Capsule& capsule) -> BulletShape { return{ make_unique<btCapsuleShape>(capsule.m_radius, capsule.m_height) }; });
		dispatch_branch<Cylinder>(*this, [](Cylinder& cylinder) -> BulletShape { return{ make_unique<btCylinderShape>(btVector3(cylinder.m_radius, cylinder.m_height / 2.f, cylinder.m_radius)) }; });
		dispatch_branch<Cube>(*this, [](Cube& box) -> BulletShape { return{ make_unique<btBoxShape>(to_btvec3(box.m_extents)) }; });
		dispatch_branch<ConvexHull>(*this, &createConvexHullShape);
		dispatch_branch<Geometry>(*this, &createGeometryShape);
	};

	BulletShape DispatchBulletShape::dispatch(CollisionShape& collision_shape)
	{
		Ref shape = Ref(collision_shape.m_shape.get());
		return Dispatch::dispatch(shape); 
	}

	class ContactCheck : public btCollisionWorld::ContactResultCallback
	{
	public:
		ContactCheck(std::vector<Collision>& collisions, float margin = 0.f)
			: m_collisions(collisions)
			, m_margin(margin)
		{}

		ContactCheck& operator=(const ContactCheck&) = delete;

		virtual bool needsCollision(btBroadphaseProxy* proxy) const
		{
			return btCollisionWorld::ContactResultCallback::needsCollision(proxy);
		}

		btScalar addSingleResult(btManifoldPoint &cp, const btCollisionObjectWrapper *colObj0, int partId0, int index0, const btCollisionObjectWrapper *colObj1, int partId1, int index1)
		{
			UNUSED(index0); UNUSED(index1); UNUSED(partId0); UNUSED(partId1);
			if(cp.getDistance() < m_margin)
				m_collisions.push_back({ (Collider*)colObj0->m_collisionObject->getUserPointer(), 
										 (Collider*)colObj1->m_collisionObject->getUserPointer(),
										 Zero3 });

			return 0.f;
		}

	private:
		std::vector<Collision>& m_collisions;
		float m_margin;
	};

	BulletCollider::BulletCollider(SubBulletWorld& bullet_world, Collider& collider, bool create)
		: m_bullet_world(bullet_world)
		, m_collider(collider)
		, m_collision_shape(DispatchBulletShape::me().dispatch(collider.m_collision_shape))
	{
		if(create)
			this->setup_object(make_unique<btCollisionObject>());
	}

	BulletCollider::~BulletCollider()
	{}

	void BulletCollider::setup_object(unique_ptr<btCollisionObject> collisionObject)
	{
		vec3 position = m_collider.m_entity.m_position + m_collider.m_collision_shape.m_center;

		m_collision_object = std::move(collisionObject);
		m_collision_object->setUserPointer(&m_collider);
		m_collision_object->setWorldTransform(btTransform(to_btquat(m_collider.m_entity.m_rotation), to_btvec3(position)));
		m_collision_object->setCollisionFlags(0);
		m_collision_object->setCollisionShape(m_collision_shape.shape.get());
		//m_collision_object->setContactProcessingThreshold(0.1f);
	}

	void BulletCollider::update_transform(const vec3& position, const quat& rotation)
	{
		m_collision_object->setWorldTransform(btTransform(to_btquat(rotation), to_btvec3(position)));
	}

	void BulletCollider::update_transform()
	{
		this->update_transform(m_collider.m_entity.absolute_position(), m_collider.m_entity.absolute_rotation());
	}

	void BulletCollider::force_update()
	{
		this->update_transform(m_collider.m_entity.absolute_position(), m_collider.m_entity.absolute_rotation());
		m_bullet_world.m_bullet_world->updateSingleAabb(m_collision_object.get());
		m_bullet_world.update_contacts();
	}

	void BulletCollider::project(const vec3& position, std::vector<Collision>& collisions, short int mask)
	{
		btTransform transform(m_collision_object->getWorldTransform());
		m_collision_object->setWorldTransform(btTransform(to_btquat(m_collider.m_entity.m_rotation), to_btvec3(position)));

		ContactCheck callback(collisions);
		callback.m_collisionFilterGroup = mask;
		callback.m_collisionFilterMask = mask;
		//m_collision_object->checkCollideWith();
		
		m_bullet_world.m_bullet_world->updateSingleAabb(m_collision_object.get());
		m_bullet_world.m_bullet_world->contactTest(m_collision_object.get(), callback);

		m_collision_object->setWorldTransform(transform);
	}

	void BulletCollider::raycast(const vec3& target, std::vector<Collision>& collisions, short int mask)
	{
		btVector3 from = to_btvec3(m_collider.m_entity.m_position);
		btVector3 to = to_btvec3(target);

		if(from == to)
			return;

		btCollisionWorld::AllHitsRayResultCallback callback(from, to);
		callback.m_collisionFilterMask = mask;
		callback.m_collisionFilterGroup = btBroadphaseProxy::AllFilter;
		m_bullet_world.m_bullet_world->rayTest(from, to, callback);
		//printf("raycast from %f, %f, %f to %f, %f, %f\n", from.x(), from.y(), from.z(), to.x(), to.y(), to.z());
		
		for(int i = 0; i != callback.m_collisionObjects.size(); ++i)
		{
			Collider* physic = static_cast<Collider*>(callback.m_collisionObjects[i]->getUserPointer());
			collisions.push_back({ &m_collider, physic, to_vec3(callback.m_hitPointWorld[i]) });
		}
	}

	Collision BulletCollider::raycast(const vec3& target, short int mask)
	{
		btVector3 from = to_btvec3(m_collider.m_entity.m_position);
		btVector3 to = to_btvec3(target);

		if(from == to)
			return {};

		btCollisionWorld::ClosestRayResultCallback callback(from, to);
		callback.m_collisionFilterMask = mask;
		callback.m_collisionFilterGroup = btBroadphaseProxy::AllFilter;
		m_bullet_world.m_bullet_world->rayTest(from, to, callback);
		//printf("raycast from %f, %f, %f to %f, %f, %f\n", from.x(), from.y(), from.z(), to.x(), to.y(), to.z());

		if(callback.m_collisionObject)
			return { nullptr, static_cast<Collider*>(callback.m_collisionObject->getUserPointer()), to_vec3(callback.m_hitPointWorld) };
		return {};
	}
}
