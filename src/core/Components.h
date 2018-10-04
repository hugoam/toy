//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <core/Forward.h>
#include <pool/Pool.h>
#include <ecs/Registry.h>

namespace mud
{
	template <> struct TypedBuffer<toy::Spatial>		{ static size_t index() { return 0; } };
	template <> struct TypedBuffer<toy::Movable>		{ static size_t index() { return 1; } };
	template <> struct TypedBuffer<toy::Camera>			{ static size_t index() { return 2; } };
	template <> struct TypedBuffer<toy::Emitter>		{ static size_t index() { return 3; } };
	template <> struct TypedBuffer<toy::Receptor>		{ static size_t index() { return 4; } };
	template <> struct TypedBuffer<toy::EntityScript>	{ static size_t index() { return 5; } };
	template <> struct TypedBuffer<toy::WorldPage>		{ static size_t index() { return 6; } };
	template <> struct TypedBuffer<toy::Navblock>		{ static size_t index() { return 7; } };
	template <> struct TypedBuffer<toy::Collider>		{ static size_t index() { return 8; } };
	template <> struct TypedBuffer<toy::Solid>			{ static size_t index() { return 9; } };

	template <> struct TypedBuffer<toy::Origin>			{ static size_t index() { return 10; } };
	template <> struct TypedBuffer<toy::Waypoint>		{ static size_t index() { return 11; } };
}

using namespace mud; namespace toy
{
	using HCollider = SparseHandle<Collider>;
	using OCollider = OwnedHandle<Collider>;
	using HSolid = SparseHandle<Solid>;
	using OSolid = OwnedHandle<Solid>;

	using HSpatial = ComponentHandle<Spatial>;
	using HMovable = ComponentHandle<Movable>;
	using HCamera = ComponentHandle<Camera>;
	using HEmitter = ComponentHandle<Emitter>;
	using HReceptor = ComponentHandle<Receptor>;
	using HEntityScript = ComponentHandle<EntityScript>;
	using HWorldPage = ComponentHandle<WorldPage>;
	using HNavblock = ComponentHandle<Navblock>;

	using HOrigin = ComponentHandle<Origin>;
	using HWaypoint = ComponentHandle<Waypoint>;
}

#if 0
namespace mud
{
	export_ template <> TOY_CORE_EXPORT Type& type<toy::HSpatial>();
	export_ template <> TOY_CORE_EXPORT Type& type<toy::HMovable>();
	export_ template <> TOY_CORE_EXPORT Type& type<toy::HCamera>();
	export_ template <> TOY_CORE_EXPORT Type& type<toy::HEmitter>();
	export_ template <> TOY_CORE_EXPORT Type& type<toy::HReceptor>();
	export_ template <> TOY_CORE_EXPORT Type& type<toy::HEntityScript>();
	export_ template <> TOY_CORE_EXPORT Type& type<toy::HWorldPage>();
	export_ template <> TOY_CORE_EXPORT Type& type<toy::HNavblock>();

	template <> TOY_CORE_EXPORT Type& type<toy::HSpatial>() { static Type ty("HSpatial"); return ty; }
	template <> TOY_CORE_EXPORT Type& type<toy::HMovable>() { static Type ty("HMovable"); return ty; }
	template <> TOY_CORE_EXPORT Type& type<toy::HCamera>() { static Type ty("HCamera"); return ty; }
	template <> TOY_CORE_EXPORT Type& type<toy::HEmitter>() { static Type ty("HEmitter"); return ty; }
	template <> TOY_CORE_EXPORT Type& type<toy::HReceptor>() { static Type ty("HReceptor"); return ty; }
	template <> TOY_CORE_EXPORT Type& type<toy::HEntityScript>() { static Type ty("HEntityScript"); return ty; }
	template <> TOY_CORE_EXPORT Type& type<toy::HWorldPage>() { static Type ty("HWorldPage"); return ty; }
	template <> TOY_CORE_EXPORT Type& type<toy::HNavblock>() { static Type ty("HNavblock"); return ty; }
}
#endif
