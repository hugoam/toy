#ifndef USE_STL
#ifdef TWO_MODULES
module toy.block;
#else
#include <stl/vector.hpp>
#include <stl/unordered_map.hpp>
#include <block/Api.h>
#include <math/Grid.hpp>
#include <geom/Shapes.h>
#include <gfx/Model.h>
#endif

namespace two
{
	template class TOY_BLOCK_EXPORT vector2d<toy::Block*>;
}

namespace stl
{
	using namespace toy;
	template class TOY_BLOCK_EXPORT vector<Quad>;
	template class TOY_BLOCK_EXPORT vector<Cube>;
	template class TOY_BLOCK_EXPORT vector<Chunk>;
	template class TOY_BLOCK_EXPORT vector<Heap>;
	template class TOY_BLOCK_EXPORT vector<Block>;
	template class TOY_BLOCK_EXPORT vector<Sector>;
	template class TOY_BLOCK_EXPORT vector<Tileblock>;
	template class TOY_BLOCK_EXPORT vector<HBlock>;
	template class TOY_BLOCK_EXPORT vector<Element*>;
	template class TOY_BLOCK_EXPORT vector<Heap*>;
	template class TOY_BLOCK_EXPORT vector<Block*>;
	template class TOY_BLOCK_EXPORT vector<Sector*>;
	template class TOY_BLOCK_EXPORT unordered_map<Element*, vector<ProcShape>>;
	template class TOY_BLOCK_EXPORT unordered_map<Element*, unique<Model>>;
}
#endif
