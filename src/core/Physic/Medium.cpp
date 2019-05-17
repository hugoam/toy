//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/Physic/Medium.h>

#include <core/Physic/Collider.h>
#include <core/Physic/Obstacle.h>
#include <core/Physic/Scope.h>

namespace toy
{
	Medium::Medium(const string& name, bool occlusions)
		: m_name(name)
		, m_occlusions(occlusions)
		, m_solid(false)
	{
		m_masks[CM_SOURCE] = CM_RECEPTOR;
		m_masks[CM_RECEPTOR] = CM_SOURCE;
		m_masks[CM_OBSTACLE] = CM_OBSTACLE;
	}

	short int Medium::mask(CollisionGroup group)
	{
		return m_masks[group];
	}

	float Medium::throughput(EmitterScope& emitter, ReceptorScope& receptor, vector<Obstacle*>& occluding)
	{
		UNUSED(emitter); UNUSED(receptor);

		float throughput = 1.f;

		for(Obstacle* obstacle : occluding)
		{
			if(obstacle->m_throughput <= 0.f)
				return 0.f;
			
			throughput *= obstacle->m_throughput;
		}

		//float distance2 = source->m_position.distance2(receptor->m_position);
		
		//if(distance2 > 1.f)
		//	throughput *= 1/distance2;

		return throughput;
	}
}
