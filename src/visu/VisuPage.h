//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <visu/Forward.h>
#include <visu/VisuScene.h>

using namespace mud; namespace toy
{
	export_ TOY_VISU_EXPORT void build_geometry(Geometry& geometry, array<Item*> items);
	export_ TOY_VISU_EXPORT void build_world_page_geometry(WorldPage& page, array<Item*> items);
	export_ TOY_VISU_EXPORT void build_world_page_geometry(Scene& scene, WorldPage& page);

	export_ TOY_VISU_EXPORT void paint_world_page(Gnode& parent, WorldPage& page);
	export_ TOY_VISU_EXPORT void paint_navmesh(Gnode& parent, Navmesh& navmesh);
}
