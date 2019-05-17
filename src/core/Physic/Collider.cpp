//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#ifdef TWO_MODULES
module toy.core
#else
#include <pool/SparsePool.hpp>
#include <ecs/Complex.h>
#include <core/Types.h>
#include <core/Physic/Collider.h>
#include <core/Spatial/Spatial.h>
#include <core/World/Section.h>
#include <core/World/World.hpp>
#include <core/Physic/Medium.h>
#include <core/Physic/PhysicWorld.h>
#include <core/Physic/CollisionShape.h>
#include <core/Physic/Solid.h>
#endif

namespace toy
{
	OCollider Collider::create(HSpatial spatial, HMovable movable, const CollisionShape& collision_shape, Medium& medium, CollisionGroup group)
	{
		SparsePool<Collider>& pool = spatial->m_world->pool<Collider>();

		OCollider collider = pool.create(spatial, movable, collision_shape, medium, group);
		collider->m_world->add_collider(collider);
		return collider;
	}

	void Collider::destroy(HCollider collider)
	{
		collider->m_world->remove_collider(collider);
	}

    Collider::Collider(HSpatial spatial, HMovable movable, const CollisionShape& collision_shape, Medium& medium, CollisionGroup group)
        : m_spatial(spatial)
		, m_movable(movable)
		, m_collision_shape(collision_shape)
		, m_medium(&medium)
		, m_group(group)
		, m_world(&as<PhysicWorld>(spatial->m_world->m_complex).sub_world(*m_medium))
		, m_impl()
		, m_motion_state(collision_shape.m_center)
    {}

    Collider::~Collider()
    {}

	void Collider::init(object<ColliderImpl> impl)
	{
		m_impl = move(impl);
	}

	void Collider::next_frame(size_t tick, size_t delta)
	{
		if(m_movable)
			this->next_frame(m_spatial, m_movable, tick, delta);
		else
			this->next_frame(m_spatial, tick, delta);
	}

	void Collider::next_frame(Spatial& spatial, size_t tick, size_t delta)
	{
		UNUSED(delta);
		m_motion_state.update(spatial, tick);
	}

	void Collider::next_frame(Spatial& spatial, Movable& movable, size_t tick, size_t delta)
	{
		UNUSED(delta);
		m_motion_state.update(spatial, movable, tick);
	}

	OSolid Solid::create(HSpatial spatial, HMovable movable, const CollisionShape& collision_shape, Medium& medium, CollisionGroup group, bool isstatic, float mass)
	{
		SparsePool<Collider>& colliders = spatial->m_world->pool<Collider>();
		SparsePool<Solid>& solids = spatial->m_world->pool<Solid>();

		OCollider collider = colliders.create(spatial, movable, collision_shape, medium, group);
		OSolid solid = solids.create(spatial, movable, move(collider), isstatic, mass);

		HCollider hcollider = solid->m_collider;
		hcollider->m_world->add_solid(hcollider, solid);

		return solid;
	}

	OSolid Solid::create(HSpatial spatial, HMovable movable, const CollisionShape& collision_shape, bool isstatic, float mass)
	{
		return create(spatial, movable, collision_shape, SolidMedium::me, CM_SOLID, isstatic, mass);
	}

	void Solid::destroy(HSolid solid)
	{
		solid->m_collider->m_world->remove_solid(solid->m_collider, solid);
	}

	Solid::Solid(HSpatial spatial, HMovable movable, OCollider collider, bool isstatic, float mass)
		: m_spatial(spatial)
		, m_collider(move(collider))
		, m_static(isstatic)
		, m_mass(mass)
	{
		UNUSED(movable);
	}

	Solid::~Solid()
	{}

	void Solid::init(object<SolidImpl> impl)
	{
		m_impl = move(impl);
	}
}
