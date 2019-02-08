//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.


#include <edit/Edit/EditActions.h>

namespace toy
{
	void Edit::begin()
	{
		//mUser->selector().selection()->select(m_target); // @crash the selection is being iterated
	}

	void Clone::begin()
	{
		//Object& clone = m_object_type.m_meta->creator().cloneObject(m_object);
		//mUser->selector().selection()->select(clone);
	}
}
