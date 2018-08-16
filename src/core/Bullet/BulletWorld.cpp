//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.


#include <core/Types.h>
#include <core/Bullet/BulletWorld.h>

#include <geom/Geom.h>
#include <geom/Shape.h>

#define TOY_PRIVATE
#include <core/Bullet.h>

#include <core/World/World.h>
#include <core/Bullet/BulletSolid.h>
#include <core/Bullet/BulletCollider.h>
#include <core/Physic/Solid.h>

#include <math/Timer.h>

#if _MSC_VER
#	pragma warning (push)
#	pragma warning (disable : 4127) // members are private, so there's no risk them being accessed by the user
#endif

#include <BulletDynamics/ConstraintSolver/btSequentialImpulseConstraintSolver.h>
#include <BulletDynamics/Dynamics/btDiscreteDynamicsWorld.h>

#include <BulletCollision/CollisionDispatch/btGhostObject.h>
#include <btBulletCollisionCommon.h>

#if _MSC_VER
#	pragma warning (pop)
#endif

#ifdef TRIGGER_COLLISIONS
extern CollisionStartedCallback gCollisionStartedCallback;
extern CollisionEndedCallback gCollisionEndedCallback;
#endif

using namespace mud; namespace toy
{
	static void collisionStarted(btPersistentManifold* manifold)
	{
		Collider* col0 = (Collider*)((btCollisionObject*)manifold->getBody0())->getUserPointer();
		Collider* col1 = (Collider*)((btCollisionObject*)manifold->getBody1())->getUserPointer();

		if(&col0->m_entity == &col1->m_entity)
			return;

		if (col0->m_object && col1->m_object)
		{
			//printf("DEBUG: Add contact %i : %i\n", int(col0->m_entity.m_id), int(col1->m_entity.m_id));
			col0->m_object->add_contact(*col1);
			col1->m_object->add_contact(*col0);
		}
	}

#ifdef TRIGGER_COLLISIONS
	static void collisionEnded(btPersistentManifold* manifold)
	{
		Collider* col0 = (Collider*)((btCollisionObject*)manifold->getBody0())->getUserPointer();
		Collider* col1 = (Collider*)((btCollisionObject*)manifold->getBody1())->getUserPointer();

		if(&col0->m_entity == &col1->m_entity)
			return;

		if (col0->m_object && col1->m_object)
		{
			// printf << "Remove contact " << col0->m_entity.m_id << " : " << col1->m_entity.m_id << std::endl;
			col0->m_object->remove_contact(*col1);
			col1->m_object->remove_contact(*col0); // @todo : replace this with buffered action (set a flag on bullet object ?) to not loop infinitely from bullet code
		}
	}
#endif

#define BULLET_WORLD_SCALE 10000.f

    SubBulletWorld::SubBulletWorld(World& world, Medium& medium)
        : PhysicMedium(world, medium)
        , m_collisionConfiguration(make_unique<btDefaultCollisionConfiguration>())
        , m_collisionDispatcher(make_unique<btCollisionDispatcher>(m_collisionConfiguration.get()))
		, m_broadphaseInterface(make_unique<btAxisSweep3>(btVector3/*worldAabbMin*/(-1.f,-1.f,-1.f) * -BULLET_WORLD_SCALE, btVector3/*worldAabbMax*/(1.f, 1.f, 1.f) * BULLET_WORLD_SCALE, /*maxProxies*/32000)) // @crash btAssert(m_firstFreeHandle) is limited by this setting
		//, m_broadphaseInterface(make_unique<btDbvtBroadphase>()) // @crash btAssert(m_firstFreeHandle) is limited by this setting
		
	{
		if(medium.m_solid)
		{
			m_constraintSolver = make_unique<btSequentialImpulseConstraintSolver>();
			m_bullet_world = make_unique<btDiscreteDynamicsWorld>(m_collisionDispatcher.get(), m_broadphaseInterface.get(), m_constraintSolver.get(), m_collisionConfiguration.get());
			m_dynamicsWorld = static_cast<btDiscreteDynamicsWorld*>(m_bullet_world.get());
		}
		else
		{
			m_bullet_world = make_unique<btCollisionWorld>(m_collisionDispatcher.get(), m_broadphaseInterface.get(), m_collisionConfiguration.get());
		}
	}

    SubBulletWorld::~SubBulletWorld()
    {}

	object_ptr<ColliderImpl> SubBulletWorld::make_collider(Collider& collider)
	{
		return make_object<BulletCollider>(*this, collider);
	}

	object_ptr<ColliderImpl> SubBulletWorld::make_solid(Solid& solid)
	{
		return make_object<BulletSolid>(*this, solid);
	}

	void SubBulletWorld::add_solid(Solid& solid)
	{
		//printf("DEBUG: Add solid to medium %s\n", m_medium.m_name.c_str());
		m_dynamicsWorld->addRigidBody(as<BulletSolid>(*solid.m_impl).m_rigid_body, solid.m_group, m_medium.mask(solid.m_group));
		m_solids.push_back(&solid);
	}

	void SubBulletWorld::remove_solid(Solid& solid)
	{
		m_dynamicsWorld->removeRigidBody(as<BulletSolid>(*solid.m_impl).m_rigid_body);
		this->remove_contacts(solid);
		vector_remove(m_solids, &solid);
	}

	void SubBulletWorld::add_collider(Collider& collider)
	{
		//printf("DEBUG: Add collision object to medium %s\n", m_medium.m_name.c_str());
		m_bullet_world->addCollisionObject(as<BulletCollider>(*collider.m_impl).m_collision_object.get(), collider.m_group, m_medium.mask(collider.m_group));
	}

	void SubBulletWorld::remove_collider(Collider& collider)
	{
		m_bullet_world->removeCollisionObject(as<BulletCollider>(*collider.m_impl).m_collision_object.get());
		this->remove_contacts(collider);
	}

	void SubBulletWorld::remove_contacts(Collider& collider)
	{
		for(int i = m_contacts.size() - 1; i >= 0; --i)
		{
			Contact& contact = *m_contacts[i];
			if(contact.m_col0 == &collider || contact.m_col1 == &collider)
				this->remove_contact(contact, i);
		}
	}

	void SubBulletWorld::remove_contact(Contact& contact, size_t index)
	{
#if 0 // DEBUG
		Entity& entity0 = contact.m_col0->m_entity;
		Entity& entity1 = contact.m_col1->m_entity;
		printf("DEBUG: %s remove contact %s %u : %s %u\n", m_medium.m_name.c_str(), entity0.m_complex.m_type.m_name, entity0.m_id, entity1.m_complex.m_type.m_name, entity1.m_id);
#endif
		if(contact.m_col0->m_object && contact.m_col1->m_object)
		{
			contact.m_col0->m_object->remove_contact(*contact.m_col1);
			contact.m_col1->m_object->remove_contact(*contact.m_col0);
		}

		m_contacts.back()->m_index = index;
		std::swap(m_contacts[index], m_contacts.back());
		m_contacts.pop_back();

		remove_contact(*contact.m_col0, *contact.m_col1);
	}

	void SubBulletWorld::update_contacts()
	{
#ifndef TRIGGER_COLLISIONS
		btManifoldArray manifoldArray;

		int numManifolds = m_bullet_world->getDispatcher()->getNumManifolds();
		for(int i = 0; i<numManifolds; i++)
		{
			btPersistentManifold* manifold = m_bullet_world->getDispatcher()->getManifoldByIndexInternal(i);

			int numContacts = manifold->getNumContacts();
			for(int j = 0; j<numContacts; j++)
			{
				btManifoldPoint& pt = manifold->getContactPoint(j);

				if(pt.getDistance() < 0.f)
				{
					Collider* col0 = (Collider*)((btCollisionObject*)manifold->getBody0())->getUserPointer();
					Collider* col1 = (Collider*)((btCollisionObject*)manifold->getBody1())->getUserPointer();

					Contact& contact = findContact(*col0, *col1);

					if(contact.m_tick == 0)
					{
						collisionStarted(manifold);
						contact.m_col0 = col0;
						contact.m_col1 = col1;
						contact.m_index = m_contacts.size();
						m_contacts.push_back(&contact);
					}

					contact.m_tick = m_last_tick;
				}
			}
		}

		for(int i = m_contacts.size() - 1; i >= 0; --i)
		{
			Contact& contact = *m_contacts[i];
			if(contact.m_tick < m_last_tick)
				this->remove_contact(contact, i);
		}
#endif
	}

	void SubBulletWorld::remove_contact(Collider& col0, Collider& col1)
	{
		m_hashContacts.erase(&col0 < &col1 ? m_hash(&col0, &col1) : m_hash(&col1, &col0));
	}

	SubBulletWorld::Contact& SubBulletWorld::findContact(Collider& col0, Collider& col1)
	{
		return m_hashContacts[&col0 < &col1 ? m_hash(&col0, &col1) : m_hash(&col1, &col0)];
	}

    // @note : this assume that we cap the framerate at 120fps, and that it shouldn't go lower than 12fps
    void SubBulletWorld::next_frame(size_t tick, size_t delta)
    {
		m_last_tick = tick;

		if(m_dynamicsWorld)
#ifdef MUD_PLATFORM_EMSCRIPTEN
			m_dynamicsWorld->stepSimulation(delta * c_tick_interval, 3, 0.032f);
#else
			m_dynamicsWorld->stepSimulation(delta * c_tick_interval, 3);
#endif
		else
			m_bullet_world->performDiscreteCollisionDetection();

		this->update_contacts();
    }

	BulletWorld::BulletWorld(World& world)
		: PhysicWorld(world)
    {
#ifdef TRIGGER_COLLISIONS
		gCollisionStartedCallback = collisionStarted;
		gCollisionEndedCallback = collisionEnded;
#endif
	}

	BulletWorld::~BulletWorld()
    {}

	object_ptr<PhysicMedium> BulletWorld::create_sub_world(Medium& medium)
	{
		return make_object<SubBulletWorld>(m_world, medium);
	}

	vec3 BulletWorld::ground_point(const Ray& ray)
	{
		Collision collision = this->raycast(ray, CM_GROUND);
		return collision.m_hit_point;
	}

	Collision BulletWorld::raycast(const Ray& ray, short int mask)
	{
		btCollisionWorld::ClosestRayResultCallback callback(to_btvec3(ray.m_start), to_btvec3(ray.m_end));
		callback.m_collisionFilterMask = mask;
		callback.m_collisionFilterGroup = btBroadphaseProxy::AllFilter;

		SubBulletWorld& subWorld = as<SubBulletWorld>(this->sub_world(SolidMedium::me));
		subWorld.m_bullet_world->rayTest(to_btvec3(ray.m_start), to_btvec3(ray.m_end), callback);

		if(callback.hasHit())
			return { nullptr, static_cast<Collider*>(callback.m_collisionObject->getUserPointer()), to_vec3(callback.m_hitPointWorld) };
		return {};
	}
}
