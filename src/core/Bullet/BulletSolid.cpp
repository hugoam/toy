//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.


#include <core/Bullet/BulletSolid.h>

#define TOY_PRIVATE
#include <core/Bullet.h>

#include <core/Spatial/Spatial.h>
#include <core/Movable/Movable.h>
#include <core/Bullet/BulletWorld.h>
#include <core/Bullet/BulletMotionState.h>

/* bullet */

#if _MSC_VER
#	pragma warning (push)
#	pragma warning (disable : 4127)
#	pragma warning (disable : 4100)
#endif

#include <LinearMath/btMotionState.h>
#include <btBulletDynamicsCommon.h>

#if _MSC_VER
#	pragma warning (pop)
#endif

using namespace mud; namespace toy
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
