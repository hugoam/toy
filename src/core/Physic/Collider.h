//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <stl/memory.h>
#include <math/Vec.h>
#include <pool/Pool.h>
#include <core/Forward.h>
#include <core/Physic/CollisionGroup.h>
#include <core/Physic/CollisionShape.h>
#include <core/Movable/MotionState.h>

namespace toy
{
	struct refl_ TOY_CORE_EXPORT Collision
	{
		Collision() {}
		Collision(HCollider first, HCollider second, const vec3& hit_point) : m_first(first), m_second(second), m_hit_point(hit_point) {}
		attr_ HCollider m_first = {};
		attr_ HCollider m_second = {};
		attr_ vec3 m_hit_point = vec3(0.f);
	};

	class refl_ TOY_CORE_EXPORT ColliderImpl : public TransformSource
	{
	public:
		virtual ~ColliderImpl() {}

		virtual void update_transform(const vec3& position, const quat& rotation) = 0;
		virtual void update_transform() = 0;

		virtual void project(const vec3& position, vector<Collision>& collisions, short int mask) = 0;
		virtual void raycast(const vec3& position, vector<Collision>& collisions, short int mask) = 0;
		virtual Collision raycast(const vec3& position, short int mask) = 0;
	};

	class refl_ TOY_CORE_EXPORT ColliderObject
	{
	public:
		virtual ~ColliderObject() {}
		virtual void add_contact(Collider& collider, ColliderObject& object) { UNUSED(collider); UNUSED(object); }
		virtual void remove_contact(Collider& collider, ColliderObject& object) { UNUSED(collider); UNUSED(object); }
	};

    class refl_ TOY_CORE_EXPORT Collider
    {
	public:
		constr_ Collider() {}
		constr_ Collider(HSpatial spatial, HMovable movable, const CollisionShape& collision_shape, Medium& medium, CollisionGroup group);
        virtual ~Collider();

		Collider(Collider&& other) = default;
		Collider& operator=(Collider&& other) = default;

		attr_ HSpatial m_spatial;
		attr_ HMovable m_movable;
		attr_ CollisionShape m_collision_shape;
		attr_ Medium* m_medium = nullptr;
		attr_ CollisionGroup m_group;

		attr_ ColliderObject* m_object = nullptr;

		PhysicMedium* m_world;
		object<ColliderImpl> m_impl;

		attr_ ColliderImpl& impl() { return *m_impl; }

		MotionState m_motion_state;

		void init(object<ColliderImpl> impl);

		void next_frame(size_t tick, size_t delta);
		void next_frame(Spatial& spatial, size_t tick, size_t delta);
		void next_frame(Spatial& spatial, Movable& movable, size_t tick, size_t delta);

		ColliderImpl* operator->() { return m_impl.get(); }
		const ColliderImpl* operator->() const { return m_impl.get(); }

		static OCollider create(HSpatial spatial, HMovable movable, const CollisionShape& collision_shape, Medium& medium, CollisionGroup group);
		static void destroy(HCollider solid);
    };

	class refl_ TOY_CORE_EXPORT SolidImpl : public TransformSource, public MotionSource
	{
	public:
		virtual ~SolidImpl() {}

		virtual void update_transform(const vec3& position, const quat& rotation) = 0;
		virtual void update_motion(const vec3& linear_velocity, const vec3& angular_velocity) = 0;

		meth_ virtual vec3 linear_velocity() = 0;
		meth_ virtual vec3 angular_velocity() = 0;

		meth_ virtual void set_linear_velocity(const vec3& force) = 0;
		meth_ virtual void set_angular_velocity(const vec3& torque) = 0;
		meth_ virtual void set_angular_factor(const vec3& factor) = 0;

		virtual void set_force(const vec3& force) = 0;
		virtual void set_torque(const vec3& torque) = 0;

		meth_ virtual void impulse(const vec3& force, const vec3& point) = 0;

		virtual void impulse_force(const vec3& force) = 0;
		virtual void impulse_torque(const vec3& torque) = 0;
	};

	class refl_ TOY_CORE_EXPORT Solid
	{
	public:
		Solid() {}
		Solid(HSpatial spatial, HMovable movable, OCollider collider, bool isstatic, float mass = 0.f);
		virtual ~Solid();

		Solid(Solid&& other) = default;
		Solid& operator=(Solid&& other) = default;

		attr_ HSpatial m_spatial;
		//attr_ nomut_ OCollider m_collider;
		OCollider m_collider;
		attr_ bool m_static = false;
		attr_ float m_mass = 0.f;

		void init(object<SolidImpl> impl);

		object<SolidImpl> m_impl;

		SolidImpl* operator->() { return m_impl.get(); }
		const SolidImpl* operator->() const { return m_impl.get(); }

		static OSolid create(HSpatial spatial, HMovable movable, const CollisionShape& collision_shape, Medium& medium, CollisionGroup group, bool isstatic, float mass = 0.f);
		static OSolid create(HSpatial spatial, HMovable movable, const CollisionShape& collision_shape, bool isstatic, float mass = 0.f);
		static void destroy(HSolid solid);
	};
}

namespace two
{
	template <>
	struct DestroyHandle<toy::Collider>
	{
		static void destroy(const SparseHandle<toy::Collider>& handle) { toy::Collider::destroy(handle); }
	};

	template <>
	struct DestroyHandle<toy::Solid>
	{
		static void destroy(const SparseHandle<toy::Solid>& handle) { toy::Solid::destroy(handle); }
	};
}
