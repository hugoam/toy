//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.


#include <util/Types.h>
#include <util/Loader/MemberLoader.h>

#include <infra/StringConvert.h>

#include <refl/Iterable.h>
#include <refl/Class.h>
#include <refl/Injector.h>

#include <util/Loader/Loader.h>
#include <util/Loader/DataLoader.h>

#include <infra/String.h>

using namespace mud; namespace toy
{
	MemberLoader::MemberLoader(ObjectLoader& parent, Member& member, size_t index)
		: Loader(*member.m_type, parent.m_dataSource, &parent)
		, m_member(member)
		, m_index(index)
	{}

	TypeLoader::TypeLoader(ObjectLoader& parent, Member& member, size_t index)
		: MemberLoader(parent, member, index)
	{}

	void TypeLoader::dump(Ref object, Var& data)
	{
		Var member = m_member.get(object);
		if(!member.null())
			val<Id>(data) = m_parent->m_dataSource.typetoIndex(val<Type>(member));
		else
			val<Id>(data) = 0; // Id 0 is reserved for null values, first valid Id is 1
	}

	void TypeLoader::parse(Var& data, Var& arg)
	{
		if(val<Id>(data) != 0)
			set<Type>(arg, m_parent->m_dataSource.indexToType(val<Id>(data)));
	}

	LinkedLoader::LinkedLoader(ObjectLoader& parent, Member& member, size_t index)
		: MemberLoader(parent, member, index)
	{}

	void LinkedLoader::dump(Ref object, Var& data)
	{
		Var member = m_member.get(object);
		if(!member.null())
			val<Id>(data) = 0; // @todo id_member get id 
		else
			val<Id>(data) = 0; // Id 0 is reserved for null values, first valid Id is 1
	}

	void LinkedLoader::parse(Var& data, Var& arg)
	{
		if(val<Id>(data) != 0)
			arg = indexed(m_type, val<Id>(data));
	}

	OwnedLoader::OwnedLoader(ObjectLoader& parent, Member& member, size_t index)
		: ObjectLoader(*member.m_type, parent.m_dataSource, &parent, &member)
		, m_member(member)
		, m_index(index)
	{}

	void OwnedLoader::dump(Ref object, Var& data)
	{
		if(m_autoId)
			val<Id>(data) = ObjectLoader::batchId()++;
		else
			val<Id>(data) = val<Id>(cls(object).m_id_member->get(object));
	}

	void OwnedLoader::queue(Ref object, size_t depth)
	{
		Var member = m_member.get(object);
		ObjectLoader::queue(member, depth);
	}

	void OwnedLoader::parse(Var& data, Var& arg)
	{
		UNUSED(data);
		//ObjectLoader::loadNext(arg);

		ObjectLoader::parseNext();
		m_injector->inject(arg);
	}

	void OwnedLoader::unload(Ref object)
	{
		UNUSED(object);
		//m_memberLoader->injector().destroyObject(m_member->object(object));
	}

	void OwnedLoader::erase(Ref object, Id id)
	{
		ObjectLoader::erase(m_member.get(object), id);
	}



	SequenceLoader::SequenceLoader(ObjectLoader& parent, Member& member, size_t index)
		: MemberLoader(parent, member, index)
	{
		if(member.is_link())
			m_elementLoader = make_object<LinkedLoader>(parent, member, index);
		else
			m_elementLoader = make_object<ObjectLoader>(*member.cls().m_content, parent.m_dataSource);

		this->setup(m_parent, &m_member);
	}

	void SequenceLoader::dump(Ref parent, Var& data)
	{
		UNUSED(data);

		if(m_member.is_link())
			return;

		m_member.cls().m_sequence(m_member.get(parent))->iterate([&](const Var& var) { UNUSED(var);/*m_elementLoader->dumpElement(parent, var);*/ });
	}

	void SequenceLoader::queue(Ref object, size_t depth)
	{
		if(m_member.is_link())
			return;

		m_member.cls().m_sequence(m_member.get(object))->iterate([this, depth](Var var) { m_elementLoader->queue(var, depth + 1); });
	}

	void SequenceLoader::parse(Var& data, Var& arg)
	{
		UNUSED(data); UNUSED(arg);

		if(m_member.is_link())
			return;

		//val<std::vector<object_ptr<Object>>>(arg).clear();
		//while(m_elementLoader->selectNext())
		//	m_elementLoader->loadNext();
		//arg->val<std::vector<object_ptr<Object>>>().push_back(m_memberLoader->construct());*/
	}

	void SequenceLoader::erase(Ref object)
	{
		m_member.cls().m_sequence(m_member.get(object))->iterate([&](Var var) { m_elementLoader->erase(var); });
	}


	StructureLoader::StructureLoader(ObjectLoader& parent, Member& member, size_t index)
		: MemberLoader(parent, member, index)
	{
		this->setup(m_parent, &m_member);
	}

	void StructureLoader::select(Id id)
	{
		UNUSED(id);
	}

	bool StructureLoader::selectNext()
	{
		return true;
	}

	void StructureLoader::parseNext()
	{}

	void StructureLoader::dump(Ref parent, Var& data)
	{
		UNUSED(data);

		if(m_member.is_link())
			return;

		m_member.cls().m_sequence(m_member.get(parent))->iterate([&](const Var& var) { UNUSED(var);/*m_parent.dumpElement(parent, var);*/ });
	}

	void StructureLoader::queue(Ref object, size_t depth)
	{
		if(m_member.is_link())
			return;

		m_member.cls().m_sequence(m_member.get(object))->iterate([&](Var var) { m_parent->queue(var, depth + 1); });
	}

	void StructureLoader::parse(Var& data, Var& arg)
	{
		UNUSED(data); UNUSED(arg);
	}

	void StructureLoader::erase(Ref object)
	{
		m_member.cls().m_sequence(m_member.get(object))->iterate([this](Var var) { m_parent->erase(var, 0); });
	}
}
