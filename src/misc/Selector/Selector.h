//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <core/Store/Array.h>
#include <core/Types.h>
#include <core/Entity/EntityObserver.h>
#include <core/Selector/Selection.h>

using namespace two; namespace toy
{
	class TargetDispatcher
	{
	public:
		//virtual void init(const ActorList& actors) = 0;
		virtual void init(const vector<Ref>& targets) = 0;
		virtual Ref dispatchTarget(Ref agent) = 0;
	};

	//void selector_actions()

	class refl_ TOY_CORE_EXPORT Selector : public StoreObserver<Entity>
	{
	public:
		constr_ Selector(User& user);
		~Selector();

		attr_ User& m_user;

		Selection m_selection;
		Selection m_targets;

		Array<ProcedureType> m_actions;
		Array<ProcedureType> m_methods;

		void updateActions();
		void updateMethods();

		void handle_add(Entity& entity);
		void handle_remove(Entity& entity);
		bool handleClear();

		//void execute(ProcedureType& method);
		void execute(ProcedureType& action);

		//void execute(const string& action);

		void execute(ProcedureType& action, TargetDispatcher& dispatcher);
	};
}
