#pragma once

#include <infra/Config.h>

#include <type/Forward.h>
#include <ui/Forward.h>
#include <tool/Forward.h>
#include <util/Forward.h>
#include <core/Forward.h>
#include <visu/Forward.h>

#ifndef TOY_EDIT_EXPORT
#define TOY_EDIT_EXPORT TWO_IMPORT
#endif

namespace toy
{
    class CameraController;
    class FPSCameraController;
    class RTSCameraController;
    class Edit;
    class Clone;
    class Cut;
    class Paste;
    class Toolbox;
    class DynamicToolbox;
    class Toolbelt;
	class RunTool;
    class PlayTool;
    struct ActionGroup;
    struct GraphicsDebug;
    class Editor;
}
