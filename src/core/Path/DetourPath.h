//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <ecs/Proto.h>
#include <math/Math.h>
#include <math/Vec.h>
#include <infra/NonCopy.h>
#include <core/Forward.h>
#include <core/Spatial/Spatial.h>

#ifndef MUD_CPP_20
#include <vector>
#include <memory>
#endif

using namespace mud; namespace toy
{
	typedef unsigned int dtPolyRef;

	class refl_ TOY_CORE_EXPORT Waypoint
	{
	public:
		constr_ Waypoint() {}
		constr_ Waypoint(HSpatial parent);

		static Entity create(ECS& ecs, HSpatial parent, const vec3& position);

		comp_ HSpatial m_spatial;
	};

    class refl_ TOY_CORE_EXPORT DetourPath
    {
	public:
		DetourPath(Pathfinder& pathfinder, const vec3& origin, const vec3& destination);

		Pathfinder& m_pathfinder;

		vec3 m_origin;
		vec3 m_destination;

		std::vector<vec3> m_path;
		std::vector<vec3> m_waypoints;
		std::vector<dtPolyRef> m_poly_path;

		void clear();
		bool compute();

	private:
		dtPolyRef m_currentPoly;
    };
}
