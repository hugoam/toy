//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.
//
// Copyright (c) 2009-2010 Mikko Mononen memon@inside.org
//
// This software is provided 'as-is', without any express or implied
// warranty.  In no event will the authors be held liable for any damages
// arising from the use of this software.
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would be
//    appreciated but is not required.
// 2. Altered source versions must be plainly marked as such, and must not be
//    misrepresented as being the original software.
// 3. This notice may not be removed or altered from any source distribution.
//

#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <string.h>

#include <geom/Primitive.h>

#include <core/Navmesh/rcTileMesh.h>
#include <core/Navmesh/NavGeom.h>
#include <core/Navmesh/ChunkyTriMesh.h>

#include <Recast.h>
#include <DetourNavMesh.h>
#include <DetourNavMeshBuilder.h>
#include <DetourCommon.h>
#include <DetourAlloc.h>
#include <DetourAssert.h>

#ifdef WIN32
#	define snprintf _snprintf
#endif

namespace toy
{
	class MyContext : public rcContext
	{
	public:
		virtual void doLog(const rcLogCategory category, const char* msg, const int len) { UNUSED(category); UNUSED(len); printf("%s\n", msg); }
	};

	inline unsigned int nextPow2(unsigned int v)
	{
		v--;
		v |= v >> 1;
		v |= v >> 2;
		v |= v >> 4;
		v |= v >> 8;
		v |= v >> 16;
		v++;
		return v;
	}

	inline unsigned int ilog2(unsigned int v)
	{
		unsigned int r;
		unsigned int shift;
		r = (v > 0xffff) << 4; v >>= r;
		shift = (v > 0xff) << 3; v >>= shift; r |= shift;
		shift = (v > 0xf) << 2; v >>= shift; r |= shift;
		shift = (v > 0x3) << 1; v >>= shift; r |= shift;
		r |= (v >> 1);
		return r;
	}


	rcTileMesh::rcTileMesh() :
		m_ctx(make_unique<rcContext>()),
		m_cfg(make_unique<rcConfig>())
	{
		memset(m_tileBmin, 0, sizeof(m_tileBmin));
		memset(m_tileBmax, 0, sizeof(m_tileBmax));
	}

	void rcTileMesh::setupSettings()
	{
		m_keepInterResults = true;

		const float* bmin = value_ptr(m_geometry.m_bounds_min);
		const float* bmax = value_ptr(m_geometry.m_bounds_max);
		//char text[64];
		int gw = 0, gh = 0;
		rcCalcGridSize(bmin, bmax, m_cellSize, &gw, &gh);
		const int ts = (int)m_tileSize;
		const int tw = (gw + ts-1) / ts;
		const int th = (gh + ts-1) / ts;

		// Max tiles and max polys affect how the tile IDs are caculated.
		// There are 22 bits available for identifying a tile and a polygon.
		int tileBits = rcMin((int)ilog2(nextPow2(tw*th)), 14);
		if(tileBits > 14) tileBits = 14;
		int polyBits = 22 - tileBits;

		m_maxTiles = 1 << tileBits;
		m_maxPolysPerTile = 1 << polyBits;
	}

	rcTileMesh::~rcTileMesh()
	{
		cleanup();
		dtFreeNavMesh(m_navmesh);
		m_navmesh = 0;
	}

	void rcTileMesh::cleanup()
	{
		delete [] m_triareas;
		m_triareas = 0;
		rcFreeHeightField(m_solid);
		m_solid = 0;
		rcFreeCompactHeightfield(m_chf);
		m_chf = 0;
		rcFreeContourSet(m_cset);
		m_cset = 0;
		rcFreePolyMesh(m_pmesh);
		m_pmesh = 0;
		rcFreePolyMeshDetail(m_dmesh);
		m_dmesh = 0;
	}

	void rcTileMesh::handleMeshChanged(Geometry& geom)
	{
		UNUSED(geom);
		//m_geom = &geom;

		cleanup();

		dtFreeNavMesh(m_navmesh);
		m_navmesh = 0;
	}

	bool rcTileMesh::handleBuild()
	{
		if(m_geometry.m_triangles.empty())
		{
			m_ctx->log(RC_LOG_ERROR, "buildTiledNavigation: No vertices and triangles.");
			return false;
		}

		dtFreeNavMesh(m_navmesh);

		m_navmesh = dtAllocNavMesh();
		if(!m_navmesh)
		{
			m_ctx->log(RC_LOG_ERROR, "buildTiledNavigation: Could not allocate navmesh.");
			return false;
		}

		dtNavMeshParams params;
		rcVcopy(params.orig, value_ptr(m_geometry.m_bounds_min));
		params.tileWidth = m_tileSize*m_cellSize;
		params.tileHeight = m_tileSize*m_cellSize;
		params.maxTiles = m_maxTiles;
		params.maxPolys = m_maxPolysPerTile;
	
		dtStatus status;
	
		status = m_navmesh->init(&params);
		if(dtStatusFailed(status))
		{
			m_ctx->log(RC_LOG_ERROR, "buildTiledNavigation: Could not init navmesh.");
			return false;
		}
	
		if(m_buildAll)
			buildAllTiles();

		return true;
	}

	void rcTileMesh::buildTile(const float* pos)
	{
		if(m_geometry.m_triangles.empty()) return;
		if(!m_navmesh) return;
		
		const float* bmin = value_ptr(m_geometry.m_bounds_min);
		const float* bmax = value_ptr(m_geometry.m_bounds_max);
	
		const float ts = m_tileSize*m_cellSize;
		const int tx = (int)((pos[0] - bmin[0]) / ts);
		const int ty = (int)((pos[2] - bmin[2]) / ts);
	
		m_tileBmin[0] = bmin[0] + tx*ts;
		m_tileBmin[1] = bmin[1];
		m_tileBmin[2] = bmin[2] + ty*ts;
	
		m_tileBmax[0] = bmin[0] + (tx+1)*ts;
		m_tileBmax[1] = bmax[1];
		m_tileBmax[2] = bmin[2] + (ty+1)*ts;
	
		m_ctx->resetLog();
	
		int dataSize = 0;
		unsigned char* data = buildTileMesh(tx, ty, m_tileBmin, m_tileBmax, dataSize);
	
		if(data)
		{
			// Remove any previous data (navmesh owns and deletes the data).
			m_navmesh->removeTile(m_navmesh->getTileRefAt(tx,ty,0),0,0);
		
			// Let the navmesh own the data.
			dtStatus status = m_navmesh->addTile(data,dataSize,DT_TILE_FREE_DATA,0,0);
			if(dtStatusFailed(status))
				dtFree(data);
		}
	
		m_ctx->log(RC_LOG_PROGRESS, "Build Tile (%d,%d):", tx,ty);
	}

	void rcTileMesh::getTilePos(const float* pos, int& tx, int& ty)
	{
		if(m_geometry.m_triangles.empty()) return;
	
		const float* bmin = value_ptr(m_geometry.m_bounds_min);
	
		const float ts = m_tileSize*m_cellSize;
		tx = (int)((pos[0] - bmin[0]) / ts);
		ty = (int)((pos[2] - bmin[2]) / ts);
	}

	void rcTileMesh::removeTile(const float* pos)
	{
		if(m_geometry.m_triangles.empty()) return;
		if(!m_navmesh) return;
	
		const float* bmin = value_ptr(m_geometry.m_bounds_min);
		const float* bmax = value_ptr(m_geometry.m_bounds_max);

		const float ts = m_tileSize*m_cellSize;
		const int tx = (int)((pos[0] - bmin[0]) / ts);
		const int ty = (int)((pos[2] - bmin[2]) / ts);
	
		m_tileBmin[0] = bmin[0] + tx*ts;
		m_tileBmin[1] = bmin[1];
		m_tileBmin[2] = bmin[2] + ty*ts;
	
		m_tileBmax[0] = bmin[0] + (tx+1)*ts;
		m_tileBmax[1] = bmax[1];
		m_tileBmax[2] = bmin[2] + (ty+1)*ts;
	
		m_navmesh->removeTile(m_navmesh->getTileRefAt(tx,ty,0),0,0);
	}

	void rcTileMesh::buildAllTiles()
	{
		if(m_geometry.m_triangles.empty()) return;
		if(!m_navmesh) return;
	
		const float* bmin = value_ptr(m_geometry.m_bounds_min);
		const float* bmax = value_ptr(m_geometry.m_bounds_max);
		int gw = 0, gh = 0;
		rcCalcGridSize(bmin, bmax, m_cellSize, &gw, &gh);
		const int ts = (int)m_tileSize;
		const int tw = (gw + ts-1) / ts;
		const int th = (gh + ts-1) / ts;
		const float tcs = m_tileSize*m_cellSize;


		// Start the build process.
		m_ctx->startTimer(RC_TIMER_TEMP);

		for(int y = 0; y < th; ++y)
		{
			for(int x = 0; x < tw; ++x)
			{
				m_tileBmin[0] = bmin[0] + x*tcs;
				m_tileBmin[1] = bmin[1];
				m_tileBmin[2] = bmin[2] + y*tcs;
			
				m_tileBmax[0] = bmin[0] + (x+1)*tcs;
				m_tileBmax[1] = bmax[1];
				m_tileBmax[2] = bmin[2] + (y+1)*tcs;
			
				int dataSize = 0;
				unsigned char* data = buildTileMesh(x, y, m_tileBmin, m_tileBmax, dataSize);
				if(data)
				{
					// Remove any previous data (navmesh owns and deletes the data).
					m_navmesh->removeTile(m_navmesh->getTileRefAt(x,y,0),0,0);
					// Let the navmesh own the data.
					dtStatus status = m_navmesh->addTile(data,dataSize,DT_TILE_FREE_DATA,0,0);
					if(dtStatusFailed(status))
						dtFree(data);
				}
			}
		}
	
		// Start the build process.	
		m_ctx->stopTimer(RC_TIMER_TEMP);

		m_totalBuildTimeMs = m_ctx->getAccumulatedTime(RC_TIMER_TEMP)/1000.0f;
	
	}

	void rcTileMesh::removeAllTiles()
	{
		const float* bmin = value_ptr(m_geometry.m_bounds_min);
		const float* bmax = value_ptr(m_geometry.m_bounds_max);
		int gw = 0, gh = 0;
		rcCalcGridSize(bmin, bmax, m_cellSize, &gw, &gh);
		const int ts = (int)m_tileSize;
		const int tw = (gw + ts-1) / ts;
		const int th = (gh + ts-1) / ts;
	
		for(int y = 0; y < th; ++y)
			for(int x = 0; x < tw; ++x)
				m_navmesh->removeTile(m_navmesh->getTileRefAt(x,y,0),0,0);
	}


	unsigned char* rcTileMesh::buildTileMesh(const int tx, const int ty, const float* bmin, const float* bmax, int& dataSize)
	{
		if(m_geometry.m_triangles.empty())
		{
			m_ctx->log(RC_LOG_ERROR, "buildNavigation: Input mesh is not specified.");
			return 0;
		}
	

		m_tileMemUsage = 0;
		m_tileBuildTime = 0;
	
		cleanup();
	
		const float* verts = &m_geometry.m_vertices[0].m_position.x;
		const int nverts = int(m_geometry.m_vertices.size());
		const int ntris = int(m_geometry.m_triangles.size());
		const rcChunkyTriMesh* chunkyMesh = m_navgeom->m_chunkyMesh.get();
		
		// Init build configuration from GUI
		//memset(&m_cfg, 0, sizeof(m_cfg));
		m_cfg->cs = m_cellSize;
		m_cfg->ch = m_cellHeight;
		m_cfg->walkableSlopeAngle = m_agentMaxSlope;
		m_cfg->walkableHeight = (int)ceilf(m_agentHeight / m_cfg->ch);
		m_cfg->walkableClimb = (int)floorf(m_agentMaxClimb / m_cfg->ch);
		m_cfg->walkableRadius = (int)ceilf(m_agentRadius / m_cfg->cs);
		m_cfg->maxEdgeLen = (int)(m_edgeMaxLen / m_cellSize);
		m_cfg->maxSimplificationError = m_edgeMaxError;
		m_cfg->minRegionArea = (int)rcSqr(m_regionMinSize);		// Note: area = size*size
		m_cfg->mergeRegionArea = (int)rcSqr(m_regionMergeSize);	// Note: area = size*size
		m_cfg->maxVertsPerPoly = (int)m_vertsPerPoly;
		m_cfg->tileSize = (int)m_tileSize;
		m_cfg->borderSize = m_cfg->walkableRadius + 3; // Reserve enough padding.
		m_cfg->width = m_cfg->tileSize + m_cfg->borderSize * 2;
		m_cfg->height = m_cfg->tileSize + m_cfg->borderSize * 2;
		m_cfg->detailSampleDist = m_detailSampleDist < 0.9f ? 0 : m_cellSize * m_detailSampleDist;
		m_cfg->detailSampleMaxError = m_cellHeight * m_detailSampleMaxError;
	
		rcVcopy(m_cfg->bmin, bmin);
		rcVcopy(m_cfg->bmax, bmax);
		m_cfg->bmin[0] -= m_cfg->borderSize*m_cfg->cs;
		m_cfg->bmin[2] -= m_cfg->borderSize*m_cfg->cs;
		m_cfg->bmax[0] += m_cfg->borderSize*m_cfg->cs;
		m_cfg->bmax[2] += m_cfg->borderSize*m_cfg->cs;
	
		// Reset build times gathering.
		m_ctx->resetTimers();
	
		// Start the build process.
		m_ctx->startTimer(RC_TIMER_TOTAL);
	
		m_ctx->log(RC_LOG_PROGRESS, "Building navigation:");
		m_ctx->log(RC_LOG_PROGRESS, " - %d x %d cells", m_cfg->width, m_cfg->height);
		m_ctx->log(RC_LOG_PROGRESS, " - %.1fK verts, %.1fK tris", nverts/1000.0f, ntris/1000.0f);

		// Allocate voxel heightfield where we rasterize our input data to.
		m_solid = rcAllocHeightfield();
		if(!m_solid)
		{
			m_ctx->log(RC_LOG_ERROR, "buildNavigation: Out of memory 'solid'.");
			return 0;
		}
		if(!rcCreateHeightfield(m_ctx.get(), *m_solid, m_cfg->width, m_cfg->height, m_cfg->bmin, m_cfg->bmax, m_cfg->cs, m_cfg->ch))
		{
			m_ctx->log(RC_LOG_ERROR, "buildNavigation: Could not create solid heightfield.");
			return 0;
		}
	
		// Allocate span that can hold triangle flags.
		// If you have multiple meshes you need to process, allocate
		// and span which can hold the max number of triangles you need to process.
		m_triareas = new/*memory*/unsigned char[chunkyMesh->maxTrisPerChunk];
		if(!m_triareas)
		{
			m_ctx->log(RC_LOG_ERROR, "buildNavigation: Out of memory 'm_triareas' (%d).", chunkyMesh->maxTrisPerChunk);
			return 0;
		}
	
		vec2 tbmin, tbmax;
		tbmin[0] = m_cfg->bmin[0];
		tbmin[1] = m_cfg->bmin[2];
		tbmax[0] = m_cfg->bmax[0];
		tbmax[1] = m_cfg->bmax[2];
		int cid[512];// TODO: Make grow when returning too many items.
		const int ncid = rcGetChunksOverlappingRect(chunkyMesh, tbmin, tbmax, cid, 512);
		if(!ncid)
			return 0;
	
		m_tileTriCount = 0;
	
		for(int i = 0; i < ncid; ++i)
		{
			const rcChunkyTriMeshNode& node = chunkyMesh->nodes[cid[i]];
			const int* tris = &chunkyMesh->tris[node.i*3];
			const int ntris = node.n;
		
			m_tileTriCount += ntris;
		
			memset(m_triareas, 0, ntris*sizeof(unsigned char));
			rcMarkWalkableTriangles(m_ctx.get(), m_cfg->walkableSlopeAngle,
									verts, nverts, tris, ntris, m_triareas);
		
			rcRasterizeTriangles(m_ctx.get(), verts, nverts, tris, m_triareas, ntris, *m_solid, m_cfg->walkableClimb);
		}
	
		if(!m_keepInterResults)
		{
			delete [] m_triareas;
			m_triareas = 0;
		}
	
		// Once all geometry is rasterized, we do initial pass of filtering to
		// remove unwanted overhangs caused by the conservative rasterization
		// as well as filter spans where the character cannot possibly stand.
		rcFilterLowHangingWalkableObstacles(m_ctx.get(), m_cfg->walkableClimb, *m_solid);
		rcFilterLedgeSpans(m_ctx.get(), m_cfg->walkableHeight, m_cfg->walkableClimb, *m_solid);
		rcFilterWalkableLowHeightSpans(m_ctx.get(), m_cfg->walkableHeight, *m_solid);
	
		// Compact the heightfield so that it is faster to type from now on.
		// This will result more cache coherent data as well as the neighbours
		// between walkable cells will be calculated.
		m_chf = rcAllocCompactHeightfield();
		if(!m_chf)
		{
			m_ctx->log(RC_LOG_ERROR, "buildNavigation: Out of memory 'chf'.");
			return 0;
		}
		if(!rcBuildCompactHeightfield(m_ctx.get(), m_cfg->walkableHeight, m_cfg->walkableClimb, *m_solid, *m_chf))
		{
			m_ctx->log(RC_LOG_ERROR, "buildNavigation: Could not build compact data.");
			return 0;
		}
	
		if(!m_keepInterResults)
		{
			rcFreeHeightField(m_solid);
			m_solid = 0;
		}

		// Erode the walkable area by agent radius.
		if(!rcErodeWalkableArea(m_ctx.get(), m_cfg->walkableRadius, *m_chf))
		{
			m_ctx->log(RC_LOG_ERROR, "buildNavigation: Could not erode.");
			return 0;
		}

		// (Optional) Mark areas.
		const ConvexVolume* vols = m_navgeom->getConvexVolumes();
		for(int i  = 0; i < m_navgeom->getConvexVolumeCount(); ++i)
			rcMarkConvexPolyArea(m_ctx.get(), vols[i].verts, vols[i].nverts, vols[i].hmin, vols[i].hmax, (unsigned char)vols[i].area, *m_chf);
	
		if(m_monotonePartitioning)
		{
			// Partition the walkable surface into simple regions without holes.
			if(!rcBuildRegionsMonotone(m_ctx.get(), *m_chf, m_cfg->borderSize, m_cfg->minRegionArea, m_cfg->mergeRegionArea))
			{
				m_ctx->log(RC_LOG_ERROR, "buildNavigation: Could not build regions.");
				return 0;
			}
		}
		else
		{
			// Prepare for region partitioning, by calculating distance field along the walkable surface.
			if(!rcBuildDistanceField(m_ctx.get(), *m_chf))
			{
				m_ctx->log(RC_LOG_ERROR, "buildNavigation: Could not build distance field.");
				return 0;
			}
		
			// Partition the walkable surface into simple regions without holes.
			if(!rcBuildRegions(m_ctx.get(), *m_chf, m_cfg->borderSize, m_cfg->minRegionArea, m_cfg->mergeRegionArea))
			{
				m_ctx->log(RC_LOG_ERROR, "buildNavigation: Could not build regions.");
				return 0;
			}
		}
 	
		// Create contours.
		m_cset = rcAllocContourSet();
		if(!m_cset)
		{
			m_ctx->log(RC_LOG_ERROR, "buildNavigation: Out of memory 'cset'.");
			return 0;
		}
		if(!rcBuildContours(m_ctx.get(), *m_chf, m_cfg->maxSimplificationError, m_cfg->maxEdgeLen, *m_cset))
		{
			m_ctx->log(RC_LOG_ERROR, "buildNavigation: Could not create contours.");
			return 0;
		}
	
		if(m_cset->nconts == 0)
		{
			return 0;
		}
	
		// Build polygon navmesh from the contours.
		m_pmesh = rcAllocPolyMesh();
		if(!m_pmesh)
		{
			m_ctx->log(RC_LOG_ERROR, "buildNavigation: Out of memory 'pmesh'.");
			return 0;
		}
		if(!rcBuildPolyMesh(m_ctx.get(), *m_cset, m_cfg->maxVertsPerPoly, *m_pmesh))
		{
			m_ctx->log(RC_LOG_ERROR, "buildNavigation: Could not triangulate contours.");
			return 0;
		}
	
		// Build detail mesh.
		m_dmesh = rcAllocPolyMeshDetail();
		if(!m_dmesh)
		{
			m_ctx->log(RC_LOG_ERROR, "buildNavigation: Out of memory 'dmesh'.");
			return 0;
		}
	
		if(!rcBuildPolyMeshDetail(m_ctx.get(), *m_pmesh, *m_chf,
								   m_cfg->detailSampleDist, m_cfg->detailSampleMaxError,
								   *m_dmesh))
		{
			m_ctx->log(RC_LOG_ERROR, "buildNavigation: Could build polymesh detail.");
			return 0;
		}
	
		if(!m_keepInterResults)
		{
			rcFreeCompactHeightfield(m_chf);
			m_chf = 0;
			rcFreeContourSet(m_cset);
			m_cset = 0;
		}
	
		unsigned char* navData = 0;
		int navDataSize = 0;
		if(m_cfg->maxVertsPerPoly <= DT_VERTS_PER_POLYGON)
		{
			if(m_pmesh->nverts >= 0xffff)
			{
				// The vertex indices are ushorts, and cannot point to more than 0xffff vertices.
				m_ctx->log(RC_LOG_ERROR, "Too many vertices per tile %d (max: %d).", m_pmesh->nverts, 0xffff);
				return 0;
			}
		
			// Update poly flags from areas.
			for(int i = 0; i < m_pmesh->npolys; ++i)
			{
				if(m_pmesh->areas[i] == RC_WALKABLE_AREA)
					m_pmesh->areas[i] = SAMPLE_POLYAREA_GROUND;
			
				if(m_pmesh->areas[i] == SAMPLE_POLYAREA_GROUND ||
					m_pmesh->areas[i] == SAMPLE_POLYAREA_GRASS ||
					m_pmesh->areas[i] == SAMPLE_POLYAREA_ROAD)
				{
					m_pmesh->flags[i] = SAMPLE_POLYFLAGS_WALK;
				}
				else if(m_pmesh->areas[i] == SAMPLE_POLYAREA_WATER)
				{
					m_pmesh->flags[i] = SAMPLE_POLYFLAGS_SWIM;
				}
				else if(m_pmesh->areas[i] == SAMPLE_POLYAREA_DOOR)
				{
					m_pmesh->flags[i] = SAMPLE_POLYFLAGS_WALK | SAMPLE_POLYFLAGS_DOOR;
				}
			}
		
			dtNavMeshCreateParams params;
			memset(&params, 0, sizeof(params));
			params.verts = m_pmesh->verts;
			params.vertCount = m_pmesh->nverts;
			params.polys = m_pmesh->polys;
			params.polyAreas = m_pmesh->areas;
			params.polyFlags = m_pmesh->flags;
			params.polyCount = m_pmesh->npolys;
			params.nvp = m_pmesh->nvp;
			params.detailMeshes = m_dmesh->meshes;
			params.detailVerts = m_dmesh->verts;
			params.detailVertsCount = m_dmesh->nverts;
			params.detailTris = m_dmesh->tris;
			params.detailTriCount = m_dmesh->ntris;
			params.offMeshConVerts = m_navgeom->m_offMeshConVerts;
			params.offMeshConRad = m_navgeom->m_offMeshConRads;
			params.offMeshConDir = m_navgeom->m_offMeshConDirs;
			params.offMeshConAreas = m_navgeom->m_offMeshConAreas;
			params.offMeshConFlags = m_navgeom->m_offMeshConFlags;
			params.offMeshConUserID = m_navgeom->m_offMeshConId;
			params.offMeshConCount = m_navgeom->m_offMeshConCount;
			params.walkableHeight = m_agentHeight;
			params.walkableRadius = m_agentRadius;
			params.walkableClimb = m_agentMaxClimb;
			params.tileX = tx;
			params.tileY = ty;
			params.tileLayer = 0;
			rcVcopy(params.bmin, m_pmesh->bmin);
			rcVcopy(params.bmax, m_pmesh->bmax);
			params.cs = m_cfg->cs;
			params.ch = m_cfg->ch;
			params.buildBvTree = true;
		
			if(!dtCreateNavMeshData(&params, &navData, &navDataSize))
			{
				m_ctx->log(RC_LOG_ERROR, "Could not build Detour navmesh.");
				return 0;
			}		
		}
		m_tileMemUsage = navDataSize/1024.0f;
	
		m_ctx->stopTimer(RC_TIMER_TOTAL);
	
		// Show performance stats.
		//duLogBuildTimes(*m_ctx, m_ctx->getAccumulatedTime(RC_TIMER_TOTAL));
		m_ctx->log(RC_LOG_PROGRESS, ">> Polymesh: %d vertices  %d polygons", m_pmesh->nverts, m_pmesh->npolys);
	
		m_tileBuildTime = m_ctx->getAccumulatedTime(RC_TIMER_TOTAL)/1000.0f;

		dataSize = navDataSize;
		return navData;
	}

	dtStatus rcTileMesh::getPolyHeight(dtPolyRef ref, const float* pos, float* height) const
	{
		dtAssert(m_navmesh);

		const dtMeshTile* tile = 0;
		const dtPoly* poly = 0;
		if(dtStatusFailed(m_navmesh->getTileAndPolyByRef(ref, &tile, &poly)))
			return DT_FAILURE | DT_INVALID_PARAM;
	
		if(poly->getType() == DT_POLYTYPE_OFFMESH_CONNECTION)
		{
			const float* v0 = &tile->verts[poly->verts[0]*3];
			const float* v1 = &tile->verts[poly->verts[1]*3];
			const float d0 = dtVdist(pos, v0);
			const float d1 = dtVdist(pos, v1);
			const float u = d0 / (d0+d1);
			if(height)
				*height = v0[1] + (v1[1] - v0[1]) * u;
			return DT_SUCCESS;
		}
		else
		{
			const unsigned int ip = (unsigned int)(poly - tile->polys);
			const dtPolyDetail* pd = &tile->detailMeshes[ip];
			for(int j = 0; j < pd->triCount; ++j)
			{
				const unsigned char* t = &tile->detailTris[(pd->triBase+j)*4];
				const float* v[3];
				for(int k = 0; k < 3; ++k)
				{
					if(t[k] < poly->vertCount)
						v[k] = &tile->verts[poly->verts[t[k]]*3];
					else
						v[k] = &tile->detailVerts[(pd->vertBase+(t[k]-poly->vertCount))*3];
				}
				float h;
				if(dtClosestHeightPointTriangle(pos, v[0], v[1], v[2], h))
				{
					if(height)
						*height = h;
					return DT_SUCCESS;
				}
			}
		}
	
		return DT_FAILURE | DT_INVALID_PARAM;
	}
}
