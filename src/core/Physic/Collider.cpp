//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/Physic/Collider.h>

#include <core/Entity/Entity.h>
#include <core/World/Section.h>
#include <core/World/World.h>
#include <core/Physic/Medium.h>
#include <core/Physic/PhysicWorld.h>
#include <core/Physic/CollisionShape.h>

using namespace mud; namespace toy
{
    Collider::Collider(Entity& entity, ColliderObject& object, const CollisionShape& collision_shape, Medium& medium, CollisionGroup group, bool init)
        : m_entity(entity)
		, m_object(object)
		, m_collision_shape(collision_shape)
		, m_medium(medium)
		, m_group(group)
		, m_world(entity.m_world.as<PhysicWorld>().sub_world(m_medium))
		, m_impl()
		, m_motion_state(entity, collision_shape.m_center)
    {
		m_entity.m_world.add_task(this, short(Task::Physics)); // @kludge: collider motion states have to be updated (->bullet) before physics step

		if(init)
		{
			m_impl = m_world.make_collider(*this);
			this->init();
		}
		
		// @note : instant contact detection on world inclusion works only if a call to update is done after
		//	in a non delayed manner it is possible only by calling performDiscreteCollisionDetection on each item add
		//	in a delayed manner it is possible by updating on the frame after
		//this->force_update();
	}

    Collider::~Collider()
    {
		m_entity.m_world.remove_task(this, short(Task::Physics));

		if(m_entity.m_hooked)
			this->unhooked();
	}

	void Collider::init()
	{
		m_motion_state.m_source = m_impl.get();
		m_entity.observe_hook(*this);
	}

	void Collider::next_frame(size_t tick, size_t delta)
	{
		UNUSED(delta);
		m_motion_state.update(tick);
	}

	void Collider::hooked()
	{
		m_world.add_collider(*this);
	}

	void Collider::unhooked()
	{
		m_world.remove_collider(*this);
	}

	Solid::Solid(Entity& entity, ColliderObject& object, const CollisionShape& collision_shape, Medium& medium, CollisionGroup group, bool isstatic, float mass)
		: Collider(entity, object, collision_shape, medium, group, false)
		, m_static(isstatic)
		, m_mass(mass)
	{
		m_impl = m_world.make_solid(*this);
		this->init();
	}

	Solid::~Solid()
	{}

	void Solid::hooked()
	{
		m_world.add_solid(*this);
	}

	void Solid::unhooked()
	{
		m_world.remove_solid(*this);
	}
}
