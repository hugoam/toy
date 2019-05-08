#include <two/jobs.refl.h>
#include <two/lang.refl.h>
#include <toy/core.refl.h>
#include <two/geom.refl.h>
#include <toy/core.h>
#include <two/type.refl.h>
#include <two/refl.h>
#include <two/math.refl.h>
#include <toy/util.refl.h>
#include <two/infra.h>
#include <two/type.h>
#include <two/ecs.refl.h>


#ifdef TWO_MODULES
module toy.core;
#else
#include <cstddef>
#include <stl/new.h>
#endif


using namespace two;

void toy_CollisionGroup__to_string(void* val, string& str) { str = g_enu[type<toy::CollisionGroup>().m_id]->name(uint32_t((*static_cast<toy::CollisionGroup*>(val)))); }
void toy_CollisionGroup__to_value(const string& str, void* val) { (*static_cast<toy::CollisionGroup*>(val)) = toy::CollisionGroup(g_enu[type<toy::CollisionGroup>().m_id]->value(str.c_str())); }
size_t stl_vector_toy_HSpatial__size(void* vec) { return (*static_cast<stl::vector<toy::HSpatial>*>(vec)).size(); }
void* stl_vector_toy_HSpatial__at(void* vec, size_t i) { return &(*static_cast<stl::vector<toy::HSpatial>*>(vec))[i]; }
void stl_vector_toy_HSpatial__push(void* vec) { (*static_cast<stl::vector<toy::HSpatial>*>(vec)).emplace_back(); }
void stl_vector_toy_HSpatial__add(void* vec, void* value) { (*static_cast<stl::vector<toy::HSpatial>*>(vec)).push_back(*static_cast<toy::HSpatial*>(value)); }
void stl_vector_toy_HSpatial__remove(void* vec, void* value) { vector_remove_any((*static_cast<stl::vector<toy::HSpatial>*>(vec)), *static_cast<toy::HSpatial*>(value)); }
void two_OwnedHandle_toy_Collider__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) two::OwnedHandle<toy::Collider>(  ); }
void two_OwnedHandle_toy_Solid__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) two::OwnedHandle<toy::Solid>(  ); }
void two_SparseHandle_toy_Collider__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) two::SparseHandle<toy::Collider>(  ); }
void two_SparseHandle_toy_Collider__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) two::SparseHandle<toy::Collider>((*static_cast<two::SparseHandle<toy::Collider>*>(other))); }
void two_SparseHandle_toy_Solid__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) two::SparseHandle<toy::Solid>(  ); }
void two_SparseHandle_toy_Solid__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) two::SparseHandle<toy::Solid>((*static_cast<two::SparseHandle<toy::Solid>*>(other))); }
void two_ComponentHandle_toy_Spatial__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) two::ComponentHandle<toy::Spatial>(  ); }
void two_ComponentHandle_toy_Spatial__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) two::ComponentHandle<toy::Spatial>((*static_cast<two::ComponentHandle<toy::Spatial>*>(other))); }
void two_ComponentHandle_toy_Movable__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) two::ComponentHandle<toy::Movable>(  ); }
void two_ComponentHandle_toy_Movable__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) two::ComponentHandle<toy::Movable>((*static_cast<two::ComponentHandle<toy::Movable>*>(other))); }
void two_ComponentHandle_toy_Camera__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) two::ComponentHandle<toy::Camera>(  ); }
void two_ComponentHandle_toy_Camera__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) two::ComponentHandle<toy::Camera>((*static_cast<two::ComponentHandle<toy::Camera>*>(other))); }
void two_ComponentHandle_toy_Emitter__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) two::ComponentHandle<toy::Emitter>(  ); }
void two_ComponentHandle_toy_Emitter__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) two::ComponentHandle<toy::Emitter>((*static_cast<two::ComponentHandle<toy::Emitter>*>(other))); }
void two_ComponentHandle_toy_Receptor__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) two::ComponentHandle<toy::Receptor>(  ); }
void two_ComponentHandle_toy_Receptor__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) two::ComponentHandle<toy::Receptor>((*static_cast<two::ComponentHandle<toy::Receptor>*>(other))); }
void two_ComponentHandle_toy_EntityScript__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) two::ComponentHandle<toy::EntityScript>(  ); }
void two_ComponentHandle_toy_EntityScript__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) two::ComponentHandle<toy::EntityScript>((*static_cast<two::ComponentHandle<toy::EntityScript>*>(other))); }
void two_ComponentHandle_toy_WorldPage__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) two::ComponentHandle<toy::WorldPage>(  ); }
void two_ComponentHandle_toy_WorldPage__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) two::ComponentHandle<toy::WorldPage>((*static_cast<two::ComponentHandle<toy::WorldPage>*>(other))); }
void two_ComponentHandle_toy_Navblock__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) two::ComponentHandle<toy::Navblock>(  ); }
void two_ComponentHandle_toy_Navblock__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) two::ComponentHandle<toy::Navblock>((*static_cast<two::ComponentHandle<toy::Navblock>*>(other))); }
void two_ComponentHandle_toy_Origin__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) two::ComponentHandle<toy::Origin>(  ); }
void two_ComponentHandle_toy_Origin__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) two::ComponentHandle<toy::Origin>((*static_cast<two::ComponentHandle<toy::Origin>*>(other))); }
void two_ComponentHandle_toy_Waypoint__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) two::ComponentHandle<toy::Waypoint>(  ); }
void two_ComponentHandle_toy_Waypoint__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) two::ComponentHandle<toy::Waypoint>((*static_cast<two::ComponentHandle<toy::Waypoint>*>(other))); }
void toy_Spatial__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) toy::Spatial(  ); }
void toy_Spatial__construct_1(void* ref, span<void*> args) { new(stl::placeholder(), ref) toy::Spatial( *static_cast<toy::HSpatial*>(args[0]), *static_cast<two::vec3*>(args[1]), *static_cast<two::quat*>(args[2]) ); }
void toy_Spatial__construct_2(void* ref, span<void*> args) { new(stl::placeholder(), ref) toy::Spatial( *static_cast<toy::World*>(args[0]), *static_cast<toy::HSpatial*>(args[1]), *static_cast<two::vec3*>(args[2]), *static_cast<two::quat*>(args[3]) ); }
void toy_Spatial_set_position(void* object, span<void*> args, void*& result) { UNUSED(result); (*static_cast<toy::Spatial*>(object)).set_position(*static_cast<two::vec3*>(args[0])); }
void toy_Spatial_set_rotation(void* object, span<void*> args, void*& result) { UNUSED(result); (*static_cast<toy::Spatial*>(object)).set_rotation(*static_cast<two::quat*>(args[0])); }
void toy_Origin__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) toy::Origin(  ); }
void toy_World__construct_0(void* ref, span<void*> args) { new(stl::placeholder(), ref) toy::World( *static_cast<uint32_t*>(args[0]), *static_cast<two::Complex*>(args[1]), *static_cast<stl::string*>(args[2]), *static_cast<two::JobSystem*>(args[3]) ); }
void* toy_World__get_complex(void* object) { return &(*static_cast<toy::World*>(object)).m_complex; }
void* toy_World__get_origin(void* object) { return &(*static_cast<toy::World*>(object)).origin(); }
void* toy_World__get_unworld(void* object) { return &(*static_cast<toy::World*>(object)).unworld(); }
void toy_CollisionShape__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) toy::CollisionShape(  ); }
void toy_CollisionShape__construct_1(void* ref, span<void*> args) { new(stl::placeholder(), ref) toy::CollisionShape( *static_cast<two::Shape*>(args[0]), *static_cast<two::vec3*>(args[1]), *static_cast<float*>(args[2]) ); }
void toy_Movable__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) toy::Movable(  ); }
void toy_Movable__construct_1(void* ref, span<void*> args) { new(stl::placeholder(), ref) toy::Movable( *static_cast<two::vec3*>(args[0]) ); }
void toy_Movable_set_linear_velocity(void* object, span<void*> args, void*& result) { UNUSED(result); (*static_cast<toy::Movable*>(object)).set_linear_velocity(*static_cast<two::vec3*>(args[0])); }
void toy_Movable_modify_linear_velocity(void* object, span<void*> args, void*& result) { UNUSED(result); (*static_cast<toy::Movable*>(object)).modify_linear_velocity(*static_cast<two::vec3*>(args[0])); }
void toy_Movable_set_angular_velocity(void* object, span<void*> args, void*& result) { UNUSED(result); (*static_cast<toy::Movable*>(object)).set_angular_velocity(*static_cast<two::vec3*>(args[0])); }
void toy_Movable_modify_angular_velocity(void* object, span<void*> args, void*& result) { UNUSED(result); (*static_cast<toy::Movable*>(object)).modify_angular_velocity(*static_cast<two::vec3*>(args[0])); }
void toy_Collision__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) toy::Collision(  ); }
void toy_Collision__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) toy::Collision((*static_cast<toy::Collision*>(other))); }
void toy_Collider__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) toy::Collider(  ); }
void toy_Collider__construct_1(void* ref, span<void*> args) { new(stl::placeholder(), ref) toy::Collider( *static_cast<toy::HSpatial*>(args[0]), *static_cast<toy::HMovable*>(args[1]), *static_cast<toy::CollisionShape*>(args[2]), *static_cast<toy::Medium*>(args[3]), *static_cast<toy::CollisionGroup*>(args[4]) ); }
void* toy_Collider__get_impl(void* object) { return &(*static_cast<toy::Collider*>(object)).impl(); }
void toy_SolidImpl_linear_velocity(void* object, span<void*> args, void*& result) { UNUSED(args); (*static_cast<two::v3<float>*>(result)) = (*static_cast<toy::SolidImpl*>(object)).linear_velocity(); }
void toy_SolidImpl_angular_velocity(void* object, span<void*> args, void*& result) { UNUSED(args); (*static_cast<two::v3<float>*>(result)) = (*static_cast<toy::SolidImpl*>(object)).angular_velocity(); }
void toy_SolidImpl_set_linear_velocity(void* object, span<void*> args, void*& result) { UNUSED(result); (*static_cast<toy::SolidImpl*>(object)).set_linear_velocity(*static_cast<two::vec3*>(args[0])); }
void toy_SolidImpl_set_angular_velocity(void* object, span<void*> args, void*& result) { UNUSED(result); (*static_cast<toy::SolidImpl*>(object)).set_angular_velocity(*static_cast<two::vec3*>(args[0])); }
void toy_SolidImpl_set_angular_factor(void* object, span<void*> args, void*& result) { UNUSED(result); (*static_cast<toy::SolidImpl*>(object)).set_angular_factor(*static_cast<two::vec3*>(args[0])); }
void toy_SolidImpl_impulse(void* object, span<void*> args, void*& result) { UNUSED(result); (*static_cast<toy::SolidImpl*>(object)).impulse(*static_cast<two::vec3*>(args[0]), *static_cast<two::vec3*>(args[1])); }
void toy_WorldMedium__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) toy::WorldMedium(  ); }
void toy_WorldPage__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) toy::WorldPage(  ); }
void toy_WorldPage__construct_1(void* ref, span<void*> args) { new(stl::placeholder(), ref) toy::WorldPage( *static_cast<toy::HSpatial*>(args[0]), *static_cast<bool*>(args[1]), *static_cast<two::vec3*>(args[2]) ); }
void toy_WorldPage_update_geometry(void* object, span<void*> args, void*& result) { UNUSED(result); (*static_cast<toy::WorldPage*>(object)).update_geometry(*static_cast<size_t*>(args[0])); }
void toy_WorldPage_ground_point(void* object, span<void*> args, void*& result) { UNUSED(result); (*static_cast<toy::WorldPage*>(object)).ground_point(*static_cast<two::vec3*>(args[0]), *static_cast<bool*>(args[1]), *static_cast<two::vec3*>(args[2])); }
void toy_WorldPage_raycast_ground(void* object, span<void*> args, void*& result) { UNUSED(result); (*static_cast<toy::WorldPage*>(object)).raycast_ground(*static_cast<two::vec3*>(args[0]), *static_cast<two::vec3*>(args[1]), *static_cast<two::vec3*>(args[2])); }
void toy_Navmesh__construct_0(void* ref, span<void*> args) { new(stl::placeholder(), ref) toy::Navmesh( *static_cast<toy::World*>(args[0]) ); }
void* toy_Navmesh__get_world(void* object) { return &(*static_cast<toy::Navmesh*>(object)).m_world; }
void toy_Navblock__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) toy::Navblock(  ); }
void toy_Navblock__construct_1(void* ref, span<void*> args) { new(stl::placeholder(), ref) toy::Navblock( *static_cast<toy::HSpatial*>(args[0]), *static_cast<toy::HWorldPage*>(args[1]), *static_cast<toy::Navmesh*>(args[2]) ); }
void toy_NavmeshShape__construct_0(void* ref, span<void*> args) { new(stl::placeholder(), ref) toy::NavmeshShape( *static_cast<toy::Navmesh*>(args[0]) ); }
void* toy_PhysicWorld__get_world(void* object) { return &(*static_cast<toy::PhysicWorld*>(object)).m_world; }
void toy_PhysicWorld_ground_point(void* object, span<void*> args, void*& result) { (*static_cast<two::v3<float>*>(result)) = (*static_cast<toy::PhysicWorld*>(object)).ground_point(*static_cast<two::Ray*>(args[0])); }
void toy_PhysicWorld_raycast(void* object, span<void*> args, void*& result) { (*static_cast<toy::Collision*>(result)) = (*static_cast<toy::PhysicWorld*>(object)).raycast(*static_cast<two::Ray*>(args[0]), *static_cast<short*>(args[1])); }
void toy_BulletWorld__construct_0(void* ref, span<void*> args) { new(stl::placeholder(), ref) toy::BulletWorld( *static_cast<toy::World*>(args[0]) ); }
void toy_DefaultWorld__construct_0(void* ref, span<void*> args) { new(stl::placeholder(), ref) toy::DefaultWorld( *static_cast<stl::string*>(args[0]), *static_cast<two::JobSystem*>(args[1]) ); }
void toy_Emitter__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) toy::Emitter(  ); }
void toy_Emitter__construct_1(void* ref, span<void*> args) { new(stl::placeholder(), ref) toy::Emitter( *static_cast<toy::HSpatial*>(args[0]) ); }
void toy_Receptor__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) toy::Receptor(  ); }
void toy_Receptor__construct_1(void* ref, span<void*> args) { new(stl::placeholder(), ref) toy::Receptor( *static_cast<toy::HSpatial*>(args[0]) ); }
void toy_Receptor_scope(void* object, span<void*> args, void*& result) { result = (*static_cast<toy::Receptor*>(object)).scope(*static_cast<toy::Medium*>(args[0])); }
void toy_Camera__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) toy::Camera(  ); }
void toy_Camera__construct_1(void* ref, span<void*> args) { new(stl::placeholder(), ref) toy::Camera( *static_cast<float*>(args[0]), *static_cast<float*>(args[1]), *static_cast<float*>(args[2]) ); }
void toy_SoundMedium__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) toy::SoundMedium(  ); }
void toy_VisualMedium__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) toy::VisualMedium(  ); }
void toy_Waypoint__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) toy::Waypoint(  ); }
void toy_Pathfinder__construct_0(void* ref, span<void*> args) { new(stl::placeholder(), ref) toy::Pathfinder( *static_cast<toy::Navmesh*>(args[0]) ); }
void toy_Obstacle__construct_0(void* ref, span<void*> args) { new(stl::placeholder(), ref) toy::Obstacle( *static_cast<toy::HSpatial*>(args[0]), *static_cast<toy::HMovable*>(args[1]), *static_cast<toy::Medium*>(args[2]), *static_cast<toy::CollisionShape*>(args[3]), *static_cast<float*>(args[4]) ); }
void toy_SolidMedium__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) toy::SolidMedium(  ); }
void toy_EntityScript__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) toy::EntityScript(  ); }
void toy_EntityScript__construct_1(void* ref, span<void*> args) { new(stl::placeholder(), ref) toy::EntityScript( *static_cast<toy::HSpatial*>(args[0]) ); }
void toy_move_2d_0(span<void*> args, void*& result) { (*static_cast<bool*>(result)) = toy::move_2d(*static_cast<toy::Spatial*>(args[0]), *static_cast<toy::Movable*>(args[1]), *static_cast<two::vec3*>(args[2]), *static_cast<float*>(args[3]), *static_cast<float*>(args[4]), *static_cast<float*>(args[5])); }
void toy_steer_2d_1(span<void*> args, void*& result) { (*static_cast<bool*>(result)) = toy::steer_2d(*static_cast<toy::Spatial*>(args[0]), *static_cast<toy::Movable*>(args[1]), *static_cast<two::vec3*>(args[2]), *static_cast<float*>(args[3]), *static_cast<float*>(args[4]), *static_cast<float*>(args[5])); }

namespace two
{
	void toy_core_meta(Module& m)
	{
	UNUSED(m);
	
	// Base Types
	
	// Enums
	{
		Type& t = type<toy::CollisionGroup>();
		static Meta meta = { t, &namspc({ "toy" }), "CollisionGroup", sizeof(toy::CollisionGroup), TypeClass::Enum };
		static cstring ids[] = { "CM_NOMASK", "CM_OBJECT", "CM_SOLID", "CM_GROUND", "CM_AREA", "CM_BUFFER", "CM_LIGHT", "CM_LIGHTREFLECTOR", "CM_SOURCE", "CM_RECEPTOR", "CM_OBSTACLE" };
		static uint32_t values[] = { 0, 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };
		static toy::CollisionGroup vars[] = { toy::CM_NOMASK, toy::CM_OBJECT, toy::CM_SOLID, toy::CM_GROUND, toy::CM_AREA, toy::CM_BUFFER, toy::CM_LIGHT, toy::CM_LIGHTREFLECTOR, toy::CM_SOURCE, toy::CM_RECEPTOR, toy::CM_OBSTACLE};
		static void* refs[] = { &vars[0], &vars[1], &vars[2], &vars[3], &vars[4], &vars[5], &vars[6], &vars[7], &vars[8], &vars[9], &vars[10]};
		static Enum enu = { t, false, ids, values, refs };
		static Convert convert = { toy_CollisionGroup__to_string,
		                           toy_CollisionGroup__to_value };
		g_convert[t.m_id] = &convert;
	}
	
	// Sequences
	{
		Type& t = type<stl::vector<toy::HSpatial>>();
		static Meta meta = { t, &namspc({ "stl" }), "vector<toy::HSpatial>", sizeof(stl::vector<toy::HSpatial>), TypeClass::Sequence };
		static Class cls = { t };
		static Iterable iterable = { &type<toy::HSpatial>(),
		                             stl_vector_toy_HSpatial__size,
		                             stl_vector_toy_HSpatial__at};
		g_iterable[t.m_id] = &iterable;
		static Sequence sequence = { stl_vector_toy_HSpatial__push,
		                             stl_vector_toy_HSpatial__add,
		                             stl_vector_toy_HSpatial__remove };
		g_sequence[t.m_id] = &sequence;
	}
	
	// two::OwnedHandle<toy::Collider>
	{
		Type& t = type<two::OwnedHandle<toy::Collider>>();
		static Meta meta = { t, &namspc({ "two" }), "OwnedHandle<toy::Collider>", sizeof(two::OwnedHandle<toy::Collider>), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, two_OwnedHandle_toy_Collider__construct_0, {} }
		};
		// copy constructor
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, {}, {}, {}, {}, };
	}
	// two::OwnedHandle<toy::Solid>
	{
		Type& t = type<two::OwnedHandle<toy::Solid>>();
		static Meta meta = { t, &namspc({ "two" }), "OwnedHandle<toy::Solid>", sizeof(two::OwnedHandle<toy::Solid>), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, two_OwnedHandle_toy_Solid__construct_0, {} }
		};
		// copy constructor
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, {}, {}, {}, {}, };
	}
	// two::SparseHandle<toy::Collider>
	{
		Type& t = type<two::SparseHandle<toy::Collider>>();
		static Meta meta = { t, &namspc({ "two" }), "SparseHandle<toy::Collider>", sizeof(two::SparseHandle<toy::Collider>), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, two_SparseHandle_toy_Collider__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, two_SparseHandle_toy_Collider__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
	}
	// two::SparseHandle<toy::Solid>
	{
		Type& t = type<two::SparseHandle<toy::Solid>>();
		static Meta meta = { t, &namspc({ "two" }), "SparseHandle<toy::Solid>", sizeof(two::SparseHandle<toy::Solid>), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, two_SparseHandle_toy_Solid__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, two_SparseHandle_toy_Solid__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
	}
	// two::ComponentHandle<toy::Spatial>
	{
		Type& t = type<two::ComponentHandle<toy::Spatial>>();
		static Meta meta = { t, &namspc({ "two" }), "ComponentHandle<toy::Spatial>", sizeof(two::ComponentHandle<toy::Spatial>), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, two_ComponentHandle_toy_Spatial__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, two_ComponentHandle_toy_Spatial__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
	}
	// two::ComponentHandle<toy::Movable>
	{
		Type& t = type<two::ComponentHandle<toy::Movable>>();
		static Meta meta = { t, &namspc({ "two" }), "ComponentHandle<toy::Movable>", sizeof(two::ComponentHandle<toy::Movable>), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, two_ComponentHandle_toy_Movable__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, two_ComponentHandle_toy_Movable__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
	}
	// two::ComponentHandle<toy::Camera>
	{
		Type& t = type<two::ComponentHandle<toy::Camera>>();
		static Meta meta = { t, &namspc({ "two" }), "ComponentHandle<toy::Camera>", sizeof(two::ComponentHandle<toy::Camera>), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, two_ComponentHandle_toy_Camera__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, two_ComponentHandle_toy_Camera__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
	}
	// two::ComponentHandle<toy::Emitter>
	{
		Type& t = type<two::ComponentHandle<toy::Emitter>>();
		static Meta meta = { t, &namspc({ "two" }), "ComponentHandle<toy::Emitter>", sizeof(two::ComponentHandle<toy::Emitter>), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, two_ComponentHandle_toy_Emitter__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, two_ComponentHandle_toy_Emitter__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
	}
	// two::ComponentHandle<toy::Receptor>
	{
		Type& t = type<two::ComponentHandle<toy::Receptor>>();
		static Meta meta = { t, &namspc({ "two" }), "ComponentHandle<toy::Receptor>", sizeof(two::ComponentHandle<toy::Receptor>), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, two_ComponentHandle_toy_Receptor__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, two_ComponentHandle_toy_Receptor__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
	}
	// two::ComponentHandle<toy::EntityScript>
	{
		Type& t = type<two::ComponentHandle<toy::EntityScript>>();
		static Meta meta = { t, &namspc({ "two" }), "ComponentHandle<toy::EntityScript>", sizeof(two::ComponentHandle<toy::EntityScript>), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, two_ComponentHandle_toy_EntityScript__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, two_ComponentHandle_toy_EntityScript__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
	}
	// two::ComponentHandle<toy::WorldPage>
	{
		Type& t = type<two::ComponentHandle<toy::WorldPage>>();
		static Meta meta = { t, &namspc({ "two" }), "ComponentHandle<toy::WorldPage>", sizeof(two::ComponentHandle<toy::WorldPage>), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, two_ComponentHandle_toy_WorldPage__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, two_ComponentHandle_toy_WorldPage__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
	}
	// two::ComponentHandle<toy::Navblock>
	{
		Type& t = type<two::ComponentHandle<toy::Navblock>>();
		static Meta meta = { t, &namspc({ "two" }), "ComponentHandle<toy::Navblock>", sizeof(two::ComponentHandle<toy::Navblock>), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, two_ComponentHandle_toy_Navblock__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, two_ComponentHandle_toy_Navblock__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
	}
	// two::ComponentHandle<toy::Origin>
	{
		Type& t = type<two::ComponentHandle<toy::Origin>>();
		static Meta meta = { t, &namspc({ "two" }), "ComponentHandle<toy::Origin>", sizeof(two::ComponentHandle<toy::Origin>), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, two_ComponentHandle_toy_Origin__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, two_ComponentHandle_toy_Origin__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
	}
	// two::ComponentHandle<toy::Waypoint>
	{
		Type& t = type<two::ComponentHandle<toy::Waypoint>>();
		static Meta meta = { t, &namspc({ "two" }), "ComponentHandle<toy::Waypoint>", sizeof(two::ComponentHandle<toy::Waypoint>), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, two_ComponentHandle_toy_Waypoint__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, two_ComponentHandle_toy_Waypoint__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
	}
	// toy::Spatial
	{
		Type& t = type<toy::Spatial>();
		static Meta meta = { t, &namspc({ "toy" }), "Spatial", sizeof(toy::Spatial), TypeClass::Object };
		// bases
		static Type* bases[] = { &type<two::Transform>() };
		static size_t bases_offsets[] = { base_offset<toy::Spatial, two::Transform>() };
		// defaults
		static toy::World* world_default = nullptr;
		// constructors
		static Constructor constructors[] = {
			{ t, toy_Spatial__construct_0, {} },
			{ t, toy_Spatial__construct_1, { { "parent", type<toy::HSpatial>(),  }, { "position", type<two::vec3>(),  }, { "rotation", type<two::quat>(),  } } },
			{ t, toy_Spatial__construct_2, { { "world", type<toy::World>(),  }, { "parent", type<toy::HSpatial>(),  }, { "position", type<two::vec3>(),  }, { "rotation", type<two::quat>(),  } } }
		};
		// copy constructor
		// members
		static Member members[] = {
			{ t, offsetof(toy::Spatial, m_world), type<toy::World>(), "world", world_default, Member::Flags(Member::Pointer|Member::Link), nullptr },
			{ t, offsetof(toy::Spatial, m_parent), type<toy::HSpatial>(), "parent", nullptr, Member::Flags(Member::Value|Member::Link), nullptr },
			{ t, offsetof(toy::Spatial, m_contents), type<stl::vector<toy::HSpatial>>(), "contents", nullptr, Member::Flags(Member::NonMutable|Member::Structure), nullptr }
		};
		// methods
		static Method methods[] = {
			{ t, "set_position", Address(), toy_Spatial_set_position, { { "position", type<two::vec3>(),  } }, g_qvoid },
			{ t, "set_rotation", Address(), toy_Spatial_set_rotation, { { "rotation", type<two::quat>(),  } }, g_qvoid }
		};
		// static members
		static Class cls = { t, bases, bases_offsets, constructors, {}, members, methods, {}, };
	}
	// toy::Origin
	{
		Type& t = type<toy::Origin>();
		static Meta meta = { t, &namspc({ "toy" }), "Origin", sizeof(toy::Origin), TypeClass::Object };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, toy_Origin__construct_0, {} }
		};
		// copy constructor
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, {}, {}, {}, {}, };
	}
	// toy::WorldClock
	{
		Type& t = type<toy::WorldClock>();
		static Meta meta = { t, &namspc({ "toy" }), "WorldClock", sizeof(toy::WorldClock), TypeClass::Object };
		// bases
		// defaults
		// constructors
		// copy constructor
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, {}, {}, {}, {}, {}, };
	}
	// toy::World
	{
		Type& t = type<toy::World>();
		static Meta meta = { t, &namspc({ "toy" }), "World", sizeof(toy::World), TypeClass::Object };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, toy_World__construct_0, { { "id", type<uint32_t>(),  }, { "complex", type<two::Complex>(),  }, { "name", type<stl::string>(),  }, { "job_system", type<two::JobSystem>(),  } } }
		};
		// copy constructor
		// members
		static Member members[] = {
			{ t, offsetof(toy::World, m_id), type<uint32_t>(), "id", nullptr, Member::Value, nullptr },
			{ t, SIZE_MAX, type<two::Complex>(), "complex", nullptr, Member::Flags(Member::NonMutable|Member::Link), toy_World__get_complex },
			{ t, offsetof(toy::World, m_name), type<stl::string>(), "name", nullptr, Member::Value, nullptr },
			{ t, SIZE_MAX, type<toy::HSpatial>(), "origin", nullptr, Member::Flags(Member::Value|Member::NonMutable|Member::Structure), toy_World__get_origin },
			{ t, SIZE_MAX, type<toy::HSpatial>(), "unworld", nullptr, Member::Flags(Member::Value|Member::NonMutable|Member::Structure), toy_World__get_unworld }
		};
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, {}, members, {}, {}, };
	}
	// toy::Medium
	{
		Type& t = type<toy::Medium>();
		static Meta meta = { t, &namspc({ "toy" }), "Medium", sizeof(toy::Medium), TypeClass::Object };
		// bases
		// defaults
		// constructors
		// copy constructor
		// members
		static Member members[] = {
			{ t, offsetof(toy::Medium, m_name), type<stl::string>(), "name", nullptr, Member::Value, nullptr },
			{ t, offsetof(toy::Medium, m_occlusions), type<bool>(), "occlusions", nullptr, Member::Value, nullptr },
			{ t, offsetof(toy::Medium, m_solid), type<bool>(), "solid", nullptr, Member::Value, nullptr }
		};
		// methods
		// static members
		static Class cls = { t, {}, {}, {}, {}, members, {}, {}, };
	}
	// toy::CollisionShape
	{
		Type& t = type<toy::CollisionShape>();
		static Meta meta = { t, &namspc({ "toy" }), "CollisionShape", sizeof(toy::CollisionShape), TypeClass::Object };
		// bases
		// defaults
		static two::vec3 construct_1_center_default = vec3(0.f);
		static float construct_1_margin_default = 0.f;
		// constructors
		static Constructor constructors[] = {
			{ t, toy_CollisionShape__construct_0, {} },
			{ t, toy_CollisionShape__construct_1, { { "shape", type<two::Shape>(),  }, { "center", type<two::vec3>(), Param::Default, &construct_1_center_default }, { "margin", type<float>(), Param::Default, &construct_1_margin_default } } }
		};
		// copy constructor
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, {}, {}, {}, {}, };
	}
	// toy::Movable
	{
		Type& t = type<toy::Movable>();
		static Meta meta = { t, &namspc({ "toy" }), "Movable", sizeof(toy::Movable), TypeClass::Object };
		// bases
		// defaults
		static bool moving_default = false;
		// constructors
		static Constructor constructors[] = {
			{ t, toy_Movable__construct_0, {} },
			{ t, toy_Movable__construct_1, { { "position", type<two::vec3>(),  } } }
		};
		// copy constructor
		// members
		static Member members[] = {
			{ t, offsetof(toy::Movable, m_linear_velocity), type<two::vec3>(), "linear_velocity", nullptr, Member::Value, nullptr },
			{ t, offsetof(toy::Movable, m_angular_velocity), type<two::vec3>(), "angular_velocity", nullptr, Member::Value, nullptr },
			{ t, offsetof(toy::Movable, m_moving), type<bool>(), "moving", &moving_default, Member::Value, nullptr },
			{ t, offsetof(toy::Movable, m_previous_position), type<two::vec3>(), "previous_position", nullptr, Member::Value, nullptr }
		};
		// methods
		static Method methods[] = {
			{ t, "set_linear_velocity", Address(), toy_Movable_set_linear_velocity, { { "velocity", type<two::vec3>(),  } }, g_qvoid },
			{ t, "modify_linear_velocity", Address(), toy_Movable_modify_linear_velocity, { { "velocity", type<two::vec3>(),  } }, g_qvoid },
			{ t, "set_angular_velocity", Address(), toy_Movable_set_angular_velocity, { { "velocity", type<two::vec3>(),  } }, g_qvoid },
			{ t, "modify_angular_velocity", Address(), toy_Movable_modify_angular_velocity, { { "velocity", type<two::vec3>(),  } }, g_qvoid }
		};
		// static members
		static Class cls = { t, {}, {}, constructors, {}, members, methods, {}, };
	}
	// toy::Collision
	{
		Type& t = type<toy::Collision>();
		static Meta meta = { t, &namspc({ "toy" }), "Collision", sizeof(toy::Collision), TypeClass::Struct };
		// bases
		// defaults
		static toy::HCollider first_default = {};
		static toy::HCollider second_default = {};
		// constructors
		static Constructor constructors[] = {
			{ t, toy_Collision__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, toy_Collision__copy_construct }
		};
		// members
		static Member members[] = {
			{ t, offsetof(toy::Collision, m_first), type<toy::HCollider>(), "first", &first_default, Member::Value, nullptr },
			{ t, offsetof(toy::Collision, m_second), type<toy::HCollider>(), "second", &second_default, Member::Value, nullptr },
			{ t, offsetof(toy::Collision, m_hit_point), type<two::vec3>(), "hit_point", nullptr, Member::Value, nullptr }
		};
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, members, {}, {}, };
	}
	// toy::ColliderImpl
	{
		Type& t = type<toy::ColliderImpl>();
		static Meta meta = { t, &namspc({ "toy" }), "ColliderImpl", sizeof(toy::ColliderImpl), TypeClass::Object };
		// bases
		// defaults
		// constructors
		// copy constructor
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, {}, {}, {}, {}, {}, };
	}
	// toy::ColliderObject
	{
		Type& t = type<toy::ColliderObject>();
		static Meta meta = { t, &namspc({ "toy" }), "ColliderObject", sizeof(toy::ColliderObject), TypeClass::Object };
		// bases
		// defaults
		// constructors
		// copy constructor
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, {}, {}, {}, {}, {}, };
	}
	// toy::Collider
	{
		Type& t = type<toy::Collider>();
		static Meta meta = { t, &namspc({ "toy" }), "Collider", sizeof(toy::Collider), TypeClass::Object };
		// bases
		// defaults
		static toy::Medium* medium_default = nullptr;
		static toy::ColliderObject* object_default = nullptr;
		// constructors
		static Constructor constructors[] = {
			{ t, toy_Collider__construct_0, {} },
			{ t, toy_Collider__construct_1, { { "spatial", type<toy::HSpatial>(),  }, { "movable", type<toy::HMovable>(),  }, { "collision_shape", type<toy::CollisionShape>(),  }, { "medium", type<toy::Medium>(),  }, { "group", type<toy::CollisionGroup>(),  } } }
		};
		// copy constructor
		// members
		static Member members[] = {
			{ t, offsetof(toy::Collider, m_spatial), type<toy::HSpatial>(), "spatial", nullptr, Member::Value, nullptr },
			{ t, offsetof(toy::Collider, m_movable), type<toy::HMovable>(), "movable", nullptr, Member::Value, nullptr },
			{ t, offsetof(toy::Collider, m_collision_shape), type<toy::CollisionShape>(), "collision_shape", nullptr, Member::NonMutable, nullptr },
			{ t, offsetof(toy::Collider, m_medium), type<toy::Medium>(), "medium", medium_default, Member::Flags(Member::Pointer|Member::Link), nullptr },
			{ t, offsetof(toy::Collider, m_group), type<toy::CollisionGroup>(), "group", nullptr, Member::Value, nullptr },
			{ t, offsetof(toy::Collider, m_object), type<toy::ColliderObject>(), "object", object_default, Member::Flags(Member::Pointer|Member::Link), nullptr },
			{ t, SIZE_MAX, type<toy::ColliderImpl>(), "impl", nullptr, Member::Flags(Member::NonMutable|Member::Link), toy_Collider__get_impl }
		};
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, {}, members, {}, {}, };
	}
	// toy::SolidImpl
	{
		Type& t = type<toy::SolidImpl>();
		static Meta meta = { t, &namspc({ "toy" }), "SolidImpl", sizeof(toy::SolidImpl), TypeClass::Object };
		// bases
		// defaults
		// constructors
		// copy constructor
		// members
		// methods
		static Method methods[] = {
			{ t, "linear_velocity", Address(), toy_SolidImpl_linear_velocity, {}, { &type<two::vec3>(), QualType::None } },
			{ t, "angular_velocity", Address(), toy_SolidImpl_angular_velocity, {}, { &type<two::vec3>(), QualType::None } },
			{ t, "set_linear_velocity", Address(), toy_SolidImpl_set_linear_velocity, { { "force", type<two::vec3>(),  } }, g_qvoid },
			{ t, "set_angular_velocity", Address(), toy_SolidImpl_set_angular_velocity, { { "torque", type<two::vec3>(),  } }, g_qvoid },
			{ t, "set_angular_factor", Address(), toy_SolidImpl_set_angular_factor, { { "factor", type<two::vec3>(),  } }, g_qvoid },
			{ t, "impulse", Address(), toy_SolidImpl_impulse, { { "force", type<two::vec3>(),  }, { "point", type<two::vec3>(),  } }, g_qvoid }
		};
		// static members
		static Class cls = { t, {}, {}, {}, {}, {}, methods, {}, };
	}
	// toy::Solid
	{
		Type& t = type<toy::Solid>();
		static Meta meta = { t, &namspc({ "toy" }), "Solid", sizeof(toy::Solid), TypeClass::Object };
		// bases
		// defaults
		static bool static_default = false;
		static float mass_default = 0.f;
		// constructors
		// copy constructor
		// members
		static Member members[] = {
			{ t, offsetof(toy::Solid, m_spatial), type<toy::HSpatial>(), "spatial", nullptr, Member::Value, nullptr },
			{ t, offsetof(toy::Solid, m_static), type<bool>(), "static", &static_default, Member::Value, nullptr },
			{ t, offsetof(toy::Solid, m_mass), type<float>(), "mass", &mass_default, Member::Value, nullptr }
		};
		// methods
		// static members
		static Class cls = { t, {}, {}, {}, {}, members, {}, {}, };
	}
	// toy::WorldMedium
	{
		Type& t = type<toy::WorldMedium>();
		static Meta meta = { t, &namspc({ "toy" }), "WorldMedium", sizeof(toy::WorldMedium), TypeClass::Object };
		// bases
		static Type* bases[] = { &type<toy::Medium>() };
		static size_t bases_offsets[] = { base_offset<toy::WorldMedium, toy::Medium>() };
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, toy_WorldMedium__construct_0, {} }
		};
		// copy constructor
		// members
		// methods
		// static members
		static Static statics[] = {
			{ t, "me", Ref(&toy::WorldMedium::me) }
		};
		static Class cls = { t, bases, bases_offsets, constructors, {}, {}, {}, statics, };
	}
	// toy::WorldPage
	{
		Type& t = type<toy::WorldPage>();
		static Meta meta = { t, &namspc({ "toy" }), "WorldPage", sizeof(toy::WorldPage), TypeClass::Object };
		// bases
		// defaults
		static bool open_default = true;
		static toy::World* world_default = nullptr;
		static size_t last_rebuilt_default = 0;
		// constructors
		static Constructor constructors[] = {
			{ t, toy_WorldPage__construct_0, {} },
			{ t, toy_WorldPage__construct_1, { { "spatial", type<toy::HSpatial>(),  }, { "open", type<bool>(),  }, { "extents", type<two::vec3>(),  } } }
		};
		// copy constructor
		// members
		static Member members[] = {
			{ t, offsetof(toy::WorldPage, m_open), type<bool>(), "open", &open_default, Member::Value, nullptr },
			{ t, offsetof(toy::WorldPage, m_extents), type<two::vec3>(), "extents", nullptr, Member::Value, nullptr },
			{ t, offsetof(toy::WorldPage, m_world), type<toy::World>(), "world", world_default, Member::Flags(Member::Pointer|Member::Link), nullptr },
			{ t, offsetof(toy::WorldPage, m_last_rebuilt), type<size_t>(), "last_rebuilt", &last_rebuilt_default, Member::Value, nullptr }
		};
		// methods
		static Method methods[] = {
			{ t, "update_geometry", Address(), toy_WorldPage_update_geometry, { { "tick", type<size_t>(),  } }, g_qvoid },
			{ t, "ground_point", Address(), toy_WorldPage_ground_point, { { "position", type<two::vec3>(),  }, { "relative", type<bool>(),  }, { "outputPoint", type<two::vec3>(), Param::Output } }, g_qvoid },
			{ t, "raycast_ground", Address(), toy_WorldPage_raycast_ground, { { "from", type<two::vec3>(),  }, { "to", type<two::vec3>(),  }, { "ground_point", type<two::vec3>(),  } }, g_qvoid }
		};
		// static members
		static Class cls = { t, {}, {}, constructors, {}, members, methods, {}, };
	}
	// toy::Navmesh
	{
		Type& t = type<toy::Navmesh>();
		static Meta meta = { t, &namspc({ "toy" }), "Navmesh", sizeof(toy::Navmesh), TypeClass::Object };
		// bases
		// defaults
		static size_t updated_default = 0;
		static bool dirty_default = false;
		// constructors
		static Constructor constructors[] = {
			{ t, toy_Navmesh__construct_0, { { "world", type<toy::World>(),  } } }
		};
		// copy constructor
		// members
		static Member members[] = {
			{ t, SIZE_MAX, type<toy::World>(), "world", nullptr, Member::Flags(Member::NonMutable|Member::Link), toy_Navmesh__get_world },
			{ t, offsetof(toy::Navmesh, m_updated), type<size_t>(), "updated", &updated_default, Member::Value, nullptr },
			{ t, offsetof(toy::Navmesh, m_dirty), type<bool>(), "dirty", &dirty_default, Member::Value, nullptr }
		};
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, {}, members, {}, {}, };
	}
	// toy::Navblock
	{
		Type& t = type<toy::Navblock>();
		static Meta meta = { t, &namspc({ "toy" }), "Navblock", sizeof(toy::Navblock), TypeClass::Object };
		// bases
		// defaults
		static toy::Navmesh* navmesh_default = nullptr;
		static bool auto_update_default = false;
		static size_t updated_default = 0;
		// constructors
		static Constructor constructors[] = {
			{ t, toy_Navblock__construct_0, {} },
			{ t, toy_Navblock__construct_1, { { "spatial", type<toy::HSpatial>(),  }, { "world_page", type<toy::HWorldPage>(),  }, { "navmesh", type<toy::Navmesh>(),  } } }
		};
		// copy constructor
		// members
		static Member members[] = {
			{ t, offsetof(toy::Navblock, m_navmesh), type<toy::Navmesh>(), "navmesh", navmesh_default, Member::Flags(Member::Pointer|Member::Link), nullptr },
			{ t, offsetof(toy::Navblock, m_auto_update), type<bool>(), "auto_update", &auto_update_default, Member::Value, nullptr },
			{ t, offsetof(toy::Navblock, m_updated), type<size_t>(), "updated", &updated_default, Member::Value, nullptr }
		};
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, {}, members, {}, {}, };
	}
	// toy::NavmeshShape
	{
		Type& t = type<toy::NavmeshShape>();
		static Meta meta = { t, &namspc({ "toy" }), "NavmeshShape", sizeof(toy::NavmeshShape), TypeClass::Object };
		// bases
		static Type* bases[] = { &type<two::Shape>() };
		static size_t bases_offsets[] = { base_offset<toy::NavmeshShape, two::Shape>() };
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, toy_NavmeshShape__construct_0, { { "navmesh", type<toy::Navmesh>(),  } } }
		};
		// copy constructor
		// members
		// methods
		// static members
		static Class cls = { t, bases, bases_offsets, constructors, {}, {}, {}, {}, };
	}
	// toy::PhysicWorld
	{
		Type& t = type<toy::PhysicWorld>();
		static Meta meta = { t, &namspc({ "toy" }), "PhysicWorld", sizeof(toy::PhysicWorld), TypeClass::Object };
		// bases
		// defaults
		// constructors
		// copy constructor
		// members
		static Member members[] = {
			{ t, SIZE_MAX, type<toy::World>(), "world", nullptr, Member::Flags(Member::NonMutable|Member::Link), toy_PhysicWorld__get_world }
		};
		// methods
		static Method methods[] = {
			{ t, "ground_point", Address(), toy_PhysicWorld_ground_point, { { "ray", type<two::Ray>(),  } }, { &type<two::vec3>(), QualType::None } },
			{ t, "raycast", Address(), toy_PhysicWorld_raycast, { { "ray", type<two::Ray>(),  }, { "mask", type<short>(),  } }, { &type<toy::Collision>(), QualType::None } }
		};
		// static members
		static Class cls = { t, {}, {}, {}, {}, members, methods, {}, };
	}
	// toy::BulletMedium
	{
		Type& t = type<toy::BulletMedium>();
		static Meta meta = { t, &namspc({ "toy" }), "BulletMedium", sizeof(toy::BulletMedium), TypeClass::Object };
		// bases
		// defaults
		// constructors
		// copy constructor
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, {}, {}, {}, {}, {}, };
	}
	// toy::BulletWorld
	{
		Type& t = type<toy::BulletWorld>();
		static Meta meta = { t, &namspc({ "toy" }), "BulletWorld", sizeof(toy::BulletWorld), TypeClass::Object };
		// bases
		static Type* bases[] = { &type<toy::PhysicWorld>() };
		static size_t bases_offsets[] = { base_offset<toy::BulletWorld, toy::PhysicWorld>() };
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, toy_BulletWorld__construct_0, { { "world", type<toy::World>(),  } } }
		};
		// copy constructor
		// members
		// methods
		// static members
		static Class cls = { t, bases, bases_offsets, constructors, {}, {}, {}, {}, };
	}
	// toy::Core
	{
		Type& t = type<toy::Core>();
		static Meta meta = { t, &namspc({ "toy" }), "Core", sizeof(toy::Core), TypeClass::Object };
		// bases
		// defaults
		// constructors
		// copy constructor
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, {}, {}, {}, {}, {}, };
	}
	// toy::DefaultWorld
	{
		Type& t = type<toy::DefaultWorld>();
		static Meta meta = { t, &namspc({ "toy" }), "DefaultWorld", sizeof(toy::DefaultWorld), TypeClass::Object };
		// bases
		static Type* bases[] = { &type<two::Complex>() };
		static size_t bases_offsets[] = { base_offset<toy::DefaultWorld, two::Complex>() };
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, toy_DefaultWorld__construct_0, { { "name", type<stl::string>(),  }, { "job_system", type<two::JobSystem>(),  } } }
		};
		// copy constructor
		// members
		static Member members[] = {
			{ t, offsetof(toy::DefaultWorld, m_world), type<toy::World>(), "world", nullptr, Member::NonMutable, nullptr },
			{ t, offsetof(toy::DefaultWorld, m_bullet_world), type<toy::BulletWorld>(), "bullet_world", nullptr, Member::Flags(Member::NonMutable|Member::Component), nullptr },
			{ t, offsetof(toy::DefaultWorld, m_navmesh), type<toy::Navmesh>(), "navmesh", nullptr, Member::Flags(Member::NonMutable|Member::Component), nullptr }
		};
		// methods
		// static members
		static Class cls = { t, bases, bases_offsets, constructors, {}, members, {}, {}, };
	}
	// toy::User
	{
		Type& t = type<toy::User>();
		static Meta meta = { t, &namspc({ "toy" }), "User", sizeof(toy::User), TypeClass::Object };
		// bases
		// defaults
		// constructors
		// copy constructor
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, {}, {}, {}, {}, {}, };
	}
	// toy::BulletShape
	{
		Type& t = type<toy::BulletShape>();
		static Meta meta = { t, &namspc({ "toy" }), "BulletShape", sizeof(toy::BulletShape), TypeClass::Object };
		// bases
		// defaults
		// constructors
		// copy constructor
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, {}, {}, {}, {}, {}, };
	}
	// toy::BulletCollider
	{
		Type& t = type<toy::BulletCollider>();
		static Meta meta = { t, &namspc({ "toy" }), "BulletCollider", sizeof(toy::BulletCollider), TypeClass::Object };
		// bases
		static Type* bases[] = { &type<toy::ColliderImpl>() };
		static size_t bases_offsets[] = { base_offset<toy::BulletCollider, toy::ColliderImpl>() };
		// defaults
		// constructors
		// copy constructor
		// members
		// methods
		// static members
		static Class cls = { t, bases, bases_offsets, {}, {}, {}, {}, {}, };
	}
	// toy::BulletSolid
	{
		Type& t = type<toy::BulletSolid>();
		static Meta meta = { t, &namspc({ "toy" }), "BulletSolid", sizeof(toy::BulletSolid), TypeClass::Object };
		// bases
		static Type* bases[] = { &type<toy::SolidImpl>() };
		static size_t bases_offsets[] = { base_offset<toy::BulletSolid, toy::SolidImpl>() };
		// defaults
		// constructors
		// copy constructor
		// members
		// methods
		// static members
		static Class cls = { t, bases, bases_offsets, {}, {}, {}, {}, {}, };
	}
	// toy::PhysicScope
	{
		Type& t = type<toy::PhysicScope>();
		static Meta meta = { t, &namspc({ "toy" }), "PhysicScope", sizeof(toy::PhysicScope), TypeClass::Object };
		// bases
		static Type* bases[] = { &type<toy::ColliderObject>() };
		static size_t bases_offsets[] = { base_offset<toy::PhysicScope, toy::ColliderObject>() };
		// defaults
		// constructors
		// copy constructor
		// members
		// methods
		// static members
		static Class cls = { t, bases, bases_offsets, {}, {}, {}, {}, {}, };
	}
	// toy::EmitterScope
	{
		Type& t = type<toy::EmitterScope>();
		static Meta meta = { t, &namspc({ "toy" }), "EmitterScope", sizeof(toy::EmitterScope), TypeClass::Object };
		// bases
		static Type* bases[] = { &type<toy::PhysicScope>() };
		static size_t bases_offsets[] = { base_offset<toy::EmitterScope, toy::PhysicScope>() };
		// defaults
		// constructors
		// copy constructor
		// members
		// methods
		// static members
		static Class cls = { t, bases, bases_offsets, {}, {}, {}, {}, {}, };
	}
	// toy::ReceptorScope
	{
		Type& t = type<toy::ReceptorScope>();
		static Meta meta = { t, &namspc({ "toy" }), "ReceptorScope", sizeof(toy::ReceptorScope), TypeClass::Object };
		// bases
		static Type* bases[] = { &type<toy::PhysicScope>() };
		static size_t bases_offsets[] = { base_offset<toy::ReceptorScope, toy::PhysicScope>() };
		// defaults
		// constructors
		// copy constructor
		// members
		// methods
		// static members
		static Class cls = { t, bases, bases_offsets, {}, {}, {}, {}, {}, };
	}
	// toy::Emitter
	{
		Type& t = type<toy::Emitter>();
		static Meta meta = { t, &namspc({ "toy" }), "Emitter", sizeof(toy::Emitter), TypeClass::Object };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, toy_Emitter__construct_0, {} },
			{ t, toy_Emitter__construct_1, { { "spatial", type<toy::HSpatial>(),  } } }
		};
		// copy constructor
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, {}, {}, {}, {}, };
	}
	// toy::Receptor
	{
		Type& t = type<toy::Receptor>();
		static Meta meta = { t, &namspc({ "toy" }), "Receptor", sizeof(toy::Receptor), TypeClass::Object };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, toy_Receptor__construct_0, {} },
			{ t, toy_Receptor__construct_1, { { "spatial", type<toy::HSpatial>(),  } } }
		};
		// copy constructor
		// members
		// methods
		static Method methods[] = {
			{ t, "scope", Address(), toy_Receptor_scope, { { "medium", type<toy::Medium>(),  } }, { &type<toy::ReceptorScope>(), QualType::None } }
		};
		// static members
		static Class cls = { t, {}, {}, constructors, {}, {}, methods, {}, };
	}
	// toy::Camera
	{
		Type& t = type<toy::Camera>();
		static Meta meta = { t, &namspc({ "toy" }), "Camera", sizeof(toy::Camera), TypeClass::Object };
		// bases
		// defaults
		static float lens_distance_default = 1.f;
		static float lens_angle_default = 0.f;
		static float near_default = 0.001f;
		static float far_default = 1000.f;
		static float construct_1_near_default = 0.001f;
		static float construct_1_far_default = 1000.f;
		// constructors
		static Constructor constructors[] = {
			{ t, toy_Camera__construct_0, {} },
			{ t, toy_Camera__construct_1, { { "distance", type<float>(),  }, { "near", type<float>(), Param::Default, &construct_1_near_default }, { "far", type<float>(), Param::Default, &construct_1_far_default } } }
		};
		// copy constructor
		// members
		static Member members[] = {
			{ t, offsetof(toy::Camera, m_lens_distance), type<float>(), "lens_distance", &lens_distance_default, Member::Value, nullptr },
			{ t, offsetof(toy::Camera, m_lens_angle), type<float>(), "lens_angle", &lens_angle_default, Member::Value, nullptr },
			{ t, offsetof(toy::Camera, m_near), type<float>(), "near", &near_default, Member::Value, nullptr },
			{ t, offsetof(toy::Camera, m_far), type<float>(), "far", &far_default, Member::Value, nullptr },
			{ t, offsetof(toy::Camera, m_aspect), type<float>(), "aspect", nullptr, Member::Value, nullptr }
		};
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, {}, members, {}, {}, };
	}
	// toy::SoundMedium
	{
		Type& t = type<toy::SoundMedium>();
		static Meta meta = { t, &namspc({ "toy" }), "SoundMedium", sizeof(toy::SoundMedium), TypeClass::Object };
		// bases
		static Type* bases[] = { &type<toy::Medium>() };
		static size_t bases_offsets[] = { base_offset<toy::SoundMedium, toy::Medium>() };
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, toy_SoundMedium__construct_0, {} }
		};
		// copy constructor
		// members
		// methods
		// static members
		static Static statics[] = {
			{ t, "me", Ref(&toy::SoundMedium::me) }
		};
		static Class cls = { t, bases, bases_offsets, constructors, {}, {}, {}, statics, };
	}
	// toy::VisualMedium
	{
		Type& t = type<toy::VisualMedium>();
		static Meta meta = { t, &namspc({ "toy" }), "VisualMedium", sizeof(toy::VisualMedium), TypeClass::Object };
		// bases
		static Type* bases[] = { &type<toy::Medium>() };
		static size_t bases_offsets[] = { base_offset<toy::VisualMedium, toy::Medium>() };
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, toy_VisualMedium__construct_0, {} }
		};
		// copy constructor
		// members
		// methods
		// static members
		static Static statics[] = {
			{ t, "me", Ref(&toy::VisualMedium::me) }
		};
		static Class cls = { t, bases, bases_offsets, constructors, {}, {}, {}, statics, };
	}
	// toy::Waypoint
	{
		Type& t = type<toy::Waypoint>();
		static Meta meta = { t, &namspc({ "toy" }), "Waypoint", sizeof(toy::Waypoint), TypeClass::Object };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, toy_Waypoint__construct_0, {} }
		};
		// copy constructor
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, {}, {}, {}, {}, };
	}
	// toy::DetourPath
	{
		Type& t = type<toy::DetourPath>();
		static Meta meta = { t, &namspc({ "toy" }), "DetourPath", sizeof(toy::DetourPath), TypeClass::Object };
		// bases
		// defaults
		// constructors
		// copy constructor
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, {}, {}, {}, {}, {}, };
	}
	// toy::Pathfinder
	{
		Type& t = type<toy::Pathfinder>();
		static Meta meta = { t, &namspc({ "toy" }), "Pathfinder", sizeof(toy::Pathfinder), TypeClass::Object };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, toy_Pathfinder__construct_0, { { "navmesh", type<toy::Navmesh>(),  } } }
		};
		// copy constructor
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, {}, {}, {}, {}, };
	}
	// toy::Obstacle
	{
		Type& t = type<toy::Obstacle>();
		static Meta meta = { t, &namspc({ "toy" }), "Obstacle", sizeof(toy::Obstacle), TypeClass::Object };
		// bases
		static Type* bases[] = { &type<toy::Collider>() };
		static size_t bases_offsets[] = { base_offset<toy::Obstacle, toy::Collider>() };
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, toy_Obstacle__construct_0, { { "spatial", type<toy::HSpatial>(),  }, { "movable", type<toy::HMovable>(),  }, { "medium", type<toy::Medium>(),  }, { "shape", type<toy::CollisionShape>(),  }, { "throughput", type<float>(),  } } }
		};
		// copy constructor
		// members
		static Member members[] = {
			{ t, offsetof(toy::Obstacle, m_shape), type<toy::CollisionShape>(), "shape", nullptr, Member::NonMutable, nullptr },
			{ t, offsetof(toy::Obstacle, m_throughput), type<float>(), "throughput", nullptr, Member::Value, nullptr }
		};
		// methods
		// static members
		static Class cls = { t, bases, bases_offsets, constructors, {}, members, {}, {}, };
	}
	// toy::SolidMedium
	{
		Type& t = type<toy::SolidMedium>();
		static Meta meta = { t, &namspc({ "toy" }), "SolidMedium", sizeof(toy::SolidMedium), TypeClass::Object };
		// bases
		static Type* bases[] = { &type<toy::Medium>() };
		static size_t bases_offsets[] = { base_offset<toy::SolidMedium, toy::Medium>() };
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, toy_SolidMedium__construct_0, {} }
		};
		// copy constructor
		// members
		// methods
		// static members
		static Static statics[] = {
			{ t, "me", Ref(&toy::SolidMedium::me) }
		};
		static Class cls = { t, bases, bases_offsets, constructors, {}, {}, {}, statics, };
	}
	// toy::ComponentPool
	{
		Type& t = type<toy::ComponentPool>();
		static Meta meta = { t, &namspc({ "toy" }), "ComponentPool", sizeof(toy::ComponentPool), TypeClass::Object };
		// bases
		// defaults
		// constructors
		// copy constructor
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, {}, {}, {}, {}, {}, };
	}
	// toy::EntityScript
	{
		Type& t = type<toy::EntityScript>();
		static Meta meta = { t, &namspc({ "toy" }), "EntityScript", sizeof(toy::EntityScript), TypeClass::Object };
		// bases
		// defaults
		static two::Script* logic_script_default = nullptr;
		static two::Script* render_script_default = nullptr;
		// constructors
		static Constructor constructors[] = {
			{ t, toy_EntityScript__construct_0, {} },
			{ t, toy_EntityScript__construct_1, { { "spatial", type<toy::HSpatial>(),  } } }
		};
		// copy constructor
		// members
		static Member members[] = {
			{ t, offsetof(toy::EntityScript, m_logic_script), type<two::Script>(), "logic_script", logic_script_default, Member::Flags(Member::Pointer|Member::Link), nullptr },
			{ t, offsetof(toy::EntityScript, m_render_script), type<two::Script>(), "render_script", render_script_default, Member::Flags(Member::Pointer|Member::Link), nullptr }
		};
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, {}, members, {}, {}, };
	}
	
	{
		Type& t = type<two::SparseHandle<toy::Collider>>();
		static Alias alias = { &t, &namspc({ "toy" }), "HCollider" };
		m.m_aliases.push_back(&alias);
	}
	{
		Type& t = type<two::OwnedHandle<toy::Collider>>();
		static Alias alias = { &t, &namspc({ "toy" }), "OCollider" };
		m.m_aliases.push_back(&alias);
	}
	{
		Type& t = type<two::SparseHandle<toy::Solid>>();
		static Alias alias = { &t, &namspc({ "toy" }), "HSolid" };
		m.m_aliases.push_back(&alias);
	}
	{
		Type& t = type<two::OwnedHandle<toy::Solid>>();
		static Alias alias = { &t, &namspc({ "toy" }), "OSolid" };
		m.m_aliases.push_back(&alias);
	}
	{
		Type& t = type<two::ComponentHandle<toy::Spatial>>();
		static Alias alias = { &t, &namspc({ "toy" }), "HSpatial" };
		m.m_aliases.push_back(&alias);
	}
	{
		Type& t = type<two::ComponentHandle<toy::Movable>>();
		static Alias alias = { &t, &namspc({ "toy" }), "HMovable" };
		m.m_aliases.push_back(&alias);
	}
	{
		Type& t = type<two::ComponentHandle<toy::Camera>>();
		static Alias alias = { &t, &namspc({ "toy" }), "HCamera" };
		m.m_aliases.push_back(&alias);
	}
	{
		Type& t = type<two::ComponentHandle<toy::Emitter>>();
		static Alias alias = { &t, &namspc({ "toy" }), "HEmitter" };
		m.m_aliases.push_back(&alias);
	}
	{
		Type& t = type<two::ComponentHandle<toy::Receptor>>();
		static Alias alias = { &t, &namspc({ "toy" }), "HReceptor" };
		m.m_aliases.push_back(&alias);
	}
	{
		Type& t = type<two::ComponentHandle<toy::EntityScript>>();
		static Alias alias = { &t, &namspc({ "toy" }), "HEntityScript" };
		m.m_aliases.push_back(&alias);
	}
	{
		Type& t = type<two::ComponentHandle<toy::WorldPage>>();
		static Alias alias = { &t, &namspc({ "toy" }), "HWorldPage" };
		m.m_aliases.push_back(&alias);
	}
	{
		Type& t = type<two::ComponentHandle<toy::Navblock>>();
		static Alias alias = { &t, &namspc({ "toy" }), "HNavblock" };
		m.m_aliases.push_back(&alias);
	}
	{
		Type& t = type<two::ComponentHandle<toy::Origin>>();
		static Alias alias = { &t, &namspc({ "toy" }), "HOrigin" };
		m.m_aliases.push_back(&alias);
	}
	{
		Type& t = type<two::ComponentHandle<toy::Waypoint>>();
		static Alias alias = { &t, &namspc({ "toy" }), "HWaypoint" };
		m.m_aliases.push_back(&alias);
	}
	{
		Type& t = type<uint>();
		static Alias alias = { &t, &namspc({}), "dtStatus" };
		m.m_aliases.push_back(&alias);
	}
	{
		Type& t = type<uint>();
		static Alias alias = { &t, &namspc({}), "dtPolyRef" };
		m.m_aliases.push_back(&alias);
	}
	{
		Type& t = type<uint>();
		static Alias alias = { &t, &namspc({}), "dtTileRef" };
		m.m_aliases.push_back(&alias);
	}
	{
		Type& t = type<uint>();
		static Alias alias = { &t, &namspc({}), "dtStatus" };
		m.m_aliases.push_back(&alias);
	}
	{
		Type& t = type<uint>();
		static Alias alias = { &t, &namspc({}), "dtPolyRef" };
		m.m_aliases.push_back(&alias);
	}
	{
		Type& t = type<uint>();
		static Alias alias = { &t, &namspc({}), "dtTileRef" };
		m.m_aliases.push_back(&alias);
	}
	{
		Type& t = type<uint>();
		static Alias alias = { &t, &namspc({ "toy" }), "dtPolyRef" };
		m.m_aliases.push_back(&alias);
	}
	
		m.m_types.push_back(&type<two::OwnedHandle<toy::Collider>>());
		m.m_types.push_back(&type<two::OwnedHandle<toy::Solid>>());
		m.m_types.push_back(&type<two::SparseHandle<toy::Collider>>());
		m.m_types.push_back(&type<two::SparseHandle<toy::Solid>>());
		m.m_types.push_back(&type<two::ComponentHandle<toy::Spatial>>());
		m.m_types.push_back(&type<two::ComponentHandle<toy::Movable>>());
		m.m_types.push_back(&type<two::ComponentHandle<toy::Camera>>());
		m.m_types.push_back(&type<two::ComponentHandle<toy::Emitter>>());
		m.m_types.push_back(&type<two::ComponentHandle<toy::Receptor>>());
		m.m_types.push_back(&type<two::ComponentHandle<toy::EntityScript>>());
		m.m_types.push_back(&type<two::ComponentHandle<toy::WorldPage>>());
		m.m_types.push_back(&type<two::ComponentHandle<toy::Navblock>>());
		m.m_types.push_back(&type<two::ComponentHandle<toy::Origin>>());
		m.m_types.push_back(&type<two::ComponentHandle<toy::Waypoint>>());
		m.m_types.push_back(&type<toy::HCollider>());
		m.m_types.push_back(&type<toy::OCollider>());
		m.m_types.push_back(&type<toy::HSolid>());
		m.m_types.push_back(&type<toy::OSolid>());
		m.m_types.push_back(&type<toy::HSpatial>());
		m.m_types.push_back(&type<toy::HMovable>());
		m.m_types.push_back(&type<toy::HCamera>());
		m.m_types.push_back(&type<toy::HEmitter>());
		m.m_types.push_back(&type<toy::HReceptor>());
		m.m_types.push_back(&type<toy::HEntityScript>());
		m.m_types.push_back(&type<toy::HWorldPage>());
		m.m_types.push_back(&type<toy::HNavblock>());
		m.m_types.push_back(&type<toy::HOrigin>());
		m.m_types.push_back(&type<toy::HWaypoint>());
		m.m_types.push_back(&type<stl::vector<toy::HSpatial>>());
		m.m_types.push_back(&type<dtStatus>());
		m.m_types.push_back(&type<dtPolyRef>());
		m.m_types.push_back(&type<dtTileRef>());
		m.m_types.push_back(&type<toy::Spatial>());
		m.m_types.push_back(&type<toy::Origin>());
		m.m_types.push_back(&type<toy::WorldClock>());
		m.m_types.push_back(&type<toy::World>());
		m.m_types.push_back(&type<toy::CollisionGroup>());
		m.m_types.push_back(&type<toy::Medium>());
		m.m_types.push_back(&type<toy::CollisionShape>());
		m.m_types.push_back(&type<toy::Movable>());
		m.m_types.push_back(&type<toy::Collision>());
		m.m_types.push_back(&type<toy::ColliderImpl>());
		m.m_types.push_back(&type<toy::ColliderObject>());
		m.m_types.push_back(&type<toy::Collider>());
		m.m_types.push_back(&type<toy::SolidImpl>());
		m.m_types.push_back(&type<toy::Solid>());
		m.m_types.push_back(&type<toy::WorldMedium>());
		m.m_types.push_back(&type<toy::WorldPage>());
		m.m_types.push_back(&type<dtStatus>());
		m.m_types.push_back(&type<dtPolyRef>());
		m.m_types.push_back(&type<dtTileRef>());
		m.m_types.push_back(&type<toy::Navmesh>());
		m.m_types.push_back(&type<toy::Navblock>());
		m.m_types.push_back(&type<toy::NavmeshShape>());
		m.m_types.push_back(&type<toy::PhysicWorld>());
		m.m_types.push_back(&type<toy::BulletMedium>());
		m.m_types.push_back(&type<toy::BulletWorld>());
		m.m_types.push_back(&type<toy::Core>());
		m.m_types.push_back(&type<toy::DefaultWorld>());
		m.m_types.push_back(&type<toy::User>());
		m.m_types.push_back(&type<toy::BulletShape>());
		m.m_types.push_back(&type<toy::BulletCollider>());
		m.m_types.push_back(&type<toy::BulletSolid>());
		m.m_types.push_back(&type<toy::PhysicScope>());
		m.m_types.push_back(&type<toy::EmitterScope>());
		m.m_types.push_back(&type<toy::ReceptorScope>());
		m.m_types.push_back(&type<toy::Emitter>());
		m.m_types.push_back(&type<toy::Receptor>());
		m.m_types.push_back(&type<toy::Camera>());
		m.m_types.push_back(&type<toy::SoundMedium>());
		m.m_types.push_back(&type<toy::VisualMedium>());
		m.m_types.push_back(&type<toy::dtPolyRef>());
		m.m_types.push_back(&type<toy::Waypoint>());
		m.m_types.push_back(&type<toy::DetourPath>());
		m.m_types.push_back(&type<toy::Pathfinder>());
		m.m_types.push_back(&type<toy::Obstacle>());
		m.m_types.push_back(&type<toy::SolidMedium>());
		m.m_types.push_back(&type<toy::ComponentPool>());
		m.m_types.push_back(&type<toy::EntityScript>());
		{
			static float margin_default = 0.1f;
			static Function f = { &namspc({ "toy" }), "move_2d", funcptr<bool(*)(toy::Spatial&, toy::Movable&, const two::vec3&, float, float, float)>(toy::move_2d), toy_move_2d_0, { { "spatial", type<toy::Spatial>(),  }, { "movable", type<toy::Movable>(),  }, { "target", type<two::vec3>(),  }, { "velocity", type<float>(),  }, { "time_step", type<float>(),  }, { "margin", type<float>(), Param::Default, &margin_default } }, { &type<bool>(), QualType::None } };
			m.m_functions.push_back(&f);
		}
		{
			static float margin_default = 0.1f;
			static Function f = { &namspc({ "toy" }), "steer_2d", funcptr<bool(*)(toy::Spatial&, toy::Movable&, const two::vec3&, float, float, float)>(toy::steer_2d), toy_steer_2d_1, { { "spatial", type<toy::Spatial>(),  }, { "movable", type<toy::Movable>(),  }, { "target", type<two::vec3>(),  }, { "velocity", type<float>(),  }, { "time_step", type<float>(),  }, { "margin", type<float>(), Param::Default, &margin_default } }, { &type<bool>(), QualType::None } };
			m.m_functions.push_back(&f);
		}
	}
}

namespace toy
{
	toy_core::toy_core()
		: Module("toy::core", { &two_type::m(), &two_jobs::m(), &two_ecs::m(), &two_math::m(), &two_geom::m(), &two_lang::m(), &toy_util::m() })
	{
		// setup reflection meta data
		toy_core_meta(*this);
	}
}

#ifdef TOY_CORE_MODULE
extern "C"
Module& getModule()
{
	return toy_core::m();
}
#endif
