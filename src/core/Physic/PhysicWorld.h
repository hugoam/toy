//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <infra/NonCopy.h>
#include <obj/Unique.h>
#include <infra/Updatable.h>
#include <math/Vec.h>
#include <core/Forward.h>

#ifndef MUD_CPP_20
#include <map>
#endif

using namespace mud; namespace toy
{
	class TOY_CORE_EXPORT PhysicMedium
	{
	public:
		PhysicMedium(World& world, Medium& medium);
		virtual ~PhysicMedium() {}

		World& m_world;
		Medium& m_medium;

		virtual void update_contacts() = 0;
		virtual void next_frame(size_t tick, size_t delta) = 0;

		virtual object_ptr<ColliderImpl> make_collider(Collider& collider) = 0;
		virtual object_ptr<ColliderImpl> make_solid(Solid& solid) = 0;

		virtual void add_solid(Solid& solid) = 0;
		virtual void remove_solid(Solid& solid) = 0;

		virtual void add_collider(Collider& collider) = 0;
		virtual void remove_collider(Collider& collider) = 0;
	};

	class refl_ TOY_CORE_EXPORT PhysicWorld : public NonCopy, public Updatable
    {
	public:
        PhysicWorld(World& world);
		~PhysicWorld();

		attr_ World& m_world;

		void next_frame(size_t tick, size_t delta);

		PhysicMedium& sub_world(Medium& medium);

	public:
		virtual object_ptr<PhysicMedium> create_sub_world(Medium& medium) = 0;
		meth_ virtual vec3 ground_point(const Ray& ray) = 0;
		meth_ virtual Collision raycast(const Ray& ray, short int mask) = 0;

	protected:
		std::map<Medium*, object_ptr<PhysicMedium>> m_subworlds;
    };
}
