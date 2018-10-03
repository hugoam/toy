-- toy engine

solution "toy"
	configurations {
		"Debug",
		"Release",
	}

	platforms {
		"x32",
		"x64"
	}

	language "C++"
    
    
PROJECT_DIR = path.getabsolute("..")
BUILD_DIR = path.join(path.getabsolute(".."), "build")

dofile "toolchain.lua"

dofile "toy.lua"
group "bin"
dofile "editor.lua"
dofile "example.lua"
dofile "jams.lua"

--dofile(path.join(MUD_DIR, "scripts/mud_example.lua"))
