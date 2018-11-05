//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <block/VisuBlock.h>

#include <infra/StringConvert.h>

#include <math/Random.h>

#include <block/Block.h>
#include <block/Element.h>
#include <block/Sector.h>
#include <block/Elements.h>

#include <meta/math/Convert.h>

#include <gfx/Scene.h>
#include <gfx/Item.h>
#include <gfx/Model.h>
#include <gfx/GfxSystem.h>

#include <gfx/Draw.h>
#include <gfx/Gfx.h>

#include <geom/Shape/Quad.h>
#include <geom/Shape/Cube.h>

#include <core/Spatial/Spatial.h>

#define DEBUG_BLOCK 0
#define BLOCK_WIREFRAME 1

using namespace mud; namespace toy
{
	void paint_heap(Gnode& parent, Heap& heap)
	{
		gfx::light(parent, LightType::Point, false, heap.m_element->m_colour, heap.m_radius * 2.f);
		//gfx::shape(parent, Circle(heap.m_radius), Symbol(heap.m_element.m_colour));
		//gfx::shape(parent, Spheroid(heap.radius(), Symbol(heap.m_element.m_colour));
	}

	void paint_block(Gnode& parent, Block& block, Material* material)
	{
#if DEBUG_BLOCK
		float size = block.m_size / 2.f;
		gfx::shape(parent, Cube(size), Symbol(Colour(1.f, 1.f, 1.f, 0.2f)));
#endif
		BlockState& state = parent.state<BlockState>();
		if(state.m_updated < block.m_updated)
		{
			state.m_updated = block.m_updated;
			update_block_geometry(parent.m_scene->m_gfx_system, block, state);
		}

		for(auto& element_model : state.m_models)
			gfx::item(parent, *element_model.second, ItemFlag::Default | ItemFlag::Static | ItemFlag::Selectable, material);
	}

	Material& plain_material(GfxSystem& gfx_system, cstring name)
	{
		Material& material = gfx_system.fetch_material(name, "pbr/pbr");
		material.m_base_block.m_geometry_filter = 1 << PLAIN;
		material.m_pbr_block.m_enabled = true;
		return material;
	}

	Material& wireframe_material(GfxSystem& gfx_system, cstring name, const Colour& colour)
	{
		string variant_name = string(name) + "_" + to_string(to_rgba(colour));
		Material& material = gfx_system.fetch_material(variant_name.c_str(), "unshaded");
		material.m_base_block.m_geometry_filter = 1 << OUTLINE;
		material.m_unshaded_block.m_enabled = true;
		material.m_unshaded_block.m_colour.m_value = colour;
		return material;
	}

	void paint_block(Gnode& parent, Block& block)
	{
		static Material& material = plain_material(parent.m_scene->m_gfx_system, "block");
		paint_block(parent, block, &material);
	}

	void paint_block_wireframe(Gnode& parent, Block& block, const Colour& colour)
	{
		static Material& material = wireframe_material(parent.m_scene->m_gfx_system, "block_wireframe", colour);
		paint_block(parent, block, &material);
	}

	void voxel_side(Block& block, size_t chunk, Element* element, Side side, std::vector<Quad>& quads, std::vector<ProcShape>& shapes)
	{
		Quad quad = { to_xz(block.chunk_size()), c_dirs_tangents[size_t(side)], c_dirs_normals[size_t(side)] };
		quad.m_center = block.chunk_position(chunk) + to_vec3(side) * block.chunk_size() / 2.f;

		quads.push_back(quad);
		shapes.push_back({ Symbol(), &quads.back(), OUTLINE });
		shapes.push_back({ Symbol(element->m_colour), &quads.back(), PLAIN });
	}

	void update_block_geometry(GfxSystem& gfx_system, Block& block, BlockState& state)
	{
		UNUSED(gfx_system);

		//Spatial& spatial = block.m_spatial;
		WorldPage& world_page = block.m_world_page;

		if(block.m_subdived)
			return;

		std::vector<Quad> quads;
		//quads.reserve(block.m_chunks.size() * 6 / 2);
		quads.reserve(block.m_chunks.size() * 6 / 2 * 16);

		state.m_models.clear();

		std::map<Element*, std::vector<ProcShape>> bodies;

		std::vector<Element*> elements = { &Earth::me, &Stone::me, &Sand::me, &Air::me, &Gas::me, &Minerals::me, &Fungus::me, &Water::me };

		size_t index = 0;
		for(Element* element : block.m_chunks)
		{
			if(element == nullptr /*|| element->matterState() != STATE_SOLID*/)
			{
				++index;
				continue;
			}

			for(Side side : c_sides)
			{
				Hunk neighbour = block.neighbour(index, side);

				if(!neighbour || neighbour.element == element)
					continue;

				voxel_side(block, index, element, side, quads, bodies[element]);
			}

			++index;
		}

		for(Element* element : elements)
			if(!bodies[element].empty())
			{
				string identifier = "sector_" + to_string(block.m_index) + "_" + element->m_name;

				printf("INFO: Creating geometry for Block %s, %zu quads\n", identifier.c_str(), bodies[element].size());

				state.m_models[element] = draw_model(identifier.c_str(), bodies[element], true);

				/*
				Material& plain = gfx_system.fetch_material(element->m_name.c_str(), "pbr/pbr");
				plain.m_base_block.m_geometry_filter = 1 << PLAIN;
				plain.m_pbr_block.m_enabled = true;

				state.m_models[element]->m_meshes[0]->m_material = &wireframe;
				state.m_models[element]->m_meshes[1]->m_material = &wireframe;
				*/

				world_page.m_geometry_filter.push_back(identifier); // @kludge : find out a more intelligent way to filter world geometry
			}

		//as<WorldPage>(block.sector()).update_geometry();
	}
}
