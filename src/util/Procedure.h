//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <stl/string.h>
#include <stl/span.h>
#include <type/Ref.h>
#include <type/Indexer.h>
#include <util/Forward.h>
#include <util/Executable.h>
#include <refl/Meta.h>

namespace toy
{
	class User;

	class refl_ TOY_UTIL_EXPORT ProcedureType
	{
	public:
		ProcedureType(Type& type);
		virtual ~ProcedureType();

		attr_ Type& m_type;
		attr_ uint32_t m_index;
		attr_ string m_name;

		Meta& meta() { return two::meta(m_type); }

		virtual bool checkObject(Ref object) = 0;
		virtual bool checkArgs(span<Ref> args) = 0;
		virtual object<Procedure> instance(User* user, Ref object, vector<Ref> args) = 0;
	};

	class refl_ TOY_UTIL_EXPORT Procedure : public Executable
	{
	public:
		Procedure(ProcedureType& def, User* user, Ref object, vector<Ref> args = {});

		ProcedureType& m_def;
		User* m_user;
		Ref m_object;
		vector<Ref> m_args;
	};

	template <class T_Procedure>
	class ProcedureDef : public ProcedureType//, public LazyGlobal<ProcedureDef<T_Procedure>>
	{
	public:
		ProcedureDef() : ProcedureType(type<T_Procedure>()) {}

		bool checkObject(Ref object) { return T_Procedure::checkObject(object); }
		bool checkArgs(span<Ref> args) { return T_Procedure::checkArgs(args); }
		object<Procedure> instance(User* user, Ref object, vector<Ref> args) { return T_Procedure::instance(user, object, args); }
	};

	template <class T_Procedure>
	class TypedProcedure : public Procedure
	{
	public:
		TypedProcedure(User* user, Ref object, vector<Ref> args = {}) : Procedure(T_Procedure::def(), user, object, args) {}

		static bool checkObject(Ref object) { UNUSED(object); return true; }
		static bool checkArgs(span<Ref> args) { UNUSED(args); return true; }
		static object<Procedure> instance(User* user, Ref object, vector<Ref> args) { return oconstruct<T_Procedure>(user, object, args); }

		static ProcedureType& def() { static ProcedureDef<T_Procedure> df; return df; }
	};
}
