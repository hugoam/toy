//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.


#include <edit/Edit/Editor.h>

#include <tool//EditContext.h>
#include <edit/Editor/Editor.h>

#include <infra/StringConvert.h>
#include <type/Indexer.h>
#include <refl/System.h>
#include <refl/Class.h>
#include <refl/Meta.h>

#include <edit/Editor/Editor.h>
#include <edit/Editor/Toolbox.h>

#include <core/Spatial/Spatial.h>
#include <core/World/World.h>
//#include <core/Selector/Selector.h>

#include <gfx/Item.h>
#include <gfx/GfxSystem.h>
#include <gfx-ui/Viewport.h>
#include <gfx-edit/GfxEdit.h>

#include <uio/Edit/Section.h>
#include <uio/Edit/Injector.h>
#include <uio/Edit/Indexer.h>
#include <uio/Edit/Structure.h>
#include <uio/Edit/Inspector.h>
#include <uio/Object.h>

#include <ui/Style/Layout.h>
#include <ui/Structs/Container.h>
#include <ui/Structs/Dock.h>

#include <visu/VisuScene.h>

using namespace mud; namespace toy
{
#if 0
	void context_menu(Widget& parent, Selector& selector, Ref object)
	{
		UNUSED(parent); UNUSED(selector); UNUSED(object);
		popup(parent, [&] { parent.destroy(); }, nullptr);

		if(selector.m_selection.has(val<IdObject>(object)))
			for(auto& method : selector.m_methods.store())
				if(ui::button(parent, method->m_name).activated())
					selector.execute(*method);
		else
			for(auto& action : selector.m_actions.store())
				if(ui::button(parent, action->m_name).activated())
					selector.execute(*action);

		for(auto& action : m_echobject.m_methods)
		this->emplace<Deck>().maker(&make_device<CarbonMethod, DMethod>).tstore<CarbonMethod>();
	}
#endif

	string to_icon(const string& name)
	{
		string clean = replace_all(to_lower(name), " ", "_");
		return "(" + clean + ")";
	}

	void tool_button(Widget& parent, Tool& tool)
	{
		Widget& button = ui::button(parent, to_icon(tool.m_name).c_str());
		button.set_state(ACTIVE, tool.m_state == ToolState::Active);
		if (button.activated())
			tool.activate();
	}

	void edit_toolbox(Widget& parent, Toolbox& toolbox)
	{
		for(auto& tool : toolbox.m_tools)
			tool_button(parent, *tool);
	}

	void edit_toolbelt(Widget& parent, Toolbelt& toolbelt)
	{
		Widget& self = ui::toolbar(parent);
		for(auto& name_toolbox : toolbelt.m_toolboxes)
			edit_toolbox(self, *name_toolbox.second);
	}

	void edit_selection(Widget& parent, Selection& selection)
	{
		Widget& self = ui::select_list(parent);

		for(Ref object : selection)
			object_item(self, object);
	}

#if 0
	void edit_selector(Widget& parent, Selector& selector)
	{
		Widget& self = section(parent, "Selector");
		Widget& tabber = ui::tabber(self);

		edit_selection(tabber, selector.m_selection); // "Selection"
		edit_selection(tabber, selector.m_targets); // "Targets"
	}
#endif

	void scene_edit(Widget& parent, World& world)
	{
		UNUSED(parent); UNUSED(world);
	}

	std::vector<Type*> entity_types()
	{
		auto has_component = [](Class& cls, Type& component)
		{
			for(Member* member : cls.m_components)
				if(member->m_type->is(component))
					return true;
			return false;
		};

		std::vector<Type*> types;
		for(Type* type : system().m_types)
			if(g_class[type->m_id])
			{
				if(has_component(cls(*type), mud::type<Spatial>()))
					types.push_back(type);
			}
		return types;
	}

	void registry_section(Widget& parent, Indexer& indexer, Selection& selection)
	{
		enum Modes { CREATE = 1 << 0 };

		Section& self = section(parent, (string(indexer.m_type.m_name) + " Registry").c_str());
		complex_indexer(*self.m_body, indexer, &selection);

		if(ui::modal_button(self, *self.m_toolbar, "Create", CREATE))
		{
			static std::vector<Type*> types = entity_types();

			Widget& modal = ui::auto_modal(self, CREATE); //, { 600, 400 });
			object_switch_creator(modal, types);
		}
	}

	void library(Widget& parent, const std::vector<Type*>& types, Selection& selection)
	{
		Tabber& self = ui::tabber(parent);

		for(Type* type : types)
			if(Widget* tab = ui::tab(self, type->m_name))
			{
				registry_section(*tab, indexer(*type), selection);
			}
	}

	void library_section(Widget& parent, const std::vector<Type*>& types, Selection& selection)
	{
		Section& self = section(parent, "Library");
		library(*self.m_body, types, selection);
	}

	void editor_menu(Widget& parent, ActionGroup& action_group)
	{
		Widget& self = ui::menu(parent, action_group.m_name.c_str());

		if(self.m_body)
			for(auto& action : action_group.m_actions)
			{
				if(ui::button(*self.m_body, action.first.c_str()).activated())
					action.second();
			}
	}

	void editor_menu_bar(Widget& parent, Editor& editor)
	{
		Widget& self = ui::menubar(parent);

		for(auto& name_group : editor.m_action_groups)
			editor_menu(self, name_group.second);
	}

	string entity_name(uint32_t entity)
	{
		return string(entity_prototype({ entity, 0 })) + ":" + to_string(entity);
	}

	string entity_icon(uint32_t entity)
	{
		return "(" + string(entity_prototype({ entity, 0 })) + ")";
	}

	void outliner_node(Widget& parent, uint32_t entity, HSpatial spatial, std::vector<Ref>& selection)
	{
		TreeNode& self = ui::tree_node(parent, carray<cstring, 2>{ entity_icon(entity).c_str(), entity_name(entity).c_str() }, false, false);

		self.m_header->set_state(SELECTED, vector_has(selection, ent_ref(entity)));

		if(self.m_header->activated())
			vector_select(selection, ent_ref(entity));

		//object_item(self, object);

		if(self.m_body)
			for(HSpatial child : spatial->m_contents)
			{
				outliner_node(*self.m_body, child.m_handle, child, selection);
			}
	}

	void outliner_graph(Widget& parent, HSpatial spatial, std::vector<Ref>& selection)
	{
		ScrollSheet& sheet = ui::scroll_sheet(parent);
		Widget& tree = ui::tree(*sheet.m_body);
		outliner_node(tree, spatial.m_handle, spatial, selection);
	}

	void editor_graph(Widget& parent, Editor& editor, Selection& selection)
	{
		Section& self = section(parent, "Outliner");

		if(!editor.m_edited_world)
			return;

		HSpatial origin = editor.m_edited_world->origin();
		//structure_view(*self.m_body, Ref(&origin), selection);
		outliner_graph(*self.m_body, origin, selection);
	}

	void graphics_debug_section(Widget& parent, Dockspace& dockspace, Editor& editor)
	{
		UNUSED(dockspace);
		for(Scene* scene : editor.m_scenes)
		{
			editor.m_graphics_debug.m_debug_draw_csm = true;
			if(editor.m_graphics_debug.m_debug_draw_csm)
			{
				//Widget* dock = ui::dockitem(dockspace, "Screen", carray<uint16_t, 2>{ 0U, 1U });
				//if(dock)
				{
					//Viewer& viewer = ui::viewer(*dock, *scene);
					Viewer& viewer = ui::viewer(parent, *scene);
					viewer.m_camera.m_far = 1000.f;
					ui::orbit_controller(viewer);

					scene->m_pool->pool<Light>().iterate([&](Light& light) {
						debug_draw_light_slices(scene->m_graph, light);
					});
				}
			}
		}
	}
	
	Docksystem& editor_docksystem()
	{
		static Docksystem docksystem;
		return docksystem;
	}

	void editor_components(Widget& parent, Editor& editor)
	{
		static Docksystem& docksystem = editor_docksystem();
		Dockspace& dockspace = ui::dockspace(parent, docksystem);

		std::vector<Type*> library_types = { &type<Spatial>(), &type<World>() };
		if(Widget* dock = ui::dockitem(dockspace, "Outliner", carray<uint16_t, 2>{ 0U, 0U }))
			editor_graph(*dock, editor, editor.m_selection);
		if(Widget* dock = ui::dockitem(dockspace, "Library", carray<uint16_t, 2>{ 0U, 0U }))
			library_section(*dock, library_types, editor.m_selection);
		if(Widget* dock = ui::dockitem(dockspace, "Inspector", carray<uint16_t, 2>{ 0U, 2U }))
			object_editor(*dock, editor.m_selection);
		//edit_selector(self, editor.m_selection); // dockid { 0, 2 }
		if(Widget* dock = ui::dockitem(dockspace, "Script", carray<uint16_t, 2>{ 0U, 2U }))
			script_editor(*dock, editor.m_script_editor);
		//current_brush_edit(self, editor); // dockid { 0, 0 }
		//ui_edit(self, editor.m_selection); // dockid { 0, 2 }
		if (Widget* dock = ui::dockitem(dockspace, "Graphics", carray<uint16_t, 2>{ 0U, 2U }))
			edit_gfx_system(*dock, editor.m_gfx_system);

		editor.m_screen = ui::dockitem(dockspace, "Screen", carray<uint16_t, 2>{ 0U, 1U }, 4.f);
		
		//if(editor.m_editedScene)
		{
			//scene_viewport(self, *editor.m_editedScene); // dockid { 0, 1 } dockspan 4.f
			//painter_panel(self, *editor.m_editedScene); // dockid { 0, 2 }
		}

		if(editor.m_viewer)
		{
			if(MouseEvent mouse_event = editor.m_viewer->mouse_event(DeviceType::MouseLeft, EventType::Stroked, InputMod::None, false))
				editor.m_viewer->take_focus();

			viewport_picker(*editor.m_viewer, *editor.m_viewer, editor.m_selection);

			KeyEvent key_event = editor.m_viewer->key_event(Key::F, EventType::Pressed);
			if(key_event)
				editor.m_frame_view_tool.activate();
		}

		if(editor.m_spatial_tool && editor.m_viewer)
			editor.m_spatial_tool->process(*editor.m_viewer, editor.m_selection);
	}

	Widget& editor_viewer_overlay(Viewer& viewer, Editor& editor)
	{
		UNUSED(viewer);
		Widget& layout = ui::screen(*editor.m_viewer);
		Widget& toolbar = ui::row(layout);
		tools_transform(toolbar, editor);

		auto entry = [](Widget& parent, cstring name, int value)
		{
			Widget& row = ui::row(parent);
			ui::label(row, name);
			ui::label(row, to_string(value).c_str());
		};

		float eps = 0.0000001f;
		entry(layout, "frame time", int(editor.m_gfx_system.m_frame_time * 1000.f));
		entry(layout, "frame per second", int(1.f / max(editor.m_gfx_system.m_frame_time, eps)));

		return layout;
	}

	Viewer& editor_viewport(Widget& parent, Scene& scene)
	{
		Viewer& self = ui::viewer(parent, scene);
		ui::free_orbit_controller(self);
		return self;
	}

	void editor(Widget& parent, Editor& editor, Widget*& screen)
	{
		editor.update();

		if(editor.m_viewer)
		{
			editor.m_tool_context.m_camera = &editor.m_viewer->m_camera;
		}

		Widget& self = ui::layout(parent);

		editor_menu_bar(self, editor);
		edit_toolbelt(self, editor.m_toolbelt);
		editor_components(self, editor);

		screen = editor.m_screen;

		if(editor.m_play_game)
			editor.m_viewer = nullptr;
		else if(editor.m_scenes.size() > 0 && screen)
		{
			Widget& sheet = ui::widget(*screen, styles().sheet, &editor);
			editor.m_viewer = &editor_viewport(sheet, *editor.m_scenes[0]);
		}

		if(editor.m_viewer)
		{
			Ref hovered = editor.m_viewer->m_hovered ? editor.m_viewer->m_hovered->m_node->m_object : Ref();
			paint_selection(editor.m_viewer->m_scene->m_graph, editor.m_selection, hovered);
			//Widget& layout = toy::editor_viewer_overlay(*editor.m_viewer, editor);
			//time_entries(layout);
		}
		else
		{
			//Widget& layout = ui::screen(*screen);
			//time_entries(layout);
		}

		//m_scriptEditor.m_actions.emplace<Response>("Create Scripted Brush", [this] { this->createScriptedBrush(); });
	}

	void mini_editor(Widget& parent, Editor& editor, Widget*& screen)
	{
		editor.update();

		Widget& board = ui::board(parent);

		Widget& left = ui::sheet(board);
		Section& right = section(board, "Game Editor");

		tool_button(*right.m_toolbar, editor.m_run_tool);
		tool_button(*right.m_toolbar, editor.m_play_tool);
		
		TextScript& script = as<TextScript>(*editor.m_script_editor.m_scripts[0]);

		Tabber& tabber = ui::tabber(*right.m_body);
		if(Widget* tab = ui::tab(tabber, "Script"))
			script_edit(*tab, script);
		if(Widget* tab = ui::tab(tabber, "Outliner"))
			editor_graph(*tab, editor, editor.m_selection);
		if(Widget* tab = ui::tab(tabber, "Inspector"))
			object_editor(*tab, editor.m_selection);

		screen = &left;
	}
}
