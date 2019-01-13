#include <type/Api.h>
#include <math/Api.h>
#include <wfc-gfx/Api.h>
#include <core/Api.h>
#include <visu/Api.h>
#include <edit/Api.h>
#include <block/Api.h>
#include <emscripten.h>
#include <cstdint>


extern "C" {
	
	// Block
	toy::Block* EMSCRIPTEN_KEEPALIVE toy_Block_Block_0() {
		return new toy::Block();
	}
	toy::Block* EMSCRIPTEN_KEEPALIVE toy_Block_Block_5(toy::HSpatial spatial, toy::HWorldPage world_page, toy::Block* parentblock, size_t index, const mud::vec3* size) {
		return new toy::Block(spatial, world_page, parentblock, index, *size);
	}
	void EMSCRIPTEN_KEEPALIVE toy_Block_chunk_4(toy::Block* self, size_t x, size_t y, size_t z, toy::Element* element) {
		self->chunk(x, y, z, *element);
	}
	void EMSCRIPTEN_KEEPALIVE toy_Block_commit_0(toy::Block* self) {
		self->commit();
	}
	void EMSCRIPTEN_KEEPALIVE toy_Block_reset_0(toy::Block* self) {
		self->reset();
	}
	void EMSCRIPTEN_KEEPALIVE toy_Block_subdivide_0(toy::Block* self) {
		self->subdivide();
	}
	toy::HWorldPage EMSCRIPTEN_KEEPALIVE toy_Block_get_world_page(toy::Block* self) {
		return self->m_world_page;
	}
	void EMSCRIPTEN_KEEPALIVE toy_Block_set_world_page(toy::Block* self, toy::HWorldPage value) {
		self->m_world_page = value;
	}
	toy::Block* EMSCRIPTEN_KEEPALIVE toy_Block_get_parentblock(toy::Block* self) {
		return self->m_parentblock;
	}
	void EMSCRIPTEN_KEEPALIVE toy_Block_set_parentblock(toy::Block* self, toy::Block* value) {
		self->m_parentblock = value;
	}
	size_t EMSCRIPTEN_KEEPALIVE toy_Block_get_index(toy::Block* self) {
		return self->m_index;
	}
	void EMSCRIPTEN_KEEPALIVE toy_Block_set_index(toy::Block* self, size_t value) {
		self->m_index = value;
	}
	mud::vec3* EMSCRIPTEN_KEEPALIVE toy_Block_get_size(toy::Block* self) {
		static mud::vec3 temp;
		return (temp = self->m_size, &temp);
	}
	void EMSCRIPTEN_KEEPALIVE toy_Block_set_size(toy::Block* self, mud::vec3* value) {
		self->m_size = *value;
	}
	size_t EMSCRIPTEN_KEEPALIVE toy_Block_get_updated(toy::Block* self) {
		return self->m_updated;
	}
	void EMSCRIPTEN_KEEPALIVE toy_Block_set_updated(toy::Block* self, size_t value) {
		self->m_updated = value;
	}
	void EMSCRIPTEN_KEEPALIVE toy_Block___destroy__(toy::Block* self) {
		delete self;
	}
	// Chunk
	toy::Chunk* EMSCRIPTEN_KEEPALIVE toy_Chunk_Chunk_0() {
		return new toy::Chunk();
	}
	toy::Chunk* EMSCRIPTEN_KEEPALIVE toy_Chunk_Chunk_5(toy::HSpatial spatial, toy::Block* block, size_t index, toy::Element* element, float size) {
		return new toy::Chunk(spatial, *block, index, *element, size);
	}
	size_t EMSCRIPTEN_KEEPALIVE toy_Chunk_get_index(toy::Chunk* self) {
		return self->m_index;
	}
	void EMSCRIPTEN_KEEPALIVE toy_Chunk_set_index(toy::Chunk* self, size_t value) {
		self->m_index = value;
	}
	toy::Block* EMSCRIPTEN_KEEPALIVE toy_Chunk_get_block(toy::Chunk* self) {
		return self->m_block;
	}
	void EMSCRIPTEN_KEEPALIVE toy_Chunk_set_block(toy::Chunk* self, toy::Block* value) {
		self->m_block = value;
	}
	toy::Element* EMSCRIPTEN_KEEPALIVE toy_Chunk_get_element(toy::Chunk* self) {
		return self->m_element;
	}
	void EMSCRIPTEN_KEEPALIVE toy_Chunk_set_element(toy::Chunk* self, toy::Element* value) {
		self->m_element = value;
	}
	float EMSCRIPTEN_KEEPALIVE toy_Chunk_get_size(toy::Chunk* self) {
		return self->m_size;
	}
	void EMSCRIPTEN_KEEPALIVE toy_Chunk_set_size(toy::Chunk* self, float value) {
		self->m_size = value;
	}
	void EMSCRIPTEN_KEEPALIVE toy_Chunk___destroy__(toy::Chunk* self) {
		delete self;
	}
	// Element
	toy::Element* EMSCRIPTEN_KEEPALIVE toy_Element_Element_3(const char* name, toy::MatterState state, mud::Colour* colour) {
		return new toy::Element(name, state, *colour);
	}
	mud::Id EMSCRIPTEN_KEEPALIVE toy_Element_get_id(toy::Element* self) {
		return self->m_id;
	}
	void EMSCRIPTEN_KEEPALIVE toy_Element_set_id(toy::Element* self, mud::Id value) {
		self->m_id = value;
	}
	const char* EMSCRIPTEN_KEEPALIVE toy_Element_get_name(toy::Element* self) {
		return self->m_name.c_str();
	}
	void EMSCRIPTEN_KEEPALIVE toy_Element_set_name(toy::Element* self, const char* value) {
		self->m_name = value;
	}
	toy::MatterState EMSCRIPTEN_KEEPALIVE toy_Element_get_state(toy::Element* self) {
		return self->m_state;
	}
	void EMSCRIPTEN_KEEPALIVE toy_Element_set_state(toy::Element* self, toy::MatterState value) {
		self->m_state = value;
	}
	mud::Colour* EMSCRIPTEN_KEEPALIVE toy_Element_get_colour(toy::Element* self) {
		static mud::Colour temp;
		return (temp = self->m_colour, &temp);
	}
	void EMSCRIPTEN_KEEPALIVE toy_Element_set_colour(toy::Element* self, mud::Colour* value) {
		self->m_colour = *value;
	}
	void EMSCRIPTEN_KEEPALIVE toy_Element___destroy__(toy::Element* self) {
		delete self;
	}
	// Heap
	toy::Heap* EMSCRIPTEN_KEEPALIVE toy_Heap_Heap_0() {
		return new toy::Heap();
	}
	toy::Heap* EMSCRIPTEN_KEEPALIVE toy_Heap_Heap_3(toy::HSpatial spatial, toy::Element* element, float radius) {
		return new toy::Heap(spatial, *element, radius);
	}
	toy::Element* EMSCRIPTEN_KEEPALIVE toy_Heap_get_element(toy::Heap* self) {
		return self->m_element;
	}
	void EMSCRIPTEN_KEEPALIVE toy_Heap_set_element(toy::Heap* self, toy::Element* value) {
		self->m_element = value;
	}
	float EMSCRIPTEN_KEEPALIVE toy_Heap_get_radius(toy::Heap* self) {
		return self->m_radius;
	}
	void EMSCRIPTEN_KEEPALIVE toy_Heap_set_radius(toy::Heap* self, float value) {
		self->m_radius = value;
	}
	void EMSCRIPTEN_KEEPALIVE toy_Heap___destroy__(toy::Heap* self) {
		delete self;
	}
	// Sector
	toy::Sector* EMSCRIPTEN_KEEPALIVE toy_Sector_Sector_0() {
		return new toy::Sector();
	}
	toy::Sector* EMSCRIPTEN_KEEPALIVE toy_Sector_Sector_5(toy::HSpatial spatial, toy::HWorldPage world_page, toy::HNavblock navblock, const mud::uvec3* coordinate, const mud::vec3* size) {
		return new toy::Sector(spatial, world_page, navblock, *coordinate, *size);
	}
	mud::uvec3* EMSCRIPTEN_KEEPALIVE toy_Sector_get_coordinate(toy::Sector* self) {
		static mud::uvec3 temp;
		return (temp = self->m_coordinate, &temp);
	}
	void EMSCRIPTEN_KEEPALIVE toy_Sector_set_coordinate(toy::Sector* self, mud::uvec3* value) {
		self->m_coordinate = *value;
	}
	mud::vec3* EMSCRIPTEN_KEEPALIVE toy_Sector_get_size(toy::Sector* self) {
		static mud::vec3 temp;
		return (temp = self->m_size, &temp);
	}
	void EMSCRIPTEN_KEEPALIVE toy_Sector_set_size(toy::Sector* self, mud::vec3* value) {
		self->m_size = *value;
	}
	toy::Block* EMSCRIPTEN_KEEPALIVE toy_Sector_get_block(toy::Sector* self) {
		return self->m_block;
	}
	void EMSCRIPTEN_KEEPALIVE toy_Sector_set_block(toy::Sector* self, toy::Block* value) {
		self->m_block = value;
	}
	void EMSCRIPTEN_KEEPALIVE toy_Sector___destroy__(toy::Sector* self) {
		delete self;
	}
	// Tileblock
	toy::Tileblock* EMSCRIPTEN_KEEPALIVE toy_Tileblock_Tileblock_0() {
		return new toy::Tileblock();
	}
	toy::Tileblock* EMSCRIPTEN_KEEPALIVE toy_Tileblock_Tileblock_6(toy::HSpatial spatial, toy::HWorldPage world_page, toy::HNavblock navblock, const mud::uvec3* size, const mud::vec3* tile_scale, mud::WaveTileset* tileset) {
		return new toy::Tileblock(spatial, world_page, navblock, *size, *tile_scale, *tileset);
	}
	mud::WfcBlock* EMSCRIPTEN_KEEPALIVE toy_Tileblock_get_wfc_block(toy::Tileblock* self) {
		return &self->m_wfc_block;
	}
	bool EMSCRIPTEN_KEEPALIVE toy_Tileblock_get_setup(toy::Tileblock* self) {
		return self->m_setup;
	}
	void EMSCRIPTEN_KEEPALIVE toy_Tileblock_set_setup(toy::Tileblock* self, bool value) {
		self->m_setup = value;
	}
	bool EMSCRIPTEN_KEEPALIVE toy_Tileblock_get_populated(toy::Tileblock* self) {
		return self->m_populated;
	}
	void EMSCRIPTEN_KEEPALIVE toy_Tileblock_set_populated(toy::Tileblock* self, bool value) {
		self->m_populated = value;
	}
	void EMSCRIPTEN_KEEPALIVE toy_Tileblock___destroy__(toy::Tileblock* self) {
		delete self;
	}
	// Earth
	toy::Earth* EMSCRIPTEN_KEEPALIVE toy_Earth_Earth_0() {
		return new toy::Earth();
	}
	void EMSCRIPTEN_KEEPALIVE toy_Earth___destroy__(toy::Earth* self) {
		delete self;
	}
	// MatterState
	toy::MatterState EMSCRIPTEN_KEEPALIVE toy_MatterState_Solid() {
		return toy::MatterState::Solid;
	}
	toy::MatterState EMSCRIPTEN_KEEPALIVE toy_MatterState_Liquid() {
		return toy::MatterState::Liquid;
	}
	toy::MatterState EMSCRIPTEN_KEEPALIVE toy_MatterState_Gas() {
		return toy::MatterState::Gas;
	}
	toy::MatterState EMSCRIPTEN_KEEPALIVE toy_MatterState_Plasma() {
		return toy::MatterState::Plasma;
	}
	
}


