#include <toy/toy.h>
#include <shell/Shell.h>

#include <meta/core/Module.h>
#include <meta/visu/Module.h>
#include <meta/edit/Module.h>
#include <meta/block/Module.h>
#include <meta/shell/Module.h>

using namespace two; using namespace toy;

int main(int argc, char *argv[])
{
	GameShell app(carray<cstring, 1>{ TOY_RESOURCE_PATH }, argc, argv);

	if(argc > 1)
	{
		string game = argv[1];
		app.run_editor_path(game);
	}

	// @kludge for link error
	toy_util::m(); toy_core::m(); toy_visu::m(); toy_edit::m(); toy_block::m();

	//app.run_editor_path("ex_space");
	//app.run_editor_path("ex_platform");
	app.run_editor_path("ex_blocks");
}
