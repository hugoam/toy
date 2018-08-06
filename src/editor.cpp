#include <toy/toy.h>
#include <shell/Shell.h>

using namespace mud; using namespace toy;

int main(int argc, char *argv[])
{
	GameShell app(carray<cstring, 1>{ TOY_RESOURCE_PATH }, argc, argv);

	if(argc > 1)
	{
		std::string game = argv[1];
		app.run_editor_path(game);
	}

	//app.run_editor_path("ex_space");
	//app.run_editor_path("ex_platform");
	app.run_editor_path("ex_blocks");
}
