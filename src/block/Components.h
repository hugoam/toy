//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <block/Forward.h>
#include <ecs/Registry.h>

namespace mud
{
	template <> struct TypedBuffer<toy::Sector>		{ static size_t index() { return 12; } };
	template <> struct TypedBuffer<toy::Tileblock>	{ static size_t index() { return 13; } };
	template <> struct TypedBuffer<toy::Block>		{ static size_t index() { return 14; } };
	template <> struct TypedBuffer<toy::Chunk>		{ static size_t index() { return 15; } };
	template <> struct TypedBuffer<toy::Heap>		{ static size_t index() { return 16; } };
}

using namespace mud; namespace toy
{
	using HBlock = ComponentHandle<Block>;
	using HChunk = ComponentHandle<Chunk>;
	using HHeap = ComponentHandle<Heap>;
	using HSector = ComponentHandle<Sector>;
	using HTileblock = ComponentHandle<Tileblock>;
}
