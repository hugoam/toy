#include <toy/core.refl.h>
#include <two/ui.refl.h>
#include <toy/visu.refl.h>
#include <two/type.refl.h>
#include <toy/edit.h>
#include <two/refl.h>
#include <two/tool.refl.h>
#include <toy/util.refl.h>
#include <toy/edit.refl.h>
#include <two/infra.h>
#include <two/type.h>


#ifdef TWO_MODULES
module toy.edit;
#else
#include <cstddef>
#include <stl/new.h>
#endif


using namespace two;

void toy_ActionGroup__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) toy::ActionGroup(  ); }
void toy_ActionGroup__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) toy::ActionGroup((*static_cast<toy::ActionGroup*>(other))); }
void toy_GraphicsDebug__construct_0(void* ref, span<void*> args) { UNUSED(args); new(stl::placeholder(), ref) toy::GraphicsDebug(  ); }
void toy_GraphicsDebug__copy_construct(void* ref, void* other) { new(stl::placeholder(), ref) toy::GraphicsDebug((*static_cast<toy::GraphicsDebug*>(other))); }

namespace two
{
	void toy_edit_meta(Module& m)
	{
	UNUSED(m);
	
	// Base Types
	
	// Enums
	
	// Sequences
	
	// toy::Edit
	{
		Type& t = type<toy::Edit>();
		static Meta meta = { t, &namspc({ "toy" }), "Edit", sizeof(toy::Edit), TypeClass::Object };
		// bases
		// defaults
		// constructors
		// copy constructor
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, {}, {}, {}, {}, {}, };
	}
	// toy::Clone
	{
		Type& t = type<toy::Clone>();
		static Meta meta = { t, &namspc({ "toy" }), "Clone", sizeof(toy::Clone), TypeClass::Object };
		// bases
		// defaults
		// constructors
		// copy constructor
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, {}, {}, {}, {}, {}, };
	}
	// toy::Cut
	{
		Type& t = type<toy::Cut>();
		static Meta meta = { t, &namspc({ "toy" }), "Cut", sizeof(toy::Cut), TypeClass::Object };
		// bases
		// defaults
		// constructors
		// copy constructor
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, {}, {}, {}, {}, {}, };
	}
	// toy::Paste
	{
		Type& t = type<toy::Paste>();
		static Meta meta = { t, &namspc({ "toy" }), "Paste", sizeof(toy::Paste), TypeClass::Object };
		// bases
		// defaults
		// constructors
		// copy constructor
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, {}, {}, {}, {}, {}, };
	}
	// toy::Toolbox
	{
		Type& t = type<toy::Toolbox>();
		static Meta meta = { t, &namspc({ "toy" }), "Toolbox", sizeof(toy::Toolbox), TypeClass::Object };
		// bases
		// defaults
		// constructors
		// copy constructor
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, {}, {}, {}, {}, {}, };
	}
	// toy::DynamicToolbox
	{
		Type& t = type<toy::DynamicToolbox>();
		static Meta meta = { t, &namspc({ "toy" }), "DynamicToolbox", sizeof(toy::DynamicToolbox), TypeClass::Object };
		// bases
		static Type* bases[] = { &type<toy::Toolbox>() };
		static size_t bases_offsets[] = { base_offset<toy::DynamicToolbox, toy::Toolbox>() };
		// defaults
		// constructors
		// copy constructor
		// members
		// methods
		// static members
		static Class cls = { t, bases, bases_offsets, {}, {}, {}, {}, {}, };
	}
	// toy::Toolbelt
	{
		Type& t = type<toy::Toolbelt>();
		static Meta meta = { t, &namspc({ "toy" }), "Toolbelt", sizeof(toy::Toolbelt), TypeClass::Object };
		// bases
		// defaults
		// constructors
		// copy constructor
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, {}, {}, {}, {}, {}, };
	}
	// toy::PlayTool
	{
		Type& t = type<toy::PlayTool>();
		static Meta meta = { t, &namspc({ "toy" }), "PlayTool", sizeof(toy::PlayTool), TypeClass::Object };
		// bases
		static Type* bases[] = { &type<two::Tool>() };
		static size_t bases_offsets[] = { base_offset<toy::PlayTool, two::Tool>() };
		// defaults
		// constructors
		// copy constructor
		// members
		// methods
		// static members
		static Class cls = { t, bases, bases_offsets, {}, {}, {}, {}, {}, };
	}
	// toy::RunTool
	{
		Type& t = type<toy::RunTool>();
		static Meta meta = { t, &namspc({ "toy" }), "RunTool", sizeof(toy::RunTool), TypeClass::Object };
		// bases
		static Type* bases[] = { &type<two::Tool>() };
		static size_t bases_offsets[] = { base_offset<toy::RunTool, two::Tool>() };
		// defaults
		// constructors
		// copy constructor
		// members
		// methods
		// static members
		static Class cls = { t, bases, bases_offsets, {}, {}, {}, {}, {}, };
	}
	// toy::ActionGroup
	{
		Type& t = type<toy::ActionGroup>();
		static Meta meta = { t, &namspc({ "toy" }), "ActionGroup", sizeof(toy::ActionGroup), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, toy_ActionGroup__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, toy_ActionGroup__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
	}
	// toy::GraphicsDebug
	{
		Type& t = type<toy::GraphicsDebug>();
		static Meta meta = { t, &namspc({ "toy" }), "GraphicsDebug", sizeof(toy::GraphicsDebug), TypeClass::Struct };
		// bases
		// defaults
		// constructors
		static Constructor constructors[] = {
			{ t, toy_GraphicsDebug__construct_0, {} }
		};
		// copy constructor
		static CopyConstructor copy_constructor[] = {
			{ t, toy_GraphicsDebug__copy_construct }
		};
		// members
		// methods
		// static members
		static Class cls = { t, {}, {}, constructors, copy_constructor, {}, {}, {}, };
	}
	// toy::Editor
	{
		Type& t = type<toy::Editor>();
		static Meta meta = { t, &namspc({ "toy" }), "Editor", sizeof(toy::Editor), TypeClass::Object };
		// bases
		static Type* bases[] = { &type<two::EditContext>() };
		static size_t bases_offsets[] = { base_offset<toy::Editor, two::EditContext>() };
		// defaults
		static toy::World* edited_world_default = nullptr;
		static bool run_game_default = false;
		static bool play_game_default = false;
		// constructors
		// copy constructor
		// members
		static Member members[] = {
			{ t, offsetof(toy::Editor, m_run_tool), type<toy::RunTool>(), "run_tool", nullptr, Member::NonMutable, nullptr },
			{ t, offsetof(toy::Editor, m_play_tool), type<toy::PlayTool>(), "play_tool", nullptr, Member::NonMutable, nullptr },
			{ t, offsetof(toy::Editor, m_frame_view_tool), type<two::FrameViewTool>(), "frame_view_tool", nullptr, Member::NonMutable, nullptr },
			{ t, offsetof(toy::Editor, m_edited_world), type<toy::World>(), "edited_world", edited_world_default, Member::Flags(Member::Pointer|Member::Link), nullptr },
			{ t, offsetof(toy::Editor, m_run_game), type<bool>(), "run_game", &run_game_default, Member::Value, nullptr },
			{ t, offsetof(toy::Editor, m_play_game), type<bool>(), "play_game", &play_game_default, Member::Value, nullptr }
		};
		// methods
		// static members
		static Class cls = { t, bases, bases_offsets, {}, {}, members, {}, {}, };
	}
	
	{
		Type& t = type<stl::vector<two::Ref>>();
		static Alias alias = { &t, &namspc({ "toy" }), "Selection" };
		m.m_aliases.push_back(&alias);
	}
	
		m.m_types.push_back(&type<toy::Edit>());
		m.m_types.push_back(&type<toy::Clone>());
		m.m_types.push_back(&type<toy::Cut>());
		m.m_types.push_back(&type<toy::Paste>());
		m.m_types.push_back(&type<toy::Selection>());
		m.m_types.push_back(&type<toy::Toolbox>());
		m.m_types.push_back(&type<toy::DynamicToolbox>());
		m.m_types.push_back(&type<toy::Toolbelt>());
		m.m_types.push_back(&type<toy::PlayTool>());
		m.m_types.push_back(&type<toy::RunTool>());
		m.m_types.push_back(&type<toy::ActionGroup>());
		m.m_types.push_back(&type<toy::GraphicsDebug>());
		m.m_types.push_back(&type<toy::Editor>());
	}
}

namespace toy
{
	toy_edit::toy_edit()
		: Module("toy::edit", { &two_type::m(), &two_ui::m(), &two_tool::m(), &toy_util::m(), &toy_core::m(), &toy_visu::m() })
	{
		// setup reflection meta data
		toy_edit_meta(*this);
	}
}

#ifdef TOY_EDIT_MODULE
extern "C"
Module& getModule()
{
	return toy_edit::m();
}
#endif
