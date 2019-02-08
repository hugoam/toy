//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.


#pragma once

#include <infra/Global.h>
#include <type/Dispatch.h>
#include <core/Forward.h>
#include <core/Structs.h>
#include <core/Physic/Collider.h>
#include <core/Physic/CollisionShape.h>

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
