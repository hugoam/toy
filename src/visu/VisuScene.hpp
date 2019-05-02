//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <visu/Forward.h>
#include <visu/VisuScene.h>
#include <core/World/World.h>

#include <ecs/ECS.hpp>

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
