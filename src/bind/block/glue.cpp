#include <type/Api.h>
#include <math/Api.h>
#include <wfc-gfx/Api.h>
#include <core/Api.h>
#include <visu/Api.h>
#include <edit/Api.h>
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
	toy::Block* EMSCRIPTEN_KEEPALIVE Block_Block_5(toy::HSpatial spatial, toy::HWorldPage world_page, Block parentblock, size_t index, const vec3 size) {
		return new toy::Block(spatial, world_page, parentblock, index, *size);
	}
	void EMSCRIPTEN_KEEPALIVE Block_subdivide_0(toy::Block* self) {
		self->subdivide();
	}
	void EMSCRIPTEN_KEEPALIVE Block_reset_0(toy::Block* self) {
		self->reset();
	}
	void EMSCRIPTEN_KEEPALIVE Block_chunk_4(toy::Block* self, size_t x, size_t y, size_t z, Element element) {
		self->chunk(x, y, z, *element);
	}
	void EMSCRIPTEN_KEEPALIVE Block_commit_0(toy::Block* self) {
		self->commit();
	}
	toy::HWorldPage EMSCRIPTEN_KEEPALIVE Block_get_world_page(toy::Block* self) {
		return self->m_world_page;
	}
	void EMSCRIPTEN_KEEPALIVE Block_set_world_page(toy::Block* self, toy::HWorldPage world_page) {
		self->m_world_page = world_page;
	}
	Block EMSCRIPTEN_KEEPALIVE Block_get_parentblock(toy::Block* self) {
		return self->m_parentblock;
	}
	void EMSCRIPTEN_KEEPALIVE Block_set_parentblock(toy::Block* self, Block parentblock) {
		self->m_parentblock = parentblock;
	}
	size_t EMSCRIPTEN_KEEPALIVE Block_get_index(toy::Block* self) {
		return self->m_index;
	}
	void EMSCRIPTEN_KEEPALIVE Block_set_index(toy::Block* self, size_t index) {
		self->m_index = index;
	}
	vec3 EMSCRIPTEN_KEEPALIVE Block_get_size(toy::Block* self) {
		return self->m_size;
	}
	void EMSCRIPTEN_KEEPALIVE Block_set_size(toy::Block* self, vec3 size) {
		self->m_size = size;
	}
	size_t EMSCRIPTEN_KEEPALIVE Block_get_updated(toy::Block* self) {
		return self->m_updated;
	}
	void EMSCRIPTEN_KEEPALIVE Block_set_updated(toy::Block* self, size_t updated) {
		self->m_updated = updated;
	}
	void EMSCRIPTEN_KEEPALIVE Block___destroy__(toy::Block* self) {
		delete self;
	}
	// Chunk
	toy::Chunk* EMSCRIPTEN_KEEPALIVE Chunk_Chunk_0() {
		return new toy::Chunk();
	}
	toy::Chunk* EMSCRIPTEN_KEEPALIVE Chunk_Chunk_5(toy::HSpatial spatial, Block block, size_t index, Element element, float size) {
		return new toy::Chunk(spatial, *block, index, *element, size);
	}
	size_t EMSCRIPTEN_KEEPALIVE Chunk_get_index(toy::Chunk* self) {
		return self->m_index;
	}
	void EMSCRIPTEN_KEEPALIVE Chunk_set_index(toy::Chunk* self, size_t index) {
		self->m_index = index;
	}
	Block EMSCRIPTEN_KEEPALIVE Chunk_get_block(toy::Chunk* self) {
		return self->m_block;
	}
	void EMSCRIPTEN_KEEPALIVE Chunk_set_block(toy::Chunk* self, Block block) {
		self->m_block = block;
	}
	Element EMSCRIPTEN_KEEPALIVE Chunk_get_element(toy::Chunk* self) {
		return self->m_element;
	}
	void EMSCRIPTEN_KEEPALIVE Chunk_set_element(toy::Chunk* self, Element element) {
		self->m_element = element;
	}
	float EMSCRIPTEN_KEEPALIVE Chunk_get_size(toy::Chunk* self) {
		return self->m_size;
	}
	void EMSCRIPTEN_KEEPALIVE Chunk_set_size(toy::Chunk* self, float size) {
		self->m_size = size;
	}
	void EMSCRIPTEN_KEEPALIVE Chunk___destroy__(toy::Chunk* self) {
		delete self;
	}
	// Element
	toy::Element* EMSCRIPTEN_KEEPALIVE Element_Element_3(const char* name, MatterState state, Colour colour) {
		return new toy::Element(name, state, colour);
	}
	mud::Id EMSCRIPTEN_KEEPALIVE Element_get_id(toy::Element* self) {
		return self->m_id;
	}
	void EMSCRIPTEN_KEEPALIVE Element_set_id(toy::Element* self, mud::Id id) {
		self->m_id = id;
	}
	std::string EMSCRIPTEN_KEEPALIVE Element_get_name(toy::Element* self) {
		return self->m_name;
	}
	void EMSCRIPTEN_KEEPALIVE Element_set_name(toy::Element* self, std::string name) {
		self->m_name = name;
	}
	MatterState EMSCRIPTEN_KEEPALIVE Element_get_state(toy::Element* self) {
		return self->m_state;
	}
	void EMSCRIPTEN_KEEPALIVE Element_set_state(toy::Element* self, MatterState state) {
		self->m_state = state;
	}
	Colour EMSCRIPTEN_KEEPALIVE Element_get_colour(toy::Element* self) {
		return self->m_colour;
	}
	void EMSCRIPTEN_KEEPALIVE Element_set_colour(toy::Element* self, Colour colour) {
		self->m_colour = colour;
	}
	void EMSCRIPTEN_KEEPALIVE Element___destroy__(toy::Element* self) {
		delete self;
	}
	// Heap
	toy::Heap* EMSCRIPTEN_KEEPALIVE Heap_Heap_0() {
		return new toy::Heap();
	}
	toy::Heap* EMSCRIPTEN_KEEPALIVE Heap_Heap_3(toy::HSpatial spatial, Element element, float radius) {
		return new toy::Heap(spatial, *element, radius);
	}
	Element EMSCRIPTEN_KEEPALIVE Heap_get_element(toy::Heap* self) {
		return self->m_element;
	}
	void EMSCRIPTEN_KEEPALIVE Heap_set_element(toy::Heap* self, Element element) {
		self->m_element = element;
	}
	float EMSCRIPTEN_KEEPALIVE Heap_get_radius(toy::Heap* self) {
		return self->m_radius;
	}
	void EMSCRIPTEN_KEEPALIVE Heap_set_radius(toy::Heap* self, float radius) {
		self->m_radius = radius;
	}
	void EMSCRIPTEN_KEEPALIVE Heap___destroy__(toy::Heap* self) {
		delete self;
	}
	// Sector
	toy::Sector* EMSCRIPTEN_KEEPALIVE Sector_Sector_0() {
		return new toy::Sector();
	}
	toy::Sector* EMSCRIPTEN_KEEPALIVE Sector_Sector_5(toy::HSpatial spatial, toy::HWorldPage world_page, toy::HNavblock navblock, const uvec3 coordinate, const vec3 size) {
		return new toy::Sector(spatial, world_page, navblock, *coordinate, *size);
	}
	uvec3 EMSCRIPTEN_KEEPALIVE Sector_get_coordinate(toy::Sector* self) {
		return self->m_coordinate;
	}
	void EMSCRIPTEN_KEEPALIVE Sector_set_coordinate(toy::Sector* self, uvec3 coordinate) {
		self->m_coordinate = coordinate;
	}
	vec3 EMSCRIPTEN_KEEPALIVE Sector_get_size(toy::Sector* self) {
		return self->m_size;
	}
	void EMSCRIPTEN_KEEPALIVE Sector_set_size(toy::Sector* self, vec3 size) {
		self->m_size = size;
	}
	Block EMSCRIPTEN_KEEPALIVE Sector_get_block(toy::Sector* self) {
		return self->m_block;
	}
	void EMSCRIPTEN_KEEPALIVE Sector_set_block(toy::Sector* self, Block block) {
		self->m_block = block;
	}
	void EMSCRIPTEN_KEEPALIVE Sector___destroy__(toy::Sector* self) {
		delete self;
	}
	// Tileblock
	toy::Tileblock* EMSCRIPTEN_KEEPALIVE Tileblock_Tileblock_0() {
		return new toy::Tileblock();
	}
	toy::Tileblock* EMSCRIPTEN_KEEPALIVE Tileblock_Tileblock_6(toy::HSpatial spatial, toy::HWorldPage world_page, toy::HNavblock navblock, const uvec3 size, const vec3 tile_scale, WaveTileset tileset) {
		return new toy::Tileblock(spatial, world_page, navblock, *size, *tile_scale, *tileset);
	}
	WfcBlock EMSCRIPTEN_KEEPALIVE Tileblock_get_wfc_block(toy::Tileblock* self) {
		return self->m_wfc_block;
	}
	void EMSCRIPTEN_KEEPALIVE Tileblock_set_wfc_block(toy::Tileblock* self, WfcBlock wfc_block) {
		self->m_wfc_block = wfc_block;
	}
	bool EMSCRIPTEN_KEEPALIVE Tileblock_get_setup(toy::Tileblock* self) {
		return self->m_setup;
	}
	void EMSCRIPTEN_KEEPALIVE Tileblock_set_setup(toy::Tileblock* self, bool setup) {
		self->m_setup = setup;
	}
	bool EMSCRIPTEN_KEEPALIVE Tileblock_get_populated(toy::Tileblock* self) {
		return self->m_populated;
	}
	void EMSCRIPTEN_KEEPALIVE Tileblock_set_populated(toy::Tileblock* self, bool populated) {
		self->m_populated = populated;
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
	
}


