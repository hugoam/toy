//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <core/Forward.h>
#include <pool/Pool.h>
#include <ecs/ECS.h>

#include <core/Spatial/Spatial.h>
#include <core/Movable/Movable.h>
#include <core/Camera/Camera.h>
#include <core/Physic/Scope.h>
#include <core/Script/Script.h>
#include <core/WorldPage/WorldPage.h>
#include <core/Navmesh/Navmesh.h>
#include <core/Path/DetourPath.h>

namespace mud
{
	export_ template struct refl_ nocopy_ TOY_CORE_EXPORT OwnedHandle<toy::Collider>;
	export_ template struct refl_ nocopy_ TOY_CORE_EXPORT OwnedHandle<toy::Solid>;
	export_ template struct refl_ TOY_CORE_EXPORT SparseHandle<toy::Collider>;
	export_ template struct refl_ TOY_CORE_EXPORT SparseHandle<toy::Solid>;

	export_ template struct refl_ TOY_CORE_EXPORT ComponentHandle<toy::Spatial>;
	export_ template struct refl_ TOY_CORE_EXPORT ComponentHandle<toy::Movable>;
	export_ template struct refl_ TOY_CORE_EXPORT ComponentHandle<toy::Camera>;
	export_ template struct refl_ TOY_CORE_EXPORT ComponentHandle<toy::Emitter>;
	export_ template struct refl_ TOY_CORE_EXPORT ComponentHandle<toy::Receptor>;
	export_ template struct refl_ TOY_CORE_EXPORT ComponentHandle<toy::EntityScript>;
	export_ template struct refl_ TOY_CORE_EXPORT ComponentHandle<toy::WorldPage>;
	export_ template struct refl_ TOY_CORE_EXPORT ComponentHandle<toy::Navblock>;
	//export_ template struct refl_ TOY_CORE_EXPORT ComponentHandle<toy::Collider>;
	//export_ template struct refl_ TOY_CORE_EXPORT ComponentHandle<toy::Solid>;

	export_ template struct refl_ TOY_CORE_EXPORT ComponentHandle<toy::Origin>;
	export_ template struct refl_ TOY_CORE_EXPORT ComponentHandle<toy::Waypoint>;
}
