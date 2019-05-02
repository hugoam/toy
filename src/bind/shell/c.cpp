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
#include <frame/Api.h>
#include <shell/Api.h>

#ifdef MUD_PLATFORM_EMSCRIPTEN
#include <emscripten.h>
#define DECL EMSCRIPTEN_KEEPALIVE
#else
#define DECL
#endif


extern "C" {
	
	// Game
	two::Type* DECL toy_Game__type() {
		return &two::type<toy::Game>();
	}
	toy::User* DECL toy_Game__get_user(toy::Game* self) {
		return self->m_user;
	}
	void DECL toy_Game__set_user(toy::Game* self, toy::User* value) {
		self->m_user = value;
	}
	toy::GameMode DECL toy_Game__get_mode(toy::Game* self) {
		return self->m_mode;
	}
	void DECL toy_Game__set_mode(toy::Game* self, toy::GameMode value) {
		self->m_mode = value;
	}
	toy::GameShell* DECL toy_Game__get_shell(toy::Game* self) {
		return self->m_shell;
	}
	void DECL toy_Game__set_shell(toy::Game* self, toy::GameShell* value) {
		self->m_shell = value;
	}
	toy::GameModule* DECL toy_Game__get_module(toy::Game* self) {
		return self->m_module;
	}
	void DECL toy_Game__set_module(toy::Game* self, toy::GameModule* value) {
		self->m_module = value;
	}
	two::Ref* DECL toy_Game__get_player(toy::Game* self) {
		static two::Ref temp;
		return (temp = self->m_player, &temp);
	}
	void DECL toy_Game__set_player(toy::Game* self, two::Ref* value) {
		self->m_player = *value;
	}
	toy::World* DECL toy_Game__get_world(toy::Game* self) {
		return self->m_world;
	}
	void DECL toy_Game__set_world(toy::Game* self, toy::World* value) {
		self->m_world = value;
	}
	two::Widget* DECL toy_Game__get_screen(toy::Game* self) {
		return self->m_screen;
	}
	void DECL toy_Game__set_screen(toy::Game* self, two::Widget* value) {
		self->m_screen = value;
	}
	void DECL toy_Game__destroy(toy::Game* self) {
		delete self;
	}
	// GameModule
	two::Type* DECL toy_GameModule__type() {
		return &two::type<toy::GameModule>();
	}
	void DECL toy_GameModule_init_2(toy::GameModule* self, toy::GameShell* shell, toy::Game* game) {
		self->init(*shell, *game);
	}
	void DECL toy_GameModule_start_2(toy::GameModule* self, toy::GameShell* shell, toy::Game* game) {
		self->start(*shell, *game);
	}
	void DECL toy_GameModule_pump_3(toy::GameModule* self, toy::GameShell* shell, toy::Game* game, two::Widget* ui) {
		self->pump(*shell, *game, *ui);
	}
	void DECL toy_GameModule_scene_2(toy::GameModule* self, toy::GameShell* shell, toy::GameScene* scene) {
		self->scene(*shell, *scene);
	}
	void DECL toy_GameModule_paint_3(toy::GameModule* self, toy::GameShell* shell, toy::GameScene* scene, two::Gnode* graph) {
		self->paint(*shell, *scene, *graph);
	}
	void DECL toy_GameModule__destroy(toy::GameModule* self) {
		delete self;
	}
	// GameShell
	two::Type* DECL toy_GameShell__type() {
		return &two::type<toy::GameShell>();
	}
	toy::GameShell* DECL toy_GameShell_GameShell_1(const char* resource_path) {
		return new toy::GameShell(resource_path);
	}
	toy::GameShell* DECL toy_GameShell_GameShell_2(const char* resource_path, const char* exec_path) {
		return new toy::GameShell(resource_path, exec_path);
	}
	void DECL toy_GameShell_init_0(toy::GameShell* self) {
		self->init();
	}
	void DECL toy_GameShell_load_1(toy::GameShell* self, toy::GameModule* module) {
		self->load(*module);
	}
	void DECL toy_GameShell_load_path_1(toy::GameShell* self, const char* module_path) {
		self->load_path(module_path);
	}
	void DECL toy_GameShell_run_0(toy::GameShell* self) {
		self->run();
	}
	void DECL toy_GameShell_run_1(toy::GameShell* self, size_t iterations) {
		self->run(iterations);
	}
	void DECL toy_GameShell_run_game_1(toy::GameShell* self, toy::GameModule* module) {
		self->run_game(*module);
	}
	void DECL toy_GameShell_run_game_2(toy::GameShell* self, toy::GameModule* module, size_t iterations) {
		self->run_game(*module, iterations);
	}
	void DECL toy_GameShell_run_editor_1(toy::GameShell* self, toy::GameModule* module) {
		self->run_editor(*module);
	}
	void DECL toy_GameShell_run_editor_2(toy::GameShell* self, toy::GameModule* module, size_t iterations) {
		self->run_editor(*module, iterations);
	}
	void DECL toy_GameShell_run_game_path_1(toy::GameShell* self, const char* module_path) {
		self->run_game_path(module_path);
	}
	void DECL toy_GameShell_run_game_path_2(toy::GameShell* self, const char* module_path, size_t iterations) {
		self->run_game_path(module_path, iterations);
	}
	void DECL toy_GameShell_run_editor_path_1(toy::GameShell* self, const char* module_path) {
		self->run_editor_path(module_path);
	}
	void DECL toy_GameShell_run_editor_path_2(toy::GameShell* self, const char* module_path, size_t iterations) {
		self->run_editor_path(module_path, iterations);
	}
	void DECL toy_GameShell_launch_0(toy::GameShell* self) {
		self->launch();
	}
	void DECL toy_GameShell_save_0(toy::GameShell* self) {
		self->save();
	}
	void DECL toy_GameShell_reload_0(toy::GameShell* self) {
		self->reload();
	}
	bool DECL toy_GameShell_pump_0(toy::GameShell* self) {
		return self->pump();
	}
	void DECL toy_GameShell_cleanup_0(toy::GameShell* self) {
		self->cleanup();
	}
	toy::GameScene* DECL toy_GameShell_add_scene_0(toy::GameShell* self) {
		return &self->add_scene();
	}
	void DECL toy_GameShell_remove_scene_1(toy::GameShell* self, toy::GameScene* scene) {
		self->remove_scene(*scene);
	}
	void DECL toy_GameShell_clear_scenes_0(toy::GameShell* self) {
		self->clear_scenes();
	}
	toy::Core* DECL toy_GameShell__get_core(toy::GameShell* self) {
		return &self->core();
	}
	two::LuaInterpreter* DECL toy_GameShell__get_lua(toy::GameShell* self) {
		return &self->lua();
	}
	two::WrenInterpreter* DECL toy_GameShell__get_wren(toy::GameShell* self) {
		return &self->wren();
	}
	two::GfxSystem* DECL toy_GameShell__get_gfx(toy::GameShell* self) {
		return &self->gfx();
	}
	two::Context* DECL toy_GameShell__get_context(toy::GameShell* self) {
		return &self->context();
	}
	two::Vg* DECL toy_GameShell__get_vg(toy::GameShell* self) {
		return &self->vg();
	}
	two::UiWindow* DECL toy_GameShell__get_ui_window(toy::GameShell* self) {
		return &self->ui_window();
	}
	toy::Editor* DECL toy_GameShell__get_editor(toy::GameShell* self) {
		return &self->m_editor;
	}
	two::Ui* DECL toy_GameShell__get_ui(toy::GameShell* self) {
		return self->m_ui;
	}
	void DECL toy_GameShell__set_ui(toy::GameShell* self, two::Ui* value) {
		self->m_ui = value;
	}
	void DECL toy_GameShell__destroy(toy::GameShell* self) {
		delete self;
	}
	// GameModuleBind
	two::Type* DECL toy_GameModuleBind__type() {
		return &two::type<toy::GameModuleBind>();
	}
	toy::GameModuleBind* DECL toy_GameModuleBind_GameModuleBind_2(two::Module* module, const two::VirtualMethod call) {
		return new toy::GameModuleBind(*module, call);
	}
	void DECL toy_GameModuleBind__destroy(toy::GameModuleBind* self) {
		delete self;
	}
	// GameScene
	two::Type* DECL toy_GameScene__type() {
		return &two::type<toy::GameScene>();
	}
	void DECL toy_GameScene__destroy(toy::GameScene* self) {
		delete self;
	}
	void DECL toy_paint_physics_2(two::Gnode* parent, toy::World* world) {
		toy::paint_physics(*parent, *world);
	}
	void DECL toy_physic_painter_1(toy::GameScene* scene) {
		toy::physic_painter(*scene);
	}
	// GameMode
	toy::GameMode DECL toy_GameMode_Play() {
		return toy::GameMode::Play;
	}
	toy::GameMode DECL toy_GameMode_PlayEditor() {
		return toy::GameMode::PlayEditor;
	}
	toy::GameMode DECL toy_GameMode_Pause() {
		return toy::GameMode::Pause;
	}
	
}


