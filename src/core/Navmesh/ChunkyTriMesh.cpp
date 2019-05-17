//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <math/Math.h>
#include <geom/Intersect.h>
#include <core/Navmesh/ChunkyTriMesh.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

namespace toy
{
	struct BoundsItem
	{
		vec2 bmin;
		vec2 bmax;
		int i;
	};

	static int compareItemX(const void* va, const void* vb)
	{
		const BoundsItem* a = (const BoundsItem*)va;
		const BoundsItem* b = (const BoundsItem*)vb;
		if(a->bmin[0] < b->bmin[0])
			return -1;
		if(a->bmin[0] > b->bmin[0])
			return 1;
		return 0;
	}

	static int compareItemY(const void* va, const void* vb)
	{
		const BoundsItem* a = (const BoundsItem*)va;
		const BoundsItem* b = (const BoundsItem*)vb;
		if(a->bmin[1] < b->bmin[1])
			return -1;
		if(a->bmin[1] > b->bmin[1])
			return 1;
		return 0;
	}

	static void calcExtends(const BoundsItem* items, const int /*nitems*/, const int imin, const int imax, vec2& bmin, vec2& bmax)
	{
		bmin = items[imin].bmin;
		bmax = items[imin].bmax;

		for(int i = imin + 1; i < imax; ++i)
		{
			bmin = min(items[i].bmin, bmin);
			bmax = max(items[i].bmax, bmax);
		}
	}

	inline int longestAxis(float x, float y)
	{
		return y > x ? 1 : 0;
	}

	static void subdivide(BoundsItem* items, int nitems, int imin, int imax, int trisPerChunk,int& curNode, rcChunkyTriMeshNode* nodes, const int maxNodes,
						  int& curTri, int* outTris, const uint32_t* inTris)
	{
		int inum = imax - imin;
		int icur = curNode;

		if(curNode > maxNodes)
			return;

		rcChunkyTriMeshNode& node = nodes[curNode++];

		if(inum <= trisPerChunk)
		{
			// Leaf
			calcExtends(items, nitems, imin, imax, node.bmin, node.bmax);

			// Copy triangles.
			node.i = curTri;
			node.n = inum;

			for(int i = imin; i < imax; ++i)
			{
				const uint32_t* src = &inTris[items[i].i * 3];
				int* dst = &outTris[curTri * 3];
				curTri++;
				dst[0] = static_cast<int>(src[0]);
				dst[1] = static_cast<int>(src[1]);
				dst[2] = static_cast<int>(src[2]);
			}
		}
		else
		{
			// Split
			calcExtends(items, nitems, imin, imax, node.bmin, node.bmax);

			int	axis = longestAxis(node.bmax[0] - node.bmin[0],
				node.bmax[1] - node.bmin[1]);

			if(axis == 0)
			{
				// Sort along x-axis
				qsort(items + imin, inum, sizeof(BoundsItem), compareItemX);
			}
			else if(axis == 1)
			{
				// Sort along y-axis
				qsort(items + imin, inum, sizeof(BoundsItem), compareItemY);
			}

			int isplit = imin + inum / 2;

			// Left
			subdivide(items, nitems, imin, isplit, trisPerChunk, curNode, nodes, maxNodes, curTri, outTris, inTris);
			// Right
			subdivide(items, nitems, isplit, imax, trisPerChunk, curNode, nodes, maxNodes, curTri, outTris, inTris);

			int iescape = curNode - icur;
			// Negative index means escape.
			node.i = -iescape;
		}
	}

	bool rcCreateChunkyTriMesh(const float* verts, const uint32_t* tris, int ntris, int trisPerChunk, rcChunkyTriMesh* cm)
	{
		int nchunks = (ntris + trisPerChunk - 1) / trisPerChunk;

		cm->nodes = new/*memory*/rcChunkyTriMeshNode[nchunks * 4];
		if(!cm->nodes)
			return false;

		cm->tris = new/*memory*/int[ntris * 3];
		if(!cm->tris)
			return false;

		cm->ntris = ntris;

		// Build tree
		BoundsItem* items = new/*memory*/BoundsItem[ntris];
		if(!items)
			return false;

		for(int i = 0; i < ntris; i++)
		{
			const uint32_t* t = &tris[i * 3];
			BoundsItem& it = items[i];
			it.i = i;
			// Calc triangle XZ bounds.
			it.bmin[0] = it.bmax[0] = verts[t[0] * 3 + 0];
			it.bmin[1] = it.bmax[1] = verts[t[0] * 3 + 2];
			for(int j = 1; j < 3; ++j)
			{
				const float* v = &verts[t[j] * 3];
				if(v[0] < it.bmin[0]) it.bmin[0] = v[0];
				if(v[2] < it.bmin[1]) it.bmin[1] = v[2];

				if(v[0] > it.bmax[0]) it.bmax[0] = v[0];
				if(v[2] > it.bmax[1]) it.bmax[1] = v[2];
			}
		}

		int curTri = 0;
		int curNode = 0;
		subdivide(items, ntris, 0, ntris, trisPerChunk, curNode, cm->nodes, nchunks * 4, curTri, cm->tris, tris);

		delete[] items;

		cm->nnodes = curNode;

		// Calc max tris per node.
		cm->maxTrisPerChunk = 0;
		for(int i = 0; i < cm->nnodes; ++i)
		{
			rcChunkyTriMeshNode& node = cm->nodes[i];
			const bool isLeaf = node.i >= 0;
			if(!isLeaf) continue;
			if(node.n > cm->maxTrisPerChunk)
				cm->maxTrisPerChunk = node.n;
		}

		return true;
	}

	inline bool checkOverlapRect(const vec2& amin, const vec2& amax, const vec2& bmin, const vec2& bmax)
	{
		bool overlap = true;
		overlap = (amin[0] > bmax[0] || amax[0] < bmin[0]) ? false : overlap;
		overlap = (amin[1] > bmax[1] || amax[1] < bmin[1]) ? false : overlap;
		return overlap;
	}

	int rcGetChunksOverlappingRect(const rcChunkyTriMesh* cm, const vec2& bmin, const vec2& bmax, int* ids, const int maxIds)
	{
		// Traverse tree
		int i = 0;
		int n = 0;
		while(i < cm->nnodes)
		{
			const rcChunkyTriMeshNode* node = &cm->nodes[i];
			const bool overlap = checkOverlapRect(bmin, bmax, node->bmin, node->bmax);
			const bool isLeafNode = node->i >= 0;

			if(isLeafNode && overlap)
			{
				if(n < maxIds)
				{
					ids[n] = i;
					n++;
				}
			}

			if(overlap || isLeafNode)
				i++;
			else
			{
				const int escapeIndex = -node->i;
				i += escapeIndex;
			}
		}

		return n;
	}

	int rcGetChunksOverlappingSegment(const rcChunkyTriMesh* cm, const vec2& p, const vec2& q, int* ids, const int maxIds)
	{
		// Traverse tree
		int i = 0;
		int n = 0;
		while(i < cm->nnodes)
		{
			const rcChunkyTriMeshNode* node = &cm->nodes[i];
			const bool overlap = segment_aabb_intersection_2d(p, q, node->bmin, node->bmax);
			const bool isLeafNode = node->i >= 0;

			if(isLeafNode && overlap)
			{
				if(n < maxIds)
				{
					ids[n] = i;
					n++;
				}
			}

			if(overlap || isLeafNode)
				i++;
			else
			{
				const int escapeIndex = -node->i;
				i += escapeIndex;
			}
		}

		return n;
	}
}
