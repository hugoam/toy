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
	
	// ActionGroup
	mud::Type* DECL toy_ActionGroup__type() {
		return &mud::type<toy::ActionGroup>();
	}
	toy::ActionGroup* DECL toy_ActionGroup__construct_0() {
		return new toy::ActionGroup();
	}
	void DECL toy_ActionGroup__destroy(toy::ActionGroup* self) {
		delete self;
	}
	// Clone
	mud::Type* DECL toy_Clone__type() {
		return &mud::type<toy::Clone>();
	}
	void DECL toy_Clone__destroy(toy::Clone* self) {
		delete self;
	}
	// Cut
	mud::Type* DECL toy_Cut__type() {
		return &mud::type<toy::Cut>();
	}
	void DECL toy_Cut__destroy(toy::Cut* self) {
		delete self;
	}
	// Edit
	mud::Type* DECL toy_Edit__type() {
		return &mud::type<toy::Edit>();
	}
	void DECL toy_Edit__destroy(toy::Edit* self) {
		delete self;
	}
	// GraphicsDebug
	mud::Type* DECL toy_GraphicsDebug__type() {
		return &mud::type<toy::GraphicsDebug>();
	}
	toy::GraphicsDebug* DECL toy_GraphicsDebug__construct_0() {
		return new toy::GraphicsDebug();
	}
	void DECL toy_GraphicsDebug__destroy(toy::GraphicsDebug* self) {
		delete self;
	}
	// Paste
	mud::Type* DECL toy_Paste__type() {
		return &mud::type<toy::Paste>();
	}
	void DECL toy_Paste__destroy(toy::Paste* self) {
		delete self;
	}
	// Toolbelt
	mud::Type* DECL toy_Toolbelt__type() {
		return &mud::type<toy::Toolbelt>();
	}
	void DECL toy_Toolbelt__destroy(toy::Toolbelt* self) {
		delete self;
	}
	// Toolbox
	mud::Type* DECL toy_Toolbox__type() {
		return &mud::type<toy::Toolbox>();
	}
	void DECL toy_Toolbox__destroy(toy::Toolbox* self) {
		delete self;
	}
	// DynamicToolbox
	mud::Type* DECL toy_DynamicToolbox__type() {
		return &mud::type<toy::DynamicToolbox>();
	}
	void DECL toy_DynamicToolbox__destroy(toy::DynamicToolbox* self) {
		delete self;
	}
	// Editor
	mud::Type* DECL toy_Editor__type() {
		return &mud::type<toy::Editor>();
	}
	toy::RunTool* DECL toy_Editor__get_run_tool(toy::Editor* self) {
		return &self->m_run_tool;
	}
	toy::PlayTool* DECL toy_Editor__get_play_tool(toy::Editor* self) {
		return &self->m_play_tool;
	}
	mud::FrameViewTool* DECL toy_Editor__get_frame_view_tool(toy::Editor* self) {
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
	// PlayTool
	mud::Type* DECL toy_PlayTool__type() {
		return &mud::type<toy::PlayTool>();
	}
	void DECL toy_PlayTool__destroy(toy::PlayTool* self) {
		delete self;
	}
	// RunTool
	mud::Type* DECL toy_RunTool__type() {
		return &mud::type<toy::RunTool>();
	}
	void DECL toy_RunTool__destroy(toy::RunTool* self) {
		delete self;
	}
	
}


