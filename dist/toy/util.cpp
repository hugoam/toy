#include <toy/util.h>
#include <two/refl.h>
#include <two/infra.h>
#include <two/type.h>




namespace toy
{
	ProcedureType::ProcedureType(Type& type)
		: m_type(type), m_index(index(type, Ref(this)))
	{}

	ProcedureType::~ProcedureType()
	{
		unindex(m_type, m_index);
	}

	Procedure::Procedure(ProcedureType& def, User* user, Ref object, vector<Ref> args)
		: m_def(def)
		, m_user(user)
		, m_object(object)
		, m_args(move(args))
	{}
}

#ifdef TWO_MODULES
module toy.util;
#else
#endif

namespace two
{
    // Exported types
    
    
    template <> TOY_UTIL_EXPORT Type& type<toy::ProcedureType>() { static Type ty("ProcedureType", sizeof(toy::ProcedureType)); return ty; }
    template <> TOY_UTIL_EXPORT Type& type<toy::Procedure>() { static Type ty("Procedure", sizeof(toy::Procedure)); return ty; }
}
//  Copyright (c) 2015 Hugo Amiard hugo.amiard@laposte.net



namespace toy
{
	Scheduler::Scheduler(size_t queueSize)
		: m_actions(queueSize)
	{}

	Scheduler::~Scheduler() 
	{}

	bool Scheduler::scheduleAction(const ProcedureType& action)
	{
		return m_actions.push(action);
	}

	void Scheduler::processActions()
	{
		int i = 0;
		ProcedureType action;

		if(!m_actions.empty())
		{
			while(((++i) < 5) && m_actions.pop(action))
			{
				action();
			}
		}
	}
}
