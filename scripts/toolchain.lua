-- toy toolchain

newoption {
    trigger = "misc",
    description = "Use toy misc module",
}

TOY_DIR        = path.getabsolute("..")
TWO_DIR        = path.join(TOY_DIR, "two")

TOY_SRC_DIR         = path.join(TOY_DIR, "src")
TOY_3RDPARTY_DIR    = path.join(TOY_DIR, "3rdparty")

dofile(path.join(TWO_DIR, "scripts/toolchain.lua"))

function toy_binary_config()
    two_binary_config()
    
    configuration { "not osx", "not asmjs" }
        defines {
            "TOY_RESOURCE_PATH=\"" .. path.join(TOY_DIR, "data") .. "\"",
        }

    configuration { "osx", "not asmjs" }
        defines {
            -- might need to update GENie to remove that special case
            "TOY_RESOURCE_PATH=\\\"" .. path.join(TOY_DIR, "data") .. "\\\"",
        }

	configuration {}
end

configuration { "windows" }
    includedirs {
        "C:/Program Files (x86)/OpenAL/include",
        "C:/Program Files/OpenAL/include",
    }

configuration { "windows", "x32" }
    libdirs {
        "C:/Program Files (x86)/OpenAL/libs/Win32",
        "C:/Program Files/OpenAL/libs/Win32",
    }
    
configuration { "windows", "x64" }
    libdirs {
        "C:/Program Files (x86)/OpenAL/libs/Win64",
        "C:/Program Files/OpenAL/libs/Win64",
    }

configuration { "vs*-clang" }
    defines {
        "BT_NO_SIMD_OPERATOR_OVERLOADS"
    }
    
configuration {}