//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <obj/Var.h>
#include <obj/Unique.h>
#include <util/Forward.h>

#ifndef MUD_CPP_20
#include <vector>
#endif

using namespace mud; namespace toy
{
	/*class TOY_UTIL_EXPORT Query
	{
	public:
	};*/

	class TOY_UTIL_EXPORT DataSource
	{
	public:
		virtual unique_ptr<DataLoader> makeLoader() = 0;

		virtual void beginBatch(Loader& loader) = 0;
		virtual void commitBatch(Loader& loader) = 0;

		virtual Type* indexToType(Id index) = 0;
		virtual Id typetoIndex(Type& type) = 0;
	};

	class TOY_UTIL_EXPORT DataLoader
	{
	public:
		virtual void setup(Type& type, DataLoader* parent = nullptr, Member* meber = nullptr) = 0;

		virtual std::vector<Var> data() = 0;

		virtual bool check(Id& id, cstring field, const Var& value) = 0;

		virtual void select(Id id) = 0;
		virtual bool selectNext() = 0;
		virtual void load(array<Var> data) = 0;

		virtual Id save(Id id, array<Var> data, bool fetchId = true) = 0;
		virtual Id lastId() = 0;

		virtual void saveElement(Id parent, Id element) = 0;

		virtual Id allocate() = 0;
		virtual void deallocate(Id id) = 0;
	};
}
