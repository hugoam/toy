//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#if 0
#include <edit/Types.h>
#include <edit/Edit/ReactiveEdit.h>

#include <uio/Object.h>

#include <core/Reactive/Reactive.h>

namespace toy
{
	void edit_reactive(Widget& parent, Reactive& reactive)
	{
		for(auto& behavior : reactive.m_behaviors)
			object_item(parent, Ref(behavior.get()));
	}
}
#endif