//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <obj/Forward.h>
#include <obj/Type.h>
#include <core/Store/Array.h>
#include <core/Store/StoreObserver.h>
#include <core/Store/Store.h>

#ifndef MUD_CPP_20
#include <vector>
#include <unordered_map>
#include <unordered_set>
#endif

using namespace mud; namespace toy
{
	template <class T>
	class CountStore : public StoreBase<CountStore<T>, T>
	{
	public:
		typedef std::vector<std::pair<T*, size_t>> StoreContainer;

	public:
		CountStore() {}
		~CountStore() { this->clear(); }

		inline T& deref(const typename StoreContainer::value_type& kv) const { return *kv.first; }

		inline const StoreContainer& store() const { return m_store; }
		inline StoreContainer& store() { return m_store; }

		using StoreBase<CountStore<T>, T>::has;
		using StoreBase<CountStore<T>, T>::remove;
		using StoreBase<CountStore<T>, T>::add;

		inline void add(T& object)
		{
			this->resize(object);
			m_store.at(object.m_id).first = &object;

			size_t& count = this->countref(object);
			count++;
			if(count == 1)
				this->notifyAdd(object);
		}

		inline void remove(T& object)
		{
			size_t& count = this->countref(object);
			count--;
			if(count == 0)
				this->notifyRemove(object);
		}

		void observe(StoreObserver<T>& observer)
		{
			this->m_observers.push_back(&observer);
			for(auto& pair : m_store)
				if(pair.first)
					observer.handle_add(*pair.first);
		}

		void unobserve(StoreObserver<T>& observer, bool notify = false)
		{
			vector_remove(this->m_observers, &observer);
			if(notify)
				for(auto& pair : m_store)
					if(pair.first)
						observer.handle_remove(*pair.first);
		}

		void resize(T& object) { if(object.m_id >= m_store.size()) m_store.resize((object.m_id + 1) * 2); }

		inline size_t count(T& object) const { return m_store.at(object.m_id).second; }
		inline size_t& countref(T& object) { return m_store.at(object.m_id).second; }

		bool has(T& object) const	{ return this->count(object) > 0; }

	protected:
		StoreContainer m_store;
	};
}
