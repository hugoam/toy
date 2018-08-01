

#pragma once

#ifndef MUD_MODULES
#include <meta/editor/Module.h>

#include <obj/Any.h>
#include <obj/Vector.h>
#include <refl/MetaDecl.h>
#include <refl/Module.h>
#endif

namespace mud
{
    void toy_editor_meta(Module& m)
    {   
    // Base Types
    
    // Enums
    
    // Sequences
    
    
    
        
    // toy::ActionGroup
    {
        static Meta meta = { type<toy::ActionGroup>(), &namspc({ "toy" }), "ActionGroup", sizeof(toy::ActionGroup), TypeClass::Object };
        static Class cls = { type<toy::ActionGroup>(),
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
        
        
        
        
        meta_class<toy::ActionGroup>();
    }
    
    
        
    // toy::Clone
    {
        static Meta meta = { type<toy::Clone>(), &namspc({ "toy" }), "Clone", sizeof(toy::Clone), TypeClass::Object };
        static Class cls = { type<toy::Clone>(),
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
        
        
        
        
        meta_class<toy::Clone>();
    }
    
    
        
    // toy::Cut
    {
        static Meta meta = { type<toy::Cut>(), &namspc({ "toy" }), "Cut", sizeof(toy::Cut), TypeClass::Object };
        static Class cls = { type<toy::Cut>(),
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
        
        
        
        
        meta_class<toy::Cut>();
    }
    
    
        
    // toy::Edit
    {
        static Meta meta = { type<toy::Edit>(), &namspc({ "toy" }), "Edit", sizeof(toy::Edit), TypeClass::Object };
        static Class cls = { type<toy::Edit>(),
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
        
        
        
        
        meta_class<toy::Edit>();
    }
    
    
        
    // toy::Editor
    {
        static Meta meta = { type<toy::Editor>(), &namspc({ "toy" }), "Editor", sizeof(toy::Editor), TypeClass::Object };
        static Class cls = { type<toy::Editor>(),
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
        
        
        
        
        meta_class<toy::Editor>();
    }
    
    
    
        
    // toy::Paste
    {
        static Meta meta = { type<toy::Paste>(), &namspc({ "toy" }), "Paste", sizeof(toy::Paste), TypeClass::Object };
        static Class cls = { type<toy::Paste>(),
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
        
        
        
        
        meta_class<toy::Paste>();
    }
    
    
    
        
    // toy::Toolbelt
    {
        static Meta meta = { type<toy::Toolbelt>(), &namspc({ "toy" }), "Toolbelt", sizeof(toy::Toolbelt), TypeClass::Object };
        static Class cls = { type<toy::Toolbelt>(),
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
        
        
        
        
        meta_class<toy::Toolbelt>();
    }
    
    
        
    // toy::Toolbox
    {
        static Meta meta = { type<toy::Toolbox>(), &namspc({ "toy" }), "Toolbox", sizeof(toy::Toolbox), TypeClass::Object };
        static Class cls = { type<toy::Toolbox>(),
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
        
        
        
        
        meta_class<toy::Toolbox>();
    }
    
    
        
    // toy::DynamicToolbox
    {
        static Meta meta = { type<toy::DynamicToolbox>(), &namspc({ "toy" }), "DynamicToolbox", sizeof(toy::DynamicToolbox), TypeClass::Object };
        static Class cls = { type<toy::DynamicToolbox>(),
            // bases
            { &type<toy::Toolbox>() },
            { base_offset<toy::DynamicToolbox, toy::Toolbox>() },
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
        
        
        
        
        meta_class<toy::DynamicToolbox>();
    }
    
    

    
        m.m_types.push_back(&type<toy::ActionGroup>());
        m.m_types.push_back(&type<toy::Clone>());
        m.m_types.push_back(&type<toy::Cut>());
        m.m_types.push_back(&type<toy::Edit>());
        m.m_types.push_back(&type<toy::Editor>());
        m.m_types.push_back(&type<toy::Paste>());
        m.m_types.push_back(&type<toy::Toolbelt>());
        m.m_types.push_back(&type<toy::Toolbox>());
        m.m_types.push_back(&type<toy::DynamicToolbox>());
    
    }
}
