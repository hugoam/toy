-- toy engine
-- bullet dependency module

group "bullet"

include(path.join(TOY_3RDPARTY_DIR, "bullet/src/LinearMath"))
include(path.join(TOY_3RDPARTY_DIR, "bullet/src/BulletCollision"))
include(path.join(TOY_3RDPARTY_DIR, "bullet/src/BulletDynamics"))

project "BulletCollision"
    configuration { "linux" }
        buildoptions {
            "-Wno-strict-aliasing",
            "-Wno-unused-parameter",
            "-Wno-unused-variable",
            "-Wno-unused-function",
            "-Wno-maybe-uninitialized",
        }

    configuration {}

project "BulletDynamics"
    configuration { "linux" }
        buildoptions {
            "-Wno-strict-aliasing",
            "-Wno-unused-parameter",
            "-Wno-unused-variable",
            "-Wno-unused-function",
            "-Wno-maybe-uninitialized",
        }

    configuration {}
