
// Bindings utilities
function WrapperObject() {
}
// Block
/** @suppress {undefinedVars, duplicate} */ function Block(spatial, world_page, parentblock, index, size) {
    var self = this.ptr;
    /* spatial <toy::HSpatial> [] */
    /* world_page <toy::HWorldPage> [] */
    /* parentblock <Block> [] */
    /* index <size_t> [] */
    /* size <vec3> [] */
};
Block.prototype = Object.create(WrapperObject.prototype);
Block.prototype.constructor = Block;
Block.prototype.__class__ = Block;
Block.__cache__ = {};
Module['Block'] = Block;

Block.prototype["chunk"] = Block.prototype.chunk = /** @suppress {undefinedVars, duplicate} */ function(x, y, z, element) {
    /* x <size_t> [] */
    /* y <size_t> [] */
    /* z <size_t> [] */
    /* element <Element> [] */
};

Block.prototype["commit"] = Block.prototype.commit = /** @suppress {undefinedVars, duplicate} */ function() {
};

Block.prototype["reset"] = Block.prototype.reset = /** @suppress {undefinedVars, duplicate} */ function() {
};

Block.prototype["subdivide"] = Block.prototype.subdivide = /** @suppress {undefinedVars, duplicate} */ function() {
};

Block.prototype["get_world_page"] = Block.prototype.get_world_page = function() {
    var self = this.ptr;
    return _Block_get_world_page(self);
};

Block.prototype["set_world_page"] = Block.prototype.set_world_page = function(world_page) {
    var self = this.ptr;
    /* world_page <toy::HWorldPage> [] */
    _Block_set_world_page(self, world_page);
};

Object.defineProperty(Block.prototype, "world_page", { get: Block.prototype.get_world_page, set: Block.prototype.set_world_page }) 

Block.prototype["get_parentblock"] = Block.prototype.get_parentblock = function() {
    var self = this.ptr;
    return _Block_get_parentblock(self);
};

Block.prototype["set_parentblock"] = Block.prototype.set_parentblock = function(parentblock) {
    var self = this.ptr;
    /* parentblock <Block> [] */
    _Block_set_parentblock(self, parentblock);
};

Object.defineProperty(Block.prototype, "parentblock", { get: Block.prototype.get_parentblock, set: Block.prototype.set_parentblock }) 

Block.prototype["get_index"] = Block.prototype.get_index = function() {
    var self = this.ptr;
    return _Block_get_index(self);
};

Block.prototype["set_index"] = Block.prototype.set_index = function(index) {
    var self = this.ptr;
    /* index <size_t> [] */
    _Block_set_index(self, index);
};

Object.defineProperty(Block.prototype, "index", { get: Block.prototype.get_index, set: Block.prototype.set_index }) 

Block.prototype["get_size"] = Block.prototype.get_size = function() {
    var self = this.ptr;
    return _Block_get_size(self);
};

Block.prototype["set_size"] = Block.prototype.set_size = function(size) {
    var self = this.ptr;
    /* size <vec3> [] */
    _Block_set_size(self, size);
};

Object.defineProperty(Block.prototype, "size", { get: Block.prototype.get_size, set: Block.prototype.set_size }) 

Block.prototype["get_updated"] = Block.prototype.get_updated = function() {
    var self = this.ptr;
    return _Block_get_updated(self);
};

Block.prototype["set_updated"] = Block.prototype.set_updated = function(updated) {
    var self = this.ptr;
    /* updated <size_t> [] */
    _Block_set_updated(self, updated);
};

Object.defineProperty(Block.prototype, "updated", { get: Block.prototype.get_updated, set: Block.prototype.set_updated }) 

Block.prototype["__destroy__"] = Block.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Block___destroy__(self);
};
// Chunk
/** @suppress {undefinedVars, duplicate} */ function Chunk(spatial, block, index, element, size) {
    var self = this.ptr;
    /* spatial <toy::HSpatial> [] */
    /* block <Block> [] */
    /* index <size_t> [] */
    /* element <Element> [] */
    /* size <float> [] */
};
Chunk.prototype = Object.create(WrapperObject.prototype);
Chunk.prototype.constructor = Chunk;
Chunk.prototype.__class__ = Chunk;
Chunk.__cache__ = {};
Module['Chunk'] = Chunk;

Chunk.prototype["get_index"] = Chunk.prototype.get_index = function() {
    var self = this.ptr;
    return _Chunk_get_index(self);
};

Chunk.prototype["set_index"] = Chunk.prototype.set_index = function(index) {
    var self = this.ptr;
    /* index <size_t> [] */
    _Chunk_set_index(self, index);
};

Object.defineProperty(Chunk.prototype, "index", { get: Chunk.prototype.get_index, set: Chunk.prototype.set_index }) 

Chunk.prototype["get_block"] = Chunk.prototype.get_block = function() {
    var self = this.ptr;
    return _Chunk_get_block(self);
};

Chunk.prototype["set_block"] = Chunk.prototype.set_block = function(block) {
    var self = this.ptr;
    /* block <Block> [] */
    _Chunk_set_block(self, block);
};

Object.defineProperty(Chunk.prototype, "block", { get: Chunk.prototype.get_block, set: Chunk.prototype.set_block }) 

Chunk.prototype["get_element"] = Chunk.prototype.get_element = function() {
    var self = this.ptr;
    return _Chunk_get_element(self);
};

Chunk.prototype["set_element"] = Chunk.prototype.set_element = function(element) {
    var self = this.ptr;
    /* element <Element> [] */
    _Chunk_set_element(self, element);
};

Object.defineProperty(Chunk.prototype, "element", { get: Chunk.prototype.get_element, set: Chunk.prototype.set_element }) 

Chunk.prototype["get_size"] = Chunk.prototype.get_size = function() {
    var self = this.ptr;
    return _Chunk_get_size(self);
};

Chunk.prototype["set_size"] = Chunk.prototype.set_size = function(size) {
    var self = this.ptr;
    /* size <float> [] */
    _Chunk_set_size(self, size);
};

Object.defineProperty(Chunk.prototype, "size", { get: Chunk.prototype.get_size, set: Chunk.prototype.set_size }) 

Chunk.prototype["__destroy__"] = Chunk.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Chunk___destroy__(self);
};
// Element
/** @suppress {undefinedVars, duplicate} */ function Element(name, state, colour) {
    var self = this.ptr;
    ensureCache.prepare();
    /* name <const char*> [] */
    if (name && typeof name === "object") name = name.ptr;
    else name = ensureString(name);
    /* state <MatterState> [] */
    /* colour <Colour> [] */
};
Element.prototype = Object.create(WrapperObject.prototype);
Element.prototype.constructor = Element;
Element.prototype.__class__ = Element;
Element.__cache__ = {};
Module['Element'] = Element;

Element.prototype["get_id"] = Element.prototype.get_id = function() {
    var self = this.ptr;
    return _Element_get_id(self);
};

Element.prototype["set_id"] = Element.prototype.set_id = function(id) {
    var self = this.ptr;
    /* id <mud::Id> [] */
    _Element_set_id(self, id);
};

Object.defineProperty(Element.prototype, "id", { get: Element.prototype.get_id, set: Element.prototype.set_id }) 

Element.prototype["get_name"] = Element.prototype.get_name = function() {
    var self = this.ptr;
    return Pointer_stringify(_Element_get_name(self));
};

Element.prototype["set_name"] = Element.prototype.set_name = function(name) {
    var self = this.ptr;
    /* name <std::string> [] */
    if (name && typeof name === "object") name = name.ptr;
    else name = ensureString(name);
    _Element_set_name(self, name);
};

Object.defineProperty(Element.prototype, "name", { get: Element.prototype.get_name, set: Element.prototype.set_name }) 

Element.prototype["get_state"] = Element.prototype.get_state = function() {
    var self = this.ptr;
    return _Element_get_state(self);
};

Element.prototype["set_state"] = Element.prototype.set_state = function(state) {
    var self = this.ptr;
    /* state <MatterState> [] */
    _Element_set_state(self, state);
};

Object.defineProperty(Element.prototype, "state", { get: Element.prototype.get_state, set: Element.prototype.set_state }) 

Element.prototype["get_colour"] = Element.prototype.get_colour = function() {
    var self = this.ptr;
    return _Element_get_colour(self);
};

Element.prototype["set_colour"] = Element.prototype.set_colour = function(colour) {
    var self = this.ptr;
    /* colour <Colour> [] */
    _Element_set_colour(self, colour);
};

Object.defineProperty(Element.prototype, "colour", { get: Element.prototype.get_colour, set: Element.prototype.set_colour }) 

Element.prototype["__destroy__"] = Element.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Element___destroy__(self);
};
// Heap
/** @suppress {undefinedVars, duplicate} */ function Heap(spatial, element, radius) {
    var self = this.ptr;
    /* spatial <toy::HSpatial> [] */
    /* element <Element> [] */
    /* radius <float> [] */
};
Heap.prototype = Object.create(WrapperObject.prototype);
Heap.prototype.constructor = Heap;
Heap.prototype.__class__ = Heap;
Heap.__cache__ = {};
Module['Heap'] = Heap;

Heap.prototype["get_element"] = Heap.prototype.get_element = function() {
    var self = this.ptr;
    return _Heap_get_element(self);
};

Heap.prototype["set_element"] = Heap.prototype.set_element = function(element) {
    var self = this.ptr;
    /* element <Element> [] */
    _Heap_set_element(self, element);
};

Object.defineProperty(Heap.prototype, "element", { get: Heap.prototype.get_element, set: Heap.prototype.set_element }) 

Heap.prototype["get_radius"] = Heap.prototype.get_radius = function() {
    var self = this.ptr;
    return _Heap_get_radius(self);
};

Heap.prototype["set_radius"] = Heap.prototype.set_radius = function(radius) {
    var self = this.ptr;
    /* radius <float> [] */
    _Heap_set_radius(self, radius);
};

Object.defineProperty(Heap.prototype, "radius", { get: Heap.prototype.get_radius, set: Heap.prototype.set_radius }) 

Heap.prototype["__destroy__"] = Heap.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Heap___destroy__(self);
};
// Sector
/** @suppress {undefinedVars, duplicate} */ function Sector(spatial, world_page, navblock, coordinate, size) {
    var self = this.ptr;
    /* spatial <toy::HSpatial> [] */
    /* world_page <toy::HWorldPage> [] */
    /* navblock <toy::HNavblock> [] */
    /* coordinate <uvec3> [] */
    /* size <vec3> [] */
};
Sector.prototype = Object.create(WrapperObject.prototype);
Sector.prototype.constructor = Sector;
Sector.prototype.__class__ = Sector;
Sector.__cache__ = {};
Module['Sector'] = Sector;

Sector.prototype["get_coordinate"] = Sector.prototype.get_coordinate = function() {
    var self = this.ptr;
    return _Sector_get_coordinate(self);
};

Sector.prototype["set_coordinate"] = Sector.prototype.set_coordinate = function(coordinate) {
    var self = this.ptr;
    /* coordinate <uvec3> [] */
    _Sector_set_coordinate(self, coordinate);
};

Object.defineProperty(Sector.prototype, "coordinate", { get: Sector.prototype.get_coordinate, set: Sector.prototype.set_coordinate }) 

Sector.prototype["get_size"] = Sector.prototype.get_size = function() {
    var self = this.ptr;
    return _Sector_get_size(self);
};

Sector.prototype["set_size"] = Sector.prototype.set_size = function(size) {
    var self = this.ptr;
    /* size <vec3> [] */
    _Sector_set_size(self, size);
};

Object.defineProperty(Sector.prototype, "size", { get: Sector.prototype.get_size, set: Sector.prototype.set_size }) 

Sector.prototype["get_block"] = Sector.prototype.get_block = function() {
    var self = this.ptr;
    return _Sector_get_block(self);
};

Sector.prototype["set_block"] = Sector.prototype.set_block = function(block) {
    var self = this.ptr;
    /* block <Block> [] */
    _Sector_set_block(self, block);
};

Object.defineProperty(Sector.prototype, "block", { get: Sector.prototype.get_block, set: Sector.prototype.set_block }) 

Sector.prototype["__destroy__"] = Sector.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Sector___destroy__(self);
};
// Tileblock
/** @suppress {undefinedVars, duplicate} */ function Tileblock(spatial, world_page, navblock, size, tile_scale, tileset) {
    var self = this.ptr;
    /* spatial <toy::HSpatial> [] */
    /* world_page <toy::HWorldPage> [] */
    /* navblock <toy::HNavblock> [] */
    /* size <uvec3> [] */
    /* tile_scale <vec3> [] */
    /* tileset <WaveTileset> [] */
};
Tileblock.prototype = Object.create(WrapperObject.prototype);
Tileblock.prototype.constructor = Tileblock;
Tileblock.prototype.__class__ = Tileblock;
Tileblock.__cache__ = {};
Module['Tileblock'] = Tileblock;

Tileblock.prototype["get_wfc_block"] = Tileblock.prototype.get_wfc_block = function() {
    var self = this.ptr;
    return _Tileblock_get_wfc_block(self);
};

Tileblock.prototype["set_wfc_block"] = Tileblock.prototype.set_wfc_block = function(wfc_block) {
    var self = this.ptr;
    /* wfc_block <WfcBlock> [] */
    _Tileblock_set_wfc_block(self, wfc_block);
};

Object.defineProperty(Tileblock.prototype, "wfc_block", { get: Tileblock.prototype.get_wfc_block, set: Tileblock.prototype.set_wfc_block }) 

Tileblock.prototype["get_setup"] = Tileblock.prototype.get_setup = function() {
    var self = this.ptr;
    return !!(_Tileblock_get_setup(self));
};

Tileblock.prototype["set_setup"] = Tileblock.prototype.set_setup = function(setup) {
    var self = this.ptr;
    /* setup <bool> [] */
    _Tileblock_set_setup(self, setup);
};

Object.defineProperty(Tileblock.prototype, "setup", { get: Tileblock.prototype.get_setup, set: Tileblock.prototype.set_setup }) 

Tileblock.prototype["get_populated"] = Tileblock.prototype.get_populated = function() {
    var self = this.ptr;
    return !!(_Tileblock_get_populated(self));
};

Tileblock.prototype["set_populated"] = Tileblock.prototype.set_populated = function(populated) {
    var self = this.ptr;
    /* populated <bool> [] */
    _Tileblock_set_populated(self, populated);
};

Object.defineProperty(Tileblock.prototype, "populated", { get: Tileblock.prototype.get_populated, set: Tileblock.prototype.set_populated }) 

Tileblock.prototype["__destroy__"] = Tileblock.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Tileblock___destroy__(self);
};
// Earth
/** @suppress {undefinedVars, duplicate} */ function Earth() {
    var self = this.ptr;
};
Earth.prototype = Object.create(WrapperObject.prototype);
Earth.prototype.constructor = Earth;
Earth.prototype.__class__ = Earth;
Earth.__cache__ = {};
Module['Earth'] = Earth;

Earth.prototype["__destroy__"] = Earth.prototype.__destroy__ = function() {
    var self = this.ptr;
    _Earth___destroy__(self);
};

(function() {
      function setupEnums() {
            
          }
      if (Module['calledRun']) setupEnums();
      else addOnPreMain(setupEnums);
})();
