//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is provided 'as-is' under the zlib License, see the LICENSE.txt file.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <platform/Forward.h>
#include <toy/toy.h>

using namespace mud;
using namespace toy;

extern "C"
{
	//_PLATFORM_EXPORT void ex_platform_game(GameShell& app, Game& game);
}

#ifdef TOY_ECS
namespace mud
{
	template <> struct TypedBuffer<Bullet> { using type = ComponentBufferDense<Bullet*>; static size_t index() { return 12; } };
	template <> struct TypedBuffer<Human> { using type = ComponentBufferDense<Human*>; static size_t index() { return 13; } };
	template <> struct TypedBuffer<Lamp> { using type = ComponentBufferDense<Lamp*>; static size_t index() { return 14; } };
	template <> struct TypedBuffer<Crate> { using type = ComponentBufferDense<Crate*>; static size_t index() { return 15; } };
}
#endif

class refl_ _PLATFORM_EXPORT TileWorld : public Complex
{
public:
	constr_ TileWorld(const std::string& name);
	~TileWorld();

	comp_ attr_ World m_world;
	comp_ attr_ BulletWorld m_bullet_world;
	comp_ attr_ Navmesh m_navmesh;

	uvec3 m_block_subdiv = uvec3(20, 4, 20);
	vec3 m_tile_scale = vec3(4.f);
	vec3 m_block_size;

	std::map<ivec2, TileBlock*> m_blocks;
	TileBlock* m_center_block = nullptr;

	void next_frame();

	void generate_block(GfxSystem& gfx_system, const ivec2& coord);
	void open_blocks(GfxSystem& gfx_system, const vec3& position, const ivec2& radius);
};

class refl_ _PLATFORM_EXPORT Bullet : public Entity
{
public:
	Bullet(HSpatial parent, const vec3& source, const quat& rotation, float velocity);
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

enum class refl_ Faction
{
	Ally,
	Enemy
};

struct refl_ Aim
{
	attr_ quat rotation;
	attr_ vec3 start;
	attr_ vec3 end;
	attr_ Spatial* hit;
};

struct HumanController
{
	vec3 m_force = Zero3;
	vec3 m_torque = Zero3;
};

struct refl_ Stance
{
	constr_ Stance() : name(""), loop(false) {}
	constr_ Stance(const std::string& name, bool loop) : name(name), loop(loop) {}
	attr_ std::string name;
	attr_ bool loop;
};

class refl_ _PLATFORM_EXPORT Human : public Entity, public NonCopy
{
public:
	constr_ Human(HSpatial parent, const vec3& position, Faction faction);
	~Human();

	comp_ attr_ CSpatial m_spatial;
	comp_ attr_ CMovable m_movable;
	comp_ attr_ CEmitter m_emitter;
	comp_ attr_ CReceptor m_receptor;
	comp_ attr_ CEntityScript m_script; // @todo ---->> ECS

	OSolid m_solid;

	attr_ Faction m_faction;

	vec2 m_angles = Zero2;
	bool m_aiming = false;
	Aim m_visor;

	attr_ float m_life = 1.f;
	attr_ float m_energy = 1.f;
	attr_ float m_discharge = 0.f;

	attr_ bool m_headlight = true;
	attr_ bool m_shield = false;
	attr_ bool m_walk = true;

	bool m_stealth = false;

	attr_ Human* m_target = nullptr;
	attr_ vec3 m_dest = Zero3;
	attr_ float m_cooldown = 0.f;

	attr_ Stance m_state = { "IdleAim", true };

	std::vector<unique_ptr<Bullet>> m_bullets;

	void next_frame(Spatial& spatial, Movable& movable, Receptor& receptor, size_t tick, size_t delta);

	meth_ quat sight(bool aiming = true);
	meth_ Aim aim();
	meth_ void shoot();
	meth_ void stop();
	void damage(float amount);

	static const vec3 muzzle_offset;
	static float headlight_angle;
};

class refl_ _PLATFORM_EXPORT Lamp : public Entity
{
public:
	constr_ Lamp(HSpatial parent, const vec3& position);

	comp_ attr_ CSpatial m_spatial;
	comp_ attr_ CMovable m_movable;
};

class refl_ _PLATFORM_EXPORT Crate : public Entity
{
public:
	constr_ Crate(HSpatial parent, const vec3& position, const vec3& extents);

	comp_ attr_ CSpatial m_spatial;
	comp_ attr_ CMovable m_movable;

	attr_ vec3 m_extents;
	OSolid m_solid;
};

class refl_ _PLATFORM_EXPORT Player
{
public:
	Player(TileWorld& world);
	
	void spawn(const vec3& start_position);
	
	TileWorld* m_world;
	Human* m_human = nullptr;
	Viewer* m_viewer = nullptr;
	ui::OrbitMode m_mode = ui::OrbitMode::ThirdPerson;
};
