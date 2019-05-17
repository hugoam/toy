//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <stl/map.h>
#include <stl/function.h>
#include <tool/Tool.h>
#include <tool/ActionStack.h>
#include <tool/EditContext.h>
#include <edit/Forward.h>
#include <edit/Editor/Toolbox.h>

#include <uio/ScriptEdit.h>

namespace toy
{
	export_ class refl_ TOY_EDIT_EXPORT PlayTool : public Tool
	{
	public:
		PlayTool(ToolContext& context, Editor& editor);

		virtual void activate() final;

		Editor& m_editor;
	};

	export_ class refl_ TOY_EDIT_EXPORT RunTool : public Tool
	{
	public:
		RunTool(ToolContext& context, Editor& editor);

		virtual void activate() final;

		Editor& m_editor;
	};

	struct refl_ TOY_EDIT_EXPORT ActionGroup
	{
		string m_name;
		map<string, function<void()>> m_actions;
	};

	struct refl_ TOY_EDIT_EXPORT GraphicsDebug
	{
		bool m_debug_draw_csm = false;
	};

	class refl_ TOY_EDIT_EXPORT Editor : public EditContext
    {
    public:
		Editor(GfxSystem& gfx);
        
		Toolbelt m_toolbelt;

		attr_ RunTool m_run_tool;
		attr_ PlayTool m_play_tool;
		
		attr_ FrameViewTool m_frame_view_tool;

		map<string, ActionGroup> m_action_groups;

		attr_ World* m_edited_world = nullptr;
		attr_ bool m_run_game = false;
		attr_ bool m_play_game = false;

		vector<Scene*> m_scenes;

		GraphicsDebug m_graphics_debug;

		void update();

		void create_scripted_brush();

		ActionGroup& action_group(const string& name);
    };
}
