#ifndef USE_STL
#ifdef TWO_MODULES
module toy.visu;
#else
#include <stl/vector.hpp>
#include <stl/unordered_map.hpp>
#include <visu/Api.h>
#endif

namespace stl
{
	using namespace toy;
	template class TOY_VISU_EXPORT vector<Gnode*>;
	template class TOY_VISU_EXPORT vector<vector<Gnode*>>;
	template class TOY_VISU_EXPORT vector<unique<VisuPainter>>;
}
#endif
