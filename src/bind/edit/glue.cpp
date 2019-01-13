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
	
	// Not using size_t for array indices as the values used by the javascript code are signed.
	void array_bounds_check(const int array_size, const int array_idx) {
		  if (array_idx < 0 || array_idx >= array_size) {
			    EM_ASM({
				      throw 'Array index ' + $0 + ' out of bounds: [0,' + $1 + ')';
				    }, array_idx, array_size);
			  }
	}
	// ActionGroup
	toy::ActionGroup* EMSCRIPTEN_KEEPALIVE ActionGroup_ActionGroup_0() {
		return new toy::ActionGroup();
	}
	void EMSCRIPTEN_KEEPALIVE ActionGroup___destroy__(toy::ActionGroup* self) {
		delete self;
	}
	// Clone
	void EMSCRIPTEN_KEEPALIVE Clone___destroy__(toy::Clone* self) {
		delete self;
	}
	// Cut
	void EMSCRIPTEN_KEEPALIVE Cut___destroy__(toy::Cut* self) {
		delete self;
	}
	// Edit
	void EMSCRIPTEN_KEEPALIVE Edit___destroy__(toy::Edit* self) {
		delete self;
	}
	// GraphicsDebug
	toy::GraphicsDebug* EMSCRIPTEN_KEEPALIVE GraphicsDebug_GraphicsDebug_0() {
		return new toy::GraphicsDebug();
	}
	void EMSCRIPTEN_KEEPALIVE GraphicsDebug___destroy__(toy::GraphicsDebug* self) {
		delete self;
	}
	// Paste
	void EMSCRIPTEN_KEEPALIVE Paste___destroy__(toy::Paste* self) {
		delete self;
	}
	// Toolbelt
	void EMSCRIPTEN_KEEPALIVE Toolbelt___destroy__(toy::Toolbelt* self) {
		delete self;
	}
	// Toolbox
	void EMSCRIPTEN_KEEPALIVE Toolbox___destroy__(toy::Toolbox* self) {
		delete self;
	}
	// DynamicToolbox
	void EMSCRIPTEN_KEEPALIVE DynamicToolbox___destroy__(toy::DynamicToolbox* self) {
		delete self;
	}
	// Editor
	toy::RunTool* EMSCRIPTEN_KEEPALIVE Editor_get_run_tool(toy::Editor* self) {
		return &self->m_run_tool;
	}
	toy::PlayTool* EMSCRIPTEN_KEEPALIVE Editor_get_play_tool(toy::Editor* self) {
		return &self->m_play_tool;
	}
	mud::FrameViewTool* EMSCRIPTEN_KEEPALIVE Editor_get_frame_view_tool(toy::Editor* self) {
		return &self->m_frame_view_tool;
	}
	toy::World* EMSCRIPTEN_KEEPALIVE Editor_get_edited_world(toy::Editor* self) {
		return self->m_edited_world;
	}
	void EMSCRIPTEN_KEEPALIVE Editor_set_edited_world(toy::Editor* self, toy::World* value) {
		self->m_edited_world = value;
	}
	bool EMSCRIPTEN_KEEPALIVE Editor_get_run_game(toy::Editor* self) {
		return self->m_run_game;
	}
	void EMSCRIPTEN_KEEPALIVE Editor_set_run_game(toy::Editor* self, bool value) {
		self->m_run_game = value;
	}
	bool EMSCRIPTEN_KEEPALIVE Editor_get_play_game(toy::Editor* self) {
		return self->m_play_game;
	}
	void EMSCRIPTEN_KEEPALIVE Editor_set_play_game(toy::Editor* self, bool value) {
		self->m_play_game = value;
	}
	void EMSCRIPTEN_KEEPALIVE Editor___destroy__(toy::Editor* self) {
		delete self;
	}
	// PlayTool
	void EMSCRIPTEN_KEEPALIVE PlayTool___destroy__(toy::PlayTool* self) {
		delete self;
	}
	// RunTool
	void EMSCRIPTEN_KEEPALIVE RunTool___destroy__(toy::RunTool* self) {
		delete self;
	}
	
}


