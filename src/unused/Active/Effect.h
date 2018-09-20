//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <core/Forward.h>

#ifndef MUD_CPP_20
#include <string>
#endif

using namespace mud; namespace toy
{
	using string = std::string;

	class EffectCallback { public: virtual void effectEnded(Effect& effect) = 0; };

	class refl_ TOY_CORE_EXPORT Effect
	{
	public:
		constr_ Effect(Active& active, const string& name, float duration = 0.f, bool loop = true);

		bool update(size_t tick, double step);
		void stop();

		Active* m_active;
		string m_name;
		float m_duration;
		bool m_loop;

	protected:
		double m_currentTime;
		bool m_done;
	};
}
