#pragma once

#ifndef MUD_MODULES
#include <meta/boids/Module.h>

#include <type/Any.h>
#include <type/Vector.h>
#include <refl/MetaDecl.h>
#include <refl/Module.h>
#endif

namespace mud
{
    void _boids_meta(Module& m)
    {
    
    // Base Types
    
    // Enums
    
    // Sequences
    
    // boids::Boid
    {
        static Meta meta = { type<boids::Boid>(), &namspc({ "boids" }), "Boid", sizeof(boids::Boid), TypeClass::Struct };
        static Class cls = { type<boids::Boid>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<boids::Boid>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<boids::Boid>(ref)) boids::Boid(  ); }, {} }
            },
            // copy constructor
            {
                { type<boids::Boid>(), [](Ref ref, Ref other) { new(&val<boids::Boid>(ref)) boids::Boid(val<boids::Boid>(other)); } }
            },
            // members
            {
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        meta_class<boids::Boid>();
    }
    // boids::BoidObstacle
    {
        static Meta meta = { type<boids::BoidObstacle>(), &namspc({ "boids" }), "BoidObstacle", sizeof(boids::BoidObstacle), TypeClass::Struct };
        static Class cls = { type<boids::BoidObstacle>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<boids::BoidObstacle>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<boids::BoidObstacle>(ref)) boids::BoidObstacle(  ); }, {} }
            },
            // copy constructor
            {
                { type<boids::BoidObstacle>(), [](Ref ref, Ref other) { new(&val<boids::BoidObstacle>(ref)) boids::BoidObstacle(val<boids::BoidObstacle>(other)); } }
            },
            // members
            {
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        meta_class<boids::BoidObstacle>();
    }
    // boids::BoidTarget
    {
        static Meta meta = { type<boids::BoidTarget>(), &namspc({ "boids" }), "BoidTarget", sizeof(boids::BoidTarget), TypeClass::Struct };
        static Class cls = { type<boids::BoidTarget>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<boids::BoidTarget>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<boids::BoidTarget>(ref)) boids::BoidTarget(  ); }, {} }
            },
            // copy constructor
            {
                { type<boids::BoidTarget>(), [](Ref ref, Ref other) { new(&val<boids::BoidTarget>(ref)) boids::BoidTarget(val<boids::BoidTarget>(other)); } }
            },
            // members
            {
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        meta_class<boids::BoidTarget>();
    }
    // boids::Heading
    {
        static Meta meta = { type<boids::Heading>(), &namspc({ "boids" }), "Heading", sizeof(boids::Heading), TypeClass::Struct };
        static Class cls = { type<boids::Heading>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<boids::Heading>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<boids::Heading>(ref)) boids::Heading(  ); }, {} }
            },
            // copy constructor
            {
                { type<boids::Heading>(), [](Ref ref, Ref other) { new(&val<boids::Heading>(ref)) boids::Heading(val<boids::Heading>(other)); } }
            },
            // members
            {
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        meta_class<boids::Heading>();
    }
    // boids::MoveForward
    {
        static Meta meta = { type<boids::MoveForward>(), &namspc({ "boids" }), "MoveForward", sizeof(boids::MoveForward), TypeClass::Struct };
        static Class cls = { type<boids::MoveForward>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<boids::MoveForward>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<boids::MoveForward>(ref)) boids::MoveForward(  ); }, {} }
            },
            // copy constructor
            {
                { type<boids::MoveForward>(), [](Ref ref, Ref other) { new(&val<boids::MoveForward>(ref)) boids::MoveForward(val<boids::MoveForward>(other)); } }
            },
            // members
            {
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        meta_class<boids::MoveForward>();
    }
    // boids::MoveSpeed
    {
        static Meta meta = { type<boids::MoveSpeed>(), &namspc({ "boids" }), "MoveSpeed", sizeof(boids::MoveSpeed), TypeClass::Struct };
        static Class cls = { type<boids::MoveSpeed>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<boids::MoveSpeed>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<boids::MoveSpeed>(ref)) boids::MoveSpeed(  ); }, {} }
            },
            // copy constructor
            {
                { type<boids::MoveSpeed>(), [](Ref ref, Ref other) { new(&val<boids::MoveSpeed>(ref)) boids::MoveSpeed(val<boids::MoveSpeed>(other)); } }
            },
            // members
            {
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        meta_class<boids::MoveSpeed>();
    }
    // boids::Player
    {
        static Meta meta = { type<boids::Player>(), &namspc({ "boids" }), "Player", sizeof(boids::Player), TypeClass::Object };
        static Class cls = { type<boids::Player>(),
            // bases
            {  },
            {  },
            // constructors
            {
            },
            // copy constructor
            {
            },
            // members
            {
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        meta_class<boids::Player>();
    }
    // boids::Position
    {
        static Meta meta = { type<boids::Position>(), &namspc({ "boids" }), "Position", sizeof(boids::Position), TypeClass::Struct };
        static Class cls = { type<boids::Position>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<boids::Position>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<boids::Position>(ref)) boids::Position(  ); }, {} }
            },
            // copy constructor
            {
                { type<boids::Position>(), [](Ref ref, Ref other) { new(&val<boids::Position>(ref)) boids::Position(val<boids::Position>(other)); } }
            },
            // members
            {
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        meta_class<boids::Position>();
    }
    // boids::Rotation
    {
        static Meta meta = { type<boids::Rotation>(), &namspc({ "boids" }), "Rotation", sizeof(boids::Rotation), TypeClass::Struct };
        static Class cls = { type<boids::Rotation>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<boids::Rotation>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<boids::Rotation>(ref)) boids::Rotation(  ); }, {} }
            },
            // copy constructor
            {
                { type<boids::Rotation>(), [](Ref ref, Ref other) { new(&val<boids::Rotation>(ref)) boids::Rotation(val<boids::Rotation>(other)); } }
            },
            // members
            {
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        meta_class<boids::Rotation>();
    }
    // boids::Transform4
    {
        static Meta meta = { type<boids::Transform4>(), &namspc({ "boids" }), "Transform4", sizeof(boids::Transform4), TypeClass::Struct };
        static Class cls = { type<boids::Transform4>(),
            // bases
            {  },
            {  },
            // constructors
            {
                { type<boids::Transform4>(), [](Ref ref, array<Var> args) { UNUSED(args); new(&val<boids::Transform4>(ref)) boids::Transform4(  ); }, {} }
            },
            // copy constructor
            {
                { type<boids::Transform4>(), [](Ref ref, Ref other) { new(&val<boids::Transform4>(ref)) boids::Transform4(val<boids::Transform4>(other)); } }
            },
            // members
            {
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        meta_class<boids::Transform4>();
    }
        m.m_types.push_back(&type<boids::Boid>());
        m.m_types.push_back(&type<boids::BoidObstacle>());
        m.m_types.push_back(&type<boids::BoidTarget>());
        m.m_types.push_back(&type<boids::Heading>());
        m.m_types.push_back(&type<boids::MoveForward>());
        m.m_types.push_back(&type<boids::MoveSpeed>());
        m.m_types.push_back(&type<boids::Player>());
        m.m_types.push_back(&type<boids::Position>());
        m.m_types.push_back(&type<boids::Rotation>());
        m.m_types.push_back(&type<boids::Transform4>());
    }
}
