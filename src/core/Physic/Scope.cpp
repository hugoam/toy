//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/Types.h>
#include <core/Physic/Scope.h>

#include <geom/Shapes.h>

#include <core/Entity/Entity.h>
#include <core/Physic/Medium.h>
#include <core/Physic/PhysicWorld.h>
#include <core/World/World.h>

using namespace mud; namespace toy
{
	PhysicScope::PhysicScope(HSpatial spatial, HMovable movable, Medium& medium, const CollisionShape& collision_shape, CollisionGroup group)
		: Collider(spatial, movable, collision_shape, medium, group)
	{
		Collider::m_object = this;
	}

	void PhysicScope::add_contact(Collider& collider)
	{
		UNUSED(collider);
	}

	void PhysicScope::remove_contact(Collider& collider)
	{
		UNUSED(collider);
	}

	void PhysicScope::add_scope(HSpatial object)
	{
		UNUSED(object);
	}

	void PhysicScope::remove_scope(HSpatial object)
	{
		UNUSED(object);
	}

	EmitterScope::EmitterScope(HSpatial spatial, HMovable movable, Medium& medium, const CollisionShape& collision_shape, CollisionGroup group)
		: PhysicScope(spatial, movable, medium, collision_shape, group)
		, m_signals()
	{}

    void EmitterScope::add_contact(Collider& collider)
	{
		ReceptorScope& receptor = static_cast<ReceptorScope&>(collider);
		m_signals.emplace_back(*this, receptor);
	}

    void EmitterScope::remove_contact(Collider& collider)
    {
		ReceptorScope& receptor = static_cast<ReceptorScope&>(collider);
		vector_remove_if(m_signals, [&] (const Signal& s) { return s.m_receptor == &receptor; });
    }

	void EmitterScope::handle_moved()
	{
		Spatial& spatial = m_spatial;
		if(!spatial.m_moved) // @Hack performance kludge : scopes are usually spheres
			return;

		for(Signal& signal : m_signals)
			signal.update();
	}

	ReceptorScope::ReceptorScope(HSpatial spatial, HMovable movable, Medium& medium, const CollisionShape& collision_shape, CollisionGroup group)
		: PhysicScope(spatial, movable, medium, collision_shape, group)
	{}

	Emitter::Emitter(HSpatial spatial, HMovable movable)
		: m_spatial(spatial)
		, m_movable(movable)
	{}

	Emitter::~Emitter()
	{}

	HEmitterScope Emitter::add_scope(Medium& medium, const CollisionShape& collision_shape, CollisionGroup group)
	{
		SparsePool<EmitterScope>& pool = m_spatial->m_world->pool<EmitterScope>();
		m_emitters.emplace_back(pool.construct(m_spatial, m_movable, medium, collision_shape, group));
		return m_emitters.back();
	}

	HEmitterScope Emitter::add_sphere(Medium& medium, float radius, CollisionGroup group)
	{
		return this->add_scope(medium, Sphere(radius), group);
	}

	Receptor::Receptor(HSpatial spatial, HMovable movable)
		: m_spatial(spatial)
		, m_movable(movable)
	{}

	Receptor::~Receptor()
	{}

	HReceptorScope Receptor::add_scope(Medium& medium, const CollisionShape& collision_shape, CollisionGroup group)
	{
		SparsePool<ReceptorScope>& pool = m_spatial->m_world->pool<ReceptorScope>();
		m_receptors.emplace_back(pool.construct(m_spatial, m_movable, medium, collision_shape, group));
		return m_receptors.back();
	}

	HReceptorScope Receptor::add_sphere(Medium& medium, float radius, CollisionGroup group)
	{
		return this->add_scope(medium, Sphere(radius), group);
	}

	ReceptorScope* Receptor::scope(Medium& medium)
	{
		for(auto& scope : m_receptors)
			if(scope->m_medium == &medium)
				return &(*scope);
		return nullptr;
	}

}
