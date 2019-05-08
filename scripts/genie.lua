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

two_libs();
toy_libs();

group "bin"
dofile "jams.lua"

if _OPTIONS["tools"] then
    two_binary("metagen", { two.clrefl }, {})
    two_binary("amalg", { two.amalg }, {})
end


--dofile "editor.lua"
--dofile "example.lua"

dofile(path.join(TWO_DIR, "scripts/two_example.lua"))
