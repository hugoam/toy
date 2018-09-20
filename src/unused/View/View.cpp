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
		: Array<Spatial>()
		, m_filter([](Spatial& spatial) { UNUSED(spatial); return true; })
	{
		// filter only non movables
		// m_filter = [](Spatial& spatial) { return !entity.is<Movable>(); };
	}

	void RecursiveStore::handle_add(Spatial& spatial)
	{
		if(spatial.m_hooked && m_filter(spatial))
			this->addRecursive(spatial);
	}

	void RecursiveStore::handle_remove(Spatial& spatial)
	{
		if(spatial.m_hooked && m_filter(spatial))
			this->removeRecursive(spatial);
	}

	void RecursiveStore::addRecursive(Spatial& spatial)
	{
		this->add(spatial);
		spatial.m_contents.observe(*this);
	}

	void RecursiveStore::removeRecursive(Spatial& spatial)
	{
		spatial.m_contents.unobserve(*this, true);
		this->remove(spatial);
	}

	View::View(Vision& vision, Type& type)
		: m_type(type)
		, m_vision(vision)
	{}

	View::~View()
	{}

	StoreView::StoreView(Vision& vision, const string& name, Store<Spatial>& store)
		: View(vision, type<StoreView>())
		, m_store(store)
	{
		UNUSED(name);
		vision.addView(*this);
	}

	ReceptorView::ReceptorView(Vision& vision, Medium& medium, Store<Spatial>& receptors)
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

	void ReceptorView::handle_add(Spatial& spatial)
	{
		if(!spatial.isa<Receptor>())
			return;

		ReceptorScope* scope = spatial.as<Receptor>().scope(m_medium);
		if(scope)
			scope->m_scope.observe(m_store);
			
	}

	void ReceptorView::handle_remove(Spatial& spatial)
	{
		if(!spatial.isa<Receptor>())
			return;

		ReceptorScope* scope = spatial.as<Receptor>().scope(m_medium);
		if(scope)
			scope->m_scope.unobserve(m_store);
	}
}
