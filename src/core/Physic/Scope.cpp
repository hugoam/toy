//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/Types.h>
#include <core/Physic/Scope.h>

#include <geom/Shapes.h>

#include <core/Spatial/Spatial.h>
#include <core/Physic/Medium.h>
#include <core/Physic/PhysicWorld.h>
#include <core/World/World.h>

using namespace mud; namespace toy
{
	PhysicScope::PhysicScope(HSpatial spatial, Medium& medium, const CollisionShape& collision_shape, CollisionGroup group)
		: m_spatial(spatial)
		, m_collider(Collider::create(spatial, HMovable(), collision_shape, medium, group))
	{
		m_collider->m_object = this;
	}

	void PhysicScope::add_scope(HSpatial object)
	{
		m_scope.push_back(object);
	}

	void PhysicScope::remove_scope(HSpatial object)
	{
		vector_remove(m_scope, object);
	}

	EmitterScope::EmitterScope(HSpatial spatial, Medium& medium, const CollisionShape& collision_shape, CollisionGroup group)
		: PhysicScope(spatial, medium, collision_shape, group)
		, m_signals()
	{}

    void EmitterScope::add_contact(Collider& collider, ColliderObject& object)
	{
		if(collider.m_spatial == m_spatial) return;
		ReceptorScope& receptor = static_cast<ReceptorScope&>(object);
		m_signals.emplace_back(*this, receptor);
	}

    void EmitterScope::remove_contact(Collider& collider, ColliderObject& object)
    {
		if(collider.m_spatial == m_spatial) return;
		ReceptorScope& receptor = static_cast<ReceptorScope&>(object);
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

	ReceptorScope::ReceptorScope(HSpatial spatial, Medium& medium, const CollisionShape& collision_shape, CollisionGroup group)
		: PhysicScope(spatial, medium, collision_shape, group)
	{}

	Emitter::Emitter(HSpatial spatial)
		: m_spatial(spatial)
	{}

	Emitter::~Emitter()
	{}

	HEmitterScope Emitter::add_scope(Medium& medium, const CollisionShape& collision_shape, CollisionGroup group)
	{
		//SparsePool<EmitterScope>& pool = m_spatial->m_world->pool<EmitterScope>();
		//m_emitters.emplace_back(pool.construct(m_spatial, medium, collision_shape, group));
		m_emitters.emplace_back(make_object<EmitterScope>(m_spatial, medium, collision_shape, group));
		return *m_emitters.back();
	}

	HEmitterScope Emitter::add_sphere(Medium& medium, float radius, CollisionGroup group)
	{
		return this->add_scope(medium, Sphere(radius), group);
	}

	Receptor::Receptor(HSpatial spatial)
		: m_spatial(spatial)
	{}

	Receptor::~Receptor()
	{}

	HReceptorScope Receptor::add_scope(Medium& medium, const CollisionShape& collision_shape, CollisionGroup group)
	{
		//SparsePool<ReceptorScope>& pool = m_spatial->m_world->pool<ReceptorScope>();
		//m_receptors.emplace_back(pool.construct(m_spatial, medium, collision_shape, group));
		m_receptors.emplace_back(make_object<ReceptorScope>(m_spatial, medium, collision_shape, group));
		return *m_receptors.back();
	}

	HReceptorScope Receptor::add_sphere(Medium& medium, float radius, CollisionGroup group)
	{
		return this->add_scope(medium, Sphere(radius), group);
	}

	ReceptorScope* Receptor::scope(Medium& medium)
	{
		for(auto& scope : m_receptors)
			if(scope->m_collider->m_medium == &medium)
				return &(*scope);
		return nullptr;
	}

}
