//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <type/Ref.h>
#include <type/Indexer.h>
#include <util/Forward.h>
#include <util/Executable.h>
#include <refl/Meta.h>

#ifndef MUD_CPP_20
#include <string>
#endif

using namespace mud; namespace toy
{
	using string = std::string;
	class User;

	class refl_ TOY_UTIL_EXPORT ProcedureType
	{
	public:
		ProcedureType(Type& type);
		virtual ~ProcedureType();

		attr_ Type& m_type;
		attr_ uint32_t m_index;
		attr_ string m_name;

		Meta& meta() { return mud::meta(m_type); }

		virtual bool checkObject(Ref object) = 0;
		virtual bool checkArgs(const std::vector<Ref>& args) = 0;
		virtual object_ptr<Procedure> instance(User* user, Ref object, std::vector<Ref> args) = 0;
	};

	class refl_ TOY_UTIL_EXPORT Procedure : public Executable
	{
	public:
		Procedure(ProcedureType& def, User* user, Ref object, std::vector<Ref> args = {});

		ProcedureType& m_def;
		User* m_user;
		Ref m_object;
		std::vector<Ref> m_args;
	};

	template <class T_Procedure>
	class ProcedureDef : public ProcedureType//, public LazyGlobal<ProcedureDef<T_Procedure>>
	{
	public:
		ProcedureDef() : ProcedureType(type<T_Procedure>()) {}

		bool checkObject(Ref object) { return T_Procedure::checkObject(object); }
		bool checkArgs(const std::vector<Ref>& args) { return T_Procedure::checkArgs(args); }
		object_ptr<Procedure> instance(User* user, Ref object, std::vector<Ref> args) { return T_Procedure::instance(user, object, args); }
	};

	template <class T_Procedure>
	class TypedProcedure : public Procedure
	{
	public:
		TypedProcedure(User* user, Ref object, std::vector<Ref> args = {}) : Procedure(T_Procedure::def(), user, object, args) {}

		static bool checkObject(Ref object) { UNUSED(object); return true; }
		static bool checkArgs(const std::vector<Ref>& args) { UNUSED(args); return true; }
		static object_ptr<Procedure> instance(User* user, Ref object, std::vector<Ref> args) { return make_object<T_Procedure>(user, object, args); }

		static ProcedureType& def() { static ProcedureDef<T_Procedure> df; return df; }
	};
}
