//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/Disq/Disq.h>

#include <geom/Shapes.h>
#include <geom/Intersect.h>

#include <core/World/World.h>
#include <core/Entity/Entity.h>
#include <core/Entity/Entity.h>
#include <core/Movable/Movable.h>
#include <core/Physic/Collider.h>
#include <core/Physic/CollisionShape.h>
#include <core/Physic/Solid.h>
#include <core/WorldPage/WorldPage.h>

#include <core/World/Section.h>

#include <algorithm>

#define CONTACT_THRESHOLD 0.1f

using namespace two; namespace toy
{
	Atoll::Atoll()
		: m_center(0.f,0.f,0.f)
		, m_farthestDist(0.f)
		, m_highRadius(0.f)
	{}

	bool Atoll::inside(Disq& tested)
	{
		for(Disq* disq : m_contents)
		{
			if(disq == &tested)
				continue;

			float dist2 = distance2(disq->m_entity.m_position, tested.m_entity.m_position);
			float thresh = tested.m_radius + disq->m_radius + CONTACT_THRESHOLD;
			thresh *= thresh;
			if(dist2 < thresh)
				return true;
		}
		return false;
	}

	void Atoll::update()
	{
		m_center = {};

		for(Disq* disq : m_contents)
			m_center += disq->m_entity.m_position;

		m_center /= float(m_contents.size());

		float dist;
		for(Disq* disq : m_contents)
		{
			dist = distance2(disq->m_entity.m_position, m_center);
			if(dist > (m_farthestDist * m_farthestDist))
			{
				m_farthestDist = distance(disq->m_entity.m_position, m_center);
				m_farthest = disq;
			}

			if(disq->m_radius > m_highRadius)
				m_highRadius = disq->m_radius;
		}
	}

	vec3 Atoll::escape(Disq& toplace)
	{
		float mindist = m_farthestDist + 1.f;
		Disq* nearest = 0;

		for(Disq* disq : m_contents)
			if(disq->room(disq->span(toplace)))
			{
				float dist = distance(disq->m_entity.m_position, m_center);
				if(dist < mindist)
				{
					mindist = dist;
					nearest = disq;
				}
			}

		vec3 pos = nearest->closest(toplace);
		return pos;
	}

	vec3 Atoll::suggestDirection(Disq& disq)
	{
		vec3 pt1 = Zero3;
		vec3 pt2 = Zero3;
		circle_circle_intersection(m_center, m_farthestDist, m_farthest->m_entity.m_position, m_farthest->m_radius + disq.m_radius, pt1, pt2);

		pt1 -= m_center;
		return pt1;
	}

	void Atoll::next_frame(size_t tick, size_t delta)
	{
		UNUSED(tick); UNUSED(delta);
		this->update();	
	}

	Belt::Belt()
	{}

	size_t Belt::nearest(float span, float angle)
	{
		size_t after = this->next(angle);
		size_t before = this->before(after);
		size_t nearest;

		if(span <= this->at(after)->interval)
			return after;

		for(size_t i = 0; i < m_contacts.size(); ++i)
		{
			float angleBefore = float_shortest_angle(this->at(before)->angle, angle);
			float angleAfter = float_shortest_angle(this->at(after)->angle, angle);

			nearest = angleBefore < angleAfter ? before : after;

			if(span <= this->at(nearest)->interval)
				return nearest;

			if(angleBefore < angleAfter)
				before = this->before(before);
			else
				after = this->after(after);
		}

		return 0;
	}

	size_t Belt::place(float span)
	{
		for(size_t i = 0; i < m_contacts.size(); ++i)
			if(span < m_contacts[i].interval)
				return i;

		return 0;
	}

	bool Belt::room(float span)
	{
		for(size_t i = 0; i < m_contacts.size(); ++i)
			if(span < m_contacts[i].interval )
				return true;

		return false;
	}

	bool Belt::room(float span, float angle)
	{
		size_t index = this->next(angle);
		size_t before = this->before(index);
		return (this->at(index)->interval > span
			&& this->at(index)->angle - this->at(index)->span / 2.f > angle
			&& this->at(before)->angle + this->at(before)->angle / 2.f < angle);
	}

	size_t Belt::find(Disq& disq)
	{
		for(size_t i = 0; i < m_contacts.size(); ++i)
			if(m_contacts[i].disq == &disq)
				return i;

		return 0;
	}

	size_t Belt::index(float angle)
	{
		for(size_t i = 0; i < m_contacts.size(); ++i)
			if(angle < m_contacts[i].angle)
				return i;

		return m_contacts.size();
	}

	size_t Belt::next(float angle)
	{
		for(size_t i = 0; i < m_contacts.size(); ++i)
			if(angle < m_contacts[i].angle)
				return i;

		return 0;
	}

	float Belt::interval(Contact& before, Contact& after)
	{
		float halfspans = before.span / 2 + after.span / 2;
		return before.angle < after.angle ? after.angle - before.angle - halfspans : 2 * c_pi + after.angle - before.angle - halfspans;
	}

	void Belt::add(Disq& disq, float span, float angle)
	{
		if(m_contacts.empty())
		{
			m_contacts.emplace_back(&disq, angle, span, float(2 * c_pi - span));
		}
		else
		{
			size_t i = this->index(angle);
			Contact* after = this->at(this->next(angle));

			float halfspans = span / 2 + after->span / 2;
			float interval = angle < after->angle ? after->angle - angle - halfspans : 2 * c_pi + after->angle - angle - halfspans;
			flatten(interval);

			float rest = after->interval - interval - span;
			after->interval = interval;

			if(interval < -0.001)
				printf("ERROR");

			m_contacts.emplace(m_contacts.begin() + i, &disq, angle, span, rest); // Insert us before cursor
		}
	}

	void Belt::remove(Disq& disq)
	{
		size_t index = this->find(disq);

		if(m_contacts.size() > 1)
		{
			m_contacts[this->after(index)].interval += m_contacts[index].interval + m_contacts[index].span;
		}

		m_contacts.erase(m_contacts.begin() + index);
	}

	Disq::Disq(Entity& entity, float radius, float height, Medium& medium, CollisionGroup group)
		: Collider(entity, Capsule(radius, height), medium, group)
		, m_entity(entity)
		, m_radius(radius)
		, m_height(height)
	{
		entity.m_world.add_task(this, short(Task::State));

		Collider::m_object = this;
		Collider::m_collision_shape.m_margin = -0.1f;
	}

	Disq::~Disq()
	{
		m_entity.m_world.remove_task(this, short(Task::State));
	}

	void Disq::add_contact(Collider& collider)
	{
		UNUSED(collider);
		//this->contact(static_cast<Disq&>(collider));
	}

	void Disq::remove_contact(Collider& collider)
	{
		UNUSED(collider);
		//this->disconnect(static_cast<Disq&>(collider));
	}

	float Disq::span(Disq& other)
	{
		float radius = this->m_radius + other.m_radius;

		vec3 p1 = Zero3;
		vec3 p2 = Zero3;

		float tangent = sqrt((radius * radius) - (other.m_radius * other.m_radius));
		circle_circle_intersection(Zero3, tangent, vec3(radius,0,0), other.m_radius, p1, p2);

		return angle(p1, p2);
	}

	float Disq::angle_to(Entity& self, Entity& m0, Entity& m1)
	{
		vec3 a0 = self.m_position - m0.m_position;
		vec3 a1 = self.m_position - m1.m_position;
		return glm::angle(a0, a1);
	}

	float Disq::angle_to(Entity& other)
	{
		return this->angle_to(other.m_position);
	}

	float Disq::angle_to_safe(Entity& self, Entity& other)
	{
		if(self.m_position == other.m_position)
			return randomAngle();
		else
			return this->angle_to(other);
	}
	
	float Disq::angle_to(const vec3& pos)
	{
		vec3 zero = X3;
		vec3 axis = normalize(pos - this->m_entity.m_position);

		return trigo_angle(zero, axis);
	}

	float Disq::randomAngle()
	{
		return 0.f;
	}

	vec3 Disq::randomDir()
	{
		return rotate(X3, 0.f /*random100(2 * c_pi)*/, Y3);
	}

	vec3 Disq::attract(const vec3& from, const vec3& to, float range)
	{
		vec3 spot = from - to;
		if(spot == Zero3)
			spot = this->randomDir();
		spot = normalize(spot);
		spot *= range;
		spot += to;

		//printf("Disq::stick position %f, %f, %f\n", spot.x(), spot.y(), spot.z());

		return spot;
	}

	vec3 Disq::stick(Disq& other)
	{
		return this->attract(other.m_entity.m_position, m_entity.m_position, this->m_radius + other.m_radius);
	}

	bool Disq::collides(Disq& other)
	{
		if(m_entity.m_position.y + m_height < other.m_entity.m_position.y)
			return false;
		if(other.m_entity.m_position.y + other.m_height < m_entity.m_position.y)
			return false;
		if(distance2(m_entity.m_position, other.m_entity.m_position) >(m_radius + other.m_radius) * (m_radius + other.m_radius))
			return false;

		return true;
	}

	vec3 Disq::closest(Disq& other)
	{
		if(m_contacts.size() < 1)
			return this->stick(other);

		float span = this->span(other);
		float angle = this->angle_to_safe(other);

		if(this->room(span, angle))
			return this->stick(other);

		Contact* ref = this->at(Belt::nearest(span, angle));

		vec3 direction = ref->disq->m_entity.m_position - m_entity.m_position;
		direction = normalize(rotate(direction, ref->span / 2.f + span / 2.f, -Y3));
		direction *= m_radius + other.m_radius;
		direction += m_entity.m_position;

		//printf("Disq::closest position %f, %f, %f\n", direction.x(), direction.y(), direction.z());

		return direction;
	}

	vec3 Disq::nearest(Disq& other)
	{
		if(this->m_atoll)
			return this->m_atoll->escape(other);
		else
			return this->stick(other);
	}

	void Disq::contact(Disq& other)
	{
		if(!m_atoll && !other.m_atoll)
		{		
			m_atoll = make_unique<Atoll>();
			other.m_atoll = m_atoll;
			m_atoll->add(other);
			m_atoll->add(*this);
		}
		else if(!other.m_atoll)
		{
			other.m_atoll = m_atoll;
			m_atoll->add(other);
		}
		else if(!m_atoll)
		{
			m_atoll = other.m_atoll;
			m_atoll->add(*this);
		}

		float span = this->span(other);
		float angle = this->angle_to(other);

		this->add(other, span, angle);
	}

	void Disq::disconnect(Disq& other)
	{
		if(m_atoll /*&& (!m_atoll->inside(this) || m_atoll->m_contents.size() <= 2)*/)
		{
			//printf("Disq : removing from Atoll\n");
			m_atoll->remove(*this);
			m_atoll = nullptr;
		}

		//printf("Disq : %u remove %u\n", m_entity.m_id, other.m_entity.m_id);
		this->remove(other);
	}

	bool Disq::collisions(const vec3& pos)
	{
		vector<Collision> obstacles;
		this->collisions(pos, obstacles);
		return (obstacles.size() > 0);
	}
	
	void Disq::collisions(const vec3& pos, vector<Collision>& obstacles)
	{
		//this->m_collision_shape.setMargin(0.f);
		m_impl->project(pos, obstacles, m_group);
		//this->m_collision_shape.setMargin(-0.1f);
	}

	vec3 Disq::project(const vec3& pos)
	{
		vector<Collision> contacts;
		this->collisions(pos, contacts);

		if(contacts.size() >= 1)
			return as<Disq>(*contacts[0].m_second).nearest(*this);

		vec3 result = pos - m_entity.m_parent->absolute_position();

		printf("Disq::project position %f, %f, %f\n", result.x, result.y, result.z);

		return result;
	}

	void Disq::imbed(const vec3& pos)
	{
		m_entity.set_position(pos);
		this->imbed();
	}

	void Disq::imbed()
	{
		vec3 pos = this->project(m_entity.absolute_position());
		m_entity.set_position(pos);
		m_impl->force_update();
	}

	/*vec3 Disq::slide(float alpha, Disq& anchor)
	{
		return vec3();
	}*/

	/*bool Disq::insideAtoll()
	{
		if(!m_atoll)
			return false;

		bool inside = m_atoll->inside(this);

		if(inside)
			return true;

		m_atoll->remove(this);
		m_atoll.reset();
		return false;
	}*/
}
