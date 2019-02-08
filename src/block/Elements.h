//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <block/Forward.h>
#include <block/Element.h>

namespace toy
{
	class refl_ TOY_BLOCK_EXPORT Earth : public Element
	{
	public:
		constr_ Earth() : Element("earth", MatterState::Solid, Colour(0.4f, 0.3f, 0.3f)) {}
		attr_ static Earth me;
	};

	class TOY_BLOCK_EXPORT Stone : public Element
	{
	public:
		constr_ Stone() : Element("stone", MatterState::Solid, Colour(0.6f, 0.6f, 0.65f)) {}
		attr_ static Stone me;
	};

	class TOY_BLOCK_EXPORT Sand : public Element
	{
	public:
		Sand() : Element("sand", MatterState::Solid, Colour(0.55f, 0.5f, 0.2f)) {}
		attr_ static Sand me;
	};

	class TOY_BLOCK_EXPORT Air : public Element
	{
	public:
		Air() : Element("air", MatterState::Gas, Colour(1.f, 1.f, 1.f)) {}
		attr_ static Air me;
	};

	class TOY_BLOCK_EXPORT Gas : public Element
	{
	public:
		Gas() : Element("gas", MatterState::Gas, Colour(1.f, 0.1f, 0.f)) {}
		attr_ static Gas me;
	};

	class TOY_BLOCK_EXPORT Minerals : public Element
	{
	public:
		Minerals() : Element("minerals", MatterState::Solid, Colour(0.1f, 0.2f, 1.f)) {}
		attr_ static Minerals me;
	};

	class TOY_BLOCK_EXPORT Fungus : public Element
	{
	public:
		Fungus() : Element("mushrooms", MatterState::Solid, Colour(0.f, 1.f, 0.1f)) {}
		attr_ static Fungus me;
	};

	class TOY_BLOCK_EXPORT Water : public Element
	{
	public:
		Water() : Element("water", MatterState::Liquid, Colour(0.f, 0.3f, 1.f)) {}
		attr_ static Water me;
	};
}
