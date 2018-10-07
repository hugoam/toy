//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is provided 'as-is' under the zlib License, see the LICENSE.txt file.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <blocks/Forward.h>
#include <toy/toy.h>

using namespace mud;
using namespace toy;

extern "C"
{
	//_BLOCKS_EXPORT void ex_blocks_game(GameShell& app, Game& game);
}

namespace mud
{
	template <> struct TypedBuffer<Well>	{ static size_t index() { return 20; } };
	template <> struct TypedBuffer<Camp>	{ static size_t index() { return 21; } };
	template <> struct TypedBuffer<Shield>	{ static size_t index() { return 22; } };
	template <> struct TypedBuffer<Slug>	{ static size_t index() { return 23; } };
	template <> struct TypedBuffer<Tank>	{ static size_t index() { return 24; } };
}

using HWell = ComponentHandle<Well>;
using HCamp = ComponentHandle<Camp>;
using HShield = ComponentHandle<Shield>;
using HSlug = ComponentHandle<Slug>;
using HTank = ComponentHandle<Tank>;

enum CustomCollisionGroup : short int
{
	CM_ENERGY = 1 << 10,
};

class refl_ _BLOCKS_EXPORT Well
{
public:
	constr_ Well() {}
	constr_ Well(HSpatial spatial, HEmitter emitter);

	static Entity create(ECS& ecs, HSpatial parent, const vec3& position);

	comp_ HSpatial m_spatial;
	comp_ HEmitter m_emitter;

	void next_frame(size_t tick, size_t delta);
};

class refl_ _BLOCKS_EXPORT Faction
{
public:
	constr_ Faction(uint32_t id, const Colour& colour);
	~Faction();

	attr_ uint32_t m_id;
	attr_ Colour m_colour;

	HTank m_leader = {};

	Material* m_highlight2;
	Material* m_highlight11;

	static const size_t s_max_factions = 10U;
};

export_ extern _BLOCKS_EXPORT std::vector<Faction> g_factions;

class refl_ _BLOCKS_EXPORT Camp
{
public:
	constr_ Camp() {}
	constr_ Camp(HSpatial spatial, const vec3& position, Faction& faction);

	static Entity create(ECS& ecs, HSpatial parent, const vec3& position, Faction& faction);

	comp_ HSpatial m_spatial;

	attr_ vec3 m_position;
	attr_ Faction* m_faction;
};

class refl_ _BLOCKS_EXPORT Shield
{
public:
	constr_ Shield() {}
	constr_ Shield(HSpatial spatial, HEmitter emitter, Faction& faction, float radius);

	static Entity create(ECS& ecs, HSpatial parent, const vec3& position, Faction& faction, float radius);

	comp_ HSpatial m_spatial;
	comp_ HEmitter m_emitter;

	attr_ Faction* m_faction;
	attr_ float m_radius;
	attr_ float m_charge;
	attr_ float m_discharge;

	OCollider m_collider;

	void next_frame(size_t tick, size_t delta);
};

class refl_ _BLOCKS_EXPORT Slug
{
public:
	Slug() {}
	Slug(HSpatial spatial, const vec3& source, const vec3& velocity, float power = 1.f);

	static Entity create(ECS& ecs, HSpatial parent, const vec3& source, const quat& rotation, const vec3& velocity, float power = 1.f);

	comp_ HSpatial m_spatial;

	attr_ vec3 m_source;
	attr_ vec3 m_velocity;
	attr_ float m_power = 1.f;

	bool m_impacted = false;
	bool m_destroy = false;
	vec3 m_impact = Zero3;

	//OSolid m_solid;
	OCollider m_collider;

	void update(Spatial& spatial);
};

class refl_ _BLOCKS_EXPORT Tank
{
public:
	constr_ Tank() {}
	constr_ Tank(HSpatial spatial, HMovable movable, HEmitter emitter, HReceptor receptor, Faction& faction);

	static Entity create(ECS& ecs, HSpatial parent, const vec3& position, Faction& faction);

	comp_ HSpatial m_spatial;
	comp_ HMovable m_movable;
	comp_ HEmitter m_emitter;
	comp_ HReceptor m_receptor;

	Faction* m_faction;

	OSolid m_solid;

	vec3 m_force = Zero3;
	vec3 m_torque = Zero3;

	quat m_turret_angle = ZeroQuat;

	float m_cooldown = 0.f;
	float m_hitpoints = 100.f;
	float m_energy = 100.f;
	float m_range = 50.f;

	bool m_stealth = false;
	float m_shock = 0.f;

	Tank* m_target = nullptr;
	vec3 m_dest = Zero3;

	bool m_ia = true;

	std::vector<EntityHandle<Slug>> m_slugs;

	void next_frame(Spatial& spatial, Movable& movable, Receptor& receptor, size_t tick, size_t delta);

	void shoot(bool critical = false);

	inline quat turret_rotation() { return m_turret_angle; } //quat(vec3(0.f, m_turret_angle, 0.f)); }
	inline vec3 turret_direction() { return rotate(turret_rotation(), -Z3); }
};

class refl_ _BLOCKS_EXPORT BlockWorld : public Complex
{
public:
	constr_ BlockWorld(const std::string& name, JobSystem& job_system);
	~BlockWorld();

	attr_ World m_world;
	attr_ BulletWorld m_bullet_world;
	attr_ Navmesh m_navmesh;

	attr_ uvec3 m_block_subdiv = uvec3(20, 4, 20);
	attr_ vec3 m_tile_scale = vec3(4.f);
	attr_ vec3 m_block_size;

	attr_ vec3 m_world_size;
	
	std::map<ivec2, Tileblock*> m_blocks;
	Tileblock* m_center_block = nullptr;

	void generate_block(GfxSystem& gfx_system, const ivec2& coord);
};

class refl_ _BLOCKS_EXPORT Player
{
public:
	Player(BlockWorld& world);
	BlockWorld* m_world;
	HTank m_tank;
};

_BLOCKS_EXPORT void paint_tank(Gnode& parent, Tank& tank);
