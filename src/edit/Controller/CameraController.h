//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <core/Camera/Camera.h>
#include <ui/Controller/Controller.h>
#include <gfx-ui/Viewer.h>
#include <edit/Forward.h>

namespace toy
{
	class TOY_EDIT_EXPORT CameraController : public ViewerController, public EventDispatch
	{
	public:
		CameraController(Viewer& viewer, HCamera camera, HMovable movable);

		void default_velocities();
		void set_velocities(const map<Key, vec3>& velocities);

		void rotate_left();
		void rotate_right();

		void stop_rotate_left();
		void stop_rotate_right();

		void stop();

		void zoom_in();
		void zoom_out();

		void pitch_lens_up();
		void pitch_lens_down();

	protected:
		Viewer& m_viewer;
		HCamera m_camera;
		HMovable m_movable;
		float m_velocity;
		float m_angular_velocity;
	};
}
