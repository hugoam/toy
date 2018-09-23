//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <core/Forward.h>
#include <pool/Pool.h>
#include <proto/ECS/Registry.h>

#ifdef TOY_ECS
namespace mud
{
	template <> struct TypedBuffer<toy::Spatial> { using type = ComponentBuffer<toy::Spatial>; static size_t index() { return 0; } };
	template <> struct TypedBuffer<toy::Movable> { using type = ComponentBuffer<toy::Movable>; static size_t index() { return 1; } };
	template <> struct TypedBuffer<toy::Camera> { using type = ComponentBuffer<toy::Camera>; static size_t index() { return 2; } };
	template <> struct TypedBuffer<toy::Emitter> { using type = ComponentBuffer<toy::Emitter>; static size_t index() { return 3; } };
	template <> struct TypedBuffer<toy::Receptor> { using type = ComponentBuffer<toy::Receptor>; static size_t index() { return 4; } };
	template <> struct TypedBuffer<toy::EntityScript> { using type = ComponentBuffer<toy::EntityScript>; static size_t index() { return 5; } };
	template <> struct TypedBuffer<toy::WorldPage> { using type = ComponentBuffer<toy::WorldPage>; static size_t index() { return 6; } };
	template <> struct TypedBuffer<toy::Navblock> { using type = ComponentBuffer<toy::Navblock>; static size_t index() { return 7; } };
	template <> struct TypedBuffer<toy::Collider> { using type = ComponentBuffer<toy::Collider>; static size_t index() { return 8; } };
	template <> struct TypedBuffer<toy::Solid> { using type = ComponentBuffer<toy::Solid>; static size_t index() { return 9; } };
}
#endif

using namespace mud; namespace toy
{
#ifdef TOY_ECS
	using HSpatial = ComponentHandle<Spatial>;
	using CSpatial = Component<Spatial>;

	using HMovable = ComponentHandle<Movable>;
	using CMovable = Component<Movable>;

	using HCamera = ComponentHandle<Camera>;
	using CCamera = Component<Camera>;

	using HCollider = SparseHandle<Collider>;
	using OCollider = OwnedHandle<Collider>;
	//using HCollider = ComponentHandle<Collider>;
	using CCollider = Component<Collider>;

	using HSolid = SparseHandle<Solid>;
	using OSolid = OwnedHandle<Solid>;
	//using HSolid = ComponentHandle<Solid>;
	using CSolid = Component<Solid>;

	using HEmitter = ComponentHandle<Emitter>;
	using CEmitter = Component<Emitter>;

	using HReceptor = ComponentHandle<Receptor>;
	using CReceptor = Component<Receptor>;

	using HEntityScript = ComponentHandle<EntityScript>;
	using CEntityScript = Component<EntityScript>;

	using HWorldPage = ComponentHandle<WorldPage>;
	using CWorldPage = Component<WorldPage>;

	using HNavblock = ComponentHandle<Navblock>;
	using CNavblock = Component<Navblock>;
#else
	using HSpatial = Spatial&;
	using CSpatial = Spatial;

	using HMovable = Movable&;
	using CMovable = Movable;

	using HCamera = Camera&;
	using CCamera = Camera;

	using HEmitter = Emitter&;
	using CEmitter = Emitter;

	using HReceptor = Receptor&;
	using CReceptor = Receptor;

	using HEntityScript = EntityScript&;
	using CEntityScript = EntityScript;

	using HWorldPage = WorldPage&;
	using CWorldPage = WorldPage;

	using HNavblock = Navblock&;
	using CNavblock = Navblock;
#endif
}

#if 0
#ifdef TOY_ECS
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
#endif
