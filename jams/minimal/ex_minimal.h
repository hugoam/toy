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

namespace mud
{
	template <> struct TypedBuffer<Bullet> { static size_t index() { return 20; } };
	template <> struct TypedBuffer<Human>  { static size_t index() { return 21; } };
	template <> struct TypedBuffer<Crate>  { static size_t index() { return 22; } };
}

using HBullet = ComponentHandle<Bullet>;
using HHuman = ComponentHandle<Human>;
using HCrate = ComponentHandle<Crate>;

class refl_ _MINIMAL_EXPORT Bullet
{
public:
	Bullet() {}
	Bullet(HSpatial spatial, const vec3& source, const quat& rotation, float velocity);

	static Entity create(ECS& ecs, HSpatial parent, const vec3& source, const quat& rotation, float velocity);

	comp_ HSpatial m_spatial;

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

class refl_ _MINIMAL_EXPORT Human
{
public:
	constr_ Human() {}
	constr_ Human(HSpatial spatial, HMovable movable);

	static Entity create(ECS& ecs, HSpatial parent, const vec3& position);

	comp_ HSpatial m_spatial;
	comp_ HMovable m_movable;

	OSolid m_solid;

	vec2 m_angles = Zero2;
	bool m_aiming = false;

	bool m_walk = true;

	std::vector<unique_ptr<Bullet>> m_bullets;

	struct State { std::string name; bool loop; };
	State m_state = { "IdleAim", true };

	void next_frame(Spatial& spatial, size_t tick, size_t delta);

	quat sight(bool aiming = true);
	Aim aim();
	void shoot();

	static const vec3 muzzle_offset;
	static float headlight_angle;
};

class refl_ _MINIMAL_EXPORT Crate
{
public:
	constr_ Crate() {}
	constr_ Crate(HSpatial spatial, HMovable movable, const vec3& extents);

	static Entity create(ECS& ecs, HSpatial parent, const vec3& position, const vec3& extents);

	comp_ HSpatial m_spatial;
	comp_ HMovable m_movable;

	attr_ vec3 m_extents;
	OSolid m_solid;
};

class refl_ _MINIMAL_EXPORT Player
{
public:
	Player(World& world);
	
	World* m_world;
	HHuman m_human = {};
};
