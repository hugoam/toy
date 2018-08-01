

#pragma once

#ifndef MUD_MODULES
#include <meta/util/Module.h>

#include <obj/Any.h>
#include <obj/Vector.h>
#include <refl/MetaDecl.h>
#include <refl/Module.h>
#endif

namespace mud
{
    void toy_util_meta(Module& m)
    {   
    // Base Types
    
    // Enums
    
    // Sequences
    
    
    
    
    
    
    
        
    // toy::Loader
    {
        static Meta meta = { type<toy::Loader>(), &namspc({ "toy" }), "Loader", sizeof(toy::Loader), TypeClass::Object };
        static Class cls = { type<toy::Loader>(),
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
        
        
        
        
        meta_class<toy::Loader>();
    }
    
    
        
    // toy::Procedure
    {
        static Meta meta = { type<toy::Procedure>(), &namspc({ "toy" }), "Procedure", sizeof(toy::Procedure), TypeClass::Object };
        static Class cls = { type<toy::Procedure>(),
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
        
        
        
        
        meta_class<toy::Procedure>();
    }
    
    
        
    // toy::ProcedureType
    {
        static Meta meta = { type<toy::ProcedureType>(), &namspc({ "toy" }), "ProcedureType", sizeof(toy::ProcedureType), TypeClass::Object };
        static Class cls = { type<toy::ProcedureType>(),
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
                { type<toy::ProcedureType>(), Address(), type<mud::Type>(), "type", Ref(type<mud::Type>()), Member::Flags(Member::NonMutable|Member::Link), [](Ref object) { return Ref(&val<toy::ProcedureType>(object).m_type); } },
                { type<toy::ProcedureType>(), member_address(&toy::ProcedureType::m_index), type<uint32_t>(), "index", var(uint32_t()), Member::Value, nullptr },
                { type<toy::ProcedureType>(), member_address(&toy::ProcedureType::m_name), type<std::string>(), "name", var(std::string()), Member::Value, nullptr }
            },
            // methods
            {
            },
            // static members
            {
            }
        };
        
        
        
        
        meta_class<toy::ProcedureType>();
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
        
    // toy::LinkedLoader
    {
        static Meta meta = { type<toy::LinkedLoader>(), &namspc({ "toy" }), "LinkedLoader", sizeof(toy::LinkedLoader), TypeClass::Object };
        static Class cls = { type<toy::LinkedLoader>(),
            // bases
            { &type<toy::MemberLoader>() },
            { base_offset<toy::LinkedLoader, toy::MemberLoader>() },
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
        
        
        
        
        meta_class<toy::LinkedLoader>();
    }
    
    
        
    // toy::SequenceLoader
    {
        static Meta meta = { type<toy::SequenceLoader>(), &namspc({ "toy" }), "SequenceLoader", sizeof(toy::SequenceLoader), TypeClass::Object };
        static Class cls = { type<toy::SequenceLoader>(),
            // bases
            { &type<toy::MemberLoader>() },
            { base_offset<toy::SequenceLoader, toy::MemberLoader>() },
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
        
        
        
        
        meta_class<toy::SequenceLoader>();
    }
    
    
        
    // toy::StructureLoader
    {
        static Meta meta = { type<toy::StructureLoader>(), &namspc({ "toy" }), "StructureLoader", sizeof(toy::StructureLoader), TypeClass::Object };
        static Class cls = { type<toy::StructureLoader>(),
            // bases
            { &type<toy::MemberLoader>() },
            { base_offset<toy::StructureLoader, toy::MemberLoader>() },
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
        
        
        
        
        meta_class<toy::StructureLoader>();
    }
    
    
        
    // toy::TypeLoader
    {
        static Meta meta = { type<toy::TypeLoader>(), &namspc({ "toy" }), "TypeLoader", sizeof(toy::TypeLoader), TypeClass::Object };
        static Class cls = { type<toy::TypeLoader>(),
            // bases
            { &type<toy::MemberLoader>() },
            { base_offset<toy::TypeLoader, toy::MemberLoader>() },
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
        
        
        
        
        meta_class<toy::TypeLoader>();
    }
    
    
        
    // toy::MemberLoader
    {
        static Meta meta = { type<toy::MemberLoader>(), &namspc({ "toy" }), "MemberLoader", sizeof(toy::MemberLoader), TypeClass::Object };
        static Class cls = { type<toy::MemberLoader>(),
            // bases
            { &type<toy::Loader>() },
            { base_offset<toy::MemberLoader, toy::Loader>() },
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
        
        
        
        
        meta_class<toy::MemberLoader>();
    }
    
    
        
    // toy::ObjectLoader
    {
        static Meta meta = { type<toy::ObjectLoader>(), &namspc({ "toy" }), "ObjectLoader", sizeof(toy::ObjectLoader), TypeClass::Object };
        static Class cls = { type<toy::ObjectLoader>(),
            // bases
            { &type<toy::Loader>() },
            { base_offset<toy::ObjectLoader, toy::Loader>() },
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
        
        
        
        
        meta_class<toy::ObjectLoader>();
    }
    
    
        
    // toy::OwnedLoader
    {
        static Meta meta = { type<toy::OwnedLoader>(), &namspc({ "toy" }), "OwnedLoader", sizeof(toy::OwnedLoader), TypeClass::Object };
        static Class cls = { type<toy::OwnedLoader>(),
            // bases
            { &type<toy::ObjectLoader>() },
            { base_offset<toy::OwnedLoader, toy::ObjectLoader>() },
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
        
        
        
        
        meta_class<toy::OwnedLoader>();
    }
    
    
        
    // toy::PartLoader
    {
        static Meta meta = { type<toy::PartLoader>(), &namspc({ "toy" }), "PartLoader", sizeof(toy::PartLoader), TypeClass::Object };
        static Class cls = { type<toy::PartLoader>(),
            // bases
            { &type<toy::ObjectLoader>() },
            { base_offset<toy::PartLoader, toy::ObjectLoader>() },
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
        
        
        
        
        meta_class<toy::PartLoader>();
    }
    

    
        m.m_types.push_back(&type<toy::Loader>());
        m.m_types.push_back(&type<toy::Procedure>());
        m.m_types.push_back(&type<toy::ProcedureType>());
        m.m_types.push_back(&type<toy::LinkedLoader>());
        m.m_types.push_back(&type<toy::SequenceLoader>());
        m.m_types.push_back(&type<toy::StructureLoader>());
        m.m_types.push_back(&type<toy::TypeLoader>());
        m.m_types.push_back(&type<toy::MemberLoader>());
        m.m_types.push_back(&type<toy::ObjectLoader>());
        m.m_types.push_back(&type<toy::OwnedLoader>());
        m.m_types.push_back(&type<toy::PartLoader>());
    
    }
}
