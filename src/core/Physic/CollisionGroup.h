//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

namespace toy
{
	enum refl_ CollisionGroup : short int
	{
		CM_NOMASK   = 0,
		CM_OBJECT   = 1 << 0,
		CM_SOLID    = 1 << 1,
		CM_GROUND   = 1 << 2,
		CM_AREA     = 1 << 3,
		CM_BUFFER   = 1 << 4,
		CM_LIGHT    = 1 << 5,
		CM_LIGHTREFLECTOR = 1 << 6,
		CM_SOURCE   = 1 << 7,
		CM_RECEPTOR = 1 << 8,
		CM_OBSTACLE = 1 << 9
	};
}
