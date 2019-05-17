#include <type/Api.h>
#include <math/Api.h>
#include <util/Api.h>

#ifdef MUD_PLATFORM_EMSCRIPTEN
#include <emscripten.h>
#define DECL EMSCRIPTEN_KEEPALIVE
#else
#define DECL
#endif


extern "C" {
	
	// Procedure
	two::Type* DECL toy_Procedure__type() {
		return &two::type<toy::Procedure>();
	}
	void DECL toy_Procedure__destroy(toy::Procedure* self) {
		delete self;
	}
	// ProcedureType
	two::Type* DECL toy_ProcedureType__type() {
		return &two::type<toy::ProcedureType>();
	}
	two::Type* DECL toy_ProcedureType__get_type(toy::ProcedureType* self) {
		return &self->m_type;
	}
	uint32_t DECL toy_ProcedureType__get_index(toy::ProcedureType* self) {
		return self->m_index;
	}
	void DECL toy_ProcedureType__set_index(toy::ProcedureType* self, uint32_t value) {
		self->m_index = value;
	}
	const char* DECL toy_ProcedureType__get_name(toy::ProcedureType* self) {
		return self->m_name.c_str();
	}
	void DECL toy_ProcedureType__set_name(toy::ProcedureType* self, const char* value) {
		self->m_name = value;
	}
	void DECL toy_ProcedureType__destroy(toy::ProcedureType* self) {
		delete self;
	}
	
}


