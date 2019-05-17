//  Copyright (c) 2019 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#include <core/Symbolic/Symbolic.h>

#include <core/Entity/Entity.h>
#include <math/Colour.h>

using namespace two; namespace toy
{
	Symbolic::Symbolic(Entity& entity, vector<Symbol> shapes)
		: m_entity(entity)
		, m_symbols(shapes)
		, m_updated(0)
	{}

	void Symbolic::clearSymbols()
	{
		m_symbols.clear();
		m_updated++;
	}

	void Symbolic::addSymbol(const Symbol& symbol)
	{
		m_symbols.emplace_back(symbol);
		m_updated++;
	}
}
