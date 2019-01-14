#include <type/Api.h>
#include <gfx/Api.h>
#include <util/Api.h>
#include <core/Api.h>
#include <visu/Api.h>

#ifdef MUD_PLATFORM_EMSCRIPTEN
#include <emscripten.h>
#define DECL EMSCRIPTEN_KEEPALIVE
#else
#define DECL
#endif


extern "C" {
	
	// PhysicDebugDraw
	mud::Type* DECL toy_PhysicDebugDraw__type() {
		return &mud::type<toy::PhysicDebugDraw>();
	}
	void DECL toy_PhysicDebugDraw__destroy(toy::PhysicDebugDraw* self) {
		delete self;
	}
	// VisuScene
	mud::Type* DECL toy_VisuScene__type() {
		return &mud::type<toy::VisuScene>();
	}
	void DECL toy_VisuScene_next_frame_0(toy::VisuScene* self) {
		self->next_frame();
	}
	mud::GfxSystem* DECL toy_VisuScene__get_gfx_system(toy::VisuScene* self) {
		return &self->m_gfx_system;
	}
	mud::Scene* DECL toy_VisuScene__get_scene(toy::VisuScene* self) {
		return &self->m_scene;
	}
	void DECL toy_VisuScene__destroy(toy::VisuScene* self) {
		delete self;
	}
	
}


