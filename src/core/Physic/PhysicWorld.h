//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <infra/NonCopy.h>
#include <type/Unique.h>
#include <math/Vec.h>
#include <core/Forward.h>
#include <core/Structs.h>
#include <core/Physic/Collider.h>

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

		virtual object_ptr<ColliderImpl> make_collider(HCollider collider) = 0;
		virtual object_ptr<SolidImpl> make_solid(HSolid solid) = 0;

		virtual void add_solid(HCollider collider, HSolid solid) = 0;
		virtual void remove_solid(HCollider collider, HSolid solid) = 0;

		virtual void add_collider(HCollider collider) = 0;
		virtual void remove_collider(HCollider collider) = 0;

		virtual void project(HCollider collider, const vec3& position, const quat& rotation, std::vector<Collision>& collisions, short int mask) = 0;
		virtual void raycast(HCollider collider, const vec3& start, const vec3& end, std::vector<Collision>& collisions, short int mask) = 0;
		virtual Collision raycast(HCollider collider, const vec3& target, const vec3& end, short int mask) = 0;
	};

	class refl_ TOY_CORE_EXPORT PhysicWorld : public NonCopy
    {
	public:
        PhysicWorld(World& world);
		virtual ~PhysicWorld();

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
