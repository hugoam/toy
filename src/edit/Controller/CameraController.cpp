//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#ifdef TWO_MODULES
module toy.edit
#else
#include <stl/hash_base.hpp>
#include <core/Spatial/Spatial.h>
#include <core/Movable/Movable.h>
#include <edit/Controller/CameraController.h>
#endif

namespace toy
{
	CameraController::CameraController(Viewer& viewer, HCamera camera, HMovable movable)
		: m_viewer(viewer)
		, m_camera(camera)
		, m_movable(movable)
		, m_velocity(50.f)
		, m_angular_velocity(2.f)
	{
		default_velocities();

		m_movable->set_acceleration(vec3(0.f), vec3(0.f, 0.f, m_velocity));
	}

	void CameraController::default_velocities()
	{
		map<Key, vec3> velocities;

		velocities[Key::W] = velocities[Key::Up] = to_vec3(Side::Front) * m_velocity;
		velocities[Key::S] = velocities[Key::Down] = to_vec3(Side::Back) * m_velocity;
		velocities[Key::D] = velocities[Key::Right] = to_vec3(Side::Right) * m_velocity;
		velocities[Key::A] = velocities[Key::Left] = to_vec3(Side::Left) * m_velocity;
		velocities[Key::R] = to_vec3(Side::Up) * m_velocity;
		velocities[Key::F] = to_vec3(Side::Down) * m_velocity;

		set_velocities(velocities);
	}

	void CameraController::set_velocities(const map<Key, vec3>& velocities)
	{
		for(auto& key_velocity : velocities)
		{
			vec3 velocity = key_velocity.second;
			//m_key_down_handlers[key_velocity.first] = [this, velocity] { m_movable->modify_linear_velocity(velocity); };
			//m_key_up_handlers[key_velocity.first] = [this, velocity] { m_movable->modify_linear_velocity(-velocity); };
		}
	}

	void CameraController::stop()
	{
		m_movable->set_linear_velocity(vec3(0.f));
		m_movable->set_angular_velocity(vec3(0.f));
	}

	void CameraController::rotate_left()
	{
		m_movable->modify_angular_velocity(y3 * -m_angular_velocity);
	}

	void CameraController::rotate_right()
	{
		m_movable->modify_angular_velocity(y3 * m_angular_velocity);
	}

	void CameraController::stop_rotate_left()
	{
		m_movable->modify_angular_velocity(y3 * m_angular_velocity);
	}

	void CameraController::stop_rotate_right()
	{
		m_movable->modify_angular_velocity(y3 * -m_angular_velocity);

	}
	void CameraController::zoom_in()
	{
		m_camera->zoom(1.2f);//mCamera->zoom(3.f);
	}

	void CameraController::zoom_out()
	{
		m_camera->zoom(0.8f);//mCamera->zoom(-3.f);
	}

	void CameraController::pitch_lens_up()
	{
		m_camera->pitch_lens(c_pi / 12.f);
	}

	void CameraController::pitch_lens_down()
	{
		m_camera->pitch_lens(-c_pi / 12.f);
	}
}
