-- toy engine

-- known build issues :
-- glfw3 on ubuntu is installed as libglfw.so (and not libglfw3.so)
-- if yacc is not found it will generate an empty glcpp-lexer.c file

if not _OPTIONS["compile-only"] then
    group "3rdparty"
    dofile(path.join(TOY_DIR, "scripts/3rdparty/bullet.lua"))
    dofile(path.join(TOY_DIR, "scripts/3rdparty/detour.lua"))
end

dofile(path.join(TWO_DIR, "scripts/two.lua"))

function toy_core()
    includedirs {
        path.join(TOY_3RDPARTY_DIR, "recast", "Recast", "Include"),
        path.join(TOY_3RDPARTY_DIR, "recast", "Detour", "Include"),
        path.join(TOY_3RDPARTY_DIR, "bullet", "src"),
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
        path.join(TWO_3RDPARTY_DIR, "tracy"),
    }
end

toy = {}

--                       base   name        root path    sub path   self decl       usage decl      reflect     dependencies
toy.util        = module("toy", "util",     TOY_SRC_DIR, "util",    nil,            nil,            true,       { two.type, two.math })
toy.core        = module("toy", "core",     TOY_SRC_DIR, "core",    toy_core,       uses_toy_core,  true,       { detour, two.type, two.jobs, two.ecs, two.math, two.geom, two.lang, toy.util })
if _OPTIONS["sound"] then
    toy.visu    = module("toy", "visu",     TOY_SRC_DIR, "visu",    toy_visu,       uses_toy_visu,  true,       { two.type, two.snd, two.gfx, toy.util, toy.core })
else
    toy.visu    = module("toy", "visu",     TOY_SRC_DIR, "visu",    toy_visu,       uses_toy_visu,  true,       { two.type, two.gfx, toy.util, toy.core })
end
toy.edit        = module("toy", "edit",     TOY_SRC_DIR, "edit",    nil,            nil,            true,       { two.type, two.ui, two.tool, toy.util, toy.core, toy.visu }) -- table.union(two.all, 
toy.block       = module("toy", "block",    TOY_SRC_DIR, "block",   nil,            nil,            true,       { two.type, two.math, two.wfc.gfx, toy.core, toy.visu, toy.edit })
toy.shell       = module("toy", "shell",    TOY_SRC_DIR, "shell",   toy_shell,      nil,            true,       table.union(two.two, { toy.core, toy.visu, toy.edit, toy.block }))
if _OPTIONS["misc"] then
    toy.misc    = module("toy", "misc",     TOY_SRC_DIR, "misc",    nil,            nil,            true,       { two.type, two.math, toy.core })
end

toy.toy = { toy.util, toy.core, toy.visu, toy.edit, toy.block, toy.shell }
if _OPTIONS["misc"] then
    table.insert(toy.toy, toy.misc)
end

function toy_libs()
    if _OPTIONS["unity"] then
        for _, m in pairs(toy.toy) do
            m.unity = true
            if m.refl then
                m.refl.unity = true
            end
        end
    end

    group "lib"
    if _OPTIONS["as-libs"] then
        group "lib/toy"
            libs(toy.toy, "StaticLib")
        group "lib"
    else
        if _OPTIONS["compile-only"] then
            toy.lib = lib("toy", toy.toy, "StaticLib")
        else
            toy.lib = lib("toy", toy.toy, "SharedLib")
        end
        
            --files {
            --    path.join(TOY_SRC_DIR, "toy",    "**.h"),
            --}
    end

    toy.all = table.union(two.two, toy.toy)

    group "bin"
    --dofile(path.join(TOY_DIR, "scripts/shell.lua"))
end

function toy_binary(name, modules, deps)
    lib(name, modules, "ConsoleApp", deps)
    defines { "_" .. name:upper() .. "_EXE" }
    toy_binary_config()
end

function toy_shell(name, modules, deps)
    toy_binary(name, modules, deps)
end

function toy_dll(name, modules, deps)
    lib(name, modules, "SharedLib", deps)
end
