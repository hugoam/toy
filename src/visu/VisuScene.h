//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <stl/string.h>
#include <stl/function.h>
#include <tree/Graph.h>
#include <math/Timer.h>
#include <visu/Forward.h>

#include <ecs/ECS.h>

#include <core/World/World.h>
#include <core/Spatial/Spatial.h>
#include <core/Camera/Camera.h>
#include <core/Selector/Selection.h>

#include <gfx/Scene.h>

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
