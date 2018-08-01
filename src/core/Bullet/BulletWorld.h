//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <obj/Unique.h>
#include <core/Forward.h>
#include <core/Physic/PhysicWorld.h>

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

	class refl_ TOY_CORE_EXPORT SubBulletWorld : public PhysicMedium
	{
	public:
        SubBulletWorld(World& world, Medium& medium);
        ~SubBulletWorld();

		void update_contacts();

        void next_frame(size_t tick, size_t delta);

		virtual object_ptr<ColliderImpl> make_collider(Collider& collider);
		virtual object_ptr<ColliderImpl> make_solid(Solid& solid);

		void add_solid(Solid& solid);
		void remove_solid(Solid& solid);

		void add_collider(Collider& collider);
		void remove_collider(Collider& collider);

		void remove_contacts(Collider& collider);

    public:
		size_t m_last_tick;
		unique_ptr<btCollisionConfiguration> m_collisionConfiguration;
        unique_ptr<btCollisionDispatcher> m_collisionDispatcher;
        unique_ptr<btBroadphaseInterface> m_broadphaseInterface;

		unique_ptr<btCollisionWorld> m_bullet_world;
        unique_ptr<btConstraintSolver> m_constraintSolver;

		btDynamicsWorld* m_dynamicsWorld = nullptr;

		std::vector<Solid*> m_solids;

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

			Collider* m_col0;
			Collider* m_col1;
			size_t m_tick;
			size_t m_index;
		};

		std::unordered_map<size_t, Contact> m_hashContacts;
		std::vector<Contact*> m_contacts;

		void remove_contact(Contact& contact, size_t index);

		void remove_contact(Collider& col0, Collider& col1);
		Contact& findContact(Collider& col0, Collider& col1);
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
