Module['stl'] = Module['stl'] || {};
Module['two'] = Module['two'] || {};
// ComponentHandle<toy::Block>
function ComponentHandle_toy_Block() {
    
    this.__ptr = _two_ComponentHandle_toy_Block__construct_0(); getCache(ComponentHandle_toy_Block)[this.__ptr] = this;
};
ComponentHandle_toy_Block.prototype = Object.create(WrapperObject.prototype);
ComponentHandle_toy_Block.prototype.constructor = ComponentHandle_toy_Block;
ComponentHandle_toy_Block.prototype.__class = ComponentHandle_toy_Block;
ComponentHandle_toy_Block.__cache = {};
Module['two']['ComponentHandle_toy_Block'] = ComponentHandle_toy_Block;
ComponentHandle_toy_Block.prototype["__destroy"] = ComponentHandle_toy_Block.prototype.__destroy = function() {
    _two_ComponentHandle_toy_Block__destroy(this.__ptr);
};
// ComponentHandle<toy::Chunk>
function ComponentHandle_toy_Chunk() {
    
    this.__ptr = _two_ComponentHandle_toy_Chunk__construct_0(); getCache(ComponentHandle_toy_Chunk)[this.__ptr] = this;
};
ComponentHandle_toy_Chunk.prototype = Object.create(WrapperObject.prototype);
ComponentHandle_toy_Chunk.prototype.constructor = ComponentHandle_toy_Chunk;
ComponentHandle_toy_Chunk.prototype.__class = ComponentHandle_toy_Chunk;
ComponentHandle_toy_Chunk.__cache = {};
Module['two']['ComponentHandle_toy_Chunk'] = ComponentHandle_toy_Chunk;
ComponentHandle_toy_Chunk.prototype["__destroy"] = ComponentHandle_toy_Chunk.prototype.__destroy = function() {
    _two_ComponentHandle_toy_Chunk__destroy(this.__ptr);
};
// ComponentHandle<toy::Heap>
function ComponentHandle_toy_Heap() {
    
    this.__ptr = _two_ComponentHandle_toy_Heap__construct_0(); getCache(ComponentHandle_toy_Heap)[this.__ptr] = this;
};
ComponentHandle_toy_Heap.prototype = Object.create(WrapperObject.prototype);
ComponentHandle_toy_Heap.prototype.constructor = ComponentHandle_toy_Heap;
ComponentHandle_toy_Heap.prototype.__class = ComponentHandle_toy_Heap;
ComponentHandle_toy_Heap.__cache = {};
Module['two']['ComponentHandle_toy_Heap'] = ComponentHandle_toy_Heap;
ComponentHandle_toy_Heap.prototype["__destroy"] = ComponentHandle_toy_Heap.prototype.__destroy = function() {
    _two_ComponentHandle_toy_Heap__destroy(this.__ptr);
};
// ComponentHandle<toy::Sector>
function ComponentHandle_toy_Sector() {
    
    this.__ptr = _two_ComponentHandle_toy_Sector__construct_0(); getCache(ComponentHandle_toy_Sector)[this.__ptr] = this;
};
ComponentHandle_toy_Sector.prototype = Object.create(WrapperObject.prototype);
ComponentHandle_toy_Sector.prototype.constructor = ComponentHandle_toy_Sector;
ComponentHandle_toy_Sector.prototype.__class = ComponentHandle_toy_Sector;
ComponentHandle_toy_Sector.__cache = {};
Module['two']['ComponentHandle_toy_Sector'] = ComponentHandle_toy_Sector;
ComponentHandle_toy_Sector.prototype["__destroy"] = ComponentHandle_toy_Sector.prototype.__destroy = function() {
    _two_ComponentHandle_toy_Sector__destroy(this.__ptr);
};
// ComponentHandle<toy::Tileblock>
function ComponentHandle_toy_Tileblock() {
    
    this.__ptr = _two_ComponentHandle_toy_Tileblock__construct_0(); getCache(ComponentHandle_toy_Tileblock)[this.__ptr] = this;
};
ComponentHandle_toy_Tileblock.prototype = Object.create(WrapperObject.prototype);
ComponentHandle_toy_Tileblock.prototype.constructor = ComponentHandle_toy_Tileblock;
ComponentHandle_toy_Tileblock.prototype.__class = ComponentHandle_toy_Tileblock;
ComponentHandle_toy_Tileblock.__cache = {};
Module['two']['ComponentHandle_toy_Tileblock'] = ComponentHandle_toy_Tileblock;
ComponentHandle_toy_Tileblock.prototype["__destroy"] = ComponentHandle_toy_Tileblock.prototype.__destroy = function() {
    _two_ComponentHandle_toy_Tileblock__destroy(this.__ptr);
};
// vector2d<toy::Block*>
function vector2d_toy_Block_() {
    
    this.__ptr = _two_vector2d_toy_Block___construct_0(); getCache(vector2d_toy_Block_)[this.__ptr] = this;
};
vector2d_toy_Block_.prototype = Object.create(WrapperObject.prototype);
vector2d_toy_Block_.prototype.constructor = vector2d_toy_Block_;
vector2d_toy_Block_.prototype.__class = vector2d_toy_Block_;
vector2d_toy_Block_.__cache = {};
Module['two']['vector2d_toy_Block_'] = vector2d_toy_Block_;
vector2d_toy_Block_.prototype["__destroy"] = vector2d_toy_Block_.prototype.__destroy = function() {
    _two_vector2d_toy_Block___destroy(this.__ptr);
};
// Block
function Block(a0, a1, a2, a3, a4) {
    if (a0 === undefined) {  }
    else { if (!checkClass(a0, ComponentHandle_toy_Spatial)) throw Error('Block(0:spatial): expected ComponentHandle<toy::Spatial>'); if (!checkClass(a1, ComponentHandle_toy_WorldPage)) throw Error('Block(1:world_page): expected ComponentHandle<toy::WorldPage>'); if (!checkClass(a2, Block)) throw Error('Block(2:parentblock): expected Block'); if (typeof a3 !== 'number') throw Error('Block(3:index): expected integer'); if (!checkClass(a4, v3_float)) throw Error('Block(4:size): expected v3<float>'); }
    if (a0 === undefined) { this.__ptr = _toy_Block__construct_0(); getCache(Block)[this.__ptr] = this; }
    else { this.__ptr = _toy_Block__construct_5(/*spatial*/a0.__ptr, /*world_page*/a1.__ptr, /*parentblock*/a2.__ptr, /*index*/a3, /*size*/a4.__ptr); getCache(Block)[this.__ptr] = this; }
};
Block.prototype = Object.create(WrapperObject.prototype);
Block.prototype.constructor = Block;
Block.prototype.__class = Block;
Block.__cache = {};
Module['Block'] = Block;
Block.prototype["subdivide"] = Block.prototype.subdivide = function() {
    
    _toy_Block_subdivide_0(this.__ptr);
};
Block.prototype["reset"] = Block.prototype.reset = function() {
    
    _toy_Block_reset_0(this.__ptr);
};
Block.prototype["chunk"] = Block.prototype.chunk = function(a0, a1, a2, a3) {
    if (typeof a0 !== 'number') throw Error('chunk(0:x): expected integer'); if (typeof a1 !== 'number') throw Error('chunk(1:y): expected integer'); if (typeof a2 !== 'number') throw Error('chunk(2:z): expected integer'); if (!checkClass(a3, Element)) throw Error('chunk(3:element): expected Element');
    _toy_Block_chunk_4(this.__ptr, /*x*/a0, /*y*/a1, /*z*/a2, /*element*/a3.__ptr);
};
Block.prototype["commit"] = Block.prototype.commit = function() {
    
    _toy_Block_commit_0(this.__ptr);
};
Object.defineProperty(Block.prototype, "world_page", {
    get: function() {
        return wrapPointer(_toy_Block__get_world_page(this.__ptr), ComponentHandle_toy_WorldPage);
    },
    set: function(value) {
        if (!checkClass(value, ComponentHandle_toy_WorldPage)) throw Error('Block.world_page: expected ComponentHandle<toy::WorldPage>');
        _toy_Block__set_world_page(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Block.prototype, "parentblock", {
    get: function() {
        return wrapPointer(_toy_Block__get_parentblock(this.__ptr), Block);
    },
    set: function(value) {
        if (!checkClass(value, Block)) throw Error('Block.parentblock: expected Block');
        _toy_Block__set_parentblock(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Block.prototype, "index", {
    get: function() {
        return _toy_Block__get_index(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Block.index: expected integer');
        _toy_Block__set_index(this.__ptr, value);
    }
});
Object.defineProperty(Block.prototype, "size", {
    get: function() {
        return wrapPointer(_toy_Block__get_size(this.__ptr), v3_float);
    },
    set: function(value) {
        if (!checkClass(value, v3_float)) throw Error('Block.size: expected v3<float>');
        _toy_Block__set_size(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Block.prototype, "updated", {
    get: function() {
        return _toy_Block__get_updated(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Block.updated: expected integer');
        _toy_Block__set_updated(this.__ptr, value);
    }
});
Block.prototype["__destroy"] = Block.prototype.__destroy = function() {
    _toy_Block__destroy(this.__ptr);
};
// Chunk
function Chunk(a0, a1, a2, a3) {
    if (a0 === undefined) {  }
    else { if (!checkClass(a0, Block)) throw Error('Chunk(0:block): expected Block'); if (typeof a1 !== 'number') throw Error('Chunk(1:index): expected integer'); if (!checkClass(a2, Element)) throw Error('Chunk(2:element): expected Element'); if (typeof a3 !== 'number') throw Error('Chunk(3:size): expected number'); }
    if (a0 === undefined) { this.__ptr = _toy_Chunk__construct_0(); getCache(Chunk)[this.__ptr] = this; }
    else { this.__ptr = _toy_Chunk__construct_4(/*block*/a0.__ptr, /*index*/a1, /*element*/a2.__ptr, /*size*/a3); getCache(Chunk)[this.__ptr] = this; }
};
Chunk.prototype = Object.create(WrapperObject.prototype);
Chunk.prototype.constructor = Chunk;
Chunk.prototype.__class = Chunk;
Chunk.__cache = {};
Module['Chunk'] = Chunk;
Object.defineProperty(Chunk.prototype, "index", {
    get: function() {
        return _toy_Chunk__get_index(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Chunk.index: expected integer');
        _toy_Chunk__set_index(this.__ptr, value);
    }
});
Object.defineProperty(Chunk.prototype, "block", {
    get: function() {
        return wrapPointer(_toy_Chunk__get_block(this.__ptr), Block);
    },
    set: function(value) {
        if (!checkClass(value, Block)) throw Error('Chunk.block: expected Block');
        _toy_Chunk__set_block(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Chunk.prototype, "element", {
    get: function() {
        return wrapPointer(_toy_Chunk__get_element(this.__ptr), Element);
    },
    set: function(value) {
        if (!checkClass(value, Element)) throw Error('Chunk.element: expected Element');
        _toy_Chunk__set_element(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Chunk.prototype, "size", {
    get: function() {
        return _toy_Chunk__get_size(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Chunk.size: expected number');
        _toy_Chunk__set_size(this.__ptr, value);
    }
});
Chunk.prototype["__destroy"] = Chunk.prototype.__destroy = function() {
    _toy_Chunk__destroy(this.__ptr);
};
// Element
function Element(a0, a1, a2) {
    ensureCache.prepare();
    if (typeof a0 !== 'string') throw Error('Element(0:name): expected string'); if (typeof a1 !== 'number') throw Error('Element(1:state): expected integer'); if (!checkClass(a2, Colour)) throw Error('Element(2:colour): expected Colour');
    this.__ptr = _toy_Element__construct_3(ensureString(/*name*/a0), /*state*/a1, /*colour*/a2.__ptr); getCache(Element)[this.__ptr] = this;
};
Element.prototype = Object.create(WrapperObject.prototype);
Element.prototype.constructor = Element;
Element.prototype.__class = Element;
Element.__cache = {};
Module['Element'] = Element;
Object.defineProperty(Element.prototype, "id", {
    get: function() {
        return _toy_Element__get_id(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Element.id: expected integer');
        _toy_Element__set_id(this.__ptr, value);
    }
});
Object.defineProperty(Element.prototype, "name", {
    get: function() {
        return UTF8ToString(_toy_Element__get_name(this.__ptr));
    },
    set: function(value) {
        if (typeof value !== 'string') throw Error('Element.name: expected string');
        _toy_Element__set_name(this.__ptr, ensureString(value));
    }
});
Object.defineProperty(Element.prototype, "state", {
    get: function() {
        return _toy_Element__get_state(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Element.state: expected integer');
        _toy_Element__set_state(this.__ptr, value);
    }
});
Object.defineProperty(Element.prototype, "colour", {
    get: function() {
        return wrapPointer(_toy_Element__get_colour(this.__ptr), Colour);
    },
    set: function(value) {
        if (!checkClass(value, Colour)) throw Error('Element.colour: expected Colour');
        _toy_Element__set_colour(this.__ptr, value.__ptr);
    }
});
Element.prototype["__destroy"] = Element.prototype.__destroy = function() {
    _toy_Element__destroy(this.__ptr);
};
// Heap
function Heap(a0, a1) {
    if (a0 === undefined) {  }
    else { if (!checkClass(a0, Element)) throw Error('Heap(0:element): expected Element'); if (typeof a1 !== 'number') throw Error('Heap(1:radius): expected number'); }
    if (a0 === undefined) { this.__ptr = _toy_Heap__construct_0(); getCache(Heap)[this.__ptr] = this; }
    else { this.__ptr = _toy_Heap__construct_2(/*element*/a0.__ptr, /*radius*/a1); getCache(Heap)[this.__ptr] = this; }
};
Heap.prototype = Object.create(WrapperObject.prototype);
Heap.prototype.constructor = Heap;
Heap.prototype.__class = Heap;
Heap.__cache = {};
Module['Heap'] = Heap;
Object.defineProperty(Heap.prototype, "element", {
    get: function() {
        return wrapPointer(_toy_Heap__get_element(this.__ptr), Element);
    },
    set: function(value) {
        if (!checkClass(value, Element)) throw Error('Heap.element: expected Element');
        _toy_Heap__set_element(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Heap.prototype, "radius", {
    get: function() {
        return _toy_Heap__get_radius(this.__ptr);
    },
    set: function(value) {
        if (typeof value !== 'number') throw Error('Heap.radius: expected number');
        _toy_Heap__set_radius(this.__ptr, value);
    }
});
Heap.prototype["__destroy"] = Heap.prototype.__destroy = function() {
    _toy_Heap__destroy(this.__ptr);
};
// Earth
function Earth() {
    
    this.__ptr = _toy_Earth__construct_0(); getCache(Earth)[this.__ptr] = this;
};
Earth.prototype = Object.create(Element.prototype);
Earth.prototype.constructor = Earth;
Earth.prototype.__class = Earth;
Earth.__base = Element;
Earth.__cache = {};
Module['Earth'] = Earth;
Earth.prototype["__destroy"] = Earth.prototype.__destroy = function() {
    _toy_Earth__destroy(this.__ptr);
};
// Sector
function Sector(a0, a1, a2, a3, a4) {
    if (a0 === undefined) {  }
    else { if (!checkClass(a0, ComponentHandle_toy_Spatial)) throw Error('Sector(0:spatial): expected ComponentHandle<toy::Spatial>'); if (!checkClass(a1, ComponentHandle_toy_WorldPage)) throw Error('Sector(1:world_page): expected ComponentHandle<toy::WorldPage>'); if (!checkClass(a2, ComponentHandle_toy_Navblock)) throw Error('Sector(2:navblock): expected ComponentHandle<toy::Navblock>'); if (!checkClass(a3, v3_uint)) throw Error('Sector(3:coordinate): expected v3<uint>'); if (!checkClass(a4, v3_float)) throw Error('Sector(4:size): expected v3<float>'); }
    if (a0 === undefined) { this.__ptr = _toy_Sector__construct_0(); getCache(Sector)[this.__ptr] = this; }
    else { this.__ptr = _toy_Sector__construct_5(/*spatial*/a0.__ptr, /*world_page*/a1.__ptr, /*navblock*/a2.__ptr, /*coordinate*/a3.__ptr, /*size*/a4.__ptr); getCache(Sector)[this.__ptr] = this; }
};
Sector.prototype = Object.create(WrapperObject.prototype);
Sector.prototype.constructor = Sector;
Sector.prototype.__class = Sector;
Sector.__cache = {};
Module['Sector'] = Sector;
Object.defineProperty(Sector.prototype, "coordinate", {
    get: function() {
        return wrapPointer(_toy_Sector__get_coordinate(this.__ptr), v3_uint);
    },
    set: function(value) {
        if (!checkClass(value, v3_uint)) throw Error('Sector.coordinate: expected v3<uint>');
        _toy_Sector__set_coordinate(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Sector.prototype, "size", {
    get: function() {
        return wrapPointer(_toy_Sector__get_size(this.__ptr), v3_float);
    },
    set: function(value) {
        if (!checkClass(value, v3_float)) throw Error('Sector.size: expected v3<float>');
        _toy_Sector__set_size(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Sector.prototype, "block", {
    get: function() {
        return wrapPointer(_toy_Sector__get_block(this.__ptr), Block);
    },
    set: function(value) {
        if (!checkClass(value, Block)) throw Error('Sector.block: expected Block');
        _toy_Sector__set_block(this.__ptr, value.__ptr);
    }
});
Sector.prototype["__destroy"] = Sector.prototype.__destroy = function() {
    _toy_Sector__destroy(this.__ptr);
};
// Tileblock
function Tileblock(a0, a1, a2, a3, a4, a5) {
    if (a0 === undefined) {  }
    else { if (!checkClass(a0, ComponentHandle_toy_Spatial)) throw Error('Tileblock(0:spatial): expected ComponentHandle<toy::Spatial>'); if (!checkClass(a1, ComponentHandle_toy_WorldPage)) throw Error('Tileblock(1:world_page): expected ComponentHandle<toy::WorldPage>'); if (!checkClass(a2, ComponentHandle_toy_Navblock)) throw Error('Tileblock(2:navblock): expected ComponentHandle<toy::Navblock>'); if (!checkClass(a3, v3_uint)) throw Error('Tileblock(3:size): expected v3<uint>'); if (!checkClass(a4, v3_float)) throw Error('Tileblock(4:tile_scale): expected v3<float>'); if (!checkClass(a5, WaveTileset)) throw Error('Tileblock(5:tileset): expected WaveTileset'); }
    if (a0 === undefined) { this.__ptr = _toy_Tileblock__construct_0(); getCache(Tileblock)[this.__ptr] = this; }
    else { this.__ptr = _toy_Tileblock__construct_6(/*spatial*/a0.__ptr, /*world_page*/a1.__ptr, /*navblock*/a2.__ptr, /*size*/a3.__ptr, /*tile_scale*/a4.__ptr, /*tileset*/a5.__ptr); getCache(Tileblock)[this.__ptr] = this; }
};
Tileblock.prototype = Object.create(WrapperObject.prototype);
Tileblock.prototype.constructor = Tileblock;
Tileblock.prototype.__class = Tileblock;
Tileblock.__cache = {};
Module['Tileblock'] = Tileblock;
Object.defineProperty(Tileblock.prototype, "wfc_block", {
    get: function() {
        return wrapPointer(_toy_Tileblock__get_wfc_block(this.__ptr), WfcBlock);
    }});
Object.defineProperty(Tileblock.prototype, "setup", {
    get: function() {
        return !!(_toy_Tileblock__get_setup(this.__ptr));
    },
    set: function(value) {
        if (typeof value !== 'boolean') throw Error('Tileblock.setup: expected boolean');
        _toy_Tileblock__set_setup(this.__ptr, value);
    }
});
Object.defineProperty(Tileblock.prototype, "populated", {
    get: function() {
        return !!(_toy_Tileblock__get_populated(this.__ptr));
    },
    set: function(value) {
        if (typeof value !== 'boolean') throw Error('Tileblock.populated: expected boolean');
        _toy_Tileblock__set_populated(this.__ptr, value);
    }
});
Tileblock.prototype["__destroy"] = Tileblock.prototype.__destroy = function() {
    _toy_Tileblock__destroy(this.__ptr);
};
Module['paint_block_height'] = function(a0, a1, a2) {
    if (!checkClass(a0, Block)) throw Error('paint_block_height(0:block): expected Block'); if (!checkClass(a1, Image256)) throw Error('paint_block_height(1:image): expected Image256'); if (!checkClass(a2, Element)) throw Error('paint_block_height(2:element): expected Element');
    _toy_paint_block_height_3(/*block*/a0.__ptr, /*image*/a1.__ptr, /*element*/a2.__ptr);
};
Module['generate_block'] = function(a0, a1, a2, a3, a4, a5, a6) {
    if (a6 === undefined) { if (!checkClass(a0, GfxSystem)) throw Error('generate_block(0:gfx): expected GfxSystem'); if (!checkClass(a1, WaveTileset)) throw Error('generate_block(1:tileset): expected WaveTileset'); if (!checkClass(a2, ComponentHandle_toy_Spatial)) throw Error('generate_block(2:origin): expected ComponentHandle<toy::Spatial>'); if (!checkClass(a3, v2_int)) throw Error('generate_block(3:coord): expected v2<int>'); if (!checkClass(a4, v3_uint)) throw Error('generate_block(4:block_subdiv): expected v3<uint>'); if (!checkClass(a5, v3_float)) throw Error('generate_block(5:tile_scale): expected v3<float>'); }
    else { if (!checkClass(a0, GfxSystem)) throw Error('generate_block(0:gfx): expected GfxSystem'); if (!checkClass(a1, WaveTileset)) throw Error('generate_block(1:tileset): expected WaveTileset'); if (!checkClass(a2, ComponentHandle_toy_Spatial)) throw Error('generate_block(2:origin): expected ComponentHandle<toy::Spatial>'); if (!checkClass(a3, v2_int)) throw Error('generate_block(3:coord): expected v2<int>'); if (!checkClass(a4, v3_uint)) throw Error('generate_block(4:block_subdiv): expected v3<uint>'); if (!checkClass(a5, v3_float)) throw Error('generate_block(5:tile_scale): expected v3<float>'); if (typeof a6 !== 'boolean') throw Error('generate_block(6:from_file): expected boolean'); }
    if (a6 === undefined) { return wrapPointer(_toy_generate_block_6(/*gfx*/a0.__ptr, /*tileset*/a1.__ptr, /*origin*/a2.__ptr, /*coord*/a3.__ptr, /*block_subdiv*/a4.__ptr, /*tile_scale*/a5.__ptr), ComponentHandle_toy_Tileblock); }
    else { return wrapPointer(_toy_generate_block_7(/*gfx*/a0.__ptr, /*tileset*/a1.__ptr, /*origin*/a2.__ptr, /*coord*/a3.__ptr, /*block_subdiv*/a4.__ptr, /*tile_scale*/a5.__ptr, /*from_file*/a6), ComponentHandle_toy_Tileblock); }
};
Module['build_block_geometry'] = function(a0, a1, a2) {
    if (!checkClass(a0, Scene)) throw Error('build_block_geometry(0:scene): expected Scene'); if (!checkClass(a1, WorldPage)) throw Error('build_block_geometry(1:page): expected WorldPage'); if (!checkClass(a2, Tileblock)) throw Error('build_block_geometry(2:block): expected Tileblock');
    _toy_build_block_geometry_3(/*scene*/a0.__ptr, /*page*/a1.__ptr, /*block*/a2.__ptr);
};
Module['index_blocks'] = function(a0, a1, a2, a3) {
    if (!checkClass(a0, v3_uint)) throw Error('index_blocks(0:grid_size): expected v3<uint>'); if (!checkClass(a1, vector2d_toy_Block_)) throw Error('index_blocks(1:grid): expected vector2d<toy::Block*>'); if (!checkClass(a2, span_toy_Block_)) throw Error('index_blocks(2:blocks): expected span<toy::Block*>'); if (!checkClass(a3, span_toy_Sector_)) throw Error('index_blocks(3:sectors): expected span<toy::Sector*>');
    _toy_index_blocks_4(/*grid_size*/a0.__ptr, /*grid*/a1.__ptr, /*blocks*/a2.__ptr, /*sectors*/a3.__ptr);
};
Module['HBlock'] = ComponentHandle_toy_Block;
Module['HChunk'] = ComponentHandle_toy_Chunk;
Module['HHeap'] = ComponentHandle_toy_Heap;
Module['HSector'] = ComponentHandle_toy_Sector;
Module['HTileblock'] = ComponentHandle_toy_Tileblock;

(function() {
    function setup() {
        Block.prototype.__type = _toy_Block__type();
        Chunk.prototype.__type = _toy_Chunk__type();
        Element.prototype.__type = _toy_Element__type();
        Heap.prototype.__type = _toy_Heap__type();
        Earth.prototype.__type = _toy_Earth__type();
        Sector.prototype.__type = _toy_Sector__type();
        Tileblock.prototype.__type = _toy_Tileblock__type();
        // MatterState
        Module['MatterState'] = Module['MatterState'] || {};
        Module['MatterState']['Solid'] = _toy_MatterState_Solid();
        Module['MatterState']['Liquid'] = _toy_MatterState_Liquid();
        Module['MatterState']['Gas'] = _toy_MatterState_Gas();
        Module['MatterState']['Plasma'] = _toy_MatterState_Plasma();
    }
    if (Module['calledRun']) setup();
    else addOnPreMain(setup);
})();
