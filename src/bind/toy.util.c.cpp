#include <type/Api.h>
#include <math/Api.h>
#include <util/Api.h>

#ifdef TWO_PLATFORM_EMSCRIPTEN
#include <emscripten.h>
#define DECL EMSCRIPTEN_KEEPALIVE
#else
#define DECL
#endif


extern "C" {
	
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
	stl::string DECL toy_ProcedureType__get_name(toy::ProcedureType* self) {
		return self->m_name;
	}
	void DECL toy_ProcedureType__set_name(toy::ProcedureType* self, stl::string value) {
		self->m_name = value;
	}
	void DECL toy_ProcedureType__destroy(toy::ProcedureType* self) {
		delete self;
	}
	// Procedure
	two::Type* DECL toy_Procedure__type() {
		return &two::type<toy::Procedure>();
	}
	void DECL toy_Procedure__destroy(toy::Procedure* self) {
		delete self;
	}
	
}


