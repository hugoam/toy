//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.


#include <core/Types.h>
#include <core/Light/Light.h>

#include <core/World/World.h>
#include <core/Entity/Entity.h>
//#include <core/Event/EventRelay.h>

#include <core/Physic/Collider.h>
#include <core/Physic/CollisionShape.h>

#include <core/Medium/VisualMedium.h>

#include <math/Colour.h>

using namespace two; namespace toy
{
	LightReflector::LightReflector(HSpatial spatial, HReceptor receptor)
		: m_spatial(spatial)
		, m_brightness(0.f)
		, m_sphere(((Receptor&)receptor).add_sphere(VisualMedium::me, 0.1f, CM_LIGHTREFLECTOR))
	{
		//entity.add_part(type<LightReflector>(), this);
	}

	void LightReflector::handle_moved()
	{
		ReceptorScope& scope = m_sphere;
		for(Spatial* entity : scope.m_scope.store())
			entity->as<LightSource>().moved(*this);

		//printf("VisualEmitter::updated, m_brightness = " << m_brightness.getValue() << std::endl;
	}

    LightSource::LightSource(HSpatial spatial, HEmitter emitter, float range, float intensity, Colour colour, bool shadows)
        : m_spatial(spatial)
		, m_emitter(emitter)
		, m_range(range)
		, m_intensity(intensity)
		, m_colour(std::move(colour))
		, m_shadows(shadows)
		, m_sphere(((Emitter&)emitter).add_sphere(VisualMedium::me, range, CM_LIGHT))
    {
		m_sphere->m_scope.observe(*this);
	}

	float LightSource::computeIntensity(float distance)
	{
		return (1.f - (distance / m_range)) * m_intensity; // @todo : falloff
	}

	void LightSource::moved(LightReflector& reflector)
	{
		UNUSED(reflector);
		//vec3 pos = reflector.m_spatial.absolute_position();
		//float value = computeIntensity(distance(pos, m_spatial.absolute_position()));
		//reflector.m_brightness.updateModifier(this, value);
	}

	void LightSource::handle_moved()
	{
		EmitterScope& scope = m_sphere;
		for(Spatial* entity : scope.m_scope.store())
			this->moved(entity->as<LightReflector>());
	}

	void LightSource::handle_add(Spatial& contact)
	{
		UNUSED(contact);
		//LightReflector& reflector = contact.as<LightReflector>();
		//float value = computeIntensity(0.f);
		//reflector.brightness().setModifier(this, value);
	}

	void LightSource::handle_remove(Spatial& contact)
	{
		UNUSED(contact);
		//LightReflector& reflector = contact.as<LightReflector>();
		//reflector.brightness().removeModifier(this);
	}

	OLight::OLight(Id id, Spatial& parent, const vec3& position, float range, float intensity, Colour colour, bool shadows)
#ifdef TOY_ECS
		: m_spatial(*this, id, *this, parent, position, ZeroQuat)
		, m_emitter(*this, m_spatial)
		, m_light(*this, m_spatial, m_emitter, range, intensity, colour, shadows)
#else
		: Entity(id, type<OLight>(), m_emitter, m_light)
		, m_spatial(id, *this, parent, position, ZeroQuat)
		, m_emitter(m_spatial)
		, m_light(m_spatial, m_emitter, range, intensity, colour, shadows)
#endif
	{}
}
