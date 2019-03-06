//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <core/Forward.h>
#include <core/Spatial/Spatial.h>

namespace toy
{
	class refl_ TOY_CORE_EXPORT Origin
	{
	public:
		constr_ Origin() {}

		static Entity create(ECS& ecs, World& world);
	};
}
