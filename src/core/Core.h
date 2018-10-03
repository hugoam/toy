//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <infra/NonCopy.h>
#include <core/Forward.h>
#include <core/World/Section.h>

#include <core/World/World.h>
#include <core/Bullet/BulletWorld.h>
#include <core/Navmesh/Navmesh.h>

#include <ecs/Loop.h>

#ifndef MUD_CPP_20
#include <map>
#endif

using namespace mud; namespace toy
{
	using string = std::string;

	namespace helper
	{
		template <class T>
		T& deref(T& val) { return val; }

		template <class T>
		T& deref(T*& val) { return *val; }
	}

	class refl_ TOY_CORE_EXPORT Core : public NonCopy
	{
	public:
		Core(JobSystem& job_system);
		~Core();

		void next_frame();
		
		template <class T_Component, class... T_Args>
		void add_loop(Task task)
		{
			auto loop = [](size_t tick, size_t delta)
			{
				s_registry.Loop<T_Component, T_Args...>([tick, delta](uint32_t entity, T_Component& component, T_Args&... args)
				{
					UNUSED(entity); helper::deref(component).next_frame(args..., tick, delta);
				});
			};

			m_pump.add_step({ task, loop });
		}

		template <class T_Component, class... T_Args>
		void add_parallel_loop(Task task)
		{
			auto loop = [&](size_t tick, size_t delta)
			{
				auto process = [tick, delta](uint32_t entity, T_Component& component, T_Args&... args)
				{
					UNUSED(entity); helper::deref(component).next_frame(args..., tick, delta);
				};

				Job* job = for_components<T_Component, T_Args...>(m_job_system, nullptr, process);
				m_job_system.complete(job);
			};

			m_pump.add_step({ task, loop });
		}

		JobSystem& m_job_system;
		JobPump m_pump;
	};

	class refl_ TOY_CORE_EXPORT DefaultWorld : public Complex
	{
	public:
		constr_ DefaultWorld(const string& name);
		~DefaultWorld();

		comp_ attr_ World m_world;
		comp_ attr_ BulletWorld m_bullet_world;
		comp_ attr_ Navmesh m_navmesh;
	};
}
