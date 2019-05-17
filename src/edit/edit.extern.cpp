#ifndef USE_STL
#ifdef TWO_MODULES
module toy.edit;
#else
#include <stl/vector.hpp>
#include <stl/unordered_map.hpp>
#include <edit/Api.h>
#endif

namespace stl
{
	using namespace toy;
	template class TOY_EDIT_EXPORT vector<Tool*>;
	template class TOY_EDIT_EXPORT unordered_map<string, function<void()>>;
	template class TOY_EDIT_EXPORT unordered_map<string, ActionGroup>;
	template class TOY_EDIT_EXPORT unordered_map<string, unique<Toolbox>>;
	template class TOY_EDIT_EXPORT unordered_map<Key, vec3>;
}
#endif
