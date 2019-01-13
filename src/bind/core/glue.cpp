#include <type/Api.h>
#include <jobs/Api.h>
#include <ecs/Api.h>
#include <math/Api.h>
#include <geom/Api.h>
#include <lang/Api.h>
#include <util/Api.h>
#include <core/Api.h>
#include <emscripten.h>
#include <cstdint>


extern "C" {
	
	// BulletMedium
	void EMSCRIPTEN_KEEPALIVE BulletMedium___destroy__(toy::BulletMedium* self) {
		delete self;
	}
	// BulletShape
	void EMSCRIPTEN_KEEPALIVE BulletShape___destroy__(toy::BulletShape* self) {
		delete self;
	}
	// Camera
	toy::Camera* EMSCRIPTEN_KEEPALIVE Camera_Camera_0() {
		return new toy::Camera();
	}
	toy::Camera* EMSCRIPTEN_KEEPALIVE Camera_Camera_1(toy::HSpatial spatial) {
		return new toy::Camera(spatial);
	}
	toy::Camera* EMSCRIPTEN_KEEPALIVE Camera_Camera_2(toy::HSpatial spatial, float lens_distance) {
		return new toy::Camera(spatial, lens_distance);
	}
	toy::Camera* EMSCRIPTEN_KEEPALIVE Camera_Camera_3(toy::HSpatial spatial, float lens_distance, float near) {
		return new toy::Camera(spatial, lens_distance, near);
	}
	toy::Camera* EMSCRIPTEN_KEEPALIVE Camera_Camera_4(toy::HSpatial spatial, float lens_distance, float near, float far) {
		return new toy::Camera(spatial, lens_distance, near, far);
	}
	float EMSCRIPTEN_KEEPALIVE Camera_get_lens_distance(toy::Camera* self) {
		return self->m_lens_distance;
	}
	void EMSCRIPTEN_KEEPALIVE Camera_set_lens_distance(toy::Camera* self, float value) {
		self->m_lens_distance = value;
	}
	float EMSCRIPTEN_KEEPALIVE Camera_get_lens_angle(toy::Camera* self) {
		return self->m_lens_angle;
	}
	void EMSCRIPTEN_KEEPALIVE Camera_set_lens_angle(toy::Camera* self, float value) {
		self->m_lens_angle = value;
	}
	float EMSCRIPTEN_KEEPALIVE Camera_get_near(toy::Camera* self) {
		return self->m_near;
	}
	void EMSCRIPTEN_KEEPALIVE Camera_set_near(toy::Camera* self, float value) {
		self->m_near = value;
	}
	float EMSCRIPTEN_KEEPALIVE Camera_get_far(toy::Camera* self) {
		return self->m_far;
	}
	void EMSCRIPTEN_KEEPALIVE Camera_set_far(toy::Camera* self, float value) {
		self->m_far = value;
	}
	float EMSCRIPTEN_KEEPALIVE Camera_get_aspect(toy::Camera* self) {
		return self->m_aspect;
	}
	void EMSCRIPTEN_KEEPALIVE Camera_set_aspect(toy::Camera* self, float value) {
		self->m_aspect = value;
	}
	void EMSCRIPTEN_KEEPALIVE Camera___destroy__(toy::Camera* self) {
		delete self;
	}
	// Collider
	toy::Collider* EMSCRIPTEN_KEEPALIVE Collider_Collider_0() {
		return new toy::Collider();
	}
	toy::Collider* EMSCRIPTEN_KEEPALIVE Collider_Collider_5(toy::HSpatial spatial, toy::HMovable movable, const toy::CollisionShape* collision_shape, toy::Medium* medium, toy::CollisionGroup group) {
		return new toy::Collider(spatial, movable, *collision_shape, *medium, group);
	}
	toy::HSpatial EMSCRIPTEN_KEEPALIVE Collider_get_spatial(toy::Collider* self) {
		return self->m_spatial;
	}
	void EMSCRIPTEN_KEEPALIVE Collider_set_spatial(toy::Collider* self, toy::HSpatial value) {
		self->m_spatial = value;
	}
	toy::HMovable EMSCRIPTEN_KEEPALIVE Collider_get_movable(toy::Collider* self) {
		return self->m_movable;
	}
	void EMSCRIPTEN_KEEPALIVE Collider_set_movable(toy::Collider* self, toy::HMovable value) {
		self->m_movable = value;
	}
	toy::CollisionShape* EMSCRIPTEN_KEEPALIVE Collider_get_collision_shape(toy::Collider* self) {
		return &self->m_collision_shape;
	}
	toy::Medium* EMSCRIPTEN_KEEPALIVE Collider_get_medium(toy::Collider* self) {
		return self->m_medium;
	}
	void EMSCRIPTEN_KEEPALIVE Collider_set_medium(toy::Collider* self, toy::Medium* value) {
		self->m_medium = value;
	}
	toy::CollisionGroup EMSCRIPTEN_KEEPALIVE Collider_get_group(toy::Collider* self) {
		return self->m_group;
	}
	void EMSCRIPTEN_KEEPALIVE Collider_set_group(toy::Collider* self, toy::CollisionGroup value) {
		self->m_group = value;
	}
	toy::ColliderObject* EMSCRIPTEN_KEEPALIVE Collider_get_object(toy::Collider* self) {
		return self->m_object;
	}
	void EMSCRIPTEN_KEEPALIVE Collider_set_object(toy::Collider* self, toy::ColliderObject* value) {
		self->m_object = value;
	}
	toy::ColliderImpl* EMSCRIPTEN_KEEPALIVE Collider_get_impl(toy::Collider* self) {
		return &self->impl();
	}
	void EMSCRIPTEN_KEEPALIVE Collider___destroy__(toy::Collider* self) {
		delete self;
	}
	// ColliderImpl
	void EMSCRIPTEN_KEEPALIVE ColliderImpl___destroy__(toy::ColliderImpl* self) {
		delete self;
	}
	// ColliderObject
	void EMSCRIPTEN_KEEPALIVE ColliderObject___destroy__(toy::ColliderObject* self) {
		delete self;
	}
	// Collision
	toy::Collision* EMSCRIPTEN_KEEPALIVE Collision_Collision_0() {
		return new toy::Collision();
	}
	toy::HCollider EMSCRIPTEN_KEEPALIVE Collision_get_first(toy::Collision* self) {
		return self->m_first;
	}
	void EMSCRIPTEN_KEEPALIVE Collision_set_first(toy::Collision* self, toy::HCollider value) {
		self->m_first = value;
	}
	toy::HCollider EMSCRIPTEN_KEEPALIVE Collision_get_second(toy::Collision* self) {
		return self->m_second;
	}
	void EMSCRIPTEN_KEEPALIVE Collision_set_second(toy::Collision* self, toy::HCollider value) {
		self->m_second = value;
	}
	mud::vec3* EMSCRIPTEN_KEEPALIVE Collision_get_hit_point(toy::Collision* self) {
		static mud::vec3 temp;
		return (temp = self->m_hit_point, &temp);
	}
	void EMSCRIPTEN_KEEPALIVE Collision_set_hit_point(toy::Collision* self, mud::vec3* value) {
		self->m_hit_point = *value;
	}
	void EMSCRIPTEN_KEEPALIVE Collision___destroy__(toy::Collision* self) {
		delete self;
	}
	// CollisionShape
	toy::CollisionShape* EMSCRIPTEN_KEEPALIVE CollisionShape_CollisionShape_0() {
		return new toy::CollisionShape();
	}
	toy::CollisionShape* EMSCRIPTEN_KEEPALIVE CollisionShape_CollisionShape_1(const mud::Shape* shape) {
		return new toy::CollisionShape(*shape);
	}
	toy::CollisionShape* EMSCRIPTEN_KEEPALIVE CollisionShape_CollisionShape_2(const mud::Shape* shape, const mud::vec3* center) {
		return new toy::CollisionShape(*shape, *center);
	}
	toy::CollisionShape* EMSCRIPTEN_KEEPALIVE CollisionShape_CollisionShape_3(const mud::Shape* shape, const mud::vec3* center, float margin) {
		return new toy::CollisionShape(*shape, *center, margin);
	}
	void EMSCRIPTEN_KEEPALIVE CollisionShape___destroy__(toy::CollisionShape* self) {
		delete self;
	}
	// ComponentPool
	void EMSCRIPTEN_KEEPALIVE ComponentPool___destroy__(toy::ComponentPool* self) {
		delete self;
	}
	// Core
	void EMSCRIPTEN_KEEPALIVE Core___destroy__(toy::Core* self) {
		delete self;
	}
	// DetourPath
	void EMSCRIPTEN_KEEPALIVE DetourPath___destroy__(toy::DetourPath* self) {
		delete self;
	}
	// Emitter
	toy::Emitter* EMSCRIPTEN_KEEPALIVE Emitter_Emitter_0() {
		return new toy::Emitter();
	}
	toy::Emitter* EMSCRIPTEN_KEEPALIVE Emitter_Emitter_1(toy::HSpatial spatial) {
		return new toy::Emitter(spatial);
	}
	void EMSCRIPTEN_KEEPALIVE Emitter___destroy__(toy::Emitter* self) {
		delete self;
	}
	// EntityScript
	toy::EntityScript* EMSCRIPTEN_KEEPALIVE EntityScript_EntityScript_0() {
		return new toy::EntityScript();
	}
	toy::EntityScript* EMSCRIPTEN_KEEPALIVE EntityScript_EntityScript_1(toy::HSpatial spatial) {
		return new toy::EntityScript(spatial);
	}
	mud::Script* EMSCRIPTEN_KEEPALIVE EntityScript_get_logic_script(toy::EntityScript* self) {
		return self->m_logic_script;
	}
	void EMSCRIPTEN_KEEPALIVE EntityScript_set_logic_script(toy::EntityScript* self, mud::Script* value) {
		self->m_logic_script = value;
	}
	mud::Script* EMSCRIPTEN_KEEPALIVE EntityScript_get_render_script(toy::EntityScript* self) {
		return self->m_render_script;
	}
	void EMSCRIPTEN_KEEPALIVE EntityScript_set_render_script(toy::EntityScript* self, mud::Script* value) {
		self->m_render_script = value;
	}
	void EMSCRIPTEN_KEEPALIVE EntityScript___destroy__(toy::EntityScript* self) {
		delete self;
	}
	// Medium
	const char* EMSCRIPTEN_KEEPALIVE Medium_get_name(toy::Medium* self) {
		return self->m_name.c_str();
	}
	void EMSCRIPTEN_KEEPALIVE Medium_set_name(toy::Medium* self, const char* value) {
		self->m_name = value;
	}
	bool EMSCRIPTEN_KEEPALIVE Medium_get_occlusions(toy::Medium* self) {
		return self->m_occlusions;
	}
	void EMSCRIPTEN_KEEPALIVE Medium_set_occlusions(toy::Medium* self, bool value) {
		self->m_occlusions = value;
	}
	bool EMSCRIPTEN_KEEPALIVE Medium_get_solid(toy::Medium* self) {
		return self->m_solid;
	}
	void EMSCRIPTEN_KEEPALIVE Medium_set_solid(toy::Medium* self, bool value) {
		self->m_solid = value;
	}
	void EMSCRIPTEN_KEEPALIVE Medium___destroy__(toy::Medium* self) {
		delete self;
	}
	// Movable
	toy::Movable* EMSCRIPTEN_KEEPALIVE Movable_Movable_0() {
		return new toy::Movable();
	}
	toy::Movable* EMSCRIPTEN_KEEPALIVE Movable_Movable_1(toy::HSpatial spatial) {
		return new toy::Movable(spatial);
	}
	void EMSCRIPTEN_KEEPALIVE Movable_modify_angular_velocity_1(toy::Movable* self, const mud::vec3* velocity) {
		self->modify_angular_velocity(*velocity);
	}
	void EMSCRIPTEN_KEEPALIVE Movable_modify_linear_velocity_1(toy::Movable* self, const mud::vec3* velocity) {
		self->modify_linear_velocity(*velocity);
	}
	void EMSCRIPTEN_KEEPALIVE Movable_set_angular_velocity_1(toy::Movable* self, const mud::vec3* velocity) {
		self->set_angular_velocity(*velocity);
	}
	void EMSCRIPTEN_KEEPALIVE Movable_set_linear_velocity_1(toy::Movable* self, const mud::vec3* velocity) {
		self->set_linear_velocity(*velocity);
	}
	mud::vec3* EMSCRIPTEN_KEEPALIVE Movable_get_linear_velocity(toy::Movable* self) {
		static mud::vec3 temp;
		return (temp = self->m_linear_velocity, &temp);
	}
	void EMSCRIPTEN_KEEPALIVE Movable_set_linear_velocity(toy::Movable* self, mud::vec3* value) {
		self->m_linear_velocity = *value;
	}
	mud::vec3* EMSCRIPTEN_KEEPALIVE Movable_get_angular_velocity(toy::Movable* self) {
		static mud::vec3 temp;
		return (temp = self->m_angular_velocity, &temp);
	}
	void EMSCRIPTEN_KEEPALIVE Movable_set_angular_velocity(toy::Movable* self, mud::vec3* value) {
		self->m_angular_velocity = *value;
	}
	bool EMSCRIPTEN_KEEPALIVE Movable_get_moving(toy::Movable* self) {
		return self->m_moving;
	}
	void EMSCRIPTEN_KEEPALIVE Movable_set_moving(toy::Movable* self, bool value) {
		self->m_moving = value;
	}
	mud::vec3* EMSCRIPTEN_KEEPALIVE Movable_get_previous_position(toy::Movable* self) {
		static mud::vec3 temp;
		return (temp = self->m_previous_position, &temp);
	}
	void EMSCRIPTEN_KEEPALIVE Movable_set_previous_position(toy::Movable* self, mud::vec3* value) {
		self->m_previous_position = *value;
	}
	void EMSCRIPTEN_KEEPALIVE Movable___destroy__(toy::Movable* self) {
		delete self;
	}
	// Navblock
	toy::Navblock* EMSCRIPTEN_KEEPALIVE Navblock_Navblock_0() {
		return new toy::Navblock();
	}
	toy::Navblock* EMSCRIPTEN_KEEPALIVE Navblock_Navblock_3(toy::HSpatial spatial, toy::HWorldPage world_page, toy::Navmesh* navmesh) {
		return new toy::Navblock(spatial, world_page, *navmesh);
	}
	toy::Navmesh* EMSCRIPTEN_KEEPALIVE Navblock_get_navmesh(toy::Navblock* self) {
		return self->m_navmesh;
	}
	void EMSCRIPTEN_KEEPALIVE Navblock_set_navmesh(toy::Navblock* self, toy::Navmesh* value) {
		self->m_navmesh = value;
	}
	bool EMSCRIPTEN_KEEPALIVE Navblock_get_auto_update(toy::Navblock* self) {
		return self->m_auto_update;
	}
	void EMSCRIPTEN_KEEPALIVE Navblock_set_auto_update(toy::Navblock* self, bool value) {
		self->m_auto_update = value;
	}
	size_t EMSCRIPTEN_KEEPALIVE Navblock_get_updated(toy::Navblock* self) {
		return self->m_updated;
	}
	void EMSCRIPTEN_KEEPALIVE Navblock_set_updated(toy::Navblock* self, size_t value) {
		self->m_updated = value;
	}
	void EMSCRIPTEN_KEEPALIVE Navblock___destroy__(toy::Navblock* self) {
		delete self;
	}
	// Navmesh
	toy::Navmesh* EMSCRIPTEN_KEEPALIVE Navmesh_Navmesh_1(toy::World* world) {
		return new toy::Navmesh(*world);
	}
	toy::World* EMSCRIPTEN_KEEPALIVE Navmesh_get_world(toy::Navmesh* self) {
		return &self->m_world;
	}
	size_t EMSCRIPTEN_KEEPALIVE Navmesh_get_updated(toy::Navmesh* self) {
		return self->m_updated;
	}
	void EMSCRIPTEN_KEEPALIVE Navmesh_set_updated(toy::Navmesh* self, size_t value) {
		self->m_updated = value;
	}
	bool EMSCRIPTEN_KEEPALIVE Navmesh_get_dirty(toy::Navmesh* self) {
		return self->m_dirty;
	}
	void EMSCRIPTEN_KEEPALIVE Navmesh_set_dirty(toy::Navmesh* self, bool value) {
		self->m_dirty = value;
	}
	void EMSCRIPTEN_KEEPALIVE Navmesh___destroy__(toy::Navmesh* self) {
		delete self;
	}
	// Origin
	toy::Origin* EMSCRIPTEN_KEEPALIVE Origin_Origin_0() {
		return new toy::Origin();
	}
	toy::Origin* EMSCRIPTEN_KEEPALIVE Origin_Origin_1(toy::HSpatial spatial) {
		return new toy::Origin(spatial);
	}
	void EMSCRIPTEN_KEEPALIVE Origin___destroy__(toy::Origin* self) {
		delete self;
	}
	// Pathfinder
	toy::Pathfinder* EMSCRIPTEN_KEEPALIVE Pathfinder_Pathfinder_1(toy::Navmesh* navmesh) {
		return new toy::Pathfinder(*navmesh);
	}
	void EMSCRIPTEN_KEEPALIVE Pathfinder___destroy__(toy::Pathfinder* self) {
		delete self;
	}
	// PhysicWorld
	mud::vec3* EMSCRIPTEN_KEEPALIVE PhysicWorld_ground_point_1(toy::PhysicWorld* self, const mud::Ray* ray) {
		static mud::vec3 temp;
		return (temp = self->ground_point(*ray), &temp);
	}
	toy::Collision* EMSCRIPTEN_KEEPALIVE PhysicWorld_raycast_2(toy::PhysicWorld* self, const mud::Ray* ray, short mask) {
		static toy::Collision temp;
		return (temp = self->raycast(*ray, mask), &temp);
	}
	toy::World* EMSCRIPTEN_KEEPALIVE PhysicWorld_get_world(toy::PhysicWorld* self) {
		return &self->m_world;
	}
	void EMSCRIPTEN_KEEPALIVE PhysicWorld___destroy__(toy::PhysicWorld* self) {
		delete self;
	}
	// Receptor
	toy::Receptor* EMSCRIPTEN_KEEPALIVE Receptor_Receptor_0() {
		return new toy::Receptor();
	}
	toy::Receptor* EMSCRIPTEN_KEEPALIVE Receptor_Receptor_1(toy::HSpatial spatial) {
		return new toy::Receptor(spatial);
	}
	toy::ReceptorScope* EMSCRIPTEN_KEEPALIVE Receptor_scope_1(toy::Receptor* self, toy::Medium* medium) {
		return self->scope(*medium);
	}
	void EMSCRIPTEN_KEEPALIVE Receptor___destroy__(toy::Receptor* self) {
		delete self;
	}
	// Solid
	toy::HSpatial EMSCRIPTEN_KEEPALIVE Solid_get_spatial(toy::Solid* self) {
		return self->m_spatial;
	}
	void EMSCRIPTEN_KEEPALIVE Solid_set_spatial(toy::Solid* self, toy::HSpatial value) {
		self->m_spatial = value;
	}
	bool EMSCRIPTEN_KEEPALIVE Solid_get_static(toy::Solid* self) {
		return self->m_static;
	}
	void EMSCRIPTEN_KEEPALIVE Solid_set_static(toy::Solid* self, bool value) {
		self->m_static = value;
	}
	float EMSCRIPTEN_KEEPALIVE Solid_get_mass(toy::Solid* self) {
		return self->m_mass;
	}
	void EMSCRIPTEN_KEEPALIVE Solid_set_mass(toy::Solid* self, float value) {
		self->m_mass = value;
	}
	void EMSCRIPTEN_KEEPALIVE Solid___destroy__(toy::Solid* self) {
		delete self;
	}
	// SolidImpl
	mud::vec3* EMSCRIPTEN_KEEPALIVE SolidImpl_angular_velocity_0(toy::SolidImpl* self) {
		static mud::vec3 temp;
		return (temp = self->angular_velocity(), &temp);
	}
	void EMSCRIPTEN_KEEPALIVE SolidImpl_impulse_2(toy::SolidImpl* self, const mud::vec3* force, const mud::vec3* point) {
		self->impulse(*force, *point);
	}
	mud::vec3* EMSCRIPTEN_KEEPALIVE SolidImpl_linear_velocity_0(toy::SolidImpl* self) {
		static mud::vec3 temp;
		return (temp = self->linear_velocity(), &temp);
	}
	void EMSCRIPTEN_KEEPALIVE SolidImpl_set_angular_factor_1(toy::SolidImpl* self, const mud::vec3* factor) {
		self->set_angular_factor(*factor);
	}
	void EMSCRIPTEN_KEEPALIVE SolidImpl_set_angular_velocity_1(toy::SolidImpl* self, const mud::vec3* torque) {
		self->set_angular_velocity(*torque);
	}
	void EMSCRIPTEN_KEEPALIVE SolidImpl_set_linear_velocity_1(toy::SolidImpl* self, const mud::vec3* force) {
		self->set_linear_velocity(*force);
	}
	void EMSCRIPTEN_KEEPALIVE SolidImpl___destroy__(toy::SolidImpl* self) {
		delete self;
	}
	// User
	void EMSCRIPTEN_KEEPALIVE User___destroy__(toy::User* self) {
		delete self;
	}
	// Waypoint
	toy::Waypoint* EMSCRIPTEN_KEEPALIVE Waypoint_Waypoint_0() {
		return new toy::Waypoint();
	}
	toy::Waypoint* EMSCRIPTEN_KEEPALIVE Waypoint_Waypoint_1(toy::HSpatial parent) {
		return new toy::Waypoint(parent);
	}
	void EMSCRIPTEN_KEEPALIVE Waypoint___destroy__(toy::Waypoint* self) {
		delete self;
	}
	// World
	toy::World* EMSCRIPTEN_KEEPALIVE World_World_4(mud::Id id, mud::Complex* complex, const char* name, mud::JobSystem* job_system) {
		return new toy::World(id, *complex, name, *job_system);
	}
	mud::Id EMSCRIPTEN_KEEPALIVE World_get_id(toy::World* self) {
		return self->m_id;
	}
	void EMSCRIPTEN_KEEPALIVE World_set_id(toy::World* self, mud::Id value) {
		self->m_id = value;
	}
	mud::Complex* EMSCRIPTEN_KEEPALIVE World_get_complex(toy::World* self) {
		return &self->m_complex;
	}
	const char* EMSCRIPTEN_KEEPALIVE World_get_name(toy::World* self) {
		return self->m_name.c_str();
	}
	void EMSCRIPTEN_KEEPALIVE World_set_name(toy::World* self, const char* value) {
		self->m_name = value;
	}
	toy::HSpatial EMSCRIPTEN_KEEPALIVE World_get_origin(toy::World* self) {
		return self->origin();
	}
	toy::HSpatial EMSCRIPTEN_KEEPALIVE World_get_unworld(toy::World* self) {
		return self->unworld();
	}
	void EMSCRIPTEN_KEEPALIVE World___destroy__(toy::World* self) {
		delete self;
	}
	// WorldClock
	void EMSCRIPTEN_KEEPALIVE WorldClock___destroy__(toy::WorldClock* self) {
		delete self;
	}
	// WorldPage
	toy::WorldPage* EMSCRIPTEN_KEEPALIVE WorldPage_WorldPage_0() {
		return new toy::WorldPage();
	}
	toy::WorldPage* EMSCRIPTEN_KEEPALIVE WorldPage_WorldPage_3(toy::HSpatial spatial, bool open, const mud::vec3* extents) {
		return new toy::WorldPage(spatial, open, *extents);
	}
	void EMSCRIPTEN_KEEPALIVE WorldPage_build_geometry_1(toy::WorldPage* self, const toy::Spatial* spatial) {
		self->build_geometry(*spatial);
	}
	void EMSCRIPTEN_KEEPALIVE WorldPage_ground_point_3(toy::WorldPage* self, const mud::vec3* position, bool relative, mud::vec3* outputPoint) {
		self->ground_point(*position, relative, *outputPoint);
	}
	void EMSCRIPTEN_KEEPALIVE WorldPage_raycast_ground_3(toy::WorldPage* self, const mud::vec3* from, const mud::vec3* to, mud::vec3* ground_point) {
		self->raycast_ground(*from, *to, *ground_point);
	}
	void EMSCRIPTEN_KEEPALIVE WorldPage_update_geometry_0(toy::WorldPage* self) {
		self->update_geometry();
	}
	bool EMSCRIPTEN_KEEPALIVE WorldPage_get_open(toy::WorldPage* self) {
		return self->m_open;
	}
	void EMSCRIPTEN_KEEPALIVE WorldPage_set_open(toy::WorldPage* self, bool value) {
		self->m_open = value;
	}
	mud::vec3* EMSCRIPTEN_KEEPALIVE WorldPage_get_extents(toy::WorldPage* self) {
		static mud::vec3 temp;
		return (temp = self->m_extents, &temp);
	}
	void EMSCRIPTEN_KEEPALIVE WorldPage_set_extents(toy::WorldPage* self, mud::vec3* value) {
		self->m_extents = *value;
	}
	toy::World* EMSCRIPTEN_KEEPALIVE WorldPage_get_world(toy::WorldPage* self) {
		return self->m_world;
	}
	void EMSCRIPTEN_KEEPALIVE WorldPage_set_world(toy::WorldPage* self, toy::World* value) {
		self->m_world = value;
	}
	size_t EMSCRIPTEN_KEEPALIVE WorldPage_get_last_rebuilt(toy::WorldPage* self) {
		return self->m_last_rebuilt;
	}
	void EMSCRIPTEN_KEEPALIVE WorldPage_set_last_rebuilt(toy::WorldPage* self, size_t value) {
		self->m_last_rebuilt = value;
	}
	void EMSCRIPTEN_KEEPALIVE WorldPage___destroy__(toy::WorldPage* self) {
		delete self;
	}
	// BulletCollider
	void EMSCRIPTEN_KEEPALIVE BulletCollider___destroy__(toy::BulletCollider* self) {
		delete self;
	}
	// BulletSolid
	void EMSCRIPTEN_KEEPALIVE BulletSolid___destroy__(toy::BulletSolid* self) {
		delete self;
	}
	// BulletWorld
	toy::BulletWorld* EMSCRIPTEN_KEEPALIVE BulletWorld_BulletWorld_1(toy::World* world) {
		return new toy::BulletWorld(*world);
	}
	void EMSCRIPTEN_KEEPALIVE BulletWorld___destroy__(toy::BulletWorld* self) {
		delete self;
	}
	// DefaultWorld
	toy::DefaultWorld* EMSCRIPTEN_KEEPALIVE DefaultWorld_DefaultWorld_2(const char* name, mud::JobSystem* job_system) {
		return new toy::DefaultWorld(name, *job_system);
	}
	toy::World* EMSCRIPTEN_KEEPALIVE DefaultWorld_get_world(toy::DefaultWorld* self) {
		return &self->m_world;
	}
	toy::BulletWorld* EMSCRIPTEN_KEEPALIVE DefaultWorld_get_bullet_world(toy::DefaultWorld* self) {
		return &self->m_bullet_world;
	}
	toy::Navmesh* EMSCRIPTEN_KEEPALIVE DefaultWorld_get_navmesh(toy::DefaultWorld* self) {
		return &self->m_navmesh;
	}
	void EMSCRIPTEN_KEEPALIVE DefaultWorld___destroy__(toy::DefaultWorld* self) {
		delete self;
	}
	// PhysicScope
	void EMSCRIPTEN_KEEPALIVE PhysicScope___destroy__(toy::PhysicScope* self) {
		delete self;
	}
	// EmitterScope
	void EMSCRIPTEN_KEEPALIVE EmitterScope___destroy__(toy::EmitterScope* self) {
		delete self;
	}
	// NavmeshShape
	toy::NavmeshShape* EMSCRIPTEN_KEEPALIVE NavmeshShape_NavmeshShape_1(toy::Navmesh* navmesh) {
		return new toy::NavmeshShape(*navmesh);
	}
	void EMSCRIPTEN_KEEPALIVE NavmeshShape___destroy__(toy::NavmeshShape* self) {
		delete self;
	}
	// Obstacle
	toy::Obstacle* EMSCRIPTEN_KEEPALIVE Obstacle_Obstacle_5(toy::HSpatial spatial, toy::HMovable movable, toy::Medium* medium, const toy::CollisionShape* shape, float throughput) {
		return new toy::Obstacle(spatial, movable, *medium, *shape, throughput);
	}
	toy::CollisionShape* EMSCRIPTEN_KEEPALIVE Obstacle_get_shape(toy::Obstacle* self) {
		return &self->m_shape;
	}
	float EMSCRIPTEN_KEEPALIVE Obstacle_get_throughput(toy::Obstacle* self) {
		return self->m_throughput;
	}
	void EMSCRIPTEN_KEEPALIVE Obstacle_set_throughput(toy::Obstacle* self, float value) {
		self->m_throughput = value;
	}
	void EMSCRIPTEN_KEEPALIVE Obstacle___destroy__(toy::Obstacle* self) {
		delete self;
	}
	// ReceptorScope
	void EMSCRIPTEN_KEEPALIVE ReceptorScope___destroy__(toy::ReceptorScope* self) {
		delete self;
	}
	// SolidMedium
	toy::SolidMedium* EMSCRIPTEN_KEEPALIVE SolidMedium_SolidMedium_0() {
		return new toy::SolidMedium();
	}
	void EMSCRIPTEN_KEEPALIVE SolidMedium___destroy__(toy::SolidMedium* self) {
		delete self;
	}
	// SoundMedium
	toy::SoundMedium* EMSCRIPTEN_KEEPALIVE SoundMedium_SoundMedium_0() {
		return new toy::SoundMedium();
	}
	void EMSCRIPTEN_KEEPALIVE SoundMedium___destroy__(toy::SoundMedium* self) {
		delete self;
	}
	// Spatial
	toy::Spatial* EMSCRIPTEN_KEEPALIVE Spatial_Spatial_0() {
		return new toy::Spatial();
	}
	toy::Spatial* EMSCRIPTEN_KEEPALIVE Spatial_Spatial_3(toy::HSpatial parent, const mud::vec3* position, const mud::quat* rotation) {
		return new toy::Spatial(parent, *position, *rotation);
	}
	void EMSCRIPTEN_KEEPALIVE Spatial_set_position_1(toy::Spatial* self, const mud::vec3* position) {
		self->set_position(*position);
	}
	void EMSCRIPTEN_KEEPALIVE Spatial_set_rotation_1(toy::Spatial* self, const mud::quat* rotation) {
		self->set_rotation(*rotation);
	}
	toy::World* EMSCRIPTEN_KEEPALIVE Spatial_get_world(toy::Spatial* self) {
		return self->m_world;
	}
	void EMSCRIPTEN_KEEPALIVE Spatial_set_world(toy::Spatial* self, toy::World* value) {
		self->m_world = value;
	}
	toy::HSpatial EMSCRIPTEN_KEEPALIVE Spatial_get_parent(toy::Spatial* self) {
		return self->m_parent;
	}
	void EMSCRIPTEN_KEEPALIVE Spatial_set_parent(toy::Spatial* self, toy::HSpatial value) {
		self->m_parent = value;
	}
	void EMSCRIPTEN_KEEPALIVE Spatial___destroy__(toy::Spatial* self) {
		delete self;
	}
	// VisualMedium
	toy::VisualMedium* EMSCRIPTEN_KEEPALIVE VisualMedium_VisualMedium_0() {
		return new toy::VisualMedium();
	}
	void EMSCRIPTEN_KEEPALIVE VisualMedium___destroy__(toy::VisualMedium* self) {
		delete self;
	}
	// WorldMedium
	toy::WorldMedium* EMSCRIPTEN_KEEPALIVE WorldMedium_WorldMedium_0() {
		return new toy::WorldMedium();
	}
	void EMSCRIPTEN_KEEPALIVE WorldMedium___destroy__(toy::WorldMedium* self) {
		delete self;
	}
	// CollisionGroup
	toy::CollisionGroup EMSCRIPTEN_KEEPALIVE CollisionGroup_CM_NOMASK() {
		return toy::CM_NOMASK;
	}
	toy::CollisionGroup EMSCRIPTEN_KEEPALIVE CollisionGroup_CM_OBJECT() {
		return toy::CM_OBJECT;
	}
	toy::CollisionGroup EMSCRIPTEN_KEEPALIVE CollisionGroup_CM_SOLID() {
		return toy::CM_SOLID;
	}
	toy::CollisionGroup EMSCRIPTEN_KEEPALIVE CollisionGroup_CM_GROUND() {
		return toy::CM_GROUND;
	}
	toy::CollisionGroup EMSCRIPTEN_KEEPALIVE CollisionGroup_CM_AREA() {
		return toy::CM_AREA;
	}
	toy::CollisionGroup EMSCRIPTEN_KEEPALIVE CollisionGroup_CM_BUFFER() {
		return toy::CM_BUFFER;
	}
	toy::CollisionGroup EMSCRIPTEN_KEEPALIVE CollisionGroup_CM_LIGHT() {
		return toy::CM_LIGHT;
	}
	toy::CollisionGroup EMSCRIPTEN_KEEPALIVE CollisionGroup_CM_LIGHTREFLECTOR() {
		return toy::CM_LIGHTREFLECTOR;
	}
	toy::CollisionGroup EMSCRIPTEN_KEEPALIVE CollisionGroup_CM_SOURCE() {
		return toy::CM_SOURCE;
	}
	toy::CollisionGroup EMSCRIPTEN_KEEPALIVE CollisionGroup_CM_RECEPTOR() {
		return toy::CM_RECEPTOR;
	}
	toy::CollisionGroup EMSCRIPTEN_KEEPALIVE CollisionGroup_CM_OBSTACLE() {
		return toy::CM_OBSTACLE;
	}
	
}


