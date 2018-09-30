//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.


#pragma once

#include <infra/NonCopy.h>
#include <type/Dispatch.h>
#include <core/Forward.h>
#include <core/Structs.h>
#include <core/Physic/Collider.h>
#include <core/Physic/CollisionShape.h>

using namespace mud; namespace toy
{
	class refl_ TOY_CORE_EXPORT BulletShape : public Movabl
	{
	public:
		BulletShape(unique_ptr<btCollisionShape> shape);
		BulletShape(unique_ptr<btCollisionShape> shape, unique_ptr<btStridingMeshInterface> mesh);
		~BulletShape();

		BulletShape(BulletShape&& other);
		BulletShape& operator=(BulletShape&& other);

		unique_ptr<btCollisionShape> shape;
		unique_ptr<btStridingMeshInterface> mesh;
	};

	class TOY_CORE_EXPORT DispatchBulletShape : public Dispatch<BulletShape>, public LazyGlobal<DispatchBulletShape>
	{
	public:
		DispatchBulletShape();
		BulletShape dispatch(CollisionShape& collision_shape);
	};

    class refl_ TOY_CORE_EXPORT BulletCollider : public NonCopy, public ColliderImpl
    {
	public:
        BulletCollider(BulletMedium& bulletWorld, HSpatial spatial, HCollider collider, CollisionShape& collision_shape, bool create = true);
        ~BulletCollider();

		void setup(Spatial& spatial, btCollisionObject& collisionObject);

		virtual void update_transform(const vec3& position, const quat& rotation) override;
		virtual void update_transform() override;

		virtual void project(const vec3& position, std::vector<Collision>& collisions, short int mask) override;
		virtual void raycast(const vec3& position, std::vector<Collision>& collisions, short int mask) override;
		virtual Collision raycast(const vec3& position, short int mask) override;

	public:
		BulletMedium& m_bullet_world;
		HSpatial m_spatial;
		HCollider m_collider;
		BulletShape m_collision_shape;
		unique_ptr<btCollisionObject> m_collision_object;
    };
}
