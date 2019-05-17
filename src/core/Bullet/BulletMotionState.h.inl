//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <math/Vec.h>
#include <core/Forward.h>
#include <core/Movable/MotionState.h>
#include <core/Structs.h>

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
