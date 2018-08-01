//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/Entity/Entity.h>

#include <obj/Indexer.h>
#include <math/Timer.h>
#include <math/Math.h>

#include <core/World/World.h>

#include <core/Entity/EntityObserver.h>
#include <core/World/Section.h>

#include <proto/Proto.h>

#include <refl/Meta.h>

using namespace mud; namespace toy
{
	Entity::Entity(Id id, Complex& complex, World& world, Entity* parent, const vec3& position, const quat& rotation)
        : Transform(position, rotation, Unit3)
		, m_id(index(type<Entity>(), id, Ref(this)))
		, m_complex(complex)
		, m_world(world)
		, m_parent(parent)
		, m_hooked(true)
	{
		world.add_task(this, short(Task::Entity)); // @todo in the long term this should be moved out of the entity's responsibility

		if(parent)
			parent->m_contents.add(this);
	}

	Entity::Entity(Id id, Complex& complex, Entity& parent, const vec3& position, const quat& rotation)
		: Entity(id, complex, parent.m_world, &parent, position, rotation)
	{}

    Entity::~Entity()
    {
		unindex(type<Entity>(), m_id);

		m_world.remove_task(this, short(Task::Entity));

		if(m_parent)
			m_parent->m_contents.remove(*this);

		m_parent = nullptr;
		
		for(Entity* entity : m_contents.store())
			entity->m_parent = nullptr;
	}

	Entity& Entity::origin()
	{
		return m_world.origin();
	}

	void Entity::debug_contents(size_t depth)
	{
		if(m_contents.store().size() > 1)
		{
			for(size_t o = 0; o < depth; ++o)
				printf("    ");

			printf("Entity %u : %zu leafs\n", m_id, m_contents.store().size());
		}

		for(auto& child : m_contents.store())
			child->debug_contents(depth + 1);
	}

	vec3 Entity::absolute_position()
	{
		if(m_parent)
			return m_position + m_parent->absolute_position();
		else
			return m_position;
	}

	quat Entity::absolute_rotation()
	{
		if(m_parent)
			return m_rotation * m_parent->absolute_rotation();
		else
			return m_rotation;
	}

	void Entity::translate(const vec3& vec)
	{
		set_position(mud::rotate(m_rotation, vec) + m_position);
	}

	void Entity::rotate(const vec3& axis, float angle)
	{
		quat rot = angle_axis(angle, mud::rotate(m_rotation, axis));
		set_rotation(rot * m_rotation);
		normalize(m_rotation);
	}

	void Entity::yaw(float value)
	{
		vec3 axis(glm::rotate(m_rotation, Y3));			
		rotate(axis, value);
	}

	void Entity::yaw_fixed(float value)
	{			
		rotate(Y3, value);
	}

	void Entity::pitch(float value)
	{
		vec3 axis(glm::rotate(m_rotation, X3));
		rotate(axis, value);
	}

	void Entity::roll(float value)
	{
		vec3 axis(glm::rotate(m_rotation, Z3));
		rotate(axis, value);
	}

    void Entity::next_frame(size_t tick, size_t delta)
    {
		UNUSED(delta);

		m_moved = false;
		m_last_tick = tick;
	}

	void Entity::observe_hook(HookObserver& obs)
	{
		m_hook_observers.push_back(&obs);
		if(m_hooked)
			obs.hooked();
	}

	void Entity::unobserve_hook(HookObserver& observer)
	{
		vector_remove(m_hook_observers, &observer);
	}

	void Entity::hook()
	{
		m_hooked = true;

		for(HookObserver* obs : m_hook_observers)
			obs->hooked();
	}

	void Entity::unhook()
	{
		for(HookObserver* obs : m_hook_observers)
			obs->unhooked();

		m_hooked = false;
	}

	void Entity::set_parent(Entity* parent)
	{
		this->detach_to(*parent);
	}

	bool Entity::is_child_of(Entity& entity)
	{
		if(m_parent == &entity)
			return true;
		else if(m_parent)
			return m_parent->is_child_of(entity);
		else
			return false;
	}

	Entity* Entity::spatial_root()
	{
		if(m_parent)
			return m_parent->spatial_root();
		else
			return this;
	}

	Entity* Entity::find_parent(Type& part_type)
	{
		if(m_parent && m_parent->m_complex.has_part(part_type))
			return m_parent;
		else if(m_parent)
			return m_parent->find_parent(part_type);
		else
			return nullptr;
	}

	void Entity::detach_to(Entity& moveto)
	{
		Entity& movefrom = *m_parent; 
		m_parent = &moveto;
		movefrom.m_contents.remove(*this);
		moveto.m_contents.add(*this);
		this->set_dirty(false);
	}

	void Entity::detach(Entity& child)
	{
		child.m_parent = 0;
		m_contents.remove(child);
	}

	void Entity::visit(const Visitor& visitor)
	{
		if(!visitor(*this))
			return;

		for(Entity* entity : m_contents.store())
			entity->visit(visitor);
	}
}
