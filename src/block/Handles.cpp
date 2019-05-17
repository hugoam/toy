//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <ecs/ECS.hpp>
#include <block/Forward.h>
#include <block/Block.h>
#include <block/Chunk.h>
#include <block/Sector.h>

namespace two
{
	template struct ComponentHandle<toy::Block>;
	template struct ComponentHandle<toy::Chunk>;
	template struct ComponentHandle<toy::Heap>;
	template struct ComponentHandle<toy::Sector>;
	template struct ComponentHandle<toy::Tileblock>;
}
