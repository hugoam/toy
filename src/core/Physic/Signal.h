//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <core/Forward.h>

#ifndef MUD_CPP_20
#include <vector>
#endif

using namespace mud; namespace toy
{
	class TOY_CORE_EXPORT Signal
	{
	public:
		Signal(EmitterScope& emitter, ReceptorScope& receptor);
		~Signal();

		EmitterScope* m_emitter;
		ReceptorScope* m_receptor;
		float m_strength;
		bool m_on;

		void update();
		void on();
		void off();

	private:
		std::vector<Obstacle*> m_occluding;
	};
}
