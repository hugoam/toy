//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/Action.h>

#include <core/Entity/Entity.h>

#include <proto/Complex.h>
#include <refl/Method.h>

using namespace mud; namespace toy
{
	Action::Action(ProcedureType& actionType, User* user, Entity& agent, Entity& target)
		: Procedure(actionType, user, Ref(&agent), { Ref(&target) })
		, m_agent(agent)
		, m_target(target)
	{}
}
