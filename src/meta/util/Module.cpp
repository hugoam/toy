#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module toy.util;
#else
#include <type/Any.h>
#include <type/Vector.h>
#include <refl/MetaDecl.h>
#include <refl/Module.h>
#include <meta/type/Module.h>
#include <meta/math/Module.h>
#include <meta/util/Module.h>
#include <meta/util/Convert.h>
#endif

#include <util/Api.h>

namespace mud
{
	void toy_util_meta(Module& m)
	{
	UNUSED(m);
	
	// Base Types
	
	// Enums
	
	// Sequences
	
	// toy::Procedure
	{
		static Meta meta = { type<toy::Procedure>(), &namspc({ "toy" }), "Procedure", sizeof(toy::Procedure), TypeClass::Object };
		static Class cls = { type<toy::Procedure>(),
			// bases
			{  },
			{  },
			// constructors
			{
			},
			// copy constructor
			{
			},
			// members
			{
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		meta_class<toy::Procedure>();
	}
	// toy::ProcedureType
	{
		static Meta meta = { type<toy::ProcedureType>(), &namspc({ "toy" }), "ProcedureType", sizeof(toy::ProcedureType), TypeClass::Object };
		static Class cls = { type<toy::ProcedureType>(),
			// bases
			{  },
			{  },
			// constructors
			{
			},
			// copy constructor
			{
			},
			// members
			{
				{ type<toy::ProcedureType>(), Address(), type<mud::Type>(), "type", Ref(type<mud::Type>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::ProcedureType>(object).m_type); } },
				{ type<toy::ProcedureType>(), member_address(&toy::ProcedureType::m_index), type<uint32_t>(), "index", var(uint32_t()), Member::Value, nullptr },
				{ type<toy::ProcedureType>(), member_address(&toy::ProcedureType::m_name), type<string>(), "name", var(string()), Member::Value, nullptr }
			},
			// methods
			{
			},
			// static members
			{
			}
		};
		meta_class<toy::ProcedureType>();
	}
		m.m_types.push_back(&type<toy::Procedure>());
		m.m_types.push_back(&type<toy::ProcedureType>());
	}
}

namespace toy
{
	toy_util::toy_util()
		: Module("toy::util", { &mud_type::m(), &mud_math::m() })
	{
		// setup reflection meta data
		toy_util_meta(*this);
	}
}

#ifdef TOY_UTIL_MODULE
extern "C"
Module& getModule()
{
		return toy_util::m();
}
#endif
