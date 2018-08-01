//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <proto/Complex.h>
#include <core/Store/Array.h>
#include <infra/Updatable.h>
#include <math/Vec.h>
#include <core/Forward.h>
#include <core/Physic/Medium.h>
#include <core/Physic/Collider.h>

#ifndef MUD_CPP_20
#include <memory>
#include <atomic>
#endif

using namespace mud; namespace toy
{
	class refl_ TOY_CORE_EXPORT WorldMedium : public Medium
	{
	public:
		constr_ WorldMedium();
		attr_ static WorldMedium me;
	};

	/* A WorldPage has : 
		- contents (entities)
		- static geometry (static entities)
		- nested worldpages (worldpages)
		- adjacent worldpages
	*/

	class refl_ TOY_CORE_EXPORT WorldPage : public NonCopy, public ColliderObject, public Updatable, public StoreObserver<Entity>
    {
	public:
		constr_ WorldPage(Entity& entity, Emitter& emitter, bool open, const vec3& extents);
        ~WorldPage();

		attr_ Entity& m_entity;
		attr_ Emitter& m_emitter;
		attr_ bool m_open;
		attr_ vec3 m_extents;
		attr_ World& m_world;
		attr_ size_t m_last_rebuilt = 0;
		std::atomic<size_t> m_updated = { 0 };

		std::vector<string> m_geometry_filter;

		std::function<void(WorldPage&)> m_build_geometry;

		EmitterScope& m_scope;

		std::vector<Geometry> m_chunks;
		std::vector<object_ptr<Solid>> m_solids;

		virtual void next_frame(size_t tick, size_t delta) final;

		virtual void add_contact(Collider& object);
		virtual void remove_contact(Collider& object);

		virtual void handle_add(Entity& entity);
		virtual void handle_remove(Entity& entity);

		meth_ void build_geometry();
		meth_ void update_geometry();

		meth_ void ground_point(const vec3& position, bool relative, vec3& outputPoint);
		meth_ void raycast_ground(const vec3& from, const vec3& to, vec3& ground_point);
    };
}
