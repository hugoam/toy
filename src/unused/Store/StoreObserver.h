//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <core/Forward.h>
#include <obj/Type.h>

using namespace mud; namespace toy
{
	template <class T>
	class Store;

	class TOY_CORE_EXPORT Observer
	{
	public:
		virtual ~Observer() {}

		virtual void update() {}
	};

	class TOY_CORE_EXPORT GenStoreObserver : public Observer
	{
	public:
		virtual bool handleClear() { return false; }
		virtual void handle_add(Var value) = 0;
		virtual void handle_remove(Var value) = 0;
	};

	template <class T>
	class StoreObserver : public Observer
	{
	public:
		virtual bool handleClear() { return false; }
		virtual void handle_add(T& object) = 0;
		virtual void handle_remove(T& object) = 0;
	};

	template <class T>
	class GenericObserver : public StoreObserver<T>
	{
	public:
		GenericObserver(Store<T>& store, GenStoreObserver& observer) : m_store(store), m_observer(observer) { m_store.observe(*this); }
		~GenericObserver() { m_store.unobserve(*this); }

		virtual bool handleClear() { return m_observer.handleClear(); }
		virtual void handle_add(T& object) { m_observer.handle_add(var(object)); }
		virtual void handle_remove(T& object) { m_observer.handle_remove(var(object)); }

	protected:
		Store<T>& m_store;
		GenStoreObserver& m_observer;
	};

	template <class T_Object, class T>
	class TypedObserver : public StoreObserver<T_Object>
	{
	public:
		virtual void handle_add(T_Object& object) { this->handle_add(as<T>(object)); }
		virtual void handle_remove(T_Object& object) { this->handle_remove(as<T>(object)); }

		virtual void handle_add(T& object) = 0;
		virtual void handle_remove(T& object) = 0;
	};
}
