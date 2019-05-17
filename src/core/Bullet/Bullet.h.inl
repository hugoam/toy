//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <math/Forward.h>
#include <math/Vec.h>
#include <math/Colour.h>

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
