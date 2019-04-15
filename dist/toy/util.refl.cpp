#include <mud/type.refl.h>
#include <toy/util.h>
#include <mud/refl.h>
#include <mud/math.refl.h>
#include <toy/util.refl.h>
#include <mud/infra.h>
#include <mud/type.h>


#ifdef MUD_MODULES
module toy.util;
#else
#include <cstddef>
#include <stl/new.h>
#endif


using namespace mud;

void* toy_ProcedureType__get_type(void* object) { return &(*static_cast<toy::ProcedureType*>(object)).m_type; }

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
		Type& t = type<toy::Procedure>();
		static Meta meta = { t, &namspc({ "toy" }), "Procedure", sizeof(toy::Procedure), TypeClass::Object };
		// bases
		// defaults
		// constructors
		// copy constructor
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, {}, {}, {}, {}, {}, };
	}
	// toy::ProcedureType
	{
		Type& t = type<toy::ProcedureType>();
		static Meta meta = { t, &namspc({ "toy" }), "ProcedureType", sizeof(toy::ProcedureType), TypeClass::Object };
		// bases
		// defaults
		// constructors
		// copy constructor
		// members
		static Member members[] = {
			{ t, SIZE_MAX, type<mud::Type>(), "type", nullptr, Member::Flags(Member::NonMutable|Member::Link), toy_ProcedureType__get_type },
			{ t, offsetof(toy::ProcedureType, m_index), type<uint32_t>(), "index", nullptr, Member::Value, nullptr },
			{ t, offsetof(toy::ProcedureType, m_name), type<stl::string>(), "name", nullptr, Member::Value, nullptr }
		};
		// methods
		// static members
		static Class cls = { t, {}, {}, {}, {}, members, {}, {}, };
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
