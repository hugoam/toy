

#pragma once

#ifndef MUD_MODULES
#include <meta/edit/Module.h>

#include <type/Any.h>
#include <type/Vector.h>
#include <refl/MetaDecl.h>
#include <refl/Module.h>
#endif

namespace mud
{
    void toy_edit_meta(Module& m)
    {   
    // Base Types
    
    // Enums
    
    // Sequences
    
    
    
        
    // toy::ActionGroup
    {
        static Meta meta = { type<toy::ActionGroup>(), &namspc({ "toy" }), "ActionGroup", sizeof(toy::ActionGroup), TypeClass::Struct };
        static Class cls = { type<toy::ActionGroup>(),
            // bases
            {  },
            {  },
            // constructors
            {
            },
            // copy constructor
            {
                { type<toy::ActionGroup>(), [](Ref ref, Ref other) { new(&val<toy::ActionGroup>(ref)) toy::ActionGroup(val<toy::ActionGroup>(other)); } }
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
    
    
    
        
    // toy::GraphicsDebug
    {
        static Meta meta = { type<toy::GraphicsDebug>(), &namspc({ "toy" }), "GraphicsDebug", sizeof(toy::GraphicsDebug), TypeClass::Struct };
        static Class cls = { type<toy::GraphicsDebug>(),
            // bases
            {  },
            {  },
            // constructors
            {
            },
            // copy constructor
            {
                { type<toy::GraphicsDebug>(), [](Ref ref, Ref other) { new(&val<toy::GraphicsDebug>(ref)) toy::GraphicsDebug(val<toy::GraphicsDebug>(other)); } }
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
        
        
        
        
        meta_class<toy::GraphicsDebug>();
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
    
    

	// toy::RunTool
	{
		static Meta meta = { type<toy::RunTool>(), &namspc({ "toy" }), "RunTool", sizeof(toy::RunTool), TypeClass::Object };
		static Class cls = { type<toy::RunTool>(),
			// bases
		{ &type<mud::Tool>() },
		{ base_offset<toy::RunTool, mud::Tool>() },
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




		meta_class<toy::RunTool>();
	}

        
    // toy::PlayTool
    {
        static Meta meta = { type<toy::PlayTool>(), &namspc({ "toy" }), "PlayTool", sizeof(toy::PlayTool), TypeClass::Object };
        static Class cls = { type<toy::PlayTool>(),
            // bases
            { &type<mud::Tool>() },
            { base_offset<toy::PlayTool, mud::Tool>() },
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
        
        
        
        
        meta_class<toy::PlayTool>();
    }
    
    
        
    // toy::Editor
    {
        static Meta meta = { type<toy::Editor>(), &namspc({ "toy" }), "Editor", sizeof(toy::Editor), TypeClass::Object };
        static Class cls = { type<toy::Editor>(),
            // bases
            { &type<mud::EditContext>() },
            { base_offset<toy::Editor, mud::EditContext>() },
            // constructors
            {
            },
            // copy constructor
            {
            },
            // members
            {
                { type<toy::Editor>(), member_address(&toy::Editor::m_run_tool), type<toy::RunTool>(), "run_tool", Ref(type<toy::RunTool>()), Member::None, nullptr },
				{ type<toy::Editor>(), member_address(&toy::Editor::m_play_tool), type<toy::PlayTool>(), "play_tool", Ref(type<toy::PlayTool>()), Member::None, nullptr },
				{ type<toy::Editor>(), member_address(&toy::Editor::m_frame_view_tool), type<mud::FrameViewTool>(), "frame_view_tool", Ref(type<mud::FrameViewTool>()), Member::None, nullptr },
                { type<toy::Editor>(), member_address(&toy::Editor::m_edited_world), type<toy::World>(), "edited_world", Ref(type<toy::World>()), Member::Flags(Member::Pointer|Member::Link), nullptr },
                { type<toy::Editor>(), member_address(&toy::Editor::m_run_game), type<bool>(), "run_game", var(bool(false)), Member::Value, nullptr },
				{ type<toy::Editor>(), member_address(&toy::Editor::m_play_game), type<bool>(), "play_game", var(bool(false)), Member::Value, nullptr }
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
            { },
            { },
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
    

    
        m.m_types.push_back(&type<toy::ActionGroup>());
        m.m_types.push_back(&type<toy::GraphicsDebug>());
        m.m_types.push_back(&type<toy::Toolbelt>());
        m.m_types.push_back(&type<toy::Toolbox>());
        m.m_types.push_back(&type<toy::DynamicToolbox>());
		m.m_types.push_back(&type<toy::RunTool>());
        m.m_types.push_back(&type<toy::PlayTool>());
        m.m_types.push_back(&type<toy::Editor>());
        m.m_types.push_back(&type<toy::Paste>());
        m.m_types.push_back(&type<toy::Clone>());
        m.m_types.push_back(&type<toy::Edit>());
        m.m_types.push_back(&type<toy::Cut>());
    
    }
}
