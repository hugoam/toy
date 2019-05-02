//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <ecs/ECS.h>
#include <block/Forward.h>

namespace two
{
	template <> struct TypedBuffer<toy::Sector>		{ static uint32_t index() { return 12; } };
	template <> struct TypedBuffer<toy::Tileblock>	{ static uint32_t index() { return 13; } };
	template <> struct TypedBuffer<toy::Block>		{ static uint32_t index() { return 14; } };
	template <> struct TypedBuffer<toy::Chunk>		{ static uint32_t index() { return 15; } };
	template <> struct TypedBuffer<toy::Heap>		{ static uint32_t index() { return 16; } };
}
