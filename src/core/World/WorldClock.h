//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <math/Timer.h>
#include <core/Forward.h>

namespace toy
{
    class refl_ TOY_CORE_EXPORT WorldClock
    {
    public:
        WorldClock();

		double step();
        double step(double step);

		double read();
		double symbolic();

    private:
		Clock m_clock;

		float m_speed = 1.f;
		double m_time = 0.f;
		double m_symbolic_time = 0.f;
    };
}
