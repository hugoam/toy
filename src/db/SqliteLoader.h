//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is provided 'as-is' under the zlib License, see the LICENSE.txt file.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

/* toy */
#include <infra/NonCopy.h>
#include <obj/Dispatch.h>
#include <infra/Global.h>
#include <util/Loader/DataLoader.h>
#include <db/Generated/Forward.h>

#include <stl/string>

struct sqlite3;
struct sqlite3_stmt;

#define CACHE_QUERY

using namespace two; namespace toy
{
	using string = string;

	class TOY_DB_EXPORT SqliteGet : public Dispatch<void, sqlite3_stmt*, size_t>, public LazyGlobal<SqliteGet>
	{
	public:
		SqliteGet();
	};

	class TOY_DB_EXPORT SqliteSet : public Dispatch<void, sqlite3_stmt*, size_t>, public LazyGlobal<SqliteSet>
	{
	public:
		SqliteSet();
	};

	class TOY_DB_EXPORT SqliteModel
	{
	public:
		SqliteModel(Type& type, SqliteDatabase& database);

		Type& m_type;
		Type& m_dataType;

		bool m_autoId;
		bool m_dataId;

		string m_table;
		vector<stl/string> m_argNames;
		vector<stl/string> m_argDecls;
		vector<Var> m_argData;

		bool needSync();
		void synchronize();

		void checkError(int result);

	protected:
		sqlite3* m_database;
	};

	/*class TOY_DB_EXPORT SqliteQuery : public Query
	{
	public:

		string m_statement;
	};*/

	class TOY_DB_EXPORT SqliteLoader : public DataLoader
	{
	public:
		SqliteLoader(SqliteDatabase& database);
		~SqliteLoader();

		SqliteModel& model() { return *m_model; }

		virtual void setup(Type& type, DataLoader* parent, Member* member);

		void prepare();

		string rootQuery();
		string joinQuery();

		string selectStatement();
		string saveStatement();

		virtual vector<Var> data();

		virtual bool check(Id& id, cstring field, const Var& value);

		virtual void select(Id id = 0);
		virtual bool selectNext();
		virtual void load(array<Var> data);

		virtual Id save(Id id, array<Var> data, bool fetchId = true);
		virtual void saveElement(Id parent, Id object);
		virtual Id lastId();

		virtual Id allocate();
		virtual void deallocate(Id id);

		void prepareCheck(cstring name);

		void checkError(int result);

		void prepare(sqlite3_stmt*& statement, cstring content);

	private:
		SqliteDatabase& m_datasource;
		sqlite3* m_database;

		SqliteModel* m_model = nullptr;

		bool m_tree = false;
		SqliteLoader* m_root = nullptr;

		Member* m_member = nullptr;
		SqliteLoader* m_parent = nullptr; // for members
		SqliteLoader* m_element = nullptr; // for sequence members

		sqlite3_stmt* m_select = nullptr;

		sqlite3_stmt* m_save = nullptr;
		sqlite3_stmt* m_nextId = nullptr;

		sqlite3_stmt* m_deallocate = nullptr;

		sqlite3_stmt* m_check;

		vector<sqlite3_stmt*> m_statements;
	};
}
