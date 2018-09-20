//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is licensed  under the terms of the GNU General Public License v3.0.
//  See the attached LICENSE.txt file or https://www.gnu.org/licenses/gpl-3.0.en.html.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#include <gfx-ui/Forward.h>
#include <edit/Forward.h>
#include <uio/Unode.h>

#ifndef MUD_CPP_20
#include <vector>
#endif

using namespace mud; namespace toy
{
	using Selection = std::vector<Ref>;

	//TOY_EDIT_EXPORT void context_menu(Widget& parent, Selector& selector, Ref object);

	TOY_EDIT_EXPORT void edit_toolbox(Widget& parent, Toolbox& toolbox);
	TOY_EDIT_EXPORT void edit_toolbelt(Widget& parent, Toolbelt& toolbelt);

	TOY_EDIT_EXPORT void edit_selection(Widget& parent, Selection& selection);
	//TOY_EDIT_EXPORT void edit_selector(Widget& parent, Selector& selector);

	TOY_EDIT_EXPORT void scene_edit(Widget& parent, World& world);

	TOY_EDIT_EXPORT void registry(Widget& parent, Indexer& indexer, Selection& selection);
	TOY_EDIT_EXPORT void registry_section(Widget& parent, Indexer& indexer, Selection& selection);
	TOY_EDIT_EXPORT void library(Widget& parent, const std::vector<Type*>& types, Selection& selection);
	TOY_EDIT_EXPORT void library_section(Widget& parent, const std::vector<Type*>& types, Selection& selection);

	TOY_EDIT_EXPORT void editor_menu(Widget& parent, ActionGroup& action_group);
	TOY_EDIT_EXPORT void editor_menu_bar(Widget& parent, Editor& editor);
	TOY_EDIT_EXPORT void editor_graph(Widget& parent, Editor& editor, Selection& selection);

	TOY_EDIT_EXPORT void editor_components(Widget& parent, Editor& editor);

	TOY_EDIT_EXPORT void editor(Widget& parent, Editor& editor, Widget*& screen);
	TOY_EDIT_EXPORT void mini_editor(Widget& parent, Editor& editor, Widget*& screen);

	TOY_EDIT_EXPORT Widget& editor_viewer_overlay(Viewer& viewer, Editor& editor);
}
