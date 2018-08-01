#pragma once

#include <mud/mud.h>

#include <snd/Api.h>

#include <util/Api.h>
//#include <db/Api.h>
#include <core/Api.h>
#include <visu/Api.h>
#include <block/Api.h>
#include <edit/Api.h>
#include <shell/Api.h>

#ifdef MUD_PLATFORM_EMSCRIPTEN
#define TOY_RESOURCE_PATH "/data/"
#endif
