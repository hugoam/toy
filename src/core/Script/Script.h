//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <infra/NonCopy.h>
#include <core/Forward.h>
#include <core/Spatial/Spatial.h>

#include <string>

using namespace mud; namespace toy
{
	using string = std::string;

	class refl_ TOY_CORE_EXPORT ComponentPool
	{

	};

	class refl_ TOY_CORE_EXPORT EntityScript
	{
	public:
		constr_ EntityScript() {}
		constr_ EntityScript(HSpatial spatial);
		
		comp_ HSpatial m_spatial;
		attr_ Script* m_logic_script = nullptr;
		attr_ Script* m_render_script = nullptr;

		void next_frame(size_t tick, size_t delta);

		void run_logic();
		void run_render(); // Gnode& parent
	};
}
