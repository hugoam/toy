#include <type/Api.h>
#include <math/Api.h>
#include <util/Api.h>
#include <emscripten.h>


extern "C" {
	
	// Not using size_t for array indices as the values used by the javascript code are signed.
	void array_bounds_check(const int array_size, const int array_idx) {
		  if (array_idx < 0 || array_idx >= array_size) {
			    EM_ASM({
				      throw 'Array index ' + $0 + ' out of bounds: [0,' + $1 + ')';
				    }, array_idx, array_size);
			  }
	}
	// Procedure
	void EMSCRIPTEN_KEEPALIVE Procedure___destroy__(toy::Procedure* self) {
		delete self;
	}
	// ProcedureType
	mud::Type* EMSCRIPTEN_KEEPALIVE ProcedureType_get_type(toy::ProcedureType* self) {
		return &self->m_type;
	}
	void EMSCRIPTEN_KEEPALIVE ProcedureType_set_type(toy::ProcedureType* self, mud::Type* type) {
		self->m_type = *type;
	}
	uint32_t EMSCRIPTEN_KEEPALIVE ProcedureType_get_index(toy::ProcedureType* self) {
		return self->m_index;
	}
	void EMSCRIPTEN_KEEPALIVE ProcedureType_set_index(toy::ProcedureType* self, uint32_t index) {
		self->m_index = index;
	}
	const char* EMSCRIPTEN_KEEPALIVE ProcedureType_get_name(toy::ProcedureType* self) {
		return self->m_name.c_str();
	}
	void EMSCRIPTEN_KEEPALIVE ProcedureType_set_name(toy::ProcedureType* self, const char* name) {
		self->m_name = name;
	}
	void EMSCRIPTEN_KEEPALIVE ProcedureType___destroy__(toy::ProcedureType* self) {
		delete self;
	}
	
}


