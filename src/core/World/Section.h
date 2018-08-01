//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <obj/Util/LocklessQueue.h>
#include <obj/Unique.h>
#include <math/Timer.h>
#include <core/Forward.h>

#ifndef MUD_CPP_20
#include <vector>
#include <thread>
#include <mutex>
#include <algorithm>
#include <functional>
#endif

using namespace mud; namespace toy
{
	enum class Task : unsigned int
	{
		World = 0,
		Entity = 1,
		State = 2,
		Physics = 3,
		PhysicsWorld = 4,
		GameObject = 5,
		Ui = 6,
		Graphics = 7,
		Core = 8,
		Cleanup = 9,
		Loader = 10,
		Count = 11,
		Background = 12,
	};

	/* Threading recap :
			TaskSection 0 - MonoThread
				BulletWorld next_frame
					read write BulletCollider (CONFLICT with section 2)

			TaskSection 1 - MonoThread
				Actor next_frame
					Observer handleSetCurrentAction
					Action	execute
							next_frame

				Active next_frame
					Effect update

				Camera next_frame
					Observer cameraUpdated

				Entity next_frame
					Observer transformUpdated

				Movable
					Manipulator update
					Observer movementUpdated
								accelerationUpdated
					Entity updatePosition
							updateRotation

				Agent next_frame (lock : position)
					MotionStrategy update (position)

			TaskSection 2 - MonoThread
				Collider next_frame
					receive entity position
					read write BulletCollider (CONFLICT with section 0)

			TaskSection 3 - MonoThread
				Reactive next_frame
					Behavior update

				Human next_frame
	*/

	class refl_ TOY_CORE_EXPORT TaskSection
	{
	public:
		TaskSection(short int id);
		virtual ~TaskSection();

		virtual void update() = 0;
		
		virtual void add_task(Updatable* task) = 0;
		virtual void remove_task(Updatable* task) = 0;

		short int m_id;
		Clock m_clock;
		size_t m_last_tick;
	};

	typedef std::function<void()> TaskFunc;

	class refl_ TOY_CORE_EXPORT QueueSection : public TaskSection
	{
	public:
		QueueSection(short int id);

		void update();

		void add_task(Updatable* task) { UNUSED(task); }
		void remove_task(Updatable* task) { UNUSED(task); }

		void add_task(TaskFunc task) { m_task_queue.push(task); }

	private:
		unique_ptr<std::thread> m_thread;
		LocklessQueue<TaskFunc> m_task_queue;
	};

	class refl_ TOY_CORE_EXPORT MonoSection : public TaskSection
	{
	public:
		MonoSection(short int id, bool thread = false);

		void update();

		void add_task(Updatable* task);
		void remove_task(Updatable* task);

	private:
		std::vector<Updatable*> m_tasks;
		std::vector<Updatable*> m_tasks_buffer;
		std::mutex m_mutex;
		unique_ptr<std::thread> m_thread;
	};

	class refl_ TOY_CORE_EXPORT ParallelSection  : public TaskSection
	{
	public:
		ParallelSection(short int id);

		void update();
		void worker_update();

	private:
		unique_ptr<std::thread> m_thread;
		std::vector<unique_ptr<std::thread>> m_workers;

		int m_task_cursor;
		int m_task_queue_size;
		LocklessQueue<Updatable*> m_task_queue;
	};
}
