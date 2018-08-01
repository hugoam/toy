//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <core/Forward.h>
#include <core/Store/StoreObserver.h>

using namespace mud; namespace toy
{
	template class TOY_CORE_EXPORT StoreObserver<Entity>;

	class HookObserver { public: virtual void hooked() = 0;
								 virtual void unhooked() = 0; };
}
