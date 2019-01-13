#include <type/Api.h>
#include <ui/Api.h>
#include <tool/Api.h>
#include <util/Api.h>
#include <core/Api.h>
#include <visu/Api.h>
#include <edit/Api.h>
#include <emscripten.h>
#include <cstdint>


extern "C" {
	
	// ActionGroup
	toy::ActionGroup* EMSCRIPTEN_KEEPALIVE toy_ActionGroup_ActionGroup_0() {
		return new toy::ActionGroup();
	}
	void EMSCRIPTEN_KEEPALIVE toy_ActionGroup___destroy__(toy::ActionGroup* self) {
		delete self;
	}
	// Clone
	void EMSCRIPTEN_KEEPALIVE toy_Clone___destroy__(toy::Clone* self) {
		delete self;
	}
	// Cut
	void EMSCRIPTEN_KEEPALIVE toy_Cut___destroy__(toy::Cut* self) {
		delete self;
	}
	// Edit
	void EMSCRIPTEN_KEEPALIVE toy_Edit___destroy__(toy::Edit* self) {
		delete self;
	}
	// GraphicsDebug
	toy::GraphicsDebug* EMSCRIPTEN_KEEPALIVE toy_GraphicsDebug_GraphicsDebug_0() {
		return new toy::GraphicsDebug();
	}
	void EMSCRIPTEN_KEEPALIVE toy_GraphicsDebug___destroy__(toy::GraphicsDebug* self) {
		delete self;
	}
	// Paste
	void EMSCRIPTEN_KEEPALIVE toy_Paste___destroy__(toy::Paste* self) {
		delete self;
	}
	// Toolbelt
	void EMSCRIPTEN_KEEPALIVE toy_Toolbelt___destroy__(toy::Toolbelt* self) {
		delete self;
	}
	// Toolbox
	void EMSCRIPTEN_KEEPALIVE toy_Toolbox___destroy__(toy::Toolbox* self) {
		delete self;
	}
	// DynamicToolbox
	void EMSCRIPTEN_KEEPALIVE toy_DynamicToolbox___destroy__(toy::DynamicToolbox* self) {
		delete self;
	}
	// Editor
	toy::RunTool* EMSCRIPTEN_KEEPALIVE toy_Editor_get_run_tool(toy::Editor* self) {
		return &self->m_run_tool;
	}
	toy::PlayTool* EMSCRIPTEN_KEEPALIVE toy_Editor_get_play_tool(toy::Editor* self) {
		return &self->m_play_tool;
	}
	mud::FrameViewTool* EMSCRIPTEN_KEEPALIVE toy_Editor_get_frame_view_tool(toy::Editor* self) {
		return &self->m_frame_view_tool;
	}
	toy::World* EMSCRIPTEN_KEEPALIVE toy_Editor_get_edited_world(toy::Editor* self) {
		return self->m_edited_world;
	}
	void EMSCRIPTEN_KEEPALIVE toy_Editor_set_edited_world(toy::Editor* self, toy::World* value) {
		self->m_edited_world = value;
	}
	bool EMSCRIPTEN_KEEPALIVE toy_Editor_get_run_game(toy::Editor* self) {
		return self->m_run_game;
	}
	void EMSCRIPTEN_KEEPALIVE toy_Editor_set_run_game(toy::Editor* self, bool value) {
		self->m_run_game = value;
	}
	bool EMSCRIPTEN_KEEPALIVE toy_Editor_get_play_game(toy::Editor* self) {
		return self->m_play_game;
	}
	void EMSCRIPTEN_KEEPALIVE toy_Editor_set_play_game(toy::Editor* self, bool value) {
		self->m_play_game = value;
	}
	void EMSCRIPTEN_KEEPALIVE toy_Editor___destroy__(toy::Editor* self) {
		delete self;
	}
	// PlayTool
	void EMSCRIPTEN_KEEPALIVE toy_PlayTool___destroy__(toy::PlayTool* self) {
		delete self;
	}
	// RunTool
	void EMSCRIPTEN_KEEPALIVE toy_RunTool___destroy__(toy::RunTool* self) {
		delete self;
	}
	
}


