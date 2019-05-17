#pragma once

#include <two/gfx.h>
#include <two/snd.h>
#include <toy/core.h>
#include <two/tree.h>
#include <two/ecs.h>
#include <two/tool.h>
#include <toy/util.h>
#include <two/math.h>
#include <two/gfx.ui.h>
#include <two/infra.h>
#include <two/type.h>




#ifndef TOY_VISU_EXPORT
#define TOY_VISU_EXPORT TWO_IMPORT
#endif

namespace toy
{
    struct VisuPainter;
    class PhysicDebugDraw;
    class VisuScene;
    class SoundSource;
}

#include <stdint.h>
#include <stl/string.h>
#include <stl/vector.h>

#if !defined TWO_MODULES || defined TWO_TYPE_LIB
#endif

#ifndef TWO_MODULES
#endif


namespace two
{
    // Exported types
    
    
    export_ template <> TOY_VISU_EXPORT Type& type<toy::PhysicDebugDraw>();
    export_ template <> TOY_VISU_EXPORT Type& type<toy::VisuScene>();
}




#include <stl/string.h>
#include <stl/function.h>




#define TOY_PHYSIC_DEBUG_DRAW

namespace toy
{
	struct TOY_VISU_EXPORT VisuPainter
	{
		VisuPainter(cstring name, size_t index, function<void(size_t, VisuScene&, Gnode&)> paint)
			: m_name(name)
			, m_index(index)
			, m_paint(paint)
		{}

		string m_name;
		size_t m_index;
		bool m_enabled = true;

		function<void(size_t, VisuScene&, Gnode&)> m_paint;
	};

	class refl_ TOY_VISU_EXPORT PhysicDebugDraw
	{
	public:
		PhysicDebugDraw(ImmediateDraw& immediate);
		~PhysicDebugDraw();

		void draw_physics(Gnode& parent, World& world, Medium& medium);

		class Impl;
		unique<Impl> m_impl;
	};

	class refl_ TOY_VISU_EXPORT VisuScene
    {
    public:
        VisuScene(GfxSystem& gfx, SoundManager* sound_system = nullptr);
        ~VisuScene();

		attr_ GfxSystem& m_gfx;
		attr_ Scene m_scene;

		Ref m_player;

#ifdef TOY_SOUND
		SoundManager& m_snd_manager;
#endif

		vector<vector<Gnode*>> m_entities;

		vector<unique<VisuPainter>> m_painters;

		meth_ void next_frame();

		Gnode& entity_node(Gnode& parent, Entity entity, Spatial& spatial, size_t painter);

		inline void painter(cstring name, function<void(size_t, VisuScene&, Gnode&)> paint)
		{
			m_painters.push_back(construct<VisuPainter>(name, m_painters.size(), paint));
		}

		template <class T>
		inline void entity_painter(cstring name, World& world, void(*paint_func)(Gnode&, T&));

		template <class T, class T_PaintFunc>
		inline void range_entity_painter(HSpatial reference, float range, cstring name, World& world, T_PaintFunc paint_func);

		template <class T, class T_Container>
		inline void object_painter(cstring name, T_Container& objects, void(*paint_func)(Gnode&, T&));

	private:
		Clock m_clock;
    };

	export_ TOY_VISU_EXPORT void update_camera(Camera& camera, two::Camera& gfx_camera);

	export_ TOY_VISU_EXPORT void paint_selection(Gnode& parent, Selection& selection, Ref hovered);

	export_ TOY_VISU_EXPORT void paint_camera(Gnode& parent, Camera& camera);
	//export_ TOY_VISU_EXPORT void paint_light(Gnode& parent, LightSource& light);
	//export_ TOY_VISU_EXPORT void paint_symbolic(Gnode& parent, Symbolic& symbolic);
	export_ TOY_VISU_EXPORT void paint_obstacle(Gnode& parent, Obstacle& obstacle);
	//export_ TOY_VISU_EXPORT void paint_disq(Gnode& parent, Disq& disq);
	//export_ TOY_VISU_EXPORT void paint_event_sphere(Gnode& parent, EventReceptor& receptor);
	export_ TOY_VISU_EXPORT void paint_entity(Gnode& parent, Spatial& spatial);
	//export_ TOY_VISU_EXPORT void paint_active(Gnode& parent, Active& active);

	export_ TOY_VISU_EXPORT void scene_painters(VisuScene& scene, World& world);

	export_ TOY_VISU_EXPORT bool sound(Gnode& parent, const string& sound, bool loop = false, float volume = 1.f);
}

namespace toy
{
	export_ TOY_VISU_EXPORT void build_geometry(Geometry& geometry, span<Item*> items);
	export_ TOY_VISU_EXPORT void build_world_page_geometry(WorldPage& page, span<Item*> items);
	export_ TOY_VISU_EXPORT void build_world_page_geometry(Scene& scene, WorldPage& page);

	export_ TOY_VISU_EXPORT void paint_world_page(Gnode& parent, WorldPage& page);
	export_ TOY_VISU_EXPORT void paint_navmesh(Gnode& parent, Navmesh& navmesh);
}



namespace toy
{
	class TOY_VISU_EXPORT OgreViewport : public Viewer
	{
	public:
		OgreViewport(Widget* parent, void* identity, Scene& scene/*, VisuCamera& camera*/);
	};
}

#if 0

#include <stl/map.h>

#ifdef TOY_SOUND
#endif

namespace toy
{
	class refl_ TOY_VISU_EXPORT SoundSource : public StoreObserver<State>
	{
	public:
#ifdef TOY_SOUND
		SoundSource(HSpatial spatial, SoundManager& soundManager);
#else
		SoundSource(HSpatial spatial);
#endif

		attr_ HSpatial m_spatial;

#ifdef TOY_SOUND
		void soundDestroyed(Sound& sound);
#endif

		void handle_add(State& effect);
		void handle_remove(State& effect);

	private:
		Active& m_active;

#ifdef TOY_SOUND
		SoundManager& m_soundManager;
		map<State*, Sound*> m_sounds;
#endif

		size_t m_updated;
	};
}
#endif





using namespace two; namespace toy
{
	template <class T>
	inline void VisuScene::entity_painter(cstring name, World& world, void (*paint_func)(Gnode&, T&))
	{
		auto paint = [this, &world, paint_func](size_t index, VisuScene&, Gnode& parent)
		{
			world.m_ecs.loop_ent<Spatial, T>([this, paint_func, index, &parent](Entity entity, Spatial& spatial, T& component)
			{
				paint_func(this->entity_node(parent, entity, spatial, index), component);
			});
		};
		m_painters.push_back(make_unique<VisuPainter>(name, m_painters.size(), paint));
	}

	template <class T, class T_PaintFunc>
	inline void VisuScene::range_entity_painter(HSpatial reference, float range, cstring name, World& world, T_PaintFunc paint_func)
	{
		float range2 = range * range;
		auto paint = [reference, range2, this, &world, paint_func](size_t index, VisuScene&, Gnode& parent)
		{
			vec3 position = reference->m_position;
			world.m_ecs.loop_ent<Spatial, T>([&position, range2, this, paint_func, index, &parent](Entity entity, Spatial& spatial, T& component)
			{
				float dist2 = distance2(spatial.m_position, position);
				if(dist2 < range2)
					paint_func(this->entity_node(parent, entity, spatial, index), component);
			});
		};
		m_painters.push_back(make_unique<VisuPainter>(name, m_painters.size(), paint));
	}

	template <class T, class T_Container>
	inline void VisuScene::object_painter(cstring name, T_Container& objects, void (*paint_func)(Gnode&, T&))
	{
		auto paint = [this, &objects, paint_func](size_t index, VisuScene&, Gnode& parent)
		{
			for(auto object : objects)
				paint_func(this->entity_node(parent, object->m_spatial, object->m_spatial, index), *object);
		};
		m_painters.push_back(make_unique<VisuPainter>(name, m_painters.size(), paint));
	}
}
