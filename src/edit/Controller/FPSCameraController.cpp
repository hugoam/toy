//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.


#include <edit/Controller/FPSCameraController.h>

#include <core/Spatial/Spatial.h>

#include <ui/Frame/Frame.h>
#include <ui/Widget.h>
#include <ui/Cursor.h>
#include <ui/UiRoot.h>
#include <ctx/InputDevice.h>

#include <gfx-ui/Viewer.h>

namespace toy
{
	FPSCameraController::FPSCameraController(Viewer& viewer, HCamera camera, HMovable movable)
		: CameraController(viewer, camera, movable)
	{
		//m_key_down_handlers[Key::Q] = [this] { this->rotate_left(); };
		//m_key_down_handlers[Key::E] = [this] { this->rotate_right(); }; 
	}

	void FPSCameraController::process(Viewer& viewer)
	{
		EventDispatch::process(viewer);
		//this->process(viewer, m_camera->m_spatial, m_camera);
	}

	void FPSCameraController::process(Viewer& viewer, Spatial& spatial, Camera& camera)
	{
		UNUSED(camera);
		//if(active)
		//m_inputWidget->ui().m_cursor.hide();
		//else
		//m_inputWidget->ui().m_cursor.show();

		if(MouseEvent event = viewer.mouse_event(DeviceType::Mouse, EventType::Moved))
		{
			vec2 angle = event.m_delta / viewer.m_frame.m_size;
			spatial.pitch(-angle.x * 4);
			spatial.yaw_fixed(-angle.y * 4);
		}
	}
}
