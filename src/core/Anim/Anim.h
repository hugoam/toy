//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is provided 'as-is' under the zlib License, see the LICENSE.txt file.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#ifndef TWO_MODULES
#include <type/Var.h>
#include <math/Timer.h>
#endif
#include <math/Interp.h>
#include <core/Forward.h>

namespace two
{
	export_ struct TOY_CORE_EXPORT Anim
	{
		Ref m_object;
		Member* m_member;
		Var m_source_value;
		Var m_target_value;
		float m_duration;
		float m_cursor;
		// Interpolation m_interpolation = LINEAR;
		// Easing m_easing;
	};

	export_ class TOY_CORE_EXPORT Animator
	{
	public:
		Animator();

		void next_frame(size_t tick, size_t delta);
		void animate(Ref object, Member& member, const Var& value, float duration);

		Clock m_clock;
		vector<Anim> m_animations;

		static Animator me;
	};

	inline void animate(Ref object, Member& member, const Var& value, float duration)
	{
		Animator::me.animate(object, member, value, duration);
	}
}
