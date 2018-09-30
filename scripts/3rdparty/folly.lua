-- toy engine
-- folly dependency module

folly = mud_dep(nil, "folly")
    kind "StaticLib"
    
    includedirs {
        path.join(TOY_3RDPARTY_DIR, "hashmap"),
    }

    files {
        path.join(TOY_3RDPARTY_DIR, "hashmap", "folly", "**.h"),
        path.join(TOY_3RDPARTY_DIR, "hashmap", "folly", "**.cpp"),
    }

    defines { "FOLLY_NO_CONFIG" }
