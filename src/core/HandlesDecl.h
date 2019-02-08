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
	export_ extern template struct refl_ nocopy_ OwnedHandle<toy::Collider>;
	export_ extern template struct refl_ nocopy_ OwnedHandle<toy::Solid>;
	export_ extern template struct refl_ SparseHandle<toy::Collider>;
	export_ extern template struct refl_ SparseHandle<toy::Solid>;

	export_ extern template struct refl_ ComponentHandle<toy::Spatial>;
	export_ extern template struct refl_ ComponentHandle<toy::Movable>;
	export_ extern template struct refl_ ComponentHandle<toy::Camera>;
	export_ extern template struct refl_ ComponentHandle<toy::Emitter>;
	export_ extern template struct refl_ ComponentHandle<toy::Receptor>;
	export_ extern template struct refl_ ComponentHandle<toy::EntityScript>;
	export_ extern template struct refl_ ComponentHandle<toy::WorldPage>;
	export_ extern template struct refl_ ComponentHandle<toy::Navblock>;
	//export_ extern template struct refl_ ComponentHandle<toy::Collider>;
	//export_ extern template struct refl_ ComponentHandle<toy::Solid>;

	export_ extern template struct refl_ ComponentHandle<toy::Origin>;
	export_ extern template struct refl_ ComponentHandle<toy::Waypoint>;
}
