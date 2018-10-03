//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <ecs/Entity.h>
#include <infra/Global.h>
#include <core/Forward.h>
#include <core/Physic/Medium.h>
#include <core/Physic/Scope.h>

using namespace mud; namespace toy
{
	class TOY_CORE_EXPORT AreaMedium final : public Medium
	{
	public:
		constr_ AreaMedium();
		attr_ static AreaMedium me;
	};

	class TOY_CORE_EXPORT Physic
	{
	public:
		Physic(Spatial& spatial);
	};
}
