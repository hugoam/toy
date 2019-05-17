#ifndef USE_STL
#ifdef TWO_MODULES
module toy.core;
#else
#include <stl/vector.hpp>
#include <stl/unordered_map.hpp>
#include <core/Api.h>
#endif

namespace stl
{
	using namespace toy;
	template class TOY_CORE_EXPORT vector<JobPump::Entry>;
	template class TOY_CORE_EXPORT vector<Spatial>;
	template class TOY_CORE_EXPORT vector<Movable>;
	template class TOY_CORE_EXPORT vector<Camera>;
	template class TOY_CORE_EXPORT vector<WorldPage>;
	template class TOY_CORE_EXPORT vector<Navblock>;
	template class TOY_CORE_EXPORT vector<Origin>;
	template class TOY_CORE_EXPORT vector<HSpatial>;
	template class TOY_CORE_EXPORT vector<OSolid>;
	template class TOY_CORE_EXPORT vector<Signal>;
	template class TOY_CORE_EXPORT vector<Collider>;
	template class TOY_CORE_EXPORT vector<Solid>;
	template class TOY_CORE_EXPORT vector<Obstacle*>;
	template class TOY_CORE_EXPORT vector<unique<EmitterScope>>;
	template class TOY_CORE_EXPORT vector<unique<ReceptorScope>>;
	template class TOY_CORE_EXPORT vector<unique<HandlePool>>;
	template class TOY_CORE_EXPORT vector<Waypoint>;
	template class TOY_CORE_EXPORT vector<Anim>;
	template class TOY_CORE_EXPORT vector<Observer*>;
	template class TOY_CORE_EXPORT vector<Collision>;
	template class TOY_CORE_EXPORT vector<BulletMedium::Contact*>;
	//template class TOY_CORE_EXPORT vector<ContactCheck::Contact>;
	template class TOY_CORE_EXPORT unordered_map<CollisionGroup, short>;
	template class TOY_CORE_EXPORT unordered_map<Medium*, unique<PhysicMedium>>;
	template class TOY_CORE_EXPORT unordered_map<uint64_t, BulletMedium::Contact>;
}
#endif
