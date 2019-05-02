//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <obj/Forward.h>
#include <obj/Unique.h>
#include <obj/TypeUtils.h>
#include <core/Store/StoreObserver.h>

#ifndef MUD_CPP_20
#include <memory>
#include <stl/vector>
#endif

using namespace two; namespace toy
{
	template <class T, class R>
	struct ResPointer { static inline T* pointer(R& r) { return &r; } };

	template <class T>
	struct ResPointer<T, T*> { static inline T* pointer(T* const& r) { return r; } };

	template <class T>
	struct ResPointer<T, unique_ptr<T>> { static inline T* pointer(const unique_ptr<T>& r) { return r.get(); } };

	template <class R, class T>
	class VectorObserver // : public Observer
	{
	public:
		VectorObserver(vector<R>& vector) : m_vector(vector) {}

		void update()
		{
			bool modified = false;

			for(size_t i = 0; i < m_vector.size(); ++i)
			{
				if(i >= m_copy.size())
				{
					for(; i < m_vector.size(); ++i)
						this->handle_add(*ResPointer<T, R>::pointer(m_vector[i]), i);
					modified = true;
					break;
				}

				if(ResPointer<T, R>::pointer(m_vector[i]) == m_copy[i])
					continue;

				size_t j = i;
				while(j < m_vector.size() - 1 && j < m_copy.size() - 1 && ResPointer<T, R>::pointer(m_vector[i]) != m_copy[j] && ResPointer<T, R>::pointer(m_vector[j]) != m_copy[i])
					++j;

				if(ResPointer<T, R>::pointer(m_vector[i]) == m_copy[j])
					for(; i < j; ++i)
						this->handle_add(*ResPointer<T, R>::pointer(m_vector[i]), i);
				else if(ResPointer<T, R>::pointer(m_vector[j]) == m_copy[i])
					for(; i < j; ++i)
						this->handle_remove(*m_copy[i], i);
				else
				{
					this->handle_add(*ResPointer<T, R>::pointer(m_vector[i]), i);
					this->handle_remove(*m_copy[i], i);
				}

				modified = true;
			}

			if(modified)
			{
				m_copy.clear();
				m_copy.resize(m_vector.size());
				for(size_t i = 0; i < m_vector.size(); ++i)
					m_copy[i] = ResPointer<T, R>::pointer(m_vector[i]);
			}
		}

		virtual void handle_add(T& object, size_t index) = 0;
		virtual void handle_remove(T& object, size_t index) = 0;

	protected:
		vector<R>& m_vector;
		vector<T*> m_copy;
	};
	
	template <class T_Content, class T_Type = typename type_class<T_Content>::type>
	class GenVectorObserver : public VectorObserver<T_Content, T_Type>
	{
	public:
		GenVectorObserver(vector<T_Content>& vector, GenStoreObserver& observer)
			: VectorObserver<T_Content, T_Type>(vector)
			, m_observer(observer)
		{}

		void handle_add(T_Type& value, size_t index) { UNUSED(index); m_observer.handle_add(var(value)); }
		void handle_remove(T_Type& value, size_t index) { UNUSED(index); m_observer.handle_remove(var(value)); }

	protected:
		GenStoreObserver& m_observer;
	};
}
