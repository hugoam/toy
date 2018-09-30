//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <util/Types.h>
#include <util/Procedure.h>

#include <ecs/Entity.h>
#include <refl/Method.h>

using namespace mud; namespace toy
{
	ProcedureType::ProcedureType(Type& type)
		: m_type(type), m_index(index(type, Ref(this)))
	{}

	ProcedureType::~ProcedureType()
	{
		unindex(m_type, m_index);
	}

	Procedure::Procedure(ProcedureType& def, User* user, Ref object, std::vector<Ref> args)
		: m_def(def)
		, m_user(user)
		, m_object(object)
		, m_args(std::move(args))
	{}
}
