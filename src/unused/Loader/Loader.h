//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <infra/Global.h>
#include <proto/Proto.h>
#include <obj/Indexer.h>
#include <obj/Var.h>
#include <refl/Injector.h>
#include <util/Forward.h>

#ifndef MUD_CPP_20
#include <vector>
#endif

using namespace mud; namespace toy
{
	class TOY_UTIL_EXPORT GlobalLoader : public NonCopy, public Global<GlobalLoader>
	{
	public:
		GlobalLoader();

		void clear();

		void setDataSource(DataSource& dataSource);
		ObjectLoader& getLoader(Type& type);

	protected:
		DataSource* m_dataSource;
		std::vector<object_ptr<ObjectLoader>> m_loaders;
	};

	class refl_ TOY_UTIL_EXPORT Loader : public NonCopy
	{
	public:
		Loader(Type& type, DataSource& dataSource, ObjectLoader* parent = nullptr);
		virtual ~Loader();

		void setup(Loader* parent = nullptr, Member* member = nullptr);

		Type& m_type;
		DataSource& m_dataSource;

		ObjectLoader* m_parent;

		bool m_autoId;
		bool m_dataId;

		unique_ptr<DataLoader> m_dataLoader;

		std::vector<Var> m_data;

		// Loading
		virtual void select(Id id);
		virtual bool selectNext();
		virtual void parseNext();

		// Saving
		virtual void saveInit();
		virtual void queue(Ref object, size_t depth);
		virtual void dump(Ref object);
		virtual void saveCommit();

		// Erasing
		virtual void erase(Ref object);
	};

	class refl_ TOY_UTIL_EXPORT ObjectLoader : public Loader
	{
	public:
		ObjectLoader(Type& type, DataSource& dataSource, ObjectLoader* parent = nullptr, Member* member = nullptr);
        ~ObjectLoader();

		void setup_object(Loader* parent = nullptr, Member* member = nullptr);

		Injector* m_injector;
		Prototype* m_prototype;
		array<Var> m_args;

		array<Var> data() { return m_dataId ? array<Var>{ m_data, 1 } : array<Var>{ m_data }; }

		// Allocation
		Id allocate();
		void erase(Ref object, Id id);


		// Loading
		virtual void select(Id id);
		virtual bool selectNext();
		virtual void parseNext();

		Ref load(Id id);
		void fill(Ref object, Id id);
		void parsePrototype();
		void loadNext(Var& arg);
		Ref loadNext();

		// Saving
		virtual void saveInit();
		virtual void queue(Ref object, size_t depth);
		virtual void saveCommit();

		void save(Ref object, Id id);
		Id saveId(Ref object);

		// Erasing
		using Loader::erase;

		void debugPrint(Ref object, size_t depth, cstring message);

	public:
		size_t& batchId() { return m_autoFirstId; }

	protected:
		std::vector<object_ptr<Loader>> m_subloaders;
		std::vector<object_ptr<Loader>> m_postloaders;

		std::vector<std::vector<Ref>> m_batch;
		size_t m_batchDepth;
		size_t m_batchCounter;
		size_t m_autoFirstId;

		size_t m_protoIndex;

		std::vector<Injector> m_injectors;
	};

	class refl_ TOY_UTIL_EXPORT PartLoader : public ObjectLoader
	{
	public:
		PartLoader(ObjectLoader& parent, Type& type);

		virtual void parseNext();
		
		virtual void queue(Ref object, size_t depth);
	};
}
