//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <ecs/Proto.h>
#include <core/Forward.h>
#include <core/Spatial/Spatial.h>

using namespace mud; namespace toy
{
	class refl_ TOY_CORE_EXPORT Origin
	{
	public:
		constr_ Origin() {}
		constr_ Origin(HSpatial spatial);

		static Entity create(ECS& ecs, World& world);

		comp_ HSpatial m_spatial;
	};
}
