#include <type/Api.h>
#include <ui/Api.h>
#include <tool/Api.h>
#include <util/Api.h>
#include <core/Api.h>
#include <visu/Api.h>
#include <edit/Api.h>

#ifdef MUD_PLATFORM_EMSCRIPTEN
#include <emscripten.h>
#define DECL EMSCRIPTEN_KEEPALIVE
#else
#define DECL
#endif


extern "C" {
	
	// Edit
	two::Type* DECL toy_Edit__type() {
		return &two::type<toy::Edit>();
	}
	void DECL toy_Edit__destroy(toy::Edit* self) {
		delete self;
	}
	// Clone
	two::Type* DECL toy_Clone__type() {
		return &two::type<toy::Clone>();
	}
	void DECL toy_Clone__destroy(toy::Clone* self) {
		delete self;
	}
	// Cut
	two::Type* DECL toy_Cut__type() {
		return &two::type<toy::Cut>();
	}
	void DECL toy_Cut__destroy(toy::Cut* self) {
		delete self;
	}
	// Paste
	two::Type* DECL toy_Paste__type() {
		return &two::type<toy::Paste>();
	}
	void DECL toy_Paste__destroy(toy::Paste* self) {
		delete self;
	}
	// Toolbox
	two::Type* DECL toy_Toolbox__type() {
		return &two::type<toy::Toolbox>();
	}
	void DECL toy_Toolbox__destroy(toy::Toolbox* self) {
		delete self;
	}
	// DynamicToolbox
	two::Type* DECL toy_DynamicToolbox__type() {
		return &two::type<toy::DynamicToolbox>();
	}
	void DECL toy_DynamicToolbox__destroy(toy::DynamicToolbox* self) {
		delete self;
	}
	// Toolbelt
	two::Type* DECL toy_Toolbelt__type() {
		return &two::type<toy::Toolbelt>();
	}
	void DECL toy_Toolbelt__destroy(toy::Toolbelt* self) {
		delete self;
	}
	// PlayTool
	two::Type* DECL toy_PlayTool__type() {
		return &two::type<toy::PlayTool>();
	}
	void DECL toy_PlayTool__destroy(toy::PlayTool* self) {
		delete self;
	}
	// RunTool
	two::Type* DECL toy_RunTool__type() {
		return &two::type<toy::RunTool>();
	}
	void DECL toy_RunTool__destroy(toy::RunTool* self) {
		delete self;
	}
	// ActionGroup
	two::Type* DECL toy_ActionGroup__type() {
		return &two::type<toy::ActionGroup>();
	}
	toy::ActionGroup* DECL toy_ActionGroup__construct_0() {
		return new toy::ActionGroup();
	}
	void DECL toy_ActionGroup__destroy(toy::ActionGroup* self) {
		delete self;
	}
	// GraphicsDebug
	two::Type* DECL toy_GraphicsDebug__type() {
		return &two::type<toy::GraphicsDebug>();
	}
	toy::GraphicsDebug* DECL toy_GraphicsDebug__construct_0() {
		return new toy::GraphicsDebug();
	}
	void DECL toy_GraphicsDebug__destroy(toy::GraphicsDebug* self) {
		delete self;
	}
	// Editor
	two::Type* DECL toy_Editor__type() {
		return &two::type<toy::Editor>();
	}
	toy::RunTool* DECL toy_Editor__get_run_tool(toy::Editor* self) {
		return &self->m_run_tool;
	}
	toy::PlayTool* DECL toy_Editor__get_play_tool(toy::Editor* self) {
		return &self->m_play_tool;
	}
	two::FrameViewTool* DECL toy_Editor__get_frame_view_tool(toy::Editor* self) {
		return &self->m_frame_view_tool;
	}
	toy::World* DECL toy_Editor__get_edited_world(toy::Editor* self) {
		return self->m_edited_world;
	}
	void DECL toy_Editor__set_edited_world(toy::Editor* self, toy::World* value) {
		self->m_edited_world = value;
	}
	bool DECL toy_Editor__get_run_game(toy::Editor* self) {
		return self->m_run_game;
	}
	void DECL toy_Editor__set_run_game(toy::Editor* self, bool value) {
		self->m_run_game = value;
	}
	bool DECL toy_Editor__get_play_game(toy::Editor* self) {
		return self->m_play_game;
	}
	void DECL toy_Editor__set_play_game(toy::Editor* self, bool value) {
		self->m_play_game = value;
	}
	void DECL toy_Editor__destroy(toy::Editor* self) {
		delete self;
	}
	
}


