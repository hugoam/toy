-- toy engine
-- bullet dependency module

group "bullet"

include(path.join(TOY_3RDPARTY_DIR, "bullet/src/LinearMath"))
include(path.join(TOY_3RDPARTY_DIR, "bullet/src/BulletCollision"))
include(path.join(TOY_3RDPARTY_DIR, "bullet/src/BulletDynamics"))

function bullet_warnings()
    configuration { "windows" }
        buildoptions {
            "/wd4456", -- warning C4456: declaration of 'xxx' hides previous local declaration
            "/wd4100", -- warning C4100: 'xxx': unreferenced formal parameter
            "/wd4244", -- warning C4244: '=': conversion from 'xxx' to 'yyy', possible loss of data
            "/wd4267", -- warning C4267: '=': conversion from 'xxx' to 'yyy', possible loss of data
            "/wd4305", -- warning C4305: '=': truncation from 'xxx' to 'yyy'
            "/wd4127", -- warning C4127: conditional expression is constant
            "/wd4701", -- warning C4701: potentially uninitialized local variable 'xxx' used
            "/wd4458", -- warning C4458: declaration of 'xxx' hides class member
            "/wd4457", -- warning C4457: declaration of 'xxx' hides function parameter
            "/wd4189", -- warning C4189: 'xxx': local variable is initialized but not referenced
            "/wd4505", -- warning C4505: 'xxx': unreferenced local function has been removed
            "/wd4702", -- warning C4702: unreachable code
        }

    configuration { "mingw* or linux or osx or wasm*" }
        buildoptions {
            "-Wno-strict-aliasing",
            "-Wno-unused-parameter",
            "-Wno-unused-variable",
            "-Wno-unused-function",
            "-Wno-sign-compare",
        }

    configuration { "osx or *-clang* or wasm*" }
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