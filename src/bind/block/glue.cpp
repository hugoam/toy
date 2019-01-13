#include <type/Api.h>
#include <math/Api.h>
#include <wfc-gfx/Api.h>
#include <core/Api.h>
#include <visu/Api.h>
#include <edit/Api.h>
#include <block/Api.h>
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
	// Block
	toy::Block* EMSCRIPTEN_KEEPALIVE Block_Block_0() {
		return new toy::Block();
	}
	toy::Block* EMSCRIPTEN_KEEPALIVE Block_Block_5(toy::HSpatial spatial, toy::HWorldPage world_page, toy::Block* parentblock, size_t index, const mud::vec3* size) {
		return new toy::Block(spatial, world_page, parentblock, index, *size);
	}
	void EMSCRIPTEN_KEEPALIVE Block_subdivide_0(toy::Block* self) {
		self->subdivide();
	}
	void EMSCRIPTEN_KEEPALIVE Block_reset_0(toy::Block* self) {
		self->reset();
	}
	void EMSCRIPTEN_KEEPALIVE Block_chunk_4(toy::Block* self, size_t x, size_t y, size_t z, toy::Element* element) {
		self->chunk(x, y, z, *element);
	}
	void EMSCRIPTEN_KEEPALIVE Block_commit_0(toy::Block* self) {
		self->commit();
	}
	toy::HWorldPage EMSCRIPTEN_KEEPALIVE Block_get_world_page(toy::Block* self) {
		return self->m_world_page;
	}
	toy::Block* EMSCRIPTEN_KEEPALIVE Block_get_parentblock(toy::Block* self) {
		return self->m_parentblock;
	}
	size_t EMSCRIPTEN_KEEPALIVE Block_get_index(toy::Block* self) {
		return self->m_index;
	}
	mud::vec3* EMSCRIPTEN_KEEPALIVE Block_get_size(toy::Block* self) {
		static mud::vec3 temp;
		return (temp = &self->m_size, &temp);
	}
	size_t EMSCRIPTEN_KEEPALIVE Block_get_updated(toy::Block* self) {
		return self->m_updated;
	}
	void EMSCRIPTEN_KEEPALIVE Block___destroy__(toy::Block* self) {
		delete self;
	}
	// Chunk
	toy::Chunk* EMSCRIPTEN_KEEPALIVE Chunk_Chunk_0() {
		return new toy::Chunk();
	}
	toy::Chunk* EMSCRIPTEN_KEEPALIVE Chunk_Chunk_5(toy::HSpatial spatial, toy::Block* block, size_t index, toy::Element* element, float size) {
		return new toy::Chunk(spatial, *block, index, *element, size);
	}
	size_t EMSCRIPTEN_KEEPALIVE Chunk_get_index(toy::Chunk* self) {
		return self->m_index;
	}
	toy::Block* EMSCRIPTEN_KEEPALIVE Chunk_get_block(toy::Chunk* self) {
		return self->m_block;
	}
	toy::Element* EMSCRIPTEN_KEEPALIVE Chunk_get_element(toy::Chunk* self) {
		return self->m_element;
	}
	float EMSCRIPTEN_KEEPALIVE Chunk_get_size(toy::Chunk* self) {
		return self->m_size;
	}
	void EMSCRIPTEN_KEEPALIVE Chunk___destroy__(toy::Chunk* self) {
		delete self;
	}
	// Element
	toy::Element* EMSCRIPTEN_KEEPALIVE Element_Element_3(const char* name, toy::MatterState state, mud::Colour* colour) {
		return new toy::Element(name, state, colour);
	}
	mud::Id EMSCRIPTEN_KEEPALIVE Element_get_id(toy::Element* self) {
		return self->m_id;
	}
	std::string EMSCRIPTEN_KEEPALIVE Element_get_name(toy::Element* self) {
		return self->m_name;
	}
	toy::MatterState EMSCRIPTEN_KEEPALIVE Element_get_state(toy::Element* self) {
		static toy::MatterState temp;
		return (temp = &self->m_state, &temp);
	}
	mud::Colour* EMSCRIPTEN_KEEPALIVE Element_get_colour(toy::Element* self) {
		static mud::Colour temp;
		return (temp = &self->m_colour, &temp);
	}
	void EMSCRIPTEN_KEEPALIVE Element___destroy__(toy::Element* self) {
		delete self;
	}
	// Heap
	toy::Heap* EMSCRIPTEN_KEEPALIVE Heap_Heap_0() {
		return new toy::Heap();
	}
	toy::Heap* EMSCRIPTEN_KEEPALIVE Heap_Heap_3(toy::HSpatial spatial, toy::Element* element, float radius) {
		return new toy::Heap(spatial, *element, radius);
	}
	toy::Element* EMSCRIPTEN_KEEPALIVE Heap_get_element(toy::Heap* self) {
		return self->m_element;
	}
	float EMSCRIPTEN_KEEPALIVE Heap_get_radius(toy::Heap* self) {
		return self->m_radius;
	}
	void EMSCRIPTEN_KEEPALIVE Heap___destroy__(toy::Heap* self) {
		delete self;
	}
	// Sector
	toy::Sector* EMSCRIPTEN_KEEPALIVE Sector_Sector_0() {
		return new toy::Sector();
	}
	toy::Sector* EMSCRIPTEN_KEEPALIVE Sector_Sector_5(toy::HSpatial spatial, toy::HWorldPage world_page, toy::HNavblock navblock, const mud::uvec3* coordinate, const mud::vec3* size) {
		return new toy::Sector(spatial, world_page, navblock, *coordinate, *size);
	}
	mud::uvec3* EMSCRIPTEN_KEEPALIVE Sector_get_coordinate(toy::Sector* self) {
		static mud::uvec3 temp;
		return (temp = &self->m_coordinate, &temp);
	}
	mud::vec3* EMSCRIPTEN_KEEPALIVE Sector_get_size(toy::Sector* self) {
		static mud::vec3 temp;
		return (temp = &self->m_size, &temp);
	}
	toy::Block* EMSCRIPTEN_KEEPALIVE Sector_get_block(toy::Sector* self) {
		return self->m_block;
	}
	void EMSCRIPTEN_KEEPALIVE Sector___destroy__(toy::Sector* self) {
		delete self;
	}
	// Tileblock
	toy::Tileblock* EMSCRIPTEN_KEEPALIVE Tileblock_Tileblock_0() {
		return new toy::Tileblock();
	}
	toy::Tileblock* EMSCRIPTEN_KEEPALIVE Tileblock_Tileblock_6(toy::HSpatial spatial, toy::HWorldPage world_page, toy::HNavblock navblock, const mud::uvec3* size, const mud::vec3* tile_scale, mud::WaveTileset* tileset) {
		return new toy::Tileblock(spatial, world_page, navblock, *size, *tile_scale, *tileset);
	}
	mud::WfcBlock* EMSCRIPTEN_KEEPALIVE Tileblock_get_wfc_block(toy::Tileblock* self) {
		static mud::WfcBlock temp;
		return (temp = &self->m_wfc_block, &temp);
	}
	bool EMSCRIPTEN_KEEPALIVE Tileblock_get_setup(toy::Tileblock* self) {
		return self->m_setup;
	}
	bool EMSCRIPTEN_KEEPALIVE Tileblock_get_populated(toy::Tileblock* self) {
		return self->m_populated;
	}
	void EMSCRIPTEN_KEEPALIVE Tileblock___destroy__(toy::Tileblock* self) {
		delete self;
	}
	// Earth
	toy::Earth* EMSCRIPTEN_KEEPALIVE Earth_Earth_0() {
		return new toy::Earth();
	}
	void EMSCRIPTEN_KEEPALIVE Earth___destroy__(toy::Earth* self) {
		delete self;
	}
	// MatterState
	toy::MatterState EMSCRIPTEN_KEEPALIVE emscripten_enum_MatterState_Solid() {
		return toy::MatterState::Solid;
	}
	toy::MatterState EMSCRIPTEN_KEEPALIVE emscripten_enum_MatterState_Liquid() {
		return toy::MatterState::Liquid;
	}
	toy::MatterState EMSCRIPTEN_KEEPALIVE emscripten_enum_MatterState_Gas() {
		return toy::MatterState::Gas;
	}
	toy::MatterState EMSCRIPTEN_KEEPALIVE emscripten_enum_MatterState_Plasma() {
		return toy::MatterState::Plasma;
	}
	
}


