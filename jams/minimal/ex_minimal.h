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

class refl_ _MINIMAL_EXPORT Bullet : public Entity
{
public:
	Bullet(Entity& parent, const vec3& source, const quat& rotation, float velocity);
	~Bullet();

	comp_ attr_ CSpatial m_spatial;

	attr_ vec3 m_source;
	attr_ vec3 m_velocity;

	bool m_impacted = false;
	bool m_destroy = false;
	vec3 m_impact = Zero3;

	//OSolid m_solid;
	OCollider m_collider;

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

class refl_ _MINIMAL_EXPORT Human : public Entity, public Updatable
{
public:
	constr_ Human(HSpatial parent, const vec3& position);
	~Human();

	comp_ attr_ CSpatial m_spatial;
	comp_ attr_ CMovable m_movable;

	OSolid m_solid;

	vec2 m_angles = Zero2;
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

class refl_ _MINIMAL_EXPORT Crate : public Entity
{
public:
	constr_ Crate(HSpatial parent, const vec3& position, const vec3& extents);

	comp_ attr_ CSpatial m_spatial;
	comp_ attr_ CMovable m_movable;

	attr_ vec3 m_extents;
	OSolid m_solid;
};

class refl_ _MINIMAL_EXPORT Player
{
public:
	Player(World& world);
	
	World* m_world;
	Human* m_human = nullptr;
};
