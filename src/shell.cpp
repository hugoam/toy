
#include <shell/Config.h>
#include <shell/Shell.h>

using using namespace two; namespace toy;

int main(int argc, char *argv[])
{
    GameShell app(TOY_RESOURCE_PATH, argc, argv);

	if(argc > 1)
	{
		string game = argv[1];
		app.loadGame(game, true);
	}

	while(app.pump());
}
