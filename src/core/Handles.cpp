//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/Forward.h>
#include <pool/SparsePool.hpp>
#include <ecs/ECS.hpp>

#include <core/Spatial/Spatial.h>
#include <core/Movable/Movable.h>
#include <core/Camera/Camera.h>
#include <core/Physic/Scope.h>
#include <core/Script/Script.h>
#include <core/WorldPage/WorldPage.h>
#include <core/Navmesh/Navmesh.h>
#include <core/Path/DetourPath.h>
#include <core/World/Origin.h>

namespace two
{
	template struct OwnedHandle<toy::Collider>;
	template struct OwnedHandle<toy::Solid>;
	template struct SparseHandle<toy::Collider>;
	template struct SparseHandle<toy::Solid>;

	template struct ComponentHandle<toy::Spatial>;
	template struct ComponentHandle<toy::Movable>;
	template struct ComponentHandle<toy::Camera>;
	template struct ComponentHandle<toy::Emitter>;
	template struct ComponentHandle<toy::Receptor>;
	template struct ComponentHandle<toy::EntityScript>;
	template struct ComponentHandle<toy::WorldPage>;
	template struct ComponentHandle<toy::Navblock>;
	//emplate struct ComponentHandle<toy::Collider>;
	//emplate struct ComponentHandle<toy::Solid>;

	template struct ComponentHandle<toy::Origin>;
	template struct ComponentHandle<toy::Waypoint>;
}
