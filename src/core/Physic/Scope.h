//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <core/Store/Array.h>
#include <core/Forward.h>

#include <core/Entity/Entity.h> // @array-include
#include <core/Physic/Collider.h>
#include <core/Physic/Signal.h>

using namespace mud; namespace toy
{
	class refl_ TOY_CORE_EXPORT PhysicScope : public Collider, public ColliderObject
    {
    public:
        PhysicScope(Entity& entity, Medium& medium, const CollisionShape& collision_shape, CollisionGroup group);

		virtual void add_contact(Collider& object);
		virtual void remove_contact(Collider& collider);

		meth_ inline std::vector<Entity*>& scope() { return m_scope.store(); }

		Array<Entity> m_scope;
	};

	class refl_ TOY_CORE_EXPORT EmitterScope : public PhysicScope
	{
	public:
		EmitterScope(Entity& entity, Medium& medium, const CollisionShape& collision_shape, CollisionGroup group /*= CM_SOURCE*/);

		virtual void add_contact(Collider& object);
		virtual void remove_contact(Collider& collider);

		virtual void handleMoved();

	protected:
		std::vector<Signal> m_signals;
	};

	class refl_ TOY_CORE_EXPORT ReceptorScope : public PhysicScope
	{
	public:
		ReceptorScope(Entity& entity, Medium& medium, const CollisionShape& collision_shape, CollisionGroup group /*= CM_RECEPTOR*/);
	};

	class refl_ TOY_CORE_EXPORT EmitterSphere : public EmitterScope
	{
	public:
		EmitterSphere(Entity& entity, Medium& medium, CollisionGroup group, float radius);
	};

	class refl_ TOY_CORE_EXPORT ReceptorSphere : public ReceptorScope
	{
	public:
		ReceptorSphere(Entity& entity, Medium& medium, CollisionGroup group, float radius);

		float m_radius;
	};

	class refl_ TOY_CORE_EXPORT Emitter : public NonCopy
	{
	public:
		constr_ Emitter(Entity& entity);
		~Emitter();

		attr_ Entity& m_entity;

		EmitterScope& add_scope(Medium& medium, const CollisionShape& collision_shape, CollisionGroup group);
		EmitterSphere& add_sphere(Medium& medium, float radius, CollisionGroup group = CM_SOURCE);

	protected:
		std::vector<object_ptr<EmitterScope>> m_emitters;
	};

	class refl_ TOY_CORE_EXPORT Receptor : public NonCopy
	{
	public:
		constr_ Receptor(Entity& entity);
		~Receptor();

		attr_ Entity& m_entity;

		ReceptorScope& add_scope(object_ptr<ReceptorScope> emitter);
		ReceptorSphere& add_sphere(Medium& medium, float radius, CollisionGroup group = CM_RECEPTOR);

		meth_ ReceptorScope* scope(Medium& medium);

	protected:
		std::vector<object_ptr<ReceptorScope>> m_receptors;
	};
}
