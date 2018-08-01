//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/Physic/Scope.h>

#include <geom/Shapes.h>

#include <core/Entity/Entity.h>
#include <core/Physic/Medium.h>
#include <core/Physic/PhysicWorld.h>

using namespace mud; namespace toy
{
	PhysicScope::PhysicScope(Entity& entity, Medium& medium, const CollisionShape& collision_shape, CollisionGroup group)
		: Collider(entity, *this, collision_shape, medium, group)
	{}

	void PhysicScope::add_contact(Collider& collider)
	{
		UNUSED(collider);
	}

	void PhysicScope::remove_contact(Collider& collider)
	{
		UNUSED(collider);
	}

	EmitterScope::EmitterScope(Entity& entity, Medium& medium, const CollisionShape& collision_shape, CollisionGroup group)
		: PhysicScope(entity, medium, collision_shape, group)
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

	void EmitterScope::handleMoved()
	{
		if(!m_entity.m_moved) // @Hack performance kludge : scopes are usually spheres
			return;

		for(Signal& signal : m_signals)
			signal.update();
	}

	ReceptorScope::ReceptorScope(Entity& entity, Medium& medium, const CollisionShape& collision_shape, CollisionGroup group)
		: PhysicScope(entity, medium, collision_shape, group)
	{}

	EmitterSphere::EmitterSphere(Entity& entity, Medium& medium, CollisionGroup group, float range)
		: EmitterScope(entity, medium, Sphere(range), group)
	{}

	ReceptorSphere::ReceptorSphere(Entity& entity, Medium& medium, CollisionGroup group, float range)
		: ReceptorScope(entity, medium, Sphere(range), group)
		, m_radius(range)
	{}

	Emitter::Emitter(Entity& entity)
		: m_entity(entity)
	{}

	Emitter::~Emitter()
	{}

	EmitterScope& Emitter::add_scope(Medium& medium, const CollisionShape& collision_shape, CollisionGroup group)
	{
		m_emitters.emplace_back(make_object<EmitterScope>(m_entity, medium, collision_shape, group));
		return *m_emitters.back();
	}

	EmitterSphere& Emitter::add_sphere(Medium& medium, float radius, CollisionGroup group)
	{
		m_emitters.emplace_back(make_object<EmitterSphere>(m_entity, medium, group, radius));
		return as<EmitterSphere>(*m_emitters.back());
	}

	Receptor::Receptor(Entity& entity)
		: m_entity(entity)
	{}

	Receptor::~Receptor()
	{}

	ReceptorScope& Receptor::add_scope(object_ptr<ReceptorScope> scope)
	{
		m_receptors.emplace_back(std::move(scope));
		return *m_receptors.back();
	}

	ReceptorSphere& Receptor::add_sphere(Medium& medium, float radius, CollisionGroup group)
	{
		m_receptors.emplace_back(make_object<ReceptorSphere>(m_entity, medium, group, radius));
		return as<ReceptorSphere>(*m_receptors.back());
	}


	ReceptorScope* Receptor::scope(Medium& medium)
	{
		for(auto& scope : m_receptors)
			if(&scope->m_medium == &medium)
				return scope.get();
		return nullptr;
	}

}
