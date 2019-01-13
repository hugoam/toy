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
#include <platform/Api.h>
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
	// Aim
	Aim* EMSCRIPTEN_KEEPALIVE Aim_Aim_0() {
		return new Aim();
	}
	mud::quat* EMSCRIPTEN_KEEPALIVE Aim_get_rotation(Aim* self) {
		static mud::quat temp;
		return (temp = self->rotation, &temp);
	}
	void EMSCRIPTEN_KEEPALIVE Aim_set_rotation(Aim* self, mud::quat* rotation) {
		self->rotation = *rotation;
	}
	mud::vec3* EMSCRIPTEN_KEEPALIVE Aim_get_start(Aim* self) {
		static mud::vec3 temp;
		return (temp = self->start, &temp);
	}
	void EMSCRIPTEN_KEEPALIVE Aim_set_start(Aim* self, mud::vec3* start) {
		self->start = *start;
	}
	mud::vec3* EMSCRIPTEN_KEEPALIVE Aim_get_end(Aim* self) {
		static mud::vec3 temp;
		return (temp = self->end, &temp);
	}
	void EMSCRIPTEN_KEEPALIVE Aim_set_end(Aim* self, mud::vec3* end) {
		self->end = *end;
	}
	toy::Spatial* EMSCRIPTEN_KEEPALIVE Aim_get_hit(Aim* self) {
		return self->hit;
	}
	void EMSCRIPTEN_KEEPALIVE Aim_set_hit(Aim* self, toy::Spatial* hit) {
		self->hit = hit;
	}
	void EMSCRIPTEN_KEEPALIVE Aim___destroy__(Aim* self) {
		delete self;
	}
	// Bullet
	mud::vec3* EMSCRIPTEN_KEEPALIVE Bullet_get_source(Bullet* self) {
		static mud::vec3 temp;
		return (temp = self->m_source, &temp);
	}
	void EMSCRIPTEN_KEEPALIVE Bullet_set_source(Bullet* self, mud::vec3* source) {
		self->m_source = *source;
	}
	mud::vec3* EMSCRIPTEN_KEEPALIVE Bullet_get_velocity(Bullet* self) {
		static mud::vec3 temp;
		return (temp = self->m_velocity, &temp);
	}
	void EMSCRIPTEN_KEEPALIVE Bullet_set_velocity(Bullet* self, mud::vec3* velocity) {
		self->m_velocity = *velocity;
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
	void EMSCRIPTEN_KEEPALIVE Crate_set_extents(Crate* self, mud::vec3* extents) {
		self->m_extents = *extents;
	}
	void EMSCRIPTEN_KEEPALIVE Crate___destroy__(Crate* self) {
		delete self;
	}
	// Human
	Human* EMSCRIPTEN_KEEPALIVE Human_Human_0() {
		return new Human();
	}
	Human* EMSCRIPTEN_KEEPALIVE Human_Human_6(toy::HSpatial spatial, toy::HMovable movable, toy::HEmitter emitter, toy::HReceptor receptor, toy::HEntityScript script, Faction faction) {
		return new Human(spatial, movable, emitter, receptor, script, faction);
	}
	Aim* EMSCRIPTEN_KEEPALIVE Human_aim_0(Human* self) {
		static Aim temp;
		return (temp = self->aim(), &temp);
	}
	void EMSCRIPTEN_KEEPALIVE Human_shoot_0(Human* self) {
		self->shoot();
	}
	mud::quat* EMSCRIPTEN_KEEPALIVE Human_sight_0(Human* self) {
		static mud::quat temp;
		return (temp = self->sight(), &temp);
	}
	mud::quat* EMSCRIPTEN_KEEPALIVE Human_sight_1(Human* self, bool aiming) {
		static mud::quat temp;
		return (temp = self->sight(aiming), &temp);
	}
	void EMSCRIPTEN_KEEPALIVE Human_stop_0(Human* self) {
		self->stop();
	}
	Faction EMSCRIPTEN_KEEPALIVE Human_get_faction(Human* self) {
		return self->m_faction;
	}
	void EMSCRIPTEN_KEEPALIVE Human_set_faction(Human* self, Faction faction) {
		self->m_faction = faction;
	}
	float EMSCRIPTEN_KEEPALIVE Human_get_life(Human* self) {
		return self->m_life;
	}
	void EMSCRIPTEN_KEEPALIVE Human_set_life(Human* self, float life) {
		self->m_life = life;
	}
	float EMSCRIPTEN_KEEPALIVE Human_get_energy(Human* self) {
		return self->m_energy;
	}
	void EMSCRIPTEN_KEEPALIVE Human_set_energy(Human* self, float energy) {
		self->m_energy = energy;
	}
	float EMSCRIPTEN_KEEPALIVE Human_get_discharge(Human* self) {
		return self->m_discharge;
	}
	void EMSCRIPTEN_KEEPALIVE Human_set_discharge(Human* self, float discharge) {
		self->m_discharge = discharge;
	}
	bool EMSCRIPTEN_KEEPALIVE Human_get_headlight(Human* self) {
		return self->m_headlight;
	}
	void EMSCRIPTEN_KEEPALIVE Human_set_headlight(Human* self, bool headlight) {
		self->m_headlight = headlight;
	}
	bool EMSCRIPTEN_KEEPALIVE Human_get_shield(Human* self) {
		return self->m_shield;
	}
	void EMSCRIPTEN_KEEPALIVE Human_set_shield(Human* self, bool shield) {
		self->m_shield = shield;
	}
	bool EMSCRIPTEN_KEEPALIVE Human_get_walk(Human* self) {
		return self->m_walk;
	}
	void EMSCRIPTEN_KEEPALIVE Human_set_walk(Human* self, bool walk) {
		self->m_walk = walk;
	}
	HHuman EMSCRIPTEN_KEEPALIVE Human_get_target(Human* self) {
		return self->m_target;
	}
	void EMSCRIPTEN_KEEPALIVE Human_set_target(Human* self, HHuman target) {
		self->m_target = target;
	}
	mud::vec3* EMSCRIPTEN_KEEPALIVE Human_get_dest(Human* self) {
		static mud::vec3 temp;
		return (temp = self->m_dest, &temp);
	}
	void EMSCRIPTEN_KEEPALIVE Human_set_dest(Human* self, mud::vec3* dest) {
		self->m_dest = *dest;
	}
	float EMSCRIPTEN_KEEPALIVE Human_get_cooldown(Human* self) {
		return self->m_cooldown;
	}
	void EMSCRIPTEN_KEEPALIVE Human_set_cooldown(Human* self, float cooldown) {
		self->m_cooldown = cooldown;
	}
	Stance* EMSCRIPTEN_KEEPALIVE Human_get_state(Human* self) {
		static Stance temp;
		return (temp = self->m_state, &temp);
	}
	void EMSCRIPTEN_KEEPALIVE Human_set_state(Human* self, Stance* state) {
		self->m_state = *state;
	}
	void EMSCRIPTEN_KEEPALIVE Human___destroy__(Human* self) {
		delete self;
	}
	// Lamp
	Lamp* EMSCRIPTEN_KEEPALIVE Lamp_Lamp_0() {
		return new Lamp();
	}
	Lamp* EMSCRIPTEN_KEEPALIVE Lamp_Lamp_2(toy::HSpatial spatial, toy::HMovable movable) {
		return new Lamp(spatial, movable);
	}
	void EMSCRIPTEN_KEEPALIVE Lamp___destroy__(Lamp* self) {
		delete self;
	}
	// Player
	void EMSCRIPTEN_KEEPALIVE Player___destroy__(Player* self) {
		delete self;
	}
	// Stance
	Stance* EMSCRIPTEN_KEEPALIVE Stance_Stance_0() {
		return new Stance();
	}
	Stance* EMSCRIPTEN_KEEPALIVE Stance_Stance_2(const char* name, bool loop) {
		return new Stance(name, loop);
	}
	const char* EMSCRIPTEN_KEEPALIVE Stance_get_name(Stance* self) {
		return self->name.c_str();
	}
	void EMSCRIPTEN_KEEPALIVE Stance_set_name(Stance* self, const char* name) {
		self->name = name;
	}
	bool EMSCRIPTEN_KEEPALIVE Stance_get_loop(Stance* self) {
		return self->loop;
	}
	void EMSCRIPTEN_KEEPALIVE Stance_set_loop(Stance* self, bool loop) {
		self->loop = loop;
	}
	void EMSCRIPTEN_KEEPALIVE Stance___destroy__(Stance* self) {
		delete self;
	}
	// TileWorld
	TileWorld* EMSCRIPTEN_KEEPALIVE TileWorld_TileWorld_2(const char* name, mud::JobSystem* job_system) {
		return new TileWorld(name, *job_system);
	}
	toy::World* EMSCRIPTEN_KEEPALIVE TileWorld_get_world(TileWorld* self) {
		return &self->m_world;
	}
	toy::BulletWorld* EMSCRIPTEN_KEEPALIVE TileWorld_get_bullet_world(TileWorld* self) {
		return &self->m_bullet_world;
	}
	toy::Navmesh* EMSCRIPTEN_KEEPALIVE TileWorld_get_navmesh(TileWorld* self) {
		return &self->m_navmesh;
	}
	void EMSCRIPTEN_KEEPALIVE TileWorld___destroy__(TileWorld* self) {
		delete self;
	}
	// Faction
	Faction EMSCRIPTEN_KEEPALIVE Faction_Ally() {
		return Faction::Ally;
	}
	Faction EMSCRIPTEN_KEEPALIVE Faction_Enemy() {
		return Faction::Enemy;
	}
	
}


