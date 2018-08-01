//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/View/View.h>

#include <core/Store/Array.h>
#include <core/Entity/Entity.h>
#include <core/Entity/Entity.h>
#include <core/Physic/Scope.h>

#include <core/Camera/Camera.h>
#include <core/View/Vision.h>

using namespace mud; namespace toy
{
	RecursiveStore::RecursiveStore()
		: Array<Entity>()
		, m_filter([](Entity& entity) { UNUSED(entity); return true; })
	{
		// filter only non movables
		// m_filter = [](Entity& entity) { return !entity.is<Movable>(); };
	}

	void RecursiveStore::handle_add(Entity& entity)
	{
		if(entity.m_hooked && m_filter(entity))
			this->addRecursive(entity);
	}

	void RecursiveStore::handle_remove(Entity& entity)
	{
		if(entity.m_hooked && m_filter(entity))
			this->removeRecursive(entity);
	}

	void RecursiveStore::addRecursive(Entity& entity)
	{
		this->add(entity);
		entity.m_contents.observe(*this);
	}

	void RecursiveStore::removeRecursive(Entity& entity)
{
		entity.m_contents.unobserve(*this, true);
		this->remove(entity);
	}

	View::View(Vision& vision, Type& type)
		: m_type(type)
		, m_vision(vision)
	{}

	View::~View()
	{}

	StoreView::StoreView(Vision& vision, const string& name, Store<Entity>& store)
		: View(vision, type<StoreView>())
		, m_store(store)
	{
		UNUSED(name);
		vision.addView(*this);
	}

	ReceptorView::ReceptorView(Vision& vision, Medium& medium, Store<Entity>& receptors)
		: View(vision, type<ReceptorView>())
		, m_medium(medium)
		, m_receptors(receptors)
		, m_store()
	{
		vision.addView(*this);

		m_receptors.observe(*this);
	}

	ReceptorView::~ReceptorView()
	{
		m_receptors.unobserve(*this);
	}

	void ReceptorView::handle_add(Entity& entity)
	{
		if(!entity.isa<Receptor>())
			return;

		ReceptorScope* scope = entity.as<Receptor>().scope(m_medium);
		if(scope)
			scope->m_scope.observe(m_store);
			
	}

	void ReceptorView::handle_remove(Entity& entity)
	{
		if(!entity.isa<Receptor>())
			return;

		ReceptorScope* scope = entity.as<Receptor>().scope(m_medium);
		if(scope)
			scope->m_scope.unobserve(m_store);
	}
}
