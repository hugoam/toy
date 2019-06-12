//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.


#include <core/View/Vision.h>

#include <core/Entity/Entity.h>
#include <core/Camera/Camera.h>

#include <core/View/View.h>

#include <core/Medium/VisualMedium.h>
#include <core/Medium/SoundMedium.h>
#include <core/WorldPage/WorldPage.h>

#include <core/World/World.h>

#include <core/Core.h>

using namespace two; namespace toy
{
	Vision::Vision(World& world)
		: m_world(world)
	{
		m_entities.observe(*this);
	}

	Vision::~Vision()
	{
		m_entities.unobserve(*this);
	}

	void Vision::addView(View& view)
	{
		m_views.add(view);
		view.store().observe(m_entities);
	}

	void Vision::handle_add(Spatial& owned)
	{
		if(owned.isa<Camera>())
			m_cameras.add(owned.as<Camera>());
	}

	void Vision::handle_remove(Spatial& owned)
	{
		if(owned.isa<Camera>())
			m_cameras.remove(owned.as<Camera>());
	}

	Camera& Vision::addCamera(const vec3& position, float lensDistance, bool planar)
	{
		UNUSED(planar);
		Camera& camera = m_world.origin()->construct<OCamera>(m_world.origin(), position, lensDistance, 0.1f, 300.f).m_camera;
		//m_owneds.add(camera.m_spatial);
		//m_cameras.add(camera);
		return camera;
	}

#if 0
	PlayerVision::PlayerVision(Player& player, World& world)
		: Vision(world)
		//, m_ownedView(*this, "owned", player.m_owneds)
		//, m_visualView(*this, VisualMedium::me, player.m_owneds)
		//, m_soundView(*this, SoundMedium::me, player.m_owneds)
		//, m_worldView(*this, WorldMedium::me, player.m_owneds)
		//, m_bufferView(*this, WorldMedium::me, player.m_owneds)
	{
		UNUSED(player);
	}
#endif

	OmniVision::OmniVision(World& world)
		: Vision(world)
		, m_store()
		, m_view(*this, "omni", m_store)
	{
		m_origin.observe(m_store);
		m_origin.add(world.origin());
	}

	OmniVision::~OmniVision()
	{
		m_origin.remove(m_world.origin());
		m_origin.unobserve(m_store);
	}
}
