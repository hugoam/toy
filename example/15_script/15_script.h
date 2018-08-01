//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is provided 'as-is' under the zlib License, see the LICENSE.txt file.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <15_script/Forward.h>
#include <shell/Shell.h>

struct ShapeInstance;

class _refl_ GameObject : public IdObject
{
public:
	GameObject(const ShapeInstance* shape, Material* material, Colour colour);
	/*_attr_ */const ShapeInstance* m_shape;
	_attr_ _mut_ Colour m_colour;
	Material* m_material;
};
