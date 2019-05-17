//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/Bullet/BulletMotionState.h.inl>

#include <core/Spatial/Spatial.h>
#include <core/Physic/Collider.h>
#include <core/Bullet/Bullet.h.inl>

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
