//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/Navmesh/NavGeom.h>
#include <core/Navmesh/ChunkyTriMesh.h>

#include <geom/Intersect.h>
#include <geom/Geometry.h>

#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <string.h>

#include <Recast.h>
#include <DetourNavMesh.h>
#include <DetourNavMeshBuilder.h>

namespace toy
{
	NavGeom::NavGeom(Geometry& geometry, cstring name)
		: m_geometry(geometry)
		, m_name(name)
		, m_ctx(make_unique<rcContext>())
	{}

	NavGeom::~NavGeom()
	{}

	bool NavGeom::build()
	{
		const float* verts = &m_geometry.m_vertices[0].m_position.x;
		const uint32_t* tris = &m_geometry.m_triangles[0].a;

		const int num_verts = int(m_geometry.m_vertices.size());
		const int num_tris = int(m_geometry.m_triangles.size());

		rcCalcBounds(verts, num_verts, value_ptr(m_geometry.m_bounds_min), value_ptr(m_geometry.m_bounds_max));

		m_chunkyMesh = make_unique<rcChunkyTriMesh>();
		if(!rcCreateChunkyTriMesh(verts, tris, num_tris, 256, m_chunkyMesh.get()))
		{
			m_ctx->log(RC_LOG_ERROR, "buildTiledNavigation: Failed to build chunky mesh.");
			return false;
		}

		return true;
	}

	bool NavGeom::raycastMesh(const vec3& src, const vec3& dst, float& tmin)
	{
		//vec3 dir = dst - src;

		// Prune hit ray.
		float btmin, btmax;
		if(!segment_aabb_intersection(src, dst, m_geometry.m_bounds_min, m_geometry.m_bounds_max, btmin, btmax))
			return false;
		vec2 p, q;
		p[0] = src[0] + (dst[0]-src[0])*btmin;
		p[1] = src[2] + (dst[2]-src[2])*btmin;
		q[0] = src[0] + (dst[0]-src[0])*btmax;
		q[1] = src[2] + (dst[2]-src[2])*btmax;
	
		int cid[512];
		const int ncid = rcGetChunksOverlappingSegment(m_chunkyMesh.get(), p, q, cid, 512);
		if(!ncid)
			return false;
	
		tmin = 1.0f;
		bool hit = false;
		//const float* verts = value_ptr(m_geometry.m_vertices[0].m_position);
	
		for(int i = 0; i < ncid; ++i)
		{
			const rcChunkyTriMeshNode& node = m_chunkyMesh->nodes[cid[i]];
			const int* tris = &m_chunkyMesh->tris[node.i*3];
			const int ntris = node.n;

			for(int j = 0; j < ntris*3; j += 3)
			{
				float t = 1;
				if(segment_triangle_intersection(src, dst, m_geometry.m_vertices[tris[j]].m_position,
															m_geometry.m_vertices[tris[j+1]].m_position,
															m_geometry.m_vertices[tris[j+2]].m_position, t))
				{
					if(t < tmin)
						tmin = t;
					hit = true;
				}
			}
		}
	
		return hit;
	}

	void NavGeom::addOffMeshConnection(const float* spos, const float* epos, const float rad,
										 unsigned char bidir, unsigned char area, unsigned short flags)
	{
		if(m_offMeshConCount >= MAX_OFFMESH_CONNECTIONS) return;
		float* v = &m_offMeshConVerts[m_offMeshConCount*3*2];
		m_offMeshConRads[m_offMeshConCount] = rad;
		m_offMeshConDirs[m_offMeshConCount] = bidir;
		m_offMeshConAreas[m_offMeshConCount] = area;
		m_offMeshConFlags[m_offMeshConCount] = flags;
		m_offMeshConId[m_offMeshConCount] = 1000 + m_offMeshConCount;
		rcVcopy(&v[0], spos);
		rcVcopy(&v[3], epos);
		m_offMeshConCount++;
	}

	void NavGeom::deleteOffMeshConnection(int i)
	{
		m_offMeshConCount--;
		float* src = &m_offMeshConVerts[m_offMeshConCount*3*2];
		float* dst = &m_offMeshConVerts[i*3*2];
		rcVcopy(&dst[0], &src[0]);
		rcVcopy(&dst[3], &src[3]);
		m_offMeshConRads[i] = m_offMeshConRads[m_offMeshConCount];
		m_offMeshConDirs[i] = m_offMeshConDirs[m_offMeshConCount];
		m_offMeshConAreas[i] = m_offMeshConAreas[m_offMeshConCount];
		m_offMeshConFlags[i] = m_offMeshConFlags[m_offMeshConCount];
	}

	void NavGeom::addConvexVolume(const float* verts, const int nverts,
									const float minh, const float maxh, unsigned char area)
	{
		if(m_volumeCount >= MAX_VOLUMES) return;
		ConvexVolume* vol = &m_volumes[m_volumeCount++];
		memset(vol, 0, sizeof(ConvexVolume));
		memcpy(vol->verts, verts, sizeof(float)*3*nverts);
		vol->hmin = minh;
		vol->hmax = maxh;
		vol->nverts = nverts;
		vol->area = area;
	}

	void NavGeom::deleteConvexVolume(int i)
	{
		m_volumeCount--;
		m_volumes[i] = m_volumes[m_volumeCount];
	}

}
