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
#include <minimal/Api.h>

#ifdef MUD_PLATFORM_EMSCRIPTEN
#include <emscripten.h>
#define DECL EMSCRIPTEN_KEEPALIVE
#else
#define DECL
#endif


extern "C" {
	
	// ComponentHandle<Bullet>
	two::Type* DECL two_ComponentHandle_Bullet__type() {
		return &two::type<two::ComponentHandle<Bullet>>();
	}
	two::ComponentHandle<Bullet>* DECL two_ComponentHandle_Bullet__construct_0() {
		return new two::ComponentHandle<Bullet>();
	}
	void DECL two_ComponentHandle_Bullet__destroy(two::ComponentHandle<Bullet>* self) {
		delete self;
	}
	// ComponentHandle<Human>
	two::Type* DECL two_ComponentHandle_Human__type() {
		return &two::type<two::ComponentHandle<Human>>();
	}
	two::ComponentHandle<Human>* DECL two_ComponentHandle_Human__construct_0() {
		return new two::ComponentHandle<Human>();
	}
	void DECL two_ComponentHandle_Human__destroy(two::ComponentHandle<Human>* self) {
		delete self;
	}
	// ComponentHandle<Crate>
	two::Type* DECL two_ComponentHandle_Crate__type() {
		return &two::type<two::ComponentHandle<Crate>>();
	}
	two::ComponentHandle<Crate>* DECL two_ComponentHandle_Crate__construct_0() {
		return new two::ComponentHandle<Crate>();
	}
	void DECL two_ComponentHandle_Crate__destroy(two::ComponentHandle<Crate>* self) {
		delete self;
	}
	// Bullet
	two::Type* DECL Bullet__type() {
		return &two::type<Bullet>();
	}
	two::vec3* DECL Bullet__get_source(Bullet* self) {
		return &self->m_source;
	}
	void DECL Bullet__set_source(Bullet* self, two::vec3* value) {
		self->m_source = *value;
	}
	two::vec3* DECL Bullet__get_velocity(Bullet* self) {
		return &self->m_velocity;
	}
	void DECL Bullet__set_velocity(Bullet* self, two::vec3* value) {
		self->m_velocity = *value;
	}
	void DECL Bullet__destroy(Bullet* self) {
		delete self;
	}
	// Human
	two::Type* DECL Human__type() {
		return &two::type<Human>();
	}
	Human* DECL Human__construct_0() {
		return new Human();
	}
	Human* DECL Human__construct_2(toy::HSpatial* spatial, toy::HMovable* movable) {
		return new Human(*spatial, *movable);
	}
	void DECL Human__destroy(Human* self) {
		delete self;
	}
	// Crate
	two::Type* DECL Crate__type() {
		return &two::type<Crate>();
	}
	Crate* DECL Crate__construct_0() {
		return new Crate();
	}
	Crate* DECL Crate__construct_3(toy::HSpatial* spatial, toy::HMovable* movable, const two::vec3* extents) {
		return new Crate(*spatial, *movable, *extents);
	}
	two::vec3* DECL Crate__get_extents(Crate* self) {
		return &self->m_extents;
	}
	void DECL Crate__set_extents(Crate* self, two::vec3* value) {
		self->m_extents = *value;
	}
	void DECL Crate__destroy(Crate* self) {
		delete self;
	}
	// Player
	two::Type* DECL Player__type() {
		return &two::type<Player>();
	}
	void DECL Player__destroy(Player* self) {
		delete self;
	}
	
}


