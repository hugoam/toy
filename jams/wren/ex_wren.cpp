
#include <wren/ex_wren.h>
#include <toy/toy.h>

#include <wren/Api.h>
#include <meta/wren/Module.h>

#ifdef _EX_WREN_EXE
int main(int argc, char *argv[])
{
	cstring example_path = TOY_RESOURCE_PATH "examples/ex_wren/";
	GameShell app(carray<cstring, 2>{ TOY_RESOURCE_PATH, example_path }, argc, argv);
	
	//app.run_script(_wren::m(), "ex_wren.wren");
	//app.run_script(_wren::m(), "ex_wren_cube.wren");
	//app.run_script(_wren::m(), "ex_wren_shapes.wren");
	app.run_script(_wren::m(), "tutorial_empty.wren", true);
	//app.run_script(_wren::m(), "tutorial_0.wren", true);
	//app.run_script(_wren::m(), "tutorial_1.wren", true);
	//app.run_script(_wren::m(), "tutorial_2.wren", true);
	//app.run_script(_wren::m(), "tutorial_3.wren", true);
	//app.run_script(_wren::m(), "tutorial_4.wren", true);
	//app.run_script(_wren::m(), "tutorial_test.wren", true);
}
#endif
