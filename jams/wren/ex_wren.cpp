
#include <wren/ex_wren.h>
#include <toy/toy.h>

#include <wren/Api.h>
#include <meta/wren/Module.h>

#ifdef _EX_WREN_EXE
int main(int argc, char *argv[])
{
	cstring example_path = TOY_RESOURCE_PATH "examples/ex_wren/";
	GameShell app(carray<cstring, 2>{ TOY_RESOURCE_PATH, example_path }, argc, argv);
	
	app.m_wren->declare_types();

	LocatedFile location = app.m_gfx_system->locate_file("scripts/ex_wren.wren");

	if(location.m_name != nullptr)
	{
		Signature signature = { { Param{ "app", Ref(type<GameShell>()) }, Param{ "module", Ref(type<Module>()) } } };

		TextScript& script = app.m_editor.m_script_editor.create_script("ex_wren", Language::Wren, signature);
		script.m_script = read_text_file(std::string(location.m_location) + location.m_name);

		Var args[2] = { Ref(&app), Ref((Module*)&_wren::m()) };
		script({ args, 2 });
	}
}
#endif
