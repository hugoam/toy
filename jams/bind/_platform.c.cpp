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
#include <platform/Api.h>

#ifdef MUD_PLATFORM_EMSCRIPTEN
#include <emscripten.h>
#define DECL EMSCRIPTEN_KEEPALIVE
#else
#define DECL
#endif


extern "C" {
	
	// Aim
	mud::Type* DECL Aim__type() {
		return &mud::type<Aim>();
	}
	Aim* DECL Aim__construct_0() {
		return new Aim();
	}
	mud::quat* DECL Aim__get_rotation(Aim* self) {
		return &self->rotation;
	}
	void DECL Aim__set_rotation(Aim* self, mud::quat* value) {
		self->rotation = *value;
	}
	mud::vec3* DECL Aim__get_start(Aim* self) {
		return &self->start;
	}
	void DECL Aim__set_start(Aim* self, mud::vec3* value) {
		self->start = *value;
	}
	mud::vec3* DECL Aim__get_end(Aim* self) {
		return &self->end;
	}
	void DECL Aim__set_end(Aim* self, mud::vec3* value) {
		self->end = *value;
	}
	toy::Spatial* DECL Aim__get_hit(Aim* self) {
		return self->hit;
	}
	void DECL Aim__set_hit(Aim* self, toy::Spatial* value) {
		self->hit = value;
	}
	void DECL Aim__destroy(Aim* self) {
		delete self;
	}
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
	// ComponentHandle<Lamp>
	mud::Type* DECL mud_ComponentHandle_Lamp__type() {
		return &mud::type<mud::ComponentHandle<Lamp>>();
	}
	mud::ComponentHandle<Lamp>* DECL mud_ComponentHandle_Lamp__construct_0() {
		return new mud::ComponentHandle<Lamp>();
	}
	void DECL mud_ComponentHandle_Lamp__destroy(mud::ComponentHandle<Lamp>* self) {
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
	Human* DECL Human__construct_6(toy::HSpatial* spatial, toy::HMovable* movable, toy::HEmitter* emitter, toy::HReceptor* receptor, toy::HEntityScript* script, Faction faction) {
		return new Human(*spatial, *movable, *emitter, *receptor, *script, faction);
	}
	mud::quat* DECL Human_sight_0(Human* self) {
		static mud::quat temp;
		return (temp = self->sight(), &temp);
	}
	mud::quat* DECL Human_sight_1(Human* self, bool aiming) {
		static mud::quat temp;
		return (temp = self->sight(aiming), &temp);
	}
	Aim* DECL Human_aim_0(Human* self) {
		static Aim temp;
		return (temp = self->aim(), &temp);
	}
	void DECL Human_shoot_0(Human* self) {
		self->shoot();
	}
	void DECL Human_stop_0(Human* self) {
		self->stop();
	}
	Faction DECL Human__get_faction(Human* self) {
		return self->m_faction;
	}
	void DECL Human__set_faction(Human* self, Faction value) {
		self->m_faction = value;
	}
	float DECL Human__get_life(Human* self) {
		return self->m_life;
	}
	void DECL Human__set_life(Human* self, float value) {
		self->m_life = value;
	}
	float DECL Human__get_energy(Human* self) {
		return self->m_energy;
	}
	void DECL Human__set_energy(Human* self, float value) {
		self->m_energy = value;
	}
	float DECL Human__get_discharge(Human* self) {
		return self->m_discharge;
	}
	void DECL Human__set_discharge(Human* self, float value) {
		self->m_discharge = value;
	}
	bool DECL Human__get_headlight(Human* self) {
		return self->m_headlight;
	}
	void DECL Human__set_headlight(Human* self, bool value) {
		self->m_headlight = value;
	}
	bool DECL Human__get_shield(Human* self) {
		return self->m_shield;
	}
	void DECL Human__set_shield(Human* self, bool value) {
		self->m_shield = value;
	}
	bool DECL Human__get_walk(Human* self) {
		return self->m_walk;
	}
	void DECL Human__set_walk(Human* self, bool value) {
		self->m_walk = value;
	}
	HHuman* DECL Human__get_target(Human* self) {
		return &self->m_target;
	}
	void DECL Human__set_target(Human* self, HHuman* value) {
		self->m_target = *value;
	}
	mud::vec3* DECL Human__get_dest(Human* self) {
		return &self->m_dest;
	}
	void DECL Human__set_dest(Human* self, mud::vec3* value) {
		self->m_dest = *value;
	}
	float DECL Human__get_cooldown(Human* self) {
		return self->m_cooldown;
	}
	void DECL Human__set_cooldown(Human* self, float value) {
		self->m_cooldown = value;
	}
	Stance* DECL Human__get_state(Human* self) {
		return &self->m_state;
	}
	void DECL Human__set_state(Human* self, Stance* value) {
		self->m_state = *value;
	}
	void DECL Human__destroy(Human* self) {
		delete self;
	}
	// Lamp
	mud::Type* DECL Lamp__type() {
		return &mud::type<Lamp>();
	}
	Lamp* DECL Lamp__construct_0() {
		return new Lamp();
	}
	Lamp* DECL Lamp__construct_2(toy::HSpatial* spatial, toy::HMovable* movable) {
		return new Lamp(*spatial, *movable);
	}
	void DECL Lamp__destroy(Lamp* self) {
		delete self;
	}
	// Player
	mud::Type* DECL Player__type() {
		return &mud::type<Player>();
	}
	void DECL Player__destroy(Player* self) {
		delete self;
	}
	// Stance
	mud::Type* DECL Stance__type() {
		return &mud::type<Stance>();
	}
	Stance* DECL Stance__construct_0() {
		return new Stance();
	}
	Stance* DECL Stance__construct_2(const char* name, bool loop) {
		return new Stance(name, loop);
	}
	const char* DECL Stance__get_name(Stance* self) {
		return self->name.c_str();
	}
	void DECL Stance__set_name(Stance* self, const char* value) {
		self->name = value;
	}
	bool DECL Stance__get_loop(Stance* self) {
		return self->loop;
	}
	void DECL Stance__set_loop(Stance* self, bool value) {
		self->loop = value;
	}
	void DECL Stance__destroy(Stance* self) {
		delete self;
	}
	// TileWorld
	mud::Type* DECL TileWorld__type() {
		return &mud::type<TileWorld>();
	}
	TileWorld* DECL TileWorld__construct_2(const char* name, mud::JobSystem* job_system) {
		return new TileWorld(name, *job_system);
	}
	toy::World* DECL TileWorld__get_world(TileWorld* self) {
		return &self->m_world;
	}
	toy::BulletWorld* DECL TileWorld__get_bullet_world(TileWorld* self) {
		return &self->m_bullet_world;
	}
	toy::Navmesh* DECL TileWorld__get_navmesh(TileWorld* self) {
		return &self->m_navmesh;
	}
	void DECL TileWorld__destroy(TileWorld* self) {
		delete self;
	}
	// Faction
	Faction DECL Faction_Ally() {
		return Faction::Ally;
	}
	Faction DECL Faction_Enemy() {
		return Faction::Enemy;
	}
	
}


