//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <obj/Type.h>
#include <obj/Any.h>
#include <refl/Iterable.h>
#include <infra/Reverse.h>
#include <core/Forward.h>
#include <core/Store/StoreObserver.h>

#include <algorithm>
#include <vector>

using namespace mud; namespace toy
{
	class GenStore
	{
	public:
		virtual void observe(Observer& observer) = 0;
		virtual void unobserve(Observer& observer, bool notify = false) = 0;
	};

	template <class T>
	class Store : public GenStore
	{
	public:
		virtual void observe(Observer& observer) { this->observe(static_cast<StoreObserver<T>&>(observer)); }
		virtual void unobserve(Observer& observer, bool notify = false) { this->unobserve(static_cast<StoreObserver<T>&>(observer), notify); }

		virtual void observe(StoreObserver<T>& observer) = 0;
		virtual void unobserve(StoreObserver<T>& observer, bool notify = false) = 0;
	};

	template <class T_Array, class T_Element>
	class StoreBase : public Sequence, public Store<T_Element>
	{
	public:
		typedef T_Element T;
		typedef T_Element value_type;

	public:
		StoreBase() {}
		~StoreBase() { this->clear(); }

		inline void select(T& object) { this->clear(); self().add(object); }
		inline void swap(T& object) { self().has(object) ? self().remove(object) : self().add(object); }

		size_t size() const { return self().store().size(); }
		bool empty() const { return self().store().empty(); }

		virtual void add(Ref value) final { self().add(val<T>(value)); }
		virtual void remove(Ref value) final { self().remove(val<T>(value)); }

		virtual void iterate(const std::function<void(Ref)>& callback) const { self().iterate([callback](T& object) { return callback(Ref(&object)); }); }
		virtual bool has(Ref object) const { return self().has(val<T>(object)); }

		std::vector<T*> copy() const
		{
			std::vector<T*> vec;
			for(auto& pt : self().store())
				vec.push_back(&self().deref(pt));
			return vec;
		}

		void iterate(const std::function<void(T&)>& callback) const
		{
			for(const auto& pt : self().store())
				callback(self().deref(pt));
		}

		void clear()
		{
			for(auto observer : reverse_adapt(m_observers))
				if(!observer->handleClear())
					for(auto& pt : self().store())
						observer->handle_remove(self().deref(pt));

			self().store().clear();
		}

		T* find(std::function<bool(T&)> predicate)
		{
			for(auto& pt : self().store())
				if(predicate(self().deref(pt)))
					return &self().deref(pt);
			return nullptr;
		}

		void observe(StoreObserver<T>& observer)
		{
			m_observers.push_back(&observer);
			for(auto& pt : self().store())
				observer.handle_add(self().deref(pt));
		}

		void unobserve(StoreObserver<T>& observer, bool notify = false)
		{
			vector_remove(m_observers, &observer);
			if(notify)
				for(auto& pt : self().store())
					observer.handle_remove(self().deref(pt));
		}

		void notifyAdd(T& object)
		{
			for(auto& observer : m_observers)
				observer->handle_add(object);
		}

		void notifyRemove(T& object)
		{
			for(auto& observer : reverse_adapt(m_observers))
				observer->handle_remove(object);
		}

		void resize(size_t size) { UNUSED(size); }

		inline T_Array& self() { return as<T_Array>(*this); }
		inline const T_Array& self() const { return as<T_Array>(*this); }

	protected:
		std::vector<StoreObserver<T>*> m_observers;
	};
}
