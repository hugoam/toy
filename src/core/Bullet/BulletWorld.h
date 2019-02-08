//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <stl/unordered_map.h>
#include <type/Unique.h>
#include <core/Forward.h>
#include <core/Physic/PhysicWorld.h>
#include <core/Physic/Collider.h>

class btCollisionWorld;
class btDynamicsWorld;
class btDiscreteDynamicsWorld;
class btBroadphaseInterface;
class btConstraintSolver;

class btCollisionShape;
class btStridingMeshInterface;
class btCollisionObject;
class btRigidBody;
class btPersistentManifold;

class btCollisionConfiguration;
class btCollisionDispatcher;

namespace toy
{
#ifdef TRIGGER_COLLISIONS
	static void collisionStarted(btPersistentManifold* manifold);
	static void collisionEnded(btPersistentManifold* manifold);
#endif

	class refl_ TOY_CORE_EXPORT BulletMedium : public PhysicMedium
	{
	public:
        BulletMedium(World& world, BulletWorld& bullet_world, Medium& medium);
        ~BulletMedium();

		virtual void update_contacts() override final;

        virtual void next_frame(size_t tick, size_t delta) override final;

		virtual object<ColliderImpl> make_collider(HCollider collider) override final;
		virtual object<SolidImpl> make_solid(HSolid solid) override final;

		virtual void add_solid(HCollider collider, HSolid solid) override final;
		virtual void remove_solid(HCollider collider, HSolid solid) override final;

		virtual void add_collider(HCollider collider) override final;
		virtual void remove_collider(HCollider collider) override final;

		virtual void project(HCollider collider, const vec3& position, const quat& rotation, vector<Collision>& collisions, short int mask) override final;
		virtual void raycast(HCollider collider, const vec3& start, const vec3& end, vector<Collision>& collisions, short int mask) override final;
		virtual Collision raycast(HCollider collider, const vec3& start, const vec3& end, short int mask) override final;

		void remove_contacts(uint32_t collider);

    public:
		BulletWorld& m_bullet_world;

		size_t m_last_tick;
        unique<btCollisionDispatcher> m_collision_dispatcher;
        unique<btBroadphaseInterface> m_broadphase_interface;

		unique<btCollisionWorld> m_collision_world;
        unique<btConstraintSolver> m_constraint_solver;

		btDynamicsWorld* m_dynamics_world = nullptr;

#ifndef TRIGGER_COLLISIONS
		uint64_t hash(uint32_t a, uint32_t b) { return uint64_t(a) | (uint64_t(b) << 32); }
		uint64_t pair_hash(uint32_t a, uint32_t b) { return a < b ? hash(a, b) : hash(b, a); }

		struct Contact
		{
			Contact() : m_tick(0) {}

			uint32_t m_col0;
			uint32_t m_col1;
			size_t m_tick;
			size_t m_index;
		};

		unordered_map<uint64_t, Contact> m_hash_contacts;
		vector<Contact*> m_contacts;

		void remove_contact(Contact& contact, size_t index);

		void remove_contact(uint32_t col0, uint32_t col1);
		Contact& find_contact(uint32_t col0, uint32_t col1);
#endif
	};

	class refl_ TOY_CORE_EXPORT BulletWorld : public PhysicWorld
	{
	public:
		constr_ BulletWorld(World& world);
        ~BulletWorld();

		object<PhysicMedium> create_sub_world(Medium& medium);

		vec3 ground_point(const Ray& ray);
		Collision raycast(const Ray& ray, short int mask);
    };
}
