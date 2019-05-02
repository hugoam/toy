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
#include <blocks/Api.h>

#ifdef MUD_PLATFORM_EMSCRIPTEN
#include <emscripten.h>
#define DECL EMSCRIPTEN_KEEPALIVE
#else
#define DECL
#endif


extern "C" {
	
	// ComponentHandle<Camp>
	two::Type* DECL two_ComponentHandle_Camp__type() {
		return &two::type<two::ComponentHandle<Camp>>();
	}
	two::ComponentHandle<Camp>* DECL two_ComponentHandle_Camp__construct_0() {
		return new two::ComponentHandle<Camp>();
	}
	void DECL two_ComponentHandle_Camp__destroy(two::ComponentHandle<Camp>* self) {
		delete self;
	}
	// ComponentHandle<Shield>
	two::Type* DECL two_ComponentHandle_Shield__type() {
		return &two::type<two::ComponentHandle<Shield>>();
	}
	two::ComponentHandle<Shield>* DECL two_ComponentHandle_Shield__construct_0() {
		return new two::ComponentHandle<Shield>();
	}
	void DECL two_ComponentHandle_Shield__destroy(two::ComponentHandle<Shield>* self) {
		delete self;
	}
	// ComponentHandle<Slug>
	two::Type* DECL two_ComponentHandle_Slug__type() {
		return &two::type<two::ComponentHandle<Slug>>();
	}
	two::ComponentHandle<Slug>* DECL two_ComponentHandle_Slug__construct_0() {
		return new two::ComponentHandle<Slug>();
	}
	void DECL two_ComponentHandle_Slug__destroy(two::ComponentHandle<Slug>* self) {
		delete self;
	}
	// ComponentHandle<Tank>
	two::Type* DECL two_ComponentHandle_Tank__type() {
		return &two::type<two::ComponentHandle<Tank>>();
	}
	two::ComponentHandle<Tank>* DECL two_ComponentHandle_Tank__construct_0() {
		return new two::ComponentHandle<Tank>();
	}
	void DECL two_ComponentHandle_Tank__destroy(two::ComponentHandle<Tank>* self) {
		delete self;
	}
	// Faction
	two::Type* DECL Faction__type() {
		return &two::type<Faction>();
	}
	Faction* DECL Faction__construct_2(uint32_t id, const two::Colour* colour) {
		return new Faction(id, *colour);
	}
	uint32_t DECL Faction__get_id(Faction* self) {
		return self->m_id;
	}
	void DECL Faction__set_id(Faction* self, uint32_t value) {
		self->m_id = value;
	}
	two::Colour* DECL Faction__get_colour(Faction* self) {
		return &self->m_colour;
	}
	void DECL Faction__set_colour(Faction* self, two::Colour* value) {
		self->m_colour = *value;
	}
	void DECL Faction__destroy(Faction* self) {
		delete self;
	}
	// Camp
	two::Type* DECL Camp__type() {
		return &two::type<Camp>();
	}
	Camp* DECL Camp__construct_0() {
		return new Camp();
	}
	Camp* DECL Camp__construct_3(toy::HSpatial* spatial, const two::vec3* position, Faction* faction) {
		return new Camp(*spatial, *position, *faction);
	}
	two::vec3* DECL Camp__get_position(Camp* self) {
		return &self->m_position;
	}
	void DECL Camp__set_position(Camp* self, two::vec3* value) {
		self->m_position = *value;
	}
	Faction* DECL Camp__get_faction(Camp* self) {
		return self->m_faction;
	}
	void DECL Camp__set_faction(Camp* self, Faction* value) {
		self->m_faction = value;
	}
	void DECL Camp__destroy(Camp* self) {
		delete self;
	}
	// Shield
	two::Type* DECL Shield__type() {
		return &two::type<Shield>();
	}
	Shield* DECL Shield__construct_0() {
		return new Shield();
	}
	Shield* DECL Shield__construct_4(toy::HSpatial* spatial, toy::HEmitter* emitter, Faction* faction, float radius) {
		return new Shield(*spatial, *emitter, *faction, radius);
	}
	Faction* DECL Shield__get_faction(Shield* self) {
		return self->m_faction;
	}
	void DECL Shield__set_faction(Shield* self, Faction* value) {
		self->m_faction = value;
	}
	float DECL Shield__get_radius(Shield* self) {
		return self->m_radius;
	}
	void DECL Shield__set_radius(Shield* self, float value) {
		self->m_radius = value;
	}
	float DECL Shield__get_charge(Shield* self) {
		return self->m_charge;
	}
	void DECL Shield__set_charge(Shield* self, float value) {
		self->m_charge = value;
	}
	float DECL Shield__get_discharge(Shield* self) {
		return self->m_discharge;
	}
	void DECL Shield__set_discharge(Shield* self, float value) {
		self->m_discharge = value;
	}
	void DECL Shield__destroy(Shield* self) {
		delete self;
	}
	// Slug
	two::Type* DECL Slug__type() {
		return &two::type<Slug>();
	}
	two::vec3* DECL Slug__get_source(Slug* self) {
		return &self->m_source;
	}
	void DECL Slug__set_source(Slug* self, two::vec3* value) {
		self->m_source = *value;
	}
	two::vec3* DECL Slug__get_velocity(Slug* self) {
		return &self->m_velocity;
	}
	void DECL Slug__set_velocity(Slug* self, two::vec3* value) {
		self->m_velocity = *value;
	}
	float DECL Slug__get_power(Slug* self) {
		return self->m_power;
	}
	void DECL Slug__set_power(Slug* self, float value) {
		self->m_power = value;
	}
	void DECL Slug__destroy(Slug* self) {
		delete self;
	}
	// Tank
	two::Type* DECL Tank__type() {
		return &two::type<Tank>();
	}
	Tank* DECL Tank__construct_0() {
		return new Tank();
	}
	Tank* DECL Tank__construct_5(toy::HSpatial* spatial, toy::HMovable* movable, toy::HEmitter* emitter, toy::HReceptor* receptor, Faction* faction) {
		return new Tank(*spatial, *movable, *emitter, *receptor, *faction);
	}
	void DECL Tank__destroy(Tank* self) {
		delete self;
	}
	// BlockWorld
	two::Type* DECL BlockWorld__type() {
		return &two::type<BlockWorld>();
	}
	BlockWorld* DECL BlockWorld__construct_2(const char* name, two::JobSystem* job_system) {
		return new BlockWorld(name, *job_system);
	}
	toy::World* DECL BlockWorld__get_world(BlockWorld* self) {
		return &self->m_world;
	}
	toy::BulletWorld* DECL BlockWorld__get_bullet_world(BlockWorld* self) {
		return &self->m_bullet_world;
	}
	toy::Navmesh* DECL BlockWorld__get_navmesh(BlockWorld* self) {
		return &self->m_navmesh;
	}
	two::uvec3* DECL BlockWorld__get_block_subdiv(BlockWorld* self) {
		return &self->m_block_subdiv;
	}
	void DECL BlockWorld__set_block_subdiv(BlockWorld* self, two::uvec3* value) {
		self->m_block_subdiv = *value;
	}
	two::vec3* DECL BlockWorld__get_tile_scale(BlockWorld* self) {
		return &self->m_tile_scale;
	}
	void DECL BlockWorld__set_tile_scale(BlockWorld* self, two::vec3* value) {
		self->m_tile_scale = *value;
	}
	two::vec3* DECL BlockWorld__get_block_size(BlockWorld* self) {
		return &self->m_block_size;
	}
	void DECL BlockWorld__set_block_size(BlockWorld* self, two::vec3* value) {
		self->m_block_size = *value;
	}
	two::vec3* DECL BlockWorld__get_world_size(BlockWorld* self) {
		return &self->m_world_size;
	}
	void DECL BlockWorld__set_world_size(BlockWorld* self, two::vec3* value) {
		self->m_world_size = *value;
	}
	void DECL BlockWorld__destroy(BlockWorld* self) {
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


