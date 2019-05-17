//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/Medium/VisualMedium.h>

#include <core/Spatial/Spatial.h>
#include <core/Physic/Collider.h>

namespace toy
{
	VisualMedium VisualMedium::me;

	VisualMedium::VisualMedium()
		: Medium("VisualMedium")
	{	
		m_masks[CM_LIGHT] = CM_LIGHTREFLECTOR;
		m_masks[CM_LIGHTREFLECTOR] = CM_LIGHT;
	}
}
