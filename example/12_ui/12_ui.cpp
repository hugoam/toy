
#include <12_ui/12_ui.h>

#include <toy/toy.h>

#include <01_shapes/01_shapes.h>
#include <03_materials/03_materials.h>

#define UI_SCRIPT_EXAMPLE

struct Item
{
	string m_name;
	string m_description;
};

struct Trait
{
	string m_name;
	uint8_t m_value;
};

struct Skill
{
	string m_name;
	uint8_t m_level;
};

struct Inventory
{
	void add_item(Item item, size_t slot) { m_items.push_back(item); m_slots[slot] = &m_items.back(); }
	std::vector<Item> m_items;
	std::vector<Item*> m_slots;
};

struct Character
{
	string m_name;
	std::vector<Trait> m_traits;
	std::vector<Skill> m_skills;
	Inventory m_inventory;
};

struct GameStyles
{
	Style character_sheet = { "CharacterSheet", mud::styles().sheet, Args{} };
	Style inventory_sheet = { "InventorySheet", mud::styles().sheet, Args{} };
	Style inventory_slot = { "InventorySlot", mud::styles().item, Args{ { &Layout::m_size, vec2{ 40.f, 40.f } }, { &InkStyle::m_empty, false }, { &InkStyle::m_border_width, 1.f }, { &InkStyle::m_border_colour, Colour::AlphaGrey } } };
};

GameStyles& game_styles() { static GameStyles styles; return styles; }

void character_sheet(Widget& parent, Character& character)
{
	Widget& modal = ui::modal(parent);
	//Widget& sheet = ui::sheet(modal);
	Widget& sheet = ui::widget(modal, game_styles().character_sheet);

	Widget& skills = ui::stack(sheet);
	ui::label(skills, "Skills");
	for(Skill& skill : character.m_skills)
	{
		Widget& row = ui::row(skills);
		ui::label(row, skill.m_name);
		ui::label(row, to_string(skill.m_level));
	}

	Widget& traits = ui::stack(sheet);
	ui::label(traits, "Traits");
	for(Trait& trait : character.m_traits)
	{
		Widget& row = ui::row(traits);
		ui::label(row, trait.m_name);
		ui::label(row, to_string(trait.m_value));
	}

	if(!modal.m_open)
		parent.close();
}

void inventory_sheet(Widget& parent, Inventory& inventory)
{
	Widget& modal = ui::modal(parent);
	//Widget& sheet = ui::sheet(modal);
	Widget& sheet = ui::widget(modal, game_styles().inventory_sheet);
	ui::label(sheet, "Inventory");

	//for(Item* slot : inventory.m_slots)
	for(size_t y = 0; y < 2; ++y)
	{
		Widget& row = ui::row(sheet);

		for(size_t x = 0; x < 10; ++x)
		{
			Item* slot = inventory.m_slots[x + y * 10];

			Widget& slot_widget = ui::item(row, game_styles().inventory_slot, "(inventory_slot)");
			if(slot)
				ui::icon(slot_widget, "(" + slot->m_name + ")");
		}
	}

	if(!modal.m_open)
		parent.close();
}

Character create_character()
{
	std::vector<Trait> traits = { { "Force", 7 }, { "Agility", 10 }, { "Charisma", 3 }, { "Blood", 100 } };
	std::vector<Skill> skills = { { "Hacking", 1 }, { "Firearms", 2 } };
	Character character = { "Marc Citrus", traits, skills,{} };
	character.m_inventory.m_slots.resize(20);
	character.m_inventory.m_items.reserve(20);
	character.m_inventory.add_item({ "Gun" }, 1);
	character.m_inventory.add_item({ "Bandages" }, 4);
	return character;
}

void edit_styles(Widget& parent)
{
	static std::vector<Style*> styles = { &game::game_styles().character_sheet, &game::game_styles().inventory_sheet, &game::game_styles().inventory_slot };
	static std::vector<string> style_names = { "Character Sheet", "Inventory Sheet", "Inventory Slot" };

	Widget& layout = ui::layout_span(parent, 0.3f);
	ScrollSheet& scroll_sheet = ui::scroll_sheet(layout);
	Widget& self = ui::sheet(*scroll_sheet.m_body);

	static size_t selected_style = 0;
	ui::dropdown_input(self, style_names, selected_style);

	Style* edited_style = styles[selected_style];
	object_edit(parent, &edited_style->m_layout);
	object_edit(parent, &edited_style->m_skin);
}

enum InteractModes
{
	CONTEXT_MENU = 1 << 0,
	CHARACTER_SHEET = 1 << 1,
	INVENTORY_SHEET = 1 << 2

};

void ex_12_ui_pump(Shell& shell, Game& game)
{
	Widget& uroot = shell.m_ui->begin();
	Widget& umain = ui::board(uroot);

	SceneViewer& viewer = ui::scene_viewer(umain);
	ui::orbit_controller(viewer);

	edit_styles(umain);

	Gnode& groot = viewer.m_scene->begin();

	Material& material = milky_white(viewer.m_gfx_system);

	gfx::directional_light_node(groot);
	gfx::radiance(groot, "radiance/spherical_snow.jpg", BackgroundMode::None);

	gfx::shape(groot, Cube(), Symbol(Colour::None, Colour::White), ITEM_SELECTABLE, &material);

	static game::Character character = game::create_character();

	static Item* selected = nullptr;
	if(MouseEvent mouse_event = viewer.mouse_event(DeviceType::MouseRight, EventType::Stroked))
	{
		auto callback = [&](Item* item) { selected = item; umain.m_switch |= CONTEXT_MENU; };
		viewer.pick_point(mouse_event.m_relative, callback, ITEM_SELECTABLE);
	}

	if((umain.m_switch & CONTEXT_MENU) != 0)
	{
		Widget& popup = ui::popup(viewer, true);
		if(ui::button(popup, "character").activated())
			umain.m_switch |= CHARACTER_SHEET;
		if(ui::button(popup, "inventory").activated())
			umain.m_switch |= INVENTORY_SHEET;
		if((umain.m_switch & CHARACTER_SHEET) != 0
		|| (umain.m_switch & INVENTORY_SHEET) != 0
		||	!popup.m_open)
			umain.m_switch &= ~(CONTEXT_MENU);
	}

	if((umain.m_switch & CHARACTER_SHEET) != 0)
		game::character_sheet(umain, character);

	if((umain.m_switch & INVENTORY_SHEET) != 0)
		game::inventory_sheet(umain, character.m_inventory);
}

void ex_12_ui_start(Shell& shell, Game& game)
{
	game.m_world = &GlobalPool::me().pool<DefaultWorld>().construct("Arcadia").m_world;
}


