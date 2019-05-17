#include <toy/visu.h>
#include <two/gfx.h>
#include <two/snd.h>
#include <two/pool.h>
#include <two/geom.h>
#include <toy/core.h>
#include <two/tree.h>
#include <two/ecs.h>
#include <two/math.h>
#include <two/refl.h>
#include <two/infra.h>
#include <two/type.h>

#ifndef USE_STL
#ifdef TWO_MODULES
module toy.visu;
#else
#include <stl/vector.hpp>
#include <stl/unordered_map.hpp>
#endif

namespace stl
{
	using namespace toy;
	template class TOY_VISU_EXPORT vector<Gnode*>;
	template class TOY_VISU_EXPORT vector<vector<Gnode*>>;
	template class TOY_VISU_EXPORT vector<unique<VisuPainter>>;
}
#endif

#ifdef TWO_MODULES
module toy.visu;
#else
#endif

namespace two
{
    // Exported types
    
    
    template <> TOY_VISU_EXPORT Type& type<toy::PhysicDebugDraw>() { static Type ty("PhysicDebugDraw", sizeof(toy::PhysicDebugDraw)); return ty; }
    template <> TOY_VISU_EXPORT Type& type<toy::VisuScene>() { static Type ty("VisuScene", sizeof(toy::VisuScene)); return ty; }
}

#ifdef TWO_MODULES
module toy.visu
#else
#include <stl/algorithm.h>
#endif

#include <cstdio>

#define DEBUG_NAVMESH_GEOM 0
#define DEBUG_NAVMESH 0

namespace toy
{
	void paint_world_page(Gnode& parent, WorldPage& page)
	{
		if(page.m_updated > page.m_last_rebuilt)
		{
			printf("[info] Rebuilding WorldPage geometry\n");
			build_world_page_geometry(*parent.m_scene, page);
			page.update_geometry(page.m_spatial->m_last_tick);
		}
		//gfx::shape(parent, Cube(page.m_extents), Symbol(Colour(1.f, 0.f, 1.f, 0.2f)));
	}

	void paint_navmesh(Gnode& parent, Navmesh& navmesh)
	{
#if DEBUG_NAVMESH_GEOM
		if(navmesh.geom().m_vertices.size())
			gfx::shape(parent, navmesh.geom(), Symbol(Colour::Red, Colour::Red));
#elif DEBUG_NAVMESH
		if(navmesh.m_updated > navmesh.m_worldPage.m_last_rebuilt)
			gfx::shape(parent, NavmeshShape(navmesh), Symbol(Colour::Cyan, Colour::AlphaGrey));
#else
		UNUSED(parent); UNUSED(navmesh);
#endif
	}

	void build_geometry(Geometry& geometry, span<Item*> items)
	{
		size_t vertex_count = 0;
		size_t index_count = 0;

		for(Item* item : items)
			for(const ModelElem& elem : item->m_model->m_items)
			{
				uint16_t num = item->m_batch ? item->m_batch->m_cache.size() / 16 : 1U;
				if(elem.m_mesh->m_primitive < PrimitiveType::Triangles)
					continue;
				vertex_count += num * elem.m_mesh->m_vertex_count;
				index_count += num * elem.m_mesh->m_index_count;
			}

		if(vertex_count == 0 || index_count == 0)
			return;

		geometry.allocate(vertex_count, index_count / 3);

		span<Vertex> vertices = geometry.vertices();
		span<uint32_t> indices = geometry.indices();
		MeshAdapter data(Vertex::vertex_format, { vertices.data(), uint32_t(vertices.size()) }, { indices.data(), uint32_t(indices.size()) }, true);

		for(Item* item : items)
			for(const ModelElem& elem : item->m_model->m_items)
			{
				if(elem.m_mesh->m_primitive < PrimitiveType::Triangles)
					continue;

				if(!item->m_batch)
				{
					elem.m_mesh->m_cache.xcopy(data, item->m_node->m_transform * elem.m_transform);
					data.next();
				}
				else
				{
					span<mat4> transforms = { (mat4*)item->m_batch->m_cache.data(), item->m_batch->m_cache.size() / 16 };
					for(const mat4& transform : transforms)
					{
						elem.m_mesh->m_cache.xcopy(data, transform);
						data.next();
					}
				}

			}
	}

	void build_world_page_geometry(WorldPage& page, span<Item*> items)
	{
		Geometry& geom = push(page.m_chunks);
		build_geometry(geom, items);
	}

	void build_world_page_geometry(Scene& scene, WorldPage& page)
	{
		Spatial& spatial = page.m_spatial;

		vector<Item*> items;

		scene.m_pool->pool<Item>().iterate([&](Item& item)
		{
			//if((item->m_flags & ItemFlag::Static) != 0)
			//{
				//items.push_back(item);
			//}
			//else
			{
				bool add = has(page.m_geometry_filter, item.m_model->m_name);
				add &= bool(item.m_node->m_object);
				if(add)
				{
					Entity entity = item.m_node->m_object;
					Spatial& object = asa<Spatial>(entity);
					if((object.is_child_of(page.m_spatial) || &object == &spatial) && !isa<Movable>(entity))
						items.push_back(&item);
				}
			}
		});

		// @todo : filter on WORLD_GEOMETRY mask ? a way to filter out debug draw geometry ?
		build_world_page_geometry(page, items);
	}
}

#ifdef TWO_MODULES
module toy.visu
#else
#ifdef TOY_SOUND
#endif
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




#include <LinearMath/btScalar.h>
#include <LinearMath/btVector3.h>
#include <LinearMath/btQuaternion.h>
#include <LinearMath/btTransform.h>
#include <LinearMath/btTransformUtil.h>

namespace toy
{
	using namespace two;

	inline vec3 to_vec3(const btVector3& vec) { return { vec.x(), vec.y(), vec.z() }; }
	inline btVector3 to_btvec3(const vec3& vec) { return { vec.x, vec.y, vec.z }; }
	
	inline quat to_quat(const btQuaternion& q) { return { q.x(), q.y(), q.z(), q.w() }; }
	inline btQuaternion to_btquat(const quat& q) { return { q.x, q.y, q.z, q.w }; }

	inline Colour to_colour(const btVector3& col) { return { col.x(), col.y(), col.z() }; }
}

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


namespace toy
{
	OgreViewport::OgreViewport(Widget* parent, void* identity, Scene& scene)
		: Viewer(parent, identity, scene)
	{
		// camera->camera()->addCameraObserver(this);
	}

	/*void OgreViewport::addFocusObject(VisuEntity* object)
	{
		mFocusObjects.push_back(object);
		object->addFocusObserver(this);
	}

	void OgreViewport::removeFocusObject(VisuEntity* object)
	{
		remove(mFocusObjects, object);
		object->removeFocusObserver(this);
	}*/

	/*void OgreViewport::focusUpdate(VisuEntity* target, const vec3& position)
	{
		// For each focused entity that moves
		// We cast a ray between the camera and the entity position

		VisuEntity* blocking = checkBlocking(position);

		VisuEntity* old = mBlockingFocus[target];
		if(old != NULL && old != blocking)
			old->disableObstructing();
			// @crash : we can't operate on an OgreEntity we stored before if we can't be sure it's still valid

		if(blocking && target != blocking) // @kludge maybe ?
		{
			blocking->enableObstructing();
			mBlockingFocus[target] = blocking;
		}
	}

	VisuEntity* OgreViewport::checkBlocking(const vec3& position)
	{
		static Ogre::Ray ray;

		Ogre::vec3 origin = mCamera->ogreCamera()->getPosition();
		Ogre::vec3 target(position[0], position[1], position[2]);
		Ogre::vec3 normal = target - origin;
 
		ray.setOrigin(origin);
		ray.setDirection(normal);

		Ogre::vec3 result;
		Ogre::MovableObject* object;

		uint32_t queryMask = SHADEABLE_OGRE_MASK;

		float f = 0.f;
		if(mCollisionTools->raycast(ray, result, object, f, queryMask))
		{
			const Ogre::Any& any = object->getUserObjectBindings().getUserAny();
			if(!any.isEmpty())
				return Ogre::any_cast<VisuEntity*> (any);
		}

		return NULL;
	}*/

	/*void OgreViewport::cameraUpdated(const vec3& position, const quat& rotation, const vec3& target, float nearClipDist, float farClipDist)
	{
		//for(auto it = mFocusObjects.begin(); it != mFocusObjects.end(); ++it)
		//	focusUpdate((*it), (*it)->m_spatial->position());
	}*/
}

#if 0

//#include <core/Active/Effect.h>
//#include <core/Active/Active.h>

#ifdef TOY_SOUND
#endif

namespace toy
{
#ifdef TOY_SOUND
	SoundSource::SoundSource(HSpatial spatial, SoundManager& soundManager)
#else
	SoundSource::SoundSource(HSpatial spatial)
#endif
		: m_spatial(spatial)
		, m_active(entity.as<Active>())
#ifdef TOY_SOUND
		, m_soundManager(soundManager)
#endif
	{
		//m_spatial.addTransformObserver(*this);

		//m_active.effects().observe(*this);
		//m_active.states().observe(*this);
	}

#ifdef TOY_SOUND
	void SoundSource::soundDestroyed(Sound& sound)
	{
		for(auto kv : m_sounds)
			if(kv.second == &sound)
			{
				m_sounds.erase(kv.first);
				break;
			}
	}
#endif

	/*void SoundSource::transformUpdated(Spatial& spatial, const vec3& pos, const quat& rot, size_t tick, bool key)
	{
		for(auto& kv : m_sounds)
		{
			kv.second->set_position(entity.absolute_position());
			kv.second->setDirection(entity.front());
		}
	}*/

	void SoundSource::handle_add(State& effect)
	{
#ifdef TOY_SOUND
		Sound* sound = m_soundManager.createSound(("../data/sounds/" + effect.m_name + ".ogg").c_str(), true/*effect.loop()*/, false, [=](Sound& sound) { this->soundDestroyed(sound); });
		if(sound)
		{
			sound->play();
			sound->enable_3D();
			m_sounds[&effect] = sound;
		}
#else
		UNUSED(effect);
#endif
	}

	void SoundSource::handle_remove(State& effect)
	{
#ifdef TOY_SOUND
		if(m_sounds.find(&effect) != m_sounds.end())
		{
			Sound* sound = m_sounds[&effect];
			sound->stop();
			m_sounds.erase(&effect);
		}
#else
		UNUSED(effect);
#endif
	}
}
#endif
