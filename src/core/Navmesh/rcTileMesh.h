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

#ifndef RECASTSAMPLETILEMESH_H
#define RECASTSAMPLETILEMESH_H

#include <infra/NonCopy.h>
#include <type/Unique.h>
#include <geom/Mesh.h>
#include <core/Navmesh/NavGeom.h>

struct rcHeightfield;
struct rcCompactHeightfield;
struct rcContourSet;
struct rcPolyMesh;
struct rcPolyMeshDetail;
struct rcConfig;

class rcContext;

typedef unsigned int dtStatus;
typedef unsigned int dtPolyRef;
typedef unsigned int dtTileRef;

class dtNavMeshQuery;
class dtQueryFilter;
class dtNavMesh;

using namespace mud; namespace toy
{
	enum SamplePolyAreas : unsigned int
	{
		SAMPLE_POLYAREA_GROUND,
		SAMPLE_POLYAREA_WATER,
		SAMPLE_POLYAREA_ROAD,
		SAMPLE_POLYAREA_DOOR,
		SAMPLE_POLYAREA_GRASS,
		SAMPLE_POLYAREA_JUMP,
	};

	enum SamplePolyFlags : unsigned int
	{
		SAMPLE_POLYFLAGS_WALK = 0x01,		// Ability to walk (ground, grass, road)
		SAMPLE_POLYFLAGS_SWIM = 0x02,		// Ability to swim (water).
		SAMPLE_POLYFLAGS_DOOR = 0x04,		// Ability to move through doors.
		SAMPLE_POLYFLAGS_JUMP = 0x08,		// Ability to jump.
		SAMPLE_POLYFLAGS_ALL = 0xffff		// All abilities.
	};

	class TOY_CORE_EXPORT rcTileMesh : public NonCopy
	{
	public:
		float m_cellSize = 0.3f;
		float m_cellHeight = 0.2f;
		float m_agentHeight = 2.0f;
		float m_agentRadius = 0.35f;
		float m_agentMaxClimb = 0.9f;
		float m_agentMaxSlope = 45.0f;
		int m_regionMinSize = 8;
		int m_regionMergeSize = 20;
		bool m_monotonePartitioning = false;
		float m_edgeMaxLen = 12.0f;
		float m_edgeMaxError = 1.3f;
		int m_vertsPerPoly = 6;
		float m_detailSampleDist = 6.0f;
		float m_detailSampleMaxError = 1.0f;

		unique_ptr<rcContext> m_ctx;

	public:
		bool m_keepInterResults = false;
		bool m_buildAll = true;
		float m_totalBuildTimeMs = 0.f;

		Geometry m_geometry;
		dtNavMesh* m_navmesh = nullptr;
		unique_ptr<NavGeom> m_navgeom;
		unsigned char* m_triareas = nullptr;
		rcHeightfield* m_solid = nullptr;
		rcCompactHeightfield* m_chf = nullptr;
		rcContourSet* m_cset = nullptr;
		rcPolyMesh* m_pmesh = nullptr;
		rcPolyMeshDetail* m_dmesh = nullptr;
		unique_ptr<rcConfig> m_cfg;	

		int m_maxTiles = 0;
		int m_maxPolysPerTile = 0;
		float m_tileSize = 32.f;
	
		float m_tileBmin[3];
		float m_tileBmax[3];
		float m_tileBuildTime = 0.f;
		float m_tileMemUsage = 0.f;
		int m_tileTriCount = 0;

		unsigned char* buildTileMesh(const int tx, const int ty, const float* bmin, const float* bmax, int& dataSize);
	
		void cleanup();
	
	public:
		rcTileMesh();
		virtual ~rcTileMesh();
	
		void setupSettings();

		virtual void handleMeshChanged(Geometry& geom);
		virtual bool handleBuild();
	
		void getTilePos(const float* pos, int& tx, int& ty);
	
		void buildTile(const float* pos);
		void removeTile(const float* pos);
		void buildAllTiles();
		void removeAllTiles();

		dtStatus getPolyHeight(dtPolyRef ref, const float* pos, float* height) const;
	};
}


#endif // RECASTSAMPLETILEMESH_H
