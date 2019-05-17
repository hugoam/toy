//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is provided 'as-is' under the zlib License, see the LICENSE.txt file.
//  This notice and the license may not be removed or altered from any source distribution.

#include <db/Generated/Types.h>
#include <db/SqliteDatabase.h>

#include <obj/Indexer.h>
#include <db/SqliteLoader.h>

#include <refl/System.h>

#include <algorithm>

/* sqlite */
#include "sqlite3.h"

using namespace two; namespace toy
{
	SqliteDatabase::SqliteDatabase(cstring path)
		: m_path(path)
		, m_models(MUD_MAX_TYPES)
	{}

	SqliteDatabase::~SqliteDatabase()
	{
		close();
	}

	unique_ptr<DataLoader> SqliteDatabase::makeLoader()
	{
		return make_unique<SqliteLoader>(*this);
	}

	bool SqliteDatabase::init()
	{
		bool result = !sqlite3_open(m_path.c_str(), &m_database);
		sqlite3_exec(m_database, "PRAGMA recursive_triggers = true", 0, 0, 0);
		this->syncTypes();
		return result;
	}

	void SqliteDatabase::close()
	{
		sqlite3_close(m_database);
	}

	SqliteModel& SqliteDatabase::getModel(Type& type)
	{
		if(m_models[type.m_id] == nullptr)
			m_models[type.m_id] = make_unique<SqliteModel>(type, *this);

		return *m_models[type.m_id];
	}

	void SqliteDatabase::syncTypes()
	{
		string statement = "SELECT 1 FROM sqlite_master WHERE type='table' AND name='M_Types'";

		int result = 0;
		sqlite3_exec(m_database, statement.c_str(), [](void* result, int cols, char**, char**) -> int { *(int*)result = cols; return 0; }, &result, 0);

		if(result == 0)
			this->saveTypes();

		this->loadTypes();
	}

	void SqliteDatabase::loadTypes()
	{
		string statement = "SELECT id, name FROM M_Types";
		sqlite3_stmt* load = nullptr;
		sqlite3_prepare_v2(m_database, statement.c_str(), -1, &load, 0);

		while(checkError(sqlite3_step(load)) == SQLITE_ROW)
		{
			size_t index = sqlite3_column_int(load, 0);
			const char* name = reinterpret_cast<const char*>(sqlite3_column_text(load, 1));

			Type* type = system().find_type(name);

#if 0
			printf("INFO: Loading type %s data from database\n", name);
#endif

			if(type == nullptr)
			{
				printf("WARNING: Type %s registered in database not found in runtime\n", name);
				continue;
			}

			m_typeToIndex.resize(max(m_typeToIndex.size(), size_t(type->m_id + 1)));
			m_indexToType.resize(max(m_indexToType.size(), index + 1));

			m_typeToIndex[type->m_id] = index;
			m_indexToType[index] = type;
		}
	}

	void SqliteDatabase::saveTypes()
	{
		string statement = "CREATE TABLE M_Types (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT)";
		checkError(sqlite3_exec(m_database, statement.c_str(), 0, 0, 0));

		statement = "INSERT INTO M_Types(id, name) VALUES ((?), (?))";
		sqlite3_stmt* save = nullptr;
		sqlite3_prepare_v2(m_database, statement.c_str(), -1, &save, 0);

		sqlite3_exec(m_database, "BEGIN;", 0, 0, 0);

		for(Type* type : System::instance().m_types)
		{
			sqlite3_bind_null(save, 1);
			sqlite3_bind_text(save, 2, type->m_name, strlen(type->m_name), SQLITE_TRANSIENT);
			checkError(sqlite3_step(save));
			sqlite3_reset(save);
		}

		sqlite3_exec(m_database, "COMMIT;", 0, 0, 0);
	}

	void SqliteDatabase::beginBatch(Loader& loader)
	{
		if(m_batching)
			return;

		sqlite3_exec(m_database, "BEGIN;", 0, 0, 0);
		m_batching = &loader;
	}

	void SqliteDatabase::commitBatch(Loader& loader)
	{
		if(m_batching != &loader)
			return;

		sqlite3_exec(m_database, "COMMIT;", 0, 0, 0);
		m_batching = nullptr;
	}

	int SqliteDatabase::checkError(int result)
	{
		if(result != SQLITE_OK && result != SQLITE_DONE && result != SQLITE_ROW)
			printf("ERROR: SqliteDatabase statement execution failed\n");
		return result;
	}
}
