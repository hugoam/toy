//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <stl/vector.h>
#include <stl/string.h>
#include <stl/map.h>
#include <core/Forward.h>
#include <core/Physic/CollisionGroup.h>

namespace toy
{
	//@todo : cleanup, remove references to emitters and receptors since it's not supposed to be specific
	//			make_unique masks stored in a map based on the group
    class refl_ TOY_CORE_EXPORT Medium
	{
	public:
		Medium(const string& name, bool occlusions = false);

		attr_ string m_name;
		attr_ bool m_occlusions;
		attr_ bool m_solid;

		map<CollisionGroup, short int> m_masks;

		short int mask(CollisionGroup group);

		virtual float throughput(EmitterScope& emitter, ReceptorScope& receptor, vector<Obstacle*>& occluding);
	};
}
