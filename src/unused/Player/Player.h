//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <obj/Ref.h>
#include <obj/Indexer.h>
#include <core/Forward.h>

#ifndef MUD_CPP_20
#include <vector>
#endif

using namespace mud; namespace toy
{
	using string = std::string;

	class refl_ TOY_CORE_EXPORT User
	{
	public:
		std::vector<Ref> m_selection;
	};

#if 0
	class refl_ TOY_CORE_EXPORT Player
	{
	public:
		constr_ Player(Id id, const string& name);

		attr_ Id m_id;
		attr_ string m_name;
		attr_ std::vector<Ref> m_selection;
	};
#endif
}
