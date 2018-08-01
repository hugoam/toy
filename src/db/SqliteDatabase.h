//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is provided 'as-is' under the zlib License, see the LICENSE.txt file.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

/* toy */
#include <infra/NonCopy.h>
#include <obj/Unique.h>
#include <db/Generated/Forward.h>
#include <util/Loader/DataLoader.h>

/* std */
#include <vector>
#include <string>

struct sqlite3;

using namespace mud; namespace toy
{
	using string = std::string;

    class refl_ TOY_DB_EXPORT SqliteDatabase : public NonCopy, public DataSource
    {
    public:
        SqliteDatabase(cstring path);
        ~SqliteDatabase();

		virtual unique_ptr<DataLoader> makeLoader();

		bool init();
		void close();

		void syncTypes();
		void loadTypes();
		void saveTypes();

		SqliteModel& getModel(Type& type);

		virtual void beginBatch(Loader& loader);
		virtual void commitBatch(Loader& loader);

		virtual Type* indexToType(Id index) { return m_indexToType[index]; }
		virtual Id typetoIndex(Type& type) { return m_typeToIndex[type.m_id]; }

		int checkError(int result);

		//void synchronize();

		sqlite3* database() { return m_database; }

    private:
		string m_path;
        sqlite3* m_database = nullptr;
		Loader* m_batching = nullptr;

		std::vector<unique_ptr<SqliteModel>> m_models;

		std::vector<Type*> m_indexToType;
		std::vector<Id> m_typeToIndex;
    };
}
