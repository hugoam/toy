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
#include <lang/Api.h>
#include <ctx/Api.h>
#include <ui/Api.h>
#include <uio/Api.h>
#include <bgfx/Api.h>
#include <gfx/Api.h>
#include <gfx-ui/Api.h>
#include <frame/Api.h>
#include <util/Api.h>
#include <core/Api.h>
#include <visu/Api.h>
#include <edit/Api.h>
#include <block/Api.h>
#include <shell/Api.h>
#include <boids/Api.h>

#ifdef MUD_PLATFORM_EMSCRIPTEN
#include <emscripten.h>
#define DECL EMSCRIPTEN_KEEPALIVE
#else
#define DECL
#endif


extern "C" {
	
	// Boid
	mud::Type* DECL boids_Boid__type() {
		return &mud::type<boids::Boid>();
	}
	boids::Boid* DECL boids_Boid__construct_0() {
		return new boids::Boid();
	}
	void DECL boids_Boid__destroy(boids::Boid* self) {
		delete self;
	}
	// BoidObstacle
	mud::Type* DECL boids_BoidObstacle__type() {
		return &mud::type<boids::BoidObstacle>();
	}
	boids::BoidObstacle* DECL boids_BoidObstacle__construct_0() {
		return new boids::BoidObstacle();
	}
	void DECL boids_BoidObstacle__destroy(boids::BoidObstacle* self) {
		delete self;
	}
	// BoidTarget
	mud::Type* DECL boids_BoidTarget__type() {
		return &mud::type<boids::BoidTarget>();
	}
	boids::BoidTarget* DECL boids_BoidTarget__construct_0() {
		return new boids::BoidTarget();
	}
	void DECL boids_BoidTarget__destroy(boids::BoidTarget* self) {
		delete self;
	}
	// Heading
	mud::Type* DECL boids_Heading__type() {
		return &mud::type<boids::Heading>();
	}
	boids::Heading* DECL boids_Heading__construct_0() {
		return new boids::Heading();
	}
	void DECL boids_Heading__destroy(boids::Heading* self) {
		delete self;
	}
	// MoveForward
	mud::Type* DECL boids_MoveForward__type() {
		return &mud::type<boids::MoveForward>();
	}
	boids::MoveForward* DECL boids_MoveForward__construct_0() {
		return new boids::MoveForward();
	}
	void DECL boids_MoveForward__destroy(boids::MoveForward* self) {
		delete self;
	}
	// MoveSpeed
	mud::Type* DECL boids_MoveSpeed__type() {
		return &mud::type<boids::MoveSpeed>();
	}
	boids::MoveSpeed* DECL boids_MoveSpeed__construct_0() {
		return new boids::MoveSpeed();
	}
	void DECL boids_MoveSpeed__destroy(boids::MoveSpeed* self) {
		delete self;
	}
	// Player
	mud::Type* DECL boids_Player__type() {
		return &mud::type<boids::Player>();
	}
	void DECL boids_Player__destroy(boids::Player* self) {
		delete self;
	}
	// Position
	mud::Type* DECL boids_Position__type() {
		return &mud::type<boids::Position>();
	}
	boids::Position* DECL boids_Position__construct_0() {
		return new boids::Position();
	}
	void DECL boids_Position__destroy(boids::Position* self) {
		delete self;
	}
	// Rotation
	mud::Type* DECL boids_Rotation__type() {
		return &mud::type<boids::Rotation>();
	}
	boids::Rotation* DECL boids_Rotation__construct_0() {
		return new boids::Rotation();
	}
	void DECL boids_Rotation__destroy(boids::Rotation* self) {
		delete self;
	}
	// Transform4
	mud::Type* DECL boids_Transform4__type() {
		return &mud::type<boids::Transform4>();
	}
	boids::Transform4* DECL boids_Transform4__construct_0() {
		return new boids::Transform4();
	}
	void DECL boids_Transform4__destroy(boids::Transform4* self) {
		delete self;
	}
	
}


