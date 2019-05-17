
#pragma once

#include <space/Forward.h>

#include <map>

using namespace two;
using namespace toy;

using Ships = std::map<ShipSchema*, uint32_t>;

void fill_fleet(VisuFleet& visu, const Ships& ships);

void paint_fleet_ships(Gnode& parent, VisuFleet& visu, float radius = 0.4f, float ship_scale = 0.05f);

void paint_star(Gnode& parent, Star& star);
void paint_scan_star(Gnode& parent, Star& star);
void paint_scan_fleet(Gnode& parent, Fleet& fleet);
void paint_galaxy(Gnode& parent, Galaxy& galaxy);
void paint_combat(Gnode& parent, SpatialCombat& combat);
void paint_scene(Gnode& parent);
void paint_viewer(Viewer& viewer);
