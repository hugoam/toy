//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.


#pragma once

#include <infra/NonCopy.h>
#include <core/Store/Array.h>
#include <obj/Dispatch.h>
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
        BulletCollider(SubBulletWorld& bulletWorld, Collider& collider, bool create = true);
        ~BulletCollider();

		void setup_object(unique_ptr<btCollisionObject> collisionObject);

		virtual void update_transform(const vec3& position, const quat& rotation) override;
		virtual void update_motion(const vec3& linear_velocity, const vec3& angular_velocity) override { UNUSED(linear_velocity); UNUSED(angular_velocity); }
		virtual void update_transform() override;
		virtual void force_update() override;

		virtual void project(const vec3& position, std::vector<Collision>& collisions, short int mask) override;
		virtual void raycast(const vec3& position, std::vector<Collision>& collisions, short int mask) override;
		virtual Collision raycast(const vec3& position, short int mask) override;

		virtual vec3 linear_velocity() override { return Zero3; }
		virtual vec3 angular_velocity() override { return Zero3; }

		virtual void set_linear_velocity(const vec3& force) override { UNUSED(force); }
		virtual void set_angular_velocity(const vec3& torque) override { UNUSED(torque); }
		virtual void set_angular_factor(const vec3& factor) override { UNUSED(factor); }

		virtual void set_force(const vec3& force) override { UNUSED(force); }
		virtual void set_torque(const vec3& torque) override { UNUSED(torque); }

		virtual void impulse(const vec3& force, const vec3& point) override { UNUSED(force); UNUSED(point); }

		virtual void impulse_force(const vec3& force) override { UNUSED(force); }
		virtual void impulse_torque(const vec3& torque) override { UNUSED(torque); }

	public:
		SubBulletWorld& m_bullet_world;
		Collider& m_collider;
		BulletShape m_collision_shape;
		unique_ptr<btCollisionObject> m_collision_object;
    };
}
