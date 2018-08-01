//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/World/Section.h>

#include <infra/Updatable.h>
#include <infra/Vector.h>

#ifndef MUD_CPP_20
#include <memory>
#include <thread>
#endif

#define NUM_THREADS 2

using namespace mud; namespace toy
{
	TaskSection::TaskSection(short int id)
		: m_id(id)
		, m_clock()
		, m_last_tick(0)
	{}

	TaskSection::~TaskSection()
	{}

	QueueSection::QueueSection(short int id)
		: TaskSection(id)
		, m_thread(make_unique<std::thread>([this] { this->update(); }))
		, m_task_queue(50)
	{}

	void QueueSection::update()
	{
		if(!m_task_queue.empty())
		{
			TaskFunc task;
			m_task_queue.pop(task);
			task();
		}
	}

	MonoSection::MonoSection(short int id, bool thread)
		: TaskSection(id)
		, m_tasks()
#ifdef MUD_PLATFORM_EMSCRIPTEN
		, m_thread(nullptr)
#else
		, m_thread(thread ? make_unique<std::thread>([this] { while(true) this->update(); }) : nullptr)
#endif
	{}

	void MonoSection::add_task(Updatable* task)
	{
#ifdef MUD_PLATFORM_EMSCRIPTEN
		m_tasks.push_back(task);
#else
		m_mutex.lock();
		m_tasks.push_back(task);
		m_mutex.unlock();
#endif
	}

	void MonoSection::remove_task(Updatable* task)
	{
#ifdef MUD_PLATFORM_EMSCRIPTEN
		vector_remove(m_tasks, task);
#else
		m_mutex.lock();
		vector_remove(m_tasks, task);
		m_mutex.unlock();
#endif
	}

	void MonoSection::update()
	{
		size_t tick = m_clock.readTick();
		size_t delta = m_clock.stepTick();

		m_last_tick = tick;

		size_t i = 0;

		m_tasks_buffer.clear();

#ifdef MUD_PLATFORM_EMSCRIPTEN
		m_tasks_buffer.assign(m_tasks.begin(), m_tasks.end());
#else
		m_mutex.lock();
		m_tasks_buffer.assign(m_tasks.begin(), m_tasks.end());
		m_mutex.unlock();
#endif

		for(Updatable* task : m_tasks_buffer)
		{
			task->next_frame(tick, delta);
			++i;
		}
	}

	ParallelSection::ParallelSection(short int id)
		: TaskSection(id)
		, m_thread(make_unique<std::thread>([this] { this->update(); }))
		, m_workers()
		, m_task_cursor(0)
		, m_task_queue_size(50)
		, m_task_queue(50)
	{
		for(int i = 0; i != NUM_THREADS; ++i)
			m_workers.emplace_back(make_unique<std::thread>([this] { this->worker_update(); }));
	}

	void ParallelSection::update()
	{
		if(!m_task_queue.empty())
			return;

		//int numTasks = 0;
		//for(; numTasks != m_task_queue_size && m_task_cursor != m_world->getTasks(m_id).size(); ++numTasks, ++mTaskCursor)
		//	m_task_queue.push(m_world->getTasks(m_id)[mTaskCursor]);
		
		m_task_cursor += m_task_queue_size;
	}

	void ParallelSection::worker_update()
	{
		if(m_task_queue.empty())
			return;

		// Symbolic time : double timeStep = m_world->stepClock(m_clock->step());
		size_t tick = m_clock.readTick();
		size_t delta = m_clock.stepTick();

		m_last_tick = tick;

		Updatable* task;
		m_task_queue.pop(task);
		task->next_frame(tick, delta);
	}

}
