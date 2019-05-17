//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/Physic/Solid.h>

namespace toy
{
	SolidMedium SolidMedium::me;

	SolidMedium::SolidMedium()
		: Medium("SolidMedium")
	{
		m_solid = true;
		m_masks[CM_SOLID] = CM_SOLID | CM_GROUND;
		m_masks[CM_GROUND] = CM_GROUND | CM_SOLID;
	}
}
