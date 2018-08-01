

#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module toy.util;
#else
#include <util/Types.h>
#include <util/Api.h>
#include <obj/Vector.h>
//#include <proto/Proto.h>
#endif

namespace mud
{
    // Exported types
    
    template <> TOY_UTIL_EXPORT Type& type<toy::Loader>() { static Type ty("Loader"); return ty; }
    template <> TOY_UTIL_EXPORT Type& type<toy::Procedure>() { static Type ty("Procedure"); return ty; }
    template <> TOY_UTIL_EXPORT Type& type<toy::ProcedureType>() { static Type ty("ProcedureType"); return ty; }
    template <> TOY_UTIL_EXPORT Type& type<toy::LinkedLoader>() { static Type ty("LinkedLoader", type<toy::MemberLoader>()); return ty; }
    template <> TOY_UTIL_EXPORT Type& type<toy::SequenceLoader>() { static Type ty("SequenceLoader", type<toy::MemberLoader>()); return ty; }
    template <> TOY_UTIL_EXPORT Type& type<toy::StructureLoader>() { static Type ty("StructureLoader", type<toy::MemberLoader>()); return ty; }
    template <> TOY_UTIL_EXPORT Type& type<toy::TypeLoader>() { static Type ty("TypeLoader", type<toy::MemberLoader>()); return ty; }
    template <> TOY_UTIL_EXPORT Type& type<toy::MemberLoader>() { static Type ty("MemberLoader", type<toy::Loader>()); return ty; }
    template <> TOY_UTIL_EXPORT Type& type<toy::ObjectLoader>() { static Type ty("ObjectLoader", type<toy::Loader>()); return ty; }
    template <> TOY_UTIL_EXPORT Type& type<toy::OwnedLoader>() { static Type ty("OwnedLoader", type<toy::ObjectLoader>()); return ty; }
    template <> TOY_UTIL_EXPORT Type& type<toy::PartLoader>() { static Type ty("PartLoader", type<toy::ObjectLoader>()); return ty; }
}
