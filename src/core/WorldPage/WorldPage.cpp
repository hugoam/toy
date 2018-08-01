//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.


#include <core/WorldPage/WorldPage.h>

#include <geom/Shapes.h>
#include <geom/Mesh.h>
#include <geom/Geom.h>

#include <core/Entity/Entity.h>
#include <core/Movable/Movable.h>
#include <core/Physic/Scope.h>

#include <core/World/World.h>
#include <core/World/Section.h>
#include <core/Physic/PhysicWorld.h>

#include <core/Physic/Collider.h>
#include <core/Physic/Solid.h>

using namespace mud; namespace toy
{
	WorldMedium WorldMedium::me;

	WorldMedium::WorldMedium()
		: Medium("World", false)
	{}

	WorldPage::WorldPage(Entity& entity, Emitter& emitter, bool open, const vec3& extents)
        : m_entity(entity)
		, m_emitter(emitter)
		, m_open(open)
		, m_extents(extents)
		, m_world(entity.m_world)
		, m_scope(emitter.add_scope(WorldMedium::me, Cube(m_extents / 2.f), CM_SOURCE))
    {
		entity.m_world.add_task(this, short(Task::World)); // @todo in the long term this should be moved out of the entity's responsibility
		m_entity.m_contents.observe(*this);
	}

    WorldPage::~WorldPage()
    {
		m_entity.m_world.remove_task(this, short(Task::World)); // @todo in the long term this should be moved out of the entity's responsibility
		m_entity.m_contents.unobserve(*this);
	}

	void WorldPage::next_frame(size_t tick, size_t delta)
	{
		UNUSED(tick); UNUSED(delta);
		if(m_updated > m_last_rebuilt)
			this->build_geometry();
	}

	void WorldPage::build_geometry()
	{
		if(m_build_geometry)
		{
			printf("INFO: Rebuilding WorldPage geometry\n");

			m_build_geometry(*this);
			this->update_geometry();
			m_last_rebuilt = m_entity.m_last_tick;

			//printf("INFO: Rebuilt WorldPage geometry, %zu vertices\n", m_geom->m_vertices.size());
		}
	}

	void WorldPage::update_geometry()
	{
		for(Geometry& geom : m_chunks)
			m_solids.push_back(make_object<Solid>(m_entity, *this, geom, SolidMedium::me, CM_GROUND, true));
	}

	void WorldPage::add_contact(Collider& object)
	{
		UNUSED(object);
		// these are contacts from the world geometry, so that's not the right place to switch worldpage of an entity
		//object.m_entity.set_parent(m_entity);
	}

	void WorldPage::remove_contact(Collider& object)
	{
		UNUSED(object);
		//object.m_entity.set_parent(*m_entity.m_parent);
	}

	void WorldPage::handle_add(Entity& entity)
	{
		UNUSED(entity);
		//if(!entity.isa<Movable>())
		//	m_updated = m_entity.m_last_tick;
	}

	void WorldPage::handle_remove(Entity& entity)
	{
		UNUSED(entity);
		//if(!entity.isa<Movable>())
		//	m_updated = m_entity.m_last_tick;
	}

	void WorldPage::ground_point(const vec3& position, bool relative, vec3& ground_point)
	{
		// to absolute
		vec3 start(position.x, -m_extents.y / 2, position.z);
		vec3 end(position.x, +m_extents.y / 2, position.z);

		if(relative)
		{
			start += m_entity.m_position;
			end += m_entity.m_position;
		}

		Ray ray = { start, end, normalize(end - start), normalize(start - end) };
		ground_point = m_world.as<PhysicWorld>().ground_point(ray) - m_entity.m_position;

		if(any(isnan(ground_point)) || any(isinf(ground_point)))
			printf("ERROR: raycast ground point failed, position result invalid\n");
	}

	void WorldPage::raycast_ground(const vec3& start, const vec3& end, vec3& ground_point)
	{
		Ray ray = { start, end, normalize(end - start), normalize(start - end) };
		ground_point = m_world.as<PhysicWorld>().ground_point(ray);
	}
}
