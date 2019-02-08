//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#if 0
#pragma once

#include <stl/map.h>
#include <visu/Forward.h>

#ifdef TOY_SOUND
#include <snd/Forward.h>
#endif

namespace toy
{
	class refl_ TOY_VISU_EXPORT SoundSource : public StoreObserver<State>
	{
	public:
#ifdef TOY_SOUND
		SoundSource(HSpatial spatial, SoundManager& soundManager);
#else
		SoundSource(HSpatial spatial);
#endif

		attr_ HSpatial m_spatial;

#ifdef TOY_SOUND
		void soundDestroyed(Sound& sound);
#endif

		void handle_add(State& effect);
		void handle_remove(State& effect);

	private:
		Active& m_active;

#ifdef TOY_SOUND
		SoundManager& m_soundManager;
		map<State*, Sound*> m_sounds;
#endif

		size_t m_updated;
	};
}
#endif
