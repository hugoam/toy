//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#ifdef TWO_MODULES
module toy.visu
#else
#include <stl/algorithm.h>
#include <pool/Pool.hpp>
#include <pool/ObjectPool.hpp>
#include <ecs/ECS.hpp>
#include <gfx/Node3.h>
#include <gfx/Item.h>
#include <gfx/Mesh.h>
#include <gfx/Model.h>
#include <gfx/GfxSystem.h>
#include <core/Movable/Movable.h>
#include <core/Navmesh/Navmesh.h>
#include <core/WorldPage/WorldPage.h>
#include <visu/Types.h>
#include <visu/VisuPage.h>
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
