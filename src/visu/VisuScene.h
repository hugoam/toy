//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <tree/Node.h>
#include <math/Timer.h>
#include <infra/Updatable.h>
#include <visu/Forward.h>

#include <core/Entity/Entity.h>
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

		void next_frame();

		Gnode& entity_node(Gnode& parent, Entity& entity, size_t painter);

		inline void painter(cstring name, std::function<void(size_t, VisuScene&, Gnode&)> paint)
		{
			m_painters.emplace_back(make_unique<VisuPainter>(name, m_painters.size(), paint));
		}

		template <class T, class T_Store>
		inline void entity_painter(cstring name, T_Store& entities, void (*paint_func)(Gnode&, T&))
		{
			auto paint = [this, &entities, paint_func](size_t index, VisuScene&, Gnode& parent)
			{
				for(Entity* entity : entities.store())
					if(entity->isa<T>())
						paint_func(this->entity_node(parent, *entity, index), entity->as<T>());
			};
			m_painters.emplace_back(make_unique<VisuPainter>(name, m_painters.size(), paint));
		}

		template <class T, class T_Container>
		inline void object_painter(cstring name, T_Container& objects, void (*paint_func)(Gnode&, T&))
		{
			auto paint = [this, &objects, paint_func](size_t index, VisuScene&, Gnode& parent)
			{
				for(T* object : objects)
					paint_func(this->entity_node(parent, object->m_entity, index), *object);
			};
			m_painters.emplace_back(make_unique<VisuPainter>(name, m_painters.size(), paint));
		}

	private:
		Clock m_clock;
    };

	export_ TOY_VISU_EXPORT void update_camera(Camera& camera, mud::Camera& gfx_camera);

	export_ TOY_VISU_EXPORT void paint_selection(Gnode& parent, Selection& selection);

	export_ TOY_VISU_EXPORT void paint_camera(Gnode& parent, Camera& camera);
	export_ TOY_VISU_EXPORT void paint_light(Gnode& parent, LightSource& light);
	export_ TOY_VISU_EXPORT void paint_symbolic(Gnode& parent, Symbolic& symbolic);
	export_ TOY_VISU_EXPORT void paint_obstacle(Gnode& parent, Obstacle& obstacle);
	export_ TOY_VISU_EXPORT void paint_disq(Gnode& parent, Disq& disq);
	export_ TOY_VISU_EXPORT void paint_event_sphere(Gnode& parent, EventReceptor& receptor);
	export_ TOY_VISU_EXPORT void paint_entity(Gnode& parent, Entity& entity);
	export_ TOY_VISU_EXPORT void paint_active(Gnode& parent, Active& active);

	export_ TOY_VISU_EXPORT void scene_painters(VisuScene& scene, Array<Entity>& store);

	export_ TOY_VISU_EXPORT bool sound(Gnode& parent, const string& sound, bool loop = false, float volume = 1.f);
}
