//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <core/Forward.h>
#include <ecs/ECS.h>

namespace two
{
	template <> struct TypedBuffer<toy::Spatial>		{ static uint32_t index() { return 0; } };
	template <> struct TypedBuffer<toy::Movable>		{ static uint32_t index() { return 1; } };
	template <> struct TypedBuffer<toy::Camera>			{ static uint32_t index() { return 2; } };
	template <> struct TypedBuffer<toy::Emitter>		{ static uint32_t index() { return 3; } };
	template <> struct TypedBuffer<toy::Receptor>		{ static uint32_t index() { return 4; } };
	template <> struct TypedBuffer<toy::EntityScript>	{ static uint32_t index() { return 5; } };
	template <> struct TypedBuffer<toy::WorldPage>		{ static uint32_t index() { return 6; } };
	template <> struct TypedBuffer<toy::Navblock>		{ static uint32_t index() { return 7; } };
	//template <> struct TypedBuffer<toy::Collider>		{ static uint32_t index() { return 8; } };
	//template <> struct TypedBuffer<toy::Solid>			{ static uint32_t index() { return 9; } };

	template <> struct TypedBuffer<toy::Origin>			{ static uint32_t index() { return 10; } };
	template <> struct TypedBuffer<toy::Waypoint>		{ static uint32_t index() { return 11; } };
}
