-- toy engine
-- cds dependency module

cds = mud_dep(nil, "cds")
    kind "StaticLib"
    
    includedirs {
        path.join(TOY_3RDPARTY_DIR, "libcds"),
        path.join(TOY_3RDPARTY_DIR, "libcds", "cds"),
    }

    files {
        path.join(TOY_3RDPARTY_DIR, "libcds", "src", "**.cpp"),
    }

    defines { "CDS_BUILD_STATIC_LIB" }
