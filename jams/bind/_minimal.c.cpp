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
	
	// Bullet
	mud::Type* DECL Bullet__type() {
		return &mud::type<Bullet>();
	}
	mud::vec3* DECL Bullet__get_source(Bullet* self) {
		return &self->m_source;
	}
	void DECL Bullet__set_source(Bullet* self, mud::vec3* value) {
		self->m_source = *value;
	}
	mud::vec3* DECL Bullet__get_velocity(Bullet* self) {
		return &self->m_velocity;
	}
	void DECL Bullet__set_velocity(Bullet* self, mud::vec3* value) {
		self->m_velocity = *value;
	}
	void DECL Bullet__destroy(Bullet* self) {
		delete self;
	}
	// ComponentHandle<Bullet>
	mud::Type* DECL mud_ComponentHandle_Bullet__type() {
		return &mud::type<mud::ComponentHandle<Bullet>>();
	}
	mud::ComponentHandle<Bullet>* DECL mud_ComponentHandle_Bullet__construct_0() {
		return new mud::ComponentHandle<Bullet>();
	}
	void DECL mud_ComponentHandle_Bullet__destroy(mud::ComponentHandle<Bullet>* self) {
		delete self;
	}
	// ComponentHandle<Crate>
	mud::Type* DECL mud_ComponentHandle_Crate__type() {
		return &mud::type<mud::ComponentHandle<Crate>>();
	}
	mud::ComponentHandle<Crate>* DECL mud_ComponentHandle_Crate__construct_0() {
		return new mud::ComponentHandle<Crate>();
	}
	void DECL mud_ComponentHandle_Crate__destroy(mud::ComponentHandle<Crate>* self) {
		delete self;
	}
	// ComponentHandle<Human>
	mud::Type* DECL mud_ComponentHandle_Human__type() {
		return &mud::type<mud::ComponentHandle<Human>>();
	}
	mud::ComponentHandle<Human>* DECL mud_ComponentHandle_Human__construct_0() {
		return new mud::ComponentHandle<Human>();
	}
	void DECL mud_ComponentHandle_Human__destroy(mud::ComponentHandle<Human>* self) {
		delete self;
	}
	// Crate
	mud::Type* DECL Crate__type() {
		return &mud::type<Crate>();
	}
	Crate* DECL Crate__construct_0() {
		return new Crate();
	}
	Crate* DECL Crate__construct_3(toy::HSpatial* spatial, toy::HMovable* movable, const mud::vec3* extents) {
		return new Crate(*spatial, *movable, *extents);
	}
	mud::vec3* DECL Crate__get_extents(Crate* self) {
		return &self->m_extents;
	}
	void DECL Crate__set_extents(Crate* self, mud::vec3* value) {
		self->m_extents = *value;
	}
	void DECL Crate__destroy(Crate* self) {
		delete self;
	}
	// Human
	mud::Type* DECL Human__type() {
		return &mud::type<Human>();
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
	// Player
	mud::Type* DECL Player__type() {
		return &mud::type<Player>();
	}
	void DECL Player__destroy(Player* self) {
		delete self;
	}
	
}


