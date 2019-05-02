//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <proto/Entity.h>
#include <proto/Proto.h>
#include <math/Stat.h>
#include <math/Colour.h>
#include <core/Forward.h>
#include <core/Physic/Scope.h>
#include <core/Entity/EntityObserver.h>

using namespace two; namespace toy
{
	//class TOY_CORE_EXPORT VisualEmitter object_ptr<LightReflector> m_lreflector;

	class refl_ TOY_CORE_EXPORT LightReflector
	{
	public:
#ifdef TOY_ECS
		LightReflector();
#endif
		LightReflector(HSpatial spatial, HReceptor receptor);

		attr_ HSpatial m_spatial;
		attr_ Ratio m_brightness;

		void handle_moved();

	protected:
		HReceptorScope m_sphere;
	};

#ifdef TOY_ECS
}

namespace two
{
	template <> struct TypedBuffer<toy::LightReflector> { using type = ComponentBufferDense<toy::LightReflector>; static size_t index() { return 0; } };
}

namespace toy
{
	using HLightReflector = ComponentHandle<LightReflector>;
	using CLightReflector = Component<LightReflector>;
#else
	using HLightReflector = LightReflector&;
	using CLightReflector = LightReflector;
#endif

	class refl_ TOY_CORE_EXPORT LightSource : public StoreObserver<Spatial>
	{
	public:
#ifdef TOY_ECS
		constr_ LightSource();
#endif
		constr_ LightSource(HSpatial spatial, HEmitter emitter, float range, float intensity, Colour colour, bool shadows);

		attr_ HSpatial m_spatial;
		attr_ HEmitter m_emitter;
		attr_ float m_range;
		attr_ float m_intensity;
		attr_ Colour m_colour;
		attr_ bool m_shadows;

		virtual void handle_add(Spatial& contact);
		virtual void handle_remove(Spatial& contact);

		void moved(LightReflector& reflector);

		void handle_moved();

	private:
		float computeIntensity(float distance);

	private:
		HEmitterScope m_sphere;
	};

#ifdef TOY_ECS
}

namespace two
{
	template <> struct TypedBuffer<toy::LightSource> { using type = ComponentBufferDense<toy::LightSource>; static size_t index() { return 0; } };
}

namespace toy
{
	using HLightSource = ComponentHandle<LightSource>;
	using CLightSource = Component<LightSource>;
#else
	using HLightSource = LightSource&;
	using CLightSource = LightSource;
#endif

	class refl_ TOY_CORE_EXPORT OLight : public Entity
	{
	public:
		constr_ OLight(Id id, Spatial& parent, const vec3& position, float range = 10.f, float intensity = 1.f, Colour colour = Colour::White, bool shadows = false);

		comp_ attr_ CSpatial m_spatial;
		comp_ attr_ CEmitter m_emitter;
		comp_ attr_ CLightSource m_light;
	};
}
