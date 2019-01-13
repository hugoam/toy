#include <infra/Api.h>
#include <jobs/Api.h>
#include <type/Api.h>
#include <tree/Api.h>
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
#include <util/Api.h>
#include <core/Api.h>
#include <visu/Api.h>
#include <edit/Api.h>
#include <block/Api.h>
#include <shell/Api.h>
#include <minimal/Api.h>
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
	// Bullet
	mud::vec3* EMSCRIPTEN_KEEPALIVE Bullet_get_source(Bullet* self) {
		static mud::vec3 temp;
		return (temp = self->m_source, &temp);
	}
	void EMSCRIPTEN_KEEPALIVE Bullet_set_source(Bullet* self, mud::vec3* value) {
		self->m_source = *value;
	}
	mud::vec3* EMSCRIPTEN_KEEPALIVE Bullet_get_velocity(Bullet* self) {
		static mud::vec3 temp;
		return (temp = self->m_velocity, &temp);
	}
	void EMSCRIPTEN_KEEPALIVE Bullet_set_velocity(Bullet* self, mud::vec3* value) {
		self->m_velocity = *value;
	}
	void EMSCRIPTEN_KEEPALIVE Bullet___destroy__(Bullet* self) {
		delete self;
	}
	// Crate
	Crate* EMSCRIPTEN_KEEPALIVE Crate_Crate_0() {
		return new Crate();
	}
	Crate* EMSCRIPTEN_KEEPALIVE Crate_Crate_3(toy::HSpatial spatial, toy::HMovable movable, const mud::vec3* extents) {
		return new Crate(spatial, movable, *extents);
	}
	mud::vec3* EMSCRIPTEN_KEEPALIVE Crate_get_extents(Crate* self) {
		static mud::vec3 temp;
		return (temp = self->m_extents, &temp);
	}
	void EMSCRIPTEN_KEEPALIVE Crate_set_extents(Crate* self, mud::vec3* value) {
		self->m_extents = *value;
	}
	void EMSCRIPTEN_KEEPALIVE Crate___destroy__(Crate* self) {
		delete self;
	}
	// Human
	Human* EMSCRIPTEN_KEEPALIVE Human_Human_0() {
		return new Human();
	}
	Human* EMSCRIPTEN_KEEPALIVE Human_Human_2(toy::HSpatial spatial, toy::HMovable movable) {
		return new Human(spatial, movable);
	}
	void EMSCRIPTEN_KEEPALIVE Human___destroy__(Human* self) {
		delete self;
	}
	// Player
	void EMSCRIPTEN_KEEPALIVE Player___destroy__(Player* self) {
		delete self;
	}
	
}


