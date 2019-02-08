//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <stl/vector.h>
#include <core/Forward.h>
#include <core/Path/DetourPath.h>

class dtNavMesh;
class dtNavMeshQuery;
class dtQueryFilter;

namespace toy
{
	class refl_ TOY_CORE_EXPORT Pathfinder
    {
	public:
		constr_ Pathfinder(Navmesh& navmesh);
		~Pathfinder();

		dtNavMesh& m_navmesh;

		unique<dtNavMeshQuery> m_query;
		unique<dtQueryFilter> m_filter;

		size_t m_max_polys = 20;
		size_t m_max_waypoints = 50;

		bool validity(const vec3& pos);
		void nearestValid(vec3& destination, float margin);
    };
}
