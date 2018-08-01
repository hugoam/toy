//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <infra/Updatable.h>
#include <math/Vec.h>
#include <core/Forward.h>
#include <core/Physic/CollisionGroup.h>
#include <core/Physic/CollisionShape.h>
#include <core/Entity/EntityObserver.h>
#include <core/Movable/MotionState.h>

#ifndef MUD_CPP_20
#include <memory>
#endif

using namespace mud; namespace toy
{
	struct refl_ TOY_CORE_EXPORT Collision
	{
		Collision() {}
		Collision(Collider* first, Collider* second, const vec3& hit_point) : m_first(first), m_second(second), m_hit_point(hit_point) {}
		attr_ Collider* m_first = nullptr;
		attr_ Collider* m_second = nullptr;
		attr_ vec3 m_hit_point = Zero3;
	};

	class refl_ TOY_CORE_EXPORT ColliderImpl : public MotionSource
	{
	public:
		virtual ~ColliderImpl() {}

        //virtual void update() = 0;
		virtual void force_update() = 0;

		virtual void update_transform(const vec3& position, const quat& rotation) = 0;
		virtual void update_motion(const vec3& linear_velocity, const vec3& angular_velocity) = 0;
		virtual void update_transform() = 0;

		virtual void project(const vec3& position, std::vector<Collision>& collisions, short int mask) = 0;
		virtual void raycast(const vec3& position, std::vector<Collision>& collisions, short int mask) = 0;
		virtual Collision raycast(const vec3& position, short int mask) = 0;

		virtual vec3 linear_velocity() = 0;
		virtual vec3 angular_velocity() = 0;

		virtual void set_linear_velocity(const vec3& force) = 0;
		virtual void set_angular_velocity(const vec3& torque) = 0;
		virtual void set_angular_factor(const vec3& factor) = 0;

		virtual void set_force(const vec3& force) = 0;
		virtual void set_torque(const vec3& torque) = 0;

		virtual void impulse(const vec3& force, const vec3& point) = 0;

		virtual void impulse_force(const vec3& force) = 0;
		virtual void impulse_torque(const vec3& torque) = 0;
	};

	class refl_ TOY_CORE_EXPORT ColliderObject
	{
	public:
		virtual ~ColliderObject() {}
		virtual void add_contact(Collider& object) { UNUSED(object); }
		virtual void remove_contact(Collider& object) { UNUSED(object); }
	};

    class refl_ TOY_CORE_EXPORT Collider : public NonCopy, public Updatable, public HookObserver
    {
	public:
		Collider(Entity& entity, ColliderObject& object, const CollisionShape& collision_shape, Medium& medium, CollisionGroup group, bool init = true);
        virtual ~Collider();

		attr_ Entity& m_entity;
		ColliderObject& m_object;
		CollisionShape m_collision_shape;
		attr_ Medium& m_medium;
		CollisionGroup m_group;

		PhysicMedium& m_world;
		object_ptr<ColliderImpl> m_impl;

		MotionState m_motion_state;

		void init();

		void next_frame(size_t tick, size_t delta);

		virtual void unhooked();
		virtual void hooked();

		ColliderImpl* operator->() { return m_impl.get(); }
		const ColliderImpl* operator->() const { return m_impl.get(); }
    };

	class refl_ TOY_CORE_EXPORT Solid : public Collider
	{
	public:
		Solid(Entity& entity, ColliderObject& object, const CollisionShape& collision_shape, Medium& medium, CollisionGroup group, bool isstatic, float mass = 0.f);
		Solid(Entity& entity, ColliderObject& object, const CollisionShape& collision_shape, bool isstatic, float mass = 0.f);
		~Solid();

		bool m_static;
		float m_mass;

		virtual void unhooked();
		virtual void hooked();
	};
}
