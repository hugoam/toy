

#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module toy.edit;
#else
#include <edit/Types.h>
#include <edit/Api.h>
#include <type/Vector.h>
//#include <ecs/Proto.h>
#endif

namespace mud
{
    // Exported types
    
    template <> TOY_EDIT_EXPORT Type& type<toy::ActionGroup>() { static Type ty("ActionGroup"); return ty; }
    template <> TOY_EDIT_EXPORT Type& type<toy::GraphicsDebug>() { static Type ty("GraphicsDebug"); return ty; }
    template <> TOY_EDIT_EXPORT Type& type<toy::Toolbelt>() { static Type ty("Toolbelt"); return ty; }
    template <> TOY_EDIT_EXPORT Type& type<toy::Toolbox>() { static Type ty("Toolbox"); return ty; }
    template <> TOY_EDIT_EXPORT Type& type<toy::DynamicToolbox>() { static Type ty("DynamicToolbox", type<toy::Toolbox>()); return ty; }
	template <> TOY_EDIT_EXPORT Type& type<toy::RunTool>() { static Type ty("RunTool", type<mud::Tool>()); return ty; }
    template <> TOY_EDIT_EXPORT Type& type<toy::PlayTool>() { static Type ty("PlayTool", type<mud::Tool>()); return ty; }
    template <> TOY_EDIT_EXPORT Type& type<toy::Editor>() { static Type ty("Editor", type<mud::EditContext>()); return ty; }
    template <> TOY_EDIT_EXPORT Type& type<toy::Paste>() { static Type ty("Paste"); return ty; }
    template <> TOY_EDIT_EXPORT Type& type<toy::Clone>() { static Type ty("Clone"); return ty; }
    template <> TOY_EDIT_EXPORT Type& type<toy::Edit>() { static Type ty("Edit"); return ty; }
    template <> TOY_EDIT_EXPORT Type& type<toy::Cut>() { static Type ty("Cut"); return ty; }
}
