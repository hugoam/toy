//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <edit/Forward.h>
#include <core/Spatial/Spatial.h>
#include <edit/Types.h>

#ifndef MUD_CPP_20
#include <map>
#include <string>
#endif

using namespace mud; namespace toy
{
	using string = std::string;
	using Selection = std::vector<Ref>;

	class refl_ Toolbox : public NonCopy
	{
	public:
		Toolbox(cstring name);
		virtual ~Toolbox();

		string m_name;
		std::vector<Tool*> m_tools;
	};

	class refl_ DynamicToolbox : public Toolbox
	{
	public:
		DynamicToolbox(cstring name, const Selection& targets);

		void update_tools(const Selection& targets);

	protected:
		std::vector<Tool*> m_current_tools;

		const Selection& m_targets;
	};

	class refl_ Toolbelt : public NonCopy
	{
	public:
		Toolbelt();

		std::map<string, object_ptr<Toolbox>> m_toolboxes;

		Tool* m_activeTool;
		Brush* m_activeBrush;

		Toolbox& toolbox(cstring name);

		void setActiveTool(Tool& tool);
	};
}
