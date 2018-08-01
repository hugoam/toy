//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.


#include <edit/Controller/RTSCameraController.h>

#include <core/Entity/Entity.h>

#include <ui/Frame/Frame.h>
#include <ui/Widget.h>
#include <ui/Structs/RootSheet.h>
#include <ctx/InputDevice.h>

#include <gfx-ui/Viewer.h>

#define DRAG_BY_GRAB 1

using namespace mud; namespace toy
{
	RTSCameraController::RTSCameraController(Viewer& viewer, Camera& camera)
		: CameraController(viewer, camera)
	{
		m_key_down_handlers[KC_Q] = [this] { this->rotate_left(); };
		m_key_down_handlers[KC_E] = [this] { this->rotate_right(); };
		m_key_down_handlers[KC_O] = [this] { this->zoom_in(); };
		m_key_down_handlers[KC_L] = [this] { this->zoom_out(); };
		m_key_down_handlers[KC_I] = [this] { this->pitch_lens_up(); };
		m_key_down_handlers[KC_K] = [this] { this->pitch_lens_down(); };

		m_key_up_handlers[KC_Q] = [this] { this->stop_rotate_left(); };
		m_key_up_handlers[KC_E] = [this] { this->stop_rotate_right(); };
	}

	void RTSCameraController::process(Viewer& viewer)
	{
		EventDispatch::process(viewer);

		// activate
		//mWidget->root_sheet().cursor()->bind(m_widget);
		// deactivate
		//mWidget->root_sheet().cursor()->free();

		if(MouseEvent mouse_event = viewer.mouse_event(DeviceType::MouseMiddle, EventType::Moved))
		{
			if(mouse_event.m_deltaZ > 0)
				m_camera.zoom(1.3f);
			else
				m_camera.zoom(0.75f);
		}

		if(MouseEvent mouse_event = viewer.mouse_event(DeviceType::MouseLeft, EventType::Stroked, InputModifier::None, false))
		{
			viewer.take_focus();
		}

		if(MouseEvent mouse_event = viewer.mouse_event(DeviceType::MouseMiddle, EventType::Dragged, InputModifier::Ctrl))
		{
#if DRAG_BY_GRAB
			Plane horizontal_plane = { Y3, m_camera.m_entity.m_position.y };
			vec3 from = m_viewer.m_viewport.raycast(horizontal_plane, mouse_event.m_relative);
			vec3 to = m_viewer.m_viewport.raycast(horizontal_plane, mouse_event.m_relative - mouse_event.m_delta);

			//m_camera.m_entity.translate(to - from);
			m_camera.m_entity.set_position(m_camera.m_entity.m_position + (to - from));
#else
			m_camera.m_entity.translate(to_vec3(Side::Right) * 0.02f * m_camera.m_lensDistance * -mouse_event.m_delta.x);
			m_camera.m_entity.translate(to_vec3(Side::Front) * 0.02f * m_camera.m_lensDistance * mouse_event.m_delta.y);
#endif
		}

		if(MouseEvent mouse_event = viewer.mouse_event(DeviceType::MouseMiddle, EventType::Dragged))
		{
			m_camera.m_entity.rotate(to_vec3(Side::Down), 0.02f * mouse_event.m_delta.x);
			//m_camera.m_entity.rotateRelative(to_vec3(Side::Left), 0.02f * mouse_event.m_delta.y);
			m_camera.set_lens_angle(m_camera.m_lens_angle + 0.02f * mouse_event.m_delta.y);
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
