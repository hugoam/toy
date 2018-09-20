//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <core/Forward.h>

#include <core/Entity/Entity.h> // @array-include
#include <core/Physic/Collider.h>
#include <core/Physic/Signal.h>

using namespace mud; namespace toy
{
	class refl_ TOY_CORE_EXPORT PhysicScope : public Collider, public ColliderObject
    {
    public:
		PhysicScope() {}
        PhysicScope(HSpatial spatial, HMovable movable, Medium& medium, const CollisionShape& collision_shape, CollisionGroup group);

		virtual void add_contact(Collider& object);
		virtual void remove_contact(Collider& collider);

		void add_scope(HSpatial object);
		void remove_scope(HSpatial object);

		std::vector<HSpatial> m_scope;
		std::vector<Observer*> m_observers;
	};

	class refl_ TOY_CORE_EXPORT EmitterScope : public PhysicScope
	{
	public:
		EmitterScope() {}
		EmitterScope(HSpatial spatial, HMovable movable, Medium& medium, const CollisionShape& collision_shape, CollisionGroup group /*= CM_SOURCE*/);

		virtual void add_contact(Collider& object);
		virtual void remove_contact(Collider& collider);

		virtual void handle_moved();

	protected:
		std::vector<Signal> m_signals;
	};

	class refl_ TOY_CORE_EXPORT ReceptorScope : public PhysicScope
	{
	public:
		ReceptorScope() {}
		ReceptorScope(HSpatial spatial, HMovable movable, Medium& medium, const CollisionShape& collision_shape, CollisionGroup group /*= CM_RECEPTOR*/);
	};

	using OEmitterScope = OwnedHandle<EmitterScope>;
	using OReceptorScope = OwnedHandle<ReceptorScope>;

	using HEmitterScope = SparseHandle<EmitterScope>;
	using HReceptorScope = SparseHandle<ReceptorScope>;

	class refl_ TOY_CORE_EXPORT Emitter : public Movabl
	{
	public:
#ifdef TOY_ECS
		constr_ Emitter() {}
#endif
		constr_ Emitter(HSpatial spatial, HMovable movable);
		~Emitter();

		Emitter(Emitter&& other) = default;
		Emitter& operator=(Emitter&& other) = default;

		attr_ HSpatial m_spatial;
		attr_ HMovable m_movable;

		HEmitterScope add_scope(Medium& medium, const CollisionShape& collision_shape, CollisionGroup group);
		HEmitterScope add_sphere(Medium& medium, float radius, CollisionGroup group = CM_SOURCE);

	protected:
		std::vector<OEmitterScope> m_emitters;
	};

	class refl_ TOY_CORE_EXPORT Receptor : public Movabl
	{
	public:
#ifdef TOY_ECS
		constr_ Receptor() {}
#endif
		constr_ Receptor(HSpatial spatial, HMovable movable);
		~Receptor();

		Receptor(Receptor&& other) = default;
		Receptor& operator=(Receptor&& other) = default;

		attr_ HSpatial m_spatial;
		attr_ HMovable m_movable;

		HReceptorScope add_scope(Medium& medium, const CollisionShape& collision_shape, CollisionGroup group);
		HReceptorScope add_sphere(Medium& medium, float radius, CollisionGroup group = CM_RECEPTOR);

		meth_ ReceptorScope* scope(Medium& medium);

	protected:
		std::vector<OReceptorScope> m_receptors;
	};
}
