//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <core/Forward.h>
#include <core/Bullet/BulletCollider.h>
#include <core/Spatial/Spatial.h>

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
