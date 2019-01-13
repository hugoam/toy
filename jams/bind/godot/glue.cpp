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
#include <godot/Api.h>
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
	mud::vec3* EMSCRIPTEN_KEEPALIVE Aim_get_start(Aim* self) {
		static mud::vec3 temp;
		return (temp = self->start, &temp);
	}
	mud::vec3* EMSCRIPTEN_KEEPALIVE Aim_get_end(Aim* self) {
		static mud::vec3 temp;
		return (temp = self->end, &temp);
	}
	toy::Spatial* EMSCRIPTEN_KEEPALIVE Aim_get_hit(Aim* self) {
		return self->hit;
	}
	void EMSCRIPTEN_KEEPALIVE Aim___destroy__(Aim* self) {
		delete self;
	}
	// Bullet
	mud::vec3* EMSCRIPTEN_KEEPALIVE Bullet_get_source(Bullet* self) {
		static mud::vec3 temp;
		return (temp = self->m_source, &temp);
	}
	mud::vec3* EMSCRIPTEN_KEEPALIVE Bullet_get_velocity(Bullet* self) {
		static mud::vec3 temp;
		return (temp = self->m_velocity, &temp);
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
	mud::quat* EMSCRIPTEN_KEEPALIVE Human_sight_0(Human* self) {
		static mud::quat temp;
		return (temp = self->sight(aiming), &temp);
	}
	mud::quat* EMSCRIPTEN_KEEPALIVE Human_sight_1(Human* self, bool aiming) {
		static mud::quat temp;
		return (temp = self->sight(aiming), &temp);
	}
	Aim* EMSCRIPTEN_KEEPALIVE Human_aim_0(Human* self) {
		static Aim temp;
		return (temp = self->aim(), &temp);
	}
	void EMSCRIPTEN_KEEPALIVE Human_shoot_0(Human* self) {
		self->shoot();
	}
	void EMSCRIPTEN_KEEPALIVE Human_stop_0(Human* self) {
		self->stop();
	}
	Faction EMSCRIPTEN_KEEPALIVE Human_get_faction(Human* self) {
		return self->m_faction;
	}
	float EMSCRIPTEN_KEEPALIVE Human_get_life(Human* self) {
		return self->m_life;
	}
	float EMSCRIPTEN_KEEPALIVE Human_get_energy(Human* self) {
		return self->m_energy;
	}
	float EMSCRIPTEN_KEEPALIVE Human_get_discharge(Human* self) {
		return self->m_discharge;
	}
	bool EMSCRIPTEN_KEEPALIVE Human_get_headlight(Human* self) {
		return self->m_headlight;
	}
	bool EMSCRIPTEN_KEEPALIVE Human_get_shield(Human* self) {
		return self->m_shield;
	}
	bool EMSCRIPTEN_KEEPALIVE Human_get_walk(Human* self) {
		return self->m_walk;
	}
	HHuman EMSCRIPTEN_KEEPALIVE Human_get_target(Human* self) {
		return self->m_target;
	}
	mud::vec3* EMSCRIPTEN_KEEPALIVE Human_get_dest(Human* self) {
		static mud::vec3 temp;
		return (temp = self->m_dest, &temp);
	}
	float EMSCRIPTEN_KEEPALIVE Human_get_cooldown(Human* self) {
		return self->m_cooldown;
	}
	Stance* EMSCRIPTEN_KEEPALIVE Human_get_state(Human* self) {
		static Stance temp;
		return (temp = self->m_state, &temp);
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
	Stance* EMSCRIPTEN_KEEPALIVE Stance_Stance_0() {
		return new Stance();
	}
	Stance* EMSCRIPTEN_KEEPALIVE Stance_Stance_2(const char* name, bool loop) {
		return new Stance(*name, loop);
	}
	const char* EMSCRIPTEN_KEEPALIVE Stance_get_name(Stance* self) {
		return self->name.c_str();
	}
	bool EMSCRIPTEN_KEEPALIVE Stance_get_loop(Stance* self) {
		return self->loop;
	}
	void EMSCRIPTEN_KEEPALIVE Stance___destroy__(Stance* self) {
		delete self;
	}
	// WorldBlock
	WorldBlock* EMSCRIPTEN_KEEPALIVE WorldBlock_WorldBlock_0() {
		return new WorldBlock();
	}
	WorldBlock* EMSCRIPTEN_KEEPALIVE WorldBlock_WorldBlock_4(toy::HSpatial spatial, toy::HWorldPage world_page, toy::HNavblock navblock, const mud::vec3* extents) {
		return new WorldBlock(spatial, world_page, navblock, *extents);
	}
	mud::vec3* EMSCRIPTEN_KEEPALIVE WorldBlock_get_extents(WorldBlock* self) {
		static mud::vec3 temp;
		return (temp = self->m_extents, &temp);
	}
	void EMSCRIPTEN_KEEPALIVE WorldBlock___destroy__(WorldBlock* self) {
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


