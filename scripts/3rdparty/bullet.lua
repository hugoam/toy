-- toy engine
-- bullet dependency module

group "bullet"

include(path.join(TOY_3RDPARTY_DIR, "bullet/src/LinearMath"))
include(path.join(TOY_3RDPARTY_DIR, "bullet/src/BulletCollision"))
include(path.join(TOY_3RDPARTY_DIR, "bullet/src/BulletDynamics"))

function bullet_warnings()
	configuration { "mingw* or linux or osx or asmjs" }
        buildoptions {
            "-Wno-strict-aliasing",
            "-Wno-unused-parameter",
            "-Wno-unused-variable",
            "-Wno-unused-function",
            "-Wno-sign-compare",
        }
        
	configuration { "osx or *-clang* or asmjs" }
        buildoptions {
            "-Wno-undef",
        }
        
    configuration { "osx" }
        buildoptions {
            "-Wno-ignored-qualifiers",
        }
        
    configuration { "*-gcc*" }
        buildoptions {
            "-Wno-maybe-uninitialized",
            "-Wno-type-limits",
        }

    configuration {}
end

project "LinearMath"
	bullet_warnings()

project "BulletCollision"
	bullet_warnings()

project "BulletDynamics"
    bullet_warnings()