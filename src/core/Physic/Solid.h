//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <core/Forward.h>
#include <core/Physic/Medium.h>

namespace toy
{
	class refl_ TOY_CORE_EXPORT SolidMedium final : public Medium
	{
	public:
		constr_ SolidMedium();
		attr_ static SolidMedium me;
	};
}
