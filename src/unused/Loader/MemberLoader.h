//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <obj/Ref.h>
#include <refl/Member.h>
#include <util/Forward.h>
#include <util/Loader/Loader.h>

using namespace two; namespace toy
{
	/* The loader system and its nodes are responsible for transcripting a hierarchy of objects into a linear list of data values for each object 
		It uses the dataloader, through two main interfaces :
			- save (->ObjectId, ->DataValues)
			- load (->ObjectId, <-DataValues)
	*/

	class refl_ TOY_UTIL_EXPORT MemberLoader : public Loader
	{
	public:
		MemberLoader(ObjectLoader& parent, Member& member, size_t index);

		virtual void parseNext() { this->parse(m_parent->data()[m_index], m_parent->m_args[m_index]); }
		virtual void parse(Var& data, Var& arg) { arg = data; }

		virtual void dump(Ref object) { return this->dump(object, m_parent->data()[m_index]); }
		virtual void dump(Ref object, Var& data) { data = m_member.get(object); }

		virtual void erase(Ref object) { UNUSED(object); }
		virtual void empty(Ref object) { UNUSED(object); }

	protected:
		Member& m_member;
		size_t m_index;
	};

	class refl_ TOY_UTIL_EXPORT TypeLoader : public MemberLoader
	{
	public:
		TypeLoader(ObjectLoader& parent, Member& member, size_t index);

		void parse(Var& darg, Var& arg);
		void dump(Ref object, Var& darg);

	protected:
		vector<Type*> m_types;
		vector<Id> m_ids;
	};

	class refl_ TOY_UTIL_EXPORT LinkedLoader : public MemberLoader
	{
	public:
		LinkedLoader(ObjectLoader& parent, Member& member, size_t index);

		void parse(Var& darg, Var& arg);
		void dump(Ref object, Var& darg);
	};

	class refl_ TOY_UTIL_EXPORT OwnedLoader : public ObjectLoader
	{
	public:
		OwnedLoader(ObjectLoader& parent, Member& member, size_t index);

		virtual void parseNext() { this->parse(m_parent->data()[m_index], m_parent->m_args[m_index]); }

		virtual void dump(Ref object) { return this->dump(object, m_parent->data()[m_index]); }

		void parse(Var& darg, Var& arg);

		void queue(Ref object, size_t depth);
		void dump(Ref object, Var& darg);

		void erase(Ref object, Id id);
		void unload(Ref object);

	protected:
		Member& m_member;
		size_t m_index;
	};

	class refl_ TOY_UTIL_EXPORT SequenceLoader : public MemberLoader
	{
	public:
		SequenceLoader(ObjectLoader& parent, Member& member, size_t index);

		void parse(Var& darg, Var& arg);

		void queue(Ref object, size_t depth);
		void dump(Ref object, Var& darg);

		void erase(Ref object);

	protected:
		object_ptr<Loader> m_elementLoader;
	};

	class refl_ TOY_UTIL_EXPORT StructureLoader : public MemberLoader
	{
	public:
		StructureLoader(ObjectLoader& parent, Member& member, size_t index);

		void select(Id id);
		bool selectNext();
		void parseNext();

		void parse(Var& darg, Var& arg);

		void queue(Ref object, size_t depth);
		void dump(Ref object, Var& darg);

		void erase(Ref object);
	};
}
