//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <ecs/Complex.h>
#include <core/Forward.h>
#include <core/World/Section.h>
#include <core/World/World.h>
#include <core/Navmesh/Navmesh.h>
#include <core/Bullet/BulletWorld.h>

namespace toy
{
	class refl_ TOY_CORE_EXPORT Core
	{
	public:
		Core(JobSystem& job_system);
		~Core();

		void next_frame();
		
		JobSystem& m_job_system;
		JobPump m_pump;
	};

	class refl_ TOY_CORE_EXPORT DefaultWorld : public Complex
	{
	public:
		constr_ DefaultWorld(const string& name, JobSystem& job_system);
		~DefaultWorld();

		attr_ World m_world;
		attr_ comp_ BulletWorld m_bullet_world;
		attr_ comp_ Navmesh m_navmesh;
	};
}
