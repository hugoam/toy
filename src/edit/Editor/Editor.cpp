//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <stl/algorithm.h>
#include <edit/Types.h>
#include <edit/Editor/Editor.h>

#include <type/DispatchDecl.h>

#include <core/User.h>

#include <lang/VisualScript.h>

namespace toy
{
	RunTool::RunTool(ToolContext& context, Editor& editor)
		: Tool(context, "Run", type<UndoTool>())
		, m_editor(editor)
	{}

	void RunTool::activate()
	{
		m_editor.m_run_game = !m_editor.m_run_game;
		m_state = m_editor.m_run_game ? ToolState::Active : ToolState::Inactive;
	}

	PlayTool::PlayTool(ToolContext& context, Editor& editor)
		: Tool(context, "Play", type<UndoTool>())
		, m_editor(editor)
	{}

	void PlayTool::activate()
	{
		m_editor.m_play_game = !m_editor.m_play_game;
		m_state = m_editor.m_play_game ? ToolState::Active : ToolState::Inactive;
	}

	Editor::Editor(GfxSystem& gfx)
		: EditContext(gfx)
		, m_run_tool(m_tool_context, *this)
		, m_play_tool(m_tool_context, *this)
		, m_frame_view_tool(m_tool_context)
	{
		extend(m_toolbelt.toolbox("Action").m_tools, { &m_undo_tool, &m_redo_tool, &m_run_tool, &m_play_tool });
		//extend(m_toolbelt.toolbox("View").m_tools, { &m_view_tools.m_top, &m_view_tools.m_bottom, &m_view_tools.m_front, &m_view_tools.m_back, &m_view_tools.m_left, &m_view_tools.m_right });
		//extend(m_toolbelt.toolbox("View").m_tools, { &m_frame_view_tool });

		//m_toolbelt.toolbox("Brushes").m_tools.add(oconstruct<PlaceBrush>(*this));
		//m_toolbelt.toolbox("Brushes").m_tools.add(oconstruct<CircleBrush>(*this));

		//m_toolbox->updateTools();
	}

	void Editor::update()
	{
		m_tool_context.m_action_stack = &m_action_stack;
		m_tool_context.m_work_plane = &m_work_plane;
		m_tool_context.m_selection = &m_selection.objects;

		m_run_tool.m_state = m_run_game ? ToolState::Active : ToolState::Inactive;
		m_play_tool.m_state = m_play_game ? ToolState::Active : ToolState::Inactive;
	}

	void Editor::create_scripted_brush()
	{
#if 0
		Signature signature({ Param("position", var(vec3(0.f))) });
		VisualScript& script = global_pool<VisualScript>().construct("Brush VisualScript", signature);

		//m_toolbelt.toolbox("Brushes").m_tools.add(oconstruct<ScriptedBrush>(*this, m_editedWorld->origin(), script));
#endif
	}

	ActionGroup& Editor::action_group(const string& name)
	{
		if(m_action_groups.find(name) == m_action_groups.end())
			m_action_groups[name] = { name, {} };
		return m_action_groups[name];
	}
}
