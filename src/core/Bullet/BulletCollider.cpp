//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/Types.h>
#include <core/Bullet/BulletCollider.h>

#include <type/DispatchDecl.h>

#include <geom/Shapes.h>
#include <geom/ShapesComplex.h>
#include <geom/Geometry.h>
#include <geom/Geom.h>
#include <geom/Primitive.h>

#include <core/World/World.h>
#include <core/Spatial/Spatial.h>
#include <core/Bullet/BulletWorld.h>
#include <core/Physic/PhysicWorld.h>
#include <core/Physic/Medium.h>

#ifdef _MSC_VER
#	pragma warning (push)
#	pragma warning (disable : 4127)
#	pragma warning (disable : 4100)
#	pragma warning (disable : 4305)
#	pragma warning (disable : 5033) // @todo deal with this ?
#endif

#include <core/Bullet/Bullet.h.inl>

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
