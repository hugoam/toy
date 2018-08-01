//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/Physic/Signal.h>

#include <core/Entity/Entity.h>
#include <core/Entity/Entity.h>

#include <core/Physic/Scope.h>
#include <core/Physic/Medium.h>
#include <core/Physic/PhysicWorld.h>
#include <core/Physic/Obstacle.h>

using namespace mud; namespace toy
{
	Signal::Signal(EmitterScope& emitter, ReceptorScope& receptor)
		: m_emitter(&emitter)
		, m_receptor(&receptor)
		, m_strength(0.f)
		, m_on(false)
		, m_occluding()
	{
		if(!m_emitter->m_medium.m_occlusions)
			this->on();

		update();
	}

	Signal::~Signal()
	{
		if(m_on)
			this->off();
	}

	void Signal::update()
	{
		if(m_emitter->m_medium.m_occlusions)
		{
			std::vector<Collision> occluding;

			m_emitter->m_impl->raycast(m_receptor->m_entity.m_position, occluding, CM_OBSTACLE);

			m_occluding.clear();

			for(const Collision& coll : occluding)
				m_occluding.push_back(static_cast<ObstacleBody*>(coll.m_second));

			m_strength = m_emitter->m_medium.throughput(*m_emitter, *m_receptor, m_occluding);

			if(m_strength > 0.f && !m_on)
				this->on();
			else if(m_strength == 0.f && m_on)
				this->off();
		}
	}

	void Signal::on()
	{
		m_on = true;
		m_receptor->m_scope.add(m_emitter->m_entity);
		m_emitter->m_scope.add(m_receptor->m_entity);
	}

	void Signal::off()
	{
		m_on = false;
		m_receptor->m_scope.remove(m_emitter->m_entity);
		m_emitter->m_scope.remove(m_receptor->m_entity);
	}
}
