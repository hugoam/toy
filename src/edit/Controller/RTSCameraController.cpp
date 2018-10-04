//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.


#include <edit/Controller/RTSCameraController.h>

#include <core/Spatial/Spatial.h>

#include <ui/Frame/Frame.h>
#include <ui/Widget.h>
#include <ui/Structs/RootSheet.h>
#include <ctx/InputDevice.h>

#include <gfx-ui/Viewer.h>

#define DRAG_BY_GRAB 1

using namespace mud; namespace toy
{
	RTSCameraController::RTSCameraController(Viewer& viewer, HCamera camera, HMovable movable)
		: CameraController(viewer, camera, movable)
	{
		m_key_down_handlers[Key::Q] = [this] { this->rotate_left(); };
		m_key_down_handlers[Key::E] = [this] { this->rotate_right(); };
		m_key_down_handlers[Key::O] = [this] { this->zoom_in(); };
		m_key_down_handlers[Key::L] = [this] { this->zoom_out(); };
		m_key_down_handlers[Key::I] = [this] { this->pitch_lens_up(); };
		m_key_down_handlers[Key::K] = [this] { this->pitch_lens_down(); };

		m_key_up_handlers[Key::Q] = [this] { this->stop_rotate_left(); };
		m_key_up_handlers[Key::E] = [this] { this->stop_rotate_right(); };
	}

	void RTSCameraController::process(Viewer& viewer)
	{
		EventDispatch::process(viewer);
		this->process(viewer, m_camera->m_spatial, m_camera);
	}

	void RTSCameraController::process(Viewer& viewer, Spatial& spatial, Camera& camera)
	{
		// activate
		//mWidget->ui().cursor()->bind(m_widget);
		// deactivate
		//mWidget->ui().cursor()->free();

		if(MouseEvent mouse_event = viewer.mouse_event(DeviceType::MouseMiddle, EventType::Moved))
		{
			if(mouse_event.m_deltaZ > 0)
				camera.zoom(1.3f);
			else
				camera.zoom(0.75f);
		}

		if(MouseEvent mouse_event = viewer.mouse_event(DeviceType::MouseLeft, EventType::Stroked, InputMod::None, false))
		{
			viewer.take_focus();
		}

		if(MouseEvent mouse_event = viewer.mouse_event(DeviceType::MouseMiddle, EventType::Dragged, InputMod::Ctrl))
		{
#if DRAG_BY_GRAB
			Plane horizontal_plane = { Y3, spatial.m_position.y };
			vec3 from = m_viewer.m_viewport.raycast(horizontal_plane, mouse_event.m_relative);
			vec3 to = m_viewer.m_viewport.raycast(horizontal_plane, mouse_event.m_relative - mouse_event.m_delta);

			//spatial.translate(to - from);
			spatial.set_position(spatial.m_position + (to - from));
#else
			spatial.translate(to_vec3(Side::Right) * 0.02f * m_camera.m_lensDistance * -mouse_event.m_delta.x);
			spatial.translate(to_vec3(Side::Front) * 0.02f * m_camera.m_lensDistance * mouse_event.m_delta.y);
#endif
		}

		if(MouseEvent mouse_event = viewer.mouse_event(DeviceType::MouseMiddle, EventType::Dragged))
		{
			spatial.rotate(to_vec3(Side::Down), 0.02f * mouse_event.m_delta.x);
			//spatial.rotateRelative(to_vec3(Side::Left), 0.02f * mouse_event.m_delta.y);
			camera.set_lens_angle(m_camera->m_lens_angle + 0.02f * mouse_event.m_delta.y);
		}

		if(MouseEvent mouse_event = viewer.mouse_event(DeviceType::Mouse, EventType::Heartbeat))
		{
#if 0
			static const float threshold = 4.f;

			if(std::abs(mouse_event.posX - m_inputWidget->frame().left()) < threshold)
				this->moveLeft();
			else if(std::abs(mouse_event.posX - m_inputWidget->frame().right()) < threshold)
				this->moveRight();
			else if(std::abs(mouse_event.posY - m_inputWidget->frame().top()) < threshold)
				this->moveForward();
			else if(std::abs(mouse_event.posY - m_inputWidget->frame().bottom()) < threshold)
				this->moveBackward();
#endif
		}

	}
}
