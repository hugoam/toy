//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <stl/vector.h>
#include <core/Forward.h>

namespace toy
{
	class TOY_CORE_EXPORT Signal
	{
	public:
		Signal() {}
		Signal(EmitterScope& emitter, ReceptorScope& receptor);
		~Signal();

		EmitterScope* m_emitter = nullptr;
		ReceptorScope* m_receptor = nullptr;
		float m_strength = 0.f;
		bool m_on = false;

		void update();
		void on();
		void off();

	private:
		vector<Obstacle*> m_occluding;
	};
}
