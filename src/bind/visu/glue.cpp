#include <type/Api.h>
#include <gfx/Api.h>
#include <util/Api.h>
#include <core/Api.h>
#include <visu/Api.h>
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
	// PhysicDebugDraw
	void EMSCRIPTEN_KEEPALIVE PhysicDebugDraw___destroy__(toy::PhysicDebugDraw* self) {
		delete self;
	}
	// VisuScene
	void EMSCRIPTEN_KEEPALIVE VisuScene_next_frame_0(toy::VisuScene* self) {
		self->next_frame();
	}
	mud::GfxSystem* EMSCRIPTEN_KEEPALIVE VisuScene_get_gfx_system(toy::VisuScene* self) {
		return &self->m_gfx_system;
	}
	mud::Scene* EMSCRIPTEN_KEEPALIVE VisuScene_get_scene(toy::VisuScene* self) {
		return &self->m_scene;
	}
	void EMSCRIPTEN_KEEPALIVE VisuScene___destroy__(toy::VisuScene* self) {
		delete self;
	}
	
}


