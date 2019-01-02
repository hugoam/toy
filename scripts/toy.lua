-- toy engine

-- known build issues :
-- glfw3 on ubuntu is installed as libglfw.so (and not libglfw3.so)
-- if yacc is not found it will generate an empty glcpp-lexer.c file

group "3rdparty"
dofile(path.join(TOY_DIR, "scripts/3rdparty/bullet.lua"))

dofile(path.join(MUD_DIR, "scripts/mud.lua"))

function toy_core()
	includedirs {
        path.join(TOY_3RDPARTY_DIR, "recast", "Recast", "Include"),
        path.join(TOY_3RDPARTY_DIR, "recast", "Detour", "Include"),
        path.join(TOY_3RDPARTY_DIR, "bullet", "src"),
	}

	files {
        path.join(TOY_3RDPARTY_DIR, "recast", "Recast", "Include", "*.h"),
        path.join(TOY_3RDPARTY_DIR, "recast", "Recast", "Source", "*.cpp"),
        
        path.join(TOY_3RDPARTY_DIR, "recast", "Detour", "Include", "*.h"),
        path.join(TOY_3RDPARTY_DIR, "recast", "Detour", "Source", "*.cpp"),
	}
    
    links {
        "LinearMath",
        "BulletCollision",
        "BulletDynamics",
	}
end

function uses_toy_core()
	includedirs {
        TOY_SRC_DIR,
        path.join(TOY_3RDPARTY_DIR, "bullet", "src"),
	}

    links {
        "LinearMath",
        "BulletCollision",
        "BulletDynamics",
    }
end

function toy_visu()
    if not _OPTIONS["sound"] then
        removefiles {
            path.join(TOY_VISU_DIR, "Sound", "**.h"),
            path.join(TOY_VISU_DIR, "Sound", "**.cpp"), 
        }
    end
end

function uses_toy_visu()
    if _OPTIONS["sound"] then
        defines { "TOY_SOUND" }
    end
end

function toy_shell()
    includedirs {
        path.join(MUD_3RDPARTY_DIR, "tracy"),
    }
end

toy = {}

--                           base   name        root path    sub path   decl        self decl       decl transitive     dependencies
toy.util        = mud_module("toy", "util",     TOY_SRC_DIR, "util",    nil,        nil,            nil,                { mud.type, mud.math })
toy.core        = mud_module("toy", "core",     TOY_SRC_DIR, "core",    nil,        toy_core,       uses_toy_core,      { mud.type, mud.jobs, mud.ecs, mud.math, mud.geom, mud.lang, toy.util })
if _OPTIONS["sound"] then
    toy.visu    = mud_module("toy", "visu",     TOY_SRC_DIR, "visu",    nil,        toy_visu,       uses_toy_visu,      { mud.type, mud.snd, mud.gfx, toy.util, toy.core })
else
    toy.visu    = mud_module("toy", "visu",     TOY_SRC_DIR, "visu",    nil,        toy_visu,       uses_toy_visu,      { mud.type, mud.gfx, toy.util, toy.core })
end
toy.edit        = mud_module("toy", "edit",     TOY_SRC_DIR, "edit",    nil,        nil,            nil,                { mud.type, mud.ui, mud.tool, toy.util, toy.core, toy.visu }) -- table.merge(mud.all, 
toy.block       = mud_module("toy", "block",    TOY_SRC_DIR, "block",   nil,        nil,            nil,                { mud.type, mud.math, mud.wfc.gfx, toy.core, toy.visu, toy.edit })
toy.shell       = mud_module("toy", "shell",    TOY_SRC_DIR, "shell",   nil,        toy_shell,      nil,                table.merge(mud.mud, { toy.core, toy.visu, toy.edit, toy.block }))

toy.core.aliases = { ['toy::string'] = 'std::string' }

toy.toy = { toy.util, toy.core, toy.visu, toy.edit, toy.block, toy.shell }


group "lib"
if _OPTIONS["as-libs"] then
    group "lib/toy"
        mud_libs(toy.toy, "StaticLib")
    group "lib"
else
    toy.lib = mud_lib("toy", toy.toy, "SharedLib")
        
        files {
            path.join(TOY_SRC_DIR, "toy",    "**.h"),
        }
end

group "bin"
--dofile(path.join(TOY_DIR, "scripts/shell.lua"))

function toy_binary(name, modules, deps)
    mud_lib(name, modules, "ConsoleApp", deps)
    defines { "_" .. name:upper() .. "_EXE" }
    toy_binary_config()
end

function toy_shell(name, modules, deps)
    toy_binary(name, modules, deps)
    
    files {
        path.join(MUD_DIR, "src", "mud", "Shell.cpp"),
    }
end

function toy_dll(name, modules, deps)
    mud_lib(name, modules, "SharedLib", deps)
end
