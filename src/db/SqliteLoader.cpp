//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is provided 'as-is' under the zlib License, see the LICENSE.txt file.
//  This notice and the license may not be removed or altered from any source distribution.

#include <db/Generated/Types.h>
#include <db/SqliteLoader.h>

#include <obj/DispatchDecl.h>
#include <refl/Class.h>
#include <refl/Convert.h>
#include <db/SqliteDatabase.h>

#include <util/Loader/Loader.h>
#include <util/Loader/MemberLoader.h>

#include <infra/StringConvert.h>

/* sqlite */
#include "sqlite3.h"

/* std */
#include <stdio.h>

using namespace two; namespace toy
{
	Type& dataType(Type& type)
	{
		if(is_object(type))
			return type<Id>();
		else if(type.is<Type>())
			return type<Id>();
		else if(is_enum(type))
			return type<int>();
		else
			return type;
	}

	string fieldType(const string& name, Type& type, bool autoid)
	{
		if(type.is<Id>() && name == "id" && !autoid)
			return "INTEGER PRIMARY KEY";
		else if(type.is<Id>() && name == "id" && autoid)
			return "INTEGER PRIMARY KEY AUTOINCREMENT";
		else if(type.is<bool>() || type.is<int>() || type.is<unsigned int>() || type.is<size_t>())
			return "INTEGER";
		else if(type.is<float>())
			return "FLOAT";
		else if(type.is<stl/string>())
			return "TEXT";
		else
			return "INTEGER";
	}

	SqliteSet::SqliteSet()
	{
		dispatch_branch<int>(*this, [](int& value, sqlite3_stmt* stmt, size_t i) { sqlite3_bind_int(stmt, i + 1, value); });
		dispatch_branch<float>(*this, [](float& value, sqlite3_stmt* stmt, size_t i) { sqlite3_bind_double(stmt, i + 1, value); });
		dispatch_branch<stl/string>(*this, [](string& value, sqlite3_stmt* stmt, size_t i) { sqlite3_bind_text(stmt, i + 1, value.c_str(), value.size(), SQLITE_TRANSIENT); });
		dispatch_branch<Id>(*this, [](Id& value, sqlite3_stmt* stmt, size_t i) { sqlite3_bind_int(stmt, i + 1, value); });
		dispatch_branch<bool>(*this, [](bool& value, sqlite3_stmt* stmt, size_t i) { sqlite3_bind_int(stmt, i + 1, value); });
	}

	SqliteGet::SqliteGet()
	{
		dispatch_branch<int>(*this, [](int& value, sqlite3_stmt* stmt, size_t i) { value = sqlite3_column_int(stmt, i); });
		dispatch_branch<float>(*this, [](float& value, sqlite3_stmt* stmt, size_t i) { value = float(sqlite3_column_double(stmt, i)); });
		dispatch_branch<stl/string>(*this, [](string& value, sqlite3_stmt* stmt, size_t i) { const char* result = reinterpret_cast<const char*>(sqlite3_column_text(stmt, i)); value = result ? result : ""; });
		dispatch_branch<Id>(*this, [](Id& value, sqlite3_stmt* stmt, size_t i) { value = sqlite3_column_int(stmt, i); });
		dispatch_branch<bool>(*this, [](bool& value, sqlite3_stmt* stmt, size_t i) { value = sqlite3_column_int(stmt, i) != 0; });
	}

	string quote(const string& str)
	{
		return "`" + str + "`";
	}

	string join(const vector<stl/string>& values, string separator, string prefix = "")
	{
		string str;
		for(const string& val : values)
			str += prefix + val + separator;
		str.erase(str.begin() + str.size() - separator.size(), str.end());
		return str;
	}

	SqliteModel::SqliteModel(Type& type, SqliteDatabase& database)
		: m_type(type)
		, m_dataType(dataType(type))
		, m_autoId(false)
		, m_dataId(false)
		, m_database(database.database())
	{
		if(type.m_class->m_members.empty() || string(type.m_class->m_members[0].m_name) != "id")
			m_dataId = true;
		if(m_dataId && is_root_type(type))
			m_autoId = true;

		m_table = "M_" + string(type.m_meta->m_name);

		if(m_dataId)
		{
			m_argNames.push_back("id");
			m_argDecls.push_back("id " + (m_autoId ? string("INTEGER PRIMARY KEY AUTOINCREMENT") : string("INTEGER PRIMARY KEY")));
			m_argData.push_back(var(Id()));
		}

		//for(Member& member : type.m_class->members)
		for(Param& param : type.m_class->m_constructors[int(ConstructorIndex::Default)].m_params)
		{
			if(param.m_index == 0)
				continue;
			Type& paramType = dataType(param.m_value.type());
			m_argNames.push_back(quote(param.m_name));
			m_argDecls.push_back(quote(param.m_name) + " " + fieldType(param.m_name, paramType, m_autoId));
			m_argData.push_back(paramType.m_meta->m_empty_var());
		}

		if(this->needSync())
			this->synchronize();
	}

	bool SqliteModel::needSync()
	{
		string statement = "SELECT 1 FROM sqlite_master WHERE type='table' AND name='" + m_table + "'";

		int result = 0;
		sqlite3_exec(m_database, statement.c_str(), [](void* result, int cols, char**, char**) -> int { *(int*)result = cols; return 0; }, &result, 0);

		return result == 0;
	}

	void SqliteModel::synchronize()
	{
		string statement = "CREATE TABLE " + m_table + " (" + join(m_argDecls, ", ") + ")";

		//printf("SqliteLoader init: %s\n", statement.c_str());
		checkError(sqlite3_exec(m_database, statement.c_str(), 0, 0, 0));

		for(Member& member : m_type.m_class->m_members)
		{
			if(is_struct(*member.m_type) || (is_object(*member.m_type) && !member.is_link()))
			{
				string trigger = "CREATE TRIGGER " + m_table + "_" + member.m_name + "_delete";
				trigger += " DELETE ON " + m_table + " FOR EACH ROW";
				trigger += " BEGIN";
				trigger += " DELETE FROM M_" + string(member.meta().m_name) + " WHERE id=old." + member.m_name + ";";
				trigger += " END;";
				//printf("SqliteLoader init: %s\n", trigger.c_str());
				//checkError(sqlite3_exec(m_database, trigger.c_str(), 0, 0, 0));

				trigger = "CREATE TRIGGER " + m_table + "_" + member.m_name + "_update";
				trigger += " UPDATE OF " + string(member.m_name) + " ON " + m_table + " FOR EACH ROW";
				trigger += " BEGIN";
				trigger += " DELETE FROM M_" + string(member.meta().m_name) + " WHERE id=old." + member.m_name + ";";
				trigger += " END;";
				//printf("SqliteLoader init: %s\n", trigger.c_str());
				//checkError(sqlite3_exec(m_database, trigger.c_str(), 0, 0, 0));
			}
		}
	}

	void SqliteModel::checkError(int result)
	{
		if(result != SQLITE_OK && result != SQLITE_DONE)
			printf("ERROR: SqliteModel statement execution failed\n");
	}

	SqliteLoader::SqliteLoader(SqliteDatabase& database)
		: DataLoader()
		, m_datasource(database)
		, m_database(database.database())
	{}

	SqliteLoader::~SqliteLoader()
	{
		for(sqlite3_stmt* statement : m_statements)
			sqlite3_finalize(statement);
	}

	void SqliteLoader::setup(Type& type, DataLoader* parent, Member* member)
	{
		if(type.m_class->m_constructors.empty())
			return;

		m_model = &m_datasource.getModel(type);
		m_tree = type.m_class->m_nested;
		m_parent = parent ? &as<SqliteLoader>(*parent) : nullptr;
		m_root = m_parent ? m_parent->m_root : this;
		m_member = member;

		// @todo : sequences
		/*if(is_sequence(type))
		{
			m_element = type.m_class->content;

			m_table = "M_" + type.m_meta->name;
			m_argNames = { "id", "element" };
			m_argDecls = { "id INTEGER", "element INTEGER" };
		}*/

		this->prepare();
	}

	vector<Var> SqliteLoader::data()
	{
		return m_model ? m_model->m_argData : vector<Var>();
	}

	void SqliteLoader::prepare(sqlite3_stmt*& statement, cstring content)
	{
		//printf("SqliteLoader prepare: %s\n", content);
		checkError(sqlite3_prepare_v2(m_database, content, -1, &statement, 0));
		if(statement != nullptr)
			m_statements.push_back(statement);
	}
	
	string SqliteLoader::saveStatement()
	{
		string statement = "INSERT OR REPLACE INTO " + m_model->m_table + "(" + join(m_model->m_argNames, ", ") + ")";
		statement += " VALUES (" + join(vector<stl/string>(m_model->m_argNames.size(), "(?)"), ", ") + ");";
		return statement;
	}

	string SqliteLoader::rootQuery()
	{
		if(m_tree)
		{
			return " WITH RECURSIVE q(id) AS(SELECT id FROM " + m_model->m_table + " WHERE parent = (?)"
				   " UNION ALL SELECT m.id FROM " + m_model->m_table + " AS m JOIN q ON m.parent = q.id)";
		}
		else
		{
			return " WITH q(id) AS (SELECT id FROM " + m_model->m_table + " WHERE id = (?))";
		}
	}

	string SqliteLoader::joinQuery()
	{
		string query;

		if(m_member)
			query = m_parent->joinQuery() + " INNER JOIN " + m_model->m_table + " ON " + m_model->m_table + ".id = " + m_parent->m_model->m_table + "." + m_member->m_name;
		else if(m_parent)
			query = m_parent->joinQuery() + " LEFT JOIN " + m_model->m_table + " ON " + m_model->m_table + "." + m_model->m_argNames[0] + " = " + m_parent->m_model->m_table + ".id";
		else
			query = " q INNER JOIN " + m_model->m_table + " ON " + m_model->m_table + ".id = " + "q.id";

		if(m_element)
			query += " INNER JOIN " + m_element->m_model->m_table + " ON " + m_model->m_table + ".element = " + m_element->m_model->m_table + ".id";

		return query;
	}

	string SqliteLoader::selectStatement()
	{
		string statement = m_root->rootQuery();
		statement += " SELECT " + join(m_model->m_argNames, ", ", m_model->m_table + ".");
		statement += " FROM " + this->joinQuery() + " ORDER BY q.id";
		return statement;
	}

	void SqliteLoader::prepare()
	{
		prepare(m_select, selectStatement().c_str());
		prepare(m_save, saveStatement().c_str());

		prepare(m_nextId, ("SELECT seq FROM SQLITE_SEQUENCE WHERE name='" + m_model->m_table + "'").c_str());
		prepare(m_deallocate, ("DELETE FROM " + m_model->m_table + " WHERE id = (?)").c_str());
	}

	void SqliteLoader::select(Id id)
	{
		sqlite3_reset(m_select);
		sqlite3_clear_bindings(m_select);
		if(id)
			sqlite3_bind_int(m_select, 1, id);
		else
			sqlite3_bind_null(m_select, 1);
	}

	bool SqliteLoader::selectNext()
	{
		int result = sqlite3_step(m_select);

		if(result == SQLITE_DONE)
			return false;

		if(sqlite3_column_type(m_select, 0) == SQLITE_NULL)
			return false;

		return true;
	}

	void SqliteLoader::load(array<Var> data)
	{
		size_t offset = m_model->m_dataId ? 1 : 0;

		for(size_t i = offset; i < data.size(); ++i)
			SqliteGet::me().dispatch(data[i], m_select, i);
	}

	void SqliteLoader::saveElement(Id object, Id element)
	{
		UNUSED(object); UNUSED(element);
	}

	Id SqliteLoader::save(Id id, array<Var> data, bool fetchId)
	{
		//this->deallocate(id); // @kludge because neither UPDATE or DELETE trigger fire on INSERT OR REPLACE in Sqlite... which is wrong

		if(m_model->m_dataId)
			m_model->m_autoId ? sqlite3_bind_null(m_save, 1) : sqlite3_bind_int(m_save, 1, id);

		size_t offset = m_model->m_dataId ? 1 : 0;

		for(size_t i = offset; i < data.size(); ++i)
			SqliteSet::me().dispatch(data[i], m_save, i);

		checkError(sqlite3_step(m_save));

		sqlite3_reset(m_save);
		sqlite3_clear_bindings(m_save);

		if(!m_model->m_dataId || !fetchId)
			return id;
		else
			return this->lastId();
	}

	Id SqliteLoader::lastId()
	{
		sqlite3_reset(m_nextId);
		sqlite3_step(m_nextId);
		Id id = sqlite3_column_int(m_nextId, 0);
		return id;
	}

	Id SqliteLoader::allocate()
	{
		return lastId() + 1;
	}

	void SqliteLoader::deallocate(Id id)
	{
		sqlite3_reset(m_deallocate);
		sqlite3_bind_int(m_deallocate, 1, id);

		checkError(sqlite3_step(m_deallocate));
	}

	void SqliteLoader::prepareCheck(cstring name)
	{
		string statement = "SELECT id FROM " + m_model->m_table;
		statement += " WHERE " + string(name) + " = (?)";
		prepare(m_check, statement.c_str());
	}

	bool SqliteLoader::check(Id& id, cstring name, const Var& value)
	{
		string str = to_string(value);
		printf("SqliteLoader check: %s = %s\n", name, str.c_str());
		this->prepareCheck(name);

		sqlite3_reset(m_check);
		sqlite3_clear_bindings(m_check);

		SqliteSet::me().dispatch(value.m_ref, m_check, 0);

		int result = sqlite3_step(m_check);
		checkError(result);

		if(result != SQLITE_ROW)
			return false;

		id = sqlite3_column_int(m_check, 0);

		return true;
	}

	void SqliteLoader::checkError(int result)
	{
		if(result != SQLITE_OK && result != SQLITE_DONE)
			printf("ERROR: SqliteLoader statement execution failed\n");
	}
}
