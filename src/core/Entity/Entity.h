//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <proto/Complex.h>
#include <core/Store/Array.h>
#include <infra/Updatable.h>
#include <pool/ObjectPool.h>
#include <math/VecOps.h>
#include <math/Axes.h>
#include <core/Forward.h>
#include <core/Types.h> // @kludge because of Array<T>
#include <core/Entity/EntityObserver.h>

#ifndef MUD_CPP_20
#include <vector>
#include <memory>
#endif

using namespace mud; namespace toy
{
	template class refl_ TOY_CORE_EXPORT Array<Entity>;

	class refl_ TOY_CORE_EXPORT Entity : public Updatable, public Transform
    {
	public:
		constr_ Entity(Id id, Complex& complex, Entity& parent, const vec3& position, const quat& rotation);
		constr_ Entity(Id id, Complex& complex, World& world, Entity* parent, const vec3& position, const quat& rotation);
        ~Entity();

		attr_ Id m_id;
		attr_ Complex& m_complex;
		attr_ World& m_world;
		attr_ link_ Entity* m_parent;

		attr_ graph_ Array<Entity> m_contents;

		size_t m_last_tick = 0;
		size_t m_last_updated = 0;
		size_t m_last_modified = 0;

		bool m_moved;
		bool m_hooked;

		Entity& origin();
		void set_parent(Entity* entity);
		bool is_child_of(Entity& entity);

		vec3 absolute_position();
		quat absolute_rotation();

		inline void set_dirty(bool moved) { m_last_updated = m_last_tick + 1; m_last_modified = m_last_tick + 1; m_moved = moved; }
		inline void set_sync_dirty(bool moved) { m_last_updated = m_last_tick + 1; m_moved = moved; }

		meth_ inline void set_position(const vec3& position) { m_position = position; this->set_dirty(true); }
		meth_ inline void set_rotation(const quat& rotation) { m_rotation = rotation; this->set_dirty(false); }

		inline void sync_position(const vec3& position) { m_position = position; this->set_sync_dirty(true); }
		inline void sync_rotation(const quat& rotation) { m_rotation = rotation; this->set_sync_dirty(false); }

		inline vec3 front() const { return mud::rotate(m_rotation, to_vec3(Side::Front)); }
		inline vec3 right() const { return mud::rotate(m_rotation, to_vec3(Side::Right)); }
		inline vec3 up()    const { return mud::rotate(m_rotation, to_vec3(Side::Up)); }
		inline vec3 down()  const { return mud::rotate(m_rotation, to_vec3(Side::Down)); }

		void translate(const vec3& vec);
		void rotate(const vec3& axis, float angle);

		void yaw(float value);
		void yaw_fixed(float value);
		void pitch(float value);
		void roll(float value);

		void next_frame(size_t tick, size_t delta);
		
		Entity* spatial_root();
		Entity* find_parent(Type& part_type);

		void remove();

		void detach(Entity& child);
		void detach_to(Entity& moveto);

		void hook();
		void unhook();

		typedef std::function<bool(Entity&)> Visitor;
		void visit(const Visitor& visitor);

		void debug_contents(size_t depth = 0);

	public:
		void observe_hook(HookObserver& listener);
		void unobserve_hook(HookObserver& listener);

	public:
		template <class T>
		inline bool isa() { return m_complex.isa<T>(); }

		template <class T>
		inline T& as() { return m_complex.as<T>(); }

		template <class T>
		inline T* try_as() { return m_complex.isa<T>() ? &m_complex.as<T>() : nullptr; }

		template <class T, class... Types>
		inline T& construct(Types&&... args) { return global_pool<T>().construct(0, *this, std::forward<Types>(args)...); }

    private:
		MotionState* m_motion_state;

		std::vector<HookObserver*> m_hook_observers; // @todo study replacing this with other way : check each frame if entity is still hooked
	};
}
