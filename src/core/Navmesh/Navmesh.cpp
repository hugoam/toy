//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/Types.h>
#include <core/Navmesh/Navmesh.h>

#include <infra/StringConvert.h>
#include <geom/Shape/ProcShape.h>
#include <geom/Shape/DrawShape.h>
#include <math/Random.h>

#include <core/World/World.h>
#include <core/World/Section.h>
#include <core/WorldPage/WorldPage.h>
#include <core/Spatial/Spatial.h>

#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "Recast.h"
#include "DetourNavMesh.h"
#include "DetourNavMeshBuilder.h"

using namespace mud; namespace toy
{
	uint32_t navmesh_num_vertices(const Navmesh& navmesh)
	{
		const dtNavMesh& dt_navmesh = *navmesh.m_navmesh;

		uint32_t count = 0;
		for(int i = 0; i < dt_navmesh.getMaxTiles(); ++i)
		{
			const dtMeshTile* tile = dt_navmesh.getTile(i);
			if(tile->header)
				count += tile->header->polyCount * navmesh.m_vertsPerPoly;
		}
		return count;
	}

	ShapeSize size_shape_lines(const ProcShape& shape, const NavmeshShape& navmesh)
	{
		UNUSED(shape);
		uint16_t num_verts = uint16_t(navmesh_num_vertices(navmesh.m_navmesh));
		return { num_verts, num_verts * 2 };
	}

	void draw_shape_lines(const ProcShape& shape, const NavmeshShape& navmesh_shape, MeshAdapter& writer)
	{
		UNUSED(shape);
		Navmesh& navmesh = navmesh_shape.m_navmesh;
		const dtNavMesh& dt_navmesh = *navmesh.m_navmesh;

		uint16_t index = 0;

		for(int t = 0; t < dt_navmesh.getMaxTiles(); ++t)
		{
			const dtMeshTile* tile = dt_navmesh.getTile(t);

			if(!tile->header)
				continue;

			for(int p = 0; p < tile->header->polyCount; ++p)
			{
				float r = random_scalar(0.f, 1.f);
				float g = random_scalar(0.f, 1.f);
				float b = random_scalar(0.f, 1.f);

				Colour colour = { r, g, b, 1.f };

				for(int v = 0; v < tile->polys[p].vertCount; ++v)
				{
					size_t vertex_offset = tile->polys[p].verts[v] * 3;
					vec3 vertex = { tile->verts[vertex_offset], tile->verts[vertex_offset + 1], tile->verts[vertex_offset + 2] };

					writer.position(vertex)
						  .colour(colour);

				}

				for(uint16_t i = 0; i < tile->polys[p].vertCount; i++)
				{
					uint16_t i0 = index + i;
					uint16_t i1 = i + 1 < tile->polys[p].vertCount ? index + i + 1 : index;
					writer.line(i0, i1);
				}

				index += tile->polys[p].vertCount;
			}
		}
	}

	ShapeSize size_shape_triangles(const ProcShape& shape, const NavmeshShape& navmesh)
	{
		UNUSED(shape);
		uint16_t num_verts = uint16_t(navmesh_num_vertices(navmesh.m_navmesh));
		return { num_verts, num_verts * 3 };
	}

	void draw_shape_triangles(const ProcShape& shape, const NavmeshShape& navmesh_shape, MeshAdapter& writer)
	{
		UNUSED(shape);
		Navmesh& navmesh = navmesh_shape.m_navmesh;
		const dtNavMesh& dt_navmesh = *navmesh.m_navmesh;

		uint16_t index = 0;

		for(int t = 0; t < dt_navmesh.getMaxTiles(); ++t)
		{
			const dtMeshTile* tile = dt_navmesh.getTile(t);

			if(!tile->header)
				continue;

			for(int p = 0; p < tile->header->polyCount; ++p)
			{
				float r = random_scalar(0.f, 1.f);
				float g = random_scalar(0.f, 1.f);
				float b = random_scalar(0.f, 1.f);

				Colour colour = { r, g, b, 0.6f };

				vec3 center = Zero3;

				for(int v = 0; v < tile->polys[p].vertCount; ++v)
				{

					size_t vertex_offset = tile->polys[p].verts[v] * 3;
					vec3 vertex = { tile->verts[vertex_offset], tile->verts[vertex_offset + 1], tile->verts[vertex_offset + 2] };

					center += vertex;

					writer.position(vertex)
						  .colour(colour);
				}

				center /= tile->polys[p].vertCount;
				
				writer.position(center)
					  .colour(colour);

				uint16_t center_index = index + tile->polys[p].vertCount;

				for(uint16_t i = 0; i < tile->polys[p].vertCount; i++)
				{
					uint16_t i0 = index + i;
					uint16_t i1 = i + 1 < tile->polys[p].vertCount ? index + i + 1 : index;
					writer.tri(i0, i1, center_index);
				}

				index += tile->polys[p].vertCount + 1;
			}
		}
	}

	struct NavmeshShapeDeclaration
	{
		NavmeshShapeDeclaration()
		{
			declare_shape<NavmeshShape>(DispatchDrawProcShape::me);
		}
	};

	Navblock::Navblock(HSpatial spatial, HWorldPage world_page, Navmesh& navmesh)
		: m_spatial(spatial)
		, m_world_page(world_page)
		, m_navmesh(&navmesh)
	{}

	Navblock::~Navblock()
	{}

	void Navblock::next_frame(const Spatial& spatial, const WorldPage& world_page, size_t tick, size_t delta)
	{
		UNUSED(tick); UNUSED(delta);
		
		if(m_auto_update && m_updated < world_page.m_last_rebuilt)
		{
			m_navmesh->update_block(*this);
			m_updated = spatial.m_last_tick;
		}
	}

	Navmesh::Navmesh(World& world)
		: rcTileMesh()
		, m_world(world)
	{
		static NavmeshShapeDeclaration decl;

		m_navgeom = make_unique<NavGeom>(m_geometry, m_world.m_name.c_str());
	}

	Navmesh::~Navmesh()
	{}

	void Navmesh::update_block(Navblock& navblock)
	{
		// @todo we are just appending here, should clear and update

		const Spatial& spatial = navblock.m_spatial;
		const WorldPage& world_page = navblock.m_world_page;

		for(const Geometry& geom : world_page.m_chunks)
		{
			if(geom.m_vertices.empty())
				return;

			printf("INFO: Updating Navmesh geometry block with %zu vertices\n", geom.m_vertices.size());

			ShapeIndex offset = ShapeIndex(m_geometry.m_vertices.size());

			for(const Vertex& vertex : geom.m_vertices)
				m_geometry.m_vertices.emplace_back(Vertex{ spatial.m_position + vertex.m_position });

			for(const Tri& tri : geom.m_triangles)
				m_geometry.m_triangles.push_back(Tri{ ShapeIndex(offset + tri.a), ShapeIndex(offset + tri.b), ShapeIndex(offset + tri.c) });

			m_dirty = true;
		}

	}

	void Navmesh::next_frame(size_t tick, size_t delta)
	{
		UNUSED(tick); UNUSED(delta);
		if(m_dirty)
		{
			this->build();
			m_dirty = false;
		}
	}

	void Navmesh::build()
	{
		m_navgeom->build();

		this->setupSettings();
		this->handleBuild();

		string name = m_world.m_name + ".nav";
		this->save(name.c_str());
	}

	void Navmesh::load()
	{
		this->setupSettings();

		string name = m_world.m_name + ".nav";
		this->load(name.c_str());
	}

	static const int NAVMESHSET_MAGIC = 'M'<<24 | 'S'<<16 | 'E'<<8 | 'T'; //'MSET';
	static const int NAVMESHSET_VERSION = 1;

	struct NavmeshSetHeader
	{
		int magic;
		int version;
		int numTiles;
		dtNavMeshParams params;
	};

	struct NavmeshTileHeader
	{
		dtTileRef tileRef;
		int dataSize;
	};

	void Navmesh::load(const char* path)
	{
		m_navmesh = this->_load(path);
	}

	void Navmesh::save(const char* path)
	{
		this->_save(path, m_navmesh);
	}

	void Navmesh::_save(const char* path, const dtNavMesh* mesh)
	{
		if (!mesh) return;
	
		FILE* fp = fopen(path, "wb");
		if (!fp)
			return;
	
		// Array header.
		NavmeshSetHeader header;
		header.magic = NAVMESHSET_MAGIC;
		header.version = NAVMESHSET_VERSION;
		header.numTiles = 0;
		for (int i = 0; i < mesh->getMaxTiles(); ++i)
		{
			const dtMeshTile* tile = mesh->getTile(i);
			if (!tile || !tile->header || !tile->dataSize) continue;
			header.numTiles++;
		}
		memcpy(&header.params, mesh->getParams(), sizeof(dtNavMeshParams));
		fwrite(&header, sizeof(NavmeshSetHeader), 1, fp);

		// Array tiles.
		for (int i = 0; i < mesh->getMaxTiles(); ++i)
		{
			const dtMeshTile* tile = mesh->getTile(i);
			if (!tile || !tile->header || !tile->dataSize) continue;

			NavmeshTileHeader tileHeader;
			tileHeader.tileRef = mesh->getTileRef(tile);
			tileHeader.dataSize = tile->dataSize;
			fwrite(&tileHeader, sizeof(tileHeader), 1, fp);

			fwrite(tile->data, tile->dataSize, 1, fp);
		}

		fclose(fp);
	}

	dtNavMesh* Navmesh::_load(const char* path)
	{
		FILE* fp = fopen(path, "rb");
		if (!fp) return 0;
	
		// Read header.
		NavmeshSetHeader header;
		fread(&header, sizeof(NavmeshSetHeader), 1, fp);
		if (header.magic != NAVMESHSET_MAGIC)
		{
			fclose(fp);
			return 0;
		}
		if (header.version != NAVMESHSET_VERSION)
		{
			fclose(fp);
			return 0;
		}
	
		dtNavMesh* mesh = dtAllocNavMesh();
		if (!mesh)
		{
			fclose(fp);
			return 0;
		}
		dtStatus status = mesh->init(&header.params);
		if (dtStatusFailed(status))
		{
			fclose(fp);
			return 0;
		}
		
		// Read tiles.
		for (int i = 0; i < header.numTiles; ++i)
		{
			NavmeshTileHeader tileHeader;
			fread(&tileHeader, sizeof(tileHeader), 1, fp);
			if (!tileHeader.tileRef || !tileHeader.dataSize)
				break;

			unsigned char* data = (unsigned char*)dtAlloc(tileHeader.dataSize, DT_ALLOC_PERM);
			if (!data) break;
			memset(data, 0, tileHeader.dataSize);
			fread(data, tileHeader.dataSize, 1, fp);
		
			mesh->addTile(data, tileHeader.dataSize, DT_TILE_FREE_DATA, tileHeader.tileRef, 0);
		}
	
		fclose(fp);
	
		return mesh;
	}

	NavmeshShape::NavmeshShape(Navmesh& navmesh)
		: Shape(type<NavmeshShape>())
		, m_navmesh(navmesh)
	{}

	object_ptr<Shape> NavmeshShape::clone() const { return make_object<NavmeshShape>(m_navmesh); }
}
