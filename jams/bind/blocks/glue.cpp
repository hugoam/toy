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
#include <blocks/Api.h>
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
	// Camp
	Camp* EMSCRIPTEN_KEEPALIVE Camp_Camp_0() {
		return new Camp();
	}
	Camp* EMSCRIPTEN_KEEPALIVE Camp_Camp_3(toy::HSpatial spatial, const vec3 position, Faction faction) {
		return new Camp(spatial, *position, *faction);
	}
	vec3 EMSCRIPTEN_KEEPALIVE Camp_get_position(Camp* self) {
		return self->m_position;
	}
	Faction EMSCRIPTEN_KEEPALIVE Camp_get_faction(Camp* self) {
		return self->m_faction;
	}
	void EMSCRIPTEN_KEEPALIVE Camp___destroy__(Camp* self) {
		delete self;
	}
	// Faction
	Faction* EMSCRIPTEN_KEEPALIVE Faction_Faction_2(uint32_t id, const Colour colour) {
		return new Faction(id, *colour);
	}
	uint32_t EMSCRIPTEN_KEEPALIVE Faction_get_id(Faction* self) {
		return self->m_id;
	}
	Colour EMSCRIPTEN_KEEPALIVE Faction_get_colour(Faction* self) {
		return self->m_colour;
	}
	void EMSCRIPTEN_KEEPALIVE Faction___destroy__(Faction* self) {
		delete self;
	}
	// Player
	void EMSCRIPTEN_KEEPALIVE Player___destroy__(Player* self) {
		delete self;
	}
	// Shield
	Shield* EMSCRIPTEN_KEEPALIVE Shield_Shield_0() {
		return new Shield();
	}
	Shield* EMSCRIPTEN_KEEPALIVE Shield_Shield_4(toy::HSpatial spatial, toy::HEmitter emitter, Faction faction, float radius) {
		return new Shield(spatial, emitter, *faction, radius);
	}
	Faction EMSCRIPTEN_KEEPALIVE Shield_get_faction(Shield* self) {
		return self->m_faction;
	}
	float EMSCRIPTEN_KEEPALIVE Shield_get_radius(Shield* self) {
		return self->m_radius;
	}
	float EMSCRIPTEN_KEEPALIVE Shield_get_charge(Shield* self) {
		return self->m_charge;
	}
	float EMSCRIPTEN_KEEPALIVE Shield_get_discharge(Shield* self) {
		return self->m_discharge;
	}
	void EMSCRIPTEN_KEEPALIVE Shield___destroy__(Shield* self) {
		delete self;
	}
	// Slug
	vec3 EMSCRIPTEN_KEEPALIVE Slug_get_source(Slug* self) {
		return self->m_source;
	}
	vec3 EMSCRIPTEN_KEEPALIVE Slug_get_velocity(Slug* self) {
		return self->m_velocity;
	}
	float EMSCRIPTEN_KEEPALIVE Slug_get_power(Slug* self) {
		return self->m_power;
	}
	void EMSCRIPTEN_KEEPALIVE Slug___destroy__(Slug* self) {
		delete self;
	}
	// Tank
	Tank* EMSCRIPTEN_KEEPALIVE Tank_Tank_0() {
		return new Tank();
	}
	Tank* EMSCRIPTEN_KEEPALIVE Tank_Tank_5(toy::HSpatial spatial, toy::HMovable movable, toy::HEmitter emitter, toy::HReceptor receptor, Faction faction) {
		return new Tank(spatial, movable, emitter, receptor, *faction);
	}
	void EMSCRIPTEN_KEEPALIVE Tank___destroy__(Tank* self) {
		delete self;
	}
	// BlockWorld
	BlockWorld* EMSCRIPTEN_KEEPALIVE BlockWorld_BlockWorld_2(const std::string name, JobSystem job_system) {
		return new BlockWorld(*name, *job_system);
	}
	World EMSCRIPTEN_KEEPALIVE BlockWorld_get_world(BlockWorld* self) {
		return self->m_world;
	}
	BulletWorld EMSCRIPTEN_KEEPALIVE BlockWorld_get_bullet_world(BlockWorld* self) {
		return self->m_bullet_world;
	}
	Navmesh EMSCRIPTEN_KEEPALIVE BlockWorld_get_navmesh(BlockWorld* self) {
		return self->m_navmesh;
	}
	uvec3 EMSCRIPTEN_KEEPALIVE BlockWorld_get_block_subdiv(BlockWorld* self) {
		return self->m_block_subdiv;
	}
	vec3 EMSCRIPTEN_KEEPALIVE BlockWorld_get_tile_scale(BlockWorld* self) {
		return self->m_tile_scale;
	}
	vec3 EMSCRIPTEN_KEEPALIVE BlockWorld_get_block_size(BlockWorld* self) {
		return self->m_block_size;
	}
	vec3 EMSCRIPTEN_KEEPALIVE BlockWorld_get_world_size(BlockWorld* self) {
		return self->m_world_size;
	}
	void EMSCRIPTEN_KEEPALIVE BlockWorld___destroy__(BlockWorld* self) {
		delete self;
	}
	
}


