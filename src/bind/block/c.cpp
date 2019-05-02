#include <type/Api.h>
#include <math/Api.h>
#include <wfc-gfx/Api.h>
#include <core/Api.h>
#include <visu/Api.h>
#include <edit/Api.h>
#include <block/Api.h>

#ifdef MUD_PLATFORM_EMSCRIPTEN
#include <emscripten.h>
#define DECL EMSCRIPTEN_KEEPALIVE
#else
#define DECL
#endif


extern "C" {
	
	// Block
	two::Type* DECL toy_Block__type() {
		return &two::type<toy::Block>();
	}
	toy::Block* DECL toy_Block_Block_0() {
		return new toy::Block();
	}
	toy::Block* DECL toy_Block_Block_5(toy::HSpatial spatial, toy::HWorldPage world_page, toy::Block* parentblock, size_t index, const two::vec3* size) {
		return new toy::Block(spatial, world_page, parentblock, index, *size);
	}
	void DECL toy_Block_subdivide_0(toy::Block* self) {
		self->subdivide();
	}
	void DECL toy_Block_reset_0(toy::Block* self) {
		self->reset();
	}
	void DECL toy_Block_chunk_4(toy::Block* self, size_t x, size_t y, size_t z, toy::Element* element) {
		self->chunk(x, y, z, *element);
	}
	void DECL toy_Block_commit_0(toy::Block* self) {
		self->commit();
	}
	toy::HWorldPage DECL toy_Block__get_world_page(toy::Block* self) {
		return self->m_world_page;
	}
	void DECL toy_Block__set_world_page(toy::Block* self, toy::HWorldPage value) {
		self->m_world_page = value;
	}
	toy::Block* DECL toy_Block__get_parentblock(toy::Block* self) {
		return self->m_parentblock;
	}
	void DECL toy_Block__set_parentblock(toy::Block* self, toy::Block* value) {
		self->m_parentblock = value;
	}
	size_t DECL toy_Block__get_index(toy::Block* self) {
		return self->m_index;
	}
	void DECL toy_Block__set_index(toy::Block* self, size_t value) {
		self->m_index = value;
	}
	two::vec3* DECL toy_Block__get_size(toy::Block* self) {
		static two::vec3 temp;
		return (temp = self->m_size, &temp);
	}
	void DECL toy_Block__set_size(toy::Block* self, two::vec3* value) {
		self->m_size = *value;
	}
	size_t DECL toy_Block__get_updated(toy::Block* self) {
		return self->m_updated;
	}
	void DECL toy_Block__set_updated(toy::Block* self, size_t value) {
		self->m_updated = value;
	}
	void DECL toy_Block__destroy(toy::Block* self) {
		delete self;
	}
	// Chunk
	two::Type* DECL toy_Chunk__type() {
		return &two::type<toy::Chunk>();
	}
	toy::Chunk* DECL toy_Chunk_Chunk_0() {
		return new toy::Chunk();
	}
	toy::Chunk* DECL toy_Chunk_Chunk_5(toy::HSpatial spatial, toy::Block* block, size_t index, toy::Element* element, float size) {
		return new toy::Chunk(spatial, *block, index, *element, size);
	}
	size_t DECL toy_Chunk__get_index(toy::Chunk* self) {
		return self->m_index;
	}
	void DECL toy_Chunk__set_index(toy::Chunk* self, size_t value) {
		self->m_index = value;
	}
	toy::Block* DECL toy_Chunk__get_block(toy::Chunk* self) {
		return self->m_block;
	}
	void DECL toy_Chunk__set_block(toy::Chunk* self, toy::Block* value) {
		self->m_block = value;
	}
	toy::Element* DECL toy_Chunk__get_element(toy::Chunk* self) {
		return self->m_element;
	}
	void DECL toy_Chunk__set_element(toy::Chunk* self, toy::Element* value) {
		self->m_element = value;
	}
	float DECL toy_Chunk__get_size(toy::Chunk* self) {
		return self->m_size;
	}
	void DECL toy_Chunk__set_size(toy::Chunk* self, float value) {
		self->m_size = value;
	}
	void DECL toy_Chunk__destroy(toy::Chunk* self) {
		delete self;
	}
	// Element
	two::Type* DECL toy_Element__type() {
		return &two::type<toy::Element>();
	}
	toy::Element* DECL toy_Element_Element_3(const char* name, toy::MatterState state, two::Colour* colour) {
		return new toy::Element(name, state, *colour);
	}
	uint32_t DECL toy_Element__get_id(toy::Element* self) {
		return self->m_id;
	}
	void DECL toy_Element__set_id(toy::Element* self, uint32_t value) {
		self->m_id = value;
	}
	const char* DECL toy_Element__get_name(toy::Element* self) {
		return self->m_name.c_str();
	}
	void DECL toy_Element__set_name(toy::Element* self, const char* value) {
		self->m_name = value;
	}
	toy::MatterState DECL toy_Element__get_state(toy::Element* self) {
		return self->m_state;
	}
	void DECL toy_Element__set_state(toy::Element* self, toy::MatterState value) {
		self->m_state = value;
	}
	two::Colour* DECL toy_Element__get_colour(toy::Element* self) {
		static two::Colour temp;
		return (temp = self->m_colour, &temp);
	}
	void DECL toy_Element__set_colour(toy::Element* self, two::Colour* value) {
		self->m_colour = *value;
	}
	void DECL toy_Element__destroy(toy::Element* self) {
		delete self;
	}
	// Heap
	two::Type* DECL toy_Heap__type() {
		return &two::type<toy::Heap>();
	}
	toy::Heap* DECL toy_Heap_Heap_0() {
		return new toy::Heap();
	}
	toy::Heap* DECL toy_Heap_Heap_3(toy::HSpatial spatial, toy::Element* element, float radius) {
		return new toy::Heap(spatial, *element, radius);
	}
	toy::Element* DECL toy_Heap__get_element(toy::Heap* self) {
		return self->m_element;
	}
	void DECL toy_Heap__set_element(toy::Heap* self, toy::Element* value) {
		self->m_element = value;
	}
	float DECL toy_Heap__get_radius(toy::Heap* self) {
		return self->m_radius;
	}
	void DECL toy_Heap__set_radius(toy::Heap* self, float value) {
		self->m_radius = value;
	}
	void DECL toy_Heap__destroy(toy::Heap* self) {
		delete self;
	}
	// Sector
	two::Type* DECL toy_Sector__type() {
		return &two::type<toy::Sector>();
	}
	toy::Sector* DECL toy_Sector_Sector_0() {
		return new toy::Sector();
	}
	toy::Sector* DECL toy_Sector_Sector_5(toy::HSpatial spatial, toy::HWorldPage world_page, toy::HNavblock navblock, const two::uvec3* coordinate, const two::vec3* size) {
		return new toy::Sector(spatial, world_page, navblock, *coordinate, *size);
	}
	two::uvec3* DECL toy_Sector__get_coordinate(toy::Sector* self) {
		static two::uvec3 temp;
		return (temp = self->m_coordinate, &temp);
	}
	void DECL toy_Sector__set_coordinate(toy::Sector* self, two::uvec3* value) {
		self->m_coordinate = *value;
	}
	two::vec3* DECL toy_Sector__get_size(toy::Sector* self) {
		static two::vec3 temp;
		return (temp = self->m_size, &temp);
	}
	void DECL toy_Sector__set_size(toy::Sector* self, two::vec3* value) {
		self->m_size = *value;
	}
	toy::Block* DECL toy_Sector__get_block(toy::Sector* self) {
		return self->m_block;
	}
	void DECL toy_Sector__set_block(toy::Sector* self, toy::Block* value) {
		self->m_block = value;
	}
	void DECL toy_Sector__destroy(toy::Sector* self) {
		delete self;
	}
	// Tileblock
	two::Type* DECL toy_Tileblock__type() {
		return &two::type<toy::Tileblock>();
	}
	toy::Tileblock* DECL toy_Tileblock_Tileblock_0() {
		return new toy::Tileblock();
	}
	toy::Tileblock* DECL toy_Tileblock_Tileblock_6(toy::HSpatial spatial, toy::HWorldPage world_page, toy::HNavblock navblock, const two::uvec3* size, const two::vec3* tile_scale, two::WaveTileset* tileset) {
		return new toy::Tileblock(spatial, world_page, navblock, *size, *tile_scale, *tileset);
	}
	two::WfcBlock* DECL toy_Tileblock__get_wfc_block(toy::Tileblock* self) {
		return &self->m_wfc_block;
	}
	bool DECL toy_Tileblock__get_setup(toy::Tileblock* self) {
		return self->m_setup;
	}
	void DECL toy_Tileblock__set_setup(toy::Tileblock* self, bool value) {
		self->m_setup = value;
	}
	bool DECL toy_Tileblock__get_populated(toy::Tileblock* self) {
		return self->m_populated;
	}
	void DECL toy_Tileblock__set_populated(toy::Tileblock* self, bool value) {
		self->m_populated = value;
	}
	void DECL toy_Tileblock__destroy(toy::Tileblock* self) {
		delete self;
	}
	// Earth
	two::Type* DECL toy_Earth__type() {
		return &two::type<toy::Earth>();
	}
	toy::Earth* DECL toy_Earth_Earth_0() {
		return new toy::Earth();
	}
	void DECL toy_Earth__destroy(toy::Earth* self) {
		delete self;
	}
	void DECL toy_paint_block_height_3(toy::Block* block, two::Image256* image, toy::Element* element) {
		toy::paint_block_height(*block, *image, *element);
	}
	toy::HTileblock DECL toy_generate_block_6(two::GfxSystem* gfx_system, two::WaveTileset* tileset, toy::HSpatial origin, const two::ivec2* coord, const two::uvec3* block_subdiv, const two::vec3* tile_scale) {
		return toy::generate_block(*gfx_system, *tileset, origin, *coord, *block_subdiv, *tile_scale);
	}
	toy::HTileblock DECL toy_generate_block_7(two::GfxSystem* gfx_system, two::WaveTileset* tileset, toy::HSpatial origin, const two::ivec2* coord, const two::uvec3* block_subdiv, const two::vec3* tile_scale, bool from_file) {
		return toy::generate_block(*gfx_system, *tileset, origin, *coord, *block_subdiv, *tile_scale, from_file);
	}
	void DECL toy_build_block_geometry_3(two::Scene* scene, toy::WorldPage* page, toy::Tileblock* block) {
		toy::build_block_geometry(*scene, *page, *block);
	}
	// MatterState
	toy::MatterState DECL toy_MatterState_Solid() {
		return toy::MatterState::Solid;
	}
	toy::MatterState DECL toy_MatterState_Liquid() {
		return toy::MatterState::Liquid;
	}
	toy::MatterState DECL toy_MatterState_Gas() {
		return toy::MatterState::Gas;
	}
	toy::MatterState DECL toy_MatterState_Plasma() {
		return toy::MatterState::Plasma;
	}
	
}


