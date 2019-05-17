//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/Types.h>
#include <core/Script/Script.h>

#include <type/Indexer.h>
#include <refl/Class.h>
#include <lang/Script.h>

#include <core/Spatial/Spatial.h>

#include <stl/vector.h>
#include <sstream>

namespace toy
{
	EntityScript::EntityScript(HSpatial spatial)
		: m_spatial(spatial)
	{}

	void EntityScript::next_frame(size_t tick, size_t delta)
	{
		UNUSED(tick); UNUSED(delta);
		this->run_logic();
	}

	void EntityScript::run_logic()
	{
		if(m_logic_script)
		{
			//Spatial& spatial = m_spatial;
			// @hack @kludge add proper way to define a script signature
			if(m_logic_script->m_signature.m_params.empty())
			{
				//m_logic_script->m_signature.m_params.push_back({ "self", Ref(spatial.m_entity->m_type) });
				//m_logic_script->m_signature.m_params.push_back({ "self", Ref(type<Entity>()) });
				//m_logic_script->m_signature.m_params.push_back({ "entity", Ref(type<Spatial>()) });
			}

			//vector<Var> args = { Ref(spatial.m_handle), Ref(&spatial) };
			//(*m_logic_script)(args);
		}
	}

	void EntityScript::run_render()
	{
		if(m_render_script)
		{
			Spatial& spatial = m_spatial;
			//vector<Var> args = { Ref(&spatial) };
			//(*m_render_script)(args);
		}
	}
}
