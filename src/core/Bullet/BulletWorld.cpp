//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#ifndef USE_STL
#include <stl/vector.hpp>
#endif
#include <math/Timer.h>
#include <geom/Geom.h>
#include <geom/Shape.h>
#include <core/Types.h>
#include <core/Bullet/BulletWorld.h>
#include <core/World/World.hpp>
#include <core/Bullet/BulletSolid.h>
#include <core/Bullet/BulletCollider.h>
#include <core/Physic/Solid.h>

#ifdef _MSC_VER
#	pragma warning (push)
#	pragma warning (disable : 4127) // members are private, so there's no risk them being accessed by the user
#	pragma warning (disable : 4100)
#	pragma warning (disable : 4305)
#	pragma warning (disable : 5033) // @todo deal with this ?
#endif

#include <core/Bullet/Bullet.h.inl>

#include <BulletDynamics/ConstraintSolver/btSequentialImpulseConstraintSolver.h>
#include <BulletDynamics/Dynamics/btDiscreteDynamicsWorld.h>

#include <BulletCollision/CollisionDispatch/btGhostObject.h>
#include <btBulletCollisionCommon.h>

#ifdef _MSC_VER
#	pragma warning (pop)
#endif

#ifdef TRIGGER_COLLISIONS
extern CollisionStartedCallback gCollisionStartedCallback;
extern CollisionEndedCallback gCollisionEndedCallback;
#endif

namespace toy
{
#ifdef TRIGGER_COLLISIONS
	static void collisionStarted(btPersistentManifold* manifold)
	{
	}

	static void collisionEnded(btPersistentManifold* manifold)
	{
		Collider* col0 = (Collider*)((btCollisionObject*)manifold->getBody0())->getUserPointer();
		Collider* col1 = (Collider*)((btCollisionObject*)manifold->getBody1())->getUserPointer();

		if(&col0->m_spatial == &col1->m_spatial)
			return;

		if(col0->m_object && col1->m_object)
		{
			// printf << "Remove contact " << col0->m_spatial.m_id << " : " << col1->m_spatial.m_id << endl;
			col0->m_object->remove_contact(*col1);
			col1->m_object->remove_contact(*col0); // @todo : replace this with buffered action (set a flag on bullet object ?) to not loop infinitely from bullet code
		}
	}
#endif

	HCollider object_collider(BulletWorld& bullet_world, const btCollisionObject& object)
	{
		SparsePool<Collider>& pool = bullet_world.m_world.pool<Collider>();
		uint32_t handle = uint32_t((uintptr_t)object.getUserPointer());
		return { pool, handle };
	}

#define BULLET_WORLD_SCALE 10000.f

    BulletMedium::BulletMedium(World& world, BulletWorld& bullet_world, Medium& medium)
        : PhysicMedium(world, medium)
		, m_bullet_world(bullet_world)
	{
		static btDefaultCollisionConfiguration configuration;

		m_collision_dispatcher = make_unique<btCollisionDispatcher>(&configuration);
		m_broadphase_interface = make_unique<btAxisSweep3>(btVector3(-1.f, -1.f, -1.f) * BULLET_WORLD_SCALE, btVector3(1.f, 1.f, 1.f) * BULLET_WORLD_SCALE, uint16_t(32000)); // @crash btAssert(m_firstFreeHandle) is limited by this setting
		//, m_broadphaseInterface(make_unique<btDbvtBroadphase>()) // @crash btAssert(m_firstFreeHandle) is limited by this setting

		if(medium.m_solid)
		{
			m_constraint_solver = make_unique<btSequentialImpulseConstraintSolver>();
			m_collision_world = make_unique<btDiscreteDynamicsWorld>(m_collision_dispatcher.get(), m_broadphase_interface.get(), m_constraint_solver.get(), &configuration);
			m_dynamics_world = static_cast<btDiscreteDynamicsWorld*>(m_collision_world.get());
		}
		else
		{
			m_collision_world = make_unique<btCollisionWorld>(m_collision_dispatcher.get(), m_broadphase_interface.get(), &configuration);
		}
	}

    BulletMedium::~BulletMedium()
    {}

	object<ColliderImpl> BulletMedium::make_collider(HCollider collider)
	{
		return oconstruct<BulletCollider>(*this, collider->m_spatial, collider, collider->m_collision_shape);
	}

	object<SolidImpl> BulletMedium::make_solid(HSolid solid)
	{
		return oconstruct<BulletSolid>(*this, as<BulletCollider>(*solid->m_collider->m_impl), solid->m_spatial, solid->m_collider, solid);
	}

	void BulletMedium::add_solid(HCollider collider, HSolid solid)
	{
		collider->m_impl = this->make_collider(collider);
		solid->m_impl = this->make_solid(solid);
		m_dynamics_world->addRigidBody(as<BulletSolid>(*solid->m_impl).m_rigid_body, collider->m_group, m_medium.mask(collider->m_group));
	}

	void BulletMedium::remove_solid(HCollider collider, HSolid solid)
	{
		m_dynamics_world->removeRigidBody(as<BulletSolid>(*solid->m_impl).m_rigid_body);
		this->remove_contacts(collider.m_handle);
		solid->m_impl = nullptr;
		collider->m_impl = nullptr;
	}

	void BulletMedium::add_collider(HCollider collider)
	{
		collider->m_impl = this->make_collider(collider);
		m_collision_world->addCollisionObject(as<BulletCollider>(*collider->m_impl).m_collision_object.get(), collider->m_group, m_medium.mask(collider->m_group));
	}

	void BulletMedium::remove_collider(HCollider collider)
	{
		m_collision_world->removeCollisionObject(as<BulletCollider>(*collider->m_impl).m_collision_object.get());
		this->remove_contacts(collider.m_handle);
		collider->m_impl = nullptr;
	}

	class ContactCheck : public btCollisionWorld::ContactResultCallback
	{
	public:
		struct Contact { const btCollisionObject* first; const btCollisionObject* second; btVector3 position; };

		ContactCheck(float margin = 0.f)
			: m_margin(margin)
		{}

		ContactCheck& operator=(const ContactCheck&) = delete;

		btScalar addSingleResult(btManifoldPoint &cp, const btCollisionObjectWrapper *colObj0, int partId0, int index0, const btCollisionObjectWrapper *colObj1, int partId1, int index1)
		{
			UNUSED(index0); UNUSED(index1); UNUSED(partId0); UNUSED(partId1);
			if(cp.getDistance() < m_margin)
				m_contacts.push_back({ colObj0->m_collisionObject, colObj1->m_collisionObject, btVector3(0.f, 0.f, 0.f) });

			return 0.f;
		}

		vector<Contact> m_contacts;
		float m_margin;
	};

	void project_test(btCollisionWorld& collision_world, btCollisionObject& collision_object, ContactCheck& callback, const vec3& position, const quat& rotation, short int mask)
	{
		btTransform transform = collision_object.getWorldTransform();
		collision_object.setWorldTransform(btTransform(to_btquat(rotation), to_btvec3(position)));

		callback.m_collisionFilterGroup = mask;
		callback.m_collisionFilterMask = mask;

		collision_world.updateSingleAabb(&collision_object);
		collision_world.contactTest(&collision_object, callback);

		collision_object.setWorldTransform(transform);
	}

	void ray_test(btCollisionWorld& collision_world, btCollisionWorld::RayResultCallback& callback, const vec3& start, const vec3& end, short int mask)
	{
		callback.m_collisionFilterMask = mask;
		callback.m_collisionFilterGroup = btBroadphaseProxy::AllFilter;
		collision_world.rayTest(to_btvec3(start), to_btvec3(end), callback);
	}

	void BulletMedium::project(HCollider collider, const vec3& position, const quat& rotation, vector<Collision>& collisions, short int mask)
	{
		ContactCheck callback;
		BulletCollider& bullet_collider = as<BulletCollider>(*collider->m_impl);
		project_test(*m_collision_world, *bullet_collider.m_collision_object, callback, position, rotation, mask);

		SparsePool<Collider>& pool = m_bullet_world.m_world.pool<Collider>();

		for(ContactCheck::Contact& contact : callback.m_contacts)
		{
			HCollider first = { pool, uint32_t((uintptr_t)contact.first->getUserPointer()) };
			HCollider second = { pool, uint32_t((uintptr_t)contact.second->getUserPointer()) };
			collisions.push_back({ collider, second.m_handle == collider.m_handle ? first : second, to_vec3(contact.position) });
		}
	}
	
	void BulletMedium::raycast(HCollider collider, const vec3& start, const vec3& end, vector<Collision>& collisions, short int mask)
	{
		btCollisionWorld::AllHitsRayResultCallback callback(to_btvec3(start), to_btvec3(end));
		ray_test(*m_collision_world, callback, start, end, mask);

		SparsePool<Collider>& pool = m_bullet_world.m_world.pool<Collider>();

		for(int i = 0; i < callback.m_collisionObjects.size(); ++i)
		{
			HCollider collision = { pool, uint32_t((uintptr_t)callback.m_collisionObjects[i]->getUserPointer()) };
			collisions.push_back({ collider, collision, to_vec3(callback.m_hitPointWorld[i]) });
		}
	}

	Collision BulletMedium::raycast(HCollider collider, const vec3& start, const vec3& end, short int mask)
	{
		btCollisionWorld::ClosestRayResultCallback callback(to_btvec3(start), to_btvec3(end));
		ray_test(*m_collision_world, callback, start, end, mask);

		if(callback.m_collisionObject)
			return { collider, object_collider(m_bullet_world, *callback.m_collisionObject), to_vec3(callback.m_hitPointWorld) };
		return {};
	}

	void BulletMedium::remove_contacts(uint32_t collider)
	{
		for(int i = int(m_contacts.size()) - 1; i >= 0; --i)
		{
			Contact& contact = *m_contacts[i];
			if(contact.m_col0 == collider || contact.m_col1 == collider)
				this->remove_contact(contact, i);
		}
	}

	void BulletMedium::remove_contact(Contact& contact, size_t index)
	{
		SparsePool<Collider>& pool = m_bullet_world.m_world.pool<Collider>();

		Collider& first = pool.get(contact.m_col0);
		Collider& second = pool.get(contact.m_col1);

		if(first.m_object && second.m_object)
		{
			first.m_object->remove_contact(second, *second.m_object);
			second.m_object->remove_contact(first, *first.m_object);
		}

		m_contacts.back()->m_index = index;
		swap(m_contacts[index], m_contacts.back());
		m_contacts.pop_back();

		remove_contact(contact.m_col0, contact.m_col1);
	}

	void BulletMedium::update_contacts()
	{
#ifndef TRIGGER_COLLISIONS
		btManifoldArray manifoldArray;

		SparsePool<Collider>& pool = m_bullet_world.m_world.pool<Collider>();

		int numManifolds = m_collision_world->getDispatcher()->getNumManifolds();
		for(int i = 0; i<numManifolds; i++)
		{
			btPersistentManifold* manifold = m_collision_world->getDispatcher()->getManifoldByIndexInternal(i);

			uint32_t col0 = uint32_t((uintptr_t)((btCollisionObject*)manifold->getBody0())->getUserPointer());
			uint32_t col1 = uint32_t((uintptr_t)((btCollisionObject*)manifold->getBody1())->getUserPointer());

			Collider& first = pool.get(col0);
			Collider& second = pool.get(col1);

			if(col0 == col1 || first.m_object == second.m_object)
				continue;

			int numContacts = manifold->getNumContacts();
			for(int j = 0; j<numContacts; j++)
			{
				btManifoldPoint& pt = manifold->getContactPoint(j);

				if(pt.getDistance() < 0.f)
				{
					Contact& contact = this->find_contact(col0, col1);

					if(contact.m_tick == 0)
					{
						if(first.m_object && second.m_object)
						{
							first.m_object->add_contact(second, *second.m_object);
							second.m_object->add_contact(first, *first.m_object);
						}

						contact.m_col0 = col0;
						contact.m_col1 = col1;
						contact.m_index = m_contacts.size();
						m_contacts.push_back(&contact);
					}

					contact.m_tick = m_last_tick;
				}
			}
		}

		for(int i = int(m_contacts.size()) - 1; i >= 0; --i)
		{
			Contact& contact = *m_contacts[i];
			if(contact.m_tick < m_last_tick)
				this->remove_contact(contact, i);
		}
#endif
	}

	void BulletMedium::remove_contact(uint32_t col0, uint32_t col1)
	{
		m_hash_contacts.erase(pair_hash(col0, col1));
	}

	BulletMedium::Contact& BulletMedium::find_contact(uint32_t col0, uint32_t col1)
	{
		return m_hash_contacts[pair_hash(col0, col1)];
	}

    // @note : this assume that we cap the framerate at 120fps, and that it shouldn't go lower than 12fps
    void BulletMedium::next_frame(size_t tick, size_t delta)
    {
		m_last_tick = tick;

		if(m_dynamics_world)
#ifdef TWO_PLATFORM_EMSCRIPTEN
			m_dynamics_world->stepSimulation(float(delta * c_tick_interval), 3, 0.032f);
#else
			m_dynamics_world->stepSimulation(float(delta * c_tick_interval), 3);
#endif
		else
			m_collision_world->performDiscreteCollisionDetection();

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

	object<PhysicMedium> BulletWorld::create_sub_world(Medium& medium)
	{
		return oconstruct<BulletMedium>(m_world, *this, medium);
	}

	vec3 BulletWorld::ground_point(const Ray& ray)
	{
		Collision collision = this->raycast(ray, CM_GROUND);
		return collision.m_hit_point;
	}

	Collision BulletWorld::raycast(const Ray& ray, short int mask)
	{
		BulletMedium& bullet_medium = as<BulletMedium>(this->sub_world(SolidMedium::me));
		return bullet_medium.raycast(HCollider(), ray.m_start, ray.m_end, mask);
	}
}
