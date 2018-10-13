//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <tree/Node.h>
#include <math/Timer.h>
#include <visu/Forward.h>

#include <ecs/Registry.h>

#include <core/World/World.h>
#include <core/Spatial/Spatial.h>
#include <core/Camera/Camera.h>
#include <core/Selector/Selection.h>

#include <gfx/Scene.h>

#ifndef MUD_CPP_20
#include <functional>
#include <string>
#endif

#define TOY_PHYSIC_DEBUG_DRAW

using namespace mud; namespace toy
{
	using string = std::string;

	struct TOY_VISU_EXPORT VisuPainter
	{
		VisuPainter(cstring name, size_t index, std::function<void(size_t, VisuScene&, Gnode&)> paint)
			: m_name(name)
			, m_index(index)
			, m_paint(paint)
		{}

		string m_name;
		size_t m_index;
		bool m_enabled = true;

		std::function<void(size_t, VisuScene&, Gnode&)> m_paint;
	};

	class refl_ TOY_VISU_EXPORT PhysicDebugDraw
	{
	public:
		PhysicDebugDraw(ImmediateDraw& immediate);
		~PhysicDebugDraw();

		void draw_physics(Gnode& parent, World& world, Medium& medium);

		class Impl;
		unique_ptr<Impl> m_impl;
	};

	class refl_ TOY_VISU_EXPORT VisuScene : public NonCopy
    {
    public:
        VisuScene(GfxSystem& gfx_system, SoundManager* sound_system = nullptr);
        ~VisuScene();

		attr_ GfxSystem& m_gfx_system;
		attr_ Scene m_scene;

		Ref m_player;

#ifdef TOY_SOUND
		SoundManager& m_snd_manager;
#endif

		std::vector<Gnode*> m_entities;

		std::vector<unique_ptr<VisuPainter>> m_painters;

		meth_ void next_frame();

		Gnode& entity_node(Gnode& parent, uint32_t entity, Spatial& spatial, size_t painter);

		inline void painter(cstring name, std::function<void(size_t, VisuScene&, Gnode&)> paint)
		{
			m_painters.emplace_back(make_unique<VisuPainter>(name, m_painters.size(), paint));
		}

		template <class T>
		inline void entity_painter(cstring name, World& world, void (*paint_func)(Gnode&, T&))
		{
			auto paint = [this, &world, paint_func](size_t index, VisuScene&, Gnode& parent)
			{
				world.m_ecs.Loop<Spatial, T>([this, paint_func, index, &parent](uint32_t entity, Spatial& spatial, T& component)
				{
					paint_func(this->entity_node(parent, entity, spatial, index), component);
				});
			};
			m_painters.emplace_back(make_unique<VisuPainter>(name, m_painters.size(), paint));
		}

		template <class T, class T_PaintFunc>
		inline void range_entity_painter(HSpatial reference, float range, cstring name, World& world, T_PaintFunc paint_func)
		{
			float range2 = range * range;
			auto paint = [reference, range2, this, &world, paint_func](size_t index, VisuScene&, Gnode& parent)
			{
				vec3 position = reference->m_position;
				world.m_ecs.Loop<Spatial, T>([&position, range2, this, paint_func, index, &parent](uint32_t entity, Spatial& spatial, T& component)
				{
					UNUSED(entity);
					float dist2 = distance2(spatial.m_position, position);
					if(dist2 < range2)
						paint_func(this->entity_node(parent, entity, spatial, index), component);
				});
			};
			m_painters.emplace_back(make_unique<VisuPainter>(name, m_painters.size(), paint));
		}

		template <class T, class T_Container>
		inline void object_painter(cstring name, T_Container& objects, void (*paint_func)(Gnode&, T&))
		{
			auto paint = [this, &objects, paint_func](size_t index, VisuScene&, Gnode& parent)
			{
				for(auto object : objects)
					paint_func(this->entity_node(parent, object->m_spatial.m_handle, object->m_spatial, index), *object);
			};
			m_painters.emplace_back(make_unique<VisuPainter>(name, m_painters.size(), paint));
		}

	private:
		Clock m_clock;
    };

	export_ TOY_VISU_EXPORT void update_camera(Camera& camera, mud::Camera& gfx_camera);

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
