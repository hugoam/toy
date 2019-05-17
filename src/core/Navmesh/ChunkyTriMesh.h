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

#ifndef CHUNKYTRIMESH_H
#define CHUNKYTRIMESH_H

#include <core/Forward.h>
#include <math/Vec.h>

#include <stdint.h>

namespace toy
{
	struct rcChunkyTriMeshNode
	{
		vec2 bmin, bmax;
		int i, n;
	};

	struct rcChunkyTriMesh
	{
		inline rcChunkyTriMesh() : nodes(0), tris(0) {};
		inline ~rcChunkyTriMesh() { delete[] nodes; delete[] tris; }

		rcChunkyTriMeshNode* nodes;
		int nnodes;
		int* tris;
		int ntris;
		int maxTrisPerChunk;
	};

	// Creates partitioned triangle mesh (AABB tree),
	// where each node contains at max trisPerChunk triangles.
	bool rcCreateChunkyTriMesh(const float* verts, const uint32_t* tris, int ntris, int trisPerChunk, rcChunkyTriMesh* cm);

	// Returns the chunk indices which overlap the input rectable.
	int rcGetChunksOverlappingRect(const rcChunkyTriMesh* cm, const vec2& bmin, const vec2& bmax, int* ids, const int maxIds);

	// Returns the chunk indices which overlap the input segment.
	int rcGetChunksOverlappingSegment(const rcChunkyTriMesh* cm, const vec2& p, const vec2& q, int* ids, const int maxIds);
}


#endif // CHUNKYTRIMESH_H
