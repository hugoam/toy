#include <infra/Cpp20.h>

#ifdef TWO_MODULES
module toy.edit;
#else
#include <edit/Types.h>
#include <edit/Api.h>
#include <type/Vector.h>
#endif

namespace two
{
    // Exported types
    
    
    template <> TOY_EDIT_EXPORT Type& type<toy::Edit>() { static Type ty("Edit", sizeof(toy::Edit)); return ty; }
    template <> TOY_EDIT_EXPORT Type& type<toy::Clone>() { static Type ty("Clone", sizeof(toy::Clone)); return ty; }
    template <> TOY_EDIT_EXPORT Type& type<toy::Cut>() { static Type ty("Cut", sizeof(toy::Cut)); return ty; }
    template <> TOY_EDIT_EXPORT Type& type<toy::Paste>() { static Type ty("Paste", sizeof(toy::Paste)); return ty; }
    template <> TOY_EDIT_EXPORT Type& type<toy::Toolbox>() { static Type ty("Toolbox", sizeof(toy::Toolbox)); return ty; }
    template <> TOY_EDIT_EXPORT Type& type<toy::DynamicToolbox>() { static Type ty("DynamicToolbox", type<toy::Toolbox>(), sizeof(toy::DynamicToolbox)); return ty; }
    template <> TOY_EDIT_EXPORT Type& type<toy::Toolbelt>() { static Type ty("Toolbelt", sizeof(toy::Toolbelt)); return ty; }
    template <> TOY_EDIT_EXPORT Type& type<toy::PlayTool>() { static Type ty("PlayTool", type<two::Tool>(), sizeof(toy::PlayTool)); return ty; }
    template <> TOY_EDIT_EXPORT Type& type<toy::RunTool>() { static Type ty("RunTool", type<two::Tool>(), sizeof(toy::RunTool)); return ty; }
    template <> TOY_EDIT_EXPORT Type& type<toy::ActionGroup>() { static Type ty("ActionGroup", sizeof(toy::ActionGroup)); return ty; }
    template <> TOY_EDIT_EXPORT Type& type<toy::GraphicsDebug>() { static Type ty("GraphicsDebug", sizeof(toy::GraphicsDebug)); return ty; }
    template <> TOY_EDIT_EXPORT Type& type<toy::Editor>() { static Type ty("Editor", type<two::EditContext>(), sizeof(toy::Editor)); return ty; }
}
