//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <edit/Types.h>
#include <edit/Edit/Viewport.h>

#include <gfx-ui/Viewport.h>
#include <gfx-ui/Viewer.h>
#include <gfx/Item.h>

#include <core/Camera/Camera.h>
#include <core/Selector/Selection.h>
#include <core/World/World.h>
#include <core/Physic/PhysicWorld.h>

#include <uio/Edit/Section.h>
#include <visu/VisuScene.h>

#include <edit/Controller/RTSCameraController.h>

using namespace mud; namespace toy
{
	vec3 pick_terrain(Viewer& viewer, World& world, vec2 position)
	{
		Ray ray = viewer.m_camera.ray(position);
		return as<PhysicWorld>(world.m_complex).ground_point(ray);
	}

	Viewer& scene_viewport(Widget& parent, VisuScene& scene, HCamera camera, HMovable movable, Selection& selection)
	{
		Widget& board = ui::widget(parent, styles().sheet, &scene);
		Viewer& viewer = board.suba<Viewer, Scene&>(scene.m_scene);
		if(viewer.once())
		{
			viewer.m_controller = make_unique<RTSCameraController>(viewer, camera, movable);
		}

		update_camera(camera, viewer.m_camera);

		viewer.m_controller->process(viewer);
		viewport_picker(viewer, viewer, selection);
		return viewer;
	}
}
