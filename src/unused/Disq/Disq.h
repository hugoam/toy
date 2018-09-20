//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <proto/Complex.h>
#include <math/Math.h>
#include <math/Vec.h>
#include <core/Forward.h>
#include <core/Physic/Collider.h>
#include <infra/Updatable.h>

#ifndef MUD_CPP_20
#include <vector>
#include <memory>
#include <list>
#endif

using namespace mud; namespace toy
{
	class TOY_CORE_EXPORT Atoll : public Updatable
	{
	public:
		Atoll();

		std::list<Disq*> m_contents;
		vec3 m_center;
		Disq* m_farthest;
		float m_farthestDist;
		float m_highRadius;

		float totalRadius() { return m_farthestDist + m_highRadius; }

		void next_frame(size_t tick, size_t delta);
		void update();

		bool inside(Disq& disq);

		void add(Disq& disq) { m_contents.push_back(&disq); this->update(); }
		void remove(Disq& disq) { m_contents.remove(&disq); }

		vec3 escape(Disq& disq);
		vec3 suggestDirection(Disq& movable);
	};

	typedef std::vector<Movable*> MovableVector;

	struct TOY_CORE_EXPORT Contact
	{
		Contact(Disq* m, float a, float s, float i) : disq(m), angle(a), span(s), interval(i) {}

		Disq* disq;
		float angle;
		float span;
		float interval;
	};

	class TOY_CORE_EXPORT Belt
	{
	public:
		Belt();

		void add(Disq& disq, float span, float angle);
		void remove(Disq& disq);

		size_t index(float angle);
		size_t next(float angle);
		size_t nearest(float span, float hintAngle);
		size_t place(float span);
		bool room(float span);
		bool room(float span, float angle);
		float interval(Contact& before, Contact& after);

		size_t find(Disq& disq);
		
		Contact* at(size_t index) { return &m_contacts[index]; }
		size_t before(size_t index) { return index == 0 ? m_contacts.size() - 1 : index - 1; }
		size_t after(size_t index) { return index == m_contacts.size() - 1 ? 0 : index + 1; }

		size_t numContacts() { return m_contacts.size(); }

		std::vector<Contact>& contacts() { return m_contacts; }

	protected:
		std::vector<Contact> m_contacts;
	};

	class TOY_CORE_EXPORT Disq : public Belt, public Collider, public ColliderObject
	{
	public:
		Disq(Entity& entity, float radius, float height, Medium& medium, CollisionGroup group);
		~Disq();

	public:
		Entity& m_entity;

		float m_radius;
		float m_height;

		void add_contact(Collider& collider);
		void remove_contact(Collider& collider);

		Atoll* atoll() { return m_atoll.get(); }

	public:
		float span(Disq& other);
		float angle_to(const vec3& pos);
		float angle_to(Entity& other);
		float angle_to_safe(Entity& self, Entity& other);
		float angle_to(Entity& self, Entity& m0, Entity& m1);
		float randomAngle();
		vec3 randomDir();
		vec3 attract(const vec3& from, const vec3& to, float range);
		vec3 stick(Disq& other);

		void contact(Disq& other);
		void disconnect(Disq& other);
		bool collides(Disq& other);
		vec3 closest(Disq& other);
		vec3 nearest(Disq& other);
		
		bool collisions(const vec3& spot);
		void collisions(const vec3& spot, std::vector<Collision>& obstacles);

		vec3 project(const vec3& pos);

		void imbed(const vec3& pos);
		void imbed();

		//vec3 slide(float alpha, Disq& anchor);

		//bool insideAtoll();

		//void avoid(const vec3& spot);

	protected:
		std::shared_ptr<Atoll> m_atoll;
	};
}
