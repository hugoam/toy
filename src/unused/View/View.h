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
	class TOY_CORE_EXPORT RecursiveStore : public Array<Spatial>, public StoreObserver<Spatial>
	{
	public:
		RecursiveStore();

		virtual void handle_add(Spatial& spatial);
		virtual void handle_remove(Spatial& spatial);

		void addRecursive(Spatial& spatial);
		void removeRecursive(Spatial& spatial);

	protected:
		std::function<bool(Spatial&)> m_filter;
	};

	class refl_ TOY_CORE_EXPORT View
	{
	public:
		View(Vision& vision, Type& type);
		virtual ~View();

		virtual Store<Spatial>& store() = 0;

		attr_ Type& m_type;
		Vision& m_vision;
	};

	class refl_ TOY_CORE_EXPORT StoreView : public View
	{
	public:
		StoreView(Vision& vision, const string& name, Store<Spatial>& store);

		virtual Store<Spatial>& store() { return m_store; }

	protected:
		Store<Spatial>& m_store;
	};

    class refl_ TOY_CORE_EXPORT ReceptorView : public View, public StoreObserver<Spatial>
    {
	public:
		ReceptorView(Vision& vision, Medium& medium, Store<Spatial>& receptors);
		~ReceptorView();

		Medium& medium() { return m_medium; }

		virtual Store<Spatial>& store() { return m_store; }

		void handle_add(Spatial& spatial);
		void handle_remove(Spatial& spatial);

	protected:
		Medium& m_medium;
		Store<Spatial>& m_receptors;
		Chained<CountStore<Spatial>> m_store;
    };
}
