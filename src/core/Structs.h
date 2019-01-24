//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <math/Forward.h>
#include <util/Forward.h>

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

class btCollisionWorld;
class btDynamicsWorld;
class btDiscreteDynamicsWorld;
class btBroadphaseInterface;
class btConstraintSolver;

class btCollisionShape;
class btStridingMeshInterface;
class btCollisionObject;
class btRigidBody;
class btPersistentManifold;

class btCollisionConfiguration;
class btCollisionDispatcher;

#include <core/Handles.h>
