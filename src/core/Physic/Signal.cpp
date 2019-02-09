//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/Physic/Signal.h>

#include <core/Spatial/Spatial.h>
#include <core/Spatial/Spatial.h>

#include <core/Physic/Scope.h>
#include <core/Physic/Medium.h>
#include <core/Physic/PhysicWorld.h>
#include <core/Physic/Obstacle.h>

namespace toy
{
	Signal::Signal(EmitterScope& emitter, ReceptorScope& receptor)
		: m_emitter(&emitter)
		, m_receptor(&receptor)
	{
		if(!m_emitter->m_collider->m_medium->m_occlusions)
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
		if(m_emitter->m_collider->m_medium->m_occlusions)
		{
			vector<Collision> occluding;

			Spatial& receptor = m_receptor->m_spatial;
			m_emitter->m_collider->m_impl->raycast(receptor.m_position, occluding, CM_OBSTACLE);

			m_occluding.clear();
			//for(const Collision& coll : occluding)
			//	m_occluding.push_back(static_cast<Obstacle*>(coll.m_second));

			m_strength = m_emitter->m_collider->m_medium->throughput(*m_emitter, *m_receptor, m_occluding);

			if(m_strength > 0.f && !m_on)
				this->on();
			else if(m_strength == 0.f && m_on)
				this->off();
		}
	}

	void Signal::on()
	{
		m_on = true;
		m_receptor->add_scope(m_emitter->m_spatial);
		m_emitter->add_scope(m_receptor->m_spatial);
	}

	void Signal::off()
	{
		m_on = false;
		m_receptor->remove_scope(m_emitter->m_spatial);
		m_emitter->remove_scope(m_receptor->m_spatial);
	}
}
