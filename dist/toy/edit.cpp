#include <two/gfx.h>
#include <toy/visu.h>
#include <two/ui.h>
#include <two/geom.h>
#include <two/pool.h>
#include <toy/core.h>
#include <two/uio.h>
#include <two/gfx.pbr.h>
#include <two/tree.h>
#include <two/lang.h>
#include <two/ecs.h>
#include <two/gfx.edit.h>
#include <toy/edit.h>
#include <two/tool.h>
#include <two/ctx.h>
#include <two/gfx.ui.h>
#include <two/refl.h>
#include <two/infra.h>
#include <two/type.h>

#ifndef USE_STL
#ifdef TWO_MODULES
module toy.edit;
#else
#include <stl/vector.hpp>
#include <stl/unordered_map.hpp>
#endif

namespace stl
{
	using namespace toy;
	template class TOY_EDIT_EXPORT vector<Tool*>;
	template class TOY_EDIT_EXPORT unordered_map<string, function<void()>>;
	template class TOY_EDIT_EXPORT unordered_map<string, ActionGroup>;
	template class TOY_EDIT_EXPORT unordered_map<string, unique<Toolbox>>;
	template class TOY_EDIT_EXPORT unordered_map<Key, vec3>;
}
#endif

#ifdef TWO_MODULES
module toy.edit;
#else
#endif

namespace two
{
    // Exported types
    
    
    template <> TOY_EDIT_EXPORT Type& type<toy::Edit>() { static Type ty("Edit", sizeof(toy::Edit)); return ty; }
    template <> TOY_EDIT_EXPORT Type& type<toy::Clone>() { static Type ty("Clone", sizeof(toy::Clone)); return ty; }
    template <> TOY_EDIT_EXPORT Type& type<toy::Cut>() { static Type ty("Cut", sizeof(toy::Cut)); return ty; }
    template <> TOY_EDIT_EXPORT Type& type<toy::Paste>() { static Type ty("Paste", sizeof(toy::Paste)); return ty; }
    template <> TOY_EDIT_EXPORT Type& type<toy::Toolbox>() { static Type ty("Toolbox", sizeof(toy::Toolbox)); return ty; }
    template <> TOY_EDIT_EXPORT Type& type<toy::DynamicToolbox>() { static Type ty("DynamicToolbox", type<toy::Toolbox>(), sizeof(toy::DynamicToolbox)); return ty; }
    template <> TOY_EDIT_EXPORT Type& type<toy::Toolbelt>() { static Type ty("Toolbelt", sizeof(toy::Toolbelt)); return ty; }
    template <> TOY_EDIT_EXPORT Type& type<toy::PlayTool>() { static Type ty("PlayTool", type<two::Tool>(), sizeof(toy::PlayTool)); return ty; }
    template <> TOY_EDIT_EXPORT Type& type<toy::RunTool>() { static Type ty("RunTool", type<two::Tool>(), sizeof(toy::RunTool)); return ty; }
    template <> TOY_EDIT_EXPORT Type& type<toy::ActionGroup>() { static Type ty("ActionGroup", sizeof(toy::ActionGroup)); return ty; }
    template <> TOY_EDIT_EXPORT Type& type<toy::GraphicsDebug>() { static Type ty("GraphicsDebug", sizeof(toy::GraphicsDebug)); return ty; }
    template <> TOY_EDIT_EXPORT Type& type<toy::Editor>() { static Type ty("Editor", type<two::EditContext>(), sizeof(toy::Editor)); return ty; }
}


namespace toy
{
#if 0
	/*EditorUser& EditorCore::connect(const string& name, EditorApp& frontApp)
	{
		if(m_users.find(name) == m_users.end())
			m_users[name] = oconstruct<EditorUser>(*this, frontApp);

		return *m_users[name];
	}*/

	template <> Type& type<Shell>() { static Type ty("Shell"); return ty; }

	EditorApp::EditorApp(const string& execPath, const string& resourcePath)
		: m_user(0, "admin")
		, m_shell(oconstruct<Shell>(execPath, resourcePath))
		, m_editor(nullptr)
	{
		System::instance().loadModules({ &toyobj::module(), &toymath::module(), &toyutil::module(), &toycore::module(),
										 &toyui::module(), &toygfx::module(), &toyvisu::module(), &toyedit::module(),
										 &toyblock::module(), &toygen::module() });
	}

	EditorApp::~EditorApp()
	{}

	void EditorApp::init(bool prompt)
	{
		m_shell->initVisu(m_user, prompt);
		this->startEditor();
	}

	void EditorApp::loadGame(const string& path)
	{
		m_shell->loadGame(path, false);
		m_editor->editWorld(*m_shell->m_game.m_world);
	}

	void EditorApp::reloadGame()
	{
		m_editor->closeWorld();
		World& world = m_shell->reloadGame();
		m_editor->editWorld(world);
	}

	void EditorApp::startEditor()
	{
		printf("Starting Editor\n");

		m_editor = oconstruct<Editor>(m_user, *m_shell->m_visuSystem);

		//m_editorUi = &m_shell->m_rootDevice->emplace<DEditor>(*m_editor, *m_shell->m_visuSystem);
		
		/*m_editor->actionGroup("File").m_actions["Load Game"] = [this] {

			DModal& modal = m_editorUi->rootDevice().emplace<DModal>();
			DQuery& query = modal.emplace<DQuery>("Game Module Path", var(string()));
			modal.m_callback = [this, &query] { this->loadGame(val<string>(query.m_value)); };

		};*/

		m_editor->actionGroup("File").m_actions["New World"] = [this] { m_shell->generateWorld(); };

		m_editor->actionGroup("File").m_actions["Save World"] = [this] { m_shell->saveWorld(); };

		m_editor->actionGroup("File").m_actions["Reload Game"] = [this] { this->reloadGame(); };

		m_editor->actionGroup("File").m_actions["Dump Memory Usage"] = [this] { System::instance().dumpMemoryUsage(); };

		m_editor->actionGroup("File").m_actions["Start"] = [this] { m_shell->launchGame(); };
	}
#endif
}

#ifdef TWO_MODULES
module toy.edit
#else
#include <stl/hash_base.hpp>
#endif

namespace toy
{
	CameraController::CameraController(Viewer& viewer, HCamera camera, HMovable movable)
		: m_viewer(viewer)
		, m_camera(camera)
		, m_movable(movable)
		, m_velocity(50.f)
		, m_angular_velocity(2.f)
	{
		default_velocities();

		m_movable->set_acceleration(vec3(0.f), vec3(0.f, 0.f, m_velocity));
	}

	void CameraController::default_velocities()
	{
		map<Key, vec3> velocities;

		velocities[Key::W] = velocities[Key::Up] = to_vec3(Side::Front) * m_velocity;
		velocities[Key::S] = velocities[Key::Down] = to_vec3(Side::Back) * m_velocity;
		velocities[Key::D] = velocities[Key::Right] = to_vec3(Side::Right) * m_velocity;
		velocities[Key::A] = velocities[Key::Left] = to_vec3(Side::Left) * m_velocity;
		velocities[Key::R] = to_vec3(Side::Up) * m_velocity;
		velocities[Key::F] = to_vec3(Side::Down) * m_velocity;

		set_velocities(velocities);
	}

	void CameraController::set_velocities(const map<Key, vec3>& velocities)
	{
		for(auto& key_velocity : velocities)
		{
			vec3 velocity = key_velocity.second;
			//m_key_down_handlers[key_velocity.first] = [this, velocity] { m_movable->modify_linear_velocity(velocity); };
			//m_key_up_handlers[key_velocity.first] = [this, velocity] { m_movable->modify_linear_velocity(-velocity); };
		}
	}

	void CameraController::stop()
	{
		m_movable->set_linear_velocity(vec3(0.f));
		m_movable->set_angular_velocity(vec3(0.f));
	}

	void CameraController::rotate_left()
	{
		m_movable->modify_angular_velocity(Y3 * -m_angular_velocity);
	}

	void CameraController::rotate_right()
	{
		m_movable->modify_angular_velocity(Y3 * m_angular_velocity);
	}

	void CameraController::stop_rotate_left()
	{
		m_movable->modify_angular_velocity(Y3 * m_angular_velocity);
	}

	void CameraController::stop_rotate_right()
	{
		m_movable->modify_angular_velocity(Y3 * -m_angular_velocity);

	}
	void CameraController::zoom_in()
	{
		m_camera->zoom(1.2f);//mCamera->zoom(3.f);
	}

	void CameraController::zoom_out()
	{
		m_camera->zoom(0.8f);//mCamera->zoom(-3.f);
	}

	void CameraController::pitch_lens_up()
	{
		m_camera->pitch_lens(c_pi / 12.f);
	}

	void CameraController::pitch_lens_down()
	{
		m_camera->pitch_lens(-c_pi / 12.f);
	}
}






namespace toy
{
	FPSCameraController::FPSCameraController(Viewer& viewer, HCamera camera, HMovable movable)
		: CameraController(viewer, camera, movable)
	{
		//m_key_down_handlers[Key::Q] = [this] { this->rotate_left(); };
		//m_key_down_handlers[Key::E] = [this] { this->rotate_right(); }; 
	}

	void FPSCameraController::process(Viewer& viewer)
	{
		EventDispatch::process(viewer);
		//this->process(viewer, m_camera->m_spatial, m_camera);
	}

	void FPSCameraController::process(Viewer& viewer, Spatial& spatial, Camera& camera)
	{
		UNUSED(camera);
		//if(active)
		//m_inputWidget->ui().m_cursor.hide();
		//else
		//m_inputWidget->ui().m_cursor.show();

		if(MouseEvent event = viewer.mouse_event(DeviceType::Mouse, EventType::Moved))
		{
			vec2 angle = event.m_delta / viewer.m_frame.m_size;
			spatial.pitch(-angle.x * 4);
			spatial.yaw_fixed(-angle.y * 4);
		}
	}
}

#ifdef TWO_MODULES
module toy.edit
#else
#endif

#define DRAG_BY_GRAB 1

namespace toy
{
	RTSCameraController::RTSCameraController(Viewer& viewer, HCamera camera, HMovable movable)
		: CameraController(viewer, camera, movable)
	{
		//m_key_down_handlers[Key::Q] = [this] { this->rotate_left(); };
		//m_key_down_handlers[Key::E] = [this] { this->rotate_right(); };
		//m_key_down_handlers[Key::O] = [this] { this->zoom_in(); };
		//m_key_down_handlers[Key::L] = [this] { this->zoom_out(); };
		//m_key_down_handlers[Key::I] = [this] { this->pitch_lens_up(); };
		//m_key_down_handlers[Key::K] = [this] { this->pitch_lens_down(); };
		//
		//m_key_up_handlers[Key::Q] = [this] { this->stop_rotate_left(); };
		//m_key_up_handlers[Key::E] = [this] { this->stop_rotate_right(); };
	}

	void RTSCameraController::process(Viewer& viewer)
	{
		EventDispatch::process(viewer);
		//this->process(viewer, m_camera, m_camera);
	}

	void RTSCameraController::process(Viewer& viewer, Spatial& spatial, Camera& camera)
	{
		// activate
		//mWidget->ui().cursor()->bind(m_widget);
		// deactivate
		//mWidget->ui().cursor()->free();

		if(MouseEvent event = viewer.mouse_event(DeviceType::MouseMiddle, EventType::Moved))
		{
			if(event.m_deltaZ > 0)
				camera.zoom(1.3f);
			else
				camera.zoom(0.75f);
		}

		if(MouseEvent event = viewer.mouse_event(DeviceType::MouseLeft, EventType::Stroked, InputMod::None, false))
		{
			viewer.take_focus();
		}

		if(MouseEvent event = viewer.mouse_event(DeviceType::MouseMiddle, EventType::Dragged, InputMod::Ctrl))
		{
#if DRAG_BY_GRAB
			Plane horizontal_plane = { Y3, spatial.m_position.y };
			vec3 from = m_viewer.m_viewport.raycast(horizontal_plane, event.m_relative);
			vec3 to = m_viewer.m_viewport.raycast(horizontal_plane, event.m_relative - event.m_delta);

			//spatial.translate(to - from);
			spatial.set_position(spatial.m_position + (to - from));
#else
			spatial.translate(to_vec3(Side::Right) * 0.02f * m_camera.m_lensDistance * -event.m_delta.x);
			spatial.translate(to_vec3(Side::Front) * 0.02f * m_camera.m_lensDistance * event.m_delta.y);
#endif
		}

		if(MouseEvent event = viewer.mouse_event(DeviceType::MouseMiddle, EventType::Dragged))
		{
			spatial.rotate(to_vec3(Side::Down), 0.02f * event.m_delta.x);
			//spatial.rotateRelative(to_vec3(Side::Left), 0.02f * event.m_delta.y);
			camera.set_lens_angle(m_camera->m_lens_angle + 0.02f * event.m_delta.y);
		}

		if(MouseEvent event = viewer.mouse_event(DeviceType::Mouse, EventType::Heartbeat))
		{
#if 0
			static const float threshold = 4.f;

			if(abs(mouse_event.posX - m_inputWidget->frame().left()) < threshold)
				this->moveLeft();
			else if(abs(mouse_event.posX - m_inputWidget->frame().right()) < threshold)
				this->moveRight();
			else if(abs(mouse_event.posY - m_inputWidget->frame().top()) < threshold)
				this->moveForward();
			else if(abs(mouse_event.posY - m_inputWidget->frame().bottom()) < threshold)
				this->moveBackward();
#endif
		}

	}
}



namespace toy
{
	void Edit::begin()
	{
		//mUser->selector().selection()->select(m_target); // @crash the selection is being iterated
	}

	void Clone::begin()
	{
		//Object& clone = m_object_type.m_meta->creator().cloneObject(m_object);
		//mUser->selector().selection()->select(clone);
	}
}

#ifdef TWO_MODULES
module toy.edit
#else
#include <stl/hash_base.hpp>
#include <tool//EditContext.h>
//#include <core/Selector/Selector.h>
#endif

namespace toy
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
		string clean = replace(to_lower(name), " ", "_");
		return "(" + clean + ")";
	}

	void tool_button(Widget& parent, Tool& tool)
	{
		Widget& button = ui::button(parent, to_icon(tool.m_name).c_str());
		button.set_state(ACTIVE, tool.m_state == ToolState::Active);
		if(button.activated())
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

		for(Ref object : selection.objects)
			object_item(self, object);

		//for(Entity entity : selection.entities)
		//	object_item(self, object);
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

	vector<Type*> entity_types()
	{
		auto has_component = [](Class& cls, Type& component)
		{
			for(Member* member : cls.m_components)
				if(member->m_type->is(component))
					return true;
			return false;
		};

		vector<Type*> types;
		for(Type* type : system().m_types)
			if(g_class[type->m_id])
			{
				if(has_component(cls(*type), two::type<Spatial>()))
					types.push_back(type);
			}
		return types;
	}

	void registry_section(Widget& parent, Indexer& indexer, Selection& selection)
	{
		enum Modes { CREATE = 1 << 0 };

		Section& self = section(parent, string(indexer.m_type->m_name) + " Registry");
		complex_indexer(*self.m_body, indexer, &selection.objects);

		if(ui::modal_button(self, *self.m_toolbar, "Create", CREATE))
		{
			static vector<Type*> types = entity_types();

			Widget& modal = ui::auto_modal(self, CREATE); //, { 600, 400 });
			object_switch_creator(modal, types);
		}
	}

	void library(Widget& parent, span<Type*> types, Selection& selection)
	{
		Tabber& self = ui::tabber(parent);

		for(Type* type : types)
			if(Widget* tab = ui::tab(self, type->m_name))
			{
				registry_section(*tab, indexer(*type), selection);
			}
	}

	void library_section(Widget& parent, span<Type*> types, Selection& selection)
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

	string entity_name(Entity entity)
	{
		return entity_prototype(entity) + ":" + to_string(entity.m_handle);
	}

	string entity_icon(Entity entity)
	{
		return "(" + entity_prototype(entity) + ")";
	}

	void outliner_node(Widget& parent, Entity entity, HSpatial spatial, Selection& selection)
	{
		TreeNode& self = ui::tree_node(parent, { entity_icon(entity).c_str(), entity_name(entity).c_str() }, false, false);

		self.m_header->set_state(SELECTED, has(selection.entities, entity));

		if(self.m_header->activated())
			select(selection.entities, entity);

		//object_item(self, object);

		if(self.m_body)
			for(HSpatial child : spatial->m_contents)
			{
				outliner_node(*self.m_body, child, child, selection);
			}
	}

	void outliner_graph(Widget& parent, HSpatial spatial, Selection& selection)
	{
		ScrollSheet& sheet = ui::scroll_sheet(parent);
		Widget& tree = ui::tree(*sheet.m_body);
		outliner_node(tree, spatial, spatial, selection);
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
				//Widget* dock = ui::dockitem(dockspace, "Screen", { 0U, 1U });
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

		vector<Type*> library_types = { &type<Spatial>(), &type<World>() };
		if(Widget* dock = ui::dockitem(dockspace, "Outliner", { 0U, 0U }))
			editor_graph(*dock, editor, editor.m_selection);
		if(Widget* dock = ui::dockitem(dockspace, "Library", { 0U, 0U }))
			library_section(*dock, library_types, editor.m_selection);
		if(Widget* dock = ui::dockitem(dockspace, "Inspector", { 0U, 2U }))
			object_editor(*dock, editor.m_selection);
		//edit_selector(self, editor.m_selection); // dockid { 0, 2 }
		if(Widget* dock = ui::dockitem(dockspace, "Script", { 0U, 2U }))
			script_editor(*dock, editor.m_script_editor);
		//current_brush_edit(self, editor); // dockid { 0, 0 }
		//ui_edit(self, editor.m_selection); // dockid { 0, 2 }
		if(Widget* dock = ui::dockitem(dockspace, "Graphics", { 0U, 2U }))
			edit_gfx(*dock, editor.m_gfx);

		editor.m_screen = ui::dockitem(dockspace, "Screen", { 0U, 1U }, 4.f);
		
		//if(editor.m_editedScene)
		{
			//scene_viewport(self, *editor.m_editedScene); // dockid { 0, 1 } dockspan 4.f
			//painter_panel(self, *editor.m_editedScene); // dockid { 0, 2 }
		}

		if(editor.m_viewer)
		{
			if(MouseEvent event = editor.m_viewer->mouse_event(DeviceType::MouseLeft, EventType::Stroked, InputMod::None, false))
				editor.m_viewer->take_focus();

			ui::viewport_picker(*editor.m_viewer, *editor.m_viewer, editor.m_selection.objects);

			KeyEvent key_event = editor.m_viewer->key_event(Key::F, EventType::Pressed);
			if(key_event)
				editor.m_frame_view_tool.activate();
		}

		if(editor.m_spatial_tool && editor.m_viewer)
			editor.m_spatial_tool->process(*editor.m_viewer, editor.m_selection.objects);
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
		entry(layout, "frame time", int(editor.m_gfx.m_frame_time * 1000.f));
		entry(layout, "frame per second", int(1.f / max(editor.m_gfx.m_frame_time, eps)));

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
			Ref hovered = Ref(); // editor.m_viewer->m_hovered ? editor.m_viewer->m_hovered->m_node->m_object : Ref();
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

#if 0


#include <core/Reactive/Reactive.h>

namespace toy
{
	void edit_reactive(Widget& parent, Reactive& reactive)
	{
		for(auto& behavior : reactive.m_behaviors)
			object_item(parent, Ref(behavior.get()));
	}
}
#endif






namespace toy
{
	vec3 pick_terrain(Viewer& viewer, World& world, vec2 position)
	{
		Ray ray = viewer.m_camera.ray(position);
		return as<PhysicWorld>(world.m_complex).ground_point(ray);
	}

	Viewer& scene_viewport(Widget& parent, VisuScene& scene, HCamera camera, HMovable movable, Selection& selection)
	{
		Widget& board = ui::widget(parent, styles().sheet, &scene);
		Viewer& viewer = board.suba<Viewer, Scene&>(scene.m_scene);
		if(viewer.once())
		{
			viewer.m_controller = make_unique<RTSCameraController>(viewer, camera, movable);
		}

		update_camera(camera, viewer.m_camera);

		viewer.m_controller->process(viewer);
		ui::viewport_picker(viewer, viewer, selection);
		return viewer;
	}
}

#include <stl/algorithm.h>




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

#include <stl/algorithm.h>



namespace toy
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
			if(tool->enabled(targets.objects))
				add(m_current_tools, tool);
	}

	Toolbelt::Toolbelt()
		: m_toolboxes()
		, m_activeTool(nullptr)
		, m_activeBrush(nullptr)
	{}

	Toolbox& Toolbelt::toolbox(cstring name)
	{
		if(!m_toolboxes[name])
			m_toolboxes[name] = oconstruct<Toolbox>(name);
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
