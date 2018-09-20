//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <core/Store/Array.h>
#include <core/Store/CountStore.h>
#include <core/Entity/EntityObserver.h>
#include <core/View/View.h>
#include <core/Types.h> // @kludge because of Array

using namespace mud; namespace toy
{
	class refl_ TOY_CORE_EXPORT Vision : public StoreObserver<Spatial>
	{
	public:
		constr_ Vision(World& world);
		~Vision();

		attr_ World& m_world;
		attr_ Ref m_player;

		Chained<CountStore<Spatial>> m_entities;
		Array<Camera> m_cameras;
		Array<View> m_views;

		void handle_add(Spatial& owned);
		void handle_remove(Spatial& owned);

		void addView(View& view);

		Camera& addCamera(const vec3& position, float lensDistance, bool planar);
	};

#if 0
	class refl_ TOY_CORE_EXPORT PlayerVision : public Vision
	{
	public:
		PlayerVision(Player& player, World& world);

		//StoreView m_ownedView;
		//ReceptorView m_visualView;
		//ReceptorView m_soundView;
		//ReceptorView m_worldView;
		//ReceptorView m_bufferView;
	};
#endif

	class refl_ TOY_CORE_EXPORT OmniVision : public Vision
	{
	public:
		OmniVision(World& world);
		~OmniVision();

		Array<Spatial> m_origin;
		RecursiveStore m_store;
		StoreView m_view;
	};
}
