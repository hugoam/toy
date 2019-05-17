//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is provided 'as-is' under the zlib License, see the LICENSE.txt file.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <minimal/Forward.h>

#include <ecs/ECS.hpp>
#include <stl/vector.hpp>
#include <stl/string.hpp>
#include <pool/SparsePool.hpp>
#include <pool/ObjectPool.hpp>
#include <pool/Pool.hpp>
#include <core/World/World.hpp>
#include <visu/VisuScene.hpp>
#include <tree/Graph.hpp>

#include <toy/toy.h>

using namespace two;
using namespace toy;

extern "C"
{
	//_MINIMAL_EXPORT void ex_minimal_game(GameShell& app, Game& game);
}

namespace two
{
	template <> struct TypedBuffer<Bullet> { static uint32_t index() { return 20; } };
	template <> struct TypedBuffer<Human>  { static uint32_t index() { return 21; } };
	template <> struct TypedBuffer<Crate>  { static uint32_t index() { return 22; } };
}

namespace two
{
	template struct refl_ ComponentHandle<Bullet>;
	template struct refl_ ComponentHandle<Human>;
	template struct refl_ ComponentHandle<Crate>;
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
	vec3 m_impact = vec3(0.f);

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
	vec3 m_force = vec3(0.f);
	vec3 m_torque = vec3(0.f);
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

	vec2 m_angles = vec2(0.f);
	bool m_aiming = false;

	bool m_walk = true;

	vector<EntityHandle<Bullet>> m_bullets;

	struct State { string name; bool loop; };
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
