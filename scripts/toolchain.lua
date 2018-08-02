-- toy toolchain

TOY_DIR        = path.getabsolute("..")
MUD_DIR        = path.join(TOY_DIR, "mud")

TOY_SRC_DIR         = path.join(TOY_DIR, "src")
TOY_3RDPARTY_DIR    = path.join(TOY_DIR, "3rdparty")

dofile(path.join(MUD_DIR, "scripts/toolchain.lua"))

function toy_binary_config()
    mud_binary_config()
    
    configuration { "not linux", "not osx", "not asmjs" }
        defines {
            "TOY_RESOURCE_PATH=\"" .. path.join(TOY_DIR, "data") .. "/\"",
        }

    configuration { "linux or osx", "not asmjs" }
        defines {
            "TOY_RESOURCE_PATH=\\\"" .. path.join(TOY_DIR, "data") .. "/\\\"",
        }

	configuration {}
end

configuration { "windows"}
    libdirs {
        "C:/Program Files (x86)/OpenAL/libs/Win32",
        "C:/Program Files/OpenAL/libs/Win32",
    }
    
    includedirs {
        "C:/Program Files (x86)/OpenAL/include",
        "C:/Program Files/OpenAL/include",
    }

configuration { "vs*-clang" }
    defines {
        "BT_NO_SIMD_OPERATOR_OVERLOADS"
    }
    
configuration {}