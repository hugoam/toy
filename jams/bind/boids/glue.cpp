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
#include <boids/Api.h>
#include <emscripten.h>


extern "C" {
	
	// Not using size_t for array indices as the values used by the javascript code are signed.
	void array_bounds_check(const int array_size, const int array_idx) {
		  if (array_idx < 0 || array_idx >= array_size) {
			    EM_ASM({
				      throw 'Array index ' + $0 + ' out of bounds: [0,' + $1 + ')';
				    }, array_idx, array_size);
			  }
	}
	// Boid
	boids::Boid* EMSCRIPTEN_KEEPALIVE Boid_Boid_0() {
		return new boids::Boid();
	}
	void EMSCRIPTEN_KEEPALIVE Boid___destroy__(boids::Boid* self) {
		delete self;
	}
	// BoidObstacle
	boids::BoidObstacle* EMSCRIPTEN_KEEPALIVE BoidObstacle_BoidObstacle_0() {
		return new boids::BoidObstacle();
	}
	void EMSCRIPTEN_KEEPALIVE BoidObstacle___destroy__(boids::BoidObstacle* self) {
		delete self;
	}
	// BoidTarget
	boids::BoidTarget* EMSCRIPTEN_KEEPALIVE BoidTarget_BoidTarget_0() {
		return new boids::BoidTarget();
	}
	void EMSCRIPTEN_KEEPALIVE BoidTarget___destroy__(boids::BoidTarget* self) {
		delete self;
	}
	// Heading
	boids::Heading* EMSCRIPTEN_KEEPALIVE Heading_Heading_0() {
		return new boids::Heading();
	}
	void EMSCRIPTEN_KEEPALIVE Heading___destroy__(boids::Heading* self) {
		delete self;
	}
	// MoveForward
	boids::MoveForward* EMSCRIPTEN_KEEPALIVE MoveForward_MoveForward_0() {
		return new boids::MoveForward();
	}
	void EMSCRIPTEN_KEEPALIVE MoveForward___destroy__(boids::MoveForward* self) {
		delete self;
	}
	// MoveSpeed
	boids::MoveSpeed* EMSCRIPTEN_KEEPALIVE MoveSpeed_MoveSpeed_0() {
		return new boids::MoveSpeed();
	}
	void EMSCRIPTEN_KEEPALIVE MoveSpeed___destroy__(boids::MoveSpeed* self) {
		delete self;
	}
	// Player
	void EMSCRIPTEN_KEEPALIVE Player___destroy__(boids::Player* self) {
		delete self;
	}
	// Position
	boids::Position* EMSCRIPTEN_KEEPALIVE Position_Position_0() {
		return new boids::Position();
	}
	void EMSCRIPTEN_KEEPALIVE Position___destroy__(boids::Position* self) {
		delete self;
	}
	// Rotation
	boids::Rotation* EMSCRIPTEN_KEEPALIVE Rotation_Rotation_0() {
		return new boids::Rotation();
	}
	void EMSCRIPTEN_KEEPALIVE Rotation___destroy__(boids::Rotation* self) {
		delete self;
	}
	// Transform4
	boids::Transform4* EMSCRIPTEN_KEEPALIVE Transform4_Transform4_0() {
		return new boids::Transform4();
	}
	void EMSCRIPTEN_KEEPALIVE Transform4___destroy__(boids::Transform4* self) {
		delete self;
	}
	
}


