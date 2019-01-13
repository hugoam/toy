#include <core/Api.h>
#include <visu/Api.h>
#include <edit/Api.h>
#include <block/Api.h>
#include <pool/Api.h>
#include <refl/Api.h>
#include <ecs/Api.h>
#include <srlz/Api.h>
#include <math/Api.h>
#include <geom/Api.h>
#include <noise/Api.h>
#include <wfc/Api.h>
#include <fract/Api.h>
#include <lang/Api.h>
#include <ctx/Api.h>
#include <ui/Api.h>
#include <uio/Api.h>
#include <bgfx/Api.h>
#include <gfx/Api.h>
#include <gfx-pbr/Api.h>
#include <gfx-obj/Api.h>
#include <gltf/Api.h>
#include <gfx-gltf/Api.h>
#include <gfx-ui/Api.h>
#include <gfx-edit/Api.h>
#include <tool/Api.h>
#include <wfc-gfx/Api.h>
#include <shell/Api.h>
#include <emscripten.h>
#include <cstdint>


extern "C" {
	
	// Game
	toy::User* EMSCRIPTEN_KEEPALIVE toy_Game_get_user(toy::Game* self) {
		return self->m_user;
	}
	void EMSCRIPTEN_KEEPALIVE toy_Game_set_user(toy::Game* self, toy::User* value) {
		self->m_user = value;
	}
	toy::GameMode EMSCRIPTEN_KEEPALIVE toy_Game_get_mode(toy::Game* self) {
		return self->m_mode;
	}
	void EMSCRIPTEN_KEEPALIVE toy_Game_set_mode(toy::Game* self, toy::GameMode value) {
		self->m_mode = value;
	}
	toy::GameShell* EMSCRIPTEN_KEEPALIVE toy_Game_get_shell(toy::Game* self) {
		return self->m_shell;
	}
	void EMSCRIPTEN_KEEPALIVE toy_Game_set_shell(toy::Game* self, toy::GameShell* value) {
		self->m_shell = value;
	}
	toy::GameModule* EMSCRIPTEN_KEEPALIVE toy_Game_get_module(toy::Game* self) {
		return self->m_module;
	}
	void EMSCRIPTEN_KEEPALIVE toy_Game_set_module(toy::Game* self, toy::GameModule* value) {
		self->m_module = value;
	}
	toy::World* EMSCRIPTEN_KEEPALIVE toy_Game_get_world(toy::Game* self) {
		return self->m_world;
	}
	void EMSCRIPTEN_KEEPALIVE toy_Game_set_world(toy::Game* self, toy::World* value) {
		self->m_world = value;
	}
	mud::Widget* EMSCRIPTEN_KEEPALIVE toy_Game_get_screen(toy::Game* self) {
		return self->m_screen;
	}
	void EMSCRIPTEN_KEEPALIVE toy_Game_set_screen(toy::Game* self, mud::Widget* value) {
		self->m_screen = value;
	}
	void EMSCRIPTEN_KEEPALIVE toy_Game___destroy__(toy::Game* self) {
		delete self;
	}
	// GameModule
	void EMSCRIPTEN_KEEPALIVE toy_GameModule_init_2(toy::GameModule* self, toy::GameShell* shell, toy::Game* game) {
		self->init(*shell, *game);
	}
	void EMSCRIPTEN_KEEPALIVE toy_GameModule_paint_3(toy::GameModule* self, toy::GameShell* shell, toy::GameScene* scene, mud::Gnode* graph) {
		self->paint(*shell, *scene, *graph);
	}
	void EMSCRIPTEN_KEEPALIVE toy_GameModule_pump_3(toy::GameModule* self, toy::GameShell* shell, toy::Game* game, mud::Widget* ui) {
		self->pump(*shell, *game, *ui);
	}
	void EMSCRIPTEN_KEEPALIVE toy_GameModule_scene_2(toy::GameModule* self, toy::GameShell* shell, toy::GameScene* scene) {
		self->scene(*shell, *scene);
	}
	void EMSCRIPTEN_KEEPALIVE toy_GameModule_start_2(toy::GameModule* self, toy::GameShell* shell, toy::Game* game) {
		self->start(*shell, *game);
	}
	void EMSCRIPTEN_KEEPALIVE toy_GameModule___destroy__(toy::GameModule* self) {
		delete self;
	}
	// GameShell
	toy::GameScene* EMSCRIPTEN_KEEPALIVE toy_GameShell_add_scene_0(toy::GameShell* self) {
		return &self->add_scene();
	}
	void EMSCRIPTEN_KEEPALIVE toy_GameShell_cleanup_0(toy::GameShell* self) {
		self->cleanup();
	}
	void EMSCRIPTEN_KEEPALIVE toy_GameShell_clear_scenes_0(toy::GameShell* self) {
		self->clear_scenes();
	}
	void EMSCRIPTEN_KEEPALIVE toy_GameShell_init_0(toy::GameShell* self) {
		self->init();
	}
	void EMSCRIPTEN_KEEPALIVE toy_GameShell_launch_0(toy::GameShell* self) {
		self->launch();
	}
	void EMSCRIPTEN_KEEPALIVE toy_GameShell_load_1(toy::GameShell* self, toy::GameModule* module) {
		self->load(*module);
	}
	void EMSCRIPTEN_KEEPALIVE toy_GameShell_load_path_1(toy::GameShell* self, const char* module_path) {
		self->load_path(module_path);
	}
	bool EMSCRIPTEN_KEEPALIVE toy_GameShell_pump_0(toy::GameShell* self) {
		return self->pump();
	}
	void EMSCRIPTEN_KEEPALIVE toy_GameShell_reload_0(toy::GameShell* self) {
		self->reload();
	}
	void EMSCRIPTEN_KEEPALIVE toy_GameShell_remove_scene_1(toy::GameShell* self, toy::GameScene* scene) {
		self->remove_scene(*scene);
	}
	void EMSCRIPTEN_KEEPALIVE toy_GameShell_run_0(toy::GameShell* self) {
		self->run();
	}
	void EMSCRIPTEN_KEEPALIVE toy_GameShell_run_1(toy::GameShell* self, size_t iterations) {
		self->run(iterations);
	}
	void EMSCRIPTEN_KEEPALIVE toy_GameShell_run_editor_1(toy::GameShell* self, toy::GameModule* module) {
		self->run_editor(*module);
	}
	void EMSCRIPTEN_KEEPALIVE toy_GameShell_run_editor_2(toy::GameShell* self, toy::GameModule* module, size_t iterations) {
		self->run_editor(*module, iterations);
	}
	void EMSCRIPTEN_KEEPALIVE toy_GameShell_run_editor_path_1(toy::GameShell* self, const char* module_path) {
		self->run_editor_path(module_path);
	}
	void EMSCRIPTEN_KEEPALIVE toy_GameShell_run_editor_path_2(toy::GameShell* self, const char* module_path, size_t iterations) {
		self->run_editor_path(module_path, iterations);
	}
	void EMSCRIPTEN_KEEPALIVE toy_GameShell_run_game_1(toy::GameShell* self, toy::GameModule* module) {
		self->run_game(*module);
	}
	void EMSCRIPTEN_KEEPALIVE toy_GameShell_run_game_2(toy::GameShell* self, toy::GameModule* module, size_t iterations) {
		self->run_game(*module, iterations);
	}
	void EMSCRIPTEN_KEEPALIVE toy_GameShell_run_game_path_1(toy::GameShell* self, const char* module_path) {
		self->run_game_path(module_path);
	}
	void EMSCRIPTEN_KEEPALIVE toy_GameShell_run_game_path_2(toy::GameShell* self, const char* module_path, size_t iterations) {
		self->run_game_path(module_path, iterations);
	}
	void EMSCRIPTEN_KEEPALIVE toy_GameShell_save_0(toy::GameShell* self) {
		self->save();
	}
	toy::Core* EMSCRIPTEN_KEEPALIVE toy_GameShell_get_core(toy::GameShell* self) {
		return &self->core();
	}
	mud::LuaInterpreter* EMSCRIPTEN_KEEPALIVE toy_GameShell_get_lua(toy::GameShell* self) {
		return &self->lua();
	}
	mud::WrenInterpreter* EMSCRIPTEN_KEEPALIVE toy_GameShell_get_wren(toy::GameShell* self) {
		return &self->wren();
	}
	mud::GfxSystem* EMSCRIPTEN_KEEPALIVE toy_GameShell_get_gfx(toy::GameShell* self) {
		return &self->gfx();
	}
	mud::Context* EMSCRIPTEN_KEEPALIVE toy_GameShell_get_context(toy::GameShell* self) {
		return &self->context();
	}
	mud::Vg* EMSCRIPTEN_KEEPALIVE toy_GameShell_get_vg(toy::GameShell* self) {
		return &self->vg();
	}
	mud::UiWindow* EMSCRIPTEN_KEEPALIVE toy_GameShell_get_ui_window(toy::GameShell* self) {
		return &self->ui_window();
	}
	toy::Editor* EMSCRIPTEN_KEEPALIVE toy_GameShell_get_editor(toy::GameShell* self) {
		return &self->m_editor;
	}
	mud::Ui* EMSCRIPTEN_KEEPALIVE toy_GameShell_get_ui(toy::GameShell* self) {
		return self->m_ui;
	}
	void EMSCRIPTEN_KEEPALIVE toy_GameShell_set_ui(toy::GameShell* self, mud::Ui* value) {
		self->m_ui = value;
	}
	void EMSCRIPTEN_KEEPALIVE toy_GameShell___destroy__(toy::GameShell* self) {
		delete self;
	}
	// GameModuleBind
	toy::GameModuleBind* EMSCRIPTEN_KEEPALIVE toy_GameModuleBind_GameModuleBind_2(mud::Module* module, const mud::VirtualMethod call) {
		return new toy::GameModuleBind(*module, call);
	}
	void EMSCRIPTEN_KEEPALIVE toy_GameModuleBind___destroy__(toy::GameModuleBind* self) {
		delete self;
	}
	// GameScene
	void EMSCRIPTEN_KEEPALIVE toy_GameScene___destroy__(toy::GameScene* self) {
		delete self;
	}
	// GameMode
	toy::GameMode EMSCRIPTEN_KEEPALIVE toy_GameMode_Play() {
		return toy::GameMode::Play;
	}
	toy::GameMode EMSCRIPTEN_KEEPALIVE toy_GameMode_PlayEditor() {
		return toy::GameMode::PlayEditor;
	}
	toy::GameMode EMSCRIPTEN_KEEPALIVE toy_GameMode_Pause() {
		return toy::GameMode::Pause;
	}
	
}


