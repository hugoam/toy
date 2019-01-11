#include <core/Api.h>
#include <emscripten/bind.h>

using namespace emscripten;

EMSCRIPTEN_BINDINGS(toy_core)
{
    
    // Enums
    enum_<toy::CollisionGroup>("toy::CollisionGroup")
        .value("CM_NOMASK", toy::CM_NOMASK)
        .value("CM_OBJECT", toy::CM_OBJECT)
        .value("CM_SOLID", toy::CM_SOLID)
        .value("CM_GROUND", toy::CM_GROUND)
        .value("CM_AREA", toy::CM_AREA)
        .value("CM_BUFFER", toy::CM_BUFFER)
        .value("CM_LIGHT", toy::CM_LIGHT)
        .value("CM_LIGHTREFLECTOR", toy::CM_LIGHTREFLECTOR)
        .value("CM_SOURCE", toy::CM_SOURCE)
        .value("CM_RECEPTOR", toy::CM_RECEPTOR)
        .value("CM_OBSTACLE", toy::CM_OBSTACLE)
        ;
    
    // Sequences
    
    // Arrays
    
    // Structs
    value_object<toy::Collision>("Collision")
        .field("first", &toy::Collision::m_first)
        .field("second", &toy::Collision::m_second)
        .field("hit_point", &toy::Collision::m_hit_point)
        ;
    value_object<mud::OwnedHandle<toy::Collider>>("OwnedHandle<toy::Collider>")
        ;
    value_object<mud::OwnedHandle<toy::Solid>>("OwnedHandle<toy::Solid>")
        ;
    value_object<mud::SparseHandle<toy::Collider>>("SparseHandle<toy::Collider>")
        ;
    value_object<mud::SparseHandle<toy::Solid>>("SparseHandle<toy::Solid>")
        ;
    value_object<mud::ComponentHandle<toy::Camera>>("ComponentHandle<toy::Camera>")
        ;
    value_object<mud::ComponentHandle<toy::Emitter>>("ComponentHandle<toy::Emitter>")
        ;
    value_object<mud::ComponentHandle<toy::EntityScript>>("ComponentHandle<toy::EntityScript>")
        ;
    value_object<mud::ComponentHandle<toy::Movable>>("ComponentHandle<toy::Movable>")
        ;
    value_object<mud::ComponentHandle<toy::Navblock>>("ComponentHandle<toy::Navblock>")
        ;
    value_object<mud::ComponentHandle<toy::Origin>>("ComponentHandle<toy::Origin>")
        ;
    value_object<mud::ComponentHandle<toy::Receptor>>("ComponentHandle<toy::Receptor>")
        ;
    value_object<mud::ComponentHandle<toy::Spatial>>("ComponentHandle<toy::Spatial>")
        ;
    value_object<mud::ComponentHandle<toy::Waypoint>>("ComponentHandle<toy::Waypoint>")
        ;
    value_object<mud::ComponentHandle<toy::WorldPage>>("ComponentHandle<toy::WorldPage>")
        ;
    
    // Classes
    class_<toy::BulletMedium>("BulletMedium")
        ;
    class_<toy::BulletShape>("BulletShape")
        ;
    class_<toy::Camera>("Camera")
        .constructor<>()
        .constructor<toy::HSpatial, float, float, float>()
        .property("lens_distance", &toy::Camera::m_lens_distance)
        .property("lens_angle", &toy::Camera::m_lens_angle)
        .property("near", &toy::Camera::m_near)
        .property("far", &toy::Camera::m_far)
        .property("aspect", &toy::Camera::m_aspect)
        ;
    class_<toy::Collider>("Collider")
        .constructor<>()
        .constructor<toy::HSpatial, toy::HMovable, const toy::CollisionShape&, toy::Medium&, toy::CollisionGroup>()
        .property("spatial", &toy::Collider::m_spatial)
        .property("movable", &toy::Collider::m_movable)
        .property("collision_shape", &toy::Collider::m_collision_shape)
        .property("medium", &toy::Collider::m_medium)
        .property("group", &toy::Collider::m_group)
        .property("object", &toy::Collider::m_object)
        .property("impl", &toy::Collider::impl, &toy::Collider::setImpl)
        ;
    class_<toy::ColliderImpl>("ColliderImpl")
        ;
    class_<toy::ColliderObject>("ColliderObject")
        ;
    class_<toy::CollisionShape>("CollisionShape")
        .constructor<>()
        .constructor<const mud::Shape&, const mud::vec3&, float>()
        ;
    class_<toy::ComponentPool>("ComponentPool")
        ;
    class_<toy::Core>("Core")
        ;
    class_<toy::DetourPath>("DetourPath")
        ;
    class_<toy::Emitter>("Emitter")
        .constructor<>()
        .constructor<toy::HSpatial>()
        ;
    class_<toy::EntityScript>("EntityScript")
        .constructor<>()
        .constructor<toy::HSpatial>()
        .property("logic_script", &toy::EntityScript::m_logic_script)
        .property("render_script", &toy::EntityScript::m_render_script)
        ;
    class_<toy::Medium>("Medium")
        .property("name", &toy::Medium::m_name)
        .property("occlusions", &toy::Medium::m_occlusions)
        .property("solid", &toy::Medium::m_solid)
        ;
    class_<toy::Movable>("Movable")
        .constructor<>()
        .constructor<toy::HSpatial>()
        .property("linear_velocity", &toy::Movable::m_linear_velocity)
        .property("angular_velocity", &toy::Movable::m_angular_velocity)
        .property("moving", &toy::Movable::m_moving)
        .property("previous_position", &toy::Movable::m_previous_position)
        .function("set_linear_velocity", &toy::Movable::set_linear_velocity)
        .function("modify_linear_velocity", &toy::Movable::modify_linear_velocity)
        .function("set_angular_velocity", &toy::Movable::set_angular_velocity)
        .function("modify_angular_velocity", &toy::Movable::modify_angular_velocity)
        ;
    class_<toy::Navblock>("Navblock")
        .constructor<>()
        .constructor<toy::HSpatial, toy::HWorldPage, toy::Navmesh&>()
        .property("navmesh", &toy::Navblock::m_navmesh)
        .property("auto_update", &toy::Navblock::m_auto_update)
        .property("updated", &toy::Navblock::m_updated)
        ;
    class_<toy::Navmesh>("Navmesh")
        .constructor<toy::World&>()
        .property("world", &toy::Navmesh::m_world)
        .property("updated", &toy::Navmesh::m_updated)
        .property("dirty", &toy::Navmesh::m_dirty)
        ;
    class_<toy::Origin>("Origin")
        .constructor<>()
        .constructor<toy::HSpatial>()
        ;
    class_<toy::Pathfinder>("Pathfinder")
        .constructor<toy::Navmesh&>()
        ;
    class_<toy::PhysicWorld>("PhysicWorld")
        .property("world", &toy::PhysicWorld::m_world)
        .function("ground_point", &toy::PhysicWorld::ground_point)
        .function("raycast", &toy::PhysicWorld::raycast)
        ;
    class_<toy::Receptor>("Receptor")
        .constructor<>()
        .constructor<toy::HSpatial>()
        .function("scope", &toy::Receptor::scope)
        ;
    class_<toy::Solid>("Solid")
        .constructor<>()
        .constructor<toy::HSpatial, toy::HMovable, toy::OCollider, bool, float>()
        .property("spatial", &toy::Solid::m_spatial)
        .property("collider", &toy::Solid::m_collider)
        .property("static", &toy::Solid::m_static)
        .property("mass", &toy::Solid::m_mass)
        ;
    class_<toy::SolidImpl>("SolidImpl")
        .function("linear_velocity", &toy::SolidImpl::linear_velocity)
        .function("angular_velocity", &toy::SolidImpl::angular_velocity)
        .function("set_linear_velocity", &toy::SolidImpl::set_linear_velocity)
        .function("set_angular_velocity", &toy::SolidImpl::set_angular_velocity)
        .function("set_angular_factor", &toy::SolidImpl::set_angular_factor)
        .function("impulse", &toy::SolidImpl::impulse)
        ;
    class_<toy::User>("User")
        ;
    class_<toy::Waypoint>("Waypoint")
        .constructor<>()
        .constructor<toy::HSpatial>()
        ;
    class_<toy::World>("World")
        .constructor<mud::Id, mud::Complex&, const std::string&, mud::JobSystem&>()
        .property("id", &toy::World::m_id)
        .property("complex", &toy::World::m_complex)
        .property("name", &toy::World::m_name)
        .property("origin", &toy::World::origin, &toy::World::setOrigin)
        .property("unworld", &toy::World::unworld, &toy::World::setUnworld)
        ;
    class_<toy::WorldClock>("WorldClock")
        ;
    class_<toy::WorldPage>("WorldPage")
        .constructor<>()
        .constructor<toy::HSpatial, bool, const mud::vec3&>()
        .property("open", &toy::WorldPage::m_open)
        .property("extents", &toy::WorldPage::m_extents)
        .property("world", &toy::WorldPage::m_world)
        .property("last_rebuilt", &toy::WorldPage::m_last_rebuilt)
        .function("build_geometry", &toy::WorldPage::build_geometry)
        .function("update_geometry", &toy::WorldPage::update_geometry)
        .function("ground_point", &toy::WorldPage::ground_point)
        .function("raycast_ground", &toy::WorldPage::raycast_ground)
        ;
    class_<toy::BulletCollider>("BulletCollider")
        ;
    class_<toy::BulletSolid>("BulletSolid")
        ;
    class_<toy::BulletWorld>("BulletWorld")
        .constructor<toy::World&>()
        ;
    class_<toy::DefaultWorld>("DefaultWorld")
        .constructor<const std::string&, mud::JobSystem&>()
        .property("world", &toy::DefaultWorld::m_world)
        .property("bullet_world", &toy::DefaultWorld::m_bullet_world)
        .property("navmesh", &toy::DefaultWorld::m_navmesh)
        ;
    class_<toy::PhysicScope>("PhysicScope")
        ;
    class_<toy::EmitterScope>("EmitterScope")
        ;
    class_<toy::NavmeshShape>("NavmeshShape")
        .constructor<toy::Navmesh&>()
        ;
    class_<toy::Obstacle>("Obstacle")
        .constructor<toy::HSpatial, toy::HMovable, toy::Medium&, const toy::CollisionShape&, float>()
        .property("shape", &toy::Obstacle::m_shape)
        .property("throughput", &toy::Obstacle::m_throughput)
        ;
    class_<toy::ReceptorScope>("ReceptorScope")
        ;
    class_<toy::SolidMedium>("SolidMedium")
        .constructor<>()
        .class_property("me", &toy::SolidMedium::me)
        ;
    class_<toy::SoundMedium>("SoundMedium")
        .constructor<>()
        .class_property("me", &toy::SoundMedium::me)
        ;
    class_<toy::Spatial>("Spatial")
        .constructor<>()
        .constructor<toy::HSpatial, const mud::vec3&, const mud::quat&>()
        .constructor<toy::World&, toy::HSpatial, const mud::vec3&, const mud::quat&>()
        .property("world", &toy::Spatial::m_world)
        .property("parent", &toy::Spatial::m_parent)
        .property("contents", &toy::Spatial::m_contents)
        .function("set_position", &toy::Spatial::set_position)
        .function("set_rotation", &toy::Spatial::set_rotation)
        ;
    class_<toy::VisualMedium>("VisualMedium")
        .constructor<>()
        .class_property("me", &toy::VisualMedium::me)
        ;
    class_<toy::WorldMedium>("WorldMedium")
        .constructor<>()
        .class_property("me", &toy::WorldMedium::me)
        ;
    
    // Functions
    function("move_2d", &toy::move_2d);
    function("steer_2d", &toy::steer_2d);
    
}
