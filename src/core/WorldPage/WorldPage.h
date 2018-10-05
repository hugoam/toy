//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <ecs/Entity.h>
#include <math/Vec.h>
#include <core/Forward.h>
#include <core/Physic/Medium.h>
#include <core/Physic/Collider.h>

#ifndef MUD_CPP_20
#include <memory>
//#include <atomic>
#endif

using namespace mud; namespace toy
{
	class refl_ TOY_CORE_EXPORT WorldMedium final : public Medium
	{
	public:
		constr_ WorldMedium();
		attr_ static WorldMedium me;
	};

	/* A WorldPage has : 
		- contents (entities)
		- static geometry (static entities)
		- nested worldpages (worldpages)
		- adjacent worldpages
	*/

	class refl_ TOY_CORE_EXPORT WorldPage : public Movabl
    {
	public:
		constr_ WorldPage() {}
		constr_ WorldPage(HSpatial spatial, bool open, const vec3& extents);
        ~WorldPage();

		WorldPage(WorldPage&& other) = default;
		WorldPage& operator=(WorldPage&& other) = default;

		comp_ HSpatial m_spatial;

		attr_ bool m_open = true;
		attr_ vec3 m_extents = Zero3;
		attr_ World* m_world = nullptr;
		attr_ size_t m_last_rebuilt = 0;

		size_t m_updated = 0;
		//std::atomic<size_t> m_updated = 0;

		std::vector<string> m_geometry_filter;

		std::function<void(WorldPage&)> m_build_geometry;

		//EmitterScope& m_scope;

		std::vector<Geometry> m_chunks;
		std::vector<OSolid> m_solids;

		void next_frame(const Spatial& spatial, size_t tick, size_t delta);

		meth_ void build_geometry(const Spatial& spatial);
		meth_ void update_geometry();

		meth_ void ground_point(const vec3& position, bool relative, vec3& outputPoint);
		meth_ void raycast_ground(const vec3& from, const vec3& to, vec3& ground_point);
    };
}
