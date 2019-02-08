//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#if 0
#include <visu/Sound/SoundSource.h>

#include <core/Spatial/Spatial.h>
//#include <core/Active/Effect.h>
//#include <core/Active/Active.h>

#ifdef TOY_SOUND
#include <snd/SoundManager.h>
#include <snd/Sound.h>
#endif

namespace toy
{
#ifdef TOY_SOUND
	SoundSource::SoundSource(HSpatial spatial, SoundManager& soundManager)
#else
	SoundSource::SoundSource(HSpatial spatial)
#endif
		: m_spatial(spatial)
		, m_active(entity.as<Active>())
#ifdef TOY_SOUND
		, m_soundManager(soundManager)
#endif
	{
		//m_spatial.addTransformObserver(*this);

		//m_active.effects().observe(*this);
		//m_active.states().observe(*this);
	}

#ifdef TOY_SOUND
	void SoundSource::soundDestroyed(Sound& sound)
	{
		for(auto kv : m_sounds)
			if(kv.second == &sound)
			{
				m_sounds.erase(kv.first);
				break;
			}
	}
#endif

	/*void SoundSource::transformUpdated(Spatial& spatial, const vec3& pos, const quat& rot, size_t tick, bool key)
	{
		for(auto& kv : m_sounds)
		{
			kv.second->set_position(entity.absolute_position());
			kv.second->setDirection(entity.front());
		}
	}*/

	void SoundSource::handle_add(State& effect)
	{
#ifdef TOY_SOUND
		Sound* sound = m_soundManager.createSound(("../data/sounds/" + effect.m_name + ".ogg").c_str(), true/*effect.loop()*/, false, [=](Sound& sound) { this->soundDestroyed(sound); });
		if(sound)
		{
			sound->play();
			sound->enable_3D();
			m_sounds[&effect] = sound;
		}
#else
		UNUSED(effect);
#endif
	}

	void SoundSource::handle_remove(State& effect)
	{
#ifdef TOY_SOUND
		if(m_sounds.find(&effect) != m_sounds.end())
		{
			Sound* sound = m_sounds[&effect];
			sound->stop();
			m_sounds.erase(&effect);
		}
#else
		UNUSED(effect);
#endif
	}
}
#endif
