//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is provided 'as-is' under the zlib License, see the LICENSE.txt file.
//  This notice and the license may not be removed or altered from any source distribution.


#include <space/Types.h>
#include <space/Ui.h>
#include <space/Scene.h>

#include <meta/math/Convert.h>
#include <meta/space/Convert.h>

#include <toy/toy.h>

#include <space/ex_space.h>

#define CAMERA_ROTATION_SPEED 0.03f

void label_entry(Widget& parent, cstring name, cstring value)
{
	Widget& row = ui::table_row(parent); ui::label(row, name); ui::label(row, value);
}

template <class T>
void number_entry(Widget& parent, cstring name, T value)
{
	Widget& row = ui::table_row(parent); ui::label(row, name); ui::label(row, truncate_number(to_string(value)).c_str());
}

void commander_emblem(Widget& parent, Commander& commander, cstring title = nullptr)
{
	Widget& row = ui::row(parent);
	ui::image256(row, commander.m_name.c_str(), commander.m_avatar, vec2(50.f));
	Widget& stack = ui::stack(row);
	if(title)
		ui::title(stack, title);
	ui::title(stack, ("Commander " + commander.m_name).c_str());
}

static Colour light_grey = Colour::DarkGrey;
static Colour dark_grey = Colour(0.07f, 0.07f, 0.07f, 0.5f);

Style& panel_style()
{
	static Style style("SpacePanel", styles().wedge, [](Layout& l) { l.m_space = { PARAGRAPH, SHRINK, WRAP }; l.m_align = { CENTER, CENTER }; l.m_padding = vec4(15.f); l.m_spacing = vec2(10.f); },
													 [](InkStyle& s) { s.m_empty = false; s.m_background_colour = dark_grey; s.m_border_colour = light_grey; s.m_border_width = vec4(1.f); });
	return style;
}

Style& sheet_style()
{
	static Style style("SpaceSheet", styles().wedge, [](Layout& l) { l.m_space = { PARAGRAPH, WRAP, WRAP }; l.m_align = { CENTER, CENTER }; l.m_spacing = vec2(40.f); });
	return style;
}

Style& orders_panel_style()
{
	static Style style("OrdersPanel", styles().wedge, [](Layout& l) { l.m_space = { PARAGRAPH, SHRINK, WRAP }; l.m_align = { CENTER, Right }; l.m_padding = vec4(15.f); l.m_spacing = vec2(10.f); },
													  [](InkStyle& s) { s.m_empty = false; s.m_background_colour = dark_grey; s.m_border_colour = light_grey; s.m_border_width = vec4(1.f); });
	return style;
}

Style& order_label_style()
{
	static Style style("OrderLabel", styles().label, [](Layout& l) { l.m_align = { CENTER, CENTER }; }, [](InkStyle& s) { s.m_empty = false; s.m_text_colour = Colour::Red; s.m_text_size = 18.f; });
	return style;
}

static Colour active_blue = { 0.145f, 0.5f, 1.f, 1.f };

Style& order_button_style()
{
	static Style style("OrderButton", styles().button, [](Layout& l) { l.m_space = BLOCK; l.m_align = { CENTER, CENTER }; }, 
													   [](InkStyle& s) { s.m_empty = false; s.m_text_colour = Colour::White; s.m_text_size = 18.f; s.m_padding = vec4(8.f); s.m_border_width = vec4(1.f); s.m_border_colour = light_grey; },
													   [](Style& s) { s.decline_skin(HOVERED).m_background_colour = active_blue; });
	return style;
}

Style& event_style()
{
	static Style style("EventLabel", styles().label, {}, [](InkStyle& s) { s.m_empty = false; s.m_text_colour = Colour::Red; });
	return style;
}

bool select_parsec(Widget& parent, Viewer& viewer, Galaxy& galaxy, uvec2& hover, uvec2& value, const uvec2& center, uint range)
{
	//UNUSED(parent);
	//Widget& screen = ui::overlay(viewer);
	Widget& screen = ui::overlay(parent);

	uvec2 lo = center - min(uvec2(range), center);
	uvec2 hi = center + range;
	auto check_parsec = [&](const uvec2& coord) { return intersects(coord, lo, hi); };

	if(MouseEvent mouse_event = screen.mouse_event(DeviceType::Mouse, EventType::Moved))
	{
		uvec2 coord = galaxy.intersect_coord(viewer.mouse_ray());
		if(check_parsec(coord))
			hover = coord;
	}

	if(MouseEvent mouse_event = screen.mouse_event(DeviceType::MouseLeft, EventType::Stroked))
	{
		uvec2 coord = galaxy.intersect_coord(viewer.mouse_ray());
		if(check_parsec(coord))
		{
			value = galaxy.intersect_coord(viewer.mouse_ray());
			return true;
		}
	}

	return false;
}

struct JumpQuery : public NodeState
{
	JumpQuery() {}
	size_t m_step = 0;
	uvec2 m_hover = uvec2(UINT_MAX);
	uvec2 m_coord = uvec2(UINT_MAX);
	FleetStance m_stance = FleetStance::Movement;
};

struct SplitQuery : public NodeState
{
	SplitQuery() {}
	std::string m_name;
	std::map<ShipSchema*, uint32_t> m_ships;
	FleetStance m_stance = FleetStance::Movement;
};

struct BuildQuery : public NodeState
{
	BuildQuery() {}
	Schema* m_schema = nullptr;
	int m_number = 0;
	Fleet* m_destination = nullptr;
};

void draw_jump_hover(Gnode& parent, const vec3& start, const uvec2& dest, const Colour& colour)
{
	vec3 end = to_xz(vec2(dest)) + 0.5f + Y3;
	vec3 middle = (end + start) / 2.f + Y3 * 0.2f * length(end - start);
	gfx::shape(parent, ArcLine(start, middle, end), Symbol::wire(colour));
	gfx::shape(parent, Quad(to_xz(vec2(dest)) + 0.5f, vec2(1.f), X3, Z3), Symbol::wire(colour));
}

void jump_query(Widget& parent, Viewer& viewer, Fleet& fleet, uint32_t mode)
{
	Widget& self = ui::screen(viewer);
	Widget& modal = ui::popup(self, styles().modal, ui::PopupFlags::None);
	JumpQuery& query = self.state<JumpQuery>();

	if(&modal == parent.ui().m_hovered)
		query.m_hover = uvec2(UINT_MAX);

	ui::label(modal, "Jump");
	ui::label(modal, ("to [" + to_string(query.m_coord) + "]").c_str());

	Widget& row = ui::row(modal);
	ui::label(row, "in directive:");

	if(select_parsec(self, viewer, fleet.galaxy(), query.m_hover, query.m_coord, fleet.m_coord, uint(fleet.m_speed)))
		fleet.order_jump(query.m_coord, query.m_stance);

	if(ui::enum_input<FleetStance>(row, query.m_stance))
		if(query.m_coord != uvec2(UINT_MAX))
			fleet.order_jump(query.m_coord, query.m_stance);

	if(ui::button(modal, "Done").activated())	
		parent.m_switch &= ~mode;

	if(query.m_hover != uvec2(UINT_MAX))
	{
		uint16_t magic = 16; // @kludge: we probably have less than 16 painters, so safe
		draw_jump_hover(viewer.m_scene->m_graph.subx(magic), fleet.m_spatial->m_position, query.m_hover, fleet.m_commander->m_colour);
	}
}

void split_query(Widget& parent, Fleet& fleet, uint32_t mode)
{
	Widget& modal = ui::auto_modal(parent, mode);
	Widget& self = ui::widget(modal, panel_style());

	SplitQuery& query = self.state<SplitQuery>();

	ui::label(self, ("Split Fleet " + fleet.m_name).c_str());

	ui::input_field<std::string>(self, "Name", query.m_name);
	ui::enum_field<FleetStance>(self, "Directive", query.m_stance);

	Table& table = ui::table(self, carray<cstring, 4>{ "Code", "Name", "Number", "Split" }, carray<float, 4>{ 0.2f, 0.6f, 0.2f, 0.2f });

	for(auto& kv : fleet.m_ships)
	{
		Widget& row = ui::table_row(table);
		ui::label(row, kv.first->m_code.c_str());
		ui::label(row, kv.first->m_name.c_str());
		ui::label(row, to_string(kv.second).c_str());
		ui::number_input<uint32_t>(row, { query.m_ships[kv.first], StatDef<uint32_t>{ 0, fleet.m_ships[kv.first] } });
	}

	if(ui::button(self, "Split").activated())
	{
		fleet.order_split(query.m_name.c_str(), query.m_stance, query.m_ships);
		parent.m_switch &= ~mode;
	}
}

bool modal_button(Widget& screen, Widget& parent, Style& style, cstring content, uint32_t mode)
{
	if(ui::button(parent, style, content).activated())
		screen.m_switch |= mode;
	return (screen.m_switch & mode) != 0;
}

void fleet_orders(Widget& parent, Viewer& viewer, Fleet& fleet)
{
	enum Modes { Jump = 1 << 0, Split = 1 << 1 };

	Widget& self = ui::row(parent);
	if(modal_button(self, self, order_button_style(), "Jump", Jump))
		jump_query(self, viewer, fleet, Jump);
	if(modal_button(self, self, order_button_style(), "Split", Split))
		split_query(self, fleet, Split);

	if(fleet.m_split.m_state == Split::Ordered)
		ui::item(parent, order_label_style(), ("Split to " + fleet.m_split.m_code).c_str());
	if(fleet.m_jump.m_state == Jump::Ordered)
		ui::item(parent, order_label_style(), ("Jump to [" + to_string(fleet.m_jump.m_dest) + "]").c_str());
}

void fleet_summary(Widget& parent, Fleet& fleet)
{
	Widget& self = ui::row(parent);
	Table& left = ui::columns(self, carray<float, 2>{ 0.6f, 0.4f });
	Table& right = ui::columns(self, carray<float, 2>{ 0.6f, 0.4f });

	number_entry(left, "Speed", fleet.m_speed);
	number_entry(left, "Scan", fleet.m_scan);
	number_entry(left, "Upkeep", fleet.m_upkeep);
	label_entry(left, "Stance", to_string(fleet.m_stance).c_str());

	number_entry(right, "Spatial Power", float(fleet.m_spatial_power));
	number_entry(right, "Planetary Power", fleet.m_planetary_power);
	number_entry(right, "Experience", fleet.m_experience);
	label_entry(right, "Size", to_string(fleet_size(float(fleet.m_spatial_power) + fleet.m_planetary_power)).c_str());
}

void fleet_scan_sheet(Widget& parent, Fleet& fleet)
{
	Widget& self = ui::widget(parent, panel_style());

	commander_emblem(self, *fleet.m_commander);

	Table& table = ui::columns(self, carray<float, 2>{ 0.6f, 0.4f });

	label_entry(table, "Code", fleet.m_name.c_str());
	label_entry(table, "Size", to_string(fleet_size(float(fleet.m_spatial_power) + fleet.m_planetary_power)).c_str());
	label_entry(table, "Experience", to_string(fleet_experience(fleet.m_experience)).c_str());
}

void fleet_sheet(Widget& parent, Fleet& fleet)
{
	Widget& self = ui::widget(parent, sheet_style(), &fleet);

	{
		Widget& info = ui::widget(self, panel_style());
		commander_emblem(info, *fleet.m_commander, ("Fleet " + fleet.m_name).c_str());
		fleet_summary(info, fleet);
	}

	{
		Widget& spaceships = ui::widget(self, panel_style());

		Table& table = ui::table(spaceships, carray<cstring, 3>{ "Code", "Name", "Number" }, carray<float, 3>{ 0.2f, 0.6f, 0.2f });

		for(auto& kv : fleet.m_ships)
		{
			Widget& row = ui::table_row(table);
			ui::label(row, kv.first->m_code.c_str());
			ui::label(row, kv.first->m_name.c_str());
			ui::label(row, to_string(kv.second).c_str());
		}
	}
}

Widget& schema_row(Widget& parent, Schema& schema, bool selected)
{
	Widget& row = ui::table_row(parent);
	ui::label(row, schema.m_code.c_str());
	ui::label(row, schema.m_name.c_str());
	ui::label(row, "Building");
	ui::label(row, to_string(schema.m_level).c_str());
	Widget& cost = ui::stack(row);
	ui::label(cost, ("Centaure : " + to_string(schema.m_cost)).c_str());
	ui::label(cost, ("Minerals : " + to_string(schema.m_minerals)).c_str());
	ui::label(row, "");
	row.set_state(SELECTED, selected);
	return row;
}

void launch_build_sheet(Widget& parent, Star& star, uint32_t mode)
{
	Widget& self = ui::auto_modal(parent, mode, { 800.f, 600.f });
	Widget& sheet = ui::scroll_sheet(*self.m_body);

	Table& table = ui::table(*sheet.m_body, carray<cstring, 6>{ "Code", "Name", "Kind", "Level", "Cost", "Stats" }, 
											carray<float, 6>  {  0.15f,  0.3f,   0.1f,   0.05f,   0.15f,  0.25f  });

	BuildQuery& query = self.state<BuildQuery>();

	for(BuildingSchema& schema : BuildingDatabase::me.m_schemas)
	{
		if(schema_row(table, schema, query.m_schema == &schema).activated())
			query.m_schema = &schema;
	}

	for(ShipSchema& schema : ShipDatabase::me.m_schemas)
	{
		if(schema_row(table, schema, query.m_schema == &schema).activated())
			query.m_schema = &schema;
	}

	ui::number_field<int>(self, "Number", { query.m_number, { 0, 99'999 } });

	if(ui::button(self, "Submit").activated())
	{
		star.add_construction(*query.m_schema, query.m_number, query.m_destination);
		parent.m_switch &= ~mode;
	}
}

void star_orders(Widget& parent, Viewer& viewer, Star& star)
{
	UNUSED(viewer);
	enum Modes { Build = (1 << 0) };

	Widget& self = ui::row(parent);

	if(ui::modal_button(self, self, "Start Construction", Build))
		launch_build_sheet(self, star, Build);
	ui::button(self, "Change Taxation");
	ui::button(self, "Change Politics");
	ui::button(self, "Transfer System");
}

void star_scan_sheet(Widget& parent, Star& star)
{
	Widget& self = ui::widget(parent, panel_style());

	if(star.m_commander)
		commander_emblem(self, *star.m_commander, ("Star " + star.m_name).c_str());

	Table& table = ui::columns(self, carray<float, 2>{ 0.6f, 0.4f });

	label_entry(table, "Population", (to_string(star.m_population) + "/" + to_string(star.m_max_population)).c_str());
	number_entry(table, "Environment", star.m_environment);
}

void star_sheet(Widget& parent, Star& star)
{
	Widget& self = ui::widget(parent, sheet_style(), &star);

	{
		Widget& info = ui::widget(self, panel_style());

		if(star.m_commander)
			commander_emblem(info, *star.m_commander, ("Star " + star.m_name).c_str());

		Widget& row = ui::row(info);
		Table& left = ui::columns(row, carray<float, 2>{ 0.6f, 0.4f });
		Table& right = ui::columns(row, carray<float, 2>{ 0.6f, 0.4f });

		label_entry(right, "Population", (to_string(star.m_population) + "/" + to_string(star.m_max_population)).c_str());
		number_entry(right, "Environment", star.m_environment);
		number_entry(right, "Terraformation", star.m_terraformation);
		number_entry(right, "Defense", int(star.m_defense));

		label_entry(left, "Politic", to_string(star.m_politic).c_str());
		label_entry(left, "Taxation", to_string(star.m_taxation).c_str());
		number_entry(left, "Stability", star.m_stability);
		label_entry(left, "Militia", (to_string(int(star.m_militia * 100.f)) + "%").c_str());
	}

	{
		Widget& resources = ui::widget(self, panel_style());

		Table& table = ui::columns(resources, carray<float, 2>{ 1.f, 1.f});
		for(Resource resource = Resource(0); resource != Resource::Count; resource = Resource(size_t(resource) + 1))
			if(star.m_resources[size_t(resource)] > 0)
			{
				number_entry(table, to_string(resource).c_str(), star.m_resources[size_t(resource)]);
			}
	}

	{
		Widget& stocks = ui::widget(self, panel_style());

		Table& table = ui::columns(stocks, carray<float, 2>{ 1.f, 1.f});
		for(Resource resource = Resource(0); resource != Resource::Count; resource = Resource(size_t(resource) + 1))
			if(star.m_stocks[size_t(resource)] > 0)
			{
				number_entry(table, to_string(resource).c_str(), star.m_stocks[size_t(resource)]);
			}
	}

	{
		Widget& buildings = ui::widget(self, panel_style());

		Table& table = ui::columns(buildings, carray<float, 2>{ 1.f, 1.f});
		for(auto& kv : star.m_buildings)
			number_entry(table, kv.first->m_code.c_str(), kv.second);
	}

	{
		Widget& constructing = ui::widget(self, panel_style());

		Table& table = ui::table(constructing, carray<cstring, 3>{ "Code", "Number", "ETA" }, carray<float, 3>{ 1.f, 1.f, 1.f });
		for(Construction& construction : star.m_constructions)
		{
			Widget& row = ui::table_row(table);
			ui::label(row, construction.m_schema->m_code.c_str());
			ui::label(row, to_string(construction.m_number).c_str());
			ui::label(row, to_string(construction.m_turns).c_str());
		}
	}
}

Widget& sheet(Widget& parent, cstring title)
{
	Widget& self = ui::widget(parent, panel_style());
	ui::title(self, title);
	return self;
}

void commander_sheet(Widget& parent, Commander& commander)
{
	Widget& self = sheet(parent, "Commander");

	commander_emblem(self, commander);

	Table& table = ui::columns(self, carray<float, 2>{ 1.f, 1.f});
	label_entry(table, "Race", to_string(commander.m_race).c_str());
	number_entry(table, "Command", commander.m_command);
	number_entry(table, "Commerce", commander.m_commerce);
	number_entry(table, "Diplomacy", commander.m_diplomacy);
}

void empire_sheet(Widget& parent, Commander& commander)
{
	Widget& self = sheet(parent, "Government");

	Table& statistics = ui::columns(self, carray<float, 2>{ 1.f, 1.f});
	label_entry(statistics, "Regime", to_string(commander.m_regime).c_str());
	number_entry(statistics, "Systems", commander.m_stars.size());
	number_entry(statistics, "Fleets", commander.m_fleets.size());
	number_entry(statistics, "Centaures", commander.m_centaures);
	number_entry(statistics, "Power", commander.m_power);
}

void technology_sheet(Widget& parent, Commander& commander)
{
	Widget& self = sheet(parent, "Technology");

	Table& technology = ui::table(self, carray<cstring, 4>("Name", "Level", "Points", "Budget"), carray<float, 4>{ 0.45f, 0.15f, 0.2f, 0.2f });
	for(size_t i = 0; i != size_t(Technology::Count); ++i)
	{
		TechDomain& techno = commander.m_technology[i];
		Widget& row = ui::table_row(technology);
		ui::label(row, to_string(Technology(i)).c_str());
		ui::label(row, to_string(techno.m_level).c_str());
		ui::label(row, to_string(techno.m_points).c_str());
		ui::number_input<float>(row, { techno.m_budget, StatDef<float>{} });
	}
}

void turn_report_stage_events(Widget& parent, Turn& turn, Commander& commander, TurnStage stage)
{
	for(const TurnEvents::Item& item : turn.m_events[&commander].m_items[size_t(stage)])
	{
		ui::item(parent, event_style(), item.m_summary.c_str());
	}
}

void turn_report_stage(Widget& parent, Turn& turn, Commander& commander, TurnStage stage)
{
	Widget& self = sheet(parent, "Events");
	turn_report_stage_events(self, turn, commander, stage);
}

void turn_report_divisions(Widget& parent, Turn& turn)
{
	sheet(parent, "Divisions");

	Split* split = turn.split();

	if(split)
	{
		split->update(*split->m_source, split->m_source->m_spatial->m_last_tick);
		turn.m_split++;
	}

	if(!split)
		turn.next_stage();
}

void jump_camera_to(Spatial& spatial, toy::Camera& camera, const vec3& target, const quat& rotation, float distance, float angle, float duration = 1.f)
{
	animate(Ref(&camera), member(&toy::Camera::m_lens_distance), var(distance), duration);
	animate(Ref(&camera), member(&toy::Camera::m_lens_angle), var(angle), duration);
	animate(Ref(&as<Transform>(spatial)), member(&Transform::m_position), var(target), duration);
	animate(Ref(&as<Transform>(spatial)), member(&Transform::m_rotation), var(rotation), duration);
}

void turn_report_movements(Widget& parent, GameScene& scene, Turn& turn)
{
	Player& player = val<Player>(scene.m_player);
	sheet(parent, "Movements");

	auto do_jump = [&](Fleet& fleet, Jump& jump)
	{
		jump.update(fleet, fleet.m_spatial->m_last_tick);
		if(jump.m_state_updated == fleet.m_spatial->m_last_tick)
		{
			quat rotation = look_at(jump.m_start_pos, jump.m_dest_pos);

			float size = c_fleet_visu_sizes[size_t(fleet.estimated_size())];

			if(jump.m_state == Jump::Start)
				jump_camera_to(player.m_camera->m_spatial, player.m_camera, jump.m_start_pos, rotation, 2.f * size, c_pi / 8.f, 3.f);
			else if(jump.m_state == Jump::Warp)
				jump_camera_to(player.m_camera->m_spatial, player.m_camera, jump.m_dest_pos, 2.f * size);
		}
		if(jump.m_state == Jump::None)
			turn.m_jump++;
	};

	Jump* jump = turn.jump();

	if(jump)
		do_jump(*jump->m_fleet, *jump);

	if(!jump)
		turn.next_stage();
}

void fleet_losses_sheet(Widget& parent, const CombatFleet& combat_fleet, float t)
{
	Fleet& fleet = *combat_fleet.m_fleet;
	ui::label(parent, ("Fleet " + fleet.m_name + " of commander " + fleet.m_commander->m_name).c_str());

	Table& table = ui::table(parent, carray<cstring, 3>{ "Code", "Name", "Losses" }, carray<float, 3>{ 0.2f, 0.6f, 0.2f });

	for(auto& kv : fleet.m_ships)
	{
		ShipSchema* ship = kv.first;
		uint32_t number = kv.second;
		uint32_t destroyed = uint32_t(float(combat_fleet.m_losses.at(ship)) * t);

		Widget& row = ui::table_row(table);
		ui::label(row, kv.first->m_code.c_str());
		ui::label(row, kv.first->m_name.c_str());
		ui::label(row, (to_string(destroyed) + "/" + to_string(number)).c_str());
	}
}

void system_losses_sheet(Widget& parent, const CombatStar& combat_star, float t)
{
	Star& star = *combat_star.m_star;
	ui::label(parent, ("System " + star.m_name + " of commander " + (star.m_commander ? star.m_commander->m_name : "NEUTRAL")).c_str());

	Table& table = ui::table(parent, carray<cstring, 3>{ "Code", "Name", "Losses" }, carray<float, 3>{ 0.2f, 0.6f, 0.2f });

	for(auto& kv : combat_star.m_losses)
	{
		BuildingSchema* building = kv.first;
		uint32_t number = star.m_buildings[building];
		uint32_t destroyed = uint32_t(float(kv.second) * t);

		Widget& row = ui::table_row(table);
		ui::label(row, kv.first->m_code.c_str());
		ui::label(row, kv.first->m_name.c_str());
		ui::label(row, (to_string(destroyed) + "/" + to_string(number)).c_str());
	}
}

void combat_report_sheet(Widget& parent, SpatialCombat& combat)
{
	Widget& self = sheet(parent, "Combat");

	ui::label(self, "Attackers");
	for(const CombatFleet& combat_fleet : combat.m_attack)
		fleet_losses_sheet(self, combat_fleet, combat.m_t_damage);

	ui::label(self, "Defenders");
	for(const CombatFleet& combat_fleet : combat.m_defense)
		fleet_losses_sheet(self, combat_fleet, combat.m_t_damage);
}

void combat_report_sheet(Widget& parent, PlanetaryCombat& combat)
{
	Widget& self = sheet(parent, "Combat");

	ui::label(self, "Attackers");
	for(const CombatFleet& combat_fleet : combat.m_attack)
		fleet_losses_sheet(self, combat_fleet, combat.m_t_damage);

	ui::label(self, "Defenders");
	system_losses_sheet(self, combat.m_defense, combat.m_t_damage);
}

void turn_report_spatial_combats(Widget& parent, GameScene& scene, Turn& turn)
{
	sheet(parent, "Spatial Combats");

	SpatialCombat* combat = turn.spatial_combat();

	if(combat)
	{
		//vec3 position = to_xz(vec2(turn.m_current_combat->m_coord)) + 0.5f + Y3;
		//jump_camera_to(scene.m_camera, position);
		UNUSED(scene);

		combat_report_sheet(parent, *combat);
		if(ui::button(parent, "Next").activated())
		{
			combat->apply_losses();
			turn.m_spatial_combat++;
		}
	}
	else
	{
		turn.next_stage();
	}
}

void turn_report_planetary_combats(Widget& parent, GameScene& scene, Turn& turn)
{
	sheet(parent, "Planetary Combats");

	PlanetaryCombat* combat = turn.planetary_combat();

	if(combat)
	{
		//vec3 position = to_xz(vec2(turn.m_current_combat->m_coord)) + 0.5f + Y3;
		//jump_camera_to(scene.m_camera, position);
		UNUSED(scene);

		combat_report_sheet(parent, *combat);
		if(ui::button(parent, "Next").activated())
		{
			combat->apply_losses();
			turn.m_planetary_combat++;
		}
	}
	else
	{
		turn.next_stage();
		turn.next_stage();
		turn.next_stage();
		turn.next_stage();
		turn.next_stage();
	}
}

void turn_report_systems(Widget& parent, Player& player, Turn& turn)
{
	//sheet(parent, "Systems");

	Widget& self = sheet(parent, "Events");
	turn_report_stage_events(self, turn, *player.m_commander, TurnStage::Systems);
	turn_report_stage_events(self, turn, *player.m_commander, TurnStage::Constructions);
	turn_report_stage_events(self, turn, *player.m_commander, TurnStage::Fleets);
	turn_report_stage_events(self, turn, *player.m_commander, TurnStage::Technology);
	turn_report_stage_events(self, turn, *player.m_commander, TurnStage::Scans);

	if(ui::button(parent, "Next Turn").activated())
	{
		player.m_mode = GameStage::Empire;
	}
}

void turn_report_sheet(Widget& parent, GameScene& scene, Player& player, Turn& turn, Commander& commander)
{
	UNUSED(commander);
	sheet(parent, "Turn Report");

	if(turn.m_stage == TurnStage::None)
		turn.next_stage();
	else if(turn.m_stage == TurnStage::Divisions)
		turn_report_divisions(parent, turn);
	else if(turn.m_stage == TurnStage::Movements)
		turn_report_movements(parent, scene, turn);
	else if(turn.m_stage == TurnStage::SpatialCombats)
		turn_report_spatial_combats(parent, scene, turn);
	else if(turn.m_stage == TurnStage::PlanetaryCombats)
		turn_report_planetary_combats(parent, scene, turn);
	else if(turn.m_stage >= TurnStage::Systems)
		turn_report_systems(parent, player, turn);
	//else if(turn.m_stage == TurnStage::Constructions)
	//	turn_report_constructions(parent, player, turn);
	//else if(turn.m_stage == TurnStage::Fleets)
	//	turn_report_divisions(parent, *player.m_galaxy, turn);
	//else if(turn.m_stage == TurnStage::Technology)
	//	turn_report_stage(parent, turn, *player.m_commander, TurnStage::Technology);
	//else if(turn.m_state == TurnStage::Payments)
	//	turn_report_divisions(parent, *player.m_galaxy, turn);

}

static void game_actions(Widget& parent, Player& player)
{
	Widget& self = sheet(parent, "Actions");

	if(ui::button(self, "End Turn").activated())
	{
		player.m_last_turn = { *player.m_galaxy };
		player.m_turn_replay = { *player.m_galaxy };
		//player.m_turn_replay = player.m_last_turn;
		player.m_mode = GameStage::TurnReport;
	}
}

Widget& division(Widget& parent, float span)
{
	static Style style("GameDivision", styles().layout, [](Layout& l) { l.m_padding = vec4(40.f); l.m_spacing = vec2(40.f); });

	Widget& self = ui::widget(parent, style);
	self.m_frame.set_span(DIM_X, span);
	self.m_frame.set_span(DIM_Y, span);
	return self;
}

void shrink_switch(Widget& parent, array<cstring> labels, uint32_t& value)
{
	static Style style("ShrinkSwitch", styles().wedge, [](Layout& l) { l.m_space = { READING, SHRINK, SHRINK }; l.m_align = { CENTER, CENTER }; });

	Widget& middlebox = ui::widget(parent, style);
	ui::radio_switch(middlebox, labels, value);
}

static void game_viewer_ui(Viewer& viewer, GameScene& scene, Player& player)
{
	Widget& self = ui::screen(viewer);

	Widget& header = ui::header(self);
	GameStage game_mode = player.m_mode;
	shrink_switch(header, carray<cstring, 3>{ "Empire", "Tactics", "Turn Report" }, (uint32_t&) player.m_mode);
	
	if(game_mode == GameStage::TurnReport || (player.m_mode == GameStage::TurnReport && game_mode != player.m_mode))
		player.m_mode = game_mode;

	struct Divs
	{
		Divs(Widget& parent)
			: board(ui::board(parent))
			, left(division(board, 0.3f))
			, middle(division(board, 0.45f))
			, right(division(board, 0.25f))
		{}
		Widget &board, &left, &middle, &right;
	};

	Divs divs = { self };

	if(player.m_mode == GameStage::Empire)
	{
		enum Modes : uint32_t { Overview, Technology };
		static Modes mode = Overview;
		shrink_switch(divs.left, carray<cstring, 2>{ "Overview", "Technology" }, (uint32_t&) mode);

		if(mode == Overview)
		{
			Widget& sheet = ui::widget(divs.left, sheet_style(), (void*) Overview);
			commander_sheet(sheet, *player.m_commander);
			empire_sheet(sheet, *player.m_commander);
		}
		else if(mode == Technology)
		{
			Widget& sheet = ui::widget(divs.left, sheet_style(), (void*) Technology);
			technology_sheet(sheet, *player.m_commander);
		}

		player.m_selected_item = {};

		static Entity hovered = player.m_hovered_item;
		static Clock clock;
		if(hovered != player.m_hovered_item)
		{
			hovered = player.m_hovered_item;
			clock.step();
		}
		if(hovered && clock.read() > 0.2f)
		{
			//space_item_sheet(right, *scene.m_viewer, player, hovered);
		}
	}
	else if(player.m_mode == GameStage::Tactics)
	{
		Entity selected = { scene.m_selection.size() > 0 ? as_ent(scene.m_selection[0]) : UINT32_MAX, 0 };

		if(Star* star = try_asa<Star>(selected))
		{
			if(star->m_commander == player.m_commander)
				star_sheet(divs.left, *star);
			else
				star_scan_sheet(divs.left, *star);

			Widget& orders = ui::widget(divs.middle, orders_panel_style());
			star_orders(orders, viewer, *star);
		}

		if(Fleet* fleet = try_asa<Fleet>(selected))
		{
			if(fleet->m_commander == player.m_commander)
				fleet_sheet(divs.left, *fleet);
			else
				fleet_scan_sheet(divs.left, *fleet);

			Widget& orders = ui::widget(divs.middle, orders_panel_style());
			fleet_orders(orders, viewer, *fleet);
		}

		game_actions(divs.right, player);

		if(player.m_selected_item != selected)
		{
			if(selected)
			{
				Spatial& spatial = asa<Spatial>(selected);
				jump_camera_to(player.m_camera->m_spatial, player.m_camera, spatial.m_position, random_scalar(1.f, 2.f), random_scalar(float(-c_pi / 8.f), float(c_pi / 8.f)));
			}
			player.m_selected_item = selected;
		}

		static Clock clock;
		player.m_camera->m_spatial->rotate(Y3, CAMERA_ROTATION_SPEED * float(clock.step()));
	}
	else if(player.m_mode == GameStage::TurnReport)
	{
		turn_report_sheet(divs.left, scene, player, player.m_turn_replay, *player.m_commander);
	}
}

void ex_space_ui(Widget& parent, GameScene& scene)
{
	Player& player = val<Player>(scene.m_game.m_player);

	Widget& self = ui::widget(parent, styles().board, &scene);

	Viewer& viewer = game_viewport(self, scene, player.m_camera, HMovable(player.m_camera));
	viewer.m_camera.m_near = 0.001f;
	paint_viewer(viewer);

	game_viewer_ui(viewer, scene, player);

	if(viewer.m_hovered)
	{
		uint32_t* hovered = try_val<uint32_t>(viewer.m_hovered->m_node->m_object);
		player.m_hovered_item = hovered ? Entity(*hovered, 0) : Entity();
	}
	else
	{
		player.m_hovered_item = Entity();
	}
}
