//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <ecs/Entity.h>
#include <math/Timer.h>
#include <core/Forward.h>

using namespace mud; namespace toy
{
    class refl_ TOY_CORE_EXPORT WorldClock
    {
    public:
        WorldClock(World& world);
        ~WorldClock();

		double stepClock();

		void setSpeed(float speed);
        double stepClock(double realStep);
		double readClock();

		double readSymbolic();

    private:
		World& m_world;
		Clock m_clock;

		float m_speed;
		double m_time;
		double m_symbolicTime;
    };
}
