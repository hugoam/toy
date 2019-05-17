//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <core/Forward.h>

#include <core/Spatial/Spatial.h> // @span-include
#include <core/Physic/Collider.h>
#include <core/Physic/Signal.h>

namespace toy
{
	class refl_ TOY_CORE_EXPORT PhysicScope : public ColliderObject
    {
    public:
		PhysicScope() {}
        PhysicScope(HSpatial spatial, Medium& medium, const CollisionShape& collision_shape, CollisionGroup group);

		void add_scope(HSpatial object);
		void remove_scope(HSpatial object);

		HSpatial m_spatial;
		OCollider m_collider;
		vector<HSpatial> m_scope;
		vector<Observer*> m_observers;
	};

	class refl_ TOY_CORE_EXPORT EmitterScope : public PhysicScope
	{
	public:
		EmitterScope() {}
		EmitterScope(HSpatial spatial, Medium& medium, const CollisionShape& collision_shape, CollisionGroup group /*= CM_SOURCE*/);

		virtual void add_contact(Collider& collider, ColliderObject& object);
		virtual void remove_contact(Collider& collider, ColliderObject& object);

		virtual void handle_moved();

	protected:
		vector<Signal> m_signals;
	};

	class refl_ TOY_CORE_EXPORT ReceptorScope : public PhysicScope
	{
	public:
		ReceptorScope() {}
		ReceptorScope(HSpatial spatial, Medium& medium, const CollisionShape& collision_shape, CollisionGroup group /*= CM_RECEPTOR*/);
	};

#if 0
	using OEmitterScope = OwnedHandle<EmitterScope>;
	using OReceptorScope = OwnedHandle<ReceptorScope>;

	using HEmitterScope = SparseHandle<EmitterScope>;
	using HReceptorScope = SparseHandle<ReceptorScope>;
#else
	using OEmitterScope = object<EmitterScope>;
	using OReceptorScope = object<ReceptorScope>;

	using HEmitterScope = EmitterScope&;
	using HReceptorScope = ReceptorScope&;
#endif

	class refl_ TOY_CORE_EXPORT Emitter// : public Movabl
	{
	public:
		constr_ Emitter() {}
		constr_ Emitter(HSpatial spatial);
		~Emitter();

		Emitter(Emitter&& other) = default;
		Emitter& operator=(Emitter&& other) = default;

		comp_ HSpatial m_spatial;

		HEmitterScope add_scope(Medium& medium, const CollisionShape& collision_shape, CollisionGroup group);
		HEmitterScope add_sphere(Medium& medium, float radius, CollisionGroup group = CM_SOURCE);

	protected:
		vector<OEmitterScope> m_emitters;
	};

	class refl_ TOY_CORE_EXPORT Receptor// : public Movabl
	{
	public:
		constr_ Receptor() {}
		constr_ Receptor(HSpatial spatial);
		~Receptor();

		Receptor(Receptor&& other) = default;
		Receptor& operator=(Receptor&& other) = default;

		comp_ HSpatial m_spatial;

		HReceptorScope add_scope(Medium& medium, const CollisionShape& collision_shape, CollisionGroup group);
		HReceptorScope add_sphere(Medium& medium, float radius, CollisionGroup group = CM_RECEPTOR);

		meth_ ReceptorScope* scope(Medium& medium);

	protected:
		vector<OReceptorScope> m_receptors;
	};
}
