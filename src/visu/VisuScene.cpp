//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#ifdef TWO_MODULES
module toy.visu
#else
#include <infra/Reverse.h>
#include <tree/Graph.hpp>
#include <pool/Pool.hpp>
#include <pool/ObjectPool.hpp>
#include <ecs/Complex.h>
#include <refl/Member.h>
#include <math/Timer.h>
#include <geom/Shapes.h>
#include <geom/ShapesComplex.h>
#include <gfx/Gfx.h>
#include <gfx/Item.h>
#include <gfx/GfxSystem.h>
#include <gfx/Draw.h>
#include <gfx/Camera.h>
#include <gfx/Frustum.h>
#include <gfx/Material.h>
#ifdef TOY_SOUND
#include <snd/SoundManager.h>
#include <snd/Sound.h>
#endif
#include <core/World/Section.h>
#include <core/World/World.h>
#include <core/Spatial/Spatial.h>
#include <core/Physic/Obstacle.h>
#include <core/WorldPage/WorldPage.h>
#include <core/Selector/Selection.h>
#include <core/Navmesh/Navmesh.h>
#include <core/Bullet/BulletWorld.h>
#include <core/Physic/Solid.h>
#include <visu/Types.h>
#include <visu/VisuScene.h>
#include <visu/VisuScene.hpp>
#include <visu/VisuPage.h>
#endif

#include <cctype>

#include <bgfx/bgfx.h>

#ifdef _MSC_VER
#	pragma warning (push)
#	pragma warning (disable : 4127)
#	pragma warning (disable : 4100)
#	pragma warning (disable : 4305)
#	pragma warning (disable : 5033) // @todo deal with this ?
#endif

#include <core/Bullet/Bullet.h.inl>

#include <LinearMath/btIDebugDraw.h>
#include <btBulletCollisionCommon.h>

#ifdef _MSC_VER
#	pragma warning (pop)
#endif


namespace toy
{
#ifdef TOY_PHYSIC_DEBUG_DRAW
	class PhysicDebugDraw::Impl : public btIDebugDraw
	{
	public:
		Impl(ImmediateDraw& immediate) : m_immediate(immediate)
		{}

		virtual void drawLine(const btVector3& from, const btVector3& to, const btVector3& color) final
		{
			ImmediateDraw::Batch* batch = m_immediate.batch(OUTLINE, 2);
			uint32_t abgr = to_abgr(to_colour(color));
			uint16_t index = uint16_t(batch->m_vertices.size());

			batch->m_vertices.push_back({ to_vec3(from), abgr });
			batch->m_vertices.push_back({ to_vec3(to), abgr });

			batch->m_indices.push_back(index);
			batch->m_indices.push_back(index + 1);
		}

		virtual void drawContactPoint(const btVector3& PointOnB, const btVector3& normalOnB, btScalar distance, int lifeTime, const btVector3& color)
		{
			UNUSED(PointOnB); UNUSED(normalOnB); UNUSED(distance); UNUSED(lifeTime); UNUSED(color);
		}

		virtual void reportErrorWarning(const char* warningString)
		{
			UNUSED(warningString);
		}

		virtual void draw3dText(const btVector3& location, const char* textString)
		{
			UNUSED(location); UNUSED(textString);
		}

		virtual void setDebugMode(int debugMode)
		{
			UNUSED(debugMode);
		}

		virtual int	getDebugMode() const
		{
			// DBG_NoDebug = 0,
			// DBG_DrawWireframe = 1,
			// DBG_DrawAabb = 2,
			// DBG_DrawFeaturesText = 4,
			// DBG_DrawContactPoints = 8,
			// DBG_NoDeactivation = 16,
			// DBG_NoHelpText = 32,
			// DBG_DrawText = 64,
			// DBG_ProfileTimings = 128,
			// DBG_EnableSatComparison = 256,
			// DBG_DisableBulletLCP = 512,
			// DBG_EnableCCD = 1024,
			// DBG_DrawConstraints = (1 << 11),
			// DBG_DrawConstraintLimits = (1 << 12),
			// DBG_FastWireframe = (1 << 13),
			// DBG_DrawNormals = (1 << 14),
			// DBG_DrawFrames = (1 << 15),
			return DBG_DrawWireframe;
			//return DBG_DrawAabb;
		}

		bool m_enabled = false;
		ImmediateDraw& m_immediate;
	};
#endif
	
	PhysicDebugDraw::PhysicDebugDraw(ImmediateDraw& immediate)
		: m_impl(make_unique<Impl>(immediate))
	{}

	PhysicDebugDraw::~PhysicDebugDraw()
	{}

	void PhysicDebugDraw::draw_physics(Gnode& parent, World& world, Medium& medium)
	{
		UNUSED(parent);
		BulletMedium& bullet_world = as<BulletMedium>(as<BulletWorld>(world.m_complex).sub_world(medium));

		if(!bullet_world.m_collision_world->getDebugDrawer())
			bullet_world.m_collision_world->setDebugDrawer(m_impl.get());

		bullet_world.m_collision_world->debugDrawWorld();
	}

	VisuScene::VisuScene(GfxSystem& gfx, SoundManager* sound_system)
		: m_gfx(gfx)
		, m_scene(gfx)
#ifdef TOY_SOUND
		, m_snd_manager(*sound_system)
#endif
    {
#ifdef TOY_SOUND
		m_scene.m_graph.m_sound_manager = &m_snd_manager;
#endif
	}

	VisuScene::~VisuScene()
    {}

	Gnode& VisuScene::entity_node(Gnode& parent, Entity entity, Spatial& spatial, size_t painter)
	{
		const size_t index = entity.m_handle;

		if(m_entities.size() <= entity.m_stream)
			m_entities.resize(entity.m_stream + 1);

		vector<Gnode*>& nodes = m_entities[entity.m_stream];

		if(nodes.size() <= index)
			nodes.resize((index + 1) * 2);

		if(nodes[index] == nullptr)
		{
			nodes[index] = &gfx::node(parent.subx(uint16_t(index)), spatial.absolute_position(), spatial.absolute_rotation());
			nodes[index]->m_node->m_object = entity;
		}

		return nodes[index]->subx(uint16_t(painter));
	}

	void VisuScene::next_frame()
	{
#ifdef TOY_SOUND
		for(Sound* sound : reverse_adapt(m_scene.m_orphan_sounds))
			if(sound->m_loop || sound->m_state == Sound::STOPPED)
			{
				m_snd_manager.destroy_sound(*sound);
				remove(m_scene.m_orphan_sounds, sound);
			}

		m_snd_manager.update();
#endif

		for(vector<Gnode*>& entities : m_entities)
		{
			for(size_t i = 0; i < entities.size(); ++i)
				entities[i] = nullptr;
		}

		Gnode& root = m_scene.begin();

		for(size_t i = 0; i < m_painters.size(); ++i)
			m_painters[i]->m_paint(i, *this, root.subx(uint16_t(i)));
	}

	void scene_painters(VisuScene& scene, World& world)
	{
		UNUSED(scene); UNUSED(world);
		scene.entity_painter<WorldPage>("WorldPage", world, paint_world_page);
	}

	void paint_selection(Gnode& parent, Selection& selection, Ref hovered)
	{
		Aabb select_bounds;
		Aabb hover_bounds;

		parent.m_scene->m_pool->pool<Item>().iterate([&](Item& item)
		{
			//for(Ref object : selection)
			//	if(item.m_node->m_object == object)
			//		select_bounds.merge(item.m_aabb);
			//
			//if(hovered != Ref() && item.m_node->m_object == hovered)
			//	hover_bounds.merge(item.m_aabb);
		});

		gfx::draw(parent, Cube(select_bounds), Symbol(Colour::White));
		gfx::draw(parent, Cube(hover_bounds), Symbol(Colour::AlphaGrey));
	}

	void update_camera(Camera& camera, two::Camera& gfx_camera)
	{
		//gfx_camera.set_look_at(camera.m_lens_position, camera.m_spatial->absolute_position());

		gfx_camera.m_near = camera.m_near;
		gfx_camera.m_far = camera.m_far;
	}

	void paint_frustum(Gnode& parent, Frustum& frustum)
	{
		gfx::shape(parent, Box({ &frustum.m_corners[0], 8 }), Symbol());
	}

	void paint_camera(Gnode& parent, Camera& camera)
	{
		UNUSED(camera);
		gfx::shape(parent, Circle(0.01f), Symbol(Colour::White));
		//gfx::shape(parent, Spheroid(1.f), Symbol(Colour::White));
	}

#if 0
	void paint_light(Gnode& parent, LightSource& light)
	{
		gfx::light(parent, LightType::Point, light.m_shadows, light.m_colour, light.m_range);

#ifdef DEBUG_LIGHT
		gfx::shape(parent, Spheroid(0.2f), Symbol(Colour::White));
		gfx::shape(parent, Circle(light.m_range), Symbol(Colour::White));
#endif
	}

	void paint_symbolic(Gnode& parent, Symbolic& symbolic)
	{
		UNUSED(parent); UNUSED(symbolic);
		//for(auto& symbol : symbolic.m_symbols)
		//	gfx::shape(parent, symbol.m_shape, symbol);
	}
#endif

	void paint_obstacle(Gnode& parent, Obstacle& obstacle)
	{
		UNUSED(obstacle);
		//ConvexHullShape& colShape = as<ConvexHullShape>(obstacle.shape());
		gfx::shape(parent, Box(/*(colShape.points())*/), Symbol(Colour::Pink));
	}

#if 0
	void paint_disq(Gnode& parent, Disq& disq)
	{
		gfx::shape(parent, Circle(disq.m_radius, Axis::X), Symbol(Colour::Pink));
	}

	void paint_event_sphere(Gnode& parent, EventReceptor& receptor)
	{
		UNUSED(receptor);
		float size = 0.f; // receptor.sphere.radius
		gfx::shape(parent, Spheroid(size), Symbol(Colour(1.f, 0.f, 1.f, 0.2f)));
	}
#endif

	void paint_entity(Gnode& parent, Spatial& spatial)
	{
		UNUSED(parent); UNUSED(spatial);
		// if obstructed
	}

	void advance_animation(const string& name, bool loop, float speed)
	{
		UNUSED(loop); UNUSED(speed);
		string capname = name;
		capname[0] = char(toupper(capname[0]));

		// todo
	}

#if 0
	void paint_active(Gnode& parent, Active& active)
	{
		UNUSED(parent);

		for(Effect& effect : active.m_effects)
			advance_animation(effect.m_name, effect.m_loop, 1.f);

		for(State& state : active.m_states)
			advance_animation(state.m_name, true, 1.f);
	}
#endif

#ifdef TOY_SOUND
	bool sound(Gnode& parent, const string& sound, bool loop, float volume)
	{
		Gnode& self = parent.suba();
		if(self.m_sound)
		{
			self.m_sound->set_position(parent.m_attach->position());
			return self.m_sound->m_state != Sound::STOPPED;
		}

		LocatedFile location = parent.m_scene->m_gfx.locate_file("sounds/" + sound + ".ogg");
		self.m_sound = parent.m_sound_manager->create_sound(location.path(true), loop, false, [](Sound&) {});

		if(self.m_sound)
		{
			self.m_sound->play();
			self.m_sound->enable_3D();
			self.m_sound->set_volume(volume);
			return true;
		}

		return false;
	}
#else
	bool sound(Gnode& parent, const string& sound, bool loop, float volume)
	{
		UNUSED(parent); UNUSED(sound); UNUSED(loop); UNUSED(volume);
		return false;
	}
#endif

	// @todo
	// sub entities bone attachments
	// selected materials or bounding box
	// obstructing materials : set a variant of material with alpha blending when between camera and actor
	// depending on a SHADEABLE_OGRE_MASK
}
