#pragma once

#include <mud/math.h>
#include <mud/refl.h>
#include <mud/infra.h>
#include <mud/type.h>
//#include <util/Executable.h>



#ifndef TOY_UTIL_EXPORT
#define TOY_UTIL_EXPORT MUD_IMPORT
#endif

namespace mud
{
    class Executable;
}

namespace toy
{
	class ProcedureType;
    class Procedure;
    class Scheduler;
}


#include <stl/string.h>



#ifndef MUD_CPP_20
#include <atomic>
#include <stl/stddef.h>
#endif

namespace mud
{
	class MUD_TYPE_EXPORT Executable
	{
	public:
		Executable() : m_done(false), m_doneFlag(0) {}
		virtual ~Executable() {}

		virtual void begin() = 0;
		virtual void update(size_t tick, double step) { UNUSED(tick); UNUSED(step); }
		virtual void abort() {}
		
		void execute() { m_done = false; this->begin(); }
		void stop()	{ m_done = true; if(m_doneFlag) *m_doneFlag = true; this->abort(); }
		bool done() { return m_done; }

		void flag(std::atomic<bool>* done) { *done = false; m_doneFlag = done; }

	protected:
		bool m_done;
		std::atomic<bool>* m_doneFlag;
	};
}

using namespace mud; namespace toy
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

		Meta& meta() { return mud::meta(m_type); }

		virtual bool checkObject(Ref object) = 0;
		virtual bool checkArgs(const vector<Ref>& args) = 0;
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
		bool checkArgs(const vector<Ref>& args) { return T_Procedure::checkArgs(args); }
		object<Procedure> instance(User* user, Ref object, vector<Ref> args) { return T_Procedure::instance(user, object, args); }
	};

	template <class T_Procedure>
	class TypedProcedure : public Procedure
	{
	public:
		TypedProcedure(User* user, Ref object, vector<Ref> args = {}) : Procedure(T_Procedure::def(), user, object, args) {}

		static bool checkObject(Ref object) { UNUSED(object); return true; }
		static bool checkArgs(const vector<Ref>& args) { UNUSED(args); return true; }
		static object<Procedure> instance(User* user, Ref object, vector<Ref> args) { return oconstruct<T_Procedure>(user, object, args); }

		static ProcedureType& def() { static ProcedureDef<T_Procedure> df; return df; }
	};
}


#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#endif

#ifndef MUD_MODULES
#endif

#ifndef MUD_CPP_20
#include <stl/string.h>
#include <stl/vector.h>
#include <stdint.h>
#endif


namespace mud
{
    // Exported types
    
    export_ template <> TOY_UTIL_EXPORT Type& type<toy::Procedure>();
    export_ template <> TOY_UTIL_EXPORT Type& type<toy::ProcedureType>();
    
    export_ template <> TOY_UTIL_EXPORT Type& type<vector<toy::Procedure*>>();
    export_ template <> TOY_UTIL_EXPORT Type& type<vector<toy::ProcedureType*>>();
}


#include <stl/function.h>

using namespace mud; namespace toy
{
	class TOY_UTIL_EXPORT Scheduler
	{
	public:
		typedef function<void()> ProcedureType;

	public:
		Scheduler(size_t queueSize);
		~Scheduler();

		bool scheduleAction(const ProcedureType& action);
		void processActions();

	private:
		LocklessQueue<ProcedureType> m_actions;
	};
}

