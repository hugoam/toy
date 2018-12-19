
#pragma once

#if !defined MUD_MODULES || defined MUD_TYPE_LIB
#include <refl/Module.h>
#endif

#ifndef MUD_MODULES
#include <meta/infra/Module.h>
#include <meta/type/Module.h>
#include <meta/pool/Module.h>
#include <meta/refl/Module.h>
#include <meta/ecs/Module.h>
#include <meta/tree/Module.h>
#include <meta/srlz/Module.h>
#include <meta/math/Module.h>
#include <meta/geom/Module.h>
#include <meta/noise/Module.h>
#include <meta/wfc/Module.h>
#include <meta/fract/Module.h>
#include <meta/lang/Module.h>
#include <meta/ctx/Module.h>
#include <meta/ui/Module.h>
#include <meta/uio/Module.h>
#include <meta/snd/Module.h>
#include <meta/ctx-glfw/Module.h>
#include <meta/ui-vg/Module.h>
#include <meta/bgfx/Module.h>
#include <meta/gfx/Module.h>
#include <meta/gfx-pbr/Module.h>
#include <meta/gfx-obj/Module.h>
#include <meta/gfx-gltf/Module.h>
#include <meta/gfx-ui/Module.h>
#include <meta/tool/Module.h>
#include <meta/wfc-gfx/Module.h>
#include <meta/util/Module.h>
#include <meta/core/Module.h>
#include <meta/visu/Module.h>
#include <meta/edit/Module.h>
#include <meta/block/Module.h>
#include <meta/shell/Module.h>
#endif
        
#include <boids/Forward.h>
#include <boids/Types.h>
#include <boids/Api.h>

#include <meta/boids/Convert.h>

#ifndef _BOIDS_REFL_EXPORT
#define _BOIDS_REFL_EXPORT MUD_IMPORT
#endif

	export_ class _BOIDS_REFL_EXPORT _boids : public Module
	{
	private:
		_boids();

	public:
		static _boids& m() { static _boids instance; return instance; }
	};

#ifdef _BOIDS_MODULE
extern "C"
_BOIDS_REFL_EXPORT Module& getModule();
#endif
