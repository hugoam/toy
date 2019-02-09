#ifndef USE_STL
#ifdef MUD_MODULES
module toy.block;
#else
#include <stl/vector.hpp>
#include <shell/Api.h>
#endif

namespace stl
{
	using namespace toy;
	template class TOY_SHELL_EXPORT vector<unique<GameScene>>;
}
#endif
