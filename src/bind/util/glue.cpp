#include <type/Api.h>
#include <math/Api.h>
#include <util/Api.h>
#include <emscripten.h>
#include <cstdint>


extern "C" {
	
	// Procedure
	void EMSCRIPTEN_KEEPALIVE toy_Procedure___destroy__(toy::Procedure* self) {
		delete self;
	}
	// ProcedureType
	mud::Type* EMSCRIPTEN_KEEPALIVE toy_ProcedureType_get_type(toy::ProcedureType* self) {
		return &self->m_type;
	}
	uint32_t EMSCRIPTEN_KEEPALIVE toy_ProcedureType_get_index(toy::ProcedureType* self) {
		return self->m_index;
	}
	void EMSCRIPTEN_KEEPALIVE toy_ProcedureType_set_index(toy::ProcedureType* self, uint32_t value) {
		self->m_index = value;
	}
	const char* EMSCRIPTEN_KEEPALIVE toy_ProcedureType_get_name(toy::ProcedureType* self) {
		return self->m_name.c_str();
	}
	void EMSCRIPTEN_KEEPALIVE toy_ProcedureType_set_name(toy::ProcedureType* self, const char* value) {
		self->m_name = value;
	}
	void EMSCRIPTEN_KEEPALIVE toy_ProcedureType___destroy__(toy::ProcedureType* self) {
		delete self;
	}
	
}


