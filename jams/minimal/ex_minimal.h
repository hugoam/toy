//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is provided 'as-is' under the zlib License, see the LICENSE.txt file.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <minimal/Forward.h>
#include <toy/toy.h>

using namespace mud;
using namespace toy;

extern "C"
{
	//_MINIMAL_EXPORT void ex_minimal_game(GameShell& app, Game& game);
}

class refl_ _MINIMAL_EXPORT Bullet : public Complex, public ColliderObject
{
public:
	Bullet(Entity& parent, const vec3& source, const quat& rotation, float velocity);
	~Bullet();

	comp_ attr_ Entity m_entity;

	attr_ vec3 m_source;
	attr_ vec3 m_velocity;

	bool m_impacted = false;
	bool m_destroy = false;
	vec3 m_impact = Zero3;

	//Solid m_solid;
	Collider m_collider;

	void update();
};

struct Aim
{
	vec3 source;
	quat rotation;
};

struct HumanController
{
	vec3 m_force = Zero3;
	vec3 m_torque = Zero3;
};

class refl_ _MINIMAL_EXPORT Human : public Complex, public Updatable, public ColliderObject
{
public:
	constr_ Human(Id id, Entity& parent, const vec3& position);
	~Human();

	comp_ attr_ Entity m_entity;
	comp_ attr_ Movable m_movable;

	Solid m_solid;

	float m_vangle = 0.f;
	bool m_aiming = false;

	bool m_walk = true;

	std::vector<unique_ptr<Bullet>> m_bullets;

	struct State { std::string name; bool loop; };
	State m_state = { "IdleAim", true };

	void next_frame(size_t tick, size_t delta);

	quat sight(bool aiming = true);
	Aim aim();
	void shoot();

	static const vec3 muzzle_offset;
	static float headlight_angle;
};

class refl_ _MINIMAL_EXPORT Crate : public Complex, public ColliderObject
{
public:
	constr_ Crate(Id id, Entity& parent, const vec3& position, const vec3& extents);

	comp_ attr_ Entity m_entity;
	comp_ attr_ Movable m_movable;

	attr_ vec3 m_extents;
	Solid m_solid;
};

class refl_ _MINIMAL_EXPORT Player
{
public:
	Player(World& world);
	
	World* m_world;
	Human* m_human = nullptr;
};
