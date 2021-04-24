
detour = dep(nil, "detour")
	kind "StaticLib"
    
	includedirs {
        path.join(TOY_3RDPARTY_DIR, "recast", "Recast", "Include"),
        path.join(TOY_3RDPARTY_DIR, "recast", "Detour", "Include"),
	}

	files {
        path.join(TOY_3RDPARTY_DIR, "recast", "Recast", "Include", "*.h"),
        path.join(TOY_3RDPARTY_DIR, "recast", "Recast", "Source", "*.cpp"),
        
        path.join(TOY_3RDPARTY_DIR, "recast", "Detour", "Include", "*.h"),
        path.join(TOY_3RDPARTY_DIR, "recast", "Detour", "Source", "*.cpp"),
	}
    
    configuration { "mingw* or linux or osx or wasm*" }
        buildoptions {
        }
        
    configuration { "osx or *-clang* or wasm*" }
        buildoptions {
        }
        
    configuration { "vs*", "not wasm*" }
        buildoptions {
        }
    
	configuration {}
