#include <type/Api.h>
#include <jobs/Api.h>
#include <ecs/Api.h>
#include <math/Api.h>
#include <geom/Api.h>
#include <lang/Api.h>
#include <util/Api.h>
#include <core/Api.h>

#ifdef MUD_PLATFORM_EMSCRIPTEN
#include <emscripten.h>
#define DECL EMSCRIPTEN_KEEPALIVE
#else
#define DECL
#endif


extern "C" {
	
	// OwnedHandle<toy::Collider>
	two::Type* DECL two_OwnedHandle_toy_Collider__type() {
		return &two::type<two::OwnedHandle<toy::Collider>>();
	}
	two::OwnedHandle<toy::Collider>* DECL two_OwnedHandle_toy_Collider__construct_0() {
		return new two::OwnedHandle<toy::Collider>();
	}
	void DECL two_OwnedHandle_toy_Collider__destroy(two::OwnedHandle<toy::Collider>* self) {
		delete self;
	}
	// OwnedHandle<toy::Solid>
	two::Type* DECL two_OwnedHandle_toy_Solid__type() {
		return &two::type<two::OwnedHandle<toy::Solid>>();
	}
	two::OwnedHandle<toy::Solid>* DECL two_OwnedHandle_toy_Solid__construct_0() {
		return new two::OwnedHandle<toy::Solid>();
	}
	void DECL two_OwnedHandle_toy_Solid__destroy(two::OwnedHandle<toy::Solid>* self) {
		delete self;
	}
	// SparseHandle<toy::Collider>
	two::Type* DECL two_SparseHandle_toy_Collider__type() {
		return &two::type<two::SparseHandle<toy::Collider>>();
	}
	two::SparseHandle<toy::Collider>* DECL two_SparseHandle_toy_Collider__construct_0() {
		return new two::SparseHandle<toy::Collider>();
	}
	void DECL two_SparseHandle_toy_Collider__destroy(two::SparseHandle<toy::Collider>* self) {
		delete self;
	}
	// SparseHandle<toy::Solid>
	two::Type* DECL two_SparseHandle_toy_Solid__type() {
		return &two::type<two::SparseHandle<toy::Solid>>();
	}
	two::SparseHandle<toy::Solid>* DECL two_SparseHandle_toy_Solid__construct_0() {
		return new two::SparseHandle<toy::Solid>();
	}
	void DECL two_SparseHandle_toy_Solid__destroy(two::SparseHandle<toy::Solid>* self) {
		delete self;
	}
	// ComponentHandle<toy::Spatial>
	two::Type* DECL two_ComponentHandle_toy_Spatial__type() {
		return &two::type<two::ComponentHandle<toy::Spatial>>();
	}
	two::ComponentHandle<toy::Spatial>* DECL two_ComponentHandle_toy_Spatial__construct_0() {
		return new two::ComponentHandle<toy::Spatial>();
	}
	void DECL two_ComponentHandle_toy_Spatial__destroy(two::ComponentHandle<toy::Spatial>* self) {
		delete self;
	}
	// ComponentHandle<toy::Movable>
	two::Type* DECL two_ComponentHandle_toy_Movable__type() {
		return &two::type<two::ComponentHandle<toy::Movable>>();
	}
	two::ComponentHandle<toy::Movable>* DECL two_ComponentHandle_toy_Movable__construct_0() {
		return new two::ComponentHandle<toy::Movable>();
	}
	void DECL two_ComponentHandle_toy_Movable__destroy(two::ComponentHandle<toy::Movable>* self) {
		delete self;
	}
	// ComponentHandle<toy::Camera>
	two::Type* DECL two_ComponentHandle_toy_Camera__type() {
		return &two::type<two::ComponentHandle<toy::Camera>>();
	}
	two::ComponentHandle<toy::Camera>* DECL two_ComponentHandle_toy_Camera__construct_0() {
		return new two::ComponentHandle<toy::Camera>();
	}
	void DECL two_ComponentHandle_toy_Camera__destroy(two::ComponentHandle<toy::Camera>* self) {
		delete self;
	}
	// ComponentHandle<toy::Emitter>
	two::Type* DECL two_ComponentHandle_toy_Emitter__type() {
		return &two::type<two::ComponentHandle<toy::Emitter>>();
	}
	two::ComponentHandle<toy::Emitter>* DECL two_ComponentHandle_toy_Emitter__construct_0() {
		return new two::ComponentHandle<toy::Emitter>();
	}
	void DECL two_ComponentHandle_toy_Emitter__destroy(two::ComponentHandle<toy::Emitter>* self) {
		delete self;
	}
	// ComponentHandle<toy::Receptor>
	two::Type* DECL two_ComponentHandle_toy_Receptor__type() {
		return &two::type<two::ComponentHandle<toy::Receptor>>();
	}
	two::ComponentHandle<toy::Receptor>* DECL two_ComponentHandle_toy_Receptor__construct_0() {
		return new two::ComponentHandle<toy::Receptor>();
	}
	void DECL two_ComponentHandle_toy_Receptor__destroy(two::ComponentHandle<toy::Receptor>* self) {
		delete self;
	}
	// ComponentHandle<toy::EntityScript>
	two::Type* DECL two_ComponentHandle_toy_EntityScript__type() {
		return &two::type<two::ComponentHandle<toy::EntityScript>>();
	}
	two::ComponentHandle<toy::EntityScript>* DECL two_ComponentHandle_toy_EntityScript__construct_0() {
		return new two::ComponentHandle<toy::EntityScript>();
	}
	void DECL two_ComponentHandle_toy_EntityScript__destroy(two::ComponentHandle<toy::EntityScript>* self) {
		delete self;
	}
	// ComponentHandle<toy::WorldPage>
	two::Type* DECL two_ComponentHandle_toy_WorldPage__type() {
		return &two::type<two::ComponentHandle<toy::WorldPage>>();
	}
	two::ComponentHandle<toy::WorldPage>* DECL two_ComponentHandle_toy_WorldPage__construct_0() {
		return new two::ComponentHandle<toy::WorldPage>();
	}
	void DECL two_ComponentHandle_toy_WorldPage__destroy(two::ComponentHandle<toy::WorldPage>* self) {
		delete self;
	}
	// ComponentHandle<toy::Navblock>
	two::Type* DECL two_ComponentHandle_toy_Navblock__type() {
		return &two::type<two::ComponentHandle<toy::Navblock>>();
	}
	two::ComponentHandle<toy::Navblock>* DECL two_ComponentHandle_toy_Navblock__construct_0() {
		return new two::ComponentHandle<toy::Navblock>();
	}
	void DECL two_ComponentHandle_toy_Navblock__destroy(two::ComponentHandle<toy::Navblock>* self) {
		delete self;
	}
	// ComponentHandle<toy::Origin>
	two::Type* DECL two_ComponentHandle_toy_Origin__type() {
		return &two::type<two::ComponentHandle<toy::Origin>>();
	}
	two::ComponentHandle<toy::Origin>* DECL two_ComponentHandle_toy_Origin__construct_0() {
		return new two::ComponentHandle<toy::Origin>();
	}
	void DECL two_ComponentHandle_toy_Origin__destroy(two::ComponentHandle<toy::Origin>* self) {
		delete self;
	}
	// ComponentHandle<toy::Waypoint>
	two::Type* DECL two_ComponentHandle_toy_Waypoint__type() {
		return &two::type<two::ComponentHandle<toy::Waypoint>>();
	}
	two::ComponentHandle<toy::Waypoint>* DECL two_ComponentHandle_toy_Waypoint__construct_0() {
		return new two::ComponentHandle<toy::Waypoint>();
	}
	void DECL two_ComponentHandle_toy_Waypoint__destroy(two::ComponentHandle<toy::Waypoint>* self) {
		delete self;
	}
	// Spatial
	two::Type* DECL toy_Spatial__type() {
		return &two::type<toy::Spatial>();
	}
	toy::Spatial* DECL toy_Spatial__construct_0() {
		return new toy::Spatial();
	}
	toy::Spatial* DECL toy_Spatial__construct_3(toy::HSpatial* parent, const two::vec3* position, const two::quat* rotation) {
		return new toy::Spatial(*parent, *position, *rotation);
	}
	toy::Spatial* DECL toy_Spatial__construct_4(toy::World* world, toy::HSpatial* parent, const two::vec3* position, const two::quat* rotation) {
		return new toy::Spatial(*world, *parent, *position, *rotation);
	}
	void DECL toy_Spatial_set_position_1(toy::Spatial* self, const two::vec3* position) {
		self->set_position(*position);
	}
	void DECL toy_Spatial_set_rotation_1(toy::Spatial* self, const two::quat* rotation) {
		self->set_rotation(*rotation);
	}
	toy::World* DECL toy_Spatial__get_world(toy::Spatial* self) {
		return self->m_world;
	}
	void DECL toy_Spatial__set_world(toy::Spatial* self, toy::World* value) {
		self->m_world = value;
	}
	toy::HSpatial* DECL toy_Spatial__get_parent(toy::Spatial* self) {
		return &self->m_parent;
	}
	void DECL toy_Spatial__set_parent(toy::Spatial* self, toy::HSpatial* value) {
		self->m_parent = *value;
	}
	void DECL toy_Spatial__destroy(toy::Spatial* self) {
		delete self;
	}
	// Origin
	two::Type* DECL toy_Origin__type() {
		return &two::type<toy::Origin>();
	}
	toy::Origin* DECL toy_Origin__construct_0() {
		return new toy::Origin();
	}
	void DECL toy_Origin__destroy(toy::Origin* self) {
		delete self;
	}
	// WorldClock
	two::Type* DECL toy_WorldClock__type() {
		return &two::type<toy::WorldClock>();
	}
	void DECL toy_WorldClock__destroy(toy::WorldClock* self) {
		delete self;
	}
	// World
	two::Type* DECL toy_World__type() {
		return &two::type<toy::World>();
	}
	uint32_t DECL toy_World__get_id(toy::World* self) {
		return self->m_id;
	}
	void DECL toy_World__set_id(toy::World* self, uint32_t value) {
		self->m_id = value;
	}
	const char* DECL toy_World__get_name(toy::World* self) {
		return self->m_name.c_str();
	}
	void DECL toy_World__set_name(toy::World* self, const char* value) {
		self->m_name = value;
	}
	toy::HSpatial* DECL toy_World__get_origin(toy::World* self) {
		static toy::HSpatial temp;
		return (temp = self->origin(), &temp);
	}
	toy::HSpatial* DECL toy_World__get_unworld(toy::World* self) {
		static toy::HSpatial temp;
		return (temp = self->unworld(), &temp);
	}
	void DECL toy_World__destroy(toy::World* self) {
		delete self;
	}
	// Medium
	two::Type* DECL toy_Medium__type() {
		return &two::type<toy::Medium>();
	}
	const char* DECL toy_Medium__get_name(toy::Medium* self) {
		return self->m_name.c_str();
	}
	void DECL toy_Medium__set_name(toy::Medium* self, const char* value) {
		self->m_name = value;
	}
	bool DECL toy_Medium__get_occlusions(toy::Medium* self) {
		return self->m_occlusions;
	}
	void DECL toy_Medium__set_occlusions(toy::Medium* self, bool value) {
		self->m_occlusions = value;
	}
	bool DECL toy_Medium__get_solid(toy::Medium* self) {
		return self->m_solid;
	}
	void DECL toy_Medium__set_solid(toy::Medium* self, bool value) {
		self->m_solid = value;
	}
	void DECL toy_Medium__destroy(toy::Medium* self) {
		delete self;
	}
	// CollisionShape
	two::Type* DECL toy_CollisionShape__type() {
		return &two::type<toy::CollisionShape>();
	}
	toy::CollisionShape* DECL toy_CollisionShape__construct_0() {
		return new toy::CollisionShape();
	}
	toy::CollisionShape* DECL toy_CollisionShape__construct_1(const two::Shape* shape) {
		return new toy::CollisionShape(*shape);
	}
	toy::CollisionShape* DECL toy_CollisionShape__construct_2(const two::Shape* shape, const two::vec3* center) {
		return new toy::CollisionShape(*shape, *center);
	}
	toy::CollisionShape* DECL toy_CollisionShape__construct_3(const two::Shape* shape, const two::vec3* center, float margin) {
		return new toy::CollisionShape(*shape, *center, margin);
	}
	void DECL toy_CollisionShape__destroy(toy::CollisionShape* self) {
		delete self;
	}
	// Movable
	two::Type* DECL toy_Movable__type() {
		return &two::type<toy::Movable>();
	}
	toy::Movable* DECL toy_Movable__construct_0() {
		return new toy::Movable();
	}
	toy::Movable* DECL toy_Movable__construct_1(const two::vec3* position) {
		return new toy::Movable(*position);
	}
	void DECL toy_Movable_set_linear_velocity_1(toy::Movable* self, const two::vec3* velocity) {
		self->set_linear_velocity(*velocity);
	}
	void DECL toy_Movable_modify_linear_velocity_1(toy::Movable* self, const two::vec3* velocity) {
		self->modify_linear_velocity(*velocity);
	}
	void DECL toy_Movable_set_angular_velocity_1(toy::Movable* self, const two::vec3* velocity) {
		self->set_angular_velocity(*velocity);
	}
	void DECL toy_Movable_modify_angular_velocity_1(toy::Movable* self, const two::vec3* velocity) {
		self->modify_angular_velocity(*velocity);
	}
	two::vec3* DECL toy_Movable__get_linear_velocity(toy::Movable* self) {
		return &self->m_linear_velocity;
	}
	void DECL toy_Movable__set_linear_velocity(toy::Movable* self, two::vec3* value) {
		self->m_linear_velocity = *value;
	}
	two::vec3* DECL toy_Movable__get_angular_velocity(toy::Movable* self) {
		return &self->m_angular_velocity;
	}
	void DECL toy_Movable__set_angular_velocity(toy::Movable* self, two::vec3* value) {
		self->m_angular_velocity = *value;
	}
	bool DECL toy_Movable__get_moving(toy::Movable* self) {
		return self->m_moving;
	}
	void DECL toy_Movable__set_moving(toy::Movable* self, bool value) {
		self->m_moving = value;
	}
	two::vec3* DECL toy_Movable__get_previous_position(toy::Movable* self) {
		return &self->m_previous_position;
	}
	void DECL toy_Movable__set_previous_position(toy::Movable* self, two::vec3* value) {
		self->m_previous_position = *value;
	}
	void DECL toy_Movable__destroy(toy::Movable* self) {
		delete self;
	}
	// Collision
	two::Type* DECL toy_Collision__type() {
		return &two::type<toy::Collision>();
	}
	toy::Collision* DECL toy_Collision__construct_0() {
		return new toy::Collision();
	}
	toy::HCollider* DECL toy_Collision__get_first(toy::Collision* self) {
		return &self->m_first;
	}
	void DECL toy_Collision__set_first(toy::Collision* self, toy::HCollider* value) {
		self->m_first = *value;
	}
	toy::HCollider* DECL toy_Collision__get_second(toy::Collision* self) {
		return &self->m_second;
	}
	void DECL toy_Collision__set_second(toy::Collision* self, toy::HCollider* value) {
		self->m_second = *value;
	}
	two::vec3* DECL toy_Collision__get_hit_point(toy::Collision* self) {
		return &self->m_hit_point;
	}
	void DECL toy_Collision__set_hit_point(toy::Collision* self, two::vec3* value) {
		self->m_hit_point = *value;
	}
	void DECL toy_Collision__destroy(toy::Collision* self) {
		delete self;
	}
	// ColliderImpl
	two::Type* DECL toy_ColliderImpl__type() {
		return &two::type<toy::ColliderImpl>();
	}
	void DECL toy_ColliderImpl__destroy(toy::ColliderImpl* self) {
		delete self;
	}
	// ColliderObject
	two::Type* DECL toy_ColliderObject__type() {
		return &two::type<toy::ColliderObject>();
	}
	void DECL toy_ColliderObject__destroy(toy::ColliderObject* self) {
		delete self;
	}
	// Collider
	two::Type* DECL toy_Collider__type() {
		return &two::type<toy::Collider>();
	}
	toy::Collider* DECL toy_Collider__construct_0() {
		return new toy::Collider();
	}
	toy::Collider* DECL toy_Collider__construct_5(toy::HSpatial* spatial, toy::HMovable* movable, const toy::CollisionShape* collision_shape, toy::Medium* medium, toy::CollisionGroup group) {
		return new toy::Collider(*spatial, *movable, *collision_shape, *medium, group);
	}
	toy::HSpatial* DECL toy_Collider__get_spatial(toy::Collider* self) {
		return &self->m_spatial;
	}
	void DECL toy_Collider__set_spatial(toy::Collider* self, toy::HSpatial* value) {
		self->m_spatial = *value;
	}
	toy::HMovable* DECL toy_Collider__get_movable(toy::Collider* self) {
		return &self->m_movable;
	}
	void DECL toy_Collider__set_movable(toy::Collider* self, toy::HMovable* value) {
		self->m_movable = *value;
	}
	toy::CollisionShape* DECL toy_Collider__get_collision_shape(toy::Collider* self) {
		return &self->m_collision_shape;
	}
	toy::Medium* DECL toy_Collider__get_medium(toy::Collider* self) {
		return self->m_medium;
	}
	void DECL toy_Collider__set_medium(toy::Collider* self, toy::Medium* value) {
		self->m_medium = value;
	}
	toy::CollisionGroup DECL toy_Collider__get_group(toy::Collider* self) {
		return self->m_group;
	}
	void DECL toy_Collider__set_group(toy::Collider* self, toy::CollisionGroup value) {
		self->m_group = value;
	}
	toy::ColliderObject* DECL toy_Collider__get_object(toy::Collider* self) {
		return self->m_object;
	}
	void DECL toy_Collider__set_object(toy::Collider* self, toy::ColliderObject* value) {
		self->m_object = value;
	}
	toy::ColliderImpl* DECL toy_Collider__get_impl(toy::Collider* self) {
		return &self->impl();
	}
	void DECL toy_Collider__destroy(toy::Collider* self) {
		delete self;
	}
	// SolidImpl
	two::Type* DECL toy_SolidImpl__type() {
		return &two::type<toy::SolidImpl>();
	}
	two::vec3* DECL toy_SolidImpl_linear_velocity_0(toy::SolidImpl* self) {
		static two::vec3 temp;
		return (temp = self->linear_velocity(), &temp);
	}
	two::vec3* DECL toy_SolidImpl_angular_velocity_0(toy::SolidImpl* self) {
		static two::vec3 temp;
		return (temp = self->angular_velocity(), &temp);
	}
	void DECL toy_SolidImpl_set_linear_velocity_1(toy::SolidImpl* self, const two::vec3* force) {
		self->set_linear_velocity(*force);
	}
	void DECL toy_SolidImpl_set_angular_velocity_1(toy::SolidImpl* self, const two::vec3* torque) {
		self->set_angular_velocity(*torque);
	}
	void DECL toy_SolidImpl_set_angular_factor_1(toy::SolidImpl* self, const two::vec3* factor) {
		self->set_angular_factor(*factor);
	}
	void DECL toy_SolidImpl_impulse_2(toy::SolidImpl* self, const two::vec3* force, const two::vec3* point) {
		self->impulse(*force, *point);
	}
	void DECL toy_SolidImpl__destroy(toy::SolidImpl* self) {
		delete self;
	}
	// Solid
	two::Type* DECL toy_Solid__type() {
		return &two::type<toy::Solid>();
	}
	toy::HSpatial* DECL toy_Solid__get_spatial(toy::Solid* self) {
		return &self->m_spatial;
	}
	void DECL toy_Solid__set_spatial(toy::Solid* self, toy::HSpatial* value) {
		self->m_spatial = *value;
	}
	bool DECL toy_Solid__get_static(toy::Solid* self) {
		return self->m_static;
	}
	void DECL toy_Solid__set_static(toy::Solid* self, bool value) {
		self->m_static = value;
	}
	float DECL toy_Solid__get_mass(toy::Solid* self) {
		return self->m_mass;
	}
	void DECL toy_Solid__set_mass(toy::Solid* self, float value) {
		self->m_mass = value;
	}
	void DECL toy_Solid__destroy(toy::Solid* self) {
		delete self;
	}
	// WorldMedium
	two::Type* DECL toy_WorldMedium__type() {
		return &two::type<toy::WorldMedium>();
	}
	toy::WorldMedium* DECL toy_WorldMedium__construct_0() {
		return new toy::WorldMedium();
	}
	void DECL toy_WorldMedium__destroy(toy::WorldMedium* self) {
		delete self;
	}
	// WorldPage
	two::Type* DECL toy_WorldPage__type() {
		return &two::type<toy::WorldPage>();
	}
	toy::WorldPage* DECL toy_WorldPage__construct_0() {
		return new toy::WorldPage();
	}
	toy::WorldPage* DECL toy_WorldPage__construct_3(toy::HSpatial* spatial, bool open, const two::vec3* extents) {
		return new toy::WorldPage(*spatial, open, *extents);
	}
	void DECL toy_WorldPage_update_geometry_1(toy::WorldPage* self, size_t tick) {
		self->update_geometry(tick);
	}
	void DECL toy_WorldPage_ground_point_3(toy::WorldPage* self, const two::vec3* position, bool relative, two::vec3* outputPoint) {
		self->ground_point(*position, relative, *outputPoint);
	}
	void DECL toy_WorldPage_raycast_ground_3(toy::WorldPage* self, const two::vec3* from, const two::vec3* to, two::vec3* ground_point) {
		self->raycast_ground(*from, *to, *ground_point);
	}
	bool DECL toy_WorldPage__get_open(toy::WorldPage* self) {
		return self->m_open;
	}
	void DECL toy_WorldPage__set_open(toy::WorldPage* self, bool value) {
		self->m_open = value;
	}
	two::vec3* DECL toy_WorldPage__get_extents(toy::WorldPage* self) {
		return &self->m_extents;
	}
	void DECL toy_WorldPage__set_extents(toy::WorldPage* self, two::vec3* value) {
		self->m_extents = *value;
	}
	toy::World* DECL toy_WorldPage__get_world(toy::WorldPage* self) {
		return self->m_world;
	}
	void DECL toy_WorldPage__set_world(toy::WorldPage* self, toy::World* value) {
		self->m_world = value;
	}
	size_t DECL toy_WorldPage__get_last_rebuilt(toy::WorldPage* self) {
		return self->m_last_rebuilt;
	}
	void DECL toy_WorldPage__set_last_rebuilt(toy::WorldPage* self, size_t value) {
		self->m_last_rebuilt = value;
	}
	void DECL toy_WorldPage__destroy(toy::WorldPage* self) {
		delete self;
	}
	// Navmesh
	two::Type* DECL toy_Navmesh__type() {
		return &two::type<toy::Navmesh>();
	}
	toy::Navmesh* DECL toy_Navmesh__construct_1(toy::World* world) {
		return new toy::Navmesh(*world);
	}
	toy::World* DECL toy_Navmesh__get_world(toy::Navmesh* self) {
		return &self->m_world;
	}
	size_t DECL toy_Navmesh__get_updated(toy::Navmesh* self) {
		return self->m_updated;
	}
	void DECL toy_Navmesh__set_updated(toy::Navmesh* self, size_t value) {
		self->m_updated = value;
	}
	bool DECL toy_Navmesh__get_dirty(toy::Navmesh* self) {
		return self->m_dirty;
	}
	void DECL toy_Navmesh__set_dirty(toy::Navmesh* self, bool value) {
		self->m_dirty = value;
	}
	void DECL toy_Navmesh__destroy(toy::Navmesh* self) {
		delete self;
	}
	// Navblock
	two::Type* DECL toy_Navblock__type() {
		return &two::type<toy::Navblock>();
	}
	toy::Navblock* DECL toy_Navblock__construct_0() {
		return new toy::Navblock();
	}
	toy::Navblock* DECL toy_Navblock__construct_3(toy::HSpatial* spatial, toy::HWorldPage* world_page, toy::Navmesh* navmesh) {
		return new toy::Navblock(*spatial, *world_page, *navmesh);
	}
	toy::Navmesh* DECL toy_Navblock__get_navmesh(toy::Navblock* self) {
		return self->m_navmesh;
	}
	void DECL toy_Navblock__set_navmesh(toy::Navblock* self, toy::Navmesh* value) {
		self->m_navmesh = value;
	}
	bool DECL toy_Navblock__get_auto_update(toy::Navblock* self) {
		return self->m_auto_update;
	}
	void DECL toy_Navblock__set_auto_update(toy::Navblock* self, bool value) {
		self->m_auto_update = value;
	}
	size_t DECL toy_Navblock__get_updated(toy::Navblock* self) {
		return self->m_updated;
	}
	void DECL toy_Navblock__set_updated(toy::Navblock* self, size_t value) {
		self->m_updated = value;
	}
	void DECL toy_Navblock__destroy(toy::Navblock* self) {
		delete self;
	}
	// NavmeshShape
	two::Type* DECL toy_NavmeshShape__type() {
		return &two::type<toy::NavmeshShape>();
	}
	toy::NavmeshShape* DECL toy_NavmeshShape__construct_1(toy::Navmesh* navmesh) {
		return new toy::NavmeshShape(*navmesh);
	}
	void DECL toy_NavmeshShape__destroy(toy::NavmeshShape* self) {
		delete self;
	}
	// PhysicWorld
	two::Type* DECL toy_PhysicWorld__type() {
		return &two::type<toy::PhysicWorld>();
	}
	two::vec3* DECL toy_PhysicWorld_ground_point_1(toy::PhysicWorld* self, const two::Ray* ray) {
		static two::vec3 temp;
		return (temp = self->ground_point(*ray), &temp);
	}
	toy::Collision* DECL toy_PhysicWorld_raycast_2(toy::PhysicWorld* self, const two::Ray* ray, short mask) {
		static toy::Collision temp;
		return (temp = self->raycast(*ray, mask), &temp);
	}
	toy::World* DECL toy_PhysicWorld__get_world(toy::PhysicWorld* self) {
		return &self->m_world;
	}
	void DECL toy_PhysicWorld__destroy(toy::PhysicWorld* self) {
		delete self;
	}
	// BulletMedium
	two::Type* DECL toy_BulletMedium__type() {
		return &two::type<toy::BulletMedium>();
	}
	void DECL toy_BulletMedium__destroy(toy::BulletMedium* self) {
		delete self;
	}
	// BulletWorld
	two::Type* DECL toy_BulletWorld__type() {
		return &two::type<toy::BulletWorld>();
	}
	toy::BulletWorld* DECL toy_BulletWorld__construct_1(toy::World* world) {
		return new toy::BulletWorld(*world);
	}
	void DECL toy_BulletWorld__destroy(toy::BulletWorld* self) {
		delete self;
	}
	// Core
	two::Type* DECL toy_Core__type() {
		return &two::type<toy::Core>();
	}
	void DECL toy_Core__destroy(toy::Core* self) {
		delete self;
	}
	// DefaultWorld
	two::Type* DECL toy_DefaultWorld__type() {
		return &two::type<toy::DefaultWorld>();
	}
	toy::DefaultWorld* DECL toy_DefaultWorld__construct_2(const char* name, two::JobSystem* job_system) {
		return new toy::DefaultWorld(name, *job_system);
	}
	toy::World* DECL toy_DefaultWorld__get_world(toy::DefaultWorld* self) {
		return &self->m_world;
	}
	toy::BulletWorld* DECL toy_DefaultWorld__get_bullet_world(toy::DefaultWorld* self) {
		return &self->m_bullet_world;
	}
	toy::Navmesh* DECL toy_DefaultWorld__get_navmesh(toy::DefaultWorld* self) {
		return &self->m_navmesh;
	}
	void DECL toy_DefaultWorld__destroy(toy::DefaultWorld* self) {
		delete self;
	}
	// User
	two::Type* DECL toy_User__type() {
		return &two::type<toy::User>();
	}
	void DECL toy_User__destroy(toy::User* self) {
		delete self;
	}
	// BulletShape
	two::Type* DECL toy_BulletShape__type() {
		return &two::type<toy::BulletShape>();
	}
	void DECL toy_BulletShape__destroy(toy::BulletShape* self) {
		delete self;
	}
	// BulletCollider
	two::Type* DECL toy_BulletCollider__type() {
		return &two::type<toy::BulletCollider>();
	}
	void DECL toy_BulletCollider__destroy(toy::BulletCollider* self) {
		delete self;
	}
	// BulletSolid
	two::Type* DECL toy_BulletSolid__type() {
		return &two::type<toy::BulletSolid>();
	}
	void DECL toy_BulletSolid__destroy(toy::BulletSolid* self) {
		delete self;
	}
	// PhysicScope
	two::Type* DECL toy_PhysicScope__type() {
		return &two::type<toy::PhysicScope>();
	}
	void DECL toy_PhysicScope__destroy(toy::PhysicScope* self) {
		delete self;
	}
	// EmitterScope
	two::Type* DECL toy_EmitterScope__type() {
		return &two::type<toy::EmitterScope>();
	}
	void DECL toy_EmitterScope__destroy(toy::EmitterScope* self) {
		delete self;
	}
	// ReceptorScope
	two::Type* DECL toy_ReceptorScope__type() {
		return &two::type<toy::ReceptorScope>();
	}
	void DECL toy_ReceptorScope__destroy(toy::ReceptorScope* self) {
		delete self;
	}
	// Emitter
	two::Type* DECL toy_Emitter__type() {
		return &two::type<toy::Emitter>();
	}
	toy::Emitter* DECL toy_Emitter__construct_0() {
		return new toy::Emitter();
	}
	toy::Emitter* DECL toy_Emitter__construct_1(toy::HSpatial* spatial) {
		return new toy::Emitter(*spatial);
	}
	void DECL toy_Emitter__destroy(toy::Emitter* self) {
		delete self;
	}
	// Receptor
	two::Type* DECL toy_Receptor__type() {
		return &two::type<toy::Receptor>();
	}
	toy::Receptor* DECL toy_Receptor__construct_0() {
		return new toy::Receptor();
	}
	toy::Receptor* DECL toy_Receptor__construct_1(toy::HSpatial* spatial) {
		return new toy::Receptor(*spatial);
	}
	toy::ReceptorScope* DECL toy_Receptor_scope_1(toy::Receptor* self, toy::Medium* medium) {
		return self->scope(*medium);
	}
	void DECL toy_Receptor__destroy(toy::Receptor* self) {
		delete self;
	}
	// Camera
	two::Type* DECL toy_Camera__type() {
		return &two::type<toy::Camera>();
	}
	toy::Camera* DECL toy_Camera__construct_0() {
		return new toy::Camera();
	}
	toy::Camera* DECL toy_Camera__construct_1(float distance) {
		return new toy::Camera(distance);
	}
	toy::Camera* DECL toy_Camera__construct_2(float distance, float near) {
		return new toy::Camera(distance, near);
	}
	toy::Camera* DECL toy_Camera__construct_3(float distance, float near, float far) {
		return new toy::Camera(distance, near, far);
	}
	float DECL toy_Camera__get_lens_distance(toy::Camera* self) {
		return self->m_lens_distance;
	}
	void DECL toy_Camera__set_lens_distance(toy::Camera* self, float value) {
		self->m_lens_distance = value;
	}
	float DECL toy_Camera__get_lens_angle(toy::Camera* self) {
		return self->m_lens_angle;
	}
	void DECL toy_Camera__set_lens_angle(toy::Camera* self, float value) {
		self->m_lens_angle = value;
	}
	float DECL toy_Camera__get_near(toy::Camera* self) {
		return self->m_near;
	}
	void DECL toy_Camera__set_near(toy::Camera* self, float value) {
		self->m_near = value;
	}
	float DECL toy_Camera__get_far(toy::Camera* self) {
		return self->m_far;
	}
	void DECL toy_Camera__set_far(toy::Camera* self, float value) {
		self->m_far = value;
	}
	float DECL toy_Camera__get_aspect(toy::Camera* self) {
		return self->m_aspect;
	}
	void DECL toy_Camera__set_aspect(toy::Camera* self, float value) {
		self->m_aspect = value;
	}
	void DECL toy_Camera__destroy(toy::Camera* self) {
		delete self;
	}
	// SoundMedium
	two::Type* DECL toy_SoundMedium__type() {
		return &two::type<toy::SoundMedium>();
	}
	toy::SoundMedium* DECL toy_SoundMedium__construct_0() {
		return new toy::SoundMedium();
	}
	void DECL toy_SoundMedium__destroy(toy::SoundMedium* self) {
		delete self;
	}
	// VisualMedium
	two::Type* DECL toy_VisualMedium__type() {
		return &two::type<toy::VisualMedium>();
	}
	toy::VisualMedium* DECL toy_VisualMedium__construct_0() {
		return new toy::VisualMedium();
	}
	void DECL toy_VisualMedium__destroy(toy::VisualMedium* self) {
		delete self;
	}
	// Waypoint
	two::Type* DECL toy_Waypoint__type() {
		return &two::type<toy::Waypoint>();
	}
	toy::Waypoint* DECL toy_Waypoint__construct_0() {
		return new toy::Waypoint();
	}
	void DECL toy_Waypoint__destroy(toy::Waypoint* self) {
		delete self;
	}
	// DetourPath
	two::Type* DECL toy_DetourPath__type() {
		return &two::type<toy::DetourPath>();
	}
	void DECL toy_DetourPath__destroy(toy::DetourPath* self) {
		delete self;
	}
	// Pathfinder
	two::Type* DECL toy_Pathfinder__type() {
		return &two::type<toy::Pathfinder>();
	}
	toy::Pathfinder* DECL toy_Pathfinder__construct_1(toy::Navmesh* navmesh) {
		return new toy::Pathfinder(*navmesh);
	}
	void DECL toy_Pathfinder__destroy(toy::Pathfinder* self) {
		delete self;
	}
	// Obstacle
	two::Type* DECL toy_Obstacle__type() {
		return &two::type<toy::Obstacle>();
	}
	toy::Obstacle* DECL toy_Obstacle__construct_5(toy::HSpatial* spatial, toy::HMovable* movable, toy::Medium* medium, const toy::CollisionShape* shape, float throughput) {
		return new toy::Obstacle(*spatial, *movable, *medium, *shape, throughput);
	}
	toy::CollisionShape* DECL toy_Obstacle__get_shape(toy::Obstacle* self) {
		return &self->m_shape;
	}
	float DECL toy_Obstacle__get_throughput(toy::Obstacle* self) {
		return self->m_throughput;
	}
	void DECL toy_Obstacle__set_throughput(toy::Obstacle* self, float value) {
		self->m_throughput = value;
	}
	void DECL toy_Obstacle__destroy(toy::Obstacle* self) {
		delete self;
	}
	// SolidMedium
	two::Type* DECL toy_SolidMedium__type() {
		return &two::type<toy::SolidMedium>();
	}
	toy::SolidMedium* DECL toy_SolidMedium__construct_0() {
		return new toy::SolidMedium();
	}
	void DECL toy_SolidMedium__destroy(toy::SolidMedium* self) {
		delete self;
	}
	// ComponentPool
	two::Type* DECL toy_ComponentPool__type() {
		return &two::type<toy::ComponentPool>();
	}
	void DECL toy_ComponentPool__destroy(toy::ComponentPool* self) {
		delete self;
	}
	// EntityScript
	two::Type* DECL toy_EntityScript__type() {
		return &two::type<toy::EntityScript>();
	}
	toy::EntityScript* DECL toy_EntityScript__construct_0() {
		return new toy::EntityScript();
	}
	toy::EntityScript* DECL toy_EntityScript__construct_1(toy::HSpatial* spatial) {
		return new toy::EntityScript(*spatial);
	}
	two::Script* DECL toy_EntityScript__get_logic_script(toy::EntityScript* self) {
		return self->m_logic_script;
	}
	void DECL toy_EntityScript__set_logic_script(toy::EntityScript* self, two::Script* value) {
		self->m_logic_script = value;
	}
	two::Script* DECL toy_EntityScript__get_render_script(toy::EntityScript* self) {
		return self->m_render_script;
	}
	void DECL toy_EntityScript__set_render_script(toy::EntityScript* self, two::Script* value) {
		self->m_render_script = value;
	}
	void DECL toy_EntityScript__destroy(toy::EntityScript* self) {
		delete self;
	}
	bool DECL toy_move_2d_5(toy::Spatial* spatial, toy::Movable* movable, const two::vec3* target, float velocity, float time_step) {
		return toy::move_2d(*spatial, *movable, *target, velocity, time_step);
	}
	bool DECL toy_move_2d_6(toy::Spatial* spatial, toy::Movable* movable, const two::vec3* target, float velocity, float time_step, float margin) {
		return toy::move_2d(*spatial, *movable, *target, velocity, time_step, margin);
	}
	bool DECL toy_steer_2d_5(toy::Spatial* spatial, toy::Movable* movable, const two::vec3* target, float velocity, float time_step) {
		return toy::steer_2d(*spatial, *movable, *target, velocity, time_step);
	}
	bool DECL toy_steer_2d_6(toy::Spatial* spatial, toy::Movable* movable, const two::vec3* target, float velocity, float time_step, float margin) {
		return toy::steer_2d(*spatial, *movable, *target, velocity, time_step, margin);
	}
	// CollisionGroup
	toy::CollisionGroup DECL toy_CollisionGroup_CM_NOMASK() {
		return toy::CM_NOMASK;
	}
	toy::CollisionGroup DECL toy_CollisionGroup_CM_OBJECT() {
		return toy::CM_OBJECT;
	}
	toy::CollisionGroup DECL toy_CollisionGroup_CM_SOLID() {
		return toy::CM_SOLID;
	}
	toy::CollisionGroup DECL toy_CollisionGroup_CM_GROUND() {
		return toy::CM_GROUND;
	}
	toy::CollisionGroup DECL toy_CollisionGroup_CM_AREA() {
		return toy::CM_AREA;
	}
	toy::CollisionGroup DECL toy_CollisionGroup_CM_BUFFER() {
		return toy::CM_BUFFER;
	}
	toy::CollisionGroup DECL toy_CollisionGroup_CM_LIGHT() {
		return toy::CM_LIGHT;
	}
	toy::CollisionGroup DECL toy_CollisionGroup_CM_LIGHTREFLECTOR() {
		return toy::CM_LIGHTREFLECTOR;
	}
	toy::CollisionGroup DECL toy_CollisionGroup_CM_SOURCE() {
		return toy::CM_SOURCE;
	}
	toy::CollisionGroup DECL toy_CollisionGroup_CM_RECEPTOR() {
		return toy::CM_RECEPTOR;
	}
	toy::CollisionGroup DECL toy_CollisionGroup_CM_OBSTACLE() {
		return toy::CM_OBSTACLE;
	}
	
}


