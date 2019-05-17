//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/Path/Pathfinder.h>

#include <core/Spatial/Spatial.h>
#include <core/World/World.h>
#include <core/WorldPage/WorldPage.h>
#include <core/Path/DetourPath.h>
#include <core/Navmesh/Navmesh.h>

#include <DetourNavMeshQuery.h>

#include <core/Core.h>


namespace toy
{
	Pathfinder::Pathfinder(Navmesh& navmesh)
		: m_navmesh(*navmesh.m_navmesh)
		, m_query(make_unique<dtNavMeshQuery>())
		, m_filter(make_unique<dtQueryFilter>())
	{
		m_filter->setIncludeFlags(0xFFFF);
		m_filter->setExcludeFlags(0);
		m_filter->setAreaCost(0, 1.0f);
		m_query->init(&m_navmesh, 65535);
	}

	Pathfinder::~Pathfinder()
	{}

	void Pathfinder::nearestValid(vec3& destination, float margin)
	{
		//m_world_page.ground_point(destination, true, destination);

		float extents[3] = { 0.f, margin, 0.f };
		dtPolyRef polyLref;
		m_query->findNearestPoly(&destination[0], extents, m_filter.get(), &polyLref, &destination[0]);
		//printf("navdestination : " << destination[0] << " , " << destination[1] << " , " << destination[2] << endl;

		//m_world_page.ground_point(destination, true, destination);

		//printf("destination : " << destination[0] << " , " << destination[1] << " , " << destination[2] << endl;
	}

	bool Pathfinder::validity(const vec3& pos)
	{
		float extents[3] = { 0.f, 2.f, 0.f };
		float result[3];
		dtPolyRef poly;
		m_query->findNearestPoly(value_ptr(pos), extents, m_filter.get(), &poly, &result[0]);

		return (poly != 0);
	}

}
