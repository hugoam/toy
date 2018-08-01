//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.


#include <edit/Types.h>
#include <edit/Editor/Toolbox.h>

#include <tool/Tool.h>
#include <tool/Brush.h>

#include <core/Selector/Selection.h>

using namespace mud; namespace toy
{
	Toolbox::Toolbox(cstring name)
		: m_name(name)
		, m_tools()
	{}

	Toolbox::~Toolbox()
	{}

	DynamicToolbox::DynamicToolbox(cstring name, const Selection& targets)
		: Toolbox(name)
		, m_current_tools()
		, m_targets(targets)
	{
		//m_targets.observe(*this);
	}

	void DynamicToolbox::update_tools(const Selection& targets)
	{
		UNUSED(targets);
		m_current_tools.clear();

		for(auto& tool : m_tools)
			if(tool->enabled(targets))
				vector_add(m_current_tools, tool.get());
	}

	Toolbelt::Toolbelt()
		: m_toolboxes()
		, m_activeTool(nullptr)
		, m_activeBrush(nullptr)
	{}

	Toolbox& Toolbelt::toolbox(cstring name)
	{
		if(!m_toolboxes[name])
			m_toolboxes[name] = make_object<Toolbox>(name);
		return *m_toolboxes[name];
	}

	void Toolbelt::setActiveTool(Tool& tool)
	{
		if(m_activeTool)
			m_activeTool->deactivate();

		m_activeTool = &tool;

		if(is<Brush>(tool))
			m_activeBrush = &as<Brush>(tool);
	}
}
