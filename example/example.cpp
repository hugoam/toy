
#include <Config.h>
#include <shell/Shell.h>
#include <ui/Bundle.h>

#include <core/User/User.h>
#include <obj/Serial/Serial.h>

#include <bx/file.h>

#include <00_cube/Module.h>
#include <01_shapes/Module.h>
#include <02_camera/Module.h>
#include <03_materials/Module.h>
#include <04_lights/Module.h>
#include <05_character/Module.h>
#include <06_particles/Module.h>
#include <07_prefabs/Module.h>
#include <08_terrain_sky/Module.h>
#include <09_custom_render/Module.h>
#include <10_post_process/Module.h>
#include <11_selection/Module.h>
#include <12_ui/Module.h>
#include <13_live_ui/Module.h>
#include <14_live_gfx/Module.h>
#include <15_script/Module.h>
#include <16_visual_script/Module.h>
#include <17_proc_gen/Module.h>
#include <18_pathfinding/Module.h>
#include <19_multi_viewport/Module.h>
#include <20_meta/Module.h>

#include <space/Module.h>
#include <blocks/Module.h>
#include <platform/Module.h>

#include <fstream>

using namespace mud;

static GameModule* current_example = nullptr;

void example_screen(Shell& app, Widget& parent)
{
	static std::vector<string> examples_names = { "00_cube", "01_shapes", "02_camera", "03_materials", "04_lights", "05_character", "06_particles", "07_prefabs",
												  "08_terrain_sky", "09_custom_render", "10_post_process", "11_selection", "12_ui", "13_live_ui", "14_live_gfx", "15_script", "17_proc_gen", "20_meta",
												  "ex_space", "ex_blocks", "ex_platform" };
	static std::vector<GameModule*> examples = { &ex_00_cube::module(), &ex_01_shapes::module(), &ex_02_camera::module(), &ex_03_materials::module(), &ex_04_lights::module(), &ex_05_character::module(), &ex_06_particles::module(), &ex_07_prefabs::module(),
												 &ex_08_terrain_sky::module(), &ex_09_custom_render::module(), &ex_10_post_process::module(), &ex_11_selection::module(), &ex_12_ui::module(), &ex_13_live_ui::module(), &ex_14_live_gfx::module(), &ex_15_script::module(), &ex_17_proc_gen::module(), &ex_20_meta::module(),
												 &ex_space::module(), &ex_blocks::module(), &ex_platform::module() };

	Widget& sheet = ui::modal(parent);
	size_t example = 0;
	ui::label(sheet, "Select an example");
	if(ui::dropdown_input(sheet, examples_names, example))
	{
		current_example = examples[example];
		app.loadGame(*current_example, true);
	}
}

bool pump(Shell& app)
{
	if(current_example == nullptr)
		example_screen(app, app.m_ui->begin());
	return app.pump();
}

#if MUD_PLATFORM_EMSCRIPTEN
#define TOY_RESOURCE_PATH "/data/"
#include <emscripten/emscripten.h>

Shell* g_app = nullptr;
void iterate() { pump(*g_app); }
#endif

int main(int argc, char *argv[])
{
	//_CrtSetDbgFlag(_CRTDBG_CHECK_ALWAYS_DF);

#ifdef _WIN32
	string execPath = argv[0];
	string execDir(execPath.begin(), execPath.begin() + execPath.rfind('\\'));
#else
	string execDir = "./";
#endif
	
	static User user(0, "admin");
	static Shell app(execDir, TOY_RESOURCE_PATH);
	app.initVisu(user, false);

#ifdef MUD_PLATFORM_EMSCRIPTEN
	g_app = &app;
	emscripten_set_main_loop(iterate, 0, 1);
#else
	bool pursue = true;
	while(pursue)
		pump(app);
#endif
}
