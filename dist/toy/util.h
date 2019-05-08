#pragma once

#include <two/math.h>
#include <two/refl.h>
#include <two/infra.h>
#include <two/type.h>

//#include <util/Executable.h>



#ifndef TOY_UTIL_EXPORT
#define TOY_UTIL_EXPORT TWO_IMPORT
#endif

namespace two
{
    class Executable;
}

namespace toy
{
	using namespace two;

	class ProcedureType;
    class Procedure;
    class Scheduler;
}


#include <stl/string.h>
#include <stl/span.h>


//#include <atomic>
#include <stl/stddef.h>

namespace two
{
	class TWO_TYPE_EXPORT Executable
	{
	public:
		Executable() : m_done(false), m_done_flag(0) {}
		virtual ~Executable() {}

		virtual void begin() = 0;
		virtual void update(size_t tick, double step) { UNUSED(tick); UNUSED(step); }
		virtual void abort() {}
		
		void execute() { m_done = false; this->begin(); }
		void stop()	{ m_done = true; if(m_done_flag) *m_done_flag = true; this->abort(); }
		bool done() { return m_done; }

		//void flag(std::atomic<bool>* done) { *done = false; m_done_flag = done; }

	protected:
		bool m_done;
		//std::atomic<bool>* m_done_flag;
		bool* m_done_flag;
	};
}

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

#include <stdint.h>
#include <stl/string.h>
#include <stl/vector.h>

#if !defined TWO_MODULES || defined TWO_TYPE_LIB
#endif

#ifndef TWO_MODULES
#endif


namespace two
{
    // Exported types
    
    
    export_ template <> TOY_UTIL_EXPORT Type& type<toy::ProcedureType>();
    export_ template <> TOY_UTIL_EXPORT Type& type<toy::Procedure>();
}


#include <stl/function.h>

namespace toy
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

