//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/World/WorldClock.h>

#include <core/Spatial/Spatial.h> // @kludge
#include <core/World/World.h>
#include <math/Timer.h>

namespace toy
{
    WorldClock::WorldClock()
	{}

	double WorldClock::step()
	{
        double timeStep = m_clock.read();
        m_clock.update();
		return this->step(timeStep);
	}

    double WorldClock::step(double step)
	{
		m_symbolic_time += step * m_speed;
		m_time += step;
		return step * m_speed;
	}

	double WorldClock::read()
	{
		return m_time;
	}

	double WorldClock::symbolic()
	{
		return m_symbolic_time;
	}
}
