//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <type/Unique.h>
#include <core/Forward.h>
#include <core/Physic/PhysicWorld.h>
#include <core/Physic/Collider.h>

#ifndef MUD_CPP_20
#include <unordered_map>
#endif

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

using namespace mud; namespace toy
{
#ifdef TRIGGER_COLLISIONS
	static void collisionStarted(btPersistentManifold* manifold);
	static void collisionEnded(btPersistentManifold* manifold);
#endif

	class refl_ TOY_CORE_EXPORT BulletMedium : public PhysicMedium
	{
	public:
        BulletMedium(World& world, Medium& medium);
        ~BulletMedium();

		virtual void update_contacts() override final;

        virtual void next_frame(size_t tick, size_t delta) override final;

		virtual object_ptr<ColliderImpl> make_collider(HCollider collider) override final;
		virtual object_ptr<SolidImpl> make_solid(HSolid solid) override final;

		virtual void add_solid(HCollider collider, HSolid solid) override final;
		virtual void remove_solid(HCollider collider, HSolid solid) override final;

		virtual void add_collider(HCollider collider) override final;
		virtual void remove_collider(HCollider collider) override final;

		void remove_contacts(uint32_t collider);

    public:
		size_t m_last_tick;
		unique_ptr<btCollisionConfiguration> m_collisionConfiguration;
        unique_ptr<btCollisionDispatcher> m_collisionDispatcher;
        unique_ptr<btBroadphaseInterface> m_broadphaseInterface;

		unique_ptr<btCollisionWorld> m_bullet_world;
        unique_ptr<btConstraintSolver> m_constraintSolver;

		btDynamicsWorld* m_dynamicsWorld = nullptr;

#ifndef TRIGGER_COLLISIONS
		struct pairhash
		{
			template <class T, class U>
			size_t operator()(const T& first, const U& second) const { return std::hash<T>()(first) ^ std::hash<U>()(second); }
		};

		pairhash m_hash;

		struct Contact
		{
			Contact() : m_tick(0) {}

			uint32_t m_col0;
			uint32_t m_col1;
			size_t m_tick;
			size_t m_index;
		};

		std::unordered_map<size_t, Contact> m_hash_contacts;
		std::vector<Contact*> m_contacts;

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

		object_ptr<PhysicMedium> create_sub_world(Medium& medium);

		vec3 ground_point(const Ray& ray);
		Collision raycast(const Ray& ray, short int mask);
    };
}
