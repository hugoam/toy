//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/Forward.h>
#include <pool/SparsePool.hpp>
#include <ecs/ECS.hpp>

#include <core/Types.h>
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
	template struct TOY_CORE_EXPORT OwnedHandle<toy::Collider>;
	template struct TOY_CORE_EXPORT OwnedHandle<toy::Solid>;
	template struct TOY_CORE_EXPORT SparseHandle<toy::Collider>;
	template struct TOY_CORE_EXPORT SparseHandle<toy::Solid>;

	template struct TOY_CORE_EXPORT ComponentHandle<toy::Spatial>;
	template struct TOY_CORE_EXPORT ComponentHandle<toy::Movable>;
	template struct TOY_CORE_EXPORT ComponentHandle<toy::Camera>;
	template struct TOY_CORE_EXPORT ComponentHandle<toy::Emitter>;
	template struct TOY_CORE_EXPORT ComponentHandle<toy::Receptor>;
	template struct TOY_CORE_EXPORT ComponentHandle<toy::EntityScript>;
	template struct TOY_CORE_EXPORT ComponentHandle<toy::WorldPage>;
	template struct TOY_CORE_EXPORT ComponentHandle<toy::Navblock>;
	//emplate struct TOY_CORE_EXPORT ComponentHandle<toy::Collider>;
	//emplate struct TOY_CORE_EXPORT ComponentHandle<toy::Solid>;

	template struct TOY_CORE_EXPORT ComponentHandle<toy::Origin>;
	template struct TOY_CORE_EXPORT ComponentHandle<toy::Waypoint>;
}
