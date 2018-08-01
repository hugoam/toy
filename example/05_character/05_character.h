//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is provided 'as-is' under the zlib License, see the LICENSE.txt file.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <05_character/Types.h>
#include <05_character/Forward.h>
#include <toy/toy.h>

using namespace mud;
using namespace toy;

class refl_ Human : public Complex, public Updatable, public ColliderObject
{
public:
	constr_ Human(Id id, Entity& parent, const vec3& position, float radius, float height, const std::string& first_name, const std::string& last_name);
	~Human();

	comp_ attr_ Entity m_entity;
	comp_ attr_ Movable m_movable = { m_entity };
	comp_ attr_ Agent m_agent;
	comp_ attr_ Emitter m_emitter = { m_entity };
	comp_ attr_ Receptor m_receptor = { m_entity };
	comp_ attr_ Actor m_actor = { m_entity };
	comp_ attr_ Reactive m_reactive = { m_entity };

	attr_ std::string m_first_name;
	attr_ std::string m_last_name;

	attr_ float m_counter = 0.f;
	attr_ float m_next_change;

	struct State
	{
		std::string m_action;
		float m_action_speed;
	};

	std::vector<State> m_states;

	Entity* m_shooting = nullptr;

	std::string full_name() { return m_first_name + " " + m_last_name; }

	AutoStat<float> m_life = { 100.f, 0.f, 100.f };
	size_t m_last_tick = 0;

	unique_ptr<Solid> m_solid;

	Procedure* m_current_movement = nullptr;

	void next_frame(size_t tick, size_t delta);
	void pumpSecond();
};

class refl_ Walk : public TypedAction<Walk>
{
public:
	Walk(toy::User* user, Entity& agent, Entity& target);

	static bool checkAgent(const Entity& agent);
	static bool checkTarget(const Entity& target);

	void begin();
	void update(size_t tick, double step);
	void abort();

	virtual void nextWaypoint();

protected:
	Agent& m_agent2;
	float m_range;
};

void paint_human(Gnode& parent, Human& human);
void paint_human(Gnode& parent, Human& human);
