//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/Medium/SoundMedium.h>

#include <core/Spatial/Spatial.h>
#include <core/Physic/Collider.h>

namespace toy
{
	SoundMedium SoundMedium::me;

	SoundMedium::SoundMedium()
		: Medium("SoundMedium")
	{
		m_masks[CM_OBSTACLE] = CM_NOMASK;
		m_masks[CM_SOURCE] = CM_RECEPTOR;
		m_masks[CM_RECEPTOR] = CM_SOURCE;
	}
}
