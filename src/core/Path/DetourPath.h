//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <stl/vector.h>
#include <stl/memory.h>
#include <math/Vec.h>
#include <core/Forward.h>
#include <core/Spatial/Spatial.h>

namespace toy
{
	typedef unsigned int dtPolyRef;

	class refl_ TOY_CORE_EXPORT Waypoint
	{
	public:
		constr_ Waypoint() {}

		static Entity create(ECS& ecs, HSpatial parent, const vec3& position);
	};

    class refl_ TOY_CORE_EXPORT DetourPath
    {
	public:
		DetourPath(Pathfinder& pathfinder, const vec3& origin, const vec3& destination);

		Pathfinder& m_pathfinder;

		vec3 m_origin;
		vec3 m_destination;

		vector<vec3> m_path;
		vector<vec3> m_waypoints;
		vector<dtPolyRef> m_poly_path;

		void clear();
		bool compute();

	private:
		dtPolyRef m_currentPoly;
    };
}
