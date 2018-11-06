//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <visu/Types.h>
#include <visu/VisuPage.h>

#include <core/Movable/Movable.h>
#include <core/Navmesh/Navmesh.h>
#include <core/WorldPage/WorldPage.h>

#include <gfx/Node3.h>
#include <gfx/Item.h>
#include <gfx/Mesh.h>
#include <gfx/Model.h>
#include <gfx/GfxSystem.h>

#define DEBUG_NAVMESH_GEOM 0
#define DEBUG_NAVMESH 0

using namespace mud; namespace toy
{
	void paint_world_page(Gnode& parent, WorldPage& page)
	{
		if(!page.m_build_geometry)
			page.m_build_geometry = [&](WorldPage& page) { build_world_page_geometry(*parent.m_scene, page); };
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

	void build_geometry(Geometry& geometry, array<Item*> items)
	{
		size_t vertex_count = 0;
		size_t index_count = 0;

		for(Item* item : items)
			for(const ModelItem& model_item : item->m_model->m_items)
			{
				uint16_t num = item->m_instances.empty() ? 1U : uint16_t(item->m_instances.size());
				if(model_item.m_mesh->m_draw_mode != PLAIN)
					continue;
				vertex_count += num * model_item.m_mesh->m_vertex_count;
				index_count += num * model_item.m_mesh->m_index_count;
			}

		if(vertex_count == 0 || index_count == 0)
			return;

		geometry.allocate(vertex_count, index_count / 3);

		array<Vertex> vertices = geometry.vertices();
		array<uint32_t> indices = geometry.indices();
		MeshAdapter data(Vertex::vertex_format, vertices.data(), vertices.size(), indices.data(), indices.size(), true);

		for(Item* item : items)
			for(const ModelItem& model_item : item->m_model->m_items)
			{
				if(model_item.m_mesh->m_draw_mode != PLAIN)
					continue;

				if(item->m_instances.empty())
					model_item.m_mesh->read(data, item->m_node->m_transform);
				else
					for(const mat4& transform : item->m_instances)
						model_item.m_mesh->read(data, transform);
			}
	}

	void build_world_page_geometry(WorldPage& page, array<Item*> items)
	{
		page.m_chunks.emplace_back();
		Geometry& geom = page.m_chunks.back();
		build_geometry(geom, items);
	}

	void build_world_page_geometry(Scene& scene, WorldPage& page)
	{
		Spatial& spatial = page.m_spatial;

		std::vector<Item*> items;

		scene.m_pool->pool<Item>().iterate([&](Item& item)
		{
			//if((item->m_flags & ItemFlag::Static) != 0)
			//{
				//items.push_back(item);
			//}
			//else
			{
				bool add = vector_has(page.m_geometry_filter, string(item.m_model->m_name))
						&& item.m_node->m_object && item.m_node->m_object.m_type->is<EntityRef>();
				if(add)
				{
					Entity entity = { as_ent(item.m_node->m_object), 0 };
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
