#include <type/Api.h>
#include <jobs/Api.h>
#include <ecs/Api.h>
#include <math/Api.h>
#include <geom/Api.h>
#include <lang/Api.h>
#include <util/Api.h>
#include <core/Api.h>
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
		return new toy::Camera(spatial, lens_distance, near, far);
	}
	toy::Camera* EMSCRIPTEN_KEEPALIVE Camera_Camera_2(toy::HSpatial spatial, float lens_distance) {
		return new toy::Camera(spatial, lens_distance, near, far);
	}
	toy::Camera* EMSCRIPTEN_KEEPALIVE Camera_Camera_3(toy::HSpatial spatial, float lens_distance, float near) {
		return new toy::Camera(spatial, lens_distance, near, far);
	}
	toy::Camera* EMSCRIPTEN_KEEPALIVE Camera_Camera_4(toy::HSpatial spatial, float lens_distance, float near, float far) {
		return new toy::Camera(spatial, lens_distance, near, far);
	}
	float EMSCRIPTEN_KEEPALIVE Camera_get_lens_distance(toy::Camera* self) {
		return self->m_lens_distance;
	}
	float EMSCRIPTEN_KEEPALIVE Camera_get_lens_angle(toy::Camera* self) {
		return self->m_lens_angle;
	}
	float EMSCRIPTEN_KEEPALIVE Camera_get_near(toy::Camera* self) {
		return self->m_near;
	}
	float EMSCRIPTEN_KEEPALIVE Camera_get_far(toy::Camera* self) {
		return self->m_far;
	}
	float EMSCRIPTEN_KEEPALIVE Camera_get_aspect(toy::Camera* self) {
		return self->m_aspect;
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
	toy::HMovable EMSCRIPTEN_KEEPALIVE Collider_get_movable(toy::Collider* self) {
		return self->m_movable;
	}
	toy::CollisionShape* EMSCRIPTEN_KEEPALIVE Collider_get_collision_shape(toy::Collider* self) {
		static toy::CollisionShape temp;
		return (temp = &self->m_collision_shape, &temp);
	}
	toy::Medium* EMSCRIPTEN_KEEPALIVE Collider_get_medium(toy::Collider* self) {
		return self->m_medium;
	}
	toy::CollisionGroup EMSCRIPTEN_KEEPALIVE Collider_get_group(toy::Collider* self) {
		static toy::CollisionGroup temp;
		return (temp = &self->m_group, &temp);
	}
	toy::ColliderObject* EMSCRIPTEN_KEEPALIVE Collider_get_object(toy::Collider* self) {
		return self->m_object;
	}
	toy::ColliderImpl* EMSCRIPTEN_KEEPALIVE Collider_get_impl(toy::Collider* self) {
		return &&self->impl;
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
	toy::HCollider EMSCRIPTEN_KEEPALIVE Collision_get_second(toy::Collision* self) {
		return self->m_second;
	}
	mud::vec3* EMSCRIPTEN_KEEPALIVE Collision_get_hit_point(toy::Collision* self) {
		static mud::vec3 temp;
		return (temp = &self->m_hit_point, &temp);
	}
	void EMSCRIPTEN_KEEPALIVE Collision___destroy__(toy::Collision* self) {
		delete self;
	}
	// CollisionShape
	toy::CollisionShape* EMSCRIPTEN_KEEPALIVE CollisionShape_CollisionShape_0() {
		return new toy::CollisionShape();
	}
	toy::CollisionShape* EMSCRIPTEN_KEEPALIVE CollisionShape_CollisionShape_1(const mud::Shape* shape) {
		return new toy::CollisionShape(*shape, *center, margin);
	}
	toy::CollisionShape* EMSCRIPTEN_KEEPALIVE CollisionShape_CollisionShape_2(const mud::Shape* shape, const mud::vec3* center) {
		return new toy::CollisionShape(*shape, *center, margin);
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
	mud::Script* EMSCRIPTEN_KEEPALIVE EntityScript_get_render_script(toy::EntityScript* self) {
		return self->m_render_script;
	}
	void EMSCRIPTEN_KEEPALIVE EntityScript___destroy__(toy::EntityScript* self) {
		delete self;
	}
	// Medium
	std::string EMSCRIPTEN_KEEPALIVE Medium_get_name(toy::Medium* self) {
		return self->m_name;
	}
	bool EMSCRIPTEN_KEEPALIVE Medium_get_occlusions(toy::Medium* self) {
		return self->m_occlusions;
	}
	bool EMSCRIPTEN_KEEPALIVE Medium_get_solid(toy::Medium* self) {
		return self->m_solid;
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
	void EMSCRIPTEN_KEEPALIVE Movable_set_linear_velocity_1(toy::Movable* self, const mud::vec3* velocity) {
		self->set_linear_velocity(*velocity);
	}
	void EMSCRIPTEN_KEEPALIVE Movable_modify_linear_velocity_1(toy::Movable* self, const mud::vec3* velocity) {
		self->modify_linear_velocity(*velocity);
	}
	void EMSCRIPTEN_KEEPALIVE Movable_set_angular_velocity_1(toy::Movable* self, const mud::vec3* velocity) {
		self->set_angular_velocity(*velocity);
	}
	void EMSCRIPTEN_KEEPALIVE Movable_modify_angular_velocity_1(toy::Movable* self, const mud::vec3* velocity) {
		self->modify_angular_velocity(*velocity);
	}
	mud::vec3* EMSCRIPTEN_KEEPALIVE Movable_get_linear_velocity(toy::Movable* self) {
		static mud::vec3 temp;
		return (temp = &self->m_linear_velocity, &temp);
	}
	mud::vec3* EMSCRIPTEN_KEEPALIVE Movable_get_angular_velocity(toy::Movable* self) {
		static mud::vec3 temp;
		return (temp = &self->m_angular_velocity, &temp);
	}
	bool EMSCRIPTEN_KEEPALIVE Movable_get_moving(toy::Movable* self) {
		return self->m_moving;
	}
	mud::vec3* EMSCRIPTEN_KEEPALIVE Movable_get_previous_position(toy::Movable* self) {
		static mud::vec3 temp;
		return (temp = &self->m_previous_position, &temp);
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
	bool EMSCRIPTEN_KEEPALIVE Navblock_get_auto_update(toy::Navblock* self) {
		return self->m_auto_update;
	}
	size_t EMSCRIPTEN_KEEPALIVE Navblock_get_updated(toy::Navblock* self) {
		return self->m_updated;
	}
	void EMSCRIPTEN_KEEPALIVE Navblock___destroy__(toy::Navblock* self) {
		delete self;
	}
	// Navmesh
	toy::Navmesh* EMSCRIPTEN_KEEPALIVE Navmesh_Navmesh_1(toy::World* world) {
		return new toy::Navmesh(*world);
	}
	toy::World* EMSCRIPTEN_KEEPALIVE Navmesh_get_world(toy::Navmesh* self) {
		return &&self->m_world;
	}
	size_t EMSCRIPTEN_KEEPALIVE Navmesh_get_updated(toy::Navmesh* self) {
		return self->m_updated;
	}
	bool EMSCRIPTEN_KEEPALIVE Navmesh_get_dirty(toy::Navmesh* self) {
		return self->m_dirty;
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
		return &&self->m_world;
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
	toy::Solid* EMSCRIPTEN_KEEPALIVE Solid_Solid_0() {
		return new toy::Solid();
	}
	toy::Solid* EMSCRIPTEN_KEEPALIVE Solid_Solid_4(toy::HSpatial spatial, toy::HMovable movable, toy::OCollider collider, bool isstatic) {
		return new toy::Solid(spatial, movable, collider, isstatic, mass);
	}
	toy::Solid* EMSCRIPTEN_KEEPALIVE Solid_Solid_5(toy::HSpatial spatial, toy::HMovable movable, toy::OCollider collider, bool isstatic, float mass) {
		return new toy::Solid(spatial, movable, collider, isstatic, mass);
	}
	toy::HSpatial EMSCRIPTEN_KEEPALIVE Solid_get_spatial(toy::Solid* self) {
		return self->m_spatial;
	}
	toy::OCollider EMSCRIPTEN_KEEPALIVE Solid_get_collider(toy::Solid* self) {
		return self->m_collider;
	}
	bool EMSCRIPTEN_KEEPALIVE Solid_get_static(toy::Solid* self) {
		return self->m_static;
	}
	float EMSCRIPTEN_KEEPALIVE Solid_get_mass(toy::Solid* self) {
		return self->m_mass;
	}
	void EMSCRIPTEN_KEEPALIVE Solid___destroy__(toy::Solid* self) {
		delete self;
	}
	// SolidImpl
	mud::vec3* EMSCRIPTEN_KEEPALIVE SolidImpl_linear_velocity_0(toy::SolidImpl* self) {
		static mud::vec3 temp;
		return (temp = self->linear_velocity(), &temp);
	}
	mud::vec3* EMSCRIPTEN_KEEPALIVE SolidImpl_angular_velocity_0(toy::SolidImpl* self) {
		static mud::vec3 temp;
		return (temp = self->angular_velocity(), &temp);
	}
	void EMSCRIPTEN_KEEPALIVE SolidImpl_set_linear_velocity_1(toy::SolidImpl* self, const mud::vec3* force) {
		self->set_linear_velocity(*force);
	}
	void EMSCRIPTEN_KEEPALIVE SolidImpl_set_angular_velocity_1(toy::SolidImpl* self, const mud::vec3* torque) {
		self->set_angular_velocity(*torque);
	}
	void EMSCRIPTEN_KEEPALIVE SolidImpl_set_angular_factor_1(toy::SolidImpl* self, const mud::vec3* factor) {
		self->set_angular_factor(*factor);
	}
	void EMSCRIPTEN_KEEPALIVE SolidImpl_impulse_2(toy::SolidImpl* self, const mud::vec3* force, const mud::vec3* point) {
		self->impulse(*force, *point);
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
	toy::World* EMSCRIPTEN_KEEPALIVE World_World_4(mud::Id id, mud::Complex* complex, const std::string name, mud::JobSystem* job_system) {
		return new toy::World(id, *complex, *name, *job_system);
	}
	mud::Id EMSCRIPTEN_KEEPALIVE World_get_id(toy::World* self) {
		return self->m_id;
	}
	mud::Complex* EMSCRIPTEN_KEEPALIVE World_get_complex(toy::World* self) {
		return &&self->m_complex;
	}
	std::string EMSCRIPTEN_KEEPALIVE World_get_name(toy::World* self) {
		return self->m_name;
	}
	toy::HSpatial EMSCRIPTEN_KEEPALIVE World_get_origin(toy::World* self) {
		return self->origin;
	}
	toy::HSpatial EMSCRIPTEN_KEEPALIVE World_get_unworld(toy::World* self) {
		return self->unworld;
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
	void EMSCRIPTEN_KEEPALIVE WorldPage_update_geometry_0(toy::WorldPage* self) {
		self->update_geometry();
	}
	void EMSCRIPTEN_KEEPALIVE WorldPage_ground_point_3(toy::WorldPage* self, const mud::vec3* position, bool relative, mud::vec3* outputPoint) {
		self->ground_point(*position, relative, *outputPoint);
	}
	void EMSCRIPTEN_KEEPALIVE WorldPage_raycast_ground_3(toy::WorldPage* self, const mud::vec3* from, const mud::vec3* to, mud::vec3* ground_point) {
		self->raycast_ground(*from, *to, *ground_point);
	}
	bool EMSCRIPTEN_KEEPALIVE WorldPage_get_open(toy::WorldPage* self) {
		return self->m_open;
	}
	mud::vec3* EMSCRIPTEN_KEEPALIVE WorldPage_get_extents(toy::WorldPage* self) {
		static mud::vec3 temp;
		return (temp = &self->m_extents, &temp);
	}
	toy::World* EMSCRIPTEN_KEEPALIVE WorldPage_get_world(toy::WorldPage* self) {
		return self->m_world;
	}
	size_t EMSCRIPTEN_KEEPALIVE WorldPage_get_last_rebuilt(toy::WorldPage* self) {
		return self->m_last_rebuilt;
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
	toy::DefaultWorld* EMSCRIPTEN_KEEPALIVE DefaultWorld_DefaultWorld_2(const std::string name, mud::JobSystem* job_system) {
		return new toy::DefaultWorld(*name, *job_system);
	}
	toy::World* EMSCRIPTEN_KEEPALIVE DefaultWorld_get_world(toy::DefaultWorld* self) {
		static toy::World temp;
		return (temp = &self->m_world, &temp);
	}
	toy::BulletWorld* EMSCRIPTEN_KEEPALIVE DefaultWorld_get_bullet_world(toy::DefaultWorld* self) {
		static toy::BulletWorld temp;
		return (temp = &self->m_bullet_world, &temp);
	}
	toy::Navmesh* EMSCRIPTEN_KEEPALIVE DefaultWorld_get_navmesh(toy::DefaultWorld* self) {
		static toy::Navmesh temp;
		return (temp = &self->m_navmesh, &temp);
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
		static toy::CollisionShape temp;
		return (temp = &self->m_shape, &temp);
	}
	float EMSCRIPTEN_KEEPALIVE Obstacle_get_throughput(toy::Obstacle* self) {
		return self->m_throughput;
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
	toy::Spatial* EMSCRIPTEN_KEEPALIVE Spatial_Spatial_4(toy::World* world, toy::HSpatial parent, const mud::vec3* position, const mud::quat* rotation) {
		return new toy::Spatial(*world, parent, *position, *rotation);
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
	toy::HSpatial EMSCRIPTEN_KEEPALIVE Spatial_get_parent(toy::Spatial* self) {
		return self->m_parent;
	}
	std::vector<toy::HSpatial>* EMSCRIPTEN_KEEPALIVE Spatial_get_contents(toy::Spatial* self) {
		static std::vector<toy::HSpatial> temp;
		return (temp = &self->m_contents, &temp);
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
	toy::CollisionGroup EMSCRIPTEN_KEEPALIVE emscripten_enum_CollisionGroup_CM_NOMASK() {
		return toy::CM_NOMASK;
	}
	toy::CollisionGroup EMSCRIPTEN_KEEPALIVE emscripten_enum_CollisionGroup_CM_OBJECT() {
		return toy::CM_OBJECT;
	}
	toy::CollisionGroup EMSCRIPTEN_KEEPALIVE emscripten_enum_CollisionGroup_CM_SOLID() {
		return toy::CM_SOLID;
	}
	toy::CollisionGroup EMSCRIPTEN_KEEPALIVE emscripten_enum_CollisionGroup_CM_GROUND() {
		return toy::CM_GROUND;
	}
	toy::CollisionGroup EMSCRIPTEN_KEEPALIVE emscripten_enum_CollisionGroup_CM_AREA() {
		return toy::CM_AREA;
	}
	toy::CollisionGroup EMSCRIPTEN_KEEPALIVE emscripten_enum_CollisionGroup_CM_BUFFER() {
		return toy::CM_BUFFER;
	}
	toy::CollisionGroup EMSCRIPTEN_KEEPALIVE emscripten_enum_CollisionGroup_CM_LIGHT() {
		return toy::CM_LIGHT;
	}
	toy::CollisionGroup EMSCRIPTEN_KEEPALIVE emscripten_enum_CollisionGroup_CM_LIGHTREFLECTOR() {
		return toy::CM_LIGHTREFLECTOR;
	}
	toy::CollisionGroup EMSCRIPTEN_KEEPALIVE emscripten_enum_CollisionGroup_CM_SOURCE() {
		return toy::CM_SOURCE;
	}
	toy::CollisionGroup EMSCRIPTEN_KEEPALIVE emscripten_enum_CollisionGroup_CM_RECEPTOR() {
		return toy::CM_RECEPTOR;
	}
	toy::CollisionGroup EMSCRIPTEN_KEEPALIVE emscripten_enum_CollisionGroup_CM_OBSTACLE() {
		return toy::CM_OBSTACLE;
	}
	
}


