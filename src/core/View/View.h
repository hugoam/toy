//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <core/Store/Array.h>
#include <core/Store/CountStore.h>
#include <core/Forward.h>
#include <core/Entity/EntityObserver.h>
#include <core/Entity/Entity.h>
#include <core/Physic/Medium.h>

using namespace mud; namespace toy
{
	class TOY_CORE_EXPORT RecursiveStore : public Array<Entity>, public StoreObserver<Entity>
	{
	public:
		RecursiveStore();

		virtual void handle_add(Entity& entity);
		virtual void handle_remove(Entity& entity);

		void addRecursive(Entity& entity);
		void removeRecursive(Entity& entity);

	protected:
		std::function<bool(Entity&)> m_filter;
	};

	class refl_ TOY_CORE_EXPORT View
	{
	public:
		View(Vision& vision, Type& type);
		virtual ~View();

		virtual Store<Entity>& store() = 0;

		attr_ Type& m_type;
		Vision& m_vision;
	};

	class refl_ TOY_CORE_EXPORT StoreView : public View
	{
	public:
		StoreView(Vision& vision, const string& name, Store<Entity>& store);

		virtual Store<Entity>& store() { return m_store; }

	protected:
		Store<Entity>& m_store;
	};

    class refl_ TOY_CORE_EXPORT ReceptorView : public View, public StoreObserver<Entity>
    {
	public:
		ReceptorView(Vision& vision, Medium& medium, Store<Entity>& receptors);
		~ReceptorView();

		Medium& medium() { return m_medium; }

		virtual Store<Entity>& store() { return m_store; }

		void handle_add(Entity& entity);
		void handle_remove(Entity& entity);

	protected:
		Medium& m_medium;
		Store<Entity>& m_receptors;
		Chained<CountStore<Entity>> m_store;
    };
}
