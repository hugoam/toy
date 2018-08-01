//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/Types.h>
#include <core/Script/Script.h>

#include <obj/Indexer.h>
#include <refl/Class.h>
#include <lang/Script.h>

#include <core/Entity/Entity.h>

#include <vector>

using namespace mud; namespace toy
{
	EntityScript::EntityScript(Entity& entity)
		: m_entity(entity)
	{
		indexer(type<EntityScript>()).index(entity.m_id, Ref(this));
	}

	void EntityScript::run_logic()
	{
		if(m_logic_script)
		{
			// @hack @kludge add proper way to define a script signature
			if(m_logic_script->m_signature.m_params.empty())
			{
				m_logic_script->m_signature.m_params.push_back({ "self", Ref(m_entity.m_complex.m_type) });
				m_logic_script->m_signature.m_params.push_back({ "entity", Ref(type<Entity>()) });
			}

			std::vector<Var> args = { Ref(&m_entity.m_complex), Ref(&m_entity) };
			(*m_logic_script)(args);
		}
	}

	void EntityScript::run_render()
	{
		if(m_render_script)
		{
			std::vector<Var> args = { Ref(&m_entity) };
			(*m_render_script)(args);
		}
	}
}
