//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/Active/Effect.h>

#include <core/Active/Active.h>

using namespace two; namespace toy
{
	Effect::Effect(Active& active, const string& name, float duration, bool loop)
		: m_active(&active)
		, m_name(name)
		, m_duration(duration)
		, m_loop(loop)
		, m_currentTime(0.f)
		, m_done(false)
	{}

	void Effect::stop()
	{
		m_done = true;
	}

	bool Effect::update(size_t tick, double step)
	{
		UNUSED(tick);

		m_currentTime += step;
		if(!m_loop && m_currentTime >= m_duration)
			this->stop();

		return !m_done;
	}
}
