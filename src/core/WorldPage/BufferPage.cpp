//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/WorldPage/BufferPage.h>

#include <refl/Meta.h>
#include <util/Loader/Loader.h>

#include <core/Entity/Entity.h>
#include <core/Physic/Scope.h>

#include <core/World/World.h>
#include <core/Physic/PhysicWorld.h>

#include <core/Physic/Collider.h>
#include <core/Physic/CollisionShape.h>
#include <core/Physic/Solid.h>

#include <core/WorldPage/WorldPage.h>

using namespace mud; namespace toy
{
	BufferPage::BufferPage(Entity& entity, WorldPage& world_page, bool loaded)
        : m_entity(entity)
		, m_world_page(world_page)
		, m_loaded(loaded)
		, m_receptors(0)
    {
		//printf("Creating BufferPage %u at %f, %f, %f\n", m_entity.m_id, m_entity.m_position.x(), m_entity.m_position.y(), m_entity.m_position.z());
		m_world_page.m_scope.m_scope.observe(*this);
	}

    BufferPage::~BufferPage()
    {
		m_world_page.m_scope.m_scope.unobserve(*this);
	}

	void BufferPage::handle_add(Entity& entity)
	{
		this->add(entity);
	}

	void BufferPage::handle_remove(Entity& entity)
	{
		this->remove(entity);
	}

	void BufferPage::add(Entity& entity)
	{
		UNUSED(entity);

		//for(WorldPage* page : m_world_page.adjacentPages().store())
		//	page->m_buffer_page->increment();

		this->increment();
	}

	void BufferPage::increment()
	{
		//if(++m_receptors && !m_loaded)
		//	this->load();
	}

	void BufferPage::remove(Entity& entity)
	{
		UNUSED(entity);

		//for(WorldPage* page : m_world_page.adjacentPages().store())
		//	page->m_buffer_page->decrement();

		this->decrement();
	}

	void BufferPage::decrement()
	{
		//if(!--m_receptors && m_loaded)
		//	this->unload();
	}

	void BufferPage::load()
	{
		printf("BufferPage %u loaded\n", m_entity.m_id);
		m_loaded = true;
		ObjectLoader& loader = GlobalLoader::me.getLoader(type<Entity>());
		loader.fill(Ref(&m_world_page.m_entity), m_world_page.m_entity.m_id);
	}

	void BufferPage::unload()
	{
		printf("BufferPage %u unloaded\n", m_entity.m_id);
		m_loaded = false;
		ObjectLoader& loader = GlobalLoader::me.getLoader(type<Entity>());
		loader.save(Ref(&m_world_page.m_entity), m_world_page.m_entity.m_id);
		this->clear();
	}

	void BufferPage::clear()
	{
		//m_world_page.m_entity.as<EntityPool>().clear();
	}

	void BufferPage::fill()
	{
		ObjectLoader& loader = GlobalLoader::me.getLoader(type<Entity>());
		loader.fill(Ref(&m_world_page.m_entity), m_world_page.m_entity.m_id);
	}
}
