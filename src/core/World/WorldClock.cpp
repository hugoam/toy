//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/World/WorldClock.h>

#include <core/Spatial/Spatial.h> // @kludge
#include <core/World/World.h>
#include <math/Timer.h>

using namespace mud; namespace toy
{
    WorldClock::WorldClock(World& world)
		: m_world(world)
		, m_clock()
		, m_speed(1.f)
		, m_time(0.f)
		, m_symbolicTime(0.f)
	{}

	WorldClock::~WorldClock()
	{}

	void WorldClock::setSpeed(float speed)
	{
		m_speed = speed;
	}

	double WorldClock::stepClock()
	{
        double timeStep = m_clock.read();
        m_clock.update();

		return this->stepClock(timeStep);
	}

    double WorldClock::stepClock(double realStep)
	{
		m_symbolicTime += realStep * m_speed;
		m_time += realStep;
		return realStep * m_speed;
	}

	double WorldClock::readClock()
	{
		return m_time;
	}

	double WorldClock::readSymbolic()
	{
		return m_symbolicTime;
	}
}
