Module['stl'] = Module['stl'] || {};
Module['mud'] = Module['mud'] || {};
// Block
function Block(a0, a1, a2, a3, a4) {
    if (a0 === undefined) { this.__ptr = _toy_Block__construct_0(); this.__type = Block.__type; getCache(Block)[this.__ptr] = this; return; }
    this.__ptr = _toy_Block__construct_5(/*spatial*/a0.__ptr, /*world_page*/a1.__ptr, /*parentblock*/a2.__ptr, /*index*/a3, /*size*/a4.__ptr); this.__type = Block.__type; getCache(Block)[this.__ptr] = this;
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
        _toy_Block__set_world_page(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Block.prototype, "parentblock", {
    get: function() {
        return wrapPointer(_toy_Block__get_parentblock(this.__ptr), Block);
    },
    set: function(value) {
        _toy_Block__set_parentblock(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Block.prototype, "index", {
    get: function() {
        return _toy_Block__get_index(this.__ptr);
    },
    set: function(value) {
        _toy_Block__set_index(this.__ptr, value);
    }
});
Object.defineProperty(Block.prototype, "size", {
    get: function() {
        return wrapPointer(_toy_Block__get_size(this.__ptr), v3_float);
    },
    set: function(value) {
        _toy_Block__set_size(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Block.prototype, "updated", {
    get: function() {
        return _toy_Block__get_updated(this.__ptr);
    },
    set: function(value) {
        _toy_Block__set_updated(this.__ptr, value);
    }
});
Block.prototype["__destroy"] = Block.prototype.__destroy = function() {
    _toy_Block__destroy(this.__ptr);
};
// Chunk
function Chunk(a0, a1, a2, a3) {
    if (a0 === undefined) { this.__ptr = _toy_Chunk__construct_0(); this.__type = Chunk.__type; getCache(Chunk)[this.__ptr] = this; return; }
    this.__ptr = _toy_Chunk__construct_4(/*block*/a0.__ptr, /*index*/a1, /*element*/a2.__ptr, /*size*/a3); this.__type = Chunk.__type; getCache(Chunk)[this.__ptr] = this;
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
        _toy_Chunk__set_index(this.__ptr, value);
    }
});
Object.defineProperty(Chunk.prototype, "block", {
    get: function() {
        return wrapPointer(_toy_Chunk__get_block(this.__ptr), Block);
    },
    set: function(value) {
        _toy_Chunk__set_block(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Chunk.prototype, "element", {
    get: function() {
        return wrapPointer(_toy_Chunk__get_element(this.__ptr), Element);
    },
    set: function(value) {
        _toy_Chunk__set_element(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Chunk.prototype, "size", {
    get: function() {
        return _toy_Chunk__get_size(this.__ptr);
    },
    set: function(value) {
        _toy_Chunk__set_size(this.__ptr, value);
    }
});
Chunk.prototype["__destroy"] = Chunk.prototype.__destroy = function() {
    _toy_Chunk__destroy(this.__ptr);
};
// ComponentHandle<toy::Block>
function ComponentHandle_toy_Block() {
    this.__ptr = _mud_ComponentHandle_toy_Block__construct_0(); this.__type = ComponentHandle_toy_Block.__type; getCache(ComponentHandle_toy_Block)[this.__ptr] = this;
};
ComponentHandle_toy_Block.prototype = Object.create(WrapperObject.prototype);
ComponentHandle_toy_Block.prototype.constructor = ComponentHandle_toy_Block;
ComponentHandle_toy_Block.prototype.__class = ComponentHandle_toy_Block;
ComponentHandle_toy_Block.__cache = {};
Module['mud']['ComponentHandle_toy_Block'] = ComponentHandle_toy_Block;
ComponentHandle_toy_Block.prototype["__destroy"] = ComponentHandle_toy_Block.prototype.__destroy = function() {
    _mud_ComponentHandle_toy_Block__destroy(this.__ptr);
};
// ComponentHandle<toy::Chunk>
function ComponentHandle_toy_Chunk() {
    this.__ptr = _mud_ComponentHandle_toy_Chunk__construct_0(); this.__type = ComponentHandle_toy_Chunk.__type; getCache(ComponentHandle_toy_Chunk)[this.__ptr] = this;
};
ComponentHandle_toy_Chunk.prototype = Object.create(WrapperObject.prototype);
ComponentHandle_toy_Chunk.prototype.constructor = ComponentHandle_toy_Chunk;
ComponentHandle_toy_Chunk.prototype.__class = ComponentHandle_toy_Chunk;
ComponentHandle_toy_Chunk.__cache = {};
Module['mud']['ComponentHandle_toy_Chunk'] = ComponentHandle_toy_Chunk;
ComponentHandle_toy_Chunk.prototype["__destroy"] = ComponentHandle_toy_Chunk.prototype.__destroy = function() {
    _mud_ComponentHandle_toy_Chunk__destroy(this.__ptr);
};
// ComponentHandle<toy::Heap>
function ComponentHandle_toy_Heap() {
    this.__ptr = _mud_ComponentHandle_toy_Heap__construct_0(); this.__type = ComponentHandle_toy_Heap.__type; getCache(ComponentHandle_toy_Heap)[this.__ptr] = this;
};
ComponentHandle_toy_Heap.prototype = Object.create(WrapperObject.prototype);
ComponentHandle_toy_Heap.prototype.constructor = ComponentHandle_toy_Heap;
ComponentHandle_toy_Heap.prototype.__class = ComponentHandle_toy_Heap;
ComponentHandle_toy_Heap.__cache = {};
Module['mud']['ComponentHandle_toy_Heap'] = ComponentHandle_toy_Heap;
ComponentHandle_toy_Heap.prototype["__destroy"] = ComponentHandle_toy_Heap.prototype.__destroy = function() {
    _mud_ComponentHandle_toy_Heap__destroy(this.__ptr);
};
// ComponentHandle<toy::Sector>
function ComponentHandle_toy_Sector() {
    this.__ptr = _mud_ComponentHandle_toy_Sector__construct_0(); this.__type = ComponentHandle_toy_Sector.__type; getCache(ComponentHandle_toy_Sector)[this.__ptr] = this;
};
ComponentHandle_toy_Sector.prototype = Object.create(WrapperObject.prototype);
ComponentHandle_toy_Sector.prototype.constructor = ComponentHandle_toy_Sector;
ComponentHandle_toy_Sector.prototype.__class = ComponentHandle_toy_Sector;
ComponentHandle_toy_Sector.__cache = {};
Module['mud']['ComponentHandle_toy_Sector'] = ComponentHandle_toy_Sector;
ComponentHandle_toy_Sector.prototype["__destroy"] = ComponentHandle_toy_Sector.prototype.__destroy = function() {
    _mud_ComponentHandle_toy_Sector__destroy(this.__ptr);
};
// ComponentHandle<toy::Tileblock>
function ComponentHandle_toy_Tileblock() {
    this.__ptr = _mud_ComponentHandle_toy_Tileblock__construct_0(); this.__type = ComponentHandle_toy_Tileblock.__type; getCache(ComponentHandle_toy_Tileblock)[this.__ptr] = this;
};
ComponentHandle_toy_Tileblock.prototype = Object.create(WrapperObject.prototype);
ComponentHandle_toy_Tileblock.prototype.constructor = ComponentHandle_toy_Tileblock;
ComponentHandle_toy_Tileblock.prototype.__class = ComponentHandle_toy_Tileblock;
ComponentHandle_toy_Tileblock.__cache = {};
Module['mud']['ComponentHandle_toy_Tileblock'] = ComponentHandle_toy_Tileblock;
ComponentHandle_toy_Tileblock.prototype["__destroy"] = ComponentHandle_toy_Tileblock.prototype.__destroy = function() {
    _mud_ComponentHandle_toy_Tileblock__destroy(this.__ptr);
};
// Element
function Element(a0, a1, a2) {
    ensureCache.prepare();
    this.__ptr = _toy_Element__construct_3(ensureString(/*name*/a0), /*state*/a1, /*colour*/a2.__ptr); this.__type = Element.__type; getCache(Element)[this.__ptr] = this;
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
        _toy_Element__set_id(this.__ptr, value);
    }
});
Object.defineProperty(Element.prototype, "name", {
    get: function() {
        return Pointer_stringify(_toy_Element__get_name(this.__ptr));
    },
    set: function(value) {
        _toy_Element__set_name(this.__ptr, ensureString(value));
    }
});
Object.defineProperty(Element.prototype, "state", {
    get: function() {
        return _toy_Element__get_state(this.__ptr);
    },
    set: function(value) {
        _toy_Element__set_state(this.__ptr, value);
    }
});
Object.defineProperty(Element.prototype, "colour", {
    get: function() {
        return wrapPointer(_toy_Element__get_colour(this.__ptr), Colour);
    },
    set: function(value) {
        _toy_Element__set_colour(this.__ptr, value.__ptr);
    }
});
Element.prototype["__destroy"] = Element.prototype.__destroy = function() {
    _toy_Element__destroy(this.__ptr);
};
// Heap
function Heap(a0, a1) {
    if (a0 === undefined) { this.__ptr = _toy_Heap__construct_0(); this.__type = Heap.__type; getCache(Heap)[this.__ptr] = this; return; }
    this.__ptr = _toy_Heap__construct_2(/*element*/a0.__ptr, /*radius*/a1); this.__type = Heap.__type; getCache(Heap)[this.__ptr] = this;
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
        _toy_Heap__set_element(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Heap.prototype, "radius", {
    get: function() {
        return _toy_Heap__get_radius(this.__ptr);
    },
    set: function(value) {
        _toy_Heap__set_radius(this.__ptr, value);
    }
});
Heap.prototype["__destroy"] = Heap.prototype.__destroy = function() {
    _toy_Heap__destroy(this.__ptr);
};
// Sector
function Sector(a0, a1, a2, a3, a4) {
    if (a0 === undefined) { this.__ptr = _toy_Sector__construct_0(); this.__type = Sector.__type; getCache(Sector)[this.__ptr] = this; return; }
    this.__ptr = _toy_Sector__construct_5(/*spatial*/a0.__ptr, /*world_page*/a1.__ptr, /*navblock*/a2.__ptr, /*coordinate*/a3.__ptr, /*size*/a4.__ptr); this.__type = Sector.__type; getCache(Sector)[this.__ptr] = this;
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
        _toy_Sector__set_coordinate(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Sector.prototype, "size", {
    get: function() {
        return wrapPointer(_toy_Sector__get_size(this.__ptr), v3_float);
    },
    set: function(value) {
        _toy_Sector__set_size(this.__ptr, value.__ptr);
    }
});
Object.defineProperty(Sector.prototype, "block", {
    get: function() {
        return wrapPointer(_toy_Sector__get_block(this.__ptr), Block);
    },
    set: function(value) {
        _toy_Sector__set_block(this.__ptr, value.__ptr);
    }
});
Sector.prototype["__destroy"] = Sector.prototype.__destroy = function() {
    _toy_Sector__destroy(this.__ptr);
};
// Tileblock
function Tileblock(a0, a1, a2, a3, a4, a5) {
    if (a0 === undefined) { this.__ptr = _toy_Tileblock__construct_0(); this.__type = Tileblock.__type; getCache(Tileblock)[this.__ptr] = this; return; }
    this.__ptr = _toy_Tileblock__construct_6(/*spatial*/a0.__ptr, /*world_page*/a1.__ptr, /*navblock*/a2.__ptr, /*size*/a3.__ptr, /*tile_scale*/a4.__ptr, /*tileset*/a5.__ptr); this.__type = Tileblock.__type; getCache(Tileblock)[this.__ptr] = this;
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
        _toy_Tileblock__set_setup(this.__ptr, value);
    }
});
Object.defineProperty(Tileblock.prototype, "populated", {
    get: function() {
        return !!(_toy_Tileblock__get_populated(this.__ptr));
    },
    set: function(value) {
        _toy_Tileblock__set_populated(this.__ptr, value);
    }
});
Tileblock.prototype["__destroy"] = Tileblock.prototype.__destroy = function() {
    _toy_Tileblock__destroy(this.__ptr);
};
// vector2d<toy::Block*>
function vector2d_toy_Block_() {
    this.__ptr = _mud_vector2d_toy_Block___construct_0(); this.__type = vector2d_toy_Block_.__type; getCache(vector2d_toy_Block_)[this.__ptr] = this;
};
vector2d_toy_Block_.prototype = Object.create(WrapperObject.prototype);
vector2d_toy_Block_.prototype.constructor = vector2d_toy_Block_;
vector2d_toy_Block_.prototype.__class = vector2d_toy_Block_;
vector2d_toy_Block_.__cache = {};
Module['mud']['vector2d_toy_Block_'] = vector2d_toy_Block_;
vector2d_toy_Block_.prototype["__destroy"] = vector2d_toy_Block_.prototype.__destroy = function() {
    _mud_vector2d_toy_Block___destroy(this.__ptr);
};
// Earth
function Earth() {
    this.__ptr = _toy_Earth__construct_0(); this.__type = Earth.__type; getCache(Earth)[this.__ptr] = this;
};
Earth.prototype = Object.create(Element.prototype);
Earth.prototype.constructor = Earth;
Earth.prototype.__class = Earth;
Earth.__cache = {};
Module['Earth'] = Earth;
Earth.prototype["__destroy"] = Earth.prototype.__destroy = function() {
    _toy_Earth__destroy(this.__ptr);
};
Module['paint_block_height'] = function(a0, a1, a2) {
    _toy_paint_block_height_3(/*block*/a0.__ptr, /*image*/a1.__ptr, /*element*/a2.__ptr);
};
Module['generate_block'] = function(a0, a1, a2, a3, a4, a5, a6) {
    if (a6 === undefined) { return wrapPointer(_toy_generate_block_6(/*gfx*/a0.__ptr, /*tileset*/a1.__ptr, /*origin*/a2.__ptr, /*coord*/a3.__ptr, /*block_subdiv*/a4.__ptr, /*tile_scale*/a5.__ptr), ComponentHandle_toy_Tileblock); }
    return wrapPointer(_toy_generate_block_7(/*gfx*/a0.__ptr, /*tileset*/a1.__ptr, /*origin*/a2.__ptr, /*coord*/a3.__ptr, /*block_subdiv*/a4.__ptr, /*tile_scale*/a5.__ptr, /*from_file*/a6), ComponentHandle_toy_Tileblock);
};
Module['build_block_geometry'] = function(a0, a1, a2) {
    _toy_build_block_geometry_3(/*scene*/a0.__ptr, /*page*/a1.__ptr, /*block*/a2.__ptr);
};
Module['index_blocks'] = function(a0, a1, a2, a3) {
    _toy_index_blocks_4(/*grid_size*/a0.__ptr, /*grid*/a1.__ptr, /*blocks*/a2.__ptr, /*sectors*/a3.__ptr);
};
Module['HBlock'] = ComponentHandle_toy_Block;
Module['HChunk'] = ComponentHandle_toy_Chunk;
Module['HHeap'] = ComponentHandle_toy_Heap;
Module['HSector'] = ComponentHandle_toy_Sector;
Module['HTileblock'] = ComponentHandle_toy_Tileblock;

(function() {
    function setup() {
        Block.__type = _toy_Block__type();
        Chunk.__type = _toy_Chunk__type();
        Element.__type = _toy_Element__type();
        Heap.__type = _toy_Heap__type();
        Sector.__type = _toy_Sector__type();
        Tileblock.__type = _toy_Tileblock__type();
        Earth.__type = _toy_Earth__type();
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
